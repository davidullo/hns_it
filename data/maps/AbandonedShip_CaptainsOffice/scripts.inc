AbandonedShip_CaptainsOffice_MapScripts::
	.byte 0

AbandonedShip_CaptainsOffice_EventScript_CaptSternAide::
	lock
	faceplayer
	goto_if_set FLAG_EXCHANGED_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	checkitem ITEM_SCANNER
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner
	goto_if_set FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_2_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	msgbox AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner::
	msgbox AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus::
	msgbox AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner:
	.string "Indago su questa nave per\n"
	.string "conto di CAP. STERN.\p"
	.string "Mi ha anche chiesto di trovare\n"
	.string "uno SCANNER, ma senza risultato…$"

AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner:
	.string "Oh! Quello è uno SCANNER!\p"
	.string "Senti, puoi portarlo tu\n"
	.string "a CAP. STERN?\p"
	.string "Voglio esplorare ancora\n"
	.string "un po' la nave.$"

AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus:
	.string "Questa nave si chiama S.S. CACTUS.\n"
	.string "Sembra venire da un'altra epoca.$"

