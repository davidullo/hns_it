.set PLAYER_STARTER_SPECIES,  VAR_TEMP_2

NewBarkTown_Lab_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_Lab_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NewBarkTown_Lab_OnFrame
	.byte 0

NewBarkTown_Lab_OnTransition::
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 6, NewBarkTown_Lab_EventScript_ElmAtComputer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 2, NewBarkTown_Lab_EventScript_ElmAtComputer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 3, NewBarkTown_Lab_EventScript_ElmAtComputer
	end
	
NewBarkTown_Lab_OnFrame::
	map_script_2 VAR_NEWBARKTOWN_LABSTATE, 4, NewBarkTown_Lab_EventScript_PoliceEpisode
	.2byte 0

NewBarkTown_Lab_EventScript_ElmAtComputer::
	setobjectxyperm LOCALID_ELM, 3, 2
	setobjectmovementtype LOCALID_ELM, MOVEMENT_TYPE_FACE_UP
	end

NewBarkTown_Lab_EventScript_TriggerStartLabLeft::	
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_WalkRight
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_TriggerStartLab
	end

NewBarkTown_Lab_EventScript_TriggerStartLabRight::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_WalkLeft
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_TriggerStartLab
	end

NewBarkTown_Lab_EventScript_TriggerStartLab::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_LabMovement_WalkToElm
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_ElmIntro
	end

NewBarkTown_EventScript_Aide1::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_AideAlwaysBusy, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_EventScript_Aide2::
	lock
	faceplayer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 5, NewBarkTown_EventScript_Aide2Testimony
	msgbox NewBarkTown_Lab_Text_AideSave, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_EventScript_Aide2Testimony::
	msgbox NewBarkTown_Lab_Text_AideTheftTestimony, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_Elm::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_NEWBARKTOWN_LAB_AIDE, NewBarkTown_Lab_EventScript_ElmAideIsWaiting
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 7, NewBarkTown_Lab_EventScript_ElmMasterBall
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 8, NewBarkTown_Lab_EventScript_ElmKimono
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 9, NewBarkTown_Lab_EventScript_ElmLeague
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 10, NewBarkTown_Lab_EventScript_ElmSSTicket

	goto_if_unset FLAG_RECEIVED_TOGEPI_EGG, NewBarkTown_Lab_EventScript_Elm_AfterEggCheck
	goto_if_set FLAG_SHOWN_ELM_TOGEPI, NewBarkTown_Lab_EventScript_Elm_CallMe
	call_if_unset FLAG_SHOWN_ELM_TOGEPI, NewBarkTown_Lab_EventScript_Elm_Check_Togepi
NewBarkTown_Lab_EventScript_Elm_AfterEggCheck:
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 1, NewBarkTown_Lab_EventScript_Elm_Check_WhereIsEgg
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 5, NewBarkTown_Lab_EventScript_ElmState5

	goto_if_ge VAR_NEWBARKTOWN_LABSTATE, 6, NewBarkTown_Lab_EventScript_ElmState5
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 2, CopNewBarkTown_Lab_EventScript_ElmState2
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 3, CopNewBarkTown_Lab_EventScript_ElmState2
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_MrPokemon
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_ElmChoosePokemon
	end

NewBarkTown_Lab_EventScript_ElmAideIsWaiting::
	msgbox NewBarkTown_Lab_Text_ElmAideIsWaiting, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_Text_ElmAideIsWaiting:
	.string "{PLAYER}!\p"
	.string "Che ci fai qui?\p"
	.string "Il mio assistente ti aspetta ancora\n"
	.string "a VIOLET CITY!$"

NewBarkTown_Lab_EventScript_ElmIntro::
	msgbox NewBarkTown_Lab_Text_ElmIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ElmAccepted
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_ElmRefused
	end

NewBarkTown_Lab_EventScript_ElmRefused::
	msgbox NewBarkTown_Lab_Text_ElmRefused, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ElmAccepted
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_ElmRefused
	end

