CableClub_OnTransition_Frlg::
	call CableClub_EventScript_HideOrShowMysteryGiftMan_Frlg
	end

CableClub_EventScript_HideOrShowMysteryGiftMan_Frlg::
	specialvar VAR_RESULT, ValidateSavedWonderCard
	goto_if_eq VAR_RESULT, FALSE, EventScript_HideMysteryGiftMan_Frlg
	clearflag FLAG_HIDE_MG_DELIVERYMEN
	return

EventScript_HideMysteryGiftMan_Frlg::
	setflag FLAG_HIDE_MG_DELIVERYMEN
	return

CableClub_EventScript_MysteryGiftMan_Frlg::
	trywondercardscript

@ Unused
EventScript_MysteryGiftThankYou_Frlg::
	msgbox gText_ThankYouForAccessingMysteryGift, MSGBOX_NPC
	end

CableClub_OnWarp_Frlg::
	map_script_2 VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE, EventScript_CheckTurnAttendant_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE, EventScript_CheckTurnAttendant_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MULTI_BATTLE, EventScript_CheckTurnAttendant_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER, EventScript_CheckTurnAttendant_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_UNION_ROOM, EventScript_CheckTurnAttendant_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_BERRY_CRUSH, EventScript_CheckTurnAttendant_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, EventScript_CheckTurnAttendant_Frlg
	.2byte 0

EventScript_CheckTurnAttendant_Frlg::
	goto_if_eq VAR_0x8007, 0, EventScript_CheckTurnAttendantEnd
	turnobject VAR_0x8007, DIR_WEST
EventScript_CheckTurnAttendantEnd:
	end

CableClub_OnLoad_Frlg::
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE, EventScript_OnLoadFromColosseum_Frlg
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE, EventScript_OnLoadFromColosseum_Frlg
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_MULTI_BATTLE, EventScript_OnLoadFromColosseum_Frlg
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER, EventScript_OnLoadFromTradeCenter_Frlg
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_UNION_ROOM, EventScript_OnLoadFromUnionRoom_Frlg
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_BERRY_CRUSH, EventScript_OnLoadFromBerryCrush_Frlg
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_MINIGAME, EventScript_OnLoadFromGameCorner_Frlg
	end

EventScript_OnLoadFromColosseum_Frlg::
	call CableClub_EventScript_OpenDirectCornerBarrier_Frlg
	end

EventScript_OnLoadFromTradeCenter_Frlg::
	call CableClub_EventScript_OpenDirectCornerBarrier_Frlg
	end

EventScript_OnLoadFromUnionRoom_Frlg::
	call CableClub_EventScript_OpenUnionRoomBarrier_Frlg
	end

EventScript_OnLoadFromBerryCrush_Frlg::
	call CableClub_EventScript_OpenDirectCornerBarrier_Frlg
	end

EventScript_OnLoadFromGameCorner_Frlg::
	call CableClub_EventScript_OpenGameCornerBarrier_Frlg
	end

CableClub_OnFrame_Frlg::
	map_script_2 VAR_MAP_SCENE_POKEMON_CENTER_TEALA, 1, CableClub_EventScript_Tutorial_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE, CableClub_EventScript_ExitLinkRoom_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE, CableClub_EventScript_ExitLinkRoom_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MULTI_BATTLE, CableClub_EventScript_ExitLinkRoom_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER, CableClub_EventScript_ExitTradeCenter_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_UNION_ROOM, CableClub_EventScript_ExitUnionRoom_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_BERRY_CRUSH, CableClub_EventScript_ExitLinkRoom_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom_Frlg
	.2byte 0

CableClub_EventScript_ExitLinkRoom_Frlg::
	lockall
	call CableClub_EventScript_CloseLinkAndExitLinkRoom_Frlg
	call CableClub_EventScript_CloseDirectCornerBarrier_Frlg
	special DrawWholeMapView
	playse SE_CLICK
	erasebox 0, 0, 29, 19
	releaseall
	end

CableClub_EventScript_ExitMinigameRoom_Frlg::
	lockall
	call CableClub_EventScript_CloseLinkAndExitLinkRoom_Frlg
	call CableClub_EventScript_CloseGameCornerBarrier_Frlg
	special DrawWholeMapView
	playse SE_CLICK
	erasebox 0, 0, 29, 19
	releaseall
	end

CableClub_EventScript_CloseLinkAndExitLinkRoom_Frlg::
	setvar VAR_CABLE_CLUB_STATE, 0
	textcolor NPC_TEXT_COLOR_FEMALE
	goto_if_eq VAR_0x8007, 0, CableClub_EventScript_PlayerExitLinkRoom_Frlg
	applymovement VAR_0x8007, Movement_AttendantFaceLeft
	waitmovement 0
	applymovement LOCALID_PLAYER, Movement_PlayerExitLinkRoom
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceDown
	waitmovement 0
	return

CableClub_EventScript_ExitTradeCenter_Frlg::
	lockall
	call CableClub_EventScript_PlayerExitTradeCenter_Frlg
	call CableClub_EventScript_CloseDirectCornerBarrier_Frlg
	special DrawWholeMapView
	playse SE_CLICK
	erasebox 0, 0, 29, 19
	releaseall
	end

CableClub_EventScript_PlayerExitTradeCenter_Frlg::
	special CloseLink
	setvar VAR_CABLE_CLUB_STATE, 0
	textcolor NPC_TEXT_COLOR_FEMALE
	goto_if_eq VAR_0x8007, 0, CableClub_EventScript_PlayerExitLinkRoom_Frlg
	applymovement LOCALID_PLAYER, Movement_PlayerFaceAttendantRight
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceLeft
	waitmovement 0
	call CableClub_EventScript_TrainerCardDataOverwritten_Frlg
	return

CableClub_EventScript_ExitUnionRoom_Frlg::
	lockall
	call CableClub_EventScript_PlayerExitUnionRoom_Frlg
	call CableClub_EventScript_CloseUnionRoomBarrier_Frlg
	special DrawWholeMapView
	playse SE_CLICK
	erasebox 0, 0, 29, 19
	releaseall
	end

CableClub_EventScript_PlayerExitUnionRoom_Frlg::
	setvar VAR_CABLE_CLUB_STATE, 0
	textcolor NPC_TEXT_COLOR_FEMALE
	goto_if_eq VAR_0x8007, 0, CableClub_EventScript_PlayerExitLinkRoom_Frlg
	applymovement LOCALID_PLAYER, Movement_PlayerFaceAttendantRight
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceLeft
	waitmovement 0
	call CableClub_EventScript_TrainerCardDataOverwritten_Frlg
	return

CableClub_EventScript_TrainerCardDataOverwritten_Frlg::
	message CableClub_Text_TrainerCardDataOverwritten_Frlg
	waitmessage
	playse SE_PIN
	message CableClub_Text_HopeToSeeYouAgain_Frlg
	waitmessage
	applymovement LOCALID_PLAYER, Movement_PlayerExitLinkRoom
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceDown
	waitmovement 0
	return

CableClub_EventScript_PlayerExitLinkRoom_Frlg::
	applymovement LOCALID_PLAYER, Movement_PlayerExitLinkRoom
	waitmovement 0
	return

CableClub_EventScript_Tutorial_Frlg::
	lockall
	textcolor NPC_TEXT_COLOR_FEMALE
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox CableClub_Text_FirstTimeRightThisWay_Frlg
	closemessage
	applymovement LOCALID_PLAYER, Movement_PlayerApproachCounter
	waitmovement 0
	delay 30
	msgbox CableClub_Text_ExplainWirelessClubFirstTime_Frlg
	setvar VAR_MAP_SCENE_POKEMON_CENTER_TEALA, 2
	releaseall
	end

Movement_PlayerApproachCounter:
	walk_up
	walk_up
	step_end

CableClub_EventScript_WelcomeToCableClub_Frlg::
	message CableClub_Text_WelcomeWhichCableClubService_Frlg
	waitmessage
	delay 15
	goto CableClub_EventScript_SelectCableClubRoom_Frlg
	end

