SlateportCity_NameRatersHouse_MapScripts::
	.byte 0

SlateportCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	chooseboxmon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox SlateportCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, SlateportCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	msgbox SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox SlateportCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_ChangeNickname::
	msgbox SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_NewNameDifferent::
	msgbox SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname:
	.string "Ciao, ciao! Sono l'ONOMANTE!\n"
	.string "Sono l'indovino dei nomi!\p"
	.string "Sarò felice di giudicare il\n"
	.string "soprannome del tuo POKéMON.$"

SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
	.string "Il soprannome di quale\n"
	.string "POKéMON giudico?$"

SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
	.string "Mmm… {STR_VAR_1}, vero?\n"
	.string "Bel nome, davvero.\p"
	.string "Ma! Che ne dici se ti\n"
	.string "suggerissi un nome migliore?$"

SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe:
	.string "Ah, bene. E quale sarà il\n"
	.string "nuovo soprannome?$"

SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName:
	.string "Fatto! Da ora questo POKéMON\n"
	.string "si chiamerà {STR_VAR_1}!\p"
	.string "È un nome migliore di prima!\n"
	.string "Che fortuna per te!$"

SlateportCity_NameRatersHouse_Text_DoVisitAgain:
	.string "Capisco.\n"
	.string "Torna a trovarmi.$"

SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
	.string "Fatto! Da ora questo POKéMON\n"
	.string "si chiamerà {STR_VAR_1}!\p"
	.string "Sembra uguale a prima,\n"
	.string "eppure è molto meglio!\p"
	.string "Che fortuna per te!$"

SlateportCity_NameRatersHouse_Text_MagnificentName:
	.string "Mmm… {STR_VAR_1}!\p"
	.string "Che soprannome magnifico!\n"
	.string "È impeccabile, senza difetti!\p"
	.string "Custodisci con cura il tuo\n"
	.string "{STR_VAR_1}, ora e sempre.$"

SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string "Calma, calma.\n"
	.string "È solo un UOVO!$"

