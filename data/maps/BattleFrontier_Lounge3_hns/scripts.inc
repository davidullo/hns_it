BattleFrontier_Lounge3_hns_MapScripts::
	.byte 0

	.set BET_AMOUNT_5,  5
	.set BET_AMOUNT_10, 10
	.set BET_AMOUNT_15, 15

BattleFrontier_Lounge3_EventScript_Gambler_hns::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_GAMBLER, BattleFrontier_Lounge3_EventScript_AlreadyMetGambler_hns
	call BattleFrontier_Lounge3_EventScript_CountSilverSymbols_hns
	goto_if_le VAR_0x8004, 2, BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols_hns
	setflag FLAG_MET_BATTLE_FRONTIER_GAMBLER
	msgbox BattleFrontier_Lounge3_Text_YouLookToughExplainGambling_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge_hns
	end

BattleFrontier_Lounge3_EventScript_AskToEnterChallenge_hns::
	special ShowFrontierGamblerLookingMessage
	waitmessage
	waitbuttonpress
	msgbox BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe_hns, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge_hns
	msgbox BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints_hns, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge_hns
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot_hns
	waitmessage
	special ShowBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount_hns
	end

BattleFrontier_Lounge3_EventScript_ChooseBetAmount_hns::
	multichoice 20, 4, MULTI_FRONTIER_GAMBLER_BET, FALSE
	copyvar VAR_FRONTIER_GAMBLER_AMOUNT_BET, VAR_RESULT
	switch VAR_RESULT
	case FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_Bet5_hns
	case FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_Bet10_hns
	case FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_Bet15_hns
	case FRONTIER_GAMBLER_BET_CANCEL, BattleFrontier_Lounge3_EventScript_CancelBet_hns
	case MULTI_B_PRESSED, BattleFrontier_Lounge3_EventScript_CancelBet_hns
	end

BattleFrontier_Lounge3_EventScript_Bet5_hns::
	setvar VAR_0x8008, BET_AMOUNT_5
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet_hns
	end

BattleFrontier_Lounge3_EventScript_Bet10_hns::
	setvar VAR_0x8008, BET_AMOUNT_10
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet_hns
	end

BattleFrontier_Lounge3_EventScript_Bet15_hns::
	setvar VAR_0x8008, BET_AMOUNT_15
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet_hns
	end

BattleFrontier_Lounge3_EventScript_TryPlaceBet_hns::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge3_EventScript_PlaceBet_hns
	msgbox BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints_hns, MSGBOX_DEFAULT
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot_hns
	waitmessage
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount_hns
	end

BattleFrontier_Lounge3_EventScript_PlaceBet_hns::
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_Lounge3_Text_ThanksOffYouGo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FinishBet_hns
	end

BattleFrontier_Lounge3_EventScript_FinishBet_hns::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge3_EventScript_CountSilverSymbols_hns::
	setvar VAR_0x8004, 0
	call_if_set FLAG_SYS_TOWER_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_DOME_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_PALACE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_ARENA_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_FACTORY_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_PIKE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_PYRAMID_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	return

BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns::
	addvar VAR_0x8004, 1
	return

BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols_hns::
	msgbox BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection_hns
	end

BattleFrontier_Lounge3_EventScript_AlreadyMetGambler_hns::
	msgbox BattleFrontier_Lounge3_Text_Oh_hns, MSGBOX_DEFAULT
	goto_if_ge VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_CheckBetResults_hns
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge_hns
	end

BattleFrontier_Lounge3_EventScript_CheckBetResults_hns::
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted_hns
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WON, BattleFrontier_Lounge3_EventScript_WonChallenge_hns
	goto BattleFrontier_Lounge3_EventScript_LostChallenge_hns
	end

BattleFrontier_Lounge3_EventScript_WonChallenge_hns::
	msgbox BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints_hns, MSGBOX_DEFAULT
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_RewardBet5_hns
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_RewardBet10_hns
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_RewardBet15_hns
	msgbox BattleFrontier_Lounge3_Text_ObtainedBattlePoints_hns, MSGBOX_GETPOINTS
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge_hns, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_LostChallenge_hns::
	msgbox BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints_hns, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_RewardBet5_hns::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_5 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_5 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet10_hns::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_10 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_10 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet15_hns::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_15 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_15 * 2)
	return

BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted_hns::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge3_EventScript_DeclineChallenge_hns::
	msgbox BattleFrontier_Lounge3_Text_NotInterested_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge3_EventScript_CancelBet_hns::
	special CloseBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_DeclineChallenge_hns
	end

BattleFrontier_Lounge3_EventScript_Man_hns::
	msgbox BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge3_EventScript_Woman_hns::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_BackedWrongTrainer_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection_hns
	end

BattleFrontier_Lounge3_EventScript_PokefanF_hns::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection_hns
	end

BattleFrontier_Lounge3_EventScript_FatMan_hns::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_TrainerGoodButRattled_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection_hns
	end

BattleFrontier_Lounge3_EventScript_FaceOriginalDirection_hns::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere_hns::
	.string "…Cosa vuoi da noi?\p"
	.string "Non vedi che siamo un po' occupati?\n"
	.string "Non può aspettare qualche ora?$"

BattleFrontier_Lounge3_Text_YouLookToughExplainGambling_hns::
	.string "…Eh?\n"
	.string "Mi sembri un ALLENATORE tosto.\p"
	.string "Eheheh…\n"
	.string "Ascolta, ho una proposta.\p"
	.string "Qui abbiamo un gruppetto\n"
	.string "e giochiamo a scommettere\l"
	.string "su quel che accade al FRONTIER LOTTA.\p"
	.string "Le regole sono semplici.\p"
	.string "Prima scegliamo una struttura\n"
	.string "del FRONTIER LOTTA.\p"
	.string "Poi ognuno sceglie un ALLENATORE\n"
	.string "che la sta sfidando,\l"
	.string "e punta i suoi PUNTI LOTT.\p"
	.string "Chi punta sull'ALLENATORE\n"
	.string "col record migliore si prende\l"
	.string "tutti i PUNTI LOTT.\p"
	.string "Semplice, no?\n"
	.string "E quindi…$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerSingle_hns::
	.string "Cerco un ALLENATORE che voglia sfidare\n"
	.string "le STANZE SINGOLE della TORRE DI\l"
	.string "LOTTA.\p"
	.string "Ma finora non ho visto un ALLENATORE\n"
	.string "con la stoffa del vincente.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerDouble_hns::
	.string "Cerco un ALLENATORE che voglia sfidare\n"
	.string "le STANZE DOPPIE della TORRE DI\l"
	.string "LOTTA.\p"
	.string "Ma finora non ho visto un ALLENATORE\n"
	.string "con la stoffa del vincente.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerMulti_hns::
	.string "Cerco un ALLENATORE che voglia sfidare\n"
	.string "le STANZE MULTIPLE della TORRE\l"
	.string "DI LOTTA.\p"
	.string "Ma finora non ho visto un ALLENATORE\n"
	.string "con la stoffa del vincente.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeSingle_hns::
	.string "Cerco un ALLENATORE che vada al\n"
	.string "Torneo SINGOLO del DOMO\l"
	.string "DI LOTTA.\p"
	.string "Ma finora non ho visto nessuno\n"
	.string "con la stoffa del vincente.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeDouble_hns::
	.string "Cerca un ALLENATORE che prenderà\n"
	.string "parte al Torneo LOTTA DOPPIA\l"
	.string "della CUPOLA DI LOTTA.\p"
	.string "Ma non ho ancora visto un\n"
	.string "ALLENATORE che sappia vincere.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactorySingle_hns::
	.string "Cerco un ALLENATORE che vada allo\n"
	.string "Scambio SINGOLO della FABBRICA\l"
	.string "DI LOTTA.\p"
	.string "Ma finora non ho visto nessuno\n"
	.string "con la stoffa del vincente.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactoryDouble_hns::
	.string "Cerco un ALLENATORE che vada allo\n"
	.string "Scambio DOPPIO della FABBRICA\l"
	.string "DI LOTTA.\p"
	.string "Ma finora non ho visto nessuno\n"
	.string "con la stoffa del vincente.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceSingle_hns::
	.string "Cerco un ALLENATORE che sfidi le\n"
	.string "SALE SINGOLE del PALAZZO\l"
	.string "DI LOTTA.\p"
	.string "Ma finora non ho visto nessuno\n"
	.string "con la stoffa del vincente.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceDouble_hns::
	.string "Cerco un ALLENATORE che sfidi le\n"
	.string "SALE DOPPIE del PALAZZO\l"
	.string "DI LOTTA.\p"
	.string "Ma finora non ho visto nessuno\n"
	.string "con la stoffa del vincente.$"

