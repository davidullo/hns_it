#!/usr/bin/env python3
"""Costruisce it/data/glossary.csv e it/data/prose.jsonl dai dump CSV di PokeAPI.

Le fonti sono i dump ufficiali del progetto PokeAPI (github.com/PokeAPI/pokeapi,
data/v2/csv): i campi in italiano vengono dalle localizzazioni ufficiali dei giochi.

    python3 it/tools/build_glossary.py
"""

from __future__ import annotations

import csv
import json
import re
import sys
from pathlib import Path

IT = "8"  # local_language_id italiano nei dump PokeAPI

ROOT = Path(__file__).resolve().parents[1]
CSV = ROOT / "data" / "pokeapi"
OUT_GLOSSARY = ROOT / "data" / "glossary.csv"
OUT_PROSE = ROOT / "data" / "prose.jsonl"
OUT_MANUAL = ROOT / "data" / "glossary_manual.csv"

# (file, colonna_chiave, nome_tabella, kind, colonna_nome, colonna_genus)
NAME_TABLES = [
    ("pokemon_species_names.csv", "pokemon_species_id", "species", "name", "genus"),
    ("pokemon_form_names.csv", "pokemon_form_id", "form", "pokemon_name", None),
    ("move_names.csv", "move_id", "move", "name", None),
    ("ability_names.csv", "ability_id", "ability", "name", None),
    ("item_names.csv", "item_id", "item", "name", None),
    ("type_names.csv", "type_id", "type", "name", None),
    ("stat_names.csv", "stat_id", "stat", "name", None),
    ("nature_names.csv", "nature_id", "nature", "name", None),
    ("location_names.csv", "location_id", "location", "name", None),
    ("region_names.csv", "region_id", "region", "name", None),
    ("contest_type_names.csv", "contest_type_id", "contest_type", "name", None),
    ("move_meta_ailment_names.csv", "move_meta_ailment_id", "ailment", "name", None),
    ("move_target_prose.csv", "move_target_id", "move_target", "name", None),
    ("move_damage_class_prose.csv", "move_damage_class_id", "damage_class", "name", None),
    ("item_category_prose.csv", "item_category_id", "item_category", "name", None),
    ("item_pocket_names.csv", "item_pocket_id", "item_pocket", "name", None),
    ("growth_rate_prose.csv", "growth_rate_id", "growth_rate", "name", None),
    ("encounter_method_prose.csv", "encounter_method_id", "encounter_method", "name", None),
    ("version_names.csv", "version_id", "version", "name", None),
    ("pokemon_color_names.csv", "pokemon_color_id", "color", "name", None),
    ("pokemon_habitat_names.csv", "pokemon_habitat_id", "habitat", "name", None),
    ("pokemon_shape_prose.csv", "pokemon_shape_id", "shape", "name", None),
    ("pokedex_prose.csv", "pokedex_id", "pokedex", "name", None),
    ("berry_firmness_names.csv", "berry_firmness_id", "berry_firmness", "name", None),
    ("egg_group_prose.csv", "egg_group_id", "egg_group", "name", None),
    ("super_contest_effect_prose.csv", "super_contest_effect_id", "super_contest", "flavor_text", None),
    ("characteristic_text.csv", "characteristic_id", "characteristic", "message", None),
    ("item_flag_prose.csv", "item_flag_id", "item_flag", "name", None),
]

PROSE_TABLES = [
    ("move_effect_prose.csv", "move_effect_id", "move_effect"),
    ("ability_prose.csv", "ability_id", "ability_effect"),
    ("item_prose.csv", "item_id", "item_effect"),
]


def norm(text: str) -> str:
    """Normalizzazione per il confronto fra testi di gioco e PokeAPI."""
    t = text.replace("\u000c", " ").replace("\u00ad", "")
    t = t.replace("\u201c", '"').replace("\u201d", '"').replace("\u2018", "'").replace("\u2019", "'")
    t = t.replace("\u2026", "...").replace("\u00e9", "e").replace("\u00e8", "e")
    t = t.replace("\u00c9", "E").replace("\u00e0", "a").replace("\u00f2", "o").replace("\u00f9", "u")
    t = re.sub(r"\s+", " ", t)
    return t.strip().lower()


def rows(name: str):
    path = CSV / name
    if not path.exists():
        return
    with path.open(encoding="utf-8", newline="") as fh:
        yield from csv.DictReader(fh)


