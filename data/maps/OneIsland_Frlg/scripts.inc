OneIsland_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OneIsland_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OneIsland_OnFrame
	.byte 0

OneIsland_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_ONE_ISLAND
	end

OneIsland_OnFrame::
	map_script_2 VAR_MAP_SCENE_ONE_ISLAND_HARBOR, 2, OneIsland_EventScript_EnterOneIslandFirstTime
	.2byte 0

OneIsland_EventScript_EnterOneIslandFirstTime::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_PLAYER, OneIsland_Movement_PlayerExitHarbor
	waitmovement 0
	msgbox OneIsland_Text_BillLetsGoSeeCelio
	closemessage
	applymovement LOCALID_ONE_ISLAND_BILL, OneIsland_Movement_BillWalkToPokeCenter
	applymovement LOCALID_PLAYER, OneIsland_Movement_PlayerWalkToPokeCenter
	waitmovement 0
	opendoor 14, 5
	waitdooranim
	applymovement LOCALID_ONE_ISLAND_BILL, OneIsland_Movement_BillEnterPokeCenter
	applymovement LOCALID_PLAYER, OneIsland_Movement_PlayerEnterPokeCenter
	waitmovement 0
	closedoor 14, 5
	waitdooranim
	removeobject LOCALID_ONE_ISLAND_BILL
	setvar VAR_MAP_SCENE_ONE_ISLAND_HARBOR, 3
	warp MAP_ONE_ISLAND_POKEMON_CENTER_1F, 9, 9
	waitstate
	releaseall
	end

	.macro walk_to_pokecenter
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	.endm

OneIsland_Movement_PlayerWalkToPokeCenter::
	walk_up
	walk_to_pokecenter
	step_end

OneIsland_Movement_PlayerEnterPokeCenter::
	walk_up
	walk_up
	set_invisible
	step_end

OneIsland_Movement_PlayerExitHarbor::
	walk_up
	step_end

OneIsland_Movement_BillWalkToPokeCenter::
	walk_to_pokecenter
	walk_up
	step_end

OneIsland_Movement_BillEnterPokeCenter::
	walk_up
	set_invisible
	step_end

OneIsland_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_IS_CHAMPION, OneIsland_EventScript_OldManLinkHoenn
	goto_if_set FLAG_SEVII_DETOUR_FINISHED, OneIsland_EventScript_OldManLinkKanto
	msgbox OneIsland_Text_LuckyToHaveCelioHere
	release
	end

OneIsland_EventScript_OldManLinkKanto::
	msgbox OneIsland_Text_HavePCLinkageWithKanto
	release
	end

OneIsland_EventScript_OldManLinkHoenn::
	msgbox OneIsland_Text_HavePCLinkageWithHoenn
	release
	end

OneIsland_EventScript_BaldingMan::
	msgbox OneIsland_Text_IsntWarmClimateHereGreat, MSGBOX_NPC
	end

OneIsland_EventScript_IslandSign::
	msgbox OneIsland_Text_IslandSign, MSGBOX_SIGN
	end

OneIsland_EventScript_PokemonNetCenterSign::
	msgbox OneIsland_Text_PokemonNetCenterSign, MSGBOX_SIGN
	end

OneIsland_Text_BillLetsGoSeeCelio::
	.string "BILL: Eccoci!\n"
	.string "Questa è l'ISOLA UNO.\p"
	.string "Ci sono varie isole qui\n"
	.string "intorno, e questa è una di quelle.\p"
	.string "Il mio amico CELIO ha mandato la nave\n"
	.string "a prendermi qui.\p"
	.string "Gestisce la rete PC dell'isola\n"
	.string "tutto da solo.\p"
	.string "...Perché te lo sto dicendo ora?\n"
	.string "Andiamo a vedere CELIO!$"

Text_WhereDoYouWantToSail::
	.string "Ehi, ciao!\n"
	.string "Dove vuoi salpare?$"

OneIsland_Text_LuckyToHaveCelioHere::
	.string "Siamo su un'isola in mezzo al\n"
	.string "nulla.\p"
	.string "Siamo fortunati ad avere un ragazzo\n"
	.string "perbene come CELIO qui.\p"
	.string "Mia nipote era in agitazione\n"
	.string "per l'amico di CELIO.\p"
	.string "Qualcosa su un famoso\n"
	.string "POKéMANIACO?\p"
	.string "Non so bene cosa significhi, ma\n"
	.string "CELIO è un ragazzo in gamba!$"

OneIsland_Text_HavePCLinkageWithKanto::
	.string "Mia nipote era in agitazione\n"
	.string "per una nuova scoperta.\p"
	.string "Dice che ora abbiamo il collegamento PC\n"
	.string "con la gente di KANTO.\p"
	.string "Non so bene cosa significhi, ma\n"
	.string "CELIO è un ragazzo in gamba!$"

OneIsland_Text_HavePCLinkageWithHoenn::
	.string "Mia nipote era in agitazione\n"
	.string "per una nuova scoperta.\p"
	.string "Dice che ora abbiamo il collegamento PC\n"
	.string "con la gente di HOENN.\p"
	.string "Non so bene cosa significhi, ma\n"
	.string "CELIO è un ragazzo in gamba.\p"
	.string "Sarebbe un ottimo marito per\n"
	.string "mia nipote!$"

OneIsland_Text_IslandSign::
	.string "ISOLA UNO\n"
	.string "Gli amici si incontrano a Isola Nodo$"

OneIsland_Text_PokemonNetCenterSign::
	.string "Espandiamo il mondo POKéMON!\n"
	.string "CENTRO RETE POKéMON$"

@ Unused
OneIsland_Text_ReturnToCinnabar::
	.string "グレンタウンに　もどりますか？$"

OneIsland_Text_IsntWarmClimateHereGreat::
	.string "Ciao, sei qui in visita?\n"
	.string "Non è fantastico il clima caldo qui?$"

