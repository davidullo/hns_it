#!/usr/bin/env python3
"""Verifica della traduzione: unita', larghezze, placeholder, sorgenti.

    python3 it/tools/verify.py units [--limit 40]      # controlla i dati
    python3 it/tools/verify.py repo [--limit 40]       # controlla i sorgenti
    python3 it/tools/verify.py report                  # riassunto per file

`units` esce 1 se trova problemi duri. E' l'arbitro: se non passa, non si
committa e non si builda.
"""

from __future__ import annotations

import argparse
import json
import re
import sys
from collections import Counter, defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

from hnsit import store  # noqa: E402
from hnsit.textparse import CONTROL_RE, Metrics, read_inc_blocks, sha1_of  # noqa: E402

ROOT = Path(__file__).resolve().parents[1]
LIMIT_PX = 216
TARGET_PX = 200

# testi che restano identici all'inglese perche' sono nomi propri o simboli
ALLOW_IDENTICAL = {
    "POKéMON",
    "POKéDEX",
    "OK",
    "HP",
    "PP",
    "TV",
    "PC",
    "EXP.",
    "EXIT",
    "GAME OVER",
}


def placeholders(text: str) -> list[str]:
    return sorted(CONTROL_RE.findall(text))


def check_unit(unit, metrics: Metrics) -> list[str]:
    """Problemi duri di una unita' tradotta."""
    problems: list[str] = []
    if unit.it is None:
        return ["nessuna traduzione"]
    try:
        it_segments = unit.rebuild(unit.it)
    except ValueError as exc:
        return [str(exc)]
    en_lines = unit.lines
    if len(unit.it) != len(en_lines):
        problems.append(f"{len(unit.it)} righe IT contro {len(en_lines)} EN")
        return problems

    for i, ((en_text, _term), it_text) in enumerate(zip(en_lines, unit.it)):
        ph_en, ph_it = placeholders(en_text), placeholders(it_text)
        if ph_en != ph_it:
            problems.append(f"riga {i}: codici {ph_en} -> {ph_it}")
        if it_text != en_text:
            w, unknown = metrics.line_width(CONTROL_RE.sub("", it_text))
            if unknown:
                problems.append(f"riga {i}: caratteri fuori charmap {''.join(sorted(set(unknown)))}")
            if w > LIMIT_PX:
                problems.append(f"riga {i}: {w}px oltre il limite {LIMIT_PX}")

    if not any("px oltre" in p or "codici" in p or "charmap" in p for p in problems):
        joined = "".join(unit.it).strip()
        if joined == "".join(t for t, _ in en_lines).strip():
            if joined not in ALLOW_IDENTICAL and not joined.isupper() and not joined.startswith("?"):
                problems.append("W:identica all'inglese")
    # struttura: stessi separatori, stesso numero di segmenti
    try:
        if len(it_segments) != len(unit.segments):
            problems.append("numero di segmenti diverso")
    except Exception:
        pass
    return problems


def cmd_units(limit: int, kind: str | None) -> int:
    metrics = Metrics(store.repo_root())
    units = store.load_all()
    hard: list[str] = []
    warn: list[str] = []
    stats = Counter()
    for unit in units.values():
        if kind and unit.kind != kind:
            continue
        stats[f"status:{unit.status}"] += 1
        if unit.status == "skipped":
            continue
        if unit.it is None:
            stats["senza traduzione"] += 1
            continue
        problems = check_unit(unit, metrics)
        for p in problems:
            if p.startswith("W:"):
                warn.append(f"{unit.key}: {p[2:]}")
            elif p.startswith("riga") and "oltre il limite" in p:
                hard.append(f"{unit.key}: {p}")
            else:
                hard.append(f"{unit.key}: {p}")
        # avviso: riga IT molto piu' lunga dell'inglese
        for i, ((en_text, _t), it_text) in enumerate(zip(unit.lines, unit.it)):
            w_en, _ = metrics.line_width(CONTROL_RE.sub("", en_text))
            w_it, _ = metrics.line_width(CONTROL_RE.sub("", it_text))
            if w_it > TARGET_PX and w_en <= TARGET_PX:
                warn.append(f"{unit.key}: riga {i} {w_en}->{w_it}px")
                break

    print(f"duri: {len(hard)}   avvisi: {len(warn)}")
    for row in hard[:limit]:
        print("  H " + row)
    for row in warn[:limit]:
        print("  W " + row)
    for k, v in stats.most_common():
        print(f"  {k}: {v}")
    return 1 if hard else 0


def cmd_repo(limit: int) -> int:
    """I sorgenti contengono quello che dice il file dati?"""
    repo = store.repo_root()
    units = store.load_all()
    problems: list[str] = []
    cache: dict[str, dict] = {}
    for unit in units.values():
        if unit.it is None or unit.status == "skipped":
            continue
        if unit.kind != "inc":
            continue
        if unit.file not in cache:
            cache[unit.file] = read_inc_blocks(repo, unit.file)
        current = cache[unit.file].get(unit.label)
        if current is None:
            problems.append(f"{unit.key}: blocco assente")
            continue
        en_ok = current == unit.segments
        it_ok = current == unit.rebuild(unit.it)
        if not it_ok:
            problems.append(f"{unit.key}: {'inglese' if en_ok else 'diverso da entrambi'}")
    print(f"problemi nei sorgenti: {len(problems)}")
    for row in problems[:limit]:
        print("  " + row)
    return 1 if problems else 0


def cmd_report() -> int:
    units = store.load_all()
    by_file: dict[str, Counter] = defaultdict(Counter)
    for unit in units.values():
        c = by_file[unit.file]
        c["tot"] += 1
        c[unit.status] += 1
    done = 0
    print(f"{'file':70} {'tot':>5} {'fatte':>6}")
    for path in sorted(by_file):
        c = by_file[path]
        d = c.get("auto", 0) + c.get("translated", 0) + c.get("reviewed", 0)
        done += d
        print(f"{path:70} {c['tot']:>5} {d:>6}")
    print(f"totale fatte: {done}")
    return 0


def main() -> int:
    ap = argparse.ArgumentParser(prog="verify")
    sub = ap.add_subparsers(dest="cmd", required=True)
    p_units = sub.add_parser("units")
    p_units.add_argument("--limit", type=int, default=40)
    p_units.add_argument("--kind", choices=["inc", "cstr"], default=None)
    p_units.add_argument("--json-out", type=Path, default=None)
    p_repo = sub.add_parser("repo")
    p_repo.add_argument("--limit", type=int, default=40)
    sub.add_parser("report")
    args = ap.parse_args()
    if args.cmd == "units":
        return cmd_units(args.limit, args.kind)
    if args.cmd == "repo":
        return cmd_repo(args.limit)
    if args.cmd == "report":
        return cmd_report()
    return 1


if __name__ == "__main__":
    raise SystemExit(main())
