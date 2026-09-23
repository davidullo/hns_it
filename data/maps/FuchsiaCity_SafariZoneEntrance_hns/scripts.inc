FuchsiaCity_SafariZoneEntrance_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FuchsiaCity_SafariZoneEntrance_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_SafariZoneEntrance_OnTransition
	.byte 0

FuchsiaCity_SafariZoneEntrance_OnFrame::
	map_script_2 VAR_KANTO_SAFARI_ZONE_PROGRESS, 0, FuchsiaCity_SafariZoneEntrance_EventScript_MeetSteven
	map_script_2 VAR_SAFARI_ZONE_STATE, 2, FuchsiaCity_SafariZoneEntrance_EventScript_ExitSafari
	.2byte 0

FuchsiaCity_SafariZoneEntrance_OnTransition::
	call_if_eq VAR_KANTO_SAFARI_ZONE_PROGRESS, 0, FuchsiaCity_SafariZoneEntrance_FirstTime
	end

FuchsiaCity_SafariZoneEntrance_FirstTime::
	setobjectxyperm LOCALID_SAFARIZONEFUCHSIA_STEVEN, 4, 10
	setobjectmovementtype LOCALID_SAFARIZONEFUCHSIA_STEVEN, MOVEMENT_TYPE_FACE_LEFT
	end

FuchsiaCity_SafariZoneEntrance_EventScript_ExitSafari::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_EventScript_ReenterSafari
	clearflag FLAG_IN_KANTO_SAFARI_ZONE
	special ExitSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 1
	setflag FLAG_GOOD_LUCK_SAFARI_ZONE
	msgbox SafariZone_South_Text_ExitEarlyThankYouForPlaying
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_SafariZoneEntrance_Movement_ExitSafariZone
	waitmovement 0
	release
	end
 
FuchsiaCity_SafariZoneEntrance_EventScript_ReenterSafari::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	warp MAP_FUCHSIA_CITY_SAFARI_ZONE_BEACH_HNS, 0
	waitstate
	end

FuchsiaCity_SafariZoneEntrance_EventScript_MeetSteven::
	lock
	playse SE_PIN
	applymovement LOCALID_SAFARIZONEFUCHSIA_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SAFARIZONEFUCHSIA_STEVEN
	applymovement LOCALID_SAFARIZONEFUCHSIA_STEVEN, FuchsiaCity_SafariZoneEntrance_Movement_WalkToPlayer
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement LOCALID_SAFARIZONEFUCHSIA_STEVEN

	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenWelcome, MSGBOX_DEFAULT
	closemessage
	checkitem ITEM_POKEBLOCK_CASE
	call_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_EventScript_StevenGiveCase

	applymovement LOCALID_SAFARIZONEFUCHSIA_STEVEN, FuchsiaCity_SafariZoneEntrance_Movement_ReturnToTable
	waitmovement 0
	setvar VAR_KANTO_SAFARI_ZONE_PROGRESS, 1
	release
	end

FuchsiaCity_SafariZoneEntrance_EventScript_StevenGiveCase::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenGiveCase, MSGBOX_DEFAULT
	giveitem ITEM_POKEBLOCK_CASE
	closemessage
	return

FuchsiaCity_SafariZoneEntrance_Text_StevenGiveCase:
	.string "Ah, ti servirà questo.$"

FuchsiaCity_SafariZoneEntrance_Steven::
	lock
	faceplayer
	checkitem ITEM_EON_TICKET
	goto_if_eq VAR_RESULT, TRUE, FuchsiaCity_SafariZoneEntrance_EventScript_Steven_Trade
	goto_if_set FLAG_IS_KANTO_CHAMPION, FuchsiaCity_SafariZoneEntrance_StevenChamp
	msgbox FuchsiaCity_SafariZoneEntrance_Text_Steven, MSGBOX_NPC
	release
	end

