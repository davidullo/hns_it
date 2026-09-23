DragonsDen_Shrine_hns_MapScripts::
	@map_script MAP_SCRIPT_ON_FRAME_TABLE, DragonsDen_Shrine_OnFrame
	.byte 0

DragonsDen_Shrine_OnFrame::
	map_script_2 VAR_BLACKTHORN_CITY_STATE, 2, DragonsDen_Shrine_Trigger_ElderQuizTop
	.2byte 0

DragonsDen_Shrine_EventScript_Elder::
	lock
	faceplayer
	goto_if_ge VAR_BLACKTHORN_CITY_STATE, 4, DragonsDen_Shrine_EventScript_ElderChooseDratini
	msgbox DragonsDen_Shrine_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

DragonsDen_Shrine_Trigger_ElderQuizLeft::
	lock
	applymovement2 OBJ_EVENT_ID_PLAYER, DragonsDen_Shrine_Movement_PlayerWalkToElderLeft
	applymovement2 OBJ_EVENT_ID_FOLLOWER, DragonsDen_Shrine_Movement_MonWalkToElderLeft
	waitmovement OBJ_EVENT_ID_FOLLOWER
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 10
	lockall
	goto DragonsDen_Shrine_EventScript_ElderOfferQuiz

DragonsDen_Shrine_Trigger_ElderQuizTop::
	lock
	applymovement2 OBJ_EVENT_ID_PLAYER, DragonsDen_Shrine_Movement_PlayerWalkToElderTop
	applymovement2 OBJ_EVENT_ID_FOLLOWER, DragonsDen_Shrine_Movement_PlayerWalkToElderTop
	waitmovement OBJ_EVENT_ID_FOLLOWER
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 10
	lockall
	goto DragonsDen_Shrine_EventScript_ElderOfferQuiz

DragonsDen_Shrine_Trigger_ElderQuizRight::
	lock
	applymovement2 OBJ_EVENT_ID_PLAYER, DragonsDen_Shrine_Movement_PlayerWalkToElderRight
	applymovement2 OBJ_EVENT_ID_FOLLOWER, DragonsDen_Shrine_Movement_MonWalkToElderRight
	waitmovement OBJ_EVENT_ID_FOLLOWER
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 10
	lockall
	goto DragonsDen_Shrine_EventScript_ElderOfferQuiz


DragonsDen_Shrine_Movement_PlayerWalkToElderLeft:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Shrine_Movement_MonWalkToElderLeft:
	walk_left
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Shrine_Movement_PlayerWalkToElderTop:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Shrine_Movement_PlayerWalkToElderRight:
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
DragonsDen_Shrine_Movement_MonWalkToElderRight:
	walk_right
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Shrine_EventScript_ElderOfferQuiz::
	msgbox DragonsDen_Shrine_Text_ElderGreeting, MSGBOX_DEFAULT
	setvar VAR_DRAGONS_DEN_QUIZ, 0
	goto DragonsDen_Shrine_EventScript_ElderQuiz1

DragonsDen_Shrine_EventScript_ElderQuiz1::
	message DragonsDen_Shrine_Text_Question1
	multichoice 20, 6, MULTI_ELDERQUIIZ1, FALSE 
	switch VAR_RESULT
	case 0, DragonsDen_Shrine_EventScript_ElderQuiz1Correct
	case 2, DragonsDen_Shrine_EventScript_ElderQuiz1Correct
	case MULTI_B_PRESSED, DragonsDen_Shrine_EventScript_ElderQuiz1
	call DragonsDen_Shrine_EventScript_ElderWrong
	goto DragonsDen_Shrine_EventScript_ElderQuiz1

DragonsDen_Shrine_EventScript_ElderQuiz1Correct::
	msgbox DragonsDen_Shrine_Text_RightAnswer, MSGBOX_DEFAULT
	goto DragonsDen_Shrine_EventScript_ElderQuiz2

