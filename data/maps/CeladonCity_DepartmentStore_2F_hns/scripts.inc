CeladonCity_DepartmentStore_2F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept2_EventScript_Pokefan::
	msgbox CeladonDeptStore2F_Text_PokefanM, MSGBOX_NPC
	end

CeladonDept2_EventScript_Youngster::
	msgbox CeladonDeptStore2F_Text_Youngster, MSGBOX_NPC
	end

CeladonDept2_EventScript_Directory::
	msgbox CeladonDeptStore2F_Text_Directory, MSGBOX_SIGN
	end

CeladonDeptStore2F_Text_PokefanM:
	.string "Sono un ALLENATORE da poco.\p"
	.string "Mio figlio mi ha convinto.\p"
	.string "Mi colpisce la scelta\n"
	.string "di oggetti utili.$"

CeladonDeptStore2F_Text_Youngster:
	.string "Mio papà fa fatica a\n"
	.string "imparare i nomi degli\l"
	.string "oggetti e come si usano…$"

CeladonDeptStore2F_Text_Directory:
	.string "Articoli top allenatori!\p"
	.string "2P: MERCATO$"

