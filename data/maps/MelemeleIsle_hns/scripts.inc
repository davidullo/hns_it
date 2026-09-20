MelemeleIsle_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setrespawn HEAL_LOCATION_MELEMELE_ISLE_HNS
	gettimeofday
	compare VAR_0x8000, TIME_MORNING
	goto_if_eq MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	compare VAR_0x8000, TIME_DAY
	goto_if_eq MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	compare VAR_0x8000, TIME_EVENING
	goto_if_eq MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( RATICATE_ALOLA )
	clearflag FLAG_MELEMELE_TOTEM_DAY
	call MelemeleIsle_hns_SetTotemSignWarpFacing
	return

MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( LEAFEON )
	setflag FLAG_MELEMELE_TOTEM_DAY
	call MelemeleIsle_hns_SetTotemSignWarpFacing
	return

MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	map_script_2 VAR_TEMP_C, 0, MelemeleIsle_hns_EventScript_FacePlayerUpAfterTotemWarp
	map_script_2 VAR_ALOLA_TRAVEL, 1, MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

MelemeleIsle_hns_SetTotemSignWarpFacing:
	setvar VAR_TEMP_C, 1
	getplayerxy VAR_TEMP_A, VAR_TEMP_B
	compare VAR_TEMP_A, 34
	goto_if_ne MelemeleIsle_hns_SetTotemSignWarpFacing_End
	compare VAR_TEMP_B, 26
	goto_if_eq MelemeleIsle_hns_SetTotemSignWarpFacing_Set
	compare VAR_TEMP_B, 27
	goto_if_eq MelemeleIsle_hns_SetTotemSignWarpFacing_Set
	goto MelemeleIsle_hns_SetTotemSignWarpFacing_End

MelemeleIsle_hns_SetTotemSignWarpFacing_Set:
	setvar VAR_TEMP_C, 0

MelemeleIsle_hns_SetTotemSignWarpFacing_End:
	return

MelemeleIsle_hns_EventScript_FacePlayerUpAfterTotemWarp::
	setvar VAR_TEMP_C, 1
	applymovement LOCALID_PLAYER, MelemeleIsle_hns_Movement_FacePlayerUpAfterTotemWarp
	return

MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
	applymovement Alola_Melemele_Captain, MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0
	applymovement LOCALID_PLAYER, MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0
	return

MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_ALOLA_TRAVEL, 1, Alola_Melemele_GetOffBoat
	.2byte 0


Alola_Melemele_GetOffBoat::
	lock
	delay 30
	applymovement Alola_Melemele_Captain, Alola_Melemele_GetOffBoat_Movement_0
	applymovement LOCALID_PLAYER, Alola_Melemele_GetOffBoat_Movement_1
	waitmovement 0
	msgbox Alola_Melemele_GetOffBoat_Text_0, MSGBOX_AUTOCLOSE
	setvar VAR_ALOLA_TRAVEL, 2
	applymovement LOCALID_PLAYER, MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0
	waitmovement 0
	release
	end


Alola_Melemele_TravelToKanto::
	lock
	faceplayer
	msgbox Alola_Melemele_TravelToKanto_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Alola_Melemele_TravelToKanto_1
	msgbox Alola_Melemele_TravelToKanto_Text_2, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_TravelToKanto_1:
	msgbox Alola_Melemele_TravelToKanto_Text_1, MSGBOX_AUTOCLOSE
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 32
	goto_if_eq Alola_Melemele_TravelToKanto_5
	compare VAR_TEMP_0, 23
	goto_if_eq Alola_Melemele_TravelToKanto_8
