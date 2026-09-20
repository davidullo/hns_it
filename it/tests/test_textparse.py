"""Test delle tecnicita' del gioco: parser, larghezze, charmap, iniezione.

    python3 -m pytest it/tests -q
"""

from __future__ import annotations

import json
import shutil
import sys
from pathlib import Path

import pytest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))

from hnsit import store  # noqa: E402
from hnsit.textparse import (  # noqa: E402
    BS,
    Metrics,
    Unit,
    iter_inc_units,
    join_segment,
    parse_charmap,
    sha1_of,
    split_segment,
)

REPO = store.repo_root()


@pytest.fixture(scope="session")
def metrics() -> Metrics:
    return Metrics(REPO)


# --- charmap ---------------------------------------------------------------


def test_charmap_ha_gli_accenti_italiani():
    table = parse_charmap(REPO / "charmap.txt")
    for ch in "àèéìòùÀÈÉÌÒÙ":
        assert ch in table, f"manca {ch} dal charmap"
    for ch in "\u201c\u201d\u2019\u2026":
        assert ch in table, f"manca il segno tipografico {ch!r}"
    for ch in "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789":
        assert ch in table, f"manca {ch}"


def test_glyph_widths_coerenti(metrics: Metrics):
    # la tabella del font normale ha 512 voci (il charmap puo' indicizzare
    # oltre 0xFF per i caratteri estesi)
    assert len(metrics.widths) >= 256
    for byte in range(len(metrics.widths)):
        assert 0 < metrics.widths[byte] <= 12
    assert metrics.line_width("A")[0] == metrics.widths[metrics.charmap["A"][0]]
    # '=' e' un glifo vero (8 px): senza di lui le larghezze sarebbero sbagliate
    assert metrics.line_width("=")[0] == 8


def test_nessun_carattere_fuori_charmap_nei_testi_inglesi(metrics: Metrics):
    from hnsit.textparse import CONTROL_RE

    seen = set()
    for unit in iter_inc_units(REPO):
        for line in unit.visible_lines:
            _w, unknown = metrics.line_width(CONTROL_RE.sub("", line))
            seen.update(unknown)
    assert not seen, f"caratteri non rappresentabili: {''.join(sorted(seen))!r}"


# --- segmenti e righe ------------------------------------------------------


@pytest.mark.parametrize(
    "body",
    [
        "Hello$",
        "Hello\\nWorld$",
        "Hi!\\nHow are you?\\pSee you$",
        "{PLAYER} got {STR_VAR_1}!$",
        "\\l$",
        "\\p",
        "",
        "Line with “quotes” and … dots$",
    ],
)
def test_split_join_roundtrip(body: str):
    assert join_segment(split_segment(body)) == body


def test_rebuild_mantiene_struttura_e_terminatori():
    unit = Unit(
        key="t",
        kind="inc",
        file="f.inc",
        label="L",
        segments=["Hi!\\n", "How are you?\\p", "Fine, thanks$"],
    )
    it = unit.rebuild(["Ciao!\\n".replace("\\n", ""), "Come va?", "Bene, grazie"])
    assert it == ["Ciao!\\n", "Come va?\\p", "Bene, grazie$"]
    assert len(it) == len(unit.segments)


def test_rebuild_rifiuta_numero_di_righe_sbagliato():
    unit = Unit(key="t", kind="cstr", file="f.c", label="L", segments=["a\\nb$"])
    with pytest.raises(ValueError):
        unit.rebuild(["solo una riga"])


def test_rebuild_lascia_stare_i_segmenti_strutturali():
    # un segmento fatto solo di terminatore occupa comunque uno slot, ma il
    # testo tradotto non lo tocca: resta `\l` com'e'
    unit = Unit(key="t", kind="inc", file="f.inc", label="L", segments=["Hi\\n", "\\l"])
    it = unit.rebuild(["Ciao", ""])
    assert it == ["Ciao\\n", "\\l"]


def test_key_univoca_su_tutto_il_repo():
    keys = set()
    for unit in iter_inc_units(REPO):
        assert unit.key not in keys, f"chiave duplicata: {unit.key}"
        keys.add(unit.key)
    assert len(keys) > 10000


def test_sha1_stabile():
    assert sha1_of(["a", "b"]) == sha1_of(["a", "b"])
    assert sha1_of(["a", "b"]) != sha1_of(["ab"])


# --- dati di traduzione ----------------------------------------------------


def test_store_caricabile_e_coerente():
    units = store.load_all()
    assert units, "nessuna unita' estratta: lancia it/tools/hnsit.py extract"
    for unit in units.values():
        assert unit.kind in ("inc", "cstr")
        assert unit.segments, f"{unit.key} senza segmenti"
        if unit.it is not None:
            assert len(unit.it) == len(unit.lines), f"{unit.key}: righe IT != righe EN"


def test_ogni_unita_ha_sha1_e_file_esistente():
    units = store.load_all()
    missing = [u.file for u in units.values() if not (REPO / u.file).exists()]
    assert not missing, f"file inesistenti: {sorted(set(missing))[:5]}"


def test_placeholders_identici_dopo_la_traduzione():
    sys.path.insert(0, str(ROOT / "tools"))
    from hnsit.verify import placeholders  # type: ignore

    units = store.load_all()
    bad = []
    for unit in units.values():
        if unit.it is None or unit.status == "skipped":
            continue
        for (en, _term), it in zip(unit.lines, unit.it):
            if placeholders(en) != placeholders(it):
                bad.append(unit.key)
                break
    assert not bad, f"codici {{...}} diversi in {len(bad)} unita', es. {bad[:5]}"


def test_niente_trattini_lunghi_nelle_traduzioni():
    units = store.load_all()
    bad = [u.key for u in units.values() if u.it and any("\u2014" in line for line in u.it)]
    assert not bad, f"trattino lungo in {bad[:5]}"
