GoldenrodCity_RadioTower_1F_hns_MapScripts::
	.byte 0

RadioTower1F_EventScript_Grunt::
	lock
	faceplayer
	msgbox RadioTower1F_Text_GruntM3Seen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_2_HNS,  RadioTower1F_Text_GruntM3Beaten
	msgbox RadioTower1F_Text_GruntM3After, MSGBOX_AUTOCLOSE
	turnobject LOCALID_GOLDENROD_RADIOTOWER_GRUNT, DIR_EAST
	applymovement2 LOCALID_GOLDENROD_RADIOTOWER_GRUNT, RadioTower1F_Movement_Rocket
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_GOLDENROD_RADIOTOWER_GRUNT
	setflag FLAG_HIDE_ROCKET_GOLDENROD_RADIOTOWER_1
	release
	end

RadioTower1F_Movement_Rocket::
	walk_in_place_right
	step_end

RadioTower1F_EventScript_Lass::
	lock
	faceplayer
	msgbox RadioTower1F_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_Youngster::
	lock
	faceplayer
	msgbox RadioTower1F_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_Whitney::
	lock
	faceplayer
	msgbox RadioTower1F_Text_Whitney1, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, DIR_SOUTH
	release
	end

RadioTower1F_Text_Whitney1::
	.string "WHITNEY: Ciao!\p"
	.string "Mi chiamo WHITNEY!\p"
	.string "Ho saputo del QUIZ per la\n"
	.string "RADIO CARD, così sono venuta a\l"
	.string "prenderne una...\p"
	.string "Ma è difficilissimo!$"

RadioTower1F_Text_Whitney2::
	.string "WHITNEY: Wow, ce l'hai fatta!\p"
	.string "Credevo che la risposta alla terza\n"
	.string "fosse di certo le ghicocche!\l"
	.string "Ops!\p"
	.string "È ora di tornare in PALESTRA!$"

RadioTower1F_EventScript_Reception::
	lock
	faceplayer
	msgbox RadioTower1F_Text_ReceptionistWelcome, MSGBOX_DEFAULT
	goto_if_unset FLAG_ENABLE_RADIO, RadioTower1F_EventScript_ReceptionOfferQuiz
	msgbox RadioTower1F_Text_ReceptionistNoTours, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionOfferQuiz::
	msgbox RadioTower1F_Text_RadioCardWomanOfferQuiz, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz1
	msgbox RadioTower1F_Text_DeclineQuiz, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz1::
	msgbox RadioTower1F_Text_QuizQuestion1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz2
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz2::
	msgbox RadioTower1F_Text_QuizQuestion2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz3
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz3::
	msgbox RadioTower1F_Text_QuizQuestion3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, RadioTower1F_EventScript_ReceptionQuiz4
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz4::
	msgbox RadioTower1F_Text_QuizQuestion4, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz5
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz5::
	msgbox RadioTower1F_Text_QuizQuestion5, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, RadioTower1F_EventScript_ReceptionGiveRadio
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionGiveRadio::
	msgbox RadioTower1F_Text_QuizWin, MSGBOX_DEFAULT
	closemessage
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	msgbox RadioTower1F_Text_PokegearRadio, MSGBOX_AUTOCLOSE
	waitfanfare
	msgbox RadioTower1F_Text_TuneIn, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GOLDENROD_RADIOTOWER_WHITNEY
	turnobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, DIR_EAST
	delay 20
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox RadioTower1F_Text_Whitney2, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, GoldenrodCity_RadioTower_4F_Movement_WhitneyLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY
	setflag FLAG_ENABLE_RADIO
	setflag FLAG_HIDE_GOLDENROD_BEAUTY
	setvar VAR_GOLDENROD_CITY_STATE, 2
	release
	end

GoldenrodCity_RadioTower_4F_Movement_WhitneyLeave:
	face_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_down
	step_end

GoldenrodCity_RadioTower_1F_EventScript_Sign::
	lock
	msgbox RadioTower1F_Text_Directory, MSGBOX_SIGN
	closemessage
	release
	end

RadioTower1F_Text_ReceptionistWelcome:
    .string "Benvenuto!$"

RadioTower1F_Text_ReceptionistNoTours:
    .string "Salve. Mi spiace, ma oggi non\n"
    .string "facciamo visite.$"

RadioTower1F_Text_RadioCardWomanOfferQuiz:
    .string "Abbiamo una campagna QUIZ\n"
    .string "speciale in corso.\p"
    .string "Rispondi bene a cinque domande e\n"
    .string "vinci una RADIO CARD POKéGEAR.\p"
    .string "Tu e i tuoi POKéMON potrete\n"
    .string "ascoltare musica sempre.\p"
    .string "Vuoi fare il QUIZ?$"

RadioTower1F_Text_QuizQuestion1:
    .string "Domanda 1:\p"
    .string "Esiste un POKéMON che appare solo\n"
    .string "di giorno?$"

RadioTower1F_Text_QuizQuestion2:
    .string "Giusto!\n"
    .string "Domanda 2:\p"
    .string "È vera questa frase?\p"
    .string "Non puoi comprare una BACCA al MART.$"

