TwoIsland_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TwoIsland_OnTransition
	.byte 0

TwoIsland_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_TWO_ISLAND
	setflag FLAG_VISITED_TWO_ISLAND
	call TwoIsland_EventScript_SetShopState
	end

TwoIsland_EventScript_SetShopState::
	goto_if_set FLAG_IS_CHAMPION, TwoIsland_EventScript_SetShopStateAfterHoennLink
	goto_if_set FLAG_SYS_GAME_CLEAR, TwoIsland_EventScript_SetShopStateAfterChampion
	goto_if_set FLAG_RESCUED_LOSTELLE, TwoIsland_EventScript_SetShopStateAfterLostelleRescue
	goto TwoIsland_EventScript_SetShopStateDefault
	end

TwoIsland_EventScript_SetShopStateAfterHoennLink::
	goto_if_unset FLAG_TWO_ISLAND_SHOP_INTRODUCED, TwoIsland_EventScript_SetShopInitial
	goto_if_unset FLAG_TWO_ISLAND_SHOP_EXPANDED_1, TwoIsland_EventScript_SetShopExpanded1
	goto_if_unset FLAG_TWO_ISLAND_SHOP_EXPANDED_2, TwoIsland_EventScript_SetShopExpanded2
	goto TwoIsland_EventScript_SetShopExpanded3
	end

TwoIsland_EventScript_SetShopStateAfterChampion::
	goto_if_unset FLAG_TWO_ISLAND_SHOP_INTRODUCED, TwoIsland_EventScript_SetShopInitial
	goto_if_unset FLAG_RESCUED_LOSTELLE, TwoIsland_EventScript_SetShopInitial
	goto_if_unset FLAG_TWO_ISLAND_SHOP_EXPANDED_1, TwoIsland_EventScript_SetShopExpanded1
	goto TwoIsland_EventScript_SetShopExpanded2
	end

TwoIsland_EventScript_SetShopStateAfterLostelleRescue::
	goto_if_unset FLAG_TWO_ISLAND_SHOP_INTRODUCED, TwoIsland_EventScript_SetShopInitial
	goto TwoIsland_EventScript_SetShopExpanded1
	end

TwoIsland_EventScript_SetShopStateDefault::
	goto TwoIsland_EventScript_SetShopInitial
	end

TwoIsland_EventScript_SetShopInitial::
	setvar VAR_MAP_SCENE_TWO_ISLAND, 1
	return

TwoIsland_EventScript_SetShopExpanded1::
	setvar VAR_MAP_SCENE_TWO_ISLAND, 2
	clearflag FLAG_HIDE_TWO_ISLAND_WOMAN
	return

TwoIsland_EventScript_SetShopExpanded2::
	setvar VAR_MAP_SCENE_TWO_ISLAND, 3
	clearflag FLAG_HIDE_TWO_ISLAND_BEAUTY
	return

TwoIsland_EventScript_SetShopExpanded3::
	setvar VAR_MAP_SCENE_TWO_ISLAND, 4
	clearflag FLAG_HIDE_TWO_ISLAND_SUPER_NERD
	return

TwoIsland_EventScript_Clerk::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND, 4, TwoIsland_EventScript_ClerkShopExpanded3
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND, 3, TwoIsland_EventScript_ClerkShopExpanded2
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND, 2, TwoIsland_EventScript_ClerkShopExpanded1
	goto TwoIsland_EventScript_ClerkShopInitial
	end

TwoIsland_EventScript_ClerkShopExpanded3::
	goto_if_set FLAG_TWO_ISLAND_SHOP_EXPANDED_3, TwoIsland_EventScript_ClerkShopSkipIntro
	setflag FLAG_TWO_ISLAND_SHOP_EXPANDED_3
	message TwoIsland_Text_BringingItemsFromDistantLands
	waitmessage
	goto TwoIsland_EventScript_ShopExpanded3
	end

