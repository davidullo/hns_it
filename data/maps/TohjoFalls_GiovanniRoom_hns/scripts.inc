TohjoFalls_GiovanniRoom_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TohjoFalls_GiovanniRoom_OnTransition
	.byte 0

TohjoFalls_GiovanniRoom_OnTransition::
	specialvar VAR_RESULT, CheckCelebi
	goto_if_eq VAR_RESULT, TRUE, TohjoFalls_GiovanniRoom_SetScene
	setvar VAR_TOHJO_FALLS_GIOVANNI_STATE, 0
	end

TohjoFalls_GiovanniRoom_SetScene::
	setflag FLAG_HIDE_TOHJO_GIOVANNI
	goto_if_ne VAR_TOHJO_FALLS_GIOVANNI_STATE, 0, TohjoFalls_GiovanniRoom_DoNothing
	setvar VAR_TOHJO_FALLS_GIOVANNI_STATE, 1
	end

TohjoFalls_GiovanniRoom_DoNothing::
	end

TohjoFalls_GiovanniRoom_EventScript_Radio::
	msgbox TohjoFalls_GiovanniRoom_Text_RadioObject, MSGBOX_SIGN
	end

TohjoFalls_GiovanniRoom_Text_RadioObject::
	.string "Una radio…\n"
	.string "La batteria è scarica…$"

TohjoFalls_GiovanniRoom_CancelScene::
	setvar VAR_TOHJO_FALLS_GIOVANNI_STATE, 0
	end

TohjoFalls_EventScript_GiovanniSceneRight::
	specialvar VAR_RESULT, CheckCelebi
	goto_if_eq VAR_RESULT, FALSE, TohjoFalls_GiovanniRoom_CancelScene
	lock
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	goto TohjoFalls_EventScript_GiovanniScene

TohjoFalls_EventScript_GiovanniSceneLeft::
	specialvar VAR_RESULT, CheckCelebi
	goto_if_eq VAR_RESULT, FALSE, TohjoFalls_GiovanniRoom_CancelScene
	lock
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	goto TohjoFalls_EventScript_GiovanniScene

TohjoFalls_EventScript_GiovanniScene::
	specialvar VAR_RESULT, CheckCelebi
	goto_if_eq VAR_RESULT, FALSE, TohjoFalls_GiovanniRoom_CancelScene
	lock
	applymovement2 OBJ_EVENT_ID_FOLLOWER, TohjoFalls_Movement_CelebiBegin
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement 0
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	delay 20
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement2 OBJ_EVENT_ID_FOLLOWER, TohjoFalls_Movement_CelebiSpin
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	@playse SE_M_PETAL_DANCE
	@delay 10
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitmovement 0
	fadescreen FADE_TO_WHITE
	playse SE_M_TELEPORT
	waitse
	delay 60
	playse SE_M_TELEPORT
	waitse
	clearflag FLAG_HIDE_TOHJO_GIOVANNI
	addobject LOCALID_TOHJOFALLS_GIOVANNI
	waitse
	playbgm MUS_HG_RADIO_ROCKET, FALSE
	fadescreen FADE_FROM_WHITE
	delay 50
	turnobject  OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox TohjoFalls_GiovanniRoom_Text_Radio, MSGBOX_DEFAULT
	closemessage
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	applymovement2 OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkUp1
	waitmovement 0
	waitmovement OBJ_EVENT_ID_FOLLOWER
	playse SE_PIN
	applymovement2 LOCALID_TOHJOFALLS_GIOVANNI, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_TOHJOFALLS_GIOVANNI
	turnobject LOCALID_TOHJOFALLS_GIOVANNI, DIR_SOUTH
	msgbox TohjoFalls_GiovanniRoom_Text_GiovanniIntro, MSGBOX_DEFAULT
	applymovement2 LOCALID_TOHJOFALLS_GIOVANNI, Common_Movement_WalkDown1
	waitmovement 0
	msgbox TohjoFalls_GiovanniRoom_Text_GiovanniBeforeBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GIOVANNI_HNS, TohjoFalls_GiovanniRoom_Text_GiovanniDefeat
	playbgm MUS_HG_RADIO_ROCKET, FALSE
	applymovement2 LOCALID_TOHJOFALLS_GIOVANNI, TohjoFalls_Movement_GiovanniTakenAback
	waitmovement 0
	msgbox TohjoFalls_GiovanniRoom_Text_GiovanniAfter, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_TOHJOFALLS_GIOVANNI, TohjoFalls_Movement_GiovanniLeave
	waitmovement 0 
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_TOHJOFALLS_GIOVANNI
	playse SE_EXIT
	fadescreen FADE_FROM_BLACK
	delay 30

	applymovement2 OBJ_EVENT_ID_FOLLOWER, TohjoFalls_Movement_CelebiBegin
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement 0
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	delay 20
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement2 OBJ_EVENT_ID_FOLLOWER, TohjoFalls_Movement_CelebiSpin
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	@playse SE_M_PETAL_DANCE
	@delay 10
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitmovement 0
	fadescreen FADE_TO_WHITE
	playse SE_M_TELEPORT
	waitse
	delay 60
	playse SE_M_TELEPORT
	waitse
	fadedefaultbgm
	fadescreen FADE_FROM_WHITE
	setvar VAR_TOHJO_FALLS_GIOVANNI_STATE, 2
	release
	end

