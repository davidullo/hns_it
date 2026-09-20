# Obiettivo: traduzione italiana completa di Pokémon Heart and Soul 2.0

Questo file e' il contratto del progetto. Ogni ciclo di lavoro autonomo legge
questo file e porta avanti il primo punto non concluso.

## Definizione di fatto

La traduzione e' finita quando **tutte** queste condizioni sono vere:

1. `python3 -m hnsit stats` non ha unita' `pending`.
2. `python3 -m hnsit verify units` esce 0 (nessun problema duro).
3. `python3 -m hnsit verify repo` esce 0 dopo `hnsit.py inject`.
4. `make hns` produce `pokehns.gba` senza errori.
5. `python3 -m pytest it/tests -q` passa (col venv `it/.venv`).
6. Parity con `helikoptermann843/hns_de`: le stesse superfici coperte
   (testi `.inc`, stringhe C, easy chat, grafica con testo dentro, nome delle
   schermate), niente testi inglesi residui a parte i nomi propri.
7. `make release` + patch `.ups` generata e provata su ROM pulita.

## Stato (aggiornare a ogni ciclo)

- Unita' totali: 37.473 (17.473 blocchi `.inc` + 20.000 stringhe C).
- Riempite dal glossario ufficiale PokeAPI senza LLM: ~4.180.
- Da tradurre con LLM: ~27.400 gruppi unici (il resto e' translation memory).
- Baseline build: OK, `pokehns.gba` sha1 `2fc84dcb426683a1bb0c5245b85538f7ccff8c46`.
  Attenzione: ROM al 94,44% e EWRAM al 94,64%, il margine e' poco.

## Prossimo passo

Tradurre i gruppi `pending` con `it/hnsit/translate.py`, poi verificare,
iniettare, compilare.

## Regole non negoziabili

- La traduzione vive solo in `it/data/units_*.jsonl`: i sorgenti si generano.
- Un testo inglese non si sovrascrive a caso: `inject` controlla lo sha1 e
  si ferma su DRIFT.
- Non si tocca `GAME_LANGUAGE` in `include/constants/global.h`.
- Mai tradurre `data/text/braille.inc`.
- Struttura dei separatori (`\n`, `\p`, `\l`, `$`) e codici `{...}`: identici.
- Niente trattino lungo (—) nei testi.
- Non si toccano gli indici easy chat, si ricalcola solo `alphabeticalOrder`.
