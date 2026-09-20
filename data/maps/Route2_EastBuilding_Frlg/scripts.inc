.equ REQUIRED_SEEN_MONS, 10

Route2_EastBuilding_Frlg_MapScripts::
	.byte 0

Route2_EastBuilding_EventScript_Aide::
	lock
	faceplayer
	call Route2_EastBuilding_EventScript_GetAideRequestInfo
	goto_if_set FLAG_GOT_HM05, Route2_EastBuilding_EventScript_AlreadyGotHM05
	msgbox Route2_EastBuilding_Text_GiveHM05IfSeen10Mons, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Aide_EventScript_DeclineCheckMons
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetFrlgPokedexCount
	buffernumberstring STR_VAR_3, VAR_0x8006
	call Route2_EastBuilding_EventScript_GetAideRequestInfo
	goto_if_lt VAR_0x8006, REQUIRED_SEEN_MONS, Aide_EventScript_HaventCaughtEnough
	msgbox Route2_EastBuilding_Text_GreatHereYouGo
	checkitemspace ITEM_HM05
	goto_if_eq VAR_RESULT, FALSE, Aide_EventScript_NoRoomForItem
	giveitem_msg Route2_EastBuilding_Text_ReceivedHM05FromAide, ITEM_HM05
	setflag FLAG_GOT_HM05
	msgbox Route2_EastBuilding_Text_ExplainHM05
	release
	end

Route2_EastBuilding_EventScript_AlreadyGotHM05::
	msgbox Route2_EastBuilding_Text_ExplainHM05
	release
	end

Route2_EastBuilding_EventScript_GetAideRequestInfo::
	buffernumberstring STR_VAR_1, REQUIRED_SEEN_MONS
	bufferitemname STR_VAR_2, ITEM_HM05
	return

Route2_EastBuilding_EventScript_Rocker::
	msgbox Route2_EastBuilding_Text_CanGetThroughRockTunnel, MSGBOX_NPC
	end

Route2_EastBuilding_Text_GiveHM05IfSeen10Mons::
	.string "Ciao! Ti ricordi di me?\n"
	.string "Sono uno degli AIUTANTI del PROF. OAK.\p"
	.string "Se il tuo POKéDEX ha i dati\n"
	.string "di dieci specie, devo\l"
	.string "darti una ricompensa.\p"
	.string "Il PROF. OAK mi ha affidato\n"
	.string "la MN05 per te.\p"
	.string "Allora, {PLAYER}, ti chiedo.\p"
	.string "Hai raccolto i dati di almeno\n"
	.string "dieci tipi di POKéMON?$"

Route2_EastBuilding_Text_GreatHereYouGo::
	.string "Bene! Hai catturato o posseduto\n"
	.string "{STR_VAR_3} specie di POKéMON!\p"
	.string "Congratulazioni!\n"
	.string "Tieni!$"

Route2_EastBuilding_Text_ReceivedHM05FromAide::
	.string "{PLAYER} riceve la MN05\n"
	.string "dall'AIUTANTE.$"

Route2_EastBuilding_Text_ExplainHM05::
	.string "La MN05 contiene la mossa\n"
	.string "BALENO.\p"
	.string "BALENO illumina anche le più\n"
	.string "buie caverne e sotterranei.$"

Route2_EastBuilding_Text_CanGetThroughRockTunnel::
	.string "Se un POKéMON impara BALENO, puoi\n"
	.string "passare dalla GALLERIA ROCCIA.$"

