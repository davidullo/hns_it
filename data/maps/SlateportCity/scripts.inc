SlateportCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_OnFrame
	.byte 0

SlateportCity_OnTransition:
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
	call SlateportCity_EventScript_EnterSlateport
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_MovePeopleForSternInterview
	call_if_eq VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_SetReadyForScottScene
	end

SlateportCity_EventScript_EnterSlateport::
	setflag FLAG_VISITED_SLATEPORT_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER
	return

SlateportCity_EventScript_MovePeopleForSternInterview::
	setobjectxyperm LOCALID_SLATEPORT_CAPT_STERN, 28, 13
	setobjectxyperm LOCALID_SLATEPORT_OLD_WOMAN, 25, 13
	setobjectxyperm LOCALID_SLATEPORT_RICH_BOY, 25, 14
	setobjectxyperm LOCALID_SLATEPORT_COOK, 27, 16
	setobjectxyperm LOCALID_SLATEPORT_GIRL, 28, 16
	setobjectxyperm LOCALID_SLATEPORT_FAT_MAN, 29, 16
	setobjectxyperm LOCALID_SLATEPORT_MAN_1, 31, 14
	setobjectmovementtype LOCALID_SLATEPORT_CAPT_STERN, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_SLATEPORT_OLD_WOMAN, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	setobjectmovementtype LOCALID_SLATEPORT_RICH_BOY, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
	setobjectmovementtype LOCALID_SLATEPORT_COOK, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_GIRL, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_FAT_MAN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_MAN_1, MOVEMENT_TYPE_FACE_LEFT
	return

SlateportCity_EventScript_SetReadyForScottScene::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 30, SlateportCity_EventScript_MoveScottLeft
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 23, 27
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_EventScript_MoveScottLeft::
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 22, 27
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_OnFrame:
	map_script_2 VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_ScottScene
	.2byte 0

SlateportCity_EventScript_ScottScene::
	lockall
	addobject LOCALID_SLATEPORT_SCOTT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceScott
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottApproachPlayer
	waitmovement 0
	msgbox SlateportCity_Text_YouDroveTeamAquaAway, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 60
	msgbox SlateportCity_Text_MaybeThisTrainer, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_Text_LetsRegisterEachOther, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SlateportCity_Text_RegisteredScott, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_SCOTT_MATCH_CALL
	msgbox SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_SLATEPORT_SCOTT
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 10, 12
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_DOWN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 2
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

SlateportCity_Movement_PlayerFaceScott:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ScottApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_Movement_ScottExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_EventScript_EnergyGuru::
	lock
	faceplayer
	message SlateportCity_Text_EnergyGuruSellWhatYouNeed
	waitmessage
	pokemart SlateportCity_Pokemart_EnergyGuru
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_EnergyGuru:
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_ZINC
	.2byte ITEM_CALCIUM
	.2byte ITEM_HP_UP
	pokemartlistend

SlateportCity_EventScript_EffortRibbonWoman::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox SlateportCity_Text_OhYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
	call_if_eq VAR_RESULT, TRUE, SlateportCity_EventScript_MonHasEffortRibbon
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
	call_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_MonEVsNotMaxed
	msgbox SlateportCity_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message SlateportCity_Text_ReceivedEffortRibbon
	waitfanfare
	msgbox SlateportCity_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
	special GiveLeadMonEffortRibbon
	release
	end

SlateportCity_EventScript_MonEVsNotMaxed::
	msgbox SlateportCity_Text_GoForItLittleHarder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_MonHasEffortRibbon::
	msgbox SlateportCity_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Cook::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_CookSternInterview
	msgbox SlateportCity_Text_SeaweedFullOfLife, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_CookSternInterview::
	msgbox SlateportCity_Text_CaptainComeBackWithBigFish, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWoman::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_OldWomanSternInterview
	msgbox SlateportCity_Text_HowTownIsBornAndGrows, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWomanSternInterview::
	msgbox SlateportCity_Text_CaptSternBeingInterviewed, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Girl::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_GirlSternInterview
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_GirlSecretBase
	msgbox SlateportCity_Text_SlateportWonderfulPlace, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSternInterview::
	msgbox SlateportCity_Text_InterviewerSoCool, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSecretBase::
	msgbox SlateportCity_Text_BuyBricksSoDecorWontGetDirty, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoy::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_RichBoySternInterview
	msgbox SlateportCity_Text_GoingToCompeteInBattleTent, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoySternInterview::
	msgbox SlateportCity_Text_SternSaysDiscoveredSomething, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_FatMan::
	goto_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_FatManSternInterview
	msgbox SlateportCity_Text_BushedHikingFromMauville, MSGBOX_NPC
	end