CableClub_EventScript_UnusedWelcomeToCableClub_Frlg::
	msgbox CableClub_Text_WhichService_Frlg
	goto CableClub_EventScript_SelectCableClubRoom_Frlg
	end

CableClub_EventScript_SelectCableClubRoom_Frlg::
	setvar VAR_0x8004, 0
	multichoice 0, 0, MULTI_CABLE_CLUB_NO_RECORD_MIX, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_TradeCenter_Frlg
	case 1, CableClub_EventScript_Colosseum_Frlg
	case 2, CableClub_EventScript_AbortLink_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink_Frlg
	end

CableClub_EventScript_Colosseum_Frlg::
	copyvar VAR_0x8007, VAR_LAST_TALKED
	goto CableClub_EventScript_SelectBattleMode_Frlg
	end

CableClub_EventScript_SelectBattleMode_Frlg::
	message CableClub_Text_PlayWhichBattleMode_Frlg
	waitmessage
	multichoice 0, 0, MULTI_BATTLE_MODE, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_SingleBattleMode_Frlg
	case 1, CableClub_EventScript_DoubleBattleMode_Frlg
	case 2, CableClub_EventScript_MultiBattleMode_Frlg
	case 3, CableClub_EventScript_BattleModeInfo_Frlg
	case 4, CableClub_EventScript_AbortLink_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink_Frlg
	end

CableClub_EventScript_BattleModeInfo_Frlg::
	msgbox CableClub_Text_ExplainBattleModes_Frlg
	goto CableClub_EventScript_SelectBattleMode_Frlg
	end

CableClub_EventScript_SingleBattleMode_Frlg::
	setvar VAR_0x8004, USING_SINGLE_BATTLE
	goto CableClub_EventScript_TryEnterColosseum_Frlg
	end

CableClub_EventScript_DoubleBattleMode_Frlg::
	special HasEnoughMonsForDoubleBattle
	goto_if_ne VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS, CableClub_EventScript_NeedTwoMonsForDoubleBattle_Frlg
	setvar VAR_0x8004, USING_DOUBLE_BATTLE
	goto CableClub_EventScript_TryEnterColosseum_Frlg
	end

CableClub_EventScript_NeedTwoMonsForDoubleBattle_Frlg::
	msgbox CableClub_Text_NeedTwoMonsForDoubleBattle_Frlg
	goto CableClub_EventScript_SelectBattleMode_Frlg
	end

CableClub_EventScript_MultiBattleMode_Frlg::
	setvar VAR_0x8004, USING_MULTI_BATTLE
	goto CableClub_EventScript_TryEnterColosseum_Frlg
	end

CableClub_EventScript_TryEnterColosseum_Frlg::
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink_Frlg
	message CableClub_Text_PleaseWaitBCancel_Frlg
	waitmessage
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special TryBattleLinkup
	waitstate
	call EventScript_RestorePrevTextColor
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterColosseum_Frlg
	goto_if_eq VAR_RESULT, LINKUP_SOMEONE_NOT_READY, CableClub_EventScript_AbortLinkSomeoneNotReady_Frlg
	goto_if_eq VAR_RESULT, LINKUP_DIFF_SELECTIONS, CableClub_EventScript_AbortLinkDifferentSelections_Frlg
	goto_if_eq VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS, CableClub_EventScript_AbortLinkIncorrectNumberOfBattlers_Frlg
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_AbortLink_Frlg
	goto_if_eq VAR_RESULT, LINKUP_CONNECTION_ERROR, CableClub_EventScript_AbortLinkConnectionError_Frlg
	end

CableClub_EventScript_EnterColosseum_Frlg::
	special HealPlayerParty
	special SavePlayerParty
	special LoadPlayerBag
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	messageautoscroll CableClub_Text_PleaseEnter_Frlg
	waitmessage
	call CableClub_EventScript_OpenDirectCornerBarrier_Frlg
	special DrawWholeMapView
	playse SE_CLICK
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement LOCALID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 9, 1
	waitdooranim
	applymovement LOCALID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideplayer
	closedoor 9, 1
	waitdooranim
	release
	goto_if_eq VAR_0x8004, USING_MULTI_BATTLE, CableClub_EventScript_WarpTo4PColosseum_Frlg
	special SetCableClubWarp
	warp MAP_BATTLE_COLOSSEUM_2P, 6, 8
	special DoCableClubWarp
	waitstate
	end

@ Unused
CableClub_EventScript_PlayerApproachLinkRoomRight_Frlg::
	applymovement LOCALID_PLAYER, Movement_PlayerApproachLinkRoomRight
	waitmovement 0
	return

CableClub_EventScript_WarpTo4PColosseum_Frlg::
	special SetCableClubWarp
	warp MAP_BATTLE_COLOSSEUM_4P, 5, 8
	special DoCableClubWarp
	waitstate
	end

CableClub_EventScript_AbortLinkIncorrectNumberOfBattlers_Frlg::
	switch VAR_0x8004
	case USING_SINGLE_BATTLE, CableClub_EventScript_AbortLinkWrongNumberForSingleBattle_Frlg
	case USING_DOUBLE_BATTLE, CableClub_EventScript_AbortLinkWrongNumberForDoubleBattle_Frlg
	case USING_MULTI_BATTLE, CableClub_EventScript_AbortLinkNeedFourPlayers_Frlg
	goto CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants_Frlg
	end

CableClub_EventScript_AbortLinkNeedFourPlayers_Frlg::
	special CloseLink
	msgbox CableClub_Text_NeedFourPlayers_Frlg
	goto CableClub_EventScript_ConfirmNumberAndRestart_Frlg
	end

CableClub_EventScript_AbortLinkWrongNumberForDoubleBattle_Frlg::
	special CloseLink
	msgbox CableClub_Text_CantDoubleBattleWithXPlayers_Frlg
	goto CableClub_EventScript_ConfirmNumberAndRestart_Frlg
	end

CableClub_EventScript_AbortLinkWrongNumberForSingleBattle_Frlg::
	special CloseLink
	msgbox CableClub_Text_CantSingleBattleWithXPlayers_Frlg
	goto CableClub_EventScript_ConfirmNumberAndRestart_Frlg
	end

CableClub_EventScript_ConfirmNumberAndRestart_Frlg::
	special CloseLink  @ Redundant
	msgbox CableClub_Text_PleaseConfirmNumberAndRestart_Frlg
	release
	end

CableClub_EventScript_TradeCenter_Frlg::
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call CableClub_EventScript_CheckPartyTradeRequirements_Frlg
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink_Frlg
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink_Frlg
	message CableClub_Text_PleaseWaitBCancel_Frlg
	waitmessage
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special TryTradeLinkup
	waitstate
	call EventScript_RestorePrevTextColor
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterTradeCenter_Frlg
	goto_if_eq VAR_RESULT, LINKUP_SOMEONE_NOT_READY, CableClub_EventScript_AbortLinkSomeoneNotReady_Frlg
	goto_if_eq VAR_RESULT, LINKUP_DIFF_SELECTIONS, CableClub_EventScript_AbortLinkDifferentSelections_Frlg
	goto_if_eq VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS, CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants_Frlg
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_AbortLink_Frlg
	goto_if_eq VAR_RESULT, LINKUP_CONNECTION_ERROR, CableClub_EventScript_AbortLinkConnectionError_Frlg
	goto_if_eq VAR_RESULT, LINKUP_PLAYER_NOT_READY, CableClub_EventScript_AbortLinkPlayerNotReady_Frlg
	goto_if_eq VAR_RESULT, LINKUP_PARTNER_NOT_READY, CableClub_EventScript_AbortLinkOtherTrainerNotReady_Frlg
	end

CableClub_EventScript_EnterTradeCenter_Frlg::
	setvar VAR_0x8004, USING_TRADE_CENTER
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	messageautoscroll CableClub_Text_PleaseEnter_Frlg
	waitmessage
	call CableClub_EventScript_OpenDirectCornerBarrier_Frlg
	special DrawWholeMapView
	playse SE_CLICK
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement LOCALID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 9, 1
	waitdooranim
	applymovement LOCALID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideplayer
	closedoor 9, 1
	waitdooranim
	release
	special SetCableClubWarp
	setwarp MAP_TRADE_CENTER_FRLG, 5, 8
	special DoCableClubWarp
	waitstate
	end

