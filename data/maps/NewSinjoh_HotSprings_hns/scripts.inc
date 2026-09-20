NewSinjoh_HotSprings_hns_MapScripts::
	.byte 0

NewSinjoh_HotSprings_EventScript_Item_MaxRevive::
    finditem ITEM_MAX_REVIVE
    end

NewSinjoh_HotSprings_EventScript_Item_LavaCookie::
    finditem ITEM_LAVA_COOKIE
    end

NewSinjoh_HotSprings_EventScript_Mualani::
	goto_if_defeated TRAINER_MUALANI_HNS, NewSinjoh_HotSprings_EventScript_MualaniAfter
	msgbox NewSinjoh_HotSprings_Text_MualaniBefore, MSGBOX_NPC
	goto_if_not_defeated TRAINER_MUALANI_HNS, NewSinjoh_HotSprings_EventScript_TryMualaniBattle
	end
NewSinjoh_HotSprings_EventScript_TryMualaniBattle::
	goto_if_eq VAR_SINJOH_STORYLINE, 6, NewSinjoh_HotSprings_EventScript_MualaniBattle
	end
NewSinjoh_HotSprings_EventScript_MualaniBattle::
	lock
	msgbox NewSinjoh_HotSprings_Text_MualaniBeforeBattle, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_MUALANI_HNS, NewSinjoh_HotSprings_Text_MualaniDefeat
	giveitem ITEM_SPLASH_PLATE
	addvar VAR_PLATECOUNTER, 1
	msgbox NewSinjoh_HotSprings_Text_MualaniAfter, MSGBOX_AUTOCLOSE
	call_if_eq VAR_PLATECOUNTER, 3, SinjohRuins_Lab_EventScript_3Plates
	call_if_eq VAR_PLATECOUNTER, 6, SinjohRuins_Lab_EventScript_6Plates
	call_if_eq VAR_PLATECOUNTER, 9, SinjohRuins_Lab_EventScript_9Plates
	call_if_eq VAR_PLATECOUNTER, 12, SinjohRuins_Lab_EventScript_12Plates
	call_if_eq VAR_PLATECOUNTER, 15, SinjohRuins_Lab_EventScript_15Plates
	call_if_eq VAR_PLATECOUNTER, 16, SinjohRuins_Lab_EventScript_16Plates
	release
	end
NewSinjoh_HotSprings_EventScript_MualaniAfter::
	msgbox NewSinjoh_HotSprings_Text_MualaniAfter, MSGBOX_NPC
	end

NewSinjoh_HotSprings_Text_MualaniBefore:
	.string "Sono del posto o una visitatrice?\n"
    .string "Che domanda scortese!\p"
    .string "Se proprio devi saperlo, sono del posto.\p"
    .string "La mia famiglia è stata tra i primi a\n"
    .string "godersi queste terme.\p"
    .string "Guarda, ho persino questa IDROPIastra\n"
    .string "a provarlo.$"

NewSinjoh_HotSprings_Text_MualaniBeforeBattle:
	.string "Aspetta…\p"
	.string "Ti serve la PIASTRA SPLASH\n"
	.string "per domare il POKéMON leggendario?\p"
	.string "Se le RAGAZZE KIMONO ti ritengono\n"
	.string "degno, allora lo penso anch'io.\p"
	.string "Ma dovrai comunque guadagnarlo,\n"
	.string "prima.$"

NewSinjoh_HotSprings_Text_MualaniDefeat:
	.string "Te la sei meritata.$"

NewSinjoh_HotSprings_Text_MualaniAfter:
	.string "Mi è difficile lasciar andare\n"
	.string "questa piastra.\p"
	.string "Ma quando la situazione cambia,\n"
	.string "è importante cambiare\l"
	.string "anche noi.\p"
	.string "La piastra è tua.$"


NewSinjoh_HotSprings_EventScript_Sign1::
    msgbox NewSinjoh_HotSprings_Text_Sign1, MSGBOX_SIGN
    end

NewSinjoh_HotSprings_Text_Sign1:
    .string "NUOVA SINJOH\n"
    .string "TERME$"

NewSinjoh_HotSprings_EventScript_Sign2::
    msgbox NewSinjoh_HotSprings_Text_Sign2, MSGBOX_SIGN
    end

NewSinjoh_HotSprings_Text_Sign2:
    .string "PERICOLO\n"
    .string "TANA DEL LETARGO SELVAGGIO$"

