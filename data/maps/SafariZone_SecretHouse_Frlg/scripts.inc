SafariZone_SecretHouse_Frlg_MapScripts::
	.byte 0

SafariZone_SecretHouse_EventScript_Attendant::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HM03, SafariZone_SecretHouse_EventScript_ExplainSurf
	msgbox SafariZone_SecretHouse_Text_CongratsYouveWon
	checkitemspace ITEM_HM03
	goto_if_eq VAR_RESULT, FALSE, SafariZone_SecretHouse_EventScript_NoRoomForHM03
	giveitem_msg SafariZone_SecretHouse_Text_ReceivedHM03FromAttendant, ITEM_HM03
	msgbox SafariZone_SecretHouse_Text_ExplainSurf
	setflag FLAG_GOT_HM03
	release
	end

SafariZone_SecretHouse_EventScript_NoRoomForHM03::
	msgbox SafariZone_SecretHouse_Text_DontHaveRoomForPrize
	release
	end

SafariZone_SecretHouse_EventScript_ExplainSurf::
	msgbox SafariZone_SecretHouse_Text_ExplainSurf
	release
	end

SafariZone_SecretHouse_Text_CongratsYouveWon::
	.string "Ah! Finalmente!\p"
	.string "Sei il primo ad arrivare\n"
	.string "alla CASA SEGRETA!\p"
	.string "Anche se ho fatto una campagna\n"
	.string "per la nostra grande apertura,\p"
	.string "temevo che nessuno avrebbe\n"
	.string "vinto il premio della campagna.\p"
	.string "Congratulazioni!\n"
	.string "Hai vinto!$"

SafariZone_SecretHouse_Text_ReceivedHM03FromAttendant::
	.string "{PLAYER} riceve la MN03\n"
	.string "dall'addetto!$"

SafariZone_SecretHouse_Text_ExplainSurf::
	.string "La MN03 è SURF.\p"
	.string "Con essa i POKéMON potranno\n"
	.string "portarti sull'acqua.\p"
	.string "E questa MN non si consuma, quindi\n"
	.string "puoi usarla all'infinito.\p"
	.string "Sei fortunatissimo ad aver vinto questo\n"
	.string "favoloso premio!$"

SafariZone_SecretHouse_Text_DontHaveRoomForPrize::
	.string "Non hai spazio per questo\n"
	.string "favoloso premio!$"

