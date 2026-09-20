SilphCo_10F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_10F_OnLoad
	.byte 0

SilphCo_10F_OnLoad::
	call_if_unset FLAG_SILPH_10F_DOOR, EventScript_Close10FDoor
	end

SilphCo_10F_EventScript_WorkerF::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_10F_EventScript_WorkerFRocketsGone
	msgbox SilphCo_10F_Text_WaaaImScared
	release
	end

SilphCo_10F_EventScript_WorkerFRocketsGone::
	msgbox SilphCo_10F_Text_KeepMeCryingASecret
	release
	end

SilphCo_10F_EventScript_FloorSign::
	msgbox SilphCo_10F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_10F_EventScript_Travis::
	trainerbattle_single TRAINER_SCIENTIST_TRAVIS, SilphCo_10F_Text_TravisIntro, SilphCo_10F_Text_TravisDefeat
	msgbox SilphCo_10F_Text_TravisPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_10F_EventScript_Grunt::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_39, SilphCo_10F_Text_GruntIntro, SilphCo_10F_Text_GruntDefeat
	msgbox SilphCo_10F_Text_GruntPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_10F_Text_GruntIntro::
	.string "Benvenuto al 10P!\n"
	.string "Che bello che tu sia qui!$"

SilphCo_10F_Text_GruntDefeat::
	.string "Sono sbalordito!$"

SilphCo_10F_Text_GruntPostBattle::
	.string "Bel tentativo, ma la sala riunioni è\n"
	.string "un piano più su.$"

SilphCo_10F_Text_TravisIntro::
	.string "Basta con i tuoi giochini!$"

SilphCo_10F_Text_TravisDefeat::
	.string "Niente più vite!$"

SilphCo_10F_Text_TravisPostBattle::
	.string "Sei contento di avermi battuto?\n"
	.string "Allora torna a casa!$"

SilphCo_10F_Text_WaaaImScared::
	.string "Waaaaa!\n"
	.string "Che paura!$"

SilphCo_10F_Text_KeepMeCryingASecret::
	.string "Sul fatto che piangevo…\n"
	.string "Ti prego, tienilo segreto.$"

SilphCo_10F_Text_FloorSign::
	.string "SEDE SILPH SPA\n"
	.string "10P$"

