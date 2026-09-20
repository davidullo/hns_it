FuchsiaCity_WardensHouse_Frlg_MapScripts::
	.byte 0

FuchsiaCity_WardensHouse_EventScript_Warden::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HM04, FuchsiaCity_WardensHouse_EventScript_ExplainStrength
	goto_if_set FLAG_HIDE_SAFARI_ZONE_WEST_GOLD_TEETH, FuchsiaCity_WardensHouse_EventScript_GiveGoldTeeth
	msgbox FuchsiaCity_WardensHouse_Text_HifFuffHefifoo, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, FuchsiaCity_WardensHouse_EventScript_WardenYes
	call_if_eq VAR_RESULT, NO, FuchsiaCity_WardensHouse_EventScript_WardenNo
	release
	end

FuchsiaCity_WardensHouse_EventScript_GiveGoldTeeth::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_OBTAIN_TMHM
	message FuchsiaCity_WardensHouse_Text_GaveGoldTeethToWarden
	waitmessage
	waitfanfare
	msgbox FuchsiaCity_WardensHouse_Text_WardenPoppedInHisTeeth
	call EventScript_RestorePrevTextColor
	checkplayergender
	call_if_eq VAR_RESULT, MALE, FuchsiaCity_WardensHouse_EventScript_WardenThanksMale
	call_if_eq VAR_RESULT, FEMALE, FuchsiaCity_WardensHouse_EventScript_WardenThanksFemale
	giveitem_msg FuchsiaCity_WardensHouse_Text_ReceivedHM04FromWarden, ITEM_HM04
	setflag FLAG_GOT_HM04
	removeitem ITEM_GOLD_TEETH
	release
	end

FuchsiaCity_WardensHouse_EventScript_WardenThanksMale::
	msgbox FuchsiaCity_WardensHouse_Text_ThanksSonGiveYouSomething
	return

FuchsiaCity_WardensHouse_EventScript_WardenThanksFemale::
	msgbox FuchsiaCity_WardensHouse_Text_ThanksLassieGiveYouSomething
	return

FuchsiaCity_WardensHouse_EventScript_WardenYes::
	msgbox FuchsiaCity_WardensHouse_Text_AhHowheeHoHoo
	return

FuchsiaCity_WardensHouse_EventScript_WardenNo::
	msgbox FuchsiaCity_WardensHouse_Text_HeOhayHeHaHoo
	return

FuchsiaCity_WardensHouse_EventScript_ExplainStrength::
	msgbox FuchsiaCity_WardensHouse_Text_ExplainStrength
	release
	end

FuchsiaCity_WardensHouse_EventScript_DisplaySign1::
	msgbox FuchsiaCity_WardensHouse_Text_MonPhotosFossilsOnDisplay, MSGBOX_SIGN
	end

FuchsiaCity_WardensHouse_EventScript_DisplaySign2::
	msgbox FuchsiaCity_WardensHouse_Text_OldMonMerchandiseOnDisplay, MSGBOX_SIGN
	end

FuchsiaCity_WardensHouse_Text_HifFuffHefifoo::
	.string "GUARDIANO: Hif fuff fiu!\p"
	.string "Ha lof ha fif ii hafai ho.\n"
	.string "Heff hee fwee!$"

FuchsiaCity_WardensHouse_Text_AhHowheeHoHoo::
	.string "Ah ughi ho hu!\n"
	.string "Iif ii hafai ho!$"

FuchsiaCity_WardensHouse_Text_HeOhayHeHaHoo::
	.string "Ha?\n"
	.string "He ohai heh ha hu i haheh!$"

FuchsiaCity_WardensHouse_Text_GaveGoldTeethToWarden::
	.string "{PLAYER} dà i DENTI D'ORO\n"
	.string "al GUARDIANO.$"

FuchsiaCity_WardensHouse_Text_WardenPoppedInHisTeeth::
	.string "Il GUARDIANO si è messo i denti!$"

FuchsiaCity_WardensHouse_Text_ThanksSonGiveYouSomething::
	.string "GUARDIANO: Grazie!\n"
	.string "Mi hai salvato davvero!\p"
	.string "Nessuno capiva una parola\n"
	.string "di quello che dicevo!\p"
	.string "Mi vergognavo persino a\n"
	.string "farmi vedere in UFFICIO.\p"
	.string "Ti meriti qualcosa per la\n"
	.string "fatica.$"

FuchsiaCity_WardensHouse_Text_ThanksLassieGiveYouSomething::
	.string "GUARDIANO: Grazie, bimba!\n"
	.string "Mi hai salvato davvero!\p"
	.string "Nessuno capiva una parola\n"
	.string "di quello che dicevo!\p"
	.string "Mi vergognavo persino a\n"
	.string "farmi vedere in UFFICIO.\p"
	.string "Ti meriti qualcosa per la\n"
	.string "fatica.$"

FuchsiaCity_WardensHouse_Text_ReceivedHM04FromWarden::
	.string "{PLAYER} riceve MN04!\n"
	.string "dal GUARDIANO.$"

FuchsiaCity_WardensHouse_Text_ExplainStrength::
	.string "GUARDIANO: Nella MN04 trovi\n"
	.string "FORZA.\p"
	.string "Permette ai POKéMON di spostare\n"
	.string "i massi fuori dalla lotta.\p"
	.string "Ah, hai trovato la CASA\n"
	.string "SEGRETA nel ZONE SAFARI?$"

@ Unused
FuchsiaCity_WardensHouse_Text_YouHaveTooMuchStuff::
	.string "なんや　にもつ\n"
	.string "いっぱいやんけ！$"

FuchsiaCity_WardensHouse_Text_MonPhotosFossilsOnDisplay::
	.string "Foto e fossili di POKéMON in\n"
	.string "mostra.$"

FuchsiaCity_WardensHouse_Text_OldMonMerchandiseOnDisplay::
	.string "Vecchie cose POKéMON in\n"
	.string "mostra.$"

