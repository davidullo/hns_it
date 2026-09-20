GoldenrodCity_DepartmentStore_7F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_DepartmentStore_7F_OnTransition
	.byte 0

GoldenrodCity_DepartmentStore_7F_OnTransition:
	call_if_set FLAG_DAY_POKEMON, GoldenrodCity_DepartmentStore_7F_EventScript_SetNight
	call_if_unset FLAG_DAY_POKEMON, GoldenrodCity_DepartmentStore_7F_EventScript_SetDay
	end

GoldenrodCity_DepartmentStore_7F_EventScript_SetNight::
	setmaplayoutindex LAYOUT_GOLDENROD_CITY_DEPARTMENT_STORE_7FNIGHT_HNS
	return

GoldenrodCity_DepartmentStore_7F_EventScript_SetDay::
	setmaplayoutindex LAYOUT_GOLDENROD_CITY_DEPARTMENT_STORE_7F_HNS
	return


GoldenrodDeptStore7_EventScript_PokefanF::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofPokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofPokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_Twin::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofTwin, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_Nerd::
	lock
	msgbox GoldenrodDeptStore_Text_RoofSuperNerdOhWow, MSGBOX_DEFAULT
	closemessage
	PLAYSE SE_PIN
	applymovement LOCALID_GOLDENROD_ROOF_NERD, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GOLDENROD_ROOF_NERD
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofSuperNerdQuitBotheringMe, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_GOLDENROD_ROOF_NERD, DIR_SOUTH
	release
	end

GoldenrodDeptStore7_EventScript_Teacher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofTeacher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_Bugcatcher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofBugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_RoofPokefanF:
    .string "Uff, sono stanca.\p"
    .string "A volte salgo sul tetto\n"
    .string "per riposarmi dallo shopping.$"

GoldenrodDeptStore_Text_RoofFisher:
    .string "Come? Chi dice che un adulto non\n"
    .string "possa farlo?\p"
    .string "Tornero' ogni giorno per\n"
    .string "collezionare tutti i peluche!$"

GoldenrodDeptStore_Text_RoofTwin:
    .string "Qui fanno saldi ogni\n"
    .string "tanto.$"

GoldenrodDeptStore_Text_RoofSuperNerdOhWow:
    .string "Oh, wow!$"

GoldenrodDeptStore_Text_RoofSuperNerdQuitBotheringMe:
    .string "La smetti di seccarmi?$"

GoldenrodDeptStore_Text_RoofPokefanM:
    .string "C'è una cosa che voglio davvero,\n"
    .string "ma non ho abbastanza soldi…\p"
    .string "Magari vendo le BACche che ho\n"
    .string "raccolto…$"

GoldenrodDeptStore_Text_RoofTeacher:
    .string "Oh, e' tutto cosi' economico!\p"
    .string "Ho comprato tanto, lo ZAINO scoppia!$"

GoldenrodDeptStore_Text_RoofBugCatcher:
    .string "I miei POKéMON si paralizzano o\n"
    .string "avvelenano sempre sul piu' bello…\p"
    .string "Quindi compro una CURA TOTALE.\p"
    .string "Chissa' se ce n'e' ancora?$"