CableClub_EventScript_CheckPartyTradeRequirements_Frlg::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_lt VAR_RESULT, 2, CableClub_EventScript_NeedTwoMonsToTrade_Frlg
	specialvar VAR_RESULT, DoesPartyHaveEnigmaBerry
	goto_if_eq VAR_RESULT, TRUE, CableClub_EventScript_CantTradeEnigmaBerry_Frlg
	setvar VAR_RESULT, TRUE
	return

CableClub_EventScript_NeedTwoMonsToTrade_Frlg::
	msgbox CableClub_Text_NeedTwoMonsToTrade_Frlg
	setvar VAR_RESULT, FALSE
	return

CableClub_EventScript_CantTradeEnigmaBerry_Frlg::
	msgbox CableClub_Text_CantTradeEnigmaBerry_Frlg
	setvar VAR_RESULT, FALSE
	return

@ Record Corner is nopped in FRLG
CableClub_EventScript_RecordCorner_Frlg::
	end

CableClub_EventScript_AbortLinkPlayerNotReady_Frlg::
	special CloseLink
	msgbox CableClub_Text_NotSetUpForFarAwayRegion_Frlg
	release
	end

CableClub_EventScript_AbortLinkOtherTrainerNotReady_Frlg::
	special CloseLink
	msgbox CableClub_Text_OtherTrainerNotReady_Frlg
	release
	end

CableClub_EventScript_AbortLinkConnectionError_Frlg::
	special CloseLink
	msgbox CableClub_Text_LinkErrorPleaseReset_Frlg
	release
	end

CableClub_EventScript_AbortLinkSomeoneNotReady_Frlg::
	special CloseLink
	msgbox CableClub_Text_SomeoneIsNotReadyToLink_Frlg
	release
	end

CableClub_EventScript_AbortLinkDifferentSelections_Frlg::
	special CloseLink
	msgbox CableClub_Text_PlayersMadeDifferentSelections_Frlg
	release
	end

CableClub_EventScript_AbortLink_Frlg::
	special CloseLink
	msgbox CableClub_Text_PleaseVisitAgain_Frlg
	release
	end

CableClub_EventScript_AbortMinigame_Frlg::
	special CloseLink
	msgbox CableClub_Text_ComeAgain_Frlg
	release
	end

@ Unused
CableClub_EventScript_CableClubWarp_Frlg::
	special SetCableClubWarp
	special DoCableClubWarp
	waitstate
	end

CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants_Frlg::
	special CloseLink
	msgbox CableClub_Text_IncorrectNumberOfParticipants_Frlg
	release
	end

CableClub_EventScript_AbortLinkPlayerHasBadEgg_Frlg::
	special CloseLink
	msgbox CableClub_Text_YouHaveAMonThatCantBeTaken_Frlg
	release
	end

CableClub_EventScript_WirelessClubAdjustements_Frlg::
	msgbox Text_WirelessClubUndergoingAdjustments
	release
	end

CableClub_EventScript_NotReadyYet_Frlg::
	msgbox Text_AppearsToBeUndergoingAdjustments
	releaseall
	end

Movement_AttendantFaceDown_Frlg::
	face_down
	step_end

@ Unused
Movement_AttendantFaceRight_Frlg::
	face_right
	step_end

Movement_AttendantFaceLeft_Frlg::
	face_left
	step_end

Movement_PlayerExitLinkRoom_Frlg::
	walk_down
	walk_down
	step_end

Movement_PlayerApproachLinkRoomRight_Frlg::
	walk_right
	walk_up
	walk_up
	step_end

Movement_PlayerApproachLinkRoomLeft_Frlg::
	walk_left
	walk_up
	walk_up
	step_end

Movement_PlayerEnterLinkRoom_Frlg::
	walk_up
	step_end

@ Unused
Movement_PlayerFaceAttendantLeft_Frlg::
	face_left
	step_end

Movement_PlayerFaceAttendantRight_Frlg::
	face_right
	step_end

Movement_PlayerEnterMinigameRoom_Frlg::
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

CableClub_EventScript_ShowBattleRecords_Frlg::
	lockall
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, 0
	special ShowTrainerHillRecords
	waitstate
	releaseall
	end

BattleColosseum_2P_EventScript_PlayerSpot0::
	setvar VAR_0x8005, 0
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special ColosseumPlayerSpotTriggered
	waitstate
	end

BattleColosseum_2P_EventScript_PlayerSpot1::
	setvar VAR_0x8005, 1
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special ColosseumPlayerSpotTriggered
	waitstate
	end

BattleColosseum_4P_EventScript_PlayerSpot0::
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleColosseum_4P_EventScript_CancelSpotTrigger_Frlg
	setvar VAR_0x8005, 0
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special ColosseumPlayerSpotTriggered
	waitstate
	end

BattleColosseum_4P_EventScript_PlayerSpot1::
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleColosseum_4P_EventScript_CancelSpotTrigger_Frlg
	setvar VAR_0x8005, 1
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special ColosseumPlayerSpotTriggered
	waitstate
	end

BattleColosseum_4P_EventScript_PlayerSpot2::
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleColosseum_4P_EventScript_CancelSpotTrigger_Frlg
	setvar VAR_0x8005, 2
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special ColosseumPlayerSpotTriggered
	waitstate
	end

BattleColosseum_4P_EventScript_PlayerSpot3::
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleColosseum_4P_EventScript_CancelSpotTrigger_Frlg
	setvar VAR_0x8005, 3
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special ColosseumPlayerSpotTriggered
	waitstate
	end

BattleColosseum_4P_EventScript_CancelSpotTrigger_Frlg::
	end

TradeCenter_EventScript_Chair0::
	setvar VAR_0x8005, 0
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special PlayerEnteredTradeSeat
	waitstate
	end

TradeCenter_EventScript_Chair1::
	setvar VAR_0x8005, 1
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special PlayerEnteredTradeSeat
	waitstate
	end

@ Unused
TradeCenter_EventScript_Chair2_Frlg::
	setvar VAR_0x8005, 2
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special PlayerEnteredTradeSeat
	waitstate
	end

@ Unused
TradeCenter_EventScript_Chair3_Frlg::
	setvar VAR_0x8005, 3
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special PlayerEnteredTradeSeat
	waitstate
	end

@ Nop in FRLG
@ Separate labels to match GetDirectionForEventScript
RecordCorner_EventScript_Spot0::
RecordCorner_EventScript_Spot1::
RecordCorner_EventScript_Spot2::
RecordCorner_EventScript_Spot3::
	end

CableClub_EventScript_ReadTrainerCard_Frlg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox Text_LookedAtPlayersTrainerCard_Frlg
	fadescreen FADE_TO_BLACK
	special Script_ShowLinkTrainerCard
	waitstate
	end

CableClub_EventScript_ReadTrainerCardColored_Frlg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox Text_LookedAtPlayersTrainerCardColored_Frlg
	fadescreen FADE_TO_BLACK
	special Script_ShowLinkTrainerCard
	waitstate
	end

CableClub_EventScript_TooBusyToNotice_Frlg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox Text_TrainerTooBusyToNotice_Frlg
	closemessage
	end

BattleColosseum_2P_EventScript_Attendant_Frlg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special Script_FacePlayer
	msgbox Text_TakeSeatStartBattle_Frlg
	special Script_ClearHeldMovement
	closemessage
	end

TradeCenter_EventScript_Attendant_Frlg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special Script_FacePlayer
	msgbox Text_TakeSeatStartTrade_Frlg
	special Script_ClearHeldMovement
	closemessage
	end

@ Nop in FRLG
RecordCorner_EventScript_Attendant_Frlg::
	end

TradeCenter_ConfirmLeaveRoom_Frlg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox Text_TerminateLinkIfYouLeaveRoom_Frlg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TradeCenter_TerminateLink_Frlg
	erasebox 0, 0, 29, 19
	releaseall
	end

