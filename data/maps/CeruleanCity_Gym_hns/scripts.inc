CeruleanCity_Gym_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeruleanCity_Gym_OnFrame
	.byte 0

CeruleanCity_Gym_OnFrame::
	map_script_2 VAR_KANTO_ROCKET_STORY_STATE, 2,  CeruleanCity_Gym_EventScript_RocketGrunt
	map_script_2 VAR_TEMP_0, 0,  CeruleanCity_Gym_EventScript_TryMachinePart
	.2byte 0

CeruleanCity_Gym_EventScript_RocketGrunt::
	lock
	applymovement LOCALID_CERULEAN_GYM_ROCKET, CeruleanCity_Gym_Movement_GruntBumpPlayer
	delay 20
	playse SE_BANG
	waitmovement 0
	
	msgbox CeruleanGym_Text_GruntIntro, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_CERULEAN_GYM_ROCKET, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_CERULEAN_GYM_ROCKET
	applymovement LOCALID_CERULEAN_GYM_ROCKET, CeruleanCity_Gym_Movement_GruntWalkBack
	waitmovement 0
	msgbox CeruleanGym_Text_GruntBigMistake, MSGBOX_DEFAULT
	applymovement LOCALID_CERULEAN_GYM_ROCKET, CeruleanCity_Gym_Movement_GruntWalkToPlayerAgain
	waitmovement 0
	msgbox CeruleanGym_Text_GruntBye, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CeruleanCity_Gym_Movement_PlayerSlide
	delay 10
	applymovement LOCALID_CERULEAN_GYM_ROCKET, CeruleanCity_Gym_Movement_GruntLeave
	waitmovement 0
	fadescreenswapbuffers FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_CERULEAN_GYM_ROCKET
	removeobject LOCALID_CERULEAN_GYM_ROCKET
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_CERULEAN_CAPE_ROCKET
	setvar VAR_KANTO_ROCKET_STORY_STATE, 3
	release
	end

CeruleanCity_Gym_EventScript_TryMachinePart::
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, CeruleanCity_Gym_EventScript_MachinePart
	setvar VAR_TEMP_0, 1
	end

CeruleanCity_Gym_EventScript_MachinePart::
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, CeruleanCity_Movement_CameraPanUp
	waitmovement 0
	delay 30
	setvar VAR_0x8004, 5  @ x
	setvar VAR_0x8005, 13  @ y
	playse SE_PIN
	call Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle
	delay 55
	applymovement OBJ_EVENT_ID_CAMERA, CeruleanCity_Movement_CameraPanDown
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_TEMP_0, 1
	end

CeruleanCity_Gym_EventScript_MachinePartItem::
	goto_if_lt VAR_KANTO_ROCKET_STORY_STATE, 5, CeruleanCity_Gym_EventScript_DoNothing
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 6, CeruleanCity_Gym_EventScript_DoNothing
	finditem ITEM_MACHINE_PART
	setvar VAR_KANTO_ROCKET_STORY_STATE, 6
	setflag FLAG_HIDDEN_ITEM_MACHINE_PART
	end

CeruleanCity_Gym_EventScript_DoNothing::
	end

CeruleanCity_Movement_CameraPanUp:
	walk_up
	walk_up
	walk_up
	step_end

CeruleanCity_Movement_CameraPanDown:
	walk_down
	walk_down
	walk_down
	step_end

CeruleanCity_Gym_Movement_GruntBumpPlayer:
	walk_fast_down
	walk_fast_down
	walk_in_place_fast_down
	lock_facing_direction
	jump_up
	unlock_facing_direction
	delay_16
	walk_down
	step_end

CeruleanCity_Gym_Movement_GruntWalkBack:
	lock_facing_direction
	walk_slow_up
	walk_slow_up
	unlock_facing_direction
	step_end

CeruleanCity_Gym_Movement_GruntWalkToPlayerAgain:
	walk_down
	walk_down
	step_end

CeruleanCity_Gym_Movement_PlayerSlide:
	lock_facing_direction
	walk_fast_right
	unlock_facing_direction
	step_end

CeruleanCity_Gym_Movement_GruntLeave:
	walk_fast_down
	walk_in_place_fast_down
	step_end