NewBarkTown_Lab_EventScript_ElmAccepted::
	msgbox NewBarkTown_Lab_Text_ElmAccepted, MSGBOX_DEFAULT
	msgbox NewBarkTown_Lab_Text_ElmResearchAmbitions, MSGBOX_DEFAULT
	delay 30
	playse SE_PC_LOGIN
	waitse
	playse SE_PIN
	applymovement LOCALID_ELM, Common_Movement_QuestionMark
	delay 55
	waitmovement LOCALID_ELM
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_CheckEmail
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Left
	waitmovement 0
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmGotAnEmail, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ReturnFromEmail
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Up
	waitmovement 0
	delay 30
	msgbox NewBarkTown_Lab_Text_ElmMissionFromMrPokemon, MSGBOX_DEFAULT
	goto NewBarkTown_Lab_EventScript_ElmChoosePokemon
	end

NewBarkTown_Lab_EventScript_ElmChoosePokemon::
	msgbox NewBarkTown_Lab_Text_ElmChooseAPokemon, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 1
	release
	end

NewBarkTown_Lab_EventScript_TriggerReturnPlayer::
	lock
	msgbox NewBarkTown_Lab_Text_ElmWhereGoing, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_ReturnPlayer
	waitmovement 0
	release
	end

NewBarkTown_Lab_EventScript_ShouldntTouch::
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	closemessage
	release
	end


NewBarkTown_Lab_EventScript_ChikoritaBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_ChikoritaBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	release
	closemessage
	end

NewBarkTown_Lab_EventScript_ChikoritaBall_Choice::
	@callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 0
	setvar PLAYER_STARTER_SPECIES, SPECIES_CHIKORITA
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseChikorita, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_CyndaquilBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_CyndaquilBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_CyndaquilBall_Choice::
	@callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 1
	setvar PLAYER_STARTER_SPECIES, SPECIES_CYNDAQUIL
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseCyndaquil, MSGBOX_YESNO	
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_TotodileBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_TotodileBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	release
	closemessage
	end

NewBarkTown_Lab_EventScript_TotodileBall_Choice::
	@callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 2
	setvar PLAYER_STARTER_SPECIES, SPECIES_TOTODILE
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseTotodile, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_DeclinedStarter::
	hidemonpic
	msgbox NewBarkTown_Lab_Text_DidntChooseStarter, MSGBOX_DEFAULT
	closemessage
	@callnative EnableStaticRandomizer
	release
	end

NewBarkTown_Lab_EventScript_ChoseStarter::
	@callnative EnableStaticRandomizer
	hidemonpic
	removeobject VAR_LAST_TALKED
	msgbox NewBarkTown_Lab_Text_ChoseStarter, MSGBOX_DEFAULT
	call_if_eq VAR_STARTER_MON, 0, NewBarkTown_Lab_EventScript_GiveStarter_Chikorita
	call_if_eq VAR_STARTER_MON, 1, NewBarkTown_Lab_EventScript_GiveStarter_Cyndaquil
	call_if_eq VAR_STARTER_MON, 2, NewBarkTown_Lab_EventScript_GiveStarter_Totodile
	setflag FLAG_SYS_POKEMON_GET
	playfanfare MUS_OBTAIN_ITEM
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	message NewBarkTown_Lab_Text_ReceivedStarter
	waitfanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_ChoseStarter_NicknameStarter_Nuzlocke
	msgbox NewBarkTown_Lab_Text_Nickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_NicknameStarter
	callnative UpdateFollowingPokemon
	release
	end

NewBarkTown_Lab_EventScript_GiveStarter_Chikorita::
	call_if_unset FLAG_SHINY_STARTER_1, NewBarkTown_Lab_EventScript_GiveStarter_NotShiny
	call_if_set FLAG_SHINY_STARTER_1, NewBarkTown_Lab_EventScript_GiveStarter_Shiny
	return

NewBarkTown_Lab_EventScript_GiveStarter_Cyndaquil::
	call_if_unset FLAG_SHINY_STARTER_2, NewBarkTown_Lab_EventScript_GiveStarter_NotShiny
	call_if_set FLAG_SHINY_STARTER_2, NewBarkTown_Lab_EventScript_GiveStarter_Shiny
	return

NewBarkTown_Lab_EventScript_GiveStarter_Totodile::
	call_if_unset FLAG_SHINY_STARTER_3, NewBarkTown_Lab_EventScript_GiveStarter_NotShiny
	call_if_set FLAG_SHINY_STARTER_3, NewBarkTown_Lab_EventScript_GiveStarter_Shiny
	return

