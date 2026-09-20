# Cosa manca (stato al 20 settembre 2026, 21:20)

Fermo su richiesta: la traduzione è **quasi finita**, il testo si riprende dopo.

## Numeri

- **37.236 / 37.473 unità utili = 99,4%** (translated 32.620 + auto 4.616)
- **pending 79** (inc 70, cstr 9)
- **skipped 158** = 114 stringhe del ramo giapponese (irraggiungibili) + 44 arrese
- build con questo stato: `make hns` → ROM scritta, 32 MB

## Cosa resta, in ordine di importanza

### 1. Le 79 unità in coda
Sono la coda dura: campi ad array fisso molto stretti (`name` da 8 byte,
`categoryName` da 12) e righe di dialogo già al limite dei 216px. Il runner ci
prova in modalità creativa e accorcia da solo dove può; quello che resta sono i
casi dove l'italiano più corto possibile è comunque troppo lungo.

### 2. Le 44 unità "arresa"
Hanno fallito 6 tentativi e sono rimaste in inglese, con nota `arresa`.
Vanno guardate a mano: molte si possono accorciare a mano in 2 minuti
(`src/data/decoration/header.h`, `src/battle_main.c`), altre è giusto
lasciarle in inglese.

### 3. Due unità in drift
`cstr:src/data/pokemon/species_info/gen_7_families.h#1` (`Grass Quill`) e
`cstr:src/data/pokemon/species_info/gen_8_families.h#112` (`Apple Core`):
tradotte nello store, ma quel testo non esiste più nei sorgenti (i file
`species_info` vengono rigenerati). Da capire se il testo è altrove o se l'unità
va buttata.

### 4. Nomi degli oggetti: 902 mai tradotti (buco trovato giocando)
Nel codice i nomi degli oggetti usano la macro `ITEM_NAME("...")`, e il lettore
di stringhe della pipeline guarda solo `_()` e `COMPOUND_STRING()`: **902 nomi
sono rimasti in inglese** (nel sacchetto si vedono in inglese). Le descrizioni
degli oggetti invece sono tradotte, e i nomi delle mosse pure (quelli usano
`COMPOUND_STRING`).

Piano: **896 nomi unici, 819 hanno il nome ufficiale italiano nel glossario**
(PokeAPI: `ABILITY CAPSULE` → `CAPSULA ABILITÀ`, `ACRO BIKE` → `BICI DA CROSS`).
Gli altri 77 sono roba inventata dalla hack (`ABSOLITE Z`, `AUX POWER`,
`BARBARACITE`) e li fa il modello. Attenzione a `ITEM_NAME_LENGTH = 20`: i nomi
ufficiali vanno in maiuscolo e accorciati se sfondano.

Non si può aggiungere `ITEM_NAME` al lettore esistente senza spostare gli indici
`#N` di tutte le unita' (le chiavi dello store sono posizionali) → va fatto come
passata separata, con iniezione per testo esatto su `items.h`.

### 5. Grafica: 167 file .png in `graphics/` (il divario vero con `hns_de`)
`font/latin_*`, `title_screen`, `naming_screen`, `battle_interface`, `pokedex`,
`pokenav`. La pipeline **non tocca le immagini**: finché non si fa questo, la
ROM resta italiana nei testi ma con la grafica in inglese. È il prossimo
progetto, e non è una cosa da prompt: serve rifare i font e le schermate.

### 5. Parity `hns_de` sui testi dentro i `.c`
Il tedesco ha tradotto stringhe in 70 file `.c`, noi ne copriamo 66. Da
guardare i 4 mancanti.

### 6. Controlli da agganciare ai cron
`it/tools/check_string_arrays.py` esiste e l'ho girato su tutto `src/`, ma non è
ancora dentro il giro automatico: va aggiunto a `CRON_PROMPT.md` e
`CRON_REVIEW.md`, così un array sfondato lo becca il cron e non il compilatore
(un'ora persa).

### 7. Il revisore
Ha risposto in cinese (modello deragliato). Ho messo in cima a `CRON_REVIEW.md`
l'obbligo di scrivere in italiano: da confermare al prossimo giro delle 2h.

## Come si riprende

```bash
cd ~/Developer/hns_it/it
python3 -m hnsit translate --kind auto --size 40 --workers 16 --rounds 40
python3 -m hnsit inject
python3 -m hnsit stats
python3 it/tools/check_string_arrays.py     # exit 1 se un array sfonda
cd .. && source ~/.hermes/scripts/hns_env.sh && make hns -j8
```

## Vincoli da non dimenticare

- modelli: solo `opencode-go` + `deepseek-v4.1-flash`, `--reasoning none`
  (mai glm, guardia `MODELLO_VIETATO` nel runner)
- il worker deve fare **una sola chiamata per lotto, senza tool**
- la ROM base di Smeraldo sta in `~/roms/emerald_base/`, **fuori dal repo** e
  mai su GitHub