BattleFrontier_Lounge3_Text_ChallengeBattleArena_hns::
	.string "Cerca un ALLENATORE che prenderà\n"
	.string "parte al Torneo KO Stabiliti\l"
	.string "dell'ARENA DI LOTTA.\p"
	.string "Ma non ho ancora visto un\n"
	.string "ALLENATORE che sappia vincere.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePike_hns::
	.string "Cerco un ALLENATORE che parteciperà\n"
	.string "alla Sfida di Scelta della GALLERIA\l"
	.string "DI LOTTA.\p"
	.string "Ma finora non ho visto un ALLENATORE\n"
	.string "con quel quid vincente.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePyramid_hns::
	.string "Cerco un ALLENATORE che vada alla\n"
	.string "Sfida della PIRAMIDE\l"
	.string "DI LOTTA.\p"
	.string "Ma finora non ho visto nessuno\n"
	.string "con la stoffa del vincente.$"

BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe_hns::
	.string "Anche tu ne trarrai vantaggio.\n"
	.string "Allora che ne dici?\l"
	.string "Ti iscrivi a quell'evento per me?$"

BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints_hns::
	.string "Va bene, perfetto.\n"
	.string "Dunque… Mi presti un po' dei\l"
	.string "tuoi PUNTI LOTT?\p"
	.string "Poi ti mostrerò la mia\n"
	.string "gratitudine.$"

BattleFrontier_Lounge3_Text_HowMuchCanYouSpot_hns::
	.string "Bene, bene!\n"
	.string "Quanti PUNTI LOTT mi presti?$"

BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints_hns::
	.string "Oh, no, no, no!\n"
	.string "Non hai abbastanza PUNTI LOTT!\p"
	.string "Smettila di perdere tempo\n"
	.string "e far perdere tempo a tutti!$"

BattleFrontier_Lounge3_Text_ThanksOffYouGo_hns::
	.string "Eheheh! Grazie mille!\n"
	.string "Su, ora vai!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerSingle_hns::
	.string "Vai subito alle SALE DI COMBAT\n"
	.string "della LOTTA TOWER, singole!\p"
	.string "E' una partita da vincere!\n"
	.string "Non sprecare la chance!\l"
	.string "Da te dipende il futuro di entrambi!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerDouble_hns::
	.string "Vai alla TORRE DI LOTTA,\n"
	.string "STANZE DOPPIE, subito!\p"
	.string "Vittoria obbligatoria!\n"
	.string "Non sprecarla!\l"
	.string "Il futuro di entrambi è in te!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerMulti_hns::
	.string "Vai subito alle SALE DI COMBAT\n"
	.string "della LOTTA TOWER, doppie!\p"
	.string "E' una partita da vincere!\n"
	.string "Non sprecare la chance!\l"
	.string "Da te dipende il futuro di entrambi!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeSingle_hns::
	.string "Vai al DOMO DI LOTTA,\n"
	.string "Torneo SINGOLO, subito!\p"
	.string "Vittoria obbligatoria!\n"
	.string "Non sprecarla!\l"
	.string "Il futuro di entrambi è in te!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeDouble_hns::
	.string "Vai al DOMO DI LOTTA,\n"
	.string "Torneo DOPPIO, subito!\p"
	.string "Vittoria obbligatoria!\n"
	.string "Non sprecarla!\l"
	.string "Il futuro di entrambi è in te!$"

