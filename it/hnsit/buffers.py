"""Limiti di lunghezza dei campi di testo salvati in array a dimensione fissa.

In pokeemerald-expansion molti testi non sono puntatori ma array `u8 campo[N]`
dentro struct in ROM: se la traduzione e' piu' lunga dell'inglese il compilatore
si ferma con `excess elements in array initializer` (e' successo davvero su
`categoryName[13]`: "Magician" -> "Prestigiatore"). Qui i limiti si ricavano
dai sorgenti cosi' restano allineati al gioco, e la verifica li usa come
problema duro PRIMA della build.

Limite = byte dell'array meno il terminatore EOS.
"""

from __future__ import annotations

import json
import re
from dataclasses import dataclass, field
from pathlib import Path

# struct di cui ci interessa il testo, per file di dati
FILE_STRUCT = {
    "src/data/pokemon/species_info": "SpeciesInfo",
    "src/data/types_info": "TypeInfo",
    "src/data/abilities": "AbilityInfo",
    "src/data/trainer_classes": "TrainerClass",
    "src/data/trainers": "Trainer",
    "src/data/battle_frontier/trainer_hill": "TrainerHillTrainer",
    "src/data/battle_environment": "BattleEnvironment",
    "src/data/items": "ItemInfo",  # nomi via macro ITEM_NAME, non array
}

# limiti imparati dagli errori di build: it/data/limits_learned.json
LEARNED_FILE = "it/data/limits_learned.json"

STRUCT_HEAD_RE = re.compile(r"\bstruct\s+(?P<name>\w+)\s*(?:/\*.*?\*/\s*)?\{")


def iter_structs(text: str):
    """(nome, corpo) di ogni struct, con le graffe bilanciate.

    Con una regex pigra `.*?\\n};` si perdono i campi dopo un union/struct
    annidato (era il caso di `SpeciesInfo.categoryName`).
    """
    for m in STRUCT_HEAD_RE.finditer(text):
        start = m.end() - 1
        depth = 0
        for i in range(start, len(text)):
            if text[i] == "{":
                depth += 1
            elif text[i] == "}":
                depth -= 1
                if depth == 0:
                    yield m.group("name"), text[start + 1 : i]
                    break


FIELD_RE = re.compile(r"\bu8\s+(?P<field>\w+)\s*\[\s*(?P<size>[^\]]+)\s*\]")
# array di stringhe: `static const u8 sNames[][PLAYER_NAME_LENGTH + 1] = {`
ARRAY_DECL_RE = re.compile(
    r"\bu8\s+(?P<name>[A-Za-z_]\w*)\s*(?:\[[^\]]*\]\s*)*\[\s*(?P<size>[^\]]+)\s*\]\s*=\s*\{"
)
DEFINE_RE = re.compile(r"^\s*#define\s+(?P<name>[A-Z]\w*)\s+(?P<value>\d+)\s*$", re.M)


