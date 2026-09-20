SaffronCity_House_Frlg_MapScripts::
	.byte 0

SaffronCity_House_EventScript_Lass::
	msgbox SaffronCity_House_Text_DontLookAtMyLetter, MSGBOX_NPC
	end

SaffronCity_House_EventScript_Youngster::
	msgbox SaffronCity_House_Text_GettingCopycatPokeDoll, MSGBOX_NPC
	end

SaffronCity_House_EventScript_Pidgey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEY, CRY_MODE_NORMAL
	msgbox SaffronCity_House_Text_Pidgey
	waitmoncry
	release
	end

SaffronCity_House_EventScript_Letter::
	msgbox SaffronCity_House_Text_ExplainPPUp, MSGBOX_SIGN
	end

SaffronCity_House_Text_DontLookAtMyLetter::
	.string "…Grazie per aver scritto.\n"
	.string "Spero di vederti presto!\p"
	.string "…Ehi!\n"
	.string "Non leggere la mia LETTERA!$"

SaffronCity_House_Text_Pidgey::
	.string "PIDGEY: Kurukkoo!$"

SaffronCity_House_Text_GettingCopycatPokeDoll::
	.string "La COPIONE è carina!\n"
	.string "Le prendo un POKé DOLL.$"

SaffronCity_House_Text_ExplainPPUp::
	.string "Mi hanno regalato un PP UP.\p"
	.string "Serve ad aumentare i PP di\n"
	.string "una mossa di un POKéMON.\p"
	.string "Dovrei usarlo su una mossa forte\n"
	.string "con pochi PP.$"