NewSinjoh_HotSprings_EventScript_SkierF::
    msgbox NewSinjoh_HotSprings_Text_SkierF, MSGBOX_NPC
    end

NewSinjoh_HotSprings_Text_SkierF:
	.string "Odio il freddo!\p"
    .string "Sono qui solo per le terme!$"

NewSinjoh_HotSprings_EventScript_SkierM::
    msgbox NewSinjoh_HotSprings_Text_SkierM, MSGBOX_NPC
    end

NewSinjoh_HotSprings_Text_SkierM:
	.string "Sono venuto per lo snowboard\n"
    .string "ma la mia ragazza vuole solo\l"
    .string "stare in acqua tutto il giorno!$"


NewSinjoh_HotSprings_EventScript_OldLady::
    msgbox NewSinjoh_HotSprings_Text_OldLady, MSGBOX_NPC
    end

NewSinjoh_HotSprings_Text_OldLady:
	.string "Ignora mio marito.\p"
    .string "Lascia che le preoccupazioni svaniscano.$"

NewSinjoh_HotSprings_EventScript_CreepyMan::
	msgbox NewSinjoh_HotSprings_Text_CreepyMan, MSGBOX_NPC
	end

NewSinjoh_HotSprings_Text_CreepyMan:
	.string "Ouughh...\p"
	.string "Quest'acqua è magica sulla mia schiena.\p"
	.string "Se hai anche tu mal di schiena,\n"
	.string "dovresti restare qui con me...$"

NewSinjoh_HotSprings_EventScript_PLATutor::
	lock
	faceplayer
	msgbox NewSinjoh_HotSprings_Text_PLATutorIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, NewSinjoh_HotSprings_EventScript_PLATutorDecline
	message NewSinjoh_HotSprings_Text_PLATutorChoose
	waitmessage
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, NewSinjoh_HotSprings_Text_PLAMove_PowerShift, NewSinjoh_HotSprings_Text_PLAMove_SpringtideStorm, NewSinjoh_HotSprings_Text_PLAMove_MysticalPower, NewSinjoh_HotSprings_Text_PLAMove_WaveCrash, NewSinjoh_HotSprings_Text_PLAMove_MountainGale, NewSinjoh_HotSprings_Text_PLAMove_VictoryDance, NewSinjoh_HotSprings_Text_PLAMove_EsperWing, NewSinjoh_HotSprings_Text_PLAMove_BitterMalice, NewSinjoh_HotSprings_Text_PLAMove_Shelter, NewSinjoh_HotSprings_Text_PLAMove_BleakwindStorm, NewSinjoh_HotSprings_Text_PLAMove_WildboltStorm, NewSinjoh_HotSprings_Text_PLAMove_SandsearStorm, NewSinjoh_HotSprings_Text_PLAMove_LunarBlessing, NewSinjoh_HotSprings_Text_PLAMove_TakeHeart, NewSinjoh_HotSprings_Text_PLAMove_Cancel
	switch VAR_RESULT
	case 0, NewSinjoh_HotSprings_EventScript_PLATeach_PowerShift
	case 1, NewSinjoh_HotSprings_EventScript_PLATeach_SpringtideStorm
	case 2, NewSinjoh_HotSprings_EventScript_PLATeach_MysticalPower
	case 3, NewSinjoh_HotSprings_EventScript_PLATeach_WaveCrash
	case 4, NewSinjoh_HotSprings_EventScript_PLATeach_MountainGale
	case 5, NewSinjoh_HotSprings_EventScript_PLATeach_VictoryDance
	case 6, NewSinjoh_HotSprings_EventScript_PLATeach_EsperWing
	case 7, NewSinjoh_HotSprings_EventScript_PLATeach_BitterMalice
	case 8, NewSinjoh_HotSprings_EventScript_PLATeach_Shelter
	case 9, NewSinjoh_HotSprings_EventScript_PLATeach_BleakwindStorm
	case 10, NewSinjoh_HotSprings_EventScript_PLATeach_WildboltStorm
	case 11, NewSinjoh_HotSprings_EventScript_PLATeach_SandsearStorm
	case 12, NewSinjoh_HotSprings_EventScript_PLATeach_LunarBlessing
	case 13, NewSinjoh_HotSprings_EventScript_PLATeach_TakeHeart
	case 14, NewSinjoh_HotSprings_EventScript_PLATutorDecline
	case MULTI_B_PRESSED, NewSinjoh_HotSprings_EventScript_PLATutorDecline
	end

