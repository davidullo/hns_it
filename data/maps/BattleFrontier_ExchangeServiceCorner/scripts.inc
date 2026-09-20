BattleFrontier_ExchangeServiceCorner_MapScripts::
	.byte 0

.macro setitemandprice item:req, price:req
	setvar VAR_0x8009, \item
	setvar VAR_0x8008, \price
.endm

BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special ShowBattlePointsWindow
	return

BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize::
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor::
	checkdecorspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ExchangeServiceCorner_EventScript_NoRoomForDecor
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	adddecoration VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WellSendItToPC, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	end

BattleFrontier_ExchangeServiceCorner_EventScript_NoRoomForDecor::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_PCIsFull, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveItem::
	checkitemspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ExchangeServiceCorner_EventScript_BagFull
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	additem VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_BagFull::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk1::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_1
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_KissPoster
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_KissCushion
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_SmoochumDoll
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_TogepiDoll
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_MeowthDoll
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ClefairyDoll
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_DittoDoll
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_CyndaquilDoll
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_ChikoritaDoll
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_TotodileDoll
	case 10, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1::
	bufferdecorationname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmPurchase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_KissPoster::
	setitemandprice DECOR_KISS_POSTER, 16
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1

BattleFrontier_ExchangeServiceCorner_EventScript_KissCushion::
	setitemandprice DECOR_KISS_CUSHION, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1

BattleFrontier_ExchangeServiceCorner_EventScript_SmoochumDoll::
	setitemandprice DECOR_SMOOCHUM_DOLL, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1

BattleFrontier_ExchangeServiceCorner_EventScript_TogepiDoll::
	setitemandprice DECOR_TOGEPI_DOLL, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1

BattleFrontier_ExchangeServiceCorner_EventScript_MeowthDoll::
	setitemandprice DECOR_MEOWTH_DOLL, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1

BattleFrontier_ExchangeServiceCorner_EventScript_ClefairyDoll::
	setitemandprice DECOR_CLEFAIRY_DOLL, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1

BattleFrontier_ExchangeServiceCorner_EventScript_DittoDoll::
	setitemandprice DECOR_DITTO_DOLL, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1

BattleFrontier_ExchangeServiceCorner_EventScript_CyndaquilDoll::
	setitemandprice DECOR_CYNDAQUIL_DOLL, 80
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1

BattleFrontier_ExchangeServiceCorner_EventScript_ChikoritaDoll::
	setitemandprice DECOR_CHIKORITA_DOLL, 80
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1

BattleFrontier_ExchangeServiceCorner_EventScript_TotodileDoll::
	setitemandprice DECOR_TOTODILE_DOLL, 80
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1

BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk2::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_2
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_LaprasDoll
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_SnorlaxDoll
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_VenusaurDoll
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_CharizardDoll
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_BlastoiseDoll
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor2::
	bufferdecorationname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmPurchase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_LaprasDoll::
	setitemandprice DECOR_LAPRAS_DOLL, 128
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor2

BattleFrontier_ExchangeServiceCorner_EventScript_SnorlaxDoll::
	setitemandprice DECOR_SNORLAX_DOLL, 128
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor2

BattleFrontier_ExchangeServiceCorner_EventScript_VenusaurDoll::
	setitemandprice DECOR_VENUSAUR_DOLL, 256
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor2

BattleFrontier_ExchangeServiceCorner_EventScript_CharizardDoll::
	setitemandprice DECOR_CHARIZARD_DOLL, 256
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor2

BattleFrontier_ExchangeServiceCorner_EventScript_BlastoiseDoll::
	setitemandprice DECOR_BLASTOISE_DOLL, 256
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor2

BattleFrontier_ExchangeServiceCorner_EventScript_VitaminClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_VITAMIN_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_Protein
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_Calcium
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_Iron
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_Zinc
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_Carbos
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_HPUp
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseVitamin::
	bufferitemname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmPurchase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Protein::
	setitemandprice ITEM_PROTEIN, 1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseVitamin

BattleFrontier_ExchangeServiceCorner_EventScript_Calcium::
	setitemandprice ITEM_CALCIUM, 1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseVitamin

BattleFrontier_ExchangeServiceCorner_EventScript_Iron::
	setitemandprice ITEM_IRON, 1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseVitamin

