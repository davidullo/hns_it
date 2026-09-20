"""Parser dei testi di pokehns-expansion.

Due superfici:

* blocchi `.inc`  -> `data/text/*.inc`, `data/maps/**/*.inc`, `data/scripts/*.inc`
* stringhe C      -> `_("...")` e `COMPOUND_STRING("...")` in `src/` e `include/`

Il modulo espone un modello unico (`Unit`) e la conversione fra il testo
"sorgente" (con escape e terminatori) e le righe visibili (quelle che un
traduttore vede e riscrive).
"""

from __future__ import annotations

import hashlib
import re
from dataclasses import dataclass, field, asdict
from pathlib import Path

BS = chr(92)  # backslash, senza dipendere dall'escaping del linguaggio

CONTROL_RE = re.compile(r"\{[^}]*\}")
PLACEHOLDER_RE = re.compile(r"\{[^}]*\}")
LABEL_RE = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*)::?(?:\s*@.*)?$")
DIRECTIVE_RE = re.compile(r"^\s*#\s*(if|ifdef|ifndef|elif|else|endif)\b(.*)$")

INC_GLOBS = ("data/text/*.inc", "data/maps/**/*.inc", "data/scripts/*.inc")
C_GLOBS = ("src/**/*.c", "src/**/*.h", "include/**/*.h")

# Macro della build HNS (include/constants/global.h, include/config/general.h)
MACROS = {"IS_HNS": 1, "IS_FRLG": 0, "BUGFIX": 1, "UBFIX": 1, "MODERN": 1}

# Terminatori di riga/pagina dei testi (scritti con il backslash nel sorgente)
TERMINATORS = ("n", "p", "l")


# --------------------------------------------------------------------------
# charmap e larghezze
# --------------------------------------------------------------------------


# Una voce di charmap: chiave, '=', poi byte esadecimali.
# La chiave puo' contenere '=' (es. `'=' = 35`), quindi si divide sull'ULTIMO '='.
CHARMAP_RE = re.compile(r"^(?P<key>.*\S)\s*=\s*(?P<hex>[0-9A-Fa-f]{2}(?:\s+[0-9A-Fa-f]{2})*)\s*$")


def parse_charmap(path: Path) -> dict:
    table: dict[str, list[int]] = {}
    for raw in path.read_text(encoding="utf-8").splitlines():
        line = raw.split("@")[0].rstrip()
        if not line.strip():
            continue
        m = CHARMAP_RE.match(line)
        if not m:
            continue
        key = m.group("key").strip()
        chars: list[str] = []
        if len(key) >= 2 and key[0] == key[-1] and key[0] in "'\"":
            body = key[1:-1]
            if body.startswith(BS) and len(body) > 1:
                chars = [body[1]]
            elif body:
                chars = [body]
        elif len(key) == 1:
            chars = [key]
        if not chars:
            continue
        values = [int(tok, 16) for tok in m.group("hex").split()]
        for ch in chars:
            table.setdefault(ch, values)
    return table


def parse_widths(path: Path) -> list[int]:
    text = path.read_text(encoding="utf-8")
    m = re.search(r"gFontNormalLatinGlyphWidths\[\]\s*=\s*\{(.*?)\};", text, re.S)
    if not m:
        raise SystemExit("gFontNormalLatinGlyphWidths non trovato in src/fonts.c")
    return [int(tok) for tok in re.findall(r"\d+", m.group(1))]


class Metrics:
    """Larghezze in pixel del testo, dal charmap e da src/fonts.c."""

    def __init__(self, repo: Path):
        self.charmap = parse_charmap(repo / "charmap.txt")
        self.widths = parse_widths(repo / "src" / "fonts.c")

    def line_width(self, line: str) -> tuple[int, list[str]]:
        total, unknown = 0, []
        for ch in line:
            seq = self.charmap.get(ch)
            if seq is None:
                unknown.append(ch)
                total += self.widths[0x3F]
                continue
            for byte in seq:
                total += self.widths[byte] if byte < len(self.widths) else self.widths[0x3F]
        return total, unknown

    def encoded_len(self, text: str) -> int:
        """Byte occupati da `text` nella ROM (per i campi ad array fisso).

        Serve per capire se un testo entra in `u8 campo[N]`: i caratteri
        fuori charmap contano 1 byte, come li codificherebbe il gioco.
        """
        total = 0
        for ch in text:
            seq = self.charmap.get(ch)
            total += len(seq) if seq else 1
        return total


# --------------------------------------------------------------------------
# preprocessore minimale per i .inc
# --------------------------------------------------------------------------