FuchsiaCity_SafariZoneEntrance_StevenChamp::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenChamp, MSGBOX_DEFAULT
	giveitem ITEM_EON_TICKET
	closemessage
	release
	end

FuchsiaCity_SafariZoneEntrance_Text_StevenChamp:
	.string "Ehi, {PLAYER}!\n"
	.string "O meglio, campione di KANTO?\p"
	.string "Sai, per un po' sono stato il\n"
	.string "campione della regione HOENN.\p"
	.string "Quindi, entra nel club, {PLAYER}.\p"
	.string "Anzi, tieni.\n"
	.string "Un regalo di benvenuto.$"

FuchsiaCity_SafariZoneEntrance_EventScript_EntranceCounterTrigger::
	lockall
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	showmoneybox 0, 0
	msgbox Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_SafariZoneEntrance_EventScript_TryEnterSafariZone
	msgbox Route121_SafariZoneEntrance_Text_PlayAnotherTime, MSGBOX_DEFAULT
	goto FuchsiaCity_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

FuchsiaCity_SafariZoneEntrance_EventScript_TryEnterSafariZone::
	checkitem ITEM_POKEBLOCK_CASE
	goto_if_eq VAR_RESULT, 0, FuchsiaCity_SafariZoneEntrance_EventScript_NoPokeblockCase
	call FuchsiaCity_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon
	checkmoney 500
	goto_if_eq VAR_RESULT, 0, FuchsiaCity_SafariZoneEntrance_EventScript_NotEnoughMoney
	msgbox Route121_SafariZoneEntrance_Text_ThatWillBe500Please, MSGBOX_DEFAULT
	removemoney 500
	playse SE_SHOP
	updatemoneybox
	msgbox Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message Route121_SafariZoneEntrance_Text_Received30SafariBalls
	waitfanfare
	msgbox Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 4, FuchsiaCity_SafariZoneEntrance_EventScript_CorrectionLeft
	call_if_eq VAR_TEMP_0, 6, FuchsiaCity_SafariZoneEntrance_EventScript_CorrectionRight
	applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_SafariZoneEntrance_Movement_EnterSafariZone
	waitmovement 0
	setflag FLAG_IN_KANTO_SAFARI_ZONE
	special EnterSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 2
	clearflag FLAG_GOOD_LUCK_SAFARI_ZONE
	warp MAP_FUCHSIA_CITY_SAFARI_ZONE_BEACH_HNS, 1
	waitstate
	end

FuchsiaCity_SafariZoneEntrance_EventScript_CorrectionRight::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	return

FuchsiaCity_SafariZoneEntrance_EventScript_CorrectionLeft::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	return

FuchsiaCity_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon::
	getpartysize
	goto_if_ne VAR_RESULT, PARTY_SIZE, FuchsiaCity_SafariZoneEntrance_EventScript_HasRoomForPokemon
	specialvar VAR_RESULT, ScriptCheckFreePokemonStorageSpace
	goto_if_eq VAR_RESULT, 1, FuchsiaCity_SafariZoneEntrance_EventScript_HasRoomForPokemon
	msgbox Route121_SafariZoneEntrance_Text_PCIsFull, MSGBOX_DEFAULT
	goto FuchsiaCity_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

FuchsiaCity_SafariZoneEntrance_EventScript_HasRoomForPokemon::
	return

FuchsiaCity_SafariZoneEntrance_EventScript_NoPokeblockCase::
	msgbox Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase, MSGBOX_DEFAULT
	goto FuchsiaCity_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

FuchsiaCity_SafariZoneEntrance_EventScript_NotEnoughMoney::
	msgbox Route121_SafariZoneEntrance_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto FuchsiaCity_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

FuchsiaCity_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter::
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_SafariZoneEntrance_Movement_BackAwayFromCounter
	waitmovement 0
	releaseall
	end

FuchsiaCity_SafariZoneEntrance_Movement_BackAwayFromCounter:
	walk_down
	step_end

