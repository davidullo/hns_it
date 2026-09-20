SilphCo_3F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_3F_OnLoad
	.byte 0

SilphCo_3F_OnLoad::
	call_if_unset FLAG_SILPH_3F_DOOR_1, EventScript_Close3FDoor1
	call_if_unset FLAG_SILPH_3F_DOOR_2, EventScript_Close3FDoor2
	end

SilphCo_3F_EventScript_WorkerM::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_3F_EventScript_WorkerMRocketsGone
	msgbox SilphCo_3F_Text_WhatAmIToDo
	release
	end

SilphCo_3F_EventScript_WorkerMRocketsGone::
	msgbox SilphCo_3F_Text_YouAndYourMonsSavedUs
	release
	end

SilphCo_3F_EventScript_FloorSign::
	msgbox SilphCo_3F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_3F_EventScript_Jose::
	trainerbattle_single TRAINER_SCIENTIST_JOSE, SilphCo_3F_Text_JoseIntro, SilphCo_3F_Text_JoseDefeat
	msgbox SilphCo_3F_Text_JosePostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_3F_EventScript_Grunt::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_25, SilphCo_3F_Text_GruntIntro, SilphCo_3F_Text_GruntDefeat
	msgbox SilphCo_3F_Text_GruntPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_3F_Text_WhatAmIToDo::
	.string "Lavoro per la SILPH CO.\n"
	.string "Che cosa devo fare?$"

SilphCo_3F_Text_YouAndYourMonsSavedUs::
	.string "{PLAYER}!\n"
	.string "Tu e i tuoi POKéMON ci avete salvati!$"

SilphCo_3F_Text_GruntIntro::
	.string "Smettila di intrometterti, ragazzino!$"

SilphCo_3F_Text_GruntDefeat::
	.string "Mi arrendo!$"

SilphCo_3F_Text_GruntPostBattle::
	.string "Un indizio? Puoi aprire le porte con\n"
	.string "una CHIAVE MAGNETICA!$"

SilphCo_3F_Text_JoseIntro::
	.string "Sto dalla parte del TEAM ROCKET più\n"
	.string "che della SILPH CO.!$"

SilphCo_3F_Text_JoseDefeat::
	.string "Mi hai battuto davvero!$"

SilphCo_3F_Text_JosePostBattle::
	.string "Umph…\p"
	.string "Il TEAM ROCKET diceva che se li\n"
	.string "avessi aiutati, avrei studiato i POKéMON.$"

SilphCo_3F_Text_FloorSign::
	.string "SILPH CO. SEDE CENTRALE\n"
	.string "3F$"

