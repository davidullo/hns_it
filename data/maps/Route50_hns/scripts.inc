Route50_hns_MapScripts::
	.byte 0

Route50_EventScript_BlackBelt1::
	msgbox Route50_Text_BlackBelt1, MSGBOX_NPC
	end

Route50_Text_BlackBelt1::
	.string "Il corpo va temprato\n"
    .string "e la mente rafforzata\l"
    .string "nelle condizioni più dure!$"

Route50_EventScript_BlackBelt2::
	msgbox Route50_Text_BlackBelt2, MSGBOX_NPC
	end

Route50_Text_BlackBelt2::
    .string "Fiuu!\p"
    .string "Non sono duro come lui.\p"
	.string "Qui non c'è altro da fare\n"
    .string "che allenarsi.$"
  

Route50_EventScript_Wessel::
	goto_if_defeated TRAINER_WESSEL_HNS, Route50_EventScript_WesselAfter
	msgbox Route50_Text_WesselBefore, MSGBOX_NPC
	goto_if_not_defeated TRAINER_WESSEL_HNS, Route50_EventScript_TryWesselBattle
	end
Route50_EventScript_TryWesselBattle::
	goto_if_eq VAR_SINJOH_STORYLINE, 6, Route50_EventScript_WesselBattle
	end
Route50_EventScript_WesselBattle::
	lock
	msgbox Route50_Text_WesselBeforeBattle, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_WESSEL_HNS, Route50_Text_WesselDefeat
	giveitem ITEM_IRON_PLATE
	addvar VAR_PLATECOUNTER, 1
	msgbox Route50_Text_WesselAfter, MSGBOX_AUTOCLOSE
	call_if_eq VAR_PLATECOUNTER, 3, SinjohRuins_Lab_EventScript_3Plates
	call_if_eq VAR_PLATECOUNTER, 6, SinjohRuins_Lab_EventScript_6Plates
	call_if_eq VAR_PLATECOUNTER, 9, SinjohRuins_Lab_EventScript_9Plates
	call_if_eq VAR_PLATECOUNTER, 12, SinjohRuins_Lab_EventScript_12Plates
	call_if_eq VAR_PLATECOUNTER, 15, SinjohRuins_Lab_EventScript_15Plates
	call_if_eq VAR_PLATECOUNTER, 16, SinjohRuins_Lab_EventScript_16Plates
	release
	end
Route50_EventScript_WesselAfter::
	msgbox Route50_Text_WesselAfter, MSGBOX_NPC
	end

Route50_Text_WesselBefore:
	.string "Incredibile, un VOLTORB!\p"
    .string "Ma sembra fatto\n"
    .string "di... Legno?\p"
    .string "La mia ipotesi che questa rotta\n"
    .string "contenesse molti POKéMON di tipo\l"
    .string "ACCIAIO è smentita ancora.\p"
    .string "Ma sennò perché avrei trovato\n"
    .string "qui questa PIASTRA ACCIAIO?\p"
    .string "Devo raccogliere più dati!$"

Route50_Text_WesselBeforeBattle:
	.string "Vuoi questa PIASTRA?\n"
	.string "Ma non l'ho ancora analizzata!\p"
	.string "Va bene, combattiamo per averla.$"

Route50_Text_WesselDefeat:
	.string "La mia ipotesi era sbagliata...$"

Route50_Text_WesselAfter:
	.string "Prendi la PIASTRA. Non voglio\n"
	.string "parlarne.$"

Route50_EventScript_Finley::
	goto_if_defeated TRAINER_FINLEY_HNS, Route50_EventScript_FinleyAfter
	msgbox Route50_Text_FinleyBefore, MSGBOX_NPC
	goto_if_not_defeated TRAINER_FINLEY_HNS, Route50_EventScript_TryFinleyBattle
	end
Route50_EventScript_TryFinleyBattle::
	goto_if_eq VAR_SINJOH_STORYLINE, 6, Route50_EventScript_FinleyBattle
	end
Route50_EventScript_FinleyBattle::
	lock
	msgbox Route50_Text_FinleyBeforeBattle, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_FINLEY_HNS, Route50_Text_FinleyDefeat
	giveitem ITEM_DRACO_PLATE
	addvar VAR_PLATECOUNTER, 1
	msgbox Route50_Text_FinleyAfter, MSGBOX_AUTOCLOSE
	call_if_eq VAR_PLATECOUNTER, 3, SinjohRuins_Lab_EventScript_3Plates
	call_if_eq VAR_PLATECOUNTER, 6, SinjohRuins_Lab_EventScript_6Plates
	call_if_eq VAR_PLATECOUNTER, 9, SinjohRuins_Lab_EventScript_9Plates
	call_if_eq VAR_PLATECOUNTER, 12, SinjohRuins_Lab_EventScript_12Plates
	call_if_eq VAR_PLATECOUNTER, 15, SinjohRuins_Lab_EventScript_15Plates
	call_if_eq VAR_PLATECOUNTER, 16, SinjohRuins_Lab_EventScript_16Plates
	release
	end
