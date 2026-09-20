VermilionCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_PokemonCenter_OnTransition
	.byte 0

VermilionCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_VERMILION_CITY_HNS
	end

VermilionPokeCenter_EventScript_FishingGuru::
	goto_if_set FLAG_HIDE_VERMILION_SNORLAX, VermilionPokeCenter_EventScript_FishingGuru2
	msgbox VermilionCity_PokemonCenter1F_Text_FishingGuru, MSGBOX_NPC
	end

VermilionPokeCenter_EventScript_FishingGuru2::
	msgbox VermilionCity_PokemonCenter1F_Text_FishingGuru_FoughtSnorlax, MSGBOX_NPC
	end

VermilionPokeCenter_EventScript_Sailor::
	msgbox VermilionCity_PokemonCenter1F_Text_Sailor, MSGBOX_NPC
	end

VermilionPokeCenter_EventScript_Bugcatcher::
	msgbox VermilionCity_PokemonCenter1F_Text_BugCatcher, MSGBOX_NPC
	end

VermilionCity_PokemonCenter1F_Text_FishingGuru:
	.string "Un POKéMON che dorme è davanti\n"
	.string "alla GROTTA DIGLETT.\p"
	.string "È un'occasione fantastica per\n"
	.string "prenderlo, ma come lo svegli?$"

VermilionCity_PokemonCenter1F_Text_FishingGuru_FoughtSnorlax:
	.string "C'era un POKéMON che dormiva\n"
	.string "proprio davanti alla\l"
	.string "GROTTA DIGLETT.\p"
	.string "Ma sembra sparito.$"

VermilionCity_PokemonCenter1F_Text_Sailor:
	.string "La NAVE VELOCE è un ottimo posto\n"
	.string "per incontrare e sfidare allenatori.$"

VermilionCity_PokemonCenter1F_Text_BugCatcher:
	.string "Oh? Hai delle MEDAGLIE che non\n"
	.string "ho mai visto.\p"
	.string "Ah, ho capito. Le hai prese a\n"
	.string "JOHTO.$"