TradeCenter_TerminateLink_Frlg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	messageautoscroll Text_TerminateLinkConfirmation
	waitmessage
	special ExitLinkRoom
	end

CableClub_EventScript_DoLinkRoomExit_Frlg::
	special CleanupLinkRoomState
	special ReturnFromLinkRoom
	waitstate
	end

CableClub_EventScript_UnionRoomAttendant_Frlg::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_WirelessClubAdjustements_Frlg
	specialvar VAR_RESULT, IsBadEggInParty
	goto_if_eq VAR_RESULT, TRUE, CableClub_EventScript_AbortLinkPlayerHasBadEgg_Frlg
	copyvar VAR_0x8007, VAR_LAST_TALKED
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_UnionRoomAdapterNotConnected_Frlg
	message CableClub_Text_WelcomeUnionRoomEnter_Frlg
	waitmessage
	goto CableClub_EventScript_AskEnterUnionRoom_Frlg
	end

CableClub_EventScript_AskEnterUnionRoom_Frlg::
	multichoice 18, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_EnterUnionRoom_Frlg
	case 1, CableClub_EventScript_AbortLink_Frlg
	case 2, CableClub_EventScript_UnionRoomInfo_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink_Frlg
	end

CableClub_EventScript_UnionRoomInfo_Frlg::
	message CableClub_Text_UnionRoomInfo_Frlg
	waitmessage
	goto CableClub_EventScript_AskEnterUnionRoom_Frlg
	end

CableClub_EventScript_EnterUnionRoom_Frlg::
	call CableClub_EventScript_CheckPartyUnionRoomRequirements_Frlg
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_AbortLink_Frlg
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink_Frlg
	msgbox CableClub_Text_EnjoyUnionRoom_Frlg
	closemessage
	special HealPlayerParty
	setvar VAR_0x8004, USING_UNION_ROOM
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	call CableClub_EventScript_OpenUnionRoomBarrier_Frlg
	special DrawWholeMapView
	playse SE_CLICK
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	applymovement LOCALID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 5, 1
	waitdooranim
	applymovement LOCALID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideplayer
	closedoor 5, 1
	waitdooranim
	special Script_ResetUnionRoomTrade
	special SetCableClubWarp
	warpspinenter MAP_UNION_ROOM_FRLG, 7, 11
	waitstate
	special RunUnionRoom
	waitstate
	end

CableClub_EventScript_CheckPartyUnionRoomRequirements_Frlg::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_lt VAR_RESULT, 2, CableClub_EventScript_NeedTwoMonsForUnionRoom_Frlg
	specialvar VAR_RESULT, DoesPartyHaveEnigmaBerry
	goto_if_eq VAR_RESULT, TRUE, CableClub_EventScript_NoEnigmaBerryInUnionRoom_Frlg
	setvar VAR_RESULT, TRUE
	return

CableClub_EventScript_NeedTwoMonsForUnionRoom_Frlg::
	msgbox CableClub_Text_NeedTwoMonsForUnionRoom_Frlg
	goto EventScript_SetResultFalse
	end

CableClub_EventScript_NoEnigmaBerryInUnionRoom_Frlg::
	msgbox CableClub_Text_NoEnigmaBerryInUnionRoom_Frlg
	goto EventScript_SetResultFalse
	end

CableClub_EventScript_UnionRoomAdapterNotConnected_Frlg::
	msgbox CableClub_Text_UnionRoomAdapterNotConnected_Frlg
	release
	return

CableClub_EventScript_WirelessClubAttendant_Frlg::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_WirelessClubAdjustements_Frlg
	msgbox CableClub_Text_AskAboutLinking_Frlg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CableClub_EventScript_DontAskAboutLinking_Frlg
	msgbox CableClub_Text_ExplainWirelessClub_Frlg
	release
	return

CableClub_EventScript_DontAskAboutLinking_Frlg::
	msgbox CableClub_Text_HopeYouEnjoyWirelessSystem_Frlg
	release
	return

CableClub_EventScript_DirectCornerAttendant_Frlg::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_WirelessClubAdjustements_Frlg
	specialvar VAR_RESULT, IsBadEggInParty
	goto_if_eq VAR_RESULT, TRUE, CableClub_EventScript_AbortLinkPlayerHasBadEgg_Frlg
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_WelcomeToCableClub_Frlg
	message CableClub_Text_WelcomeWhichDirectCornerRoom_Frlg
	waitmessage
	delay 15
	goto CableClub_EventScript_DirectCornerSelectService_Frlg
	end

CableClub_EventScript_DirectCornerSelectService_Frlg::
	goto_if_unset FLAG_GOT_POWDER_JAR, CableClub_EventScript_DirectCornerNoBerry_Frlg
	multichoice 0, 0, MULTI_WIRELESS_NO_RECORD, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_WirelessTrade_Frlg
	case 1, CableClub_EventScript_WirelessBattleSelect_Frlg
	case 2, CableClub_EventScript_WirelessBerryCrush_Frlg
	case 3, CableClub_EventScript_AbortLink_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink_Frlg
	end

CableClub_EventScript_DirectCornerNoBerry_Frlg::
	multichoice 0, 0, MULTI_WIRELESS_NO_RECORD_BERRY, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_WirelessTrade_Frlg
	case 1, CableClub_EventScript_WirelessBattleSelect_Frlg
	case 2, CableClub_EventScript_AbortLink_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink_Frlg
	end

CableClub_EventScript_WirelessTrade_Frlg::
	msgbox CableClub_Text_TradePokemon_Frlg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CableClub_EventScript_AbortLink_Frlg
	call CableClub_EventScript_CheckPartyTradeRequirements_Frlg
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_AbortLink_Frlg
	setvar VAR_0x8004, LINK_GROUP_TRADE
	goto CableClub_EventScript_SaveAndChooseLinkLeader_Frlg
	end

CableClub_EventScript_WirelessBattleSelect_Frlg::
	message CableClub_Text_PlayWhichBattleMode_Frlg
	waitmessage
	multichoice 0, 0, MULTI_BATTLE_MODE, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_WirelessSingleBattle_Frlg
	case 1, CableClub_EventScript_WirelessDoubleBattle_Frlg
	case 2, CableClub_EventScript_WirelessMultiBattle_Frlg
	case 3, CableClub_EventScript_WirelessBattleInfo_Frlg
	case 4, CableClub_EventScript_AbortLink_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink_Frlg
	end

CableClub_EventScript_WirelessSingleBattle_Frlg::
	setvar VAR_0x8004, LINK_GROUP_SINGLE_BATTLE
	goto CableClub_EventScript_SaveAndChooseLinkLeader_Frlg
	end

CableClub_EventScript_WirelessDoubleBattle_Frlg::
	special HasEnoughMonsForDoubleBattle
	goto_if_ne VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS, CableClub_EventScript_TwoMonsNeededForWirelessDoubleBattle_Frlg
	setvar VAR_0x8004, LINK_GROUP_DOUBLE_BATTLE
	goto CableClub_EventScript_SaveAndChooseLinkLeader_Frlg
	end

CableClub_EventScript_TwoMonsNeededForWirelessDoubleBattle_Frlg::
	msgbox CableClub_Text_NeedTwoMonsForDoubleBattle_Frlg
	goto CableClub_EventScript_WirelessBattleSelect_Frlg
	end

CableClub_EventScript_WirelessMultiBattle_Frlg::
	setvar VAR_0x8004, LINK_GROUP_MULTI_BATTLE
	goto CableClub_EventScript_SaveAndChooseLinkLeader_Frlg
	end

CableClub_EventScript_WirelessBattleInfo_Frlg::
	msgbox CableClub_Text_ExplainBattleModes_Frlg
	goto CableClub_EventScript_WirelessBattleSelect_Frlg
	end

CableClub_EventScript_WirelessBerryCrush_Frlg::
	msgbox CableClub_Text_UseBerryCrush_Frlg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CableClub_EventScript_AbortLink_Frlg
	special HasAtLeastOneBerry
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_NeedBerryForBerryCrush_Frlg
	setvar VAR_0x8004, LINK_GROUP_BERRY_CRUSH
	goto CableClub_EventScript_SaveAndChooseLinkLeader_Frlg
	end

