OneIsland_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OneIsland_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	map_script MAP_SCRIPT_ON_LOAD, OneIsland_PokemonCenter_1F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OneIsland_PokemonCenter_1F_OnFrame
	.byte 0

OneIsland_PokemonCenter_1F_OnLoad::
	call_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, OneIsland_PokemonCenter_1F_EventScript_SetRubyMetatile
	call_if_set FLAG_IS_CHAMPION, OneIsland_PokemonCenter_1F_EventScript_SetNetworkMachineOn
	end

OneIsland_PokemonCenter_1F_EventScript_SetRubyMetatile::
	setmetatile 13, 4, METATILE_PokemonCenterFrlg_NetworkMachine_Ruby, 1
	return

OneIsland_PokemonCenter_1F_EventScript_SetSapphireMetatile::
	setmetatile 16, 4, METATILE_PokemonCenterFrlg_NetworkMachine_Sapphire, 1
	return

OneIsland_PokemonCenter_1F_EventScript_SetNetworkMachineOn::
	call OneIsland_PokemonCenter_1F_EventScript_SetSapphireMetatile
	setmetatile 14, 4, METATILE_PokemonCenterFrlg_NetworkMachine_ScreenLeft_On, 1
	setmetatile 15, 4, METATILE_PokemonCenterFrlg_NetworkMachine_ScreenRight_On, 1
	return

OneIsland_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_ONE_ISLAND
	call_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 6, OneIsland_PokemonCenter_1F_EventScript_SetCelioQuestDone
	call_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 0, OneIsland_PokemonCenter_1F_EventScript_SetBillCelioFirstMeetingPos
	call_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 2, OneIsland_PokemonCenter_1F_EventScript_SetBillCelioReadyToLeavePos
	end

OneIsland_PokemonCenter_1F_EventScript_SetCelioQuestDone::
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 7
	return

OneIsland_PokemonCenter_1F_EventScript_SetBillCelioFirstMeetingPos::
	setobjectxyperm LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, 9, 8
	setobjectmovementtype LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, MOVEMENT_TYPE_FACE_UP
	setobjectxyperm LOCALID_CELIO, 15, 6
	setobjectmovementtype LOCALID_CELIO, MOVEMENT_TYPE_FACE_UP
	return

OneIsland_PokemonCenter_1F_EventScript_SetBillCelioReadyToLeavePos::
	setobjectxyperm LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, 14, 7
	setobjectmovementtype LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm LOCALID_CELIO, 14, 8
	setobjectmovementtype LOCALID_CELIO, MOVEMENT_TYPE_FACE_LEFT
	return

OneIsland_PokemonCenter_1F_OnFrame::
	map_script_2 VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 0, OneIsland_PokemonCenter_1F_EventScript_MeetCelioScene
	.2byte 0

OneIsland_PokemonCenter_1F_EventScript_MeetCelioScene::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerWalkToCelio
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, OneIsland_PokemonCenter_1F_Movement_BillWalkToCelio
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_BillHeyThereCelio
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_CELIO, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_CELIO, Common_Movement_Delay48
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_CelioCantBelieveYouCameOut
	msgbox OneIsland_PokemonCenter_1F_Text_BillHowsYourResearchComing
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_ThisIsMyBuddyCelio
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	call_if_set FLAG_SYS_GAME_CLEAR, OneIsland_PokemonCenter_1F_EventScript_IntroducePlayerChamp
	call_if_unset FLAG_SYS_GAME_CLEAR, OneIsland_PokemonCenter_1F_EventScript_IntroducePlayerNotChamp
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_CelioThatsReallyImpressive
	msgbox OneIsland_PokemonCenter_1F_Text_BillBringMeUpToSpeed
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_CelioPCsCantLinkWithYours
	closemessage
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_BillLetMeHelpYou
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_CanYouDeliverThisMeteoritePlayer
	msgreceiveditem OneIsland_PokemonCenter_1F_Text_AcceptedMeteoriteFromBill, ITEM_METEORITE, 1, MUS_RG_OBTAIN_KEY_ITEM
	additem ITEM_METEORITE
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_CelioPleaseTakeThis
	giveitem_msg OneIsland_PokemonCenter_1F_Text_ObtainedTriPass, ITEM_TRI_PASS, 1, MUS_RG_OBTAIN_KEY_ITEM
	msgbox OneIsland_PokemonCenter_1F_Text_PassLetsYouTravelBetweenIslands
	call_if_ge VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, OneIsland_PokemonCenter_1F_EventScript_ReceiveTownMapPage
	call_if_lt VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, OneIsland_PokemonCenter_1F_EventScript_ReceiveTownMap
	setflag FLAG_SYS_SEVII_MAP_123
	msgbox OneIsland_PokemonCenter_1F_Text_BillCatchYouLater
	closemessage
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	setflag FLAG_SYS_PC_STORAGE_DISABLED
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1
	releaseall
	end

