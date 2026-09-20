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
	.string "Dici che sei venuto fin qui\n"
	.string "da LITTLEROOT?\p"
	.string "Perbacco!\n"
	.string "È lontanissimo!\p"
	.string "Con una mia BICICLETTA, potresti\n"
	.string "andare ovunque sentendo la\l"
	.string "gentile carezza del vento!\p"
	.string "Sai cosa?\n"
	.string "Ti regalo una BICICLETTA!\p"
	.string "Oh, aspetta!\p"
	.string "Dimenticavo di dirti che ci sono\n"
	.string "due tipi di BICICLETTA!\p"
	.string "Sono la MACH BIKE e\n"
	.string "la ACRO BIKE!\p"
	.string "La MACH BIKE è per chi vuole\n"
	.string "sentire il vento sul corpo!\p"
	.string "La ACRO BIKE è per chi\n"
	.string "preferisce guide tecniche!\p"
	.string "Sono un tipo generoso, quindi\n"
	.string "prendi quella che vuoi!\p"
	.string "Quale scegli?$"

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
	.string "Tenendo premuto il tasto B,\n"
	.string "la BICICLETTA salta sul posto.\p"
	.string "Si chiama bunny hop.\p"
	.string "Puoi anche andare saltando.\p"
	.string "Vuoi leggere un'altra pagina?$"

MauvilleCity_BikeShop_Text_Jumps:
	.string "Premi B e il + Pad insieme\n"
	.string "per saltare.\p"
	.string "Premi il + Pad di lato\n"
	.string "per saltare di fianco.\p"
	.string "Premilo indietro per far girare\n"
	.string "la BICICLETTA mentre salti.\p"
	.string "Vuoi leggere un'altra pagina?$"

