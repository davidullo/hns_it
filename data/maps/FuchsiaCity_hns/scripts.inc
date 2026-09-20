FuchsiaCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_EventScript_CityEnter
	.byte 0

FuchsiaCity_EventScript_CityEnter::
	setflag FLAG_VISITED_FUCHSIA_CITY
	end

FuchsiaCity_EventScript_BaobaCall::
	lock
	setspeaker FuchsiaCity_Text_BaobaName
	pokenavcall FuchsiaCity_Text_Baoba
	waitmessage
	delay 30
	setvar VAR_BAOBA_QUEST_STATE, 1
	setvar VAR_FUCHSIA_CITY_STATE, 1
	release
	end

FuchsiaCity_Text_BaobaName:
	.string "BAOBA$"

FuchsiaCity_Text_Baoba:
	.string "GUARDIANO BAOBA: {PLAYER}!\p"
	.string "Sono il GUARDIANO BAOBA.\p"
	.string "È successo qualcosa di grave!\n"
	.string "La mia vecchia ZONA SAFARI di\l"
	.string "FUCHSIA è stata comprata e\p"
	.string "riaperta! Pare che abbia POKéMON\n"
	.string "esotici!\p"
	.string "Danneggia i miei affari!\p"
	.string "{PLAYER}, devi avventurarti\n"
	.string "nella nuova ZONA SAFARI e catturare un\l"
	.string "un POKéMON da mostrarmi. Devo sapere\l"
	.string "“esotici” POKéMON.\p"
	.string "Ti prego {PLAYER}, dipende tutto\n"
	.string "da te!$"

FuchsiaCity_EventScript_Dratini::
	lock
	showmonpic SPECIES_DRATINI, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Kangaskhan::
	lock
	showmonpic SPECIES_KANGASKHAN, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Cubone::
	lock
	showmonpic SPECIES_CUBONE, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Omanyte::
	lock
	showmonpic SPECIES_OMANYTE, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Kabuto::
	lock
	showmonpic SPECIES_KABUTO, 10, 3
	delay 60
	hidemonpic
	release
	end

FuchsiaCity_EventScript_Youngster::
	msgbox FuchsiaCity_Text_Youngster, MSGBOX_NPC
	end

FuchsiaCity_EventScript_PokefanM::
	msgbox FuchsiaCity_Text_PokefanM, MSGBOX_NPC
	end

FuchsiaCity_EventScript_Teacher::
	msgbox FuchsiaCity_Text_Teacher, MSGBOX_NPC
	end

FuchsiaCity_EventScript_CitySign::
	msgbox FuchsiaCity_Text_Sign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_GymSign::
	msgbox FuchsiaCity_Text_GymSign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_SafariZone::
	msgbox FuchsiaCity_Text_SafariZone, MSGBOX_NPC
	end

FuchsiaCity_Text_Youngster:
	.string "Uno dei SUPERQUATTRO era\n"
	.string "il CAPOPALESTRA di FUCHSIA.$"

FuchsiaCity_Text_PokefanM:
	.string "La figlia di KOGA gli è succeduta\n"
	.string "come CAPOPALESTRA, poi entra nei\l"
	.string "SUPERQUATTRO.$"

FuchsiaCity_Text_Teacher:
	.string "La ZONA SAFARI ha una nuova\n"
	.string "gestione.\p"
	.string "E ha tanti POKéMON nuovi!$"

FuchsiaCity_Text_Sign:
	.string "FUCHSIA CITY\p"
	.string "Ammira! Il Rosa Passione!$"

FuchsiaCity_Text_GymSign:
	.string "PALESTRA DI FUCHSIA\n"
	.string "CAPO: JANINE\p"
	.string "La Maestra Ninja del Veleno$"

FuchsiaCity_Text_SafariZoneOfficeSign:
	.string "C'è un avviso qui…\p"
	.string "UFFICIO ZONA SAFARI chiuso fino a\n"
	.string "nuovo avviso.$"

FuchsiaCity_Text_SafariZone:
	.string "ZONA SAFARI\n"
	.string "DI PROPRIETÀ\l"
	.string "DEVON SPA.$"

FuchsiaCity_Text_SafariZoneClosedSign:
	.string "Il GUARDIANO è all'estero.\p"
	.string "Perciò la ZONA SAFARI è\n"
	.string "chiusa.$"

FuchsiaCity_Text_NoLitteringSign:
	.string "Non sporcare.\p"
	.string "Porta via i tuoi rifiuti.$"