NewBarkTown_Lab_EventScript_GiveStarter_NotShiny::
	givemon PLAYER_STARTER_SPECIES, 5, ITEM_NONE, BALL_POKE, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_NEVER
	return

NewBarkTown_Lab_EventScript_GiveStarter_Shiny::
	givemon PLAYER_STARTER_SPECIES, 5, ITEM_NONE, BALL_POKE, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS	
	return

NewBarkTown_Lab_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	release
	end

NewBarkTown_Lab_EventScript_ChoseStarter_NicknameStarter_Nuzlocke::
	message NewBarkTown_Lab_Text_Nickname
	waitmessage
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	release
	end

NewBarkTown_Lab_EventScript_MrPokemon::
	setvar VAR_NEWBARKTOWN_LABSTATE, 2
	setvar VAR_NEWBARK_TOWN_STATE, 3
	msgbox NewBarkTown_Lab_Text_ElmDirections1_Register, MSGBOX_DEFAULT
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox NewBarkTown_Lab_Text_RegisteredElm, MSGBOX_DEFAULT
	waitfanfare
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_EAST, NewBarkTown_Lab_EventScript_MrPokemonMovementSafe
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_CheckEmailSlow
	waitmovement 0
	clearflag FLAG_RECEIVED_FIRST_BALLS
	clearflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARK_TOWN_STATE, 3
	setflag FLAG_ENABLE_CONDITION
	release
	end

NewBarkTown_Lab_EventScript_MrPokemonMovementSafe::
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_GotoComputerSafe
	waitmovement 0
	clearflag FLAG_RECEIVED_FIRST_BALLS
	clearflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARK_TOWN_STATE, 3
	release
	end

CopNewBarkTown_Lab_EventScript_ElmState2::
	msgbox NewBarkTown_Lab_Text_ElmDirections1, MSGBOX_DEFAULT
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
	applymovement LOCALID_ELM, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_HealingMachine1::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_HealingMachine2
	msgbox LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_HealingMachine2::
	call Common_EventScript_OutOfCenterPartyHeal
	release
	end



NewBarkTown_Lab_EventScript_TriggerAideGivePotion::
	lock
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox NewBarkTown_Lab_Text_AideGivePotion, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARKTOWN_LABSTATE, 3
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	release
	end

NewBarkTown_Lab_EventScript_HideCyndaquil::
	setflag FLAG_HIDE_CYNDAQUILBALL
	return
NewBarkTown_Lab_EventScript_HideTotodile::
	setflag FLAG_HIDE_TOTODILEBALL
	return
NewBarkTown_Lab_EventScript_HideChikorita::
	setflag FLAG_HIDE_CHIKORITABALL
	return

NewBarkTown_Lab_EventScript_PoliceEpisode::
	lock
	setmetatile 7, 1, METATILE_R26_21_Broken_Window, TRUE
	call_if_eq VAR_STARTER_MON, 0 NewBarkTown_Lab_EventScript_HideCyndaquil
	call_if_eq VAR_STARTER_MON, 1 NewBarkTown_Lab_EventScript_HideTotodile
	call_if_eq VAR_STARTER_MON, 2 NewBarkTown_Lab_EventScript_HideChikorita
	applymovement OBJ_EVENT_ID_PLAYER, NeBarkTownLab_Movement_PlayerWalkToCop
	waitmovement 0
	setflag FLAG_HIDE_LAB_POLICEMAN
	turnobject LOCALID_COP DIR_WEST
	msgbox NewBarkTown_Lab_Text_Officer1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceYes
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceNo
	end

NewBarkTown_Lab_EventScript_PoliceNo::
	msgbox NewBarkTown_Lab_Text_OfficerNo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceYes
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceNo
	end

NewBarkTown_Lab_EventScript_PoliceYes::
	closemessage
	special NameRival
	waitstate
	msgbox NewBarkTown_Lab_Text_Officer2_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, NewBarkTown_Lab_EventScript_PoliceYes
	msgbox NewBarkTown_Lab_Text_Officer2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_COP, NewBarkTown_Lab_Movement_CopLeaves
	waitmovement 0
	removeobject LOCALID_COP

	@ setobjectxyperm LOCALID_COP, 25, 4
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_PlayerStepsToElm
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft1, MSGBOX_DEFAULT
	playfanfare MUS_LEVEL_UP
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft2, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepBack
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft3, MSGBOX_DEFAULT
	delay 20
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepForward
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft4, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 5
	setvar VAR_NEWBARK_TOWN_STATE, 4
	setflag FLAG_HIDE_MOMS_FRIEND
	clearflag FLAG_HIDE_MOMS_FRIEND2
	setflag FLAG_ADVENTURE_STARTED
	setflag FLAG_START_NUZLOCKE
	setflag FLAG_EXP_SHARE_ENABLED
	removeitem ITEM_MYSTERY_EGG
	release
	end

