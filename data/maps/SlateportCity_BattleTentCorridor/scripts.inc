SlateportCity_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_BattleTentCorridor_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_BattleTentCorridor_OnWarp
	.byte 0

	@ This is Slateport Tent's version of the Battle Factory Pre-Battle Room

SlateportCity_BattleTentCorridor_OnWarp:
	map_script_2 VAR_TEMP_1, 0, SlateportCity_BattleTentCorridor_EventScript_SetUpObjects
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_SetUpObjects::
	setvar VAR_TEMP_1, 1
	goto_if_ne VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth
	setobjectxy LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, 2, 2
	turnobject LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, DIR_SOUTH
SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

SlateportCity_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, SlateportCity_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_EnterCorridor::
	goto_if_eq VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantEnter
	applymovement LOCALID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerEnter
	waitmovement 0
	goto_if_eq VAR_0x8006, 2, SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge
	slateporttent_generaterentalmons
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	slateporttent_rentmons
	waitstate
SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantExit
	applymovement LOCALID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerExit
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM, 4, 4
	waitstate
	end

SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle::
	factory_setopponentmons
	factory_resethelditems
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent::
	frontier_get FRONTIER_DATA_BATTLE_NUM
	call_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent
	call_if_eq VAR_RESULT, 2, SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, SlateportCity_BattleTentCorridor_EventScript_AskSwapMon
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge
	case 2, SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge

SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case YES, SlateportCity_BattleTentCorridor_EventScript_PauseChallenge
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case 0, SlateportCity_BattleTent_EventScript_WarpToLobbyLost
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskSwapMon::
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	case YES, SlateportCity_BattleTentCorridor_EventScript_SwapMons
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_SwapMons::
	fadescreen FADE_TO_BLACK
	slateporttent_swapmons
	waitstate
	goto_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_PauseChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait
	waitmessage
	slateporttent_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end

SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge::
	special SavePlayerParty
	factory_setparties 0
	goto SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_Movement_PlayerEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SlateportCity_BattleTentCorridor_Movement_PlayerExit:
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_BattleTentCorridor_Movement_AttendantEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

SlateportCity_BattleTentCorridor_Movement_AttendantExit:
	walk_up
	set_invisible
	step_end

@ Leftover text from when this was a Contest Hall in R/S
@ Unused
SlateportCity_ContestHall_Text_AdviceForContests:
	.string "Vuoi un consiglio gustoso\n"
	.string "per le GARE?\p"
	.string "Usare una mossa dopo un certo\n"
	.string "tipo di mossa a volte ti fa\l"
	.string "guadagnare attenzione extra.\p"
	.string "Se sai il fatto tuo,\n"
	.string "puoi fare il pieno di punti.\p"
	.string "Certo, gli avversari possono\n"
	.string "rovinare l'esibizione del POKéMON.$"

@ Unused
SlateportCity_ContestHall_Text_MyPapaIsContestJudge:
	.string "Il mio papà fa il GIUDICE di GARA.\p"
	.string "Chissà cosa farò da grande,\n"
	.string "il GIUDICE o il CAPOPALESTRA?$"

@ Unused
SlateportCity_ContestHall_Text_ImLikeMajorlyCheesed:
	.string "Ehi, amico, sono davvero arrabbiato,\n"
	.string "sai. Tipo, sai, volevo solo\l"
	.string "capire perché il mio POKéMON\l"
	.string "non vinceva mai, sai, tipo, ehi?\p"
	.string "Così, tipo, ho dato al GIUDICE\n"
	.string "la mia opinione, sai, gratis.\p"
	.string "E non mi ha ascoltato, tipo, ehi!\n"
	.string "Che tristezza, amico!\p"
	.string "Ehi, tipo, tu! Zitto, sai?\n"
	.string "Prendi questo, sai!$"

@ Unused
SlateportCity_ContestHall_Text_ExplainTorment:
	.string "È tipo la MT41, sai?\n"
	.string "Ehi, è ATTACCALITE, mi senti?\p"
	.string "Cioè, non lascia che l'altro\n"
	.string "usi la stessa mossa due volte, capito?\p"
	.string "Ehi, ascolta bene, tipo,\n"
	.string "non ti sto mica tormentando!$"

@ Unused
SlateportCity_ContestHall_Text_MCStepUpTakePartInContest:
	.string "MC: Oh, my, my!\n"
	.string "Now isn't that a dandy of a POKéMON?\p"
	.string "Please! Do step right up and take\n"
	.string "part in our splendid CONTESTS!\p"
	.string "You'll do well! I'm sure of it!\n"
	.string "My eyes have never failed me!$"

@ Unused
SlateportCity_ContestHall_Text_JudgeWouldntDoToMissContest:
	.string "GIUDICE: Salve!\n"
	.string "Vedo che sei un ALLENATORE!\p"
	.string "Allora non puoi proprio\n"
	.string "perderti una GARA POKéMON!\p"
	.string "Prendi un PASS GARA a VERDANTURF\n"
	.string "e partecipa quando vuoi!$"

@ Unused
SlateportCity_ContestHall_Text_ItsAppealTime:
	.string "È il momento dell'esibizione!\n"
	.string "Con cosa dovrei iniziare?$"

@ Unused
SlateportCity_ContestHall_Text_DidntPayAttentionToAppeal:
	.string "Non hanno dato peso\n"
	.string "all'esibizione del mio POKéMON…\p"
	.string "Umpf, quel GIUDICE non capisce\n"
	.string "niente quando vede qualcosa di buono.$"

@ Unused
SlateportCity_ContestHall_Text_RewardWithSageAdvice:
	.string "Oh, ciao! Devi essere un fan sfegatato\n"
	.string "per arrivare così vicino all'azione.\p"
	.string "Premierò il tuo entusiasmo con\n"
	.string "questo saggio consiglio.\p"
	.string "Se una mossa va davvero bene,\n"
	.string "il pubblico si entusiasma.\p"
	.string "Il POKéMON che si esibisce\n"
	.string "proprio quando tutti sono carichi…\p"
	.string "Beh, ci si aspetta che succeda\n"
	.string "qualcosa di bello!$"

@ Unused
SlateportCity_ContestHall_Text_MoreFreakedOutThanMon:
	.string "Non ce la faccio! Sono più in panico\n"
	.string "del mio POKéMON.\p"
	.string "Sto tremando e il cuore mi batte forte!$"

@ Unused
SlateportCity_ContestHall_Text_BattleAndContestAlike:
	.string "Una lotta e una GARA non sono\n"
	.string "uguali, ma si somigliano.\p"
	.string "Devi impegnarti e credere\n"
	.string "nei POKéMON che hai cresciuto.$"

@ Unused
SlateportCity_ContestHall_Text_MonLooksOnTopOfGame:
	.string "Quel POKéMON sembra in gran\n"
	.string "forma, eh?\p"
	.string "Un POKéMON che va bene nella\n"
	.string "seconda valutazione sembra più\l"
	.string "rilassato durante le esibizioni.$"

@ Unused
SlateportCity_ContestHall_Text_MyMonBetterThanThatLot:
	.string "Hai visto che pena?\p"
	.string "Eh, il mio POKéMON è molto meglio\n"
	.string "di quella banda!$"

@ Unused
SlateportCity_ContestHall_Text_GetUrgeToMoveWithMon:
	.string "Non ti viene voglia di muoverti con\n"
	.string "i POKéMON se fanno un'esibizione\l"
	.string "piena di energia?$"

@ Unused
SlateportCity_ContestHall_Text_HyperRankStage:
	.string "GARE POKéMON\n"
	.string "PALCO CLASSE Iper!$"

