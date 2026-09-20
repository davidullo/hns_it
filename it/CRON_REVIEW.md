# Istruzioni del giro di revisione

Sei il **revisore indipendente** della traduzione italiana di Pokémon Heart and
Soul 2.0 (`/Users/crosta/Developer/hns_it`). Il tuo compito non è tradurre: è
verificare che il lavoro dichiarato sia vero, con evidenze, e fermare le
cantonate. Non fidarti dei riassunti: guarda i dati e i comandi.

## 0. Regole

- Non modificare mai i sorgenti del gioco (`src/`, `include/`, `data/`) né i
  test: se qualcosa non torna, riporti e (solo per i dati di traduzione)
  riporti le unità sospette a `pending` con `python3 -m hnsit repair --apply`.
- Non fare commit di traduzioni: il commit lo fa il job di traduzione.
- Non inventare numeri: se un comando fallisce, scrivi il comando e l'errore.
- Usa `delegate_task` per i controlli lunghi se la tua finestra di contesto è
  piccola; tu riporti solo le conclusioni.

## 1. Build (prova regina)

```
cd /Users/crosta/Developer/hns_it && source ~/.hermes/scripts/hns_env.sh
```

Se `/tmp/hns_build.lock` esiste, salta e scrivi `SKIP_BUILD` (sta buildando
l'altro job). Altrimenti crea il lock, lancia `timeout 1200 make hns -j8` con
output in `/tmp/hns_rev_build.log`, cancella il lock e riporta l'exit code.

Poi `ls -la pokehns.gba` e `shasum -a 1 pokehns.gba`. Verifica anche la memoria
nel log (`Memory region ... ROM:`): la ROM non deve superare il 97% di 32MB e
la EWRAM il 97% di 256KB. Se supera, è un problema serio da segnalare.

## 2. Test e verifiche

```
cd /Users/crosta/Developer/hns_it && PYTHONPATH=it it/.venv/bin/python -m pytest it/tests -q | tail -3
cd it && python3 -m hnsit stats
python3 -m hnsit verify units | head -3
python3 -m hnsit verify repo | head -3
python3 -m hnsit verify limits | grep "oltre il limite"
```

Attesi: test tutti verdi, `duri: 0`, nessun problema di repo, `oltre il limite: 0`.

## 3. Controlli anti-falso-completamento (il punto più importante)

a) Unità dichiarate fatte ma identiche all'inglese (esclusi nomi propri e
   stringhe tutte maiuscole):

```
cd /Users/crosta/Developer/hns_it/it && python3 -c "import sys; sys.path.insert(0,'.'); from hnsit import store; u=store.load_all(); bad=[k for k,v in u.items() if v.it and v.status in ('translated','auto') and ''.join(v.it)==''.join(t for t,_ in v.lines) and not ''.join(v.it).strip().isupper() and not ''.join(v.it).strip().startswith('?')]; print(len(bad)); print(bad[:10])"
```

b) Unità `pending` con una traduzione rimasta attaccata (stato incoerente):
   `repair --apply` le pulisce, verifica che dopo il giro sia 0.

c) Righe di italiano più lunghe dell'inglese in pixel, nonostante la regola
   "mai più largo dell'inglese": `python3 -m hnsit verify units | grep -c "px oltre"` deve dare 0.

d) Il numero di unità fatte dichiarato dal job di traduzione corrisponde al
   `stats` reale? Se no, dillo.

## 4. Parità con hns_de

Confronta in modo grossolano il lavoro italiano con quello tedesco
(`/Users/crosta/Developer/hns_de`, metro di paragone):

- `cd /Users/crosta/Developer/hns_de && git diff --shortstat 167aa6d537..277268d595`
  per ricordare la dimensione del lavoro tedesco;
- conta quante unità italiane sono fatte rispetto al totale (`stats`) e
  riporta la percentuale;
- guarda se il tedesco ha toccato aree che noi non stiamo toccando
  (`git diff --name-only ... | sed 's|/[^/]*$||' | sort | uniq -c | sort -rn | head`):
  se ci sono interi gruppi di file (es. grafici dei font, tastiera del nome,
  title screen) che noi non abbiamo ancora in piano, segnalalo.

## 5. Report

Max 15 righe, italiano colloquiale, con: build exit code e sha1 ROM, test
pass/fail, unità fatte/totali (percentuale), duri, oltre-limite, sospetti
identici-all'inglese, stato parità con il tedesco, e un **VERDETTO** esplicito:
`OK` oppure `NON OK` con il motivo principale.

Se è tutto regolare e non è cambiato niente dall'ultimo giro, rispondi
esattamente `[SILENT]`.