SlateportCity_EventScript_FatManSternInterview::
	msgbox SlateportCity_Text_AmIOnTV, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man1::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_Man1SternInterview
	msgbox SlateportCity_Text_EveryoneCallsHimCaptStern, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Man1SternInterview::
	msgbox SlateportCity_Text_CaptainsACelebrity, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1::
	lock
	faceplayer
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_EventScript_Woman1AquaGone
	msgbox SlateportCity_Text_WhatsLongLineOverThere, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1AquaGone::
	msgbox SlateportCity_Text_VisitedMuseumOften, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_BattleTentSign::
	msgbox SlateportCity_Text_BattleTentSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_SternsShipyardSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_SternsShipyardFerryComplete
	goto_if_set FLAG_BADGE07_GET, SlateportCity_EventScript_SternsShipyardNearsCompletion
	msgbox SlateportCity_Text_SternsShipyardWantedSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardNearsCompletion::
	msgbox SlateportCity_Text_SternsShipyardNearsCompletion, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardFerryComplete::
	msgbox SlateportCity_Text_SternsShipyardFerryComplete, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_PokemonFanClubSign::
	msgbox SlateportCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_OceanicMuseumSign::
	msgbox SlateportCity_Text_OceanicMuseumSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_CitySign::
	msgbox SlateportCity_Text_CitySign, MSGBOX_SIGN
	end

SlateportCity_EventScript_MarketSign::
	msgbox SlateportCity_Text_MarketSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_HarborSignFerryComplete
	msgbox SlateportCity_Text_HarborFerryUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_HarborSignFerryComplete::
	msgbox SlateportCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_NameRatersHouseSign::
	msgbox SlateportCity_Text_NameRatersHouseSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_Maniac::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_ManiacSternInterview
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

@ Unclear if the text here was meant to be different, but its not
SlateportCity_EventScript_ManiacSternInterview::
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman2::
	msgbox SlateportCity_Text_CantChangeTradeMonName, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor1::
	msgbox SlateportCity_Text_SeaIsSoWet, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor2::
	msgbox SlateportCity_Text_SinkOldBoats, MSGBOX_NPC
	end

SlateportCity_EventScript_PokefanF::
	msgbox SlateportCity_Text_BuyTooMuch, MSGBOX_NPC
	end

SlateportCity_EventScript_Man2::
	msgbox SlateportCity_Text_BattleTentBuiltRecently, MSGBOX_NPC
	end

SlateportCity_EventScript_AquaGrunt1::
	lock
	faceplayer
	msgbox SlateportCity_Text_QuitPushing, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt2::
	lock
	faceplayer
	msgbox SlateportCity_Text_AquaHasPolicy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt3::
	lock
	faceplayer
	msgbox SlateportCity_Text_BossIsBrilliant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt4::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhatsNewSchemeIWonder, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt5::
	lock
	faceplayer
	msgbox SlateportCity_Text_ShouldTakeItAll, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_5, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt6::
	lock
	faceplayer
	msgbox SlateportCity_Text_DontButtIn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_6, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt7::
	lock
	faceplayer
	msgbox SlateportCity_Text_RemindsMeOfLongLineForGames, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_7, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt8::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhyAreWeLiningUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_8, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt9::
	lock
	faceplayer
	playse SE_PIN
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_Text_WhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_Text_IllReadSignForYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	msgbox SlateportCity_Text_SaysSomethingLikeSeaIsEndless, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Movement_DelayAquaGrunt:
	delay_16
	delay_16
	step_end

SlateportCity_EventScript_AquaGrunt10::
	msgbox SlateportCity_Text_ShouldveBroughtMyGameBoy, MSGBOX_SIGN
	end

SlateportCity_EventScript_AquaGrunt11::
	lock
	faceplayer
	msgbox SlateportCity_Text_HotSpringsAfterOperation, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_11, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_DollClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor_Dolls
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor_Dolls:
	.2byte DECOR_AZURILL_DOLL
	.2byte DECOR_MARILL_DOLL
	.2byte DECOR_SKITTY_DOLL
	pokemartlistend

