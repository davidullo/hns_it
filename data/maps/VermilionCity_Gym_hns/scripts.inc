.set FOUND_FIRST_SWITCH, FLAG_TEMP_1
.set SWITCH1_ID,         VAR_0x8004
.set SWITCH2_ID,         VAR_0x8005
.set TRASH_CAN_ID,       VAR_0x8008

.set CHECK_VISITOR_STATE, 6
.set TYPE, VAR_0x8003
.set ARGUMENT, VAR_0x8004

VermilionCity_Gym_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VermilionCity_Gym_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_Gym_OnTransition
	.byte 0

VermilionCity_Gym_OnLoad::
	call_if_set FOUND_FIRST_SWITCH, VermilionCity_Gym_EventScript_SetOneBeamOff
	call_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_SetBeamsOff
	end

VermilionCity_Gym_EventScript_SetOneBeamOff::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_HalfOn, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_HalfOn, 1
	setmetatile 5, 6, METATILE_VermilionGym_Beam_MidTop_HalfOn, 1
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_HalfOn, 1
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_HalfOn, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_HalfOn, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_HalfOn, 1
	setmetatile 5, 7, METATILE_VermilionGym_Beam_MidBottom_HalfOn, 1
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_HalfOn, 1
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_HalfOn, 1
	return

VermilionCity_Gym_EventScript_SetBeamsOff::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Off, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_Off, 0
	setmetatile 5, 6, METATILE_VermilionGym_Floor, 0
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_Off, 0
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_Off, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Off, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_Off, 0
	setmetatile 5, 7, METATILE_VermilionGym_Floor, 0
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_Off, 0
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Off, 1
	return

VermilionCity_Gym_OnTransition::
	call VermilionCity_Gym_EventScript_InitTrashCans
	end

VermilionCity_Gym_EventScript_InitTrashCans::
	goto_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_Return
	special SetVermilionTrashCans
	copyvar VAR_TEMP_0, SWITCH1_ID
	copyvar VAR_TEMP_1, SWITCH2_ID
	return

VermilionCity_Gym_EventScript_Return::
	end

VermilionCity_Gym_EventScript_TrashCan1::
	lockall
	setvar TRASH_CAN_ID, 1
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan2::
	lockall
	setvar TRASH_CAN_ID, 2
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan3::
	lockall
	setvar TRASH_CAN_ID, 3
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan4::
	lockall
	setvar TRASH_CAN_ID, 4
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan5::
	lockall
	setvar TRASH_CAN_ID, 5
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan6::
	lockall
	setvar TRASH_CAN_ID, 6
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan7::
	lockall
	setvar TRASH_CAN_ID, 7
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan8::
	lockall
	setvar TRASH_CAN_ID, 8
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan9::
	lockall
	setvar TRASH_CAN_ID, 9
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan10::
	lockall
	setvar TRASH_CAN_ID, 10
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan11::
	lockall
	setvar TRASH_CAN_ID, 11
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan12::
	lockall
	setvar TRASH_CAN_ID, 12
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan13::
	lockall
	setvar TRASH_CAN_ID, 13
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan14::
	lockall
	setvar TRASH_CAN_ID, 14
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan15::
	lockall
	setvar TRASH_CAN_ID, 15
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan::
	copyvar SWITCH1_ID, VAR_TEMP_0
	copyvar SWITCH2_ID, VAR_TEMP_1
	goto_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_LocksAlreadyOpen
	goto_if_set FOUND_FIRST_SWITCH, VermilionCity_Gym_EventScript_TrySwitchTwo
	goto_if_eq SWITCH1_ID, TRASH_CAN_ID, VermilionCity_Gym_EventScript_FoundSwitchOne
	msgbox VermilionCity_Gym_Text_NopeOnlyTrashHere
	releaseall
	end

VermilionCity_Gym_EventScript_FoundSwitchOne::
	msgbox VermilionCity_Gym_Text_SwitchUnderTrashFirstLockOpened
	playse SE_PIN
	waitse
	call VermilionCity_Gym_EventScript_SetOneBeamOff
	special DrawWholeMapView
	setflag FOUND_FIRST_SWITCH
	releaseall
	end

VermilionCity_Gym_EventScript_TrySwitchTwo::
	goto_if_eq SWITCH2_ID, TRASH_CAN_ID, VermilionCity_Gym_EventScript_FoundSwitchTwo
	msgbox VermilionCity_Gym_Text_OnlyTrashLocksWereReset
	clearflag FOUND_FIRST_SWITCH
	special SetVermilionTrashCans
	copyvar VAR_TEMP_0, SWITCH1_ID
	copyvar VAR_TEMP_1, SWITCH2_ID
	call VermilionCity_Gym_EventScript_SetBeamsOn
	special DrawWholeMapView
	releaseall
	end