def build_names() -> list[dict]:
    out: list[dict] = []
    for fname, key, kind, name_col, genus_col in NAME_TABLES:
        by_id: dict[str, dict] = {}
        for row in rows(fname):
            rid = row[key]
            if row["local_language_id"] == IT:
                by_id.setdefault(rid, {})["it"] = row.get(name_col, "")
                if genus_col:
                    by_id[rid].setdefault("genus", row.get(genus_col, ""))
            elif row["local_language_id"] == "9":
                by_id.setdefault(rid, {})["en"] = row.get(name_col, "")
                if genus_col:
                    by_id[rid].setdefault("genus_en", row.get(genus_col, ""))
        for entry in by_id.values():
            en, it = entry.get("en", "").strip(), entry.get("it", "").strip()
            if en and it:
                out.append({"kind": kind, "en": en, "it": it, "source": f"pokeapi:{fname}"})
            if genus_col:
                gen_en, gen_it = entry.get("genus_en", "").strip(), entry.get("genus", "").strip()
                if gen_en and gen_it:
                    out.append({"kind": "genus", "en": gen_en, "it": gen_it, "source": f"pokeapi:{fname}"})
    return out


def build_prose() -> list[dict]:
    out: list[dict] = []
    for fname, key, kind in PROSE_TABLES:
        by_id: dict[str, dict] = {}
        for row in rows(fname):
            rid = row[key]
            lang = row["local_language_id"]
            if lang == IT:
                by_id.setdefault(rid, {})["it"] = (row.get("short_effect") or "", row.get("effect") or "")
            elif lang == "9":
                by_id.setdefault(rid, {})["en"] = (row.get("short_effect") or "", row.get("effect") or "")
        for rid, entry in by_id.items():
            en_s, en_e = entry.get("en", ("", ""))
            it_s, it_e = entry.get("it", ("", ""))
            if en_s and it_s:
                out.append({"kind": kind + "_short", "en": en_s, "it": it_s, "source": f"pokeapi:{fname}"})
            if en_e and it_e:
                out.append({"kind": kind + "_long", "en": en_e, "it": it_e, "source": f"pokeapi:{fname}"})

    # flavor text: piu' varianti per lingua, teniamo la piu' recente per chiave
    for fname, key, kind in (
        ("move_flavor_text.csv", "move_id", "move_flavor"),
        ("ability_flavor_text.csv", "ability_id", "ability_flavor"),
        ("item_flavor_text.csv", "item_id", "item_flavor"),
    ):
        best: dict[str, dict] = {}
        for row in rows(fname):
            rid = row[key]
            lang = row["language_id"]
            ver = row.get("version_id", row.get("version_group_id", "0"))
            if lang not in (IT, "9"):
                continue
            cur = best.setdefault(rid, {})
            cur.setdefault(lang, {})[ver] = row.get("flavor_text", "")
        for rid, langs in best.items():
            en_map, it_map = langs.get("9", {}), langs.get(IT, {})
            if not en_map or not it_map:
                continue
            en_ver = max(en_map, key=lambda v: int(v) if v.isdigit() else 0)
            it_ver = max(it_map, key=lambda v: int(v) if v.isdigit() else 0)
            en, it = en_map[en_ver].strip(), it_map[it_ver].strip()
            if en and it:
                out.append({"kind": kind, "en": en, "it": it, "source": f"pokeapi:{fname}"})
    return out


def main() -> int:
    names = build_names()
    prose = build_prose()
    loads = []
    if OUT_MANUAL.exists():
        with OUT_MANUAL.open(encoding="utf-8", newline="") as fh:
            for row in csv.DictReader(fh):
                if row.get("en") and row.get("it"):
                    loads.append(
                        {
                            "kind": row.get("kind", "term"),
                            "en": row["en"],
                            "it": row["it"],
                            "source": "manual",
                        }
                    )
    allterms = names + loads
    allterms.sort(key=lambda d: (d["kind"], d["en"]))
    with OUT_GLOSSARY.open("w", encoding="utf-8", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=["kind", "en", "it", "source"])
        w.writeheader()
        seen = set()
        for row in allterms:
            sig = (row["kind"], row["en"])
            if sig in seen:
                continue
            seen.add(sig)
            w.writerow(row)

    with OUT_PROSE.open("w", encoding="utf-8") as fh:
        for row in prose:
            fh.write(json.dumps(row, ensure_ascii=False) + "\n")

    by_kind: dict[str, int] = {}
    for row in allterms:
        by_kind[row["kind"]] = by_kind.get(row["kind"], 0) + 1
    print(f"glossario: {len(seen)} voci ({len(loads)} manuali)")
    for kind in sorted(by_kind):
        print(f"  {kind}: {by_kind[kind]}")
    print(f"prose: {len(prose)} testi")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
