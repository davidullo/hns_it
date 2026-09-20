Route114_FossilManiacsTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsTunnel_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route114_FossilManiacsTunnel_OnLoad
	.byte 0

Route114_FossilManiacsTunnel_OnTransition:
	call_if_set FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac
	end

Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac::
	setobjectxyperm LOCALID_FOSSIL_MANIAC, 6, 5
	setobjectmovementtype LOCALID_FOSSIL_MANIAC, MOVEMENT_TYPE_FACE_DOWN
	return

Route114_FossilManiacsTunnel_OnLoad:
	call_if_unset FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass
	end

Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass::
	setmetatile 6, 1, METATILE_Fallarbor_RedRockWall, TRUE
	setmetatile 6, 2, METATILE_Fallarbor_RedRockWall, TRUE
	return

Route114_FossilManiacsTunnel_EventScript_ManiacMentionCaveIn::
	lockall
	applymovement LOCALID_FOSSIL_MANIAC, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Route114_FossilManiacsTunnel_Text_NotSafeThatWay, MSGBOX_DEFAULT
	setvar VAR_FOSSIL_MANIAC_STATE, 2
	releaseall
	end

Route114_FossilManiacsTunnel_EventScript_FossilManiac::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REVIVED_FOSSIL_MON, Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	msgbox Route114_FossilManiacsTunnel_Text_LookInDesertForFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil::
	msgbox Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil::
	msgbox Route114_FossilManiacsTunnel_Text_FossilsAreWonderful, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_Text_LookInDesertForFossils:
	.string "Sono il MANIACO DEI FOSSILI…\n"
	.string "Un bravo tipo che ama i FOSSILI…\p"
	.string "Vuoi un FOSSILE?\p"
	.string "Ma i FOSSILI di queste parti sono\n"
	.string "tutti miei… Per te niente…\p"
	.string "Se non puoi farne a meno,\n"
	.string "cerca nel deserto, tra massi\l"
	.string "e sabbia potrebbero nascondersi\l"
	.string "FOSSILI…$"

Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils:
	.string "Hai trovato un FOSSILE, vero?\n"
	.string "Che bello… Che sogno…\p"
	.string "Cosa farai con quel\n"
	.string "FOSSILE?\p"
	.string "Ho sentito che la DEVON studia\n"
	.string "come far rivivere i POKéMON dai\l"
	.string "FOSSILI…\p"
	.string "Io amo i miei FOSSILI, quindi non\n"
	.string "farei mai una cosa simile…$"

Route114_FossilManiacsTunnel_Text_FossilsAreWonderful:
	.string "I FOSSILI sono così… Meravigliosi…\n"
	.string "Che sogno…$"

Route114_FossilManiacsTunnel_Text_NotSafeThatWay:
	.string "Oh…\n"
	.string "Da quella parte non è sicuro…\p"
	.string "Stavo scavando, sai…\n"
	.string "Quando l'intera parete è crollata…\p"
	.string "Credo che ora ci sia una caverna\n"
	.string "gigantesca sotto…\p"
	.string "Ma l'ho lasciata stare perché non\n"
	.string "credo ci siano FOSSILI…$"