SlateportCity_EventScript_ComeBackWithSecretPower::
	msgbox gText_ComeBackWithSecretPower, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_DecorClerk::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_ComeBackWithSecretPower
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor:
	.2byte DECOR_RED_BRICK
	.2byte DECOR_BLUE_BRICK
	.2byte DECOR_YELLOW_BRICK
	.2byte DECOR_RED_BALLOON
	.2byte DECOR_BLUE_BALLOON
	.2byte DECOR_YELLOW_BALLOON
	.2byte DECOR_C_LOW_NOTE_MAT
	.2byte DECOR_D_NOTE_MAT
	.2byte DECOR_E_NOTE_MAT
	.2byte DECOR_F_NOTE_MAT
	.2byte DECOR_G_NOTE_MAT
	.2byte DECOR_A_NOTE_MAT
	.2byte DECOR_B_NOTE_MAT
	.2byte DECOR_C_HIGH_NOTE_MAT
	pokemartlistend

SlateportCity_EventScript_PowerTMClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Pokemart_PowerTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_PowerTMs:
	.2byte ITEM_TM_HIDDEN_POWER
	.2byte ITEM_TM_SECRET_POWER
	pokemartlistend

@ Scene with Capt Sterns interview and Team Aqua announcing plans to steal Submarine
SlateportCity_EventScript_CaptStern::
	lockall
	msgbox SlateportCity_Text_SternMoveAheadWithExploration, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_GabbyWonderfulThanksForInterview, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GABBY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 10
	applymovement LOCALID_SLATEPORT_TY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 25
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternWatchGabbyAndTyExit
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceStern
	applymovement LOCALID_SLATEPORT_GABBY, SlateportCity_Movement_GabbyExit
	applymovement LOCALID_SLATEPORT_TY, SlateportCity_Movement_TyExit
	waitmovement 0
	removeobject LOCALID_SLATEPORT_GABBY
	removeobject LOCALID_SLATEPORT_TY
	msgbox SlateportCity_Text_SternWhewFirstInterview, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_OhPlayerWeMadeDiscovery, MSGBOX_DEFAULT
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SlateportCity_Text_AquaWillAssumeControlOfSubmarine, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_COOK, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SLATEPORT_FAT_MAN, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SLATEPORT_OLD_WOMAN, SlateportCity_Movement_OldWomanConcern
	applymovement LOCALID_SLATEPORT_RICH_BOY, Common_Movement_QuestionMark
	applymovement LOCALID_SLATEPORT_MAN_1, SlateportCity_Movement_ManConcern
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SlateportCity_Text_SternWhatWasAllThat, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_FromHarborTryingToTakeSub, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternEnterHarbor
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerEnterHarbor
	waitmovement 0
	removeobject LOCALID_SLATEPORT_CAPT_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
	setvar VAR_SLATEPORT_CITY_STATE, 2
	warp MAP_SLATEPORT_CITY_HARBOR, 11, 14
	waitstate
	releaseall
	end

SlateportCity_Movement_OldWomanConcern:
	delay_16
	delay_16
	emote_question_mark
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ManConcern:
	emote_question_mark
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_GabbyExit:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_TyExit:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_Unused:
	walk_down
	walk_in_place_faster_up
	step_end

SlateportCity_Movement_SternEnterHarbor:
	walk_right
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_Movement_SternWatchGabbyAndTyExit:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_left
	step_end

SlateportCity_Movement_PlayerEnterHarbor:
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_right
	walk_up
	step_end

SlateportCity_Movement_PlayerFaceStern:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_EventScript_Ty::
	msgbox SlateportCity_Text_BigSmileForCamera, MSGBOX_SIGN
	end

SlateportCity_EventScript_Gabby::
	msgbox SlateportCity_Text_MostInvaluableExperience, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man3::
	msgbox SlateportCity_Text_WonderIfLighthouseStartlesPokemon, MSGBOX_NPC
	end

SlateportCity_EventScript_BerryPowderClerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POWDER_JAR, SlateportCity_EventScript_ReceivedPowderJar
	msgbox SlateportCity_Text_ExplainBerries, MSGBOX_DEFAULT
	giveitem ITEM_POWDER_JAR
	setflag FLAG_RECEIVED_POWDER_JAR
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ReceivedPowderJar::
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_ExplainBerryPowder
	msgbox SlateportCity_Text_BroughtMeSomeBerryPowder, MSGBOX_DEFAULT
	special DisplayBerryPowderVendorMenu
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ExplainBerryPowder::
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ChooseBerryPowderItem::
	message SlateportCity_Text_ExchangeWhatWithIt
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, SlateportCity_EventScript_EnergyPowder
	case 1, SlateportCity_EventScript_EnergyRoot
	case 2, SlateportCity_EventScript_HealPowder
	case 3, SlateportCity_EventScript_RevivalHerb
	case 4, SlateportCity_EventScript_Protein
	case 5, SlateportCity_EventScript_Iron
	case 6, SlateportCity_EventScript_Carbos
	case 7, SlateportCity_EventScript_Calcium
	case 8, SlateportCity_EventScript_Zinc
	case 9, SlateportCity_EventScript_HPUp
	case 10, SlateportCity_EventScript_PPUp
	case 11, SlateportCity_EventScript_CancelPowderItemSelect
	case MULTI_B_PRESSED, SlateportCity_EventScript_CancelPowderItemSelect
	end

