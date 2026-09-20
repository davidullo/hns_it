#!/usr/bin/env python3
"""Sostituisce le descrizioni delle mosse con i testi ufficiali italiani.

Fonte: PokeAPI (`/api/v2/move/<nome>/`, campo `flavor_text_entries`, voci con
`language.name == "it"`; per le mosse la versione sta in `version_group`).
Sono i testi ufficiali dei giochi. Preferenza: i gruppi piu' recenti
(scarlet-violet, sword-shield, ...), saltando le voci "Questa mossa non puo'
essere usata" che i giochi recenti usano per le mosse tagliate: in questa hack
le mosse si usano, quel testo mentirebbe.

Dove sta il testo: `src/data/moves_info.h`, due forme.
  - dentro `gMovesInfo`: `.description = COMPOUND_STRING(...)`, legata alla
    mossa dal blocco `[MOVE_XXX] = {` che la contiene;
  - in testa al file: `static const u8 sXxxDescription[] = _(...)`, condivisa
    da piu' mosse (`.description = sXxxDescription,`).
Entrambe possono essere spezzate da `#if/#elif/#else/#endif`: ogni ramo e' una
variante della stessa descrizione (stessa frase con un numero diverso, oppure
"congela" contro "assidera"). Le direttive non si toccano: si riscrive il
testo dentro ogni ramo, tenendo condizioni, ordine e indentazione.

Varianti: il testo ufficiale italiano descrive la meccanica moderna. Per i rami
che descrivono la meccanica vecchia non esiste una voce ufficiale distinta:
la tabella `ADATTATE` qui sotto tiene, per ogni ramo, la frase ufficiale
adattata al caso (stesso giro di parole, solo il dato che cambia). Ogni voce e'
indicizzata dal testo inglese attuale della variante: se quel testo cambia, la
voce non combacia piu' e la mossa resta in inglese invece di essere scritta a
caso.

Vincoli di formato (imposti dal gioco, non negoziabili):
- al massimo 4 righe, ognuna sotto i 216 pixel col font di gioco
- le parole non si spezzano a meta'
- la forma del codice resta quella di pokeemerald

Uso:
    python3 it/tools/move_descriptions_it.py              # anteprima
    python3 it/tools/move_descriptions_it.py --apply      # scrive il file
    python3 it/tools/move_descriptions_it.py --only MOVE_SPITE
    python3 it/tools/move_descriptions_it.py --fetch      # solo cache PokeAPI
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

MOVES_FILE = ROOT / "src/data/moves_info.h"
CACHE_DIR = ROOT / "it/data/pokeapi"
MOVE_CACHE = CACHE_DIR / "moves"
REPORT = CACHE_DIR / "move_descriptions_report.json"
API = "https://pokeapi.co/api/v2"

LIMIT_PX = 216  # tetto assoluto per riga
WRAP_PX = 214  # margine di sicurezza per il wrapping
MAX_LINES = 4

# gruppi di versioni, dal piu' recente: le descrizioni attuali sono le ultime
VERSION_GROUPS = [
    "scarlet-violet",
    "sword-shield",
    "brilliant-diamond-shining-pearl",
    "legends-arceus",
    "lets-go-pikachu-lets-go-eevee",
    "ultra-sun-ultra-moon",
    "sun-moon",
    "omega-ruby-alpha-sapphire",
    "x-y",
    "black-2-white-2",
    "black-white",
    "heartgold-soulsilver",
    "platinum",
    "diamond-pearl",
    "emerald",
    "firered-leafgreen",
    "ruby-sapphire",
    "crystal",
    "gold-silver",
    "red-blue",
    "yellow",
]

# le voci "mossa inutilizzabile" dei giochi recenti non descrivono la mossa
UNUSABLE = (
    "non puo essere usata",
    "non si puo usare",
    "consigliabile farla dimenticare",
    "cannot be used",
)

# parole inglesi che non compaiono mai in un testo italiano: bastano a dire
# "questo blocco non e' tradotto". L'elenco e' tarato sul file: capostipiti
# inglesi di frase (the, may, ...) e i sostantivi della descrizione meccanica
# che il traduttore ha lasciato tali (beam, storm, evasiveness, ...).
EN_MARK = set("""
the of foe foes your its and with may can cause causes sharply sharp speed user leave
last defense lower raise raises raising evasiveness from used using down field beam storm
attack attacks body grow poison toxic first into known burn paralysis para freeze freezing
frostbite gust ally allies effects while upping all half turns turn prevents sleep spores
cling envelops uproar flash drastically effectiveness varies harshly reduce reduces reducing
doubles inflicted moves physical cannot would should does not but or if out over under than
then there when which this that those these have has is are was were be been they them their
his her our to by it he she you fighting flying ground rock ghost steel fire water grass
psychic ice dragon dark fairy normal bug electric
""".split())

# caratteri che il charmap del gioco non ha: sostituzioni sicure (le stesse
# del tool per le specie, piu' il nome della specie in maiuscolo come usa qui)
SUBSTITUTIONS = {
    "\u2019": "'",  # apostrofo tipografico
    "\u2018": "'",
    "\u201c": '"',
    "\u201d": '"',
    "\u2013": "-",
    "\u2014": "-",
    "\u2026": "...",
    "\u00a0": " ",
    "\u00ad": "",
    "\u200b": "",
    "\ufeff": "",
    "\u02bc": "'",
    "\u2032": "'",
    "\u2212": "-",
}

# il gioco scrive il nome della specie cosi' (le voci ufficiali "Pokémon")
NAME_FIXES = [(re.compile(r"\bPokémon\b"), "POKéMON")]

# ---------------------------------------------------------------------------
# testi delle varianti che non hanno una voce ufficiale distinta
#
# per ogni blocco: `base` = testo inglese della variante descritta dal testo
# ufficiale italiano (quello che il tool prende da PokeAPI); `adattate` = le
# altre varianti, con la frase ufficiale adattata al caso. Le chiavi sono il
# testo inglese attuale della variante (righe unite con uno spazio):
# `python3 it/tools/move_descriptions_it.py --list-keys` le stampa.
# ---------------------------------------------------------------------------
ADATTATE: dict[str, dict] = {
    "MOVE_ICE_PUNCH": {
        "base": "Pugno ghiacciato che può freeze the foe.",
        "adattate": {
            # B_USE_FROSTBITE == TRUE: il congelamento diventa assideramento
            "Pugno ghiacciato che può leave the foe with frostbite.":
                "Colpisce il bersaglio con un pugno di ghiaccio che può assiderarlo.",
        },
    },
    "MOVE_DISABLE": {
        "base": "For 4 turns, prevents foe from using last used move.",
        "adattate": {
            "For 4-7 turns, prevents foe from using last used move.":
                "Per 4-7 turni impedisce al bersaglio di riutilizzare l'ultima mossa usata.",
            "For 2-5 turns, prevents foe from using last used move.":
                "Per 2-5 turni impedisce al bersaglio di riutilizzare l'ultima mossa usata.",
        },
    },
    "MOVE_ACID": {
        "base": "Spruzza un acido corrosivo. May lower Sp. Def.",
        "adattate": {
            "Spruzza un acido corrosivo. May lower Defense.":
                "Colpisce i nemici intorno spruzzando un acido corrosivo. Può anche ridurne la Difesa.",
        },
    },
    "MOVE_SURF": {
        "base": "Crea un'onda enorme, poi crashes it down on the field.",
        "adattate": {
            "Crea un'onda enorme, poi crashes it down on the foes.":
                "Un'onda enorme sommerge i nemici intorno a chi la scatena.",
        },
    },
    "MOVE_ICE_BEAM": {
        "base": "Investe il nemico con una beam that may freeze it.",
        "adattate": {
            "Investe il nemico con una beam. May cause frostbite.":
                "Il bersaglio è colpito da un raggio di energia gelida che può anche assiderarlo.",
        },
    },
    "MOVE_BLIZZARD": {
        "base": "Colpisce i nemici con una storm that may freeze it.",
        "adattate": {
            "Colpisce i nemici con una storm. May cause frostbite.":
                "Colpisce i nemici intorno con una tremenda tempesta di ghiaccio che può anche assiderarli.",
        },
    },
    "MOVE_GROWTH": {
        "base": "Forces the body to grow, raising Attack and Sp. Atk.",
        "adattate": {
            "Forces the body to grow and heightens Sp. Atk.":
                "Provoca la crescita immediata del corpo e l'aumento dell'Attacco Speciale di chi la usa.",
        },
    },
    "MOVE_MINIMIZE": {
        "base": "Riduce al minimo le dimensioni sharply raise evasiveness.",
        "adattate": {
            "Riduce al minimo le dimensioni raise evasiveness.":
                "Il corpo di chi la usa si comprime e diventa più piccolo. La sua capacità di elusione aumenta.",
        },
    },
    "MOVE_POISON_GAS": {
        "base": "Envelops the foes in a toxic gas that may poison.",
        "adattate": {
            "Envelops the foe in a toxic gas that may poison.":
                "Spruzza in faccia al nemico una nuvola di gas tossico che avvelena.",
        },
    },
    "MOVE_CONVERSION": {
        "base": "Cambia il tipo di chi la usa into first known move's type.",
        "adattate": {
            "Cambia il tipo di chi la usa into a known move's type.":
                "Il tipo di chi la usa muta in quello di una delle sue mosse.",
        },
    },
    "MOVE_TRI_ATTACK": {
        "base": "Spara tre tipi di raggi. May burn/paralyze/freeze.",
        "adattate": {
            "Spara tre tipi di raggi. May burn/para/frostbite.":
                "Colpisce il bersaglio con tre raggi di luce che possono paralizzarlo, scottarlo o assiderarlo.",
        },
    },
    "MOVE_COTTON_SPORE": {
        "base": "Spores cling to the foes, sharply reducing Speed.",
        "adattate": {
            "Spores cling to the foe, sharply reducing Speed.":
                "Rilascia spore simili al cotone che si attaccano al nemico e ne riducono di molto la Velocità.",
        },
    },
    "MOVE_SPITE": {
        "base": "Riduce i PP del nemico per ripicca. of the foe's last move by 4.",
        "adattate": {
            "Riduce i PP del nemico per ripicca. of foe's last move by 2-5.":
                "Chi la usa sfoga la propria rabbia sull'ultima mossa usata dal bersaglio e le sottrae da 2 a 5 PP.",
        },
    },
    "MOVE_POWDER_SNOW": {
        "base": "Colpisce i nemici con una neve gust. May cause freezing.",
        "adattate": {
            "Colpisce i nemici con una neve gust. May cause frostbite.":
                "Attacca i nemici che ha intorno con una raffica di neve farinosa e può anche assiderarli.",
        },
    },
    "MOVE_RAPID_SPIN": {
        "base": "Chi la usa ruota e rimuove alcune effects, while upping speed.",
        "adattate": {
            "Chi la usa ruota e rimuove alcune effects.":
                "Attacco rotante che elimina gli effetti di mosse come Legatutto, Avvolgibotta e Parassiseme.",
        },
    },
    "MOVE_SWEET_SCENT": {
        "base": "Allures the foes to harshly reduce evasiveness.",
        "adattate": {
            "Allures the foes to reduce evasiveness.":
                "Un dolce profumo che riduce l'elusione dei nemici intorno a chi la usa.",
        },
    },
    "MOVE_HIDDEN_POWER": {
        "base": "The type varies with the user.",
        "adattate": {
            "The type and effectiveness vary with the user.":
                "Mossa singolare che cambia tipo e potenza a seconda del Pokémon che la usa.",
        },
    },
    "MOVE_CRUNCH": {
        "base": "Morde con zanne affilate. May lower Defense.",
        "adattate": {
            "Morde con zanne affilate. May lower Sp. Def.":
                "Il bersaglio viene morso con denti affilati. Può anche ridurne la Difesa Speciale.",
        },
    },
    "MOVE_UPROAR": {
        "base": "Causes an uproar for 3 turns and prevents sleep.",
        "adattate": {
            "Causes an uproar for 2 to 5 turns and prevents sleep.":
                "Chi la usa attacca per 2-5 turni con un frastuono che non fa dormire nessuno.",
        },
    },
    "MOVE_TAIL_GLOW": {
        "base": "Flashes a light that sharply raises Sp. Atk.",
        "adattate": {
            "Flash light that drastically raises Sp. Atk.":
                "Chi la usa fissa una luce forte per concentrarsi e aumentare molto l'Attacco Speciale.",
        },
    },
    "MOVE_TAILWIND": {
        "base": "Solleva una brezza, raddoppiando ally Speed for 4 turns.",
        "adattate": {
            "Solleva una brezza, raddoppiando ally Speed for 3 turns.":
                "Chi la usa scatena un turbine che aumenta la Velocità di tutti i Pokémon della squadra per tre turni.",
        },
    },
    "MOVE_ICE_FANG": {
        "base": "Può causare tentennamento o leave the foe frozen.",
        "adattate": {
            "Può causare tentennamento o leave the foe with frostbite.":
                "Chi la usa morde con denti ghiacciati. Può anche assiderare o far tentennare il bersaglio.",
        },
    },
    "MOVE_FREEZE_DRY": {
        "base": "Superefficace sull'Acqua- types. May cause freezing.",
        "adattate": {
            "Superefficace sull'Acqua- types. May cause frostbite.":
                "Chi la usa raffredda istantaneamente il bersaglio e può assiderarlo. Risulta superefficace contro i Pokémon di tipo Acqua.",
        },
    },
    "MOVE_BOUNCY_BUBBLE": {
        "base": "Attacco che assorbe half the damage inflicted.",
        "adattate": {
            "Attacco che assorbe all the damage inflicted.":
                "Chi la usa colpisce il bersaglio con una raffica di bolle e ne assorbe l'acqua, recuperando PS pari a tutto il danno inferto.",
        },
    },
    "MOVE_FREEZING_GLARE": {
        "base": "Scaglia energia psichica the eyes. May freeze the foe.",
        "adattate": {
            "Scaglia energia psichica the eyes. May frostbite.":
                "Il Pokémon attacca rilasciando energia psichica dagli occhi. Può assiderare il bersaglio.",
        },
    },
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
            req = Request(url, headers={"User-Agent": "hns-it-moves/1.0"})
            with urlopen(req, timeout=30) as fh:
                data = json.loads(fh.read().decode("utf-8"))
            cache.parent.mkdir(parents=True, exist_ok=True)
            cache.write_text(json.dumps(data, ensure_ascii=False), encoding="utf-8")
            return data
        except (HTTPError, URLError, TimeoutError) as exc:
            last = exc
            time.sleep(1.5 * (attempt + 1))
    raise RuntimeError(f"PokeAPI non raggiungibile: {url}: {last}")


def move_slug(const: str) -> str:
    """MOVE_FREEZE_DRY -> freeze-dry (il nome PokeAPI della mossa)."""
    return const[len("MOVE_"):].lower().replace("_", "-")


def key_name(text: str) -> str:
    """Nome confrontabile: `SGUARDO GELIDO` == `Sguardo Gelido` == sguardo-gelido."""
    text = text.lower().replace("é", "e").replace("É", "e")
    return re.sub(r"[^a-z0-9]+", "", text)


def fetch_moves(slugs: list[str], workers: int = 8) -> None:
    """Scarica (o legge dalla cache) le schede delle mosse richieste."""

    def one(slug: str) -> None:
        _get(f"{API}/move/{slug}/", MOVE_CACHE / f"{slug}.json")

    with ThreadPoolExecutor(max_workers=workers) as pool:
        list(pool.map(one, slugs))


def cached_move(slug: str) -> dict | None:
    path = MOVE_CACHE / f"{slug}.json"
    if not path.exists():
        return None
    return json.loads(path.read_text(encoding="utf-8"))


def italian_entries(sheet: dict) -> list[tuple[str, str]]:
    """(gruppo di versioni, testo) delle voci italiane, dalla piu' recente.

    Le voci "questa mossa non si puo' usare" si scartano: sono dei giochi
    recenti, non descrivono la mossa.
    """
    found: dict[str, str] = {}
    for entry in sheet.get("flavor_text_entries", []):
        if entry.get("language", {}).get("name") != "it":
            continue
        text = clean(entry.get("flavor_text", ""))
        if not text or any(bad in text.lower() for bad in UNUSABLE):
            continue
        group = entry.get("version_group", {}).get("name", "?")
        found.setdefault(group, text)
    out = [(g, found[g]) for g in VERSION_GROUPS if g in found]
    out += [(g, t) for g, t in found.items() if g not in VERSION_GROUPS]
    return out


def has_italian(sheet: dict) -> bool:
    return bool(italian_entries(sheet))


# ---------------------------------------------------------------------------
# lettura dei blocchi `.description = COMPOUND_STRING(...)`
# ---------------------------------------------------------------------------

OPEN_DESC_PLAIN = re.compile(r"^(\s*)\.description = COMPOUND_STRING\($")
OPEN_DESC_ONE = re.compile(r'^(\s*)\.description = COMPOUND_STRING\("(.*)"\),?$')
OPEN_STATIC_PLAIN = re.compile(r"^static const u8 (\w+)\[\] = _\($")
OPEN_STATIC_ONE = re.compile(r'^static const u8 (\w+)\[\] = _\("(.*)"\);$')
LIT_RE = re.compile(r'^(\s*)"((?:[^"\\]|\\.)*)"(\),?|\);)?\s*$')
DIR_RE = re.compile(r"^(\s*)#\s*(if|ifdef|ifndef|elif|else|endif)\b(.*)$")
MOVE_RE = re.compile(r"^\s*\[(MOVE_[A-Z0-9_]+)\]\s*=")
NAME_RE = re.compile(r'^\s*\.name = COMPOUND_STRING\("(.*)"\),')


def unescape(lit: str) -> str:
    """Dal letterale C al testo vero (`\\n` -> a capo, `\\"` -> virgoletta)."""
    out: list[str] = []
    k = 0
    while k < len(lit):
        ch = lit[k]
        if ch == "\\" and k + 1 < len(lit):
            out.append({"n": "\n", "l": "\n", '"': '"', "\\": "\\", "'": "'"}.get(lit[k + 1], lit[k + 1]))
            k += 2
            continue
        out.append(ch)
        k += 1
    return "".join(out)


def escape(text: str) -> str:
    return text.replace("\\", "\\\\").replace('"', '\\"')


def parse_tree(lines: list[str], i: int) -> tuple[list[dict], int]:
    """Legge una sequenza di item del blocco a partire dalla riga `i`.

    Item: `{"lit": testo, "ind": indentazione, "end": "),"/");"}` oppure
    `{"cond": [(riga_direttiva, [item...]), ...], "end": riga_endif}`.
    Si ferma alla riga che chiude la stringa o a un `#else/#elif/#endif`.
    """
    items: list[dict] = []
    while i < len(lines):
        line = lines[i]
        dm = DIR_RE.match(line)
        if dm:
            word = dm.group(2)
            if word in ("if", "ifdef", "ifndef"):
                branches: list[tuple[str, list[dict]]] = []
                body, i = parse_tree(lines, i + 1)
                branches.append((line, body))
                end = None
                while i < len(lines):
                    dm2 = DIR_RE.match(lines[i])
                    if not dm2:
                        break
                    word2 = dm2.group(2)
                    if word2 in ("elif", "else"):
                        dirline = lines[i]
                        body, i = parse_tree(lines, i + 1)
                        branches.append((dirline, body))
                        continue
                    if word2 == "endif":
                        end = lines[i]
                        i += 1
                    break
                items.append({"cond": branches, "end": end})
                continue
            return items, i  # elif/else/endif: fine del ramo
        lm = LIT_RE.match(line)
        if lm:
            items.append({"lit": unescape(lm.group(2)), "ind": lm.group(1), "end": lm.group(3) or ""})
            if lm.group(3):
                return items, i + 1
            i += 1
            continue
        return items, i  # riga che non e' testo: il blocco e' finito
    return items, i


@dataclass
class Block:
    path: Path
    start: int  # indice (0-based) della riga `.description = COMPOUND_STRING(`
    end: int  # indice (0-based) dell'ultima riga del blocco
    open_line: str = ""  # la riga di apertura, com'e' scritta nel file
    move: str | None = None  # costante `[MOVE_XXX] =` che lo contiene
    static: str | None = None  # nome della descrizione condivisa `sXxxDescription`
    name: str | None = None  # `.name = COMPOUND_STRING("...")` della mossa
    name_ok: bool = False  # il `.name` appartiene davvero a questo blocco
    items: list[dict] = field(default_factory=list)

    @property
    def key(self) -> str:
        return self.static or self.move or "?"

    @property
    def single_line(self) -> bool:
        """Descrizione scritta su una riga sola: `COMPOUND_STRING("testo")`."""
        return self.start == self.end

    def paths(self) -> list[str]:
        """Testo completo di ogni variante (un ramo di compilazione = un testo)."""
        return paths_of(self.items)

    def plain_paths(self) -> list[str]:
        """Come `paths`, con a capo e spazi ridotti a uno spazio (per le chiavi)."""
        return [re.sub(r"\s+", " ", p.replace("\n", " ")).strip() for p in self.paths()]

    def branches(self) -> list[tuple[str, list[dict]]] | None:
        conds = [it for it in self.items if "cond" in it]
        if len(conds) != 1:
            return None  # piu' di un condizionale: struttura non gestita
        return conds[0]["cond"]

    def endif(self) -> str | None:
        conds = [it for it in self.items if "cond" in it]
        return conds[0]["end"] if len(conds) == 1 else None

    def indent(self) -> str:
        """Indentazione delle righe di testo del blocco."""
        for it in self.items:
            if "lit" in it and it.get("ind"):
                return it["ind"]
            for _, body in it.get("cond", []):
                for sub in body:
                    if "lit" in sub and sub.get("ind"):
                        return sub["ind"]
        return " " * 12


def paths_of(items: list[dict]) -> list[str]:
    out = [""]
    for it in items:
        if "lit" in it:
            out = [t + it["lit"] for t in out]
        else:
            new: list[str] = []
            for _, body in it["cond"]:
                new.extend(t + b for t in out for b in paths_of(body))
            out = new
    return out


def load_blocks(path: Path = MOVES_FILE) -> tuple[list[Block], list[str]]:
    """Tutti i blocchi di descrizione, con la mossa o la costante di appartenenza."""
    lines = path.read_text(encoding="utf-8").splitlines()
    blocks: list[Block] = []
    i = 0
    move: str | None = None
    name: str | None = None
    move_at = name_at = -1
    while i < len(lines):
        mm = MOVE_RE.match(lines[i])
        if mm:
            move, move_at = mm.group(1), i
        nm = NAME_RE.match(lines[i])
        if nm:
            name, name_at = nm.group(1), i
        plain = OPEN_DESC_PLAIN.match(lines[i]) or OPEN_STATIC_PLAIN.match(lines[i])
        one = OPEN_DESC_ONE.match(lines[i]) or OPEN_STATIC_ONE.match(lines[i])
        if plain:
            sm = OPEN_STATIC_PLAIN.match(lines[i])
            items, j = parse_tree(lines, i + 1)
            blocks.append(Block(
                path=path, start=i, end=j - 1, open_line=lines[i],
                move=move, static=sm.group(1) if sm else None,
                name=name, name_ok=name_at > move_at >= 0,
                items=items))
            i = j
            continue
        if one:
            blocks.append(Block(
                path=path, start=i, end=i, open_line=lines[i],
                move=move,
                static=OPEN_STATIC_ONE.match(lines[i]) and OPEN_STATIC_ONE.match(lines[i]).group(1),
                name=name, name_ok=name_at > move_at >= 0,
                items=[{"lit": one.group(2), "ind": "", "end": "),"}]))
            i += 1
            continue
        i += 1
    return blocks, lines


def needs_fix(block: Block) -> list[str]:
    """Parole inglesi trovate nelle varianti: vuoto se il blocco e' italiano."""
    words = set(re.findall(r"[A-Za-zÀ-ÿ']+", " ".join(block.paths()).lower()))
    return sorted(words & EN_MARK)


