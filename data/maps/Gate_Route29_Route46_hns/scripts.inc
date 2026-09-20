Gate_Route29_Route46_hns_MapScripts::
	.byte 0

Gate_Route29_Route46_EventScript_Officer::
	lock
	faceplayer
	msgbox Gate_Route29_Route46_Text_Officer, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route29_Route46_EventScript_Youngster::
	lock
	faceplayer
	msgbox Gate_Route29_Route46_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route29_Route46_Text_Officer:
	.string "Non salire sui bordi.\p"
	.string "Ma puoi saltar giù\n"
	.string "per una scorciatoia.$"

Gate_Route29_Route46_Text_Youngster:
	.string "Qui oltre ci sono POKéMON\n"
	.string "diversi.\p"
	.string "Se li vuoi acchiappare tutti,\n"
	.string "devi guardare ovunque.$"
