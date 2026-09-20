FiveIsland_Meadow_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, FiveIsland_Meadow_OnLoad
	.byte 0

FiveIsland_Meadow_OnLoad::
	call_if_set FLAG_UNLOCKED_ROCKET_WAREHOUSE, FiveIsland_Meadow_EventScript_SetWarehouseDoorUnlocked
	end

FiveIsland_Meadow_EventScript_WarehouseDoor::
	lockall
	goto_if_set FLAG_UNLOCKED_ROCKET_WAREHOUSE, FiveIsland_Meadow_EventScript_WarehouseDoorAlreadyOpen
	goto_if_set FLAG_LEARNED_YES_NAH_CHANSEY, FiveIsland_Meadow_EventScript_OpenWarehouseDoor
	msgbox FiveIsland_Meadow_Text_EnteredPasswordAnotherNeeded
	releaseall
	end

FiveIsland_Meadow_EventScript_OpenWarehouseDoor::
	setflag FLAG_UNLOCKED_ROCKET_WAREHOUSE
	message FiveIsland_Meadow_Text_EnteredPasswordDoorOpened
	waitmessage
	delay 60
	call FiveIsland_Meadow_EventScript_SetWarehouseDoorUnlocked
	special DrawWholeMapView
	playse SE_PIN
	waitse
	releaseall
	end

FiveIsland_Meadow_EventScript_WarehouseDoorAlreadyOpen::
	msgbox FiveIsland_Meadow_Text_WarehouseDoorAlreadyOpen
	releaseall
	end

FiveIsland_Meadow_EventScript_SetWarehouseDoorUnlocked::
	setmetatile 12, 21, METATILE_SeviiIslands45_RocketWarehouseDoor_Unlocked, 1
	return

FiveIsland_Meadow_EventScript_Rocket1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_49, FiveIsland_Meadow_Text_Rocket1Intro, FiveIsland_Meadow_Text_Rocket1Defeat
	msgbox FiveIsland_Meadow_Text_Rocket1PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_Meadow_EventScript_Rocket2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_50, FiveIsland_Meadow_Text_Rocket2Intro, FiveIsland_Meadow_Text_Rocket2Defeat
	msgbox FiveIsland_Meadow_Text_Rocket2PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_Meadow_EventScript_Rocket3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_51, FiveIsland_Meadow_Text_Rocket3Intro, FiveIsland_Meadow_Text_Rocket3Defeat
	msgbox FiveIsland_Meadow_Text_Rocket3PostBattle, MSGBOX_AUTOCLOSE
	end

@ Unused
FiveIsland_Meadow_Text_DoorNeedsTwoPasswords::
	.string "とびらを　あけるには\n"
	.string "パスワードが　2つ　いるようだ$"

FiveIsland_Meadow_Text_EnteredPasswordAnotherNeeded::
	.string "{PLAYER}: password ok.\p"
	.string "“GOLDEEN vuole log.”\p"
	.string "… …  … …  … …\p"
	.string "Serve un'altra password per\n"
	.string "aprire la porta…$"

FiveIsland_Meadow_Text_EnteredPasswordDoorOpened::
	.string "{PLAYER}: due password ok.\p"
	.string "“GOLDEEN vuole log.”\n"
	.string "“Sì, no, CHANSEY.”\p"
	.string "… …  … …  … …\p"
	.string "Porta del MAGAZZINO aperta!$"

FiveIsland_Meadow_Text_WarehouseDoorAlreadyOpen::
	.string "La porta del MAGAZZINO è già\n"
	.string "aperta.$"

FiveIsland_Meadow_Text_Rocket1Intro::
	.string "Quest'area è vietata!\n"
	.string "Via, via!$"

FiveIsland_Meadow_Text_Rocket1Defeat::
	.string "Dici sul serio?$"

FiveIsland_Meadow_Text_Rocket1PostBattle::
	.string "Qui non hai niente da fare!\n"
	.string "A casa!$"

FiveIsland_Meadow_Text_Rocket2Intro::
	.string "Più avanti c'è solo il nostro\n"
	.string "MAGAZZINO.\p"
	.string "Cosa ti porta qui?$"

FiveIsland_Meadow_Text_Rocket2Defeat::
	.string "Non doveva andare così…$"

FiveIsland_Meadow_Text_Rocket2PostBattle::
	.string "Vuoi sapere cosa c'è in questo\n"
	.string "MAGAZZINO?\p"
	.string "Meglio che non lo sappia.\n"
	.string "Per il tuo bene, intendo.$"

FiveIsland_Meadow_Text_Rocket3Intro::
	.string "Perderesti tempo anche se\n"
	.string "mi superassi.$"

FiveIsland_Meadow_Text_Rocket3Defeat::
	.string "Oh, mi fai infuriare!$"

FiveIsland_Meadow_Text_Rocket3PostBattle::
	.string "Non entrerai comunque senza\n"
	.string "le password.$"

