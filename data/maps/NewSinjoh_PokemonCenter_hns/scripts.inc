NewSinjoh_PokemonCenter_hns_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, NewSinjoh_PokemonCenter_OnTransition
    .byte 0

NewSinjoh_PokemonCenter_OnTransition: 
    setrespawn HEAL_LOCATION_NEW_SINJOH_HNS
    end

NewSinjoh_EventScript_Artist::
	lock
	faceplayer
	goto_if_set FLAG_NEWSINJOH_POKEMONCENTER_ARTIST_GIFT, NewSinjoh_EventScript_ZoomLens_Gotten
	msgbox NewSinjoh_Text_Artist, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, NewSinjoh_EventScript_ZoomLens_No
	msgbox Text_ItemGiveaway, MSGBOX_DEFAULT
	giveitem ITEM_ZOOM_LENS
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_NEWSINJOH_POKEMONCENTER_ARTIST_GIFT
	release
	end

NewSinjoh_PokemonCenter_EventScript_Skiier::
	lock
	faceplayer
	msgbox NewSinjoh_PokemonCenter_Text_Skiier, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_NEWSINJOH_POKEMONCENTER_SKIIER, DIR_NORTH
	release
	end

NewSinjoh_PokemonCenter_hns_Map::
	lockall
	setvar VAR_0x8000, 1 @ SCREENSHOT_SINJOH_MAP
	msgbox NewSinjoh_PokemonCenter_hns_Text_0, MSGBOX_DEFAULT
	closemessage
	callnative OpenScreenshotsFromScript
	waitstate
	releaseall
	end

NewSinjoh_PokemonCenter_Text_Skiier:
	.string "La neve rende difficile orientarsi\n"
	.string "da queste parti.\p"
	.string "Sembra tutto uguale.\p"
	.string "Questa mappa è un grande aiuto!\p"
	.string "Che regione meravigliosa!$"

NewSinjoh_Text_Artist:
	.string "Ho trovato grande ispirazione\n"
	.string "in questa città nascosta!\p"
	.string "Non trovi che il paesaggio\n"
    .string "sia mozzafiato?$"

Text_ItemGiveaway:
	.string "Capisco!\n"
	.string "Anche tu devi essere un artista!\p"
	.string "Ho giusto un extra che\n"
	.string "ti aiuterà a notare i piccoli\l"
    .string "dettagli della vita!$"

NewSinjoh_Text_Artist_No:
    .string "Non sarai mica uno di quelli\n"
    .string "contro i turisti?\n"
	.string "La bellezza va condivisa.$"

NewSinjoh_EventScript_ZoomLens_No::
	msgbox NewSinjoh_Text_Artist_No, MSGBOX_DEFAULT
	release
	end

NewSinjoh_EventScript_ZoomLens_Gotten::
	msgbox Text_WasGiven_ZoomLensAlready, MSGBOX_DEFAULT
	release
	end

Text_WasGiven_ZoomLensAlready:
	.string "Spero che quella lente ti piaccia!$"

NewSinjoh_EventScript_FemAce::
	msgbox NewSinjoh_Text_FemAce, MSGBOX_NPC
	end

NewSinjoh_Text_FemAce:
	.string "Non abbiamo molte comodità\n"
	.string "moderne a NUOVA ROVINE SINJOH.\p"
	.string "Ma almeno abbiamo questo\n"
	.string "CENTRO POKéMON.$"


NewSinjoh_PokemonCenter_hns_Text_0:
	.string "{PLAYER} ha osservato più da vicino\n"
	.string "la mappa di ROVINE SINJOH.$"
