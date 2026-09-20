#!/usr/bin/env python3
"""Sostituisce le descrizioni del Pokedex con i testi ufficiali italiani.

Fonte: PokeAPI (`/api/v2/pokemon-species/<id>/`, campo `flavor_text_entries`,
voci con `language.name == "it"`). Sono i testi ufficiali del Pokedex dei
giochi. Preferenza di versione: emerald, ruby, sapphire, poi le altre, e in
ultima istanza la prima italiana disponibile.

A chi appartiene ogni blocco: nei file `src/data/pokemon/species_info/*.h`
ogni specie ha `.natDexNum = NATIONAL_DEX_XXX,`. Il numero PokeAPI si ricava
dal nome della costante (`NATIONAL_DEX_ZOROARK_HISUI` -> `zoroark`, perche'
le forme non hanno una voce propria in PokeAPI) e viene verificato contro
l'elenco ufficiale delle specie e contro `.speciesName`.

Vincoli di formato (imposti dal gioco, non negoziabili):
- al massimo 4 righe, ognuna sotto i 216 pixel col font di gioco
- le parole non si spezzano a meta'
- la forma del codice resta quella di pokeemerald:
      .description = COMPOUND_STRING(
          "prima riga\\n"
          "seconda riga"),

Uso:
    python3 it/tools/dex_descriptions_it.py              # anteprima
    python3 it/tools/dex_descriptions_it.py --apply       # scrive i file
    python3 it/tools/dex_descriptions_it.py --apply --only SPECIES_PIKACHU
"""

from __future__ import annotations

import argparse
import json
import re
import sys
import time
from concurrent.futures import ThreadPoolExecutor
from dataclasses import dataclass, field
from pathlib import Path
from urllib.error import HTTPError, URLError
from urllib.request import Request, urlopen

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "it"))

from hnsit import batching  # noqa: E402

SPECIES_DIR = ROOT / "src/data/pokemon/species_info"
CACHE_DIR = ROOT / "it/data/pokeapi"
SPECIES_CACHE = CACHE_DIR / "species"
INDEX_CACHE = CACHE_DIR / "species_index.json"
API = "https://pokeapi.co/api/v2"

LIMIT_PX = 216  # tetto assoluto per riga
WRAP_PX = 214  # margine di sicurezza per il wrapping
MAX_LINES = 4
IND1 = "        "  # indentazione di `.description = ...`
IND2 = "            "  # indentazione delle righe di testo

# ordine di preferenza delle versioni: prima i giochi GBA (testi brevi e
# della stessa lunghezza di quelli inglesi gia' nel repo), poi il resto
VERSIONS = [
    "emerald",
    "ruby",
    "sapphire",
    "firered",
    "leafgreen",
    "diamond",
    "pearl",
    "platinum",
    "heartgold",
    "soulsilver",
    "black",
    "white",
    "black-2",
    "white-2",
    "x",
    "y",
    "omega-ruby",
    "alpha-sapphire",
    "sun",
    "moon",
    "ultra-sun",
    "ultra-moon",
    "lets-go-pikachu",
    "lets-go-eevee",
    "sword",
    "shield",
    "brilliant-diamond",
    "shining-pearl",
    "legends-arceus",
    "scarlet",
    "violet",
]

# parole funzionali inglesi: servono per capire se il blocco attuale e' ancora
# in inglese quando il testo non combacia con nessuna voce di PokeAPI
EN_WORDS = {
    "the", "of", "and", "its", "with", "this", "that", "from", "into", "when",
    "there", "they", "their", "has", "have", "can", "will", "may", "out",
    "about", "over", "under", "because", "while", "which", "very", "also",
}

