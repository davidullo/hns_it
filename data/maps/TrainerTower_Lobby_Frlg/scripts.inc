TrainerTower_Lobby_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerTower_Lobby_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerTower_Lobby_OnReturnToField
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerTower_Lobby_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, TrainerTower_Lobby_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerTower_Lobby_OnFrame
	.byte 0

TrainerTower_Lobby_OnResume::
	setvar VAR_TEMP_2, 0
	ttower_resumetimer
	ttower_shouldexit
	goto_if_eq VAR_RESULT, FALSE, TrainerTower_Lobby_OnResumeEnd
	@ Never reached, above always FALSE
	setvar VAR_TEMP_0, 0
	setobjectxy LOCALID_PLAYER, 9, 7
	applymovement LOCALID_PLAYER, TrainerTower_Lobby_Movement_FaceReceptionist
TrainerTower_Lobby_OnResumeEnd::
	end

TrainerTower_Lobby_OnReturnToField::
	addobject LOCALID_TOWER_NURSE
	addobject LOCALID_TOWER_MART_CLERK
	addobject LOCALID_TOWER_RECEPTIONIST
	addobject LOCALID_TOWER_COOLTRAINER_F
	addobject LOCALID_TOWER_BALDING_MAN
	end

TrainerTower_Lobby_OnLoad::
	call_if_eq VAR_TEMP_D, 17, TrainerTower_Lobby_OpenCounterBarrier
	end

TrainerTower_Lobby_OpenCounterBarrier::
	setmetatile 17, 10, METATILE_TrainerTower_Floor_ShadeBottomLeft, 0
	return

TrainerTower_Lobby_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_TRAINER_TOWER_LOBBY
	getplayerxy VAR_TEMP_D, VAR_RESULT
	end

TrainerTower_Lobby_OnFrame::
	map_script_2 VAR_TEMP_0, 0, TrainerTower_Lobby_EventScript_Enter
	map_script_2 VAR_TEMP_D, 17, TrainerTower_Lobby_EventScript_ExitElevator
	.2byte 0

TrainerTower_Lobby_EventScript_ExitElevator::
	lockall
	applymovement LOCALID_PLAYER, TrainerTower_Lobby_Movement_ExitElevator
	waitmovement 0
	setmetatile 17, 10, METATILE_TrainerTower_CounterBarrier, 1
	special DrawWholeMapView
	playse SE_CLICK
	waitse
	setvar VAR_TEMP_D, 0
	releaseall
	end

TrainerTower_Lobby_Movement_ExitElevator::
	walk_down
	walk_down
	step_end

TrainerTower_Lobby_EventScript_Enter::
	setvar VAR_TEMP_0, 1
	ttower_getchallengestatus
	switch VAR_RESULT
	case TT_CHALLENGE_STATUS_LOST, TrainerTower_Lobby_EventScript_LostChallenge
	case TT_CHALLENGE_STATUS_UNK, TrainerTower_Lobby_EventScript_ExitChallengeSpeakToReceptionist
	case TT_CHALLENGE_STATUS_NORMAL, TrainerTower_Lobby_EventScript_EnterEnd

TrainerTower_Lobby_EventScript_LostChallenge::
	lock
	faceplayer
	applymovement LOCALID_PLAYER, TrainerTower_Lobby_Movement_FaceReceptionist
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox TrainerTower_Lobby_Text_TooBadComeBackTryAgain
	goto TrainerTower_Lobby_EventScript_ExitChallenge

@ Presumably E-Reader related
TrainerTower_Lobby_EventScript_ExitChallengeSpeakToReceptionist::
	lock
	faceplayer
	applymovement LOCALID_PLAYER, TrainerTower_Lobby_Movement_FaceReceptionist
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox TrainerTower_Lobby_Text_MoveCounterHereWhenTrainersSwitch
TrainerTower_Lobby_EventScript_ExitChallenge::
	closemessage
	applymovement LOCALID_PLAYER, TrainerTower_Lobby_Movement_WalkDown
	waitmovement 0
	setvar VAR_MAP_SCENE_TRAINER_TOWER, 0
	release
TrainerTower_Lobby_EventScript_EnterEnd::
	end

TrainerTower_Lobby_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

TrainerTower_Lobby_EventScript_Receptionist::
	lock
	faceplayer
	ttower_getbeatchallenge
	goto_if_eq VAR_RESULT, TRUE, TrainerTower_Lobby_EventScript_ThanksForCompeting
	msgbox TrainerTower_Lobby_Text_GiveItYourBest
	goto TrainerTower_Lobby_EventScript_ReceptionistEnd

