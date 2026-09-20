MagmaHideout_2F_2R_MapScripts::
	.byte 0

MagmaHideout_2F_2R_EventScript_Grunt15::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_15, MagmaHideout_2F_2R_Text_Grunt15Intro, MagmaHideout_2F_2R_Text_Grunt15Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt15PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_6, MagmaHideout_2F_2R_Text_Grunt6Intro, MagmaHideout_2F_2R_Text_Grunt6Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_7, MagmaHideout_2F_2R_Text_Grunt7Intro, MagmaHideout_2F_2R_Text_Grunt7Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt7PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_8, MagmaHideout_2F_2R_Text_Grunt8Intro, MagmaHideout_2F_2R_Text_Grunt8Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_Text_Grunt15Intro:
	.string "Non ce l'ho con te.\n"
	.string "Eseguo solo gli ordini!$"

MagmaHideout_2F_2R_Text_Grunt15Defeat:
	.string "Ho perso, ma…$"

MagmaHideout_2F_2R_Text_Grunt15PostBattle:
	.string "Abbiamo dissotterrato qualcosa!\n"
	.string "E abbiamo la SFERA BLU!\p"
	.string "Ora resta solo il capo e…\n"
	.string "Fufufu… Fwahahaha!$"

MagmaHideout_2F_2R_Text_Grunt6Intro:
	.string "Non sopporto il caldo. Potevo\n"
	.string "entrare nel TEAM AQUA…$"

MagmaHideout_2F_2R_Text_Grunt6Defeat:
	.string "Sì, forse non sono adatto\n"
	.string "al TEAM MAGMA…$"

MagmaHideout_2F_2R_Text_Grunt6PostBattle:
	.string "Non ti manca il mare\n"
	.string "in un posto così?$"

MagmaHideout_2F_2R_Text_Grunt7Intro:
	.string "A volte si sentono dei tremori.\p"
	.string "Sarà il vulcano che trema?\n"
	.string "O è GROU…\p"
	.string "Ops!\n"
	.string "No, no, niente!$"

MagmaHideout_2F_2R_Text_Grunt7Defeat:
	.string "Sei un lottatore ardente.\n"
	.string "Come un vulcano!$"

MagmaHideout_2F_2R_Text_Grunt7PostBattle:
	.string "Hai vinto solo per caso,\n"
	.string "ma non importa.\p"
	.string "L'obiettivo del TEAM MAGMA è\n"
	.string "vicino!$"

MagmaHideout_2F_2R_Text_Grunt8Intro:
	.string "Un nostro compagno era disperato\n"
	.string "perché ha perso l'EMBLEMA MAGMA…\p"
	.string "Un momento!\n"
	.string "L'hai trovato tu?$"

MagmaHideout_2F_2R_Text_Grunt8Defeat:
	.string "Faccio fatica a crederci…$"

MagmaHideout_2F_2R_Text_Grunt8PostBattle:
	.string "Ho la sensazione che il piano\n"
	.string "finirà male…$"

