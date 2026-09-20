FuchsiaCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FuchsiaCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_FUCHSIA_CITY
	end

FuchsiaCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

FuchsiaCity_PokemonCenter_1F_EventScript_Man::
	msgbox FuchsiaCity_PokemonCenter_1F_Text_CantBecomeGoodTrainerWithOneMon, MSGBOX_NPC
	end

FuchsiaCity_PokemonCenter_1F_EventScript_CooltrainerF::
	msgbox FuchsiaCity_PokemonCenter_1F_Text_PokemonLeagueWestOfViridian, MSGBOX_NPC
	end

FuchsiaCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox FuchsiaCity_PokemonCenter_1F_Text_VisitSafariZoneForPokedex, MSGBOX_NPC
	end

FuchsiaCity_PokemonCenter_1F_Text_CantBecomeGoodTrainerWithOneMon::
	.string "Non si diventa bravi ALLENATORI\n"
	.string "con un solo POKéMON forte.\p"
	.string "Ma allevare molti POKéMON\n"
	.string "alla pari non è facile.$"

FuchsiaCity_PokemonCenter_1F_Text_PokemonLeagueWestOfViridian::
	.string "A ovest c'è un sentiero stretto\n"
	.string "di VIRIDIAN CITY.\p"
	.string "Porta alla sede della LEGA POKéMON.\n"
	.string "La sede guida gli ALLENATORI.$"

FuchsiaCity_PokemonCenter_1F_Text_VisitSafariZoneForPokedex::
	.string "Se stai facendo un POKéDEX,\n"
	.string "visita il SAFARI ZONE.\p"
	.string "Si riproducono i rari POKéMON\n"
	.string "qui.$"

