RocketHideout_B2F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RocketHideout_B2F_OnLoad
	.byte 0

RocketHideout_B2F_OnLoad::
	call_if_set FLAG_HIDE_ROCKETHIDEOUT2_GATE, RocketHideout_B2F_HideGate
	call_if_eq VAR_MAHOGANY_TOWN_STATE, 13, RocketHideout_B2F_MoveLanceDragonite
	call_if_ge VAR_ELECTRODES_FAINTED, 4, RockerHideout2_DeactivateGenerator
	end

RockerHideout2_DeactivateGenerator::
	setmetatile 13, 8, 0x303, TRUE
	setmetatile 13, 9, 0x303, TRUE
	setmetatile 13, 10, 0x303, TRUE
	setmetatile 13, 11, 0x303, TRUE
	setmetatile 13, 12, 0x303, TRUE
	setmetatile 13, 13, 0x303, TRUE
	setmetatile 13, 14, 0x303, TRUE
	setmetatile 13, 15, 0x303, TRUE

	setmetatile 14, 8, 0x303, TRUE
	setmetatile 14, 9, 0x303, TRUE
	setmetatile 14, 10, 0x303, TRUE
	setmetatile 14, 11, 0x303, TRUE
	setmetatile 14, 12, 0x303, TRUE
	setmetatile 14, 13, 0x303, TRUE
	setmetatile 14, 14, 0x303, TRUE
	setmetatile 14, 15, 0x303, TRUE

	setmetatile 15, 8, 0x303, TRUE
	setmetatile 15, 9, 0x303, TRUE
	setmetatile 15, 10, 0x303, TRUE
	setmetatile 15, 11, 0x303, TRUE
	setmetatile 15, 12, 0x303, TRUE
	setmetatile 15, 13, 0x303, TRUE
	setmetatile 15, 14, 0x303, TRUE
	setmetatile 15, 15, 0x303, TRUE

	setmetatile 16, 8, 0x303, TRUE
	setmetatile 16, 9, 0x303, TRUE
	setmetatile 16, 10, 0x303, TRUE
	setmetatile 16, 11, 0x303, TRUE
	setmetatile 16, 12, 0x303, TRUE
	setmetatile 16, 13, 0x303, TRUE
	setmetatile 16, 14, 0x303, TRUE
	setmetatile 16, 15, 0x303, TRUE

	setmetatile 17, 8, 0x303, TRUE
	setmetatile 17, 9, 0x303, TRUE
	setmetatile 17, 10, 0x303, TRUE
	setmetatile 17, 11, 0x303, TRUE
	setmetatile 17, 12, 0x303, TRUE
	setmetatile 17, 13, 0x303, TRUE
	setmetatile 17, 14, 0x303, TRUE
	setmetatile 17, 15, 0x303, TRUE

	setmetatile 18, 8, 0x303, TRUE
	setmetatile 18, 9, 0x303, TRUE
	setmetatile 18, 10, 0x303, TRUE
	setmetatile 18, 11, 0x303, TRUE
	setmetatile 18, 12, 0x303, TRUE
	setmetatile 18, 13, 0x303, TRUE
	setmetatile 18, 14, 0x303, TRUE
	setmetatile 18, 15, 0x303, TRUE
	return

RocketHideout_B2F_HideGate::
	setmetatile 14, 19, 0x378, FALSE
	setmetatile 14, 20, 0x380, FALSE
	setmetatile 15, 19, 0x379, FALSE
	setmetatile 15, 20, 0x379, FALSE
	setmetatile 16, 19, 0x379, FALSE
	setmetatile 16, 20, 0x379, FALSE
	return

RocketHideout_B2F_MoveLanceDragonite::
	setobjectxyperm LOCALID_ROCKETHIDEOUT2_DRAGONITE, 20, 16
	setobjectxyperm LOCALID_ROCKETHIDEOUT2_LANCE, 19, 16
	setobjectmovementtype LOCALID_ROCKETHIDEOUT2_DRAGONITE, MOVEMENT_TYPE_WALK_IN_PLACE_UP
	setobjectmovementtype LOCALID_ROCKETHIDEOUT2_LANCE, MOVEMENT_TYPE_FACE_UP
	return

