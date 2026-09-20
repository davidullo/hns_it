MagmaHideout_3F_1R_MapScripts::
	.byte 0

MagmaHideout_3F_1R_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_9, MagmaHideout_3F_1R_Text_Grunt9Intro, MagmaHideout_3F_1R_Text_Grunt9Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt9PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_EventScript_Grunt16::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_16, MagmaHideout_3F_1R_Text_Grunt16Intro, MagmaHideout_3F_1R_Text_Grunt16Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt16PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_Text_Grunt9Intro:
	.string "Cosa ho fatto per meritarmi\n"
	.string "questo turno di guardia?\p"
	.string "Mi brucia l'orecchio sinistro!$"

MagmaHideout_3F_1R_Text_Grunt9Defeat:
	.string "Sto soffrendo il caldo…$"

MagmaHideout_3F_1R_Text_Grunt9PostBattle:
	.string "Ti sembra strano che portiamo\n"
	.string "il cappuccio in un vulcano?$"

MagmaHideout_3F_1R_Text_Grunt16Intro:
	.string "Ci siamo uniti per aiutare il capo\n"
	.string "a realizzare il suo sogno.\p"
	.string "Non m'importa se sei del TEAM AQUA\n"
	.string "o solo un ragazzino di passaggio.\p"
	.string "Nessuno ci intralcia e la passa\n"
	.string "liscia!$"

MagmaHideout_3F_1R_Text_Grunt16Defeat:
	.string "Oh, no!\n"
	.string "Non sei per niente affidabile!$"

MagmaHideout_3F_1R_Text_Grunt16PostBattle:
	.string "Ascoltami.\n"
	.string "Il TEAM MAGMA ha ragione!\p"
	.string "Non dare retta al TEAM AQUA.\n"
	.string "Non credere alle sue bugie!$"

