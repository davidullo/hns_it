SlateportCity_House_MapScripts::
	.byte 0

SlateportCity_House_EventScript_PokefanM::
	msgbox SlateportCity_House_Text_NatureToDoWithStatGains, MSGBOX_NPC
	end

SlateportCity_House_EventScript_Girl::
	msgbox SlateportCity_House_Text_MustBeGoingToBattleTent, MSGBOX_NPC
	end

SlateportCity_House_Text_NatureToDoWithStatGains:
	.string "Il mio POKéMON ha una natura Lesta.\p"
	.string "Ha una VELOCITÀ più alta rispetto\n"
	.string "agli altri miei POKéMON.\p"
	.string "Forse la natura influisce sulle\n"
	.string "statistiche dei POKéMON.$"

SlateportCity_House_Text_MustBeGoingToBattleTent:
	.string "Sei un ALLENATORE, vero?\p"
	.string "Visto che sei venuto a SLATEPORT CITY,\n"
	.string "vorrai andare al BATTLE TENT.$"