RocketHideout_B2F_Trigger_MurkrowStairs::
	lock
	applymovement LOCALID_ROCKETHIDEOUT2_MURKROWSTAIRS, RocketHideout_B2F_Movement_MurkrowStairs1
	waitmovement 0
	playmoncry SPECIES_MURKROW, CRY_MODE_NORMAL
	msgbox RocketHideout_B3F_Text_MurkrowSpeak1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT2_MURKROWSTAIRS, RocketHideout_B2F_Movement_MurkrowStairs2
	waitmovement 0
	setflag FLAG_HIDE_ROCKETHIDEOUT2_MURKROWSTAIRS
	removeobject LOCALID_ROCKETHIDEOUT2_MURKROWSTAIRS
	clearflag FLAG_HIDE_ROCKETHIDEOUT3_MURKROWSTAIRS
	setvar VAR_MAHOGANY_TOWN_STATE, 10
	release
	end

RocketHideout_B2F_Movement_MurkrowStairs1:
	jump_in_place_left
	jump_in_place_left
	step_end

RocketHideout_B2F_Movement_MurkrowStairs2:
	jump_in_place_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

RocketHideout_B2F_Trigger_MurkrowGate::
	lock
	applymovement LOCALID_ROCKETHIDEOUT2_MURKROWGATE, RocketHideout_B2F_Movement_MurkrowGate1
	waitmovement 0
	playmoncry SPECIES_MURKROW, CRY_MODE_NORMAL
	msgbox RocketHideout_B3F_Text_Murkrow, MSGBOX_DEFAULT
	msgbox RocketHideout_B2F_Text_MurkrowUnlock, MSGBOX_DEFAULT
	playse SE_CLICK
	setmetatile 14, 19, 0x378, FALSE
	setmetatile 14, 20, 0x380, FALSE
	setmetatile 15, 19, 0x379, FALSE
	setmetatile 15, 20, 0x379, FALSE
	setmetatile 16, 19, 0x379, FALSE
	setmetatile 16, 20, 0x379, FALSE
	special DrawWholeMapView
	setflag FLAG_HIDE_ROCKETHIDEOUT2_GATE
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT2_MURKROWGATE, RocketHideout_B2F_Movement_MurkrowGate2
	waitmovement 0
	setflag FLAG_HIDE_ROCKETHIDEOUT2_MURKROWGATE
	removeobject LOCALID_ROCKETHIDEOUT2_MURKROWGATE
	setvar VAR_MAHOGANY_TOWN_STATE, 12
	release
	end
RocketHideout_B2F_Movement_MurkrowGate1:
	jump_in_place_up
	jump_in_place_up
	step_end

RocketHideout_B2F_Movement_MurkrowGate2:
	jump_in_place_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

RocketHideout_B2F_Text_MurkrowUnlock:
    .string "MURKROW ha gridato la password,\n"
    .string "imitando la voce di PETREL.\p"
    .string "..................\n"
    .string "Il sistema di riconoscimento vocale\l"
    .string "ha aperto la porta!$"

@============================================================================================================================================

RocketHideout_B2F_Trigger_PlayerMoveLeft::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	return
RocketHideout_B2F_Trigger_PlayerMoveRight::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	return

RocketHideout_B2F_Trigger_Ariana::
	lock 
	setobjectxyperm LOCALID_ROCKETHIDEOUT2_LANCE, 6, 26
	setobjectxyperm LOCALID_ROCKETHIDEOUT2_DRAGONITE, 5, 26
	clearflag FLAG_HIDE_ROCKETHIDEOUT2_ARIANA_AND_GRUNT
	addobject LOCALID_ROCKETHIDEOUT2_ARIANA
	addobject LOCALID_ROCKETHIDEOUT2_GRUNT
	delay 20
	msgbox RocketHideout_B2F_Text_ArianaHoldIt, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 14, RocketHideout_B2F_Trigger_PlayerMoveLeft
	call_if_eq VAR_TEMP_0, 16, 	RocketHideout_B2F_Trigger_PlayerMoveRight
	applymovement OBJ_EVENT_ID_PLAYER, RocketHideout_B2F_Movement_PlayerMeetAriana
	applymovement LOCALID_ROCKETHIDEOUT2_ARIANA, RocketHideout_B2F_Movement_Ariana
	delay 20
	applymovement LOCALID_ROCKETHIDEOUT2_GRUNT, RocketHideout_B2F_Movement_Ariana
	waitmovement LOCALID_ROCKETHIDEOUT2_GRUNT
	msgbox RocketHideout_B2F_Text_ArianaChallenge, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_ROCKETHIDEOUT2_LANCE_DRAGONITE
	addobject LOCALID_ROCKETHIDEOUT2_LANCE
	addobject LOCALID_ROCKETHIDEOUT2_DRAGONITE
	applymovement LOCALID_ROCKETHIDEOUT2_LANCE, RocketHideout_B2F_Movement_Lance
	delay 20
	applymovement LOCALID_ROCKETHIDEOUT2_DRAGONITE, RocketHideout_B2F_Movement_Lance
	waitmovement 0
	msgbox RocketHideout_B2F_Text_LanceInterrupt, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT2_ARIANA, Common_Movement_WalkInPlaceFasterUp
	msgbox RocketHideout_B2F_Text_ArianaOutraged
	closemessage
	goto RocketHideout_B2F_EventScript_ReadyForBattlePrompt
	end
	