# caratteri che il charmap del gioco non ha: sostituzioni sicure.
# Attenzione: la virgoletta dritta `"` NON e' nel charmap, le virgolette
# tipografiche “ ” (177/178) si': quelle di PokeAPI restano come sono.
SUBSTITUTIONS = {
    "\u2019": "'",  # apostrofo tipografico
    "\u2018": "'",
    "\u2013": "-",  # en dash
    "\u2014": "-",  # em dash
    "\u2026": "...",
    "\u00a0": " ",
    "\u00ad": "",  # soft hyphen
    "\u200b": "",
    "\ufeff": "",
    "\u02bc": "'",
    "\u2032": "'",
    "\u2212": "-",
}

# ---------------------------------------------------------------------------
# PokeAPI
# ---------------------------------------------------------------------------


def _get(url: str, cache: Path, tries: int = 4) -> dict:
    """GET con cache su disco: un file JSON per risposta."""
    if cache.exists():
        try:
            return json.loads(cache.read_text(encoding="utf-8"))
        except json.JSONDecodeError:
            cache.unlink()  # cache corrotta: si riscarica
    last: Exception | None = None
    for attempt in range(tries):
        try:
            req = Request(url, headers={"User-Agent": "hns-it-dex/1.0"})
            with urlopen(req, timeout=30) as fh:
                data = json.loads(fh.read().decode("utf-8"))
            cache.parent.mkdir(parents=True, exist_ok=True)
            cache.write_text(json.dumps(data, ensure_ascii=False), encoding="utf-8")
            return data
        except (HTTPError, URLError, TimeoutError) as exc:
            last = exc
            time.sleep(1.5 * (attempt + 1))
    raise RuntimeError(f"PokeAPI non raggiungibile: {url}: {last}")


def species_index() -> dict[int, str]:
    """id -> nome ufficiale, da /pokemon-species?limit=2000 (una sola chiamata)."""
    data = _get(f"{API}/pokemon-species?limit=2000", INDEX_CACHE)
    out = {}
    for row in data["results"]:
        m = re.search(r"/pokemon-species/(\d+)/?$", row["url"])
        if m:
            out[int(m.group(1))] = row["name"]
    return out


def fetch_species(ids: list[int], workers: int = 8) -> None:
    """Scarica (o legge dalla cache) le schede delle specie richieste."""

    def one(pid: int) -> None:
        _get(f"{API}/pokemon-species/{pid}/", SPECIES_CACHE / f"{pid}.json")

    with ThreadPoolExecutor(max_workers=workers) as pool:
        list(pool.map(one, ids))


def cached_species(pid: int) -> dict:
    return json.loads((SPECIES_CACHE / f"{pid}.json").read_text(encoding="utf-8"))


# ---------------------------------------------------------------------------
# mappa NATIONAL_DEX_XXX -> id PokeAPI
# ---------------------------------------------------------------------------


def dex_enum_order() -> list[str]:
    """Costanti di NationalDexOrder nell'ordine in cui sono dichiarate."""
    txt = (ROOT / "include/constants/pokedex.h").read_text(encoding="utf-8")
    m = re.search(r"enum NationalDexOrder\s*\{(.*?)\};", txt, re.S)
    if not m:
        raise SystemExit("enum NationalDexOrder non trovato in include/constants/pokedex.h")
    return re.findall(r"^\s*(NATIONAL_DEX_[A-Z0-9_]+)", m.group(1), re.M)


def build_dex_map(index: dict[int, str]) -> dict[str, int]:
    """NATIONAL_DEX_XXX -> id PokeAPI, per nome (le forme ricadono sulla specie).

    Le costanti in coda all'enum (forme regionali aggiunte dalla hack, tipo
    NATIONAL_DEX_ZOROARK_HISUI) non sono in ordine di dex nazionale: per quelle
    si toglie il suffisso di forma e si cerca il nome base.
    """
    by_name = {name: pid for pid, name in index.items()}
    out: dict[str, int] = {}
    for const in dex_enum_order():
        if const == "NATIONAL_DEX_NONE":
            continue
        toks = const[len("NATIONAL_DEX_"):].lower().split("_")
        for i in range(len(toks), 0, -1):
            cand = "-".join(toks[:i])
            if cand in by_name:
                out[const] = by_name[cand]
                break
    return out