SlateportCity_EventScript_EnergyPowder::
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_EnergyRoot::
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
	setvar VAR_0x8009, 80
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HealPowder::
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
	setvar VAR_0x8008, ITEM_HEAL_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_RevivalHerb::
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
	setvar VAR_0x8009, 300
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Protein::
	bufferitemname STR_VAR_1, ITEM_PROTEIN
	setvar VAR_0x8008, ITEM_PROTEIN
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Iron::
	bufferitemname STR_VAR_1, ITEM_IRON
	setvar VAR_0x8008, ITEM_IRON
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Carbos::
	bufferitemname STR_VAR_1, ITEM_CARBOS
	setvar VAR_0x8008, ITEM_CARBOS
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Calcium::
	bufferitemname STR_VAR_1, ITEM_CALCIUM
	setvar VAR_0x8008, ITEM_CALCIUM
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Zinc::
	bufferitemname STR_VAR_1, ITEM_ZINC
	setvar VAR_0x8008, ITEM_ZINC
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HPUp::
	bufferitemname STR_VAR_1, ITEM_HP_UP
	setvar VAR_0x8008, ITEM_HP_UP
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_PPUp::
	bufferitemname STR_VAR_1, ITEM_PP_UP
	setvar VAR_0x8008, ITEM_PP_UP
	setvar VAR_0x8009, 3000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_CancelPowderItemSelect::
	msgbox SlateportCity_Text_ComeBackToTradeBerryPowder, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_TryBuyBerryPowderItem::
	msgbox SlateportCity_Text_ExchangeBerryPowderForItem, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_ChooseBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NotEnoughBerryPowder
	giveitem VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NoRoomForBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	special TakeBerryPowder
	special PrintPlayerBerryPowderAmount
	msgbox SlateportCity_Text_FineBerryPowderTradeSomethingElse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_EventScript_ChooseBerryPowderItem
	msgbox SlateportCity_Text_WhenYouGetMoreBringItToMe, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NoRoomForBerryPowderItem::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NotEnoughBerryPowder::
	msgbox SlateportCity_Text_DontHaveEnoughBerryPowder, MSGBOX_DEFAULT
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ScottBattleTentScene::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	opendoor 10, 12
	waitdooranim
	addobject LOCALID_SLATEPORT_SCOTT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PushPlayerDown
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitBattleTent
	waitmovement 0
	closedoor 10, 12
	waitdooranim
	msgbox SlateportCity_Text_TakingBattleTentChallenge, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitAfterBattleTent
	waitmovement 0
	removeobject LOCALID_SLATEPORT_SCOTT
	addvar VAR_SCOTT_STATE, 1
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	releaseall
	end

SlateportCity_Movement_PushPlayerDown:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

SlateportCity_Movement_PlayerWatchScottExit:
	delay_16
	walk_in_place_faster_right
	step_end

SlateportCity_Movement_ScottExitBattleTent:
	delay_8
	walk_down
	step_end

SlateportCity_Movement_ScottExitAfterBattleTent:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_EventScript_BerryCrushRankingsSign::
	lockall
	special ShowBerryCrushRankings
	waitstate
	releaseall
	end

SlateportCity_Text_EnergyGuruSellWhatYouNeed:
	.string "Sono il GURU DELL'ENERGIA! Ci penso io a\n"
	.string "venderti ciò che ti serve!$"

SlateportCity_Text_OhYourPokemon:
	.string "Oh?\n"
	.string "Il tuo {STR_VAR_1}…$"

SlateportCity_Text_PleaseGiveItThisEffortRibbon:
	.string "Ci ha dato dentro alla grande!\p"
	.string "Come ricompensa, dagli questo\n"
	.string "NASTRO IMPEGNO.$"

SlateportCity_Text_ReceivedEffortRibbon:
	.string "{PLAYER} riceve il NASTRO IMPEGNO.$"

SlateportCity_Text_PutEffortRibbonOnMon:
	.string "{PLAYER} mette il NASTRO IMPEGNO\n"
	.string "su {STR_VAR_1}.$"