BattleFrontier_Lounge3_Text_GetToBattleFactorySingle_hns::
	.string "Vai alla FABBRICA,\n"
	.string "Torneo Scambio SINGOLO, subito!\p"
	.string "Vittoria obbligatoria!\n"
	.string "Non sprecarla!\l"
	.string "Il futuro di entrambi è in te!$"

BattleFrontier_Lounge3_Text_GetToBattleFactoryDouble_hns::
	.string "Vai alla FABBRICA,\n"
	.string "Torneo Scambio DOPPIO, subito!\p"
	.string "Vittoria obbligatoria!\n"
	.string "Non sprecarla!\l"
	.string "Il futuro di entrambi è in te!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceSingle_hns::
	.string "Vai al PALAZZO DI LOTTA,\n"
	.string "SALE SINGOLE, subito!\p"
	.string "Vittoria obbligatoria!\n"
	.string "Non sprecarla!\l"
	.string "Il futuro di entrambi è in te!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceDouble_hns::
	.string "Vai al PALAZZO DI LOTTA,\n"
	.string "SALE DOPPIE, subito!\p"
	.string "Vittoria obbligatoria!\n"
	.string "Non sprecarla!\l"
	.string "Il futuro di entrambi è in te!$"

BattleFrontier_Lounge3_Text_GetToBattleArena_hns::
	.string "Vai all'ARENA DI LOTTA,\n"
	.string "Torneo KO, subito!\p"
	.string "Vittoria obbligatoria!\n"
	.string "Non sprecarla!\l"
	.string "Il futuro di entrambi è in te!$"

BattleFrontier_Lounge3_Text_GetToBattlePike_hns::
	.string "Vai alla GALLERIA,\n"
	.string "Scelta, subito!\p"
	.string "Vittoria obbligatoria!\n"
	.string "Non sprecarla!\l"
	.string "Il futuro di entrambi è in te!$"

BattleFrontier_Lounge3_Text_GetToBattlePyramid_hns::
	.string "Vai alla PIRAMIDE,\n"
	.string "Missione, subito!\p"
	.string "Vittoria obbligatoria!\n"
	.string "Non sprecarla!\l"
	.string "Il futuro di entrambi è in te!$"

BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints_hns::
	.string "Oh, sei tu…\n"
	.string "Bel tentativo…\p"
	.string "Mi dispiace, ma non posso\n"
	.string "restituirti i PUNTI LOTT…\p"
	.string "Chissà che non ci sproni\n"
	.string "a dare di più la prossima volta!$"

BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints_hns::
	.string "Oh, certo!\n"
	.string "Ciao, campione!\p"
	.string "Sapevo che ce la facevi!\n"
	.string "Sapevo che ce l'avresti fatta!\l"
	.string "Abbiamo vinto entrambi!\p"
	.string "Ti restituisco i PUNTI LOTT\n"
	.string "e un piccolo extra da parte mia!$"

BattleFrontier_Lounge3_Text_ObtainedBattlePoints_hns::
	.string "{PLAYER} ha ottenuto\n"
	.string "{STR_VAR_1} PUNTI LOTT.$"

BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge_hns::
	.string "Se ti va un'altra sfida,\n"
	.string "pensa a me!$"

BattleFrontier_Lounge3_Text_NotInterested_hns::
	.string "Non ti interessa?! Non dovresti\n"
	.string "aver paura di rischiare!$"

BattleFrontier_Lounge3_Text_Oh_hns::
	.string "Oh…$"

BattleFrontier_Lounge3_Text_BackedWrongTrainer_hns::
	.string "Ho scommesso di nuovo sull'\p"
	.string "ALLENATORE sbagliato! Dovrei\n"
	.string "lottare come tutti…$"

BattleFrontier_Lounge3_Text_TrainerGoodButRattled_hns::
	.string "Quell'ALLENATORE…\p"
	.string "E' forte, ma si agita facilmente\n"
	.string "per sopravvivere alla DOME…$"

BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne_hns::
	.string "Ridacchia!\n"
	.string "Un vincitore lo vedo al volo!$"

BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges_hns::
	.string "Quegli ALLENATORI…\n"
	.string "Cosa ci fanno qui?\l"
	.string "Dovrebbero sfidare qualcuno.$"
