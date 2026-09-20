BlackthornCity_House2_hns_MapScripts::
	.byte 0

BlackthornCity_House2_EventScript_Emy::
	lock
	faceplayer
	goto_if_set FLAG_BLACKTHORN_NPC_TRADE_COMPLETED, BlackthornCity_House2_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_MR_MIME, BlackthornCity_House2_Text_YouWillTradeWontYou, BlackthornCity_House2_EventScript_DeclineTrade, BlackthornCity_House2_EventScript_NotRequestedMon, BlackthornCity_House2_Text_MonYouTakeCare
	setflag FLAG_BLACKTHORN_NPC_TRADE_COMPLETED
	release
	end

BlackthornCity_House2_EventScript_DeclineTrade::
	msgbox BlackthornCity_House2_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

BlackthornCity_House2_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BlackthornCity_House2_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

BlackthornCity_House2_EventScript_TradeCompleted::
	msgbox BlackthornCity_House2_Text_After, MSGBOX_DEFAULT
	release
	end

BlackthornCity_House2_Text_YouWillTradeWontYou:
	.string "Colleziono POKéMON!\n"
	.string "Hai un {STR_VAR_1}?\p"
	.string "Lo vuoi scambiare col mio\n"
	.string "{STR_VAR_2}?$"

BlackthornCity_House2_Text_MonYouTakeCare:
	.string "Evvai! Ho {STR_VAR_1}!\p"
	.string "Ciao, {STR_VAR_2}!$"

BlackthornCity_House2_Text_ThisIsntAMon:
	.string "Ah, no, temo di no.\n"
	.string "Non è un {STR_VAR_1}.$"

BlackthornCity_House2_Text_YouWontTradeMe:
	.string "Non vuoi scambiare? Oh…$"

BlackthornCity_House2_Text_After:
	.string "Come sta il mio vecchio MR MIME?$"