NewBarkTown_Lab_EventScript_ElmState5::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_ElmStudyingEgg, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ELM Common_Movement_FaceOriginalDirection
	release
	end
	
NewBarkTown_Lab_EventScript_ElmMasterBall::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall1, MSGBOX_DEFAULT
	giveitem ITEM_MASTER_BALL
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall2, MSGBOX_DEFAULT
	closemessage
	delay 20
	playse SE_PIN
	applymovement LOCALID_ELM, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ELM
	msgbox NewBarkTown_Lab_Text_KimonoGirls, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 8
	setvar VAR_ECRUTEAK_CITY_THEATER, 4
	setflag FLAG_HIDE_ECRUTEAK_SILVER
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	release
	end

NewBarkTown_Lab_EventScript_ElmKimono::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_KimonoWaiting, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_ElmLeague::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_League, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_ElmSSTicket::
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket1, MSGBOX_DEFAULT
	giveitem ITEM_SS_TICKET
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket2, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SSAQUA_1F_GRANDPA
	setvar VAR_NEWBARKTOWN_LABSTATE, 11
	clearflag FLAG_HIDE_OLIVINE_PORT_OAK
	release
	end

NewBarkTown_Lab_EventScript_TriggerAideGiveBalls::
	lock
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox NewBarkTown_Lab_Text_AideGiveBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POKE_BALL, 5
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FIRST_BALLS
	setvar VAR_NEWBARKTOWN_LABSTATE, 6
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	release
	end

NewBarkTown_Lab_EventScript_Elm_Check_WhereIsEgg::
	msgbox NewBarkTown_Lab_Text_ElmWaitingEggHatch, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_Elm_Check_Togepi::
	checkspecies SPECIES_TOGEPI
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
	checkspecies SPECIES_TOGETIC
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
	checkspecies SPECIES_TOGEKISS
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
	return

NewBarkTown_Lab_EventScript_Elm_Togepi_Seen::
	msgbox NewBarkTown_Lab_Text_ShowTogepi1, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ShowTogepi2, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ShowTogepi3, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone1, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_EVERSTONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone2, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SHOWN_ELM_TOGEPI
	release
	end

NewBarkTown_Lab_EventScript_Elm_CallMe::
	msgbox NewBarkTown_Lab_Text_Elm_CallMe, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_Movement_WalkRight:
	walk_right
	step_end

NewBarkTown_Lab_Movement_WalkLeft:
	walk_left
	step_end

NewBarkTown_LabMovement_WalkToElm:
	walk_up
	walk_up
	walk_up
	step_end

NewBarkTown_Lab_Movement_ReturnPlayer:
	walk_up
	step_end

NewBarkTown_Lab_Movement_CheckEmail:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	step_end

NewBarkTown_Lab_Movement_CheckEmailSlow:
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

NewBarkTown_Lab_Movement_GotoComputerSafe:
	walk_up
	walk_left
	walk_left
	walk_left
	face_up
	step_end

NewBarkTown_Lab_Movement_ReturnFromEmail:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_down
	step_end

NewBarkTown_Lab_Movement_Look_Left:
	face_left
	step_end

NewBarkTown_Lab_Movement_Look_Up:
	face_up
	step_end


NewBarkTown_Lab_Movement_Aide1WalkToPlayer:
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

NewBarkTown_Lab_Movement_Aide1LeavePlayer:
	walk_left
	walk_left
	walk_up
	walk_up
	face_down
	step_end

NeBarkTownLab_Movement_PlayerWalkToCop:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_up
	face_right
	step_end

NewBarkTown_Lab_Movement_CopLeaves:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

NewBarkTown_Lab_Movement_PlayerStepsToElm:
	walk_right
	face_up
	step_end