DragonsDen_Shrine_EventScript_ElderQuiz2::
	message DragonsDen_Shrine_Text_Question2
	multichoice 20, 6, MULTI_ELDERQUIIZ2, FALSE 
	switch VAR_RESULT
	case 0, DragonsDen_Shrine_EventScript_ElderQuiz2Correct
	case 1, DragonsDen_Shrine_EventScript_ElderQuiz2Correct
	case MULTI_B_PRESSED, DragonsDen_Shrine_EventScript_ElderQuiz2
	call DragonsDen_Shrine_EventScript_ElderWrong
	goto DragonsDen_Shrine_EventScript_ElderQuiz2

DragonsDen_Shrine_EventScript_ElderQuiz2Correct::
	msgbox DragonsDen_Shrine_Text_RightAnswer, MSGBOX_DEFAULT
	goto DragonsDen_Shrine_EventScript_ElderQuiz3

DragonsDen_Shrine_EventScript_ElderQuiz3::
	message DragonsDen_Shrine_Text_Question3
	multichoice 20, 6, MULTI_ELDERQUIIZ3, FALSE 
	switch VAR_RESULT
	case 1, DragonsDen_Shrine_EventScript_ElderQuiz3Correct
	case 2, DragonsDen_Shrine_EventScript_ElderQuiz3Correct
	case MULTI_B_PRESSED, DragonsDen_Shrine_EventScript_ElderQuiz3
	call DragonsDen_Shrine_EventScript_ElderWrong
	goto DragonsDen_Shrine_EventScript_ElderQuiz3

DragonsDen_Shrine_EventScript_ElderQuiz3Correct::
	msgbox DragonsDen_Shrine_Text_RightAnswer, MSGBOX_DEFAULT
	goto DragonsDen_Shrine_EventScript_ElderQuiz4

DragonsDen_Shrine_EventScript_ElderQuiz4::
	message DragonsDen_Shrine_Text_Question4
	multichoice 20, 6, MULTI_ELDERQUIIZ4, FALSE 
	switch VAR_RESULT
	case 0, DragonsDen_Shrine_EventScript_ElderQuiz4Correct
	case 2, DragonsDen_Shrine_EventScript_ElderQuiz4Correct
	case MULTI_B_PRESSED, DragonsDen_Shrine_EventScript_ElderQuiz4
	call DragonsDen_Shrine_EventScript_ElderWrong
	goto DragonsDen_Shrine_EventScript_ElderQuiz4

DragonsDen_Shrine_EventScript_ElderQuiz4Correct::
	msgbox DragonsDen_Shrine_Text_RightAnswer, MSGBOX_DEFAULT
	goto DragonsDen_Shrine_EventScript_ElderQuiz5

DragonsDen_Shrine_EventScript_ElderQuiz5::
	message DragonsDen_Shrine_Text_Question5
	multichoice 20, 6, MULTI_ELDERQUIIZ5, FALSE 
	switch VAR_RESULT
	case 2, DragonsDen_Shrine_EventScript_ElderQuizFinish
	case MULTI_B_PRESSED, DragonsDen_Shrine_EventScript_ElderQuiz5
	call DragonsDen_Shrine_EventScript_ElderWrong
	goto DragonsDen_Shrine_EventScript_ElderQuiz5

DragonsDen_Shrine_EventScript_ElderWrong::
	msgbox DragonsDen_Shrine_Text_WrongAnswer1, MSGBOX_DEFAULT
	addvar VAR_DRAGONS_DEN_QUIZ, 1
	return

DragonsDen_Shrine_EventScript_ElderQuizFinish::
	msgbox DragonsDen_Shrine_Text_RightAnswer, MSGBOX_DEFAULT
	delay 20
	msgbox DragonsDen_Shrine_Text_PassedTest, MSGBOX_DEFAULT
	closemessage
	goto DragonsDen_Shrine_EventScript_ClairEnter