# ---------------------------------------------------------------------------
# testo ufficiale, adattamenti e caratteri
# ---------------------------------------------------------------------------


def wrap_key(text: str) -> str:
    """Chiave di confronto per le varianti: righe unite, spazi normalizzati."""
    return re.sub(r"\s+", " ", text.replace("\n", " ")).strip()


def clean(text: str) -> str:
    """Toglie `\\n`/`\\f`, normalizza spazi, apostrofi e nome della specie."""
    for bad, good in SUBSTITUTIONS.items():
        text = text.replace(bad, good)
    text = text.replace("\f", " ").replace("\n", " ").replace("\r", " ")
    for pat, good in NAME_FIXES:
        text = pat.sub(good, text)
    text = re.sub(r"\s+", " ", text)
    # trattino che spezza una parola a fine riga nella voce di PokeAPI
    text = re.sub(r"(\w)-\s+(\w)", r"\1\2", text)
    return text.strip()


# ---------------------------------------------------------------------------
# impaginazione
# ---------------------------------------------------------------------------


def split_cost(ws: list[int], sp: int, limit: int, n_lines: int) -> list[int] | None:
    """Divide le parole in `n_lines` righe entro `limit` px, il piu' uniformi
    possibile (peso triplo sull'ultima riga, per non lasciare una parola orfana)."""
    n = len(ws)
    if n_lines < 1 or n_lines > n:
        return None
    prefix = [0] * (n + 1)
    for i, w in enumerate(ws):
        prefix[i + 1] = prefix[i] + w + sp

    def width(i: int, j: int) -> int:
        return prefix[j] - prefix[i] - sp

    INF = float("inf")
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
    """Righe entro `limit` px, al massimo MAX_LINES. None se non entra."""
    words = [w for w in text.split(" ") if w]
    if not words:
        return None
    ws = [metrics.line_width(w)[0] for w in words]
    sp = metrics.line_width(" ")[0]
    if any(w > limit for w in ws):
        return None
    for n_lines in range(1, MAX_LINES + 1):
        groups = split_cost(ws, sp, limit, n_lines)
        if groups is None:
            continue
        out: list[str] = []
        i = 0
        for g in groups:
            out.append(" ".join(words[i:i + g]))
            i += g
        return out
    return None


