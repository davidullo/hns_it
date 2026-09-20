SootopolisCity_House6_MapScripts::
	.byte 0

SootopolisCity_House6_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_WAILMER_DOLL, SootopolisCity_House6_EventScript_ReceivedWailmerDoll
	msgbox SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, SootopolisCity_House6_EventScript_DeclineWailmerDoll
	msgbox SootopolisCity_House6_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	givedecoration DECOR_WAILMER_DOLL
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_House6_EventScript_NoRoomForWailmerDoll
	setflag FLAG_RECEIVED_WAILMER_DOLL
	release
	end

SootopolisCity_House6_EventScript_DeclineWailmerDoll::
	msgbox SootopolisCity_House6_Text_DontWantThisDoll, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_ReceivedWailmerDoll::
	msgbox SootopolisCity_House6_Text_LovePlushDolls, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_NoRoomForWailmerDoll::
	bufferdecorationname STR_VAR_2, DECOR_WAILMER_DOLL
	msgbox gText_NoRoomLeftForAnother, MSGBOX_DEFAULT
	msgbox SootopolisCity_House6_Text_IllHoldItForYou, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll:
	.string "Ciao! Sei il primo ospite da\n"
	.string "un bel po'.\p"
	.string "Mi hai rallegrato la giornata, quindi ti\n"
	.string "do un grande PELUCHE WAILMER.$"

SootopolisCity_House6_Text_TakeGoodCareOfIt:
	.string "Prenditene cura!$"

SootopolisCity_House6_Text_IllHoldItForYou:
	.string "Oh, lo vuoi, ma non ora?\n"
	.string "Ok, allora te lo tengo da parte.$"

SootopolisCity_House6_Text_DontWantThisDoll:
	.string "Sei sicuro?\n"
	.string "Non vuoi questo PELUCHE?$"

SootopolisCity_House6_Text_LovePlushDolls:
	.string "Adoro i PELUCHE!$"

