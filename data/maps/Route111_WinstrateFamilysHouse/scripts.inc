Route111_WinstrateFamilysHouse_MapScripts::
	.byte 0

Route111_WinstrateFamilysHouse_EventScript_Victor::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTOR
	msgbox Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Victoria::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTORIA
	goto_if_set FLAG_RECEIVED_MACHO_BRACE, Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace
	msgbox Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace, MSGBOX_DEFAULT
	giveitem ITEM_MACHO_BRACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MACHO_BRACE
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace::
	msgbox Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vivi::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VIVI
	msgbox Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vicky::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICKY
	goto_if_set FLAG_TEMP_4, Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrong, MSGBOX_DEFAULT
	setflag FLAG_TEMP_4
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo::
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_0x8008, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou:
	.string "Sei il primo ALLENATORE che io abbia\n"
	.string "visto usare i POKéMON così bene.\p"
	.string "Ma sai, mio figlio è\n"
	.string "più forte di te.\p"
	.string "Ha pure affrontato la LEGA\n"
	.string "POKéMON, che tu sappia.$"

Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace:
	.string "Usiamo questo BRACCIALE FORTE per\n"
	.string "rafforzare i POKéMON\l"
	.string "in allenamento.\p"
	.string "Dato che ci hai battuti tutti,\n"
	.string "non so se ti serva, ma vorremmo\l"
	.string "regalarti il nostro BRACCIALE FORTE.$"

Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles:
	.string "Quando si tratta di lotte POKéMON,\n"
	.string "siamo piuttosto appassionati.$"

Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers:
	.string "La mamma è più forte del papà.\p"
	.string "Io sono più forte della mamma.\p"
	.string "E la nonna è più forte di me!\p"
	.string "Ma mio fratello grande è ancora\n"
	.string "più forte della nonna.$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrong:
	.string "Non c'è dubbio che tu sia forte.\p"
	.string "Ma se sfidassi mio nipote,\n"
	.string "finiresti a piangere dalla frustrazione.\p"
	.string "È più forte di qualsiasi ALLENATORE\n"
	.string "conosca la nostra famiglia.\p"
	.string "A quest'ora starà sfidando il\n"
	.string "CAMPIONE della LEGA POKéMON.\p"
	.string "Conoscendolo, potrebbe essere già\n"
	.string "il CAMPIONE!$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort:
	.string "Mio nipote starà sfidando il\n"
	.string "CAMPIONE della LEGA POKéMON.\p"
	.string "Conoscendolo, potrebbe essere già\n"
	.string "il CAMPIONE!$"