CableClub_EventScript_NeedBerryForBerryCrush_Frlg::
	msgbox CableClub_Text_NeedBerryForBerryCrush_Frlg
	goto CableClub_EventScript_DirectCornerSelectService_Frlg
	end

CableClub_EventScript_SaveAndChooseLinkLeader_Frlg::
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink_Frlg
	switch VAR_0x8004
	case LINK_GROUP_TRADE, CableClub_EventScript_ChooseLinkLeaderFrom2_Frlg
	case LINK_GROUP_SINGLE_BATTLE, CableClub_EventScript_ChooseLinkLeaderFrom2_Frlg
	case LINK_GROUP_DOUBLE_BATTLE, CableClub_EventScript_ChooseLinkLeaderFrom2_Frlg
	case LINK_GROUP_MULTI_BATTLE, CableClub_EventScript_ChooseLinkLeaderFrom4_Frlg
	case LINK_GROUP_BERRY_CRUSH, CableClub_EventScript_ChooseLinkLeader_Frlg
	end

CableClub_EventScript_ChooseLinkLeaderFrom2_Frlg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	message CableClub_Text_ChooseGroupLeaderOfTwo_Frlg
	waitmessage
	call EventScript_RestorePrevTextColor
	multichoice 13, 6, MULTI_LINK_LEADER, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_TryJoinGroup2Players_Frlg
	case 1, CableClub_EventScript_TryLeadGroup2Players_Frlg
	case 2, CableClub_EventScript_AbortLink_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink_Frlg
	end

CableClub_EventScript_TryLeadGroup2Players_Frlg::
	call CableClub_EventScript_TryBecomeLinkLeader_Frlg
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom_Frlg
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeaderFrom2_Frlg
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryLeadGroup2Players_Frlg
	release
	return

CableClub_EventScript_TryJoinGroup2Players_Frlg::
	call CableClub_EventScript_TryJoinLinkGroup_Frlg
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom_Frlg
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeaderFrom2_Frlg
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryJoinGroup2Players_Frlg
	release
	return

CableClub_EventScript_ChooseLinkLeaderFrom4_Frlg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	message CableClub_Text_ChooseGroupLeaderOfFour_Frlg
	waitmessage
	call EventScript_RestorePrevTextColor
	multichoice 13, 6, MULTI_LINK_LEADER, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_TryJoinGroup4Players_Frlg
	case 1, CableClub_EventScript_TryLeadGroup4Players_Frlg
	case 2, CableClub_EventScript_AbortLink_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink_Frlg
	end

CableClub_EventScript_TryLeadGroup4Players_Frlg::
	call CableClub_EventScript_TryBecomeLinkLeader_Frlg
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom_Frlg
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeaderFrom4_Frlg
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryLeadGroup4Players_Frlg
	release
	return

CableClub_EventScript_TryJoinGroup4Players_Frlg::
	call CableClub_EventScript_TryJoinLinkGroup_Frlg
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom_Frlg
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeaderFrom4_Frlg
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryJoinGroup4Players_Frlg
	release
	return

CableClub_EventScript_ChooseLinkLeader_Frlg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	message CableClub_Text_ChooseGroupLeader_Frlg
	waitmessage
	call EventScript_RestorePrevTextColor
	multichoice 13, 6, MULTI_LINK_LEADER, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_TryJoinGroupXPlayers_Frlg
	case 1, CableClub_EventScript_TryLeadGroupXPlayers_Frlg
	case 2, CableClub_EventScript_AbortLink_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink_Frlg
	end

CableClub_EventScript_TryLeadGroupXPlayers_Frlg::
	call CableClub_EventScript_TryBecomeLinkLeader_Frlg
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom_Frlg
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeader_Frlg
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryLeadGroupXPlayers_Frlg
	release
	return

CableClub_EventScript_TryJoinGroupXPlayers_Frlg::
	call CableClub_EventScript_TryJoinLinkGroup_Frlg
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom_Frlg
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeader_Frlg
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryJoinGroupXPlayers_Frlg
	release
	return

CableClub_EventScript_TryBecomeLinkLeader_Frlg::
	special TryBecomeLinkLeader
	waitstate
	return

CableClub_EventScript_TryJoinLinkGroup_Frlg::
	special TryJoinLinkGroup
	waitstate
	return

CableClub_EventScript_EnterWirelessLinkRoom_Frlg::
	messageautoscroll CableClub_Text_DirectYouToYourRoom_Frlg
	waitmessage
	delay 60
	closemessage
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call CableClub_EventScript_OpenDirectCornerBarrier_Frlg
	special DrawWholeMapView
	playse SE_CLICK
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement LOCALID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 9, 1
	waitdooranim
	applymovement LOCALID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideplayer
	closedoor 9, 1
	waitdooranim
	release
	waitstate
	end

CableClub_EventScript_ShowWirelessCommunicationScreen_Frlg::
	lockall
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_NotReadyYet_Frlg
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_AdapterNotConnected_Frlg
	fadescreen FADE_TO_BLACK
	special ShowWirelessCommunicationScreen
	waitstate
	msgbox CableClub_Text_ParticipantsStepUpToCounter_Frlg
	releaseall
	end

CableClub_EventScript_AdapterNotConnected_Frlg::
	msgbox CableClub_Text_AdapterNotConnected_Frlg
	releaseall
	end

CableClub_EventScript_OpenUnionRoomBarrier_Frlg::
	setmetatile 5, 3, METATILE_PokemonCenterFrlg_Floor_ShadeLeft, 0
	return

CableClub_EventScript_CloseUnionRoomBarrier_Frlg::
	setmetatile 5, 3, METATILE_PokemonCenterFrlg_CounterBarrier, 1
	return

CableClub_EventScript_OpenDirectCornerBarrier_Frlg::
	setmetatile 9, 3, METATILE_PokemonCenterFrlg_Floor_ShadeLeft, 0
	return

CableClub_EventScript_CloseDirectCornerBarrier_Frlg::
	setmetatile 9, 3, METATILE_PokemonCenterFrlg_CounterBarrier, 1
	return

CableClub_EventScript_OpenGameCornerBarrier_Frlg::
	setmetatile 5, 3, METATILE_GameCorner_CheckeredFloor_ShadeLeft, 0
	return

CableClub_EventScript_CloseGameCornerBarrier_Frlg::
	setmetatile 5, 3, METATILE_GameCorner_CounterBarrier, 1
	return

CableClub_OnResume_Frlg::
	special InitUnionRoom
	end

JoyfulGameCorner_EventScript_InfoMan2_Frlg::
	lock
	faceplayer
	message Text_DescribeWhichGame_Frlg
	waitmessage
	multichoice 0, 0, MULTI_WIRELESS_MINIGAME, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_PokemonJumpInfo_Frlg
	case 1, CableClub_EventScript_DodrioBerryPickingInfo_Frlg
	case 2, CableClub_EventScript_MinigameInfoExit_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_MinigameInfoExit_Frlg
	end

CableClub_EventScript_PokemonJumpInfo_Frlg::
	msgbox Text_PokemonJumpInfo_Frlg
	release
	end

CableClub_EventScript_DodrioBerryPickingInfo_Frlg::
	msgbox Text_DodrioBerryPickingInfo_Frlg
	release
	end

CableClub_EventScript_MinigameInfoExit_Frlg::
	msgbox Text_TalkToManToPlay_Frlg
	release
	end

JoyfulGameCorner_EventScript_MinigameAttendant_Frlg::
	lock
	faceplayer
	message Text_WelcomeCanYouWait_Frlg
	waitmessage
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_AdapterNotConnectedMinigame_Frlg
	delay 60
	message Text_PlayWhichGame_Frlg
	waitmessage
	multichoice 0, 0, MULTI_WIRELESS_MINIGAME, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_PlayPokemonJump_Frlg
	case 1, CableClub_EventScript_PlayDodrioBerryPicking_Frlg
	case 2, CableClub_EventScript_AbortMinigame_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_AbortMinigame_Frlg
	end

