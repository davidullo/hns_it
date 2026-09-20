CeladonCity_DepartmentStore_RoofDay_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_DepartmentStore_RoofDay_OnTransition
	.byte 0

CeladonCity_DepartmentStore_RoofDay_OnTransition:
	call_if_set FLAG_DAY_POKEMON, CeladonCity_DepartmentStore_RoofDay_EventScript_SetNight
	call_if_unset FLAG_DAY_POKEMON, CeladonCity_DepartmentStore_RoofDay_EventScript_SetDay
	end

CeladonCity_DepartmentStore_RoofDay_EventScript_SetNight::
	setmaplayoutindex LAYOUT_CELADON_CITY_DEPARTMENT_STORE_ROOF_NIGHT_HNS
	return

CeladonCity_DepartmentStore_RoofDay_EventScript_SetDay::
	setmaplayoutindex LAYOUT_CELADON_CITY_DEPARTMENT_STORE_ROOF_DAY_HNS
	return

CeladonDept6_EventScript_Nerd::
	msgbox CeladonDeptStore6F_Text_SuperNerd, MSGBOX_NPC
	end
CeladonDept6_EventScript_Youngster::
	msgbox CeladonDeptStore6F_Text_Youngster, MSGBOX_NPC
	end
CeladonDept6_EventScript_Directory::
	msgbox CeladonDeptStore6F_Text_Directory, MSGBOX_SIGN
	end


CeladonDeptStore6F_Text_Vending:
	.string "Un distributore! Ecco il menù.$"

CeladonDeptStore6F_Text_Clang:
	.string "Clang!\p"
	.string "{STRING} è uscito.$"

CeladonDeptStore6F_Text_VendingNoMoney:
	.string "Ops, soldi insufficienti…$"

CeladonDeptStore6F_Text_VendingNoSpace:
	.string "Non c'è più spazio…$"

CeladonDeptStore6F_Text_SuperNerd:
	.string "Un distributore con premi\n"
	.string "a rotelle…\p"
	.string "Non se ne vedono più.$"

CeladonDeptStore6F_Text_Youngster:
	.string "Uffa! Non ci sono giochi!\p"
	.string "Volevo giocare…$"

CeladonDeptStore6F_Text_Directory:
	.string "6F: DISTRIBUTORI DELLA\n"
	.string "TERRAZZA$"
