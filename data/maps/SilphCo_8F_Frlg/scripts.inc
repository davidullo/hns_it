SilphCo_8F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_8F_OnLoad
	.byte 0

SilphCo_8F_OnLoad::
	call_if_unset FLAG_SILPH_8F_DOOR, EventScript_Close8FDoor
	end

SilphCo_8F_EventScript_WorkerM::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_8F_EventScript_WorkerMRocketsGone
	msgbox SilphCo_8F_Text_WonderIfSilphIsFinished
	release
	end

SilphCo_8F_EventScript_WorkerMRocketsGone::
	msgbox SilphCo_8F_Text_ThanksForSavingUs
	release
	end

SilphCo_8F_EventScript_FloorSign::
	msgbox SilphCo_8F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_8F_EventScript_Parker::
	trainerbattle_single TRAINER_SCIENTIST_PARKER, SilphCo_8F_Text_ParkerIntro, SilphCo_8F_Text_ParkerDefeat
	msgbox SilphCo_8F_Text_ParkerPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_8F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_32, SilphCo_8F_Text_Grunt1Intro, SilphCo_8F_Text_Grunt1Defeat
	msgbox SilphCo_8F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_8F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_36, SilphCo_8F_Text_Grunt2Intro, SilphCo_8F_Text_Grunt2Defeat
	msgbox SilphCo_8F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_8F_Text_WonderIfSilphIsFinished::
	.string "Chissà se la SILPH è finita…$"

SilphCo_8F_Text_ThanksForSavingUs::
	.string "Grazie per averci salvati!$"

SilphCo_8F_Text_Grunt1Intro::
	.string "Fin qui puoi arrivare!$"

SilphCo_8F_Text_Grunt1Defeat::
	.string "Non ne hai la stoffa!$"

SilphCo_8F_Text_Grunt1PostBattle::
	.string "Se non torni indietro…\n"
	.string "chiamerò i rinforzi!$"

SilphCo_8F_Text_ParkerIntro::
	.string "Ci stai creando problemi!$"

SilphCo_8F_Text_ParkerDefeat::
	.string "Eh?\n"
	.string "Ho perso?$"

SilphCo_8F_Text_ParkerPostBattle::
	.string "Allora? Che ne pensi del\n"
	.string "labirinto della SILPH?$"

SilphCo_8F_Text_Grunt2Intro::
	.string "Sono uno dei quattro FRATELLI\n"
	.string "ROCKET!$"

SilphCo_8F_Text_Grunt2Defeat::
	.string "Whoo!\n"
	.string "Oh, fratelli!$"

SilphCo_8F_Text_Grunt2PostBattle::
	.string "Ci penseranno i miei fratelli.$"

SilphCo_8F_Text_FloorSign::
	.string "SILPH SPA. SEDE CENTRALE\n"
	.string "8P$"

SilphCo_8F_Text_ToRocketBossMonsAreTools::
	.string "Il CAPO del TEAM ROCKET è\n"
	.string "sanguinario!\p"
	.string "Per lui i POKéMON sono solo\n"
	.string "strumenti.\p"
	.string "Cosa succederà se quel tiranno\n"
	.string "si prende la nostra azienda…$"
