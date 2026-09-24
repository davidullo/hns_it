MauvilleCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_OnTransition
	.byte 0

MauvilleCity_OnTransition:
	setflag FLAG_VISITED_MAUVILLE_CITY
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	clearflag FLAG_HIDE_SLATEPORT_MUSEUM_POPULATION
	setflag FLAG_SYS_TV_START
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	setvar VAR_MAUVILLE_GYM_STATE, 0
	call_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_MoveWattsonBackToGym
	end

MauvilleCity_EventScript_MoveWattsonBackToGym::
	clearflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
	setflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	setflag FLAG_WATTSON_REMATCH_AVAILABLE
	return

MauvilleCity_EventScript_Boy::
	msgbox MauvilleCity_Text_NurseHurtMonBackToHealth, MSGBOX_NPC
	end

MauvilleCity_EventScript_Maniac::
	msgbox MauvilleCity_Text_AllSortsOfPeopleComeThrough, MSGBOX_NPC
	end

MauvilleCity_EventScript_Woman::
	msgbox MauvilleCity_Text_RydelVeryGenerous, MSGBOX_NPC
	end

MauvilleCity_EventScript_RichBoy::
	msgbox MauvilleCity_Text_PokemonCanJumpYouOnBike, MSGBOX_NPC
	end

MauvilleCity_EventScript_CitySign::
	msgbox MauvilleCity_Text_CitySign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GymSign::
	msgbox MauvilleCity_Text_GymSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_BikeShopSign::
	msgbox MauvilleCity_Text_BikeShopSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GameCornerSign::
	msgbox MauvilleCity_Text_GameCornerSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_SchoolKidM::
	lock
	faceplayer
	goto_if_set FLAG_TV_EXPLAINED, MauvilleCity_EventScript_TVExplained
	msgbox MauvilleCity_Text_ExplainTV, MSGBOX_DEFAULT
	setflag FLAG_TV_EXPLAINED
	release
	end

MauvilleCity_EventScript_TVExplained::
	msgbox MauvilleCity_Text_BeenCheckingOutTV, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_UncleAskPlayerToBattleWally
	msgbox MauvilleCity_Text_UncleHesTooPeppy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_UncleAskPlayerToBattleWally::
	msgbox MauvilleCity_Text_UncleCanYouBattleWally, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_Wally::
	lockall
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_WallyRequestBattleAgain
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWantToChallengeGym, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_UncleYourePushingIt, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_WallyWeCanBeatAnyone, MSGBOX_DEFAULT
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWillYouBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_EventScript_BattleWallyPrompt::
	call_if_eq VAR_RESULT, YES, MauvilleCity_EventScript_BattleWally
	goto_if_eq VAR_RESULT, NO, MauvilleCity_EventScript_DeclineWallyBattle
	closemessage
	switch VAR_FACING
	case DIR_NORTH, MauvilleCity_EventScript_WallyAndUncleExitNorth
	case DIR_EAST, MauvilleCity_EventScript_WallyAndUncleExitEast
	end

MauvilleCity_EventScript_WallyAndUncleExitNorth::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth1
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitNorth1
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth1
	waitmovement 0
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerFaceUncleNorth
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerNorth
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth2
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth2
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitNorth2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_WallyAndUncleExitEast::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast1
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitEast1
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast1
	waitmovement 0
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerEast
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast2
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast2
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitEast2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_DefeatedWally::
	removeobject LOCALID_MAUVILLE_WALLY
	removeobject LOCALID_MAUVILLE_WALLYS_UNCLE
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
	setvar VAR_WALLY_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottApproachPlayerNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottApproachPlayerEast
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox MauvilleCity_Text_ScottYouDidntHoldBack, MSGBOX_DEFAULT
	closemessage
	addvar VAR_SCOTT_STATE, 1
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottExitEast
	removeobject LOCALID_MAUVILLE_SCOTT
	releaseall
	end

