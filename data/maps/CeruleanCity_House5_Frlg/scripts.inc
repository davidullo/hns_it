CeruleanCity_House5_Frlg_MapScripts::
	.byte 0

CeruleanCity_House5_EventScript_BerryPowderMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_POWDER_JAR, CeruleanCity_House5_EventScript_AskToExchangePowder
	msgbox CeruleanCity_House1_Text_AnyInterestInBerries, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeruleanCity_House5_EventScript_NoInterestInBerries
	goto_if_unset FLAG_SYS_GOT_BERRY_POUCH, CeruleanCity_House5_EventScript_NoBerries
	msgbox CeruleanCity_House1_Text_HaveJustTheThing
	setflag FLAG_GOT_POWDER_JAR
	giveitem ITEM_POWDER_JAR
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	msgbox CeruleanCity_House1_Text_GoCrushBerriesAtDirectCorner
	release
	end

CeruleanCity_House5_EventScript_NoBerries::
	msgbox CeruleanCity_House1_Text_WhyMustYouLieNoBerries
	release
	end

CeruleanCity_House5_EventScript_NoInterestInBerries::
	msgbox CeruleanCity_House1_Text_TakeInterestInAllSortsOfThings
	release
	end

CeruleanCity_House5_EventScript_AskToExchangePowder::
	special DisplayBerryPowderVendorMenu
	msgbox CeruleanCity_House1_Text_HaveYouBroughtBerryPowder
	goto CeruleanCity_House5_EventScript_ChooseExchangeItem
	end

CeruleanCity_House5_EventScript_ChooseExchangeItem::
	message CeruleanCity_House5_Text_ExchangeWithWhat
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, CeruleanCity_House5_EventScript_EnergyPowder
	case 1, CeruleanCity_House5_EventScript_EnergyRoot
	case 2, CeruleanCity_House5_EventScript_HealPowder
	case 3, CeruleanCity_House5_EventScript_RevivalHerb
	case 4, CeruleanCity_House5_EventScript_Protein
	case 5, CeruleanCity_House5_EventScript_Iron
	case 6, CeruleanCity_House5_EventScript_Carbos
	case 7, CeruleanCity_House5_EventScript_Calcium
	case 8, CeruleanCity_House5_EventScript_Zinc
	case 9, CeruleanCity_House5_EventScript_HPUp
	case 10, CeruleanCity_House5_EventScript_PPUp
	case 11, CeruleanCity_House5_EventScript_ExitMenu
	case 127, CeruleanCity_House5_EventScript_ExitMenu
	end

CeruleanCity_House5_EventScript_EnergyPowder::
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
	setvar VAR_0x8009, 50
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_EnergyRoot::
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
	setvar VAR_0x8009, 80
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_HealPowder::
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
	setvar VAR_0x8008, ITEM_HEAL_POWDER
	setvar VAR_0x8009, 50
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_RevivalHerb::
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
	setvar VAR_0x8009, 300
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_Protein::
	bufferitemname STR_VAR_1, ITEM_PROTEIN
	setvar VAR_0x8008, ITEM_PROTEIN
	setvar VAR_0x8009, 1000
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_Iron::
	bufferitemname STR_VAR_1, ITEM_IRON
	setvar VAR_0x8008, ITEM_IRON
	setvar VAR_0x8009, 1000
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_Carbos::
	bufferitemname STR_VAR_1, ITEM_CARBOS
	setvar VAR_0x8008, ITEM_CARBOS
	setvar VAR_0x8009, 1000
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_Calcium::
	bufferitemname STR_VAR_1, ITEM_CALCIUM
	setvar VAR_0x8008, ITEM_CALCIUM
	setvar VAR_0x8009, 1000
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_Zinc::
	bufferitemname STR_VAR_1, ITEM_ZINC
	setvar VAR_0x8008, ITEM_ZINC
	setvar VAR_0x8009, 1000
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_HPUp::
	bufferitemname STR_VAR_1, ITEM_HP_UP
	setvar VAR_0x8008, ITEM_HP_UP
	setvar VAR_0x8009, 1000
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_PPUp::
	bufferitemname STR_VAR_1, ITEM_PP_UP
	setvar VAR_0x8008, ITEM_PP_UP
	setvar VAR_0x8009, 3000
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_ExitMenu::
	msgbox CeruleanCity_House1_Text_SeeMeIfYoudLikeToTradePowder
	special RemoveBerryPowderVendorMenu
	release
	end

