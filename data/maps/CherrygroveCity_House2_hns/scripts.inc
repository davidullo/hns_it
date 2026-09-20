CherrygroveCity_House2_hns_MapScripts::
	.byte 0

CherrygroveCity_House2_EventScript_GuideGent::
	lock
	faceplayer
	msgbox CherrygroveCity_GuideHouse_Text_GuideGent, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_GuideHouse_Text_GuideGent:
	.string "Quando ero piccolo,\n"
	.string "ero un asso!\p"
	.string "Un consiglio da amico:\n"
	.string "Cattura tanti POKéMON!\p"
	.string "Sii gentile con loro!$"