Alola_Melemele_TravelToKanto_7:
Alola_Melemele_TravelToKanto_4:
	applymovement Alola_Melemele_Captain, Alola_Melemele_TravelToKanto_Movement_2
	applymovement LOCALID_PLAYER, Alola_Melemele_TravelToKanto_Movement_2
	waitmovement 0
	fadescreenswapbuffers FADE_TO_BLACK
	hidefollower
	playse SE_EXIT
	special SpawnCameraObject
	hideobjectat LOCALID_PLAYER, MAP_MELEMELE_ISLE_HNS
	hideobjectat Alola_Melemele_Captain, MAP_MELEMELE_ISLE_HNS
	applymovement OBJ_EVENT_ID_CAMERA, Alola_Melemele_TravelToKanto_Movement_3
	waitmovement 0
	waitse
	delay 30
	fadescreenswapbuffers FADE_FROM_BLACK
	playse SE_RG_SS_ANNE_HORN
	waitse
	playse SE_M_SURF
	applymovement Alola_Melemele_Ship, Alola_Melemele_TravelToKanto_Movement_4
	delay 90
	fadescreenswapbuffers FADE_TO_BLACK
	special RemoveCameraObject
	warp MAP_ROUTE13_HNS, 77, 26
	waitstate
	end

Alola_Melemele_TravelToKanto_5:
	applymovement LOCALID_PLAYER, Alola_Melemele_TravelToKanto_Movement_0
	waitmovement 0
	goto Alola_Melemele_TravelToKanto_4

Alola_Melemele_TravelToKanto_6:
	applymovement LOCALID_PLAYER, Alola_Melemele_TravelToKanto_Movement_1
	waitmovement 0
	goto Alola_Melemele_TravelToKanto_4

Alola_Melemele_TravelToKanto_8:
	compare VAR_TEMP_1, 33
	goto_if_eq Alola_Melemele_TravelToKanto_6
	goto Alola_Melemele_TravelToKanto_7


Alola_Melemele_Mailbox::
	lock
	msgbox Alola_Melemele_Mailbox_Text_0
	release
	end


Alola_Melemele_Melemele_Sign::
	lock
	msgbox Alola_Melemele_Melemele_Sign_Text_0
	release
	end


Alola_Melemele_Pokecenter_Sign::
	lock
	msgbox Alola_Melemele_Pokecenter_Sign_Text_0
	release
	end


Alola_Melemele_MelemeleMart_Sign::
	lock
	msgbox Alola_Melemele_MelemeleMart_Sign_Text_0
	release
	end


Alola_Melemele_FindItem1::
	finditem ITEM_RARE_CANDY, 1
	end


Alola_Melemele_SamsonOak_Trigger_Beginning::
	lock
	addobject SamsonOakMelemeleIntro
	msgbox Alola_Melemele_SamsonOak_Trigger_Beginning_Text_0
	playse SE_PIN
	applymovement LOCALID_PLAYER, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_0
	waitmovement 0
	applymovement SamsonOakMelemeleIntro, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_1
	waitmovement 0
	msgbox Alola_Melemele_SamsonOak_Trigger_Beginning_Text_1, MSGBOX_AUTOCLOSE
	applymovement SamsonOakMelemeleIntro, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_2
	waitmovement 0
	msgbox Alola_Melemele_SamsonOak_Trigger_Beginning_Text_2, MSGBOX_AUTOCLOSE
	applymovement LOCALID_PLAYER, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_3
	waitmovement 0
	delay 15
	msgbox Alola_Melemele_SamsonOak_Trigger_Beginning_Text_3, MSGBOX_AUTOCLOSE
	playbgm MUS_HG_FOLLOW_ME_1, FALSE
	applymovement SamsonOakMelemeleIntro, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_4
	applymovement LOCALID_PLAYER, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_5
	waitmovement 0
	delay 30
	applymovement SamsonOakMelemeleIntro, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_2
	waitmovement 0
	msgbox Alola_Melemele_SamsonOak_Trigger_Beginning_Text_4
	applymovement SamsonOakMelemeleIntro, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_6
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	msgbox Alola_Melemele_SamsonOak_Trigger_Beginning_Text_5, MSGBOX_AUTOCLOSE
	applymovement SamsonOakMelemeleIntro, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_6
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	msgbox Alola_Melemele_SamsonOak_Trigger_Beginning_Text_6, MSGBOX_AUTOCLOSE
	applymovement SamsonOakMelemeleIntro, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_7
	waitmovement 0
	delay 30
	fadedefaultbgm
	setvar VAR_ALOLA_STATE, 1
	removeobject SamsonOakMelemeleIntro
	setflag FLAG_VISITED_ALOLA
	release
	end