FuchsiaCity_SafariZoneEntrance_Movement_EnterSafariZone:
	walk_up
	walk_up
	walk_up
	step_end

FuchsiaCity_SafariZoneEntrance_Movement_ExitSafariZone:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

FuchsiaCity_SafariZoneEntrance_Movement_WalkToPlayer:
	walk_right
	walk_down
	step_end

FuchsiaCity_SafariZoneEntrance_Movement_ReturnToTable:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	face_right
	step_end

FuchsiaCity_SafariZoneEntrance_Text_StevenWelcome:
	.string "Rieccoti, {PLAYER}!\p"
	.string "Eccoti nella ZONA SAFARI DEVON!\p"
	.string "Questo safari creato apposta\n"
	.string "ha 4 habitat diversi che\l"
	.string "attira e ospita specie invasive\l"
	.string "diverse dalla regione HOENN.\p"
	.string "Invitiamo gli allenatori a\n"
	.string "catturarne il più possibile\l"
	.string "e a toglierle dall'ambiente.\p"
	.string "Troverai POKéMON rarissimi\n"
	.string "qui. Soprattutto se alzi il\l"
	.string "LIVELLO SAFARI.\p"
	.string "Parla con l'addetto\n"
	.string "quando vuoi: alza il LIVELLO\l"
	.string "SAFARI.$"

FuchsiaCity_SafariZoneEntrance_UpgradeGuy::
	goto_if_eq VAR_KANTO_SAFARI_ZONE_PROGRESS, 1, FuchsiaCity_SafariZoneEntrance_UpgradeGuy1
	goto_if_eq VAR_KANTO_SAFARI_ZONE_PROGRESS, 2, FuchsiaCity_SafariZoneEntrance_UpgradeGuy2
	goto_if_eq VAR_KANTO_SAFARI_ZONE_PROGRESS, 3, FuchsiaCity_SafariZoneEntrance_UpgradeGuy3
	msgbox FuchsiaCity_SafariZoneEntrance_Text_MaxLevel, MSGBOX_NPC
	end

FuchsiaCity_SafariZoneEntrance_UpgradeGuy1::
	showmoneybox 0, 0
	msgbox FuchsiaCity_SafariZoneEntrance_Text_Level1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyDecline
	checkmoney 200000
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyNotEnoughMoney
	removemoney 200000
	updatemoneybox 0
	playse SE_SHOP
	waitse
	msgbox FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyAccepted, MSGBOX_NPC
	setvar VAR_KANTO_SAFARI_ZONE_PROGRESS, 2
	hidemoneybox
	end

FuchsiaCity_SafariZoneEntrance_UpgradeGuy2::
	showmoneybox 0, 0
	msgbox FuchsiaCity_SafariZoneEntrance_Text_Level2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyDecline
	checkmoney 300000
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyNotEnoughMoney
	removemoney 300000
	updatemoneybox 0
	playse SE_SHOP
	waitse
	msgbox FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyAccepted, MSGBOX_NPC
	setvar VAR_KANTO_SAFARI_ZONE_PROGRESS, 3
	hidemoneybox
	end

FuchsiaCity_SafariZoneEntrance_UpgradeGuy3::
	showmoneybox 0, 0
	msgbox FuchsiaCity_SafariZoneEntrance_Text_Level3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyDecline
	checkmoney 400000
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyNotEnoughMoney
	removemoney 400000
	updatemoneybox 0
	playse SE_SHOP
	waitse
	msgbox FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyAccepted, MSGBOX_NPC
	setvar VAR_KANTO_SAFARI_ZONE_PROGRESS, 4
	hidemoneybox
	end

FuchsiaCity_SafariZoneEntrance_UpgradeGuyDecline::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyDeclined, MSGBOX_NPC
	hidemoneybox
	end

FuchsiaCity_SafariZoneEntrance_UpgradeGuyNotEnoughMoney::
	msgbox Route121_SafariZoneEntrance_Text_NotEnoughMoney, MSGBOX_NPC
	hidemoneybox
	end

