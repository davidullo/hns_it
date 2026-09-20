CeruleanCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_PokemonCenter_OnTransition
	.byte 0

CeruleanCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_CERULEAN_CITY_HNS
	end

CeruleanCity_PokemonCenter_EventScript_Nerd::
	msgbox CeruleanCity_PokemonCenter1F_Text_SuperNerd, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_EventScript_Guy::
	msgbox CeruleanCity_PokemonCenter1F_Text_GymGuide, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter1F_Text_SuperNerd:
	.string "Per le lotte preferisco usare\n"
	.string "i POKéMON che ho allevato, anche\p"
	.string "se sono più deboli di quelli\n"
	.string "appena presi.$"

CeruleanCity_PokemonCenter1F_Text_GymGuide:
	.string "Il TRENO CALAMITA viaggia a\n"
	.string "oltre 550 km/h. Collega KANTO\l"
	.string "e JOHTO quasi in un istante.\p"
	.string "Rende JOHTO davvero vicina.$"
