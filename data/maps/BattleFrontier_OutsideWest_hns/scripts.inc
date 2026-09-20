BattleFrontier_OutsideWest_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition_hns
	.byte 0

BattleFrontier_OutsideWest_OnTransition_hns:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_EventScript_Sailor_hns::
	lock
	faceplayer
	msgbox FarawayIsland_Entrance_Text_SailorReturn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_AsYouLike_hns
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	hideobjectat LOCALID_BATTLE_FRONTIER_SAILOR_HNS, MAP_BATTLE_FRONTIER_OUTSIDE_WEST_HNS
	setvar VAR_0x8004, LOCALID_FARAWAY_BATTLE_FRONTIER_HNS_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	warpsilent MAP_OLIVINE_CITY_PORT_INSIDE_HNS, 8, 16
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_AsYouLike_hns::
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_BattleDomeSign_hns::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattleFactorySign_hns::
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattlePikeSign_hns::
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign_hns, MSGBOX_SIGN
	end

@ Unused. Of note, Battle Tower is in the East section in the final release
BattleFrontier_OutsideWest_EventScript_UnusedNPC1_hns::
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower_hns, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC2_hns::
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Boy1_hns::
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman2_hns::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere_hns
	waitmessage
	applymovement LOCALID_FRONTIER_FISHERMAN_2, Common_Movement_FaceAwayPlayer
	waitmovement 0
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Man1_hns::
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Maniac1_hns::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk_hns
	end

BattleFrontier_OutsideWest_EventScript_Maniac2_hns::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk_hns
	end

BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk_hns::
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons_hns, MSGBOX_DEFAULT
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons_hns, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper_hns::
	lock
	faceplayer
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_Camper_hnsFaceFactory_hns
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_Camper_hnsAlreadyFacingFactory_hns
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_Camper_hnsFaceFactory_hns
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_Camper_hnsFaceFactory_hns
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper_hnsFaceFactory_hns::
	applymovement LOCALID_FRONTIER_CAMPER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_Camper_hnsAlreadyFacingFactory_hns::
	return

BattleFrontier_OutsideWest_EventScript_Girl_hns::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper_hns
	waitmessage
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderNorth_hns
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderSouth_hns
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderWest_hns
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderEast_hns
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderNorth_hns::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth_hns
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderSouth_hns::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth_hns
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderWest_hns::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest_hns
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderEast_hns::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast_hns
	waitmovement 0
	return

BattleFrontier_OutsideWest_Movement_GirlShudderNorth_hns:
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderSouth_hns:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderWest_hns:
	walk_in_place_faster_right
	walk_in_place_faster_right
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderEast_hns:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

BattleFrontier_OutsideWest_EventScript_Woman2_hns::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors_hns, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors_hns
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors_hns
	end

BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors_hns::
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors_hns::
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Fisherman1_hns::
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling_hns, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC3_hns::
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Gentleman_hns::
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Lass_hns::
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_ExpertM_hns::
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man2_hns::
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman1_hns::
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan1_hns::
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan2_hns::
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman3_hns::
	lock
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Boy2_hns::
	lock
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_OldMan_hns::
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man4_hns::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_MAN_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_PokefanF_hns::
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_BattleDomeSign_hns:
	.string "Questo è il DOMO DI LOTTA!\n"
	.string "La via della superstar invincibile!$"

BattleFrontier_OutsideWest_Text_BattleFactorySign_hns:
	.string "Questa è la FABBRICA DI LOTTA!\n"
	.string "Cerca i POKéMON più forti!$"

BattleFrontier_OutsideWest_Text_BattlePikeSign_hns:
	.string "Questa è la LANCE DI LOTTA!\n"
	.string "Scegli uno dei tre sentieri!$"

BattleFrontier_OutsideWest_Text_ThisIsBattleTower_hns:
	.string "Questa è la TORRE LOTTA.\p"
	.string "Gli ALLENATORI portano i loro\n"
	.string "POKéMON migliori per eliminazione.$"

