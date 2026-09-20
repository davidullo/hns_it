#!/usr/bin/env python3
"""Riempie le unita' traducibili senza usare un LLM.

Fonti deterministiche:

1. il glossario ufficiale (it/data/glossary.csv), per i nomi di specie, mosse,
   abilita', oggetti, tipi, nature, luoghi, regioni;
2. i testi ufficiali (it/data/prose.jsonl) per le descrizioni di mosse,
   abilita' e oggetti.

Regole:
* si sostituisce solo quando l'intero testo visibile dell'unita' corrisponde;
* se l'inglese e' tutto maiuscolo, anche l'italiano viene messo in maiuscolo
  (convenzione delle localizzazioni ufficiali);
* nessuna sostituzione parziale dentro le frasi: quelle passano dall'LLM.

    python3 it/tools/autofill.py [--dry-run] [--only inc|cstr]
"""

from __future__ import annotations

import argparse
import csv
import json
import re
import sys
from collections import Counter
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

from hnsit import store  # noqa: E402
from hnsit.textparse import CONTROL_RE  # noqa: E402

ROOT = Path(__file__).resolve().parents[1]

# Tipi del glossario che si possono applicare a un blocco intero.
NAME_KINDS = {
    "species",
    "form",
    "move",
    "ability",
    "item",
    "type",
    "stat",
    "nature",
    "location",
    "region",
    "genus",
}
PROSE_KINDS = {
    "move_effect_short",
    "move_effect_long",
    "ability_effect_short",
    "ability_effect_long",
    "item_effect_short",
    "item_effect_long",
    "move_flavor",
    "ability_flavor",
    "item_flavor",
    "super_contest",
}


def norm(text: str) -> str:
    t = text.replace("\u000c", " ").replace("\u00ad", "")
    t = t.replace("\u201c", '"').replace("\u201d", '"').replace("\u2018", "'").replace("\u2019", "'")
    t = t.replace("\u2026", "...")
    t = t.replace("\u00e9", "e").replace("\u00c9", "E")
    t = t.replace("\u00e8", "e").replace("\u00e0", "a").replace("\u00f2", "o").replace("\u00f9", "u")
    t = re.sub(r"\\[npl]", " ", t)
    t = re.sub(r"\{[^}]*\}", " ", t)
    t = re.sub(r"[\s]+", " ", t)
    return t.strip().lower().strip(".!")


def load_glossary() -> dict[str, dict[str, str]]:
    """{norm(en): {kind: it}}"""
    out: dict[str, dict[str, str]] = {}
    path = ROOT / "data" / "glossary.csv"
    with path.open(encoding="utf-8", newline="") as fh:
        for row in csv.DictReader(fh):
            out.setdefault(norm(row["en"]), {})[row["kind"]] = row["it"]
    return out


def load_prose() -> dict[str, str]:
    out: dict[str, str] = {}
    path = ROOT / "data" / "prose.jsonl"
    for line in path.read_text(encoding="utf-8").splitlines():
        if not line.strip():
            continue
        row = json.loads(line)
        if row["kind"] in PROSE_KINDS:
            out.setdefault(norm(row["en"]), row["it"])
    return out


def wordsish(text: str) -> bool:
    return bool(re.search(r"[A-Za-z]", text))


def apply_units(units: list, glossary, prose, dry_run: bool) -> Counter:
    counts: Counter = Counter()
    for unit in units:
        if unit.status != "pending" or unit.it is not None:
            continue
        lines = unit.visible_lines
        if not lines:
            continue
        # testi senza lettere (es. "???", "- - -"): restano come sono
        if all(not wordsish(CONTROL_RE.sub("", line)) for line in lines):
            if not dry_run:
                unit.it = list(lines)
                unit.status = "auto"
                unit.note = "identico:simboli"
            counts["identico:simboli"] += 1
            continue
        joined = " ".join(lines)
        key = norm(joined)
        it_text = None
        hit_kind = None
        pre_rebuilt: list[str] | None = None
        if it_text is None and len(lines) == 1 and CONTROL_RE.search(lines[0]):
            # riga con codici {...}: si sostituisce solo la parte testuale,
            # i codici restano dove sono e non si perdono
            line = lines[0]
            residual = CONTROL_RE.sub("", line).strip()
            if residual:
                entry = glossary.get(norm(residual), {})
                for kind in NAME_KINDS:
                    if kind in entry:
                        cand = entry[kind]
                        if residual.isupper():
                            cand = cand.upper()
                        markers: dict[str, str] = {}
                        masked = CONTROL_RE.sub(
                            lambda m: markers.setdefault(f"\x01{len(markers)}\x01", m.group(0)), line
                        )
                        if masked.count(residual) == 1:
                            rebuilt = masked.replace(residual, cand)
                            for token, code in markers.items():
                                rebuilt = rebuilt.replace(token, code)
                            it_text = cand
                            hit_kind = f"glossary-coded:{kind}"
                            pre_rebuilt = [rebuilt]
                        break
        if it_text is None and not any(CONTROL_RE.search(line) for line in lines):
            if key in glossary:
                entry = glossary[key]
                for kind in NAME_KINDS:
                    if kind in entry:
                        it_text = entry[kind]
                        hit_kind = f"glossary:{kind}"
                        break
            if it_text is None and key in prose:
                it_text = prose[key]
                hit_kind = "prose"
        if it_text is None:
            continue
        if pre_rebuilt is not None:
            new_lines = pre_rebuilt
        else:
            # il maiuscolo si conserva, e' la convenzione ufficiale
            visible = [l for l in lines if wordsish(l)]
            if visible and all(l.strip().isupper() for l in visible):
                it_text = it_text.upper()
            if len(lines) == 1:
                new_lines = [it_text]
            else:
                # blocco su piu' righe: si ripartisce sulle righe originali in
                # modo proporzionale alla lunghezza
                new_lines = split_proportional(it_text, [len(l) or 1 for l in lines])
        if dry_run:
            counts[f"would:{hit_kind}"] += 1
            continue
        try:
            unit.rebuild(new_lines)
        except ValueError:
            counts["salta:righe"] += 1
            continue
        unit.it = new_lines
        unit.status = "auto"
        unit.note = hit_kind
        counts[hit_kind] += 1
    return counts


def split_proportional(text: str, weights: list[int]) -> list[str]:
    """Spezza `text` in len(weights) pezzi, con lunghezze proporzionali ai pesi."""
    words = text.split()
    total = sum(weights)
    target = [max(1, round(len(words) * w / total)) for w in weights]
    while sum(target) > len(words):
        i = target.index(max(target))
        target[i] -= 1
    while sum(target) < len(words):
        i = target.index(min(target))
        target[i] += 1
    out, pos = [], 0
    for n in target:
        out.append(" ".join(words[pos:pos + n]))
        pos += n
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--only", choices=["inc", "cstr"], default=None)
    args = ap.parse_args()

    glossary = load_glossary()
    prose = load_prose()
    print(f"glossario: {len(glossary)} chiavi, prose: {len(prose)} testi")

    for name in (store.INC_STORE, store.CSTR_STORE):
        kind = "inc" if "inc" in name else "cstr"
        if args.only and args.only != kind:
            continue
        path = store.data_dir() / name
        units = store.load_units(path)
        counts = apply_units(units, glossary, prose, args.dry_run)
        if not args.dry_run:
            store.save_units(path, units)
        print(f"--- {kind}")
        for k, v in counts.most_common():
            print(f"  {k}: {v}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
