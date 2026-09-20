OlivineCity_Mart_hns_MapScripts::
	.byte 0

OlivineCity_EventScript_Trainer1::
	lock
	faceplayer
	msgbox OlivineCity_Text_MartCooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Lass::
	lock
	faceplayer
	msgbox OlivineCity_Text_MartLass, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_MartCooltrainerF:
	.string "I tuoi POKéMON conoscono già\n"
	.string "la mossa per portare persone\l"
	.string "sull'acqua?$"

OlivineCity_Text_MartLass:
	.string "Il mio BUTTERFREE viene dal mio\n"
	.string "ragazzo all'estero.\p"
	.string "Mi ha portato una LETTERA.\p"
	.string "Vuoi sapere cosa dice?\p"
	.string "Vediamo... No! È un\n"
	.string "segreto!$"
