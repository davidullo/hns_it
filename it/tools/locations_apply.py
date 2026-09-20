#!/usr/bin/env python3
"""Traduce i nomi dei luoghi (mappa, popup, radio) con i nomi ufficiali italiani.

Fonte: Bulbapedia, via i collegamenti interlinguistici verso il wiki italiano
(Pokémon Central Wiki), che usa i nomi ufficiali dei giochi.

Gli id delle sezioni sono ricavati dalle costanti (`MAPSEC_NEW_BARK_TOWN` ->
"New Bark Town"), perche' il JSON delle sezioni non copre Johto.

Uso:
    python3 it/tools/locations_apply.py            # cerca e salva la mappa
    python3 it/tools/locations_apply.py --apply    # scrive nei sorgenti
"""

from __future__ import annotations

import argparse
import json
import re
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "it"))
sys.path.insert(0, str(ROOT / "it" / "tools"))

from location_names_it import chiedi, cerca, titolo_inglese  # noqa: E402

ENTRIES = ROOT / "src" / "data" / "region_map" / "region_map_entries.h"
MAPC = ROOT / "src" / "region_map.c"
RADIO = ROOT / "src" / "data" / "text" / "radio_strings.h"
MAPPA_IT = ROOT / "it" / "data" / "locations_it.json"
LIMITE = 20


def da_costante(cost: str) -> str:
    """MAPSEC_NEW_BARK_TOWN -> NEW BARK TOWN"""
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


def carica_mappa() -> dict[str, str]:
    if MAPPA_IT.exists():
        return json.loads(MAPPA_IT.read_text(encoding="utf-8"))
    return {}


def cerca_tutti(nomi: list[str], mappa: dict[str, str]) -> dict[str, str]:
    for i, nome in enumerate(nomi, 1):
        if nome in mappa:
            continue
        titolo = titolo_inglese(nome)
        it = None
        try:
            it = chiedi([titolo]).get(titolo)
            if not it:
                it = cerca(titolo)
        except Exception:  # noqa: BLE001
            time.sleep(1.0)
        if it and not re.match(r"^(Elenco|Lista|Categoria)\b", it, re.I):
            mappa[nome] = it
        if i % 25 == 0:
            print(f"  {i}/{len(nomi)} cercati, {len(mappa)} nomi in mappa")
            MAPPA_IT.write_text(json.dumps(mappa, ensure_ascii=False, indent=1, sort_keys=True), encoding="utf-8")
        time.sleep(0.15)
    MAPPA_IT.write_text(json.dumps(mappa, ensure_ascii=False, indent=1, sort_keys=True), encoding="utf-8")
    return mappa


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--apply", action="store_true")
    args = ap.parse_args()

    testo = ENTRIES.read_text(encoding="utf-8")
    costanti = re.findall(r"\[(MAPSEC_[A-Z0-9_]+)\]\s*=\s*\{", testo)
    nomi = sorted({da_costante(c) for c in costanti})
    print(f"sezioni nella mappa: {len(costanti)} | nomi distinti: {len(nomi)}")

    mappa = carica_mappa()
    mappa = cerca_tutti(nomi, mappa)
    senza = [n for n in nomi if n not in mappa]
    print(f"con nome ufficiale italiano: {len(nomi) - len(senza)} | senza: {len(senza)}")
    print("senza:", senza[:25])

    # nome italiano attuale -> nome nuovo, per le tabelle che non usano le costanti
    it_vecchi = {}
    for m in re.finditer(r"\[(MAPSEC_[A-Z0-9_]+)\]\s*=\s*\{(.*?)\n    \}", testo, re.S):
        nome_it = re.search(r'\.name = COMPOUND_STRING\("([^"]*)"\)', m.group(2))
        if nome_it:
            it_vecchi[nome_it.group(1)] = mappa.get(da_costante(m.group(1)))

    if not args.apply:
        return 0

    # 1. region_map_entries.h e region_map.c: per costante
    for percorso in (ENTRIES, MAPC):
        t = percorso.read_text(encoding="utf-8")
        def sostituisci(m):
            cost = m.group(1)
            it = mappa.get(da_costante(cost))
            if not it:
                return m.group(0)
            nuovo = it.upper()
            if len(nuovo) > LIMITE:
                nuovo = accorcia(nuovo, LIMITE)
            return m.group(0).replace(m.group(2), f'COMPOUND_STRING("{nuovo}")')
        t2 = re.sub(
            r"\[(MAPSEC_[A-Z0-9_]+)\]\s*=\s*\{(.*?)\n    \}",
            lambda m: m.group(0) if not m.group(2) else sostituisci(m),
            t,
            flags=re.S,
        )
        percorso.write_text(t2, encoding="utf-8")
        print("aggiornato", percorso.relative_to(ROOT))

    # 2. radio: i nomi dei luoghi come parole d'ordine, sostituzione per testo
    t = RADIO.read_text(encoding="utf-8")
    for vecchio, nuovo in it_vecchi.items():
        if not nuovo or vecchio == nuovo.upper():
            continue
        t = t.replace(f'"{vecchio}"', f'"{nuovo.upper()}"')
    RADIO.write_text(t, encoding="utf-8")
    print("aggiornato", RADIO.relative_to(ROOT))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
