PacifidlogTown_House3_MapScripts::
	.byte 0

PacifidlogTown_House3_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, PacifidlogTown_House3_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_HORSEA, PacifidlogTown_House3_Text_WillingToTradeIt, PacifidlogTown_House3_EventScript_DeclineTrade, PacifidlogTown_House3_EventScript_NotRequestedMon, PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou
	setflag FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED
	release
	end

PacifidlogTown_House3_EventScript_DeclineTrade::
	msgbox PacifidlogTown_House3_Text_NotDesperateOrAnything, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_TradeCompleted::
	msgbox PacifidlogTown_House3_Text_ReallyWantedToGetBagon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_Girl::
	msgbox PacifidlogTown_House3_Text_IsThatAPokedex, MSGBOX_NPC
	end

PacifidlogTown_House3_Text_WillingToTradeIt:
	.string "Guarda questo {STR_VAR_2}!\p"
	.string "È il {STR_VAR_2} che ho catturato\n"
	.string "ieri per il mio compleanno!\p"
	.string "Oh, vedo che lo vuoi!\n"
	.string "Dopotutto è inestimabile!\p"
	.string "Ti dico: potrei essere disposto\n"
	.string "a scambiarlo con un {STR_VAR_1}.$"

PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou:
	.string "Oh, quindi è un {STR_VAR_1}?\p"
	.string "È un po' come un {STR_VAR_2},\n"
	.string "ma è leggermente diverso.\p"
	.string "Grazie!$"

PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon:
	.string "No, no, no! Non accetto niente\n"
	.string "meno di un vero {STR_VAR_1}!$"

PacifidlogTown_House3_Text_NotDesperateOrAnything:
	.string "Oh, quindi non vuoi più\n"
	.string "farlo?\p"
	.string "Va bene. Non muoio dalla voglia di\n"
	.string "fare uno scambio.$"

PacifidlogTown_House3_Text_ReallyWantedToGetBagon:
	.string "So che potrei cercarne uno\n"
	.string "da solo, ma…\p"
	.string "Volevo davvero un BAGON\n"
	.string "catturato da un altro ALLENATORE…$"

PacifidlogTown_House3_Text_IsThatAPokedex:
	.string "Quello è un POKéDEX?\p"
	.string "Hai conosciuto tanti POKéMON\n"
	.string "diversi?\p"
	.string "Vorrei essere come te.$"

