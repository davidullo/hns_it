AquaHideout_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B2F_OnTransition
	.byte 0

AquaHideout_B2F_OnTransition:
	call_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_B2F_EventScript_PreventMattNoticing
	end

AquaHideout_B2F_EventScript_PreventMattNoticing::
	setvar VAR_TEMP_1, 1
	return

AquaHideout_B2F_EventScript_MattNoticePlayer::
	lockall
	setvar VAR_0x8008, LOCALID_AQUA_HIDEOUT_MATT
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_TEMP_1, 1
	releaseall
	end

AquaHideout_B2F_EventScript_Matt::
	trainerbattle_single TRAINER_MATT, AquaHideout_B2F_Text_MattIntro, AquaHideout_B2F_Text_MattDefeat, AquaHideout_B2F_EventScript_SubmarineEscape
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_SubmarineEscape::
	setvar VAR_0x8008, LOCALID_AQUA_HIDEOUT_MATT
	setvar VAR_0x8009, LOCALID_AQUA_HIDEOUT_SUBMARINE
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_OurBossGotThroughHisPreparations, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	applymovement VAR_0x8009, AquaHideout_B2F_Movement_SumbarineDepartLeft
	waitmovement 0
	removeobject VAR_0x8009
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
	setflag FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS
	release
	end

AquaHideout_B2F_Movement_SumbarineDepartLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@ Unused
AquaHideout_B2F_Movement_SumbarineDepartRight:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

AquaHideout_B2F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_4, AquaHideout_B2F_Text_Grunt4Intro, AquaHideout_B2F_Text_Grunt4Defeat, AquaHideout_B2F_EventScript_Grunt4Defeated
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt4Defeated::
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_6, AquaHideout_B2F_Text_Grunt6Intro, AquaHideout_B2F_Text_Grunt6Defeat
	msgbox AquaHideout_B2F_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_8, AquaHideout_B2F_Text_Grunt8Intro, AquaHideout_B2F_Text_Grunt8Defeat
	msgbox AquaHideout_B2F_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_Text_MattIntro:
	.string "Hehehe…\p"
	.string "Sei già arrivato fin qui?\n"
	.string "Ti abbiamo sottostimato!\p"
	.string "Ma ora basta!\p"
	.string "Sono superiore alle RECLUTE che\n"
	.string "hai visto finora.\p"
	.string "Non sto perdendo tempo.\n"
	.string "Ti polverizzerò!$"

AquaHideout_B2F_Text_MattDefeat:
	.string "Hehehe…\n"
	.string "Anch'io ho perso…$"

AquaHideout_B2F_Text_OurBossGotThroughHisPreparations:
	.string "Hehehe!\p"
	.string "Mentre ti tenevo occupato, il nostro\n"
	.string "CAPO ha finito i preparativi!$"

AquaHideout_B2F_Text_MattPostBattle:
	.string "Hehehe!\p"
	.string "Il nostro BOSS e' gia' partito per\n"
	.string "una grotta sotto il mare!\p"
	.string "Se vuoi inseguirlo, fatti\n"
	.string "trovare nel mare in fondo a\l"
	.string "LILYCOVE.\p"
	.string "Ma lo troverai mai?\n"
	.string "Hehehe!$"

AquaHideout_B2F_Text_Grunt4Intro:
	.string "Wahahah, aspettare mi annoia!\n"
	.string "Dev'essere una lotta pure tua!$"

AquaHideout_B2F_Text_Grunt4Defeat:
	.string "Stanco di aspettare…\n"
	.string "Perso e stordito…$"

AquaHideout_B2F_Text_Grunt4PostBattle:
	.string "CAPP…\n"
	.string "Può andar bene così?$"

AquaHideout_B2F_Text_Grunt6Intro:
	.string "I pannelli trasporto, l'orgoglio\n"
	.string "del RIFUGIO!\p"
	.string "Non hai idea di dove sei,\n"
	.string "vero?\p"
	.string "Stancare il nemico e poi\n"
	.string "colpirlo! È il nostro piano!$"

AquaHideout_B2F_Text_Grunt6Defeat:
	.string "Ma che c'è?\n"
	.string "Non sei per niente stanco!$"

AquaHideout_B2F_Text_Grunt6PostBattle:
	.string "A proposito… non ricordo dove\n"
	.string "ho messo la MASTER BALL.\p"
	.string "Se non la guasto bene, il CAPO\n"
	.string "mi sgrida…$"

AquaHideout_B2F_Text_Grunt8Intro:
	.string "Quando sono entrato nel TEAM\n"
	.string "ACQUA, ho dovuto imparare subito\l"
	.string "come son collegati i pannelli.$"

AquaHideout_B2F_Text_Grunt8Defeat:
	.string "Ero preso a pensare\n"
	.string "ai pannelli teletrasporto…$"

AquaHideout_B2F_Text_Grunt8PostBattle:
	.string "Devo imparare a lottare\n"
	.string "più efficacemente…$"
