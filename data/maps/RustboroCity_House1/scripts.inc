RustboroCity_House1_MapScripts::
	.byte 0

RustboroCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House1_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_SEEDOT, RustboroCity_House1_Text_IllTradeIfYouWant, RustboroCity_House1_EventScript_DeclineTrade, RustboroCity_House1_EventScript_NotRequestedMon, RustboroCity_House1_Text_PleaseBeGoodToMyPokemon
	setflag FLAG_RUSTBORO_NPC_TRADE_COMPLETED
	release
	end

RustboroCity_House1_EventScript_DeclineTrade::
	msgbox RustboroCity_House1_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox RustboroCity_House1_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_TradeCompleted::
	msgbox RustboroCity_House1_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_Hiker::
	msgbox RustboroCity_House1_Text_AllSortsOfPlaces, MSGBOX_NPC
	end

RustboroCity_House1_Text_IllTradeIfYouWant:
	.string "Eh? Il mio POKéMON è carino?\n"
	.string "Certo, lo sapevo.\p"
	.string "Ma se ci tieni, sono disposto\n"
	.string "a scambiarlo con te.\p"
	.string "Ti do il mio {STR_VAR_2} per\n"
	.string "un {STR_VAR_1}, se vuoi.$"

RustboroCity_House1_Text_PleaseBeGoodToMyPokemon:
	.string "Eheheh…\n"
	.string "Tratta bene il mio POKéMON.$"

RustboroCity_House1_Text_DoesntLookLikeMonToMe:
	.string "Eh? A me non sembra proprio\n"
	.string "un {STR_VAR_1}.$"

RustboroCity_House1_Text_YouDontWantToThatsOkay:
	.string "Oh, se non vuoi, va bene lo stesso.\n"
	.string "Ma il mio POKéMON è carino, sai…$"

RustboroCity_House1_Text_AnyPokemonCanBeCute:
	.string "Ogni POKéMON può essere carino se\n"
	.string "lo allevi con cura e gentilezza.$"

RustboroCity_House1_Text_AllSortsOfPlaces:
	.string "In ogni luogo ci sono tanti\n"
	.string "POKéMON e tante persone.\p"
	.string "Lo trovo affascinante, perciò\n"
	.string "giro ogni luogo.$"

