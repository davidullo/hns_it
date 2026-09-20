CeladonCity_DepartmentStore_3F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept3_EventScript_Youngster::
	msgbox CeladonDeptStore3F_Text_Youngster, MSGBOX_NPC
	end
CeladonDept3_EventScript_Gbakid1::
	msgbox CeladonDeptStore3F_Text_GameboyKid1, MSGBOX_NPC
	end
CeladonDept3_EventScript_Gbakid2::
	msgbox CeladonDeptStore3F_Text_GameboyKid2, MSGBOX_NPC
	end
CeladonDept3_EventScript_SuperNerd::
	msgbox CeladonDeptStore3F_Text_SuperNerd, MSGBOX_NPC
	end
CeladonDept3_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeladonDept3_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
CeladonDept3_Pokemart:
	.2byte ITEM_TM_SAFEGUARD
	.2byte ITEM_TM_CAPTIVATE
	.2byte ITEM_TM_STEALTH_ROCK
	.2byte ITEM_TM_BRINE
	.2byte ITEM_TM_AVALANCHE
	.2byte ITEM_TM_DARK_PULSE
	.2byte ITEM_TM_GYRO_BALL
	.2byte ITEM_TM_DREAM_EATER
	.2byte ITEM_TM_GIGA_IMPACT
	.2byte ITEM_TM_ENDURE
	pokemartlistend

CeladonDept3_EventScript_Directory::
	msgbox CeladonDeptStore3F_Text_Directory, MSGBOX_SIGN
	end

CeladonDeptStore3F_Text_Youngster:
	.string "Non so su quale POKéMON\n"
	.string "usare questa MT…$"

CeladonDeptStore3F_Text_GameboyKid1:
	.string "Accidenti! Ho scambiato un POKéMON\n"
	.string "senza togliere l'UPGRADE.$"

CeladonDeptStore3F_Text_GameboyKid2:
	.string "Evvai! Finalmente avrò un\n"
	.string "PORYGON!\p"
	.string "Non sono bravo alle slot,\n"
	.string "quindi niente gettoni…\p"
	.string "…Eh?\p"
	.string "Il PORYGON scambiato si è\n"
	.string "trasformato!$"

CeladonDeptStore3F_Text_SuperNerd:
	.string "Il NEGOZIO MT vende mosse rare.$"

CeladonDeptStore3F_Text_Directory:
	.string "3F: MT\p"
	.string "Rendi più forti i POKéMON!$"