TohjoFalls_Movement_CelebiBegin:
	jump_in_place_up
	jump_in_place_up
	step_end

TohjoFalls_Movement_CelebiSpin:
	jump_in_place_up
	jump_in_place_up
	jump_in_place_up
	jump_in_place_up
	step_end

TohjoFalls_Movement_GiovanniTakenAback:
	lock_facing_direction
	walk_slow_up
	unlock_facing_direction
	walk_slow_right
	walk_slow_right
	step_end

TohjoFalls_Movement_GiovanniLeave:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	face_down
	walk_in_place_down
	step_end

TohjoFalls_GiovanniRoom_Text_Radio:
	.string "RADIO: … …\n"
	.string "Ehm, noi siamo il TEAM ROCKET!\l"
	.string "Dopo tre anni di preparativi,\l"
	.string "siamo risorti dalle nostre ceneri!\l"
	.string "GIOVANNI! Ci senti?\l"
	.string "Ce l'abbiamo fatta!\l"
	.string "Dov'è il nostro capo?\l"
	.string "Ci sta ascoltando?$"

TohjoFalls_GiovanniRoom_Text_GiovanniIntro:
	.string "GIOVANNI: ...\p"
	.string "Non so perché sei venuto\n"
	.string "qui.\p"
	.string "Comunque, ti avverto che\n"
	.string "questo non è un posto per\l"
	.string "ragazzini come te.\p"
	.string "Hai un certo sguardo.\n"
	.string "Mi ricorda il ragazzo che mi stava\l"
	.string "davanti tre anni fa...\p"
	.string "Hai gli stessi occhi...\p"
	.string "...\p"
	.string "Vado a GOLDENROD CITY\n"
	.string "per rispondere alla chiamata.\l"
	.string "Vuoi intralciarmi?$"

TohjoFalls_GiovanniRoom_Text_GiovanniBeforeBattle:
	.string "I miei vecchi compagni hanno bisogno\n"
	.string "di me… Non ripeteremo il fallimento\l"
	.string "di tre anni fa!$"

TohjoFalls_GiovanniRoom_Text_GiovanniDefeat:
	.string "Cosa diavolo sei?$"

TohjoFalls_GiovanniRoom_Text_GiovanniAfter:
	.string "GIOVANNI: Come è possibile…?\n"
	.string "Gli ultimi tre anni sono stati\l"
	.string "un inutile spreco…?\p"
	.string "Come può un ragazzino come te\n"
	.string "distruggere di nuovo il mio sogno?\p"
	.string "Il grande sogno del TEAM ROCKET\n"
	.string "non è ormai altro che\l"
	.string "un'illusione…$"
