SilphCo_7F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_7F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SilphCo_7F_OnTransition
	.byte 0

SilphCo_7F_OnLoad::
	call_if_unset FLAG_SILPH_7F_DOOR_1, EventScript_Close7FDoor1
	call_if_unset FLAG_SILPH_7F_DOOR_2, EventScript_Close7FDoor2
	call_if_unset FLAG_SILPH_7F_DOOR_3, EventScript_Close7FDoor3
	end

SilphCo_7F_OnTransition::
	call_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_SetObjRocketsGone
	end

SilphCo_7F_EventScript_SetObjRocketsGone::
	setobjectmovementtype LOCALID_SILPH_CO_7F_WORKER_M2, MOVEMENT_TYPE_FACE_UP
	return

SilphCo_7F_EventScript_RivalTriggerTop::
	lockall
	setvar VAR_TEMP_1, 0
	goto SilphCo_7F_EventScript_RivalScene
	end

SilphCo_7F_EventScript_RivalTriggerBottom::
	lockall
	setvar VAR_TEMP_1, 1
	goto SilphCo_7F_EventScript_RivalScene
	end

SilphCo_7F_EventScript_RivalScene::
	textcolor NPC_TEXT_COLOR_MALE
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	applymovement LOCALID_SILPH_CO_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_SILPH_CO_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox SilphCo_7F_Text_RivalWhatKeptYou
	call_if_eq VAR_TEMP_1, 0, SilphCo_7F_EventScript_RivalApproachTop
	call_if_eq VAR_TEMP_1, 1, SilphCo_7F_EventScript_RivalApproachBottom
	msgbox SilphCo_7F_Text_RivalIntro
	setvar VAR_LAST_TALKED, LOCALID_SILPH_CO_RIVAL
	call_if_eq VAR_STARTER_MON, 2, SilphCo_7F_EventScript_RivalSquirtle
	call_if_eq VAR_STARTER_MON, 1, SilphCo_7F_EventScript_RivalBulbasaur
	call_if_eq VAR_STARTER_MON, 0, SilphCo_7F_EventScript_RivalCharmander
	msgbox SilphCo_7F_Text_RivalPostBattle
	closemessage
	playbgm MUS_RG_RIVAL_EXIT, 0
	call_if_eq VAR_TEMP_1, 0, SilphCo_7F_EventScript_RivalExitTop
	call_if_eq VAR_TEMP_1, 1, SilphCo_7F_EventScript_RivalExitBottom
	playse SE_WARP_IN
	fadedefaultbgm
	removeobject LOCALID_SILPH_CO_RIVAL
	waitse
	setvar VAR_MAP_SCENE_SILPH_CO_7F, 1
	releaseall
	end

SilphCo_7F_EventScript_RivalApproachTop::
	closemessage
	applymovement LOCALID_SILPH_CO_RIVAL, SilphCo_7F_Movement_RivalApproachTop
	waitmovement 0
	return

SilphCo_7F_EventScript_RivalApproachBottom::
	return

SilphCo_7F_EventScript_RivalSquirtle::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_SQUIRTLE, SilphCo_7F_Text_RivalDefeat
	return

SilphCo_7F_EventScript_RivalBulbasaur::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_BULBASAUR, SilphCo_7F_Text_RivalDefeat
	return

SilphCo_7F_EventScript_RivalCharmander::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_CHARMANDER, SilphCo_7F_Text_RivalDefeat
	return

SilphCo_7F_EventScript_RivalExitTop::
	applymovement LOCALID_SILPH_CO_RIVAL, SilphCo_7F_Movement_RivalExitTop
	waitmovement 0
	return

SilphCo_7F_EventScript_RivalExitBottom::
	applymovement LOCALID_SILPH_CO_RIVAL, SilphCo_7F_Movement_RivalExitBottom
	waitmovement 0
	return

SilphCo_7F_Movement_RivalApproachTop::
	walk_up
	step_end

SilphCo_7F_Movement_RivalExitTop::
	walk_right
	walk_right
	walk_right
	walk_up
	delay_16
	step_end

SilphCo_7F_Movement_RivalExitBottom::
	walk_left
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	delay_16
	step_end

