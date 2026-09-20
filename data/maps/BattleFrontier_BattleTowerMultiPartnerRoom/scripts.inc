BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiPartnerRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame
	.byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_OnResume:
	pyramid_resetparty
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition:
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2
	tower_loadpartners
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_5, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_6, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_7, OBJ_EVENT_GFX_BOY_1
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_3, 1
	setobjectxyperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, 10, 2
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp:
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom::
	lockall
	setvar VAR_TEMP_3, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom::
	lockall
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom
	waitmovement 0
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit
	waitmovement 0
	copyobjectxytoperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner, MSGBOX_DEFAULT
	special HealPlayerParty
	setvar VAR_TEMP_1, 1
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom:
	walk_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit:
	walk_left
	walk_in_place_faster_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant::
	lock
	faceplayer
	message BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge::
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator::
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 10, 1
	waitdooranim
	call BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator
	closedoor 10, 1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 1, 6
	waitstate
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator::
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorEast:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorWest:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator:
	walk_up
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast:
	walk_right
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest:
	walk_left
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner1::
	lock
	faceplayer
	setvar VAR_TEMP_2, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner::
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_INTRO
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON1
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON2_ASK
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_ACCEPT
	waitmessage
	waitbuttonpress
	closemessage
	call_if_ne VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth
	removeobject VAR_LAST_TALKED
	setflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM, 10, 3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner::
	tower_dopartnermsg PARTNER_MSGID_REJECT
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner2::
	lock
	faceplayer
	setvar VAR_TEMP_2, 1
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner3::
	lock
	faceplayer
	setvar VAR_TEMP_2, 2
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner4::
	lock
	faceplayer
	setvar VAR_TEMP_2, 3
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner5::
	lock
	faceplayer
	setvar VAR_TEMP_2, 4
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner6::
	lock
	faceplayer
	setvar VAR_TEMP_2, 5
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner7::
	lock
	faceplayer
	setvar VAR_TEMP_2, 6
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner8::
	lock
	faceplayer
	setvar VAR_TEMP_2, 7
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner:
	.string "Scegli un partner fra gli\n"
	.string "ALLENATORI qui presenti.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner:
	.string "{PLAYER}, non hai trovato un partner\n"
	.string "per la tua coppia.\p"
	.string "Vuoi smettere di cercare e\n"
	.string "tornare alla reception?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2:
	.string "Poi scegli un partner fra\n"
	.string "gli ALLENATORI qui presenti.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner::
	.string "Grazie per aver scelto un partner.\p"
	.string "Ora ti accomplicherò alla\n"
	.string "SALA COMBATTIMENTI MULTIPLI.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Intro::
	.string "Apprendista n. {STR_VAR_2} di {STR_VAR_1}.\n"
	.string "Chiamami {STR_VAR_3}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon1::
	.string "Su consiglio di {STR_VAR_1} ho\n"
	.string "preso un {STR_VAR_3} con {STR_VAR_2} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Fammi entrare nella tua squadra.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Accept::
	.string "Grazie!\n"
	.string "Vado subito a iscrivermi.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Reject::
	.string "Volevo tanto fare squadra\n"
	.string "con te, {PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Intro::
	.string "Apprendista n. {STR_VAR_2} di {STR_VAR_1}.\n"
	.string "Mi chiamo {STR_VAR_3}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon1::
	.string "Su consiglio di {STR_VAR_1} ho\n"
	.string "preso un {STR_VAR_3} con {STR_VAR_2} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Dai, facciamo squadra!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Accept::
	.string "Grazie mille!\n"
	.string "Finisco subito l'iscrizione!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Reject::
	.string "{PLAYER}, speravo di poter\n"
	.string "fare squadra con te…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Intro::
	.string "Ehm, mi chiamo {STR_VAR_3} e sono\n"
	.string "l'apprendista n. {STR_VAR_2} di {STR_VAR_1}.\p"
	.string "Snuff…\p"
	.string "Scusa!\n"
	.string "La tensione mi fa piangere…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon1::
	.string "Su consiglio di {STR_VAR_3}, ho\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Snuff…\n"
	.string "Ti prego, fai squadra con me!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Accept::
	.string "Oh, davvero? Accetti?\n"
	.string "Fantastico! Awoooh!\p"
	.string "Oh… scusa…\n"
	.string "Che felicità, piango…\p"
	.string "Vado subito a registrarci.\n"
	.string "Non ti muovere!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Reject::
	.string "Oh, m-ma…\n"
	.string "Sob… Waaaah!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Intro::
	.string "Ciao! Sono {STR_VAR_3}!\n"
	.string "Sono l'apprendista n. {STR_VAR_2} di {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon1::
	.string "{STR_VAR_3} l'ha suggerito al team.\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1},\n"
	.string "ecco la mia squadra! Fico, eh?\p"
	.string "Su, dai!\n"
	.string "Facciamo una coppia!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Accept::
	.string "Sì! Evviva!\n"
	.string "Vado a registrarci, va bene?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Reject::
	.string "Oh, perché?\n"
	.string "Volevo far coppia, {PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Intro::
	.string "Sono {STR_VAR_3}, apprendista n. {STR_VAR_2}\n"
	.string "del famoso {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon1::
	.string "Ho chiesto consiglio a {STR_VAR_3}.\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon2Ask::
	.string "e un {STR_VAR_2} con {STR_VAR_1},\n"
	.string "è la mia coppia.\p"
	.string "Vuoi fare coppia\n"
	.string "con me?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Accept::
	.string "Grazie!\n"
	.string "Mi registro subito!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Reject::
	.string "{PLAYER}, speravo di fare\n"
	.string "copia con te…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Intro::
	.string "Um… sono davvero contento che\n"
	.string "tu mi abbia dedicato tempo.\p"
	.string "Sono {STR_VAR_3}.\n"
	.string "Sono l'apprendista n. {STR_VAR_2} di {STR_VAR_1}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon1::
	.string "{STR_VAR_3} mi ha consigliato.\n"
	.string "Gliene sono grato.\p"
	.string "Ho una squadra di un {STR_VAR_2}\n"
	.string "con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\n"
	.string "Chiedo molto, lo so…\p"
	.string "Non credo che accetterai,\n"
	.string "ma posso fare coppia con te?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Accept::
	.string "Davvero? Non ci credo!\n"
	.string "Non credo che mi accetterai!\l"
	.string "Io… non ti deluderò!\p"
	.string "Um… se va davvero, vado\n"
	.string "a registrarmi subito!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Reject::
	.string "Oh…\n"
	.string "Sapevo di non essere all'altezza…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Intro::
	.string "Ciao, sono {STR_VAR_3}.\n"
	.string "Sono l'apprendista n. {STR_VAR_2} di {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon1::
	.string "{STR_VAR_3} mi ha detto che\n"
	.string "questa squadra va bene:\l"
	.string "un {STR_VAR_2} con {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon2Ask::
	.string "e un {STR_VAR_2} che sa usare\n"
	.string "{STR_VAR_1}.\p"
	.string "Niente male, eh?\n"
	.string "Ti va di far coppia con me?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Accept::
	.string "Ok, che gioia unirsi!\n"
	.string "Spero che tu non combini guai!\l"
	.string "Mi registro ora.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Reject::
	.string "Eh? Perché mi hai rifiutato?\n"
	.string "Non capisci la gente!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Intro::
	.string "Sono {STR_VAR_3}, TRIATLETA.\n"
	.string "Fra corsa, palestra e rap\l"
	.string "non ho mai un attimo libero.\p"
	.string "E sono pure l'allievo di {STR_VAR_1},\n"
	.string "il n. {STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon1::
	.string "Scelto da {STR_VAR_3}.\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon2Ask::
	.string "e un altro con {STR_VAR_1}:\n"
	.string "{STR_VAR_2}.\p"
	.string "Li ho allevati con cura,\n"
	.string "malgrado gli impegni.\p"
	.string "Facciamo una coppia\n"
	.string "e proviamo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Accept::
	.string "Grazie, questo è spirito!\n"
	.string "Aspetta che vado a registrarmi, ok?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Reject::
	.string "Ho mollato tutto per venire!\n"
	.string "Dai, sii comprensivo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Intro::
	.string "Hi!\n"
	.string "How's it going?\p"
	.string "I'm {STR_VAR_3}, {STR_VAR_1}'s\n"
	.string "no. {STR_VAR_2} apprentice. Glad to meet you!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon1::
	.string "Senti, senti! Devi sapere dei\n"
	.string "POKéMON scelti da {STR_VAR_3}.\l"
	.string "Un {STR_VAR_2} con {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\n"
	.string "Certo che li ho allevati bene!\p"
	.string "Facciamo squadra?\n"
	.string "Sarà un'ottima coppia!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Accept::
	.string "Yay! Sarà divertente!\n"
	.string "Vado a registrarmi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Reject::
	.string "Oh, che cattivo!\n"
	.string "Sono qui su raccomandazione!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Intro::
	.string "Con permesso, mi presento.\n"
	.string "Sono {STR_VAR_3}.\p"
	.string "L'apprendista di {STR_VAR_1}\n"
	.string "n. {STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon1::
	.string "Ho chiesto consiglio a\n"
	.string "{STR_VAR_3} e ho allenato\l"
	.string "un {STR_VAR_2} con {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon2Ask::
	.string "e un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Fa' squadra con me, ti prego!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Accept::
	.string "Oh… che gioia!\n"
	.string "Ti prometto il mio meglio!\p"
	.string "Certo che ci registro!\n"
	.string "Aspetta!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Reject::
	.string "Speravo di far squadra con te,\n"
	.string "{PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Intro::
	.string "Eek! Mi hai parlato!\n"
	.string "Che… che gioia!\p"
	.string "Sono {STR_VAR_3}! Di {STR_VAR_1}\n"
	.string "n. {STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon1::
	.string "Su consiglio di {STR_VAR_3},\n"
	.string "un {STR_VAR_2} con {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon2Ask::
	.string "e uno con {STR_VAR_1}:\n"
	.string "{STR_VAR_2}.\p"
	.string "Puoi esaudire il mio Desiderio?\n"
	.string "Voglio far squadra con te!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Accept::
	.string "Eek! Sono… sono felice!\n"
	.string "Grazie infinite!\l"
	.string "Ci registro subito!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Reject::
	.string "Waaah! Niente compassione?\n"
	.string "Ma così sei più fico…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Intro::
	.string "Ehi! Sono di {STR_VAR_1}\n"
	.string "allievo n. {STR_VAR_2}!\p"
	.string "Mi chiamo {STR_VAR_3}, salve, salve!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon1::
	.string "Il maestro {STR_VAR_3} ha\n"
	.string "scelto un {STR_VAR_1}, {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon2Ask::
	.string "e un {STR_VAR_1}\n"
	.string "{STR_VAR_2}.\p"
	.string "Bello, eh?\n"
	.string "Sarai mio partner, vero?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Accept::
	.string "Ehi, perfetto!\n"
	.string "Tiro giù l'iscrizione in fretta!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Reject::
	.string "Aaah!\n"
	.string "Ma che sei calcolatore, {PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Intro::
	.string "Hey! There's big trouble! This is\n"
	.string "the BATTLE TOWER's last day!\p"
	.string "… … … … … …\n"
	.string "I'm only joking!\p"
	.string "People call me {STR_VAR_3} and I do, too!\n"
	.string "I'm {STR_VAR_1}'s 1,000th apprentice!\l"
	.string "Actually, I'm no. {STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon1::
	.string "Un consiglio da {STR_VAR_3}.\n"
	.string "{STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon2Ask::
	.string "{STR_VAR_2} con {STR_VAR_1}.\n"
	.string "Ne ho dieci per ogni tipo!\l"
	.string "Anzi, uno per tipo!\p"
	.string "Che ne dici?\n"
	.string "Vuoi provare le lotte di coppia?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Accept::
	.string "Evvai!\n"
	.string "Un POKéMON in regalo, per te!\p"
	.string "Scherzo! Ma poi vado davvero\n"
	.string "a iscrivermi, ok?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Reject::
	.string "Oh, che freddezza! Ora distruggo\n"
	.string "la TORRE LOTTA!\p"
	.string "Certo che no!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Intro::
	.string "Ehi, sono qui che scatto e volo!\n"
	.string "Comando i POKéMON, sì!\p"
	.string "Sono {STR_VAR_3}, MARINAIO rap.\n"
	.string "Non scambiarmi per un piangone!\p"
	.string "Sono il n. {STR_VAR_2} di {STR_VAR_1}.\n"
	.string "Non sottovalutarmi, eh!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon1::
	.string "Col consiglio di {STR_VAR_3} ho\n"
	.string "creato la squadra del mio orgoglio!\l"
	.string "Un {STR_VAR_1}, {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon2Ask::
	.string "e un {STR_VAR_1}\n"
	.string "{STR_VAR_2}!\p"
	.string "Festeggiamo il nostro incontro,\n"
	.string "con una vittoria di coppia!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Accept::
	.string "Ehi, mi piace il tuo stile!\n"
	.string "Vado a fare la registrazione!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Reject::
	.string "Oh, {PLAYER}, che freddezza!\n"
	.string "Se posso dire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Intro::
	.string "Evviva!\n"
	.string "Ehi, non scappare! Scherzavo!\p"
	.string "Salve, {STR_VAR_3}!\n"
	.string "Sono il n. {STR_VAR_2} di {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon1::
	.string "{STR_VAR_3} mi ha istruito.\n"
	.string "un {STR_VAR_1}, {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon2Ask::
	.string "e un {STR_VAR_1}\n"
	.string "{STR_VAR_2}, scelto.\p"
	.string "Allora, che dici?\n"
	.string "Dai, esaudiscimi!\p"
	.string "Ti prego, dai!\n"
	.string "Prendimi con te, non mi lasciar!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Accept::
	.string "Sì! Che fortuna!\n"
	.string "Che felicità!\p"
	.string "Prima di entrare in gioco,\n"
	.string "vado subito a iscrivermi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Reject::
	.string "Mi dici di no?\n"
	.string "{PLAYER}, che tristezza!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Intro::
	.string "Ahem!\p"
	.string "Scusa, ho il raffreddore.\n"
	.string "I miei POKéMON stanno bene.\p"
	.string "Sono {STR_VAR_3}, di {STR_VAR_1}\n"
	.string "allievo n. {STR_VAR_2}. Ahem!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon1::
	.string "Ho seguito il consiglio di {STR_VAR_3}\n"
	.string "e ho formato la squadra di\l"
	.string "un {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Li alleno ogni giorno,\n"
	.string "anche con la pioggia.\p"
	.string "Ecco il mio raffreddore,\n"
	.string "Credo.\p"
	.string "Sono fatto così.\n"
	.string "Vuoi farmi da compagno?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Accept::
	.string "Grazie, davvero!\n"
	.string "Cof cof!\l"
	.string "Aspetta, vado a iscrivermi.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Reject::
	.string "Oh, non vuoi?\n"
	.string "{PLAYER}, penso che siamo compatibili.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Intro::
	.string "Oh, ciao!\n"
	.string "Che tensione.\p"
	.string "Sono {STR_VAR_3}.\n"
	.string "Sono l'apprendista n. {STR_VAR_2} di {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon1::
	.string "{STR_VAR_3} dice che la squadra è forte\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Mi sento a disagio, lo ammetto,\n"
	.string "ma mi accetti nella squadra?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Accept::
	.string "Oh, grazie!\n"
	.string "Che imbarazzo! Farò del mio meglio!\p"
	.string "Vado a fare la registrazione.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Reject::
	.string "Oh, non dire di no!\n"
	.string "Mi sento già abbastanza a disagio…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Intro::
	.string "Sono {STR_VAR_3}, e non è una bugia.\n"
	.string "Sono l'apprendista n. {STR_VAR_2} di {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon1::
	.string "{STR_VAR_3} ha scelto il team.\p"
	.string "Il consiglio sembrava sincero,\n"
	.string "così ho deciso di portare\l"
	.string "il mio {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon2Ask::
	.string "il mio {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Mi piacerebbe, se possibile, avere\n"
	.string "te come compagno di squadra.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Accept::
	.string "Mi accetti davvero?\n"
	.string "Sarebbe troppo tragico altrimenti.\p"
	.string "Ma visto che accetti, va benissimo.\n"
	.string "Vado a registrarci entrambi.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Reject::
	.string "Hm? Now why would you refuse?\n"
	.string "Is this your idea of a joke?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassIntro::
	.string "Sono la SIGNORINA {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon1::
	.string "Ho un {STR_VAR_2} che usa\n"
	.string "{STR_VAR_1}, e un altro$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon2Ask::
	.string "{STR_VAR_2} che usa {STR_VAR_1}.\n"
	.string "Sono quelli che porto con me.\p"
	.string "Vuoi fare squadra?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassAccept::
	.string "Grazie!\n"
	.string "Vado a registrarmi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassReject::
	.string "Non vuoi fare squadra con me?\n"
	.string "Te ne pentirai!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterIntro::
	.string "Ciao!\p"
	.string "GIOVANOTTO {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon1::
	.string "Sai cosa ho con me?\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "Sarai il mio partner,\n"
	.string "vero?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterAccept::
	.string "Sì!\n"
	.string "Vado a iscrivermi, va?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterReject::
	.string "Peccato! In squadra coi miei\n"
	.string "POKéMON saremmo imbattibili!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerIntro::
	.string "Yuhuu!\n"
	.string "Sono l'ESCURSIONISTA {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon1::
	.string "Sai cosa ho con me?\n"
	.string "Il mio {STR_VAR_2} che usa {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon2Ask::
	.string "{STR_VAR_2} che usa {STR_VAR_1}!\p"
	.string "Va bene, eh?\n"
	.string "Facciamo una squadra?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerAccept::
	.string "Yuhuu!\n"
	.string "Vado a registrarci, allora.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerReject::
	.string "Mi sarebbe piaciuto averti\n"
	.string "al fianco.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyIntro::
	.string "Ciao!\n"
	.string "Sono {STR_VAR_1}, una BEAUTY!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon1::
	.string "Sai cosa sto allevando?\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "Che ne dici?\n"
	.string "Facciamo una squadra?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyAccept::
	.string "Fantastico!\n"
	.string "Vado subito a registrarmi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyReject::
	.string "Che delusione!\p"
	.string "Insieme saremmo stati\n"
	.string "i migliori!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanIntro::
	.string "Ehi!\p"
	.string "Sai chi sono?\n"
	.string "Sono {STR_VAR_1}, il PESCATORE!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon1::
	.string "Ho con me una squadra di un\n"
	.string "{STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon2Ask::
	.string "un {STR_VAR_2} che usa {STR_VAR_1}.\p"
	.string "Allora, che ne dici?\n"
	.string "Vuoi lottare al mio fianco?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanAccept::
	.string "Bene, bene!\n"
	.string "Lascia fare a me!\p"
	.string "Vado a registrarci subito.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanReject::
	.string "Eravamo fatti apposta, peccato…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyIntro::
	.string "Molto lieta di conoscerti.\n"
	.string "Sono la LADY {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon1::
	.string "Mi accompagna una squadra di\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Spero di essere all'altezza.\n"
	.string "Vorrei averti come partner.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyAccept::
	.string "Grazie infinite.\n"
	.string "Mi occupo della registrazione.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyReject::
	.string "Rimpiangerai di non avermi\n"
	.string "preso come partner.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFIntro::
	.string "Sono la TRIATLETA {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon1::
	.string "Quello che ho…\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\n"
	.string "Sono una coppia!\p"
	.string "Ti prego!\n"
	.string "Vuoi fare coppia con me?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFAccept::
	.string "Oh, grazie!\n"
	.string "Vado a registrarci al bancone.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFReject::
	.string "Insieme saremmo stati\n"
	.string "sicuramente fortissimi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherIntro::
	.string "Ehilà!\n"
	.string "Sono CACCIABUG {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon1::
	.string "Guarda che ho!\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "Allora, senti!\n"
	.string "Vuoi fare squadra con me?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherAccept::
	.string "Ricevuto!\p"
	.string "Vado a fare la registrazione\n"
	.string "al banco.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherReject::
	.string "I miei POKéMON sono forti.\n"
	.string "Spero non te ne pentirai!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMIntro::
	.string "Buongiorno!\n"
	.string "Sono lo SCOLARO {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon1::
	.string "Quello che allevio è un\n"
	.string "{STR_VAR_2} che usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon2Ask::
	.string "and one {STR_VAR_2} that uses\n"
	.string "{STR_VAR_1}.\p"
	.string "Not too bad, don't you think?\n"
	.string "Would you care to form a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMAccept::
	.string "Grazie mille!\n"
	.string "Vado a fare l'iscrizione.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMReject::
	.string "That's too bad…\p"
	.string "I was hoping that I could learn\n"
	.string "from you as your partner…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyIntro::
	.string "Ehi! Ti dico chi sono!\n"
	.string "Sono RICH BOY {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon1::
	.string "Indovina cosa ho!\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "Ti offro la possibilità\n"
	.string "di far coppia con me.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyAccept::
	.string "Ottima scelta!\p"
	.string "Completo la registrazione\n"
	.string "in un attimo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyReject::
	.string "Mi rifiuti proprio io?\n"
	.string "Te ne pentirai sul serio!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltIntro::
	.string "Heia!\n"
	.string "Sono LOTTATORE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon1::
	.string "Ho con me, come compagni,\n"
	.string "un {STR_VAR_2} con {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon2Ask::
	.string "e un {STR_VAR_2} con\n"
	.string "{STR_VAR_1}.\p"
	.string "Esaudisci il mio desiderio!\n"
	.string "Fammi essere il tuo compagno!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltAccept::
	.string "Iah!\n"
	.string "Vado subito a registrarmi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltReject::
	.string "Capisco… Spero in una\n"
	.string "prossima occasione…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFIntro::
	.string "Ciao, ciao!\n"
	.string "Sono {STR_VAR_1}, una BIMBA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon1::
	.string "Ti dico cosa ho con me.\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\n"
	.string "Posso unirmi a te in coppia?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFAccept::
	.string "Grazie!\n"
	.string "Vado a registrarci io!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFReject::
	.string "Se fossimo stati partner,\n"
	.string "saremmo stati fortissimi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacIntro::
	.string "Salve…\n"
	.string "Sono la STRANA {STR_VAR_1}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon1::
	.string "Porto con me un {STR_VAR_1} e\n"
	.string "un {STR_VAR_2}, e un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon2Ask::
	.string "{STR_VAR_2} che usa {STR_VAR_1}…\p"
	.string "Ti prego…\n"
	.string "Fai coppia con me…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacAccept::
	.string "Grazie…\n"
	.string "Ci registro subito…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacReject::
	.string "Volevo tanto far coppia…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMIntro::
	.string "Salve! Sono {STR_VAR_1},\n"
	.string "un ALLEVATORE di POKéMON!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon1::
	.string "Ne allevo due forti!\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "Che ne dici?\n"
	.string "Ti va di far squadra con me?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMAccept::
	.string "Thank you kindly!\p"
	.string "I'll go take care of the registration\n"
	.string "stuff, so you wait right here!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMReject::
	.string "Speravo di essere\n"
	.string "il tuo partner…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFIntro::
	.string "Ehilà, ciao!\n"
	.string "Sono TRIATHLETE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon1::
	.string "Sai con cosa corro?\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "Ebbene?\n"
	.string "Vuoi far coppia con me?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFAccept::
	.string "Good going!\p"
	.string "I'll be quick and get the registration\n"
	.string "all done!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFReject::
	.string "Insieme saremmo stati top.\n"
	.string "Che peccato…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMIntro::
	.string "Ehi! Sono {STR_VAR_1}!\n"
	.string "Sono un TRIATHLETE!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon1::
	.string "Corro con una squadra robusta:\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "Non male, eh?\n"
	.string "Dovremmo far coppia insieme!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMAccept::
	.string "Perfetto!\n"
	.string "Vado a iscrivermi in un Baleno!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMReject::
	.string "Volevo tanto gareggiare\n"
	.string "come tuo partner…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlIntro::
	.string "BATTLE GIRL {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon1::
	.string "Sto allenando un\n"
	.string "{STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "Ti piace questa coppia?\n"
	.string "Facciamo squadra?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlAccept::
	.string "Why, thanks!\p"
	.string "I'll get the registration done\n"
	.string "right now!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlReject::
	.string "Con te potevamo fare\n"
	.string "la coppia perfetta…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMIntro::
	.string "Sono la TRIATLETA {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon1::
	.string "Corro con un {STR_VAR_2}\n"
	.string "che sa usare {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon2Ask::
	.string "e un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "In coppia saremmo forti.\n"
	.string "Non sarebbe fantastico?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMAccept::
	.string "Grazie!\p"
	.string "Vado a registrarci,\n"
	.string "subito!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMReject::
	.string "Che peccato! Saremmo stati\n"
	.string "la coppia più forte in giro!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMIntro::
	.string "Io?\n"
	.string "Sono BIMBO {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon1::
	.string "Cosa ho con me?\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "Ehi?\n"
	.string "Fai squadra con me, vero?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMAccept::
	.string "Ok!\p"
	.string "Vado a iscrivermi!\n"
	.string "Saremo fantastici insieme!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMReject::
	.string "I miei POKéMON sono forti…\n"
	.string "Peccato che tu non voglia far squadra.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristIntro::
	.string "Yuhuu!\n"
	.string "Chiamami CHITARRISTA {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon1::
	.string "Guarda un po' la mia band!\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "Yuhuu! Che ritmo, eh?\n"
	.string "Facciamo un duetto in coppia!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristAccept::
	.string "Yuhuu! Grande!\n"
	.string "Ora faccio la registrazione io!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristReject::
	.string "I miei POKéMON spaccano!\n"
	.string "Te ne pentirai, credimi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanIntro::
	.string "Piacere di conoscerti.\n"
	.string "Sono {STR_VAR_1}, un GENTILUOMO.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon1::
	.string "Mi accompagnano il mio fedele\n"
	.string "{STR_VAR_2} che usa {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon2Ask::
	.string "un {STR_VAR_2} che usa {STR_VAR_1}.\p"
	.string "Le andrebbe di farmi coppia in una\n"
	.string "sfida a squadre?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanAccept::
	.string "Ah, grazie della fiducia.\n"
	.string "Procedo con la registrazione.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanReject::
	.string "That is most unfortunate…\p"
	.string "I shall look forward to the next\n"
	.string "opportunity…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMIntro::
	.string "Ciao, sono {STR_VAR_1},\n"
	.string "un vero POKéFAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon1::
	.string "Con me adesso ho un {STR_VAR_2}\n"
	.string "che conosce la mossa {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Ti piace quello che vedi?\n"
	.string "Vuoi farmi da partner di coppia?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMAccept::
	.string "Grazie!\n"
	.string "Penso io alla registrazione!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMReject::
	.string "I miei POKéMON sono di prima scelta…\n"
	.string "Peccato che tu non lo capisca.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMIntro::
	.string "Ah!\n"
	.string "Sono {STR_VAR_1}, un ESPERTO!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon1::
	.string "I POKéMON che ho temprato sono\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "Che dici di far squadra con me?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMAccept::
	.string "Ah!\n"
	.string "Ci registro subito!\l"
	.string "Diamo il massimo, entrambi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMReject::
	.string "Spero che la tua scelta sia\n"
	.string "giusta…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFIntro::
	.string "Salve, salve.\n"
	.string "Sono {STR_VAR_1}, un'ESPERTA.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon1::
	.string "Ho allevato i POKéMON a dovere.\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}:\n"
	.string "ho solo quelli.\p"
	.string "Vuoi fare squadra con me?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFAccept::
	.string "Bene, bene.\n"
	.string "Mi occupo subito della registrazione.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFReject::
	.string "Forse faremo squadra alla prossima\n"
	.string "volta che ci incontriamo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerIntro::
	.string "Sono il DOMADRAHI {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon1::
	.string "Ho allenato una squadra con\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "Che ne dici?\n"
	.string "Vuoi fare squadra con me?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerAccept::
	.string "Va bene, farò del mio meglio!\n"
	.string "Mi registro subito, va bene?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerReject::
	.string "Non troverai partner più forti\n"
	.string "di me!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperIntro::
	.string "BIRD KEEPER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon1::
	.string "Quali POKéMON ho?\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Don't you think we'd make a decent\n"
	.string "tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperAccept::
	.string "Grazie mille!\n"
	.string "Penso io alla registrazione!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperReject::
	.string "I miei POKéMON sono forti.\n"
	.string "Che delusione.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyIntro::
	.string "Il NINJA BOY {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon1::
	.string "La mia squadra POKéMON ha un\n"
	.string "{STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon2Ask::
	.string "Un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "Facciamo squadra insieme!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyAccept::
	.string "Sì!\n"
	.string "Vado a registrarmi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyReject::
	.string "Ti pentirai di non avere i\n"
	.string "miei forti POKéMON!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyIntro::
	.string "Ciao!\n"
	.string "Sono OMBRELLINA {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon1::
	.string "Mi accompagnano un {STR_VAR_2}\n"
	.string "che usa {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon2Ask::
	.string "un {STR_VAR_2} che usa\n"
	.string "{STR_VAR_1}.\p"
	.string "Sono carini, eh?\n"
	.string "Ti va di far squadra?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyAccept::
	.string "Grazie mille!\p"
	.string "Vado a registrarmi.\n"
	.string "Non deluderemo l'altro!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyReject::
	.string "I miei POKéMON sono fortissimi.\n"
	.string "Che delusione…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacIntro::
	.string "Salve.\n"
	.string "Sono {STR_VAR_1}, COLEOTTOMANE!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon1::
	.string "Sì, ho scelto i miei POKéMON.\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}:\n"
	.string "sono i miei trovati.\p"
	.string "Ti andrebbe di fare\n"
	.string "squadra con me?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacAccept::
	.string "Va bene!\n"
	.string "Capito!\p"
	.string "Faccio in fretta a registrarci.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacReject::
	.string "Con i POKéMON che ho trovato\n"
	.string "non perderemmo…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorIntro::
	.string "Ehilà!\n"
	.string "Sono il MARINAIO {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon1::
	.string "Ti mostro il mio vanto!\n"
	.string "Uno {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "Mica mi dirai di no,\n"
	.string "vero? Facciamo squadra, eh?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorAccept::
	.string "Me l'aspettavo!\n"
	.string "Vado a iscrivermi ora.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorReject::
	.string "Avremmo spazzato via\n"
	.string "tutti! Peccato!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorIntro::
	.string "Ciao, sono {STR_VAR_1}.\n"
	.string "Sono un COLLEZIONISTA.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon1::
	.string "I gioielli della mia collezione\n"
	.string "sono il mio {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "Fantastico, vero?\n"
	.string "Dovremmo fare squadra insieme.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorAccept::
	.string "Oh, sì!\p"
	.string "Non perdiamo tempo allora.\n"
	.string "Vado a registrarci io.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorReject::
	.string "Beh, che dispiacere.\n"
	.string "Non apprezzi i miei POKéMON.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMIntro::
	.string "Ehilà, sono {STR_VAR_1}.\n"
	.string "Sono un RANGER POKéMON.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon1::
	.string "Mi fanno compagnia un\n"
	.string "{STR_VAR_2} con {STR_VAR_1} e un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Don't you think we'd make an impressive\n"
	.string "tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMAccept::
	.string "Fantastico!\n"
	.string "Penso io alla registrazione.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMReject::
	.string "La prossima volta scegli\n"
	.string "i miei POKéMON, eh?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFIntro::
	.string "Mi chiamo {STR_VAR_1}.\n"
	.string "Sono un RANGER POKéMON!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon1::
	.string "Ecco la mia squadra: ho\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "Ti va di formare una squadra\n"
	.string "con la mia comitiva?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFAccept::
	.string "Saremo al top!\n"
	.string "Registro io, in un attimo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFReject::
	.string "La prossima volta scegli\n"
	.string "i miei POKéMON.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyIntro::
	.string "Piacere, sono {STR_VAR_1}.\n"
	.string "Sono un'AROMA LADY.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon1::
	.string "Viaggio con un {STR_VAR_2}\n"
	.string "che usa {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon2Ask::
	.string "un {STR_VAR_2} che usa\n"
	.string "{STR_VAR_1}.\p"
	.string "Spero ti piacciano.\n"
	.string "Vuoi fare squadra con me?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyAccept::
	.string "L'onore è mio, grazie.\n"
	.string "Vado subito a registrarmi.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyReject::
	.string "Che bello se alla prossima\n"
	.string "volta facessimo squadra.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacIntro::
	.string "Vuoi sapere chi sono?\n"
	.string "Sono {STR_VAR_1}, RUIN MANIAC!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon1::
	.string "I POKéMON che porto sono\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "Interessante, eh?\n"
	.string "Facciamo coppia, che ne dici?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacAccept::
	.string "Saggia decisione!\n"
	.string "Vado a fare le pratiche.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacReject::
	.string "Hmm…\n"
	.string "I miei POKéMON sono forti…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMIntro::
	.string "Sono la CERTIFICANTE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon1::
	.string "I POKéMON che ho ora sono un\n"
	.string "{STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\n"
	.string "Figo, eh?\p"
	.string "Non credi sarebbe fantastico\n"
	.string "farci una coppia?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMAccept::
	.string "Grande!\n"
	.string "Vado a farci registrare in un lampo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMReject::
	.string "Pensavo che avremmo formato\n"
	.string "la squadra più forte di sempre.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFIntro::
	.string "Sono la CERTIFICANTE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon1::
	.string "La squadra che sto allevando ha un\n"
	.string "{STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Ti sembra va bene?\n"
	.string "Facciamo coppia, che ne dici?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFAccept::
	.string "Perfetto!\n"
	.string "Meglio che faccia la registrazione.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFReject::
	.string "Pensavo che saremmo stati\n"
	.string "una squadra fortissima…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacIntro::
	.string "Ehi!\n"
	.string "Sono {STR_VAR_1}, un POKéMANIAC!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon1::
	.string "Cosa avrà uno come me?\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1},\n"
	.string "ecco cosa!\p"
	.string "Si parte!\n"
	.string "Faremo scempio in coppia!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacAccept::
	.string "Ottima scelta!\n"
	.string "Vi registro entrambi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacReject::
	.string "I miei POKéMON sono brutali!\n"
	.string "Se te ne pentirai, non è colpa mia!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerIntro::
	.string "Ehi, ciao!\n"
	.string "Il PIROMANTE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon1::
	.string "Sai cosa mi ha dato l'allenamento?\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon2Ask::
	.string "e un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "Allora, che dici?\n"
	.string "Facciamo una squadra?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerAccept::
	.string "Perfetto!\n"
	.string "Procedo con la registrazione.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerReject::
	.string "Prometti che farai squadra con me\n"
	.string "la prossima volta che ci incontriamo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperIntro::
	.string "Sono CAMPEGGIATORE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon1::
	.string "Allevio un {STR_VAR_1} con\n"
	.string "un {STR_VAR_2}, e un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon2Ask::
	.string "{STR_VAR_2} che usa {STR_VAR_1}.\p"
	.string "Ti farebbe divertire un team?\n"
	.string "Scommetto di sì!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperAccept::
	.string "Sì!\n"
	.string "Vado a registrarmi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperReject::
	.string "La prossima volta, va?\n"
	.string "Voglio stare nel tuo team.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerIntro::
	.string "Ciao!\n"
	.string "Sono {STR_VAR_1}, CAMPIAGNOLA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon1::
	.string "I miei POKéMON sono\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Are you interested in joining me\n"
	.string "on a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerAccept::
	.string "Oh, grazie!\n"
	.string "Ora vado a registrarmi.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerReject::
	.string "Sarebbe bello fare squadra\n"
	.string "un'altra volta.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMIntro::
	.string "Sono il PSICHICO {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon1::
	.string "I due che allevo sono\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Vuoi formare una coppia\n"
	.string "con me?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMAccept::
	.string "Volentieri!\n"
	.string "Penso io alla registrazione!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMReject::
	.string "Se ci rincontreremo, allora vorrei\n"
	.string "far coppia con te.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFIntro::
	.string "Sono {STR_VAR_1}.\n"
	.string "Sono una PSICHICA.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon1::
	.string "Un {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1},\n"
	.string "sono i miei discepoli.\p"
	.string "L'idea di fare una coppia\n"
	.string "di lotta ti tenta?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFAccept::
	.string "Grazie.\n"
	.string "Penso io alla registrazione.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFReject::
	.string "Spero ci sia un'altra occasione\n"
	.string "per stringere un'alleanza.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFIntro::
	.string "Sono lo SCOLARO {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon1::
	.string "Uno {STR_VAR_2} con {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon2Ask::
	.string "e un {STR_VAR_1}-uso\n"
	.string "{STR_VAR_2} sono la mia coppia.\p"
	.string "Posso essere la tua partner\n"
	.string "in una squadra?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFAccept::
	.string "Oh, grazie!\n"
	.string "Vado subito a iscrivermi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFReject::
	.string "Dai…\n"
	.string "Potrei unirmi a te un'altra volta?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFIntro::
	.string "Ehilà! Sono {STR_VAR_1}!\n"
	.string "Sono un ALLEVATORE!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon1::
	.string "I POKéMON che allevai sono\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Interessante, eh?\n"
	.string "Facciamo una squadra, così?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFAccept::
	.string "Perfetto!\n"
	.string "Penserò io alla registrazione!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFReject::
	.string "La prossima volta fai squadra\n"
	.string "con me, va bene?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFIntro::
	.string "Sono {STR_VAR_1} e lo dico\n"
	.string "con Orgoglio: sono un POKéFAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon1::
	.string "I tesori che ho cresciuto sono\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Non sono adorabili?\n"
	.string "Dobbiamo far squadra!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFAccept::
	.string "Grazie, caro!\n"
	.string "Vado a registrarci!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFReject::
	.string "I miei tesori sono i migliori,\n"
	.string "lo sapevi. Che seccatura!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFIntro::
	.string "Ciao, sono la NUOTATRICE {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon1::
	.string "Uno {STR_VAR_2} con {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon2Ask::
	.string "e un {STR_VAR_1}-uso\n"
	.string "{STR_VAR_2} sono i miei.\p"
	.string "Facciamo squadra, tu e io.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFAccept::
	.string "Fantastico!\n"
	.string "Iscrivo noi due.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFReject::
	.string "Se ci rivediamo, mi devi\n"
	.string "una squadra!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMIntro::
	.string "Come va?\n"
	.string "Sono {STR_VAR_1}, un TRIATLETA.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon1::
	.string "Ho dei POKéMON per bene.\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "Sarebbe bello fare coppia\n"
	.string "insieme, che ne dici?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMAccept::
	.string "Perfetto!\n"
	.string "Aspetta che mi registro, ok?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMReject::
	.string "I expect you'll let me join you\n"
	.string "next time, how's that?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFIntro::
	.string "Sono la TRIATLETA {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon1::
	.string "Un {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon2Ask::
	.string "un altro {STR_VAR_2} che sa usare\n"
	.string "{STR_VAR_1}. La mia coppia.\p"
	.string "Che ne pensi?\n"
	.string "Insieme saremmo forti, direi.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFAccept::
	.string "Mi piace la risposta!\n"
	.string "Finisco subito la registrazione!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFReject::
	.string "Mi darai un'altra occasione\n"
	.string "di fare squadra, vero?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMIntro::
	.string "Ciao, ciao! Ehilà!\n"
	.string "Sono {STR_VAR_1}, un NUOTATORE!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon1::
	.string "Guarda un po' i miei POKéMON!\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "Che coppia, eh?\n"
	.string "Faremmo un bel team, vero?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMAccept::
	.string "Grazie mille!\n"
	.string "Completo subito la registrazione!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMReject::
	.string "Se ci si rivede, fai squadra\n"
	.string "con me. D'accordo, eh?$"

