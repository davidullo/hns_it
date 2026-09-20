#!/usr/bin/env python3
"""CLI unica del progetto di traduzione italiana.

    python3 it/tools/hnsit.py extract
    python3 it/tools/hnsit.py stats
    python3 it/tools/hnsit.py inject [--dry-run]
"""

from __future__ import annotations

import argparse
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

from hnsit import extract, inject, store  # noqa: E402


def main() -> int:
    ap = argparse.ArgumentParser(prog="hnsit")
    ap.add_argument("--repo", type=Path, default=store.repo_root())
    sub = ap.add_subparsers(dest="cmd", required=True)

    sub.add_parser("extract", help="ricostruisce it/data/units_*.jsonl dal repo")

    p_stats = sub.add_parser("stats", help="riassunto dello stato di traduzione")
    p_stats.add_argument("--by-kind", action="store_true")

    p_inj = sub.add_parser("inject", help="scrive le traduzioni nei sorgenti")
    p_inj.add_argument("--dry-run", action="store_true")
    p_inj.add_argument("--only", default=None, help="prefisso di chiave")

    args = ap.parse_args()
    repo: Path = args.repo

    if args.cmd == "extract":
        return extract.cmd_extract(repo)
    if args.cmd == "stats":
        units = store.load_all()
        s = store.stats(list(units.values()))
        for k, v in s.items():
            print(f"{k}: {v}")
        return 0
    if args.cmd == "inject":
        return inject.cmd_inject(repo, dry_run=args.dry_run, only=args.only)
    return 1


if __name__ == "__main__":
    raise SystemExit(main())
