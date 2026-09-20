Route12_House_hns_MapScripts::
	.byte 0

Route12_House_EventScript_SuperRod::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SUPER_ROD, Route12_House_EventScript_SuperRodGot
	msgbox Route12_House_Text_OfferSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route12_House_EventScript_SuperRodRefused
	msgbox Route12_House_Text_GiveSuperRod, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	msgbox Route12_House_Text_GaveSuperRod, MSGBOX_DEFAULT
	setflag FLAG_GOT_SUPER_ROD
	closemessage
	release
	end

Route12_House_EventScript_SuperRodRefused::
	msgbox Route12_House_Text_DontWantSuperRod, MSGBOX_DEFAULT
	closemessage
	release
	end

Route12_House_EventScript_SuperRodGot::
	msgbox Route12_House_Text_GaveSuperRod, MSGBOX_NPC
	release
	end

Route12_House_Text_OfferSuperRod:
	.string "Sono il fratello minore del\n"
	.string "GURU DELLA PESCA.\p"
	.string "Vedo che ti piace pescare.\p"
	.string "Non ho alcun dubbio\n"
	.string "al riguardo!\p"
	.string "Allora? So di aver ragione.$"

Route12_House_Text_GiveSuperRod:
	.string "Sì, sì. Proprio come pensavo!\p"
	.string "Tieni, appassionato di pesca!\n"
	.string "È un SUPER AMO.$"

Route12_House_Text_GaveSuperRod:
	.string "Prova a pescare dove\n"
	.string "c'è acqua.\p"
	.string "Ricorda: con AMI diversi\n"
	.string "prendi POKéMON diversi.$"

Route12_House_Text_DontWantSuperRod:
	.string "Eh? I miei occhi mi hanno ingannato?$"

