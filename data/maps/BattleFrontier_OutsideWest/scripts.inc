BattleFrontier_OutsideWest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition
	.byte 0

BattleFrontier_OutsideWest_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_FerryAttendant::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_OutsideWest_EventScript_NoSSTicket
	message BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination::
	multichoicedefault 18, 6, MULTI_SSTIDAL_BATTLE_FRONTIER, 2, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_OutsideWest_EventScript_FerryToSlateport
	case 1, BattleFrontier_OutsideWest_EventScript_FerryToLilycove
	case 2, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	case MULTI_B_PRESSED, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	end

BattleFrontier_OutsideWest_EventScript_NoSSTicket::
	msgbox BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToSlateport::
	msgbox BattleFrontier_OutsideWest_Text_SlateportItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToLilycove::
	msgbox BattleFrontier_OutsideWest_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination::
	message BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_BoardFerry::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_FRONTIER_FERRY_ATTENDANT, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	setvar VAR_0x8004, LOCALID_FRONTIER_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	return

BattleFrontier_OutsideWest_EventScript_CancelFerrySelect::
	msgbox BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_BattleDomeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattleFactorySign::
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattlePikeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign, MSGBOX_SIGN
	end

@ Unused. Of note, Battle Tower is in the East section in the final release
BattleFrontier_OutsideWest_EventScript_UnusedNPC1::
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC2::
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Boy1::
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman2::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere
	waitmessage
	applymovement LOCALID_FRONTIER_FISHERMAN_2, Common_Movement_FaceAwayPlayer
	waitmovement 0
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Man1::
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Maniac1::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_Maniac2::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk::
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons, MSGBOX_DEFAULT
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper::
	lock
	faceplayer
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_CamperFaceFactory::
	applymovement LOCALID_FRONTIER_CAMPER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory::
	return

BattleFrontier_OutsideWest_EventScript_Girl::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper
	waitmessage
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_GirlShudderNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_GirlShudderSouth
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_GirlShudderWest
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_GirlShudderEast
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_GirlShudderNorth::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderSouth::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderWest::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderEast::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast
	waitmovement 0
	return

BattleFrontier_OutsideWest_Movement_GirlShudderNorth:
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderSouth:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderWest:
	walk_in_place_faster_right
	walk_in_place_faster_right
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderEast:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

BattleFrontier_OutsideWest_EventScript_Woman2::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors
	end

BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Fisherman1::
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC3::
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Lass::
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_ExpertM::
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man2::
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman1::
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan1::
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan2::
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Boy2::
	lock
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_OldMan::
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man4::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_MAN_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_PokefanF::
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_BattleDomeSign:
	.string "Questo è il DOMO DI LOTTA!\n"
	.string "La via della superstar invincibile!$"

BattleFrontier_OutsideWest_Text_BattleFactorySign:
	.string "Questa è la FABBRICA DI LOTTA!\n"
	.string "Cerca i POKéMON più forti!$"

BattleFrontier_OutsideWest_Text_BattlePikeSign:
	.string "Questa è la LANCE DI LOTTA!\n"
	.string "Scegli uno dei tre sentieri!$"

BattleFrontier_OutsideWest_Text_ThisIsBattleTower:
	.string "Questa è la TORRE LOTTA.\p"
	.string "Gli ALLENATORI portano i loro\n"
	.string "POKéMON migliori per eliminazione.$"

BattleFrontier_OutsideWest_Text_MayISeeYourTicket:
	.string "Salve, è qui per il traghetto?\n"
	.string "Posso vedere il BIGLIETTO?$"

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard:
	.string "{PLAYER} non ha il BIGLIETTO…\p"
	.string "Mi dispiace davvero.\p"
	.string "Per salire sul traghetto serve\n"
	.string "un BIGLIETTO.$"

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo:
	.string "{PLAYER} mostra il BIGLIETTO.\p"
	.string "Perfetto! È tutto qui!\p"
	.string "E dove vuoi andare?$"

BattleFrontier_OutsideWest_Text_SlateportItIs:
	.string "Dunque, PETROPOLI!$"

BattleFrontier_OutsideWest_Text_LilycoveItIs:
	.string "Allora si va a PORTALBA!$"

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime:
	.string "Viaggiate con noi un'altra volta!$"

BattleFrontier_OutsideWest_Text_PleaseBoardFerry:
	.string "Salite sul traghetto e aspettate\n"
	.string "la partenza.$"

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo:
	.string "Dove vuoi andare, allora?$"

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends:
	.string "Sono il migliore dei miei amici.\n"
	.string "Ma qui…\l"
	.string "Non sono valso niente!$"

