.equ REQUIRED_CAUGHT_MONS, 40

Route16_NorthEntrance_2F_Frlg_MapScripts::
	.byte 0

Route16_NorthEntrance_2F_EventScript_LittleBoy::
	msgbox Route16_NorthEntrance_2F_Text_OnBikeRideWithGirlfriend, MSGBOX_NPC
	end

Route16_NorthEntrance_2F_EventScript_LittleGirl::
	msgbox Route16_NorthEntrance_2F_Text_RidingTogetherOnNewBikes, MSGBOX_NPC
	end

Route16_NorthEntrance_2F_EventScript_LeftBinoculars::
	msgbox Route16_NorthEntrance_2F_Text_ItsCeladonDeptStore, MSGBOX_SIGN
	end

Route16_NorthEntrance_2F_EventScript_RightBinoculars::
	msgbox Route16_NorthEntrance_2F_Text_LongPathOverWater, MSGBOX_SIGN
	end

Route16_NorthEntrance_2F_EventScript_Aide::
	lock
	faceplayer
	call Route16_NorthEntrance_2F_EventScript_GetAideRequestInfo
	goto_if_set FLAG_GOT_AMULET_COIN_FROM_OAKS_AIDE, Route16_NorthEntrance_2F_EventScript_AlreadyGotAmuletCoin
	msgbox Route16_NorthEntrance_2F_Text_GiveAmuletCoinIfCaught40, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Aide_EventScript_DeclineCheckMons
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetFrlgPokedexCount
	buffernumberstring STR_VAR_3, VAR_0x8006
	call Route16_NorthEntrance_2F_EventScript_GetAideRequestInfo
	goto_if_lt VAR_0x8006, REQUIRED_CAUGHT_MONS, Aide_EventScript_HaventCaughtEnough
	msgbox Route16_NorthEntrance_2F_Text_GreatHereYouGo
	checkitemspace ITEM_AMULET_COIN
	goto_if_eq VAR_RESULT, FALSE, Aide_EventScript_NoRoomForItem
	giveitem_msg Route16_NorthEntrance_2F_Text_ReceivedAmuletCoinFromAide, ITEM_AMULET_COIN
	setflag FLAG_GOT_AMULET_COIN_FROM_OAKS_AIDE
	msgbox Route16_NorthEntrance_2F_Text_ExplainAmuletCoin
	release
	end

Route16_NorthEntrance_2F_EventScript_AlreadyGotAmuletCoin::
	msgbox Route16_NorthEntrance_2F_Text_ExplainAmuletCoin
	release
	end

Route16_NorthEntrance_2F_EventScript_GetAideRequestInfo::
	buffernumberstring STR_VAR_1, REQUIRED_CAUGHT_MONS
	bufferitemname STR_VAR_2, ITEM_AMULET_COIN
	return

Route16_NorthEntrance_2F_Text_OnBikeRideWithGirlfriend::
	.string "Sto facendo un giro rilassante\n"
	.string "con la mia ragazza sulla bici nuova.$"

Route16_NorthEntrance_2F_Text_RidingTogetherOnNewBikes::
	.string "Andiamo in giro insieme\n"
	.string "con le bici nuove.$"

Route16_NorthEntrance_2F_Text_ItsCeladonDeptStore::
	.string "Vediamo cosa mostrano\n"
	.string "i binocoli…\p"
	.string "È il CENTRO COMMERCIALE\ndi AZZURROPOLI!$"

Route16_NorthEntrance_2F_Text_LongPathOverWater::
	.string "Vediamo cosa mostrano\n"
	.string "i binocoli…\p"
	.string "C'è un lungo sentiero sull'acqua\n"
	.string "in lontananza.$"

Route16_NorthEntrance_2F_Text_GiveAmuletCoinIfCaught40::
	.string "Ciao! Ti ricordi di me?\n"
	.string "Sono un ASSISTENTE del PROF. OAK.\p"
	.string "Se nel POKéDEX hai i dati\n"
	.string "di 40 specie, devo darti\l"
	.string "una ricompensa.\p"
	.string "Il PROF. OAK mi ha affidato\n"
	.string "una MONETAMULETO per te.\p"
	.string "Allora, {PLAYER}, ti chiedo:\p"
	.string "hai raccolto i dati su almeno\n"
	.string "40 tipi di POKéMON?$"

Route16_NorthEntrance_2F_Text_GreatHereYouGo::
	.string "Bene! Hai catturato o posseduto\n"
	.string "{STR_VAR_3} specie di POKéMON!\p"
	.string "Congratulazioni!\n"
	.string "Tieni!$"

Route16_NorthEntrance_2F_Text_ReceivedAmuletCoinFromAide::
	.string "{PLAYER} riceve la MONETAMULETO\n"
	.string "dall'ASSISTENTE.$"

Route16_NorthEntrance_2F_Text_ExplainAmuletCoin::
	.string "La MONETAMULETO è un oggetto\n"
	.string "da far tenere a un POKéMON.\p"
	.string "Se il POKéMON appare in una lotta\n"
	.string "vinta, guadagni più soldi.$"

