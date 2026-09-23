PewterCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_PokemonCenter_OnTransition
	.byte 0

PewterCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_PEWTER_CITY_HNS
	end

PewterCity_PokemonCenter_EventScript_Teacher::
	msgbox PewterCity_PokemonCenter1F_Text_Teacher, MSGBOX_NPC
	end

PewterCity_PokemonCenter_EventScript_BugCatcher::
	msgbox PewterCity_PokemonCenter1F_Text_BugCatcher, MSGBOX_NPC
	end

PewterCity_PokemonCenter1F_Text_Teacher:
	.string "…Sì, e la PALESTRA di ISOLA\nCANNELLA è sparita.\p"
	.string "Sono rimasto davvero stupito.\p"
	.string "…Sì? Sono al telefono. Vattene!$"

PewterCity_PokemonCenter1F_Text_Jigglypuff:
	.string "JIGGLYPUFF: Puu pupuu!$"

PewterCity_PokemonCenter_EventScript_Mondo::
	lock
	faceplayer
	goto_if_set FLAG_PEWTER_NPC_TRADE_COMPLETED, PewterCity_PokemonCenter_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_HAUNTER, PewterCity_PokemonCenter_Text_WantToTrade, PewterCity_PokemonCenter_EventScript_DeclineTrade, PewterCity_PokemonCenter_EventScript_NotRequestedMon, PewterCity_PokemonCenter_Text_TakeCare
	setflag FLAG_PEWTER_NPC_TRADE_COMPLETED
	release
	end

PewterCity_PokemonCenter_EventScript_DeclineTrade::
	msgbox PewterCity_PokemonCenter_Text_DeclineTrade, MSGBOX_DEFAULT
	release
	end

PewterCity_PokemonCenter_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PewterCity_PokemonCenter_Text_NotRequestedMon, MSGBOX_DEFAULT
	release
	end

PewterCity_PokemonCenter_EventScript_TradeCompleted::
	msgbox PewterCity_PokemonCenter_Text_TradeCompleted, MSGBOX_DEFAULT
	release
	end

PewterCity_PokemonCenter_Text_WantToTrade:
	.string "Ho girato il mondo, cercando\n"
	.string "un buon {STR_VAR_1}.\p"
	.string "Lo scambieresti con il mio\n"
	.string "{STR_VAR_2}?$"

PewterCity_PokemonCenter_Text_TakeCare:
	.string "Grazie mille!\n"
	.string "Abbi cura del mio {STR_VAR_1}!$"

PewterCity_PokemonCenter_Text_DeclineTrade:
	.string "No? Che peccato…\n"
	.string "Penso che ti piacerebbe il mio HAUNTER.$"

PewterCity_PokemonCenter_Text_NotRequestedMon:
	.string "Hmm, non è un {STR_VAR_1}.\n"
	.string "Non è quello che cerco.$"

PewterCity_PokemonCenter_Text_TradeCompleted:
	.string "Come ti trovi con HAUNTER?\n"
	.string "È un vero combinaguai!$"

PewterCity_PokemonCenter1F_Text_BugCatcher:
	.string "Quasi tutti i POKéMON si intontiscono\n"
	.string "se sentono un JIGGLYPUFF cantare.\p"
	.string "Ci sono mosse che si possono usare\n"
	.string "solo mentre un POKéMON dorme.$"