BattleFrontier_ExchangeServiceCorner_EventScript_Zinc::
	setitemandprice ITEM_ZINC, 1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseVitamin

BattleFrontier_ExchangeServiceCorner_EventScript_Carbos::
	setitemandprice ITEM_CARBOS, 1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseVitamin

BattleFrontier_ExchangeServiceCorner_EventScript_HPUp::
	setitemandprice ITEM_HP_UP, 1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseVitamin


BattleFrontier_ExchangeServiceCorner_EventScript_HoldItemClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_HOLD_ITEM_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PokeBallClerk::
	lock
	faceplayer
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special CreateBPPokeBallShop
	waitstate
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_HOLD_ITEM_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_Leftovers
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_WhiteHerb
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_QuickClaw
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_MentalHerb
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_Brightpowder
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceBand
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_KingsRock
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_FocusBand
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_ScopeLens
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem::
	bufferitemname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmPurchase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Leftovers::
	setitemandprice ITEM_LEFTOVERS, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_WhiteHerb::
	setitemandprice ITEM_WHITE_HERB, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_QuickClaw::
	setitemandprice ITEM_QUICK_CLAW, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_MentalHerb::
	setitemandprice ITEM_MENTAL_HERB, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_Brightpowder::
	setitemandprice ITEM_BRIGHT_POWDER, 64
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceBand::
	setitemandprice ITEM_CHOICE_BAND, 64
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_KingsRock::
	setitemandprice ITEM_KINGS_ROCK, 64
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_FocusBand::
	setitemandprice ITEM_FOCUS_BAND, 64
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_ScopeLens::
	setitemandprice ITEM_SCOPE_LENS, 64
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_Man::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Sailor::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PokefanF::
	lock
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_RichBoy::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Girl::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize:
	.string "Salve, questo è il SERVIZIO\n"
	.string "SCAMBI.\p"
	.string "Scambiamo i Punti Lotta che\n"
	.string "hai raccolto con bei premi.\p"
	.string "Scegli un premio da questo elenco.$"

@ Unused
BattleFrontier_ExchangeServiceCorner_Text_PleaseChoosePrize:
	.string "Scegli un premio da questo elenco.$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmPurchase:
	.string "Hai scelto {STR_VAR_1}.\n"
	.string "Confermi?$"

BattleFrontier_ExchangeServiceCorner_Text_WellSendItToPC:
	.string "Grazie!\n"
	.string "Te lo invieremo al PC di casa.$"

BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize:
	.string "Ecco il tuo premio!$"

BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints:
	.string "Mi dispiace tanto…\n"
	.string "Non hai abbastanza Punti Lotta…$"

BattleFrontier_ExchangeServiceCorner_Text_PCIsFull:
	.string "Mi dispiace…\n"
	.string "Il tuo PC sembra pieno…$"

BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt:
	.string "Mi dispiace tanto…\n"
	.string "Non c'è spazio per portarlo…$"

BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints:
	.string "Grazie mille.\p"
	.string "Torna quando avrai\n"
	.string "accumulato Punti Lotta.$"

BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls:
	.string "Oh, che carini!\n"
	.string "Quanto li vorrei!\l"
	.string "Cuscini carini!\l"
	.string "PELUCHE grandi!\l"
	.string "PELUCHE piccoli!\l"
	.string "Li vorrei tutti!$"

BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant:
	.string "Lascia fare alla mamma!\p"
	.string "Se desideri qualcosa, lo otterrò\n"
	.string "a ogni costo, tesoro!$"

BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher:
	.string "Se ottengo gli oggetti di qui,\n"
	.string "i miei POKéMON diventeranno\p"
	.string "più tosti!\n"
	.string "Senza dubbio!$"

BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll:
	.string "Eh?\n"
	.string "Cosa mi fissi così?\p"
	.string "Non mi piace che mi fissi\n"
	.string "il peluche.\p"
	.string "Se la vuoi, prenditene una!\n"
	.string "Vero, SMOOCHUM?$"

BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord:
	.string "Lo sapevi?\p"
	.string "Se porti avanti il record nelle\n"
	.string "STRUTTURE DI LOTTA, ti daranno\l"
	.string "Punti Lotta sempre più grandi.$"

