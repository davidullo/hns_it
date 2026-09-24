Route26_House2_hns_MapScripts::
	.byte 0

Route26_House2_EventScript_Book::
	lock
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE,Route26_House2_EventScript_BookRead
	closemessage
	release
	end

Route26_House2_EventScript_BookRead::
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route26_House2_EventScript_BookRead2
	closemessage
	release
	end
	
Route26_House2_EventScript_BookRead2::
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex3, MSGBOX_DEFAULT
	closemessage
	release
	end

DayOfWeekSiblingsHouse_Text_Pokedex1:
    .string "C'è qualcosa di scritto qui.\p"
    .string "Vuoi leggerlo?$"

DayOfWeekSiblingsHouse_Text_Pokedex2:
    .string "Ai miei fratelli e sorelle:\p"
    .string "Siamo orgogliosi di servire gli\n"
    .string "allenatori di POKéMON.\p"
    .string "Quando vi parlano, date\n"
    .string "qualcosa di utile.\p"
    .string "Con affetto,\n"
    .string "MONICA\p"
    .string "Continuare a leggere?$"

DayOfWeekSiblingsHouse_Text_Pokedex3:
    .string "Lunedì, MONICA\n"
    .string "PERCORSO 40\p"
    .string "Martedì, TUSCANY\n"
    .string "PERCORSO 29\p"
    .string "Mercoledì, WESLEY\n"
    .string "LAGO D'IRA\p"
    .string "Giovedì, ARTURO\n"
    .string "PERCORSO 36\p"
    .string "Venerdì, FRIEDA\n"
    .string "PERCORSO 32\p"
    .string "Sabato, SANTOS\n"
    .string "CITTÀ DI BLUVERDE\p"
    .string "Domenica, SUNNY\n"
    .string "PERCORSO 37$"
