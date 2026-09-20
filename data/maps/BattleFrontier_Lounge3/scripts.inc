BattleFrontier_Lounge3_MapScripts::
	.byte 0

	.set BET_AMOUNT_5,  5
	.set BET_AMOUNT_10, 10
	.set BET_AMOUNT_15, 15

BattleFrontier_Lounge3_EventScript_Gambler::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_GAMBLER, BattleFrontier_Lounge3_EventScript_AlreadyMetGambler
	call BattleFrontier_Lounge3_EventScript_CountSilverSymbols
	goto_if_le VAR_0x8004, 2, BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols
	setflag FLAG_MET_BATTLE_FRONTIER_GAMBLER
	msgbox BattleFrontier_Lounge3_Text_YouLookToughExplainGambling, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_AskToEnterChallenge::
	special ShowFrontierGamblerLookingMessage
	waitmessage
	waitbuttonpress
	msgbox BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	msgbox BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	special ShowBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_ChooseBetAmount::
	multichoice 20, 4, MULTI_FRONTIER_GAMBLER_BET, FALSE
	copyvar VAR_FRONTIER_GAMBLER_AMOUNT_BET, VAR_RESULT
	switch VAR_RESULT
	case FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_Bet5
	case FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_Bet10
	case FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_Bet15
	case FRONTIER_GAMBLER_BET_CANCEL, BattleFrontier_Lounge3_EventScript_CancelBet
	case MULTI_B_PRESSED, BattleFrontier_Lounge3_EventScript_CancelBet
	end

BattleFrontier_Lounge3_EventScript_Bet5::
	setvar VAR_0x8008, BET_AMOUNT_5
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet10::
	setvar VAR_0x8008, BET_AMOUNT_10
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet15::
	setvar VAR_0x8008, BET_AMOUNT_15
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_TryPlaceBet::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge3_EventScript_PlaceBet
	msgbox BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints, MSGBOX_DEFAULT
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_PlaceBet::
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_Lounge3_Text_ThanksOffYouGo, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FinishBet
	end

BattleFrontier_Lounge3_EventScript_FinishBet::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge3_EventScript_CountSilverSymbols::
	setvar VAR_0x8004, 0
	call_if_set FLAG_SYS_TOWER_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_DOME_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PALACE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_ARENA_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_FACTORY_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PIKE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PYRAMID_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	return

BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount::
	addvar VAR_0x8004, 1
	return

BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols::
	msgbox BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_AlreadyMetGambler::
	msgbox BattleFrontier_Lounge3_Text_Oh, MSGBOX_DEFAULT
	goto_if_ge VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_CheckBetResults
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_CheckBetResults::
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WON, BattleFrontier_Lounge3_EventScript_WonChallenge
	goto BattleFrontier_Lounge3_EventScript_LostChallenge
	end

BattleFrontier_Lounge3_EventScript_WonChallenge::
	msgbox BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints, MSGBOX_DEFAULT
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_RewardBet5
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_RewardBet10
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_RewardBet15
	msgbox BattleFrontier_Lounge3_Text_ObtainedBattlePoints, MSGBOX_GETPOINTS
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_LostChallenge::
	msgbox BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_RewardBet5::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_5 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_5 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet10::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_10 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_10 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet15::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_15 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_15 * 2)
	return

BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge3_EventScript_DeclineChallenge::
	msgbox BattleFrontier_Lounge3_Text_NotInterested, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge3_EventScript_CancelBet::
	special CloseBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_DeclineChallenge
	end

BattleFrontier_Lounge3_EventScript_Man::
	msgbox BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges, MSGBOX_NPC
	end

BattleFrontier_Lounge3_EventScript_Woman::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_BackedWrongTrainer, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FatMan::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_TrainerGoodButRattled, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere::
	.string "…Cosa vuoi da noi?\p"
	.string "Non vedi che siamo un po' occupati?\n"
	.string "Non può aspettare qualche ora?$"

BattleFrontier_Lounge3_Text_YouLookToughExplainGambling::
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

