BattleFrontier_BattlePikeThreePathRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePikeRoom_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeThreePathRoom_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeThreePathRoom_OnWarp
	.byte 0

BattleFrontier_BattlePikeThreePathRoom_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpToLobby
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePikeThreePathRoom_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_5, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_SetHintRoom
	map_script_2 VAR_TEMP_5, 1, BattleFrontier_BattlePikeThreePathRoom_EventScript_GivePikeQueenHint
	.2byte 0

BattleFrontier_BattlePikeThreePathRoom_OnWarp:
	map_script_2 VAR_TEMP_4, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePikeThreePathRoom_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_4, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpToLobby::
	warp MAP_BATTLE_FRONTIER_BATTLE_PIKE_LOBBY, 5, 6
	waitstate
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattlePikeThreePathRoom_Text_AwaitingReturnSaveBeforeResume
	waitmessage
	pike_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_PleaseEnjoyChallenge, MSGBOX_DEFAULT
	closemessage
	releaseall
	frontier_settrainers
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 99
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_Attendant::
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Room number
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom1
	case 3, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom3
	case 5, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom5
	case 7, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom7
	case 9, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom9
	case 11, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom11
	case 13, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom13
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom1::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom1, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom3::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom3, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom5::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom5, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom7::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom7, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom9::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom9, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom11::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom11, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom13::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom13, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_ContinueWithChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePikeThreePathRoom_EventScript_AskSaveChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeThreePathRoom_EventScript_AskSaveChallenge
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_PauseChallenge::
	frontier_saveparty
	message BattleFrontier_BattlePikeThreePathRoom_Text_SavingYourData
	waitmessage
	special LoadPlayerParty
	pike_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AskSaveChallenge::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_SaveChallengeAndQuit, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_BattlePikeThreePathRoom_EventScript_PauseChallenge
	case NO, BattleFrontier_BattlePikeThreePathRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeThreePathRoom_EventScript_AskRetireChallenge
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AskRetireChallenge::
	message BattleFrontier_BattlePikeThreePathRoom_Text_RetireFromChallenge
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePike_EventScript_Retire
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_SetHintRoom::
	pike_sethintroom
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePikeThreePathRoom_EventScript_SetPikeQueenHint
	setvar VAR_TEMP_5, 255
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_SetPikeQueenHint::
	setvar VAR_TEMP_5, 1
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_GivePikeQueenHint::
	applymovement LOCALID_PIKE_HINT_GIVER, BattleFrontier_BattlePikeThreePathRoom_Movement_HintGiverApproachPlayer
	waitmovement 0
	lockall
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_TerrifyingEvent, MSGBOX_DEFAULT
	releaseall
	applymovement LOCALID_PIKE_HINT_GIVER, BattleFrontier_BattlePikeThreePathRoom_Movement_HintGiverReturnToPos
	waitmovement 0
	setvar VAR_TEMP_5, 255
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_HintGiver::
	pike_gethint
	goto_if_eq VAR_RESULT, PIKE_HINT_BRAIN, BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveBrainHint
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_FindingItDifficultToChoose, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_BattlePikeThreePathRoom_EventScript_AcceptHint
	case NO, BattleFrontier_BattlePikeThreePathRoom_EventScript_DeclineHint
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeThreePathRoom_EventScript_DeclineHint
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_DeclineHint::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_ApologizeForImpertinence, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AcceptHint::
	pike_gethintroomid
	switch VAR_RESULT
	case PIKE_ROOM_LEFT, BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveLeftRoomHint
	case PIKE_ROOM_CENTER, BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveCenterRoomHint
	case PIKE_ROOM_RIGHT, BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveRightRoomHint
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveLeftRoomHint::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutLeftPath, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveHint

BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveCenterRoomHint::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutCenterPath, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveHint

BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveRightRoomHint::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutRightPath, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveHint

BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveHint::
	pike_gethint
	switch VAR_RESULT
	case PIKE_HINT_NOSTALGIA, BattleFrontier_BattlePikeThreePathRoom_EventScript_HintNostalgia
	case PIKE_HINT_WHISPERING, BattleFrontier_BattlePikeThreePathRoom_EventScript_HintWhispering
	case PIKE_HINT_POKEMON, BattleFrontier_BattlePikeThreePathRoom_EventScript_HintPokemon
	case PIKE_HINT_PEOPLE, BattleFrontier_BattlePikeThreePathRoom_EventScript_HintPeople
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_HintNostalgia::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_WaveOfNostaliga, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_HintWhispering::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_HeardWhispering, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_HintPokemon::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_AromaOfPokemon, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_HintPeople::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_PresenceOfPeople, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveBrainHint::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_DreadfulPresence, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_Movement_HintGiverApproachPlayer:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

