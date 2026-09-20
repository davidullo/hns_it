GoldenrodCity_DepartmentStore_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore1_EventScript_Receptionist::
	lock
	faceplayer
	msgbox GoldenrodDeptStor1_Text_Receptionist, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_Gentleman::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_PokefanF::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_PokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_BugCatcher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore1_EventScript_Directory::
	lock
	msgbox GoldenrodDeptStore1_Text_Directory, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodDeptStor1_Text_Receptionist:
    .string "Benvenuto al GRANDE MAGAZZINO.$"

GoldenrodDeptStore1_Text_Gentleman:
    .string "Il GRANDE MAGAZZINO ha una\n"
    .string "buona scelta.\p"
    .string "Ma alcuni oggetti si trovano solo\n"
    .string "come premi del CASINÒ.$"

GoldenrodDeptStore1_Text_PokefanF:
    .string "Non vedo l'ora di far spese oggi!$"

GoldenrodDeptStore1_Text_BugCatcher:
    .string "Mamma sa cacciare gli affari.\p"
    .string "Compra sempre la roba a\n"
    .string "prezzi bassi.$"

GoldenrodDeptStore1_Text_Directory:
    .string "1P BANCO SERVIZI\n"
	.string "SEI QUI.\p"
    .string "2P MERCATO ALLENATORI\p"
    .string "3P COLLEZIONE LOTTA\p"
    .string "4P SCATOLA MEDICINE\p"
    .string "5P ANGOLO MT\p"
    .string "6P PIAZZA TRANQUILLA\p"
    .string "TERRAZZA SENTINELLA$"
