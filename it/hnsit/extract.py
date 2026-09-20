"""Estrazione dell'inventario di traduzione dal repo."""

from __future__ import annotations

import json
from pathlib import Path

from . import cstr, store
from .textparse import Unit, iter_inc_units, split_segment, visible_text

# File che non si toccano: vedi it/README.md
SKIP_FILES = {
    "data/text/braille.inc",
}

SKIP_LABELS = {
    # nomi di costanti/simboli usati da script, non testo
}


def is_skipped(unit: Unit) -> tuple[bool, str]:
    if unit.file in SKIP_FILES:
        return True, "file nella skip list (braille)"
    if unit.key in SKIP_LABELS:
        return True, "etichetta nella skip list"
    return False, ""


def extract_inc(repo: Path) -> list[Unit]:
    units = []
    for unit in iter_inc_units(repo):
        skip, why = is_skipped(unit)
        if skip:
            unit.status = "skipped"
            unit.note = why
        units.append(unit)
    return units


def extract_cstr(repo: Path) -> list[Unit]:
    units: list[Unit] = []
    for path in cstr.iter_csrc_files(repo):
        rel = str(path.relative_to(repo))
        text = path.read_text(encoding="utf-8")
        for hit in cstr.find_c_strings(rel, text):
            segments = [part[0] for part in hit.parts]
            if not visible_text(segments).strip():
                continue
            key = f"cstr:{rel}#{hit.ordinal}"
            skip, why = is_skipped(
                Unit(key=key, kind="cstr", file=rel, label=hit.macro, segments=segments)
            )
            units.append(
                Unit(
                    key=key,
                    kind="cstr",
                    file=rel,
                    label=hit.macro or f"#{hit.ordinal}",
                    hint=f"{rel}:{hit.line}",
                    segments=segments,
                    status="skipped" if skip else "pending",
                    note=why,
                )
            )
    return units


def merge_units(new_units: list, old_path: Path) -> list:
    """Fonde le unita' nuove con l'archivio precedente.

    Il lavoro fatto (traduzioni e stato) non va perso quando si ri-estrae:
    si conserva per chiave, ma solo se il testo inglese non e' cambiato.
    """
    old = {u.key: u for u in store.load_units(old_path)}
    kept = dropped = changed = 0
    for unit in new_units:
        prev = old.get(unit.key)
        if prev is None:
            continue
        if prev.sha1 == unit.sha1:
            unit.it = prev.it
            unit.status = prev.status
            unit.note = prev.note
            kept += 1
        else:
            changed += 1
            unit.note = "testo inglese cambiato"
        dropped += 1 if prev.status == "skipped" else 0
    print(f"  merge: {kept} conservate, {changed} con inglese cambiato, {len(old) - dropped} vecchie")
    return new_units


def cmd_extract(repo: Path) -> int:
    inc = extract_inc(repo)
    c = extract_cstr(repo)
    inc = merge_units(inc, store.data_dir() / store.INC_STORE)
    c = merge_units(c, store.data_dir() / store.CSTR_STORE)
    store.save_units(store.data_dir() / store.INC_STORE, inc)
    store.save_units(store.data_dir() / store.CSTR_STORE, c)
    inv = {
        "repo": str(repo),
        "inc": store.stats(inc),
        "cstr": store.stats(c),
    }
    (store.data_dir() / "inventory.json").write_text(
        json.dumps(inv, ensure_ascii=False, indent=2, sort_keys=True), encoding="utf-8"
    )
    for name, s in (("inc", inv["inc"]), ("cstr", inv["cstr"])):
        print(f"--- {name}")
        for k, v in s.items():
            print(f"  {k}: {v}")
    tot = store.stats(inc + c)
    print("--- totale")
    for k, v in tot.items():
        print(f"  {k}: {v}")
    return 0


def empty_blocks(repo: Path) -> None:
    """Controllo di servizio: blocchi .inc senza testo visibile."""
    for unit in iter_inc_units(repo):
        if not visible_text(unit.segments).strip():
            print(f"vuoto: {unit.key} {[split_segment(s) for s in unit.segments]}")