NewSinjoh_HotSprings_EventScript_PLATeach_PowerShift::
	setvar VAR_0x8005, MOVE_POWER_SHIFT
	goto NewSinjoh_HotSprings_EventScript_PLATeachMove
	end

NewSinjoh_HotSprings_EventScript_PLATeach_SpringtideStorm::
	setvar VAR_0x8005, MOVE_SPRINGTIDE_STORM
	goto NewSinjoh_HotSprings_EventScript_PLATeachMove
	end

NewSinjoh_HotSprings_EventScript_PLATeach_MysticalPower::
	setvar VAR_0x8005, MOVE_MYSTICAL_POWER
	goto NewSinjoh_HotSprings_EventScript_PLATeachMove
	end

NewSinjoh_HotSprings_EventScript_PLATeach_WaveCrash::
	setvar VAR_0x8005, MOVE_WAVE_CRASH
	goto NewSinjoh_HotSprings_EventScript_PLATeachMove
	end

NewSinjoh_HotSprings_EventScript_PLATeach_MountainGale::
	setvar VAR_0x8005, MOVE_MOUNTAIN_GALE
	goto NewSinjoh_HotSprings_EventScript_PLATeachMove
	end

NewSinjoh_HotSprings_EventScript_PLATeach_VictoryDance::
	setvar VAR_0x8005, MOVE_VICTORY_DANCE
	goto NewSinjoh_HotSprings_EventScript_PLATeachMove
	end

NewSinjoh_HotSprings_EventScript_PLATeach_EsperWing::
	setvar VAR_0x8005, MOVE_ESPER_WING
	goto NewSinjoh_HotSprings_EventScript_PLATeachMove
	end

NewSinjoh_HotSprings_EventScript_PLATeach_BitterMalice::
	setvar VAR_0x8005, MOVE_BITTER_MALICE
	goto NewSinjoh_HotSprings_EventScript_PLATeachMove
	end

NewSinjoh_HotSprings_EventScript_PLATeach_Shelter::
	setvar VAR_0x8005, MOVE_SHELTER
	goto NewSinjoh_HotSprings_EventScript_PLATeachMove
	end

NewSinjoh_HotSprings_EventScript_PLATeach_BleakwindStorm::
	setvar VAR_0x8005, MOVE_BLEAKWIND_STORM
	goto NewSinjoh_HotSprings_EventScript_PLATeachMove
	end

NewSinjoh_HotSprings_EventScript_PLATeach_WildboltStorm::
	setvar VAR_0x8005, MOVE_WILDBOLT_STORM
	goto NewSinjoh_HotSprings_EventScript_PLATeachMove
	end

NewSinjoh_HotSprings_EventScript_PLATeach_SandsearStorm::
	setvar VAR_0x8005, MOVE_SANDSEAR_STORM
	goto NewSinjoh_HotSprings_EventScript_PLATeachMove
	end

NewSinjoh_HotSprings_EventScript_PLATeach_LunarBlessing::
	setvar VAR_0x8005, MOVE_LUNAR_BLESSING
	goto NewSinjoh_HotSprings_EventScript_PLATeachMove
	end

NewSinjoh_HotSprings_EventScript_PLATeach_TakeHeart::
	setvar VAR_0x8005, MOVE_TAKE_HEART
	goto NewSinjoh_HotSprings_EventScript_PLATeachMove
	end

NewSinjoh_HotSprings_EventScript_PLATeachMove::
	buffermovename STR_VAR_1, VAR_0x8005
	msgbox NewSinjoh_HotSprings_Text_PLATutorConfirm, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, NewSinjoh_HotSprings_EventScript_PLATutor
	msgbox NewSinjoh_HotSprings_Text_PLATutorWhichMon, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	chooseboxmon SELECT_PC_MON_PLA_TUTOR
	waitstate
	goto_if_eq VAR_RESULT, FALSE, NewSinjoh_HotSprings_EventScript_PLATutorCancelMon
	msgbox NewSinjoh_HotSprings_Text_PLATutorDone, MSGBOX_DEFAULT
	release
	end

NewSinjoh_HotSprings_EventScript_PLATutorCancelMon::
	msgbox NewSinjoh_HotSprings_Text_PLATutorComeBack, MSGBOX_DEFAULT
	release
	end

