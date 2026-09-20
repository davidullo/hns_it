BattleFrontier_BattlePalaceLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePalaceLobby_OnWarp
	.byte 0

BattleFrontier_BattlePalaceLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePalaceLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge, MSGBOX_DEFAULT
	closemessage
	palace_set PALACE_DATA_WIN_STREAK, 0
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven
	msgbox BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers, MSGBOX_DEFAULT
BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded
	waitmessage
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded
	waitmessage
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	palace_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge
	message BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge

BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge::
	return

BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting, MSGBOX_DEFAULT
	message BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge
	waitmessage
	palace_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge

BattleFrontier_BattlePalaceLobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant
	end

BattleFrontier_BattlePalaceLobby_EventScript_DoublesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant
	end

BattleFrontier_BattlePalaceLobby_EventScript_Attendant::
	palace_get PALACE_DATA_PRIZE
	goto_if_ne VAR_RESULT, ITEM_NONE, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle
BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_WhichChallenge
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge2, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	palace_init
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePalaceLobby_Text_FollowMe, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_CORRIDOR, 8, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge::
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative LoadPlayerParty
BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge
	return

BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge
	return

BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor
	waitdooranim
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor
	waitdooranim
	return

BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_PALACE_ATTENDANT_SINGLES
	return

BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_PALACE_ATTENDANT_DOUBLES
	return

BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor::
	opendoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor::
	opendoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor::
	closedoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor::
	closedoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor:
	walk_up
	step_end

BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_EventScript_ShowSinglesResults::
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_ShowDoublesResults::
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_BlackBelt::
	msgbox BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Man::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Beauty::
	msgbox BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Maniac::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 16, 0, MULTI_BATTLE_PALACE_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_RulesNature
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves
	case 3, BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered
	case 4, BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger
	case 5, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesNature::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle:
	.string "Qui il cuore degli ALLENATORI\n"
	.string "è messo alla prova.\p"
	.string "Benvenuto nel PALAZZO LOTTA.\p"
	.string "Accetto le sfide SINGOLE di\n"
	.string "SALA LOTTA.$"

BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge:
	.string "Vuoi affrontare\n"
	.string "la SFIDA SINGOLA di SALA LOTTA?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge:
	.string "Nella PALAZZO LOTTA ci sono\n"
	.string "diverse sale per LOTTE SINGOLE\l"
	.string "dette SALA LOTTA SINGOLA.\p"
	.string "Le LOTTE SINGOLE si svolgono\n"
	.string "come al solito, ma con una regola\l"
	.string "essenziale da rispettare.\p"
	.string "Gli ALLENATORI possono solo\n"
	.string "cambiare i loro POKéMON.\p"
	.string "Gli ALLENATORI non possono\n"
	.string "in nessun caso dare ordini.\p"
	.string "I POKéMON agiscono secondo\n"
	.string "la natura e lottano da soli.\p"
	.string "Fidati dei tuoi POKéMON\n"
	.string "e osservali con attenzione.\p"
	.string "Se batti sette ALLENATORI\n"
	.string "di fila, un grande onore,\l"
	.string "riceverai Punti Lotta.\p"
	.string "Se vuoi interrompere la prova\n"
	.string "devi salvare la partita.\p"
	.string "Se non salvi prima di uscire\n"
	.string "sarai squalificato.$"

BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified:
	.string "Quando hai rafforzato il cuore\n"
	.string "e i POKéMON, devi tornare.$"

BattleFrontier_BattlePalaceLobby_Text_WhichChallenge:
	.string "Ci sono due SALE LOTTA,\n"
	.string "Livello 50 e Livello Aperto.\l"
	.string "Quale sfida scegli?$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50:
	.string "Ahimè…\p"
	.string "Ti mancano i tre POKéMON\n"
	.string "necessari alla prova.\p"
	.string "Per entrare servono tre\n"
	.string "POKéMON diversi.\p"
	.string "Devono essere tutti di\n"
	.string "Livello 50 o meno.\p"
	.string "E non devono portare\n"
	.string "gli stessi strumenti.\p"
	.string "UOVA{STR_VAR_1}.$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsEnd:
	.string "Torna quando ti sarai\n"
	.string "preparato.$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Ahimè…\p"
	.string "Ti mancano i tre POKéMON\n"
	.string "necessari alla prova.\p"
	.string "Per entrare servono tre\n"
	.string "POKéMON diversi.\p"
	.string "E non devono portare\n"
	.string "gli stessi strumenti.\p"
	.string "UOVA{STR_VAR_1}.$"

BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons:
	.string "Bene. Ora scegli i tuoi\n"
	.string "tre POKéMON.$"

BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge2:
	.string "Devo salvare prima di portarti\n"
	.string "alla SALA LOTTA. Va bene?$"

BattleFrontier_BattlePalaceLobby_Text_FollowMe:
	.string "Bene.\n"
	.string "Ora seguimi.$"

BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded:
	.string "È stato un onore vedere le\n"
	.string "gesta dei tuoi POKéMON.\p"
	.string "I risultati saranno registrati.\n"
	.string "Ti chiedo di aspettare un attimo.$"

BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak:
	.string "Per vincere 7 volte di fila…\p"
	.string "Il legame che unisce te e i\n"
	.string "tuoi POKéMON è saldo e vero.$"

BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded:
	.string "La tua impresa sarà registrata.\n"
	.string "Ti chiedo di aspettare un attimo.$"

@ Unused
BattleFrontier_BattlePalaceLobby_Text_BattlePointsFor7WinStreak:
	.string "Per la tua serie di 7 vittorie,\n"
	.string "ricevi Punti Lotta.$"

BattleFrontier_BattlePalaceLobby_Text_NoSpaceForPrize:
	.string "Sembra che tu non abbia spazio\n"
	.string "per il premio.\p"
	.string "Torna quando avrai\n"
	.string "sistemato lo ZAINO.$"

BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting:
	.string "Ti aspettavamo…$"

BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge:
	.string "Devo salvare prima di portarti\n"
	.string "alla SALA LOTTA. Va bene?$"

BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge:
	.string "Ahimè…\p"
	.string "Non hai salvato prima di\n"
	.string "concludere la prova scorsa.\p"
	.string "Così la prova è stata\n"
	.string "squalificata. Che peccato.$"

@ Unused
BattleFrontier_BattlePalaceLobby_Text_ReceivedPrize:
	.string "{PLAYER} ha ottenuto\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink:
	.string "Per un tipo Ardita come me,\n"
	.string "i POKéMON Ardita sono il top.\p"
	.string "L'attacco è la miglior difesa!\n"
	.string "Colpire sempre è l'ideale!\p"
	.string "Ma non è di questo che volevo\n"
	.string "parlare.\p"
	.string "Ogni tanto passa di qui\n"
	.string "una ragazza bellissima.\p"
	.string "Dice che sa capire cosa\n"
	.string "pensano i POKéMON.\p"
	.string "Non so se sia vero,\n"
	.string "ma è davvero carina.\p"
	.string "Eh?\n"
	.string "Perché mi guardi così?$"

BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere:
	.string "Hmm…\p"
	.string "Sembra che la natura dei POKéMON\n"
	.string "e le mosse che hanno imparato\l"
	.string "siano la chiave qui.\p"
	.string "Più precisamente, conta quanto\n"
	.string "le mosse si adattano alla\l"
	.string "natura del POKéMON.\p"
	.string "Se il tuo POKéMON è in difficoltà\n"
	.string "e non rende al meglio,\l"
	.string "forse devi vedere quanto\l"
	.string "le mosse gli si addicono.$"

BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms:
	.string "Il mio POKéMON è docile.\p"
	.string "Ma in una SALA LOTTA\n"
	.string "a volte sembra trasformarsi\l"
	.string "in qualcosa di Burbero!\p"
	.string "Fa davvero paura.\n"
	.string "È sconvolgente.$"

BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway:
	.string "Che natura avrà un POKéMON\n"
	.string "che ama indebolire i rivali\l"
	.string "e logorarli piano piano?\p"
	.string "Sarei stupito se fosse FIACCA.\p"
	.string "Ma no, non è possibile.$"

BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle:
	.string "Qui il cuore degli ALLENATORI\n"
	.string "è messo alla prova.\p"
	.string "Benvenuto nel PALAZZO LOTTA.\p"
	.string "Accetto le sfide DOPPIE di\n"
	.string "SALA LOTTA.$"

BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge:
	.string "Vuoi affrontare\n"
	.string "la SFIDA DOPPIA di SALA LOTTA?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge:
	.string "Nella PALAZZO LOTTA ci sono\n"
	.string " diverse sale per LOTTE DOPPIE\l"
	.string " dette SALA LOTTA DOPPIA.\p"
	.string "Le LOTTE DOPPIE si svolgono\n"
	.string "come al solito, ma con una regola\l"
	.string "essenziale da rispettare.\p"
	.string "Gli ALLENATORI possono solo\n"
	.string "cambiare i loro POKéMON.\p"
	.string "Gli ALLENATORI non possono\n"
	.string "in nessun caso dare ordini.\p"
	.string "I POKéMON agiscono secondo\n"
	.string "la natura e lottano da soli.\p"
	.string "Fidati dei tuoi POKéMON\n"
	.string "e osservali con attenzione.\p"
	.string "Se batti sette ALLENATORI\n"
	.string "di fila, un grande onore,\l"
	.string "riceverai Punti Lotta.\p"
	.string "Se vuoi interrompere la prova\n"
	.string "salva prima la partita.\p"
	.string "Se non salvi prima di uscire\n"
	.string "sarai squalificato.$"

BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers:
	.string "Per battere la MAESTRA DEL\n"
	.string "PALAZZO e 7 ALLENATORI…$"

BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints:
	.string "In onore del legame che ti unisce\n"
	.string "ai tuoi POKéMON, ecco in dono\l"
	.string "questi Punti Lotta.$"

BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch:
	.string "Vuoi registrare la tua ultima\n"
	.string "lotta alla PALAZZO LOTTA\l"
	.string "sul PASSA FRONTIERA?$"

BattleFrontier_BattlePalaceLobby_Text_RulesAreListed:
	.string "Ecco le regole della SALA LOTTA.$"

BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading:
	.string "Quale voce vuoi leggere?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics:
	.string "Qui i POKéMON pensano\n"
	.string "e lottano da soli.\p"
	.string "Ma quelli cresciuti con le\n"
	.string "persone si comportano in modo\l"
	.string "diverso per natura.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature:
	.string "Secondo la natura, un POKéMON\n"
	.string "può voler attaccare sempre.\p"
	.string "Un altro può preferire\n"
	.string "proteggersi dai danni.\p"
	.string "Un altro ancora adora\n"
	.string "confondere i nemici.\p"
	.string "Per natura un POKéMON\n"
	.string "ha mosse preferite, che\l"
	.string "usa con abilità.\p"
	.string "Ma può odiarne altre, che\n"
	.string "usa con fatica.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves:
	.string "Ci sono mosse offensive\n"
	.string "che colpiscono il nemico.\p"
	.string "E mosse difensive, per\n"
	.string "prepararsi agli attacchi o\l"
	.string "curare i PS e altro.\p"
	.string "Poi vi sono mosse strane\n"
	.string "che affliggono il nemico con\l"
	.string "problemi come Veleno\l"
	.string "o paralisi.\p"
	.string "I POKéMON scelgono tra\n"
	.string "queste tre categorie.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered:
	.string "Senza gli ordini del suo\n"
	.string "ALLENATORE, un POKéMON può\l"
	.string "non usare bene certe mosse.\p"
	.string "Un POKéMON non riesce mai\n"
	.string "con una mossa che odia.\p"
	.string "Se ha solo mosse diverse\n"
	.string "dalla sua natura, spesso\l"
	.string "non dà il massimo.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger:
	.string "In base alla natura, un POKéMON\n"
	.string "può usare mosse contrarie\l"
	.string "quando è in difficoltà.\p"
	.string "Se un POKéMON si comporta\n"
	.string "male, osservalo bene.$"

