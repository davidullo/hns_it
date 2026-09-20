Route24_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route24_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route24_OnTransition:
	call_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route24_MapScript_SetRocketScene
	callnative SetTimeBasedEncounters
	end

Route24_MapScript_SetRocketScene:
	setobjectxyperm LOCALID_ROUTE24_GRUNT, 16, 8
	setobjectxyperm LOCALID_ROUTE24_WOMAN, 16, 9
	setobjectmovementtype LOCALID_ROUTE24_GRUNT, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype LOCALID_ROUTE24_WOMAN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_ROUTE24_MAN, MOVEMENT_TYPE_FACE_DOWN
	return

Route24_EventScript_Woman::
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route24_EventScript_WomanRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, Route24_EventScript_WomanAfterRocket
	msgbox Route24_Text_Woman, MSGBOX_NPC
	end

Route24_EventScript_WomanRocket::
	msgbox Route24_Text_WomanRocket, MSGBOX_NPC
	end

Route24_EventScript_WomanAfterRocket::
	msgbox Route24_Text_WomanAfterRocket, MSGBOX_NPC
	end

Route24_EventScript_Man::
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route24_EventScript_ManRocket
		goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, Route24_EventScript_ManAfterRocket
	msgbox Route24_Text_Man, MSGBOX_NPC
	end

Route24_EventScript_ManRocket::
	msgbox Route24_Text_ManRocket, MSGBOX_NPC
	end

Route24_EventScript_ManAfterRocket::
	msgbox Route24_Text_ManAfterRocket, MSGBOX_NPC
	end

Route24_Trigger_GruntScene::
	lock
	playse SE_PIN
	applymovement2 LOCALID_ROUTE24_GRUNT Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ROUTE24_GRUNT
	applymovement2 LOCALID_ROUTE24_GRUNT, Route24_Movement_GruntHide
	delay 10
	applymovement2 LOCALID_ROUTE24_WOMAN, Route24_Movement_WomanMove
	waitmovement 0
	turnobject LOCALID_ROUTE24_MAN, DIR_SOUTH
	setvar VAR_KANTO_ROCKET_STORY_STATE, 4
	call Route24_MapScript_SetRocketScene
	release
	end

Route24_Movement_GruntHide:
	walk_fast_left
	walk_fast_left
	step_end

Route24_Movement_WomanMove:
	lock_facing_direction
	walk_fast_down
	unlock_facing_direction
	face_up
	step_end

Route24_EventScript_Grunt::
	lock
	faceplayer
	msgbox Route24_Text_RocketSeen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_31_HNS, Route24_Text_RocketBeaten
	msgbox Route24_Text_RocketAfter, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement2 LOCALID_ROUTE24_GRUNT, Common_Movement_QuestionMark
	delay 55
	waitmovement LOCALID_ROUTE24_GRUNT
	msgbox Route24_Text_RocketDisappears, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route24_Movement_PlayerSlide
	delay 20
	applymovement LOCALID_ROUTE24_GRUNT, Route24_Movement_GruntLeave
	waitmovement LOCALID_ROUTE24_GRUNT
	setflag FLAG_HIDE_CERULEAN_CAPE_ROCKET
	removeobject LOCALID_ROUTE24_GRUNT
	setvar VAR_KANTO_ROCKET_STORY_STATE, 5
	clearflag FLAG_HIDDEN_ITEM_MACHINE_PART
	release
	end

Route24_Movement_PlayerSlide:
	delay_16
	lock_facing_direction
	walk_fast_up
	unlock_facing_direction
	face_down
	step_end

Route24_Movement_GruntLeave:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Route24_Text_RocketSeen:
	.string "Ehi, ragazzo! Io sono un membro\n"
	.string "del TEAM ROCKET!\p"
	.string "Vengo da un altro paese, un\n"
	.string "allenatore numero uno, io!\p"
	.string "Penso io, se fermo l'energia,\n"
	.string "gran panico per la gente qui!\p"
	.string "Segreta è la mia missione, quindi dirti\n"
	.string "io no!\p"
	.string "Ma! Se vinci tu contro me, un\n"
	.string "uomo sarò e il mio segreto a te\l"
	.string "dirò.\p"
	.string "Ehi, ragazzo! La battaglia inizia ora!$"

Route24_Text_RocketBeaten:
	.string "Ayieeeh! No, no, no, crederci\n"
	.string "non posso!\p"
	.string "Forte molto sei tu! Non sono\n"
	.string "alla tua altezza!$"

Route24_Text_RocketAfter:
	.string "OK. Il mio segreto ti dico io?\n"
	.string "PEZZO MACCHINA rubato da me, nascosto\l"
	.string "l'ho nella PALESTRA di AZZURROPOLI.\p"
	.string "Nell'acqua l'ho messo. Cerca\n"
	.string "nell'acqua al centro della PALESTRA.\p"
	.string "Ma non dimenticare me!\p"
	.string "Batterà voi di sicuro il TEAM\n"
	.string "ROCKET.\p"
	.string "Da JOHTO verranno, miei\n"
	.string "amici, sì. Vendetta avranno\l"
	.string "loro.$"

Route24_Text_RocketDisappears:
	.string "…\p"
	.string "Tu dire cosa? TEAM ROCKET bye-\n"
	.string "bye andato? Rotto è dici\l"
	.string "tu?\p"
	.string "Oh, no! Cosa devo fare ora in\n"
	.string "avanti, io?$"



Route24_Text_Woman:
	.string "Non è un panorama incantevole?$"
Route24_Text_Man:
	.string "Potrei restare qui tutto il giorno.$"

Route24_Text_WomanRocket:
	.string "Nessuno spinge me!$"
Route24_Text_ManRocket:
	.string "Nessuno spinge la mia ragazza!$"

Route24_Text_WomanAfterRocket:
	.string "Ma cosa succedeva?$"
Route24_Text_ManAfterRocket:
	.string "Era un ROCKET?$"
