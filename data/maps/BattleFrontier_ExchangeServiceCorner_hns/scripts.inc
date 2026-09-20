BattleFrontier_ExchangeServiceCorner_hns_MapScripts::
	.byte 0

BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk1_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize_hns, MSGBOX_DEFAULT
	special CreateBPDecorShop1
	waitstate
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk2_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize_hns, MSGBOX_DEFAULT
	special CreateBPDecorShop2
	waitstate
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_VitaminClerk_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize_hns, MSGBOX_DEFAULT
	special CreateBPVitaminShop
	waitstate
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_HoldItemClerk_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize_hns, MSGBOX_DEFAULT
	special CreateBPHoldItemShop
	waitstate
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PokeBallClerk_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize_hns, MSGBOX_DEFAULT
	special CreateBPPokeBallShop
	waitstate
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_HoldItemClerk2_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize_hns, MSGBOX_DEFAULT
	special CreateBPHoldItemShop2
	waitstate
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PowerClerk_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize_hns, MSGBOX_DEFAULT
	special CreateBPPowerShop
	waitstate
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Man_hns::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll_hns, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Sailor_hns::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher_hns, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PokefanF_hns::
	lock
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_RichBoy_hns::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls_hns, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Girl_hns::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord_hns, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize_hns:
	.string "Salve, questo è il SERVIZIO\n"
	.string "SCAMBI.\p"
	.string "Scambiamo i Punti Lotta che\n"
	.string "hai raccolto con bei premi.\p"
	.string "Scegli un premio da questo elenco.$"

BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls_hns:
	.string "Oh, che carini!\n"
	.string "Quanto li vorrei!\l"
	.string "Cuscini carini!\l"
	.string "PELUCHE grandi!\l"
	.string "PELUCHE piccoli!\l"
	.string "Li vorrei tutti!$"

BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant_hns:
	.string "Lascia fare alla mamma!\p"
	.string "Se desideri qualcosa, lo otterrò\n"
	.string "a ogni costo, tesoro!$"

BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher_hns:
	.string "Se ottengo gli oggetti di qui,\n"
	.string "i miei POKéMON diventeranno\p"
	.string "più tosti!\n"
	.string "Senza dubbio!$"

BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll_hns:
	.string "Eh?\n"
	.string "Cosa mi fissi così?\p"
	.string "Non mi piace che mi fissi\n"
	.string "il peluche.\p"
	.string "Se la vuoi, prenditene una!\n"
	.string "Vero, SMOOCHUM?$"

BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord_hns:
	.string "Lo sapevi?\p"
	.string "Se porti avanti il record nelle\n"
	.string "STRUTTURE DI LOTTA, ti daranno\l"
	.string "Punti Lotta sempre più grandi.$"