def eval_condition(expr: str, macros: dict) -> bool:
    expr = expr.split("@")[0].strip()
    expr = expr.replace("&&", " and ").replace("||", " or ")
    expr = re.sub(r"!\s*", " not ", expr)
    for name, value in macros.items():
        expr = re.sub(r"\b%s\b" % re.escape(name), str(value), expr)
    expr = re.sub(r"\bdefined\b", "", expr)
    expr = re.sub(r"\b[A-Za-z_][A-Za-z0-9_]*\b", "0", expr)
    try:
        return bool(eval(expr, {"__builtins__": {}}, {}))
    except Exception:
        return True


def active_lines(text: str, macros: dict | None = None) -> list[tuple[int, str]]:
    """[(lineno, riga)] escludendo i rami #if non compilati."""
    macros = MACROS if macros is None else macros
    out: list[tuple[int, str]] = []
    stack: list[tuple[bool, bool, bool]] = []
    for lineno, raw in enumerate(text.splitlines(), 1):
        m = DIRECTIVE_RE.match(raw)
        if m:
            kind, rest = m.group(1), m.group(2)
            if kind in ("if", "ifdef", "ifndef"):
                parent = stack[-1][2] if stack else True
                if kind == "ifdef":
                    cond = rest.strip().split()[0] in macros if rest.strip() else False
                elif kind == "ifndef":
                    cond = rest.strip().split()[0] not in macros if rest.strip() else False
                else:
                    cond = eval_condition(rest, macros)
                stack.append((cond, cond, parent and cond))
            elif kind == "elif":
                if stack:
                    taken, _, _ = stack[-1]
                    parent = stack[-2][2] if len(stack) > 1 else True
                    cond = (not taken) and eval_condition(rest, macros)
                    stack[-1] = (taken or cond, taken or cond, parent and cond)
            elif kind == "else":
                if stack:
                    taken, _, _ = stack[-1]
                    parent = stack[-2][2] if len(stack) > 1 else True
                    stack[-1] = (True, True, parent and not taken)
            elif kind == "endif":
                if stack:
                    stack.pop()
            continue
        if stack[-1][2] if stack else True:
            out.append((lineno, raw))
    return out


# --------------------------------------------------------------------------
# lettura/scrittura dei letterali
# --------------------------------------------------------------------------


def read_quoted(rest: str, start: int = 0) -> tuple[str | None, int, int]:
    """Da `rest` che inizia con `"` legge il letterale.

    Ritorna (contenuto_come_scritto, inizio_contenuto, fine_contenuto):
    gli indici sono dentro `rest` e il contenuto esclude le virgolette.
    """
    if start >= len(rest) or rest[start] != '"':
        return None, -1, -1
    buf: list[str] = []
    i = start + 1
    body_start = i
    while i < len(rest):
        ch = rest[i]
        if ch == BS and i + 1 < len(rest):
            buf.append(ch)
            buf.append(rest[i + 1])
            i += 2
            continue
        if ch == '"':
            return "".join(buf), body_start, i
        buf.append(ch)
        i += 1
    return None, -1, -1


def escape_body(body: str) -> str:
    """Il letterale va scritto nel sorgente esattamente com'e' in memoria."""
    return body


def parse_string_line(raw: str) -> tuple[str, int, int, str, str] | None:
    """`.string "..."` -> (contenuto, inizio, fine, prefisso, suffisso)."""
    stripped = raw.lstrip()
    indent = raw[: len(raw) - len(stripped)]
    if not stripped.startswith(".string"):
        return None
    rest = stripped[len(".string"):]
    pad = rest[: len(rest) - len(rest.lstrip())]
    content, s, e = read_quoted(rest, len(pad))
    if content is None:
        return None
    prefix = indent + ".string" + pad
    tail = rest[e + 1:]
    return content, len(indent) + len(".string") + len(pad) + s, len(indent) + len(".string") + len(pad) + e, prefix, tail


def split_segment(body: str) -> list[tuple[str, str]]:
    """Da un letterale a [(testo_visibile, terminatore)].

    Il terminatore e' `\\n`, `\\p`, `\\l`, oppure tutto quello che segue il
    primo `$` (che chiude la stringa: nei testi giapponesi il resto e' padding
    di `$` e va lasciato esattamente com'e').
    """
    parts: list[tuple[str, str]] = []
    buf: list[str] = []
    i = 0
    while i < len(body):
        ch = body[i]
        if ch == BS and i + 1 < len(body):
            nxt = body[i + 1]
            if nxt in TERMINATORS:
                parts.append(("".join(buf), BS + nxt))
                buf = []
                i += 2
                continue
            if nxt == "$":
                parts.append(("".join(buf), BS + body[i + 1:]))
                buf = []
                i = len(body)
                continue
            buf.append(nxt)
            i += 2
            continue
        if ch == "$":
            parts.append(("".join(buf), body[i:]))
            buf = []
            i = len(body)
            continue
        buf.append(ch)
        i += 1
    parts.append(("".join(buf), ""))
    return parts


