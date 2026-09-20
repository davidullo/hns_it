CeladonCity_Apartments_RoofHouse_hns_MapScripts::
	.byte 0

CeladonCity_Apartments_RoofHouse_EventScript_BlackBelt::
	lock 
	faceplayer
	goto_if_set FLAG_GOT_TM_SLEEP_TALK, CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltAfter
	msgbox CeladonMansionRoofHouse_Text_PharmacistIntro, MSGBOX_DEFAULT	
	goto_if_set FLAG_NIGHT_POKEMON, CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltRefused
	msgbox CeladonMansionRoofHouse_Text_PharmacistStory, MSGBOX_NPC
	giveitem ITEM_TM_SLEEP_TALK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM_SLEEP_TALK
	msgbox CeladonMansionRoofHouse_Text_PharmacistCurse, MSGBOX_NPC
	closemessage
	release
	end

CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltRefused::
	msgbox CeladonMansionRoofHouse_Text_PharmacistNotNight, MSGBOX_NPC
	closemessage
	release
	end

CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltAfter::
	msgbox CeladonMansionRoofHouse_Text_PharmacistCurse, MSGBOX_NPC
	release
	end

CeladonMansionRoofHouse_Text_PharmacistIntro:
	.string "Ti racconto una storia terrificante…$"

CeladonMansionRoofHouse_Text_PharmacistNotNight:
	.string "Then again, it's not as scary\n"
	.string "while it's still light outside.\p"
	.string "Come back after sunset, OK?$"

CeladonMansionRoofHouse_Text_PharmacistStory:
	.string "C'era una volta un\n"
	.string "bambino a cui regalarono\l"
	.string "una BICICLETTA…\p"
	.string "Voleva provarla subito…\p"
	.string "Si divertiva tanto che\n"
	.string "non notò il tramonto…\p"
	.string "Pedalando verso casa nel\n"
	.string "buio totale, la bici di\l"
	.string "colpo rallentò!\p"
	.string "I pedali si fecero pesanti!\p"
	.string "Quando smetteva di pedalare,\n"
	.string "la bici scivolava all'indietro!\p"
	.string "Sembrava una bici maledetta\n"
	.string "che voleva trascinarlo\l"
	.string "nel baratro!\p"
	.string "…\p"
	.string "…\p"
	.string "SGRAAAL!\p"
	.string "Il bambino andava su per la\n"
	.string "PISTA CICLABILE!\p"
	.string "…\n"
	.string "Tum tum!\p"
	.string "Per avermi ascoltato con pazienza,\n"
	.string "prendi la MT82!$"

CeladonMansionRoofHouse_Text_PharmacistCurse:
	.string "La MT82 è SONNOFONIA.\p"
	.string "Fa usare una mossa a caso\n"
	.string "al tuo POKéMON addormentato.\p"
	.string "Ma buona notte dopo quel\n"
	.string "racconto terrificante!$"

