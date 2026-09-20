"""Test delle regole di gioco: iniezione, idempotenza, glossario, autofill.

    it/.venv/bin/python -m pytest it/tests -q
"""

from __future__ import annotations

import shutil
import sys
from pathlib import Path

import pytest

IT_DIR = Path(__file__).resolve().parents[1]
ROOT = IT_DIR.parent
sys.path.insert(0, str(IT_DIR))
sys.path.insert(0, str(IT_DIR / "tools"))

from hnsit.textparse import CONTROL_RE, Metrics, Unit  # noqa: E402

MINI = '''#include "constants/global.h"

MiniMap_Text_Hello::
\t.string "Hello!\\n"
\t.string "How are you?$"

MiniMap_Text_Bye:
\t.string "Bye!$"

#if IS_HNS
MiniMap_Text_Hns:
\t.string "HNS only!$"
#else
MiniMap_Text_Frlg:
\t.string "FRLG only!$"
#endif
'''


def test_il_parser_salta_i_rami_non_compilati(tmp_path: Path):
    from hnsit.textparse import iter_inc_units

    (tmp_path / "data" / "text").mkdir(parents=True)
    (tmp_path / "data" / "text" / "mini.inc").write_text(MINI, encoding="utf-8")
    labels = {u.label for u in iter_inc_units(tmp_path)}
    assert labels == {"MiniMap_Text_Hello", "MiniMap_Text_Bye", "MiniMap_Text_Hns"}


def test_le_larghezze_contano_i_codici_zero():
    metrics = Metrics(ROOT)
    from hnsit.textparse import CONTROL_RE

    largo, _ = metrics.line_width("Hello")
    assert metrics.line_width(CONTROL_RE.sub("", "{PLAYER}Hello"))[0] == largo
    assert metrics.line_width(CONTROL_RE.sub("", "{COLOR RED}Pippo"))[0] == metrics.line_width("Pippo")[0]


def test_righe_troppo_lunghe_vengono_segnalate():
    metrics = Metrics(ROOT)
    w, _ = metrics.line_width("x" * 100)
    assert w > 216


def test_inject_e_idempotente_su_un_repo_finto(tmp_path: Path):
    """Copia minima del repo, inietta due volte, il secondo giro non cambia nulla."""
    from hnsit import inject as injectmod
    from hnsit.textparse import iter_inc_units

    for name in ("charmap.txt",):
        shutil.copy(ROOT / name, tmp_path / name)
    (tmp_path / "src").mkdir()
    shutil.copy(ROOT / "src" / "fonts.c", tmp_path / "src" / "fonts.c")
    (tmp_path / "data" / "text").mkdir(parents=True)
    (tmp_path / "data" / "text" / "mini.inc").write_text(MINI, encoding="utf-8")

    units = [u for u in iter_inc_units(tmp_path)]
    hello = next(u for u in units if u.label == "MiniMap_Text_Hello")
    hello.it = ["Ciao!", "Come va?"]
    hello.status = "translated"

    n = injectmod.inject_file(tmp_path, "data/text/mini.inc", [hello])
    assert n == 1
    after_first = (tmp_path / "data" / "text" / "mini.inc").read_text(encoding="utf-8")
    assert "Ciao!\\n" in after_first and "Come va?$" in after_first
    # il ramo non compilato non si tocca
    assert "FRLG only!$" in after_first

    n2 = injectmod.inject_file(tmp_path, "data/text/mini.inc", [hello])
    assert n2 == 0
    assert (tmp_path / "data" / "text" / "mini.inc").read_text(encoding="utf-8") == after_first


def test_inject_si_ferma_su_deriva(tmp_path: Path):
    from hnsit import inject as injectmod
    from hnsit.textparse import iter_inc_units

    shutil.copy(ROOT / "charmap.txt", tmp_path / "charmap.txt")
    (tmp_path / "src").mkdir()
    shutil.copy(ROOT / "src" / "fonts.c", tmp_path / "src" / "fonts.c")
    (tmp_path / "data" / "text").mkdir(parents=True)
    path = tmp_path / "data" / "text" / "mini.inc"
    path.write_text(MINI, encoding="utf-8")

    hello = next(u for u in iter_inc_units(tmp_path) if u.label == "MiniMap_Text_Hello")
    hello.it = ["Ciao!", "Come va?"]
    hello.status = "translated"
    # qualcuno cambia l'inglese a monte
    path.write_text(MINI.replace("Hello!", "Hi!"), encoding="utf-8")
    with pytest.raises(injectmod.Drift):
        injectmod.inject_file(tmp_path, "data/text/mini.inc", [hello])


def test_glossario_copre_i_nomi_delle_mosse(glossary):
    names = {en.upper() for (kind, en) in glossary if kind == "move"}
    from hnsit import store

    units = store.load_all().values()
    movenames = [
        u
        for u in units
        if u.kind == "cstr" and u.label == "name" and u.file.endswith("moves_info.h")
    ]
    assert movenames, "nessun nome di mossa estratto da moves_info.h"
    missing = sorted({u.visible_lines[0] for u in movenames if u.visible_lines[0] not in names})
    # qualche mossa e' nuova di pokeemerald-expansion e non esiste in PokeAPI:
    # la soglia controlla che non siano la maggioranza
    assert len(missing) < len(movenames) * 0.05, f"{len(missing)} nomi senza voce: {missing[:8]}"


def test_easy_chat_ordine_alfabetico_coerente():
    """Dove `alphabeticalOrder` esiste deve essere un indice EC_INDEX valido."""
    import re

    path = ROOT / "src" / "data" / "easy_chat"
    groups = sorted(path.glob("easy_chat_group_*.h"))
    assert groups, "nessun file easy chat trovato"
    checked = 0
    for group in groups:
        text = group.read_text(encoding="utf-8")
        orders = re.findall(r"\.alphabeticalOrder\s*=\s*([^,\n]+)", text)
        for order in orders:
            assert "EC_INDEX" in order or order.strip().isdigit(), f"{group.name}: {order}"
            checked += 1
    # i gruppi pokemon/mosse non hanno il campo: deve esserci almeno un gruppo che lo usa
    assert checked > 100, f"solo {checked} voci con alphabeticalOrder"


def test_unita_senza_testo_visibile_non_hanno_traduzione():
    from hnsit import store

    for unit in store.load_all().values():
        if unit.it is None:
            continue
        assert any(line.strip() for line in unit.it) or not any(
            line.strip() for line in unit.visible_lines
        )


def test_nessun_codice_perso_nelle_traduzioni():
    from hnsit import store

    for unit in store.load_all().values():
        if unit.it is None or unit.status == "skipped":
            continue
        for (en, _t), it in zip(unit.lines, unit.it):
            assert sorted(CONTROL_RE.findall(en)) == sorted(CONTROL_RE.findall(it)), unit.key
