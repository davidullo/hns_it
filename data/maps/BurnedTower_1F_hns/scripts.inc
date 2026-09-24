BurnedTower_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, BurnedTower_1F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BurnedTower_1F_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BurnedTower_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

BurnedTower_1F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

BurnedTower_1F_OnLoad::
	goto_if_ge VAR_ECRUTEAK_CITY_STATE, 4, BurnedTower_1F_MapScript_CreateHole
	end

BurnedTower_1F_MapScript_CreateHole::
	setmetatile 16, 12, 0x37E, FALSE
	end

BurnedTower_1F_OnFrame::
	map_script_2 VAR_ECRUTEAK_CITY_STATE, 1, BurnedTower_1F_EventScript_MeetEusine
	.2byte 0

BurnedTower_1F_EventScript_MeetEusine::
	lock
	playse SE_PIN
	applymovement LOCALID_BURNED_TOWER_EUSINE, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_BURNED_TOWER_EUSINE
	applymovement LOCALID_BURNED_TOWER_EUSINE, BurnedTower_Movement_Eusine1
	waitmovement 0
	msgbox BurnedTower_1FEusineIntroText, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BURNED_TOWER_EUSINE, BurnedTower_Movement_Eusine2
	waitmovement 0
	setvar VAR_ECRUTEAK_CITY_STATE, 2
	release
	end

BurnedTower_Movement_Eusine1:
	walk_down
	walk_down
	step_end

BurnedTower_Movement_Eusine2:
	walk_up
	walk_up
	step_end


BurnedTower_1FEusineIntroText:
	.string "EUGENIUS: Mi chiamo EUGENIUS.\p"
	.string "Sto cercando un POKéMON\n"
	.string "di nome SUICUNE.\p"
	.string "Tu chi sei...?\p"
	.string "{PLAYER}? Piacere!\p"
	.string "Ho sentito che SUICUNE\n"
	.string "sia nella TORRE ARSA, e sono\l"
	.string "venuto a vedere.\p"
	.string "Ma dove può stare esattamente?$"

BurnedTower_1F_EventScript_Item_HpUp::
	finditem ITEM_HP_UP
	end

BurnedTower_1F_EventScript_Item_Ether::
	finditem ITEM_ETHER
	end

BurnedTower_1F_EventScript_Eusine::
	lock
	faceplayer
	msgbox BurnedTower_1FEusineText, MSGBOX_DEFAULT
	closemessage
	release
	end

BurnedTower_1F_EventScript_Morty::
	lock
	faceplayer
	msgbox BurnedTower_1FMortyText, MSGBOX_DEFAULT
	closemessage
	release
	end

BurnedTower_1FEusineText:
	.string "EUGENIUS: Ho sentito che SUICUNE\n"
	.string "sia in questa TORRE ARSA, così\l"
	.string "sono venuto a vedere.\p"
	.string "Ma dove può stare esattamente?$"

BurnedTower_1FMortyText:
	.string "ANGELO: Il CAPOPALESTRA di\n"
	.string "FIORDORISO deve studiare i\l"
	.string "POKéMON leggendari, ossia\l"
	.string "SUICUNE, ENTEI e RAIKOU.\p"
	.string "EUGENIUS è qui, così ho\n"
	.string "deciso di indagare nella\l"
	.string "TORRE con lui.$"

