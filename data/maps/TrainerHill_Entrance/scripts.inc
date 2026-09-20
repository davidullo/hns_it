TrainerHill_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_Entrance_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerHill_Entrance_OnReturn
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Entrance_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Entrance_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Entrance_OnFrame
	.byte 0

TrainerHill_Entrance_OnTransition:
	setflag FLAG_LANDMARK_TRAINER_HILL
	getplayerxy VAR_TEMP_D, VAR_RESULT
	end

@ Unused
TrainerHill_Entrance_OnWarp:
	end

TrainerHill_Entrance_OnResume:
	trainerhill_resumetimer
	setvar VAR_TEMP_0, 0
	trainerhill_getusingereader
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_TryFaceAttendant  @ VAR_RESULT always FALSE here
	setobjectxy LOCALID_PLAYER, 9, 6
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_TryFaceAttendant::
	trainerhill_getwon
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant::
	end

TrainerHill_Entrance_OnReturn:
	addobject LOCALID_TRAINER_HILL_NURSE
	addobject LOCALID_TRAINER_HILL_ATTENDANT
	addobject LOCALID_TRAINER_HILL_MAN
	addobject LOCALID_TRAINER_HILL_GIRL
	end

TrainerHill_Entrance_OnLoad:
	call_if_eq VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_OpenCounterDoor
	end

TrainerHill_Entrance_EventScript_OpenCounterDoor::
	setmetatile 17, 10, METATILE_TrainerHill_GreenFloorTile, FALSE
	return

TrainerHill_Entrance_OnFrame:
	map_script_2 VAR_TEMP_0, 0, TrainerHill_Entrance_EventScript_ExitChallenge
	map_script_2 VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_ExitElevator
	map_script_2 VAR_TEMP_5, 1, TrainerHill_Entrance_EventScript_EntryTrigger
	map_script_2 VAR_TEMP_1, 1, TrainerHill_EventScript_WarpToEntranceCounter
	.2byte 0

TrainerHill_Entrance_EventScript_ExitElevator::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerExitElevator
	waitmovement 0
	setmetatile 17, 10, METATILE_TrainerHill_CounterDoor, TRUE
	special DrawWholeMapView
	playse SE_CLICK
	waitse
	setvar VAR_TEMP_D, 0
	releaseall
	end

TrainerHill_Entrance_EventScript_ExitChallenge::
	setvar VAR_TEMP_0, 1
	trainerhill_getstatus
	switch VAR_RESULT
	case TRAINER_HILL_PLAYER_STATUS_LOST, TrainerHill_Entrance_EventScript_ExitChallengeLost
	case TRAINER_HILL_PLAYER_STATUS_ECARD_SCANNED, TrainerHill_Entrance_EventScript_ExitChallengeECard
	case TRAINER_HILL_PLAYER_STATUS_NORMAL, TrainerHill_Entrance_EventScript_EndExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeLost::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_TooBadTremendousEffort, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_PlayerExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeECard::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_MovedReceptionHereForSwitch, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_PlayerExitChallenge::
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	releaseall
TrainerHill_Entrance_EventScript_EndExitChallenge::
	end

TrainerHill_Entrance_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_TRAINER_HILL_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

TrainerHill_Entrance_EventScript_Attendant::
	lock
	faceplayer
	trainerhill_inchallenge
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_ThanksForPlaying
	msgbox TrainerHill_Entrance_Text_HopeYouGiveItYourBest, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AttendantEnd

TrainerHill_Entrance_EventScript_ThanksForPlaying::
	msgbox TrainerHill_Entrance_Text_ThankYouForPlaying, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AttendantEnd::
	release
	end

TrainerHill_Entrance_EventScript_EntryTrigger::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_Closed
	msgbox TrainerHill_Entrance_Text_WelcomeToTrainerHill, MSGBOX_DEFAULT
	trainerhill_getsaved
	call_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveGame
	trainerhill_allfloorsused
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_AllFloorsUsed
	msgbox TrainerHill_Entrance_Text_TrainersUpToFloorX, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers

TrainerHill_Entrance_EventScript_AllFloorsUsed::
	msgbox TrainerHill_Entrance_Text_TrainersInEveryRoom, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AskChallengeTrainers::
	message TrainerHill_Entrance_Text_LikeToChallengeTrainers
	waitmessage
	multichoice 15, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, TrainerHill_Entrance_EventScript_ChooseChallenge
	case 1, TrainerHill_Entrance_EventScript_CancelEntry
	case 2, TrainerHill_Entrance_EventScript_Info
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Info::
	msgbox TrainerHill_Entrance_Text_ExplainTrainerHill, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers
	end