OneIsland_PokemonCenter_1F_EventScript_IntroducePlayerChamp::
	msgbox OneIsland_PokemonCenter_1F_Text_PlayerIsReigningPokemonChamp
	return

OneIsland_PokemonCenter_1F_EventScript_IntroducePlayerNotChamp::
	msgbox OneIsland_PokemonCenter_1F_Text_PlayerIsRisingPokemonChamp
	return

OneIsland_PokemonCenter_1F_EventScript_ReceiveTownMapPage::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message OneIsland_PokemonCenter_1F_Text_ReceivedExtraPageForTownMap
	waitmessage
	waitfanfare
	call EventScript_RestorePrevTextColor
	return

OneIsland_PokemonCenter_1F_EventScript_ReceiveTownMap::
	setflag FLAG_HIDE_TOWN_MAP
	setvar VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2
	giveitem_msg OneIsland_PokemonCenter_1F_Text_ReceivedTownMap, ITEM_TOWN_MAP, 1, MUS_RG_OBTAIN_KEY_ITEM
	return

OneIsland_PokemonCenter_1F_Movement_PlayerWalkToCelio::
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

OneIsland_PokemonCenter_1F_Movement_BillWalkToCelio::
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_in_place_faster_right
	step_end

@ Unused
OneIsland_PokemonCenter_1F_Movement_WalkUp:
	walk_up
	step_end

@ Unused
OneIsland_PokemonCenter_1F_Movement_StepAsideLeft::
	walk_left
	walk_in_place_faster_right
	step_end

OneIsland_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

OneIsland_PokemonCenter_1F_EventScript_Bill::
	lock
	goto_if_set FLAG_SEVII_DETOUR_FINISHED, OneIsland_PokemonCenter_1F_EventScript_BillGoTakeStroll
	msgbox OneIsland_PokemonCenter_1F_Text_HmmHowAboutLikeThis
	release
	end

OneIsland_PokemonCenter_1F_EventScript_BillGoTakeStroll::
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_FacePlayer
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_GotPCWorkingStrollAWhileMore
	release
	end

OneIsland_PokemonCenter_1F_EventScript_Celio::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 7, OneIsland_PokemonCenter_1F_EventScript_CelioGiveBillFact
	goto_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 6, OneIsland_PokemonCenter_1F_EventScript_CelioJustGivenSapphire
	goto_if_set FLAG_RECOVERED_SAPPHIRE, OneIsland_PokemonCenter_1F_EventScript_GiveCelioSapphire
	goto_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, OneIsland_PokemonCenter_1F_EventScript_ExplainRainbowPass
	goto_if_set FLAG_GOT_RUBY, OneIsland_PokemonCenter_1F_EventScript_GiveCelioRuby
	goto_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 4, OneIsland_PokemonCenter_1F_EventScript_CelioWaitingForRuby
	specialvar VAR_RESULT, IsNationalPokedexEnabled
	goto_if_eq VAR_RESULT, TRUE, OneIsland_PokemonCenter_1F_EventScript_CelioRequestRuby
	goto_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 3, OneIsland_PokemonCenter_1F_EventScript_CelioPlayerMissingNationalDex
	msgbox OneIsland_PokemonCenter_1F_Text_SorryForBeingPoorHost
	closemessage
	applymovement LOCALID_CELIO, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

OneIsland_PokemonCenter_1F_EventScript_CelioGiveBillFact::
	msgbox OneIsland_PokemonCenter_1F_Text_CelioHearingRumorsAboutYou
	random 3
	goto_if_eq VAR_RESULT, 0, OneIsland_PokemonCenter_1F_EventScript_BillFact1
	goto_if_eq VAR_RESULT, 1, OneIsland_PokemonCenter_1F_EventScript_BillFact2
	famechecker FAMECHECKER_BILL, 5
	msgbox OneIsland_PokemonCenter_1F_Text_BillCantStomachMilk
	release
	end

OneIsland_PokemonCenter_1F_EventScript_BillFact1::
	famechecker FAMECHECKER_BILL, 3
	msgbox OneIsland_PokemonCenter_1F_Text_BillsFirstMonWasAbra
	release
	end

OneIsland_PokemonCenter_1F_EventScript_BillFact2::
	famechecker FAMECHECKER_BILL, 4
	msgbox OneIsland_PokemonCenter_1F_Text_BillsHometownInGoldenrod
	release
	end