CableClub_EventScript_PlayPokemonJump_Frlg::
	setvar VAR_0x8005, 0
	special IsPokemonJumpSpeciesInParty
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_NoEligiblePkmn_Frlg
	msgbox Text_EnterWhichPokemon_Frlg
	setvar VAR_0x8005, 0
	special ChooseMonForWirelessMinigame
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, CableClub_EventScript_AbortMinigame_Frlg
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortMinigame_Frlg
	setvar VAR_0x8004, LINK_GROUP_POKEMON_JUMP
	goto CableClub_EventScript_ChooseLinkLeaderMinigame_Frlg
	end

CableClub_EventScript_PlayDodrioBerryPicking_Frlg::
	setvar VAR_0x8005, 1
	special IsDodrioInParty
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_NoEligiblePkmn_Frlg
	msgbox Text_EnterWhichPokemon_Frlg
	setvar VAR_0x8005, 1
	special ChooseMonForWirelessMinigame
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, CableClub_EventScript_AbortMinigame_Frlg
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortMinigame_Frlg
	setvar VAR_0x8004, LINK_GROUP_BERRY_PICKING
	goto CableClub_EventScript_ChooseLinkLeaderMinigame_Frlg
	end

CableClub_EventScript_ChooseLinkLeaderMinigame_Frlg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	message CableClub_Text_ChooseGroupLeader_Frlg
	waitmessage
	call EventScript_RestorePrevTextColor
	multichoice 13, 6, MULTI_LINK_LEADER, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_TryJoinMinigameLinkGroup_Frlg
	case 1, CableClub_EventScript_TryBecomeMinigameLinkLeader_Frlg
	case 2, CableClub_EventScript_AbortMinigame_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_AbortMinigame_Frlg
	end

CableClub_EventScript_TryBecomeMinigameLinkLeader_Frlg::
	call CableClub_EventScript_TryBecomeLinkLeader_Frlg
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterMinigame_Frlg
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeaderMinigame_Frlg
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryBecomeMinigameLinkLeader_Frlg
	release
	return

CableClub_EventScript_TryJoinMinigameLinkGroup_Frlg::
	call CableClub_EventScript_TryJoinLinkGroup_Frlg
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterMinigame_Frlg
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeaderMinigame_Frlg
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryJoinMinigameLinkGroup_Frlg
	release
	return

CableClub_EventScript_EnterMinigame_Frlg::
	messageautoscroll Text_AllGoodToGo_Frlg
	waitmessage
	delay 120
	closemessage
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call CableClub_EventScript_OpenGameCornerBarrier_Frlg
	special DrawWholeMapView
	playse SE_CLICK
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement LOCALID_PLAYER, Movement_PlayerEnterMinigameRoom
	waitmovement 0
	hideplayer
	release
	waitstate
	end

CableClub_EventScript_AdapterNotConnectedMinigame_Frlg::
	msgbox Text_AdapterNotConnectedMinigame_Frlg
	release
	end

CableClub_EventScript_NoEligiblePkmn_Frlg::
	msgbox EventScript_ExplainPokemonJumpRequirements_Frlg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CableClub_EventScript_AbortMinigame_Frlg
	call_if_eq VAR_0x8005, 0, CableClub_EventScript_ExplainPokemonJumpRequirements_Frlg
	call_if_eq VAR_0x8005, 1, CableClub_EventScript_ExplainDodrioBerryPickingRequirements_Frlg
	goto CableClub_EventScript_AbortMinigame_Frlg
	end

CableClub_EventScript_ExplainPokemonJumpRequirements_Frlg::
	msgbox Text_ShortJumpingPokemonAllowed_Frlg
	return

CableClub_EventScript_ExplainDodrioBerryPickingRequirements_Frlg::
	msgbox Text_OnlyDodrioAllowed_Frlg
	return

TwoIsland_JoyfulGameCorner_EventScript_ShowPokemonJumpRecords::
	lockall
	special ShowPokemonJumpRecords
	waitstate
	releaseall
	end

TwoIsland_JoyfulGameCorner_EventScript_ShowDodrioBerryPickingRecords::
	lockall
	special ShowDodrioBerryPickingRecords
	waitstate
	releaseall
	end

CableClub_Text_WelcomeWhichCableClubService_Frlg::
	.string "Benvenuto nel CLUB CAVO\n"
	.string "POKéMON.\p"
	.string "Quale dei nostri servizi vuoi\n"
	.string "usare?$"

CableClub_Text_WhichService_Frlg::
	.string "Quale dei nostri servizi vuoi\n"
	.string "usare?$"

CableClub_Text_TradeMonsUsingLinkCable_Frlg::
	.string "Scambia POKéMON con un altro giocatore\n"
	.string "usando un cavo GBA Game Link.$"

CableClub_Text_BattleUsingLinkCable_Frlg::
	.string "Puoi lottare contro un altro\n"
	.string "ALLENATORE con un cavo GBA.$"

@ Unused, translated in Emerald
CableClub_Text_CloseThisMenu_Frlg::
	.string "おわります$"

CableClub_Text_NeedTwoMonsForDoubleBattle_Frlg::
	.string "Per una LOTTA DOPPIA devi\n"
	.string "avere almeno due POKéMON.$"

CableClub_Text_NeedTwoMonsToTrade_Frlg::
	.string "Per scambiare devi avere con te\n"
	.string "almeno due POKéMON.$"

CableClub_Text_CantTradeEnigmaBerry_Frlg::
	.string "Un POKéMON che tiene la {STR_VAR_1}\n"
	.string "non può essere scambiato.$"

CableClub_Text_PleaseWaitBCancel_Frlg::
	.string "Attendi.\n"
	.string "… … Tasto B: Annulla$"

CableClub_Text_WhenAllPlayersReadyAConfirmBCancel_Frlg::
	.string "Quando tutti sono pronti…\n"
	.string "Tasto A: Conferma\l"
	.string "Tasto B: Annulla$"

CableClub_Text_StartLinkWithXPlayersAConfirmBCancel_Frlg::
	.string "Collega con {STR_VAR_1} giocatori.\n"
	.string "Tasto A: Conferma\l"
	.string "Tasto B: Annulla$"

CableClub_Text_AwaitingLinkupBCancel_Frlg::
	.string "In attesa del collegamento…\n"
	.string "… … Tasto B: Annulla$"

@ Unused, translated in Emerald
CableClub_Text_OkayToSaveProgress_Frlg::
	.string "はじめる　まえに　レポートを\n"
	.string "かきますが　よろしいですか？$"

CableClub_Text_PleaseEnter_Frlg::
	.string "Entra, prego.$"

CableClub_Text_DirectYouToYourRoom_Frlg::
	.string "Ora ti accompagno nella tua stanza.$"

CableClub_Text_SomeoneIsNotReadyToLink_Frlg::
	.string "Qualcuno non è pronto a collegarsi.\p"
	.string "Torna dopo che tutti\n"
	.string "si saranno preparati.$"

CableClub_Text_LinkErrorPleaseReset_Frlg::
	.string "Spiacente, c'è un errore di collegamento…\n"
	.string "Riavvia e riprova.$"

CableClub_Text_PlayersMadeDifferentSelections_Frlg::
	.string "I partner del collegamento sembrano\n"
	.string "aver scelto opzioni diverse.$"

CableClub_Text_PleaseVisitAgain_Frlg::
	.string "Torna a trovarci.$"

CableClub_Text_IncorrectNumberOfParticipants_Frlg::
	.string "Il numero di partecipanti non\n"
	.string "è corretto.$"

CableClub_Text_CantSingleBattleWithXPlayers_Frlg::
	.string "La modalità LOTTA IN SINGOLO non\n"
	.string "si può usare in {STR_VAR_1} giocatori.$"

CableClub_Text_CantDoubleBattleWithXPlayers_Frlg::
	.string "La modalità LOTTA IN DOPPIO non\n"
	.string "si può usare in {STR_VAR_1} giocatori.$"

CableClub_Text_NeedFourPlayers_Frlg::
	.string "Servono quattro giocatori per questa\n"
	.string "Modalità Lotta.$"

CableClub_Text_PleaseConfirmNumberAndRestart_Frlg::
	.string "Conferma il numero di\n"
	.string "giocatori e ricomincia.$"

