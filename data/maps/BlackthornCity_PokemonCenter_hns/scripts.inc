BlackthornCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BlackthornCity_PokemonCenter_OnTransition
	.byte 0

BlackthornCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_BLACKTHORN_CITY_HNS
	end

BlackthornCity_PokemonCenter_EventScript_Gent::
	msgbox BlackthornCity_PokemonCenter1FGentlemanText, MSGBOX_NPC
	end

BlackthornCity_PokemonCenter_EventScript_Twin::
	msgbox BlackthornCity_PokemonCenter1FTwinText, MSGBOX_NPC
	end

BlackthornCity_PokemonCenter1FGentlemanText:
	.string "In fondo al lontano INDACO\n"
	.string "PLATEAU c'è la LEGA POKéMON.\p"
	.string "I migliori allenatori si\n"
	.string "radunano da tutto il paese.$"

BlackthornCity_PokemonCenter1FTwinText:
	.string "Dovevo insegnare una mossa al\n"
	.string "mio POKéMON.\p"
	.string "Così ho fatto dimenticare una MN\n"
	.string "col CANCELLAMOSSE.$"
