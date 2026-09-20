BugContest_EventScript_Start::
	end

BugContest_EventScript_WhiteOut::
	lockall
	delay 200
	msgbox BugContest_Text_WhiteOut, MSGBOX_DEFAULT
	closemessage
	goto BugContest_EventScript_End
	end

BugContest_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	msgbox BugContest_Text_TimesUp, MSGBOX_DEFAULT
	closemessage
	waitse
	getpartysize
	goto_if_eq VAR_RESULT, 1, BugContest_EventScript_Didntcatch
	fadescreen FADE_TO_BLACK
	setvar VAR_BUG_CONTEST_STATE, 3

	msgbox BugContest_Text_Judging0, MSGBOX_DEFAULT
	closemessage
	BugContest_EventScript_TimesUp2::
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BugContest_EventScript_WrongChoiceMon
	goto_if_eq VAR_0x8004, 0, BugContest_EventScript_WrongChoiceMon
	fadescreen FADE_TO_BLACK
	warp MAP_NATIONAL_PARK_BUG_CONTEST_HNS, 5
	waitstate
	delay 90
	end

BugContest_EventScript_WrongChoiceMon::
	msgbox BugContest_Text_WrongChoiceMon, MSGBOX_DEFAULT
	goto BugContest_EventScript_TimesUp2
	end

BugContestEventScript_Judging::
	msgbox BugContest_Text_Judging1, MSGBOX_DEFAULT
	closemessage
	special JudgeBugContestMon
	call_if_eq VAR_RESULT, 1, BugContest_EventScript_First
	call_if_eq VAR_RESULT, 2, BugContest_EventScript_Second
	call_if_eq VAR_RESULT, 3, BugContest_EventScript_Third
	special TransferBugContestMon
	delay 20
	giveitem VAR_0x8005
	msgbox BugContest_Text_TransferAndReturn, MSGBOX_DEFAULT
	playse SE_SUCCESS
	waitse
	msgbox BugContest_Text_TakePartInFuture, MSGBOX_DEFAULT
	closemessage
	goto BugContest_EventScript_End
	end

BugContest_EventScript_Didntcatch::
	msgbox BugContest_Text_DidntCatch, MSGBOX_DEFAULT
	playse SE_SUCCESS
	closemessage
	fadescreen FADE_TO_BLACK
	goto BugContest_EventScript_End
	end

BugContest_EventScript_First::
	msgbox BugContest_Text_First1, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_3RD_PLACE
	waitfanfare
	msgbox BugContest_Text_First2, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_2ND_PLACE
	waitfanfare
	msgbox BugContest_Text_First3, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_1ST_PLACE
	waitfanfare
	closemessage
	return

BugContest_EventScript_Second::
	msgbox BugContest_Text_Second1, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_3RD_PLACE
	waitfanfare
	msgbox BugContest_Text_Second2, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_2ND_PLACE
	waitfanfare
	msgbox BugContest_Text_Second3, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_1ST_PLACE
	waitfanfare
	closemessage
	return

BugContest_EventScript_Third::
	msgbox BugContest_Text_Third1, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_3RD_PLACE
	waitfanfare
	msgbox BugContest_Text_Third2, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_2ND_PLACE
	waitfanfare
	msgbox BugContest_Text_Third3, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_1ST_PLACE
	waitfanfare
	closemessage
	return

BugContest_EventScript_End::
	special HealPlayerParty
	special LoadPlayerParty
	special ExitBugContestMode
	clearflag FLAG_DISABLE_EXP_GAIN
	setvar VAR_BUG_CONTEST_STATE, 0
	special RemoveSportBalls
	goto_if_eq VAR_TEMP_1, 1, BugContest_EventScript_SideEnd
	warp MAP_GATE_NATIONAL_PARK_HNS, 7, 2
	waitstate
	releaseall
	end

BugContest_EventScript_SideEnd::
	warp MAP_GATE_NATIONAL_PARK_HNS, 35, 7
	waitstate
	releaseall
	end

BugContest_Text_Judging0::
	.string "La gara è terminata.\n"
	.string "Scegli il POKéMON che vuoi\l"
	.string "tenere e far giudicare.$"

BugContest_Text_Judging1::
	.string "Ora giudicheremo i POKéMON\n"
	.string "che hai catturato.\p"
	.string "...................\n"
	.string "...................\p"
	.string "Abbiamo scelto i vincitori! Siete\n"
	.string "pronti?$"

BugContest_Text_WrongChoiceMon:
	.string "Scegli il POKéMON che vuoi\n"
	.string "tenere e far giudicare.$"

BugContest_Text_DidntCatch:
	.string "Oh no! Non hai catturato POKéMON.\n"
	.string "Hai rinunciato alla gara.\p"
	.string "Ora la tua squadra tornerà.$"

BugContest_Text_TimesUp:
	.string "Din-don! Tempo scaduto!$"

BugContest_Text_WhiteOut:
	.string "{PLAYER} non ha più POKéMON.\n"
	.string "{PLAYER} ha rinunciato alla gara.$"

BugContest_Text_First1:
	.string "Al terzo posto c'è la COOLTRAINER\n"
	.string "BELINDA, che ha preso un\l"
	.string "BUTTERFREE guizzante!$"
BugContest_Text_First2:
	.string "Al secondo posto c'è il PIGLIABUG\n"
	.string "SHAUN, che ha preso un\l"
	.string "PINSIR contorcente!$"
BugContest_Text_First3:
	.string "Il vincitore della Gara Cattura Insetti\n"
	.string "è…\p"
	.string "{PLAYER}, che ha preso un\n"
	.string "{STR_VAR_1} enorme!$"

BugContest_Text_Second1:
	.string "Al terzo posto c'è la COOLTRAINER\n"
	.string "BELINDA, che ha preso un\l"
	.string "BUTTERFREE guizzante!$"
BugContest_Text_Second2:
	.string "Al secondo posto c'è {PLAYER}, che\n"
	.string "ha preso un {STR_VAR_1} contorcente!$"
BugContest_Text_Second3:
	.string "Il vincitore della Gara Cattura Insetti\n"
	.string "è…\p"
	.string "PIGLIABUG SHAUN, che ha preso un\n"
	.string "PINSIR enorme!$"

BugContest_Text_Third1:
	.string "Al terzo posto c'è {PLAYER}, che\n"
	.string "ha preso un {STR_VAR_1} guizzante!$"
BugContest_Text_Third2:
	.string "Al secondo posto c'è la COOLTRAINER\n"
	.string "BELINDA, che ha preso un\l"
	.string "BUTTERFREE contorcente!$"
BugContest_Text_Third3:
	.string "Il vincitore della Gara Cattura Insetti\n"
	.string "è…\p"
	.string "PIGLIABUG SHAUN, che ha preso un\n"
	.string "PINSIR enorme!$"

BugContest_Text_TakePartInFuture:
	.string "Grazie per aver partecipato!\n"
	.string "Speriamo che parteciperai anche\l"
	.string "in futuro.$"

BugContest_Text_TransferAndReturn:
	.string "Il POKéMON INSETTO scelto sarà\n"
	.string "inviato al PC e la tua squadra\l"
	.string "ti sarà restituita.$"