CeruleanCity_Gym_EventScript_Statue::
	lockall
	goto_if_set FLAG_BADGE10_GET, CeruleanCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeruleanCity_Gym_Text_GymStatue
	releaseall
	end

CeruleanCity_Gym_EventScript_StatueDuringRocket::
	msgbox CeruleanGym_Text_Note, MSGBOX_SIGN
	end 

CeruleanCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeruleanCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeruleanGym_EventScript_Diana::
	trainerbattle_single TRAINER_DIANA_HNS, CeruleanGym_Text_SwimmerfDianaSeen, CeruleanGym_Text_SwimmerfDianaBeaten
	msgbox CeruleanGym_Text_SwimmerfDianaAfter, MSGBOX_AUTOCLOSE
	end

CeruleanGym_EventScript_Briana::
	trainerbattle_single TRAINER_BRIANA_HNS, CeruleanGym_Text_SwimmerfBrianaSeen, CeruleanGym_Text_SwimmerfBrianaBeaten
	msgbox CeruleanGym_Text_SwimmerfBrianaAfter, MSGBOX_AUTOCLOSE
	end

CeruleanGym_EventScript_Parker::
	trainerbattle_single TRAINER_PARKER_HNS, CeruleanGym_Text_SwimmermParkerSeen, CeruleanGym_Text_SwimmermParkerBeaten
	msgbox CeruleanGym_Text_SwimmermParkerAfter, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_CERULEAN_GYM, CeruleanCity_Gym_EventScript_GymGuyAfter
	msgbox CeruleanGym_Text_GuideIntro, MSGBOX_NPC
	end

CeruleanCity_Gym_EventScript_GymGuyAfter::
	msgbox CeruleanGym_Text_GuideWin, MSGBOX_NPC
	end

CeruleanCity_Gym_Text_GymStatue::
    .string "PALESTRA CERULEAN\n"
    .string "CAPO: MISTY\p"
	.string "VINCITORI:\n"
	.string "BLU,ROSSO$"

CeruleanCity_Gym_Text_GymStatuePlayerWon::
    .string "PALESTRA CERULEAN\n"
    .string "CAPO: MISTY\p"
    .string "VINCITORI:\n"
	.string "BLU,ROSSO,{PLAYER}$"

CeruleanGym_Text_Note:
	.string "Scusate, sarò via per un po'.\n"
	.string "MISTY, CAPOPALESTRA\p"
	.string "Dato che MISTY è via, anche\n"
	.string "noi.\l"
	.string "ALLENATORI$"


CeruleanCity_Gym_EventScript_Misty::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CERULEAN_GYM, CeruleanCity_Gym_EventScript_Misty_Defeated
	msgbox CeruleanGym_Text_MistyIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MISTY_HNS, CeruleanGym_Text_MistyWinLoss
	message CeruleanGym_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_BADGE10_GET
	setflag FLAG_DEFEATED_CERULEAN_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 10
	call Common_EventScript_SetGymTrainers_hns
	msgbox CeruleanGym_Text_Misty_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_WATER_PULSE
	msgbox CeruleanGym_Text_Misty_ExplainTM, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_CAPE_MISTY
	call_if_eq VAR_SUICUNE_ENCOUNTERS, 5, CeruleanCity_Gym_SetSuicuneScene
	closemessage
	release
	end

CeruleanCity_Gym_SetSuicuneScene::
	setvar VAR_SUICUNE_ENCOUNTERS, 6
	clearflag FLAG_HIDE_ROUTE25_SUICUNE
	return

CeruleanCity_Gym_EventScript_Misty_Defeated::
	msgbox CeruleanGym_Text_MistyFightDone, MSGBOX_DEFAULT
	closemessage
	release
	end

CeruleanGym_Text_GruntIntro:
	.string "Ops! Scusa! Stai bene,\n"
	.string "ok?\p"
	.string "Io molto occupato. Non ho\n"
	.string "tempo per te. Non va bene\l"
	.string "se mi vedono.$"

CeruleanGym_Text_GruntBigMistake:
	.string "Oh no! Mi hai già visto!\n"
	.string "Che errore grande!$"

