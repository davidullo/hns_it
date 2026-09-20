BattleFrontier_BattleDomeLobby_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleDomeLobby_OnResume_hns
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomeLobby_OnFrame_hns
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp_hns
	.byte 0

BattleFrontier_BattleDomeLobby_OnResume_hns:
	dome_initresultstree
	end

BattleFrontier_BattleDomeLobby_OnWarp_hns:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleDomeLobby_EventScript_TurnPlayerNorth_hns
	.2byte 0

BattleFrontier_BattleDomeLobby_EventScript_TurnPlayerNorth_hns::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleDomeLobby_OnFrame_hns:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleDomeLobby_EventScript_GetChallengeStatus_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleDomeLobby_EventScript_QuitWithoutSaving_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleDomeLobby_EventScript_ResumeChallenge_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleDomeLobby_EventScript_WonChallenge_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleDomeLobby_EventScript_LostChallenge_hns
	.2byte 0

BattleFrontier_BattleDomeLobby_EventScript_GetChallengeStatus_hns::
	frontier_getstatus
	end

BattleFrontier_BattleDomeLobby_EventScript_QuitWithoutSaving_hns::
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_DidntSaveBeforeQuitting_hns, MSGBOX_DEFAULT
	closemessage
	dome_set DOME_DATA_WIN_STREAK, 0
	dome_set DOME_DATA_WIN_STREAK_ACTIVE, FALSE
	dome_set DOME_DATA_ATTEMPTED_CHALLENGE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_WonChallenge_hns::
	call BattleFrontier_EventScript_IncrementWinStreak
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleDomeLobby_EventScript_DefeatedAce_hns
	msgbox BattleFrontier_BattleDomeLobby_Text_CongratsForWinningTourney_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_GiveBattlePoints_hns

BattleFrontier_BattleDomeLobby_EventScript_DefeatedAce_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_CongratsDefeatedTucker_hns, MSGBOX_DEFAULT
BattleFrontier_BattleDomeLobby_EventScript_GiveBattlePoints_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_AwardTheseBattlePoints_hns, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleDomeLobby_Text_RecordWillBeSaved_hns
	waitmessage
	special LoadPlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	frontier_checkairshow
	dome_set DOME_DATA_ATTEMPTED_CHALLENGE, TRUE
	dome_set DOME_DATA_HAS_WON_CHALLENGE, TRUE
	dome_set DOME_DATA_WIN_STREAK_ACTIVE, TRUE
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	goto BattleFrontier_BattleDomeLobby_EventScript_AskRecordBattle_hns

BattleFrontier_BattleDomeLobby_EventScript_LostChallenge_hns::
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_ThankYouForPlaying_hns, MSGBOX_DEFAULT
	message BattleFrontier_BattleDomeLobby_Text_RecordWillBeSaved_hns
	waitmessage
	special LoadPlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	frontier_checkairshow
	dome_set DOME_DATA_WIN_STREAK_ACTIVE, FALSE
	dome_set DOME_DATA_ATTEMPTED_CHALLENGE, TRUE
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattleDomeLobby_EventScript_AskRecordBattle_hns::
	dome_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleDomeLobby_EventScript_EndChallenge_hns
	message BattleFrontier_BattleDomeLobby_Text_RecordLastMatch_hns
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleDomeLobby_EventScript_EndChallenge_hns
	case 0, BattleFrontier_BattleDomeLobby_EventScript_RecordBattle_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_EndChallenge_hns

BattleFrontier_BattleDomeLobby_EventScript_RecordBattle_hns::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleDomeLobby_EventScript_EndChallenge_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_HopeToSeeYouAgain_hns, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_ResumeChallenge_hns::
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_WeveBeenWaitingForYou_hns, MSGBOX_DEFAULT
	message BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge_hns2_hns
	waitmessage
	dome_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattleDomeLobby_EventScript_EnterChallenge_hns

BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendant_hns::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_DOME
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattleDomeLobby_EventScript_AttendantWelcome_hns
	end

BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendant_hns::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_DOME
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattleDomeLobby_EventScript_AttendantWelcome_hns
	end

BattleFrontier_BattleDomeLobby_EventScript_AttendantWelcome_hns::
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_WelcomeSingles_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_WelcomeDoubles_hns
BattleFrontier_BattleDomeLobby_EventScript_AskTakeChallenge_hns::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_TakeSinglesChallenge_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_TakeDoublesChallenge_hns
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomeLobby_EventScript_TryEnterChallenge_hns
	case 1, BattleFrontier_BattleDomeLobby_EventScript_ExplainChallenge_hns
	case 2, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattleDomeLobby_EventScript_TryEnterChallenge_hns::
	message BattleFrontier_BattleDomeLobby_Text_WhichLevelMode_hns
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge_hns
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMons_hns
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleDomeLobby_Text_SelectThreeMons_hns, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge_hns
	msgbox BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge_hns, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge_hns
	case YES, BattleFrontier_BattleDomeLobby_EventScript_SaveBeforeChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge_hns

BattleFrontier_BattleDomeLobby_EventScript_SaveBeforeChallenge_hns::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	dome_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge_hnsSaveFailed_hns
	dome_inittrainers
BattleFrontier_BattleDomeLobby_EventScript_EnterChallenge_hns::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	dome_settrainers
	msgbox BattleFrontier_BattleDomeLobby_Text_ShowYouToBattleDome_hns, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattleDomeLobby_EventScript_WalkToDoor_hns
	special HealPlayerParty
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_CORRIDOR_HNS, 23, 6
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleDomeLobby_EventScript_ExplainChallenge_hns::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_ExplainSinglesChallenge_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_ExplainDoublesChallenge_hns
	goto BattleFrontier_BattleDomeLobby_EventScript_AskTakeChallenge_hns

BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMons_hns::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMons_hnsLv50_hns
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMons_hnsLvOpen_hns

BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMons_hnsLv50_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLv50_hns, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsEnd_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_EndCancelChallenge_hns

BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMons_hnsLvOpen_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLvOpen_hns, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsEnd_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_EndCancelChallenge_hns

BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge_hnsSaveFailed_hns::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge_hns::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_HopeToSeeYouAgain_hns, MSGBOX_DEFAULT
BattleFrontier_BattleDomeLobby_EventScript_EndCancelChallenge_hns::
	release
	end

BattleFrontier_BattleDomeLobby_EventScript_WalkToDoor_hns::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendant_hnsWalkToDoor_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendant_hnsWalkToDoor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeLobby_Movement_WalkToDoor_hns
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_OpenSinglesDoor_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_OpenDoublesDoor_hns
	waitdooranim
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendant_hnsEnterDoor_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendant_hnsEnterDoor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeLobby_Movement_PlayerEnterDoor_hns
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_CloseSinglesDoor_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_CloseDoublesDoor_hns
	waitdooranim
	return

BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendant_hnsWalkToDoor_hns::
	applymovement LOCALID_DOME_ATTENDANT_SINGLES, BattleFrontier_BattleDomeLobby_Movement_WalkToDoor_hns
	return

BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendant_hnsWalkToDoor_hns::
	applymovement LOCALID_DOME_ATTENDANT_DOUBLES, BattleFrontier_BattleDomeLobby_Movement_WalkToDoor_hns
	return

BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendant_hnsEnterDoor_hns::
	applymovement LOCALID_DOME_ATTENDANT_SINGLES, BattleFrontier_BattleDomeLobby_Movement_AttendantEnterDoor_hns
	return

BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendant_hnsEnterDoor_hns::
	applymovement LOCALID_DOME_ATTENDANT_DOUBLES, BattleFrontier_BattleDomeLobby_Movement_AttendantEnterDoor_hns
	return

