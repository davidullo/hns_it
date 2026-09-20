Route30_House_hns_MapScripts::
	.byte 0

Route30_House_EventScript_BaldMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BERRY_ROUTE_30_HOUSE, Route30_House_EventScript_BaldMan2
	msgbox Route30_BerryHouse_Text_MonEatBerries, MSGBOX_DEFAULT
	giveitem ITEM_CHERI_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_GOT_BERRY_ROUTE_30_HOUSE
Route30_House_EventScript_BaldMan2::
	msgbox Route30_BerryHouse_Text_CheckTrees, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_BerryHouse_Text_MonEatBerries:
	.string "Se segui quel sentiero a nord,\n"
	.string "vedrai la casa del SIG. POKéMON.\p"
	.string "Ma prima lascia che ti\n"
	.string "parli delle BACCHE!\p"
	.string "I POKéMON stanno meglio mangiando\n"
	.string "le BACCHE.\p"
	.string "Possono mangiarle anche\n"
	.string "se le tengono in lotta.\p"
	.string "Le BACCHE diventano\n"
	.string "BALL con KURT ad AZALINA.\p"
	.string "Tieni. Te ne do una!$"

Route30_BerryHouse_Text_CheckTrees:
	.string "Cerca le BACCHE sugli alberi.\n"
	.string "Ricrescono dopo qualche ora.$"
