#!/usr/bin/env python3
"""Impara i limiti dei campi dagli errori di build.

Il compilatore e' l'arbitro dei campi ad array fisso: quando la build si ferma
con `excess elements in array initializer` questo strumento legge il log, trova
le unita' colpevoli (il loro `hint` e' `file:riga`), scrive il limite in
it/data/limits_learned.json e le rimette in coda, cosi' il lotto successivo sa
quanto spazio ha.

Il limite imparato e' la lunghezza dell'inglese di quella unita': l'inglese
compila, quindi e' una misura sicura (mai piu' largo dell'originale).

    cd it && python3 -m hnsit learn --log /tmp/hns_build.log
    cd it && python3 -m hnsit learn --log /tmp/hns_build.log --apply
"""

from __future__ import annotations

import argparse
import json
import re
from collections import defaultdict
from pathlib import Path

from . import store
from .buffers import LEARNED_FILE
from .textparse import Metrics

# src/data/battle_frontier/trainer_hill.h:4041:105: error: excess elements ...
ERR_RE = re.compile(
    r"^(?P<file>[^\s:]+\.(?:c|h)):(?P<line>\d+):\d+:\s*error:\s*"
    r"(?:excess elements in array initializer|initializer-string for array)"
)


def parse_log(path: Path) -> dict[str, dict[int, str]]:
    """{file: {riga: primo pezzo di testo della riga colpevole}}"""
    out: dict[str, dict[int, str]] = defaultdict(dict)
    for raw in path.read_text(encoding="utf-8", errors="replace").splitlines():
        m = ERR_RE.match(raw.strip())
        if not m:
            continue
        out[m.group("file")][int(m.group("line"))] = ""
    return {k: dict(v) for k, v in out.items()}


def find_units(units: dict, file: str, line: int) -> list:
    hint = f"{file}:{line}"
    return [u for u in units.values() if u.file == file and u.hint == hint]


def main() -> int:
    ap = argparse.ArgumentParser(prog="hnsit learn")
    ap.add_argument("--log", type=Path, required=True)
    ap.add_argument("--apply", action="store_true")
    args = ap.parse_args()

    errors = parse_log(args.log)
    if not errors:
        print("nessun errore di array nel log: niente da imparare")
        return 0

    repo = store.repo_root()
    metrics = Metrics(repo)
    units = store.load_all()
    learned_path = repo / LEARNED_FILE
    learned: dict[str, dict[str, int]] = {}
    if learned_path.exists():
        learned = json.loads(learned_path.read_text(encoding="utf-8"))

    touched = 0
    for file, lines in sorted(errors.items()):
        for line in sorted(lines):
            victims = find_units(units, file, line)
            if not victims:
                print(f"  ? {file}:{line}: nessuna unita' (riga fuori dal testo?)")
                continue
            # il limite sicuro: quanto e' lungo l'inglese che compila
            sizes = [metrics.encoded_len("".join(t for t, _ in u.lines)) for u in victims]
            limit = min(sizes)
            field = (victims[0].label or "?").split(".")[-1]
            old = learned.setdefault(file, {}).get(field)
            learned[file][field] = limit if old is None else min(old, limit)
            print(f"  {file}:{line} campo {field}: limite {learned[file][field]} ({len(victims)} unita')")
            for unit in victims:
                if unit.status != "pending" or unit.it is not None:
                    unit.status = "pending"
                    unit.it = None
                    unit.note = f"limite:{limit}"
                    touched += 1

    if args.apply:
        learned_path.write_text(
            json.dumps(learned, ensure_ascii=False, indent=1, sort_keys=True), encoding="utf-8"
        )
        for name in (store.INC_STORE, store.CSTR_STORE):
            path = store.data_dir() / name
            rows = store.load_units(path)
            fixed = []
            for unit in rows:
                if unit.key in units:
                    unit.status = units[unit.key].status
                    unit.note = units[unit.key].note
                fixed.append(unit)
            store.save_units(path, fixed)
        print(f"scritti {len(learned)} file con limiti imparati, {touched} unita' rimesse in coda")
    else:
        print(f"(dry-run) {touched} unita' da rimettere in coda")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