BurnedTower_1F_EventScript_Silver::
	lock
	playse SE_PIN
	applymovement LOCALID_BURNED_TOWER_SILVER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_BURNED_TOWER_SILVER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	applymovement LOCALID_BURNED_TOWER_SILVER, Common_Movement_WalkLeft1
	waitmovement 0
	waitmovement 0
	msgbox BurnedTowerSilver_BeforeText, MSGBOX_DEFAULT
	call_if_eq VAR_STARTER_MON, 0, BurnedTower_1F_Silver_Battle_Cyndaquil
	call_if_eq VAR_STARTER_MON, 1, BurnedTower_1F_Silver_Battle_Totodile
	call_if_eq VAR_STARTER_MON, 2, BurnedTower_1F_Silver_Battle_Chikorita
	playbgm MUS_HG_RIVAL_EXIT, FALSE
	msgbox BurnedTowerSilver_AfterText1, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	playse SE_CLICK
	setmetatile 16, 12, 0x37E, FALSE
	special DrawWholeMapView
	waitse
	delay 60
	special SpawnCameraObject
	removeobject OBJ_EVENT_ID_PLAYER
	playse SE_FALL
	delay 60
	msgbox BurnedTowerSilver_AfterText2, MSGBOX_AUTOCLOSE
	waitmessage
	warphole MAP_BURNED_TOWER_B1F_HNS
	setvar VAR_ECRUTEAK_CITY_STATE, 3
	waitstate
	release
	end

BurnedTower_1F_Silver_Battle_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_3_HNS, BurnedTowerSilver_WinText
	return

BurnedTower_1F_Silver_Battle_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_3_HNS, BurnedTowerSilver_WinText
	return

BurnedTower_1F_Silver_Battle_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_3_HNS, BurnedTowerSilver_WinText
	return

BurnedTowerSilver_BeforeText:
	.string "..............................\p"
	.string "...Oh, sei tu.\p"
	.string "Cercavo dei POKéMON\n"
	.string "leggendari, a quanto dicono,\l"
	.string "vivano qui.\p"
	.string "Ma qui non c'è niente!\p"
	.string "Niente, dopo tutto lo sforzo\n"
	.string "di venire fin qui?\l"
	.string "No!\p"
	.string "È tutta colpa tua!$"

BurnedTowerSilver_WinText:
	.string "...Umph!\p"
	.string "Ho perso perché i miei\n"
	.string "POKéMON sono debolissimi.\p"
	.string "Patetico.$"

BurnedTowerSilver_AfterText1:
	.string "...Vabbè.\p"
	.string "Non sapresti mai catturare\n"
	.string "un POKéMON leggendario.$"

BurnedTowerSilver_LossText:
	.string "...Umph!\p"
	.string "Ecco perché odio lottare\n"
	.string "coi debolucci. Tempo perso.$"

BurnedTowerSilver_AfterText2:
	.string "Umph!\p"
	.string "Che ci fai caduto\n"
	.string "in una buca? Genio!\p"
	.string "Ben ti sta!$"

BurnedTower_1F_EventScript_Nard::
	trainerbattle_single TRAINER_NARD_HNS, BurnedTower_Text_NardSeen, BurnedTower_Text_NardBeaten
	msgbox BurnedTower_Text_NardAfter, MSGBOX_AUTOCLOSE
	end

BurnedTower_1F_EventScript_Richardo::
	trainerbattle_single TRAINER_RICHARDO_HNS, BurnedTower_Text_RichardoSeen, BurnedTower_Text_RichardoBeaten
	msgbox BurnedTower_Text_RichardoAfter, MSGBOX_AUTOCLOSE
	end

BurnedTower_Text_NardSeen:
	.string "Tranquillo!\p"
	.string "Noi sputafuoco conosciamo il\n"
	.string "vero potere del fuoco!$"
BurnedTower_Text_NardBeaten:
	.string "Grazie per la lotta accesa!$"
BurnedTower_Text_NardAfter:
	.string "Se questa torre è bruciata è\n"
	.string "perché colpita da un fulmine.\p"
	.string "Il fuoco che sputo è minuscolo\n"
	.string "in confronto...$"

BurnedTower_Text_RichardoSeen:
	.string "Mi sto esercitando a rubare in\n"
	.string "TORRE ARSA! Non provateci\l"
	.string "a casa!$"
BurnedTower_Text_RichardoBeaten:
	.string "Pfffffffffffffff.$"
BurnedTower_Text_RichardoAfter:
	.string "Forse il crimine non fa per\n"
	.string "me...$"
