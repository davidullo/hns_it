BattleFrontier_BattleArenaLobby_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaLobby_OnFrame_hns
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleArenaLobby_OnWarp_hns
	.byte 0

BattleFrontier_BattleArenaLobby_OnWarp_hns:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth_hns
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth_hns::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleArenaLobby_OnFrame_hns:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleArenaLobby_EventScript_WonChallenge_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleArenaLobby_EventScript_LostChallenge_hns
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus_hns::
	frontier_getstatus
	end

BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving_hns::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown_hns, MSGBOX_DEFAULT
	closemessage
	arena_set ARENA_DATA_WIN_STREAK, 0
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_WonChallenge_hns::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon_hns
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints_hns

BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon_hns, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints_hns, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleArenaLobby_Text_RecordAchievement_hns
	waitmessage
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge_hns
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge_hns2_hns, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_LostChallenge_hns::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave_hns
	waitmessage
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge_hns
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge_hns2_hns, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge_hns::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	arena_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge_hns
	message BattleFrontier_BattleArenaLobby_Text_RecordLastMatch_hns
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge_hns
	case 0, BattleFrontier_BattleArenaLobby_EventScript_RecordMatch_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge_hns

BattleFrontier_BattleArenaLobby_EventScript_RecordMatch_hns::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge_hns::
	return

BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge_hns::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame_hns
	waitmessage
	arena_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge_hns

BattleFrontier_BattleArenaLobby_EventScript_Attendant_hns::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_ARENA
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena_hns, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge_hns::
	message BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge_hns
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge_hns
	case 1, BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge_hns
	case 2, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge_hns::
	message BattleFrontier_BattleArenaLobby_Text_WhichLevelMode_hns
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge_hns
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons_hns
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleArenaLobby_Text_SelectThreeMons_hns, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge_hns
	msgbox BattleFrontier_BattleArenaLobby_Text_OkayToSave_hns, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge_hns
	case YES, BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge_hns

BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge_hns::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	arena_init
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge_hnsSaveFailed_hns
BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge_hns::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattleArenaLobby_Text_GuideYouToArena_hns, MSGBOX_DEFAULT
	closemessage
	frontier_get FRONTIER_DATA_LVL_MODE
	call_if_eq VAR_RESULT, FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50_hns
	call_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen_hns
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_CORRIDOR_HNS, 9, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainChallenge_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge_hns

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons_hns::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons_hnsLv50_hns
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons_hnsLvOpen_hns

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons_hnsLv50_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50_hns, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsEnd_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge_hns

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons_hnsLvOpen_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen_hns, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsEnd_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge_hns

BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge_hnsSaveFailed_hns::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge_hns::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge_hns, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge_hns::
	release
	end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50_hns::
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor_hns
	waitmovement 0
	opendoor 2, 2
	waitdooranim
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor_hns
	waitmovement 0
	closedoor 2, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor_hns:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor_hns:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor_hns:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor_hns:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen_hns::
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor_hns
	waitmovement 0
	opendoor 11, 2
	waitdooranim
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor_hns
	waitmovement 0
	closedoor 11, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor_hns:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor_hns:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_EventScript_ShowResults_hns::
	lockall
	frontier_results FRONTIER_FACILITY_ARENA
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_Youngster_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack_hns, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Man_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked_hns, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Camper_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw_hns, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Woman_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant_hns, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_RulesBoard_hns::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_RulesAreListed_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard_hns::
	message BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading_hns
	waitmessage
	multichoice 17, 2, MULTI_BATTLE_ARENA_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_BattleRules_hns
	case 1, BattleFrontier_BattleArenaLobby_EventScript_MindRules_hns
	case 2, BattleFrontier_BattleArenaLobby_EventScript_SkillRules_hns
	case 3, BattleFrontier_BattleArenaLobby_EventScript_BodyRules_hns
	case 4, BattleFrontier_BattleArenaLobby_EventScript_ExitRules_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_ExitRules_hns
	end

BattleFrontier_BattleArenaLobby_EventScript_BattleRules_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleArenaLobby_EventScript_MindRules_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainMindRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleArenaLobby_EventScript_SkillRules_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleArenaLobby_EventScript_BodyRules_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleArenaLobby_EventScript_ExitRules_hns::
	releaseall
	end

BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena_hns:
	.string "Dove lo spirito lottatore degli\n"
	.string "ALLENATORI è messo alla prova!\p"
	.string "Benvenuto all'ARENA DI LOTTA!\p"
	.string "Sono la tua guida al Torneo KO!$"

BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge_hns:
	.string "Allora, vuoi affrontare\n"
	.string "la sfida dell'ARENA DI LOTTA?$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge_hns:
	.string "Ti aspettiamo di nuovo\n"
	.string "per una sfida!$"

BattleFrontier_BattleArenaLobby_Text_ExplainChallenge_hns:
	.string "Nella Zona Lotta si svolge\n"
	.string "il Torneo Ko Stabilito.\p"
	.string "Tutti entrano con una squadra\n"
	.string "di 3 POKéMON.\p"
	.string "I 3 POKéMON vanno messi in fila\n"
	.string "nell'ordine d'ingresso.\p"
	.string "In lotta entreranno uno\n"
	.string "alla volta, in tale ordine.\p"
	.string "Entrato in campo, il POKéMON\n"
	.string "resta finché la lotta è decisa.\p"
	.string "Se dopo 3 turni non c'è\n"
	.string "verdetto, si va al giudizio.\p"
	.string "Per interrompere la sfida,\n"
	.string "salva il gioco.\p"
	.string "Senza salvataggio non potrai\n"
	.string "continuare la sfida.\p"
	.string "Se batti 7 ALLENATORI\n"
	.string "di fila,\l"
	.string "riceverai Punti Lotta.$"

BattleFrontier_BattleArenaLobby_Text_OkayToSave_hns:
	.string "Prima di portarti al PALAGOTTON\n"
	.string "devi salvare. Va bene?$"

BattleFrontier_BattleArenaLobby_Text_WhichLevelMode_hns:
	.string "L'ARENA DI LOTTA offre due livelli\n"
	.string "di sfida: Livello 50 e Livello Libero.\l"
	.string "Cosa scegli?$"

BattleFrontier_BattleArenaLobby_Text_SelectThreeMons_hns:
	.string "Bene, ora scegli pure\n"
	.string "i tuoi tre POKéMON.$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen_hns:
	.string "Cara sfidante!\p"
	.string "Non hai i tre POKéMON\n"
	.string "per l'ingresso.\p"
	.string "Per partecipare servono tre\n"
	.string "POKéMON di specie diverse.\p"
	.string "Non devono neanche tenere\n"
	.string "oggetti uguali.\p"
	.string "UOVA{STR_VAR_1}.$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsEnd_hns:
	.string "Quando sarai pronto,\n"
	.string "ti prego torna.$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50_hns:
	.string "Cara sfidante!\p"
	.string "Non hai i tre POKéMON\n"
	.string "per l'ingresso.\p"
	.string "Per partecipare servono tre\n"
	.string "POKéMON di specie diverse.\p"
	.string "I tre POKéMON diversi\n"
	.string "devono essere Liv. 50 o meno.\p"
	.string "Non devono neanche tenere\n"
	.string "oggetti uguali.\p"
	.string "UOVA{STR_VAR_1}.$"

BattleFrontier_BattleArenaLobby_Text_GuideYouToArena_hns:
	.string "Ora ti guiderò\n"
	.string "al PALAGOTTON.$"

BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown_hns:
	.string "Caro sfidante!\p"
	.string "Non hai salvato prima\n"
	.string "di spegnere, vero?\p"
	.string "Purtroppo questo comporta\n"
	.string "la tua squalifica\l"
	.string "dalla sfida.\p"
	.string "Puoi riprovare da capo,\n"
	.string "beninteso.$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins_hns:
	.string "Congratulazioni per le\n"
	.string "sette vittorie di fila!$"

BattleFrontier_BattleArenaLobby_Text_RecordAchievement_hns:
	.string "Il tuo risultato sarà registrato.\n"
	.string "Attendi mentre salvo il gioco.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_PresentYouWithPrize_hns:
	.string "Per la tua serie di 7 vittorie,\n"
	.string "ricevi questo premio.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_ReceivedPrize_hns:
	.string "{PLAYER} ha ottenuto\n"
	.string "{STR_VAR_1}.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_BagFullReturnForPrize_hns:
	.string "Oh?\n"
	.string "La tua BORSA è piena.\p"
	.string "Fai spazio e torna\n"
	.string "a ritirare il premio.$"

BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave_hns:
	.string "Grazie per la partecipazione!\p"
	.string "Attendi mentre salvo il gioco.$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge_hns2_hns:
	.string "Ti aspettiamo di nuovo\n"
	.string "per una sfida!$"

BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame_hns:
	.string "Ti aspettavamo\n"
	.string "con ansia.\p"
	.string "Prima di portarti al PALAGOTTON\n"
	.string "devo salvare il gioco.\l"
	.string "Aspetta.$"

BattleFrontier_BattleArenaLobby_Text_RecordLastMatch_hns:
	.string "Registro la tua ultima gara del\n"
	.string "PALAGOTTON sul SUPERPASS?$"

BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack_hns:
	.string "Perso per verdetto dell'ARBITRO…\p"
	.string "Non credo sia stato saggio usare\n"
	.string "solo difese senza attaccare…$"

BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked_hns:
	.string "Giudizio vinto!\p"
	.string "Colpire sempre il POKéMON\n"
	.string "avversario ha funzionato!$"

BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw_hns:
	.string "L'incontro è finito in parità.\p"
	.string "Quando è finito il tempo, il mio\n"
	.string "POKéMON e quello del nemico avevano\l"
	.string "HP quasi uguali.$"

BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant_hns:
	.string "Al PALAGOTTON l'ordine dei\n"
	.string "POKéMON è importantissimo.\p"
	.string "Per esempio, se il primo POKéMON\n"
	.string "ha svantaggi di tipo,\l"
	.string "scegli come secondo POKéMON uno\l"
	.string "con mosse superefficaci\l"
	.string "contro il primo.\p"
	.string "Penso sia un buon modo\n"
	.string "per una squadra forte.$"

BattleFrontier_BattleArenaLobby_Text_RulesAreListed_hns:
	.string "Qui ci sono le regole del Torneo KO.$"

BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading_hns:
	.string "Quale voce vuoi leggere?$"

BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules_hns:
	.string "Il Torneo Ko Stabilito ha regole\n"
	.string "speciali, non standard.\p"
	.string "Ogni lotta dura solo\n"
	.string "tre turni.\p"
	.string "Se il verdetto non arriva\n"
	.string "in 3 turni, si va al giudizio.\p"
	.string "L'ARBITRO sceglie il vincitore\n"
	.string "in base alle mosse dei POKéMON.\p"
	.string "Inoltre non si può cambiare\n"
	.string "POKéMON finché la lotta non è decisa.$"

BattleFrontier_BattleArenaLobby_Text_ExplainMindRules_hns:
	.string "Il primo criterio è la “Mente.”\n"
	.string "Valuta quanto erano aggressivi\l"
	.string "i lottatori.\p"
	.string "Il giudizio conta quante volte\n"
	.string "gli ALLENATORI hanno ordinato\l"
	.string "mosse offensive.$"

BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules_hns:
	.string "Il secondo criterio è la “Perizia.”\n"
	.string "Valuta l'uso delle mosse\l"
	.string "dei POKéMON.\p"
	.string "Se una mossa ha funzionato,\n"
	.string "la Perizia sale.\p"
	.string "Se una mossa fallisce, la Perizia\n"
	.string "scende.\p"
	.string "Se era una mossa offensiva, la Perizia\n"
	.string "sale se era “superefficace”\l"
	.string "e scende se era\l"
	.string "“poco efficace.”\p"
	.string "La Perizia non sale per\n"
	.string "tipo PROTEZIONE e INDIVIDUA.\p"
	.string "Se il nemico usa PROTEZIONE\n"
	.string "o INDIVIDUA e i tuoi POKéMON\l"
	.string "non hanno colpito, la Perizia non\l"
	.string "scende.$"

BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules_hns:
	.string "Il terzo fattore è “Corpo”.\n"
	.string "Si basa sugli HP rimasti\l"
	.string "alla fine della lotta.\p"
	.string "Il giudizio considera gli HP\n"
	.string "iniziali del POKéMON e quelli\l"
	.string "rimasti alla fine.$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon_hns:
	.string "Vittoria sul MAGNATE\n"
	.string "DELL'ARENA e su 7 sfidanti!\p"
	.string "Congratulazioni per la\n"
	.string "splendida impresa!$"

BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints_hns:
	.string "Cara sfidante, per il tuo\n"
	.string "spirito instancabile accetta\l"
	.string "questi Punti Lotta.$"
