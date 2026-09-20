SproutTower_1F_hns_MapScripts::
	.byte 0

SproutTower_1F_EventScript_SageChow::
	trainerbattle_single TRAINER_CHOW_HNS, SproutTower_Text_SageChow_Seen, SproutTower_Text_SageChow_Beaten
	msgbox SproutTower_Text_SageChow_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_1F_EventScript_Sage1::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Sage1, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_Sage2::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Sage2, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_Granny::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_Teacher::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_ItemParalyzeHeal::
	finditem ITEM_PARALYZE_HEAL
	end

SproutTower_Text_SageChow_Seen:
	.string "Facciamo la guardia in questa torre.\p"
	.string "Qui esprimiamo la nostra gratitudine\n"
	.string "in onore di tutti i POKéMON.$"

SproutTower_Text_SageChow_Beaten:
	.string "Gr-Grazie!$"

SproutTower_Text_SageChow_AfterBattle:
	.string "Tutti gli esseri viventi convivono\n"
	.string "grazie alla collaborazione.\p"
	.string "Dobbiamo esserne sempre\n"
	.string "grati.$"

SproutTower_Text_1F_Sage1:
	.string "Solo raggiungendo la cima\n"
	.string "otterrai una MN.$"

SproutTower_Text_1F_Sage2:
	.string "La TORRE SPROUT fu costruita molto\n"
	.string "tempo fa per allenare i POKéMON.$"

SproutTower_Text_1F_Granny:
	.string "Un BELLSPROUT alto più di 30 m…\n"
	.string "Dicono\p"
	.string "che sia diventato la colonna\n"
	.string "centrale di questo posto.$"

SproutTower_Text_1F_Teacher:
	.string "Vedi il pilastro che trema?\p"
	.string "Sopra si stanno allenando.$"

SproutTower_Text_1F_Statue:
	.string "Una statua di POKéMON…\p"
	.string "Sembra molto distinta.$"