CeruleanGym_Text_GruntBye:
	.string "Ehi, tu! Non mi hai visto,\n"
	.string "ok?\p"
	.string "Non vedi, non senti, non sai\p"
	.string "ok? Ciao, pupo! Niente!\p"
	.string "Ciao ciao, via!$"

CeruleanGym_Text_Note1:
	.string "Scusate, sarò via per un po'.\n"
	.string "MISTY, CAPOPALESTRA\p"
	.string "Dato che MISTY è via, anche\n"
	.string "noi. ALLENATORI$"

CeruleanGym_Text_MistyIntro:
	.string "MISTY: Ti aspettavo, sai,\n"
	.string "peste!\p"
	.string "Avrai anche molte MEDAGLIE\n"
	.string "di JOHTO, ma non prendermi\l"
	.string "alla leggera.\p"
	.string "I miei POKéMON ACQUA sono\n"
	.string "tosti!$"

CeruleanGym_Text_MistyWinLoss:
	.string "MISTY: Sei davvero forte…\p"
	.string "Ammetto che sei abile…\p"
	.string "Tieni. È la MEDAGLIA CASCATA.$"

CeruleanGym_Text_ReceivedBadge:
	.string "{PLAYER} riceve MEDAGLIA CASCATA.$"

CeruleanGym_Text_MistyFightDone:
	.string "MISTY: Ci sono forti\n"
	.string "ALLENATORI a JOHTO come te,\l"
	.string "dico.\p"
	.string "Un giorno viaggerò, così\n"
	.string "potrò sfidare tanti\l"
	.string "campioni.$"

CeruleanGym_Text_MistyRematch:
	.string "MISTY: Wow, sei CAMPIONE\n"
	.string "di KANTO!\p"
	.string "Fantastico! Hai fatto tanta\n"
	.string "strada, {PLAYER}.\p"
	.string "Ma non mi arrendo.\p"
	.string "Vuoi una rivincita con me?$"

CeruleanGym_Text_MistyRematchDefeat:
	.string "MISTY: Sei davvero forte…$"

CeruleanGym_Text_SwimmerfDianaSeen:
	.string "Scusa l'assenza. Forza,\n"
	.string "iniziamo!$"

CeruleanGym_Text_SwimmerfDianaBeaten:
	.string "Mi arrendo! Hai vinto tu!$"

CeruleanGym_Text_SwimmerfDianaAfter:
	.string "Nuoterò in silenzio.$"

CeruleanGym_Text_SwimmerfBrianaSeen:
	.string "Non lasciarti turbare dal\n"
	.string "mio nuoto.$"

CeruleanGym_Text_SwimmerfBrianaBeaten:
	.string "Ooh, mi hai battuto con calma…$"

CeruleanGym_Text_SwimmerfBrianaAfter:
	.string "Non vantarti troppo di avermi\n"
	.string "battuto.\p"
	.string "MISTY ti distruggerà se ti\n"
	.string "rilassi.$"

CeruleanGym_Text_SwimmermParkerSeen:
	.string "Glub…\p"
	.string "Sono il primo! Provaci!$"

CeruleanGym_Text_SwimmermParkerBeaten:
	.string "Impossibile…$"

CeruleanGym_Text_SwimmermParkerAfter:
	.string "MISTY è molto migliorata in\n"
	.string "questi anni.\p"
	.string "Non abbassare la guardia o\n"
	.string "ti schiaccerà!$"

CeruleanGym_Text_GuideIntro:
	.string "CAMPIONE in erba!\p"
	.string "Con MISTY via, sono uscito\p"
	.string "a divertirmi anch'io. Eh eh eh.$"

CeruleanGym_Text_GuideWin:
	.string "Uau, mi hai mostrato quanto sei\n"
	.string "forte.\p"
	.string "Come sempre, è stata una lotta\n"
	.string "fantastica!$"

CeruleanGym_Text_Misty_GiveTM:
	.string "Tieni anche questo.$"

CeruleanGym_Text_Misty_ExplainTM:
	.string "È la MT IDROPULSAR.\p"
	.string "Infligge danni e a volte\n"
	.string "causa anche confusione!$"