SENT_RE = re.compile(r"(?<=[.!?])\s+")


def sentences(text: str) -> list[str]:
    return [s for s in SENT_RE.split(text) if s]


def varianti(text: str):
    """Versioni via via piu' corte del testo ufficiale, dalla piu' fedele."""
    stripped = re.sub(r"\s*\([^)]*\)", "", text)
    stripped = re.sub(r"\s+", " ", stripped).strip()
    if stripped != text:
        yield "senza parentesi", stripped
    frasi = sentences(text)
    for m in range(len(frasi) - 1, 0, -1):
        cand = " ".join(frasi[:m]).strip()
        if cand and cand != text:
            yield f"{m} frasi", cand
    frasi0 = frasi[0] if frasi else text
    for sep in (", ", " "):
        parts = frasi0.split(sep)
        for m in range(len(parts) - 1, 0, -1):
            cand = sep.join(parts[:m]).rstrip(" ,;:")
            if len(cand.split()) < 3:
                break
            yield f"prima frase ridotta ({m} parti)", cand + "."


def layout(text: str, metrics) -> tuple[list[str] | None, str]:
    """Righe finali per `text` e nota sull'eventuale accorciamento."""
    if not text:
        return [], ""
    righe = wrap(text, metrics)
    if righe is not None:
        return righe, ""
    for nome, cand in varianti(text):
        r = wrap(cand, metrics)
        if r is not None:
            return r, "accorciata: " + nome
    return None, ""