Text_TerminateLinkIfYouLeaveRoom_Frlg::
	.string "Il collegamento si chiuderà se\n"
	.string "esci dalla stanza. Va bene?$"

Text_TerminateLinkConfirmation_Frlg::
	.string "Chiusura del collegamento…\n"
	.string "Verrai accompagnato fuori\l"
	.string "dalla stanza. Attendi.$"

Text_TrainerTooBusyToNotice_Frlg::
	.string "Questo ALLENATORE è troppo\n"
	.string "occupato…$"

Text_LookedAtPlayersTrainerCard_Frlg::
	.string "Evvai! Ho visto la {STR_VAR_1}\n"
	.string "SCHEDA ALLENATORE!$"

Text_LookedAtPlayersTrainerCardColored_Frlg::
	.string "Score! Got to look at {STR_VAR_1}'s\n"
	.string "TRAINER CARD!\p"
	.string "It's a {STR_VAR_2} card!$"

Text_TakeSeatStartBattle_Frlg::
	.string "Prendi posto e inizia\n"
	.string "la lotta.$"

Text_TakeSeatStartTrade_Frlg::
	.string "Prendi posto e inizia\n"
	.string "lo scambio.$"

@ Unused, leftover from RS
RecordCorner_Text_ThanksForComing_Frlg::
	.string "ごりよう　ありがとう　ございました$"

CableClub_Text_TrainerCardDataOverwritten_Frlg::
	.string "I dati della SCHEDA ALLENATORE\n"
	.string "saranno sovrascritti.$"

CableClub_Text_HopeToSeeYouAgain_Frlg::
	.string "Spero di rivederti!$"

CableClub_Text_NotSetUpForFarAwayRegion_Frlg::
	.string "Mi dispiace molto.\p"
	.string "Non siamo attrezzati per scambiare\n"
	.string "con ALLENATORI lontani in un'altra\l"
	.string "regione…$"

CableClub_Text_OtherTrainerNotReady_Frlg::
	.string "L'altro ALLENATORE non è pronto.$"

CableClub_Text_YouHaveAMonThatCantBeTaken_Frlg::
	.string "Hai almeno un POKéMON\n"
	.string "che non può essere portato.$"

CableClub_Text_AdapterNotConnected_Frlg::
	.string "L'Adattatore Wireless non è\n"
	.string "collegato bene.$"

CableClub_Text_ParticipantsStepUpToCounter_Frlg::
	.string "I partecipanti sono invitati a farsi\n"
	.string "avanti al banco accoglienza.$"

@ Unused, translated in Emerald
CableClub_Text_Hello_Frlg::
	.string "こんにちは！$"

@ Unused, translated in Emerald
CableClub_Text_PleaseWait_Frlg::
	.string "しょうしょう　おまちください$"

CableClub_Text_YouMayTradeHere_Frlg::
	.string "Qui puoi scambiare i tuoi POKéMON\n"
	.string "con un altro ALLENATORE.$"

CableClub_Text_YouMayBattleHere_Frlg::
	.string "Puoi lottare con i tuoi amici\n"
	.string "qui.$"

CableClub_Text_CanMakeBerryPowder_Frlg::
	.string "Da due a cinque ALLENATORI possono\n"
	.string "creare PULVISCOPPIO insieme.$"

@ Unused, Record Mix nopped
CableClub_Text_CanMixRecords_Frlg::
	.string "ワイヤレス　クラブでの\n"
	.string "あそびかたを　せつめいします$"

CableClub_Text_CancelSelectedItem_Frlg::
	.string "Annulla la voce di MENU scelta.$"

@ Unused, translated in Emerald
CableClub_Text_WhichBattleMode_Frlg::
	.string "どちらの　しょうぶに　しますか？$"

@ Unused, translated in Emerald
CableClub_Text_ReturnsToPreviousStep_Frlg::
	.string "ひとつ　まえに　もどります$"

CableClub_Text_NeedBerryForBerryCrush_Frlg::
	.string "Per usare il servizio SPRIMIBACCA,\n"
	.string "devi avere almeno una BACCA.$"

CableClub_Text_NeedTwoMonsForUnionRoom_Frlg::
	.string "Per entrare nella SALA UNIONE devi\n"
	.string "avere almeno due POKéMON.$"

CableClub_Text_NoEnigmaBerryInUnionRoom_Frlg::
	.string "Nessun POKéMON che tiene la {STR_VAR_1}\n"
	.string "può entrare nella SALA UNIONE.$"

CableClub_Text_UnionRoomAdapterNotConnected_Frlg::
	.string "Questa è la SALA UNIONE del CLUB\n"
	.string "WIRELESS POKéMON.\p"
	.string "Purtroppo il tuo Adattatore Wireless\n"
	.string "non è collegato bene.\p"
	.string "Torna a trovarci, mi raccomando.$"

Text_PlayerIsPlayingRightNowGoForIt_Frlg::
	.string "Sembra che {STR_VAR_1} stia\n"
	.string "giocando ora.\l"
	.string "Forza, vai!$"

Text_DescribeWhichGame_Frlg::
	.string "Posso spiegarti le regole,\n"
	.string "se vuoi.\p"
	.string "Quale gioco ti descrivo?$"

Text_PokemonJumpInfo_Frlg::
	.string "“POKéMON JUMP”\p"
	.string "Fai saltare i tuoi POKéMON\n"
	.string "oltre la corda LIANA con A.\p"
	.string "Possono partecipare solo i mini\n"
	.string "POKéMON di 70 cm o meno.\p"
	.string "I POKéMON che solo nuotano, scavano\n"
	.string "o volano non sono bravi a saltare.\p"
	.string "Perciò quei POKéMON non possono\n"
	.string "partecipare.\p"
	.string "Se tutti saltano a tempo\n"
	.string "succedono cose belle.$"

Text_DodrioBerryPickingInfo_Frlg::
	.string "“DODRIO BERRY-PICKING”\p"
	.string "Guida le tre teste di DODRIO\n"
	.string "per prendere le BACCHE che cadono.\p"
	.string "Premi destra, su o sinistra sul\n"
	.string "{PLUS} Control Pad per muoverle.\p"
	.string "Per questo gioco serve\n"
	.string "un DODRIO.$"

Text_TalkToManToPlay_Frlg::
	.string "Se vuoi giocare,\n"
	.string "parla all'uomo accanto a me.$"

Text_WelcomeCanYouWait_Frlg::
	.string "Ciao, benvenuto!\n"
	.string "Puoi giocare via\l"
	.string "Wireless Communication System.\p"
	.string "Puoi aspettare un attimo?$"

CableClub_Text_ComeAgain_Frlg::
	.string "Va bene, torna presto!$"

Text_AdapterNotConnectedMinigame_Frlg::
	.string "L'Adattatore Wireless non è\n"
	.string "collegato.\p"
	.string "Torna quando sarà collegato!$"

Text_PlayWhichGame_Frlg::
	.string "Bene, a quale gioco vuoi\n"
	.string "giocare?$"

Text_EnterWhichPokemon_Frlg::
	.string "Quale POKéMON vuoi\n"
	.string "iscrivere?$"

Text_AllGoodToGo_Frlg::
	.string "Ok, è tutto pronto.\n"
	.string "Non lasciarti battere dagli altri!$"

@ Unused, translated in Emerald
Text_LeavingDoComeAgain_Frlg::
	.string "きょうは　けえるのか？\n"
	.string "またこいよ！$"

EventScript_ExplainPokemonJumpRequirements_Frlg::
	.string "Non sembra che tu abbia dei\n"
	.string "POKéMON che possano partecipare…\p"
	.string "Vuoi che ti spieghi quali\n"
	.string "POKéMON possono partecipare?$"

Text_ShortJumpingPokemonAllowed_Frlg::
	.string "“POKéMON JUMP” è aperto ai POKéMON\n"
	.string "di 70 cm o meno.\p"
	.string "Non puoi iscrivere quelli\n"
	.string "che non sanno saltare.\p"
	.string "Tipo i POKéMON che solo\n"
	.string "nuotano, scavano o volano.\p"
	.string "Questo è tutto.$"

