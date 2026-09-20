VictoryRoad_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_OnTransition
	.byte 0

VictoryRoad_1F_OnTransition:
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 1, VictoryRoad_1F_EventScript_SetEntranceWallyPos1
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 2, VictoryRoad_1F_EventScript_SetEntranceWallyPos2
	end

VictoryRoad_1F_EventScript_SetEntranceWallyPos1::
	setobjectxyperm LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, 2, 24
	setobjectmovementtype LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_SetEntranceWallyPos2::
	setobjectxyperm LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, 3, 24
	setobjectmovementtype LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_WallyBattleTrigger1::
	lockall
	setvar VAR_0x8008, 1
	addobject LOCALID_VICTORY_ROAD_ENTRANCE_WALLY
	applymovement LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, VictoryRoad_1F_Movement_WallyApproachPlayer1
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyBattleTrigger2::
	lockall
	setvar VAR_0x8008, 2
	addobject LOCALID_VICTORY_ROAD_ENTRANCE_WALLY
	applymovement LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, VictoryRoad_1F_Movement_WallyApproachPlayer2
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyEntranceBattle::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_VR_1, VictoryRoad_1F_Text_WallyEntranceDefeat
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
	copyobjectxytoperm LOCALID_VICTORY_ROAD_ENTRANCE_WALLY
	setflag FLAG_DEFEATED_WALLY_VICTORY_ROAD
	copyvar VAR_VICTORY_ROAD_1F_STATE, VAR_0x8008
	releaseall
	end

VictoryRoad_1F_Movement_WallyApproachPlayer1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

VictoryRoad_1F_Movement_WallyApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

@ This Wally appears near the entrance once his battle is triggered and remains there until the Hall of Fame is entered
VictoryRoad_1F_EventScript_EntranceWally::
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_NPC
	end

@ This Wally appears and remains at the exit after the Hall of Fame is entered
VictoryRoad_1F_EventScript_ExitWally::
	trainerbattle_single TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, VictoryRoad_1F_EventScript_RematchWally
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_RematchWally::
	trainerbattle_rematch TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Edgar::
	trainerbattle_single TRAINER_EDGAR, VictoryRoad_1F_Text_EdgarIntro, VictoryRoad_1F_Text_EdgarDefeat
	msgbox VictoryRoad_1F_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Albert::
	trainerbattle_single TRAINER_ALBERT, VictoryRoad_1F_Text_AlbertIntro, VictoryRoad_1F_Text_AlbertDefeat
	msgbox VictoryRoad_1F_Text_AlbertPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Hope::
	trainerbattle_single TRAINER_HOPE, VictoryRoad_1F_Text_HopeIntro, VictoryRoad_1F_Text_HopeDefeat
	msgbox VictoryRoad_1F_Text_HopePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Quincy::
	trainerbattle_single TRAINER_QUINCY, VictoryRoad_1F_Text_QuincyIntro, VictoryRoad_1F_Text_QuincyDefeat
	msgbox VictoryRoad_1F_Text_QuincyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Katelynn::
	trainerbattle_single TRAINER_KATELYNN, VictoryRoad_1F_Text_KatelynnIntro, VictoryRoad_1F_Text_KatelynnDefeat
	msgbox VictoryRoad_1F_Text_KatelynnPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore:
	.string "WALLY: Ciao! {PLAYER}!\p"
	.string "Scommetto che ti sorprende vedermi qui!\p"
	.string "Sono arrivato fin qua, e lo devo\n"
	.string "tutto a te!\p"
	.string "{PLAYER}, perdere contro di te\n"
	.string "mi ha reso più forte!\p"
	.string "Ma non perderò mai più!\p"
	.string "Vincerò! Per i POKéMON che mi\n"
	.string "hanno dato coraggio e forza!\p"
	.string "Bene… Arrivo!$"

VictoryRoad_1F_Text_WallyEntranceDefeat:
	.string "Wow!\n"
	.string "{PLAYER}, sei forte davvero!$"

VictoryRoad_1F_Text_WallyPostEntranceBattle:
	.string "WALLY: Oggi non ti ho battuto,\n"
	.string "{PLAYER}, ma un giorno ti\l"
	.string "raggiungerò!$"

VictoryRoad_1F_Text_WallyIntro:
	.string "WALLY: Ciao! {PLAYER}!\p"
	.string "Sono più forte dall'ultima\n"
	.string "volta! Volevo mostrartelo, {PLAYER}!\p"
	.string "Okay… Arrivo!$"

VictoryRoad_1F_Text_WallyDefeat:
	.string "Wow!\n"
	.string "{PLAYER}, sei forte davvero!$"

VictoryRoad_1F_Text_WallyPostBattle:
	.string "WALLY: Stavolta non ti ho battuto,\n"
	.string "neanche… Ma un giorno, {PLAYER},\l"
	.string "ti raggiungerò…\p"
	.string "E sfiderò la POKéMON LEAGUE!$"

VictoryRoad_1F_Text_EdgarIntro:
	.string "Sono arrivato fin qui un paio di volte,\n"
	.string "ma l'ultimo tratto è così lungo…$"

VictoryRoad_1F_Text_EdgarDefeat:
	.string "Il mio sogno finisce di nuovo qui…$"

VictoryRoad_1F_Text_EdgarPostBattle:
	.string "Sei arrivato fin qui. Tieni il\n"
	.string "ritmo e diventa il\l"
	.string "CAMPIONE! Se qualcuno può, sei tu!$"

VictoryRoad_1F_Text_AlbertIntro:
	.string "Non sono arrivato fin qui per perdere ora.\n"
	.string "Quella possibilità non esiste!$"

VictoryRoad_1F_Text_AlbertDefeat:
	.string "Impossibile…\n"
	.string "Ho perso?$"

VictoryRoad_1F_Text_AlbertPostBattle:
	.string "Ho perso qui…\p"
	.string "Significa che non ho le qualità\n"
	.string "per diventare CAMPIONE…$"

VictoryRoad_1F_Text_HopeIntro:
	.string "Questa strada infinita e dura\n"
	.string "merita il nome di VITTORIA.$"

VictoryRoad_1F_Text_HopeDefeat:
	.string "Il tuo stile di lotta è fantastico…$"

VictoryRoad_1F_Text_HopePostBattle:
	.string "Sembri avere il potenziale per\n"
	.string "diventare il CAMPIONE.$"

VictoryRoad_1F_Text_QuincyIntro:
	.string "Cos'è la VICTORY ROAD?\n"
	.string "Te lo dico se vinci!$"

VictoryRoad_1F_Text_QuincyDefeat:
	.string "Okay!\n"
	.string "Ben fatto!$"

VictoryRoad_1F_Text_QuincyPostBattle:
	.string "Passare di qui indenni, questa\n"
	.string "è la prova finale per ogni ALLENATORE\l"
	.string "che vuole diventare CAMPIONE\p"
	.string "POKéMON. Per questo si chiama\n"
	.string "VICTORY ROAD.$"

VictoryRoad_1F_Text_KatelynnIntro:
	.string "Non ho nulla da dire a chi\n"
	.string "è arrivato fin qui. Forza!$"

VictoryRoad_1F_Text_KatelynnDefeat:
	.string "Che vergogna…$"

VictoryRoad_1F_Text_KatelynnPostBattle:
	.string "Umpf, vai pure avanti.\n"
	.string "Non m'importa.$"
