BattleFrontier_Lounge6_MapScripts::
	.byte 0

BattleFrontier_Lounge6_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_BATTLE_FRONTIER_TRADE_DONE, BattleFrontier_Lounge6_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_MEOWTH, BattleFrontier_Lounge6_Text_WouldYouLikeToTrade, BattleFrontier_Lounge6_EventScript_DeclineTrade, BattleFrontier_Lounge6_EventScript_NotRequestedMon, BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt
	setflag FLAG_BATTLE_FRONTIER_TRADE_DONE
	release
	end

BattleFrontier_Lounge6_EventScript_DeclineTrade::
	msgbox BattleFrontier_Lounge6_Text_WellThatsFineToo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_TradeCompleted::
	msgbox BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_Text_WouldYouLikeToTrade:
	.string "Il mio POKéMON è {STR_VAR_2}.\n"
	.string "Lo conosci?\l"
	.string "È carino e molto gentile.\p"
	.string "Con orgoglio scambierei\n"
	.string "lui!\p"
	.string "Vuoi scambiarmi un {STR_VAR_1}\n"
	.string "col mio {STR_VAR_2}?$"

BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt:
	.string "Oh, che adorabile!\n"
	.string "Grazie!\l"
	.string "Starò bene con lui!\p"
	.string "E tu stammi bene con\n"
	.string "il mio {STR_VAR_2}!$"

BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon:
	.string "Oh, mi dispiace!\n"
	.string "Non voglio scambiare altro\l"
	.string "che un {STR_VAR_1}.$"

BattleFrontier_Lounge6_Text_WellThatsFineToo:
	.string "Oh, non vuoi?\n"
	.string "Va bene lo stesso.\l"
	.string "Torna a trovarci.$"

BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined:
	.string "Ridacchio!\n"
	.string "Uno SKITTY è più carino di quanto\l"
	.string "immaginassi. Che gioia!$"