SlateportCity_Text_GoForItLittleHarder:
	.string "Devi impegnarti un po' di più.\p"
	.string "Se lo farai, darò ai tuoi POKéMON\n"
	.string "qualcosa di bello.$"

SlateportCity_Text_EffortRibbonLooksGoodOnIt:
	.string "Oh! Al tuo {STR_VAR_1} sta proprio\n"
	.string "bene il NASTRO IMPEGNO!$"

SlateportCity_Text_WonderIfLighthouseStartlesPokemon:
	.string "La luce del faro arriva\n"
	.string "a chilometri di distanza.\p"
	.string "Chissà se non spaventa i POKéMON\n"
	.string "in mare.$"

SlateportCity_Text_SeaweedFullOfLife:
	.string "Ooh, guarda qua!\p"
	.string "Le alghe di questi fondali sono\n"
	.string "fresche e piene di vita.\p"
	.string "Anzi, sembra persino che possano\n"
	.string "drizzarsi e attaccare!$"

SlateportCity_Text_HowTownIsBornAndGrows:
	.string "Dove l'acqua è pulita, si raccolgono\n"
	.string "i frutti del raccolto.\p"
	.string "E dove si raduna la gente,\n"
	.string "nasce un mercato.\p"
	.string "Così nasce e cresce una città.$"

SlateportCity_Text_SlateportWonderfulPlace:
	.string "Fare shopping respirando il\n"
	.string "profumo del mare…\p"
	.string "SLATEPORT è un posto meraviglioso!$"

SlateportCity_Text_BuyBricksSoDecorWontGetDirty:
	.string "Se metti PELUCHE o CUSCINI sul\n"
	.string "pavimento, si sporcano.\p"
	.string "Comprerò dei MATTONI così PELUCHE\n"
	.string "e CUSCINI non si sporcano\l"
	.string "quando li lascio in giro.$"

SlateportCity_Text_GoingToCompeteInBattleTent:
	.string "Wroooar! Parteciperò anch'io alla\n"
	.string "TENDA LOTTA!\p"
	.string "Ma prima devo catturare\n"
	.string "dei POKéMON!$"

SlateportCity_Text_BushedHikingFromMauville:
	.string "Fiu… sono distrutto…\p"
	.string "Sono venuto a piedi da MAUVILLE.\n"
	.string "Cavoli, che città enorme.\p"
	.string "Se l'avessi saputo, sarei venuto\n"
	.string "in BICICLETTA.$"

SlateportCity_Text_EveryoneCallsHimCaptStern:
	.string "STERN, che ha costruito il MUSEO,\n"
	.string "è anche il capo di una squadra di\l"
	.string "esplorazione subacquea.\p"
	.string "Perciò tutti lo chiamano CAPITANO STERN.$"

SlateportCity_Text_WhatsLongLineOverThere:
	.string "Cos'è quello là?\n"
	.string "Quella fila lunga…$"

SlateportCity_Text_VisitedMuseumOften:
	.string "Da bambino visitavo\n"
	.string "spesso il MUSEO.\p"
	.string "Sognavo i misteri del mare dopo\n"
	.string "aver visto le mostre.$"

SlateportCity_Text_QuitPushing:
	.string "Ehi, tu! Smettila di spingere!\n"
	.string "Non vedi che c'è la fila?$"

SlateportCity_Text_AquaHasPolicy:
	.string "Il TEAM AQUA si raduna e si\n"
	.string "disperde sul luogo\l"
	.string "dell'operazione.$"

SlateportCity_Text_BossIsBrilliant:
	.string "Il nostro CAPO è geniale.\p"
	.string "Cosa vorrà fare adesso\n"
	.string "con un MUSEO?$"

SlateportCity_Text_WhatsNewSchemeIWonder:
	.string "Chissà qual è il nuovo piano?\p"
	.string "Il nostro CAPO è spaventoso quando\n"
	.string "si arrabbia, meglio non sbagliare…$"

SlateportCity_Text_ShouldTakeItAll:
	.string "Se c'è qualcosa che ci serve nel\n"
	.string "MUSEO, dovremmo prendercela tutta!$"

SlateportCity_Text_DontButtIn:
	.string "Ehi, tu!\n"
	.string "Non intrometterti!$"

SlateportCity_Text_RemindsMeOfLongLineForGames:
	.string "Che fila lunga, eh?\p"
	.string "Mi ricorda quando facevo la coda per\n"
	.string "comprare i giochi più attesi…$"

SlateportCity_Text_WhyAreWeLiningUp:
	.string "Perché fare la fila e pagare?\n"
	.string "Dovremmo entrare e basta!$"

