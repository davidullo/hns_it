Route39_FarmHouse_hns_MapScripts::
	.byte 0


Route39House_EventScript_FarmerF::
	lock
	faceplayer
	goto_if_eq VAR_ROUTE39_BARN, 5, Route39House_EventScript_FarmerFAfter
	msgbox Route39_Text_FarmerFInTrouble, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39House_EventScript_FarmerFAfter::
	goto_if_set FLAG_GOT_TM_SNATCH, Route39House_EventScript_FarmerFAfterTM
	msgbox Route39_Text_FarmerFHealedMiltank, MSGBOX_DEFAULT
	giveitem ITEM_TM_SNATCH
	msgbox Route39_Text_FarmerFSnatchSpeech, MSGBOX_DEFAULT
	closemessage 
	setflag FLAG_GOT_TM_SNATCH
	release
	end

Route39House_EventScript_FarmerFAfterTM::
	msgbox Route39_Text_FarmerFSnatchSpeech, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM::
	lock
	faceplayer
	goto_if_lt VAR_ROUTE39_BARN, 5, Route39_FarmHouse_EventScript_FarmerM_Sick
	showmoneybox 0, 0
	msgbox Route39_Text_FarmerMBuyMilk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route39_FarmHouse_EventScript_FarmerMBuyMilk
	msgbox Route39_Text_FarmerMNoSale, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	end

Route39_FarmHouse_EventScript_FarmerMBuyMilk::
	checkmoney 500, 0
	goto_if_eq VAR_RESULT, FALSE, Route39_FarmHouse_EventScript_FarmerM_NotEnough
	additem ITEM_MOOMOO_MILK
	goto_if_eq VAR_RESULT, FALSE, Route39_FarmHouse_EventScript_FarmerM_BagFull
	removemoney 500
	updatemoneybox 0
	msgbox Route39FarmHouse_Text_WouldYouLikeAnother, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route39_FarmHouse_EventScript_FarmerMBuyMilk

	
	msgbox Route39_Text_FarmerMGotMilk, MSGBOX_DEFAULT
	closemessage
	playse MUS_OBTAIN_ITEM
	msgbox Route39_Text_GotMilk, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

Route39_FarmHouse_EventScript_FarmerM_Sick::
	msgbox Route39_Text_FarmerMSickCow, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM_BagFull::
	msgbox Route39_Text_FarmerMNoRoom, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM_NotEnough::
	msgbox Route39_Text_FarmerMNoMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

Route39_Text_FarmerMSickCow:
	.string "La mia MILTANK non mi dà\n"
	.string "più latte.\p"
	.string "Questa FATTORIA è famosa per il latte.\p"
	.string "Quasi tutti ne vogliono un sorso.\p"
	.string "Mi darà tanto latte se\n"
	.string "le do tante BACChe,\l"
	.string "credo.$"

Route39_Text_FarmerMBuyMilk:
	.string "Ti piace il mio LATTE MOOMOO?\p"
	.string "È il mio orgoglio e vanto.\p"
	.string "Dallo ai POKéMON per curarli!\p"
	.string "Te lo do per soli\n"
	.string "¥500.$"

Route39_Text_FarmerMGotMilk:
	.string "Ecco qua!\n"
	.string "Bevilo e gustalo!$"

Route39_Text_FarmerMNoMoney:
	.string "Mi spiace, amico.\n"
	.string "Niente soldi, niente vendita!$"

Route39_Text_FarmerMNoRoom:
	.string "Direi che hai lo ZAINO pieno.$"

Route39_Text_FarmerMNoSale:
	.string "Non lo vuoi?\n"
	.string "Torna presto, intesi?$"

Route39FarmHouse_Text_WouldYouLikeAnother:
	.string "Ne vuoi un altro?$"

Route39_Text_GotMilk:
	.string "{PLAYER} ha ottenuto il LATTE MUUMUU.$"

Route39_Text_FarmerMMilking:
	.string "Meglio che vada a mungere.$"

Route39_Text_FarmerFInTrouble:
	.string "Il nostro latte arriva persino\n"
	.string "a KANTO.\p"
	.string "Quindi se il nostro MILTANK non\n"
	.string "ci dà latte, sono guai.$"

Route39_Text_FarmerFHealedMiltank:
	.string "Hai curato il nostro MILTANK, tesoro.\n"
	.string "Ora dà di nuovo il LATTE MOOMOO.\p"
	.string "Ecco qualcosa per il disturbo.$"

Route39_Text_FarmerFSnatchSpeech:
	.string "That there's SNATCH.\p"
	.string "It's a tricky move that lets\n"
	.string "a POKéMON steal a foe's move\l"
	.string "right before it's used.\p"
	.string "If more than one POKéMON use\n"
	.string "SNATCH, only the slowest one\l"
	.string "will end up stealing the move.\p"
	.string "Use it smart, hon. Timing is\n"
	.string "everything.$"
