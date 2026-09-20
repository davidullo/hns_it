TrainerHill_Courtyard_hns_MapScripts::
map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Courtyard_OnTransition
	.byte 0

TrainerHill_Courtyard_OnTransition::
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	end

TrainerHill_Courtyard_EventScript_BattleTowerSign::
	lock
	msgbox BattleTowerOutsideSignText, MSGBOX_SIGN	
	closemessage	
	release
	end

TrainerHill_Courtyard_EventScript_Tent_Factory::
	lock
	msgbox BattleTower_Battle_Tent_Text_Factory, MSGBOX_SIGN	
	closemessage	
	release
	end

TrainerHill_Courtyard_EventScript_Tent_Palace::
	lock
	msgbox BattleTower_Battle_Tent_Text_Palace, MSGBOX_SIGN	
	closemessage	
	release
	end

TrainerHill_Courtyard_EventScript_Tent_Arena::
	lock
	msgbox BattleTower_Battle_Tent_Text_Arena, MSGBOX_SIGN	
	closemessage	
	release
	end
	
TrainerHill_Courtyard_EventScript_Engineer::
	lock
	faceplayer
	msgbox BattleTowerOutsideText_Closed, MSGBOX_DEFAULT
	closemessage
	release
	end

TrainerHill_Courtyard_EventScript_Youngster::
	lock
	faceplayer
	msgbox BattleTowerOutsideYoungsterText, MSGBOX_DEFAULT
	closemessage
	release
	end

TrainerHill_Courtyard_EventScript_Beauty::
	lock
	faceplayer
	msgbox BattleTowerOutsideBeautyText, MSGBOX_DEFAULT
	closemessage
	release
	end

TrainerHill_Courtyard_EventScript_Sailor::
	lock
	faceplayer
	msgbox BattleTowerOutsideSailorText, MSGBOX_DEFAULT
	closemessage
	release
	end

BattleTowerOutsideYoungsterText:
	.string "Wow, the TRAINER HILL is huge!\p"
	.string "There must be many kinds of\n"
	.string "POKéMON in there!$"

BattleTowerOutsideBeautyText:
	.string "In the BATTLE TENTS, you can\n"
	.string "use only three POKéMON.\p"
	.string "It's so hard to decide which\n"
	.string "three should go into battle…$"

BattleTowerOutsideSailorText:
	.string "Hehehe, I snuck out from work.\p"
	.string "I can't bail out until I've won!\p"
	.string "I have to win it all. That I must!$"

BattleTowerOutsideSignText:
	.string "{UP_ARROW} TRAINER HILL ENTRANCE\p"
	.string "“Scale the heights, you hot-blooded\n"
	.string "TRAINERS!”\p"
	.string "{RIGHT_ARROW} BATTLE TENTS.$"

BattleTower_Battle_Tent_Text_Factory:
	.string "BATTLE TENT: FACTORY\n"
	.string "“Find it! The ultimate POKéMON!”$"

BattleTower_Battle_Tent_Text_Palace:
	.string "BATTLE TENT: PALACE\n"
	.string "“Feast Your Eyes on Battles!”$"

BattleTower_Battle_Tent_Text_Arena:
	.string "BATTLE TENT: ARENA\n"
	.string "“May the Greatest Teams Gather!”$"

BattleTowerOutsideText_Closed:
	.string "The TRAINER HILL is currently\n"
	.string "closed for repairs.$"


TrainerHill_Courtyard_EventScript_LeftMoveTutor::
	goto BattleFrontier_Lounge7_EventScript_LeftMoveTutor_hns
	end

TrainerHill_Courtyard_EventScript_RightMoveTutor::
	goto BattleFrontier_Lounge7_EventScript_RightMoveTutor_hns
	end

TrainerHill_Courtyard_EventScript_ElementalMoveTutor::
	goto BattleFrontier_Lounge7_EventScript_ElementalMoveTutor
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_DecorClerk1::
	lock
	faceplayer
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special CreateBPDecorShop1
	waitstate
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_DecorClerk2::
	lock
	faceplayer
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special CreateBPDecorShop2
	waitstate
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_VitaminClerk::
	lock
	faceplayer
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special CreateBPVitaminShop
	waitstate
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_HoldItemClerk::
	lock
	faceplayer
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special CreateBPHoldItemShop
	waitstate
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_HoldItemClerk2::
	lock
	faceplayer
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special CreateBPHoldItemShop2
	waitstate
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_PowerClerk::
	lock
	faceplayer
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special CreateBPPowerShop
	waitstate
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Man::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_GoGetYourOwnDoll, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Sailor::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ItemsWillGetMonTougher, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_PokefanF::
	lock
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_GetYouAnythingYouWant, MSGBOX_DEFAULT
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_RichBoy::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WishIHadAllDolls, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Girl::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_MoreBattlePointsForRecord, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_OldWTMan::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_OldWTMan_Text, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_OldWTMan_Text:
	.string "Hi! If you are looking for the\n"
	.string "WONDERTRADE, they're now located in\l"
	.string "every POKéMON CENTER. Have fun!$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize:
	.string "Salve, questo è il SERVIZIO\n"
	.string "SCAMBI.\p"
	.string "Scambiamo i Punti Lotta che\n"
	.string "hai raccolto con bei premi.\p"
	.string "Scegli un premio da questo elenco.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_WishIHadAllDolls:
	.string "Oh, che carini!\n"
	.string "Quanto li vorrei!\l"
	.string "Cuscini carini!\l"
	.string "PELUCHE grandi!\l"
	.string "PELUCHE piccoli!\l"
	.string "Li vorrei tutti!$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_GetYouAnythingYouWant:
	.string "Lascia fare alla mamma!\p"
	.string "Se desideri qualcosa, lo otterrò\n"
	.string "a ogni costo, tesoro!$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ItemsWillGetMonTougher:
	.string "Se ottengo gli oggetti di qui,\n"
	.string "i miei POKéMON diventeranno\p"
	.string "più tosti!\n"
	.string "Senza dubbio!$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_GoGetYourOwnDoll:
	.string "Eh?\n"
	.string "Cosa mi fissi così?\p"
	.string "Non mi piace che mi fissi\n"
	.string "il peluche.\p"
	.string "Se la vuoi, prenditene una!\n"
	.string "Vero, SMOOCHUM?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_MoreBattlePointsForRecord:
	.string "Lo sapevi?\p"
	.string "Se porti avanti il record nelle\n"
	.string "STRUTTURE DI LOTTA, ti daranno\l"
	.string "Punti Lotta sempre più grandi.$"
