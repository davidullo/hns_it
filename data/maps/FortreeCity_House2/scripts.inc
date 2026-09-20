FortreeCity_House2_MapScripts::
	.byte 0

FortreeCity_House2_EventScript_HiddenPowerGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_HIDDEN_POWER, FortreeCity_House2_EventScript_ExplainHiddenPower
	call_if_unset FLAG_MET_HIDDEN_POWER_GIVER, FortreeCity_House2_EventScript_Greeting
	msgbox FortreeCity_House2_Text_CoinInWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand2, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 0, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_YourHiddenPowerHasAwoken, MSGBOX_DEFAULT
	giveitem ITEM_TM_HIDDEN_POWER
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_HIDDEN_POWER
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_Greeting::
	msgbox FortreeCity_House2_Text_HiddenPowersArousedByNature, MSGBOX_DEFAULT
	setflag FLAG_MET_HIDDEN_POWER_GIVER
	return

FortreeCity_House2_EventScript_ExplainHiddenPower::
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_WrongGuess::
	msgbox FortreeCity_House2_Text_YouGuessedWrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_Text_HiddenPowersArousedByNature:
	.string "Persone… POKéMON…\p"
	.string "I loro poteri nascosti si destano\n"
	.string "vivendo in ambienti naturali…$"

FortreeCity_House2_Text_CoinInWhichHand:
	.string "Che questa vecchia veda se il tuo\n"
	.string "potere si è destato…\p"
	.string "Ho una moneta in mano.\p"
	.string "Dimmi, l'ho nascosta nella\n"
	.string "mano destra? O nella sinistra?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand:
	.string "Oh! Sì, giusto!\p"
	.string "Riproviamo.\p"
	.string "In quale mano ho nascosto la moneta?\n"
	.string "Destra o sinistra?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand2:
	.string "Oh! Sì, giusto!\p"
	.string "Riproviamo.\p"
	.string "In quale mano ho nascosto la moneta?\n"
	.string "Destra o sinistra?$"

FortreeCity_House2_Text_YourHiddenPowerHasAwoken:
	.string "Oh! Perfetto!\n"
	.string "Il tuo potere si è destato!\p"
	.string "Tieni, prendi questo e desta il\n"
	.string "potere dei tuoi POKéMON.$"

FortreeCity_House2_Text_ExplainHiddenPower:
	.string "FORZA NASCOSTA cambia a seconda\n"
	.string "del POKéMON.$"

FortreeCity_House2_Text_YouGuessedWrong:
	.string "No, peccato.\n"
	.string "Hai sbagliato.$"

