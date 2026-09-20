#!/usr/bin/env python3
"""Riporta a `pending` le unita' che non passano la verifica.

Serve dopo un lotto andato male o dopo un cambio di regole: invece di
ri-traduire tutto, si azzerano solo le unita' che hanno problemi duri.

    python3 it/tools/repair.py            # dry run
    python3 it/tools/repair.py --apply
"""

from __future__ import annotations

import argparse
import sys
from pathlib import Path


from . import batching as batchmod
from . import verify as verifymod
from . import store
from .autofill import allowed_kinds, allowed_prose
from .textparse import Metrics


def wrong_context(unit) -> str | None:
    """Riempimento automatico non piu' valido per le regole attuali.

    Se le regole del glossario cambiano, i riempimenti vecchi restano: qui si
    riconoscono quelli fatti col tipo sbagliato (es. "GUTS" nome di allenatore
    tradotto con l'abilita' "Dentistretti").
    """
    note = unit.note or ""
    if note.startswith("glossary"):
        kind = note.split(":")[-1]
        allowed = allowed_kinds(unit)
        if allowed is None or kind not in allowed:
            return f"contesto: {kind} non ammesso qui"
    elif note == "prose" and not allowed_prose(unit):
        return "contesto: prose non ammesse qui"
    return None


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--apply", action="store_true")
    ap.add_argument("--limit", type=int, default=20)
    args = ap.parse_args()

    metrics = Metrics(store.repo_root())
    units = store.load_all()
    bad = []
    stale = []
    for unit in units.values():
        if unit.status == "pending":
            # pending = nessuna traduzione accettata: se ne era rimasta una
            # (reset a meta'), va buttata, altrimenti la verifica la contesta
            if unit.it is not None:
                stale.append(unit.key)
            continue
        if unit.status == "skipped" or unit.it is None:
            continue
        problems = [
            p
            for p in verifymod.check_unit(unit, metrics, verifymod.limits_for(store.repo_root()))
            if not p.startswith("W:")
        ]
        context = wrong_context(unit)
        if context:
            problems.append(context)
        if problems:
            bad.append((unit.key, problems))

    print(f"unita' con problemi duri: {len(bad)}")
    for key, problems in bad[: args.limit]:
        print(f"  {key}: {problems[0]}")
    if stale:
        print(f"unita' pending con traduzione rimasta: {len(stale)}")

    if args.apply and (bad or stale):
        for key, _problems in bad:
            unit = units[key]
            unit.it = None
            unit.status = "pending"
            unit.note = "reset:verifica"
        for key in stale:
            unit = units[key]
            unit.it = None
            unit.note = "reset:verifica"
        batchmod.save_all(units)
        print("riportate a pending")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
