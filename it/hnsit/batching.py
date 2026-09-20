#!/usr/bin/env python3
"""Gestione dei lotti di traduzione per i subagenti.

    python3 it/tools/batch.py plan  [--kind inc|cstr] [--size 30] [--max 10]
    python3 it/tools/batch.py apply it/work/results/inc-0001.jsonl
    python3 it/tools/batch.py status
    python3 it/tools/batch.py pending [--limit 5]

I lotti contengono solo unita' uniche per testo (sha1): le copie identiche
vengono riempite al momento di `apply`, cosi' non si paga due volte lo stesso
testo.
"""

from __future__ import annotations

import argparse
import csv
import json
import re
import sys
from collections import Counter, defaultdict
from pathlib import Path


from . import store
from . import verify as verifymod
from .autofill import allowed_kinds
from .buffers import all_limits
from .textparse import CONTROL_RE, Metrics

ROOT = Path(__file__).resolve().parents[1]
WORK = ROOT / "work"
BATCH_DIR = WORK / "batches"
RESULT_DIR = WORK / "results"

LIMIT_PX = 216
TARGET_PX = 200


def load_metrics():
    return Metrics(store.repo_root())


def glossary_map() -> dict[str, str]:
    out: dict[str, str] = {}
    path = ROOT / "data" / "glossary.csv"
    with path.open(encoding="utf-8", newline="") as fh:
        for row in csv.DictReader(fh):
            out.setdefault(row["en"], row["it"])
    return out


TERM_RE = re.compile(r"[A-Za-zé\u00e9'\u2019]{3,}")


def relevant_terms(items: list[dict], terms: dict[str, str], limit: int = 60) -> dict[str, str]:
    """Solo i termini del glossario che compaiono davvero nel lotto."""
    text = " ".join(" ".join(it["lines"]) for it in items)
    words = set()
    for w in TERM_RE.findall(text):
        words.add(w)
        words.add(w.upper())
        words.add(w.capitalize())
    out = {}
    for w in sorted(words):
        if w in terms:
            out[w] = terms[w]
        if len(out) >= limit:
            break
    return out


def unit_record(unit, metrics, limits=None) -> dict:
    lines = unit.visible_lines
    widths = []
    for line in lines:
        w, _ = metrics.line_width(CONTROL_RE.sub("", line))
        widths.append(w)
    rec = {
        "id": unit.key,
        "hint": unit.label + (" " + unit.hint if unit.hint else ""),
        "lines": lines,
        "width_px": widths,
        "max_px": max(LIMIT_PX, max(widths) if widths else LIMIT_PX),
    }
    # limite di byte per i campi ad array fisso (`u8 campo[N]`): la build muore
    # se la traduzione non ci sta
    if limits is not None:
        limit = limits.limit(unit.file, unit.label)
        if limit is not None:
            rec["max_chars"] = limit
    return rec


def plan(kind: str, size: int, max_batches: int, start: int) -> int:
    BATCH_DIR.mkdir(parents=True, exist_ok=True)
    units = store.load_units(store.data_dir() / (store.INC_STORE if kind == "inc" else store.CSTR_STORE))
    terms = glossary_map()
    metrics = load_metrics()
    groups = pending_groups(units)
    limits = all_limits(store.repo_root())

    made = 0
    for idx in range(start, start + max_batches):
        chunk = groups[idx * size:(idx + 1) * size]
        if not chunk:
            break
        write_batch(kind, f"{kind}-{idx:04d}", chunk, metrics, terms, limits)
        made += 1
    print(f"lotti scritti: {made} in {BATCH_DIR}")
    return 0


def pending_groups(units) -> list[list]:
    """Gruppi di unita' che condividono lo stesso testo, ancora da tradurre."""
    grouped: dict[str, list] = defaultdict(list)
    for unit in units:
        if unit.status == "skipped":
            continue
        grouped[unit.sha1].append(unit)
    todo = []
    for sha, members in grouped.items():
        if any(m.it and m.status != "skipped" for m in members):
            continue
        head = sorted(members, key=lambda u: u.key)[0]
        todo.append([head, members])
    todo.sort(key=lambda t: t[0].key)
    return todo


def write_batch(kind: str, name: str, chunk: list, metrics, terms, limits=None) -> Path:
    items = [unit_record(head, metrics, limits) for head, _m in chunk]
    aliases = {head.key: [m.key for m in members if m.key != head.key] for head, members in chunk}
    batch = {
        "batch": name,
        "kind": kind,
        "glossary": relevant_terms(items, terms),
        "items": items,
        "aliases": {k: v for k, v in aliases.items() if v},
    }
    out = BATCH_DIR / f"{name}.json"
    out.write_text(json.dumps(batch, ensure_ascii=False, indent=1), encoding="utf-8")
    return out


def apply_rows(units: dict, rows: list[dict], mark: str = "translated") -> tuple[int, list[str]]:
    applied = 0
    failed: list[str] = []
    limits = all_limits(store.repo_root())
    metrics = load_metrics()
    for row in rows:
        key, it_lines = row.get("id"), row.get("it")
        if key not in units:
            failed.append(f"id sconosciuto: {key}")
            continue
        unit = units[key]
        if not isinstance(it_lines, list) or not all(isinstance(x, str) for x in it_lines):
            failed.append(f"{key}: campo it non valido")
            continue
        # la traduzione non deve sfondare i campi ad array fisso: la build muore
        if "".join(it_lines) != "".join(t for t, _ in unit.lines):
            lim = limits.limit(unit.file, unit.label)
            if lim is not None:
                size = metrics.encoded_len("".join(it_lines))
                if size > lim:
                    failed.append(f"{key}: {size}>{lim} byte, troppo lungo per {unit.label}")
                    continue
        try:
            unit.rebuild(it_lines)
        except ValueError as exc:
            failed.append(str(exc))
            continue
        unit.it = it_lines
        unit.status = mark
        # stesse regole di verify: codici {...} nelle stesse righe, larghezza
        # di riga entro il limite del gioco. Se non passano, non entrano.
        problems = verifymod.check_unit(unit, metrics, limits)
        if problems:
            unit.it = None
            unit.status = "pending"
            unit.note = ""
            failed.append(f"{key}: {problems[0]}")
            continue
        applied += 1
    return applied, failed