BattleFrontier_BattleDomeLobby_EventScript_WelcomeSingles_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_WelcomeSingleBattle_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeLobby_EventScript_WelcomeDoubles_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_WelcomeDoubleBattle_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeLobby_EventScript_TakeSinglesChallenge_hns::
	message BattleFrontier_BattleDomeLobby_Text_TakeSinglesChallenge_hns
	return

BattleFrontier_BattleDomeLobby_EventScript_TakeDoublesChallenge_hns::
	message BattleFrontier_BattleDomeLobby_Text_TakeDoublesChallenge_hns
	return

BattleFrontier_BattleDomeLobby_EventScript_ExplainSinglesChallenge_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainSinglesChallenge_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeLobby_EventScript_ExplainDoublesChallenge_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainDoublesChallenge_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeLobby_EventScript_OpenSinglesDoor_hns::
	opendoor 5, 4
	return

BattleFrontier_BattleDomeLobby_EventScript_OpenDoublesDoor_hns::
	opendoor 17, 4
	return

BattleFrontier_BattleDomeLobby_EventScript_CloseSinglesDoor_hns::
	closedoor 5, 4
	return

BattleFrontier_BattleDomeLobby_EventScript_CloseDoublesDoor_hns::
	closedoor 17, 4
	return

BattleFrontier_BattleDomeLobby_Movement_WalkToDoor_hns:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleDomeLobby_Movement_AttendantEnterDoor_hns:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleDomeLobby_Movement_PlayerEnterDoor_hns:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleDomeLobby_EventScript_ShowSinglesResults_hns::
	lockall
	frontier_results FRONTIER_FACILITY_DOME, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_ShowDoublesResults_hns::
	lockall
	frontier_results FRONTIER_FACILITY_DOME, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_ShowPrevTourneyTree_hns::
	dome_get DOME_DATA_PREV_TOURNEY_TYPE
	call_if_eq VAR_RESULT, 0, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLv50_hns
	call_if_eq VAR_RESULT, 1, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLv50_hns
	call_if_eq VAR_RESULT, 2, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLvOpen_hns
	call_if_eq VAR_RESULT, 3, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLvOpen_hns
	fadescreen FADE_TO_BLACK
	dome_showprevtourneytree
	waitstate
	end

BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLv50_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLv50_hns, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLv50_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLv50_hns, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLvOpen_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLvOpen_hns, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLvOpen_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLvOpen_hns, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_Man_hnsiac_hns::
	dome_getwinnersname
	msgbox BattleFrontier_BattleDomeLobby_Text_LastWinnerWasTough_hns, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_Lass_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_WinnersGainReputation_hns, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_FatMan_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_TrashedInFirstRound_hns, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_Man_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_NeedToCheckOpponentCarefully_hns, MSGBOX_NPC
	end

@ A few OutsideWest event scripts are inserted here instead, two of which are unused
BattleFrontier_OutsideWest_EventScript_Man3_hns::
	msgbox BattleFrontier_OutsideWest_Text_LongDreamedAboutBattleFrontier_hns, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_BattleDomeSign2_hns::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign2_hns, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnderConstructionSign_hns::
	msgbox BattleFrontier_OutsideWest_Text_QuestionMarkUnderConstruction_hns, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_RulesBoard_hns::
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_RulesAreListed_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard_hns::
	message BattleFrontier_BattleDomeLobby_Text_ReadWhichHeading_hns
	waitmessage
	multichoice 17, 4, MULTI_BATTLE_DOME_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomeLobby_EventScript_RulesMatchup_hns
	case 1, BattleFrontier_BattleDomeLobby_EventScript_RulesTourneyTree_hns
	case 2, BattleFrontier_BattleDomeLobby_EventScript_RulesDoubleKO_hns
	case 3, BattleFrontier_BattleDomeLobby_EventScript_ExitRules_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_ExitRules_hns
	end