OneIsland_PokemonCenter_1F_EventScript_CelioJustGivenSapphire::
	msgbox OneIsland_PokemonCenter_1F_Text_WishYouBestOfLuck
	release
	end

OneIsland_PokemonCenter_1F_EventScript_GiveCelioSapphire::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_OBTAIN_TMHM
	message OneIsland_PokemonCenter_1F_Text_HandedSapphireToCelio
	waitmessage
	waitfanfare
	call EventScript_RestorePrevTextColor
	removeitem ITEM_SAPPHIRE
	msgbox OneIsland_PokemonCenter_1F_Text_ThankYouGiveMeTime
	closemessage
	applymovement LOCALID_CELIO, OneIsland_PokemonCenter_1F_Movement_CelioPutGemInMachine
	waitmovement 0
	playse SE_CLICK
	call OneIsland_PokemonCenter_1F_EventScript_SetSapphireMetatile
	special DrawWholeMapView
	msgbox OneIsland_PokemonCenter_1F_Text_OkayThisIsGood
	closemessage
	delay 60
	applymovement LOCALID_CELIO, OneIsland_PokemonCenter_1F_Movement_CelioCheckMachine
	waitmovement 0
	delay 30
	applymovement LOCALID_CELIO, OneIsland_PokemonCenter_1F_Movement_CelioCheckMachine
	waitmovement 0
	delay 40
	playse SE_PC_ON
	call OneIsland_PokemonCenter_1F_EventScript_SetNetworkMachineOn
	special DrawWholeMapView
	msgbox OneIsland_PokemonCenter_1F_Text_LinkedUpWithLanette
	applymovement LOCALID_CELIO, Common_Movement_FacePlayer
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_ManagedToLinkWithHoennThankYou
	special SetPostgameFlags
	setflag FLAG_IS_CHAMPION
	setflag FLAG_HIDE_CERULEAN_CAVE_GUARD
	setflag FLAG_HIDE_LORELEI_IN_HER_HOUSE
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 6
	special InitRoamer
	release
	end

OneIsland_PokemonCenter_1F_EventScript_ExplainRainbowPass::
	msgbox OneIsland_PokemonCenter_1F_Text_PassLetYouGetToAllIslands
	release
	end

OneIsland_PokemonCenter_1F_EventScript_GiveCelioRuby::
	msgbox OneIsland_PokemonCenter_1F_Text_OhThats
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_OBTAIN_TMHM
	message OneIsland_PokemonCenter_1F_Text_HandedRubyToCelio
	waitmessage
	waitfanfare
	call EventScript_RestorePrevTextColor
	closemessage
	applymovement LOCALID_CELIO, OneIsland_PokemonCenter_1F_Movement_CelioPutGemInMachine
	waitmovement 0
	playse SE_CLICK
	call OneIsland_PokemonCenter_1F_EventScript_SetRubyMetatile
	special DrawWholeMapView
	delay 30
	applymovement LOCALID_CELIO, Common_Movement_FacePlayer
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_MayIAskOneMoreFavor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OneIsland_PokemonCenter_1F_EventScript_DeclineHelpCelio
	goto OneIsland_PokemonCenter_1F_EventScript_GiveRainbowPass
	end

OneIsland_PokemonCenter_1F_EventScript_DeclineHelpCelio::
	msgbox OneIsland_PokemonCenter_1F_Text_PleaseINeedYourHelp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OneIsland_PokemonCenter_1F_EventScript_DeclineHelpCelio
	goto OneIsland_PokemonCenter_1F_EventScript_GiveRainbowPass
	end

OneIsland_PokemonCenter_1F_EventScript_GiveRainbowPass::
	msgbox OneIsland_PokemonCenter_1F_Text_AnotherGemstoneInSeviiIslands
	removeitem ITEM_RUBY
	removeitem ITEM_TRI_PASS
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5
	additem ITEM_RAINBOW_PASS
	setflag FLAG_SYS_SEVII_MAP_4567
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message OneIsland_PokemonCenter_1F_Text_ReturnedTriPassForRainbowPass
	waitmessage
	waitfanfare
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message OneIsland_PokemonCenter_1F_Text_ObtainedExtraMapPage
	waitmessage
	waitfanfare
	call EventScript_RestorePrevTextColor
	goto OneIsland_PokemonCenter_1F_EventScript_ExplainRainbowPass
	end

OneIsland_PokemonCenter_1F_EventScript_CelioWaitingForRuby::
	msgbox OneIsland_PokemonCenter_1F_Text_TryingToFindGem
	release
	end

