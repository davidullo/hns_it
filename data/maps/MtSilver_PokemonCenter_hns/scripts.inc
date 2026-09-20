MtSilver_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver_PokemonCenter_OnTransition
	.byte 0

MtSilver_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_MT_SILVER_HNS
	end

MtSilver_PokemonCenter_EventScript_Meara::
	lock
	faceplayer
	goto_if_ge VAR_SINJOH_STORYLINE, 1, MtSilver_PokemonCenter_EventScript_Meara_AfterUnlockSinjoh
	msgbox MtSilver_PokemonCenter_Text_Meara1, MSGBOX_AUTOCLOSE
	checkitem ITEM_AZURE_FLUTE
	goto_if_eq VAR_RESULT, TRUE, MtSilver_PokemonCenter_EventScript_Meara_BonusContentPrompt
	release
	end

MtSilver_PokemonCenter_EventScript_Meara_BonusContentPrompt::
	msgbox MtSilver_PokemonCenter_Text_Meara2, MSGBOX_AUTOCLOSE
	helpwindow HELP_SINJOH_WINDOW
	
	msgbox MtSilver_PokemonCenter_Text_Prompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, MtSilver_PokemonCenter_EventScript_Meara_BonusContentNo
	closemessage

	@sinjoh flagheap
	clearflag FLAG_MT_SILVER_1F_HIDE_SCIENTIST
    setflag FLAG_HIDE_SNOWSWEPT_NOBLE_SNEASLER
	setflag FLAG_HIDE_ROUTE49_NOBLE_WYRDEER
	setflag FLAG_HIDE_ROUTE49_NOBLE_OVERQWIL
	setflag FLAG_HIDE_HOTSPRINGS_NOBLE_ARCANINE
	setflag FLAG_HIDE_HOTSPRINGS_NOBLE_URSALUNA
	setflag FLAG_HIDE_ROUTE50_NOBLE_ELECTRODE
	setflag FLAG_HIDE_ROUTE50_NOBLE_KLEAVOR
	setflag FLAG_HIDE_NEWSINJOH_HOUSE3_NOBLE_TYPHLOSION
	setflag FLAG_HIDE_SINJOHRUINS_STEVEN
	setflag FLAG_HIDE_SINJOHRUINS_ARCEUSROOM_ARCEUS
	setflag FLAG_HIDE_SINJOHRUINS_ARCEUSROOM_STEVEN
	setflag FLAG_HIDE_NEWSINJOH_STEVEN
	setvar VAR_SINJOH_STORYLINE, 1
	setvar VAR_PLATECOUNTER, 0
	setvar VAR_REGIS_SCANNED, 0
	warp MAP_MT_SILVER_1F_WATERFALL_ROOM_HNS, 43, 9
	waitstate
	end

MtSilver_PokemonCenter_EventScript_Meara_BonusContentNo::
	release
	end

MtSilver_PokemonCenter_EventScript_Meara_AfterUnlockSinjoh::
	msgbox MtSilver_PokemonCenter_Text_Meara3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, MtSilver_PokemonCenter_EventScript_Meara_WarpToSinjoh
	closemessage
	release
	end

MtSilver_PokemonCenter_EventScript_Meara_WarpToSinjoh::
	warp MAP_MT_SILVER_1F_WATERFALL_ROOM_HNS, 43, 9
	waitstate
	release
	end

MtSilver_PokemonCenter_Text_Meara1:
	.string "Sono una ricercatrice del... Ehm...\n"
	.string "museo di PLUMBEOPOLI!\p"
	.string "Sono stati trovati molti artefatti\n"
	.string "insoliti in questa zona, quindi\l"
	.string "sono qui per indagare.\p"
	.string "Hai trovato qualcosa di strano\n"
	.string "sulla montagna?\p"
	.string "Magari qualcosa come un FLUTO?\p"
	.string "Se lo trovi, mostramelo.$"

MtSilver_PokemonCenter_Text_Meara2:
	.string "Quel flauto!\p"
	.string "Hai lo spirito di una vera\n"
	.string "archeologa!\p"
	.string "C'è un ramo della grotta\n"
	.string "dove i POKéMON sono troppo forti\l"
	.string "perché io lo esplori in sicurezza.\p"
	.string "Se ti ci porto, lo esploreresti\n"
	.string "in cerca di altri artefatti?$"

MtSilver_PokemonCenter_Text_Prompt:
	.string "Se ti ci porto, lo esploreresti\n"
	.string "in cerca di altri artefatti?$"

MtSilver_PokemonCenter_Text_Meara3:
	.string "Pronto a cercare altri artefatti?$"