RocketHideout_B2F_Movement_PlayerMeetAriana:
	walk_down
	walk_down
	walk_down
	step_end

RocketHideout_B2F_Movement_Ariana:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

RocketHideout_B2F_Movement_Lance:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

RocketHideout_B2F_Text_ArianaHoldIt:
    .string "ARIANA: Fermo lì!$"

RocketHideout_B2F_Text_ArianaChallenge:
    .string "ARIANA: Non possiamo lasciare che una\n"
    .string "peste come te faccia il comodo suo.\p"
    .string "Ferirebbe l'orgoglio del Team Rocket\n"
    .string "ancora e ancora. Facendolo scemare,\l"
    .string "capisci.\p"
    .string "...Quindi è ora di farti fuori.\n"
    .string "Per quanto tu sia forte,\p"
    .string "se ci battiamo in due\n"
    .string "contemporaneamente, non avrai\l"
    .string "speranze. Non credi?\p"
    .string "Ih ih ih! Mi spiace, tesoro.\n"
    .string "Ora preparati a prendere il resto.$"

RocketHideout_B2F_Text_LanceInterrupt:
    .string "LANCE: Fermo!\n"
    .string "Una lotta due contro uno?\p"
    .string "È troppo sleale!\n"
    .string "Tipico del Team Rocket essere\l"
    .string "subdoli.\p"
    .string "Permettimi di unirmi alla lotta!$"

RocketHideout_B2F_Text_ArianaOutraged:
    .string "ARIANA: Come? Hai un complice?\n"
    .string "Dov'è il tuo senso dell'onore?\p"
    .string "Da capo ad interim al posto di GIOVANNI,\n"
    .string "ti mostrerò quanto sia sbagliato\l"
    .string "impicciarsi del Team Rocket!$"

RocketHideout_B2F_Text_LanceChooseMons:
    .string "LANCE: Presto {PLAYER}, scegli\n"
	.string "i tuoi POKéMON!$"

RocketHideout_B2F_EventScript_ReadyForBattlePrompt::
	msgbox RocketHideout_B2F_Text_LanceChooseMons, MSGBOX_DEFAULT
	goto RocketHideout_B2F_EventScript_ChoosePartyForMultiBattle
	end

RocketHideout_B2F_EventScript_ChoosePartyForMultiBattle::
	setflag FLAG_ROCKETHIDEOUT2_BATTLE
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_ne VAR_RESULT, 0, RocketHideout_B2F_EventScript_DoLanceMultiBattle
	special LoadPlayerParty
	goto RocketHideout_B2F_EventScript_ReadyForBattlePrompt

RocketHideout_B2F_EventScript_DoLanceMultiBattle::
	@ special ReducePlayerPartyToSelectedMons
	@ frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	@ setvar VAR_0x8004, SPECIAL_BATTLE_LANCE
	@ setvar VAR_0x8005, 0
	applymovement LOCALID_ROCKETHIDEOUT2_ARIANA, Common_Movement_WalkUp1
	applymovement LOCALID_ROCKETHIDEOUT2_GRUNT, Common_Movement_WalkUp1
	waitmovement 0
	turnobject LOCALID_ROCKETHIDEOUT2_GRUNT, DIR_WEST
	multi_2_vs_2 TRAINER_ARIANA_1_HNS, Debug_Text_ArianaDefeat, TRAINER_GRUNT_23_HNS, Debug_Text_Grunt23Defeat, PARTNER_LANCE_HNS
	@ special DoSpecialTrainerBattle
	@ waitstate
	@ frontier_saveparty
	@ special LoadPlayerParty
	switch VAR_RESULT
	case 1, RocketHideout_B2F_EventScript_DefeatedAriana
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_ROCKETHIDEOUT2_LANCE_DRAGONITE
	setflag FLAG_HIDE_ROCKETHIDEOUT2_ARIANA_AND_GRUNT
	special SetCB2WhiteOut
	waitstate