DragonsDen_Shrine_Text_ElderGreeting:
    .string "Hm… Che bello vederti.\p"
    .string "So già perché sei qui.\n"
    .string "Ti ha mandato SANDRA, vero?\p"
    .string "Che ragazza difficile…\n"
    .string "Mi spiace, ma devo provarti.\p"
    .string "Non temere, dovrai rispondere\n"
    .string "solo a poche domande.\l"
    .string "Vai?$"

DragonsDen_Shrine_Text_Question1:
    .string "Cosa sono i POKéMON?$"

DragonsDen_Shrine_Text_Question2:
    .string "Cosa ti fa vincere le lotte?$"

DragonsDen_Shrine_Text_Question3:
    .string "Che tipo di allenatore vuoi\n"
    .string "sfidare?$"

DragonsDen_Shrine_Text_Question4:
    .string "Cos'è più importante per\n"
    .string "allevare POKéMON?$"

DragonsDen_Shrine_Text_Question5:
    .string "POKéMON forti, POKéMON deboli.\n"
    .string "Qual è più importante?$"

DragonsDen_Shrine_Text_WrongAnswer1:
    .string "Eh? Non ho capito bene…$"

DragonsDen_Shrine_Text_WrongAnswer2:
    .string "Come hai detto?$"

DragonsDen_Shrine_Text_RightAnswer:
    .string "Ah, capisco…$"

DragonsDen_Shrine_Text_PassedTest:
    .string "Hm… Vedo…\p"
    .string "Tieni molto ai POKéMON.\p"
    .string "Molto lodevole.\p"
    .string "È questa convinzione che\n"
    .string "conta!\p"
    .string "{PLAYER}, non perdere la fede.\p"
    .string "Ti sarà d'aiuto alla\n"
    .string "LEGA POKéMON.$"

DragonsDen_Shrine_EventScript_ClairEnter::
	clearflag FLAG_HIDE_DRAGONS_DEN_SHRINE_CLAIR
	addobject LOCALID_DRAGONSDEN3_CLAIR
	playbgm MUS_HG_CLAIR, FALSE
	playse SE_DOOR
	delay 40
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	delay 20
	turnobject OBJ_EVENT_ID_FOLLOWER, DIR_SOUTH
	applymovement2 LOCALID_DRAGONSDEN3_CLAIR, DragonsDen_Shrine_Movement_ClairEnter
	waitmovement 0
	turnobject LOCALID_DRAGONSDEN3_ELDER, DIR_WEST	
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	turnobject OBJ_EVENT_ID_FOLLOWER, DIR_NORTH
	msgbox DragonsDen_Shrine_Text_ClairYouPassed, MSGBOX_DEFAULT
	applymovement2 LOCALID_DRAGONSDEN3_CLAIR, DragonsDen_Shrine_Movement_ClairBackup1
	waitmovement 0
	msgbox DragonsDen_Shrine_Text_ClairThatCantBe, MSGBOX_DEFAULT
	applymovement2 LOCALID_DRAGONSDEN3_CLAIR, DragonsDen_Shrine_Movement_ClairBackup2
	waitmovement 0
	msgbox DragonsDen_Shrine_Text_ClairYoureLying, MSGBOX_DEFAULT
	applymovement2 LOCALID_DRAGONSDEN3_ELDER, DragonsDen_Shrine_Movement_ElderWalkToClair
	waitmovement 0
	turnobject LOCALID_DRAGONSDEN3_CLAIR, DIR_NORTH
	msgbox DragonsDen_Shrine_Text_MustIInformLance, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement2 LOCALID_DRAGONSDEN3_CLAIR, Common_Movement_ExclamationMark
	msgbox DragonsDen_Shrine_Text_IUnderstand, MSGBOX_DEFAULT
	applymovement2 LOCALID_DRAGONSDEN3_CLAIR, DragonsDen_Shrine_Movement_ClairReturnToPlayer
	waitmovement 0
	msgbox DragonsDen_Shrine_Text_HereRisingBadge, MSGBOX_DEFAULT

	message DragonsDen_Shrine_Text_PlayerReceivedRisingBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox DragonsDen_Shrine_Text_RisingBadgeExplanation, MSGBOX_DEFAULT
	setflag FLAG_BADGE08_GET
	addvar VAR_NUM_BADGES, 1

	applymovement2 LOCALID_DRAGONSDEN3_ELDER, DragonsDen_Shrine_Movement_ElderReturnToPlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	turnobject LOCALID_DRAGONSDEN3_CLAIR, DIR_NORTH
	msgbox DragonsDen_Shrine_Text_ElderScoldsClair, MSGBOX_DEFAULT
	closemessage
	delay 20
	msgbox DragonsDen_Shrine_Text_Speechless, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_DRAGONSDEN3_CLAIR, DragonsDen_Shrine_Movement_ClairLeave
	waitmovement 0
	playse SE_EXIT
	fadedefaultbgm
	setflag FLAG_HIDE_DRAGONS_DEN_SHRINE_CLAIR
	removeobject LOCALID_DRAGONSDEN3_CLAIR
	clearflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	setvar VAR_BLACKTHORN_CITY_STATE, 3
	release
	end