Alola_Melemele_NeedToTalkToSamsonOak::
	lock
	msgbox Alola_Melemele_NeedToTalkToSamsonOak_Text_0, MSGBOX_AUTOCLOSE
	applymovement LOCALID_PLAYER, Alola_Melemele_NeedToTalkToSamsonOak_Movement_0
	waitmovement 0
	release
	end


Alola_Melemele_TotemBattle_Trigger::
	goto_if_unset FLAG_TRIGGERED_MELEMELE_TOTEM, Alola_Melemele_TotemBattle_Trigger_1
	end

Alola_Melemele_TotemBattle_Trigger_1:
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_TotemBattle_Trigger_7
Alola_Melemele_TotemBattle_Trigger_5:
	end

Alola_Melemele_TotemBattle_Trigger_4:
	lock
	delay 30
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 6
	setvar VAR_0x8006, 4
	setvar VAR_0x8007, 4
	special ShakeCamera
	waitstate
	fadescreenswapbuffers FADE_TO_BLACK
	delay 30
	clearflag FLAG_HIDE_MELEMELE_TOTEM
	gettimeofday
	compare VAR_0x8000, TIME_MORNING
	goto_if_eq Alola_Melemele_TotemBattle_Trigger_14
	compare VAR_0x8000, TIME_DAY
	goto_if_eq Alola_Melemele_TotemBattle_Trigger_14
	compare VAR_0x8000, TIME_EVENING
	goto_if_eq Alola_Melemele_TotemBattle_Trigger_14
	playmoncry SPECIES_RATICATE_ALOLA, 0
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( RATICATE_ALOLA )
	clearflag FLAG_MELEMELE_TOTEM_DAY
	addobject Melemele_Totem
	waitmoncry
Alola_Melemele_TotemBattle_Trigger_13:
	special DrawWholeMapView
	delay 30
	fadescreenswapbuffers FADE_FROM_BLACK
	delay 30
	gettimeofday
	compare VAR_0x8000, TIME_MORNING
	goto_if_eq Alola_Melemele_TotemBattle_Trigger_20
	compare VAR_0x8000, TIME_DAY
	goto_if_eq Alola_Melemele_TotemBattle_Trigger_20
	compare VAR_0x8000, TIME_EVENING
	goto_if_eq Alola_Melemele_TotemBattle_Trigger_20
	playmoncry SPECIES_RATICATE_ALOLA, 0
	applymovement Melemele_Totem, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_2
	waitmovement 0
	waitmoncry
Alola_Melemele_TotemBattle_Trigger_19:
	setflag FLAG_TRIGGERED_MELEMELE_TOTEM
	release
	end

Alola_Melemele_TotemBattle_Trigger_6:
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Melemele_TotemBattle_Trigger_10
	goto Alola_Melemele_TotemBattle_Trigger_5

Alola_Melemele_TotemBattle_Trigger_7:
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_TotemBattle_Trigger_6
	goto Alola_Melemele_TotemBattle_Trigger_5

Alola_Melemele_TotemBattle_Trigger_10:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_TotemBattle_Trigger_4
	goto Alola_Melemele_TotemBattle_Trigger_5

Alola_Melemele_TotemBattle_Trigger_14:
	playmoncry SPECIES_LEAFEON, 0
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( LEAFEON )
	setflag FLAG_MELEMELE_TOTEM_DAY
	addobject Melemele_Totem
	waitmoncry
	goto Alola_Melemele_TotemBattle_Trigger_13

Alola_Melemele_TotemBattle_Trigger_20:
	playmoncry SPECIES_LEAFEON, 0
	applymovement Melemele_Totem, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_2
	waitmovement 0
	waitmoncry
	goto Alola_Melemele_TotemBattle_Trigger_19


