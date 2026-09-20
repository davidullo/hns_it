OlivineCity_House1_hns_MapScripts::
	.byte 0

OlivineCity_House1_EventScript_Tim::
	lock
	faceplayer
	goto_if_set FLAG_OLIVINE_NPC_TRADE_COMPLETED, OlivineCity_House1_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_VOLTORB, OlivineCity_House1_Text_YouWillTradeWontYou, OlivineCity_House1_EventScript_DeclineTrade, OlivineCity_House1_EventScript_NotRequestedMon, OlivineCity_House1_Text_MonYouTakeCare
	setflag FLAG_OLIVINE_NPC_TRADE_COMPLETED
	release
	end

OlivineCity_House1_EventScript_DeclineTrade::
	msgbox OlivineCity_House1_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

OlivineCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox OlivineCity_House1_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

OlivineCity_House1_EventScript_TradeCompleted::
	msgbox OlivineCity_House1_Text_After, MSGBOX_DEFAULT
	release
	end

OlivineCity_House1_Text_YouWillTradeWontYou:
	.string "Colleziono POKéMON!\n"
	.string "Hai un {STR_VAR_1}?\p"
	.string "Lo vuoi scambiare col mio\n"
	.string "{STR_VAR_2}?$"

OlivineCity_House1_Text_MonYouTakeCare:
	.string "Evvai! Ho {STR_VAR_1}!\p"
	.string "Ciao, {STR_VAR_2}!$"

OlivineCity_House1_Text_ThisIsntAMon:
	.string "Ah, no, temo di no.\n"
	.string "Non è un {STR_VAR_1}.$"

OlivineCity_House1_Text_YouWontTradeMe:
	.string "Non vuoi scambiare? Oh…$"

OlivineCity_House1_Text_After:
	.string "Hi, how's my old VOLTORB doing?$"