CeruleanCity_House5_EventScript_ExchangePowderForItem::
	msgbox CeruleanCity_House1_Text_YoullExchangeBerryPowderForItem, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeruleanCity_House5_EventScript_ChooseExchangeItem
	copyvar VAR_0x8004, VAR_0x8009
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House5_EventScript_NotEnoughBerryPowder
	giveitem VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House5_EventScript_BagIsFull
	copyvar VAR_0x8004, VAR_0x8009
	special TakeBerryPowder
	special PrintPlayerBerryPowderAmount
	msgbox CeruleanCity_House1_Text_TradeMoreBerryPowder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CeruleanCity_House5_EventScript_ChooseExchangeItem
	msgbox CeruleanCity_House1_Text_HopeToSeeYouAgain
	special RemoveBerryPowderVendorMenu
	release
	end

CeruleanCity_House5_EventScript_BagIsFull::
	msgbox gText_TheBagIsFull
	special RemoveBerryPowderVendorMenu
	release
	end

CeruleanCity_House5_EventScript_NotEnoughBerryPowder::
	msgbox CeruleanCity_House1_Text_DontHaveEnoughBerryPowder
	goto CeruleanCity_House5_EventScript_ChooseExchangeItem
	end

CeruleanCity_House5_EventScript_BerryCrushRankings::
	lockall
	special ShowBerryCrushRankings
	waitstate
	releaseall
	end

CeruleanCity_House1_Text_AnyInterestInBerries::
	.string "Faccio medicine d'ogni tipo con\n"
	.string "POLVERE BACCA.\p"
	.string "Con la buona POLVERE BACCA\n"
	.string "faccio ogni medicina.\p"
	.string "Dimmi, ti interessano le\n"
	.string "BACCHE?$"

CeruleanCity_House1_Text_HaveJustTheThing::
	.string "Ah, bene! Per te ho proprio\n"
	.string "ciò che serve.$"

CeruleanCity_House1_Text_GoCrushBerriesAtDirectCorner::
	.string "C'è una novità al secondo\n"
	.string "piano dei CENTRI POKéMON, all'\l"
	.string "ANGOLO DIRETTO\p"
	.string "Hanno installato un Adattatore\n"
	.string "Wireless per tritare BACCHE.\p"
	.string "E qui entri in gioco.\p"
	.string "Ho un favore da chiedere, uno\n"
	.string "che affido solo a te.\p"
	.string "Potresti farmi la POLVERE DI\n"
	.string "BACCA con la macchina?\p"
	.string "Non dimenticare, la macchina è\n"
	.string "all'ANGOLO DIRETTO dei CENTRI.\p"
	.string "Ti preparerò una medicina se\n"
	.string "mi porti un po' di POLVERE\p"
	.string "DI BACCA. Non scordare, trita\n"
	.string "le BACCHE e portami la POLVERE.$"

CeruleanCity_House1_Text_WhyMustYouLieNoBerries::
	.string "Perché mi devi mentire?\p"
	.string "Quante BACCHE hai?\n"
	.string "Nessuna!$"

CeruleanCity_House1_Text_TakeInterestInAllSortsOfThings::
	.string "Non ti interessano le BACCHE?\p"
	.string "Giovane, è importante avere\n"
	.string "interessi per tante cose.$"

CeruleanCity_House1_Text_HaveYouBroughtBerryPowder::
	.string "Ehm! Mi hai portato la POLVERE\n"
	.string "DI BACCA?$"

CeruleanCity_House5_Text_ExchangeWithWhat::
	.string "Con cosa vorresti\n"
	.string "scambiarla?$"

CeruleanCity_House1_Text_YoullExchangeBerryPowderForItem::
	.string "Bene, scambi la tua POLVERE\n"
	.string "DI BACCA per {STR_VAR_1}?$"

CeruleanCity_House1_Text_DontHaveEnoughBerryPowder::
	.string "Eh? Non hai abbastanza\n"
	.string "POLVERE.$"

CeruleanCity_House1_Text_TradeMoreBerryPowder::
	.string "È davvero un'ottima POLVERE\n"
	.string "di BACCA. Farà una medicina\p"
	.string "eccellente. Vuoi scambiare\n"
	.string "altra POLVERE con altro?$"

CeruleanCity_House1_Text_HopeToSeeYouAgain::
	.string "Va bene, allora.\n"
	.string "Spero di rivederti presto.$"

CeruleanCity_House1_Text_SeeMeIfYoudLikeToTradePowder::
	.string "Vieni da me se vuoi scambiare\n"
	.string "POLVERE DI BACCA.$"

