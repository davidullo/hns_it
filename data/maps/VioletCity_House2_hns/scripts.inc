VioletCity_House2_hns_MapScripts::
	.byte 0

VioletCity_House2_EventScript_Lass::
	lock
	faceplayer
	msgbox VioletCity_NicknameHouse_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_House2_EventScript_Teacher::
	lock
	faceplayer
	msgbox VioletCity_NicknameHouse_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_House2_EventScript_Pidgey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEY, CRY_MODE_NORMAL
	msgbox VioletCity_NicknameHouse_Text_Bird, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VioletCity_NicknameHouse_Text_Teacher:
	.string "Usa i nomi delle cose\n"
	.string "che le piace mangiare.\p"
	.string "Per i soprannomi che dà ai\n"
	.string "suoi POKéMON, intendo.$"

VioletCity_NicknameHouse_Text_Lass:
	.string "Ho chiamato il mio PIDGEY FRAGOLA!$"

VioletCity_NicknameHouse_Text_Bird:
	.string "FRAGOLA: Pijji!$"
