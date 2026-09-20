SSAnne_Deck_Frlg_MapScripts::
	.byte 0

SSAnne_Deck_EventScript_Youngster::
	msgbox SSAnne_Deck_Text_ShipDepartingSoon, MSGBOX_NPC
	end

SSAnne_Deck_EventScript_BaldingMan::
	msgbox SSAnne_Deck_Text_FeelSeasick, MSGBOX_NPC
	end

SSAnne_Deck_EventScript_Sailor::
	msgbox SSAnne_Deck_Text_ScrubbingDecksHardWork, MSGBOX_NPC
	end

SSAnne_Deck_EventScript_Edmond::
	trainerbattle_single TRAINER_SAILOR_EDMOND, SSAnne_Deck_Text_EdmondIntro, SSAnne_Deck_Text_EdmondDefeat
	msgbox SSAnne_Deck_Text_EdmondPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_Deck_EventScript_Trevor::
	trainerbattle_single TRAINER_SAILOR_TREVOR, SSAnne_Deck_Text_TrevorIntro, SSAnne_Deck_Text_TrevorDefeat
	msgbox SSAnne_Deck_Text_TrevorPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_Deck_Text_ShipDepartingSoon::
	.string "La festa è finita.\n"
	.string "La nave salperà presto.$"

SSAnne_Deck_Text_ScrubbingDecksHardWork::
	.string "Fiuu!\n"
	.string "Lavare i ponti è un bel lavoro!$"

SSAnne_Deck_Text_FeelSeasick::
	.string "Urf… sto male…\p"
	.string "Ho il mal di mare, sono uscito a\n"
	.string "prendere una boccata d'aria…$"

SSAnne_Deck_Text_EdmondIntro::
	.string "Ehi, amico!\p"
	.string "Facciamo un ballo!$"

SSAnne_Deck_Text_EdmondDefeat::
	.string "Sei impressionante!$"

SSAnne_Deck_Text_EdmondPostBattle::
	.string "Quante specie di POKéMON pensi\n"
	.string "che ci siano in questo mondo?$"

SSAnne_Deck_Text_TrevorIntro::
	.string "Ahoy, tu!\n"
	.string "Hai il mal di mare?$"

SSAnne_Deck_Text_TrevorDefeat::
	.string "Sono stato distratto!$"

SSAnne_Deck_Text_TrevorPostBattle::
	.string "Mio papà dice che ci sono 100 tipi\n"
	.string "di POKéMON. Io credo di più.$"