DragonsDen_Shrine_Movement_ClairEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end

DragonsDen_Shrine_Movement_ClairBackup1:
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	step_end

DragonsDen_Shrine_Movement_ClairBackup2:
	lock_facing_direction
	walk_slow_left
	unlock_facing_direction
	step_end

DragonsDen_Shrine_Movement_ElderWalkToClair:
	walk_left
	walk_left
	walk_left
	face_down
	step_end

DragonsDen_Shrine_Movement_ClairReturnToPlayer:
	walk_right
	walk_right
	step_end

DragonsDen_Shrine_Movement_ElderReturnToPlayer:
	walk_slow_right
	walk_slow_right
	walk_slow_right
	face_down
	step_end

DragonsDen_Shrine_Movement_ClairLeave:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

DragonsDen_Shrine_Text_ClairYouPassed:
    .string "Com'è andata?\p"
    .string "Immagino sia inutile\n"
	.string "chiedere. Hai fallito?\p"
    .string ".................................\p"
    .string "…Cosa? Hai passato?$"

DragonsDen_Shrine_Text_ClairThatCantBe:
    .string "Impossibile!$"

DragonsDen_Shrine_Text_ClairYoureLying:
    .string "Menti!\p"
    .string "Neppure io l'ho ricevuta!$"

DragonsDen_Shrine_Text_MustIInformLance:
    .string "SANDRA!\p"
    .string "Impeccabile, davvero!\n"
    .string "abilità e spirito!\p"
    .string "Arrenditi e consegna la\n"
    .string "MEDAGLIA LEVANTE!\p"
    .string "…O devo informare LANCE?$"

DragonsDen_Shrine_Text_IUnderstand:
    .string "H-ho capito…$"

DragonsDen_Shrine_Text_HereRisingBadge:
    .string "Ecco, è la MEDAGLIA LEVANTE…\p"
    .string "Presto! Prendila!$"

DragonsDen_Shrine_Text_PlayerReceivedRisingBadge:
    .string "{PLAYER} riceve la MEDAGLIA LEVANTE.$"

DragonsDen_Shrine_Text_RisingBadgeExplanation:
    .string "La MEDAGLIA LEVANTE ti\n"
    .string "permetterà di usare la mossa\l"
    .string "per risalire le cascate.\p"
    .string "Inoltre, tutti i POKéMON ti\n"
    .string "vedranno come allenatore e\l"
    .string "obbediranno a ogni comando.$"

DragonsDen_Shrine_Text_ElderScoldsClair:
    .string "SANDRA…\p"
    .string "Rifletti su ciò che tu\n"
    .string "non hai, e lei sì.$"

