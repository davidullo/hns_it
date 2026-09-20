Gate_IlexForest_Route34_hns_MapScripts::
	.byte 0

Route34IlexForestGate_EventScript_Lass::
	lock
	faceplayer
	msgbox Route34IlexForestGate_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route34IlexForestGate_EventScript_Butterfree::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BUTTERFREE, CRY_MODE_NORMAL
	msgbox Route34IlexForestGate_Text_Butterfree, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route34IlexForestGate_Text_Lass:
	.string "Hai visto il santuario dedi\n"
	.string "cato al protettore?\p"
	.string "Veglia sulla FORESTA da\n"
	.string "ogni tempo.\p"
	.string "Penso che sia un POKéMON\n"
	.string "di tipo Erba.$"

Route34IlexForestGate_Text_Butterfree:
	.string "BUTTERFREE: Fruu!$"