Alola_Melemele_TotemBattle::
	lock
	faceplayer
	goto_if_set FLAG_MELEMELE_TOTEM_DAY, Alola_Melemele_TotemBattle_1
	playmoncry SPECIES_RATICATE_ALOLA, 0
	msgbox Alola_Melemele_TotemBattle_Text_2, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_RATTATA_ALOLA, 60, ITEM_NONE, SPECIES_RATICATE_ALOLA_TOTEM, 60, ITEM_PECHA_BERRY
	settotemboost B_POSITION_OPPONENT_RIGHT, 0, 1, 0
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Alola_Melemele_TotemBattle_7
	return

Alola_Melemele_TotemBattle_1:
	playmoncry SPECIES_LEAFEON, 0
	msgbox Alola_Melemele_TotemBattle_Text_0, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_EEVEE, 60, ITEM_NONE, SPECIES_LEAFEON, 60, ITEM_PECHA_BERRY
	settotemboost B_POSITION_OPPONENT_RIGHT, 1, 1, 1, 1, 1, 1
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Alola_Melemele_TotemBattle_5
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Alola_Melemele_TotemBattle_9
	return

Alola_Melemele_TotemBattle_5:
	setflag FLAG_HIDE_MELEMELE_TOTEM
	setflag FLAG_DEFEATED_MELEMELE_TOTEM
	removeobject Melemele_Totem
	msgbox Alola_Melemele_TotemBattle_Text_1, MSGBOX_AUTOCLOSE
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

Alola_Melemele_TotemBattle_7:
	setflag FLAG_HIDE_MELEMELE_TOTEM
	setflag FLAG_DEFEATED_MELEMELE_TOTEM
	removeobject Melemele_Totem
	msgbox Alola_Melemele_TotemBattle_Text_3, MSGBOX_AUTOCLOSE
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

Alola_Melemele_TotemBattle_9:
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end


Alola_Melemele_Totem_sign::
	lock
	goto_if_set FLAG_BATTLED_TAPU_FINI, Alola_Melemele_Totem_sign_5
Alola_Melemele_Totem_sign_3:
	msgbox Alola_Melemele_Totem_sign_Text_6, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_Totem_sign_2:
	msgbox Alola_Melemele_Totem_sign_Text_0
	dynmultichoice 20, 4, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, Alola_Melemele_Totem_sign_Text_1, Alola_Melemele_Totem_sign_Text_2, Alola_Melemele_Totem_sign_Text_3, Alola_Melemele_Totem_sign_Text_4, Alola_Melemele_Totem_sign_Text_5
	compare VAR_RESULT, 0
	goto_if_eq Alola_Melemele_Totem_sign_12
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_Totem_sign_15
	compare VAR_RESULT, 2
	goto_if_eq Alola_Melemele_Totem_sign_18
	compare VAR_RESULT, 3
	goto_if_eq Alola_Melemele_Totem_sign_20
	release
	end

Alola_Melemele_Totem_sign_4:
	goto_if_set FLAG_BATTLED_TAPU_BULU, Alola_Melemele_Totem_sign_8
	goto Alola_Melemele_Totem_sign_3

Alola_Melemele_Totem_sign_5:
	goto_if_set FLAG_BATTLED_TAPU_KOKO, Alola_Melemele_Totem_sign_4
	goto Alola_Melemele_Totem_sign_3

Alola_Melemele_Totem_sign_8:
	goto_if_set FLAG_BATTLED_TAPU_LELE, Alola_Melemele_Totem_sign_2
	goto Alola_Melemele_Totem_sign_3

Alola_Melemele_Totem_sign_12:
	goto_if_unset FLAG_HIDE_TAPU_KOKO, Alola_Melemele_Totem_sign_12_Lower
	warp MAP_MELEMELE_ISLE_HNS, 34, 26
	waitstate
	end

