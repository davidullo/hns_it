SlateportCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SlateportCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SLATEPORT_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

SlateportCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_SLATEPORT_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SlateportCity_PokemonCenter_1F_EventScript_Sailor::
	msgbox SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_EventScript_Woman::
	msgbox SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon:
	.string "Vuoi un consiglio?\p"
	.string "Direi di allevare diversi tipi\n"
	.string "di POKéMON in modo equilibrato.\p"
	.string "Non va bene rendere forte\n"
	.string "un solo POKéMON.\p"
	.string "Se ha uno svantaggio di tipo,\n"
	.string "potrebbe non avere scampo.$"

SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend:
	.string "Scambio POKéMON con gli amici.\p"
	.string "Se un POKéMON scambiato tiene\n"
	.string "un oggetto, sono il doppio felice!$"