NewSinjoh_HotSprings_EventScript_PLATutorDecline::
	msgbox NewSinjoh_HotSprings_Text_PLATutorComeBack, MSGBOX_DEFAULT
	release
	end

NewSinjoh_HotSprings_Text_PLATutorIntro:
	.string "L'antico potere scorre\n"
	.string "in queste sorgenti.\p"
	.string "Posso insegnare al tuo POKéMON\n"
	.string "mossi di un'era dimenticata.\p"
	.string "Ti interessa?$"

NewSinjoh_HotSprings_Text_PLATutorChoose:
	.string "Quale mossa vuoi?$"

NewSinjoh_HotSprings_Text_PLATutorConfirm:
	.string "Vuoi imparare {STR_VAR_1}?$"

NewSinjoh_HotSprings_Text_PLATutorWhichMon:
	.string "Quale POKéMON deve impararla?$"

NewSinjoh_HotSprings_Text_PLATutorDone:
	.string "Fatto! Il tuo POKéMON ha appreso\n"
	.string "l'antica tecnica.$"

NewSinjoh_HotSprings_Text_PLATutorComeBack:
	.string "Torna quando vuoi.$"

NewSinjoh_HotSprings_Text_PLAMove_VictoryDance:
	.string "DANZAVITTORIA$"

NewSinjoh_HotSprings_Text_PLAMove_MountainGale:
	.string "SOFFIO D’ICEBERG$"

NewSinjoh_HotSprings_Text_PLAMove_BitterMalice:
	.string "LIVORE$"

NewSinjoh_HotSprings_Text_PLAMove_SpringtideStorm:
	.string "TEMPESTA ZEFIREA$"

NewSinjoh_HotSprings_Text_PLAMove_LunarBlessing:
	.string "INVOCALUNA$"

NewSinjoh_HotSprings_Text_PLAMove_BleakwindStorm:
	.string "TEMPESTA BOREALE$"

NewSinjoh_HotSprings_Text_PLAMove_WildboltStorm:
	.string "TEMPESTA TONANTE$"

NewSinjoh_HotSprings_Text_PLAMove_SandsearStorm:
	.string "TEMPESTA ARDENTE$"

NewSinjoh_HotSprings_Text_PLAMove_Shelter:
	.string "BARRICATA$"

NewSinjoh_HotSprings_Text_PLAMove_EsperWing:
	.string "ALI D’AURA$"

NewSinjoh_HotSprings_Text_PLAMove_TakeHeart:
	.string "BALDIMPULSO$"

NewSinjoh_HotSprings_Text_PLAMove_MysticalPower:
	.string "FORZA MISTICA$"

NewSinjoh_HotSprings_Text_PLAMove_WaveCrash:
	.string "ONDASCHIANTO$"

NewSinjoh_HotSprings_Text_PLAMove_PowerShift:
	.string "SCAMBIOFORZA$"

NewSinjoh_HotSprings_Text_PLAMove_Cancel:
	.string "ANNULLA$"


NewSinjoh_HotSprings_EventScript_ActivateArcanine::
    lock
    setobjectxyperm LOCALID_HOTSPRINGS_NOBLE_ARCANINE, 16, 4
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
    addobject LOCALID_HOTSPRINGS_NOBLE_ARCANINE
    clearflag FLAG_HIDE_HOTSPRINGS_NOBLE_ARCANINE
    applymovement2 LOCALID_HOTSPRINGS_NOBLE_ARCANINE, NewSinjoh_HotSprings_Movement_ArcanineEntrance1
    delay 10
	playse SE_LEDGE
    playmoncry SPECIES_ARCANINE_HISUI, CRY_MODE_NORMAL
    waitmoncry
    waitmovement 0
    applymovement2 LOCALID_HOTSPRINGS_NOBLE_ARCANINE, NewSinjoh_HotSprings_Movement_ArcanineEntrance2
    delay 10
	playmoncry SPECIES_ARCANINE_HISUI, CRY_MODE_NORMAL
    waitmoncry
    playse SE_LEDGE
    delay 20
	waitmovement LOCALID_HOTSPRINGS_NOBLE_ARCANINE
    setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 5  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
    setobjectxyperm LOCALID_HOTSPRINGS_NOBLE_ARCANINE, 16, 8
    setvar VAR_NOBLE_ARCANINE, 2
    release
    end