BattleFrontier_BattleDomeLobby_EventScript_RulesMatchup_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainMatchupRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleDomeLobby_EventScript_RulesTourneyTree_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainTourneyTree_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleDomeLobby_EventScript_RulesDoubleKO_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainDoubleKORules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleDomeLobby_EventScript_ExitRules_hns::
	releaseall
	end

BattleFrontier_BattleDomeLobby_Text_WelcomeSingleBattle_hns:
	.string "Dove le strategie degli ALLENATORI\n"
	.string "sono messe alla prova!\p"
	.string "Benvenuto al DOME DELLA LOTTA!\p"
	.string "Sono la tua guida al Torneo\n"
	.string "IN SINGOLAR.$"

BattleFrontier_BattleDomeLobby_Text_TakeSinglesChallenge_hns:
	.string "Vuoi sfidare il Torneo\n"
	.string "di LOTTE SINGOLE?$"

BattleFrontier_BattleDomeLobby_Text_HopeToSeeYouAgain_hns:
	.string "Ci vediamo presto!$"

BattleFrontier_BattleDomeLobby_Text_ExplainSinglesChallenge_hns:
	.string "The SINGLE BATTLE Tournament\n"
	.string "is exactly as the name suggests--\l"
	.string "a tournament of SINGLE BATTLES.\p"
	.string "All participating TRAINERS must\n"
	.string "enter three POKéMON each.\p"
	.string "In each battle, one of the three\n"
	.string "POKéMON must be held in reserve.\p"
	.string "The other two POKéMON can battle\n"
	.string "one at a time.\p"
	.string "Choose the two battling POKéMON after\n"
	.string "examining the opponent's trio.\p"
	.string "You win the tournament by defeating\n"
	.string "four TRAINERS.\p"
	.string "Battle Points are awarded to\n"
	.string "the tournament winner.\p"
	.string "If you want to interrupt your\n"
	.string "tournament, please save the game.\p"
	.string "If you don't save before interrupting,\n"
	.string "you will be disqualified.$"

BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge_hns:
	.string "Prima di portarti alla LOTTA DOME,\n"
	.string "devo salvare i dati. Va bene?$"

BattleFrontier_BattleDomeLobby_Text_WhichLevelMode_hns:
	.string "Il torneo offre due livelli\n"
	.string "di sfida, Livello 50 o Livello Aperto.\l"
	.string "Cosa scegli?$"

BattleFrontier_BattleDomeLobby_Text_SelectThreeMons_hns:
	.string "Ora scegli i tre POKéMON\n"
	.string "da iscrivere, per favore.$"

BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLvOpen_hns:
	.string "Ehi, un attimo!\p"
	.string "Non hai tre POKéMON ammessi.\p"
	.string "Inoltre i POKéMON devono tenere\n"
	.string "oggetti tutti diversi.\p"
	.string "UOVA{STR_VAR_1}.$"

BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsEnd_hns:
	.string "Torna da me quando sarai pronto.$"

BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLv50_hns:
	.string "Ehi, un attimo!\p"
	.string "Non hai tre POKéMON ammessi.\p"
	.string "Per iscriverti servono tre POKéMON\n"
	.string "diversi di livello 50 o meno.\p"
	.string "Devono anche tenere oggetti\n"
	.string "tutti diversi.\p"
	.string "UOVA{STR_VAR_1}.$"

BattleFrontier_BattleDomeLobby_Text_ShowYouToBattleDome_hns:
	.string "Ora ti accompagno\n"
	.string "alla LOTTA DOME.$"

BattleFrontier_BattleDomeLobby_Text_DidntSaveBeforeQuitting_hns:
	.string "Oh, scusa!\p"
	.string "L'ultima volta non hai salvato\n"
	.string "prima di uscire dalla sfida.\p"
	.string "Per questo la sfida finora\n"
	.string "è stata annullata. Scusa!$"

BattleFrontier_BattleDomeLobby_Text_CongratsForWinningTourney_hns:
	.string "Congratulazioni per la\n"
	.string "vittoria al Torneo!$"