RadioTower1F_Text_QuizQuestion3:
    .string "Centro pieno!\n"
    .string "Domanda 3:\p"
    .string "KURT, creatore delle POKéBALL, usa\n"
	.string "le ghicocche come ingredienti?$"

RadioTower1F_Text_QuizQuestion4:
    .string "Fin qui tutto bene!\n"
    .string "Domanda 4:\p"
    .string "FALKNER è il CAPOPALESTRA di\n"
    .string "VIOLETTO che usa POKéMON uccello?$"

RadioTower1F_Text_QuizQuestion5:
    .string "Wow! Ancora giusto!\n"
    .string "Ecco l'ultima domanda:\p"
    .string "Le slot della SALA GIOCHI di\n"
    .string "GOLDENROD hanno CHARMANDER?$"

RadioTower1F_Text_QuizWin:
    .string "Bingo! Hai indovinato!\n"
    .string "Congratulazioni!\p"
    .string "Ecco il premio: una RADIO CARD!$"

RadioTower1F_Text_PokegearRadio:
    .string "Il POKéGEAR di {PLAYER} ora fa anche\n"
    .string "da RADIO!$"

RadioTower1F_Text_TuneIn:
    .string "Sintonizzati sui nostri programmi RADIO.$"

RadioTower1F_Text_WrongAnswer:
    .string "Oh, no.\n"
    .string "Mi spiace, hai sbagliato.\p"
    .string "Riprova!$"

RadioTower1F_Text_DeclineQuiz:
    .string "Oh. Capisco. Cercami se\n"
    .string "cambi idea.$"

RadioTower1F_Text_Lass:
    .string "BEN è un DJ fantastico.\p"
    .string "La sua voce mi fa sciogliere!$"

RadioTower1F_Text_Youngster:
    .string "Adoro MARY di POKéMON TALK.\p"
    .string "Però conosco solo la sua\n"
    .string "voce.$"

RadioTower1F_Text_GruntM3Seen:
    .string "Abbiamo preso la\n"
    .string "TORRE RADIO!\p"
    .string "Ora tutti proveranno\n"
    .string "il vero terrore del TEAM ROCKET!\p"
    .string "Ti faremo vedere quanto siamo feroci!$"

RadioTower1F_Text_GruntM3Beaten:
    .string "Troppo forte! Scusa, capo…$"

RadioTower1F_Text_GruntM3After:
    .string "Sei troppo forte.\p"
    .string "Il piano è a rischio. Devo\n"
    .string "avvisare gli altri…$"

RadioTower1F_Text_Directory:
    .string "1P RECEPTION\n"
    .string "2P VENDITE\p"
    .string "3P PERSONALE\n"
    .string "4P PRODUZIONE\p"
    .string "5P UFFICIO DIREZIONE$"

RadioTower1F_Text_GotRadio:
	.string "{PLAYER} ottiene la RADIO CARD\n"
	.string "per il POKéGEAR!$"

GoldenrodCity_RadioTower_1F_EventScript_LotteryClerk::
	lock
	faceplayer
	dotimebasedevents
	goto_if_ne VAR_POKELOT_PRIZE_ITEM, ITEM_NONE, GoldenrodCity_RadioTower_1F_EventScript_GivePrizeFromEarlier
	goto_if_set FLAG_DAILY_PICKED_LOTO_TICKET, GoldenrodCity_RadioTower_1F_EventScript_ComeBackTomorrow
	msgbox GoldenrodCity_RadioTower_1F_Text_LotteryCornerDrawTicket, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain
	setflag FLAG_DAILY_PICKED_LOTO_TICKET
	message GoldenrodCity_RadioTower_1F_Text_PleasePickTicket
	waitmessage
	special RetrieveLotteryNumber
	copyvar VAR_0x8008, VAR_RESULT
	special BufferLottoTicketNumber
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketNumberIsXPleaseWait, MSGBOX_DEFAULT
	applymovement 4, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	playse SE_PC_ON
	special PickLotteryCornerTicket
	applymovement 4, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_0x8004, 0, GoldenrodCity_RadioTower_1F_EventScript_NoMatch
	incrementgamestat GAME_STAT_WON_POKEMON_LOTTERY
	call_if_eq VAR_0x8006, 0, GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPartyMon
	call_if_eq VAR_0x8006, 1, GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPCMon
	bufferitemname STR_VAR_1, VAR_0x8005
	call_if_eq VAR_0x8004, 1, GoldenrodCity_RadioTower_1F_EventScript_TwoDigitMatch
	call_if_eq VAR_0x8004, 2, GoldenrodCity_RadioTower_1F_EventScript_ThreeDigitMatch
	call_if_eq VAR_0x8004, 3, GoldenrodCity_RadioTower_1F_EventScript_FourDigitMatch
	call_if_eq VAR_0x8004, 4, GoldenrodCity_RadioTower_1F_EventScript_FullMatch
	giveitem VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_RadioTower_1F_EventScript_RecordPrizeNoRoom
	special TryPutLotteryWinnerReportOnAir
	goto GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2
	end

GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPartyMon::
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketMatchesPartyMon, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPCMon::
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketMatchesPCMon, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_ComeBackTomorrow::
	msgbox GoldenrodCity_RadioTower_1F_Text_ComeBackTomorrow, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain::
	msgbox GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_NoMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_NoNumbersMatched, MSGBOX_DEFAULT
	goto GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2
	end

GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2::
	msgbox GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain2, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_TwoDigitMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_TwoDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_ThreeDigitMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_ThreeDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_FourDigitMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_FourDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_FullMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_AllFiveDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_RecordPrizeNoRoom::
	copyvar VAR_POKELOT_PRIZE_PLACE, VAR_0x8004
	copyvar VAR_POKELOT_PRIZE_ITEM, VAR_0x8005
	goto GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize
	end

GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize::
	msgbox GoldenrodCity_RadioTower_1F_Text_NoRoomForThis, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_GivePrizeFromEarlier::
	msgbox GoldenrodCity_RadioTower_1F_Text_PrizeWeveBeenHolding, MSGBOX_DEFAULT
	giveitem VAR_POKELOT_PRIZE_ITEM
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize
	copyvar VAR_0x8004, VAR_POKELOT_PRIZE_PLACE
	copyvar VAR_0x8005, VAR_POKELOT_PRIZE_ITEM
	special TryPutLotteryWinnerReportOnAir
	setvar VAR_POKELOT_PRIZE_ITEM, ITEM_NONE
	setvar VAR_POKELOT_PRIZE_PLACE, 0
	release
	end

GoldenrodCity_RadioTower_1F_Text_LotteryCornerDrawTicket:
	.string "Questa è la LOTTERIA POKéMON.\p"
	.string "Se il numero del LOTO TICKET coincide\n"
	.string "con l'ID di un tuo POKéMON,\l"
	.string "riceverai un regalo favoloso.\p"
	.string "Vuoi estrarre un POKéMON\n"
	.string "LOTO TICKET?$"

GoldenrodCity_RadioTower_1F_Text_ComeBackTomorrow:
	.string "Torna domani.$"

GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain:
	.string "Torna a trovarci.$"

GoldenrodCity_RadioTower_1F_Text_PleasePickTicket:
	.string "Scegli un BIGLIETTO LOTO.\n"
	.string "…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}$"

GoldenrodCity_RadioTower_1F_Text_TicketNumberIsXPleaseWait:
	.string "Il numero del BIGLIETTO LOTO è {STR_VAR_1}.\p"
	.string "Devo controllare questo numero\n"
	.string "per vedere se corrisponde a un\l"
	.string "ID dei tuoi POKéMON. Attendi.$"

GoldenrodCity_RadioTower_1F_Text_TicketMatchesPartyMon:
	.string "Congratulazioni!\p"
	.string "Il numero ID del tuo\n"
	.string "{STR_VAR_1} in squadra corrisponde\l"
	.string "al numero del BIGLIETTO LOTTO!$"

GoldenrodCity_RadioTower_1F_Text_TicketMatchesPCMon:
	.string "Congratulazioni!\p"
	.string "Il numero ID del tuo\n"
	.string "{STR_VAR_1} nel PC corrisponde\l"
	.string "al numero del tuo BIGLIETTO LOTTO!$"

GoldenrodCity_RadioTower_1F_Text_NoNumbersMatched:
	.string "Mi dispiace.\n"
	.string "Nessun numero corrisponde.$"

GoldenrodCity_RadioTower_1F_Text_TwoDigitsMatched:
	.string "Due cifre uguali: vinci il\n"
	.string "terzo premio!\l"
	.string "Hai vinto {STR_VAR_1}!$"

GoldenrodCity_RadioTower_1F_Text_ThreeDigitsMatched:
	.string "Tre cifre uguali: vinci il\n"
	.string "secondo premio!\l"
	.string "Hai vinto {STR_VAR_1}!$"

GoldenrodCity_RadioTower_1F_Text_FourDigitsMatched:
	.string "Quattro cifre azzeccate, vinci il\n"
	.string "secondo premio!\l"
	.string "Hai vinto {STR_VAR_1}!$"

GoldenrodCity_RadioTower_1F_Text_AllFiveDigitsMatched:
	.string "Oh, santo cielo, cinque cifre\n"
	.string "azzeccate!\p"
	.string "Hai vinto il primo premio!\n"
	.string "Hai vinto {STR_VAR_1}!$"

GoldenrodCity_RadioTower_1F_Text_NoRoomForThis:
	.string "Oh?\n"
	.string "Sembra che tu non abbia spazio.\p"
	.string "Fai spazio nella BORSA e\n"
	.string "avvisami.$"

GoldenrodCity_RadioTower_1F_Text_PrizeWeveBeenHolding:
	.string "{PLAYER}?\n"
	.string "Sì, ti aspettavo.\p"
	.string "Questo è il premio che ti abbiamo\n"
	.string "serbato.$"

GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain2:
	.string "Torna a trovarci.$"


