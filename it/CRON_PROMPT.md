# Istruzioni del giro automatico di traduzione

Sei l'orchestratore della traduzione italiana di Pokémon Heart and Soul 2.0
(repo `/Users/crosta/Developer/hns_it`, fork di Davide). Esegui questo giro
**una volta**, senza chiedere niente a nessuno.

La tua finestra di contesto è piccola: non leggere log lunghi. Per i controlli
pesanti (build completa, verify su tutto il repo, confronto con il tedesco in
`/Users/crosta/Developer/hns_de`) usa `delegate_task` con un subagent che ti
riporti un riassunto breve. Tu lanci i comandi e leggi le ultime 5 righe.

## 1. Traduzione (budget ~18 minuti)

```
cd /Users/crosta/Developer/hns_it && source ~/.hermes/scripts/hns_env.sh && cd it
timeout 1500 python3 -m hnsit translate --kind inc --size 40 --workers 16 --rounds 20
timeout 1500 python3 -m hnsit translate --kind cstr --size 40 --workers 16 --rounds 20
```

Se stampa `SKIPPED_LOCKED` va bene (un altro giro è già in corso): passa al 2.

## 2. Consolidamento (sempre, in quest'ordine)

```
python3 -m hnsit autofill
python3 -m hnsit repair --apply
python3 -m hnsit verify units      # deve dire: duri: 0
python3 -m hnsit inject
python3 -m hnsit verify repo
python3 -m hnsit verify limits     # deve dire: oltre il limite: 0
```

## 3. Commit

Solo se `verify units`, `verify repo` e `verify limits` escono senza problemi
duri:

```
source ~/.hermes/scripts/hns_env.sh
cd /Users/crosta/Developer/hns_it && git add -A it src include data \
  && git commit -q -m "Traduzione italiana: lotto automatico" && git push origin master
```

(il `source` serve per il token di GitHub: senza, il push chiede la password e
fallisce)

Se ci sono problemi duri NON committare: riportali in 5 righe e fermati dopo
aver lanciato `python3 -m hnsit repair --apply`.

## 4. Build

Solo se `pending` è 0, oppure se hai committato più di 500 unità nuove in questo
giro. Usa il lock `/tmp/hns_build.lock` per non litigare con il job revisore:
se il file esiste salta la build e scrivi `SKIP_BUILD`, altrimenti crea il file,
lancia `timeout 1200 make hns -j8` (output in `/tmp/hns_cron_build.log`),
poi cancella il lock e mostra le ultime 3 righe del log.

### 4b. Se la build è fallita con `excess elements in array initializer`

o `initializer-string for array ... is too long`:

```
cd it && python3 -m hnsit learn --log /tmp/hns_cron_build.log --apply \
  && python3 -m hnsit repair --apply && python3 -m hnsit verify units
```

`learn` legge il log, capisce quale campo è troppo stretto, impara il limite e
rimette in coda le unità colpevoli. **Non correggere a mano i sorgenti del gioco.**

## 5. Report

Su Telegram, massimo 6 righe, italiano colloquiale: unità fatte/totali,
problemi duri, commit sì/no, build ok / ko / fallita-ma-limite-imparato.

Se non hai fatto progressi e non c'è niente da segnalare rispondi esattamente
`[SILENT]`.

## Regole inviolabili

- Non toccare la game language.
- Non toccare `data/text/braille.inc`.
- Non modificare i codici `{...}` dentro i testi.
- Non modificare i test in `it/tests` per farli passare: se un test fallisce, il
  problema è nei dati.
- Non modificare `src/` o `include/` a mano per far compilare.