@ Unused
BattleFrontier_BattleDomeLobby_Text_HereIsYourPrize_hns:
	.string "Ecco il premio per la vittoria\n"
	.string "al Torneo di Lotta.$"

@ Used by Verdanturf Tent
BattleFrontier_BattleDomeLobby_Text_ReceivedPrize_hns:
	.string "{PLAYER} ha ottenuto\n"
	.string "{STR_VAR_1}.$"

@ Unused
BattleFrontier_BattleDomeLobby_Text_BagFullMakeRoom_hns:
	.string "Oh, lo ZAINO è pieno.\p"
	.string "Fai spazio e poi torna\n"
	.string "da me.$"

BattleFrontier_BattleDomeLobby_Text_ThankYouForPlaying_hns:
	.string "Grazie per aver giocato!$"

BattleFrontier_BattleDomeLobby_Text_RecordWillBeSaved_hns:
	.string "Il risultato verrà salvato.\n"
	.string "Attendi.$"

BattleFrontier_BattleDomeLobby_Text_WeveBeenWaitingForYou_hns:
	.string "Ti aspettavamo!$"

BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge_hns2_hns:
	.string "Prima di portarti alla LOTTA DOME,\n"
	.string "devo salvare i dati. Va bene?$"

BattleFrontier_BattleDomeLobby_Text_WelcomeDoubleBattle_hns:
	.string "Qui le strategie degli ALLENATORI\n"
	.string "sono messe alla prova!\p"
	.string "Benvenuto alla LOTTA DOME!\p"
	.string "Sono la tua guida al Torneo\n"
	.string "di LOTTE DOPPIE.$"

BattleFrontier_BattleDomeLobby_Text_TakeDoublesChallenge_hns:
	.string "Vuoi sfidare il Torneo\n"
	.string "di LOTTE DOPPIE?$"

BattleFrontier_BattleDomeLobby_Text_ExplainDoublesChallenge_hns:
	.string "The DOUBLE BATTLE Tournament\n"
	.string "is exactly as the name suggests--\l"
	.string "a tournament of DOUBLE BATTLES.\p"
	.string "All participating TRAINERS must\n"
	.string "enter three POKéMON each.\p"
	.string "In each battle, one of the three\n"
	.string "POKéMON must be held in reserve.\p"
	.string "The remaining two POKéMON must take\n"
	.string "part in a DOUBLE BATTLE.\p"
	.string "Choose the two battling POKéMON after\n"
	.string "examining the opponent's trio.\p"
	.string "You win the tournament by defeating\n"
	.string "four TRAINERS.\p"
	.string "Battle Points are awarded to\n"
	.string "the tournament winner.\p"
	.string "If you want to interrupt your\n"
	.string "tournament, please save the game.\p"
	.string "If you don't save before interrupting,\n"
	.string "you will be disqualified.$"

BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLv50_hns:
	.string "Sono i risultati dell'ultimo\n"
	.string "Torneo di LOTTE SINGOLE Liv. 50.$"

BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLv50_hns:
	.string "Sono i risultati dell'ultimo\n"
	.string "Torneo di LOTTE DOPPIE Liv. 50.$"

BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLvOpen_hns:
	.string "Sono i risultati dell'ultimo\n"
	.string "Torneo di LOTTE SINGOLE a Liv. aperto.$"

BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLvOpen_hns:
	.string "Sono i risultati dell'ultimo\n"
	.string "Torneo di LOTTE DOPPIE a Liv. aperto.$"

BattleFrontier_BattleDomeLobby_Text_LastWinnerWasTough_hns:
	.string "L'hai visto?\n"
	.string "L'ultimo Torneo di Lotta?\p"
	.string "Il vincitore, {STR_VAR_1}, era\n"
	.string "davvero forte.\p"
	.string "Dai un'occhiata ai risultati\n"
	.string "sul monitor accanto al PC.$"

