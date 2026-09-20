BattleFrontier_BattlePikeLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeLobby_OnWarp
	.byte 0

BattleFrontier_BattlePikeLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePikeLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePikeLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePikeLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePikeLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePikeLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePikeLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePikeLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePikeLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePikeLobby_EventScript_QuitWithoutSaving::
	special HealPlayerParty
	pike_resethelditems
	lockall
	msgbox BattleFrontier_BattlePikeLobby_Text_FailedToSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	pike_set PIKE_DATA_WIN_STREAK, 0
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePikeLobby_EventScript_DefeatedQueen
	msgbox BattleFrontier_BattlePikeLobby_Text_PossessLuckInAbundance, MSGBOX_DEFAULT
	waitmessage
	goto BattleFrontier_BattlePikeLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePikeLobby_EventScript_DefeatedQueen::
	msgbox BattleFrontier_BattlePikeLobby_Text_SnatchedVictoryFromQueen, MSGBOX_DEFAULT
	waitmessage
BattleFrontier_BattlePikeLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	frontier_checkairshow
	pike_get PIKE_DATA_TOTAL_STREAKS
	addvar VAR_RESULT, 1
	pike_set PIKE_DATA_TOTAL_STREAKS, VAR_RESULT
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	pike_resethelditems
	message BattleFrontier_BattlePikeLobby_Text_ShallRecordResults
	waitmessage
	pike_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattlePikeLobby_Text_ChallengeEndedRecordResults
	waitmessage
	frontier_checkairshow
	frontier_set FRONTIER_DATA_BATTLE_NUM, 0
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, FALSE
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	pike_resethelditems
	pike_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PIKE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattlePikeLobby_Text_WelcomeToBattlePike, MSGBOX_DEFAULT
BattleFrontier_BattlePikeLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattlePikeLobby_Text_TakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePikeLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePikeLobby_Text_WhichChallengeMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePikeLobby_Text_PleaseChooseThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePikeLobby_Text_SaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePikeLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_1, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	pike_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, TRUE
	pike_savehelditems
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	pike_savehelditems
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePikeLobby_EventScript_CancelChallengeSaveFailed
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePikeLobby_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	frontier_settrainers
	call BattleFrontier_BattlePikeLobby_EventScript_WalkToCorridor
	special HealPlayerParty
	call BattleFrontier_BattlePike_EventScript_CloseCurtain
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PIKE_CORRIDOR, 6, 7
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePikeLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainBattlePike, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePikeLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_PIKE
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_WalkToCorridor::
	applymovement LOCALID_PIKE_LOBBY_ATTENDANT, BattleFrontier_BattlePikeLobby_Movement_AttendantWalkToCorridor
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeLobby_Movement_PlayerWalkToCorridor
	waitmovement 0
	return

BattleFrontier_BattlePikeLobby_Movement_PlayerWalkToCorridor:
	walk_up
BattleFrontier_BattlePikeLobby_Movement_AttendantWalkToCorridor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePikeLobby_EventScript_Hiker::
	msgbox BattleFrontier_BattlePikeLobby_Text_OneRoomAwayFromGoal, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_Twin::
	msgbox BattleFrontier_BattlePikeLobby_Text_NeverHadToBattleTrainer, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_Beauty::
	msgbox BattleFrontier_BattlePikeLobby_Text_ThinkAbilitiesUsefulHere, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePikeLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePikeLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 16, 4, MULTI_BATTLE_PIKE_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeLobby_EventScript_RulesPokenavBag
	case 1, BattleFrontier_BattlePikeLobby_EventScript_RulesHeldItems
	case 2, BattleFrontier_BattlePikeLobby_EventScript_RulesMonOrder
	case 3, BattleFrontier_BattlePikeLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesPokenavBag::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainPokenavBagRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesHeldItems::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainHeldItemRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesMonOrder::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainMonOrderRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePike_EventScript_CloseCurtain::
	playse SE_PIKE_CURTAIN_CLOSE
	special CloseBattlePikeCurtain
	waitstate
	waitse
	return

BattleFrontier_BattlePikeLobby_Text_WelcomeToBattlePike:
	.string "Qui la fortuna degli ALLENATORI\n"
	.string "viene messa alla prova…\p"
	.string "Benvenuti alla BATTLE PIKE…\p"
	.string "Sono la vostra guida…$"

BattleFrontier_BattlePikeLobby_Text_TakeChallenge:
	.string "Vuoi affrontare la sfida\n"
	.string "della Sfida Scelta?$"

BattleFrontier_BattlePikeLobby_Text_ExplainBattlePike:
	.string "Qui teniamo un evento\n"
	.string "detto Scelta Lotta.\p"
	.string "Le regole sono molto\n"
	.string "facili…\p"
	.string "Scegli uno dei tre sentieri e\n"
	.string "raggiungi la stanza finale\l"
	.string "del PALO LOTTA. Semplice, no?\p"
	.string "Ma ciò che accade lungo la\n"
	.string "via dipende solo dalla fortuna\l"
	.string "dello sfidante…\p"
	.string "Se arrivi al traguardo, otterrai\n"
	.string "Punti Lotta.\p"
	.string "Per interrompere la sfida,\n"
	.string "parla con il nostro staff nelle\l"
	.string "grandi sale lungo il percorso.\p"
	.string "Se non salvi prima di fermarti,\n"
	.string "sarai squalificato.$"

BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou:
	.string "Ci vediamo a un'altra\n"
	.string "occasione…$"

BattleFrontier_BattlePikeLobby_Text_WhichChallengeMode:
	.string "Potete scegliere tra due percorsi,\n"
	.string "Livello 50 e Livello Libero.\l"
	.string "Quale sfiderai?$"

BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLv50:
	.string "Scusate, ma…\p"
	.string "Non avete tre POKéMON idonei\n"
	.string "alla Sfida Scelta.\p"
	.string "Servono tre POKéMON diversi\n"
	.string "di Livello 50 o meno.\p"
	.string "Devono anche tenere\n"
	.string "strumenti diversi.\p"
	.string "UOVA{STR_VAR_1}.$"

BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsEnd:
	.string "Tornate da me quando\n"
	.string "sarete pronti…$"

BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Scusate, ma…\p"
	.string "Non avete tre POKéMON idonei\n"
	.string "alla Sfida Scelta.\p"
	.string "Servono tre POKéMON diversi\n"
	.string "per partecipare.\p"
	.string "Devono anche tenere\n"
	.string "strumenti diversi.\p"
	.string "UOVA{STR_VAR_1}.$"

BattleFrontier_BattlePikeLobby_Text_PleaseChooseThreeMons:
	.string "Scegliete i tre POKéMON da\n"
	.string "iscrivere alla sfida…$"

BattleFrontier_BattlePikeLobby_Text_SaveBeforeChallenge:
	.string "Prima di iniziare la Sfida\n"
	.string "Scelta devo salvare il gioco.\l"
	.string "Va bene?$"

BattleFrontier_BattlePikeLobby_Text_StepThisWay:
	.string "Da qui, prego…$"

BattleFrontier_BattlePikeLobby_Text_ChallengeEndedRecordResults:
	.string "La tua sfida è finita…\p"
	.string "Segno i tuoi risultati.\n"
	.string "Attendi…$"

BattleFrontier_BattlePikeLobby_Text_PossessLuckInAbundance:
	.string "Avete completato la sfida…\p"
	.string "Devo dire… Avete Fertilità\n"
	.string "di forte…$"

BattleFrontier_BattlePikeLobby_Text_ShallRecordResults:
	.string "Registrierò i risultati.\n"
	.string "Aspettate…$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints2:
	.string "Per aver completato la sfida\n"
	.string "Scelta Lotta, ricevi questi\l"
	.string "Punti Lotta…$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_ReachedBattlePointLimit:
	.string "Sembra che abbiate raggiunto\n"
	.string "il limite di Punti Lotta…\p"
	.string "Cambiate qualche Punto Lotta\n"
	.string "con premi, poi tornate…$"

BattleFrontier_BattlePikeLobby_Text_FailedToSaveBeforeQuitting:
	.string "Mi dispiace, ma…\p"
	.string "L'ultima volta non hai salvato\n"
	.string "prima di abbandonare la sfida.\p"
	.string "Perciò la sfida finora è stata\n"
	.string "squalificata. Mi spiace…$"

BattleFrontier_BattlePikeLobby_Text_SnatchedVictoryFromQueen:
	.string "Congratulazioni…\p"
	.string "Avete strappato la Vittoria alla\n"
	.string "SIGNORA DEL PIKE…$"

BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints:
	.string "Per la tua straordinaria fortuna,\n"
	.string "ricevi questi Punti Lotta…$"

BattleFrontier_BattlePikeLobby_Text_OneRoomAwayFromGoal:
	.string "Ahia! Ho rovinato tutto!\n"
	.string "Mi mancava una sola stanza!\p"
	.string "Qui state attenti a Veleno,\n"
	.string "Glaciale e via dicendo!$"

BattleFrontier_BattlePikeLobby_Text_NeverHadToBattleTrainer:
	.string "Ho fatto la sfida 10 volte e\n"
	.string "non ho mai dovuto affrontare\l"
	.string "un ALLENATORE.$"

BattleFrontier_BattlePikeLobby_Text_ThinkAbilitiesUsefulHere:
	.string "Senta! Senta!\p"
	.string "Le abilità speciali dei\n"
	.string "POKéMON non ti saranno\l"
	.string "utili qui?$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_TrainersWhicheverPathIChoose:
	.string "Che posto strano!\n"
	.string "Non ci capisco niente!\p"
	.string "Ho fatto la sfida tante volte,\n"
	.string "ma incontro solo ALLENATORI,\l"
	.string "qualunque strada scelga.$"

BattleFrontier_BattlePikeLobby_Text_RulesAreListed:
	.string "Ecco le regole della Sfida Scelta.$"

BattleFrontier_BattlePikeLobby_Text_ReadWhichHeading:
	.string "Quale voce vuoi leggere?$"

BattleFrontier_BattlePikeLobby_Text_ExplainPokenavBagRules:
	.string "ZAINO e POKéNAV vietati durante\n"
	.string "una Scelta Lotta.$"

BattleFrontier_BattlePikeLobby_Text_ExplainHeldItemRules:
	.string "Durante una Scelta Lotta,\n"
	.string "le BACCHE o le ERBE tenute dai\l"
	.string "POKéMON agiscono una volta.$"

BattleFrontier_BattlePikeLobby_Text_ExplainMonOrderRules:
	.string "Durante una Scelta Lotta,\n"
	.string "l'ordine dei POKéMON è\l"
	.string "fisso.\p"
	.string "Va stabilito prima di\n"
	.string "iniziare la sfida.$"