SilphCo_7F_EventScript_LaprasGuy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_LAPRAS_FROM_SILPH, SilphCo_7F_EventScript_AlreadyGotLapras
	msgbox SilphCo_7F_Text_HaveMonForSavingUs
	setvar VAR_TEMP_1, SPECIES_LAPRAS
	givemon SPECIES_LAPRAS, 25
	goto_if_eq VAR_RESULT, 0, SilphCo_7F_EventScript_ReceiveLaprasParty
	goto_if_eq VAR_RESULT, 1, SilphCo_7F_EventScript_ReceiveLaprasPC
	goto_if_eq VAR_RESULT, 2, Common_EventScript_NoMoreRoomForPokemon
	release
	end

SilphCo_7F_EventScript_ReceiveLaprasParty::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message SilphCo_7F_Text_ObtainedLaprasFromEmployee
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_LAPRAS
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SilphCo_7F_EventScript_EndReceiveLapras
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto SilphCo_7F_EventScript_EndReceiveLapras
	end

SilphCo_7F_EventScript_ReceiveLaprasPC::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message SilphCo_7F_Text_ObtainedLaprasFromEmployee
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_LAPRAS
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SilphCo_7F_EventScript_LaprasTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto SilphCo_7F_EventScript_LaprasTransferredToPC
	end

SilphCo_7F_EventScript_LaprasTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto SilphCo_7F_EventScript_EndReceiveLapras
	end

SilphCo_7F_EventScript_EndReceiveLapras::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox SilphCo_7F_Text_ExplainLapras
	setflag FLAG_GOT_LAPRAS_FROM_SILPH
	release
	end

SilphCo_7F_EventScript_AlreadyGotLapras::
	msgbox SilphCo_7F_Text_RocketBossWentToBoardroom
	release
	end

SilphCo_7F_EventScript_WorkerM1::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_WorkerM1RocketsGone
	msgbox SilphCo_7F_Text_RocketsAfterMasterBall
	release
	end

SilphCo_7F_EventScript_WorkerM1RocketsGone::
	msgbox SilphCo_7F_Text_CanceledMasterBallProject
	release
	end

SilphCo_7F_EventScript_WorkerM2::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_WorkerM2RocketsGone
	msgbox SilphCo_7F_Text_BadIfTeamRocketTookOver
	release
	end

SilphCo_7F_EventScript_WorkerM2RocketsGone::
	msgbox SilphCo_7F_Text_WowYouChasedOffTeamRocket
	release
	end

SilphCo_7F_EventScript_WorkerF::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_WorkerFRocketsGone
	msgbox SilphCo_7F_Text_ReallyDangerousHere
	release
	end

SilphCo_7F_EventScript_WorkerFRocketsGone::
	msgbox SilphCo_7F_Text_ThankYouSoMuch
	release
	end

SilphCo_7F_EventScript_FloorSign::
	msgbox SilphCo_7F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_7F_EventScript_Joshua::
	trainerbattle_single TRAINER_SCIENTIST_JOSHUA, SilphCo_7F_Text_JoshuaIntro, SilphCo_7F_Text_JoshuaDefeat
	msgbox SilphCo_7F_Text_JoshuaPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_33, SilphCo_7F_Text_Grunt1Intro, SilphCo_7F_Text_Grunt1Defeat
	msgbox SilphCo_7F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_34, SilphCo_7F_Text_Grunt2Intro, SilphCo_7F_Text_Grunt2Defeat
	msgbox SilphCo_7F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_35, SilphCo_7F_Text_Grunt3Intro, SilphCo_7F_Text_Grunt3Defeat
	msgbox SilphCo_7F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_Text_HaveMonForSavingUs::
	.string "Oh! Ciao! Non sei un ROCKET!\n"
	.string "Sei venuto a salvarci?\l"
	.string "Ma grazie!\p"
	.string "Voglio regalarti questo POKéMON\n"
	.string "per averci salvato.$"

SilphCo_7F_Text_ObtainedLaprasFromEmployee::
	.string "{PLAYER} riceve un LAPRAS dal\n"
	.string "dipendente SILPH!$"

SilphCo_7F_Text_ExplainLapras::
	.string "È un LAPRAS.\n"
	.string "È un POKéMON molto intelligente.\p"
	.string "Lo tenevamo in laboratorio, ma starà\n"
	.string "molto meglio con te.\p"
	.string "Penso che sarai un bravo ALLENATORE\n"
	.string "per LAPRAS!\p"
	.string "È un abile nuotatore.\n"
	.string "Ti porterà sopra le acque!$"

SilphCo_7F_Text_RocketBossWentToBoardroom::
	.string "Il CAPO del TEAM ROCKET è andato\n"
	.string "in sala riunioni!\p"
	.string "Il nostro PRESIDENTE starà bene?\n"
	.string "Sono in pensiero.$"

