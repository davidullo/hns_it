LavenderTown_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_PokemonCenter_OnTransition
	.byte 0

LavenderTown_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_LAVENDER_TOWN_HNS
	end

LavenderTown_PokemonCenter_EventScript_Gent::
	msgbox LavenderTown_PokemonCenter1F_Text_Gentleman, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_Teacher::
	msgbox LavenderTown_PokemonCenter1F_Text_Teacher, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_Youngster::
	goto_if_set FLAG_RETURNED_MACHINE_PART, LavenderTown_PokemonCenter_EventScript_YoungsterReturnedMachinePart
	msgbox LavenderTown_PokemonCenter1F_Text_Youngster, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_YoungsterReturnedMachinePart::
	msgbox LavenderTown_PokemonCenter1F_Text_Youngster_ReturnedMachinePart, MSGBOX_NPC
	end

LavenderTown_PokemonCenter1F_Text_Gentleman:
	.string "A nord di LAVANDONIA c'è la\n"
	.string "GALLERIA ROCCIA. Attraversala per\l"
	.string "arrivare alla CENTRALE.$"

LavenderTown_PokemonCenter1F_Text_Teacher:
	.string "C'è un programma\n"
	.string "col POKé FLAUTO.\p"
	.string "Serve la RADIO\n"
	.string "POTENZIATA.\p"
	.string "Forse la RADIO qui\n"
	.string "te la può dare.$"

LavenderTown_PokemonCenter1F_Text_Youngster:
	.string "Se la CENTRALE è ferma,\n"
	.string "anche il TREN CALAMITA è fermo…\p"
	.string "E la RADIO\n"
	.string "non può trasmettere…$"

LavenderTown_PokemonCenter1F_Text_Youngster_ReturnedMachinePart:
	.string "Il DIRETTORE della RADIO\n"
	.string "era davvero contento.\p"
	.string "Ha detto che sono di nuovo in onda\n"
	.string "perché la CENTRALE funziona\l"
	.string "di nuovo.$"
