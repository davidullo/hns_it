"""Iniezione delle traduzioni nei sorgenti.

Regole:
* la struttura (segmenti, terminatori, codici {...}) non cambia mai;
* si scrive l'italiano accettato, e si RIMETTE l'inglese per le unita' che non
  hanno piu' una traduzione accettata (dopo un `repair`): altrimenti nel
  sorgente resta l'italiano vecchio e la build muore su un campo troppo stretto;
* ogni scrittura e' verificata contro lo sha1 dell'inglese registrato o contro
  l'ultima traduzione nota (idempotenza e revert);
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


def _known_texts(unit: Unit) -> list[list[str]]:
    """Versioni del testo accettabili nel sorgente per questa unita'."""
    out = [unit.segments]
    for candidate in (unit.it, unit.prev_it):
        if not candidate:
            continue
        try:
            rebuilt = unit.rebuild(candidate)
        except ValueError:
            continue
        if rebuilt not in out:
            out.append(rebuilt)
    return out


def _check_known(unit: Unit, current) -> None:
    """Un'unita' senza traduzione accettata torna all'inglese comunque.

    Se invece una traduzione accettata esiste, il sorgente deve contenere
    l'inglese o una versione che conosciamo: altrimenti e' drift.
    """
    if unit.it is None or unit.status == "skipped":
        return
    if current not in _known_texts(unit):
        raise Drift(f"{unit.key}: il testo nel file non corrisponde ne' all'inglese ne' a una traduzione nota")


def _target_segments(unit: Unit) -> list[str]:
    """Cosa deve contenere il sorgente: italiano accettato, altrimenti inglese."""
    if unit.it is not None and unit.status != "skipped":
        return unit.rebuild(unit.it)
    return list(unit.segments)


def inject_file(repo: Path, rel: str, units: list[Unit], dry_run: bool = False) -> int:
    """Scrive le unita' di un file. Ritorna quante unita' ha scritto."""
    path = repo / rel
    text = path.read_text(encoding="utf-8")
    kind = units[0].kind if units else None

    if kind == "inc":
        blocks = read_inc_blocks(repo, rel)
        # offset dei letterali per etichetta, ricavati dalle righe attive
        # (i rami #if/#else non compilati non contano: altrimenti si contano
        # letterali che il gioco non vede e l'iniezione va in drift)
        active = {lineno for lineno, _ in active_lines(text)}
        spans: dict[str, list[tuple[int, int, str]]] = defaultdict(list)
        label = None
        offset = 0
        for lineno, raw in enumerate(text.splitlines(keepends=True), start=1):
            if lineno not in active:
                offset += len(raw)
                continue
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
            target = _target_segments(unit)
            current = blocks.get(unit.label)
            if current is None:
                raise Drift(f"{unit.key}: blocco assente dal file")
            s = spans.get(unit.label, [])
            if len(s) != len(unit.segments):
                raise Drift(f"{unit.key}: {len(s)} letterali nel file, {len(unit.segments)} attesi")
            if current == target:
                continue
            _check_known(unit, current)
            for (start, end, _old), new in zip(s, target):
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
            hit = hits.get(unit.key)
            if hit is None:
                raise Drift(f"{unit.key}: macro assente dal file")
            if len(hit.parts) != len(unit.segments):
                raise Drift(f"{unit.key}: {len(hit.parts)} letterali, {len(unit.segments)} attesi")
            target = _target_segments(unit)
            current = [p[0] for p in hit.parts]
            if current == target:
                continue
            _check_known(unit, current)
            for (content, start, end), new in zip(hit.parts, target):
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
    failures: list[str] = []
    for rel in sorted(by_file):
        try:
            n = inject_file(repo, rel, by_file[rel], dry_run=dry_run)
        except Drift as exc:
            # un file in drift non deve bloccare tutti gli altri
            failures.append(f"{rel}: {exc}")
            continue
        if n:
            print(f"{'[dry] ' if dry_run else ''}{rel}: {n} unita'")
        total += n
    if failures:
        print(f"file in drift: {len(failures)}")
        for row in failures[:10]:
            print("  ! " + row)
    print(f"totale unita' scritte: {total}{' (dry run)' if dry_run else ''}")
    return 1 if failures else 0
