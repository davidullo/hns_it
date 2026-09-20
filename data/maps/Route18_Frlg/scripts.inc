Route18_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route18_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route18_OnWarp
	.byte 0

Route18_OnTransition::
	call_if_eq VAR_MAP_SCENE_ROUTE16, 1, Route18_OnTransitionCyclingRoad
	end

Route18_OnTransitionCyclingRoad::
	setflag FLAG_SYS_ON_CYCLING_ROAD
	return

Route18_OnWarp::
	map_script_2 VAR_MAP_SCENE_ROUTE16, 1, Route18_OnWarpCyclingRoad
	.2byte 0

Route18_OnWarpCyclingRoad::
	special ForcePlayerOntoBike
	end

Route18_EventScript_RouteSign::
	msgbox Route18_Text_RouteSign, MSGBOX_SIGN
	end

Route18_EventScript_CyclingRoadSign::
	msgbox Route18_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route18_Text_WiltonIntro::
	.string "Controllo sempre ogni zona erbosa\n"
	.string "in cerca di nuovi POKéMON.$"

Route18_Text_WiltonDefeat::
	.string "Tsk!$"

Route18_Text_WiltonPostBattle::
	.string "Come vorrei una BICICLETTA!$"

Route18_Text_RamiroIntro::
	.string "Kurukkoo!\n"
	.string "Ti piace il mio verso?$"

Route18_Text_RamiroDefeat::
	.string "Dovevo darti fastidio!$"

Route18_Text_RamiroPostBattle::
	.string "Nel weekend catturo POKéMON di mare,\n"
	.string "visto che il mare è qui vicino.$"

Route18_Text_JacobIntro::
	.string "Questo è il mio territorio!\n"
	.string "Vattene via!$"

Route18_Text_JacobDefeat::
	.string "Accidenti!$"

Route18_Text_JacobPostBattle::
	.string "Questo è il mio posto preferito per\n"
	.string "catturare POKéMON.$"

Route18_Text_RouteSign::
	.string "PERCORSO 18\n"
	.string "CELADON CITY - FUCHSIA CITY$"

Route18_Text_CyclingRoadSign::
	.string "PISTA CICLABILE\n"
	.string "Vietato ai pedoni!$"

