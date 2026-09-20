#!/usr/bin/env python3
"""Controlla gli array di stringhe a dimensione fissa nei sorgenti.

Il compilatore muore con `excess elements in array initializer` quando una
traduzione non entra in un array tipo `gFrontAnimNames[][34]`. Il dataset dei
limiti non lo vede, perche' li' il nome non e' un campo ma una voce di array:
questo controllo legge le dichiarazioni, misura ogni voce e dice quali
sfondano.

Uso:  python3 it/tools/check_string_arrays.py [--fix]

Senza `--fix` esce con codice 1 se trova qualcosa (cosi' il cron se ne accorge).
Con `--fix` accorcia le voci troppo lunghe togliendo parole dalla coda (o dalla
testa) e aggiorna lo store, cosi' il prossimo `inject` le scrive accorciate.
"""

from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
IT = ROOT / "it"
sys.path.insert(0, str(IT))

ARRAY_RE = re.compile(r"\[\]\s*\[([0-9 +]+)\]\s*=\s*\{")
ENTRY_RE = re.compile(r'\[([A-Z0-9_]+)\]\s*=\s*_\("([^"]*)"\)')


def trova_voci(testo: str):
    """(nome_array, dimensione, [(voce, testo), ...]) per ogni array di stringhe."""
    for m in ARRAY_RE.finditer(testo):
        try:
            size = eval(m.group(1))  # noqa: S307 - solo somme di interi
        except Exception:
            continue
        fine = testo.find("\n};", m.start())
        if fine < 0:
            continue
        inizio_riga = testo.rfind("\n", 0, m.start()) + 1
        nome = re.findall(r"(\w+)\s*$", testo[inizio_riga : m.start()].strip())
        yield (nome[0] if nome else "?"), size, ENTRY_RE.findall(testo[m.start() : fine])


def accorcia(testo: str, tetto: int) -> str | None:
    parole = testo.split()
    for taglio in range(1, len(parole)):
        if len(" ".join(parole[:-taglio])) <= tetto:
            return " ".join(parole[:-taglio])
    for taglio in range(1, len(parole)):
        if len(" ".join(parole[taglio:])) <= tetto:
            return " ".join(parole[taglio:])
    return None


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--fix", action="store_true")
    args = ap.parse_args()

    store = batching = None
    if args.fix:
        from hnsit import batching as batching_mod
        from hnsit import store as store_mod

        store, batching = store_mod, batching_mod
        unita = store.load_all()

    problemi = 0
    for percorso in sorted((ROOT / "src").rglob("*.c")):
        try:
            testo = percorso.read_text(encoding="utf-8")
        except Exception:
            continue
        if '_("' not in testo:
            continue
        for nome, size, voci in trova_voci(testo):
            tetto = size - 1  # il terminatore
            for voce, it_text in voci:
                if len(it_text) <= tetto:
                    continue
                problemi += 1
                print(f"{percorso}: {nome}[][{size}] {voce}: {len(it_text)} byte (tetto {tetto})")
                if not args.fix:
                    continue
                nuovo = accorcia(it_text, tetto)
                if nuovo is None:
                    print(f"    non accorciabile: \"{it_text}\"")
                    continue
                cand = [x for x in unita.values() if x.it == [it_text] and x.file.endswith(str(percorso.relative_to(ROOT)))]
                if not cand:
                    print(f"    nessuna unita' nello store con \"{it_text}\"")
                    continue
                u = cand[0]
                u.prev_it = u.it
                u.it = [nuovo]
                u.note = "accorciata per l'array"
                u.attempts = 0
                print(f"    -> \"{nuovo}\" ({len(nuovo)} byte)")
    if args.fix and problemi:
        batching.save_all(unita)
    return 1 if problemi else 0


if __name__ == "__main__":
    raise SystemExit(main())
