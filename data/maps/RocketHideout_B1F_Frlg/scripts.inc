RocketHideout_B1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RocketHideout_B1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, RocketHideout_B1F_OnTransition
	.byte 0

RocketHideout_B1F_OnLoad::
	call_if_not_defeated TRAINER_TEAM_ROCKET_GRUNT_12 RocketHideout_B1F_EventScript_SetBarrier
	end

RocketHideout_B1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_ROCKET_HIDEOUT_B1F
	end

RocketHideout_B1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_8, RocketHideout_B1F_Text_Grunt1Intro, RocketHideout_B1F_Text_Grunt1Defeat
	msgbox RocketHideout_B1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_9, RocketHideout_B1F_Text_Grunt2Intro, RocketHideout_B1F_Text_Grunt2Defeat
	msgbox RocketHideout_B1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B1F_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_10, RocketHideout_B1F_Text_Grunt3Intro, RocketHideout_B1F_Text_Grunt3Defeat
	msgbox RocketHideout_B1F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_11, RocketHideout_B1F_Text_Grunt4Intro, RocketHideout_B1F_Text_Grunt4Defeat
	msgbox RocketHideout_B1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B1F_EventScript_Grunt5::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_12, RocketHideout_B1F_Text_Grunt5Intro, RocketHideout_B1F_Text_Grunt5Defeat, RocketHideout_B1F_EventScript_DefeatedGrunt5
	msgbox RocketHideout_B1F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B1F_EventScript_DefeatedGrunt5::
	call RocketHideout_B1F_EventScript_RemoveBarrier
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	release
	end

RocketHideout_B1F_EventScript_SetBarrier::
	setmetatile 20, 19, METATILE_SilphCo_HideoutBarrier_TopLeft_Floor, 1
	setmetatile 21, 19, METATILE_SilphCo_HideoutBarrier_TopRight_Floor, 1
	setmetatile 20, 20, METATILE_SilphCo_HideoutBarrier_BottomLeft, 1
	setmetatile 21, 20, METATILE_SilphCo_HideoutBarrier_BottomRight, 1
	setmetatile 20, 21, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 21, 21, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	return

RocketHideout_B1F_EventScript_RemoveBarrier::
	setmetatile 20, 19, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 21, 19, METATILE_SilphCo_HideoutFloor, 0
	setmetatile 20, 20, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 21, 20, METATILE_SilphCo_HideoutFloor, 0
	setmetatile 20, 21, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 21, 21, METATILE_SilphCo_HideoutFloor, 0
	return

RocketHideout_B1F_Text_Grunt1Intro::
	.string "Chi sei?\n"
	.string "Come sei arrivato qui?$"

RocketHideout_B1F_Text_Grunt1Defeat::
	.string "Ahia!\n"
	.string "Battuto!$"

RocketHideout_B1F_Text_Grunt1PostBattle::
	.string "Accidenti… stai sfidando il TEAM\n"
	.string "ROCKET, vero?$"

RocketHideout_B1F_Text_Grunt2Intro::
	.string "Hai scoperto il covo del TEAM\n"
	.string "ROCKET? Che faccia tosta!$"

RocketHideout_B1F_Text_Grunt2Defeat::
	.string "Boom!$"

RocketHideout_B1F_Text_Grunt2PostBattle::
	.string "Non la passerai liscia,\n"
	.string "monello!$"

RocketHideout_B1F_Text_Grunt3Intro::
	.string "Allarme intruso!$"

RocketHideout_B1F_Text_Grunt3Defeat::
	.string "Non ce la faccio!$"

RocketHideout_B1F_Text_Grunt3PostBattle::
	.string "Lo SPETTROSCOPIO? Umpf!\n"
	.string "Non so dove sia.$"

RocketHideout_B1F_Text_Grunt4Intro::
	.string "Perché sei venuto qui?$"

RocketHideout_B1F_Text_Grunt4Defeat::
	.string "Così non va!$"

RocketHideout_B1F_Text_Grunt4PostBattle::
	.string "Ok, parlerò…\n"
	.string "Prendi l'ascensore per il CAPO.$"

RocketHideout_B1F_Text_Grunt5Intro::
	.string "Ti sei perso, topolino?$"

RocketHideout_B1F_Text_Grunt5Defeat::
	.string "Perché…?$"

RocketHideout_B1F_Text_Grunt5PostBattle::
	.string "Ops, il trambusto ha aperto\n"
	.string "la porta!$"

