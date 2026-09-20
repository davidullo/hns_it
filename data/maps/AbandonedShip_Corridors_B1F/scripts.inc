AbandonedShip_Corridors_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_Corridors_B1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, AbandonedShip_Corridors_B1F_OnLoad
	.byte 0

AbandonedShip_Corridors_B1F_OnResume:
	setdivewarp MAP_ABANDONED_SHIP_UNDERWATER1, 5, 4
	end

AbandonedShip_Corridors_B1F_OnLoad:
	call_if_unset FLAG_USED_STORAGE_KEY, AbandonedShip_Corridors_B1F_EventScript_LockStorageRoom
	call_if_set FLAG_USED_STORAGE_KEY, AbandonedShip_Corridors_B1F_EventScript_UnlockStorageRoom
	end

AbandonedShip_Corridors_B1F_EventScript_LockStorageRoom::
	setmetatile 11, 4, METATILE_InsideShip_IntactDoor_Bottom_Locked, TRUE
	return

AbandonedShip_Corridors_B1F_EventScript_UnlockStorageRoom::
	setmetatile 11, 4, METATILE_InsideShip_IntactDoor_Bottom_Unlocked, TRUE
	return

AbandonedShip_Corridors_B1F_EventScript_TuberM::
	msgbox AbandonedShip_Corridors_B1F_Text_YayItsAShip, MSGBOX_NPC
	end

AbandonedShip_Corridors_B1F_EventScript_StorageRoomDoor::
	lockall
	goto_if_set FLAG_USED_STORAGE_KEY, AbandonedShip_Corridors_B1F_EventScript_DoorIsUnlocked
	checkitem ITEM_STORAGE_KEY
	goto_if_eq VAR_RESULT, FALSE, AbandonedShip_Corridors_B1F_EventScript_DoorIsLocked
	msgbox AbandonedShip_Corridors_B1F_Text_InsertedStorageKey, MSGBOX_DEFAULT
	playse SE_PIN
	removeitem ITEM_STORAGE_KEY
	setflag FLAG_USED_STORAGE_KEY
	call AbandonedShip_Corridors_B1F_EventScript_UnlockStorageRoom
	special DrawWholeMapView
	releaseall
	end

AbandonedShip_Corridors_B1F_EventScript_DoorIsLocked::
	msgbox AbandonedShip_Corridors_B1F_Text_DoorIsLocked, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_Corridors_B1F_EventScript_DoorIsUnlocked::
	msgbox AbandonedShip_Text_TheDoorIsOpen, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_Corridors_B1F_EventScript_Duncan::
	trainerbattle_single TRAINER_DUNCAN, AbandonedShip_Corridors_B1F_Text_DuncanIntro, AbandonedShip_Corridors_B1F_Text_DuncanDefeat
	msgbox AbandonedShip_Corridors_B1F_Text_DuncanPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_B1F_Text_DuncanIntro:
	.string "Noi MARINAI in mare portiamo\n"
	.string "sempre i nostri POKéMON.\l"
	.string "Ti va una battaglia rapida?$"

AbandonedShip_Corridors_B1F_Text_DuncanDefeat:
	.string "Ops, sono affondato!$"

AbandonedShip_Corridors_B1F_Text_DuncanPostBattle:
	.string "La chiglia è affondata in\n"
	.string "profondità.\p"
	.string "Se un POKéMON sapesse immergersi,\n"
	.string "potremmo fare passi avanti…$"

AbandonedShip_Corridors_B1F_Text_YayItsAShip:
	.string "Evviva!\n"
	.string "È una nave!$"

AbandonedShip_Corridors_B1F_Text_DoorIsLocked:
	.string "La porta è chiusa a chiave.\p"
	.string "Su di essa c'è scritto “MAGAZZINO”.$"

AbandonedShip_Corridors_B1F_Text_InsertedStorageKey:
	.string "{PLAYER} ha inserito e girato la\n"
	.string "CHIAVE MAGAZZINO.\p"
	.string "La CHIAVE è rimasta incastrata,\n"
	.string "ma la porta si è aperta.$"

AbandonedShip_Text_TheDoorIsOpen:
	.string "La porta è aperta.$"