RocketHideout_B2F_EventScript_DefeatedAriana::
	clearflag FLAG_ROCKETHIDEOUT2_BATTLE
	msgbox RocketHideout_Text_ArianaRetreat, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	applymovement LOCALID_ROCKETHIDEOUT2_LANCE, Common_Movement_WalkUp1
	applymovement LOCALID_ROCKETHIDEOUT2_DRAGONITE, Common_Movement_WalkUp1
	waitmovement 0
	applymovement LOCALID_ROCKETHIDEOUT2_LANCE, Common_Movement_WalkRight1
	applymovement LOCALID_ROCKETHIDEOUT2_DRAGONITE, Common_Movement_WalkRight1
	waitmovement 0
	setflag FLAG_HIDE_MAHOGANY_ROCKETS
	setflag FLAG_HIDE_ROCKETHIDEOUT2_ARIANA_AND_GRUNT
	removeobject LOCALID_ROCKETHIDEOUT2_ARIANA
	removeobject LOCALID_ROCKETHIDEOUT2_GRUNT
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox RocketHideout_Text_LanceStepBack, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT2_LANCE, RocketHideout_B2F_Movement_LanceWalkToGenerator
	applymovement LOCALID_ROCKETHIDEOUT2_DRAGONITE, RocketHideout_B2F_Movement_DragoniteWalkToGenerator
	delay 55
	applymovement OBJ_EVENT_ID_PLAYER, RocketHideout_B2F_Movement_LanceWalkToGenerator
	waitmovement 0

	applymovement LOCALID_ROCKETHIDEOUT2_DRAGONITE, RocketHideout_B2F_Movement_DragoniteInvestigateGenerator
	applymovement LOCALID_ROCKETHIDEOUT2_LANCE, RocketHideout_B2F_Movement_LanceInvestigateGenerator
	delay 165
	playmoncry SPECIES_DRAGONITE, CRY_MODE_NORMAL
	waitmovement LOCALID_ROCKETHIDEOUT2_DRAGONITE
	waitmovement LOCALID_ROCKETHIDEOUT2_LANCE
	msgbox RocketHideout_B2F_Text_LanceElectrodeFaint, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT2_LANCE, RocketHideout_B2F_Movement_LanceWalkToElectrode
	applymovement LOCALID_ROCKETHIDEOUT2_DRAGONITE, RocketHideout_B2F_Movement_LanceWalkToElectrode
	waitmovement LOCALID_ROCKETHIDEOUT2_DRAGONITE
	waitmovement LOCALID_ROCKETHIDEOUT2_LANCE
	applymovement OBJ_EVENT_ID_PLAYER, RocketHideout_B2F_Movement_PlayerWalkToElectrode
	waitmovement 0
	setobjectxyperm LOCALID_ROCKETHIDEOUT2_DRAGONITE, 20, 16
	setobjectxyperm LOCALID_ROCKETHIDEOUT2_LANCE, 19, 16
	setobjectmovementtype LOCALID_ROCKETHIDEOUT2_DRAGONITE, MOVEMENT_TYPE_WALK_IN_PLACE_UP
	setobjectmovementtype LOCALID_ROCKETHIDEOUT2_LANCE, MOVEMENT_TYPE_FACE_UP
	setvar VAR_MAHOGANY_TOWN_STATE, 13
	release
	end

RocketHideout_B2F_Movement_LanceWalkToGenerator:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
	
RocketHideout_B2F_Movement_DragoniteWalkToGenerator:
	delay_8
	delay_8
	walk_right
	walk_up
	walk_up
	walk_up
	step_end


RocketHideout_B2F_Movement_LanceInvestigateGenerator:
	walk_up
	walk_left
	face_up
	delay_8
	delay_8
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	delay_8
	delay_8
	face_right
	delay_8
	delay_8
	delay_8
	delay_8
	walk_left
	walk_left
	walk_left
	face_down
	step_end

RocketHideout_B2F_Movement_DragoniteInvestigateGenerator:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_left
	delay_16
	delay_16
	delay_8
	delay_8	
	delay_8
	delay_8
	walk_left
	walk_left
	walk_left
	step_end

