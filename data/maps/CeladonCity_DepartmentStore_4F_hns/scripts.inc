CeladonCity_DepartmentStore_4F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept_EventScript_Supernerd::
	msgbox CeladonDeptStore4F_Text_SuperNerd, MSGBOX_NPC
	end
CeladonDept_EventScript_Youngster::
	msgbox CeladonDeptStore4F_Text_Youngster, MSGBOX_NPC
	end
CeladonDept_EventScript_Directory::
	msgbox CeladonDeptStore4F_Text_Directory, MSGBOX_NPC
	end

CeladonDeptStore4F_Text_SuperNerd:
	.string "Volevo comprare SURF MAIL per\n"
	.string "la mia ragazza.\p"
	.string "Eh? È esaurito?$"

CeladonDeptStore4F_Text_Youngster:
	.string "Qui si può comprare\n"
	.string "la LETTERA BELLA.\p"
	.string "Almeno, si poteva. Dicono che\n"
	.string "sia esaurita.$"

CeladonDeptStore4F_Text_Directory:
	.string "Esprimiti con i regali!\p"
	.string "4F: DAL SAGGIO$"
