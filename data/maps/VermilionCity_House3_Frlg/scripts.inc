VermilionCity_House3_Frlg_MapScripts::
	.byte 0

VermilionCity_House3_EventScript_Boy::
	msgbox VermilionCity_House3_Text_PidgeyFlyLetterToSaffron, MSGBOX_NPC
	end

VermilionCity_House3_EventScript_Lass::
	msgbox VermilionCity_House3_Text_SendMyPidgeyToUnionRoom, MSGBOX_NPC
	end

VermilionCity_House3_EventScript_Pidgey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEY, CRY_MODE_NORMAL
	msgbox VermilionCity_House3_Text_Pidgey
	waitmoncry
	release
	end

VermilionCity_House3_EventScript_Letter::
	msgbox VermilionCity_House3_Text_DearPippiLetter, MSGBOX_SIGN
	end

VermilionCity_House3_Text_PidgeyFlyLetterToSaffron::
	.string "Sto facendo volare il mio PIDGEY con\n"
	.string "una lettera per ZAFFERANOPOLI.$"

VermilionCity_House3_Text_Pidgey::
	.string "PIDGEY: Kurukkoo!$"

VermilionCity_House3_Text_DearPippiLetter::
	.string "Cara PIPPI,\n"
	.string "spero di vederti presto.\p"
	.string "Ho sentito che ZAFFERANOPOLI ha\n"
	.string "problemi con il TEAM ROCKET.\p"
	.string "ARANCIOPOLI sembra al sicuro.$"

VermilionCity_House3_Text_SendMyPidgeyToUnionRoom::
	.string "Voglio scambiare MESSAGGI con\n"
	.string "ogni tipo di persona.\p"
	.string "Mando il mio PIDGEY a una SALA\n"
	.string "UNION per scambiare MESSAGGI.$"

