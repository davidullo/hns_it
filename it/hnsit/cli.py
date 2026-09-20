#!/usr/bin/env python3
"""CLI unica della traduzione italiana.

    cd it
    python3 -m hnsit extract
    python3 -m hnsit stats
    python3 -m hnsit autofill [--dry-run]
    python3 -m hnsit glossary
    python3 -m hnsit batch plan --kind inc --size 20 --max 5
    python3 -m hnsit translate --kind inc --size 20 --workers 6 --rounds 10
    python3 -m hnsit verify units
    python3 -m hnsit repair --apply
    python3 -m hnsit inject [--dry-run]
"""

from __future__ import annotations

import argparse
import sys
from pathlib import Path

from . import extract, inject, store

USAGE = """sottocomandi:
  extract             ricostruisce data/units_*.jsonl dal repo
  stats               conteggi per stato
  glossary            ricostruisce glossario e prose dai dump PokeAPI
  autofill            riempie dai dati ufficiali, senza LLM
  batch               plan | apply | status | pending
  translate           runner dei lotti verso modelli economici
  verify              units | repo | report
  repair              riporta a pending le unita' che non passano
  inject              scrive le traduzioni nei sorgenti
"""


def main() -> int:
    if len(sys.argv) < 2 or sys.argv[1] in ("-h", "--help"):
        print(USAGE)
        return 0
    cmd = sys.argv[1]
    rest = sys.argv[2:]

    if cmd == "extract":
        ap = argparse.ArgumentParser(prog="hnsit extract")
        ap.add_argument("--repo", type=Path, default=store.repo_root())
        return extract.cmd_extract(ap.parse_args(rest).repo)

    if cmd == "stats":
        units = store.load_all()
        for key, value in store.stats(list(units.values())).items():
            print(f"{key}: {value}")
        return 0

    if cmd == "inject":
        ap = argparse.ArgumentParser(prog="hnsit inject")
        ap.add_argument("--repo", type=Path, default=store.repo_root())
        ap.add_argument("--dry-run", action="store_true")
        ap.add_argument("--only", default=None)
        args = ap.parse_args(rest)
        return inject.cmd_inject(args.repo, dry_run=args.dry_run, only=args.only)

    mods = {
        "glossary": "glossary",
        "autofill": "autofill",
        "batch": "batching",
        "translate": "translate",
        "verify": "verify",
        "repair": "repair",
        "learn": "learn_limits",
    }
    if cmd in mods:
        mod = __import__(f"hnsit.{mods[cmd]}", fromlist=["main"])
        sys.argv = [f"hnsit {cmd}"] + rest
        return mod.main()

    print(f"sottocomando sconosciuto: {cmd}\n{USAGE}")
    return 2


if __name__ == "__main__":
    raise SystemExit(main())
