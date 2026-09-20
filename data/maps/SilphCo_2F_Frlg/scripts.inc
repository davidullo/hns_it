SilphCo_2F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_2F_OnLoad
	.byte 0

SilphCo_2F_OnLoad::
	call_if_unset FLAG_SILPH_2F_DOOR_1, EventScript_Close2FDoor1
	call_if_unset FLAG_SILPH_2F_DOOR_2, EventScript_Close2FDoor2
	end

SilphCo_2F_EventScript_ThunderWaveTutor::
	goto EventScript_ThunderWaveTutor
	end

SilphCo_2F_EventScript_FloorSign::
	msgbox SilphCo_2F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_2F_EventScript_Connor::
	trainerbattle_single TRAINER_SCIENTIST_CONNOR, SilphCo_2F_Text_ConnorIntro, SilphCo_2F_Text_ConnorDefeat
	msgbox SilphCo_2F_Text_ConnorPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_EventScript_Jerry::
	trainerbattle_single TRAINER_SCIENTIST_JERRY, SilphCo_2F_Text_JerryIntro, SilphCo_2F_Text_JerryDefeat
	msgbox SilphCo_2F_Text_JerryPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_23, SilphCo_2F_Text_Grunt1Intro, SilphCo_2F_Text_Grunt1Defeat
	msgbox SilphCo_2F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_24, SilphCo_2F_Text_Grunt2Intro, SilphCo_2F_Text_Grunt2Defeat
	msgbox SilphCo_2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_Text_ConnorIntro::
	.string "Aiuto!\n"
	.string "Sono un impiegato della SILPH.$"

SilphCo_2F_Text_ConnorDefeat::
	.string "Come sapevi\n"
	.string "che ero del ROCKET?$"

SilphCo_2F_Text_ConnorPostBattle::
	.string "Lavoro sia per la SILPH che per il TEAM\n"
	.string "ROCKET.$"

SilphCo_2F_Text_JerryIntro::
	.string "Qui è vietato l'accesso!\n"
	.string "Vattene a casa!$"

SilphCo_2F_Text_JerryDefeat::
	.string "Sei forte.$"

SilphCo_2F_Text_JerryPostBattle::
	.string "Sai risolvere il labirinto qui?\n"
	.string "Non è facile, te lo dico!$"

SilphCo_2F_Text_Grunt1Intro::
	.string "Qui i bambini non entrano!$"

SilphCo_2F_Text_Grunt1Defeat::
	.string "Tosto!$"

SilphCo_2F_Text_Grunt1PostBattle::
	.string "Le mattonelle a forma di rombo sono\n"
	.string "teletrasporti.\p"
	.string "Sono i trasportatori di questo\n"
	.string "edificio high-tech.$"

SilphCo_2F_Text_Grunt2Intro::
	.string "Ehi, ragazzino!\n"
	.string "Cosa ci fai qui in giro?$"

SilphCo_2F_Text_Grunt2Defeat::
	.string "Ho toppato!$"

SilphCo_2F_Text_Grunt2PostBattle::
	.string "La SILPH CO. sarà associata al\n"
	.string "TEAM ROCKET!$"

Text_ThunderWaveTeach::
	.string "Eeek!\n"
	.string "No! Stop! Help!\p"
	.string "Oh, you're not with TEAM ROCKET.\n"
	.string "I'm sorry, I thought…\p"
	.string "Will you forgive me if I teach\n"
	.string "you the THUNDER WAVE technique?$"

Text_ThunderWaveDeclined::
	.string "Oh…\n"
	.string "Ma TUONO è così comoda…$"

Text_ThunderWaveWhichMon::
	.string "A quale POKéMON insegno\n"
	.string "TUONO?$"

Text_ThunderWaveTaught::
	.string "THUNDER WAVE causes paralysis in\n"
	.string "the target POKéMON.\p"
	.string "A paralyzed POKéMON may be unable\n"
	.string "to move in battle.\p"
	.string "It's an ELECTRIC-type move, so it\n"
	.string "won't work on some POKéMON.$"

SilphCo_2F_Text_FloorSign::
	.string "SILPH CO. SEDE CENTRALE\n"
	.string "2F$"