BattleFrontier_OutsideWest_Text_CantFindBattleTower:
	.string "Voglio andare alla TORRE DI LOTTA,\n"
	.string "ma non la trovo, nonostante la\l"
	.string "mappa della FRONTIERA.\p"
	.string "Questo posto è troppo enorme!$"

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere:
	.string "Volevo affrontare una sfida\n"
	.string "appena arrivato qui.\p"
	.string "Ma per strada ho avuto il mal…\n"
	.string "Urp…$"

BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere:
	.string "Non può venire chiunque\n"
	.string "qui, sai?\p"
	.string "Solo gli ALLENATORI riconosciuti\n"
	.string "forti vengono portati qui.\p"
	.string "Ecco perché molti ALLENATORI non\n"
	.string "conoscono la FRONTIERA LOTTA.$"

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons:
	.string "Ehi, bro…\p"
	.string "Sicuro che possiamo sfidare\n"
	.string "anche senza POKéMON?$"

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons:
	.string "Uh…\n"
	.string "Sarà tutto ok.\p"
	.string "Penso…\p"
	.string "Ma ti ricordi quel tipo terribile?\n"
	.string "Disse: “Ti presto i POKéMON!”$"

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons:
	.string "È la FABBRICA LOTTA.\n"
	.string "Lì puoi affittare POKéMON forti.\p"
	.string "Ma una cosa mi incuriosisce.\n"
	.string "Chi alleva quei POKéMON in affitto?$"

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper:
	.string "Ho paura di entrare nella LOTTA\n"
	.string "PIKE per colpa di SEVIPER…\p"
	.string "M-ma sono venuto fin qui, così\n"
	.string "proverò a superare tutto!\l"
	.string "…Brrr…$"

BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors:
	.string "Facciamo morra cinese!\n"
	.string "Uno, due, tre!\p"
	.string "… … … … … …$"

BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge:
	.string "Sì! Ho vinto!\n"
	.string "Affronterò la LOTTA PIKE!$"

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge:
	.string "Oh, no…\n"
	.string "Ho perso.\p"
	.string "Oggi non sono fortunato.\n"
	.string "La sfida alla LANCE DI LOTTA\l"
	.string "sarà per domani.$"

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling:
	.string "Temo di essere l'unico qui che,\n"
	.string "per strana ragione, preferisce\l"
	.string "pescare che lottare.\p"
	.string "Eh? Qui non catturi niente?\n"
	.string "Che delusione…$"

BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol:
	.string "Oggi continuerò a lottare,\n"
	.string "costi quel che costi.$"

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome:
	.string "Oh? Vai a sfidare\n"
	.string "il DOMO LOTTA?\p"
	.string "Ti auguro buona fortuna.\n"
	.string "Vinciamo entrambi e incontriamoci\l"
	.string "sfidandoci.$"

BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa:
	.string "Nonno, qui!\n"
	.string "Il DOMO DI LOTTA è qui!\l"
	.string "Fai sul serio, nonno!$"

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe:
	.string "Ah, questo è il DOMO LOTTA?\n"
	.string "I GENTLEMEN non mi battono!\p"
	.string "Ma dov'è l'ingresso?$"

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo:
	.string "Fino a poco tempo fa qui\n"
	.string "non c'era niente.\p"
	.string "Ma guarda ora questo posto! Stupendo!\n"
	.string "Porterò mia madre a vedere.$"

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier:
	.string "Sono arrivato alla FRONTIERA\n"
	.string "LOTTA!\p"
	.string "Attirerò l'attenzione col mio\n"
	.string "fascino e il mio talento!$"

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople:
	.string "Gnam, gnam…\p"
	.string "Sembra che in questa piazza ci siano\n"
	.string "persone forti.\p"
	.string "Gnam, gnam…$"

BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike:
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

BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet:
	.string "Eh? Ma che stai a dire?\n"
	.string "Non è niente!\p"
	.string "L'ultima volta che l'ho incitato,\n"
	.string "i nostri occhi si son incontrati!$"

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering:
	.string "Cheeeee?!\n"
	.string "Pfff!\p"
	.string "È successo solo perché\n"
	.string "ero seduto proprio accanto a te!\p"
	.string "L'AS DEL DOMO ci ha guardati per\n"
	.string "il mio Incitamento assordante!$"

BattleFrontier_OutsideWest_Text_DomeAceIsMine:
	.string "Zitti!\n"
	.string "Basta con quel chiasso!\p"
	.string "Voi tifosi occasionali andate a\n"
	.string "incitare un CAPOPALESTRA!\p"
	.string "L'AS DEL DOMO è mio!\n"
	.string "Il mio unico idolo!$"

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers:
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

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier:
	.string "Ho sentito che qualcuno ha visto\n"
	.string "un POKéMON dalla coda insolitamente\l"
	.string "lunga nella FRONTIERA.\p"
	.string "Sarà adorabile. Ne sono sicuro…\p"
	.string "Le sfide possono attendere. Devo\n"
	.string "trovare quella creatura!$"

