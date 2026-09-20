CherrygroveCity_House3_hns_MapScripts::
	.byte 0

CherrygroveCity_House3_EventScript_Boy::
	lock
	faceplayer
	msgbox CherrygroveCity_EvolutionHouse_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_House3_EventScript_Girl::
	lock
	faceplayer
	msgbox CherrygroveCity_EvolutionHouse_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_EvolutionHouse_Text_Youngster:
	.string "I POKéMON crescono in\n"
	.string "lotta e cambiano forma.$"

CherrygroveCity_EvolutionHouse_Text_Lass:
	.string "I POKéMON cambiano?\p"
	.string "Se lo facessero, resterei\n"
	.string "di stucco!$"
