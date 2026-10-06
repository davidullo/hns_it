# Grafiche da tradurre in italiano

Le scritte elencate qui **non sono stringhe** e non passano dalla pipeline di traduzione:
sono pixel disegnati dentro un tileset, posizionati da una tilemap `.bin`. Vanno
ritoccate sull'immagine, una per una.

Lista ottenuta con OCR (tesseract, upscale 8x) su tutte le PNG di `graphics/`:
il metodo e' in `pokehns-ita-translation/references/grafiche-con-testo.md`.
Per aggiornare i progressi: cambiare `[ ]` in `[x]` sulla riga del file finito.

**Progressi: 7 / 90 file**

| gruppo | fatti | totale |
|---|---|---|
| Riepilogo Pokémon | 1 | 3 |
| Interfaccia e menu mosse | 2 | 5 |
| Box Pokémon | 1 | 1 |
| Pokédex | 0 | 15 |
| PokéNav | 0 | 22 |
| Scheda allenatore e Frontier Pass | 0 | 5 |
| Gare e Pokéblock | 0 | 5 |
| Stato in battaglia | 0 | 12 |
| Titolo e intro | 0 | 5 |
| Voci singole | 3 | 17 |

---

## Riepilogo Pokémon (1/3)

- [x] `graphics/summary_screen/hns/tiles.png` — PROFILO / ABILITA / STRUMENTI / STATO / MOSSE / DESCRIZIONE / TRAINER MEMO
- [ ] `graphics/summary_screen/iv_ev_tiles.png` — PROFILE / ABILITY / MOVES / DESCRIPTION / TRAINER MEMO
- [ ] `graphics/summary_screen/tiles.png` — come iv_ev_tiles (copia base, usata se IS_HNS e' spento)

## Interfaccia e menu mosse (2/5)

- [x] `graphics/interface/menu_info.png` — POWER / PP / TYPE / ACCURACY / EFFECT
- [x] `graphics/interface/status_icons.png` — PSN / PAR / SLP / FRZ / BRN / FNT
- [ ] `graphics/battle_interface/move_info_window_start.png` — START
- [ ] `graphics/battle_interface/move_info_window_l.png` — START
- [ ] `graphics/bag/check_berry.png` — BITTER / SOUR / SWEET / DRY / SPICY

## Box Pokémon (1/1)

- [x] `graphics/pokemon_storage/menu.png` — CLOSE e voci del menu del box

## Pokédex (0/15)

- [ ] `graphics/pokedex/menu.png` — CANCEL / BACK TO LIST / LIST TOP / LIST BOTTOM / BACK TO POKEDEX / CLOSE POKEDEX
- [ ] `graphics/pokedex/interface.png` — SELECT / SEARCH / START / MENU
- [ ] `graphics/pokedex/search_menu.png` — SEARCH
- [ ] `graphics/pokedex/area_unknown.png` — AREA UNKNOWN
- [ ] `graphics/pokedex/hgss/tileset_interface.png` — SELECT / SEARCH / START / MENU
- [ ] `graphics/pokedex/hgss/tileset_interface_DECA.png` — SELECT / SEARCH / START / MENU
- [ ] `graphics/pokedex/hgss/tileset_interface_hns.png` — SELECT / SEARCH / START / MENU
- [ ] `graphics/pokedex/hgss/tileset_interface_DECA_hns.png` — SELECT / SEARCH / START / MENU
- [ ] `graphics/pokedex/hgss/tileset_menu_list.png` — MENU / SEARCH
- [ ] `graphics/pokedex/hgss/tileset_menu_list_DECA.png` — MENU / SEARCH
- [ ] `graphics/pokedex/hgss/tileset_menu1.png` — voci menu Pokédex (gen 4)
- [ ] `graphics/pokedex/hgss/tileset_menu2.png` — voci menu Pokédex (gen 4)
- [ ] `graphics/pokedex/hgss/tileset_menu3.png` — voci menu Pokédex (gen 4)
- [ ] `graphics/pokedex/hgss/tileset_menu_search.png` — SEARCH
- [ ] `graphics/pokedex/hgss/tileset_menu_search_DECA.png` — SEARCH

## PokéNav (0/22)

- [ ] `graphics/pokenav/options/search.png` — SEARCH
- [ ] `graphics/pokenav/options/match_call.png` — MATCH CALL
- [ ] `graphics/pokenav/options/party.png` — PARTY
- [ ] `graphics/pokenav/options/condition.png` — CONDITION
- [ ] `graphics/pokenav/options/ribbons.png` — RIBBONS
- [ ] `graphics/pokenav/options/hoenn_map.png` — HOENN MAP
- [ ] `graphics/pokenav/options/cool.png`
- [ ] `graphics/pokenav/options/beauty.png`
- [ ] `graphics/pokenav/options/cute.png`
- [ ] `graphics/pokenav/options/smart.png`
- [ ] `graphics/pokenav/options/tough.png`
- [ ] `graphics/pokenav/options/switch_off.png` — SWITCH OFF
- [ ] `graphics/pokenav/left_headers/main_menu.png` — MAIN MENU
- [ ] `graphics/pokenav/left_headers/search.png` — SEARCH
- [ ] `graphics/pokenav/left_headers/party.png` — PARTY
- [ ] `graphics/pokenav/left_headers/cool.png`
- [ ] `graphics/pokenav/left_headers/beauty.png`
- [ ] `graphics/pokenav/left_headers/cute.png`
- [ ] `graphics/pokenav/left_headers/smart.png`
- [ ] `graphics/pokenav/region_map/city_zoom_text.png` — POKEMON CENTER / GYM / MART
- [ ] `graphics/pokenav/condition/graph.png` — TOUGH / BEAUTY / SMART / CUTE
- [ ] `graphics/pokenav/hns/radio/ui_tiles.png` — scritte del menu radio

## Scheda allenatore e Frontier Pass (0/5)

- [ ] `graphics/trainer_card/tiles.png` — TRAINER CARD
- [ ] `graphics/trainer_card/frlg/tiles.png` — TRAINER / CARD
- [ ] `graphics/frontier_pass/bg.png` — FRONTIER PASS / TRAINER CARD / POKEDEX / NAME / TIME
- [ ] `graphics/frontier_pass/map_and_card.png` — TRAINER CARD / POKEDEX / NAME / TIME
- [ ] `graphics/frontier_pass/map_screen.png`

## Gare e Pokéblock (0/5)

- [ ] `graphics/contest/results_screen/tiles.png` — LINK MASTER / NORMAL SUPER HYPER / RANK / COOL / BEAUTY / CONTEST
- [ ] `graphics/contest/interface.png` — COOL / BEAUTY / CUTE
- [ ] `graphics/pokeblock/use_screen/graph.png` — TOUGH / BEAUTY / SMART / COOL / CUTE
- [ ] `graphics/pokeblock/use_screen/updown.png` — UP / DOWN
- [ ] `graphics/pokeblock/menu.png` — FEEL

## Stato in battaglia (0/12)

- [ ] `graphics/battle_interface/status.png` — PSN / PAR / SLP / FRZ / BRN / FNT
- [ ] `graphics/battle_interface/status2.png` — PSN / PAR / SLP / FRZ / BRN / FNT
- [ ] `graphics/battle_interface/status3.png` — PSN / PAR / SLP / FRZ / BRN / FNT
- [ ] `graphics/battle_interface/status4.png` — PSN / PAR / SLP / FRZ / BRN / FNT
- [ ] `graphics/battle_interface/gen4/status.png` — PSN / PAR / SLP / FRZ / BRN / FNT
- [ ] `graphics/battle_interface/gen4/status2.png` — PSN / PAR / SLP / FRZ / BRN / FNT
- [ ] `graphics/battle_interface/gen4/status3.png` — PSN / PAR / SLP / FRZ / BRN / FNT
- [ ] `graphics/battle_interface/gen4/status4.png` — PSN / PAR / SLP / FRZ / BRN / FNT
- [ ] `graphics/battle_interface/hns/status.png` — PSN / PAR / SLP / FRZ / BRN / FNT
- [ ] `graphics/battle_interface/hns/status2.png` — PSN / PAR / SLP / FRZ / BRN / FNT
- [ ] `graphics/battle_interface/hns/status3.png` — PSN / PAR / SLP / FRZ / BRN / FNT
- [ ] `graphics/battle_interface/hns/status4.png` — PSN / PAR / SLP / FRZ / BRN / FNT

## Titolo e intro (0/5)

- [ ] `graphics/title_screen/press_start.png` — PRESS START
- [ ] `graphics/title_screen/hns/press_start.png` — PRESS START
- [ ] `graphics/title_screen_frlg/copyright_press_start.png` — PRESS START
- [ ] `graphics/title_screen/emerald_version.png` — versione di Smeraldo mostrata sul titolo
- [ ] `graphics/title_screen/hns/emerald_version.png` — versione di Smeraldo mostrata sul titolo

## Voci singole (3/17)

- [x] `graphics/naming_screen/back_button.png` — BACK
- [x] `graphics/naming_screen/ok_button.png` — OK / START
- [ ] `graphics/naming_screen/page_swap_frame.png`
- [x] `graphics/easy_chat/button_window.png` — DELETE
- [ ] `graphics/union_room_chat/background.png` — BACK / SWITCH
- [ ] `graphics/link/321start.png` — 3 / 2 / 1 / START
- [ ] `graphics/link/321start_static.png` — 3 / 2 / 1 / START
- [ ] `graphics/diploma/tiles.png` — testo del diploma
- [ ] `graphics/battle_frontier/tourney_buttons.png` — pulsanti del torneo
- [ ] `graphics/berry_blender/start.png` — START
- [ ] `graphics/slot_machine/menu.png` — SELECT
- [ ] `graphics/slot_machine/reel_symbols/7.png` — REPLAY
- [ ] `graphics/roulette/credit.png` — CREDIT
- [ ] `graphics/roulette/multiplier.png`
- [ ] `graphics/roulette/center.png`
- [ ] `graphics/mail/retro/tiles.png` — cornice della posta
- [ ] `graphics/wireless_status_screen/bg.png`

---

## Da lasciare in originale

- `graphics/types/*.png` (28 targhette dei tipi): tradotte e approvate, non si toccano
- `graphics/intro_frlg/copyright.png`, `graphics/credits_frlg/copyright.png`: testo legale
- `graphics/ui_screenshots/`: screenshot per la documentazione, non sono asset di gioco
- `graphics/map_preview/`, `graphics/map_popup/`, `graphics/battle_environment/`: nessun testo, solo texture