TrainerHill_Entrance_EventScript_ChooseChallenge::
	multichoice 13, 2, MULTI_TAG_MATCH_TYPE, FALSE
	switch VAR_RESULT
	case 4, TrainerHill_Entrance_EventScript_CancelEntry
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	trainerhill_setmode VAR_RESULT
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 1
	setvar VAR_TEMP_5, 0
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	msgbox TrainerHill_Entrance_Text_TimeProgessGetSetGo, MSGBOX_DEFAULT
	trainerhill_start
	releaseall
	end

TrainerHill_Entrance_EventScript_CancelEntry::
	setvar VAR_TEMP_5, 0
	msgbox TrainerHill_Entrance_Text_PleaseVisitUsAgain, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_EventScript_SaveGame::
	msgbox TrainerHill_Entrance_Text_SaveGameBeforeEnter, MSGBOX_DEFAULT
	trainerhill_setsaved
	setvar VAR_TEMP_5, 1
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveFailed
	trainerhill_setsaved
	return

TrainerHill_Entrance_EventScript_SaveFailed::
	trainerhill_clearsaved
	goto TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Closed::
	msgbox TrainerHill_Entrance_Text_StillGettingReady, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_Movement_PlayerFaceAttendant:
	face_right
	step_end

TrainerHill_Entrance_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

@ Unused
TrainerHill_Entrance_Movement_FaceUp:
	face_up
	step_end

TrainerHill_Entrance_Movement_PlayerExitElevator:
	walk_down
	walk_down
	step_end

TrainerHill_Entrance_EventScript_Records::
	lockall
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, 0
	special ShowTrainerHillRecords
	waitstate
	releaseall
	end

TrainerHill_Entrance_EventScript_Man::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ManTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_ManTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_CantWaitToTestTheWaters, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Girl::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_GirlTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_GirlTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ExpandedPokemart
	pokemart TrainerHill_Entrance_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Basic:
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

TrainerHill_Entrance_EventScript_ExpandedPokemart::
	pokemart TrainerHill_Entrance_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Expanded:
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

TrainerHill_Entrance_Text_StillGettingReady:
	.string "Questa è la COLLINA ALLENATORI dove\n"
	.string "puoi fare lotte in coppia con molti\l"
	.string "ALLENATORI.\p"
	.string "Purtroppo stiamo ancora preparando\n"
	.string "tutto. Torna più tardi!$"

TrainerHill_Entrance_Text_WelcomeToTrainerHill:
	.string "Benvenuto!\p"
	.string "Questa è la COLLINA ALLENATORI dove\n"
	.string "puoi fare lotte in coppia con molti\l"
	.string "ALLENATORI!$"

TrainerHill_Entrance_Text_SaveGameBeforeEnter:
	.string "È la tua prima visita qui?\p"
	.string "Prima di entrare, salva\n"
	.string "la partita.$"

TrainerHill_Entrance_Text_TrainersUpToFloorX:
	.string "Vediamo…\n"
	.string "Gli ALLENATORI presenti sono…\p"
	.string "Fino al piano n. {STR_VAR_1}.$"

TrainerHill_Entrance_Text_TrainersInEveryRoom:
	.string "Vediamo…\n"
	.string "Gli ALLENATORI presenti sono…\p"
	.string "Sembra che ci siano ALLENATORI\n"
	.string "in ogni stanza.$"

TrainerHill_Entrance_Text_LikeToChallengeTrainers:
	.string "Would you like to challenge the\n"
	.string "waiting TRAINERS?$"

TrainerHill_Entrance_Text_TimeProgessGetSetGo:
	.string "Cronometrerò il tuo tempo.\n"
	.string "In bocca al lupo!\p"
	.string "Ai vostri posti…\p"
	.string "Pronti…\p"
	.string "Via!$"

TrainerHill_Entrance_Text_PleaseVisitUsAgain:
	.string "Torna a trovarci presto!$"

TrainerHill_Entrance_Text_TooBadTremendousEffort:
	.string "Che peccato.\p"
	.string "Penso che tu abbia fatto uno sforzo\n"
	.string "enorme nelle tue lotte.\p"
	.string "Torna a riprovare!$"

TrainerHill_Entrance_Text_HopeYouGiveItYourBest:
	.string "Spero che darai il massimo.$"

TrainerHill_Entrance_Text_MovedReceptionHereForSwitch:
	.string "Quando gli ALLENATORI si scambiano\n"
	.string "di posto, c'è molta ressa.\p"
	.string "Per evitare la calca, abbiamo spostato\n"
	.string "qui il bancone della reception.\p"
	.string "Ci scusiamo per il disagio.$"

