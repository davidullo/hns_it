VioletCity_Mart_hns_MapScripts::
	.byte 0

VioletCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

VioletCity_Mart_EventScript_Granny::
	lock
	faceplayer
	msgbox VioletCity_Mart_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Mart_EventScript_Rocker::
	lock
	faceplayer
	msgbox VioletCity_Mart_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end
	
VioletCity_Mart_Text_Granny:
	.string "Quando catturi un POKéMON,\n"
	.string "può essere debole.\p"
	.string "Ma prima o poi diventerà\n"
	.string "forte.\p"
	.string "È importante trattare i POKéMON\n"
	.string "con amore.$"

VioletCity_Mart_Text_CooltrainerM:
	.string "I POKéMON possono tenere oggetti come\n"
	.string "POZIONE e ANTIDOTO.\p"
	.string "Ma non sembrano sapere\n"
	.string "usare oggetti artificiali.$"
