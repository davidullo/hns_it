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
from .autofill import allowed_kinds, allowed_prose, is_japanese
from .textparse import Metrics


def mark_japanese(units: dict) -> int:
    """Le stringhe del ramo giapponese non sono tradotte: non contarle come fatte.

    Erano marcate `auto` con nota "identico:simboli" solo perche' non hanno
    lettere latine: cosi' il conteggio delle unita' fatte mentiva.
    """
    n = 0
    for unit in units.values():
        if unit.status == "skipped" or not unit.it:
            continue
        if any(is_japanese(line) for line in unit.it):
            unit.status = "skipped"
            unit.note = "sorgente giapponese"
            n += 1
    return n


def wrong_context(unit, units: dict | None = None) -> str | None:
    """Riempimento automatico non piu' valido per le regole attuali.

    Se le regole del glossario cambiano, i riempimenti vecchi restano: qui si
    riconoscono quelli fatti col tipo sbagliato (es. "GUTS" nome di allenatore
    tradotto con l'abilita' "Dentistretti") e quelli copiati via translation
    memory da un contesto che qui non vale.
    """
    note = unit.note or ""
    if note.startswith("tm:"):
        # il contesto vale quello della sorgente della copia
        kind = _tm_kind(note, units)
        note = f"glossary:{kind}" if kind else "tm"
    if note.startswith("glossary"):
        kind = note.split(":")[-1]
        allowed = allowed_kinds(unit)
        if allowed is None or kind not in allowed:
            return f"contesto: {kind} non ammesso qui"
    elif note == "prose" and not allowed_prose(unit):
        return "contesto: prose non ammesse qui"
    return None


def _tm_kind(note: str, units: dict | None = None) -> str:
    """Tipo di glossario dell'unita' sorgente di una copia `tm:<key>`."""
    key = note[3:]
    src = (units or store.load_all()).get(key)
    if src is None or not src.note:
        return ""
    if src.note.startswith("glossary"):
        return src.note.split(":")[-1]
    if src.note.startswith("tm:"):
        return _tm_kind(src.note, units)
    return ""


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
        context = wrong_context(unit, units)
        if context:
            problems.append(context)
        if problems:
            bad.append((unit.key, problems))

    print(f"unita' con problemi duri: {len(bad)}")
    for key, problems in bad[: args.limit]:
        print(f"  {key}: {problems[0]}")
    if stale:
        print(f"unita' pending con traduzione rimasta: {len(stale)}")

    jp = mark_japanese(units)
    if jp:
        print(f"stringhe del ramo giapponese marcate come non tradotte: {jp}")

    if args.apply and (bad or stale or jp):
        for key, _problems in bad:
            unit = units[key]
            unit.prev_it = unit.it
            unit.it = None
            unit.status = "pending"
            unit.note = "reset:verifica"
        for key in stale:
            unit = units[key]
            unit.prev_it = unit.it
            unit.it = None
            unit.note = "reset:verifica"
        batchmod.save_all(units)
        print("riportate a pending (il sorgente torna all'inglese al prossimo inject)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
