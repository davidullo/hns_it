"""Fixture comuni dei test della traduzione."""

from __future__ import annotations

import csv
import sys
from pathlib import Path

import pytest

IT_DIR = Path(__file__).resolve().parents[1]
ROOT = IT_DIR.parent
sys.path.insert(0, str(IT_DIR))
sys.path.insert(0, str(IT_DIR / "tools"))

from hnsit import store  # noqa: E402
from hnsit.textparse import Metrics  # noqa: E402


@pytest.fixture(scope="session")
def root() -> Path:
    return ROOT


@pytest.fixture(scope="session")
def it_dir() -> Path:
    return IT_DIR


@pytest.fixture(scope="session")
def metrics() -> Metrics:
    return Metrics(ROOT)


@pytest.fixture(scope="session")
def units():
    return store.load_all()


@pytest.fixture(scope="session")
def glossary():
    path = IT_DIR / "data" / "glossary.csv"
    out: dict[tuple[str, str], str] = {}
    with path.open(encoding="utf-8", newline="") as fh:
        for row in csv.DictReader(fh):
            out[(row["kind"], row["en"])] = row["it"]
    return out