# ---------------------------------------------------------------------------
# lettura dei blocchi `.description = COMPOUND_STRING(...)`
# ---------------------------------------------------------------------------

SPECIES_RE = re.compile(r"^\s*\[(SPECIES_[A-Z0-9_]+)\]\s*=\s*$")
DEX_RE = re.compile(r"^\s*\.natDexNum\s*=\s*(NATIONAL_DEX_[A-Z0-9_]+)\s*,")
NAME_RE = re.compile(r'^\s*\.speciesName\s*=\s*_\("([^"]*)"\)')
OPEN_RE = re.compile(r"^( *)(\.description = COMPOUND_STRING\()$")
LIT_RE = re.compile(r'^ *"(.*)"(?:\),)?$')
MACRO_RE = re.compile(r"^\s*([A-Z][A-Z0-9_]{3,})\s*\(")
DEFINE_RE = re.compile(r"#define\s+([A-Z0-9_]+)\s*\(")


@dataclass
class Block:
    path: Path
    start: int  # indice (0-based) della riga `.description = COMPOUND_STRING(`
    end: int  # indice (0-based) della riga che chiude con `"),`
    species: str = ""
    dex: str | None = None
    species_name: str = ""
    macro: str | None = None  # macro di famiglia usata dalla voce (`..._MISC_INFO`)
    lines: list[str] = field(default_factory=list)  # righe visibili attuali


def load_misc_macros() -> dict[str, dict]:
    """Macro tipo `VIVILLON_MISC_INFO`: nome -> {dex, nome, annidata}.

    Alcune voci (Vivillon, Flabe'be', Floette, Florges, Alcremie, Unown...)
    non scrivono `.natDexNum` nel blocco: sta dentro la macro di famiglia.
    Certe famiglie hanno due livelli (`FLOETTE_NORMAL_INFO` chiama
    `FLOETTE_MISC_INFO`), quindi si segue anche la catena.
    """
    out: dict[str, dict] = {}
    for path in sorted(SPECIES_DIR.glob("*.h")):
        lines = path.read_text(encoding="utf-8").splitlines()
        i = 0
        while i < len(lines):
            m = DEFINE_RE.match(lines[i])
            if not m:
                i += 1
                continue
            body = [lines[i]]
            j = i
            while body[-1].rstrip().endswith("\\") and j + 1 < len(lines):
                j += 1
                body.append(lines[j])
            text = "\n".join(body)
            dm = re.search(r"\.natDexNum\s*=\s*(NATIONAL_DEX_[A-Z0-9_]+)", text)
            sn = re.search(r'\.speciesName\s*=\s*_\("([^"]*)"\)', text)
            annidata = None
            for extra in body[1:]:
                mm = MACRO_RE.match(extra)
                if mm:
                    annidata = mm.group(1)
                    break
            out[m.group(1)] = {"dex": dm.group(1) if dm else None,
                               "nome": sn.group(1) if sn else "",
                               "annidata": annidata}
            i = j + 1
    return out


