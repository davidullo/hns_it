NewBarkTown_House2_hns_MapScripts::
	.byte 0


NewBarkTown_House2_EventScript_ElmsWife::
	lock
	faceplayer
	msgbox NewBarkTown_House2_Text_ElmsWife, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House2_EventScript_ElmsSon::
	lock
	faceplayer
	msgbox NewBarkTown_House2_Text_ElmsSon, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House2_Text_ElmsWife:
	.string "Ciao, {PLAYER}! Mio marito è sempre\n"
	.string "occupato, spero stia bene.\p"
	.string "Quando è preso dalle sue\n"
	.string "ricerche sui POKéMON,\l"
	.string "si dimentica pure di mangiare.$"

NewBarkTown_House2_Text_ElmsSon:
	.string "Da grande aiuterò\n"
	.string "mio papà!\p"
	.string "Sarò un grande\n"
	.string "professore POKéMON!$"
