RocketHideout_B2F_Frlg_MapScripts::
	.byte 0

RocketHideout_B2F_EventScript_Grunt::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_13, RocketHideout_B2F_Text_GruntIntro, RocketHideout_B2F_Text_GruntDefeat
	msgbox RocketHideout_B2F_Text_GruntPostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B2F_Text_GruntIntro::
	.string "Il CAPO dice che vedi i fantasmi\n"
	.string "con lo SPETTROSCOPIO.$"

RocketHideout_B2F_Text_GruntDefeat::
	.string "Mi arrendo!$"

RocketHideout_B2F_Text_GruntPostBattle::
	.string "Il quartier generale del TEAM\n"
	.string "ROCKET ha quattro piani sotterranei.\p"
	.string "Credi di arrivare al CAPO?$"

