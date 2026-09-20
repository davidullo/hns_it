Gate_RuinsOfAlph_Route32_hns_MapScripts::
	.byte 0


Gate_RuinsOfAlph_Route32_EventScript_PokefanM::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route32_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route32_EventScript_Youngster::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route32_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route32_Text_PokefanM:
	.string "Studi le ROVINE?\n"
	.string "Vedo un futuro studioso.$"

Gate_RuinsOfAlph_Route32_Text_Youngster:
	.string "Ci sono disegni su\n"
	.string "lastre.\p"
	.string "Le ho mosse.\n"
	.string "Chissà che sono.$"
