"""Test dei limiti di lunghezza dei campi ad array fisso.

Sono i vincoli che hanno fatto fallire la build (`categoryName` da 13 byte):
se cambiano nel gioco, questi test lo dicono subito.
"""

from __future__ import annotations

import sys
from pathlib import Path

import pytest

IT_DIR = Path(__file__).resolve().parents[1]
ROOT = IT_DIR.parent
sys.path.insert(0, str(IT_DIR))

from hnsit import store  # noqa: E402
from hnsit.buffers import Limits, all_limits  # noqa: E402
from hnsit.textparse import Metrics  # noqa: E402
from hnsit.verify import check_unit, limits_for  # noqa: E402

LIMITS = all_limits(ROOT)
METRICS = Metrics(ROOT)


@pytest.fixture(scope="module")
def limits() -> Limits:
    return LIMITS


def test_limiti_dei_campi_noti(limits: Limits):
    # i valori vengono dai sorgenti: se upstream li cambia, questo test cade
    assert limits.limit("src/data/pokemon/species_info/gen_1_families.h", "categoryName") == 12
    assert limits.limit("src/data/pokemon/species_info/gen_1_families.h", "speciesName") == 12
    assert limits.limit("src/data/types_info.h", "name") == 10
    assert limits.limit("src/data/abilities.h", "name") == 16
    assert limits.limit("src/data/items.h", "name") == 20
    assert limits.limit("src/data/trainers.h", "trainerName") == 10


def test_limite_dagli_array_di_stringhe(limits: Limits):
    """`u8 sOddEggShinyNameList[][PLAYER_NAME_LENGTH + 1]` = 7 caratteri."""
    assert limits.limit("src/scrcmd.c", "sOddEggShinyNameList") == 7


def test_type_name_length_regge_coleottero():
    """Il tipo Coleottero (10) deve entrare in `struct TypeInfo.name`."""
    assert limits_for(ROOT).limit("src/data/types_info.h", "name") >= len("Coleottero")


def test_i_nomi_di_tipo_italiani_entrano():
    import csv

    limit = limits_for(ROOT).limit("src/data/types_info.h", "name")
    rows = list(csv.DictReader((IT_DIR / "data" / "glossary.csv").open(encoding="utf-8")))
    tipi = [r["it"] for r in rows if r["kind"] == "type"]
    assert tipi
    fuori = sorted(t for t in tipi if len(t) > limit)
    assert not fuori, f"tipi piu' lunghi di {limit}: {fuori}"


def test_categoria_troppo_lunga_e_problema_duro():
    unit = store.load_all()["cstr:src/data/pokemon/species_info/gen_9_families.h#7"]
    assert unit.label.endswith("categoryName")
    problems = check_unit(unit, METRICS, limits_for(ROOT))
    if unit.it and "".join(unit.it) != "".join(t for t, _ in unit.lines):
        assert any(p.startswith("limite:") for p in problems)


def test_identica_all_inglese_non_viola_il_limite():
    """`{B_RIVAL_NAME}` e' piu' lungo del campo ma c'e' anche in inglese."""
    for unit in store.load_all().values():
        if unit.label and unit.label.endswith("trainerName") and unit.it:
            if "".join(unit.it) == "".join(t for t, _ in unit.lines):
                assert not [p for p in check_unit(unit, METRICS, limits_for(ROOT)) if p.startswith("limite:")]
                return
    pytest.skip("nessun trainerName identico all'inglese")


def test_nessuna_traduzione_sfonda_i_limiti():
    limits = limits_for(ROOT)
    fuori = []
    for unit in store.load_all().values():
        if unit.it is None or unit.status == "skipped":
            continue
        if "".join(unit.it) == "".join(t for t, _ in unit.lines):
            continue
        limit = limits.limit(unit.file, unit.label)
        if limit is None:
            continue
        size = METRICS.encoded_len("".join(unit.it))
        if size > limit:
            fuori.append((unit.key, size, limit))
    assert not fuori[:10], f"{len(fuori)} unita' oltre il limite"
