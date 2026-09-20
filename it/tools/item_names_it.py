#!/usr/bin/env python3
"""Sostituisce i nomi degli oggetti in src/data/items.h con quelli ufficiali italiani.

Fonte: i dump PokeAPI in it/data/pokeapi/item_names.csv (localizzazioni ufficiali
dei giochi). Il collegamento avviene per nome inglese, normalizzato (apostrofi
tipografici, accenti, punteggiatura).

Regole:
- i nomi si scrivono in maiuscolo (come nel gioco)
- tetto di ITEM_NAME_LENGTH = 20 caratteri, quindi al massimo 19 + terminatore
- se il nome ufficiale sfonda, si accorcia togliendo parole dalla coda
- gli oggetti inventati dalla hack (pietre mega, oggetti AUX, ecc.) hanno una
  traduzione scritta a mano qui sotto, prese dal significato della versione
  tedesca e dalla descrizione italiana dell'oggetto

Uso:  python3 it/tools/item_names_it.py [--apply]
"""

from __future__ import annotations

import argparse
import csv
import re
import sys
import unicodedata
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
IT_DATA = ROOT / "it" / "data"
ITEMS = ROOT / "src" / "data" / "items.h"
LIMITE = 20  # ITEM_NAME_LENGTH: 19 caratteri utili + terminatore

# Oggetti senza nome ufficiale italiano: traduzione a mano.
MANUALI = {
    "ITEM_ESCAPE_ROPE": "FUNE DI FUGA",
    "ITEM_POKEMON_BOX_LINK": "BOX POKéMON",
    "ITEM_MYSTIC_TICKET": "BIGLIETTO MISTERO",
    "ITEM_AURORA_TICKET": "BIGLIETTO AURORA",
    "ITEM_BERSERK_GENE": "GENE FOLLIA",
    "ITEM_FRESH_START_MOCHI": "MOCHI RIPARTENZA",
    "ITEM_STELLAR_TERA_SHARD": "SCHEGGIA ASTRALE",
    "ITEM_JUBILIFE_MUFFIN": "MUFFIN GIUBILO",
    "ITEM_REMEDY": "RIMEDIO",
    "ITEM_FINE_REMEDY": "SUPER RIMEDIO",
    "ITEM_SUPERB_REMEDY": "IPER RIMEDIO",
    "ITEM_AUX_EVASION": "VITAMINA ELUS.",
    "ITEM_AUX_GUARD": "VITAMINA DIF.",
    "ITEM_AUX_POWER": "VITAMINA ATT.",
    "ITEM_AUX_POWERGUARD": "VITAMINA MISTA",
    "ITEM_CHOICE_DUMPLING": "GNOCCO SCELTA",
    "ITEM_SWAP_SNACK": "SPUNTINO SCAMBIO",
    "ITEM_TWICE_SPICED_RADISH": "RAVANELLO SPEZIATO",
    "ITEM_POKESHI_DOLL": "BAMBOLA POKéSHI",
    "ITEM_EXP_SHARE_SMALL": "CONDIVIS. ESP. S",
    "ITEM_HEALING_HEART": "CUORE CURATIVO",
    "ITEM_INFINITE_REPEL": "REPELL. INFINITO",
    "ITEM_INFINITE_RARE_CANDIES": "BOX CARAMELLE",
    "ITEM_SECRET_POTION": "POZIONE SEGRETA",
    "ITEM_SQUIRT_BOTTLE": "SPRUZZABOTTIGLIA",
    "ITEM_LEADERS_CREST": "EMBLEMA CAPO",
    # ufficiali troppo lunghi per i 19 caratteri: accorciati a mano
    "ITEM_GIMMIGHOUL_COIN": "MONETA GIMMIGHOUL",
    "ITEM_SWIFT_MOCHI": "MOCHI REAZIONE",
    # questi restano come sono: sigle e segnaposto
    "ITEM_GS_BALL": "GS BALL",
    "ITEM_RADIO": "RADIO",
    "ITEM_GB_PLAYER": "GB PLAYER",
    "ITEM_UNUSED_BERRY_2": "????????",
    "ITEM_UNUSED_BERRY_3": "????????",
}