OneIsland_PokemonCenter_1F_EventScript_CelioRequestRuby::
	msgbox OneIsland_PokemonCenter_1F_Text_CelioCaughtMoreMonMaybeICanBeUseful
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_YoullBeTradingFromTrainersFarAway
	applymovement LOCALID_CELIO, Common_Movement_FacePlayer
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_NeedsSpecialGemstone
	setvar VAR_MAP_SCENE_MT_EMBER_EXTERIOR, 1
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 4
	release
	end

OneIsland_PokemonCenter_1F_EventScript_CelioPlayerMissingNationalDex::
	msgbox OneIsland_PokemonCenter_1F_Text_CelioImModifyingMyNetworkMachine
	release
	end

OneIsland_PokemonCenter_1F_Movement_CelioCheckMachine::
	walk_in_place_up
	delay_8
	walk_in_place_up
	step_end

OneIsland_PokemonCenter_1F_Movement_CelioPutGemInMachine::
	walk_in_place_faster_up
	walk_in_place_up
	delay_16
	walk_in_place_up
	walk_in_place_up
	step_end

OneIsland_PokemonCenter_1F_EventScript_LittleBoy::
	msgbox OneIsland_PokemonCenter_1F_Text_CameFromPalletDontKnowIt, MSGBOX_NPC
	end

OneIsland_PokemonCenter_1F_EventScript_Hiker::
	msgbox OneIsland_PokemonCenter_1F_Text_EnormousVolcanoOnIsland, MSGBOX_NPC
	end

OneIsland_PokemonCenter_1F_EventScript_BattleGirl::
	lock
	faceplayer
	goto_if_set FLAG_IS_CHAMPION, OneIsland_PokemonCenter_1F_EventScript_BattleGirlHoennLinked
	msgbox OneIsland_PokemonCenter_1F_Text_WishICouldTradeWithBoyfriend
	release
	end

OneIsland_PokemonCenter_1F_EventScript_BattleGirlHoennLinked::
	msgbox OneIsland_PokemonCenter_1F_Text_TradedWithFarAwayBoyfriend
	release
	end

OneIsland_PokemonCenter_1F_EventScript_NetworkMachine::
	lockall
	goto_if_set FLAG_IS_CHAMPION, OneIsland_PokemonCenter_1F_EventScript_NetworkMachineLinkedWithHoenn
	goto_if_set FLAG_SEVII_DETOUR_FINISHED, OneIsland_PokemonCenter_1F_EventScript_NetworkMachineLinkedWithKanto
	msgbox OneIsland_PokemonCenter_1F_Text_MachineUnderAdjustment
	releaseall
	end

OneIsland_PokemonCenter_1F_EventScript_NetworkMachineLinkedWithKanto::
	msgbox OneIsland_PokemonCenter_1F_Text_MachineLinkedWithKanto
	releaseall
	end

OneIsland_PokemonCenter_1F_EventScript_NetworkMachineLinkedWithHoenn::
	msgbox OneIsland_PokemonCenter_1F_Text_MachineLinkedWithKantoAndHoenn
	releaseall
	end

OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandTriggerTop::
	lockall
	setvar VAR_TEMP_1, 1
	goto OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandScene
	end

OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandTriggerMidTop::
	lockall
	setvar VAR_TEMP_1, 2
	goto OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandScene
	end

OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandTriggerMidBottom::
	lockall
	setvar VAR_TEMP_1, 3
	goto OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandScene
	end

OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandTriggerBottom::
	lockall
	setvar VAR_TEMP_1, 4
	goto OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandScene
	end

OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandScene::
	textcolor NPC_TEXT_COLOR_MALE
	playse SE_PIN
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_BillOhHeyPlayer
	closemessage
	call_if_eq VAR_TEMP_1, 1, OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillTop
	call_if_eq VAR_TEMP_1, 2, OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillMidTop
	call_if_eq VAR_TEMP_1, 3, OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillMidBottom
	call_if_eq VAR_TEMP_1, 4, OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillBottom
	delay 10
	msgbox OneIsland_PokemonCenter_1F_Text_BillWeGotItDone
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_CelioJobWentQuick
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_BillYouveLearnedALot
	msgbox OneIsland_PokemonCenter_1F_Text_CelioOhReallyEhehe
	closemessage
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 10
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 15
	msgbox OneIsland_PokemonCenter_1F_Text_BillWeShouldHeadBackToKanto
	closemessage
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 15
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_CelioPromiseIllShowYouAroundSometime
	closemessage
	delay 25
	applymovement LOCALID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerExit
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, OneIsland_PokemonCenter_1F_Movement_BillExit
	waitmovement 0
	playse SE_EXIT
	setflag FLAG_HIDE_ONE_ISLAND_POKECENTER_BILL
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 3
	clearflag FLAG_HIDE_CINNABAR_BILL
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND, 3
	setvar VAR_0x8004, SEAGALLOP_ONE_ISLAND
	setvar VAR_0x8006, SEAGALLOP_CINNABAR_ISLAND
	goto EventScript_SetSail
	end

OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillTop::
	applymovement LOCALID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillTop
	waitmovement 0
	return

OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillMidTop::
	applymovement LOCALID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillMidTop
	waitmovement 0
	return

OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillMidBottom::
	applymovement LOCALID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillMidBottom
	waitmovement 0
	return

OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillBottom::
	applymovement LOCALID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillBottom
	waitmovement 0
	return

OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillTop::
	walk_right
	walk_down
	walk_in_place_faster_right
	step_end

OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillMidTop::
	walk_right
	step_end

OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillMidBottom::
	walk_right
	walk_up
	walk_in_place_faster_right
	step_end

OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillBottom::
	walk_right
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

@ Unused
OneIsland_PokemonCenter_1F_Movement_DelayWalkInPlaceLeft::
	delay_16
	delay_16
	delay_4
	walk_in_place_faster_left
	step_end

@ Unused
OneIsland_PokemonCenter_1F_Movement_WalkInPlaceDown::
	walk_in_place_fast_down
	step_end

OneIsland_PokemonCenter_1F_Movement_PlayerExit::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

OneIsland_PokemonCenter_1F_Movement_BillExit::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

OneIsland_PokemonCenter_1F_Text_BillHeyThereCelio::
	.string "BILL: Ehi, ciao!\n"
	.string "CELIO!$"

OneIsland_PokemonCenter_1F_Text_CelioCantBelieveYouCameOut::
	.string "CELIO: BILL!\n"
	.string "Non credo che sei venuto fin qui.$"

OneIsland_PokemonCenter_1F_Text_BillHowsYourResearchComing::
	.string "BILL: Beh, ma certo!\n"
	.string "Come procede la tua ricerca?\p"
	.string "…Oh, aspetta un attimo.$"

OneIsland_PokemonCenter_1F_Text_ThisIsMyBuddyCelio::
	.string "{PLAYER}, lui è il mio amico CELIO.\n"
	.string "È un MANIACO del PC davvero in gamba!$"

OneIsland_PokemonCenter_1F_Text_PlayerIsRisingPokemonChamp::
	.string "CELIO, lui è {PLAYER}, una stella\n"
	.string "nascente fra i campioni POKéMON!$"

OneIsland_PokemonCenter_1F_Text_PlayerIsReigningPokemonChamp::
	.string "CELIO, lui è {PLAYER}, il\n"
	.string "campione POKéMON in carica!$"

OneIsland_PokemonCenter_1F_Text_CelioThatsReallyImpressive::
	.string "CELIO: Davvero impressionante.\p"
	.string "Mi dispiace dirlo, ma non ho\n"
	.string "alcun talento per le lotte.\p"
	.string "Comunque, piacere di conoscerti.$"

OneIsland_PokemonCenter_1F_Text_BillBringMeUpToSpeed::
	.string "BILL: Allora, aggiornami.\n"
	.string "Come va la tua macchina?$"

OneIsland_PokemonCenter_1F_Text_CelioPCsCantLinkWithYours::
	.string "CELIO: Funziona bene, ma qui\n"
	.string "siamo troppo lontani.\p"
	.string "I PC di quest'isola non possono\n"
	.string "collegarsi al tuo, BILL.$"

OneIsland_PokemonCenter_1F_Text_BillLetMeHelpYou::
	.string "BILL: Oh, davvero?\n"
	.string "Ok, fammi dare un'occhiata.\p"
	.string "…Un attimo…\n"
	.string "Penso che possiamo farlo funzionare.\l"
	.string "Lascia che ti aiuti, ok?$"

OneIsland_PokemonCenter_1F_Text_CanYouDeliverThisMeteoritePlayer::
	.string "{PLAYER}, puoi aspettarmi\n"
	.string "solo un attimo?\p"
	.string "…Anzi, puoi farmi\n"
	.string "un favore?\p"
	.string "L'isola accanto a questa si\n"
	.string "chiama ISOLA DUE.\p"
	.string "C'è un tipo lì che gestisce\n"
	.string "una SALA GIOCHI.\p"
	.string "Ha una passione per rocce\n"
	.string "e gemme rare.\p"
	.string "Siamo in contatto, da bravi\n"
	.string "maniaci.\p"
	.string "Allora, puoi consegnare questo\n"
	.string "METEORITE a lui?$"

OneIsland_PokemonCenter_1F_Text_AcceptedMeteoriteFromBill::
	.string "{PLAYER} ha ricevuto il METEORITE\n"
	.string "da BILL.$"

