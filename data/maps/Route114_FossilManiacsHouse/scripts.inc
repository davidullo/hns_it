Route114_FossilManiacsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsHouse_OnTransition
	.byte 0

Route114_FossilManiacsHouse_OnTransition:
	setflag FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE
	end

Route114_FossilManiacsHouse_EventScript_FossilManiacsBrother::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_DIG, Route114_FossilManiacsHouse_EventScript_ReceivedDig
	msgbox Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother, MSGBOX_DEFAULT
	giveitem ITEM_TM_DIG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_DIG
	release
	end

Route114_FossilManiacsHouse_EventScript_ReceivedDig::
	msgbox Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsHouse_EventScript_RockDisplay::
	msgbox Route114_FossilManiacsHouse_Text_RocksFillDisplayCase, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_EventScript_Bookshelf::
	msgbox Route114_FossilManiacsHouse_Text_CrammedWithBooks, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother:
	.string "Mio fratello è il MANIACO DEI FOSSILI…\n"
	.string "È un bravo tipo che ama i FOSSILI…\p"
	.string "Ama anche scavare buche…\n"
	.string "Ha scavato questa buca da solo…\p"
	.string "Prendi questo, così puoi usare FOSSA\n"
	.string "come mio fratello…$"

Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance:
	.string "Se fai usare FOSSA a un POKéMON in\n"
	.string "una grotta, torni all'ingresso…$"

Route114_FossilManiacsHouse_Text_RocksFillDisplayCase:
	.string "Rocce dalle forme strane riempiono\n"
	.string "la teca…$"

Route114_FossilManiacsHouse_Text_CrammedWithBooks:
	.string "LA COMPOSIZIONE DEGLI STRATI…\n"
	.string "COME LA PIOGGIA MODELLA IL SUOLO…\l"
	.string "PIETRE, TERRA E ROCCIA…\p"
	.string "È pieno zeppo di libri.$"

