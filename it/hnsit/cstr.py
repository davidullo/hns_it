"""Scansione delle stringhe C tradotte: `_("...")` e `COMPOUND_STRING("...")`."""

from __future__ import annotations

import re
from dataclasses import dataclass
from pathlib import Path

BS = chr(92)


@dataclass
class CStringHit:
    """Una occorrenza di macro di testo con i suoi letterali."""

    ordinal: int
    macro: str  # "MOVE_TACKLE.name" o simile, solo per contesto
    parts: list[tuple[str, int, int]]  # (contenuto, inizio, fine) per letterale
    start: int  # offset di inizio della macro
    line: int


def strip_comments(text: str) -> str:
    """Rimuove i commenti mantenendo gli offset (gli spazi restano)."""
    out = list(text)
    i, n = 0, len(text)
    state = "code"
    while i < n:
        ch = text[i]
        nxt = text[i + 1] if i + 1 < n else ""
        if state == "code":
            if ch == "/" and nxt == "/":
                state = "line"
                out[i] = out[i + 1] = " "
                i += 2
                continue
            if ch == "/" and nxt == "*":
                state = "block"
                out[i] = out[i + 1] = " "
                i += 2
                continue
            if ch == '"':
                state = "str"
            elif ch == "'":
                state = "char"
        elif state == "line":
            if ch == "\n":
                state = "code"
            else:
                out[i] = " "
        elif state == "block":
            if ch == "*" and nxt == "/":
                out[i] = out[i + 1] = " "
                state = "code"
                i += 2
                continue
            if ch != "\n":
                out[i] = " "
        elif state == "str":
            if ch == BS:
                i += 2
                continue
            if ch == '"':
                state = "code"
        elif state == "char":
            if ch == BS:
                i += 2
                continue
            if ch == "'":
                state = "code"
        i += 1
    return "".join(out)


MACRO_RE = re.compile(r"(?<![A-Za-z0-9_])(COMPOUND_STRING|COMPOUND_STRING_SIZE_LIMIT|_)\s*\(")
FIELD_RE = re.compile(r"\.\s*([A-Za-z_][A-Za-z0-9_]*)\s*=\s*$")
ARRAY_RE = re.compile(r"\[\s*([A-Za-z_][A-Za-z0-9_]*)\s*\]\s*=\s*$")
SYMBOL_RE = re.compile(r"([A-Za-z_][A-Za-z0-9_]*)\s*(?:\[\s*\])?\s*=\s*$")


def _context(clean: str, pos: int) -> str:
    """Contesto leggibile della stringa: campo, indice o simbolo."""
    head = clean[:pos]
    m = FIELD_RE.search(head.splitlines()[-1] if head.splitlines() else "")
    parts = []
    if m:
        parts.append(m.group(1))
    # cerca un `[SYM] = {` piu' indietro, entro 40 righe
    window = "".join(head.splitlines(keepends=True)[-40:])
    idxs = ARRAY_RE.findall(window)
    if idxs:
        parts.insert(0, idxs[-1])
    if not parts:
        syms = SYMBOL_RE.findall("".join(head.splitlines(keepends=True)[-3:]))
        if syms:
            parts.append(syms[-1])
    return ".".join(parts)


def find_c_strings(rel: str, text: str) -> list[CStringHit]:
    """Tutte le macro di testo di un file, in ordine di comparsa."""
    clean = strip_comments(text)
    hits: list[CStringHit] = []
    ordinal = 0
    for m in MACRO_RE.finditer(clean):
        macro = m.group(1)
        i = m.end()
        parts: list[tuple[str, int, int]] = []
        while True:
            while i < len(clean) and clean[i] in " \t\r\n":
                i += 1
            if i >= len(clean):
                break
            if clean[i] == '"':
                j = i + 1
                buf: list[str] = []
                while j < len(clean):
                    ch = clean[j]
                    if ch == BS and j + 1 < len(clean):
                        buf.append(ch)
                        buf.append(clean[j + 1])
                        j += 2
                        continue
                    if ch == '"':
                        break
                    buf.append(ch)
                    j += 1
                parts.append(("".join(buf), i + 1, j))
                i = j + 1
                continue
            if clean[i] == "," and macro != "_":
                # COMPOUND_STRING_SIZE_LIMIT(str, limit)
                i += 1
                continue
            break
        if not parts:
            continue
        hits.append(
            CStringHit(
                ordinal=ordinal,
                macro=_context(clean, m.start()),
                parts=parts,
                start=m.start(),
                line=clean.count("\n", 0, m.start()) + 1,
            )
        )
        ordinal += 1
    return hits


def iter_csrc_files(repo: Path) -> list[Path]:
    paths: list[Path] = []
    for pattern in ("src/**/*.c", "src/**/*.h", "include/**/*.h"):
        paths.extend(sorted(repo.glob(pattern)))
    return paths
