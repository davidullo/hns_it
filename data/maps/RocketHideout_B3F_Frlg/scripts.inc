RocketHideout_B3F_Frlg_MapScripts::
	.byte 0

RocketHideout_B3F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_14, RocketHideout_B3F_Text_Grunt1Intro, RocketHideout_B3F_Text_Grunt1Defeat
	msgbox RocketHideout_B3F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B3F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_15, RocketHideout_B3F_Text_Grunt2Intro, RocketHideout_B3F_Text_Grunt2Defeat
	msgbox RocketHideout_B3F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B3F_Text_Grunt1Intro::
	.string "Smettila di immischiarti negli\n"
	.string "affari del TEAM ROCKET, o guai a te!$"

RocketHideout_B3F_Text_Grunt1Defeat::
	.string "Uff!\n"
	.string "Battuto!$"

RocketHideout_B3F_Text_Grunt1PostBattle::
	.string "SILPH SCOPE?\n"
	.string "Ah, la macchina che ha rubato il CAPO.\p"
	.string "È qui da qualche parte.$"

RocketHideout_B3F_Text_Grunt2Intro::
	.string "Ci hanno avvisato da sopra che\n"
	.string "stavi arrivando!$"

RocketHideout_B3F_Text_Grunt2Defeat::
	.string "Come?\n"
	.string "Ho perso? No!$"

RocketHideout_B3F_Text_Grunt2PostBattle::
	.string "Vai pure avanti!\p"
	.string "Ma non puoi usare l'ascensore\n"
	.string "senza la CHIAVE ASCENSORE.$"

