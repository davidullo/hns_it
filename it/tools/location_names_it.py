#!/usr/bin/env python3
"""Trova i nomi ufficiali italiani dei luoghi tramite Bulbapedia (interlink).

Bulbapedia ha il collegamento interlinguistico verso le altre wiki: chiedendo
`prop=langlinks&lllang=it` su un titolo inglese si ottiene il titolo italiano
(Pokémon Central Wiki), che e' il nome ufficiale usato nei giochi.

Uso:  python3 it/tools/location_names_it.py
Scrive: it/data/locations_it.json  {nome inglese: nome italiano}
"""

from __future__ import annotations

import json
import re
import time
import urllib.parse
import urllib.request
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
OUT = ROOT / "it" / "data" / "locations_it.json"
API = "https://bulbapedia.bulbagarden.net/w/api.php"
UA = "hns-it-translation/1.0 (translation helper; contact: crostasuperchill@gmail.com)"


def titolo_inglese(nome: str) -> str:
    """NEW BARK TOWN -> New Bark Town, MT. SILVER -> Mt. Silver."""
    fuori = []
    for parola in nome.split():
        fuori.append(parola.capitalize() if len(parola) > 1 else parola)
    return " ".join(fuori)


def chiedi(titoli: list[str]) -> dict[str, str]:
    q = {
        "action": "query",
        "titles": "|".join(titoli),
        "prop": "langlinks",
        "lllang": "it",
        "redirects": "1",
        "format": "json",
    }
    url = API + "?" + urllib.parse.urlencode(q)
    req = urllib.request.Request(url, headers={"User-Agent": UA})
    with urllib.request.urlopen(req, timeout=30) as fh:
        dati = json.load(fh)
    res = {}
    for pagina in dati.get("query", {}).get("pages", {}).values():
        titolo = pagina.get("title")
        ll = pagina.get("langlinks")
        if titolo and ll:
            res[titolo] = ll[0]["*"]
    return res


def cerca(titolo: str) -> str | None:
    """Fallback: cerca il titolo e prendi il link italiano del primo risultato."""
    q = {
        "action": "query",
        "list": "search",
        "srsearch": titolo,
        "srlimit": "1",
        "format": "json",
    }
    url = API + "?" + urllib.parse.urlencode(q)
    req = urllib.request.Request(url, headers={"User-Agent": UA})
    with urllib.request.urlopen(req, timeout=30) as fh:
        dati = json.load(fh)
    hit = dati.get("query", {}).get("search", [])
    if not hit:
        return None
    return chiedi([hit[0]["title"]]).get(hit[0]["title"])


def main() -> int:
    nomi = json.loads((ROOT / "it" / "data" / "locations_en.json").read_text(encoding="utf-8"))
    trovati: dict[str, str] = {}
    mancanti: list[str] = []
    for i, nome in enumerate(nomi, 1):
        titolo = titolo_inglese(nome)
        res = {}
        for tentativo in range(2):
            try:
                res = chiedi([titolo])
                break
            except Exception:  # noqa: BLE001
                time.sleep(1.5)
        it = res.get(titolo)
        if not it:
            try:
                it = cerca(titolo)
            except Exception:  # noqa: BLE001
                it = None
            time.sleep(0.3)
        if it:
            trovati[nome] = it
        else:
            mancanti.append(nome)
        if i % 25 == 0:
            print(f"  {i}/{len(nomi)}: trovati {len(trovati)}")
        time.sleep(0.15)

    OUT.write_text(json.dumps(trovati, ensure_ascii=False, indent=1, sort_keys=True), encoding="utf-8")
    print(f"italiani trovati: {len(trovati)} | senza: {len(mancanti)}")
    print("senza nome:", mancanti[:30])
    print("esempi:", [(k, v) for k, v in list(trovati.items())[:8]])
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