RocketHideout_B2F_Movement_LanceWalkToElectrode:
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

RocketHideout_B2F_Movement_PlayerWalkToElectrode:
	walk_left
	walk_left
	walk_left
	step_end

RocketHideout_B2F_Trigger_Electrode::
	lock
	goto_if_eq VAR_ELECTRODES_FAINTED, 3, RocketHideout_B2F_EventScript_ElectrodeDone
	turnobject LOCALID_ROCKETHIDEOUT2_LANCE, DIR_WEST
	msgbox RocketHideout_B2F_Text_LanceSide, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROCKETHIDEOUT2_LANCE, DIR_NORTH
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	release
	end

RocketHideout_B2F_EventScript_Electrode::
	lock
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_ELECTRODE, 30
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, RocketHideout_B2F_EventScript_Ran_Electrode
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, RocketHideout_B2F_EventScript_Ran_Electrode
	removeobject VAR_LAST_TALKED
	addvar VAR_ELECTRODES_FAINTED, 1
	release
	end

RocketHideout_B2F_EventScript_Ran_Electrode::
	release
	end

RocketHideout_B2F_EventScript_ElectrodeDone::
	playse SE_M_HYPER_BEAM
	removeobject LOCALID_LANCEELECTRODE1
	removeobject LOCALID_LANCEELECTRODE2
	removeobject LOCALID_LANCEELECTRODE3
	waitse
	getplayerxy VAR_TEMP_0, VAR_TEMP_1 
	call_if_eq VAR_TEMP_1, 16, RocketHideout_B2F_Movement_PlayerMeetLanceTop
	call_if_eq VAR_TEMP_1, 18, RocketHideout_B2F_Movement_PlayerMeetLanceBot
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	applymovement LOCALID_ROCKETHIDEOUT2_LANCE, RocketHideout_B2F_Movement_LanceMeetPlayerAfterElectrode
	applymovement LOCALID_ROCKETHIDEOUT2_DRAGONITE, RocketHideout_B2F_Movement_LanceMeetPlayerAfterElectrode
	waitmovement LOCALID_ROCKETHIDEOUT2_DRAGONITE

	playse SE_CLICK
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	turnobject LOCALID_ROCKETHIDEOUT2_LANCE, DIR_NORTH
	call RockerHideout2_DeactivateGenerator
	special DrawWholeMapView
	delay 55
	turnobject LOCALID_ROCKETHIDEOUT2_LANCE DIR_WEST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 30
	msgbox RocketHideout_B2F_Text_LanceElectrodeDone, MSGBOX_DEFAULT
	giveitem ITEM_HM_WHIRLPOOL
	msgbox RocketHideout_B2F_Text_LanceWhirlpool, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROCKETHIDEOUT2_LANCE, DIR_SOUTH
	delay 20
	msgbox RocketHideout_B2F_Text_LanceMonMaster, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT2_LANCE, RocketHideout_B2F_Movement_LanceFinalExit
	delay 20

	applymovement LOCALID_ROCKETHIDEOUT2_DRAGONITE, RocketHideout_B2F_Movement_DragoniteFinalExit
	waitmovement LOCALID_ROCKETHIDEOUT2_DRAGONITE
	waitmovement LOCALID_ROCKETHIDEOUT2_LANCE

	setflag FLAG_HIDE_ROCKETHIDEOUT2_LANCE_DRAGONITE
	removeobject LOCALID_ROCKETHIDEOUT2_DRAGONITE
	removeobject LOCALID_ROCKETHIDEOUT2_LANCE
	setvar VAR_ELECTRODES_FAINTED, 4
	setvar VAR_MAHOGANY_TOWN_STATE, 14
	clearflag FLAG_HIDE_MAHOGANY_COP
	setflag FLAG_HIDE_MAHOGANY_TOWN_FATMAN
	setvar VAR_ROCKET_HIDEOUT_STATUE_1, 2
	setvar VAR_ROCKET_HIDEOUT_STATUE_2, 2
	setvar VAR_ROCKET_HIDEOUT_STATUE_3, 2
	setvar VAR_ROCKET_HIDEOUT_STATUE_4, 2
	setvar VAR_ROCKET_HIDEOUT_STATUE_5, 2
	release
	end

RocketHideout_B2F_Movement_PlayerMeetLanceTop:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	return

