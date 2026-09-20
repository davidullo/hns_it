Route12_NorthEntrance_2F_Frlg_MapScripts::
	.byte 0

Route12_NorthEntrance_2F_EventScript_LeftBinoculars::
	msgbox Route12_NorthEntrance_2F_Text_TheresManFishing, MSGBOX_SIGN
	end

Route12_NorthEntrance_2F_EventScript_RightBinoculars::
	msgbox Route12_NorthEntrance_2F_Text_ItsPokemonTower, MSGBOX_SIGN
	end

Route12_NorthEntrance_2F_EventScript_Lass::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM27, Route12_NorthEntrance_2F_EventScript_ExplainTM27
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route12_NorthEntrance_2F_EventScript_TakeTMMale
	call_if_eq VAR_RESULT, FEMALE, Route12_NorthEntrance_2F_EventScript_TakeTMFemale
	checkitemspace ITEM_TM27
	goto_if_eq VAR_RESULT, FALSE, Route12_NorthEntrance_2F_EventScript_NoRoomForTM27
	giveitem_msg Route12_NorthEntrance_2F_Text_ReceivedTM27FromLittleGirl, ITEM_TM27
	msgbox Route12_NorthEntrance_2F_Text_ExplainTM27
	setflag FLAG_GOT_TM27
	release
	end

Route12_NorthEntrance_2F_EventScript_TakeTMMale::
	msgbox Route12_NorthEntrance_2F_Text_TakeTMDontNeedAnymoreMale
	return

Route12_NorthEntrance_2F_EventScript_TakeTMFemale::
	msgbox Route12_NorthEntrance_2F_Text_TakeTMDontNeedAnymoreFemale
	return

Route12_NorthEntrance_2F_EventScript_NoRoomForTM27::
	msgbox Route12_NorthEntrance_2F_Text_DontHaveRoomForThis
	release
	end

Route12_NorthEntrance_2F_EventScript_ExplainTM27::
	msgbox Route12_NorthEntrance_2F_Text_ExplainTM27
	release
	end

@ Male and female text identical, differ (presumably) in JP
Route12_NorthEntrance_2F_Text_TakeTMDontNeedAnymoreMale::
	.string "Le ceneri dei miei POKéMON sono\n"
	.string "nella TORRE POKéMON.\p"
	.string "Puoi prendere questa MT.\n"
	.string "Non mi serve più…$"

Route12_NorthEntrance_2F_Text_TakeTMDontNeedAnymoreFemale::
	.string "Le ceneri dei miei POKéMON sono\n"
	.string "nella TORRE POKéMON.\p"
	.string "Puoi prendere questa MT.\n"
	.string "Non mi serve più…$"

Route12_NorthEntrance_2F_Text_ReceivedTM27FromLittleGirl::
	.string "{PLAYER} ha ricevuto la MT27\n"
	.string "dalla bambina.$"

Route12_NorthEntrance_2F_Text_ExplainTM27::
	.string "La MT27 è la mossa RITORNO…\p"
	.string "Se tratti bene i POKéMON,\n"
	.string "ti ricambieranno l'affetto dando\l"
	.string "il massimo in lotta.$"

Route12_NorthEntrance_2F_Text_DontHaveRoomForThis::
	.string "Non hai spazio per questo.$"

Route12_NorthEntrance_2F_Text_TheresManFishing::
	.string "Vediamo cosa mostrano\n"
	.string "i binocoli…\p"
	.string "C'è un uomo che pesca!$"

Route12_NorthEntrance_2F_Text_ItsPokemonTower::
	.string "Vediamo cosa mostrano\n"
	.string "i binocoli…\p"
	.string "È la TORRE POKéMON!$"