BattleFrontier_OutsideWest_Text_MayISeeYourTicket_hns:
	.string "Salve, è qui per il traghetto?\n"
	.string "Posso vedere il BIGLIETTO?$"

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard_hns:
	.string "{PLAYER} non ha il BIGLIETTO…\p"
	.string "Mi dispiace davvero.\p"
	.string "Per salire sul traghetto serve\n"
	.string "un BIGLIETTO.$"

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo_hns:
	.string "{PLAYER} mostra il BIGLIETTO.\p"
	.string "Perfetto! È tutto qui!\p"
	.string "E dove vuoi andare?$"

BattleFrontier_OutsideWest_Text_SlateportItIs_hns:
	.string "Dunque, PETROPOLI!$"

BattleFrontier_OutsideWest_Text_LilycoveItIs_hns:
	.string "Allora si va a PORTALBA!$"

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime_hns:
	.string "Viaggiate con noi un'altra volta!$"

BattleFrontier_OutsideWest_Text_PleaseBoardFerry_hns:
	.string "Salite sul traghetto e aspettate\n"
	.string "la partenza.$"

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo_hns:
	.string "Dove vuoi andare, allora?$"

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends_hns:
	.string "Sono il migliore dei miei amici.\n"
	.string "Ma qui…\l"
	.string "Non sono valso niente!$"

BattleFrontier_OutsideWest_Text_CantFindBattleTower_hns:
	.string "Voglio andare alla TORRE DI LOTTA,\n"
	.string "ma non la trovo, nonostante la\l"
	.string "mappa della FRONTIERA.\p"
	.string "Questo posto è troppo enorme!$"

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere_hns:
	.string "Volevo affrontare una sfida\n"
	.string "appena arrivato qui.\p"
	.string "Ma per strada ho avuto il mal…\n"
	.string "Urp…$"

BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere_hns:
	.string "Non può venire chiunque\n"
	.string "qui, sai?\p"
	.string "Solo gli ALLENATORI riconosciuti\n"
	.string "forti vengono portati qui.\p"
	.string "Ecco perché molti ALLENATORI non\n"
	.string "conoscono la FRONTIERA LOTTA.$"

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons_hns:
	.string "Ehi, bro…\p"
	.string "Sicuro che possiamo sfidare\n"
	.string "anche senza POKéMON?$"

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons_hns:
	.string "Uh…\n"
	.string "Sarà tutto ok.\p"
	.string "Penso…\p"
	.string "Ma ti ricordi quel tipo terribile?\n"
	.string "Disse: “Ti presto i POKéMON!”$"

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons_hns:
	.string "È la FABBRICA LOTTA.\n"
	.string "Lì puoi affittare POKéMON forti.\p"
	.string "Ma una cosa mi incuriosisce.\n"
	.string "Chi alleva quei POKéMON in affitto?$"

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper_hns:
	.string "Ho paura di entrare nella LOTTA\n"
	.string "PIKE per colpa di SEVIPER…\p"
	.string "M-ma sono venuto fin qui, così\n"
	.string "proverò a superare tutto!\l"
	.string "…Brrr…$"

BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors_hns:
	.string "Facciamo morra cinese!\n"
	.string "Uno, due, tre!\p"
	.string "… … … … … …$"

BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge_hns:
	.string "Sì! Ho vinto!\n"
	.string "Affronterò la LOTTA PIKE!$"

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge_hns:
	.string "Oh, no…\n"
	.string "Ho perso.\p"
	.string "Oggi non sono fortunato.\n"
	.string "La sfida alla LANCE DI LOTTA\l"
	.string "sarà per domani.$"

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling_hns:
	.string "Temo di essere l'unico qui che,\n"
	.string "per strana ragione, preferisce\l"
	.string "pescare che lottare.\p"
	.string "Eh? Qui non catturi niente?\n"
	.string "Che delusione…$"

BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol_hns:
	.string "Oggi continuerò a lottare,\n"
	.string "costi quel che costi.$"

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome_hns:
	.string "Oh? Vai a sfidare\n"
	.string "il DOMO LOTTA?\p"
	.string "Ti auguro buona fortuna.\n"
	.string "Vinciamo entrambi e incontriamoci\l"
	.string "sfidandoci.$"

BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa_hns:
	.string "Nonno, qui!\n"
	.string "Il DOMO DI LOTTA è qui!\l"
	.string "Fai sul serio, nonno!$"

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe_hns:
	.string "Ah, questo è il DOMO LOTTA?\n"
	.string "I GENTLEMEN non mi battono!\p"
	.string "Ma dov'è l'ingresso?$"

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo_hns:
	.string "Fino a poco tempo fa qui\n"
	.string "non c'era niente.\p"
	.string "Ma guarda ora questo posto! Stupendo!\n"
	.string "Porterò mia madre a vedere.$"

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier_hns:
	.string "Finalmente sono arrivato alla\n"
	.string "FRONTIERA!\p"
	.string "Attirerò sguardi con bellezza\n"
	.string "e bravura!$"

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople_hns:
	.string "Gnam, gnam…\p"
	.string "Sembra che in questa piazza ci siano\n"
	.string "persone forti.\p"
	.string "Gnam, gnam…$"

BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike_hns:
	.string "Crunch, croc…\p"
	.string "Un po' di tempo fa ho incontrato\n"
	.string "una grande alla LANCE DI LOTTA.\p"
	.string "Aveva uno sguardo cattivo\n"
	.string "e dal piglio burbero.\p"
	.string "Crunch, croc…\p"
	.string "Si infuriò: “Smettila di\n"
	.string "mangiare!” Poi mi prese a botte.\p"
	.string "Fu un'esperienza da far rizzare\n"
	.string "i capelli, davvero.\p"
	.string "Crunch, croc…$"

BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet_hns:
	.string "Eh? Ma che stai a dire?\n"
	.string "Non è niente!\p"
	.string "L'ultima volta che l'ho incitato,\n"
	.string "i nostri occhi si son incontrati!$"

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering_hns:
	.string "Cheeeee?!\n"
	.string "Pfff!\p"
	.string "È successo solo perché\n"
	.string "ero seduto proprio accanto a te!\p"
	.string "L'AS DEL DOMO ci ha guardati per\n"
	.string "il mio Incitamento assordante!$"

BattleFrontier_OutsideWest_Text_DomeAceIsMine_hns:
	.string "Zitti!\n"
	.string "Basta con quel chiasso!\p"
	.string "Voi tifosi occasionali andate a\n"
	.string "incitare un CAPOPALESTRA!\p"
	.string "L'AS DEL DOMO è mio!\n"
	.string "Il mio unico idolo!$"

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers_hns:
	.string "Quei tipi là che bisticciano…\p"
	.string "Difficile da credere, ma un tempo\n"
	.string "erano ALLENATORI, e bravi.\p"
	.string "Erano incredibilmente tosti,\n"
	.string "e anche famosi.\p"
	.string "Ma un certo ALLENATORE li ha\n"
	.string "annientati a un torneo.\p"
	.string "Furono sconfitti talmente bene\n"
	.string "che finirono per adorarlo.\p"
	.string "Ora sono solo tifosi suoi.\n"
	.string "Ogni giorno incitano il loro\l"
	.string "idolo al DOMO DI LOTTA.$"

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier_hns:
	.string "Ho sentito che qualcuno ha visto\n"
	.string "un POKéMON dalla coda insolitamente\l"
	.string "lunga nella FRONTIERA.\p"
	.string "Sarà adorabile. Ne sono sicuro…\p"
	.string "Le sfide possono attendere. Devo\n"
	.string "trovare quella creatura!$"

