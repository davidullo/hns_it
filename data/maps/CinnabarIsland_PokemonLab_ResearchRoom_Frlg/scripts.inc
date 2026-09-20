CinnabarIsland_PokemonLab_ResearchRoom_Frlg_MapScripts::
	.byte 0

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_MetronomeTutor::
	goto EventScript_MetronomeTutor
	end

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_Scientist::
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_EeveeCanEvolveIntroThreeMons, MSGBOX_NPC
	end

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_Computer::
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_LegendaryBirdEmail, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_AmberPipe::
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_AnAmberPipe, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_ResearchRoom_Text_EeveeCanEvolveIntroThreeMons::
	.string "EEVEE può evolversi in tre tipi\n"
	.string "di POKéMON.$"

CinnabarIsland_PokemonLab_ResearchRoom_Text_LegendaryBirdEmail::
	.string "C'è un messaggio e-mail.\p"
	.string "… … …\p"
	.string "Ci sono tre uccelli leggendari\n"
	.string "POKéMON.\p"
	.string "Sono ARTICUNO, ZAPDOS e\n"
	.string "MOLTRES.\p"
	.string "Non si sa dove siano.\p"
	.string "Esploreremo la caverna\n"
	.string "vicino a CERULEAN.\p"
	.string "Da: SQUADRA RICERCA POKéMON…$"

CinnabarIsland_PokemonLab_ResearchRoom_Text_AnAmberPipe::
	.string "Pipa d'ambra!$"

