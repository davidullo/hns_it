MauvilleCity_BikeShop_MapScripts::
	.byte 0

MauvilleCity_BikeShop_EventScript_Rydel::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_AskSwitchBikes
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_SkipGreeting
	msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_SkipGreeting::
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_ChooseBike::
	message MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne
	waitmessage
	multichoice 21, 8, MULTI_BIKE, TRUE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_GetMachBike
	case 1, MauvilleCity_BikeShop_EventScript_GetAcroBike
	end

MauvilleCity_BikeShop_EventScript_NotFar::
	setflag FLAG_DECLINED_BIKE
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_YesFar::
	setflag FLAG_RECEIVED_BIKE
	goto MauvilleCity_BikeShop_EventScript_ChooseBike
	end

MauvilleCity_BikeShop_EventScript_GetMachBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseMachBike, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_GetAcroBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseAcroBike, MSGBOX_DEFAULT
	giveitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes, MSGBOX_DEFAULT
	special SwapRegisteredBike
	release
	end

MauvilleCity_BikeShop_EventScript_AskSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_WantToSwitchBikes, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_SwitchBikes
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_KeepBike
	end

@ If the player does not have a bike on them Rydel assumes its stored in the PC
MauvilleCity_BikeShop_EventScript_SwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_IllSwitchBikes, MSGBOX_DEFAULT
	checkitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchAcroForMach
	checkitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchMachForAcro
	msgbox MauvilleCity_BikeShop_Text_OhYourBikeIsInPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_KeepBike::
	msgbox MauvilleCity_BikeShop_Text_HappyYouLikeIt, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_SwitchAcroForMach::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedAcroForMach, MSGBOX_DEFAULT
	removeitem ITEM_ACRO_BIKE
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_SwitchMachForAcro::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedMachForAcro, MSGBOX_DEFAULT
	removeitem ITEM_MACH_BIKE
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_Assistant::
	msgbox MauvilleCity_BikeShop_Text_HandbooksAreInBack, MSGBOX_NPC
	end

MauvilleCity_BikeShop_EventScript_MachBikeHandbook::
	message MauvilleCity_BikeShop_Text_MachHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage::
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_HowToRide
	case 1, MauvilleCity_BikeShop_EventScript_HowToTurn
	case 2, MauvilleCity_BikeShop_EventScript_SandySlopes
	case 3, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	end

MauvilleCity_BikeShop_EventScript_HowToRide::
	message MauvilleCity_BikeShop_Text_HowToRideMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_HowToTurn::
	message MauvilleCity_BikeShop_Text_HowToTurnMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_SandySlopes::
	message MauvilleCity_BikeShop_Text_SandySlopes
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitMachHandbook::
	release
	end

MauvilleCity_BikeShop_EventScript_AcroBikeHandbook::
	message MauvilleCity_BikeShop_Text_AcroHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage::
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_Wheelies
	case 1, MauvilleCity_BikeShop_EventScript_BunnyHops
	case 2, MauvilleCity_BikeShop_EventScript_Jumps
	case 3, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	end

MauvilleCity_BikeShop_EventScript_Wheelies::
	message MauvilleCity_BikeShop_Text_Wheelies
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_BunnyHops::
	message MauvilleCity_BikeShop_Text_BunnyHops
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_Jumps::
	message MauvilleCity_BikeShop_Text_Jumps
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitAcroHandbook::
	release
	end

MauvilleCity_BikeShop_Text_RydelGreeting:
	.string "Bene, bene, chi abbiamo qui?\n"
	.string "Un cliente pieno di energia!\p"
	.string "Io? Puoi chiamarmi RYDEL.\n"
	.string "Sono il proprietario di questo negozio.$"

MauvilleCity_BikeShop_Text_DidYouComeFromFarAway:
	.string "RYDEL: Le tue SCARPE DA GINNASTICA…\n"
	.string "Sono molto sporche.\p"
	.string "Vieni da lontano?$"

MauvilleCity_BikeShop_Text_GuessYouDontNeedBike:
	.string "RYDEL: Davvero?\p"
	.string "Allora non ti serve nessuna\n"
	.string "delle mie BICICLETTE.$"

MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne:
	.string "RYDEL: Hm, hm… … … … …\p"
	.string "You're saying that you came all this\n"
	.string "way from LITTLEROOT?\p"
	.string "My goodness!\n"
	.string "That's ridiculously far!\p"
	.string "If you had one of my BIKES, you could\n"
	.string "go anywhere easily while feeling the\l"
	.string "gentle caress of the wind!\p"
	.string "I'll tell you what!\n"
	.string "I'll give you a BIKE!\p"
	.string "Oh, wait a second!\p"
	.string "I forgot to tell you that there are\n"
	.string "two kinds of BIKES!\p"
	.string "They are the MACH BIKE and\n"
	.string "the ACRO BIKE!\p"
	.string "The MACH BIKE is for cyclists who want\n"
	.string "to feel the wind with their bodies!\p"
	.string "And an ACRO BIKE is for those who\n"
	.string "prefer technical rides!\p"
	.string "I'm a real sweetheart, so you can\n"
	.string "have whichever one you like!\p"
	.string "Which one will you choose?$"

