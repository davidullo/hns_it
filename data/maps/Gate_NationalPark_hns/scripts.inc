Gate_NationalPark_hns_MapScripts::
	.byte 0

Gate_NationalPark_EventScript_Attendant::
	lockall
	faceplayer
	goto_if_set FLAG_DAILY_BUG_CONTEST_COMPLETED, Gate_NationalPark_EventScript_AttendantAlreadyPlayed
	msgbox Route35NationalParkGate_Text_OfficerAskToParticipate, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Gate_NationalPark_EventScript_AttendantStart
	msgbox Route35NationalParkGate_Text_TakePartInFuture, MSGBOX_DEFAULT
	releaseall
	end

Gate_NationalPark_EventScript_AttendantStart::
	playbgm MUS_HG_BUG_CONTEST_PREP, FALSE
	msgbox Route35NationalParkGate_Text_OfficerAskToUseFirstMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Gate_NationalPark_EventScript_AttendantCancel
	getpartysize
	call_if_eq VAR_RESULT, 1, Gate_NationalPark_EventScript_OnlyOneMon
	msgbox Route35NationalParkGate_Text_OfficerHoldYourMon, MSGBOX_DEFAULT
	closemessage
	special SavePlayerParty
	remove5mons
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Gate_NationalPark_EventScript_AttendantFaint
	playfanfare MUS_OBTAIN_ITEM
	message Route35NationalParkGate_Text_MonLeftWithHelper
	waitfanfare
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerGiveSportBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SPORT_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_WEST, Gate_NationalPark_EventScript_AttendantEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantEnterBot
	playse SE_EXIT
	clearflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	special EnterBugContestMode
	setflag FLAG_DISABLE_EXP_GAIN
	setvar VAR_BUG_CONTEST_STATE, 1
	warp MAP_NATIONAL_PARK_BUG_CONTEST_HNS, 1
	waitstate
	end

Gate_NationalPark_EventScript_OnlyOneMon::
	special SavePlayerParty
	msgbox Route35NationalParkGate_Text_OfficerGiveSportBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SPORT_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_WEST, Gate_NationalPark_EventScript_AttendantEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantEnterBot
	playse SE_EXIT
	clearflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	special EnterBugContestMode
	setflag FLAG_DISABLE_EXP_GAIN
	setvar VAR_BUG_CONTEST_STATE, 1
	warp MAP_NATIONAL_PARK_BUG_CONTEST_HNS, 1
	waitstate
	end

Gate_NationalPark_EventScript_AttendantEnterTop::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkTop
	waitmovement 0
	return

Gate_NationalPark_EventScript_AttendantEnterBot::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkBot
	waitmovement 0
	return


Gate_NationalPark_EventScript_AttendantFaint::	
	msgbox Route35NationalParkGate_Text_FirstMonCantBattle, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	release
	end	

Gate_NationalPark_EventScript_AttendantCancel::	
	msgbox Route35NationalParkGate_Text_TakePartInFuture, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	release
	end

Gate_NationalPark_EventScript_AttendantAlreadyPlayed::
	msgbox Route35NationalParkGate_Text_ContestIsOver, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_NationalPark_Movement_Player_EnterParkTop:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

Gate_NationalPark_Movement_Player_EnterParkBot:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

Gate_NationalPark_EventScript_BAttendant::
	lockall
	faceplayer
	goto_if_set FLAG_DAILY_BUG_CONTEST_COMPLETED, Gate_NationalPark_EventScript_AttendantAlreadyPlayed
	msgbox Route35NationalParkGate_Text_OfficerAskToParticipate, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Gate_NationalPark_EventScript_BAttendantStart
	msgbox Route35NationalParkGate_Text_TakePartInFuture, MSGBOX_DEFAULT
	releaseall
	end

Gate_NationalPark_EventScript_BAttendantStart::
	playbgm MUS_HG_BUG_CONTEST_PREP, FALSE
	msgbox Route35NationalParkGate_Text_OfficerAskToUseFirstMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Gate_NationalPark_EventScript_AttendantCancel
	getpartysize
	call_if_eq VAR_RESULT, 1, Gate_NationalPark_EventScript_OnlyOneMonB
	msgbox Route35NationalParkGate_Text_OfficerHoldYourMon, MSGBOX_DEFAULT
	closemessage
	special SavePlayerParty
	remove5mons
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Gate_NationalPark_EventScript_AttendantFaint
	playfanfare MUS_OBTAIN_ITEM
	message Route35NationalParkGate_Text_MonLeftWithHelper
	waitfanfare
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerGiveSportBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SPORT_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, Gate_NationalPark_EventScript_AttendantBEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantBEnterBot
	playse SE_EXIT
	special EnterBugContestMode
	setflag FLAG_DISABLE_EXP_GAIN
	setflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	setvar VAR_BUG_CONTEST_STATE, 5
	warp MAP_NATIONAL_PARK_BUG_CONTEST_HNS, 40, 19
	waitstate
	end

Gate_NationalPark_EventScript_OnlyOneMonB::
	special SavePlayerParty
	msgbox Route35NationalParkGate_Text_OfficerGiveSportBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SPORT_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, Gate_NationalPark_EventScript_AttendantBEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantBEnterBot
	playse SE_EXIT
	special EnterBugContestMode
	setflag FLAG_DISABLE_EXP_GAIN
	setflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	setvar VAR_BUG_CONTEST_STATE, 5
	warp MAP_NATIONAL_PARK_BUG_CONTEST_HNS, 40, 19
	waitstate
	end