def parse_file(path: Path) -> list[Block]:
    """Tutti i blocchi COMPOUND_STRING di descrizione, con la specie di appartenenza."""
    raw = path.read_text(encoding="utf-8").splitlines()
    blocks: list[Block] = []
    species = ""
    dex: str | None = None
    sname = ""
    macro: str | None = None
    i = 0
    while i < len(raw):
        line = raw[i]
        m = SPECIES_RE.match(line)
        if m:
            species, dex, sname, macro = m.group(1), None, "", None
            i += 1
            continue
        m = DEX_RE.match(line)
        if m:
            dex = m.group(1)
            i += 1
            continue
        m = NAME_RE.match(line)
        if m:
            sname = m.group(1)
            i += 1
            continue
        m = MACRO_RE.match(line)
        if m and not line.lstrip().startswith("."):
            macro = m.group(1)
            i += 1
            continue
        m = OPEN_RE.match(line)
        if m:
            j = i + 1
            literals: list[str] = []
            while j < len(raw):
                lm = LIT_RE.match(raw[j])
                if not lm:
                    break
                literals.append(lm.group(1))
                if raw[j].rstrip().endswith("),"):
                    break
                j += 1
            blk = Block(path=path, start=i, end=j, species=species, dex=dex,
                        species_name=sname, macro=macro, lines=visible_lines(literals))
            blocks.append(blk)
            i = j + 1
            continue
        i += 1
    return blocks


def unescape(lit: str) -> str:
    """Dal letterale C al testo vero (`\\n` -> a capo, `\\"` -> virgoletta)."""
    out: list[str] = []
    k = 0
    while k < len(lit):
        ch = lit[k]
        if ch == "\\" and k + 1 < len(lit):
            nxt = lit[k + 1]
            if nxt == "n":
                out.append("\n")
            elif nxt == "l":
                out.append("\n")
            elif nxt in ('"', "\\", "'"):
                out.append(nxt)
            else:
                out.append(nxt)
            k += 2
            continue
        out.append(ch)
        k += 1
    return "".join(out)


def escape(text: str) -> str:
    return text.replace("\\", "\\\\").replace('"', '\\"')


def visible_lines(literals: list[str]) -> list[str]:
    """Righe visibili del blocco (un `\\n` finale apre la riga seguente)."""
    text = "".join(unescape(lit) for lit in literals)
    text = text.replace("\f", "")
    return [ln for ln in text.split("\n")]


def norm(text: str) -> str:
    """Forma normalizzata per confrontare i testi (apostrofi, spazi, maiuscole)."""
    text = text.replace("\u2019", "'").replace("\u2018", "'")
    text = text.replace("\u00ad", "").replace("\u00a0", " ")
    text = re.sub(r"\s+", " ", text)
    return text.strip().lower()


# ---------------------------------------------------------------------------
# scelta del testo italiano
# ---------------------------------------------------------------------------


def italian_entries(sheet: dict) -> list[tuple[str, str]]:
    """(versione, testo) delle voci italiane, nell'ordine di preferenza."""
    found: dict[str, str] = {}
    for entry in sheet.get("flavor_text_entries", []):
        if entry.get("language", {}).get("name") != "it":
            continue
        ver = entry.get("version", {}).get("name", "?")
        found.setdefault(ver, entry.get("flavor_text", ""))
    out = [(v, found[v]) for v in VERSIONS if v in found]
    out += [(v, t) for v, t in found.items() if v not in VERSIONS]
    return out


def all_entries(sheet: dict, lang: str) -> set[str]:
    return {
        norm(e.get("flavor_text", ""))
        for e in sheet.get("flavor_text_entries", [])
        if e.get("language", {}).get("name") == lang
    }


def clean(text: str) -> str:
    """Toglie `\\n` e `\\f`, normalizza spazi e apostrofi tipografici.

    Il grado centigrado non e' nel charmap: i testi del gioco (e quelli gia'
    tradotti in questo repo, es. "oltre i 3.000 gradi") usano "gradi".
    """
    for bad, good in SUBSTITUTIONS.items():
        text = text.replace(bad, good)
    text = text.replace("\f", " ").replace("\n", " ").replace("\r", " ")
    text = re.sub(r"\s*°\s*C\b", " gradi", text)
    text = re.sub(r"\s*°", " gradi", text)
    text = re.sub(r"\s+", " ", text)
    # trattino in fondo alla riga spezzata da PokeAPI (parola divisa)
    text = re.sub(r"(\w)-\s+(\w)", r"\1\2", text)
    return text.strip()