BattleFrontier_BattlePikeThreePathRoom_Movement_HintGiverReturnToPos:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	face_down
	step_end

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom1:
	.string "Ti trovi attualmente\n"
	.string "nella 1ª stanza…$"

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom3:
	.string "Ti trovi attualmente\n"
	.string "nella 3ª stanza…$"

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom5:
	.string "Ti trovi attualmente\n"
	.string "nella 5ª stanza…$"

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom7:
	.string "Ti trovi attualmente\n"
	.string "nella 7ª stanza…$"

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom9:
	.string "Ti trovi attualmente\n"
	.string "nella 9ª stanza…$"

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom11:
	.string "Ti trovi attualmente\n"
	.string "nella 11ª stanza…$"

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom13:
	.string "Ti trovi attualmente\n"
	.string "nella 13ª stanza…$"

BattleFrontier_BattlePikeThreePathRoom_Text_ContinueWithChallenge:
	.string "Vuoi continuare la\n"
	.string "tua Sfida?$"

BattleFrontier_BattlePikeThreePathRoom_Text_SaveChallengeAndQuit:
	.string "Vuoi salvare la Sfida e uscire\n"
	.string "dal gioco per ora?$"

BattleFrontier_BattlePikeThreePathRoom_Text_RetireFromChallenge:
	.string "Vuoi ritirarti dalla Sfida\n"
	.string "della Scelta di Lotta?$"

BattleFrontier_BattlePikeThreePathRoom_Text_AwaitingReturnSaveBeforeResume:
	.string "Ti aspettavamo al tuo ritorno…\p"
	.string "Prima di riprendere la Sfida\n"
	.string "di Lotta, salvo il gioco…$"

BattleFrontier_BattlePikeThreePathRoom_Text_PleaseEnjoyChallenge:
	.string "Please do enjoy your Battle Choice\n"
	.string "challenge…$"

BattleFrontier_BattlePikeThreePathRoom_Text_SavingYourData:
	.string "Salvo i tuoi dati…\n"
	.string "Un attimo, ti prego…$"

BattleFrontier_BattlePike_Text_PathBlockedNoTurningBack:
	.string "La via è bloccata!\n"
	.string "E non è possibile tornare indietro…$"

BattleFrontier_BattlePikeThreePathRoom_Text_FindingItDifficultToChoose:
	.string "Scusa il disturbo, ma…\p"
	.string "Forse fai fatica a scegliere\n"
	.string "il tuo sentiero?$"

BattleFrontier_BattlePikeThreePathRoom_Text_ApologizeForImpertinence:
	.string "Vedo…\n"
	.string "Scusami per la sfrontatezza…$"

BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutRightPath:
	.string "Ah, vediamo… Il sentiero\n"
	.string "a destra nasconde qualcosa…$"

BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutCenterPath:
	.string "Ah, vediamo… C'è qualcosa\n"
	.string "nel sentiero centrale…$"

BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutLeftPath:
	.string "Ah, vediamo… C'è qualcosa\n"
	.string "nel sentiero a sinistra…$"

BattleFrontier_BattlePikeThreePathRoom_Text_AromaOfPokemon:
	.string "Sembra emettere un profumo\n"
	.string "inconfondibile di POKéMON…$"

BattleFrontier_BattlePikeThreePathRoom_Text_PresenceOfPeople:
	.string "È… UN ALLENATORE?\n"
	.string "Sento la presenza di persone…$"

BattleFrontier_BattlePikeThreePathRoom_Text_HeardWhispering:
	.string "Mi pare di aver udito qualcosa…\n"
	.string "Forse un sussurro…$"

BattleFrontier_BattlePikeThreePathRoom_Text_WaveOfNostaliga:
	.string "Chissà perché, mi ha dato\n"
	.string "una strana nostalgia…$"

BattleFrontier_BattlePikeThreePathRoom_Text_TerrifyingEvent:
	.string "Mi dispiace dirlo…\p"
	.string "Un evento terribile, sì, orribile,\n"
	.string "vi attenderà tra poco…\p"
	.string "Vi consiglio la massima\n"
	.string "attenzione, il peggio…$"

BattleFrontier_BattlePikeThreePathRoom_Text_DreadfulPresence:
	.string "Sento ovunque una presenza\n"
	.string "inquietante…$"
