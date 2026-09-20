Route40_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route40_MapScript_OnTransition
	.byte 0

Route40_MapScript_OnTransition::
	callnative SetTimeBasedEncounters
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, Route40_MapScript_ClearWeather
	end

Route40_MapScript_ClearWeather::
	setweather WEATHER_NONE
	end

Route40_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON_HNS, Route40_Text_SwimmermSimonSeen, Route40_Text_SwimmermSimonBeaten
	msgbox Route40_Text_SwimmermSimonAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmermSimonSeen:
	.string "Bisogna riscaldarsi prima\n"
	.string "di entrare in acqua.\p"
	.string "È la base.$"

Route40_Text_SwimmermSimonBeaten:
	.string "OK! Mi arrendo!$"

Route40_Text_SwimmermSimonAfter:
	.string "FIORLISOPRA è ancora\n"
	.string "abbastanza lontana da qui.$"

Route40_EventScript_Randall::
	trainerbattle_single TRAINER_RANDALL_HNS, Route40_Text_SwimmermRandallSeen, Route40_Text_SwimmermRandallBeaten
	msgbox Route40_Text_SwimmermRandallAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmermRandallSeen:
	.string "Ehi, sei giovane e in forma!\p"
	.string "Non cavalcare i POKéMON!\n"
	.string "Nuota!$"

Route40_Text_SwimmermRandallBeaten:
	.string "Uh-oh. Ho perso…$"

Route40_Text_SwimmermRandallAfter:
	.string "Nuotare allena tutto\n"
	.string "il corpo. Fa bene.$"

Route40_EventScript_Elaine::
	trainerbattle_single TRAINER_ELAINE_HNS, Route40_Text_SwimmerfElaineSeen, Route40_Text_SwimmerfElaineBeaten
	msgbox Route40_Text_SwimmerfElaineAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmerfElaineSeen:
	.string "Vai a FIORLISOPRA?\p"
	.string "Facciamo prima\n"
	.string "una lotta veloce?$"

Route40_Text_SwimmerfElaineBeaten:
	.string "Ho perso!$"

Route40_Text_SwimmerfElaineAfter:
	.string "I'd say I'm a better swimmer\n"
	.string "than you. Yeah!$"

Route40_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA_HNS, Route40_Text_SwimmerfPaulaSeen, Route40_Text_SwimmerfPaulaBeaten
	msgbox Route40_Text_SwimmerfPaulaAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmerfPaulaSeen:
	.string "Niente ciambella per me.\p"
	.string "Sto aggrappata a un\n"
	.string "POKéMON!$"

Route40_Text_SwimmerfPaulaBeaten:
	.string "Ooh, mi gira la testa!$"

Route40_Text_SwimmerfPaulaAfter:
	.string "Mentre galleggio così,\n"
	.string "le onde mi portano via.$"

Route40_EventScript_Woman1::
	lock
	faceplayer
	msgbox Route40_Text_Lass1, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_Lass1:
	.string "Anche se da qui non si vede,\n"
	.string "CIANWOOD è oltre il mare.$"

Route40_EventScript_Woman2::
	lock
	faceplayer
	msgbox Route40_Text_Lass2, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_Lass2:
	.string "Sono arrivata a OLIVINE in nave per\n"
	.string "vedere i posti e respirare\l"
	.string "l'atmosfera.\p"
	.string "Essendo un porto, è molto\n"
	.string "diverso da una grande città.$"

Route40_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route40_Text_StandingYoungster, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_StandingYoungster:
	.string "Sei andato alla COLLINA\n"
	.string "ALLENATORI?\p"
	.string "Credo che tanti allenatori\n"
	.string "forti si siano già radunati lì.\p"
	.string "Ma con tutte le MEDAGLIE che hai\n"
	.string "non dovresti avere problemi.$"

Route40_Text_Monica:
	.string "MONICA: Piacere di conoscerti.\n"
	.string "Sono MONICA della FAMIGLIA DEI GIORNI.\p"
	.string "Scommetto che non indovini il mio\n"
	.string "giorno preferito!$"

Route40_Text_MonicaGivesGift:
	.string "Esatto!\p"
	.string "In segno della nostra amicizia,\n"
	.string "ho un regalo per te!$"

Route40_Text_MonicaGaveGift:
	.string "MONICA: It's an item that raises\n"
	.string "the power of FLYING-type moves.\p"
	.string "You should equip a bird\n"
	.string "POKéMON with that item.$"

Route40_Text_MonicaMonday:
	.string "MONICA: I miei fratelli e\n"
	.string "sorelle sono in giro.\p"
	.string "Vedi se riesci a\n"
	.string "trovarli tutti!$"

Route40_Text_MonicaNotMonday:
	.string "MONICA: Oggi non mi pare\n"
	.string "lunedì. Che tristezza…$"

Route40_Text_MonicaNope:
	.string "Non è quello giusto.$"

Rotue40_EventScript_Monica::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SHARP_BEAK, Rotue40_EventScript_MonicaCompleted
	msgbox Route40_Text_Monica, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Rotue40_EventScript_MonicaNope
	case 1, Rotue40_EventScript_MonicaYes
	case 2, Rotue40_EventScript_MonicaNope
	case 3, Rotue40_EventScript_MonicaNope
	case 4, Rotue40_EventScript_MonicaNope
	case 5, Rotue40_EventScript_MonicaNope
	case 6, Rotue40_EventScript_MonicaNope
	case 7 Rotue40_EventScript_MonicaCancel
	case MULTI_B_PRESSED, Rotue40_EventScript_MonicaCancel
	closemessage
	release
	end
Rotue40_EventScript_MonicaYes::
	msgbox Route40_Text_MonicaGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_SHARP_BEAK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_SHARP_BEAK
	msgbox Route40_Text_MonicaGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Rotue40_EventScript_MonicaNope::
	msgbox Route40_Text_MonicaNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Rotue40_EventScript_MonicaCancel::
	closemessage
	release
	end
Rotue40_EventScript_MonicaCompleted::
	msgbox Route40_Text_MonicaMonday, MSGBOX_DEFAULT
	closemessage
	release
	end
