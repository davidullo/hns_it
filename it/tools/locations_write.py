#!/usr/bin/env python3
"""Scrive i nomi italiani dei luoghi nei punti giusti del progetto.

- `src/data/region_map/region_map_sections.json`: e' la fonte vera, da li' il
  build genera `region_map_entries.h` (che infatti e' in .gitignore)
- `src/region_map.c`: le voci Johto scritte a mano
- `src/data/text/radio_strings.h`: i nomi usati come parole d'ordine alla radio

Uso: python3 it/tools/locations_write.py [--apply]
"""

from __future__ import annotations

import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
SEZIONI = ROOT / "src" / "data" / "region_map" / "region_map_sections.json"
REGION = ROOT / "src" / "region_map.c"
RADIO = ROOT / "src" / "data" / "text" / "radio_strings.h"
MAPPA_IT = ROOT / "it" / "data" / "locations_it.json"
LIMITE = 20


def chiave(cost: str) -> str:
    nome = cost.replace("MAPSEC_", "").replace("_", " ")
    nome = re.sub(r"\bMT\b", "MT.", nome)
    return nome


def accorcia(nome: str, tetto: int) -> str:
    parole = nome.split()
    for taglio in range(1, len(parole)):
        cand = " ".join(parole[:-taglio])
        if len(cand) <= tetto:
            return cand
    return nome


def traduzione(nome_en: str, mappa: dict[str, str]) -> str | None:
    """Cerca il nome italiano, tollerando suffissi tipo "FRLG", "HNS", "2"."""
    candidati = [nome_en]
    base = re.sub(r"\s+(FRLG|HNS)$", "", nome_en)
    base = re.sub(r"\s*\d+$", "", base)
    if base != nome_en:
        candidati.append(base)
    for cand in candidati:
        it = mappa.get(cand)
        if it:
            return it.upper() if len(it) + 1 <= LIMITE else accorcia(it.upper(), LIMITE - 1)
    return None


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--apply", action="store_true")
    args = ap.parse_args()

    mappa = json.loads(MAPPA_IT.read_text(encoding="utf-8"))
    dati = json.loads(SEZIONI.read_text(encoding="utf-8"))

    cambi: list[tuple[str, str, str]] = []
    for gruppo in ("map_sections", "hns_map_sections"):
        for voce in dati.get(gruppo, []):
            en = voce.get("name")
            if not en:
                continue
            nuovo = traduzione(en, mappa)
            if nuovo and nuovo != en:
                cambi.append((voce["id"], en, nuovo))
    print(f"sezioni da rinominare nel json: {len(cambi)}")
    for i, (sid, en, it) in enumerate(cambi[:5]):
        print(f"   {sid}: {en} -> {it}")

    if not args.apply:
        return 0

    for gruppo in ("map_sections", "hns_map_sections"):
        for voce in dati.get(gruppo, []):
            en = voce.get("name")
            if not en:
                continue
            nuovo = traduzione(en, mappa)
            if nuovo:
                voce["name"] = nuovo
    SEZIONI.write_text(json.dumps(dati, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print("scritto", SEZIONI.relative_to(ROOT))

    # region_map.c: sostituisco solo la stringa dentro COMPOUND_STRING(...)
    t = REGION.read_text(encoding="utf-8")
    def sostituisci(m: re.Match) -> str:
        cost = m.group(1)
        nuovo = traduzione(chiave(cost), mappa)
        if not nuovo:
            return m.group(0)
        return f'{m.group(2)}COMPOUND_STRING("{nuovo}")'
    t2, n = re.subn(
        r"\[(MAPSEC_[A-Z0-9_]+)\][^=]*=\s*\{([^}]*?)COMPOUND_STRING\(\"[^\"]*\"\)",
        sostituisci,
        t,
        flags=re.S,
    )
    REGION.write_text(t2, encoding="utf-8")
    print(f"region_map.c: {n} voci toccate")

    # radio: i nomi dei luoghi come parole d'ordine
    vecchi = {}
    for cost, en, nuovo in cambi:
        vecchi.setdefault(en, nuovo)
    t = RADIO.read_text(encoding="utf-8")
    n = 0
    for vecchio, nuovo in vecchi.items():
        if vecchio != nuovo:
            t, k = re.subn(rf'"{re.escape(vecchio)}"', f'"{nuovo}"', t)
            n += k
    RADIO.write_text(t, encoding="utf-8")
    print(f"radio_strings.h: {n} sostituzioni")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