MauvilleCity_BikeShop_Text_ChoseMachBike:
	.string "{PLAYER} sceglie la MACH BIKE.$"

MauvilleCity_BikeShop_Text_ChoseAcroBike:
	.string "{PLAYER} sceglie la ACRO BIKE.$"

MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes:
	.string "RYDEL: Se ti va di cambiare\n"
	.string "BICICLETTA, vieni da me!$"

MauvilleCity_BikeShop_Text_WantToSwitchBikes:
	.string "RYDEL: Oh? Stavi pensando di\n"
	.string "cambiare BICICLETTA?$"

MauvilleCity_BikeShop_Text_IllSwitchBikes:
	.string "RYDEL: Ok, nessun problema!\n"
	.string "Ti cambio la BICICLETTA!$"

MauvilleCity_BikeShop_Text_ExchangedMachForAcro:
	.string "{PLAYER} scambia la MACH BIKE\n"
	.string "con una ACRO BIKE.$"

MauvilleCity_BikeShop_Text_ExchangedAcroForMach:
	.string "{PLAYER} scambia la ACRO BIKE\n"
	.string "con una MACH BIKE.$"

MauvilleCity_BikeShop_Text_HappyYouLikeIt:
	.string "RYDEL: Bene, bene!\n"
	.string "Sono felice che ti piaccia!$"

MauvilleCity_BikeShop_Text_OhYourBikeIsInPC:
	.string "Oh? Che fine ha fatto la BICICLETTA\n"
	.string "che ti ho dato?\p"
	.string "Ah, capisco, l'hai messa nel PC.\p"
	.string "Beh, tirala fuori dal PC,\n"
	.string "e te la scambio volentieri!\p"
	.string "Che il vento ti sia sempre alle\n"
	.string "spalle nella tua avventura!$"

MauvilleCity_BikeShop_Text_HandbooksAreInBack:
	.string "Sto imparando le BICICLETTE\n"
	.string "mentre lavoro qui.\p"
	.string "Se ti serve aiuto per guidare la\n"
	.string "BICICLETTA, ci sono dei manuali\l"
	.string "in fondo.$"

MauvilleCity_BikeShop_Text_MachHandbookWhichPage:
	.string "È un manuale sulla MACH BIKE.\p"
	.string "Qualche pagina da leggere?$"

MauvilleCity_BikeShop_Text_HowToRideMachBike:
	.string "La BICICLETTA va dove premi\n"
	.string "il + Control Pad.\p"
	.string "Accelera una volta partita.\p"
	.string "Per fermarti, rilascia il + Pad.\n"
	.string "La BICICLETTA rallenta e si ferma.\p"
	.string "Vuoi leggere un'altra pagina?$"

MauvilleCity_BikeShop_Text_HowToTurnMachBike:
	.string "La MACH BIKE è veloce, ma non\n"
	.string "frena rapidamente.\p"
	.string "È un po' difficile curvare\n"
	.string "in curva.\p"
	.string "Rilascia il + Pad un po'\n"
	.string "prima della curva e rallenta.\p"
	.string "Vuoi leggere un'altra pagina?$"

MauvilleCity_BikeShop_Text_SandySlopes:
	.string "Ci sono piccoli pendii sabbiosi\n"
	.string "in tutta la regione di HOENN.\p"
	.string "La sabbia smossa rende\n"
	.string "impossibile salire normalmente.\p"
	.string "Ma con una MACH BIKE puoi\n"
	.string "salire su un pendio sabbioso.\p"
	.string "Vuoi leggere un'altra pagina?$"

MauvilleCity_BikeShop_Text_AcroHandbookWhichPage:
	.string "È un manuale sulla ACRO BIKE.\p"
	.string "Quale pagina vuoi leggere?$"

MauvilleCity_BikeShop_Text_Wheelies:
	.string "Premi B mentre corri\n"
	.string "e la ruota davanti si alza.\p"
	.string "Puoi correre con la ruota\n"
	.string "alzata usando il + Pad.\p"
	.string "Si chiama impennata.\p"
	.string "Vuoi leggere un'altra pagina?$"

MauvilleCity_BikeShop_Text_BunnyHops:
	.string "Keeping the B Button pressed,\n"
	.string "your BIKE can hop on the spot.\p"
	.string "This technique is called a bunny hop.\p"
	.string "You can ride while hopping, too.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_Jumps:
	.string "Press the B Button and the + Control\n"
	.string "Pad at the same time to jump.\p"
	.string "Press the + Control Pad to the side\n"
	.string "to jump sideways.\p"
	.string "Press it backwards to make the BIKE\n"
	.string "change directions while jumping.\p"
	.string "Want to read a different page?$"

