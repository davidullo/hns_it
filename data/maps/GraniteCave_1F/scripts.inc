GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.string "Ehi, tu.\n"
	.string "Più avanti è buio pesto.\l"
	.string "Esplorare sarà dura.\p"
	.string "Quel tipo di prima…\n"
	.string "STEVEN, credo.\p"
	.string "Lui sapeva usare BALENO, quindi per lui\n"
	.string "niente problema, ma…\p"
	.string "Beh, per noi MONTANARI aiutare chi\n"
	.string "incontriamo è il nostro motto.\p"
	.string "Ecco, prendi questo.$"

GraniteCave_1F_Text_ExplainFlash:
	.string "Insegna BALENO a un POKéMON\n"
	.string "e usalo.\p"
	.string "Illumina persino il buio più fitto\n"
	.string "delle grotte.\p"
	.string "Ma per usarlo serve una MEDAGLIA\n"
	.string "della PALESTRA di PORTOVECCHIO.$"

