FiveIsland_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FiveIsland_OnTransition
	.byte 0

FiveIsland_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_FIVE_ISLAND
	end

FiveIsland_EventScript_IslandSign::
	msgbox FiveIsland_Text_IslandSign, MSGBOX_SIGN
	end

FiveIsland_EventScript_BugCatcher::
	msgbox FiveIsland_Text_WeirdBuildingInMeadow, MSGBOX_NPC
	end

FiveIsland_EventScript_Fisher::
	msgbox FiveIsland_Text_BeenGettingBusierAroundHere, MSGBOX_NPC
	end

FiveIsland_Text_IslandSign::
	.string "ISOLA CINQUE\n"
	.string "Isola Crono: dove va il tempo$"

FiveIsland_Text_WeirdBuildingInMeadow::
	.string "Uffa, che pizza. Volevo giocare\n"
	.string "nel PRATO.\p"
	.string "Ma ci hanno messo un palazzo\n"
	.string "strano, non posso giocare.$"

FiveIsland_Text_BeenGettingBusierAroundHere::
	.string "Ultimamente c'è più vita da\n"
	.string "queste parti.\p"
	.string "Non pesco bei pesci di recente,\n"
	.string "nemmeno io.$"

