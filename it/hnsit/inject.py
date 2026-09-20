"""Iniezione delle traduzioni nei sorgenti.

Regole:
* la struttura (segmenti, terminatori, codici {...}) non cambia mai;
* ogni scrittura e' verificata contro lo sha1 dell'inglese registrato,
  oppure contro il testo italiano gia' iniettato (idempotenza);
* qualunque altra cosa e' DRIFT: non si scrive niente e si esce 1.
"""

from __future__ import annotations

from collections import defaultdict
from pathlib import Path

from . import cstr, store
from .textparse import Unit, parse_string_line, active_lines, LABEL_RE, read_inc_blocks, sha1_of


class Drift(Exception):
    pass


def _replace_span(text: str, start: int, end: int, new: str) -> str:
    return text[:start] + new + text[end:]


def inject_file(repo: Path, rel: str, units: list[Unit], dry_run: bool = False) -> int:
    """Scrive le unita' di un file. Ritorna quante unita' ha scritto."""
    path = repo / rel
    text = path.read_text(encoding="utf-8")
    kind = units[0].kind if units else None

    if kind == "inc":
        blocks = read_inc_blocks(repo, rel)
        # offset dei letterali per etichetta, ricavati dalle righe attive
        spans: dict[str, list[tuple[int, int, str]]] = defaultdict(list)
        label = None
        offset = 0
        for raw in text.splitlines(keepends=True):
            stripped = raw.lstrip()
            if LABEL_RE.match(raw.rstrip("\n")):
                m = LABEL_RE.match(raw.rstrip("\n"))
                label = m.group(1)
            parsed = parse_string_line(raw.rstrip("\n"))
            if parsed is not None and label:
                content, _s, _e, prefix, tail = parsed
                line_body = raw.rstrip("\n")
                i = line_body.find('"')
                j = i + 1
                while j < len(line_body) and line_body[j] != '"':
                    if line_body[j] == chr(92):
                        j += 2
                        continue
                    j += 1
                spans[label].append((offset + i + 1, offset + j, content))
            offset += len(raw)
        # gli intervalli vanno applicati in ordine inverso per non spostare gli offset
        edits: list[tuple[int, int, str]] = []
        written = 0
        for unit in units:
            if unit.it is None or unit.status == "skipped":
                continue
            current = blocks.get(unit.label)
            if current is None:
                raise Drift(f"{unit.key}: blocco assente dal file")
            s = spans.get(unit.label, [])
            if len(s) != len(unit.segments):
                raise Drift(f"{unit.key}: {len(s)} letterali nel file, {len(unit.segments)} attesi")
            en_ok = current == unit.segments
            it_segments = unit.rebuild(unit.it)
            it_ok = current == it_segments
            if not en_ok and not it_ok:
                raise Drift(f"{unit.key}: il testo nel file non corrisponde ne' all'inglese ne' all'italiano")
            if it_ok:
                continue
            for (start, end, _old), new in zip(s, it_segments):
                edits.append((start, end, new))
            written += 1
        if not dry_run:
            for start, end, new in sorted(edits, reverse=True):
                text = _replace_span(text, start, end, new)
            path.write_text(text, encoding="utf-8")
        return written

    if kind == "cstr":
        hits = {f"cstr:{rel}#{h.ordinal}": h for h in cstr.find_c_strings(rel, text)}
        edits = []
        written = 0
        for unit in units:
            if unit.it is None or unit.status == "skipped":
                continue
            hit = hits.get(unit.key)
            if hit is None:
                raise Drift(f"{unit.key}: macro assente dal file")
            if len(hit.parts) != len(unit.segments):
                raise Drift(f"{unit.key}: {len(hit.parts)} letterali, {len(unit.segments)} attesi")
            current = [p[0] for p in hit.parts]
            it_segments = unit.rebuild(unit.it)
            if current == it_segments:
                continue
            if current != unit.segments:
                raise Drift(f"{unit.key}: il testo nel file non corrisponde ne' all'inglese ne' all'italiano")
            for (content, start, end), new in zip(hit.parts, it_segments):
                edits.append((start, end, new))
            written += 1
        if not dry_run:
            for start, end, new in sorted(edits, reverse=True):
                text = _replace_span(text, start, end, new)
            path.write_text(text, encoding="utf-8")
        return written

    return 0


def cmd_inject(repo: Path, dry_run: bool = False, only: str | None = None) -> int:
    units = store.load_all()
    by_file: dict[str, list[Unit]] = defaultdict(list)
    for unit in units.values():
        if only and not unit.key.startswith(only):
            continue
        if unit.kind == "inc":
            span, _, lbl = unit.key.partition("|")
            by_file[span[4:]].append(unit)
        else:
            by_file[unit.file].append(unit)
    total = 0
    for rel in sorted(by_file):
        n = inject_file(repo, rel, by_file[rel], dry_run=dry_run)
        if n:
            print(f"{'[dry] ' if dry_run else ''}{rel}: {n} unita'")
        total += n
    print(f"totale unita' scritte: {total}{' (dry run)' if dry_run else ''}")
    return 0
