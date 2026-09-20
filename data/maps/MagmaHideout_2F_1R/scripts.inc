MagmaHideout_2F_1R_MapScripts::
	.byte 0

MagmaHideout_2F_1R_EventScript_Grunt14::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_14, MagmaHideout_2F_1R_Text_Grunt14Intro, MagmaHideout_2F_1R_Text_Grunt14Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt14PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_3, MagmaHideout_2F_1R_Text_Grunt3Intro, MagmaHideout_2F_1R_Text_Grunt3Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_4, MagmaHideout_2F_1R_Text_Grunt4Intro, MagmaHideout_2F_1R_Text_Grunt4Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_5, MagmaHideout_2F_1R_Text_Grunt5Intro, MagmaHideout_2F_1R_Text_Grunt5Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_Text_Grunt14Intro:
	.string "Cosa, cosa, cosa?\p"
	.string "Solo i membri del TEAM MAGMA\n"
	.string "possono stare qui!\p"
	.string "Ma tu non hai la divisa del\n"
	.string "TEAM MAGMA…\p"
	.string "Mi insospettisci!\n"
	.string "Lottiamo!$"

MagmaHideout_2F_1R_Text_Grunt14Defeat:
	.string "Ahiahi…\n"
	.string "Il mio orgoglio di membro del TEAM MAGMA…$"

MagmaHideout_2F_1R_Text_Grunt14PostBattle:
	.string "Se soffri il freddo, dovresti\n"
	.string "unirti al TEAM MAGMA.$"

MagmaHideout_2F_1R_Text_Grunt3Intro:
	.string "Fermo lì!\p"
	.string "Credi che stia zitto e ti lasci\n"
	.string "passare come se niente fosse?$"

MagmaHideout_2F_1R_Text_Grunt3Defeat:
	.string "Oooh!\n"
	.string "Mi arrendo!$"

MagmaHideout_2F_1R_Text_Grunt3PostBattle:
	.string "Forse era meglio se ti lasciavo\n"
	.string "passare senza sfidarti…$"

MagmaHideout_2F_1R_Text_Grunt4Intro:
	.string "Ahah!\n"
	.string "Un intruso!$"

MagmaHideout_2F_1R_Text_Grunt4Defeat:
	.string "Grrraah!$"

MagmaHideout_2F_1R_Text_Grunt4PostBattle:
	.string "Ho già perso.\p"
	.string "Devo davvero continuare a\n"
	.string "girare in tondo?$"

MagmaHideout_2F_1R_Text_Grunt5Intro:
	.string "Oh, oh!\n"
	.string "Un intruso!$"

MagmaHideout_2F_1R_Text_Grunt5Defeat:
	.string "Mmmh…$"

MagmaHideout_2F_1R_Text_Grunt5PostBattle:
	.string "In realtà non sono un esperto…$"