SlateportCity_Text_WhatDoYouWant:
	.string "Cosa?\n"
	.string "Cosa vuoi?$"

SlateportCity_Text_IllReadSignForYou:
	.string "Vuoi leggere questo cartello?\n"
	.string "Te lo leggo io!$"

SlateportCity_Text_SaysSomethingLikeSeaIsEndless:
	.string "Vediamo…\p"
	.string "Ehm… mi pare dica qualcosa tipo\n"
	.string "“la vita nel mare è infinita.”\p"
	.string "Sì, sono quasi certo che\n"
	.string "dica così.$"

SlateportCity_Text_ShouldveBroughtMyGameBoy:
	.string "Grr…\p"
	.string "Dovevo portarmi il Game Boy\n"
	.string "Advance per non annoiarmi in fila…\p"
	.string "Grr…$"

SlateportCity_Text_HotSpringsAfterOperation:
	.string "Finito il lavoro, ti porto\n"
	.string "in un centro termale!\p"
	.string "Parola del nostro capo.\n"
	.string "Non vedo l'ora!$"

SlateportCity_Text_SeaIsSoWet:
	.string "Il mare è così immenso…\p"
	.string "E se il mare fosse nato dalle\n"
	.string "lacrime versate dai POKéMON?$"

SlateportCity_Text_SinkOldBoats:
	.string "Sai cosa fanno alle vecchie navi\n"
	.string "troppo malandate per navigare?\p"
	.string "Le affondano in mare, così diventano\n"
	.string "habitat per i POKéMON.$"

SlateportCity_Text_BuyTooMuch:
	.string "Ogni volta che vengo qui, mi lascio\n"
	.string "trasportare e compro troppo.$"

SlateportCity_Text_GetNameRaterToHelpYou:
	.string "Per cambiare il soprannome dei tuoi\n"
	.string "POKéMON, devi chiedere aiuto al\l"
	.string "GIUDICE ONOMASTICO.$"

SlateportCity_Text_CantChangeTradeMonName:
	.string "I POKéMON ricevuti in uno scambio\n"
	.string "non possono cambiare soprannome.\p"
	.string "L'amore dell'ALLENATORE originale\n"
	.string "per quel POKéMON è nel soprannome.$"

SlateportCity_Text_BattleTentBuiltRecently:
	.string "Di recente è stata costruita una\n"
	.string "TENDA LOTTA a SLATEPORT.\p"
	.string "Le PALESTRE sono belle, ma la\n"
	.string "TENDA LOTTA ha il suo fascino.\p"
	.string "Cerca POKéMON forti per la\n"
	.string "TENDA LOTTA!$"

SlateportCity_Text_CaptSternBeingInterviewed:
	.string "Speravo fosse una star famosa\n"
	.string "per farmi dare un Autografo.\p"
	.string "Ma chi stanno intervistando?\n"
	.string "Non è il CAPITANO STERN?$"

SlateportCity_Text_InterviewerSoCool:
	.string "Quella signora intervistatrice è così\n"
	.string "cool e carina.\p"
	.string "Da grande voglio fare\n"
	.string "la giornalista internazionale!$"

SlateportCity_Text_SternSaysDiscoveredSomething:
	.string "Il CAP. STERN dice che hanno trovato\n"
	.string "qualcosa sul fondo del mare.\p"
	.string "Chissà cos'è?\n"
	.string "Cosa sarà mai?$"

SlateportCity_Text_CaptainComeBackWithBigFish:
	.string "Cosa succede qui?\p"
	.string "Il buon CAPITANO è tornato con\n"
	.string "un Pesce grosso dal fondo del mare?$"

SlateportCity_Text_AmIOnTV:
	.string "Ehi! La stai guardando?\n"
	.string "Sono in TV?$"

SlateportCity_Text_CaptainsACelebrity:
	.string "Un'intervista in TV! Qui!\n"
	.string "Il CAPITANO è una celebrità!$"

SlateportCity_Text_BigSmileForCamera:
	.string "TY: Ok, CAPITANO STERN, un bel\n"
	.string "sorriso alla telecamera!$"

SlateportCity_Text_MostInvaluableExperience:
	.string "GABBY: Capisco, capisco. Hai fatto\n"
	.string "un'esperienza davvero preziosa…$"

SlateportCity_Text_SternMoveAheadWithExploration:
	.string "CAP. STERN: Proprio così. Intendiamo\n"
	.string "proseguire con le esplorazioni.$"