RocketHideout_B2F_Movement_PlayerMeetLanceBot:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	return

RocketHideout_B2F_Movement_LanceMeetPlayerAfterElectrode:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RocketHideout_B2F_Movement_LanceFinalExit:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

RocketHideout_B2F_Movement_DragoniteFinalExit:
	walk_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

RocketHideout_B2F_Text_GruntLoss:
    .string "....................$"

RocketHideout_B2F_Text_ArianaLoss:
    .string "Tch, sei davvero forte.\n"
    .string "Peccato.\p"
    .string "Se entrassi nel Team Rocket,\n"
    .string "potresti diventare un Dirigente.$"

RocketHideout_Text_ArianaRetreat:
    .string "ARIANA: Ma va bene.\n"
    .string "L'esperimento di trasmissione è stato\l"
    .string "un successo totale.\p"
    .string "Non importa cosa succede a\n"
    .string "questo covo ora.\p"
    .string "Abbiamo piani molto più grandi.\n"
    .string "Imparerai presto ad apprezzare il vero\l"
    .string "potere del Team Rocket.\p"
    .string "Divertiti finché puoi…\n"
    .string "Hee hee hee…$"

RocketHideout_Text_LanceStepBack:
    .string "Scusa, {PLAYER}. Vedevo come te la\n"
    .string "cavavi, così sono rimasto indietro.\p"
    .string "Ora resta solo da spegnere\n"
    .string "quel segnale radio strano.$"


RocketHideout_B2F_Text_LanceElectrodeFaint:
    .string "È questa macchina che causa\n"
    .string "tutti i problemi.\p"
    .string "Non vedo un interruttore…\p"
    .string "Non abbiamo scelta. Dobbiamo\n"
    .string "far svenire tutti gli ELECTRODE.\p"
    .string "Così la macchina smetterà\n"
    .string "di trasmettere quello strano\l"
    .string "segnale.\p"
    .string "Non è colpa dei POKéMON, quindi\n"
    .string "mi sento in colpa.\p"
    .string "{PLAYER}, dividiamoci il lavoro.$"

RocketHideout_B2F_Text_LanceSide:
    .string "LANCE: Lascia questo lato a me.$"

RocketHideout_B2F_Text_LanceElectrodeDone:
    .string "LANCE: That odd signal has\n"
    .string "finally stopped.\p"
    .string "The LAKE should be back to\n"
    .string "normal.\p"
    .string "You're the hero! Let me thank\n"
    .string "you on behalf of all the\l"
    .string "POKéMON.\p"
    .string "Oh, yes. You should take this.\n"
    .string "I found it here, but I don't\l"
    .string "have any need for it.$"

RocketHideout_B2F_Text_LanceWhirlpool:
    .string "Quello è MULINELLO. Insegnalo a un\n"
    .string "POKéMON per attraversare le acque.\p"
    .string "Ma ricorda una cosa.\p"
    .string "Puoi usarlo fuori dalla lotta\n"
    .string "solo con la MEDAGLIA della\l"
    .string "PALESTRA di MAHOGANY.$"

RocketHideout_B2F_Text_LanceMonMaster:
    .string "{PLAYER}…\p"
    .string "Il cammino per diventare\n"
    .string "MAESTRO POKéMON è lungo e\l"
    .string "difficile.\p"
    .string "Sapendolo, continuerai\n"
    .string "ad andare avanti?\p"
    .string "…\p"
    .string "Capisco. No, hai ragione.\p"
    .string "Se ti arrendessi così facilmente,\n"
    .string "non avresti mai inseguito quel\l"
    .string "sogno fin dall'inizio.\p"
    .string "Non vedo l'ora di rivederti\n"
    .string "ancora!$"

RocketHideout_B2F_Text_B2FTransmitter:
    .string "È la radio trasmittente che invia\n"
    .string "il segnale sinistro.\p"
    .string "Sta funzionando a pieno regime.$"

RocketHideout_B2F_Text_B2FDeactivateTransmitter:
    .string "La radio trasmittente ha finalmente\n"
    .string "interrotto la sua trasmissione malefica.$"


@===========================================================================================================================================

RocketHideout_EventScript_Item_Thief::
	finditem ITEM_TM_THIEF
	end

RocketHideout_B2F_EventScript_LanceTriggerLeft::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	goto RocketHideout_B2F_EventScript_Lance