Route50_EventScript_FinleyAfter::
	msgbox Route50_Text_FinleyAfter, MSGBOX_NPC
	end

Route50_Text_FinleyBefore:
	.string "Come ti trattano gli abitanti\n"
    .string "del villaggio?\p"
    .string "Possono essere molto ostili con\n"
    .string "gli stranieri.\p"
    .string "Ma conoscere gente nuova è una\n"
    .string "delle gioie più grandi.\p"
    .string "Un giorno spero di incontrare il CAMPIONE\n"
    .string "LANCE.\p"
    .string "È un domatore di draghi leggendario,\n"
    .string "proprio come me.\l"
    .string "Chi sono io?\p"
    .string "Sono ENNIO, custode della\n"
    .string "PIASTRA DRACO.$"

Route50_Text_FinleyBeforeBattle:
	.string "So che i KIMONO ti hanno mandato\n"
	.string "a raccogliere queste PIASTRE.\p"
	.string "Dicono che sei degno...\n"
	.string "Ma sai battere i miei draghi?$"

Route50_Text_FinleyDefeat:
	.string "I miei draghi hanno lottato bene.$"

Route50_Text_FinleyAfter:
	.string "Forse sei persino abbastanza forte\n"
	.string "da battere LANCE...$"

Route50_EventScript_Item_ULtraBall::
    finditem ITEM_ULTRA_BALL
    end

Route50_EventScript_Item_Big_Nugget::
    finditem ITEM_BIG_NUGGET
    end

Route50_EventScript_ActivateKleavor::
    lock
    setobjectxyperm LOCALID_ROUTE50_NOBLE_KLEAVOR, 75, 12
    playse SE_M_DETECT
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	dofieldeffectsparkle VAR_TEMP_1, VAR_TEMP_2, 0
	waitfieldeffect FLDEFF_SPARKLE
    playse SE_PIN
    applymovement2 LOCALID_PLAYER, Common_Movement_ExclamationMark
    delay 55
    waitmovement LOCALID_PLAYER
    msgbox SinjohRuins_Lab_Text_PlayFlute, MSGBOX_YESNO
	closemessage
    goto_if_eq VAR_RESULT, FALSE, SinjohRuins_Lab_EventScript_NoOp
    playbgm MUS_DP_AZURE_FLUTE, FALSE
    delay 200
    fadedefaultbgm
    addobject LOCALID_ROUTE50_NOBLE_KLEAVOR
    clearflag FLAG_HIDE_ROUTE50_NOBLE_KLEAVOR
    applymovement2 LOCALID_ROUTE50_NOBLE_KLEAVOR, Route50_Movement_KleavorEntrance1
    delay 10
    playmoncry SPECIES_KLEAVOR, CRY_MODE_NORMAL
    waitmoncry
    playmoncry SPECIES_KLEAVOR, CRY_MODE_NORMAL
    waitmoncry
    waitmovement 0
    applymovement2 LOCALID_ROUTE50_NOBLE_KLEAVOR, Route50_Movement_KleavorEntrance2
    delay 10
    playse SE_LEDGE
    delay 20
	waitmovement LOCALID_ROUTE50_NOBLE_KLEAVOR
    setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 5  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
    setobjectxyperm LOCALID_ROUTE50_NOBLE_KLEAVOR, 75, 14
    setvar VAR_NOBLE_KLEAVOR, 2
    release
    end

Route50_Movement_KleavorEntrance1:
    jump_in_place_down
    walk_in_place_fast_down
    walk_in_place_fast_down
	step_end

Route50_Movement_KleavorEntrance2:
	jump_2_down
    walk_in_place_slow_down
	walk_in_place_slow_down
	jump_in_place_down
	step_end

Route50_EventScript_Kleavor::
	lock
	faceplayer
	playmoncry SPECIES_KLEAVOR, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbossbattle species=SPECIES_KLEAVOR, level=80, item=ITEM_SCOPE_LENS, move1_1=MOVE_STONE_AXE, move1_2=MOVE_CROSS_POISON, move1_3=MOVE_LUNGE move1_4=MOVE_FOCUS_ENERGY
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 2, 0, 0, 2, 0
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
    dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route50_EventScript_KleavorRan
    bufferspeciesname STR_VAR_1, SPECIES_KLEAVOR
    msgbox SinjohRuins_Lab_Text_DropedItem, MSGBOX_DEFAULT
    giveitem ITEM_INSECT_PLATE
    addvar VAR_PLATECOUNTER, 1
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_ROUTE50_NOBLE_KLEAVOR
	setflag FLAG_HIDE_ROUTE50_NOBLE_KLEAVOR
	fadescreenswapbuffers FADE_FROM_BLACK
    call_if_eq VAR_PLATECOUNTER, 3, SinjohRuins_Lab_EventScript_3Plates
    call_if_eq VAR_PLATECOUNTER, 6, SinjohRuins_Lab_EventScript_6Plates
    call_if_eq VAR_PLATECOUNTER, 9, SinjohRuins_Lab_EventScript_9Plates
    call_if_eq VAR_PLATECOUNTER, 12, SinjohRuins_Lab_EventScript_12Plates
    call_if_eq VAR_PLATECOUNTER, 15, SinjohRuins_Lab_EventScript_15Plates
    call_if_eq VAR_PLATECOUNTER, 16, SinjohRuins_Lab_EventScript_16Plates
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

