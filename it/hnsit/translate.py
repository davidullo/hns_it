#!/usr/bin/env python3
"""Runner della traduzione: pianifica lotti, li manda a un modello economico,
valida e applica i risultati.

    python3 it/tools/translate_run.py --kind inc --size 20 --workers 6 \\
        --rounds 20 --provider opencode-go --model deepseek-v4.1-flash

Ogni lotto diventa un processo `hermes chat` separato (nessun tool in comune,
nessun contesto ereditato): cosi' il costo per lotto e' solo quello del lotto.
Un lock impedisce che due run si sovrappongano.

Stato e log in it/work/. Alla fine stampa un riassunto JSON.
"""

from __future__ import annotations

import argparse
import json
import os
import subprocess
import sys
import time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path


from . import batching as batchmod
from . import store

ROOT = Path(__file__).resolve().parents[1]
WORK = ROOT / "work"
LOG_DIR = WORK / "logs"
BATCH_DIR = WORK / "batches"
RESULT_DIR = WORK / "results"
LOCK = WORK / ".translate.lock"  # sostituito a runtime con un lock per tipo (inc/cstr)
PROMPT_TEMPLATE = WORK / "prompt_worker.txt"

PROMPT = """Applica le regole di {rules_path} al lotto {batch_path}.

Scrivi il risultato in {out_path}: una riga JSON per unita', nient'altro.
Ricordati: stesso numero di righe dell'input, codici {{...}} intatti, ogni riga piu' corta dell'inglese, niente trattini lunghi.
Rispondi solo con: ok <numero di righe scritte>
"""


def lock_path(kind: str) -> Path:
    """Un lock per tipo: inc e cstr possono girare in parallelo."""
    return WORK / f".translate-{kind}.lock"


def acquire_lock(kind: str = "inc") -> bool:
    WORK.mkdir(parents=True, exist_ok=True)
    LOCK = lock_path(kind)
    if LOCK.exists():
        try:
            pid = int(LOCK.read_text().split()[0])
            os.kill(pid, 0)
            return False
        except (ValueError, ProcessLookupError, PermissionError):
            pass
    LOCK.write_text(f"{os.getpid()} {time.time()}\n")
    return True


def release_lock(kind: str = "inc") -> None:
    try:
        lock_path(kind).unlink()
    except FileNotFoundError:
        pass


def run_worker(args, batch_path: Path, out_path: Path, log_path: Path) -> bool:
    prompt = PROMPT.format(
        rules_path=WORK / "PROMPT_TRANSLATOR.md",
        batch_path=batch_path,
        out_path=out_path,
    )
    cmd = [
        "hermes",
        "chat",
        "-Q",
        "--ignore-rules",
        "--oneshot",
        "--provider",
        args.provider,
        "--model",
        args.model,
        "--reasoning",
        args.reasoning,
        "--toolsets",
        "file",
        "--run-budget",
        str(args.budget_per_batch),
        "-q",
        prompt,
    ]
    with log_path.open("w", encoding="utf-8") as log:
        try:
            proc = subprocess.run(cmd, stdout=log, stderr=subprocess.STDOUT, timeout=args.budget_per_batch + 60)
        except subprocess.TimeoutExpired:
            return False
    if proc.returncode != 0:
        return False
    return out_path.exists() and out_path.stat().st_size > 0