def join_segment(parts: list[tuple[str, str]]) -> str:
    out = []
    for text, term in parts:
        out.append(text)
        if term:
            out.append(term)
    return "".join(out)


def sha1_of(segments: list[str]) -> str:
    h = hashlib.sha1()
    for seg in segments:
        h.update(seg.encode("utf-8"))
        h.update(b"\x00")
    return h.hexdigest()


def visible_text(segments: list[str]) -> str:
    return "".join(text for seg in segments for text, _ in split_segment(seg))


# --------------------------------------------------------------------------
# Unit
# --------------------------------------------------------------------------


@dataclass
class Unit:
    key: str
    kind: str  # "inc" | "cstr"
    file: str
    label: str
    hint: str = ""
    segments: list[str] = field(default_factory=list)  # EN, come scritto nel sorgente
    sha1: str = ""
    it: list[str] | None = None  # righe tradotte (senza terminatori)
    status: str = "pending"  # pending | translated | reviewed | skipped
    note: str = ""

    def __post_init__(self):
        if not self.sha1:
            self.sha1 = sha1_of(self.segments)

    # --- vista per il traduttore -------------------------------------
    @staticmethod
    def _seg_parts(seg: str) -> list[tuple[str, str]]:
        return [(text, term) for text, term in split_segment(seg) if text or term]

    @property
    def lines(self) -> list[tuple[str, str]]:
        """Righe visibili + terminatori, in ordine."""
        return [part for seg in self.segments for part in self._seg_parts(seg)]

    @property
    def visible_lines(self) -> list[str]:
        return [text for text, _ in self.lines]

    @property
    def structural_segments(self) -> list[int]:
        """Indici dei segmenti senza testo utile (es. solo `\\l`)."""
        out = []
        for idx, seg in enumerate(self.segments):
            if not visible_text([seg]).strip():
                out.append(idx)
        return out

    def rebuild(self, it_lines: list[str]) -> list[str]:
        """Ricostruisce i segmenti tradotti a partire dalle righe IT."""
        if len(it_lines) != len(self.lines):
            raise ValueError(f"{self.key}: {len(self.lines)} righe attese, {len(it_lines)} ricevute")
        out: list[str] = []
        pos = 0
        for seg in self.segments:
            parts = self._seg_parts(seg)
            n = len(parts)
            if not visible_text([seg]).strip():
                # segmento puramente strutturale: resta identico
                out.append(seg)
                pos += n
                continue
            chunk = [(it_lines[pos + i], parts[i][1]) for i in range(n)]
            pos += n
            out.append(join_segment(chunk))
        return out

    def to_json(self) -> dict:
        d = asdict(self)
        return d


# --------------------------------------------------------------------------
# blocchi .inc
# --------------------------------------------------------------------------


def iter_inc_units(repo: Path):
    """Genera le Unit dei blocchi `.inc` (una per etichetta)."""
    paths: list[Path] = []
    for pattern in INC_GLOBS:
        paths.extend(sorted(repo.glob(pattern)))
    seen: set[Path] = set()
    for path in paths:
        if path in seen:
            continue
        seen.add(path)
        rel = str(path.relative_to(repo))
        text = path.read_text(encoding="utf-8")
        label = None
        segments: list[str] = []
        hint = ""
        for lineno, raw in active_lines(text):
            m = LABEL_RE.match(raw)
            if m:
                if segments and label:
                    yield Unit(
                        key=f"inc:{rel}|{label}",
                        kind="inc",
                        file=rel,
                        label=label,
                        hint=hint,
                        segments=segments,
                    )
                label = m.group(1)
                segments = []
                hint = f"{rel}:{lineno}"
                continue
            parsed = parse_string_line(raw)
            if parsed is None:
                continue
            segments.append(parsed[0])
        if segments:
            name = label or f"{path.stem}_anon"
            yield Unit(
                key=f"inc:{rel}|{name}",
                kind="inc",
                file=rel,
                label=name,
                hint=hint or rel,
                segments=segments,
            )


def read_inc_blocks(repo: Path, rel: str) -> dict[str, list[str]]:
    """{etichetta: [segmenti]} per un singolo file .inc, per l'iniezione."""
    path = repo / rel
    text = path.read_text(encoding="utf-8")
    out: dict[str, list[str]] = {}
    label = None
    segments: list[str] = []
    for _lineno, raw in active_lines(text):
        m = LABEL_RE.match(raw)
        if m:
            if segments and label:
                out[label] = segments
            label = m.group(1)
            segments = []
            continue
        parsed = parse_string_line(raw)
        if parsed is None:
            continue
        segments.append(parsed[0])
    if segments and label:
        out[label] = segments
    if segments and not label:
        out[f"{Path(rel).stem}_anon"] = segments
    return out
