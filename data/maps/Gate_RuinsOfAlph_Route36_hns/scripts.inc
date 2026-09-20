Gate_RuinsOfAlph_Route36_hns_MapScripts::
	.byte 0

Gate_RuinsOfAlph_Route36_EventScript_Officer::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route36_Text_Officer, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route36_EventScript_PokefanM::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route36_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route36_EventScript_Youngster::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route36_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route36_Text_Officer:
	.string "RUINS OF ALPH\p"
	.string "A Look-and-Touch Tourist Site\p"
	.string "Try the sliding stone panels!$"

Gate_RuinsOfAlph_Route36_Text_PokefanM:
	.string "Studi le ROVINE?\p"
	.string "Vedo un futuro studioso.$"

Gate_RuinsOfAlph_Route36_Text_Youngster:
	.string "Ci sono disegni su\n"
	.string "lastre.\p"
	.string "Le ho mosse.\n"
	.string "Chissà che sono.$"
