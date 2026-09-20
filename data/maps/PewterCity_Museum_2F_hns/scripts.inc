PewterCity_Museum_2F_hns_MapScripts::
	.byte 0


PewterCity_Museum_2F_EventScript_Nerd::
	msgbox PewterCity_Museum_2F_Text_Nerd, MSGBOX_NPC
	end

PewterCity_Museum_2F_EventScript_Daughter::
	lock
	msgbox PewterCity_Museum_2F_Text_AskedDaddyToCatchPikachu, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_2F_EventScript_Dad::
	lock
	msgbox PewterCity_Museum_2F_Text_PikachuSoonIPromise, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_2F_EventScript_Meteor::
	msgbox PewterCity_Museum_2F_Text_MeteoriteThatFellOnMtMoon, MSGBOX_SIGN
	end

PewterCity_Museum_2F_Text_Nerd:
	.string "Dicono che dei meteoriti colpirono\n"
	.string "BIRTH ISLAND.\p"
	.string "Ci piacerebbe esporli qui\n"
	.string "nel nostro museo, ma…\p"
	.string "Si dice che questi meteoriti\n"
	.string "emettano energia strana e non\l"
	.string "si possano portare via…$"

PewterCity_Museum_2F_Text_AskedDaddyToCatchPikachu::
    .string "Voglio un PIKACHU!\n"
    .string "È così carino!\p"
    .string "Ho chiesto al mio papà di prenderlo!$"

PewterCity_Museum_2F_Text_PikachuSoonIPromise::
    .string "Sì, un PIKACHU presto, te lo prometto!$"

PewterCity_Museum_2F_Text_SpaceShuttle::
    .string "Navetta spaziale$"

PewterCity_Museum_2F_Text_MeteoriteThatFellOnMtMoon::
    .string "Un meteorite caduto sul MT. MOON.\n"
    .string "Si pensa sia una PIETRA LUNARE.$"