def check_chars(text: str, metrics) -> tuple[str, list[str]]:
    """Sostituisce i caratteri fuori charmap; ritorna (testo, residui)."""
    if all(ch in metrics.charmap for ch in text):
        return text, []
    text = "".join(SUBSTITUTIONS.get(ch, ch) for ch in text)
    text = re.sub(r"\s+", " ", text).strip()
    return text, sorted({ch for ch in text if ch not in metrics.charmap})


# ---------------------------------------------------------------------------
# lavoro sui blocchi
# ---------------------------------------------------------------------------


@dataclass
class Esito:
    key: str
    stato: str  # sostituito | gia_it | inglese | errore
    motivo: str = ""
    versioni: list[str] = field(default_factory=list)
    righe: list[list[str]] = field(default_factory=list)  # una lista per variante
    note: list[str] = field(default_factory=list)
    blk: Block | None = None
    prima: str = ""  # en / mix : com'era il testo prima


def testi_varianti(block: Block, sheet: dict, metrics) -> tuple[list[str] | None, list[str], str]:
    """Testi italiani delle varianti, nell'ordine dei rami. Ritorna (testi,
    versioni usate, motivo se non si puo' fare)."""
    paths = block.plain_paths()
    ita = italian_entries(sheet)
    if not ita:
        return None, [], "PokeAPI senza testo italiano"
    gruppo, ufficiale = ita[0]
    if len(paths) == 1 and not block.static:
        return [ufficiale], [gruppo], ""
    # varianti: il testo ufficiale descrive la meccanica moderna, le altre
    # varianti prendono la frase ufficiale adattata al caso (tabella ADATTATE)
    regole = ADATTATE.get(block.key)
    if not regole:
        return None, [gruppo], "varianti senza testo dedicato (aggiungi ADATTATE)"
    key_base = wrap_key(regole.get("base", ""))
    adattate = {wrap_key(k): v for k, v in regole.get("adattate", {}).items()}
    out: list[str] = []
    for p in paths:
        if wrap_key(p) == key_base:
            out.append(clean(ufficiale))
        elif wrap_key(p) in adattate:
            out.append(clean(adattate[wrap_key(p)]))
        else:
            return None, [gruppo], f"variante non mappata in ADATTATE: {p!r}"
    return out, [gruppo], ""