def normalizza(testo: str) -> str:
    testo = (
        testo.replace("\u2019", "'")
        .replace("\u2018", "'")
        .replace("\u201c", '"')
        .replace("\u201d", '"')
    )
    testo = unicodedata.normalize("NFKD", testo)
    testo = "".join(c for c in testo if not unicodedata.combining(c))
    testo = re.sub(r"[^a-z0-9 ]+", " ", testo.lower())
    return re.sub(r"\s+", " ", testo).strip()


def nomi_ufficiali() -> dict[str, str]:
    per_id: dict[str, dict[str, str]] = {}
    with (IT_DATA / "pokeapi" / "item_names.csv").open(encoding="utf-8") as fh:
        for riga in csv.DictReader(fh):
            per_id.setdefault(riga["item_id"], {})[riga["local_language_id"]] = riga["name"]
    fuori = {}
    for lingue in per_id.values():
        if "9" in lingue and "8" in lingue:
            fuori[normalizza(lingue["9"])] = lingue["8"].strip()
    return fuori


def accorcia(nome: str, tetto: int) -> str:
    parole = nome.split()
    for taglio in range(1, len(parole)):
        cand = " ".join(parole[:-taglio])
        if len(cand) <= tetto:
            return cand
    return nome


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--apply", action="store_true")
    args = ap.parse_args()

    ufficiali = nomi_ufficiali()
    testo = ITEMS.read_text(encoding="utf-8")
    pezzi = re.split(r"\n    \[(ITEM_[A-Z0-9_]+)\]\s*=\s*\{", testo)

    cambi, accorciati, tenuti, senza_fonte = [], [], [], []
    for i in range(1, len(pezzi), 2):
        cost, corpo = pezzi[i], pezzi[i + 1]
        m = re.search(r'\.name\s*=\s*ITEM_NAME\("([^"]*)"\)', corpo)
        if not m:
            continue
        attuale = m.group(1)
        if cost in MANUALI:
            nuovo = MANUALI[cost]
        else:
            it = ufficiali.get(normalizza(attuale))
            if not it:
                if re.search(r"ITE( [XYZ])?$", attuale):
                    tenuti.append((cost, attuale))  # pietre mega: nome gia' italiano
                    continue
                senza_fonte.append((cost, attuale))
                continue
            nuovo = it.upper()
            # il gioco scrive POKé BALL con la e minuscola accentata: il glifo
            # maiuscolo nel font non c'e', quindi si tiene la convenzione
            nuovo = nuovo.replace("É", "é")
        if len(nuovo) + 1 > LIMITE:
            corto = accorcia(nuovo, LIMITE - 1)
            accorciati.append((cost, nuovo, corto))
            nuovo = corto
        if nuovo != attuale:
            cambi.append((cost, attuale, nuovo))

    print(f"nomi ufficiali disponibili: {len(ufficiali)}")
    print(f"da cambiare: {len(cambi)} | accorciati: {len(accorciati)} | "
          f"pietre mega lasciate: {len(tenuti)} | senza fonte: {len(senza_fonte)}")
    for cost, vecchio, nuovo in accorciati:
        print(f"  accorciato: {cost.replace('ITEM_', '')}: {vecchio} -> {nuovo}")
    for cost, nome in senza_fonte:
        print(f"  senza fonte: {cost.replace('ITEM_', '')} | {nome}")

    if args.apply:
        # sostituzione mirata per blocco, per non toccare omonimi altrove
        pezzi = re.split(r"(\n    \[ITEM_[A-Z0-9_]+\]\s*=\s*\{)", testo)
        for i in range(1, len(pezzi), 2):
            cost = re.search(r"\[(ITEM_[A-Z0-9_]+)\]", pezzi[i]).group(1)
            for c, vecchio, nuovo in cambi:
                if c != cost:
                    continue
                pezzi[i + 1] = pezzi[i + 1].replace(
                    f'ITEM_NAME("{vecchio}")', f'ITEM_NAME("{nuovo}")', 1
                )
        ITEMS.write_text("".join(pezzi), encoding="utf-8")
        print(f"scritti {len(cambi)} nomi in {ITEMS.relative_to(ROOT)}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
