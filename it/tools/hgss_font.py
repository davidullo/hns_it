#!/usr/bin/env python3
"""
Estrae e ricompone il font inciso nelle schermate del Pokedex HGSS.

Le scritte di quelle schermate non sono stringhe: sono pixel dentro i tileset.
Il font e' un serif con celle 6x12, passo 6 px per lettera e 3 px per lo spazio,
disegnato a partire da x=16 dentro il riquadro. I tile sono da 8x8, quindi le
lettere NON cadono sui confini dei tile: da qui l'effetto "testo spostato ogni
8 pixel". Per questo non si possono scambiare i tile fra loro, va ricostruito
il bitmap e ritagliato di nuovo.

Uso:
  estrai <tileset.png> <tilemap.bin> <riga> "<testo>"    estrae e verifica i glifi
  font   <spec.json> <font.json>                          costruisce il font da piu' voci
  prova  <font.json> "<testo>"                            anteprima ASCII di una stringa

Spec JSON: [{"tileset": "...", "tilemap": "...", "riga": 1, "testo": "BACK TO LIST", "x0": 16}, ...]
"""

import json
import os
import struct
import sys

try:
    from PIL import Image
except ImportError:
    sys.exit("serve Pillow")

RADICE = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
CARTELLA = os.path.join(RADICE, "graphics", "pokedex", "hgss")

# metriche del font HGSS del Pokedex, trovate per fitta (errore di ricostruzione 0)
X0, PASSO, PASSO_SPAZIO, Y0, ALTEZZA, LARGHEZZA = 16, 6, 3, 1, 12, 6
COLORE_TESTO = 3          # indice di palette del testo
COLORE_SFONDO = 1
LARG_BANDA = 112
ALTEZZA_BANDA = 16


def _tile(tileset, i, cache={}):
    chiave = tileset
    if chiave not in cache:
        im = Image.open(tileset)
        px = list(im.getdata())
        w, h = im.size
        t = []
        for ty in range(h // 8):
            for tx in range(w // 8):
                t.append([[px[(ty * 8 + y) * w + tx * 8 + x] for x in range(8)] for y in range(8)])
        cache[chiave] = t
    return cache[chiave][i]


def banda(tileset, tilemap, riga, col0=16, col1=30):
    """bitmap 16 x 112 del blocco di due tile row, con x=0 sul bordo del riquadro."""
    tm = open(tilemap, "rb").read()
    larghezza_mappa = len(tm) // 2 // 20 if (len(tm) // 2) % 20 == 0 else 32
    righe = []
    for r in (riga, riga + 1):
        for y in range(8):
            rr = []
            for c in range(col0, col1):
                e = struct.unpack_from("<H", tm, (r * larghezza_mappa + c) * 2)[0] & 0x3FF
                t = _tile(tileset, e)
                for x in range(8):
                    rr.append(1 if t[y][x] == COLORE_TESTO else 0)
            righe.append(rr)
    return righe


def estrai(bm, testo, x0=X0, passo=PASSO, ps=PASSO_SPAZIO):
    """ritorna (elenco (carattere, x, glifo), incoerenze)"""
    font = {}
    incoerenze = []
    x = x0
    for ch in testo:
        if ch == " ":
            x += ps
            continue
        if x + LARGHEZZA > LARG_BANDA:
            incoerenze.append((ch, "fuori banda"))
            break
        g = tuple(tuple(bm[Y0 + yy][x + xx] for xx in range(LARGHEZZA)) for yy in range(ALTEZZA))
        if ch in font and font[ch] != g:
            incoerenze.append((ch, "glifo diverso da un'altra voce"))
        font.setdefault(ch, g)
        x += passo
    return font, incoerenze


def ricostruisci(font, testo, x0=X0):
    righe = [[0] * LARG_BANDA for _ in range(ALTEZZA_BANDA)]
    x = x0
    for ch in testo:
        if ch == " ":
            x += PASSO_SPAZIO
            continue
        if ch not in font:
            return None
        g = font[ch]
        for yy in range(ALTEZZA):
            for xx in range(LARGHEZZA):
                if g[yy][xx] and 0 <= Y0 + yy < ALTEZZA_BANDA and x + xx < LARG_BANDA:
                    righe[Y0 + yy][x + xx] = 1
        x += PASSO
    return righe


def cmd_estrai(a):
    t = os.path.join(CARTELLA, a.tileset) if not os.path.isabs(a.tileset) else a.tileset
    m = os.path.join(CARTELLA, a.tilemap) if not os.path.isabs(a.tilemap) else a.tilemap
    bm = banda(t, m, a.riga)
    font, inc = estrai(bm, a.testo)
    print("caratteri estratti:", "".join(sorted(font)))
    print("incoerenze:", inc or "nessuna")
    ric = ricostruisci(font, a.testo)
    err = sum(1 for y in range(ALTEZZA_BANDA) for x in range(LARG_BANDA) if bm[y][x] != ric[y][x])
    print("errore di ricostruzione:", err, "pixel")
    for ch in sorted(font):
        print("%r" % ch)
        for riga in font[ch]:
            print("   " + "".join("#" if v else "." for v in riga))


def cmd_font(a):
    spec = json.load(open(a.spec))
    font = {}
    problemi = []
    for voce in spec:
        t = os.path.join(CARTELLA, voce["tileset"])
        m = os.path.join(CARTELLA, voce["tilemap"])
        bm = banda(t, m, voce["riga"], voce.get("col0", 16), voce.get("col1", 30))
        f, inc = estrai(bm, voce["testo"], voce.get("x0", X0))
        ric = ricostruisci(f, voce["testo"], voce.get("x0", X0))
        err = sum(1 for y in range(ALTEZZA_BANDA) for x in range(LARG_BANDA) if bm[y][x] != ric[y][x])
        if err:
            problemi.append((voce["testo"], err))
        for ch, g in f.items():
            font.setdefault(ch, g)
    json.dump({ch: [list(r) for r in g] for ch, g in font.items()}, open(a.dest, "w"))
    print("font salvato in %s con %d caratteri: %s" % (a.dest, len(font), "".join(sorted(font))))
    if problemi:
        print("voci con errore di ricostruzione (metriche da rivedere):")
        for testo, err in problemi:
            print("   %-18s %d pixel" % (testo, err))


def cmd_prova(a):
    d = json.load(open(a.font))
    font = {ch: tuple(tuple(r) for r in g) for ch, g in d.items()}
    for testo in a.testi:
        mancanti = sorted({c for c in testo if c != " " and c not in font})
        if mancanti:
            print("%-20s mancano i glifi: %s" % (testo, " ".join(mancanti)))
            continue
        bm = ricostruisci(font, testo)
        print("%s  (larghezza %d px)" % (testo, 16 + sum(PASSO_SPAZIO if c == " " else PASSO for c in testo)))
        for riga in bm[Y0:Y0 + ALTEZZA]:
            print("   " + "".join("#" if v else "." for v in riga[:100]))
        print()


def main():
    import argparse
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = p.add_subparsers(dest="cmd", required=True)
    s = sub.add_parser("estrai"); s.add_argument("tileset"); s.add_argument("tilemap"); s.add_argument("riga", type=int); s.add_argument("testo"); s.set_defaults(func=cmd_estrai)
    s = sub.add_parser("font"); s.add_argument("spec"); s.add_argument("dest"); s.set_defaults(func=cmd_font)
    s = sub.add_parser("prova"); s.add_argument("font"); s.add_argument("testi", nargs="+"); s.set_defaults(func=cmd_prova)
    a = p.parse_args()
    a.func(a)


if __name__ == "__main__":
    main()
