#!/usr/bin/env python3
"""UPS: crea e applica patch nel formato usato dalle romhack (UPS1).

Formato verificato sul codice di flips (libups.cpp), non a memoria:

    "UPS1"
    <dimensione sorgente> <dimensione risultato>   (interi a lunghezza variabile)
    ripetuto:
        <byte da lasciare come sono>               (varint)
        <byte XOR, fino a un byte 0 che chiude il blocco>
    <CRC32 sorgente> <CRC32 risultato> <CRC32 della patch>

Uso:
    python3 it/tools/ups_it.py --create originale.gba modificata.gba patch.ups
    python3 it/tools/ups_it.py --apply originale.gba patch.ups uscita.gba
"""

from __future__ import annotations

import argparse
import struct
import zlib
from pathlib import Path


def scrivi_varint(n: int) -> bytes:
    out = bytearray()
    while True:
        x = n & 0x7F
        n >>= 7
        if n == 0:
            out.append(0x80 | x)
            break
        out.append(x)
        n -= 1
    return bytes(out)


def leggi_varint(dati: bytes, pos: int) -> tuple[int, int]:
    valore = 0
    shift = 1
    while True:
        x = dati[pos]
        pos += 1
        valore += (x & 0x7F) * shift
        if x & 0x80:
            return valore, pos
        shift <<= 7
        valore += shift


def crea(sorgente: bytes, modificata: bytes) -> bytes:
    out = bytearray(b"UPS1")
    out += scrivi_varint(len(sorgente))
    out += scrivi_varint(len(modificata))
    size = max(len(sorgente), len(modificata))
    src = sorgente.ljust(size, b"\x00")
    tgt = modificata.ljust(size, b"\x00")
    pos = 0
    while pos < size:
        salta = 0
        while pos < size and src[pos] == tgt[pos]:
            pos += 1
            salta += 1
        if pos >= size:
            break
        out += scrivi_varint(salta)
        while pos < size and src[pos] != tgt[pos]:
            out.append(src[pos] ^ tgt[pos])
            pos += 1
        out.append(0)  # chiude il blocco: il decodificatore si ferma qui
        if pos < size:
            pos += 1  # anche il byte di chiusura scrive una posizione (out ^ 0)
    out += struct.pack("<I", zlib.crc32(sorgente) & 0xFFFFFFFF)
    out += struct.pack("<I", zlib.crc32(modificata) & 0xFFFFFFFF)
    out += struct.pack("<I", zlib.crc32(bytes(out)) & 0xFFFFFFFF)
    return bytes(out)


def applica(sorgente: bytes, patch: bytes) -> bytes:
    if patch[:4] != b"UPS1":
        raise ValueError("non e' una patch UPS")
    pos = 4
    src_size, pos = leggi_varint(patch, pos)
    tgt_size, pos = leggi_varint(patch, pos)
    if len(sorgente) != src_size:
        raise ValueError(f"la ROM ha {len(sorgente)} byte, la patch ne vuole {src_size}")
    fine = len(patch) - 12
    crc_src, crc_tgt, crc_patch = struct.unpack("<III", patch[fine : fine + 12])
    if zlib.crc32(patch[:-4]) & 0xFFFFFFFF != crc_patch:
        raise ValueError("patch danneggiata (CRC32 interno diverso)")
    if zlib.crc32(sorgente) & 0xFFFFFFFF != crc_src:
        raise ValueError("CRC32 della ROM diverso da quello della patch")

    src = sorgente.ljust(tgt_size, b"\x00")
    out = bytearray(tgt_size)
    off = 0
    while pos < fine:
        salta, pos = leggi_varint(patch, pos)
        for _ in range(salta):
            if off < tgt_size:
                out[off] = src[off]
            off += 1
        while True:
            tmp = patch[pos]
            pos += 1
            if off < tgt_size:
                out[off] = src[off] ^ tmp
            off += 1
            if tmp == 0:
                break
    while off < tgt_size:
        out[off] = src[off]
        off += 1
    out = bytes(out)
    if zlib.crc32(out) & 0xFFFFFFFF != crc_tgt:
        raise ValueError("CRC32 del risultato diverso da quello della patch")
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--create", nargs=3, metavar=("ORIGINALE", "MODIFICATA", "PATCH"))
    ap.add_argument("--apply", nargs=3, metavar=("ORIGINALE", "PATCH", "USCITA"))
    ap.add_argument("--verify", nargs=2, metavar=("ROM", "PATCH"))
    args = ap.parse_args()

    if args.create:
        a, b, out = args.create
        patch = crea(Path(a).read_bytes(), Path(b).read_bytes())
        Path(out).write_bytes(patch)
        print(f"patch scritta: {out} ({len(patch)} byte)")
        return 0
    if args.apply:
        a, p, out = args.apply
        Path(out).write_bytes(applica(Path(a).read_bytes(), Path(p).read_bytes()))
        print(f"scritto: {out}")
        return 0
    if args.verify:
        rom, p = args.verify
        dati = applica(Path(rom).read_bytes(), Path(p).read_bytes())
        print(f"patch valida: risultato {len(dati)} byte, CRC32 ok")
        return 0
    ap.print_help()
    return 1


if __name__ == "__main__":
    raise SystemExit(main())