BattleFrontier_ExchangeServiceCorner_Text_KissPosterDesc::
	.string "Poster grande con SMOOCHUM stampato.$"

BattleFrontier_ExchangeServiceCorner_Text_KissCushionDesc::
	.string "Un cuscino SMOOCHUM.\n"
	.string "Da mettere su tappeto o scrivania.$"

BattleFrontier_ExchangeServiceCorner_Text_SmoochumDollDesc::
	.string "PELUCHE SMOOCHUM.\n"
	.string "Posa su tappeto o scrivania.$"

BattleFrontier_ExchangeServiceCorner_Text_TogepiDollDesc::
	.string "PELUCHE TOGEPI.\n"
	.string "Posa su tappeto o scrivania.$"

BattleFrontier_ExchangeServiceCorner_Text_MeowthDollDesc::
	.string "PELUCHE MEOWTH.\n"
	.string "Posa su tappeto o scrivania.$"

BattleFrontier_ExchangeServiceCorner_Text_ClefairyDollDesc::
	.string "Una bambola CLEFAIRY.\n"
	.string "Da mettere su tappeto o scrivania.$"

BattleFrontier_ExchangeServiceCorner_Text_DittoDollDesc::
	.string "Una bambola DITTO.\n"
	.string "Da mettere su tappeto o scrivania.$"

BattleFrontier_ExchangeServiceCorner_Text_CyndaquilDollDesc::
	.string "Una bambola CYNDAQUIL.\n"
	.string "Da mettere su tappeto o scrivania.$"

BattleFrontier_ExchangeServiceCorner_Text_ChikoritaDollDesc::
	.string "Una bambola CHIKORITA.\n"
	.string "Da mettere su tappeto o scrivania.$"

BattleFrontier_ExchangeServiceCorner_Text_TotodileDollDesc::
	.string "PELUCHE TOTODILE.\n"
	.string "Posa su tappeto o scrivania.$"

BattleFrontier_ExchangeServiceCorner_Text_LargeDollDesc::
	.string "GRAN PELUCHE.\n"
	.string "Posa su tappeto o scrivania.$"

BattleFrontier_ExchangeServiceCorner_Text_ProteinDesc::
	.string "Aumenta l'ATTACCO di un\n"
	.string "POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_CalciumDesc::
	.string "Aumenta l'ATT. SP. di un\n"
	.string "POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_IronDesc::
	.string "Aumenta la DIFESA di un\n"
	.string "POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_ZincDesc::
	.string "Aumenta la DIF. SPEC. di un\n"
	.string "POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_CarbosDesc::
	.string "Aumenta la VELOCITÀ di un\n"
	.string "POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_HPUpDesc::
	.string "Aumenta i PS di un POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_LeftoversDesc::
	.string "Strumento che ricarica gli HP\n"
	.string "poco a poco in lotta.$"

BattleFrontier_ExchangeServiceCorner_Text_WhiteHerbDesc::
	.string "Strumento che annulla le\n"
	.string "statistiche scese.$"

BattleFrontier_ExchangeServiceCorner_Text_QuickClawDesc::
	.string "Strumento che a volte consente\n"
	.string "di colpire per primo.$"

BattleFrontier_ExchangeServiceCorner_Text_MentalHerbDesc::
	.string "Strumento che scioglie i POKéMON\n"
	.string "dall'infatuazione.$"

BattleFrontier_ExchangeServiceCorner_Text_BrightpowderDesc::
	.string "Oggetto che con lo Sguardo\n"
	.string "Feroce riduce la precisione.$"

BattleFrontier_ExchangeServiceCorner_Text_ChoiceBandDesc::
	.string "Aumenta la forza di una mossa,\n"
	.string "ma solo quella.$"

BattleFrontier_ExchangeServiceCorner_Text_KingsRockDesc::
	.string "Oggetto che a volte fa tentennare\n"
	.string "il nemico colpito.$"

BattleFrontier_ExchangeServiceCorner_Text_FocusBandDesc::
	.string "Oggetto che a volte evita\n"
	.string "l'abbattimento.$"

BattleFrontier_ExchangeServiceCorner_Text_ScopeLensDesc::
	.string "Strumento che potenzia\n"
	.string "i colpi critici.$"
