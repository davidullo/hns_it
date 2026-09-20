.equ REQUIRED_CAUGHT_MONS, 50

Route15_WestEntrance_2F_Frlg_MapScripts::
	.byte 0

Route15_WestEntrance_2F_EventScript_LeftBinoculars::
	lockall
	msgbox Route15_WestEntrance_2F_Text_LargeShiningBird
	showmonpic SPECIES_ARTICUNO, 10, 3
	delay 20
	waitbuttonpress
	hidemonpic
	setvar VAR_0x8004, SPECIES_ARTICUNO
	special SetSeenMon
	releaseall
	end

Route15_WestEntrance_2F_EventScript_RightBinoculars::
	msgbox Route15_WestEntrance_2F_Text_SmallIslandOnHorizon, MSGBOX_SIGN
	end

Route15_WestEntrance_2F_EventScript_Aide::
	lock
	faceplayer
	call Route15_WestEntrance_2F_EventScript_GetAideRequestInfo
	goto_if_set FLAG_GOT_EXP_SHARE_FROM_OAKS_AIDE, Route15_WestEntrance_2F_EventScript_AlreadyGotExpShare
	msgbox Route15_WestEntrance_2F_Text_GiveItemIfCaughtEnough, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Aide_EventScript_DeclineCheckMons
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetFrlgPokedexCount
	buffernumberstring STR_VAR_3, VAR_0x8006
	call Route15_WestEntrance_2F_EventScript_GetAideRequestInfo
	goto_if_lt VAR_0x8006, REQUIRED_CAUGHT_MONS, Aide_EventScript_HaventCaughtEnough
	msgbox Route15_WestEntrance_2F_Text_GreatHereYouGo
	checkitemspace ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Aide_EventScript_NoRoomForItem
	giveitem_msg Route15_WestEntrance_2F_Text_ReceivedItemFromAide, ITEM_EXP_SHARE
	setflag FLAG_GOT_EXP_SHARE_FROM_OAKS_AIDE
	msgbox Route15_WestEntrance_2F_Text_ExplainExpShare
	release
	end

Route15_WestEntrance_2F_EventScript_AlreadyGotExpShare::
	msgbox Route15_WestEntrance_2F_Text_ExplainExpShare
	release
	end

Route15_WestEntrance_2F_EventScript_GetAideRequestInfo::
	buffernumberstring STR_VAR_1, REQUIRED_CAUGHT_MONS
	bufferitemname STR_VAR_2, ITEM_EXP_SHARE
	return

Route15_WestEntrance_2F_Text_GiveItemIfCaughtEnough::
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

Route15_WestEntrance_2F_Text_GreatHereYouGo::
	.string "Bene! Hai catturato o posseduto\n"
	.string "{STR_VAR_3} specie di POKéMON!\p"
	.string "Congratulazioni!\n"
	.string "Tieni!$"

Route15_WestEntrance_2F_Text_ReceivedItemFromAide::
	.string "{PLAYER} riceve il {STR_VAR_2}\n"
	.string "dall'ASSISTENTE.$"

Route15_WestEntrance_2F_Text_ExplainExpShare::
	.string "CONDIVIDI ESP. è uno strumento da\n"
	.string "far tenere a un POKéMON.\p"
	.string "Il POKéMON riceverà una parte\n"
	.string "dei Punti ESP. senza dover\l"
	.string "lottare.$"

Route15_WestEntrance_2F_Text_LargeShiningBird::
	.string "Vediamo cosa mostrano\n"
	.string "i binocoli…\p"
	.string "Un grande uccello splendente vola\n"
	.string "verso il mare.$"

Route15_WestEntrance_2F_Text_SmallIslandOnHorizon::
	.string "Vediamo cosa mostrano\n"
	.string "i binocoli…\p"
	.string "Sembra una piccola isola\n"
	.string "all'orizzonte!$"

