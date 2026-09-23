SilphCo_4F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_4F_OnLoad
	.byte 0

SilphCo_4F_OnLoad::
	call_if_unset FLAG_SILPH_4F_DOOR_1, EventScript_Close4FDoor1
	call_if_unset FLAG_SILPH_4F_DOOR_2, EventScript_Close4FDoor2
	end

SilphCo_4F_EventScript_WorkerM::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_4F_EventScript_WorkerMRocketsGone
	msgbox SilphCo_4F_Text_CantYouSeeImHiding
	release
	end

SilphCo_4F_EventScript_WorkerMRocketsGone::
	msgbox SilphCo_4F_Text_TeamRocketIsGone
	release
	end

SilphCo_4F_EventScript_FloorSign::
	msgbox SilphCo_4F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_4F_EventScript_Rodney::
	trainerbattle_single TRAINER_SCIENTIST_RODNEY, SilphCo_4F_Text_RodneyIntro, SilphCo_4F_Text_RodneyDefeat
	msgbox SilphCo_4F_Text_RodneyPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_4F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_26, SilphCo_4F_Text_Grunt1Intro, SilphCo_4F_Text_Grunt1Defeat
	msgbox SilphCo_4F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_4F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_27, SilphCo_4F_Text_Grunt2Intro, SilphCo_4F_Text_Grunt2Defeat
	msgbox SilphCo_4F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_4F_Text_CantYouSeeImHiding::
	.string "Sssh!\n"
	.string "Non vedi che mi sto nascondendo?$"

SilphCo_4F_Text_TeamRocketIsGone::
	.string "Eh?\n"
	.string "Il TEAM ROCKET se n'è andato?$"

SilphCo_4F_Text_Grunt1Intro::
	.string "Il TEAM ROCKET ha preso il\n"
	.string "controllo della SILPH CO.!$"

SilphCo_4F_Text_Grunt1Defeat::
	.string "Argh!$"

SilphCo_4F_Text_Grunt1PostBattle::
	.string "Fwahahaha!\n"
	.string "Il mio CAPO dà la caccia a questo posto!$"

SilphCo_4F_Text_RodneyIntro::
	.string "I miei POKéMON mi servono fedelmente.$"

SilphCo_4F_Text_RodneyDefeat::
	.string "Accidenti!\n"
	.string "Che POKéMON deboli!$"

SilphCo_4F_Text_RodneyPostBattle::
	.string "Le porte sono chiuse\n"
	.string "elettronicamente.\p"
	.string "Serve una CARD KEY per aprire le\n"
	.string "porte qui.$"

SilphCo_4F_Text_Grunt2Intro::
	.string "Intruso avvistato!$"

SilphCo_4F_Text_Grunt2Defeat::
	.string "Chi sei?$"

SilphCo_4F_Text_Grunt2PostBattle::
	.string "Meglio avvisare il CAPO all'11F!$"

SilphCo_4F_Text_FloorSign::
	.string "SEDE SILPH CO.\n"
	.string "4P$"