BattleFrontier_Lounge3_Text_ChallengeBattleTowerSingle::
	.string "Cerco un ALLENATORE che voglia sfidare\n"
	.string "le STANZE SINGOLE della TORRE DI\l"
	.string "LOTTA.\p"
	.string "Ma finora non ho visto un ALLENATORE\n"
	.string "con la stoffa del vincente.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerDouble::
	.string "Cerco un ALLENATORE che voglia sfidare\n"
	.string "le STANZE DOPPIE della TORRE DI\l"
	.string "LOTTA.\p"
	.string "Ma finora non ho visto un ALLENATORE\n"
	.string "con la stoffa del vincente.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerMulti::
	.string "Cerco un ALLENATORE che voglia sfidare\n"
	.string "le STANZE MULTIPLE della TORRE\l"
	.string "DI LOTTA.\p"
	.string "Ma finora non ho visto un ALLENATORE\n"
	.string "con la stoffa del vincente.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeSingle::
	.string "Cerco un ALLENATORE che vada al\n"
	.string "Torneo SINGOLO del DOMO\l"
	.string "DI LOTTA.\p"
	.string "Ma finora non ho visto nessuno\n"
	.string "con la stoffa del vincente.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeDouble::
	.string "Cerca un ALLENATORE che prenderà\n"
	.string "parte al Torneo LOTTA DOPPIA\l"
	.string "della CUPOLA DI LOTTA.\p"
	.string "Ma non ho ancora visto un\n"
	.string "ALLENATORE che sappia vincere.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactorySingle::
	.string "Cerco un ALLENATORE che vada allo\n"
	.string "Scambio SINGOLO della FABBRICA\l"
	.string "DI LOTTA.\p"
	.string "Ma finora non ho visto nessuno\n"
	.string "con la stoffa del vincente.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactoryDouble::
	.string "Cerco un ALLENATORE che vada allo\n"
	.string "Scambio DOPPIO della FABBRICA\l"
	.string "DI LOTTA.\p"
	.string "Ma finora non ho visto nessuno\n"
	.string "con la stoffa del vincente.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceSingle::
	.string "Cerco un ALLENATORE che sfidi le\n"
	.string "SALE SINGOLE del PALAZZO\l"
	.string "DI LOTTA.\p"
	.string "Ma finora non ho visto nessuno\n"
	.string "con la stoffa del vincente.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceDouble::
	.string "Cerco un ALLENATORE che sfidi le\n"
	.string "SALE DOPPIE del PALAZZO\l"
	.string "DI LOTTA.\p"
	.string "Ma finora non ho visto nessuno\n"
	.string "con la stoffa del vincente.$"

BattleFrontier_Lounge3_Text_ChallengeBattleArena::
	.string "Cerca un ALLENATORE che prenderà\n"
	.string "parte al Torneo KO Stabiliti\l"
	.string "dell'ARENA DI LOTTA.\p"
	.string "Ma non ho ancora visto un\n"
	.string "ALLENATORE che sappia vincere.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePike::
	.string "Cerco un ALLENATORE che parteciperà\n"
	.string "alla Sfida di Scelta della GALLERIA\l"
	.string "DI LOTTA.\p"
	.string "Ma finora non ho visto un ALLENATORE\n"
	.string "con quel quid vincente.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePyramid::
	.string "Cerco un ALLENATORE che vada alla\n"
	.string "Sfida della PIRAMIDE\l"
	.string "DI LOTTA.\p"
	.string "Ma finora non ho visto nessuno\n"
	.string "con la stoffa del vincente.$"

BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe::
	.string "Anche tu ne trarrai vantaggio.\n"
	.string "Allora che ne dici?\l"
	.string "Ti iscrivi a quell'evento per me?$"

BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints::
	.string "Va bene, perfetto.\n"
	.string "Dunque… Mi presti un po' dei\l"
	.string "tuoi PUNTI LOTT?\p"
	.string "Poi ti mostrerò la mia\n"
	.string "gratitudine.$"

BattleFrontier_Lounge3_Text_HowMuchCanYouSpot::
	.string "Bene, bene!\n"
	.string "Quanti PUNTI LOTT mi presti?$"

BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints::
	.string "Oh, no, no, no!\n"
	.string "Non hai abbastanza PUNTI LOTT!\p"
	.string "Smettila di perdere tempo\n"
	.string "e far perdere tempo a tutti!$"

BattleFrontier_Lounge3_Text_ThanksOffYouGo::
	.string "Eheheh! Grazie mille!\n"
	.string "Su, ora vai!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerSingle::
	.string "Vai subito alle SALE DI COMBAT\n"
	.string "della LOTTA TOWER, singole!\p"
	.string "E' una partita da vincere!\n"
	.string "Non sprecare la chance!\l"
	.string "Da te dipende il futuro di entrambi!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerDouble::
	.string "Vai alla TORRE DI LOTTA,\n"
	.string "STANZE DOPPIE, subito!\p"
	.string "Vittoria obbligatoria!\n"
	.string "Non sprecarla!\l"
	.string "Il futuro di entrambi è in te!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerMulti::
	.string "Vai subito alle SALE DI COMBAT\n"
	.string "della LOTTA TOWER, doppie!\p"
	.string "E' una partita da vincere!\n"
	.string "Non sprecare la chance!\l"
	.string "Da te dipende il futuro di entrambi!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeSingle::
	.string "Vai al DOMO DI LOTTA,\n"
	.string "Torneo SINGOLO, subito!\p"
	.string "Vittoria obbligatoria!\n"
	.string "Non sprecarla!\l"
	.string "Il futuro di entrambi è in te!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeDouble::
	.string "Vai al DOMO DI LOTTA,\n"
	.string "Torneo DOPPIO, subito!\p"
	.string "Vittoria obbligatoria!\n"
	.string "Non sprecarla!\l"
	.string "Il futuro di entrambi è in te!$"