OneIsland_PokemonCenter_1F_Text_CelioPleaseTakeThis::
	.string "CELIO: {PLAYER}, se vai\n"
	.string "all'ISOLA DUE, prendi questo.$"

OneIsland_PokemonCenter_1F_Text_PassLetsYouTravelBetweenIslands::
	.string "È un PASS per il servizio traghetti\n"
	.string "delle isole qui intorno.\p"
	.string "Ti permetterà di viaggiare fra le\n"
	.string "ISOLE UNO, DUE e TRE.\p"
	.string "Oh, prendi anche questo.$"

OneIsland_PokemonCenter_1F_Text_ReceivedExtraPageForTownMap::
	.string "{PLAYER} ha ricevuto una pagina extra\n"
	.string "per il TOWN MAP!$"

OneIsland_PokemonCenter_1F_Text_ReceivedTownMap::
	.string "{PLAYER} ha ricevuto\n"
	.string "un TOWN MAP!$"

OneIsland_PokemonCenter_1F_Text_BillCatchYouLater::
	.string "BILL: Ci vediamo dopo!\n"
	.string "Salutami quel tipo!$"

OneIsland_PokemonCenter_1F_Text_HmmHowAboutLikeThis::
	.string "Hmm…\p"
	.string "Che ne dici di provare così…$"

OneIsland_PokemonCenter_1F_Text_GotPCWorkingStrollAWhileMore::
	.string "Oh, ciao, {PLAYER}!\p"
	.string "Hai visto?\n"
	.string "Abbiamo fatto funzionare il PC!\p"
	.string "Devo mostrare un paio di cose\n"
	.string "a CELIO.\p"
	.string "Puoi andare a fare un giro\n"
	.string "ancora per un po'?$"

OneIsland_PokemonCenter_1F_Text_SorryForBeingPoorHost::
	.string "I'm sorry for taking up so much of\n"
	.string "BILL's time.\p"
	.string "I'm also sorry for being such a \n"
	.string "poor host on your visit here.$"

OneIsland_PokemonCenter_1F_Text_UsualPCServicesUnavailable::
	.string "I soliti servizi del PC non sono\n"
	.string "disponibili…$"

OneIsland_PokemonCenter_1F_Text_BillOhHeyPlayer::
	.string "BILL: Oh, ciao!\n"
	.string "{PLAYER}!$"

OneIsland_PokemonCenter_1F_Text_BillWeGotItDone::
	.string "BILL: Cosa ti ha trattenuto?\n"
	.string "Te la sei spassata un po'?\p"
	.string "Ce l'abbiamo fatta.\n"
	.string "I PC funzionano di nuovo!$"

OneIsland_PokemonCenter_1F_Text_CelioJobWentQuick::
	.string "CELIO: Il lavoro è andato\n"
	.string "incredibilmente veloce.\p"
	.string "BILL è un tipo straordinario…$"

OneIsland_PokemonCenter_1F_Text_BillYouveLearnedALot::
	.string "BILL: No, no! Non era quasi\n"
	.string "rimasto niente da fare.\p"
	.string "CELIO, devo ammetterlo.\n"
	.string "Hai imparato molto.$"

OneIsland_PokemonCenter_1F_Text_CelioOhReallyEhehe::
	.string "CELIO: Oh, davvero?\n"
	.string "Eh eh…$"

OneIsland_PokemonCenter_1F_Text_BillWeShouldHeadBackToKanto::
	.string "BILL: Beh, ecco fatto.\n"
	.string "Ho finito il mio lavoro.\l"
	.string "Dovremmo tornare a KANTO.\p"
	.string "CELIO, ci rivedremo presto.$"

OneIsland_PokemonCenter_1F_Text_CelioPromiseIllShowYouAroundSometime::
	.string "CELIO: {PLAYER}, mi dispiace\n"
	.string "di averti mandato in giro da solo.\p"
	.string "Prometto che ti farò visitare\n"
	.string "queste isole, prima o poi.$"

OneIsland_PokemonCenter_1F_Text_CelioImModifyingMyNetworkMachine::
	.string "CELIO: Ciao!\n"
	.string "Sembri sempre indaffarato.\p"
	.string "Come sto?\p"
	.string "Beh, sto modificando la mia\n"
	.string "Macchina Rete.\p"
	.string "Quando avrò finito, spero che\n"
	.string "tu sia il primo a usarla,\l"
	.string "{PLAYER}.$"

