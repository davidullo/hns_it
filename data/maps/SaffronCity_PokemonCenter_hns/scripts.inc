SaffronCity_PokemonCenter_hns_MapScripts::
map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_PokemonCenter_OnTransition
	.byte 0

SaffronCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_SAFFRON_CITY_HNS
	end

SaffronCity_PokemonCenter_EventScript_Teacher::
	msgbox SaffronCity_PokemonCenter1F_Text_Teacher, MSGBOX_NPC	
	end

SaffronCity_PokemonCenter_EventScript_Fisher::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_PokemonCenter_EventScript_FisherReturnedMachinePart
	msgbox SaffronCity_PokemonCenter1F_Text_Fisher, MSGBOX_NPC	
	end
SaffronCity_PokemonCenter_EventScript_FisherReturnedMachinePart::
	msgbox SaffronCity_PokemonCenter1F_Text_Fisher_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_PokemonCenter_EventScript_Youngster::
	msgbox SaffronCity_PokemonCenter1F_Text_Youngster, MSGBOX_NPC
	end

SaffronCity_PokemonCenter1F_Text_Teacher:
	.string "Come sono i CENTRI POKéMON di\n"
	.string "JOHTO?\p"
	.string "…Ah, capisco. Non sono molto\n"
	.string "diversi da quelli di KANTO.\p"
	.string "Allora posso andare a JOHTO\n"
	.string "senza preoccuparmi!$"

SaffronCity_PokemonCenter1F_Text_Fisher:
	.string "Sono passato per caso dalla\n"
	.string "GALLERIA ROCCIA.\p"
	.string "C'era trambusto alla\n"
	.string "CENTRALE ELETTRICA.$"

SaffronCity_PokemonCenter1F_Text_Fisher_ReturnedPart:
	.string "C'è una grotta strana a CERULEAN.\p"
	.string "Da HIKER esperto dovrei esplorarla,\n"
	.string "ma quel posto spaventa anche me.$"

SaffronCity_PokemonCenter1F_Text_Youngster:
	.string "La SEDE della SILPH SPA e la\n"
	.string "STAZIONE DEL MAGNETOTREN, ecco\l"
	.string "cosa vedere ad AZURPOLI.$"