TrainerTower_Lobby_EventScript_ThanksForCompeting::
	msgbox TrainerTower_Lobby_Text_ThanksForCompeting
TrainerTower_Lobby_EventScript_ReceptionistEnd::
	release
	end

TrainerTower_Lobby_EventScript_MartClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart TrainerTower_Lobby_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
TrainerTower_Lobby_Mart_Items::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

TrainerTower_Lobby_EventScript_EntryTrigger::
	lockall
	applymovement LOCALID_PLAYER, TrainerTower_Lobby_Movement_FaceReceptionist
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox TrainerTower_Lobby_Text_WelcomeToTrainerTower
	ttower_getnumfloors
	goto_if_eq VAR_RESULT, FALSE, TrainerTower_Lobby_EventScript_AllFloorsUsed
	msgbox TrainerTower_Lobby_Text_TrainersUpToFloorNum
	goto TrainerTower_Lobby_EventScript_AskEnterChallenge

TrainerTower_Lobby_EventScript_AllFloorsUsed::
	msgbox TrainerTower_Lobby_Text_TrainersUpEighthFloor
TrainerTower_Lobby_EventScript_AskEnterChallenge::
	message TrainerTower_Lobby_Text_LikeToChallengeTrainers
	waitmessage
	multichoice 18, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, TrainerTower_Lobby_EventScript_ChooseChallenge
	case 1, TrainerTower_Lobby_EventScript_DeclineChallenge
	case 2, TrainerTower_Lobby_EventScript_ChallengeInfo
	case MULTI_B_PRESSED, TrainerTower_Lobby_EventScript_DeclineChallenge
	end

TrainerTower_Lobby_EventScript_ChallengeInfo::
	msgbox TrainerTower_Lobby_Text_ExplainTrainerTower
	goto TrainerTower_Lobby_EventScript_AskEnterChallenge
	end

TrainerTower_Lobby_EventScript_ChooseChallenge::
	multichoice 13, 3, MULTI_TRAINER_TOWER_MODE, FALSE
	switch VAR_RESULT
	case 0, TrainerTower_Lobby_EventScript_BeginChallenge
	case 1, TrainerTower_Lobby_EventScript_BeginChallenge
	case 2, TrainerTower_Lobby_EventScript_BeginChallenge
	case 3, TrainerTower_Lobby_EventScript_BeginChallenge
	case 4, TrainerTower_Lobby_EventScript_DeclineChallenge
	case MULTI_B_PRESSED, TrainerTower_Lobby_EventScript_DeclineChallenge
	end

TrainerTower_Lobby_EventScript_BeginChallenge::
	copyvar VAR_0x8005, VAR_RESULT
	setvar VAR_MAP_SCENE_TRAINER_TOWER, 1
	special HealPlayerParty
	msgbox TrainerTower_Lobby_Text_StartClockGetSetGo
	ttower_startchallenge
	releaseall
	end

TrainerTower_Lobby_EventScript_DeclineChallenge::
	msgbox TrainerTower_Lobby_Text_PleaseVisitUsAgain
	closemessage
	applymovement LOCALID_PLAYER, TrainerTower_Lobby_Movement_WalkDown
	waitmovement 0
	releaseall
	end

TrainerTower_Lobby_Movement_FaceReceptionist::
	face_right
	step_end

TrainerTower_Lobby_Movement_WalkDown::
	walk_down
	step_end

TrainerTower_Lobby_EventScript_ShowRecords::
	lockall
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, 1
	special ShowTrainerHillRecords
	waitstate
	releaseall
	end

TrainerTower_Lobby_EventScript_CooltrainerF::
	msgbox TrainerTower_Lobby_Text_WonderWhatKindsOfTrainers, MSGBOX_NPC
	end

TrainerTower_Lobby_EventScript_BaldingMan::
	msgbox TrainerTower_Lobby_Text_StairsTougherThanAnyBattle, MSGBOX_NPC
	end

@ All Trainer Tower text (Lobby and Roof) is interleaved here

TrainerTower_Lobby_Text_WelcomeToTrainerTower::
	.string "Ciao!\p"
	.string "Benvenuto alla TORRE ALLENATORI dove\n"
	.string "gli ALLENATORI si radunano da ovunque!$"

TrainerTower_Lobby_Text_TrainersUpToFloorNum::
	.string "ALLENATORI da tutto il mondo\n"
	.string "si radunano qui per lottare.\p"
	.string "Vediamo…\p"
	.string "Al momento, ci sono ALLENATORI solo\n"
	.string "fino al Piano {STR_VAR_1}.$"

TrainerTower_Lobby_Text_TrainersUpEighthFloor::
	.string "Gli ALLENATORI attendono la tua\n"
	.string "sfida fino all'ottavo piano.$"

