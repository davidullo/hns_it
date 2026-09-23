CeladonCity_DepartmentStore_1F_Frlg_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_1F_EventScript_Receptionist::
	msgbox CeladonCity_DepartmentStore_1F_Text_WelcomeToDeptStore, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_1F_EventScript_LayoutSign::
	msgbox CeladonCity_DepartmentStore_1F_Text_FloorDescriptions, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_1F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_1F_Text_ServiceCounter, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_1F_Text_WelcomeToDeptStore::
	.string "Ciao!\n"
	.string "Benvenuto al GR. MAGAZZINI\ndi AZZURROPOLI.\p"
	.string "Il pannello a destra descrive\n"
	.string "la piantina del negozio.$"

CeladonCity_DepartmentStore_1F_Text_FloorDescriptions::
	.string "1F: BANCO ASSISTENZA\p"
	.string "2F: MERCATO DELL'ALLENATORE\p"
	.string "3F: NEGOZIO DI VIDEOGIOCHI\p"
	.string "4F: REGALI PER SAGGI\p"
	.string "5F: FARMACIA\p"
	.string "PIAZZALE TERRAZZA: DISTRIBUTORI$"

CeladonCity_DepartmentStore_1F_Text_ServiceCounter::
	.string "1F: BANCO ASSISTENZA$"

