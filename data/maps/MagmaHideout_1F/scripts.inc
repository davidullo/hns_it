MagmaHideout_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MagmaHideout_1F_OnTransition
	.byte 0

MagmaHideout_1F_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	end

MagmaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_1, MagmaHideout_1F_Text_Grunt1Intro, MagmaHideout_1F_Text_Grunt1Defeat
	msgbox MagmaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_2, MagmaHideout_1F_Text_Grunt2Intro, MagmaHideout_1F_Text_Grunt2Defeat
	msgbox MagmaHideout_1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_Text_Grunt1Intro:
	.string "Quando il TEAM MAGMA fa l'appello, ci\n"
	.string "assegnano i turni di guardia importanti\l"
	.string "in base all'ordine in cui ci mettiamo.\p"
	.string "Perciò sono bloccato in questo angolo.\n"
	.string "Arrivo sempre tardi all'appello!$"

MagmaHideout_1F_Text_Grunt1Defeat:
	.string "Anch'io arrivo sempre tardi\n"
	.string "agli allenamenti!\p"
	.string "Mi scoccia dirlo, ma sono una frana…$"

MagmaHideout_1F_Text_Grunt1PostBattle:
	.string "Ok, cercherò di metterci un po' più\n"
	.string "di impegno d'ora in poi…$"

MagmaHideout_1F_Text_Grunt2Intro:
	.string "Il nostro capo ci ha detto di scavare\n"
	.string "nel MT. CAMINO, e abbiamo scavato.\p"
	.string "E scavando abbiamo trovato\n"
	.string "una cosa che ci ha sconvolti!\p"
	.string "Cosa abbiamo trovato?\p"
	.string "Fuhahaha!\n"
	.string "Te lo dico se mi batti!$"

MagmaHideout_1F_Text_Grunt2Defeat:
	.string "Argh!\n"
	.string "Battuto!$"

MagmaHideout_1F_Text_Grunt2PostBattle:
	.string "Non te lo dico dopo tutto.\n"
	.string "Lo scoprirai quando arrivi!\p"
	.string "Meglio tenersi le sorprese\n"
	.string "per la fine, no?$"