def process(blocks: list[Block], metrics, only: str | None = None) -> list[Esito]:
    esiti: list[Esito] = []
    for blk in blocks:
        if only and blk.key != only and blk.move != only:
            continue
        parole = needs_fix(blk)
        if not parole:
            esiti.append(Esito(blk.key, "gia_it", "testo italiano", blk=blk))
            continue
        # mista = almeno un pezzo del testo e' gia' italiano; del tutto inglese
        # = nessun marcatore italiano in nessuna variante
        IT_MARK = re.compile(r"\b(?:il|lo|la|le|di|che|con|per|nemico|bersaglio|mossa|chi|usa|"
                             r"può|al|del|della|una|un|non|danno|attacco|turni)\b", re.I)
        prima = "mix" if any(IT_MARK.search(p) for p in blk.paths()) else "en"
        if blk.branches() is None and any("cond" in it for it in blk.items):
            esiti.append(Esito(blk.key, "inglese", "struttura con piu' condizionali: non gestita", blk=blk))
            continue
        if blk.move is None and blk.static is None:
            esiti.append(Esito(blk.key, "inglese", "blocco senza mossa", blk=blk))
            continue
        slug = move_slug(blk.move) if blk.move else ""
        sheet = cached_move(slug) if slug else None
        if blk.move and sheet is None:
            esiti.append(Esito(blk.key, "inglese", f"mossa assente in PokeAPI ({slug})", blk=blk))
            continue
        if sheet is not None and blk.name and blk.name_ok:
            ufficiali = {key_name(n["name"]) for n in sheet.get("names", [])}
            if key_name(blk.name) not in ufficiali:
                esiti.append(Esito(blk.key, "inglese",
                                   f"nome non coerente ({blk.name} vs {slug})", blk=blk))
                continue
        testi, versioni, motivo = testi_varianti(blk, sheet or {}, metrics)
        if testi is None:
            esiti.append(Esito(blk.key, "inglese", motivo, versioni, blk=blk))
            continue
        righe: list[list[str]] = []
        note: list[str] = []
        rotto = ""
        for testo in testi:
            testo, residui = check_chars(testo, metrics)
            if residui:
                rotto = "caratteri non rappresentabili: " + " ".join(residui)
                break
            r, nota = layout(testo, metrics)
            if r is None:
                rotto = "non entra in 4 righe (<216 px) nemmeno accorciata"
                break
            righe.append(r)
            note.append(nota)
        if rotto:
            esiti.append(Esito(blk.key, "inglese", rotto, versioni, blk=blk))
            continue
        esiti.append(Esito(blk.key, "sostituito", "", versioni, righe, note, blk, prima))
    return esiti