TwoIsland_EventScript_ClerkShopExpanded2::
	goto_if_set FLAG_TWO_ISLAND_SHOP_EXPANDED_2, TwoIsland_EventScript_ClerkShopSkipIntro
	setflag FLAG_TWO_ISLAND_SHOP_EXPANDED_2
	message TwoIsland_Text_HopeYouGiveItYourBest
	waitmessage
	goto TwoIsland_EventScript_ShopExpanded2
	end

TwoIsland_EventScript_ClerkShopExpanded1::
	goto_if_set FLAG_TWO_ISLAND_SHOP_EXPANDED_1, TwoIsland_EventScript_ClerkShopSkipIntro
	setflag FLAG_TWO_ISLAND_SHOP_EXPANDED_1
	message TwoIsland_Text_AddedMerchandiseForLostelle
	waitmessage
	goto TwoIsland_EventScript_ShopExpanded1
	end

TwoIsland_EventScript_ClerkShopInitial::
	goto_if_set FLAG_TWO_ISLAND_SHOP_INTRODUCED, TwoIsland_EventScript_ClerkShopSkipIntro
	setflag FLAG_TWO_ISLAND_SHOP_INTRODUCED
	message TwoIsland_Text_WelcomeToShopMerchandiseLimited
	waitmessage
	goto TwoIsland_EventScript_ShopInitial
	end

TwoIsland_EventScript_ClerkShopSkipIntro::
	message gText_HowMayIServeYou
	waitmessage
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND, 4, TwoIsland_EventScript_ShopExpanded3
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND, 3, TwoIsland_EventScript_ShopExpanded2
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND, 2, TwoIsland_EventScript_ShopExpanded1
	goto TwoIsland_EventScript_ShopInitial
	end

TwoIsland_EventScript_ShopInitial::
	pokemart TwoIsland_Items_ShopInitial
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
TwoIsland_Items_ShopInitial::
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_NONE
	release
	end

TwoIsland_EventScript_ShopExpanded1::
	pokemart TwoIsland_Items_ShopExpanded1
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
TwoIsland_Items_ShopExpanded1::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SODA_POP
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_NONE
	release
	end

TwoIsland_EventScript_ShopExpanded2::
	pokemart TwoIsland_Items_ShopExpanded2
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
TwoIsland_Items_ShopExpanded2::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_LEMONADE
	.2byte ITEM_SODA_POP
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_MOOMOO_MILK
	.2byte ITEM_NONE
	release
	end

TwoIsland_EventScript_ShopExpanded3::
	pokemart TwoIsland_Items_ShopExpanded3
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
TwoIsland_Items_ShopExpanded3::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_REPEAT_BALL
	.2byte ITEM_TIMER_BALL
	.2byte ITEM_LEMONADE
	.2byte ITEM_SODA_POP
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_MOOMOO_MILK
	.2byte ITEM_LAVA_COOKIE
	.2byte ITEM_NONE
	release
	end

TwoIsland_EventScript_Sailor::
	msgbox TwoIsland_Text_FellowMovedFromCeladonCity, MSGBOX_NPC
	end

TwoIsland_EventScript_Woman::
	msgbox TwoIsland_Text_ShopkeepersBrotherWorksGameCorner, MSGBOX_NPC
	end

TwoIsland_EventScript_Beauty::
	lock
	faceplayer
	famechecker FAMECHECKER_BRUNO, 4
	msgbox TwoIsland_Text_BrunoCameToIslandWhileBack
	release
	end

TwoIsland_EventScript_SuperNerd::
	msgbox TwoIsland_Text_BuyRareItemsHere, MSGBOX_NPC
	end

TwoIsland_EventScript_Boy::
	msgbox TwoIsland_Text_OldWomanLivesOutOnCape, MSGBOX_NPC
	end

TwoIsland_EventScript_LittleBoy::
	msgbox TwoIsland_Text_HaveYouTriedJumpingGame, MSGBOX_NPC
	end

TwoIsland_EventScript_IslandSign::
	msgbox TwoIsland_Text_IslandSign, MSGBOX_SIGN
	end

