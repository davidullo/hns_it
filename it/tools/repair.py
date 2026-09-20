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

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
sys.path.insert(0, str(Path(__file__).resolve().parent))

import batch as batchmod  # noqa: E402
import verify as verifymod  # noqa: E402
from hnsit import store  # noqa: E402
from hnsit.textparse import Metrics  # noqa: E402


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--apply", action="store_true")
    ap.add_argument("--limit", type=int, default=20)
    args = ap.parse_args()

    metrics = Metrics(store.repo_root())
    units = store.load_all()
    bad = []
    for unit in units.values():
        if unit.status in ("pending", "skipped") or unit.it is None:
            continue
        problems = [p for p in verifymod.check_unit(unit, metrics) if not p.startswith("W:")]
        if problems:
            bad.append((unit.key, problems))

    print(f"unita' con problemi duri: {len(bad)}")
    for key, problems in bad[: args.limit]:
        print(f"  {key}: {problems[0]}")

    if args.apply and bad:
        for key, _problems in bad:
            unit = units[key]
            unit.it = None
            unit.status = "pending"
            unit.note = "reset:verifica"
        batchmod.save_all(units)
        print("riportate a pending")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