SlateportCity_Text_GabbyWonderfulThanksForInterview:
	.string "GABBY: Fantastico, CAPITANO STERN!\n"
	.string "Grazie per averci dedicato del tempo\l"
	.string "nonostante i tuoi impegni.\p"
	.string "Speriamo di intervistarla ancora\n"
	.string "con altre scoperte!$"

SlateportCity_Text_SternWhewFirstInterview:
	.string "CAP. STERN: Fiuu…\p"
	.string "Era la prima volta che mi riprendevano\n"
	.string "in TV. Che tensione.$"

SlateportCity_Text_OhPlayerWeMadeDiscovery:
	.string "Oh! {PLAYER}{KUN}!\n"
	.string "Stai benissimo!\p"
	.string "Nell'ultima esplorazione dei fondali\n"
	.string "abbiamo fatto una grande scoperta.\p"
	.string "Abbiamo trovato una caverna\n"
	.string "sul PERCORSO 128.\p"
	.string "Pensiamo sia l'habitat di un POKéMON\n"
	.string "estinto da molto tempo.$"

SlateportCity_Text_AquaWillAssumeControlOfSubmarine:
	.string "Fufufu…\n"
	.string "CAPITANO STERN, suppongo.\p"
	.string "Noi del TEAM AQUA prenderemo\n"
	.string "il controllo del tuo sottomarino!\p"
	.string "Le tue obiezioni sono inutili!\n"
	.string "Ci aspettiamo totale collaborazione!\p"
	.string "Fufufu…\n"
	.string "Osserva e impara cosa ha in mente\l"
	.string "il TEAM AQUA!$"

SlateportCity_Text_SternWhatWasAllThat:
	.string "CAP. STERN: Cos'è stato?\p"
	.string "Sembrava qualcuno che usava\n"
	.string "un megafono…\p"
	.string "Da dove veniva?$"

SlateportCity_Text_FromHarborTryingToTakeSub:
	.string "Viene dal PORTO!\p"
	.string "Il sottomarino!\n"
	.string "Lo vogliono portare via!$"

SlateportCity_Text_PleaseComeWithMe:
	.string "{PLAYER}{KUN}!\n"
	.string "Vieni con me, ti prego!$"

SlateportCity_Text_BattleTentSign:
	.string "TENDA LOTTA DI SLATEPORT\n"
	.string "“Trovalo! Il POKéMON supremo!”$"

SlateportCity_Text_SternsShipyardWantedSign:
	.string "CANTIERE DI STERN\p"
	.string "“Cercasi marinaio capace di navigare\n"
	.string "in ogni corrente.”$"

SlateportCity_Text_SternsShipyardNearsCompletion:
	.string "CANTIERE DI STERN\p"
	.string "“Il traghetto S.S. TIDAL è quasi\n"
	.string "pronto a servire i porti di\l"
	.string "SLATEPORT e PORTOALGHE.”$"

SlateportCity_Text_SternsShipyardFerryComplete:
	.string "CANTIERE DI STERN\p"
	.string "“L'imbarco sul traghetto SLATEPORT-\n"
	.string "PORTOALGHE S.S. TIDAL avviene\l"
	.string "al PORTO.”$"

SlateportCity_Text_PokemonFanClubSign:
	.string "FAN CLUB POKéMON\n"
	.string "“Chiamata a tutti i fan dei POKéMON!”$"

SlateportCity_Text_OceanicMuseumSign:
	.string "“Il mare infinito sostenta\n"
	.string "ogni vita.”\p"
	.string "MUSEO OCEANICO$"

SlateportCity_Text_CitySign:
	.string "SLATEPORT\p"
	.string "“Il porto dove persone e POKéMON\n"
	.string "si incontrano.”$"

SlateportCity_Text_MarketSign:
	.string "MERCATO DI SLATEPORT\n"
	.string "“Oggetti unici, introvabili altrove!”$"

SlateportCity_Text_HarborFerryUnderConstruction:
	.string "PORTO DI SLATEPORT\p"
	.string "“Il traghetto S.S. TIDAL è in\n"
	.string "costruzione nel CANTIERE NAVALE.\p"
	.string "“Il servizio inizierà\n"
	.string "a breve.”$"

SlateportCity_Text_HarborSign:
	.string "PORTO DI SLATEPORT\p"
	.string "“Goditi una piacevole crociera sul\n"
	.string "traghetto S.S. TIDAL.”$"

SlateportCity_Text_NameRatersHouseSign:
	.string "CASA DEL GIUDICE DEI NOMI\n"
	.string "“Soprannomi POKéMON valutati.”$"