OneIsland_PokemonCenter_1F_Text_CelioCaughtMoreMonMaybeICanBeUseful::
	.string "CELIO: {PLAYER}, come\n"
	.string "te la passi?\p"
	.string "Oh, davvero?\n"
	.string "Hai catturato altri POKéMON.\p"
	.string "Sai una cosa?\n"
	.string "Forse posso esserti utile.$"

OneIsland_PokemonCenter_1F_Text_YoullBeTradingFromTrainersFarAway::
	.string "Sto modificando la Macchina\n"
	.string "di Rete proprio ora.\p"
	.string "La sto cambiando per gestire\n"
	.string "scambi a lunga distanza.\p"
	.string "Quando avrò finito, potrai\n"
	.string "scambiare POKéMON esotici con\l"
	.string "ALLENATORI lontani.$"

OneIsland_PokemonCenter_1F_Text_NeedsSpecialGemstone::
	.string "Ma c'è un piccolo intoppo.\p"
	.string "Perché il link funzioni, la Macchina\n"
	.string "ha bisogno di una gemma speciale.\p"
	.string "Dovrebbe essere sull'ISOLA UNO,\n"
	.string "ma non l'ho ancora trovata.\p"
	.string "Chissà dove può essere.$"

OneIsland_PokemonCenter_1F_Text_TryingToFindGem::
	.string "Cercavo la gemma\n"
	.string "anche mentre studiavo.\p"
	.string "E così non ho fatto progressi\n"
	.string "né nella ricerca né negli studi…\p"
	.string "Se mi affidassi a BILL, la mia\n"
	.string "ricerca andrebbe avanti.\p"
	.string "Ma stavolta voglio provare a fare\n"
	.string "da solo.$"

OneIsland_PokemonCenter_1F_Text_OhThats::
	.string "Oh!\n"
	.string "Q-questo è…$"

OneIsland_PokemonCenter_1F_Text_HandedRubyToCelio::
	.string "{PLAYER} ha consegnato il RUBINO\n"
	.string "a CELIO.$"

OneIsland_PokemonCenter_1F_Text_MayIAskOneMoreFavor::
	.string "Grazie!\n"
	.string "{PLAYER}, sei semplicemente incredibile.\p"
	.string "… … …  … … …\p"
	.string "Ehm… Posso chiederti un altro\n"
	.string "grande favore?$"

OneIsland_PokemonCenter_1F_Text_PleaseINeedYourHelp::
	.string "Non… non è niente di strano.\n"
	.string "Ti prego, ho bisogno del tuo aiuto.$"

OneIsland_PokemonCenter_1F_Text_AnotherGemstoneInSeviiIslands::
	.string "Mentre studiavo le gemme,\n"
	.string "ho scoperto una cosa importante.\p"
	.string "Esiste un'altra gemma che\n"
	.string "fa coppia con questo RUBINO.\p"
	.string "Quell'altra gemma dovrebbe\n"
	.string "essere nelle ISO SETTE.\p"
	.string "{PLAYER}, ti prego, devi andare\n"
	.string "a trovare l'altra gemma.\p"
	.string "{PLAYER}, posso avere il tuo\n"
	.string "BIGLIETTO e la MAPPA CITTÀ?$"

OneIsland_PokemonCenter_1F_Text_ReturnedTriPassForRainbowPass::
	.string "{PLAYER} ha restituito il TRI-PASS e\n"
	.string "ricevuto il RAINBOW PASS.$"

OneIsland_PokemonCenter_1F_Text_ObtainedExtraMapPage::
	.string "Hai ottenuto una pagina extra per la\n"
	.string "MAPPA CITTÀ!$"

OneIsland_PokemonCenter_1F_Text_PassLetYouGetToAllIslands::
	.string "Questo è il mio PASS del traghetto.\p"
	.string "Ti porterà in tutte le\n"
	.string "SEVII ISLANDS.\p"
	.string "{PLAYER}, ti prego, non posso\n"
	.string "farcela senza il tuo aiuto.$"

OneIsland_PokemonCenter_1F_Text_HandedSapphireToCelio::
	.string "{PLAYER} ha consegnato lo ZAFFIRO\n"
	.string "a CELIO.$"

OneIsland_PokemonCenter_1F_Text_ThankYouGiveMeTime::
	.string "CELIO: Quindi è la gemma che\n"
	.string "fa il paio con il RUBINO…\p"
	.string "{PLAYER}, hai fatto di tutto\n"
	.string "per averla, vero?\p"
	.string "Non serve che me lo dica. Lo so\n"
	.string "che non è stato facile.\p"
	.string "Grazie mille!\p"
	.string "Ora tocca a me lavorare per te!\n"
	.string "Dammi solo un po' di tempo.$"

OneIsland_PokemonCenter_1F_Text_OkayThisIsGood::
	.string "Okay, così va bene…$"

