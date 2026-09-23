#!/usr/bin/env python3
"""Riempie le unita' traducibili senza usare un LLM.

Fonti deterministiche:

1. il glossario ufficiale (it/data/glossary.csv), per i nomi di specie, mosse,
   abilita', oggetti, tipi, nature, luoghi, regioni;
2. i testi ufficiali (it/data/prose.jsonl) per le descrizioni di mosse,
   abilita' e oggetti.

Regole:

* si sostituisce solo quando l'intero testo visibile dell'unita' corrisponde;
* nei file di dati .c/.h si usa il glossario SOLO dove il contesto lo giustifica
  (nomi oggetto in items.h, mosse in moves_info.h, ...): altrove una parola come
  "Bacon" in una lista di soprannomi verrebbe tradotta a sproposito;
* niente traduzioni che non entrano nel campo di destinazione (array a
  dimensione fissa): quelle restano all'LLM, che sa accorciare;
* i testi su piu' righe si ripartiscono in proporzione alle righe inglesi.

    cd it && python3 -m hnsit autofill [--dry-run] [--only inc|cstr]
"""

from __future__ import annotations

import argparse
import csv
import json
import re
from collections import Counter
from pathlib import Path

from . import store
from .buffers import all_limits
from .textparse import CONTROL_RE, Metrics

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
    # stati alterati (assideramento): servono ai testi di servizio e alle
    # stringhe di battaglia, non a un array di nomi di specie/mosse
    "status",
}
# ordine di preferenza quando piu' tipi combaciano
KIND_ORDER = [
    "species",
    "form",
    "move",
    "ability",
    "item",
    "type",
    "nature",
    "stat",
    "location",
    "region",
    "genus",
]
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

# contesto -> tipi ammessi, per le unita' dentro file di dati .c/.h
FILE_KINDS: dict[str, set[str]] = {
    "src/data/items.h": {"item"},
    "src/data/moves_info.h": {"move"},
    "src/data/abilities.h": {"ability"},
    "src/data/types_info.h": {"type"},
    "src/data/natures.h": {"nature"},
    "src/data/pokemon/species_info": {"species", "genus"},
}
# file -> prefissi di prose ammessi
FILE_PROSE: dict[str, tuple[str, ...]] = {
    "src/data/items.h": ("item_",),
    "src/data/moves_info.h": ("move_",),
    "src/data/abilities.h": ("ability_",),
}


def allowed_kinds(unit) -> set[str] | None:
    """Tipi di glossario ammessi per questa unita' (None = nessuno)."""
    if not unit.file.endswith((".c", ".h")):
        # script e testi .inc: match esatto sull'intero testo
        return NAME_KINDS
    for prefix, kinds in FILE_KINDS.items():
        if unit.file.startswith(prefix):
            if prefix.endswith("species_info"):
                label = unit.label or ""
                if label.endswith("categoryName"):
                    return {"genus"}
                if label.endswith("speciesName"):
                    return {"species"}
                return None
            return set(kinds)
    return None


def allowed_prose(unit) -> tuple[str, ...]:
    for prefix, kinds in FILE_PROSE.items():
        if unit.file.startswith(prefix):
            return kinds
    return ()


def norm(text: str) -> str:
    t = text.replace("\u000c", " ").replace("\u00ad", "")
    t = t.replace("\u201c", '"').replace("\u201d", '"').replace("\u2018", "'").replace("\u2019", "'")
    t = t.replace("\u2026", "...")
    t = t.replace("\u00e9", "e").replace("\u00c9", "E")
    t = t.replace("\u00e8", "e").replace("\u00e0", "a").replace("\u00f2", "o").replace("\u00f9", "u")
    t = re.sub(r"\\[npl]", " ", t)
    t = re.sub(r"\{[^}]*\}", " ", t)
    t = re.sub(r"[\s]+", " ", t)
    return t.strip().lower().strip(".")


def load_glossary() -> dict[str, dict[str, str]]:
    """{norm(en): {kind: it}}"""
    out: dict[str, dict[str, str]] = {}
    path = ROOT / "data" / "glossary.csv"
    with path.open(encoding="utf-8", newline="") as fh:
        for row in csv.DictReader(fh):
            out.setdefault(norm(row["en"]), {})[row["kind"]] = row["it"]
    return out


