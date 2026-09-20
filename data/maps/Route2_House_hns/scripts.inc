Route2_House_hns_MapScripts::
	.byte 0

Route2_House_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_GOT_ROUTE2_NUGGET, Route2_House_EventScript_ManAfter
	msgbox Route2_House_Text_Fisher, MSGBOX_DEFAULT 
	giveitem ITEM_NUGGET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route2_House_Text_Fisher_GotNugget, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_GOT_ROUTE2_NUGGET
	release
	end

Route2_House_EventScript_ManAfter::
	msgbox Route2_House_Text_Fisher_GotNugget, MSGBOX_DEFAULT
	closemessage
	release
	end

Route2_House_Text_Fisher:
	.string "Ciao! Che bello vederti.\p"
	.string "Sei il primo visitatore da\n"
	.string "molto tempo.\p"
	.string "Sono felicissimo! Ti do un\n"
	.string "piccolo regalo.$"

Route2_House_Text_Fisher_GotNugget:
	.string "È una PEPITA.\p"
	.string "Non ho perle di saggezza da\n"
	.string "darti, quindi accontentati!$"