def render(block: Block, righe: list[list[str]]) -> list[str]:
    """Righe nuove del blocco: direttive intatte, testo italiano dentro i rami."""
    if block.single_line:
        # `COMPOUND_STRING("testo")`: si sostituisce solo il testo, in riga
        m = re.match(r'^(\s*.*\([\s]*)"(.*)("(?:\),?|\);)?)$', block.open_line)
        if m is None:
            raise ValueError(f"riga non riconosciuta: {block.open_line!r}")
        return [f'{m.group(1)}"{escape(" ".join(righe[0]))}"{m.group(3)}']
    branches = block.branches()
    if branches is None:
        if len(righe) != 1:
            raise ValueError("blocco senza condizionali ma con piu' varianti")
        indent = block.indent()
        out = [block.open_line.rstrip()]
        for k, line in enumerate(righe[0]):
            tail = '\\n"' if k < len(righe[0]) - 1 else '"),'
            out.append(f'{indent}"{escape(line)}{tail}')
        return out
    out = [block.open_line.rstrip()]
    for n, (dirline, body) in enumerate(branches):
        out.append(dirline.rstrip())
        indent = block.indent()
        for sub in body:
            if "lit" in sub and sub.get("ind"):
                indent = sub["ind"]
                break
        for k, line in enumerate(righe[n]):
            tail = '\\n"' if k < len(righe[n]) - 1 else '"),'
            out.append(f'{indent}"{escape(line)}{tail}')
    end = block.endif()
    if end is not None:
        out.append(end.rstrip())
    return out