VermilionCity_Gym_EventScript_FoundSwitchTwo::
	msgbox VermilionCity_Gym_Text_SecondLockOpened
	closemessage
	call VermilionCity_Gym_EventScript_SetBeamsOff
	special DrawWholeMapView
	playse SE_UNLOCK
	waitse
	setflag FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES
	releaseall
	end

VermilionCity_Gym_EventScript_LocksAlreadyOpen::
	msgbox VermilionCity_Gym_Text_NopeOnlyTrashHere
	releaseall
	end

VermilionCity_Gym_EventScript_SetBeamsOn::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_On, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_On, 1
	setmetatile 5, 6, METATILE_VermilionGym_Beam_MidTop, 1
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_On, 1
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_On, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_On, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_On, 1
	setmetatile 5, 7, METATILE_VermilionGym_Beam_MidBottom, 1
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_On, 1
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_On, 1
	return

VermilionCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VERMILION_GYM, VermilionCity_Gym_EventScript_GymGuyPostVictory
	msgbox VermilionCity_Gym_Text_GymGuyAdvice
	release
	end

VermilionCity_Gym_EventScript_GymGuyPostVictory::
	msgbox VermilionCity_Gym_Text_GymGuyPostVictory
	release
	end

VermilionCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE11_GET, VermilionCity_Gym_EventScript_GymStatuePostVictory
	msgbox VermilionCity_Gym_Text_GymStatue
	releaseall
	end

VermilionCity_Gym_EventScript_GymStatuePostVictory::
	msgbox VermilionCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

VermilionCity_Gym_EventScript_Gregory::
	trainerbattle_single TRAINER_GREGORY_HNS, VermilionGym_Text_GentlemanGregorySeen, VermilionGym_Text_GentlemanGregoryBeaten
	msgbox VermilionGym_Text_GentlemanGregoryAfter, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_Vincent::
	trainerbattle_single TRAINER_VINCENT_HNS, VermilionGym_Text_GuitaristVincentSeen, VermilionGym_Text_GuitaristVincentBeaten
	msgbox VermilionGym_Text_GuitaristVincentAfter, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_Horton::
	trainerbattle_single TRAINER_HORTON_HNS, VermilionGym_Text_JugglerHortonSeen, VermilionGym_Text_JugglerHortonBeaten
	msgbox VermilionGym_Text_JugglerHortonAfter, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_Surge::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VERMILION_GYM, VermilionCity_Gym_EventScript_Surge_Defeated
	msgbox VermilionGym_Text_LtSurgeIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LTSURGE_HNS, VermilionGym_Text_LtSurgeWinLoss
	message VermilionGym_Text_ReceivedThunderBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox VermilionGym_Text_ThunderBadgeInfo, MSGBOX_DEFAULT
	setflag FLAG_BADGE11_GET
	setflag FLAG_DEFEATED_VERMILION_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 11
	call Common_EventScript_SetGymTrainers_hns
	checkitem ITEM_TM_SHOCK_WAVE
	call_if_eq VAR_RESULT, TRUE, VermilionCity_Gym_EventScript_GiveThunderstone
	call_if_eq VAR_RESULT, FALSE, VermilionCity_Gym_EventScript_GiveTM
	clearflag FLAG_HIDE_PLANT_SURGE
	closemessage
	release
	end

VermilionCity_Gym_EventScript_GiveThunderstone::
	msgbox VermilionGym_Text_LtSurgeThunderstone, MSGBOX_DEFAULT
	giveitem ITEM_THUNDER_STONE
	return

VermilionCity_Gym_EventScript_GiveTM::
	msgbox VermilionGym_Text_LtSurge_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_SHOCK_WAVE
	msgbox VermilionGym_Text_LtSurge_ExplainTM, MSGBOX_DEFAULT
	return

VermilionCity_Gym_EventScript_Surge_Defeated::
	msgbox VermilionGym_Text_LtSurgePostBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionGym_Text_LtSurgeIntro:
	.string "SURGE: Ehi, monello!\p"
	.string "Devo ammetterlo.\n"
	.string "Non è molto intelligente\l"
	.string "sfidarmi, ma ci vuole fegato!\p"
	.string "Quando si tratta di POKéMON\n"
	.string "elettrici, sono il numero uno!\p"
	.string "Non ho mai perso sul\n"
	.string "campo di battaglia.\p"
	.string "Ti fulmino come i nemici\n"
	.string "in guerra!$"

VermilionGym_Text_LtSurgeWinLoss:
	.string "SURGE: Arrrgh! Sei forte!\p"
	.string "OK, ragazzo. Ti prendi la THUNDERBADGE!$"

VermilionGym_Text_ReceivedThunderBadge:
	.string "{PLAYER} riceve la THUNDERBADGE.$"

VermilionGym_Text_ThunderBadgeInfo:
	.string "SURGE: la THUNDERBADGE aumenta\n"
	.string "la velocità dei POKéMON.\p"
	.string "Considerala la prova che\n"
	.string "mi hai battuto.\p"
	.string "Portala con orgoglio, capito?$"