Gate_NationalPark_EventScript_AttendantBEnterTop::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkTopB
	waitmovement 0
	return

Gate_NationalPark_EventScript_AttendantBEnterBot::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkBotB
	waitmovement 0
	return

Gate_NationalPark_Movement_Player_EnterParkTopB:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_in_place_left
	step_end

Gate_NationalPark_Movement_Player_EnterParkBotB:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_left
	step_end

Route35NationalParkGate_Text_OfficerAskToParticipate:
	.string "Ciao Allenatore! Oggi c'è il\n"
	.string "Concorso Cattura Coleotteri.\p"
	.string "Le regole son semplici.\p"
	.string "Con un tuo POKéMON cattura un\n"
	.string "coleottero da giudicare.\p"
	.string "Vuoi provare?$"

Route35NationalParkGate_Text_OfficerGiveSportBalls:
	.string "Gli EXP che i POKéMON prendono\n"
	.string "durante il concorso si annullano\l"
	.string "all'uscita.\p"
	.string "Ecco le SPORT BALL per il\n"
	.string "Concorso.$"

Route35NationalParkGate_Text_ReceivedSportBalls:
	.string "{PLAYER} riceve delle SPORT BALL.$"

Route35NationalParkGate_Text_OfficerExplainRules:
	.string "Chi prende il coleottero più forte\n"
	.string "vince.\p"
	.string "Se finisci le SPORT BALL,\n"
	.string "hai finito.\p"
	.string "Puoi prendere fino a 5 POKéMON.\n"
	.string "Tieni solo l'ultimo preso, quello\l"
	.string "che entra nel concorso.\p"
	.string "Va' e prendi il coleottero più\n"
	.string "forte che trovi!$"

Route35NationalParkGate_Text_OfficerAskToUseFirstMon:
	.string "Se hai più di un POKéMON,\n"
	.string "dovrai usare il\l"
	.string "primo della squadra.\p"
	.string "Va bene?$"

Route35NationalParkGate_Text_OfficerHoldYourMon:
	.string "Va bene, teniamo noi gli altri\n"
	.string "tuoi POKéMON mentre gareggi.$"

Route35NationalParkGate_Text_MonLeftWithHelper:
	.string "I POKéMON di {PLAYER} restano con\n"
	.string "l'AIUTANTE DEL CONCORSO.$"

Route35NationalParkGate_Text_ChooseMonAndComeBack:
	.string "Scegli il POKéMON da usare nel\n"
	.string "Concorso, poi torna da me.$"

Route35NationalParkGate_Text_TakePartInFuture:
	.string "OK. Speriamo che partecipi in\n"
	.string "futuro.$"

Route35NationalParkGate_Text_FirstMonCantBattle:
	.string "Oh-oh… Il primo POKéMON della\n"
	.string "squadra non può lottare.\p"
	.string "Scambialo col POKéMON che vuoi\n"
	.string "usare, poi torna da me.$"

Route35NationalParkGate_Text_MakeRoom:
	.string "Oh-oh… Hai piena sia la squadra\n"
	.string "che il BOX PC.\p"
	.string "Non hai posto per il POKéMON\n"
	.string "coleottero che catturi.\p"
	.string "Fai spazio nella squadra o nel\n"
	.string "BOX PC, poi torna da me.$"

Route35NationalParkGate_Text_EggAsFirstMon:
	.string "Oh-oh… Hai un UOVO come primo\n"
	.string "POKéMON della squadra.\p"
	.string "Scambialo col POKéMON che vuoi\n"
	.string "usare, poi torna da me.$"

Route35NationalParkGate_Text_ContestIsOver:
	.string "Il Concorso di oggi è finito.\n"
	.string "Speriamo che partecipi in futuro.$"

Route35NationalParkGate_EventScript_Policeman::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_WeHoldContests, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_BC1::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_YoungsterWonders, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_BC2::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_BC2, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_Rocker::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_Rocker, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_Beauty::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_Beauty, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_Text_Rocker:
	.string "Adoro i POKéMON uccello! Stanotte\n"
	.string "ho trovato un uccello di\l"
	.string "tipo Buio nel parco!$"

Route35NationalParkGate_Text_BC2:
	.string "Ho preso uno SCYTHER enorme!$"

Route35NationalParkGate_Text_Beauty:
	.string "Vince sempre lui, questi concorsi!$"

Route35NationalParkGate_Text_WeHoldContests:
	.string "Facciamo gare regolarmente al\n"
	.string "PARCO. Dovresti provare.$"

Route35NationalParkGate_Text_YoungsterWonders:
	.string "Quando è la prossima Gara\n"
	.string "Pigliabug?$"

Route35NationalParkGate_Text_ContestExplanation:
	.string "Il Concorso Cattura Coleotteri si\n"
	.string "tiene martedì, giovedì e sabato.\p"
	.string "Oltre al premio per aver\n"
	.string "partecipato,\p"
	.string "tieni anche i POKéMON coleottero\n"
	.string "che hai alla fine del concorso.$"
