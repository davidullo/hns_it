MagmaHideout_3F_2R_MapScripts::
	.byte 0

MagmaHideout_3F_2R_EventScript_Grunt10::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_10, MagmaHideout_3F_2R_Text_Grunt10Intro, MagmaHideout_3F_2R_Text_Grunt10Defeat
	msgbox MagmaHideout_3F_2R_Text_Grunt10PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_2R_Text_Grunt10Intro:
	.string "Capisco tutto ciò che dice il\n"
	.string "capo. Ma sai una cosa?\p"
	.string "Dissotterrare un POKéMON\n"
	.string "antichissimo e rubare il\l"
	.string "METEORITE a qualcuno…\p"
	.string "Credo che stiamo esagerando.\n"
	.string "Tu che ne pensi?$"

MagmaHideout_3F_2R_Text_Grunt10Defeat:
	.string "Sì, credo che stiamo sbagliando\n"
	.string "qualcosa.$"

MagmaHideout_3F_2R_Text_Grunt10PostBattle:
	.string "Perdere con te mi ha schiarito.\p"
	.string "La prossima volta che vedo il capo\n"
	.string "gli chiederò cosa facciamo.$"