NewBarkTown_Lab_Movement_ElmStepBack:
	lock_facing_direction
	walk_fast_up
	unlock_facing_direction
	step_end

NewBarkTown_Lab_Movement_ElmStepForward:
	walk_fast_down
	step_end

NewBarkTown_Lab_Text_ShouldntTouch:
	.string "Meglio non toccare!$"

NewBarkTown_Lab_Text_ElmIntro:
	.string "ELM: {PLAYER}! There you are!\p"
	.string "I needed to ask you a favor.\p"
	.string "I'm conducting new POKéMON\n"
	.string "research right now. I was\l"
	.string "wondering if you could help\l"
	.string "me with it, {PLAYER}.\p"
	.string "You see…\p"
	.string "I'm writing a paper that I\n"
	.string "want to present at a conference.\p"
	.string "But there are some things I\n"
	.string "don't quite understand yet.\p"
	.string "So!\p"
	.string "I'd like you to raise a\n"
	.string "POKéMON that I recently caught.$"

NewBarkTown_Lab_Text_ElmAccepted:
	.string "Grazie, {PLAYER}!\n"
	.string "Mi sei di grande aiuto!$"

NewBarkTown_Lab_Text_ElmRefused:
	.string "Ma… Ti prego, mi serve il tuo\n"
	.string "aiuto!$"

NewBarkTown_Lab_Text_ElmResearchAmbitions:
	.string "Quando annuncerò i risultati,\n"
	.string "sono certo che approfondiremo\p"
	.string "i tanti misteri dei\n"
	.string "POKéMON.\p"
	.string "Puoi contarci!$"

NewBarkTown_Lab_Text_ElmGotAnEmail:
	.string "Oh, ehi! Ho ricevuto un'e-mail!\p"
	.string "… … … … … … … …\n"
	.string "Mmm… Uh-huh…\p"
	.string "Okay…$"

NewBarkTown_Lab_Text_ElmMissionFromMrPokemon:
	.string "Ehi, ascolta.\p"
	.string "Ho un conoscente chiamato\n"
	.string "IL SIG. POKéMON.\p"
	.string "Continua a trovare cose strane e\n"
	.string "a vantarsi delle sue scoperte.\p"
	.string "Comunque, ho appena ricevuto un'e-mail\n"
	.string "da lui che dice che questa\l"
	.string "volta è vero.\p"
	.string "È intrigante, ma siamo\n"
	.string "occupati con la ricerca sui POKéMON...\p"
	.string "Aspetta!\n"
	.string "Ho un'idea!\p"
	.string "{PLAYER}, puoi andare tu al\n"
	.string "posto nostro?$"

NewBarkTown_Lab_Text_ElmChooseAPokemon:
	.string "Voglio che tu allevi uno dei\n"
	.string "POKéMON contenuti in queste BALL.\p"
	.string "Sarai il primo compagno di\n"
	.string "quel POKéMON, {PLAYER}!\p"
	.string "Vai. Scegline uno!$"

NewBarkTown_Lab_Text_ElmWhereGoing:
	.string "ELM: Aspetta! Dove\n"
	.string "vai?$"

NewBarkTown_Lab_Text_ChooseCyndaquil:
	.string "ELM: Prendi {STR_VAR_1},\n"
	.string "il POKéMON {STR_VAR_2}?$"

NewBarkTown_Lab_Text_ChooseTotodile:
	.string "ELM: Vuoi {STR_VAR_1},\n"
	.string "il POKéMON {STR_VAR_2}?$"

NewBarkTown_Lab_Text_ChooseChikorita:
	.string "ELM: Quindi ti piace {STR_VAR_1},\n"
	.string "il POKéMON {STR_VAR_2}?$"

NewBarkTown_Lab_Text_DidntChooseStarter:
	.string "ELM: Pensaci bene.\p"
	.string "Il tuo partner è importante.$"

NewBarkTown_Lab_Text_ChoseStarter:
	.string "ELM: Penso sia un\n"
	.string "POKéMON fantastico!$"

NewBarkTown_Lab_Text_ReceivedStarter:
	.string "{PLAYER} ha ricevuto {STR_VAR_1}!$"

NewBarkTown_Lab_Text_Nickname:
	.string "Vuoi dare un soprannome\n"
	.string "a {STR_VAR_1}?$"

