CeladonCity_DepartmentStore_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept1_EventScript_Receptionsit::
    msgbox CeladonDeptStore_Text_1FReceptionist, MSGBOX_NPC
    end

CeladonDept1_EventScript_Gent::
    msgbox CeladonDeptStore_Text_1FGentleman, MSGBOX_NPC
    end

CeladonDept1_EventScript_Teacher::
    msgbox CeladonDeptStore_Text_1FTeacher, MSGBOX_NPC
    end

CeladonDept1_EventScript_Directory::
    msgbox CeladonDeptStore_Text_1FDirectory, MSGBOX_SIGN
    end

CeladonDeptStore_Text_1FReceptionist:
    .string "Ciao! Benvenuto al GR.\n"
    .string "MAGAZZINI AZZURROPOLI!\p"
    .string "L'insegna è sul muro.$"

CeladonDeptStore_Text_1FGentleman:
    .string "Questo GR. MAGAZZINI è della\n"
    .string "stessa catena di quello di\p"
    .string "FIORDOROPOLI, ristrutturati\n"
    .string "nello stesso periodo.$"

CeladonDeptStore_Text_1FTeacher:
    .string "È la mia prima volta qui.\p"
    .string "È enorme…\p"
    .string "Ho paura di perdermi.$"

CeladonDeptStore_Text_1FDirectory:
    .string "1F: BANCO ASSISTENZA\p"
    .string "2F: MERCATO DELL'ALLENATORE\p"
    .string "3F: NEGOZIO MT\p"
    .string "4F: REGALI PER SAGGI\p"
    .string "5F: FARMACIA\p"
    .string "6F: PIAZZALE TERRAZZA$"