# ---------------------------------------------------------------------------
# impaginazione
# ---------------------------------------------------------------------------


def word_widths(words: list[str], metrics) -> tuple[list[int], int]:
    ws = [metrics.line_width(w)[0] for w in words]
    sp = metrics.line_width(" ")[0]
    return ws, sp


def split_cost(ws: list[int], sp: int, limit: int, n_lines: int) -> list[int] | None:
    """Divide le parole in `n_lines` righe entro `limit` px, il piu' uniformi
    possibile (costo quadratico, con peso triplo sull'ultima riga per non
    lasciare una parola orfana in fondo). Ritorna le lunghezze dei gruppi."""
    n = len(ws)
    if n_lines < 1 or n_lines > n:
        return None
    prefix = [0] * (n + 1)
    for i, w in enumerate(ws):
        prefix[i + 1] = prefix[i] + w + sp

    def width(i: int, j: int) -> int:  # larghezza di words[i:j]
        return prefix[j] - prefix[i] - sp

    INF = float("inf")
    # f[k][i]: costo minimo per le parole da i a n su k righe
    f = [[INF] * (n + 1) for _ in range(n_lines + 1)]
    nxt = [[-1] * (n + 1) for _ in range(n_lines + 1)]
    for k in range(n_lines + 1):
        f[k][n] = 0
    for k in range(1, n_lines + 1):
        for i in range(n - 1, -1, -1):
            best, arg = INF, -1
            for j in range(i + 1, n + 1):
                w = width(i, j)
                if w > limit:
                    break
                weight = 3 if j == n else 1
                cost = (limit - w) ** 2 * weight + f[k - 1][j]
                if cost < best:
                    best, arg = cost, j
            f[k][i], nxt[k][i] = best, arg
        if f[1][0] == INF:
            pass
    if f[n_lines][0] == INF:
        return None
    groups: list[int] = []
    i, k = 0, n_lines
    while k > 0 and i < n:
        j = nxt[k][i]
        groups.append(j - i)
        i, k = j, k - 1
    return groups


def wrap(text: str, metrics, limit: int = WRAP_PX) -> list[str] | None:
    """Righe di testo entro `limit` px, al massimo MAX_LINES. None se non entra."""
    words = [w for w in text.split(" ") if w]
    if not words:
        return None
    ws, sp = word_widths(words, metrics)
    if any(w > limit for w in ws):
        return None  # una parola da sola sfonda: non si spezza a meta'
    for n_lines in range(1, MAX_LINES + 1):
        groups = split_cost(ws, sp, limit, n_lines)
        if groups is None:
            continue
        out, i = [], 0
        for g in groups:
            out.append(" ".join(words[i:i + g]))
            i += g
        return out
    return None


SENT_RE = re.compile(r"(?<=[.!?])\s+")


def sentences(text: str) -> list[str]:
    return [s for s in SENT_RE.split(text) if s]


def varianti(text: str):
    """Versioni via via piu' corte del testo ufficiale, dalla piu' fedele.

    Quando la voce italiana e' piu' lunga di quella inglese (i giochi recenti
    scrivono paragrafi interi) non si puo' tenere tutto: si toglie prima cio'
    che non cambia il senso (le parentesi), poi le frasi in coda, poi la coda
    dell'ultima frase, sempre senza toccare l'inizio.
    """
    # 1) testo intero senza parentetiche
    stripped = re.sub(r"\s*\([^)]*\)", "", text)
    stripped = re.sub(r"\s+", " ", stripped).strip()
    if stripped != text:
        yield "senza parentesi", stripped
    # 2) prefissi di frasi (dalla piu' lunga)
    frasi = sentences(text)
    for m in range(len(frasi) - 1, 0, -1):
        cand = " ".join(frasi[:m]).strip()
        if cand and cand != text:
            yield f"{m} frasi", cand
    # 3) coda tagliata a virgola o a parola, chiudendo la frase col punto
    frasi0 = frasi[0] if frasi else text
    for sep in (", ", " "):
        parts = frasi0.split(sep)
        for m in range(len(parts) - 1, 0, -1):
            cand = sep.join(parts[:m]).rstrip(" ,;:")
            if len(cand.split()) < 3:
                break
            yield f"prima frase ridotta ({m} parti)", cand + "."