VermilionGym_Text_LtSurge_GiveTM:
	.string "E prendi questa MT. Mi è servita\n"
	.string "in guerra!$"

VermilionGym_Text_LtSurge_ExplainTM:
	.string "È SHOCK WAVE.\p"
	.string "Una mossa incredibilmente precisa\n"
	.string "che colpisce sempre!$"

VermilionGym_Text_LtSurgeThunderstone:
	.string "E prendi questa pietra. Ha un vero\n"
	.string "potere di tuono!$"


VermilionGym_Text_LtSurgePostBattle:
	.string "SURGE: Ehi, ragazzo! Dai dentro\n"
	.string "come un dannato?\p"
	.string "Io e i miei POKéMON non molliamo!$"

VermilionGym_Text_SurgeRematch:
	.string "SURGE: Allora sei il CAMPIONE\n"
	.string "di KANTO!\p"
	.string "Bel lavoro, ragazzo!\n"
	.string "Ma non credere che abbia finito!\p"
	.string "Che ne dici di rifarlo?$"

VermilionGym_Text_SurgeRematchDefeat:
	.string "SURGE: Arrrgh! Sei forte\n"
	.string "come sempre!$"

VermilionGym_Text_GentlemanGregorySeen:
	.string "Vuoi battere LT.SURGE?\p"
	.string "Non se posso evitarlo!$"

VermilionGym_Text_GentlemanGregoryBeaten:
	.string "Scusi se l'ho delusa,\n"
	.string "LT.SURGE, signore!$"

VermilionGym_Text_GentlemanGregoryAfter:
	.string "Quando ero ancora nell'esercito,\n"
	.string "LT.SURGE mi salvò la vita.$"

VermilionGym_Text_GuitaristVincentSeen:
	.string "LT.SURGE ha riconosciuto il mio\n"
	.string "talento con i POKéMON elettrici.\p"
	.string "Credi di poterci battere?$"

VermilionGym_Text_GuitaristVincentBeaten:
	.string "Ooh, che shock!$"

VermilionGym_Text_GuitaristVincentAfter:
	.string "Mom told me not to quit my\n"
	.string "day job, but what am I supposed\l"
	.string "to do when I'm not finding\l"
	.string "success there either?$"

VermilionGym_Text_JugglerHortonSeen:
	.string "I'm going to take you down!\n"
	.string "Prepare to be shocked!$"

VermilionGym_Text_JugglerHortonBeaten:
	.string "Gwaaah! Mi hai sopraffatto…$"

VermilionGym_Text_JugglerHortonAfter:
	.string "Non cullarti troppo dopo\n"
	.string "avermi battuto…\p"
	.string "LT.SURGE è tosto.$"

VermilionCity_Gym_Text_GymGuyAdvice::
    .string "Ehi!\n"
    .string "Campione in erba!\p"
    .string "LT. SURGE ha un soprannome.\p"
    .string "Lo chiamano tutti\n"
    .string "l'americano del fulmine!\p"
    .string "È un esperto di POKéMON\n"
    .string "elettrici.\p"
    .string "I POKéMON di tipo VOLANTE/ACQUA\n"
    .string "sono deboli contro l'ELETTRICO.\p"
    .string "Attento anche alla paralisi.\p"
    .string "LT. SURGE è molto prudente.\p"
    .string "Si è chiuso dentro, quindi non sarà\n"
    .string "facile arrivare da lui.$"

VermilionCity_Gym_Text_GymGuyPostVictory::
	.string "Fiuuu! Che incontro\n"
	.string "elettrizzante!\p"
	.string "Mi ha messo nervosismo.$"

VermilionCity_Gym_Text_GymStatue::
    .string "PALESTRA POKéMON DI VERMILION\n"
    .string "CAPO: LT. SURGE\p"
	.string "ALLENATORI VINCENTI:\n"
	.string "BLU, ROSSO$"


VermilionCity_Gym_Text_GymStatuePlayerWon::
    .string "PALESTRA POKéMON DI VERMILION\n"
    .string "CAPO: LT. SURGE\p"
    .string "ALLENATORI VINCENTI:\n"
    .string "BLU, ROSSO, {PLAYER}$"

VermilionCity_Gym_Text_NopeOnlyTrashHere::
    .string "No!\n"
    .string "Qui ci sono solo rifiuti.$"

VermilionCity_Gym_Text_SwitchUnderTrashFirstLockOpened::
    .string "Ehi! C'è un interruttore sotto i\n"
    .string "rifiuti! Accendilo!\p"
    .string "La prima serratura elettrica si apre!$"

VermilionCity_Gym_Text_SecondLockOpened::
    .string "La seconda serratura elettrica si apre!\n"
    .string "La porta motorizzata si apre!$"

VermilionCity_Gym_Text_OnlyTrashLocksWereReset::
    .string "No!\n"
    .string "Qui c'è solo spazzatura.\p"
    .string "Ehi!\n"
    .string "Le serrature si sono riattivate!$"