Text_OnlyDodrioAllowed_Frlg::
	.string "“DODRIO BERRY-PICKING”…\n"
	.string "Beh, il nome dice tutto.\p"
	.string "Per giocare ti serve\n"
	.string "un DODRIO.$"

@ Unused, translated in Emerald
Text_RetryFromStartPlease_Frlg::
	.string "もういちど　はじめから\n"
	.string "やりなおして　みて　くれ$"

CableClub_Text_WelcomeWhichDirectCornerRoom_Frlg::
	.string "Benvenuto nell'ANGOLO DIRETTO del\n"
	.string "CLUB WIRELESS POKéMON.\p"
	.string "Qui puoi interagire direttamente\n"
	.string "con i tuoi amici.\p"
	.string "In quale sala vuoi\n"
	.string "entrare?$"

CableClub_Text_TradePokemon_Frlg::
	.string "Vuoi scambiare dei POKéMON?$"

CableClub_Text_PlayWhichBattleMode_Frlg::
	.string "Quale Modalità Lotta vuoi\n"
	.string "giocare?$"

CableClub_Text_UseBerryCrush_Frlg::
	.string "Vuoi usare il Sistema\n"
	.string "SPRIMIBACCA?$"

CableClub_Text_ExplainBattleModes_Frlg::
	.string "Ci sono tre modalità di lotta.\p"
	.string "SINGLE BATTLE è per due ALLENATORI\n"
	.string "con uno o più POKéMON ciascuno.\p"
	.string "Ogni ALLENATORE può avere un POKéMON\n"
	.string "in lotta alla volta.\p"
	.string "DOUBLE BATTLE è per due ALLENATORI\n"
	.string "con due o più POKéMON ciascuno.\p"
	.string "Ogni ALLENATORE manderà due\n"
	.string "POKéMON in lotta alla volta.\p"
	.string "MULTI BATTLE è per quattro ALLENATORI\n"
	.string "con uno o più POKéMON ciascuno.\p"
	.string "Ogni ALLENATORE può avere un POKéMON\n"
	.string "in lotta alla volta.$"

CableClub_Text_ChooseGroupLeaderOfTwo_Frlg::
	.string "Decidete chi di voi due\n"
	.string "sarà il CAPO.\p"
	.string "L'altro giocatore deve poi scegliere\n"
	.string "“UNISCITI AL GRUPPO.”$"

CableClub_Text_ChooseGroupLeaderOfFour_Frlg::
	.string "Decidete chi di voi quattro\n"
	.string "sarà il CAPO GRUPPO.\p"
	.string "Gli altri giocatori devono poi scegliere\n"
	.string "“UNISCITI AL GRUPPO.”$"

CableClub_Text_ChooseGroupLeader_Frlg::
	.string "Decidete chi di voi\n"
	.string "sarà il CAPO GRUPPO.\p"
	.string "Gli altri giocatori devono poi scegliere\n"
	.string "“UNISCITI AL GRUPPO.”$"

CableClub_Text_WelcomeUnionRoomEnter_Frlg::
	.string "Benvenuto nella SALA UNIONE del CLUB\n"
	.string "WIRELESS POKéMON.\p"
	.string "Qui puoi interagire direttamente\n"
	.string "con altri ALLENATORI, alcuni\l"
	.string "che potresti non conoscere.\p"
	.string "Vuoi entrare nella SALA?$"

CableClub_Text_UnionRoomInfo_Frlg::
	.string "Gli ALLENATORI nella SALA UNIONE\n"
	.string "saranno i giocatori intorno a te\l"
	.string "che sono entrati anche loro.\p"
	.string "Qui puoi fare tante cose,\n"
	.string "come scambiarti saluti.\p"
	.string "Puoi far entrare due POKéMON fino\n"
	.string "al Lv. 30 per una lotta uno contro uno.\p"
	.string "Puoi partecipare a una chat con\n"
	.string "da due a cinque persone.\p"
	.string "Oppure puoi registrare un POKéMON\n"
	.string "da scambiare.\p"
	.string "Vuoi entrare nella SALA?$"

CableClub_Text_EnjoyUnionRoom_Frlg::
	.string "Spero che ti divertirai nella\n"
	.string "SALA UNIONE.$"

CableClub_Text_FirstTimeRightThisWay_Frlg::
	.string "Ciao!\n"
	.string "Mi chiamo TEALA.\p"
	.string "Questa dev'essere la tua prima\n"
	.string "visita quassù.\p"
	.string "Ti mostro come funziona il Sistema\n"
	.string "di Comunicazione Wireless.\p"
	.string "Prima ti mostro questo\n"
	.string "piano del nostro CENTRO POKéMON.\p"
	.string "Da questa parte, prego.$"

CableClub_Text_ExplainWirelessClubFirstTime_Frlg::
	.string "All'ultimo piano ci sono due\n"
	.string "sale.\p"
	.string "Prima, la sala a sinistra.\n"
	.string "È la SALA UNIONE.\p"
	.string "Puoi collegarti con gli ALLENATORI\n"
	.string "intorno a te entrati\l"
	.string "nella SALA UNIONE.\p"
	.string "Con loro puoi chattare, lottare\n"
	.string "e scambiare.\p"
	.string "Seconda, la sala a destra è\n"
	.string "l'ANGOLO DIRETTO.\p"
	.string "Puoi scambiare o lottare con i\n"
	.string "POKéMON dei tuoi amici qui.\p"
	.string "Se l'Adattatore Wireless non è\n"
	.string "collegato, puoi comunque unirti\l"
	.string "con un cavo GBA Game Link.\p"
	.string "In tal caso, devi andare\n"
	.string "all'ANGOLO DIRETTO.\p"
	.string "Spero che apprezzerai il Sistema\n"
	.string "di Comunicazione Wireless.$"

CableClub_Text_AskAboutLinking_Frlg::
	.string "Ciao, {PLAYER}!\p"
	.string "Sono io, TEALA, l'addetta al\n"
	.string "PIANO 2 del CENTRO POKéMON.\p"
	.string "Volevi chiedermi qualcosa\n"
	.string "sul collegamento?$"

CableClub_Text_ExplainWirelessClub_Frlg::
	.string "Ti spiego come funziona il\n"
	.string "CLUB WIRELESS POKéMON.\p"
	.string "Qui, all'ultimo piano, ci sono\n"
	.string "due sale.\p"
	.string "Prima, la sala a sinistra.\n"
	.string "È la SALA UNIONE.\p"
	.string "Puoi collegarti con gli ALLENATORI\n"
	.string "intorno a te entrati\l"
	.string "nella SALA UNIONE.\p"
	.string "Con loro puoi chattare, lottare\n"
	.string "e scambiare.\p"
	.string "Seconda, la sala a destra è\n"
	.string "l'ANGOLO DIRETTO.\p"
	.string "Puoi scambiare o lottare con i\n"
	.string "POKéMON dei tuoi amici qui.\p"
	.string "A volte potresti non riuscire a\n"
	.string "trovare gli amici nella SALA UNIONE\l"
	.string "o nell'ANGOLO DIRETTO.\p"
	.string "In tal caso, avvicinati\n"
	.string "ai tuoi amici.\p"
	.string "Se l'Adattatore Wireless non è\n"
	.string "collegato, puoi comunque unirti\l"
	.string "con un cavo GBA Game Link.\p"
	.string "In tal caso, devi andare\n"
	.string "all'ANGOLO DIRETTO.\p"
	.string "Spero che apprezzerai il Sistema\n"
	.string "di Comunicazione Wireless.$"

CableClub_Text_HopeYouEnjoyWirelessSystem_Frlg::
	.string "Spero che apprezzerai il Sistema\n"
	.string "di Comunicazione Wireless.$"

Text_WirelessClubUndergoingAdjustments::
	.string "Mi dispiace tanto.\n"
	.string "Il POKéMON WIRELESS CLUB è\l"
	.string "in fase di modifica.$"

Text_AppearsToBeUndergoingAdjustments::
	.string "Sembra che siano in corso\n"
	.string "delle modifiche…$"