# ---------------------------------------------------------------------------
# classificazione del testo attuale
# ---------------------------------------------------------------------------


def key_name(name: str) -> str:
    """Nome di specie confrontabile (`NIDORAN♀` == `nidoran-f` == `Nidoran♀`)."""
    s = norm(name)
    s = s.replace("\u2640", " f").replace("\u2642", " m")
    return re.sub(r"[^a-z0-9]+", " ", s).strip()


def looks_english(text: str) -> bool:
    words = re.findall(r"[A-Za-z']+", text.lower())
    return any(w in EN_WORDS for w in words)


def classify(block: Block, sheet: dict) -> str:
    """`it` (gia' italiano), `en` (da tradurre), `?` (non riconosciuto)."""
    cur = norm(" ".join(block.lines))
    if cur in all_entries(sheet, "it"):
        return "it"
    if cur in all_entries(sheet, "en"):
        return "en"
    for e in sheet.get("flavor_text_entries", []):
        if norm(e.get("flavor_text", "")) == cur:
            # combacia con una voce ufficiale di una lingua non italiana
            return "en" if e.get("language", {}).get("name", "") not in ("it",) else "it"
    return "en" if looks_english(" ".join(block.lines)) else "?"


# ---------------------------------------------------------------------------
# riscrittura dei blocchi
# ---------------------------------------------------------------------------


def render(lines: list[str]) -> list[str]:
    out = [IND1 + ".description = COMPOUND_STRING("]
    for k, line in enumerate(lines):
        tail = '\\n"' if k < len(lines) - 1 else '"),'
        out.append(f'{IND2}"{escape(line)}{tail}')
    return out


@dataclass
class Esito:
    species: str
    dex: str | None
    stato: str  # sostituito | gia_it | inglese | errore
    motivo: str = ""
    versione: str = ""
    note: str = ""
    righe: list[str] = field(default_factory=list)
    blk: "Block | None" = None
    prima: str = ""  # it / en / ? : com'era il testo prima della sostituzione


def resolve_dexes(blocks: list[Block]) -> None:
    """Riempie `.natDexNum` mancanti (macro di famiglia, poi specie base).

    Alcune forme (Vivillon, Flabe'be', Florges, Unown...) non scrivono
    `.natDexNum` nel blocco: sta dentro la macro di famiglia. Se nemmeno quella
    c'e', il numero si eredita dalla specie base con lo stesso prefisso di nome.
    """
    misc = load_misc_macros()

    def da_macro(nome: str | None, salti: int = 5) -> tuple[str, str] | None:
        """Segue la catena delle macro finche' trova un numero di dex."""
        while nome and salti > 0:
            info = misc.get(nome)
            if not info:
                return None
            if info["dex"]:
                return info["dex"], info["nome"]
            nome, salti = info["annidata"], salti - 1
        return None

    noto: dict[str, str] = {}
    for blk in blocks:
        if blk.dex:
            noto[blk.species] = blk.dex
    for blk in blocks:
        if blk.dex is None:
            trovato = da_macro(blk.macro)
            if trovato:
                blk.dex, sname = trovato
                if not blk.species_name:
                    blk.species_name = sname
                noto.setdefault(blk.species, blk.dex)
    for blk in blocks:
        if blk.dex is None:
            for base in sorted(noto, key=len, reverse=True):
                if blk.species.startswith(base + "_"):
                    blk.dex = noto[base]
                    break