MauvilleCity_EventScript_ScottApproachPlayerNorth::
	addobject LOCALID_MAUVILLE_SCOTT
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottApproachPlayerNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottApproachPlayerEast::
	setobjectxyperm LOCALID_MAUVILLE_SCOTT, 12, 13
	addobject LOCALID_MAUVILLE_SCOTT
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottApproachPlayerEast
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitNorth::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitNorth
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottExitNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitEast::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitEast
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottExitEast
	waitmovement 0
	return

MauvilleCity_EventScript_BattleWally::
	msgbox MauvilleCity_Text_WallyHereICome, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_MAUVILLE, MauvilleCity_Text_WallyDefeat
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyIllGoBackToVerdanturf, MSGBOX_DEFAULT
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_ThankYouNotEnoughToBattle, MSGBOX_DEFAULT
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_UncleNoNeedToBeDown, MSGBOX_DEFAULT
	return

MauvilleCity_EventScript_DeclineWallyBattle::
	setflag FLAG_DECLINED_WALLY_BATTLE_MAUVILLE
	msgbox MauvilleCity_Text_WallyMyUncleWontKnowImStrong, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallyRequestBattleAgain::
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_WallyPleaseBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_Movement_WallyExitNorth1:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	step_end

MauvilleCity_Movement_WallyExitEast1:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallyExitNorth2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_WallyExitEast2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast2:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitNorth:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitEast:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast1:
	delay_16
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth1:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_WallysUncleExitNorth1:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

MauvilleCity_Movement_WallysUncleExitEast1:
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_PlayerFaceUncleNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerNorth:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerEast:
	walk_right
	walk_up
	step_end

MauvilleCity_Movement_WallysUncleExitNorth2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallysUncleExitEast2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_ScottApproachPlayerEast:
	walk_up
	walk_up
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

MauvilleCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_EventScript_Wattson::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_ReceivedThunderbolt
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_EventScript_CompletedNewMauville
	goto_if_set FLAG_GOT_BASEMENT_KEY_FROM_WATTSON, MauvilleCity_EventScript_BegunNewMauville
	msgbox MauvilleCity_Text_WattsonNeedFavorTakeKey, MSGBOX_DEFAULT
	giveitem ITEM_BASEMENT_KEY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_BASEMENT_KEY_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_BegunNewMauville::
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Text_WattsonThanksTakeTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_THUNDERBOLT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_ReceivedThunderbolt::
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_RegisterWallyCall::
	lockall
	pokenavcall MauvilleCity_Text_WallyPokenavCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Text_RegisteredWally, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WALLY_MATCH_CALL
	clearflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	releaseall
	end

MauvilleCity_Text_UncleHesTooPeppy:
	.string "ZIO: È per i POKéMON che\n"
	.string "questo ragazzo è più vispo…\l"
	.string "Ma è diventato troppo vispo…$"

MauvilleCity_Text_WallyWantToChallengeGym:
	.string "LINO: Dai, ZIO, ti prego?\p"
	.string "Voglio sfidare questa PALESTRA\n"
	.string "e vedere quanto sono migliorato.\p"
	.string "Ti prego? Posso, ti prego?$"

MauvilleCity_Text_UncleYourePushingIt:
	.string "ZIO: Aspetta, LINO.\p"
	.string "Da quando vivi con i POKéMON,\n"
	.string "sei diventato molto più forte.\p"
	.string "Ma non credi di esagerare\n"
	.string "a sfidare una PALESTRA?$"

MauvilleCity_Text_WallyWeCanBeatAnyone:
	.string "LINO: Non esagero.\p"
	.string "Se unisco le forze con RALTS,\n"
	.string "possiamo battere chiunque!$"

