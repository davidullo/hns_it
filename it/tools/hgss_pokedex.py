#!/usr/bin/env python3
"""
Strumenti per le schermate del Pokedex HGSS (graphics/pokedex/hgss/).

I PNG di quelle cartelle NON sono immagini: sono fogli di tile 8x8, salvati
nell'ordine in cui i tile sono stati aggiunti. Dove finisce ogni tile sullo
schermo lo decide il tilemap (tilemap_*.bin). Per questo, aperto in un editor,
il foglio sembra testo tagliato e spostato: e' normale, non e' corrotto.

  schermate                     elenca le schermate note
  schermata <nome> [-o file]    ricostruisce la schermata leggibile (tilemap + tile + palette)
  estrai <tileset.png> <dir>    scrive ogni tile come tile_NNN.png + foglio indice
  ricomponi <dir> <tileset.png> rimette i tile nell'ordine originale

Flusso di traduzione: guarda la schermata con `schermata`, capisci cosa dice il
testo; poi traduci `estrai` -> modifichi i tile_NNN.png -> `ricomponi`.
Non riordinare mai il foglio a mano: l'ordine dei tile e' l'indice che il
tilemap usa.
"""

import argparse
import os
import struct
import sys

try:
    from PIL import Image, ImageDraw
except ImportError:
    sys.exit("serve Pillow: python3 -m pip install pillow")

RADICE = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
CARTELLA = os.path.join(RADICE, "graphics", "pokedex", "hgss")

# nome -> (tileset, tilemap, palette)   come li carica src/pokedex_plus_hgss.c
SCHERMATE = {
    "lista":         ("tileset_menu_list.png",   "tilemap_list_screen.bin",           "palette_default.gbapal"),
    "lista-deca":    ("tileset_menu_list_DECA.png", "tilemap_list_screen.bin",        "palette_default.gbapal"),
    "ricerca-hoenn": ("tileset_menu_search.png", "tilemap_search_screen_hoenn.bin",   "palette_search_menu.gbapal"),
    "ricerca-naz":   ("tileset_menu_search.png", "tilemap_search_screen_national.bin","palette_search_results.gbapal"),
    "info":          ("tileset_menu1.png",       "tilemap_info_screen.bin",           "palette_default.gbapal"),
    "statistiche":   ("tileset_menu1.png",       "tilemap_stats_screen.bin",          "palette_default.gbapal"),
    "evoluzione":    ("tileset_menu2.png",       "tilemap_evo_screen.bin",            "palette_default.gbapal"),
    "forme":         ("tileset_menu2.png",       "tilemap_forms_screen.bin",          "palette_default.gbapal"),
    "verso":         ("tileset_menu3.png",       "tilemap_cry_screen.bin",            "palette_default.gbapal"),
    "taglia":        ("tileset_menu3.png",       "tilemap_size_screen.bin",           "palette_default.gbapal"),
    "menu":          ("tileset_interface_hns.png", "tilemap_start_menu.bin",          "palette_default.gbapal"),
    "menu-ricerca":  ("tileset_interface_hns.png", "tilemap_start_menu_search_results.bin", "palette_default.gbapal"),
}

NESSUNA = (255, 0, 255)  # magenta: cosi' si vede dove il gioco disegna sopra