DragonsDen_Shrine_Text_Speechless:
    .string "..................................$"

DragonsDen_Shrine_Text_ComeAgain:
    .string "Torna, se lo desideri.$"

DragonsDen_Shrine_Text_SilverIsInTraining:
    .string "Un ragazzo della tua età si\n"
    .string "allena qui.\p"
    .string "Somiglia molto a SANDRA da\n"
    .string "giovane. Mi preoccupa un po'…$"

DragonsDen_Shrine_EventScript_Elder2::
	msgbox DragonsDen_Shrine_Text_Elder2, MSGBOX_NPC
	end

DragonsDen_Shrine_EventScript_Elder3::
	msgbox DragonsDen_Shrine_Text_Elder3, MSGBOX_NPC
	end

DragonsDen_Shrine_Text_Elder2:
    .string "È da parecchio tempo che un\n"
    .string "allenatore ha il raro consenso\l"
    .string "del MASTER.\p"
    .string "Anzi, non dal MASTER LANCE.$"

DragonsDen_Shrine_Text_Elder3:
    .string "Conosci il giovane LANCE?\p"
    .string "Somiglia molto al nostro MASTER\n"
    .string "da giovane.\p"
    .string "Ce l'ha nel sangue.$"

DragonsDen_Shrine_EventScript_ElderChooseDratini::
	goto_if_eq VAR_DRAGONS_DEN_QUIZ, 0, DragonsDen_Shrine_EventScript_ElderGiveSpecialDratini
	goto DragonsDen_Shrine_EventScript_ElderGiveBasicDratini

DragonsDen_Shrine_EventScript_ElderGiveBasicDratini::
	goto_if_set FLAG_GOT_DRATINI, DragonsDen_Shrine_EventScript_ElderAlreadyGotDratini
	msgbox DragonsDen_Shrine_Text_TakeThisDratini, MSGBOX_DEFAULT

	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_DRATINI
	bufferspeciesname STR_VAR_1, SPECIES_DRATINI
	givemon SPECIES_DRATINI, 15
	call Common_EventScript_GiftMon

	msgbox DragonsDen_Shrine_Text_SymbolicDragon, MSGBOX_DEFAULT
	setflag FLAG_GOT_DRATINI
	release
	end

DragonsDen_Shrine_EventScript_ElderGiveSpecialDratini::
	goto_if_set FLAG_GOT_DRATINI, DragonsDen_Shrine_EventScript_ElderAlreadyGotDratini
	msgbox DragonsDen_Shrine_Text_TakeThisDratini, MSGBOX_DEFAULT

	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_DRATINI
	bufferspeciesname STR_VAR_1, SPECIES_DRATINI
	givenamedmon 4
	call Common_EventScript_GiftMonNamed

	msgbox DragonsDen_Shrine_Text_SymbolicDragon, MSGBOX_DEFAULT
	setflag FLAG_GOT_DRATINI
	release
	end

DragonsDen_Shrine_EventScript_ElderAlreadyGotDratini::
	msgbox DragonsDen_Shrine_Text_ClairsGrandfather, MSGBOX_DEFAULT
	release
	end

DragonsDen_Shrine_Text_TakeThisDratini:
    .string "Hm… Lieto di vederti.\p"
    .string "Il tuo arrivo è provvidenziale.\p"
    .string "Ho qualcosa per te.\p"
    .string "Prendi questo DRATINI come\n"
    .string "prova del tuo valore.$"

DragonsDen_Shrine_Text_SymbolicDragon:
    .string "I POKéMON Drago rappresentano il\n"
    .string "clan.\p"
    .string "Hai dimostrato che possiamo\n"
    .string "affidarti un Drago.$"

DragonsDen_Shrine_Text_ClairsGrandfather:
    .string "Sembra che SANDRA abbia imparato\n"
    .string "da te una lezione unica.\p"
    .string "Ti ringrazio come suo nonno.$"
