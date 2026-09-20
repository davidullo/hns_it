CianwoodHouse3_hns_MapScripts::
	.byte 0

CianwoodCity_EventScript_Kirk::
	lock
	faceplayer
	goto_if_eq VAR_SHUCKIE, 1, CianwoodCity_EventScript_KirkGivenShuckie
	goto_if_eq VAR_SHUCKIE, 3, CianwoodCity_EventScript_KirkReturnedShuckie
	msgbox CianwoodCity_Text_ManiacAskShuckle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, CianwoodCity_EventScript_KirkDeclined

	@HnS named gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SHUCKLE
	bufferspeciesname STR_VAR_1, SPECIES_SHUCKLE
	givenamedmon 2
	call Common_EventScript_GiftMonNamed

	setvar VAR_SHUCKIE, 1
	release
	end

CianwoodCity_EventScript_KirkDeclined::
	msgbox CianwoodCity_Text_ManiacIfHeComesBack, MSGBOX_DEFAULT
	closemessage
	end

CianwoodCity_EventScript_KirkGivenShuckie::
	goto_if_set FLAG_BADGE01_GET, CianwoodCity_EventScript_KirkReturnShuckie
	msgbox CianwoodCity_Text_ManiacHowsdoing, MSGBOX_DEFAULT
	closemessage
	end

CianwoodCity_EventScript_KirkReturnShuckie::
	msgbox CianwoodCity_Text_ManiacAskReturn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, CianwoodCity_EventScript_KirkDeclineReturnShuckie
	removenamedmon 2
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, CianwoodCity_EventScript_KirkNotRight
	goto_if_eq VAR_RESULT, 3, CianwoodCity_EventScript_KirkKeepShuckie
	playse MUS_OBTAIN_ITEM
	callnative UpdateFollowingPokemon
	msgbox CianwoodCity_Text_ManiacReturnedMon, MSGBOX_DEFAULT
	waitse
	msgbox CianwoodCity_Text_ManiacThankYou, MSGBOX_DEFAULT
	setvar VAR_SHUCKIE, 3
	release
	end

CianwoodCity_EventScript_KirkDeclineReturnShuckie::
	msgbox CianwoodCity_Text_ManiacRobbed2, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_EventScript_KirkNotRight::
	msgbox CianwoodCity_Text_ManiacRobbed, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_EventScript_KirkKeepShuckie::
	msgbox CianwoodCity_Text_ManiacShuckleLikesYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SHUCKIE, 3
	release
	end

CianwoodCity_EventScript_KirkReturnedShuckie::
	msgbox CianwoodCity_Text_ManiacHappinessSpeech, MSGBOX_DEFAULT
	closemessage
	end

CianwoodCity_Text_ManiacAskShuckle:
	.string "Che, che shock!\p"
	.string "Un tipo della tua età, con occhi\n"
	.string "penetranti e capelli lunghi.\p"
	.string "Mi ha spaventato e gli ho dato il\n"
	.string "mio POKéMON adorato!\p"
	.string "Ne ho ancora uno, ma se\n"
	.string "torna?\p"
	.string "Sembri forte. Potresti badare\n"
	.string "al mio POKéMON per un po'?$"

CianwoodCity_Text_ManiacTakeCareShuckle:
	.string "Oh, grazie!\p"
	.string "Abbi cura di lui, ti prego!$"

CianwoodCity_Text_ManiacGotShuckle:
	.string "{PLAYER} ha ricevuto un POKéMON.$"

CianwoodCity_Text_ManiacPartyFull:
	.string "La squadra POKéMON è piena.$"

CianwoodCity_Text_ManiacIfHeComesBack:
	.string "Oh, no… Che faccio se\n"
	.string "torna?$"

CianwoodCity_Text_ManiacHowsdoing:
	.string "Ciao! Come sta il mio POKéMON?$"

CianwoodCity_Text_ManiacAskReturn:
	.string "Ciao! Come sta il mio POKéMON?\p"
	.string "Ora sono al sicuro, posso\n"
	.string "riaverlo?$"

CianwoodCity_Text_ManiacThankYou:
	.string "Grazie!$"

CianwoodCity_Text_ManiacShuckleNotThere:
	.string "Ehi, non hai il mio POKéMON\n"
	.string "con te.$"

CianwoodCity_Text_ManiacShuckleLikesYou:
	.string "Il mio POKéMON si è affezionato\p"
	.string "a te. Bene, puoi tenerlo.\p"
	.string "Ma prometti di trattarlo bene!$"

CianwoodCity_Text_ManiacRobbed:
	.string "Ehi, qualcosa non va.$"

CianwoodCity_Text_ManiacRobbed2:
	.string "Oh, no, no… È come\n"
	.string "subire un furto.$"

CianwoodCity_Text_ManiacHappinessSpeech:
	.string "Per i POKéMON, la felicità è\n"
	.string "con chi li tratta bene.$"

CianwoodCity_Text_ManiacLastMon:
	.string "Se riprendo il mio POKéMON,\n"
	.string "cosa userai in\n"
	.string "battaglia?$"


CianwoodCity_Text_ManiacReturnedMon:
	.string "{PLAYER} restituisce SHUCKIE.$"