@dataclass(frozen=True)
class Limits:
    """Limiti per (file, campo) in byte utili (senza EOS)."""

    fields: dict[tuple[str, str], int]
    structs: dict[str, dict[str, int]]
    arrays: dict[str, dict[str, int]]
    learned: dict[str, dict[str, int]] = field(default_factory=dict)

    @classmethod
    def load(cls, repo: Path) -> "Limits":
        defines: dict[str, int] = {}
        for path in list((repo / "include").rglob("*.h")):
            for m in DEFINE_RE.finditer(path.read_text(encoding="utf-8", errors="replace")):
                defines.setdefault(m.group("name"), int(m.group("value")))
        structs: dict[str, dict[str, int]] = {}
        for path in list((repo / "include").rglob("*.h")):
            text = path.read_text(encoding="utf-8", errors="replace")
            for name, body in iter_structs(text):
                fields: dict[str, int] = {}
                for f in FIELD_RE.finditer(body):
                    size = _eval_size(f.group("size"), defines)
                    if size is None or not 2 <= size <= 64:
                        continue
                    fields[f.group("field")] = size - 1
                if fields:
                    structs.setdefault(name, {}).update(fields)
        arrays: dict[str, dict[str, int]] = {}
        for path in sorted(list((repo / "src").rglob("*.c")) + list((repo / "src").rglob("*.h"))):
            rel = path.relative_to(repo).as_posix()
            text = path.read_text(encoding="utf-8", errors="replace")
            found: dict[str, int] = {}
            for m in ARRAY_DECL_RE.finditer(text):
                size = _eval_size(m.group("size"), defines)
                if size is None or not 2 <= size <= 64:
                    continue
                found[m.group("name")] = size - 1
            if found:
                arrays[rel] = found
        learned: dict[str, dict[str, int]] = {}
        learned_path = repo / LEARNED_FILE
        if learned_path.exists():
            try:
                raw = json.loads(learned_path.read_text(encoding="utf-8"))
            except json.JSONDecodeError:
                raw = {}
            for rel, fields_map in raw.items():
                if isinstance(fields_map, dict):
                    learned[rel] = {str(k): int(v) for k, v in fields_map.items()}
        out: dict[tuple[str, str], int] = {}
        for prefix, struct in FILE_STRUCT.items():
            for field_name, limit in structs.get(struct, {}).items():
                if not _is_text_field(field_name):
                    continue
                out[(prefix, field_name)] = limit
        return cls(fields=out, structs=structs, arrays=arrays, learned=learned)

    def limit(self, file: str, label: str | None) -> int | None:
        """Limite per un'unita' del file dato, dal suffisso del suo label."""
        if not label:
            return None
        field = label.split(".")[-1]
        # 1. limiti ricavati dai sorgenti (header): sono la verita'
        for (prefix, f), limit in self.fields.items():
            if file.startswith(prefix) and f == field:
                return limit
        # 2. limiti imparati dagli errori di build (per file esatto)
        for name in (field, *label.split(".")):
            limit = self.learned.get(file, {}).get(name)
            if limit is not None:
                return limit
        # array di stringhe dichiarati nel file (`u8 nome[][N] = {`)
        for name in label.split("."):
            limit = self.arrays.get(file, {}).get(name)
            if limit is not None:
                return limit
        return None

    def known_limits(self, file: str) -> list[tuple[str, int]]:
        return sorted((f, lim) for (p, f), lim in self.fields.items() if file.startswith(p))


def _is_text_field(field: str) -> bool:
    return any(k in field.lower() for k in ("name", "text", "word", "category", "title", "desc"))


def _eval_size(expr: str, defines: dict[str, int]) -> int | None:
    """Valuta `POKEMON_NAME_LENGTH + 1` con i #define del repo."""
    expr = expr.strip()
    if expr.isdigit():
        return int(expr)
    total = 0
    for tok in re.split(r"\s*\+\s*", expr):
        tok = tok.strip()
        if tok.isdigit():
            total += int(tok)
        elif tok in defines:
            total += defines[tok]
        else:
            return None
    return total or None


def item_limits(repo: Path) -> dict[tuple[str, str], int]:
    """Limiti dei nomi oggetto: la macro ITEM_NAME usa COMPOUND_STRING_SIZE_LIMIT."""
    text = ""
    for rel in ("src/data/items.h", "include/data.h"):
        path = repo / rel
        if path.exists():
            text += path.read_text(encoding="utf-8", errors="replace")
    primary = re.search(r"#define\s+ITEM_NAME\s*\(\w+\)\s*COMPOUND_STRING_SIZE_LIMIT\(\w+,\s*(\w+)\)", text)
    plural = re.search(r"#define\s+ITEM_PLURAL_NAME\s*\(\w+\)\s*COMPOUND_STRING_SIZE_LIMIT\(\w+,\s*(\w+)\)", text)
    if not (primary and plural):
        return {}
    sizes = {}
    for path in (repo / "include").rglob("*.h"):
        for m in DEFINE_RE.finditer(path.read_text(encoding="utf-8", errors="replace")):
            sizes.setdefault(m.group("name"), int(m.group("value")))
    out = {}
    if primary.group(1) in sizes:
        out[("src/data/items", "name")] = sizes[primary.group(1)]
    if plural.group(1) in sizes:
        out[("src/data/items", "pluralName")] = sizes[plural.group(1)]
    return out


def all_limits(repo: Path) -> Limits:
    """Limiti dei campi + limiti delle macro (nomi oggetto)."""
    limits = Limits.load(repo)
    limits.fields.update(item_limits(repo))
    return limits
