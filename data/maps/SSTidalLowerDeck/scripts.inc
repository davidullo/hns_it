SSTidalLowerDeck_MapScripts::
	.byte 0

SSTidalLowerDeck_EventScript_Phillip::
	trainerbattle_single TRAINER_PHILLIP, SSTidalLowerDeck_Text_PhillipIntro, SSTidalLowerDeck_Text_PhillipDefeat
	msgbox SSTidalLowerDeck_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_EventScript_Leonard::
	trainerbattle_single TRAINER_LEONARD, SSTidalLowerDeck_Text_LeonardIntro, SSTidalLowerDeck_Text_LeonardDefeat
	msgbox SSTidalLowerDeck_Text_LeonardPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_Text_PhillipIntro:
	.string "Argh! Sono stanco morto di\n"
	.string "pulire questo posto enorme!\p"
	.string "Facciamo una lotta veloce!$"

SSTidalLowerDeck_Text_PhillipDefeat:
	.string "Fratellino, ho perso!$"

SSTidalLowerDeck_Text_PhillipPostBattle:
	.string "Siamo i FRATELLI PULIZIE!\p"
	.string "Il vecchio versa il detersivo,\n"
	.string "il giovane strofina!$"

SSTidalLowerDeck_Text_LeonardIntro:
	.string "Questa è la stiva della nave.\n"
	.string "C'è un sacco di spazio.\l"
	.string "Va benissimo per una lotta POKéMON.$"

SSTidalLowerDeck_Text_LeonardDefeat:
	.string "Fratellone, ho perso!$"

SSTidalLowerDeck_Text_LeonardPostBattle:
	.string "Siamo i FRATELLI PULIZIE!\p"
	.string "Il vecchio versa il detersivo,\n"
	.string "il giovane strofina!$"