def validate(out_path: Path, units: dict) -> tuple[int, int]:
    """(righe valide, righe scartate) senza applicare."""
    ok = 0
    bad = 0
    for raw in out_path.read_text(encoding="utf-8").splitlines():
        raw = raw.strip()
        if not raw or raw.startswith(("//", "#", "```")):
            continue
        try:
            row = json.loads(raw)
        except json.JSONDecodeError:
            bad += 1
            continue
        unit = units.get(row.get("id"))
        if unit is None or not isinstance(row.get("it"), list):
            bad += 1
            continue
        try:
            unit.rebuild(row["it"])
        except ValueError:
            bad += 1
            continue
        ok += 1
    return ok, bad


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--kind", choices=["inc", "cstr"], required=True)
    ap.add_argument("--size", type=int, default=20)
    ap.add_argument("--workers", type=int, default=6)
    ap.add_argument("--rounds", type=int, default=10, help="giri di <workers> lotti")
    ap.add_argument("--provider", default="opencode-go")
    ap.add_argument("--model", default="deepseek-v4.1-flash")
    ap.add_argument("--reasoning", default="low")
    ap.add_argument("--budget-per-batch", type=int, default=420)
    ap.add_argument("--model-label", default="")
    args = ap.parse_args()

    # vincolo di Davide: mai glm-5.3-flash / zai per questo lavoro
    if "glm" in args.model.lower() or args.provider == "zai":
        print(json.dumps({"status": "MODELLO_VIETATO", "provider": args.provider, "model": args.model}))
        return 2

    if not acquire_lock(args.kind):
        print(json.dumps({"status": "SKIPPED_LOCKED"}))
        return 0

    for d in (LOG_DIR, BATCH_DIR, RESULT_DIR):
        d.mkdir(parents=True, exist_ok=True)

    summary = {"rounds": 0, "batches_ok": 0, "batches_failed": 0, "applied": 0, "pending_left": None}
    try:
        for round_no in range(args.rounds):
            all_units = store.load_all()
            units = [u for u in all_units.values() if u.kind == args.kind]
            groups = batchmod.pending_groups(units)
            if not groups:
                summary["note"] = "niente da tradurre"
                break
            metrics = batchmod.load_metrics()
            terms = batchmod.glossary_map()
            jobs = []
            for idx in range(args.workers):
                chunk = groups[idx * args.size:(idx + 1) * args.size]
                if not chunk:
                    break
                name = f"{args.kind}-r{round_no:03d}-b{idx:02d}"
                bpath = batchmod.write_batch(args.kind, name, chunk, metrics, terms)
                jobs.append((bpath, RESULT_DIR / f"{name}.jsonl", LOG_DIR / f"{name}.log", name))
            if not jobs:
                break
            print(f"[round {round_no}] {len(jobs)} lotti da {len(jobs[0][0].read_text())} byte", flush=True)

            t0 = time.time()
            with ThreadPoolExecutor(max_workers=args.workers) as pool:
                results = list(pool.map(lambda j: run_worker(args, j[0], j[1], j[2]), jobs))
            elapsed = time.time() - t0

            for ok, (bpath, rpath, lpath, name) in zip(results, jobs):
                if not ok:
                    summary["batches_failed"] += 1
                    print(f"  KO {name}", flush=True)
                    continue
                good, bad = validate(rpath, all_units)
                if good == 0:
                    summary["batches_failed"] += 1
                    print(f"  KO {name}: nessuna riga valida", flush=True)
                    continue
                rows = [json.loads(l) for l in rpath.read_text(encoding="utf-8").splitlines() if l.strip() and l.strip().startswith("{")]
                applied, failed = batchmod.apply_rows(all_units, rows, "translated")
                stamp = f"batch:{name}"
                for row in rows:
                    u = all_units.get(row.get("id"))
                    if u is not None and u.it is not None:
                        u.note = stamp
                summary["applied"] += applied
                summary["batches_ok"] += 1
                print(f"  OK {name}: {applied} applicate, {bad} righe scartate", flush=True)
            fanned = batchmod.fan_out(all_units)
            batchmod.save_all(all_units)
            print(f"  round {round_no}: {round(elapsed)}s, tm +{fanned}", flush=True)
            summary["rounds"] += 1

        units = store.load_all()
        st = store.stats(list(units.values()))
        summary["pending_left"] = st["per_stato"].get("pending", 0)
        summary["stato"] = st["per_stato"]
    finally:
        release_lock(args.kind)

    print(json.dumps(summary, ensure_ascii=False))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