RocketHideout_B2F_EventScript_LanceTriggerRight::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	goto RocketHideout_B2F_EventScript_Lance

RocketHideout_B2F_EventScript_Lance::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	msgbox RocketHideout_B2F_Text_LanceHeals1, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox RocketHideout_B2F_Text_LanceHeals2, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_ROCKETHIDEOUT2_LANCE, RocketHideout_B2F_Movement_LanceGoDeeper
	applymovement2 LOCALID_ROCKETHIDEOUT2_DRAGONITE, RocketHideout_B2F_Movement_DragoniteGoDeeper
	waitmovement LOCALID_ROCKETHIDEOUT2_LANCE
	waitmovement LOCALID_ROCKETHIDEOUT2_DRAGONITE
	setflag FLAG_HIDE_ROCKETHIDEOUT2_LANCE_DRAGONITE
	removeobject LOCALID_ROCKETHIDEOUT2_LANCE
	setvar VAR_MAHOGANY_TOWN_STATE, 6
	removeobject LOCALID_ROCKETHIDEOUT2_DRAGONITE
	release
	end

RocketHideout_B2F_Movement_LanceGoDeeper:
	walk_right
	walk_right
	delay_2
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RocketHideout_B2F_Movement_DragoniteGoDeeper:
	delay_8
	delay_8
	delay_8
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

RocketHideout_B2F_Text_LanceHeals1:
    .string "LANCE: Stai bene?\p"
    .string "I tuoi POKéMON sono feriti e stanchi.\p"
    .string "Tieni, dagli un po' della mia\n"
    .string "medicina.$"

RocketHideout_B2F_Text_LanceHeals2:
    .string "LANCE: {PLAYER}, diamo il\n"
    .string "massimo per i POKéMON.$"

RocketHideout_B2F_Text_GruntM17Seen:
    .string "La porta non si apre?\p"
    .string "Beh, ovvio. Serve una\n"
    .string "password che conosce solo il\l"
    .string "TEAM ROCKET.$"

RocketHideout_B2F_Text_GruntM17Beaten:
    .string "Cosa? Ho perso?$"

RocketHideout_B2F_Text_GruntM17After:
    .string "Heh, sono solo una RECLUTA.\p"
    .string "Non conosco la password.\n"
    .string "Peccato per te.$"

RocketHideout_B2F_EventScript_Grunt14::
	trainerbattle_single TRAINER_GRUNT_14_HNS, RocketHideout_B2F_Text_GruntM17Seen, RocketHideout_B2F_Text_GruntM17Beaten
	msgbox RocketHideout_B2F_Text_GruntM17After, MSGBOX_AUTOCLOSE
	end

RocketHideout_B2F_Text_GruntM18Seen:
    .string "Oh, un bambino? Non mi piace\n"
    .string "granché, ma devo eliminarti.$"

RocketHideout_B2F_Text_GruntM18Beaten:
    .string "Sapevo che avrei perso…$"

RocketHideout_B2F_Text_GruntM18After:
    .string "Anche l'ultima missione\n"
    .string "mi ha distrutto un bambino.\p"
    .string "Mentre rapivamo POKéMON,\n"
    .string "un bimbo con lunghi capelli rossi\l"
    .string "e occhi cattivi mi ha\l"
    .string "annientato…$"

RocketHideout_B2F_EventScript_Grunt15::
	trainerbattle_single TRAINER_GRUNT_15_HNS, RocketHideout_B2F_Text_GruntM18Seen, RocketHideout_B2F_Text_GruntM18Beaten
	msgbox RocketHideout_B2F_Text_GruntM18After, MSGBOX_AUTOCLOSE
	end

RocketHideout_B2F_Text_GruntM19Seen:
    .string "Piccolo parassita!$"

RocketHideout_B2F_Text_GruntM19Beaten:
    .string "Grrrr…$"

RocketHideout_B2F_Text_GruntM19After:
    .string "Heh, solo il capo conosce la\n"
    .string "password di quella porta.\p"
    .string "Dov'è il capo? Chissà?\n"
    .string "Vai a cercarlo da solo.$"

RocketHideout_B2F_EventScript_Grunt16::
	trainerbattle_single TRAINER_GRUNT_16_HNS, RocketHideout_B2F_Text_GruntM19Seen, RocketHideout_B2F_Text_GruntM19Beaten
	msgbox RocketHideout_B2F_Text_GruntM19After, MSGBOX_AUTOCLOSE
	end

