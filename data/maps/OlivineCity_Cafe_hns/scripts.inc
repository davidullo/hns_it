OlivineCity_Cafe_hns_MapScripts::
	.byte 0

OlivineCity_Cafe_EventScript_Jasmine::
	lock
	faceplayer
	msgbox OlivineCity_Cafe_Text_Jasmine, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_CAFE_JASMINE
	removeobject LOCALID_CAFE_JASMINE
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_DOJO_JASMINE
	release
	end

OlivineCity_Cafe_Text_Jasmine:
	.string "Oh... Ciao, {PLAYER}.\p"
	.string "Questi piatti davanti a me non\n"
	.string "sono tutti miei...\p"
	.string "Uh...\p"
	.string "Veramente, chi era seduto qui\n"
	.string "prima ha mangiato molto...\p"
	.string "Se vuoi lottare ancora,\n"
	.string "vieni al DOJO FIGHTING di\l"
	.string "ZAFFERANOPOLI.$"

OlivineCity_EventScript_SailorA::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_STRENGTH, OlivineCity_EventScript_SailorA2
	msgbox OlivineCity_Text_CafeSailorStrength, MSGBOX_DEFAULT
	giveitem ITEM_HM_STRENGTH
	setflag FLAG_RECEIVED_HM_STRENGTH
OlivineCity_EventScript_SailorA2::
	msgbox OlivineCity_Text_CafeSailorGotStrength, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Cook::
	lock
	faceplayer
	msgbox OlivineCity_Text_CafeFishingGuru, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_SailorB::
	lock
	faceplayer
	msgbox OlivineCity_Text_CafeSailor, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_CafeSailorStrength:
	.string "Ah! I tuoi POKéMON sembrano\n"
	.string "degli smidollati!\p"
	.string "Non hanno la forza di\n"
	.string "spostare i massi.\p"
	.string "Tieni, usa questa e insegna\n"
	.string "FORZA!$"

OlivineCity_Text_CafeSailorGotStrength:
	.string "In mare puoi contare solo\n"
	.string "su te stesso!\p"
	.string "Sono fiero dei miei muscoli!\n"
	.string "Dovresti allenarti come me!$"

OlivineCity_Text_CafeFishingGuru:
	.string "Il menù dell'OLIVINE CAFE è pieno\n"
	.string "di piatti sostanziosi per\l"
	.string "MARINAITOSI come me!$"

OlivineCity_Text_CafeSailor:
	.string "Ogni volta che passo di qui,\n"
	.string "vado sempre all'OLIVINE CAFE.\p"
	.string "Tutto il menù mi fa sentire\n"
	.string "più forte. Non smetto più di mangiare!$"

