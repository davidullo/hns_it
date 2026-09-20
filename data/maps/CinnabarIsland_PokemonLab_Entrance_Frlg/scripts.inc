CinnabarIsland_PokemonLab_Entrance_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_PokemonLab_Entrance_OnTransition
	.byte 0

CinnabarIsland_PokemonLab_Entrance_OnTransition::
	call_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1, CinnabarIsland_PokemonLab_Entrance_EventScript_ReadyFossil
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_ReadyFossil::
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 2
	return

CinnabarIsland_PokemonLab_Entrance_EventScript_Scientist::
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_StudyMonsExtensively, MSGBOX_NPC
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_DrFujiPhoto::
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_PhotoOfLabFounderDrFuji, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_MeetingRoomSign::
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_MeetingRoomSign, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_RAndDRoomSign::
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_RAndDRoomSign, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_TestingRoomSign::
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_TestingRoomSign, MSGBOX_SIGN
	end

CinnabarIsland_Gym_Text_PhotoOfBlaineAndFuji::
	.string "È una foto di BLAINE e\n"
	.string "SIG. FUJI\p"
	.string "Sono lì spalla a spalla\n"
	.string "con grandi sorrisi.$"

CinnabarIsland_PokemonLab_Entrance_Text_StudyMonsExtensively::
	.string "Studiamo i POKéMON ogni\n"
	.string "giorno.\p"
	.string "Spesso ci portano POKéMON rari\n"
	.string "da esaminare.$"

CinnabarIsland_PokemonLab_Entrance_Text_PhotoOfLabFounderDrFuji::
	.string "Una foto del fondatore…\n"
	.string "FUJI?!$"

CinnabarIsland_PokemonLab_Entrance_Text_MeetingRoomSign::
	.string "LAB POKéMON\n"
	.string "Riunioni$"

CinnabarIsland_PokemonLab_Entrance_Text_RAndDRoomSign::
	.string "LAB POKéMON\n"
	.string "Sala R&S$"

CinnabarIsland_PokemonLab_Entrance_Text_TestingRoomSign::
	.string "LAB POKéMON\n"
	.string "Sala prove$"