FuchsiaCity_SafariZoneEntrance_Text_Steven:
	.string "Ciao, {PLAYER}!\p"
	.string "Ti piace il SAFARI?\p"
	.string "Hai visto pietre rare\n"
	.string "di recente?$"

FuchsiaCity_SafariZoneEntrance_Text_Level1:
	.string "Ciao {PLAYER}, vuoi\n"
	.string "portare il tuo LIVELLO SAFARI\l"
	.string "al 2? Costa ¥200.000.$"

FuchsiaCity_SafariZoneEntrance_Text_Level2:
	.string "Ciao {PLAYER}, vuoi\n"
	.string "portare il tuo LIVELLO SAFARI\l"
	.string "al 3? Costa ¥300.000.$"

FuchsiaCity_SafariZoneEntrance_Text_Level3:
	.string "Ciao {PLAYER}, vuoi\n"
	.string "portare il tuo LIVELLO SAFARI\l"
	.string "al 4? Costa ¥400.000.$"

FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyDeclined:
	.string "Oh, peccato allora…$"

FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyAccepted:
	.string "Vivi la ZONA SAFARI\n"
	.string "premium!$"

FuchsiaCity_SafariZoneEntrance_EventScript_Steven_Trade::
	goto_if_set FLAG_FUCHSIA_SAFARI_NPC_TRADE_COMPLETED, FuchsiaCity_SafariZoneEntrance_EventScript_StevenTradeCompleted
	ingame_trade INGAME_TRADE_BELDUM, FuchsiaCity_SafariZoneEntrance_Text_StevenWantToTrade, FuchsiaCity_SafariZoneEntrance_EventScript_StevenDeclineTrade, FuchsiaCity_SafariZoneEntrance_EventScript_StevenNotRequestedMon, FuchsiaCity_SafariZoneEntrance_Text_StevenTakeCare
	setflag FLAG_FUCHSIA_SAFARI_NPC_TRADE_COMPLETED
	release
	end

FuchsiaCity_SafariZoneEntrance_EventScript_StevenDeclineTrade::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenDeclineTrade, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_SafariZoneEntrance_EventScript_StevenNotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenNotRequestedMon, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_SafariZoneEntrance_EventScript_StevenTradeCompleted::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenTradeCompleted, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_SafariZoneEntrance_Text_StevenWantToTrade:
	.string "Oh, {PLAYER}…\n"
	.string "Sto allenando questo BELDUM\l"
	.string "da tempo ormai.\p"
	.string "Ma credo starebbe meglio\n"
	.string "con un bravo allenatore.\p"
	.string "Mi scambieresti {STR_VAR_1}\n"
	.string "col mio {STR_VAR_2}?$"

FuchsiaCity_SafariZoneEntrance_Text_StevenTakeCare:
	.string "Perfetto!\n"
	.string "Prenditi cura di FERRO.$"

FuchsiaCity_SafariZoneEntrance_Text_StevenDeclineTrade:
	.string "Va bene.\n"
	.string "L'offerta resta valida se\l"
	.string "cambi idea.$"

FuchsiaCity_SafariZoneEntrance_Text_StevenNotRequestedMon:
	.string "Hmm, non è un {STR_VAR_1}.\n"
	.string "Non è quello che avevo\l"
	.string "in mente.$"

FuchsiaCity_SafariZoneEntrance_Text_StevenTradeCompleted:
	.string "Come sta FERRO?\n"
	.string "POKéMON affascinanti, i BELDUM.\p"
	.string "Comunicano tra loro con\n"
	.string "impulsi magnetici.$"

FuchsiaCity_SafariZoneEntrance_Text_MaxLevel:
	.string "Ciao {PLAYER}, grazie per\n"
	.string "essere ancora un membro premium\l"
	.string "alla ZONA SAFARI FUCSIAPOLI.$"
