VioletCity_House1_hns_MapScripts::
	.byte 0

VioletCity_House1_EventScript_Kyle::
	lock
	faceplayer
	msgbox VioletCity_House1_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_House1_EventScript_Rudy::
	lock
	faceplayer
	goto_if_set FLAG_VIOLET_NPC_TRADE_COMPLETED, VioletCity_House1_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_ONIX, VioletCity_House1_Text_YouWillTradeWontYou, VioletCity_House1_EventScript_DeclineTrade, VioletCity_House1_EventScript_NotRequestedMon, VioletCity_House1_Text_MonYouTakeCare
	setflag FLAG_VIOLET_NPC_TRADE_COMPLETED
	release
	end

VioletCity_House1_EventScript_DeclineTrade::
	msgbox VioletCity_House1_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

VioletCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox VioletCity_House1_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

VioletCity_House1_EventScript_TradeCompleted::
	msgbox VioletCity_House1_Text_After, MSGBOX_DEFAULT
	release
	end

VioletCity_House1_Text_YouWillTradeWontYou:
	.string "Colleziono POKéMON!\n"
	.string "Hai un {STR_VAR_1}?\p"
	.string "Lo vuoi scambiare col mio\n"
	.string "{STR_VAR_2}?$"

VioletCity_House1_Text_MonYouTakeCare:
	.string "Evvai! Ho {STR_VAR_1}!\p"
	.string "Ciao, {STR_VAR_2}!$"

VioletCity_House1_Text_ThisIsntAMon:
	.string "Ah, no, temo di no.\n"
	.string "Non è un {STR_VAR_1}.$"

VioletCity_House1_Text_YouWontTradeMe:
	.string "Non vuoi scambiare? Oh…$"

VioletCity_House1_Text_After:
	.string "Ciao, come sta il mio vecchio ONIX?$"

VioletCity_House1_Text_PokefanM:
	.string "Un POKéMON ottenuto in uno scambio\n"
	.string "cresce in fretta.\p"
	.string "Ma senza la MEDAGLIA giusta\n"
	.string "potrebbe non ubbidirti.$"