def leggi_palette(percorso, quanti=16):
    """gbapal -> lista di tuple RGB."""
    d = open(percorso, "rb").read()
    colori = []
    for i in range(min(quanti, len(d) // 2)):
        v = struct.unpack_from("<H", d, i * 2)[0]
        colori.append((((v) & 31) * 255 // 31,
                        ((v >> 5) & 31) * 255 // 31,
                        ((v >> 10) & 31) * 255 // 31))
    return colori


def carica_tile(percorso):
    """PNG 4bpp (mode P, palette 16 colori) -> lista di tile, ognuno 8 righe di 8 indici."""
    im = Image.open(percorso)
    if im.mode != "P":
        im = im.convert("P", palette=Image.ADAPTIVE, colors=16)
    px = list(im.getdata())
    w, h = im.size
    tile = []
    for ty in range(h // 8):
        for tx in range(w // 8):
            t = []
            for y in range(8):
                riga = []
                for x in range(8):
                    riga.append(px[(ty * 8 + y) * w + (tx * 8 + x)])
                t.append(riga)
            tile.append(t)
    return tile, im


def render(percorso_tileset, percorso_tilemap, percorso_palette, scala=3, righe_visibili=20):
    tile, im = carica_tile(percorso_tileset)
    # le palette caricabili hanno piu' banchi da 16 colori: uso il banco scritto nel tilemap
    banco_palette = leggi_palette(percorso_palette, 256)
    banco_palette = banco_palette + [NESSUNA] * (256 - len(banco_palette))

    tm = open(percorso_tilemap, "rb").read()
    voci = len(tm) // 2
    if righe_visibili and voci % righe_visibili == 0:
        largh = voci // righe_visibili
    elif voci % 32 == 0:
        largh = 32
    else:
        largh = 24
    alt = (voci + largh - 1) // largh

    out = Image.new("RGB", (largh * 8, alt * 8), NESSUNA)
    px = out.load()
    for i in range(voci):
        e = struct.unpack_from("<H", tm, i * 2)[0]
        idx = e & 0x3FF
        if idx >= len(tile):
            continue
        base = e & 0x0FFF              # tile + flip
        flipx, flipy = (e >> 10) & 1, (e >> 11) & 1
        banco = (e >> 12) & 0xF
        tx, ty = i % largh, i // largh
        for y in range(8):
            for x in range(8):
                v = tile[idx][7 - y if flipy else y][7 - x if flipx else x]
                if v == 0 and banco == 0:
                    continue
                px[tx * 8 + x, ty * 8 + y] = banco_palette[banco * 16 + v]
    if scala != 1:
        out = out.resize((out.width * scala, out.height * scala), Image.NEAREST)
    return out


def cmd_schermate(_):
    print("schermate note (tileset / tilemap / palette):")
    for nome in sorted(SCHERMATE):
        t, tm, p = SCHERMATE[nome]
        print("  %-14s %-26s %-30s %s" % (nome, t, tm, p))


def cmd_schermata(a):
    if a.nome not in SCHERMATE:
        sys.exit("schermata sconosciuta: %s (usa `schermate`)" % a.nome)
    t, tm, p = SCHERMATE[a.nome]
    for f in (t, tm, p):
        if not os.path.exists(os.path.join(CARTELLA, f)):
            sys.exit("manca %s" % os.path.join(CARTELLA, f))
    img = render(os.path.join(CARTELLA, t), os.path.join(CARTELLA, tm),
                 os.path.join(CARTELLA, p), scala=a.scala)
    out = a.output or ("/tmp/hgss_%s.png" % a.nome)
    img.save(out)
    print("%s -> %s  (%dx%d)" % (a.nome, out, img.width, img.height))


def cmd_estrai(a):
    tile, im = carica_tile(a.tileset)
    outdir = a.cartella
    os.makedirs(outdir, exist_ok=True)
    for i, t in enumerate(tile):
        t2 = Image.new("P", (8, 8))
        t2.putpalette(im.getpalette()[:48])
        t2.putdata([v for riga in t for v in riga])
        t2.save(os.path.join(outdir, "tile_%03d.png" % i))
    # foglio indice: 16 tile per riga, con il numero sopra
    per = 16
    righe = (len(tile) + per - 1) // per
    cella = a.scala * 8
    fog = Image.new("RGB", (per * cella, righe * (cella + 12)), (255, 0, 255))
    d = ImageDraw.Draw(fog)
    for i in range(len(tile)):
        bx, by = (i % per) * cella, (i // per) * (cella + 12)
        for y in range(8):
            for x in range(8):
                v = tile[i][y][x]
                for dy in range(a.scala):
                    for dx in range(a.scala):
                        bb = (0, 0, 0) if v == 0 else (0, 0, 0)
                        fog.putpixel((bx + x * a.scala + dx, by + y * a.scala + dy),
                                     im.getpalette()[v * 3:v * 3 + 3] if v else (255, 255, 255))
        d.text((bx + 2, by + cella + 1), str(i), fill=(255, 255, 255))
    fog.save(os.path.join(outdir, "_indice.png"))
    print("estratti %d tile in %s/ (tile_NNN.png) + foglio _indice.png" % (len(tile), outdir))
    print("ATTENZIONE: un tile e' condiviso, correggerlo cambia tutte le sue occorrenze a schermo.")


def cmd_ricomponi(a):
    orig, _ = carica_tile(a.tileset)
    im = Image.open(a.tileset)
    w, h = im.size
    fuori = Image.new("P", (w, h))
    fuori.putpalette(im.getpalette()[:48])
    dati = [0] * (w * h)
    mancanti = 0
    for i in range(len(orig)):
        p = os.path.join(a.cartella, "tile_%03d.png" % i)
        if os.path.exists(p):
            t = list(Image.open(p).convert("P").getdata())
        else:
            t = [v for riga in orig[i] for v in riga]
            mancanti += 1
        tx, ty = i % (w // 8), i // (w // 8)
        for y in range(8):
            for x in range(8):
                dati[(ty * 8 + y) * w + (tx * 8 + x)] = t[y * 8 + x]
    fuori.putdata(dati)
    fuori.save(a.tileset)
    print("ricomposto %s (%dx%d, %d tile)" % (a.tileset, w, h, len(orig)))
    if mancanti:
        print("  %d tile non trovati nella cartella: rimessi quelli originali" % mancanti)


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = p.add_subparsers(dest="cmd", required=True)

    s = sub.add_parser("schermate", help="elenco delle schermate note")
    s.set_defaults(func=cmd_schermate)

    s = sub.add_parser("schermata", help="ricostruisce una schermata leggibile")
    s.add_argument("nome")
    s.add_argument("-o", "--output")
    s.add_argument("-z", "--scala", type=int, default=3)
    s.set_defaults(func=cmd_schermata)

    s = sub.add_parser("estrai", help="estrae i tile come PNG singoli")
    s.add_argument("tileset")
    s.add_argument("cartella")
    s.add_argument("-z", "--scala", type=int, default=1, help="scala del foglio indice")
    s.set_defaults(func=cmd_estrai)

    s = sub.add_parser("ricomponi", help="rimette i tile nel tileset")
    s.add_argument("cartella")
    s.add_argument("tileset")
    s.set_defaults(func=cmd_ricomponi)

    a = p.parse_args()
    a.func(a)


if __name__ == "__main__":
    main()