SilphCo_7F_Text_RocketsAfterMasterBall::
	.string "Il TEAM ROCKET cercava la MASTER\n"
	.string "BALL, che cattura qualsiasi POKéMON.$"

SilphCo_7F_Text_CanceledMasterBallProject::
	.string "Abbiamo annullato il progetto\n"
	.string "MASTER BALL per colpa del TEAM ROCKET.$"

SilphCo_7F_Text_BadIfTeamRocketTookOver::
	.string "Sarebbe un guaio se il TEAM ROCKET\n"
	.string "prendesse la SILPH o i POKéMON.$"

SilphCo_7F_Text_WowYouChasedOffTeamRocket::
	.string "Wow!\p"
	.string "Hai scacciato il TEAM ROCKET\n"
	.string "tutto da solo?$"

SilphCo_7F_Text_ReallyDangerousHere::
	.string "Tu!\n"
	.string "Qui è molto pericoloso!\p"
	.string "Sei venuto a salvarmi?\n"
	.string "Non puoi!$"

SilphCo_7F_Text_ThankYouSoMuch::
	.string "Grazie infinite!$"

SilphCo_7F_Text_Grunt3Intro::
	.string "Uh-oh!\n"
	.string "Sento odore di topolino!$"

SilphCo_7F_Text_Grunt3Defeat::
	.string "Luci spente!$"

SilphCo_7F_Text_Grunt3PostBattle::
	.string "Non troverai il mio CAPO andando\n"
	.string "in giro a curiosare!$"

SilphCo_7F_Text_JoshuaIntro::
	.string "Eh eh!\p"
	.string "Mi hai preso per un dipendente SILPH?$"

SilphCo_7F_Text_JoshuaDefeat::
	.string "Ho finito!$"

SilphCo_7F_Text_JoshuaPostBattle::
	.string "Nonostante l'età, sei un\n"
	.string "ALLENATORE abile!$"

SilphCo_7F_Text_Grunt1Intro::
	.string "Sono uno dei quattro FRATELLI\n"
	.string "ROCKET!$"

SilphCo_7F_Text_Grunt1Defeat::
	.string "Ahia!\n"
	.string "Fratelli, ho perso!$"

SilphCo_7F_Text_Grunt1PostBattle::
	.string "Non importa.\n"
	.string "I miei fratelli me la faranno pagare!$"

SilphCo_7F_Text_Grunt2Intro::
	.string "Un bimbo intruso?\n"
	.string "Devi essere tu!$"

SilphCo_7F_Text_Grunt2Defeat::
	.string "Bene!\n"
	.string "Ho perso!$"

SilphCo_7F_Text_Grunt2PostBattle::
	.string "Vai a casa prima che il CAPO si\n"
	.string "arrabbi!$"

SilphCo_7F_Text_RivalWhatKeptYou::
	.string "{RIVAL}: Cosa ti ha trattenuto, {PLAYER}?$"

SilphCo_7F_Text_RivalIntro::
	.string "{RIVAL}: Ahahah! Sapevo che\n"
	.string "saresti passato di qui!\p"
	.string "Il TEAM ROCKET deve averti\n"
	.string "rallentato! Non che mi importi!\p"
	.string "Ti ho visto ad ZAFFERANO, così ho\n"
	.string "voluto vedere se eri migliorato!$"

SilphCo_7F_Text_RivalDefeat::
	.string "Oh, cavoli!\n"
	.string "Allora sei pronto per il CAPO\l"
	.string "ROCKET!$"

SilphCo_7F_Text_RivalPostBattle::
	.string "Beh, {PLAYER}!\n"
	.string "Sto andando sempre più su!\p"
	.string "Controllando il POKéDEX, inizio\n"
	.string "a capire chi è forte e\l"
	.string "come si evolve!\p"
	.string "Sono un genio o no?\p"
	.string "Vado alla LEGA POKéMON a\n"
	.string "cacciare i SUPERQUATTRO.\p"
	.string "Diventerò l'ALLENATORE più\n"
	.string "forte del mondo!\p"
	.string "{PLAYER}, beh, buona fortuna!\n"
	.string "Non ti preoccupare!\l"
	.string "Ci sentiamo!$"

SilphCo_7F_Text_FloorSign::
	.string "SILPH SPA. SEDE CENTRALE\n"
	.string "7P$"

