CeladonCity_Condominiums_1F_Frlg_MapScripts::
	.byte 0

CeladonCity_Condominiums_1F_EventScript_TeaWoman::
	lock
	faceplayer
	goto_if_set FLAG_TALKED_TO_TEA_LADY_AFTER_HOF, CeladonCity_Condominiums_1F_EventScript_TeaWomanAfterTea
	goto_if_set FLAG_SYS_GAME_CLEAR, CeladonCity_Condominiums_1F_EventScript_TeaWomanMentionDaisy
	goto_if_set FLAG_GOT_TEA, CeladonCity_Condominiums_1F_EventScript_TeaWomanAfterTea
	msgbox CeladonCity_Condominiums_1F_Text_TryThisDrinkInstead
	setflag FLAG_GOT_TEA
	giveitem ITEM_TEA
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	msgbox CeladonCity_Condominiums_1F_Text_NothingBeatsThirstLikeTea
	release
	end

CeladonCity_Condominiums_1F_EventScript_TeaWomanAfterTea::
	msgbox CeladonCity_Condominiums_1F_Text_MyDearMonsKeepMeCompany
	release
	end

CeladonCity_Condominiums_1F_EventScript_TeaWomanMentionDaisy::
	famechecker FAMECHECKER_DAISY, 4
	setflag FLAG_TALKED_TO_TEA_LADY_AFTER_HOF
	msgbox CeladonCity_Condominiums_1F_Text_DaisyComesToBuyTea
	release
	end

CeladonCity_Condominiums_1F_EventScript_Meowth::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MEOWTH, CRY_MODE_NORMAL
	msgbox CeladonCity_Condominiums_1F_Text_Meowth
	waitmoncry
	release
	end

CeladonCity_Condominiums_1F_EventScript_Clefairy::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CLEFAIRY, CRY_MODE_NORMAL
	msgbox CeladonCity_Condominiums_1F_Text_Clefairy
	waitmoncry
	release
	end

CeladonCity_Condominiums_1F_EventScript_Nidoran::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_NIDORAN_F, CRY_MODE_NORMAL
	msgbox CeladonCity_Condominiums_1F_Text_Nidoran
	waitmoncry
	release
	end

CeladonCity_Condominiums_1F_EventScript_SuiteSign::
	msgbox CeladonCity_Condominiums_1F_Text_ManagersSuite, MSGBOX_SIGN
	end

CeladonCity_Condominiums_1F_Text_Meowth::
	.string "MEOWTH: Meow!$"

CeladonCity_Condominiums_1F_Text_TryThisDrinkInstead::
	.string "Non spendere tutti i soldi\n"
	.string "nelle bevande.\p"
	.string "Prova questo.$"

CeladonCity_Condominiums_1F_Text_NothingBeatsThirstLikeTea::
	.string "Niente spegne la sete come un\n"
	.string "TÈ.\p"
	.string "Il migliore, davvero.$"

CeladonCity_Condominiums_1F_Text_MyDearMonsKeepMeCompany::
	.string "I miei POKéMON mi fanno compagnia.\n"
	.string "MEOWTH porta pure a casa soldi!$"

CeladonCity_Condominiums_1F_Text_DaisyComesToBuyTea::
	.string "Oh, ciao, cara.\n"
	.string "Ti è piaciuto il mio Tè?\p"
	.string "A proposito, cara. Vieni\n"
	.string "per caso da BIANCAVILLA?\p"
	.string "Una ragazza di BIANCAVILLA, MARGI,\n"
	.string "beve Tè ogni giorno.\p"
	.string "Va al CENTRO COMMERCIALE di\n"
	.string "AZZURROPOLI a comprare il Tè.$"

CeladonCity_Condominiums_1F_Text_Clefairy::
	.string "CLEFAIRY: Pi pippippi!$"

CeladonCity_Condominiums_1F_Text_Nidoran::
	.string "NIDORAN♀: Kya kyaoo!$"

CeladonCity_Condominiums_1F_Text_ManagersSuite::
	.string "PALAZZINA AZZURROPOLI\n"
	.string "Uso del Direttore$"