NewSinjoh_HotSprings_Movement_ArcanineEntrance1:
    slide_down
	slide_down
	slide_down
	slide_down
	step_end

NewSinjoh_HotSprings_Movement_ArcanineEntrance2:
    walk_in_place_slow_down
	walk_in_place_slow_down
	jump_in_place_down
	step_end


NewSinjoh_HotSprings_EventScript_Arcanine::
	lock
	faceplayer
	playmoncry SPECIES_ARCANINE_HISUI, CRY_MODE_ENCOUNTER
	waitmoncry
    setwildbossbattle species=SPECIES_ARCANINE_HISUI, level=80, item=ITEM_LOADED_DICE, move1_1=MOVE_ROCK_BLAST, move1_2=MOVE_WILD_CHARGE, move1_3=MOVE_RAGING_FURY move1_4=MOVE_PROTECT
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 0, 2, 0, 0, 0
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
    dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NewSinjoh_HotSprings_EventScript_ArcanineRan
    bufferspeciesname STR_VAR_1, SPECIES_ARCANINE_HISUI
    msgbox SinjohRuins_Lab_Text_DropedItem, MSGBOX_DEFAULT
    giveitem ITEM_FLAME_PLATE
    addvar VAR_PLATECOUNTER, 1
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_HOTSPRINGS_NOBLE_ARCANINE
	setflag FLAG_HIDE_HOTSPRINGS_NOBLE_ARCANINE
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

NewSinjoh_HotSprings_EventScript_ArcanineRan::
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end






NewSinjoh_HotSprings_EventScript_ActivateUrsaluna::
    lock
    setobjectxyperm LOCALID_HOTSPRINGS_NOBLE_URSALUNA, 52, 26
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
    addobject LOCALID_HOTSPRINGS_NOBLE_URSALUNA
    clearflag FLAG_HIDE_HOTSPRINGS_NOBLE_URSALUNA
    applymovement2 LOCALID_HOTSPRINGS_NOBLE_URSALUNA, NewSinjoh_HotSprings_Movement_UrsalunaEntrance1
    delay 10
	playse SE_LEDGE
    playmoncry SPECIES_URSALUNA, CRY_MODE_NORMAL
    waitmoncry
    waitmovement 0
    applymovement2 LOCALID_HOTSPRINGS_NOBLE_URSALUNA, NewSinjoh_HotSprings_Movement_UrsalunaEntrance2
    delay 10
	playmoncry SPECIES_URSALUNA, CRY_MODE_NORMAL
    waitmoncry
    playse SE_LEDGE
    delay 20
	waitmovement LOCALID_HOTSPRINGS_NOBLE_URSALUNA
    setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 5  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
    setobjectxyperm LOCALID_HOTSPRINGS_NOBLE_URSALUNA, 52, 28
    setvar VAR_NOBLE_URSALUNA, 2
    release
    end

NewSinjoh_HotSprings_Movement_UrsalunaEntrance1:
    jump_in_place_down
    walk_in_place_fast_down
    walk_in_place_fast_down
	step_end

NewSinjoh_HotSprings_Movement_UrsalunaEntrance2:
	jump_2_down
    walk_in_place_slow_down
	walk_in_place_slow_down
	jump_in_place_down
	step_end


NewSinjoh_HotSprings_EventScript_Ursaluna::
	lock
	faceplayer
	playmoncry SPECIES_URSALUNA, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbossbattle species=SPECIES_URSALUNA, level=80, item=ITEM_EARTH_PLATE, move1_1=MOVE_EARTHQUAKE, move1_2=MOVE_AVALANCHE, move1_3=MOVE_BULK_UP move1_4=MOVE_GIGA_IMPACT
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 0, 2, 0, 0, 0
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
    dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NewSinjoh_HotSprings_EventScript_UrsalunaRan
    bufferspeciesname STR_VAR_1, SPECIES_URSALUNA
    msgbox SinjohRuins_Lab_Text_DropedItem, MSGBOX_DEFAULT
    giveitem ITEM_EARTH_PLATE
    addvar VAR_PLATECOUNTER, 1
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_HOTSPRINGS_NOBLE_URSALUNA
	setflag FLAG_HIDE_HOTSPRINGS_NOBLE_URSALUNA
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

NewSinjoh_HotSprings_EventScript_UrsalunaRan::
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end