NewBarkTown_Lab_Text_ElmDirections1:
	.string "IL SIG. POKéMON vive poco\n"
	.string "oltre CHERRYGROVE, la città\l"
	.string "successiva.\p"
	.string "È quasi una strada dritta,\n"
	.string "non puoi sbagliare.\p"
	.string "Ma per sicurezza, hai il mio\n"
	.string "numero. Chiamami se\l"
	.string "succede qualcosa!$"

NewBarkTown_Lab_Text_ElmDirections1_Register:
	.string "IL SIG. POKéMON vive poco\n"
	.string "oltre CHERRYGROVE, la città\l"
	.string "successiva.\p"
	.string "È quasi una strada dritta,\n"
	.string "non puoi sbagliare.\p"
	.string "Ma per sicurezza, ecco il mio\n"
	.string "numero. Chiamami se\l"
	.string "succede qualcosa!$"

NewBarkTown_Lab_Text_RegisteredElm:
	.string "PROF.ELM registrato\n"
	.string "nel POKéGEAR.$"


NewBarkTown_Lab_Text_ElmLetYourMonBattle:
	.string "Se appare un POKéMON selvatico,\n"
	.string "fallo lottare col tuo POKéMON!$"

NewBarkTown_Lab_Text_ElmDirections2:
	.string "Se appare un POKéMON selvatico,\n"
	.string "fallo lottare col tuo POKéMON!\p"
	.string "Se il tuo POKéMON è ferito,\n"
	.string "curalo con la macchina\l"
	.string "alla mia destra, o al CENTRO POKéMON.\p"
	.string "Conto su di te!$"

NewBarkTown_Lab_Text_GotElmsNumber:
	.string "{PLAYER} ha ottenuto il numero\n"
	.string "di ELM.$"

NewBarkTown_Lab_Text_ElmDescribesMrPokemon:
	.string "IL SIG. POKéMON gira ovunque e\n"
	.string "trova rarità.\p"
	.string "Peccato che siano solo rare e\n"
	.string "poco utili…$"

NewBarkTown_Lab_Text_ElmPokeBall:
	.string "Contiene un POKéMON catturato\n"
	.string "dal PROF.ELM.$"

@THEFT================================================================================

NewBarkTown_Lab_Text_ElmAfterTheft1:
	.string "ELM: {PLAYER}, è terribile…\p"
	.string "Ah, sì, qual era la grande\n"
	.string "scoperta del SIG. POKéMON?$"

NewBarkTown_Lab_Text_ElmAfterTheft2:
	.string "{PLAYER} ha consegnato l'UOVO\n"
	.string "MISTERIOSO al PROF.ELM.$"

NewBarkTown_Lab_Text_ElmAfterTheft3:
	.string "ELM: Questo?$"

NewBarkTown_Lab_Text_ElmAfterTheft4:
	.string "Ma… È un UOVO di POKéMON?\p"
	.string "Se lo è, è una grande\n"
	.string "scoperta!\p"
	.string "ELM: Cosa?!?\p"
	.string "Il PROF.OAK ti ha dato un POKéDEX?\p"
	.string "{PLAYER}, è vero?\n"
	.string "I-Incredibile!\p"
	.string "È bravissimo a vedere il\n"
	.string "potenziale delle persone.\p"
	.string "Wow, {PLAYER}. Forse hai ciò\n"
	.string "che serve per diventare CAMPIONE.\p"
	.string "Sembra che tu vada d'accordo\n"
	.string "con i POKéMON.\p"
	.string "Dovresti affrontare la sfida\n"
	.string "delle PALESTRE.\p"
	.string "La PALESTRA più vicina è quella\n"
	.string "di VIOLET CITY.\p"
	.string "…{PLAYER}. La strada verso il\n"
	.string "titolo sarà lunga.\p"
	.string "Prima di partire, vai a\n"
	.string "parlare con tua mamma.$"

NewBarkTown_Lab_Text_ElmStudyingEgg:
	.string "ELM: Non arrenderti!\n"
	.string "Ti chiamo se scopro qualcosa\l"
	.string "su quell'UOVO!$"