def apply_results(path: Path, mark: str = "translated") -> int:
    units = store.load_all()
    rows = []
    failed: list[str] = []
    for raw in path.read_text(encoding="utf-8").splitlines():
        raw = raw.strip()
        if not raw or raw.startswith("//"):
            continue
        try:
            rows.append(json.loads(raw))
        except json.JSONDecodeError as exc:
            failed.append(f"riga non JSON: {raw[:80]} ({exc})")
    applied, failed2 = apply_rows(units, rows, mark)
    failed.extend(failed2)
    stamp = f"batch:{path.stem}"
    for row in rows:
        key = row.get("id")
        if key in units and units[key].it is not None:
            units[key].note = stamp

    fanned = fan_out(units)

    save_all(units)
    print(f"applicate: {applied}, propagate per traduzione memoria: {fanned}")
    if failed:
        print(f"scartate: {len(failed)}")
        for row in failed[:15]:
            print("  " + row)
    return 0


def _propagabile(src, target, limits, metrics) -> bool:
    """La traduzione di `src` si puo' copiare su `target`?

    La translation memory e' cieca al contesto: senza questi controlli una
    parola come "GUTS" (nome di un allenatore) si propaga dalla scheda
    dell'abilita' e diventa "Dentistretti", e "Bacon" (soprannome) diventa
    "Pancetta rosolata" dentro un array da 7 byte.
    """
    note = src.note or ""
    if note.startswith("glossary"):
        kind = note.split(":")[-1]
        allowed = allowed_kinds(target)
        if allowed is None or kind not in allowed:
            return False
    limit = limits.limit(target.file, target.label)
    if limit is not None and metrics.encoded_len("".join(src.it or [])) > limit:
        return False
    return True


def fan_out(units: dict, limits=None, metrics=None) -> int:
    if limits is None:
        limits = all_limits(store.repo_root())
    if metrics is None:
        metrics = load_metrics()
    by_sha: dict[str, list] = defaultdict(list)
    for unit in units.values():
        by_sha[unit.sha1].append(unit)
    fanned = 0
    for sha, members in by_sha.items():
        done = [m for m in members if m.it and m.status in ("auto", "translated", "reviewed")]
        if not done:
            continue
        src = sorted(done, key=lambda u: (u.status != "reviewed", u.key))[0]
        for m in members:
            if m.it or m.status == "skipped":
                continue
            if not _propagabile(src, m, limits, metrics):
                continue
            try:
                m.rebuild(src.it)
            except ValueError:
                continue
            m.it = list(src.it)
            m.status = "translated"
            m.note = f"tm:{src.key}"
            fanned += 1
    return fanned


def save_all(units: dict) -> None:
    inc = [u for u in units.values() if u.kind == "inc"]
    cstr_units = [u for u in units.values() if u.kind == "cstr"]
    store.save_units(store.data_dir() / store.INC_STORE, inc)
    store.save_units(store.data_dir() / store.CSTR_STORE, cstr_units)


def status() -> int:
    units = store.load_all()
    counts = Counter(u.status for u in units.values())
    total = len(units)
    done = counts.get("auto", 0) + counts.get("translated", 0) + counts.get("reviewed", 0)
    print(f"unita': {total}  fatte: {done} ({done * 100 // max(total, 1)}%)")
    for k, v in counts.most_common():
        print(f"  {k}: {v}")
    groups = defaultdict(list)
    for u in units.values():
        if u.status != "skipped":
            groups[u.sha1].append(u)
    todo = sum(1 for v in groups.values() if not any(m.it for m in v))
    print(f"gruppi unici ancora da tradurre: {todo}")
    return 0


def pending(limit: int) -> int:
    units = store.load_all()
    groups: dict[str, list] = defaultdict(list)
    for u in units.values():
        if u.status != "skipped":
            groups[u.sha1].append(u)
    n = 0
    for sha, members in groups.items():
        if any(m.it for m in members):
            continue
        head = sorted(members, key=lambda u: u.key)[0]
        print(f"{head.key}\t{len(members)}\t{head.visible_lines}")
        n += 1
        if n >= limit:
            break
    return 0


def main() -> int:
    ap = argparse.ArgumentParser(prog="batch")
    sub = ap.add_subparsers(dest="cmd", required=True)
    p_plan = sub.add_parser("plan")
    p_plan.add_argument("--kind", choices=["inc", "cstr"], required=True)
    p_plan.add_argument("--size", type=int, default=30)
    p_plan.add_argument("--max", type=int, default=5, help="numero di lotti da scrivere")
    p_plan.add_argument("--start", type=int, default=0)
    p_apply = sub.add_parser("apply")
    p_apply.add_argument("file", type=Path)
    p_apply.add_argument("--mark", default="translated")
    sub.add_parser("status")
    p_pend = sub.add_parser("pending")
    p_pend.add_argument("--limit", type=int, default=10)
    args = ap.parse_args()
    if args.cmd == "plan":
        return plan(args.kind, args.size, args.max, args.start)
    if args.cmd == "apply":
        return apply_results(args.file, args.mark)
    if args.cmd == "status":
        return status()
    if args.cmd == "pending":
        return pending(args.limit)
    return 1


if __name__ == "__main__":
    raise SystemExit(main())
