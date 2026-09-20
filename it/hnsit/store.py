"""Lettura/scrittura dell'archivio di unita' di traduzione."""

from __future__ import annotations

import json
from collections import Counter, defaultdict
from pathlib import Path

from .textparse import Unit

INC_STORE = "units_inc.jsonl"
CSTR_STORE = "units_cstr.jsonl"


def repo_root() -> Path:
    return Path(__file__).resolve().parents[2]


def data_dir() -> Path:
    return repo_root() / "it" / "data"


def load_units(path: Path) -> list[Unit]:
    units: list[Unit] = []
    if not path.exists():
        return units
    for line in path.read_text(encoding="utf-8").splitlines():
        line = line.strip()
        if not line:
            continue
        d = json.loads(line)
        units.append(
            Unit(
                key=d["key"],
                kind=d["kind"],
                file=d["file"],
                label=d["label"],
                hint=d.get("hint", ""),
                segments=d["segments"],
                sha1=d["sha1"],
                it=d.get("it"),
                status=d.get("status", "pending"),
                note=d.get("note", ""),
            )
        )
    return units


def save_units(path: Path, units: list[Unit]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("w", encoding="utf-8") as fh:
        for unit in sorted_units(units):
            fh.write(json.dumps(unit.to_json(), ensure_ascii=False, sort_keys=True) + "\n")


def sorted_units(units):
    return sorted(units, key=lambda u: u.key)


def load_all() -> dict[str, Unit]:
    out: dict[str, Unit] = {}
    for name in (INC_STORE, CSTR_STORE):
        for unit in load_units(data_dir() / name):
            out[unit.key] = unit
    return out


def stats(units: list[Unit]) -> dict:
    by_status = Counter(u.status for u in units)
    by_kind = Counter(u.kind for u in units)
    unique_src: dict[str, list[str]] = defaultdict(list)
    for u in units:
        unique_src[u.sha1].append(u.key)
    lines = sum(len(u.visible_lines) for u in units)
    return {
        "unita": len(units),
        "per_stato": dict(by_status),
        "per_tipo": dict(by_kind),
        "unita_uniche_per_testo": len(unique_src),
        "righe_visibili": lines,
        "character_inglesi": sum(len(t) for u in units for t in u.visible_lines),
        "duplicati": sum(len(v) - 1 for v in unique_src.values()),
    }
