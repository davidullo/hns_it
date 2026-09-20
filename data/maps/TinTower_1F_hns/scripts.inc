TinTower_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TinTower_OnTransition
	.byte 0

TinTower_OnTransition::
	setescapewarp MAP_BELLCHIME_TRAIL_HNS, 35, 42
	end

TinTower_1F_EventScript_SageA::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageA_Hooh
	msgbox TinTower_1F_Sage4_Text2, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageA_Hooh::
	msgbox TinTower_1F_Sage4_Text1, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageB::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageB_Hooh
	msgbox TinTower_1F_Sage2_Text, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageB_Hooh::
	msgbox TinTower_1F_Sage1_Text, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageC::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageC_Hooh
	msgbox TinTower_1F_Sage6_Text2, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageC_Hooh::
	msgbox TinTower_1F_Sage3_Text, MSGBOX_DEFAULT
	closemessage
	release
	end


TinTower_1F_Sage1_Text:
	.string "Secondo la leggenda…\n"
	.string "Quando le anime dei POKéMON e degli\p"
	.string "uomini comunicano, dal cielo scende\n"
	.string "un POKéMON dai colori dell'arcobaleno…\p"
	.string "Che i POKéMON leggendari\n"
	.string "stiano mettendo alla prova noi umani?$"

TinTower_1F_Sage2_Text:
	.string "Quando la TORRE DI BRONZO bruciò,\n"
	.string "si dice che tre POKéMON senza nome\l"
	.string "perirono. Fu tragico.\p"
	.string "Però…\p"
	.string "Un POKéMON dai colori arcobaleno…\n"
	.string "In altre parole…\p"
	.string "HO-OH scese dal cielo e\n"
	.string "diede nuova vita ai tre POKéMON.\p"
	.string "Essi sono…\n"
	.string "SUICUNE, ENTEI e RAIKOU.\p"
	.string "Questo è ciò che si dice.$"

TinTower_1F_Sage3_Text:
	.string "Si dice che le due TORRI siano state\n"
	.string "costruite per favorire amicizia e\p"
	.string "speranza tra POKéMON e uomini.\n"
	.string "Sono passati 700 anni, ma l'ideale\p"
	.string "resta importante ancora oggi.$"

TinTower_1F_Sage4_Text1:
	.string "HO-OH sembra essere sceso\n"
	.string "su questa, la TORRE CAMPANA!$"

TinTower_1F_Sage4_Text2:
	.string "Si dice che i POKéMON leggendari\n"
	.string "racchiudano tre poteri…\p"
	.string "Il lampo che colpì la TORRE.\n"
	.string "Il fuoco che bruciò la TORRE.\p"
	.string "E la pioggia che spense il fuoco…$"

TinTower_1F_Sage6_Text2:
	.string "Dei POKéMON leggendari, SUICUNE\n"
	.string "è detto il più vicino a HO-OH.\p"
	.string "Sento che c'è anche un legame con\n"
	.string "i POKéMON noti come UNOWN.\p"
	.string "Gli UNOWN devono condividere un\n"
	.string "legame di cooperazione con SUICUNE.$"

TinTower_1F_EusineHoOh_Text:
	.string "Lo sapevo.\p"
	.string "Sapevo che avresti visto il POKéMON\n"
	.string "dai colori arcobaleno, <PLAYER>.\p"
	.string "È andata proprio come immaginavo.\n"
	.string "La mia ricerca non è male, direi.\p"
	.string "Continuerò a studiare i POKéMON\n"
	.string "per diventare un POKéMANIAC famoso!$"

TinTower_1F_EusineSuicune_Text:
	.string "EUSINE: Fantastico! Troppo bello!\n"
	.string "Mai vista una lotta così grande.\p"
	.string "È stato davvero emozionante.\n"
	.string "SUICUNE era forte, ma tu sei stato\p"
	.string "ancora più incredibile, <PLAYER>.\n"
	.string "Ho sentito che il potere magico di\p"
	.string "SUICUNE evoca un POKéMON arcobaleno.\n"
	.string "Forse, chissà, quel che è successo\p"
	.string "oggi lo farà apparire.\n"
	.string "Studierò ancora le leggende.\p"
	.string "Grazie per avermi mostrato quella\n"
	.string "lotta fantastica.\p"
	.string "Ci vediamo, <PLAYER>!$"
