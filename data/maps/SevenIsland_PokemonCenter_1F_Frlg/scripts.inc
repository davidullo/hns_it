SevenIsland_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SevenIsland_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_SEVEN_ISLAND
	end

SevenIsland_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

SevenIsland_PokemonCenter_1F_EventScript_OldMan::
	msgbox SevenIsland_PokemonCenter_1F_Text_EventsDependingOnConnections, MSGBOX_NPC
	end

SevenIsland_PokemonCenter_1F_EventScript_Sailor::
	msgbox SevenIsland_PokemonCenter_1F_Text_DidYouRideSeagallopHere, MSGBOX_NPC
	end

SevenIsland_PokemonCenter_1F_EventScript_Beauty::
	msgbox SevenIsland_PokemonCenter_1F_Text_CheckOutTrainerTower, MSGBOX_NPC
	end

SevenIsland_PokemonCenter_1F_Text_EventsDependingOnConnections::
	.string "Su quest'isola accadono eventi\n"
	.string "diversi a seconda dei collegamenti.\p"
	.string "Quali collegamenti?\p"
	.string "Sta a te scoprirlo\n"
	.string "da solo.$"

SevenIsland_PokemonCenter_1F_Text_DidYouRideSeagallopHere::
	.string "Sei arrivato qui con un\n"
	.string "traghetto SEAGALLOP?\p"
	.string "Ci sono almeno dieci di quelle\n"
	.string "navi veloci.\p"
	.string "Però non so dove vadano\n"
	.string "tutte.$"

SevenIsland_PokemonCenter_1F_Text_CheckOutTrainerTower::
	.string "Se ti senti sicuro, dovresti\n"
	.string "visitare la TORRE ALLENATORI.$"

