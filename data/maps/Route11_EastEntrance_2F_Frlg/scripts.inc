.equ REQUIRED_CAUGHT_MONS, 30

Route11_EastEntrance_2F_Frlg_MapScripts::
	.byte 0

Route11_EastEntrance_2F_EventScript_LeftBinoculars::
	lockall
	goto_if_set FLAG_WOKE_UP_ROUTE_12_SNORLAX, Route11_EastEntrance_2F_EventScript_LeftBinocularsSnorlaxGone
	msgbox Route11_EastEntrance_2F_Text_BigMonAsleepOnRoad
	releaseall
	end

Route11_EastEntrance_2F_EventScript_LeftBinocularsSnorlaxGone::
	msgbox Route11_EastEntrance_2F_Text_WhatABreathtakingView
	releaseall
	end

Route11_EastEntrance_2F_EventScript_RightBinoculars::
	msgbox Route11_EastEntrance_2F_Text_RockTunnelGoodRouteToLavender, MSGBOX_SIGN
	end

Route11_EastEntrance_2F_EventScript_Turner::
	lock
	faceplayer
	setvar VAR_0x8008, INGAME_TRADE_NIDORINOA
	call EventScript_GetInGameTradeSpeciesInfo
	goto_if_set FLAG_DID_NINA_TRADE, Route11_EastEntrance_2F_EventScript_AlreadyTraded
	msgbox Trade_Text_LookingForMonWannaTradeForMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route11_EastEntrance_2F_EventScript_DeclineTrade
	call EventScript_ChooseMonForInGameTrade
	goto_if_ge VAR_0x8004, PARTY_SIZE, Route11_EastEntrance_2F_EventScript_DeclineTrade
	call EventScript_GetInGameTradeSpecies
	goto_if_ne VAR_RESULT, VAR_0x8009, Route11_EastEntrance_2F_EventScript_NotRequestedMon
	call EventScript_DoInGameTrade
	msgbox Trade_Text_HeyThanks
	setflag FLAG_DID_NINA_TRADE
	release
	end

Route11_EastEntrance_2F_EventScript_DeclineTrade::
	msgbox Trade_Text_AwwOhWell
	release
	end

Route11_EastEntrance_2F_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox Trade_Text_WhatThatsNoMon
	release
	end

Route11_EastEntrance_2F_EventScript_AlreadyTraded::
	msgbox Trade_Text_IsntMyOldMonGreat
	release
	end

Route11_EastEntrance_2F_EventScript_Aide::
	lock
	faceplayer
	call Route11_EastEntrance_2F_EventScript_GetAideRequestInfo
	goto_if_set FLAG_GOT_ITEMFINDER, Route11_EastEntrance_2F_EventScript_AlreadyGotItemfinder
	msgbox Route11_EastEntrance_2F_Text_GiveItemfinderIfCaught30, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Aide_EventScript_DeclineCheckMons
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetFrlgPokedexCount
	buffernumberstring STR_VAR_3, VAR_0x8006
	call Route11_EastEntrance_2F_EventScript_GetAideRequestInfo
	goto_if_lt VAR_0x8006, REQUIRED_CAUGHT_MONS, Aide_EventScript_HaventCaughtEnough
	msgbox Route11_EastEntrance_2F_Text_GreatHereYouGo
	checkitemspace ITEM_ITEMFINDER
	goto_if_eq VAR_RESULT, FALSE, Aide_EventScript_NoRoomForItem
	giveitem_msg Route11_EastEntrance_2F_Text_ReceivedItemfinderFromAide, ITEM_ITEMFINDER
	setflag FLAG_GOT_ITEMFINDER
	msgbox Route11_EastEntrance_2F_Text_ExplainItemfinder
	release
	end

Route11_EastEntrance_2F_EventScript_AlreadyGotItemfinder::
	msgbox Route11_EastEntrance_2F_Text_ExplainItemfinder
	release
	end

Route11_EastEntrance_2F_EventScript_GetAideRequestInfo::
	buffernumberstring STR_VAR_1, REQUIRED_CAUGHT_MONS
	bufferitemname STR_VAR_2, ITEM_ITEMFINDER
	return

Route11_EastEntrance_2F_Text_GiveItemfinderIfCaught30::
	.string "Ciao! Ti ricordi di me?\n"
	.string "Sono uno degli ASSISTENTI del PROF. OAK.\p"
	.string "Se il tuo POKéDEX ha dati completi\n"
	.string "su {STR_VAR_1} specie, dovrei\l"
	.string "darti una ricompensa.\p"
	.string "Il PROF. OAK mi ha affidato il\n"
	.string "{STR_VAR_2} per te.\p"
	.string "Allora, {PLAYER}, ti chiedo.\p"
	.string "Hai raccolto dati su almeno\n"
	.string "{STR_VAR_1} specie di POKéMON?$"

Route11_EastEntrance_2F_Text_GreatHereYouGo::
	.string "Bene! Hai catturato o posseduto\n"
	.string "{STR_VAR_3} specie di POKéMON!\p"
	.string "Congratulazioni!\n"
	.string "Tieni!$"

Route11_EastEntrance_2F_Text_ReceivedItemfinderFromAide::
	.string "{PLAYER} riceve il {STR_VAR_2}\n"
	.string "dall'ASSISTENTE.$"

Route11_EastEntrance_2F_Text_ExplainItemfinder::
	.string "Ci sono oggetti a terra che\n"
	.string "possono restare nascosti.\p"
	.string "Usa il DETECTOR per trovare gli\n"
	.string "oggetti nascosti vicino a te.\p"
	.string "La macchina è un po' limitata.\n"
	.string "Non indica il punto esatto.\p"
	.string "Quello che fa è mostrare la direzione\n"
	.string "in cui si trova l'oggetto.\p"
	.string "Usala per orientarti, poi\n"
	.string "cerca a mano nella zona.$"

Route11_EastEntrance_2F_Text_BigMonAsleepOnRoad::
	.string "Vediamo cosa mostrano\n"
	.string "i binocoli…\p"
	.string "Un grosso POKéMON dorme sulla strada!$"

Route11_EastEntrance_2F_Text_WhatABreathtakingView::
	.string "Vediamo cosa mostrano\n"
	.string "i binocoli…\p"
	.string "Che panorama mozzafiato!$"

Route11_EastEntrance_2F_Text_RockTunnelGoodRouteToLavender::
	.string "Vediamo cosa mostrano\n"
	.string "i binocoli…\p"
	.string "Per andare a LAVANDONIA da\n"
	.string "CELESTOPOLI…\p"
	.string "la GROTTA ROCCIOSA sembra\n"
	.string "una buona strada.$"

