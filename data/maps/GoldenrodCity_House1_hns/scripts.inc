GoldenrodCity_House1_hns_MapScripts::
	.byte 0

GoldenrodCity_NameRatersHouse_EventScript_ToggleShinies::
	lock
	msgbox GoldenrodCity_NameRatersHouse_Text_AskToggleShinies, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_NameRatersHouse_EventScript_ToggleShiniesRefused
	@special ToggleShinyColors
	msgbox GoldenrodCity_NameRatersHouse_Text_ToggleShinies, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_ToggleShiniesRefused::
	release
	end

GoldenrodCity_NameRatersHouse_Text_AskToggleShinies:
	.string "Vuoi cambiare l'impostazione dei\n"
	.string "Colori Alternativi?$"

GoldenrodCity_NameRatersHouse_Text_ToggleShinies:
	.string "Colori Alternativi attivati!\p"
	.string "Controlla l'impostazione alla\n"
	.string "SALA SFIDE di un PC.$"

GoldenrodCity_NameRatersHouse_EventScript_RenameRival::
	msgbox GoldenrodCity_NameRatersHouse_Text_RenameRival, MSGBOX_DEFAULT
	closemessage
	special NameRival
	waitstate
	end

GoldenrodCity_NameRatersHouse_Text_RenameRival:
	.string "È il telegiornale…\p"
	.string "La POLIZIA cerca questo\n"
	.string "RAGAZZO DAI CAPELLI ROSSI!\p"
	.string "Sai il suo nome?$"

GoldenrodCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox GoldenrodCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, GoldenrodCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate
	end

GoldenrodCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox GoldenrodCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	lock
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, GoldenrodCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate
	end

GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox GoldenrodCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, GoldenrodCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	@special IsMonOTIDNotPlayers
	@goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	@specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	@goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	msgbox GoldenrodCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, GoldenrodCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate
	end

GoldenrodCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox GoldenrodCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox GoldenrodCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_ChangeNickname::
	msgbox GoldenrodCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox GoldenrodCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_NewNameDifferent::
	msgbox GoldenrodCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_Text_PleasedToRateMonNickname:
	.string "Ciao, ciao! Sono l'ONOMANTE!\n"
	.string "Sono l'indovino dei nomi!\p"
	.string "Sarò felice di giudicare il\n"
	.string "soprannome del tuo POKéMON.$"

GoldenrodCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
	.string "Il soprannome di quale\n"
	.string "POKéMON giudico?$"

GoldenrodCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
	.string "Mmm… {STR_VAR_1}, vero?\n"
	.string "Bel nome, davvero.\p"
	.string "Ma! Che ne dici se ti\n"
	.string "suggerissi un nome migliore?$"

GoldenrodCity_NameRatersHouse_Text_WhatShallNewNameBe:
	.string "Ah, bene. E quale sarà il\n"
	.string "nuovo soprannome?$"

GoldenrodCity_NameRatersHouse_Text_MonShallBeKnownAsName:
	.string "Fatto! Da ora questo POKéMON\n"
	.string "si chiamerà {STR_VAR_1}!\p"
	.string "È un nome migliore di prima!\n"
	.string "Che fortuna per te!$"

GoldenrodCity_NameRatersHouse_Text_DoVisitAgain:
	.string "Capisco.\n"
	.string "Torna a trovarmi.$"

GoldenrodCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
	.string "Fatto! Da ora questo POKéMON\n"
	.string "si chiamerà {STR_VAR_1}!\p"
	.string "Sembra uguale a prima,\n"
	.string "eppure è molto meglio!\p"
	.string "Che fortuna per te!$"

GoldenrodCity_NameRatersHouse_Text_MagnificentName:
	.string "Mmm… {STR_VAR_1}!\p"
	.string "Che soprannome magnifico!\n"
	.string "È impeccabile, senza difetti!\p"
	.string "Custodisci con cura il tuo\n"
	.string "{STR_VAR_1}, ora e sempre.$"

GoldenrodCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string "Calma, calma.\n"
	.string "È solo un UOVO!$"