TrainerHill_Entrance_Text_ThankYouForPlaying:
	.string "Grazie per aver giocato!$"

TrainerHill_Entrance_Text_ExplainTrainerHill:
	.string "Qui al TRAINER HILL organizziamo\n"
	.string "un evento chiamato Time Attack.\p"
	.string "È una corsa che misura quanto tempo\n"
	.string "impieghi per raggiungere il nostro\l"
	.string "titolare sul tetto da questo bancone.\p"
	.string "I tempi più veloci sono esposti sulla\n"
	.string "Bacheca dei Tempi: provate a gareggiare\l"
	.string "con i vostri amici.\p"
	.string "Nelle lotte ALLENATORE lungo il percorso\n"
	.string "non si ottengono né Punti Esperienza\l"
	.string "né soldi.$"

@ Unused
TrainerHill_Entrance_Text_NeedAtLeastTwoPokemon:
	.string "Oh, mi spiace, ma sembra che tu abbia\n"
	.string "un solo POKéMON con te.\p"
	.string "Ti servono almeno due POKéMON\n"
	.string "per partecipare a questo evento.$"

TrainerHill_Roof_Text_YouFinallyCameBravo:
	.string "Hm! Hm!\p"
	.string "Finalmente sei arrivato!\n"
	.string "Sì, sei giunto!\p"
	.string "Aspetta! Non dirlo!\n"
	.string "So perché sei venuto fin qui\l"
	.string "da solo!\p"
	.string "Volevi vedere me, il titolare\n"
	.string "del TRAINER HILL, perché…\p"
	.string "Vuoi formare una coppia con me!\n"
	.string "Wa-hoo!\p"
	.string "…Eh?\n"
	.string "Non è così?\p"
	.string "Comunque, ti ho guardato salire.\n"
	.string "Che lotte meravigliose! Bravo, davvero!$"

TrainerHill_Roof_Text_HaveTheMostMarvelousGift:
	.string "Per una persona meravigliosa come te,\n"
	.string "ho il regalo più meraviglioso!$"

TrainerHill_Roof_Text_FullUpBeBackLaterForThis:
	.string "Oh, no, ho le tasche piene!\n"
	.string "Tornerai più tardi per questo!$"

TrainerHill_Roof_Text_GotHereMarvelouslyQuickly:
	.string "Oh, un momento! Saresti forse arrivato\n"
	.string "qui in tempo meraviglioso?\p"
	.string "Che splendore! Non dovevi\n"
	.string "correre tanto per vedermi!\p"
	.string "Che delizia. Farò aggiornare la Bacheca\n"
	.string "dei Tempi alla reception!$"

TrainerHill_Roof_Text_YouWerentVeryQuick:
	.string "Ma, oh…\n"
	.string "Non sei stato molto rapido ad arrivare.$"

TrainerHill_Roof_Text_ArriveZippierNextTime:
	.string "Forse sarei più contento se arrivassi\n"
	.string "più svelto la prossima volta.\p"
	.string "Allora sì che sarei felice di formare\n"
	.string "una coppia con te!\p"
	.string "Alla prossima, amico!$"

@ Unused
TrainerHill_Roof_Text_BuiltTrainerHillToFindPartner:
	.string "Ho fatto costruire il TRAINER HILL per\n"
	.string "una sola, unica ragione!\p"
	.string "Trovare il partner più adatto\n"
	.string "con cui formare una coppia!$"

TrainerHill_Entrance_Text_ChallengeTime:
	.string "{STR_VAR_1} min. {STR_VAR_2}.{STR_VAR_3} sec.$"

TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead:
	.string "Chissà quali ALLENATORI\n"
	.string "e combinazioni di POKéMON ci aspettano?\p"
	.string "So solo che spazzerò via\n"
	.string "chiunque mi stia sulla strada!$"

TrainerHill_Entrance_Text_CantWaitToTestTheWaters:
	.string "Ho sentito che ALLENATORI forti arrivano\n"
	.string "qui al TRAINER HILL da ogni dove.\p"
	.string "Non vedo l'ora di misurarmi!\p"
	.string "Spazzerò via chiunque mi stia\n"
	.string "sulla strada!$"

TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop:
	.string "Vedi il Tabellone Tempi laggiù?\p"
	.string "Io e i miei amici vediamo chi\n"
	.string "arriva in cima nel minor tempo.$"

TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen:
	.string "Sai quando apriranno\n"
	.string "questo posto?\p"
	.string "Aspetto qui per essere il primo\n"
	.string "sfidante di sempre!$"

TrainerHill_Elevator_Text_ReturnToReception:
	.string "Would you like to return to\n"
	.string "the reception counter?$"