NewBarkTown_Lab_Text_ElmAideHasEgg:
	.string "ELM: {PLAYER}? Non hai incontrato\n"
	.string "il mio assistente?\p"
	.string "Doveva darti l'UOVO al\n"
	.string "CENTRO POKéMON di\p"
	.string "VIOLET CITY.\p"
	.string "Devi averlo mancato di poco.\n"
	.string "Prova a raggiungerlo lì.$"

NewBarkTown_Lab_Text_ElmWaitingEggHatch:
	.string "ELM: Ehi, quell'UOVO è\n"
	.string "cambiato?$"

NewBarkTown_Lab_Text_ElmThoughtEggHatched:
	.string "{PLAYER}? Credevo che l'UOVO\n"
	.string "si fosse schiuso.\p"
	.string "Dov'è il POKéMON?$"

NewBarkTown_Lab_Text_ShowTogepi1:
	.string "ELM: {PLAYER}, stai benissimo!$"

NewBarkTown_Lab_Text_ShowTogepi2:
	.string "Come? Quel POKéMON!?!$"

NewBarkTown_Lab_Text_ShowTogepi3:
	.string "L'UOVO si è schiuso! Quindi i\n"
	.string "POKéMON nascono dalle UOVA…\p"
	.string "No, forse non tutti i POKéMON\n"
	.string "lo fanno.\p"
	.string "Caspita, c'è ancora tanta\n"
	.string "ricerca da fare.$"

NewBarkTown_Lab_Text_ElmGiveEverstone1:
	.string "Grazie, {PLAYER}! Ci aiuti a\n"
	.string "svelare i misteri dei POKéMON!\p"
	.string "Voglio darti questo come\n"
	.string "segno della nostra gratitudine.$"

NewBarkTown_Lab_Text_ElmGiveEverstone2:
	.string "È una PIETRASTANTE.\p"
	.string "Alcune specie di POKéMON si evolvono\n"
	.string "raggiungendo certi livelli.\p"
	.string "Un POKéMON che tiene la PIETRASTANTE\n"
	.string "non si evolve.\p"
	.string "Dalla a un POKéMON che non\n"
	.string "vuoi far evolvere.$"

NewBarkTown_Lab_Text_ElmCallYou:
	.string "ELM: {PLAYER}, ti chiamo se\n"
	.string "succede qualcosa.$"

NewBarkTown_Lab_Text_AideAfterTheft:
	.string "…sigh… Quel POKéMON rubato.\p"
	.string "Chissà come sta.\p"
	.string "Dicono che un POKéMON cresciuto da\n"
	.string "una persona cattiva diventi cattivo.$"

NewBarkTown_Lab_Text_ElmGiveMasterBall1:
	.string "ELM: Ciao, {PLAYER}!\p"
	.string "Grazie a te, la mia ricerca\n"
	.string "procede bene!\p"
	.string "Prendi questo come segno\n"
	.string "della mia gratitudine.$"

NewBarkTown_Lab_Text_ElmGiveMasterBall2:
	.string "La MASTER BALL è la migliore!\p"
	.string "È la BALL suprema! Cattura\n"
	.string "qualsiasi POKéMON senza fallire.\p"
	.string "Viene data solo ai\n"
	.string "ricercatori POKéMON riconosciuti.\p"
	.string "Penso che tu ne farai un uso\n"
	.string "migliore di me, {PLAYER}!$"

NewBarkTown_Lab_Text_KimonoGirls:
	.string "A proposito...\n"
	.string "Un gruppo di belle RAGAZZE\l"
	.string "KIMONO ti sta cercando.\p"
	.string "Mi hanno detto che ti\n"
	.string "aspettano all'\l" 
	.string "ECRUTEAK DANCE THEATER.\p"
	.string "So che hai passato molte\n"
	.string "cose da quando quell'UOVO ti\l"
	.string "ha coinvolto in tutto questo...\p"
	.string "Spero che arriverai in fondo.$"

NewBarkTown_Lab_Text_KimonoWaiting:
	.string "PROF.ELM: Le RAGAZZE\n"
	.string "KIMONO ti aspettano all'\l"
	.string "ECRUTEAK DANCE THEATER.$"

