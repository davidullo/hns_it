SootopolisCity_House4_MapScripts::
	.byte 0

SootopolisCity_House4_EventScript_Man::
	msgbox SootopolisCity_House4_Text_AncientTreasuresWaitingInSea, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Woman::
	msgbox SootopolisCity_House4_Text_StrollUnderwaterWithPokemon, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SootopolisCity_House4_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SootopolisCity_House4_Text_AncientTreasuresWaitingInSea:
	.string "Ascolta, ti dico una cosa\n"
	.string "interessante.\p"
	.string "Dovrebbe esserci un'antica\n"
	.string "rovina nel mare qui intorno.\p"
	.string "Potrebbero esserci tesori che attendono\n"
	.string "di essere scoperti laggiù.$"

SootopolisCity_House4_Text_StrollUnderwaterWithPokemon:
	.string "Antichi tesori…\p"
	.string "Bello se esistessero, ma\n"
	.string "anche se non ci fossero, sarebbe\l"
	.string "splendido fare una passeggiata\l"
	.string "sott'acqua coi miei POKéMON.$"

SootopolisCity_House4_Text_Azumarill:
	.string "AZUMARILL: Marurii.$"

