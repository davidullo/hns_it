FortreeCity_House1_MapScripts::
	.byte 0

FortreeCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_FORTREE_NPC_TRADE_COMPLETED, FortreeCity_House1_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_PLUSLE, FortreeCity_House1_Text_YouWillTradeWontYou, FortreeCity_House1_EventScript_DeclineTrade, FortreeCity_House1_EventScript_NotRequestedMon, FortreeCity_House1_Text_MonYouTakeCare
	setflag FLAG_FORTREE_NPC_TRADE_COMPLETED
	release
	end

FortreeCity_House1_EventScript_DeclineTrade::
	msgbox FortreeCity_House1_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_TradeCompleted::
	msgbox FortreeCity_House1_Text_GoingToMakeVolbeatStrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_ExpertF::
	msgbox FortreeCity_House1_Text_TradingMemoriesWithOthers, MSGBOX_NPC
	end

FortreeCity_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House1_Text_YouWillTradeWontYou:
	.string "Wrooooaaar! Mi serve!\n"
	.string "Devo avere un {STR_VAR_1}!\l"
	.string "Per questo farei di tutto!\p"
	.string "…Uh… Hai sentito?\n"
	.string "Il mio grido dal profondo del cuore?\p"
	.string "Sentito ciò, scambierai il tuo\n"
	.string "{STR_VAR_1} col mio {STR_VAR_2},\l"
	.string "vero?$"

FortreeCity_House1_Text_MonYouTakeCare:
	.string "Oh, sì, ottimo!\p"
	.string "Ciao, {STR_VAR_1}!\n"
	.string "{STR_VAR_2}, abbi cura di te!$"

FortreeCity_House1_Text_ThisIsntAMon:
	.string "Ah, no, temo di no.\n"
	.string "Non è un {STR_VAR_1}.$"

FortreeCity_House1_Text_YouWontTradeMe:
	.string "No? Non mi scambi?\n"
	.string "Dopo che ti ho aperto il cuore?$"

FortreeCity_House1_Text_GoingToMakeVolbeatStrong:
	.string "Rendo VOLBEAT fortissimo\n"
	.string "da questo momento in poi!\p"
	.string "Fallo anche tu con PLUSLE!$"

FortreeCity_House1_Text_TradingMemoriesWithOthers:
	.string "Scambiare POKéMON con altri…\p"
	.string "È come scambiare le tue\n"
	.string "memorie con altri.$"

FortreeCity_House1_Text_Zigzagoon:
	.string "ZIGZAGOON: Gumomoh?$"