TwoIsland_EventScript_JoyfulGameCornerSign::
	msgbox TwoIsland_Text_JoyfulGameCornerSign, MSGBOX_SIGN
	end

TwoIsland_EventScript_FastCurrentSign::
	msgbox TwoIsland_Text_DangerFastCurrent, MSGBOX_SIGN
	end

TwoIsland_Text_IslandSign::
	.string "ISOLA DUE\n"
	.string "L'isola fortunata per due$"

TwoIsland_Text_JoyfulGameCornerSign::
	.string "Skip & Chomp!\n"
	.string "GAME CORNER gioioso$"

TwoIsland_Text_DangerFastCurrent::
	.string "PERICOLO! CORRENTE VELOCE!\n"
	.string "Pesca e surf proibiti!$"

TwoIsland_Text_WelcomeToShopMerchandiseLimited::
	.string "Oh!\n"
	.string "Ciao, benvenuto nel mio negozio!\p"
	.string "Abbiamo aperto da poco.\p"
	.string "La nostra merce è limitata, ma\n"
	.string "spero di soddisfare le tue esigenze.$"

TwoIsland_Text_AddedMerchandiseForLostelle::
	.string "Non so dirti quanto ti sia grato\n"
	.string "per aver salvato LOSTELLE.\p"
	.string "Grazie alla tua impresa, la gente di\n"
	.string "TERZA ISOLA ha cambiato\l"
	.string "atteggiamento verso la gente di KANTO.\p"
	.string "E io vengo da KANTO, sai.\p"
	.string "La gente di TERZA ISOLA\n"
	.string "mi ha aiutato ad ampliare la merce.$"

TwoIsland_Text_HopeYouGiveItYourBest::
	.string "Ciao! Io do il massimo qui.\n"
	.string "Spero che lo faccia anche tu, {PLAYER}.$"

TwoIsland_Text_BringingItemsFromDistantLands::
	.string "Oh, ciao, {PLAYER}!\n"
	.string "Benvenuto!\p"
	.string "Ho iniziato a importare oggetti da\n"
	.string "terre lontane.\p"
	.string "Ho anche degli oggetti rari.\n"
	.string "Dai un'occhiata!$"

TwoIsland_Text_FellowMovedFromCeladonCity::
	.string "That fellow there, he moved here\n"
	.string "from CELADON CITY.\p"
	.string "He started up a shop with his\n"
	.string "younger brother.\p"
	.string "You have to wonder if he knew what\n"
	.string "he was getting into.$"

TwoIsland_Text_ShopkeepersBrotherWorksGameCorner::
	.string "Il fratello del negoziante ha preso\n"
	.string "un lavoro al GAME CORNER.\p"
	.string "Cerca di mettere insieme dei soldi\n"
	.string "per comprare più merce.$"

TwoIsland_Text_BrunoCameToIslandWhileBack::
	.string "Listen, listen.\n"
	.string "Did you know?\p"
	.string "A famous TRAINER came to the\n"
	.string "ISLAND a little while back.\p"
	.string "He's one of the ELITE FOUR.\n"
	.string "His name is BRUNO.\p"
	.string "He went away disappointed when he\n"
	.string "found out that they were all sold\l"
	.string "out of Rage Candybars.$"

TwoIsland_Text_BuyRareItemsHere::
	.string "L'ALLENATORE esperto sa\n"
	.string "comprare oggetti rari qui!$"

TwoIsland_Text_OldWomanLivesOutOnCape::
	.string "C'è una signora anziana che vive in\n"
	.string "una casetta sul promontorio.\p"
	.string "Fa l'occhiolino ai POKéMON.\n"
	.string "È un po' inquietante.$"

TwoIsland_Text_HaveYouTriedJumpingGame::
	.string "Boing! Boing!\n"
	.string "Hai provato il gioco del salto?\p"
	.string "I POKéMON che puoi schierare…\n"
	.string "Boing!\p"
	.string "Alcuni fanno boing!\p"
	.string "E altri fanno boooooooing!\p"
	.string "Lo sapevi?\n"
	.string "Boing!$"