OneIsland_PokemonCenter_1F_Text_LinkedUpWithLanette::
	.string "Ce l'ho fatta!\n"
	.string "Mi sono collegato con LANETTE!$"

OneIsland_PokemonCenter_1F_Text_ManagedToLinkWithHoennThankYou::
	.string "{PLAYER}…\n"
	.string "{PLAYER}, ce l'ho fatta!\p"
	.string "Sono riuscito a collegarmi con\n"
	.string "gli ALLENATORI di HOENN!\p"
	.string "Finalmente la Macchina Rete è\n"
	.string "pienamente operativa!\p"
	.string "{PLAYER}, lo devo tutto a te!\p"
	.string "Grazie a te, il mio sogno si è\n"
	.string "avverato…$"

OneIsland_PokemonCenter_1F_Text_WishYouBestOfLuck::
	.string "Io…\n"
	.string "non sto piangendo.\p"
	.string "Basta parlare di me!\p"
	.string "{PLAYER}, continuerai a cercare\n"
	.string "POKéMON esotici, vero?\p"
	.string "Ti auguro buona fortuna!$"

OneIsland_PokemonCenter_1F_Text_CelioHearingRumorsAboutYou::
	.string "CELIO: Ciao!\p"
	.string "{PLAYER}, ho sentito voci\n"
	.string "sul tuo conto.$"

OneIsland_PokemonCenter_1F_Text_BillsFirstMonWasAbra::
	.string "{PLAYER}, qual è il tuo tipo\n"
	.string "di POKéMON preferito?\p"
	.string "BILL è un POKéMANIAC, quindi\n"
	.string "li ama tutti.\p"
	.string "Pare che il primo che ha preso\n"
	.string "fosse un ABRA.$"

OneIsland_PokemonCenter_1F_Text_BillsHometownInGoldenrod::
	.string "A proposito, {PLAYER}, sei di\n"
	.string "BIANCAVILLA, vero?\p"
	.string "Ho sentito che è un posto\n"
	.string "tranquillo e piacevole.\p"
	.string "BILL viene da FIORDOROPOLI,\n"
	.string "dove vivono ancora i suoi.\p"
	.string "Dicono che sia una città\n"
	.string "festosa e piena di vita.\p"
	.string "Mi piacerebbe andarci un giorno.$"

OneIsland_PokemonCenter_1F_Text_BillCantStomachMilk::
	.string "{PLAYER}, c'è qualcosa che\n"
	.string "non sopporti?\p"
	.string "A quanto pare, BILL non riesce\n"
	.string "proprio a mandar giù il latte.$"

OneIsland_PokemonCenter_1F_Text_CameFromPalletDontKnowIt::
	.string "Oh, sei uno straniero qui!\n"
	.string "Ciao! Di dove sei?\p"
	.string "…BIANCAVILLA?\n"
	.string "Non la conosco!$"

OneIsland_PokemonCenter_1F_Text_EnormousVolcanoOnIsland::
	.string "Su quest'isola c'è un enorme\n"
	.string "vulcano.\p"
	.string "Non erutta da tempo, quindi\n"
	.string "perché non farti una camminata?$"

OneIsland_PokemonCenter_1F_Text_WishICouldTradeWithBoyfriend::
	.string "Vorrei poter scambiare POKéMON con\n"
	.string "il mio ragazzo che vive lontano…$"

OneIsland_PokemonCenter_1F_Text_TradedWithFarAwayBoyfriend::
	.string "Ho scambiato POKéMON con il mio\n"
	.string "ragazzo lontano!\p"
	.string "Tutti dicono che possiamo\n"
	.string "ringraziare te e CELIO.\p"
	.string "Quindi, grazie!$"

OneIsland_PokemonCenter_1F_Text_MachineUnderAdjustment::
	.string "Macchina Rete\n"
	.string "Livello Link 0\p"
	.string "…Sistema di Memorizzazione POKéMON\n"
	.string "in regolazione…$"

OneIsland_PokemonCenter_1F_Text_MachineLinkedWithKanto::
	.string "Macchina Rete\n"
	.string "Livello Link 1\p"
	.string "Collegamento stabilito con la\n"
	.string "regione KANTO.$"

OneIsland_PokemonCenter_1F_Text_MachineLinkedWithKantoAndHoenn::
	.string "Macchina Rete\n"
	.string "Livello Link 2\p"
	.string "Collegamento stabilito con le\n"
	.string "regioni KANTO e HOENN.$"

OneIsland_PokemonCenter_1F_Text_ObtainedTriPass::
	.string "Hai ottenuto il TRI-PASS!$"

