Route26_House1_hns_MapScripts::
	.byte 0

Route26_House1_EventScript_HealWoman::
	lock
	faceplayer
	msgbox Route26_Text_HealHouseRest, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route26_Text_HealHouseKeepAtIt, MSGBOX_DEFAULT
	release
	end


Route26_Text_HealHouseRest:
    .string "I tuoi POKéMON sembrano stanchi.\p"
    .string "Dovresti farli riposare un po'.$"

Route26_Text_HealHouseKeepAtIt:
    .string "Ecco!\p"
    .string "I tuoi POKéMON stanno bene!\p"
    .string "Continua così!$"