def applica(esiti: list[Esito]) -> int:
    fatti = [e for e in esiti if e.stato == "sostituito" and e.blk is not None]
    if not fatti:
        return 0
    path = fatti[0].blk.path  # type: ignore[union-attr]
    righe = path.read_text(encoding="utf-8").splitlines()
    scritti = 0
    for esito in sorted(fatti, key=lambda e: e.blk.start, reverse=True):  # type: ignore[union-attr]
        blk = esito.blk
        assert blk is not None
        righe[blk.start:blk.end + 1] = render(blk, esito.righe)
        scritti += 1
    path.write_text("\n".join(righe) + "\n", encoding="utf-8")
    return scritti


# ---------------------------------------------------------------------------
# main
# ---------------------------------------------------------------------------


def main() -> int:
    ap = argparse.ArgumentParser(prog="move_descriptions_it")
    ap.add_argument("--apply", action="store_true", help="scrive i file (default: anteprima)")
    ap.add_argument("--only", help="una sola voce (MOVE_XXX o sXxxDescription)")
    ap.add_argument("--samples", type=int, default=8, help="esempi da stampare")
    ap.add_argument("--fetch", action="store_true", help="scarica solo la cache PokeAPI")
    ap.add_argument("--list-keys", action="store_true", help="chiavi ADATTATE mancanti o da aggiornare")
    args = ap.parse_args()

    blocks, lines = load_blocks()
    print(f"blocchi .description: {len(blocks)}")
    da_fare = [b for b in blocks if needs_fix(b)]
    print(f"con parole inglesi  : {len(da_fare)}"
          f"  (di cui con varianti #if: {sum(1 for b in da_fare if len(b.paths()) > 1)})")

    if args.list_keys:
        for blk in da_fare:
            print(f"\n{blk.key}  ({len(blk.paths())} varianti)")
            for p in blk.plain_paths():
                print(f"   {p!r},")
        return 0

    slugs = sorted({move_slug(b.move) for b in da_fare if b.move})
    try:
        fetch_moves(slugs)
    except RuntimeError as exc:
        print(f"cache incompleta: {exc}")
    if args.fetch:
        print(f"cache PokeAPI: {len(slugs)} mosse in {MOVE_CACHE}")
        return 0

    metrics = batching.load_metrics()
    esiti = process(blocks, metrics, args.only)

    conta: dict[str, int] = {}
    for e in esiti:
        conta[e.stato] = conta.get(e.stato, 0) + 1
    fuori = [e for e in esiti if e.righe and any(
        metrics.line_width(r)[0] > LIMIT_PX for righe in e.righe for r in righe)]
    troppe = [e for e in esiti if any(len(r) > MAX_LINES for r in e.righe)]
    acc = [e for e in esiti if any(n.startswith("accorciata") for n in e.note)]
    miste = [e for e in esiti if e.stato == "sostituito" and e.prima == "mix"]

    print(f"\n  sostituiti           : {conta.get('sostituito', 0)}"
          f"  (di cui miste IT/EN: {len(miste)}  tutte in inglese: {conta.get('sostituito', 0) - len(miste)})")
    print(f"  gia' in italiano     : {conta.get('gia_it', 0)}")
    print(f"  lasciati in inglese  : {conta.get('inglese', 0)}")
    print(f"  righe oltre {LIMIT_PX}px : {len(fuori)}    blocchi con piu' di {MAX_LINES} righe: {len(troppe)}")
    print(f"  accorciati           : {len(acc)}")
    for e in [x for x in esiti if x.stato == "inglese"]:
        print(f"    inglese  {e.key:<24} {e.motivo}")
    for e in [x for x in esiti if x.stato == "sostituito"][:args.samples]:
        print(f"\n  {e.key}  [da {e.versioni[0] if e.versioni else '?'}]")
        for k, righe in enumerate(e.righe):
            for r in righe:
                print(f"    {k} {metrics.line_width(r)[0]:>3}px  {r}")
    for e in acc:
        print(f"    nota {e.key:<24} {[n for n in e.note if n]}")

    if args.apply:
        n = applica(esiti)
        REPORT.write_text(json.dumps({
            "sostituiti": [{"mossa": e.key, "versioni": e.versioni,
                            "note": [x for x in e.note if x],
                            "righe": e.righe} for e in esiti if e.stato == "sostituito"],
            "lasciati": [{"mossa": e.key, "motivo": e.motivo}
                         for e in esiti if e.stato != "sostituito" and e.stato != "gia_it"],
        }, ensure_ascii=False, indent=1), encoding="utf-8")
        print(f"\nblocchi riscritti: {n}   report: {REPORT}")
        # rilegge il file scritto: e' l'arbitro di formato e di lingua
        scritti, _ = load_blocks()
        nuovo = [b for b in scritti if needs_fix(b)]
        larghe = [(b.key, p, metrics.line_width(r)[0])
                  for b in scritti for p in b.paths() for r in p.split("\n")
                  if metrics.line_width(r)[0] > LIMIT_PX]
        lunghe = [b.key for b in scritti if any(len(p.split("\n")) > MAX_LINES for p in b.paths())]
        print(f"  dopo la scrittura: blocchi totali {len(scritti)}, ancora in inglese {len(nuovo)}, "
              f"righe oltre {LIMIT_PX}px {len(larghe)}, blocchi oltre {MAX_LINES} righe {len(lunghe)}")
        for chiave, p, w in larghe[:10]:
            print(f"    {w}px  {chiave}  {p!r}")
        for chiave in lunghe[:10]:
            print(f"    troppe righe  {chiave}")
        if nuovo:
            for b in nuovo:
                print(f"    rimasto in inglese: {b.key}  {needs_fix(b)}")
    else:
        print("\nanteprima (nessuna scrittura): usa --apply per scrivere")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
