LavenderTown_House2_Frlg_MapScripts::
	.byte 0

LavenderTown_House2_EventScript_NameRater::
	lock
	faceplayer
	msgbox LavenderTown_House2_Text_WantMeToRateNicknames, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LavenderTown_House2_EventScript_ChooseMon
	goto_if_eq VAR_RESULT, NO, LavenderTown_House2_EventScript_DontRateNickname
	end

LavenderTown_House2_EventScript_ChooseMon::
	msgbox LavenderTown_House2_Text_CritiqueWhichMonsNickname
	special ChoosePartyMon
	waitstate
	goto_if_lt VAR_0x8004, PARTY_SIZE, LavenderTown_House2_EventScript_CheckCanRateMon
	goto_if_ge VAR_0x8004, PARTY_SIZE, LavenderTown_House2_EventScript_DontRateNickname
	end

LavenderTown_House2_EventScript_DontRateNickname::
	msgbox LavenderTown_House2_Text_ISeeComeVisitAgain
	release
	end

LavenderTown_House2_EventScript_CheckCanRateMon::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, LavenderTown_House2_EventScript_CantNicknameEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, TRUE, LavenderTown_House2_EventScript_CantNicknameTradeMon
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, LavenderTown_House2_EventScript_CantNicknameTradeMon
	msgbox LavenderTown_House2_Text_GiveItANicerName, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LavenderTown_House2_EventScript_ChooseNewNickname
	goto_if_eq VAR_RESULT, NO, LavenderTown_House2_EventScript_DontRateNickname
	end

LavenderTown_House2_EventScript_CantNicknameEgg::
	msgbox LavenderTown_House2_Text_ThatIsMerelyAnEgg
	release
	end

LavenderTown_House2_EventScript_CantNicknameTradeMon::
	msgbox LavenderTown_House2_Text_TrulyImpeccableName
	release
	end

LavenderTown_House2_EventScript_ChooseNewNickname::
	msgbox LavenderTown_House2_Text_WhatShallNewNicknameBe
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, LavenderTown_House2_EventScript_ChoseNewNickname
	msgbox LavenderTown_House2_Text_FromNowOnShallBeKnownAsSameName
	release
	end

LavenderTown_House2_EventScript_ChoseNewNickname::
	msgbox LavenderTown_House2_Text_FromNowOnShallBeKnownAsName
	release
	end

LavenderTown_House2_Text_WantMeToRateNicknames::
	.string "Ciao, ciao!\n"
	.string "Sono l'ONOMASTA ufficiale!\p"
	.string "Vuoi che valuti i soprannomi dei\n"
	.string "tuoi POKéMON?$"

LavenderTown_House2_Text_CritiqueWhichMonsNickname::
	.string "Il soprannome di quale\n"
	.string "POKéMON giudico?$"

LavenderTown_House2_Text_GiveItANicerName::
	.string "{STR_VAR_1}, giusto?\n"
	.string "È un bel soprannome!\p"
	.string "Ma vuoi che gliene dia\n"
	.string "uno migliore?\p"
	.string "Che ne dici?$"

LavenderTown_House2_Text_WhatShallNewNicknameBe::
	.string "Ah, bene. E quale sarà il\n"
	.string "nuovo soprannome?$"

LavenderTown_House2_Text_FromNowOnShallBeKnownAsName::
	.string "Fatto! Da ora questo POKéMON\n"
	.string "si chiamerà {STR_VAR_1}!\p"
	.string "È un nome migliore di prima!\n"
	.string "Che fortuna per te!$"

LavenderTown_House2_Text_ISeeComeVisitAgain::
	.string "Capisco.\n"
	.string "Torna a trovarmi.$"

LavenderTown_House2_Text_FromNowOnShallBeKnownAsSameName::
	.string "Fatto! Da ora questo POKéMON\n"
	.string "si chiamerà {STR_VAR_1}!\p"
	.string "Sembra uguale a prima,\n"
	.string "eppure è molto meglio!\p"
	.string "Che fortuna per te!$"

LavenderTown_House2_Text_TrulyImpeccableName::
	.string "{STR_VAR_1}, vero?\n"
	.string "Che nome davvero impeccabile!\p"
	.string "Prenditi cura di {STR_VAR_1}!$"

LavenderTown_House2_Text_ThatIsMerelyAnEgg::
	.string "Calma, calma.\n"
	.string "È solo un UOVO!$"