MauvilleCity_Text_WallyWillYouBattleMe:
	.string "LINO: Oh! Ciao, {PLAYER}!\p"
	.string "Sono molto più forte da\n"
	.string "quando ci siamo conosciuti.\p"
	.string "{PLAYER}, voglio che tu e mio ZIO\n"
	.string "lo capiate.\p"
	.string "{PLAYER}, ti prego, vuoi fare\n"
	.string "una lotta con me?$"

MauvilleCity_Text_WallyMyUncleWontKnowImStrong:
	.string "LINO: Oh… Se non lotti con me,\n"
	.string "{PLAYER}, il mio ZIO non saprà che\l"
	.string "sono diventato davvero forte.$"

MauvilleCity_Text_UncleCanYouBattleWally:
	.string "ZIO: {PLAYER}{KUN}, vero?\n"
	.string "Posso chiederti di lottare con\l"
	.string "LINO, solo per stavolta?\p"
	.string "Con il carattere che ha, non credo\n"
	.string "che ascolti ragioni.$"

MauvilleCity_Text_WallyPleaseBattleMe:
	.string "LINO: {PLAYER}, ti prego!\n"
	.string "Lotta con me, ti prego.$"

MauvilleCity_Text_WallyHereICome:
	.string "LINO: {PLAYER}, grazie.\p"
	.string "Ok… Arrivo!$"

MauvilleCity_Text_WallyDefeat:
	.string "LINO: … … … … … … …\p"
	.string "… … … … … … … …\p"
	.string "Ho perso…$"

MauvilleCity_Text_WallyIllGoBackToVerdanturf:
	.string "LINO: ZIO…\n"
	.string "Torno a VERDANTURF…$"

MauvilleCity_Text_ThankYouNotEnoughToBattle:
	.string "{PLAYER}, grazie.\n"
	.string "Fare l'ALLENATORE è duro, no?\p"
	.string "Non basta avere POKéMON\n"
	.string "e farli lottare. Non è questo\l"
	.string "essere un vero ALLENATORE.$"

MauvilleCity_Text_UncleNoNeedToBeDown:
	.string "ZIO: LINO, non devi essere così\n"
	.string "giù di morale.\p"
	.string "Cosa ti impedisce di diventare\n"
	.string "sempre più forte?\p"
	.string "Dai, andiamo a casa.\n"
	.string "Tutti ti aspettano.$"

MauvilleCity_Text_UncleVisitUsSometime:
	.string "ZIO: {PLAYER}{KUN}, ho capito ora\n"
	.string "che sei l'ALLENATORE che ha\l"
	.string "badato a LINO quando ha preso\l"
	.string "il suo POKéMON.\p"
	.string "Perché non ci fai visita a\n"
	.string "VERDANTURF?\l"
	.string "LINO ne sarebbe felice.$"


MauvilleCity_Text_WallyPokenavCall:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "LINO: Oh, ciao, {PLAYER}!\p"
	.string "Volevo dirti soltanto che\n"
	.string "lo zio mi ha preso un POKéNAV!\p"
	.string "Ora posso contattarti\n"
	.string "quando voglio, {PLAYER}!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

MauvilleCity_Text_RegisteredWally:
	.string "LINO registrato\n"
	.string "nel POKéNAV.$"

MauvilleCity_Text_ScottYouDidntHoldBack:
	.string "SAVERIO: Eh eh…\n"
	.string "Stavo guardando quella lotta!\p"
	.string "Sei amico di quel ragazzo, LINO,\n"
	.string "vero?\p"
	.string "Ma non ti sei trattenuto\n"
	.string "e l'hai battuto alla grande.\p"
	.string "Sì! Una vera lotta POKéMON\n"
	.string "è così!\p"
	.string "Adoro gli ALLENATORI così!\p"
	.string "… … … … … …\n"
	.string "Tiferò per te!$"

