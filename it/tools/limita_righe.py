#!/usr/bin/env python3
"""Misura e ripara le righe delle descrizioni di oggetti e mosse.

Limite: 18 caratteri per riga (19 ammesso nei casi estremi).
Uso:
    python3 it/tools/limita_righe.py --misura            # solo report
    python3 it/tools/limita_righe.py --file src/data/items.h
    python3 it/tools/limita_righe.py --file src/data/items.h --max 19 --scrivi
"""
import argparse, json, re, sys

LIMITE = 18
MASSIMO = 19

# righe di testo dentro le descrizioni: "....\n"  oppure "...."),"
RE_RIGA = re.compile(r'^(?P<prefisso>\s*)"(?P<testo>[^"]*?)(?P<coda>\\n|\\p|)"(?P<post>.*)$')

def righe_descrizioni(percorso):
    for i, r in enumerate(open(percorso, encoding="utf-8").read().split("\n"), 1):
        m = RE_RIGA.match(r)
        if not m:
            continue
        testo = m.group("testo")
        # salto i codici {..} che non contano come caratteri visibili
        visibile = re.sub(r"\{[^}]*\}", "", testo)
        yield i, m, testo, visibile

def misura(percorso, massimo=MASSIMO):
    lunghe = []
    for i, m, testo, visibile in righe_descrizioni(percorso):
        if len(visibile) > massimo:
            lunghe.append({"riga": i, "len": len(visibile), "testo": testo})
    return lunghe

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--file", action="append", default=[])
    ap.add_argument("--max", type=int, default=MASSIMO)
    ap.add_argument("--scrivi", action="store_true")
    ap.add_argument("--json")
    a = ap.parse_args()
    files = a.file or ["src/data/items.h", "src/data/moves_info.h"]
    tutto = {}
    for f in files:
        if not os.path.exists(f):
            print("manca:", f); continue
        lunghe = misura(f, a.max)
        tutto[f] = lunghe
        print("%-28s righe oltre %d caratteri: %d" % (f, a.max, len(lunghe)))
        for x in lunghe[:5]:
            print("   riga %6d  %2d char  %s" % (x["riga"], x["len"], x["testo"]))
    if a.json:
        json.dump(tutto, open(a.json, "w"), ensure_ascii=False, indent=1)
        print("scritto", a.json)

if __name__ == "__main__":
    import os
    main()