BattleFrontier_OutsideWest_Text_LongDreamedAboutBattleFrontier_hns:
	.string "LA ZONA LOTTA…\n"
	.string "Sognavo un posto così da sempre.$"

@ Functionally unused
BattleFrontier_OutsideWest_Text_BattleDomeSign2_hns:
	.string "IL DOME DELLA LOTTA\n"
	.string "Diventa la star imbattibile!$"

@ Functionally unused
BattleFrontier_OutsideWest_Text_QuestionMarkUnderConstruction_hns:
	.string "I ??????\n"
	.string "IN LAVORAZIONE!$"

BattleFrontier_BattleDomeLobby_Text_WinnersGainReputation_hns:
	.string "Quando un ALLENATORE ottiene molte\n"
	.string "vittorie al DOME DELLA LOTTA,\l"
	.string "diventa una star.\p"
	.string "ALLENATORI forti giungono qui\n"
	.string "spinti dalla sua fama.\p"
	.string "Un vero campione è un ALLENATORE\n"
	.string "che vince sempre i tornei.$"

BattleFrontier_BattleDomeLobby_Text_TrashedInFirstRound_hns:
	.string "Al primo turno ho incontrato uno\n"
	.string "dei favoriti del torneo.\p"
	.string "Ovviamente sono stato travolto…$"

BattleFrontier_BattleDomeLobby_Text_NeedToCheckOpponentCarefully_hns:
	.string "Avrei vinto se avessi tenuto questo\n"
	.string "POKéMON in riserva.\p"
	.string "Devi studiare bene i POKéMON\n"
	.string "dell'avversario prima di scegliere\l"
	.string "quelli con cui lottare.$"

BattleFrontier_BattleDomeLobby_Text_CongratsDefeatedTucker_hns:
	.string "Congratulazioni!\p"
	.string "Hai battuto l'ASO DELLA CUPOLA\n"
	.string "e vinto il Torneo!$"

BattleFrontier_BattleDomeLobby_Text_AwardTheseBattlePoints_hns:
	.string "In recognition of your strategy--\n"
	.string "a thing of beauty it was, too--\l"
	.string "we award you these Battle Point(s)!$"

BattleFrontier_BattleDomeLobby_Text_RecordLastMatch_hns:
	.string "Vuoi registrare la tua ultima\n"
	.string "partita alla LOTTA DOME nel\l"
	.string "SUPERPASS?$"

BattleFrontier_BattleDomeLobby_Text_RulesAreListed_hns:
	.string "Qui sono elencate le regole\n"
	.string "del Torneo.$"

BattleFrontier_BattleDomeLobby_Text_ReadWhichHeading_hns:
	.string "Quale voce vuoi leggere?$"

BattleFrontier_BattleDomeLobby_Text_ExplainMatchupRules_hns:
	.string "Gli accoppiamenti del torneo si\n"
	.string "basano sulla forza dei POKéMON\l"
	.string "degli ALLENATORI.\p"
	.string "Gli accoppiamenti evitano che\n"
	.string "forti ALLENATORI si sfidino subito.$"

BattleFrontier_BattleDomeLobby_Text_ExplainTourneyTree_hns:
	.string "Il quadro del torneo, detto anche\n"
	.string "“Albero”, è visibile nella Sala\l"
	.string "d'Attesa con qualsiasi guida.\p"
	.string "L'Albero del Torneo offre\n"
	.string "vari tipi di dati.\p"
	.string "Mostra i risultati del torneo\n"
	.string "precedente, i POKéMON degli\l"
	.string "ALLENATORI e il loro stile\l"
	.string "di lotta.$"

BattleFrontier_BattleDomeLobby_Text_ExplainDoubleKORules_hns:
	.string "Se due POKéMON vengono messi KO\n"
	.string "nello stesso turno, un KO doppio,\l"
	.string "gli ARBITRI esaminano la partita\l"
	.string "e decretano il vincitore.$"