BattleFrontier_Lounge3_Text_GetToBattleFactorySingle::
	.string "Vai alla FABBRICA,\n"
	.string "Torneo Scambio SINGOLO, subito!\p"
	.string "Vittoria obbligatoria!\n"
	.string "Non sprecarla!\l"
	.string "Il futuro di entrambi è in te!$"

BattleFrontier_Lounge3_Text_GetToBattleFactoryDouble::
	.string "Vai alla FABBRICA,\n"
	.string "Torneo Scambio DOPPIO, subito!\p"
	.string "Vittoria obbligatoria!\n"
	.string "Non sprecarla!\l"
	.string "Il futuro di entrambi è in te!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceSingle::
	.string "Vai al PALAZZO DI LOTTA,\n"
	.string "SALE SINGOLE, subito!\p"
	.string "Vittoria obbligatoria!\n"
	.string "Non sprecarla!\l"
	.string "Il futuro di entrambi è in te!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceDouble::
	.string "Vai al PALAZZO DI LOTTA,\n"
	.string "SALE DOPPIE, subito!\p"
	.string "Vittoria obbligatoria!\n"
	.string "Non sprecarla!\l"
	.string "Il futuro di entrambi è in te!$"

BattleFrontier_Lounge3_Text_GetToBattleArena::
	.string "Vai all'ARENA DI LOTTA,\n"
	.string "Torneo KO, subito!\p"
	.string "Vittoria obbligatoria!\n"
	.string "Non sprecarla!\l"
	.string "Il futuro di entrambi è in te!$"

BattleFrontier_Lounge3_Text_GetToBattlePike::
	.string "Vai alla GALLERIA,\n"
	.string "Scelta, subito!\p"
	.string "Vittoria obbligatoria!\n"
	.string "Non sprecarla!\l"
	.string "Il futuro di entrambi è in te!$"

BattleFrontier_Lounge3_Text_GetToBattlePyramid::
	.string "Vai alla PIRAMIDE,\n"
	.string "Missione, subito!\p"
	.string "Vittoria obbligatoria!\n"
	.string "Non sprecarla!\l"
	.string "Il futuro di entrambi è in te!$"

BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints::
	.string "Oh, sei tu…\n"
	.string "Bel tentativo…\p"
	.string "Mi dispiace, ma non posso\n"
	.string "restituirti i PUNTI LOTT…\p"
	.string "Chissà che non ci sproni\n"
	.string "a dare di più la prossima volta!$"

BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints::
	.string "Oh, certo!\n"
	.string "Ciao, campione!\p"
	.string "Sapevo che ce la facevi!\n"
	.string "Sapevo che ce l'avresti fatta!\l"
	.string "Abbiamo vinto entrambi!\p"
	.string "Ti restituisco i PUNTI LOTT\n"
	.string "e un piccolo extra da parte mia!$"

BattleFrontier_Lounge3_Text_ObtainedBattlePoints::
	.string "{PLAYER} ha ottenuto\n"
	.string "{STR_VAR_1} PUNTI LOTT.$"

BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge::
	.string "Se ti va un'altra sfida,\n"
	.string "pensa a me!$"

BattleFrontier_Lounge3_Text_NotInterested::
	.string "Non ti interessa?! Non dovresti\n"
	.string "aver paura di rischiare!$"

BattleFrontier_Lounge3_Text_Oh::
	.string "Oh…$"

BattleFrontier_Lounge3_Text_BackedWrongTrainer::
	.string "Ho scommesso di nuovo sull'\p"
	.string "ALLENATORE sbagliato! Dovrei\n"
	.string "lottare come tutti…$"

BattleFrontier_Lounge3_Text_TrainerGoodButRattled::
	.string "Quell'ALLENATORE…\p"
	.string "E' forte, ma si agita facilmente\n"
	.string "per sopravvivere alla DOME…$"

BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne::
	.string "Ridacchia!\n"
	.string "Un vincitore lo vedo al volo!$"

BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges::
	.string "Quegli ALLENATORI…\n"
	.string "Cosa ci fanno qui?\l"
	.string "Dovrebbero sfidare qualcuno.$"