Alola_Melemele_Totem_sign_12_Lower:
	warp MAP_MELEMELE_ISLE_HNS, 34, 27
	waitstate
	end

Alola_Melemele_Totem_sign_15:
	goto_if_unset FLAG_HIDE_TAPU_LELE, Alola_Melemele_Totem_sign_15_Lower
	warp MAP_AKALA_ISLE_HNS, 9, 11
	waitstate
	end

Alola_Melemele_Totem_sign_15_Lower:
	warp MAP_AKALA_ISLE_HNS, 9, 12
	waitstate
	end

Alola_Melemele_Totem_sign_18:
	goto_if_unset FLAG_HIDE_TAPU_BULU, Alola_Melemele_Totem_sign_18_Lower
	warp MAP_ULA_ULA_FOREST_HNS, 16, 5
	waitstate
	end

Alola_Melemele_Totem_sign_18_Lower:
	warp MAP_ULA_ULA_FOREST_HNS, 16, 6
	waitstate
	end

Alola_Melemele_Totem_sign_20:
	goto_if_unset FLAG_HIDE_TAPU_FINI, Alola_Melemele_Totem_sign_20_Lower
	warp MAP_PONI_ISLE_HNS, 13, 8
	waitstate
	end

Alola_Melemele_Totem_sign_20_Lower:
	warp MAP_PONI_ISLE_HNS, 13, 9
	waitstate
	end


Alola_MeleMele_TapuKoko_Flyover::
	goto_if_set FLAG_FLYOVER_TAPU_KOKO, Alola_MeleMele_TapuKoko_Flyover_2
	release
	end

Alola_MeleMele_TapuKoko_Flyover_2:
	addobject Melemele_Flyover_Tapu
	playse SE_M_FLY
	applymovement Melemele_Flyover_Tapu, Alola_MeleMele_TapuKoko_Flyover_Movement_0
	waitmovement 0
	removeobject Melemele_Flyover_Tapu
	clearflag FLAG_FLYOVER_TAPU_KOKO
	clearflag FLAG_HIDE_TAPU_KOKO
	release
	end


Alola_Melemele_BattleVsTapuKoko::
	lock
	faceplayer
	playmoncry SPECIES_TAPU_KOKO, CRY_MODE_ENCOUNTER
	msgbox Alola_Melemele_BattleVsTapuKoko_Text_0
	waitmoncry
	seteventmon SPECIES_TAPU_KOKO, 60
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Alola_Melemele_BattleVsTapuKoko_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Alola_Melemele_BattleVsTapuKoko_3
	release
	end

	release
	end

Alola_Melemele_BattleVsTapuKoko_2:
	setflag FLAG_HIDE_TAPU_KOKO
	setflag FLAG_BATTLED_TAPU_KOKO
	removeobject Melemele_Tapu
	release
	end

Alola_Melemele_BattleVsTapuKoko_3:
	setflag FLAG_HIDE_TAPU_KOKO
	setflag FLAG_BATTLED_TAPU_KOKO
	removeobject Melemele_Tapu
	release
	end


Alola_Melemele_TrainerBattleSwimmer::
	trainerbattle_single TRAINER_MELEMELE_SWIMMER_1_HNS, Alola_Melemele_TrainerBattleSwimmer_Text_0, Alola_Melemele_TrainerBattleSwimmer_Text_1
	msgbox Alola_Melemele_TrainerBattleSwimmer_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Alola_Melemele_Bugcatcher::
	lock
	faceplayer
	msgbox Alola_Melemele_Bugcatcher_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Alola_Melemele_camper::
	lock
	faceplayer
	msgbox Alola_Melemele_camper_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Alola_Melemele_Picnicker::
	lock
	faceplayer
	msgbox Alola_Melemele_Picnicker_Text_0, MSGBOX_AUTOCLOSE
	release
	end


MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0:
	face_up
	step_end

Alola_Melemele_GetOffBoat_Movement_0:
	face_right
	step_end

Alola_Melemele_GetOffBoat_Movement_1:
	face_left
	step_end