def process(blocks: list[Block], index: dict[int, str], dex_map: dict[str, int],
            metrics, only: str | None = None) -> list[Esito]:
    esiti: list[Esito] = []
    resolve_dexes(blocks)
    for blk in blocks:
        if only and blk.species != only:
            continue
        if blk.dex is None:
            esiti.append(Esito(blk.species, None, "inglese", "senza .natDexNum", blk=blk))
            continue
        pid = dex_map.get(blk.dex)
        if pid is None:
            esiti.append(Esito(blk.species, blk.dex, "inglese", "costante dex sconosciuta", blk=blk))
            continue
        sheet = cached_species(pid)
        if blk.species_name:
            # il nome ufficiale puo' essere in qualunque lingua: `.speciesName`
            # in questa fork e' inglese per i primi otto gen e italiano (o
            # inglese) per i paradossi di gen 9
            ufficiali = {key_name(n["name"]) for n in sheet.get("names", [])}
            if key_name(blk.species_name) not in ufficiali:
                esiti.append(Esito(blk.species, blk.dex, "inglese",
                                   f"nome non coerente ({blk.species_name} vs #{pid})", blk=blk))
                continue
        entries = italian_entries(sheet)
        if not entries:
            nota = "gia' in italiano" if not looks_english(" ".join(blk.lines)) else "ancora in inglese"
            esiti.append(Esito(blk.species, blk.dex, "gia_it" if nota.startswith("gia") else "inglese",
                               f"PokeAPI senza testo italiano ({nota})", blk=blk))
            continue
        stato = classify(blk, sheet)
        if stato == "it":
            esiti.append(Esito(blk.species, blk.dex, "gia_it",
                               "testo ufficiale italiano presente", blk=blk))
            continue
        versione, testo = entries[0]
        testo = clean(testo)
        cattivi = [ch for ch in testo if ch not in metrics.charmap]
        if cattivi:
            testo = "".join(SUBSTITUTIONS.get(ch, ch) for ch in testo)
            testo = re.sub(r"\s+", " ", testo).strip()
            restanti = sorted({ch for ch in testo if ch not in metrics.charmap})
            if restanti:
                esiti.append(Esito(blk.species, blk.dex, "inglese",
                                   "caratteri non rappresentabili: " + " ".join(restanti),
                                   blk=blk))
                continue
        righe = wrap(testo, metrics)
        nota = ""
        if righe is None:
            for nome, cand in varianti(testo):
                r = wrap(cand, metrics)
                if r is not None:
                    righe, nota = r, "accorciata: " + nome
                    break
        if righe is None:
            esiti.append(Esito(blk.species, blk.dex, "inglese",
                               "non entra in 4 righe (<216 px) nemmeno accorciata",
                               versione, blk=blk))
            continue
        esiti.append(Esito(blk.species, blk.dex, "sostituito", "", versione, nota, righe, blk))
        esiti[-1].prima = stato
    return esiti


def applica(esiti: list[Esito]) -> int:
    per_file: dict[Path, list[Esito]] = {}
    for esito in esiti:
        if esito.stato == "sostituito" and esito.blk is not None:
            per_file.setdefault(esito.blk.path, []).append(esito)
    scritti = 0
    for path, items in per_file.items():
        righe = path.read_text(encoding="utf-8").splitlines()
        items.sort(key=lambda e: e.blk.start, reverse=True)  # type: ignore[union-attr]
        for esito in items:
            blk = esito.blk
            assert blk is not None
            righe[blk.start:blk.end + 1] = render(esito.righe)
            scritti += 1
        path.write_text("\n".join(righe) + "\n", encoding="utf-8")
    return scritti


