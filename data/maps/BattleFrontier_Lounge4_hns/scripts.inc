BattleFrontier_Lounge4_hns_MapScripts::
	.byte 0

BattleFrontier_Lounge4_EventScript_Woman_hns::
	msgbox BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Cook_hns::
	msgbox BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Man_hns::
	msgbox BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring_hns:
	.string "Chissà se oggi mandano in onda\n"
	.string "interviste ad ALLENATORI tosti?$"

BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere_hns:
	.string "Se aprissi un ristorante qui,\n"
	.string "farebbe sicuramente soldi.$"

BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles_hns:
	.string "Whew…\p"
	.string "I need to take a breather after\n"
	.string "some intense battles…\p"
	.string "But even now, I never take a break\n"
	.string "from plotting strategy and combos.$"