SlateportCity_Text_ExplainBerries:
	.string "Se un POKéMON selvatico si fa male,\n"
	.string "si cura masticando BACCHE.\p"
	.string "Lo sapevi?\p"
	.string "Qualcuno l'ha visto e ha pensato\n"
	.string "di fare medicine dalle BACCHE.\p"
	.string "Lo sapevi?\p"
	.string "Per diventare medicina, le BACCHE\n"
	.string "vanno ridotte in polvere.\p"
	.string "Lo sapevi?\p"
	.string "Sembri interessato\n"
	.string "alle BACCHE!\p"
	.string "Ho qualcosa di buono per uno\n"
	.string "come te.$"

SlateportCity_Text_ExplainBerryPowder:
	.string "Ho fatto installare delle macchine\n"
	.string "nei CENTRI POKéMON per tritare le BACCHE.\p"
	.string "Le macchine Trito Bacche sono al\n"
	.string "DIRECT CORNER di sopra.\p"
	.string "Lo sapevi?\p"
	.string "Potresti farmi del PULVISCOPPIO\n"
	.string "usando quelle macchine?\p"
	.string "Ti preparo medicine di ogni tipo\n"
	.string "se mi porti molto PULVISCOPPIO.$"

SlateportCity_Text_BroughtMeSomeBerryPowder:
	.string "Mi hai portato un po' di\n"
	.string "PULVISCOPPIO?$"

SlateportCity_Text_ExchangeWhatWithIt:
	.string "Con cosa vuoi\n"
	.string "scambiarlo?$"

SlateportCity_Text_ExchangeBerryPowderForItem:
	.string "Ok, vuoi scambiare il tuo\n"
	.string "PULVISCOPPIO con {STR_VAR_1}?$"

SlateportCity_Text_DontHaveEnoughBerryPowder:
	.string "Oh, cielo. Non hai abbastanza\n"
	.string "PULVISCOPPIO.$"

SlateportCity_Text_FineBerryPowderTradeSomethingElse:
	.string "Questo è PULVISCOPPIO pregiato.\n"
	.string "Farà ottime medicine.\p"
	.string "Vuoi scambiare altro PULVISCOPPIO\n"
	.string "con qualcos'altro?$"

SlateportCity_Text_WhenYouGetMoreBringItToMe:
	.string "Certo! Quando trovi altra\n"
	.string "POLVERE D'OSSO, portamela, per favore!$"

SlateportCity_Text_ComeBackToTradeBerryPowder:
	.string "Torna se vuoi scambiare il tuo\n"
	.string "PULVISCOPPIO con delle medicine.\p"
	.string "Qui tengo sempre un bazar.\p"
	.string "Lo sapevi?$"

SlateportCity_Text_YouDroveTeamAquaAway:
	.string "SCOTT: Eh?\n"
	.string "Mi pare di averti già visto.\p"
	.string "Ti ho presentato me stesso?\n"
	.string "Se no, mi chiamo SCOTT.\p"
	.string "Ho appena visto il TEAM AQUA\n"
	.string "scappare di qui come punti.\p"
	.string "Fammi indovinare, li hai cacciati tu?$"

SlateportCity_Text_MaybeThisTrainer:
	.string "SCOTT: Hmm…\n"
	.string "Forse, e dico forse, questo ALLENATORE…$"

SlateportCity_Text_LetsRegisterEachOther:
	.string "SCOTT: Bene! Penso che diventeremo\n"
	.string "buoni amici.\p"
	.string "Registriamoci a vicenda nei\n"
	.string "POKéNAV.\p"
	.string "… … … … … …$"

SlateportCity_Text_RegisteredScott:
	.string "Registrato questo SCOTT\n"
	.string "nel POKéNAV.$"

SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou:
	.string "SCOTT: Vorrei venire\n"
	.string "con te, ma voglio tenere d'occhio\l"
	.string "anche il talento degli altri.\p"
	.string "Quindi me ne vado in giro per\n"
	.string "altre città.\p"
	.string "Ci vediamo, {PLAYER}{KUN}!$"

SlateportCity_Text_TakingBattleTentChallenge:
	.string "SCOTT: Oh, ehi!\n"
	.string "Ma sei {PLAYER}{KUN}!\p"
	.string "{PLAYER}{KUN}, fammi indovinare: vai\n"
	.string "alla TENDa LOTTA?\p"
	.string "Sì! Ottima idea!\n"
	.string "Un'idea davvero geniale!\p"
	.string "Del resto, un ALLENATORE forte è\n"
	.string "perfetto per la TENDa LOTTA!\p"
	.string "Dacci dentro!$"
