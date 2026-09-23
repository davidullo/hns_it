GoldenrodCity_DepartmentStore_4F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore4_EventScript_Cooltrainer::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FCooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_BugCatcher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FBugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_GBAKid::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FGameboyKid, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_4FCooltrainerM:
    .string "Adoro i POKéMON forti.\p"
    .string "Gli do PROTEINA, così\n"
    .string "che ATTACCO!$"

GoldenrodDeptStore_Text_4FBugCatcher:
    .string "Il FERRO aggiunge\n"
    .string "DIFESA ai POKéMON.$"

GoldenrodDeptStore_Text_4FGameboyKid:
    .string "Si vocifera che certi\n"
    .string "POKéMON evolvano solo\l"
    .string "se scambiati col Game Link\l"
    .string "cavo.\p"
    .string "Pfft...\p"
    .string "Che assurdità.\p"
    .string "Conosco alcuni dei\n"
    .string "POKéMON:\l"
    .string "MACHOKE, KADABRA, HAUNTER e,\l"
    .string "ehm, GRAVELER,\l"
    .string "ma si evolvono tutti\l"
    .string "salendo.$"

GoldenrodDeptStore4_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart GoldenrodDeptStore4_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
GoldenrodDeptStore4_Pokemart:
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	pokemartlistend

GoldenrodDeptStore_Text_4FDirectory:
    .string "Rinforziamo i POKéMON!\p"
    .string "4P SCATOLA MEDICINE$"