TrainerTower_Lobby_Text_LikeToChallengeTrainers::
	.string "Vuoi sfidare gli\n"
	.string "ALLENATORI in attesa?$"

TrainerTower_Lobby_Text_StartClockGetSetGo::
	.string "Ok, farò partire il cronometro,\n"
	.string "quindi dai tutto te stesso.\p"
	.string "Ai vostri posti…\p"
	.string "Pronti…\p"
	.string "Via!$"

TrainerTower_Lobby_Text_PleaseVisitUsAgain::
	.string "Torna a trovarci presto!$"

TrainerTower_Lobby_Text_TooBadComeBackTryAgain::
	.string "Che peccato.\p"
	.string "Penso che tu abbia fatto uno sforzo\n"
	.string "enorme nelle tue lotte.\p"
	.string "Torna a riprovare!$"

TrainerTower_Lobby_Text_GiveItYourBest::
	.string "Spero che darai il massimo.$"

TrainerTower_Lobby_Text_MoveCounterHereWhenTrainersSwitch::
	.string "Quando gli ALLENATORI si scambiano\n"
	.string "di posto, c'è molta ressa.\p"
	.string "Per evitare la calca, abbiamo spostato\n"
	.string "qui il bancone della reception.\p"
	.string "Ci scusiamo per il disagio.$"

TrainerTower_Roof_Text_ImOwnerBattledPerfectly::
	.string "Salve…\p"
	.string "Sono il proprietario di questa TORRE…\p"
	.string "Come il cielo si libra sopra questo\n"
	.string "tetto…\p"
	.string "La carezza dei venti quassù…\p"
	.string "È tutto così perfetto…\p"
	.string "Il modo in cui hai lottato…\n"
	.string "Anche quello è stato perfezione…$"

TrainerTower_Roof_Text_ThisIsForYou::
	.string "Questo è per te…$"

TrainerTower_Roof_Text_DoneItInRecordTime::
	.string "Oh!\n"
	.string "Stupendo!\p"
	.string "È meraviglioso come sei arrivato\n"
	.string "quassù così in fretta.\p"
	.string "Il fatto è che ci sei riuscito in\n"
	.string "tempo record…\p"
	.string "Farò pubblicare il tuo record al\n"
	.string "banco accettazione.$"

TrainerTower_Roof_Text_TookSweetTimeGettingHere::
	.string "Sembra che ti sia preso il tuo bel\n"
	.string "tempo per arrivare qui…$"

TrainerTower_Roof_Text_IdLikeToSeeBetterTime::
	.string "Quello che vorrei vedere è un\n"
	.string "tempo migliore da parte tua…\p"
	.string "Conto su di te.\p"
	.string "Fino ad allora, addio…$"

TrainerTower_Text_XMinYZSec::
	.string "{STR_VAR_1} min. {STR_VAR_2}.{STR_VAR_3} sec.$"

TrainerTower_Lobby_Text_HereAreTheResults::
	.string "せいせきひょうです$"

TrainerTower_Lobby_Text_NeedTwoMonsForDouble::
	.string "Questa è una lotta due contro due.\p"
	.string "Non puoi lottare se non hai\n"
	.string "almeno due POKéMON.$"

TrainerTower_Lobby_Text_ExplainTrainerTower::
	.string "Qui alla TORRE ALLENATORI c'è un\n"
	.string "evento chiamato CORSA CONTRO IL TEMPO.\p"
	.string "Verrà cronometrato quanto in fretta\n"
	.string "riesci ad arrivare dal banco\l"
	.string "accettazione al PROPRIETARIO sul tetto.\p"
	.string "I tempi migliori saranno registrati sul\n"
	.string "Tabellone dei Tempi.\p"
	.string "Sfida gli amici per vedere\n"
	.string "chi è il più veloce.\p"
	.string "Non guadagnerai Punti ESP.\n"
	.string "né soldi battendo gli ALLENATORI qui.$"

TrainerTower_Lobby_Text_ThanksForCompeting::
	.string "Grazie per aver partecipato!$"

TrainerTower_Lobby_Text_WonderWhatKindsOfTrainers::
	.string "Sono qui per vedere quanto valgo.\p"
	.string "Chissà che tipi di ALLENATORI\n"
	.string "mi aspettano?\p"
	.string "Che tensione!$"

TrainerTower_Lobby_Text_StairsTougherThanAnyBattle::
	.string "Ansimo, ansimo…\n"
	.string "Ansimo…\p"
	.string "Altro che lottare! Queste scale…\n"
	.string "Sono più dure di qualsiasi lotta…$"

