BattleFrontier_Lounge4_MapScripts::
	.byte 0

BattleFrontier_Lounge4_EventScript_Woman::
	msgbox BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Cook::
	msgbox BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Man::
	msgbox BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles, MSGBOX_NPC
	end

BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring:
	.string "Chissà se oggi mandano in onda\n"
	.string "interviste ad ALLENATORI tosti?$"

BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere:
	.string "Se aprissi un ristorante qui,\n"
	.string "farebbe sicuramente soldi.$"

BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles:
	.string "Uff…\p"
	.string "Dopo le lotte intense mi serve\n"
	.string "una pausa…\p"
	.string "Ma non smetto mai di studiare\n"
	.string "tattiche e combo.$"

