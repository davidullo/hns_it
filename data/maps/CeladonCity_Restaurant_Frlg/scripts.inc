CeladonCity_Restaurant_Frlg_MapScripts::
	.byte 0

CeladonCity_Restaurant_EventScript_Chef::
	msgbox CeladonCity_Restaurant_Text_TakingBreakRightNow, MSGBOX_NPC
	end

CeladonCity_Restaurant_EventScript_Woman::
	msgbox CeladonCity_Restaurant_Text_OftenGoToDrugstore, MSGBOX_NPC
	end

CeladonCity_Restaurant_EventScript_CoinCaseMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_COIN_CASE, CeladonCity_Restaurant_EventScript_AlreadyGotCoinCase
	msgbox CeladonCity_Restaurant_Text_TakeThisImBusted
	checkitemspace ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_Restaurant_EventScript_NoRoomForCoinCase
	giveitem_msg CeladonCity_Restaurant_Text_ReceivedCoinCaseFromMan, ITEM_COIN_CASE
	setflag FLAG_GOT_COIN_CASE
	release
	end

CeladonCity_Restaurant_EventScript_NoRoomForCoinCase::
	msgbox CeladonCity_Restaurant_Text_MakeRoomForThis
	release
	end

CeladonCity_Restaurant_EventScript_AlreadyGotCoinCase::
	msgbox CeladonCity_Restaurant_Text_ThoughtIdWinItBack
	release
	end

CeladonCity_Restaurant_EventScript_WorkerM::
	msgbox CeladonCity_Restaurant_Text_PsstBasementUnderGameCorner, MSGBOX_NPC
	end

CeladonCity_Restaurant_EventScript_FatMan::
	msgbox CeladonCity_Restaurant_Text_ManLostItAllAtSlots, MSGBOX_NPC
	end

CeladonCity_Restaurant_Text_TakingBreakRightNow::
	.string "Ciao!\p"
	.string "Scusa, ma siamo in pausa\n"
	.string "adesso.$"

CeladonCity_Restaurant_Text_OftenGoToDrugstore::
	.string "I miei POKéMON sono deboli,\n"
	.string "perciò vado in FARMACIA.$"

CeladonCity_Restaurant_Text_PsstBasementUnderGameCorner::
	.string "Psst! Sotto la SALA GIOCHI c'è\n"
	.string "un sotterraneo, dicono.$"

CeladonCity_Restaurant_Text_ManLostItAllAtSlots::
	.string "Gnam…\p"
	.string "Quel tipo al tavolo ha perso\n"
	.string "tutto alle slot.$"

CeladonCity_Restaurant_Text_TakeThisImBusted::
	.string "Go ahead! Laugh!\n"
	.string "I'm flat-out busted!\p"
	.string "No more slots for me!\n"
	.string "I'm going straight!\p"
	.string "Here!\n"
	.string "I won't be needing this anymore!$"

CeladonCity_Restaurant_Text_ReceivedCoinCaseFromMan::
	.string "{PLAYER} ha ricevuto il\n"
	.string "PORTAGETTONI dal signore.$"

CeladonCity_Restaurant_Text_MakeRoomForThis::
	.string "Fate largo a questo!$"

CeladonCity_Restaurant_Text_ThoughtIdWinItBack::
	.string "Ho sempre pensato che avrei\n"
	.string "rivinto…$"

