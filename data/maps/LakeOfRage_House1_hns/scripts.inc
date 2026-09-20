LakeOfRage_House1_hns_MapScripts::
	.byte 0

LakeOfRage_House1_EventScript_HiddenPowerGuy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HIDDEN_POWER, LakeOfRage_House1_EventScript_HiddenPowerGuyAfter
	msgbox HiddenPowerGuy_Text_Intro, MSGBOX_DEFAULT
	giveitem ITEM_TM_HIDDEN_POWER
	msgbox HiddenPowerGuy_Text_Explanation, MSGBOX_DEFAULT
	setflag FLAG_GOT_HIDDEN_POWER
	closemessage
	release
	end

LakeOfRage_House1_EventScript_HiddenPowerGuyAfter::
	msgbox HiddenPowerGuy_Text_Meditating, MSGBOX_DEFAULT
	closemessage
	release
	end

HiddenPowerGuy_Text_Intro:
    .string "…Hai viaggiato molto…\p"
    .string "Qui ho meditato. Dentro di me\n"
    .string "si è risvegliato un nuovo potere.\p"
    .string "Ti dono il mio potere per i tuoi\n"
    .string "POKéMON. Prendi, ragazzo.$"

HiddenPowerGuy_Text_Explanation:
    .string "Lo vedi? È FORZA NASCOSTA!\p"
    .string "Sprigiona la forza dei POKéMON\n"
    .string "per attaccare.\p"
    .string "Ricorda: tipo e potenza\n"
    .string "dipendono dal POKéMON che la usa.$"

HiddenPowerGuy_Text_Meditating:
    .string "Sto meditando…$"