Alola_Melemele_TravelToKanto_Movement_0:
	walk_right
	walk_down
	step_end

Alola_Melemele_TravelToKanto_Movement_1:
	walk_up
	walk_right
	walk_right
	walk_down
	step_end

Alola_Melemele_TravelToKanto_Movement_2:
	face_down
	step_end

Alola_Melemele_TravelToKanto_Movement_3:
	walk_down
	step_end

Alola_Melemele_TravelToKanto_Movement_4:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_0:
	emote_exclamation_mark
	face_up
	step_end

Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_2:
	walk_in_place_down
	walk_in_place_down
	step_end

Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_3:
	walk_in_place_up
	walk_in_place_up
	step_end

Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_4:
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_5:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_6:
	jump_in_place_down
	jump_in_place_down
	step_end

Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_7:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Alola_Melemele_NeedToTalkToSamsonOak_Movement_0:
	walk_up
	step_end

Alola_MeleMele_TapuKoko_Flyover_Movement_0:
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	step_end

Alola_Melemele_GetOffBoat_Text_0:
	.string "Benvenuto di nuovo alle ISOLE!\p"
	.string "Torna se vuoi fare un viaggio\n"
	.string "fino alla terraferma di KANTO!$"

Alola_Melemele_TravelToKanto_Text_0:
	.string "Ahoy!\p"
	.string "Vuoi viaggiare fino alla terraferma\n"
	.string "di KANTO?$"

Alola_Melemele_TravelToKanto_Text_1:
	.string "Ahoy! Ti faccio salire a bordo!$"

Alola_Melemele_TravelToKanto_Text_2:
	.string "Ahoy!\n"
	.string "Torna quando vuoi salpare.$"

Alola_Melemele_Mailbox_Text_0:
	.string "VILLA DI SAMSON OAK$"

Alola_Melemele_Melemele_Sign_Text_0:
	.string "Benvenuto a MELEMELE!$"

Alola_Melemele_Pokecenter_Sign_Text_0:
	.string "Benvenuto al CENTRO POKéMON\n"
	.string "di MELEMELE!\p"
	.string "È l'unico CENTRO POKéMON delle\n"
	.string "ISOLE di ALOLA, ma puoi riposare sulle\l"
	.string "panchine in giro per le ISOLE.$"

Alola_Melemele_MelemeleMart_Sign_Text_0:
	.string "MERCATO DI MELEMELE$"

Alola_Melemele_BattleSandygast_Text_0:
	.string "Coorr!$"

Alola_Melemele_SamsonOak_Trigger_Beginning_Text_0:
	.string "ALOLA$"

Alola_Melemele_SamsonOak_Trigger_Beginning_Text_1:
	.string "Benvenuto alle ISOLE di ALOLA!$"

Alola_Melemele_SamsonOak_Trigger_Beginning_Text_2:
	.string "Mi chiamo SAMSON OAK!\n"
	.string "Sono un PROFESSOR POKéMON.\p"
	.string "Come ti chiami?$"

Alola_Melemele_SamsonOak_Trigger_Beginning_Text_3:
	.string "Ah, {PLAYER}.\n"
	.string "Bel nome!\p"
	.string "Forse conosci mio cugino, il PROF. OAK,\n"
	.string "della regione di KANTO.\p"
	.string "Lascia che ti mostri il paese!$"

Alola_Melemele_SamsonOak_Trigger_Beginning_Text_4:
	.string "Questa è la città principale delle isole.\p"
	.string "Assomiglia molto a HAU'OLI CITY di\n"
	.string "ALOLA… {PAUSE 30}E a pensarci bene…\p"
	.string "Tutta l'isola mi ricorda MELEMELE\n"
	.string "ISLAND…$"

