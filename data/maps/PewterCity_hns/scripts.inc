PewterCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_EventScript_CityEnter
	.byte 0

PewterCity_EventScript_CityEnter::
	setflag FLAG_VISITED_PEWTER_CITY
	end

PewterCity_EventScript_CooltrainerF::
	msgbox PewterCity_Text_CooltrainerF, MSGBOX_NPC
	end

PewterCity_EventScript_BugCatcher::
	msgbox PewterCity_Text_BugCatcher, MSGBOX_NPC
	end

PewterCity_EventScript_Gramps::
	lock
	faceplayer
	goto_if_eq VAR_LUGIA_OR_HOOH, 1, PewterCity_EventScript_GrampsRainbowWing
	goto_if_eq VAR_LUGIA_OR_HOOH, 2, PewterCity_EventScript_GrampsSilverWing
	end

PewterCity_EventScript_GrampsRainbowWing::
	checkitem ITEM_RAINBOW_WING
	goto_if_eq VAR_RESULT, TRUE, PewterCity_EventScript_GrampsDone
	msgbox PewterCity_Text_Gramps, MSGBOX_DEFAULT
	setvar VAR_COMPLETED_HO_OH, 4
	giveitem ITEM_RAINBOW_WING
	setflag FLAG_HIDE_TINTOWER_GUARD
	closemessage
	release
	end

PewterCity_EventScript_GrampsSilverWing::
	checkitem ITEM_SILVER_WING
	goto_if_eq VAR_RESULT, TRUE, PewterCity_EventScript_GrampsDone
	msgbox PewterCity_Text_Gramps, MSGBOX_DEFAULT
	setvar VAR_COMPLETED_LUGIA, 4
	giveitem ITEM_SILVER_WING
	setflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	closemessage
	release
	end

PewterCity_EventScript_GrampsDone::
	msgbox PewterCity_Text_Gramps_GotSilverWing, MSGBOX_DEFAULT
	closemessage
	release
	end

PewterCity_EventScript_Bugcatcher::
	msgbox PewterCity_Text_BugCatcher, MSGBOX_NPC
	end

PewterCity_EventScript_Cooltrainer::
	msgbox PewterCity_Text_CooltrainerF, MSGBOX_NPC
	end

PewterCity_Text_CooltrainerF:
	.string "Hai visitato la PALESTRA\ndi PLUMBEOPOLI?\p"
	.string "Il CAPO usa POKéMON di tipo ROCCIA.$"

PewterCity_Text_BugCatcher:
	.string "Di notte, i CLEFAIRY vengono a giocare al\n"
	.string "MT.MOON.\p"
	.string "Ma non tutte le notti.$"

PewterCity_Text_Gramps:
	.string "Ah, sei venuto fin qui da\n"
	.string "JOHTO?\p"
	.string "Che ricordi. Da giovane andai\n"
	.string "a JOHTO ad allenarmi.\p"
	.string "Mi ricordi tanto come ero io\n"
	.string "da giovane.\p"
	.string "Tieni. Voglio che tu abbia questo\n"
	.string "oggetto che trovai a JOHTO.$"

PewterCity_Text_Gramps_GotSilverWing:
	.string "Andare in posti nuovi e sconosciuti e\n"
	.string "conoscere gente nuova…\p"
	.string "Queste sono le gioie del viaggio.$"

PewterCity_EventScript_CitySign::
	msgbox PewterCity_Text_Sign, MSGBOX_NPC
	end

PewterCity_EventScript_GymSign::
	msgbox PewterCity_Text_GymSign, MSGBOX_NPC
	end

PewterCity_EventScript_MuseumSign::
	msgbox PewterCity_Text_MuseumSign, MSGBOX_NPC
	end

PewterCity_EventScript_MtMoonSign::
	msgbox PewterCity_Text_MtMoonGiftShopSign, MSGBOX_NPC
	end

PewterCity_EventScript_WelcomeSign::
	msgbox PewterCity_Text_WelcomeSign, MSGBOX_NPC
	end

PewterCity_Text_Sign:
	.string "PLUMBEOPOLI\n"
	.string "Una città grigio pietra$"

PewterCity_Text_GymSign:
	.string "PALESTRA POKéMON DI PLUMBEOPOLI\n"
	.string "CAPO: BROCK\p"
	.string "L'Allenatore dalle rocce solide$"

PewterCity_Text_MuseumSign:
	.string "C'è un avviso…\p"
	.string "Il MUSEO DELLA SCIENZA\n"
	.string "di PLUMBEOPOLI è chiuso per lavori…$"

PewterCity_Text_MtMoonGiftShopSign:
	.string "C'è un avviso qui…\p"
	.string "IL NEGOZIO DI MT.MOON È APERTO!$"

PewterCity_Text_WelcomeSign:
	.string "BENVENUTI A PLUMBEOPOLI!$"