NewBarkTown_Lab_Text_League:
	.string "PROF.ELM: Ahahah...\n"
	.string "Ben fatto!\p"
	.string "Quell'UOVO raro ti ha dato\n"
	.string "un bel po' di guai, eh?\p"
	.string "Le RAGAZZE KIMONO hanno detto\n"
	.string "qualcosa di me?\p"
	.string "Non c'entro nulla.\p"
	.string "Hai preso una decisione e l'hai\n"
	.string "portata a termine.\p"
	.string "Dopo tutto questo, dovresti\n"
	.string "poter affrontare la LEGA!\p"
	.string "Dovresti andare all'INDIGO\n"
	.string "PLATEAU!\p"
	.string "Sai come arrivarci?\n"
	.string "Segui il PERCORSO 27 fino al 26.\p"
	.string "Una volta lì, vai dritto a nord!$"


NewBarkTown_Lab_Text_ElmGiveTicket1:
	.string "ELM: {PLAYER}! Eccoti!\p"
	.string "Ti ho chiamato perché ho\n"
	.string "una cosa per te.\p"
	.string "Visto? È un BIGLIETTO NAVE.\p"
	.string "Ora puoi catturare POKéMON a\n"
	.string "KANTO.$"

NewBarkTown_Lab_Text_ElmGiveTicket2:
	.string "La nave parte da OLIVINE\n"
	.string "CITY.\p"
	.string "Ma lo sapevi già,\n"
	.string "{PLAYER}.\p"
	.string "Dopotutto hai viaggiato\n"
	.string "ovunque con i tuoi POKéMON.\p"
	.string "Salutami il PROF.OAK a\n"
	.string "KANTO!$"

NewBarkTown_Lab_Text_LabMonEgg:
	.string "È l'UOVO di POKéMON che\n"
	.string "studia il PROF.ELM.$"

NewBarkTown_Lab_Text_AideGivePotion:
	.string "{PLAYER}, voglio che prenda\n"
	.string "questo per la tua commissione.$"

NewBarkTown_Lab_Text_AideAlwaysBusy:
	.string "Siamo solo in tre, quindi\n"
	.string "siamo sempre occupati.$"

NewBarkTown_Lab_Text_AideSave:
	.string "Non dimenticare di salvare\n"
	.string "spesso!\p"
	.string "Premi il pulsante START, poi\n"
	.string "salva la partita!$"

NewBarkTown_Lab_Text_AideTheftTestimony:
	.string "Si è sentito un forte rumore\n"
	.string "fuori…\p"
	.string "Quando siamo andati a vedere,\n"
	.string "qualcuno aveva rubato un POKéMON.\p"
	.string "È incredibile che qualcuno\n"
	.string "faccia una cosa simile!\p"
	.string "…sigh… Quel POKéMON rubato.\p"
	.string "Chissà come sta.\p"
	.string "Dicono che un POKéMON cresciuto da\n"
	.string "una persona cattiva diventi cattivo.$"

NewBarkTown_Lab_Text_AideGiveBalls:
	.string "{PLAYER}!\p"
	.string "Usale per la tua missione\n"
	.string "del POKéDEX!$"

NewBarkTown_Lab_Text_AideExplainBalls:
	.string "Per completare il POKéDEX, devi\n"
	.string "catturare i POKéMON.\p"
	.string "Lancia le POKé BALL contro i\n"
	.string "POKéMON selvatici per prenderli.$"

NewBarkTown_Lab_Text_Officer1:
	.string "Ho saputo che qui è stato\n"
	.string "rubato un POKéMON…\p"
	.string "Stavo solo prendendo\n"
	.string "informazioni dal PROF.ELM.\p"
	.string "Sembra fosse un giovane\n"
	.string "maschio dai lunghi capelli rossi…\p"
	.string "Cosa?\p"
	.string "Hai lottato contro un allenatore\n"
	.string "così?\p"
	.string "Per caso hai preso il suo\n"
	.string "nome?$"

NewBarkTown_Lab_Text_Officer2_1:
	.string "OK! Quindi {RIVAL} era il suo nome?$"

NewBarkTown_Lab_Text_Officer2:
	.string "Grazie per aver aiutato la mia\n"
	.string "indagine!$"

NewBarkTown_Lab_Text_OfficerNo:
	.string "Non avrai preso il suo nome?!$"

NewBarkTown_Lab_Text_Elm_CallMe:
	.string "Ah, {PLAYER}!\p"
	.string "Come va il tuo POKéDEX?\n"
	.string "Ora sono occupato, ma chiamami\l"
	.string "e controllo i tuoi progressi!$"