Alola_Melemele_SamsonOak_Trigger_Beginning_Text_5:
	.string "Beh, comunque!\p"
	.string "Studio le varianti dei POKéMON che\n"
	.string "si trovano nelle varie regioni!\p"
	.string "Tornando dalla regione di ALOLA,\n"
	.string "mi sono imbattuto in queste isole…\p"
	.string "Con mia sorpresa, molti POKéMON visti\n"
	.string "ad ALOLA erano anche qui, così ho\l"
	.string "chiamato il posto… {PAUSE 30}ISOLE DI ALOLA!$"

Alola_Melemele_SamsonOak_Trigger_Beginning_Text_6:
	.string "Non ho ancora esplorato del tutto le\n"
	.string "ISOLE... {PAUSE 30}sono appena arrivato anch'io.\p"
	.string "Vorrei sapere se tutte le varianti\n"
	.string "native di ALOLA sono qui.\p"
	.string "Se ne incontri qualcuna,\n"
	.string "passa dalla mia villa sul lato est\l"
	.string "dell'ISOLA e mostramela!\p"
	.string "Oh. E sentiti libero di esplorare l'ISOLA\n"
	.string "mentre vieni!\p"
	.string "Ci vediamo lì!$"

Alola_Melemele_NeedToTalkToSamsonOak_Text_0:
	.string "SAMSON ti aspetta nella sua villa...\n"
	.string "{PAUSE 30}meglio non farlo aspettare troppo!$"

Alola_Melemele_TotemBattle_Text_0:
	.string "Leee!$"

Alola_Melemele_TotemBattle_Text_1:
	.string "Il LEAFEON Totem è stato sconfitto!\n"
	.string "È scappato via da qualche parte...$"

Alola_Melemele_TotemBattle_Text_2:
	.string "Thhhh!$"

Alola_Melemele_TotemBattle_Text_3:
	.string "Il RATICATE Totem è stato sconfitto!\n"
	.string "È scappato via da qualche parte...$"

MelemeleIsle_hns_Movement_FacePlayerUpAfterTotemWarp:
	face_up
	step_end


Alola_Melemele_Totem_sign_Text_0:
	.string "Il totem emana un'energia\n"
	.string "potente…\p"
	.string "Toccalo per il Teletrasporto\n"
	.string "su un'altra isola?$"

Alola_Melemele_Totem_sign_Text_1:
	.string "ISOLA MELEMELE$"

Alola_Melemele_Totem_sign_Text_2:
	.string "ISOLA AKALA$"

Alola_Melemele_Totem_sign_Text_3:
	.string "ISOLA ULA'ULA$"

Alola_Melemele_Totem_sign_Text_4:
	.string "ISOLA PONI$"

Alola_Melemele_Totem_sign_Text_5:
	.string "Annulla$"

Alola_Melemele_Totem_sign_Text_6:
	.string "Uno strano totem si erge qui,\n"
	.string "emana una grande forza…$"

Alola_Melemele_BattleVsTapuKoko_Text_0:
	.string "Ko-Ko-Kooo!$"

Alola_Melemele_TrainerBattleSwimmer_Text_0:
	.string "L'acqua qui vicino alle ISOLE è calda!$"

Alola_Melemele_TrainerBattleSwimmer_Text_1:
	.string "Forse dovrei asciugarmi sulla terraferma\nun po'...$"

Alola_Melemele_TrainerBattleSwimmer_Text_2:
	.string "Nell'acqua ci sono POKéMON fantastici,\n"
	.string "prova con tutte le tue canne da pesca!$"

Alola_Melemele_Bugcatcher_Text_0:
	.string "I POKéMON insetto delle ISOLE DI ALOLA\n"
	.string "sono molto più grandi di quelli di KANTO!$"

Alola_Melemele_camper_Text_0:
	.string "Ho viaggiato da KANTO solo per vedere\n"
	.string "una variante del mio POKéMON gatto\l"
	.string "preferito, MEOWTH!$"

Alola_Melemele_Picnicker_Text_0:
	.string "Queste ISOLE pullulano di POKéMON\n"
	.string "unici!\p"
	.string "Devo fare scorta di POKé BALL per\n"
	.string "prenderli tutti!$"
