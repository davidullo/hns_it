Route12_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route12_OnResume
	.byte 0

Route12_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route12_EventScript_TryRemoveSnorlax
	end

Route12_EventScript_TryRemoveSnorlax::
	removeobject VAR_LAST_TALKED
	return

Route12_EventScript_Snorlax::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_POKE_FLUTE, Route12_EventScript_SnorlaxNoPokeFlute
	msgbox Text_WantToUsePokeFlute, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route12_EventScript_DontUsePokeFlute
	call EventScript_AwakenSnorlax
	setwildbattle SPECIES_SNORLAX, 30
	waitse
	playmoncry SPECIES_SNORLAX, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_HIDE_ROUTE_12_SNORLAX
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	setflag FLAG_WOKE_UP_ROUTE_12_SNORLAX
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route12_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route12_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route12_EventScript_FoughtSnorlax
	release
	end

Route12_EventScript_DontUsePokeFlute::
	release
	end

Route12_EventScript_FoughtSnorlax::
	msgbox Text_SnorlaxReturnedToMountains
	release
	end

Route12_EventScript_SnorlaxNoPokeFlute::
	msgbox Route12_Text_MonSprawledOutInSlumber
	release
	end

Route12_EventScript_RouteSign::
	msgbox Route12_Text_RouteSign, MSGBOX_SIGN
	end

Route12_EventScript_FishingSign::
	msgbox Route12_Text_SportfishingArea, MSGBOX_SIGN
	end

Route12_Text_MonSprawledOutInSlumber::
	.string "Un POKéMON è spaparanzato in\n"
	.string "un sonno profondo e beato.$"

Text_SnorlaxWokeUp::
	.string "SNORLAX si è svegliato!\p"
	.string "Ha attaccato in preda all'ira!$"

Text_SnorlaxReturnedToMountains::
	.string "SNORLAX si è calmato.\n"
	.string "Ha fatto un grande sbadiglio…\l"
	.string "Ed è tornato sui monti.$"

Text_WantToUsePokeFlute::
	.string "Vuoi usare il POKé FLAUTO?$"

Text_PlayedPokeFlute::
	.string "{PLAYER} ha suonato il POKé FLAUTO.$"

Route12_Text_NedIntro::
	.string "Sì!\n"
	.string "Qui ho preso qualcosa!$"

Route12_Text_NedDefeat::
	.string "Tsk!\n"
	.string "Solo un pesciolino…$"

Route12_Text_NedPostBattle::
	.string "Resisti!\n"
	.string "La lenza si è impigliata!$"

Route12_Text_ChipIntro::
	.string "Porta pazienza.\n"
	.string "Pescare è un gioco di attesa.$"

Route12_Text_ChipDefeat::
	.string "Quello è scappato!$"

Route12_Text_ChipPostBattle::
	.string "Con una CANNA migliore potrei\n"
	.string "prendere POKéMON migliori…$"

Route12_Text_JustinIntro::
	.string "Cerco una PIETRALUNARE.\n"
	.string "Ne hai trovata una?$"

Route12_Text_JustinDefeat::
	.string "Ahia!$"

Route12_Text_JustinPostBattle::
	.string "Avrei potuto far evolvere i miei\n"
	.string "POKéMON con una PIETRALUNARE.\p"
	.string "Avrei vinto, scommetto.$"

Route12_Text_LucaIntro::
	.string "L'elettricità è la mia specialità.\p"
	.string "Non so nulla dei POKéMON\n"
	.string "di mare, però.$"

Route12_Text_LucaDefeat::
	.string "Staccato!$"

Route12_Text_LucaPostBattle::
	.string "L'acqua conduce elettricità, quindi\n"
	.string "colpisci i POKéMON di mare.$"

Route12_Text_HankIntro::
	.string "IL PESCATORE PAZZO contro il\n"
	.string "RAGAZZO POKéMON!$"

Route12_Text_HankDefeat::
	.string "Troppo forte!$"

Route12_Text_HankPostBattle::
	.string "Immagino che si diventi bravi in\n"
	.string "ciò che piace.\p"
	.string "Mi hai battuto ai POKéMON,\n"
	.string "ma nella pesca non mi superi.$"

Route12_Text_ElliotIntro::
	.string "Adoro pescare, sia chiaro.\p"
	.string "Ma sarebbe meglio se avessi anche\n"
	.string "più lavoro.$"

Route12_Text_ElliotDefeat::
	.string "Non è facile…$"

Route12_Text_ElliotPostBattle::
	.string "Va tutto bene.\n"
	.string "Perdere non mi secca più.$"

Route12_Text_AndrewIntro::
	.string "Cosa si pesca?\p"
	.string "Non sai mai cosa potresti\n"
	.string "prendere!$"

Route12_Text_AndrewDefeat::
	.string "L'ho perso!$"

Route12_Text_AndrewPostBattle::
	.string "Come, MAGIKARP?\p"
	.string "Li prendo sempre, certo.\n"
	.string "Ma che fifoni che sono.$"

Route12_Text_RouteSign::
	.string "PERCORSO 12 \n"
	.string "A nord verso LAVANDONIA$"

Route12_Text_SportfishingArea::
	.string "ZONA PESCA SPORTIVA$"

Route12_Text_JesIntro::
	.string "JES: Se vinco, farò\n"
	.string "la proposta a GIA.$"

Route12_Text_JesDefeat::
	.string "JES: Oh, ti prego, perché non\n"
	.string "ci hai lasciato vincere?$"

Route12_Text_JesPostBattle::
	.string "JES: Oh, GIA, perdonami,\n"
	.string "amore mio!$"

Route12_Text_JesNotEnoughMons::
	.string "JES: Io e GIA staremo\n"
	.string "insieme per sempre.\p"
	.string "Non lottiamo se non hai\n"
	.string "due POKéMON tuoi.$"

Route12_Text_GiaIntro::
	.string "GIA: Ehi, JES…\p"
	.string "Se vinciamo, ti sposo!$"

Route12_Text_GiaDefeat::
	.string "GIA: Oh, ma perché?$"

Route12_Text_GiaPostBattle::
	.string "GIA: JES, sciocco!\n"
	.string "Hai rovinato tutto!$"

Route12_Text_GiaNotEnoughMons::
	.string "GIA: Non posso lottare\n"
	.string "senza il mio JES!\p"
	.string "Non hai un altro POKéMON?$"