MauvilleCity_Text_WattsonNeedFavorTakeKey:
	.string "WALTER: Oh, {PLAYER}{KUN}!\n"
	.string "Hai l'aria di chi ha grinta!\l"
	.string "E questo mi piace, wahahahaha!\p"
	.string "Bene! Ho deciso!\n"
	.string "Mi serve un favore, {PLAYER}{KUN}!\p"
	.string "Sotto FORTEVILLA c'è una zona\n"
	.string "chiamata CICLOFORTE.\p"
	.string "{PLAYER}{KUN}, vorrei che andassi lì a\n"
	.string "spegnere il GENERATORE.\p"
	.string "Il GENERATORE si sta comportando\n"
	.string "male. Sta diventando pericoloso.\p"
	.string "Tieni, questa è la CHIAVE per entrare\n"
	.string "a CICLOFORTE.$"

MauvilleCity_Text_WattsonWontBeChallenge:
	.string "WALTER: Non preoccuparti.\n"
	.string "Per te non sarà una sfida.\p"
	.string "L'ingresso a CICLANOVA è a\n"
	.string "un breve SURF dalla PERCORSO 110.\p"
	.string "Ecco, hai la mia fiducia!\n"
	.string "Wahahahaha!$"

MauvilleCity_Text_WattsonThanksTakeTM:
	.string "WALTER: Wahahahaha!\p"
	.string "Lo sapevo, {PLAYER}{KUN}! Sapevo di\n"
	.string "aver scelto bene!\p"
	.string "Questo è il mio grazie: una MT con\n"
	.string "SAETTA!\p"
	.string "Dai, te la sei meritata!$"

MauvilleCity_Text_WattsonYoungTakeCharge:
	.string "WALTER: Wahahahaha!\p"
	.string "Mi fa immenso piacere vedere\n"
	.string "i giovani che si danno da fare!$"

MauvilleCity_Text_NurseHurtMonBackToHealth:
	.string "Sai, è forte fare lotte coi\n"
	.string "POKéMON…\p"
	.string "Ma se un POKéMON si fa male,\n"
	.string "devi curarlo per guarirlo.$"

MauvilleCity_Text_AllSortsOfPeopleComeThrough:
	.string "Le strade di questa città vanno\n"
	.string "a nord e a sud, a est e a ovest.\p"
	.string "Perciò passano tutti i tipi\n"
	.string "di gente.$"

MauvilleCity_Text_RydelVeryGenerous:
	.string "Sei già stato da CICLI RYDEL?\p"
	.string "RYDEL, il titolare, è un uomo\n"
	.string "generoso.$"

MauvilleCity_Text_PokemonCanJumpYouOnBike:
	.string "Anche in Bicicletta,\n"
	.string "i POKéMON selvatici ti assalgono.$"

MauvilleCity_Text_CitySign:
	.string "CICLAMIPOLI\n"
	.string "“La brillante città del divertimento!”$"

MauvilleCity_Text_GymSign:
	.string "PALESTRA POKéMON DI MAUVILLE\n"
	.string "CAPO: WALTER\l"
	.string "“L'uomo allegro ed elettrizzante!”$"

MauvilleCity_Text_BikeShopSign:
	.string "“Corri sulla ghiaia e scatenati\n"
	.string "l'anima!”\l"
	.string "CICLI RYDEL$"

MauvilleCity_Text_GameCornerSign:
	.string "“Il luogo di gioco per tutti!”\n"
	.string "MAUVILLE GAME CORNER$"

MauvilleCity_Text_ExplainTV:
	.string "Ciao, guardi la TV?\p"
	.string "Ultimamente hanno aggiunto un\n"
	.string "sacco di bei programmi.\p"
	.string "La TV è forte. Ho visto amici in TV\n"
	.string "così, all'improvviso.\p"
	.string "E a volte ti mettono in TV\n"
	.string "senza dirtelo.\p"
	.string "Vorrei apparire in TV anch'io.\p"
	.string "Per questo dovresti guardare\n"
	.string "la TV quando puoi.$"

MauvilleCity_Text_BeenCheckingOutTV:
	.string "Ciao, guardi un po' la TV?$"
