# it/ — localizzazione italiana di Pokémon Heart and Soul 2.0

Pipeline di traduzione **deterministica**: i testi tradotti vivono in file dati
(`it/data/units_*.jsonl`), i sorgenti del gioco si generano da quei file. Niente
testi modificati a mano nel codice.

## Come e' fatto

```
it/
├── hnsit/                  libreria
│   ├── textparse.py        parser dei testi (.inc), charmap, larghezze, Unit
│   ├── cstr.py             scanner delle macro di testo C (_(), COMPOUND_STRING)
│   ├── extract.py          inventario
│   ├── inject.py           scrittura nei sorgenti con controllo di deriva
│   └── store.py            lettura/scrittura dei JSONL
├── tools/
│   ├── hnsit.py            CLI: extract | stats | inject
│   ├── build_glossary.py   glossario ufficiale dai dump PokeAPI
│   ├── autofill.py         riempie senza LLM (glossario + testi ufficiali)
│   ├── batch.py            plan | apply | status | pending
│   ├── translate_run.py    runner: lotti -> modelli economici -> applica
│   ├── verify.py           units | repo | report  (l'arbitro)
│   └── repair.py           riporta a pending le unita' che non passano
├── data/
│   ├── units_inc.jsonl     blocchi .inc  (chiave, segmenti EN, traduzione IT)
│   ├── units_cstr.jsonl    stringhe C
│   ├── glossary.csv        nomi ufficiali EN -> IT (PokeAPI)
│   ├── glossary_manual.csv termini scelti a mano (HnS non esiste ufficialmente)
│   ├── prose.jsonl         descrizioni ufficiali EN -> IT
│   └── inventory.json      conteggi, per accorgersi dei merge da upstream
├── tests/                  pytest
├── work/                   lotti, risultati, log (ignorata da git)
├── PLAN.md                 obiettivo e stato, letto dai cicli autonomi
└── PROMPT_TRANSLATOR.md    regole date ai modelli traduttori
```

## Modello di dati

Ogni unita' ha una chiave stabile e l'hash dell'inglese:

- blocco `.inc`: `inc:<percorso>|<etichetta>`
- stringa C: `cstr:<percorso>#<ordinale della macro nel file>`

Il testo e' diviso in **righe visibili** e **terminatori** (`\n`, `\p`, `\l`,
`$`). Al traduttore si danno solo le righe: i terminatori si riattaccano in
fase di ricostruzione, quindi la struttura non puo' cambiare. I codici `{...}`
restano dentro le righe e vengono verificati come multiset.

Se il testo inglese nel file non corrisponde piu' all'hash registrato,
`inject` si ferma con `DRIFT`: serve a non sovrascrivere in silenzio dopo un
merge da upstream.

## Flusso di lavoro

```bash
# 1. inventario (dopo un merge da upstream)
python3 -m hnsit extract
python3 -m hnsit glossary      # riscarica i dump PokeAPI se mancano
python3 -m hnsit autofill            # riempie nomi e descrizioni ufficiali

# 2. traduzione dei testi originali con modelli economici
python3 -m hnsit translate --kind inc  --size 20 --workers 6 --rounds 20
python3 -m hnsit translate --kind cstr --size 20 --workers 6 --rounds 20

# 3. verifica, iniezione, build
python3 -m hnsit verify units
python3 -m hnsit inject
python3 -m hnsit verify repo
make hns -j$(sysctl -n hw.ncpu)
it/.venv/bin/python -m pytest it/tests -q
```

## Cosa impone il gioco (verificato sul codice)

- Finestra dialogo standard: 27x4 tile = **216x32 px**, due righe da 16 px. Il
  frame e' disegnato fuori dalla finestra, quindi tutti i 216 px sono usabili.
  Limite duro 216 px, target 200. Le larghezze vengono da
  `gFontNormalLatinGlyphWidths` in `src/fonts.c`.
- Righe per pagina: 2 nella finestra standard, ma l'intro con Pikachu ne ha 7 e
  le descrizioni mosse in Battle Frontier Lounge7 ne hanno 3: **mai piu' righe
  dell'inglese** in quel blocco.
- Codici: `\n` nuova riga, `\p` nuova pagina, `\l` scroll, `$` fine stringa. Il
  testo va reincolonnato a mano: non c'e' auto-wrap.
- Placeholder e codici (`{PLAYER}`, `{STR_VAR_1}`, `{PAUSE 96}`, `{COLOR BLUE}`,
  `{A_BUTTON}`, …) restano identici.
- Il charmap ha gia' tutti gli accenti italiani e i segni tipografici: niente
  glifi da disegnare e niente da toccare in `charmap.txt`.
- `GAME_LANGUAGE` in `include/constants/global.h` **non si tocca**: il gioco e'
  single language, si traduce nel sorgente e si builda una ROM italiana.
- Buffer a lunghezza fissa: nome giocatore 7, allenatore 10, Pokémon 12 byte.
- Easy chat: si traduce il campo `text`, si ricalcola `alphabeticalOrder`, gli
  indici `EC_WORD_*` non si toccano.
- `data/text/braille.inc` non si traduce: sono pattern braille veri.

## Costi e token

La maggior parte dei testi sono nomi e descrizioni ufficiali: quelli arrivano
dal glossario PokeAPI senza spendere un token. Per il resto i lotti sono
deduplicati per sha1 (translation memory), i modelli sono economici e girano a
reasoning basso, e ogni lotto e' un processo separato senza contesto ereditato.

## Riferimenti

- `helikoptermann843/hns_de`: fork tedesco completo, il metro di paragone.
- `vaboston/HeartAndSoulFR`: solo patch, modello per la distribuzione.