def main() -> int:
    ap = argparse.ArgumentParser(prog="dex_descriptions_it")
    ap.add_argument("--apply", action="store_true", help="scrive i file (default: anteprima)")
    ap.add_argument("--only", help="una sola specie (SPECIES_XXX)")
    ap.add_argument("--samples", type=int, default=12, help="esempi da stampare")
    ap.add_argument("--fetch", action="store_true", help="scarica solo la cache PokeAPI")
    args = ap.parse_args()

    index = species_index()
    dex_map = build_dex_map(index)
    print(f"specie PokeAPI: {len(index)}  costanti dex mappate: {len(dex_map)}")

    blocks: list[Block] = []
    for path in sorted(SPECIES_DIR.glob("gen_*_families.h")):
        blocks.extend(parse_file(path))
    print(f"blocchi .description = COMPOUND_STRING(...): {len(blocks)}")
    resolve_dexes(blocks)
    senza_dex = [b.species for b in blocks if b.dex is None]
    if senza_dex:
        print(f"senza numero di dex: {len(senza_dex)} (es. {senza_dex[:3]})")

    ids = sorted({dex_map[b.dex] for b in blocks if b.dex in dex_map})
    fetch_species(ids)
    if args.fetch:
        print(f"cache PokeAPI: {len(ids)} schede in {SPECIES_CACHE}")
        return 0

    metrics = batching.load_metrics()
    esiti = process(blocks, index, dex_map, metrics, args.only)

    conta: dict[str, int] = {}
    for e in esiti:
        conta[e.stato] = conta.get(e.stato, 0) + 1
    fuori = [e for e in esiti if e.stato in ("sostituito", "gia_it")
             and any(m > LIMIT_PX for m in [metrics.line_width(r)[0] for r in e.righe])]
    troppe = [e for e in esiti if e.stato in ("sostituito", "gia_it") and len(e.righe) > MAX_LINES]
    acc = [e for e in esiti if e.note.startswith("accorciata")]
    da_it = [e for e in esiti if e.stato == "sostituito" and e.prima != "en"]

    print(f"\n  sostituiti : {conta.get('sostituito', 0)}"
          f"  (di cui {len(da_it)} non erano riconoscibili come inglesi)")
    print(f"  gia' IT    : {conta.get('gia_it', 0)}")
    print(f"  in inglese : {conta.get('inglese', 0)}")
    print(f"  righe oltre {LIMIT_PX}px: {len(fuori)}   blocchi con piu' di {MAX_LINES} righe: {len(troppe)}")
    print(f"  accorciate : {len(acc)}")
    rimasti = [e for e in esiti if e.stato == "inglese"]
    if rimasti:
        print("\nancora in inglese:")
        for e in rimasti:
            print(f"    {e.species:<32} {e.dex or '-':<34} {e.motivo}")
    motivi: dict[str, int] = {}
    for e in esiti:
        if e.stato == "inglese":
            motivi[e.motivo] = motivi.get(e.motivo, 0) + 1
    for m, n in sorted(motivi.items(), key=lambda kv: -kv[1]):
        print(f"    inglese ({n}): {m}")

    esempi = [e for e in esiti if e.stato == "sostituito"][:args.samples]
    for e in esempi:
        print(f"\n  {e.species}  [{e.dex} -> #{e.dex and dex_map.get(e.dex)}]  versione: {e.versione} {e.note}")
        for r in e.righe:
            print(f"    {metrics.line_width(r)[0]:>3}px  {r}")

    if args.apply:
        n = applica(esiti)
        report = CACHE_DIR / "dex_descriptions_report.json"
        report.write_text(json.dumps({
            "sostituiti": [{"specie": e.species, "dex": e.dex, "versione": e.versione,
                            "nota": e.note, "righe": e.righe} for e in esiti
                           if e.stato == "sostituito"],
            "lasciati": [{"specie": e.species, "dex": e.dex, "motivo": e.motivo}
                         for e in esiti if e.stato != "sostituito"],
        }, ensure_ascii=False, indent=1), encoding="utf-8")
        print(f"\nblocchi riscritti: {n}   report: {report}")
    else:
        print("\nanteprima (nessuna scrittura): usa --apply per scrivere")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
