Route7_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route7_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route7_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route7_EventScript_Sign::
	msgbox Route7_Text_UndergroundPathSign, MSGBOX_SIGN
	end

Route7_EventScript_Door::
	msgbox Route7_Text_LockedDoor, MSGBOX_SIGN
	end

Route7_Text_UndergroundPathSign:
	.string "Che volantino è?\p"
	.string "… Allenatori maleducati hanno\n"
	.string "combattuto nella\l"
	.string "GALLERIA SOTTERRANEA.\p"
	.string "Per le proteste dei residenti,\n"
	.string "la GALLERIA SOTTERRANEA è stata\l"
	.string "chiusa a tempo indefinito.\p"
	.string "POLIZIA DI AZZURROPOLI$"

Route7_Text_LockedDoor:
	.string "È chiuso…$"