Route50_EventScript_KleavorRan::
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end


Route50_EventScript_ActivateElectrode::
    lock
    setobjectxyperm LOCALID_ROUTE50_NOBLE_ELECTRODE, 18, 26
    playse SE_M_DETECT
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	dofieldeffectsparkle VAR_TEMP_1, VAR_TEMP_2, 0
	waitfieldeffect FLDEFF_SPARKLE
    playse SE_PIN
    applymovement2 LOCALID_PLAYER, Common_Movement_ExclamationMark
    delay 55
    waitmovement LOCALID_PLAYER
    msgbox SinjohRuins_Lab_Text_PlayFlute, MSGBOX_YESNO
	closemessage
    goto_if_eq VAR_RESULT, FALSE, SinjohRuins_Lab_EventScript_NoOp
    playbgm MUS_DP_AZURE_FLUTE, FALSE
    delay 200
    fadedefaultbgm
    addobject LOCALID_ROUTE50_NOBLE_ELECTRODE
    clearflag FLAG_HIDE_ROUTE50_NOBLE_ELECTRODE
    applymovement2 LOCALID_ROUTE50_NOBLE_ELECTRODE, Route50_Movement_ElectrodeEntrance1
    delay 10
    playmoncry SPECIES_ELECTRODE_HISUI, CRY_MODE_NORMAL
    waitmoncry
    playmoncry SPECIES_ELECTRODE_HISUI, CRY_MODE_NORMAL
    waitmoncry
    waitmovement 0
    applymovement2 LOCALID_ROUTE50_NOBLE_ELECTRODE, Route50_Movement_ElectrodeEntrance2
    delay 10
    playse SE_LEDGE
    delay 20
	waitmovement 0
    setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 5  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	applymovement2 LOCALID_ROUTE50_NOBLE_ELECTRODE, Route50_Movement_ElectrodeEntrance3
	waitmovement LOCALID_ROUTE50_NOBLE_ELECTRODE
	removeobject LOCALID_ROUTE50_NOBLE_ELECTRODE
	delay 20
	setobjectxyperm LOCALID_ROUTE50_NOBLE_ELECTRODE, 14, 31
	addobject LOCALID_ROUTE50_NOBLE_ELECTRODE
	clearflag FLAG_HIDE_ROUTE50_NOBLE_ELECTRODE
    setvar VAR_NOBLE_ELECTRODE, 2
    release
    end

Route50_Movement_ElectrodeEntrance1:
	walk_right
    jump_in_place_right
    walk_in_place_fast_right
    walk_in_place_fast_right
	step_end

Route50_Movement_ElectrodeEntrance2:
	jump_2_right
    walk_in_place_slow_up
	walk_in_place_slow_up
	jump_in_place_down
	step_end

Route50_Movement_ElectrodeEntrance3:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route50_EventScript_Electrode::
	lock
	faceplayer
	playmoncry SPECIES_ELECTRODE_HISUI, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbossbattle species=SPECIES_ELECTRODE_HISUI, level=80, item=ITEM_BRIGHT_POWDER, move1_1=MOVE_FOUL_PLAY, move1_2=MOVE_ELECTRO_BALL, move1_3=MOVE_ENERGY_BALL move1_4=MOVE_CHLOROBLAST
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 3, 1, 0, 3, 0
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
    dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route50_EventScript_ElectrodeRan
    bufferspeciesname STR_VAR_1, SPECIES_ELECTRODE_HISUI
    msgbox SinjohRuins_Lab_Text_DropedItem, MSGBOX_DEFAULT
    giveitem ITEM_ZAP_PLATE
    addvar VAR_PLATECOUNTER, 1
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_ROUTE50_NOBLE_ELECTRODE
	setflag FLAG_HIDE_ROUTE50_NOBLE_ELECTRODE
	fadescreenswapbuffers FADE_FROM_BLACK
    call_if_eq VAR_PLATECOUNTER, 3, SinjohRuins_Lab_EventScript_3Plates
    call_if_eq VAR_PLATECOUNTER, 6, SinjohRuins_Lab_EventScript_6Plates
    call_if_eq VAR_PLATECOUNTER, 9, SinjohRuins_Lab_EventScript_9Plates
    call_if_eq VAR_PLATECOUNTER, 12, SinjohRuins_Lab_EventScript_12Plates
    call_if_eq VAR_PLATECOUNTER, 15, SinjohRuins_Lab_EventScript_15Plates
    call_if_eq VAR_PLATECOUNTER, 16, SinjohRuins_Lab_EventScript_16Plates
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

Route50_EventScript_ElectrodeRan::
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end