def load_prose() -> dict[str, tuple[str, str]]:
    out: dict[str, str] = {}
    path = ROOT / "data" / "prose.jsonl"
    for line in path.read_text(encoding="utf-8").splitlines():
        if not line.strip():
            continue
        row = json.loads(line)
        if row["kind"] in PROSE_KINDS:
            out.setdefault(norm(row["en"]), (row["kind"], row["it"]))
    return out


def wordsish(text: str) -> bool:
    return bool(re.search(r"[A-Za-z]", text))


# testo giapponese rimasto nel sorgente (ramo JP del gioco): non e' tradotto,
# quindi non va contato come "fatto"
CJK_RE = re.compile(r"[\u3040-\u30ff\u3400-\u4dbf\u4e00-\u9fff\uff66-\uff9f]")


def is_japanese(text: str) -> bool:
    return bool(CJK_RE.search(text))


def ascii_punct(text: str) -> str:
    """Punteggiatura come nei testi del gioco: apostrofo dritto, niente “ ”.

    Il charmap conosce anche le virgolette tipografiche, ma i testi originali
    usano l'apostrofo dritto: tenersi coerenti evita differenze a video.
    """
    return (
        text.replace("\u2019", "'")
        .replace("\u2018", "'")
        .replace("\u201c", '"')
        .replace("\u201d", '"')
        .replace("\u2013", "-")
        .replace("\u2014", "-")
    )


def pick(entry: dict[str, str], allowed: set[str] | None = None) -> tuple[str, str] | None:
    """(kind, testo) dalla voce di glossario, rispettando i tipi ammessi."""
    for kind in KIND_ORDER:
        if kind in entry and (allowed is None or kind in allowed):
            return kind, entry[kind]
    return None


def apply_units(units: list, glossary, prose, limits, metrics: Metrics, dry_run: bool) -> Counter:
    counts: Counter = Counter()
    for unit in units:
        if unit.status != "pending" or unit.it is not None:
            continue
        lines = unit.visible_lines
        if not lines:
            continue
        limit = limits.limit(unit.file, unit.label)
        # testi senza lettere latine: o simboli (restano come sono) o stringhe
        # giapponesi del ramo JP, che NON sono tradotte e non vanno contate
        if all(not wordsish(CONTROL_RE.sub("", line)) for line in lines):
            japanese = any(is_japanese(line) for line in lines)
            if not dry_run:
                unit.it = list(lines)
                unit.status = "skipped" if japanese else "auto"
                unit.note = "sorgente giapponese" if japanese else "identico:simboli"
            counts["sorgente giapponese" if japanese else "identico:simboli"] += 1
            continue

        allowed = allowed_kinds(unit)
        if allowed is None:
            counts["salta:contesto"] += 1
            continue
        prose_kinds = allowed_prose(unit)

        joined = " ".join(lines)
        key = norm(joined)
        it_text: str | None = None
        hit_kind: str | None = None
        pre_rebuilt: list[str] | None = None

        if len(lines) == 1 and CONTROL_RE.search(lines[0]):
            # riga con codici {...}: si sostituisce solo la parte testuale,
            # i codici restano dove sono e non si perdono
            line = lines[0]
            residual = CONTROL_RE.sub("", line).strip()
            if residual:
                hit = pick(glossary.get(norm(residual), {}), allowed)
                if hit is not None:
                    kind, cand = hit
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

        if it_text is None and not any(CONTROL_RE.search(line) for line in lines):
            hit = pick(glossary.get(key, {}), allowed)
            if hit is not None:
                hit_kind, it_text = f"glossary:{hit[0]}", hit[1]
            elif prose_kinds:
                row = prose.get(key)
                if row is not None and row[0].startswith(prose_kinds):
                    it_text = row[1]
                    hit_kind = "prose"
        if it_text is None:
            continue
        it_text = ascii_punct(it_text)
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

        if limit is not None and metrics.encoded_len("".join(new_lines)) > limit:
            counts["salta:limite"] += 1
            continue
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
    limits = all_limits(store.repo_root())
    metrics = Metrics(store.repo_root())
    print(f"glossario: {len(glossary)} chiavi, prose: {len(prose)} testi")

    for name in (store.INC_STORE, store.CSTR_STORE):
        kind = "inc" if "inc" in name else "cstr"
        if args.only and args.only != kind:
            continue
        path = store.data_dir() / name
        units = store.load_units(path)
        counts = apply_units(units, glossary, prose, limits, metrics, args.dry_run)
        if not args.dry_run:
            store.save_units(path, units)
        print(f"--- {kind}")
        for k, v in counts.most_common():
            print(f"  {k}: {v}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
