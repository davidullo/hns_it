LakeOfRage_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LakeOfRage_OnTransition
	.byte 0

LakeOfRage_OnTransition::
	setflag FLAG_VISITED_LAKE_OF_RAGE
	call_if_lt VAR_MAHOGANY_TOWN_STATE, 2, LakeOfRage_EventScript_HideLois
	goto_if_lt VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_SetHighTide
	special UpdateShoalTideFlag
	goto_if_set FLAG_SYS_LAKE_OF_RAGE_TIDE, LakeOfRage_EventScript_SetHighTide
	goto LakeOfRage_EventScript_SetLowTide

LakeOfRage_EventScript_SetLowTide::
	setweather WEATHER_NONE
	setmaplayoutindex LAYOUT_LAKE_OF_RAGE_LOW_TIDE_HNS
	end

LakeOfRage_EventScript_SetHighTide::
	setmaplayoutindex LAYOUT_LAKE_OF_RAGE_HNS
	goto_if_lt VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_ThunderStorm
	random 2
	goto_if_eq VAR_RESULT, 1, LakeOfRage_EventScript_ThunderStorm
	end

LakeOfRage_EventScript_HideLois::
	setflag FLAG_TEMP_1
	return

LakeOfRage_EventScript_ThunderStorm::
	setweather WEATHER_RAIN_THUNDERSTORM
	end

LakeOfRage_EventScript_Pryce::
    lock
    faceplayer
    msgbox LakeOfRage_Text_Pryce, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_LAKE_PRYCE
    removeobject LOCALID_LAKE_PRYCE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_PRYCE
    release
    end

LakeOfRage_Text_Pryce:
    .string "{PLAYER}.\p"
	.string "Anche qui il freddo mi tiene\p"
	.string "in forma. Se vuoi lottare di\n"
	.string "nuovo, vieni al DOJO DI LOTTA.$"

LakeOfRage_EventScript_Gramps::
	goto_if_ge VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_Gramps2
	msgbox LakeOfRage_Text_Gramps, MSGBOX_NPC
	end

LakeOfRage_EventScript_Gramps2::
	msgbox LakeOfRage_Text_GrampsCleared, MSGBOX_NPC
	end
LakeOfRage_EventScript_Lass::
	msgbox LakeOfRage_Text_CooltrainerF, MSGBOX_NPC
	end

LakeOfRage_EventScript_Nerd::
	msgbox LakeOfRage_Text_SuperNerd, MSGBOX_NPC
	end

LakeOfRage_EventScript_Andre::
	trainerbattle_single TRAINER_ANDRE_HNS, LakeOfRage_Text_FisherAndreSeen, LakeOfRage_Text_FisherAndreBeaten
	msgbox LakeOfRage_Text_FisherAndreAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Raymond::
	trainerbattle_single TRAINER_RAYMOND_HNS, LakeOfRage_Text_FisherRaymondSeen, LakeOfRage_Text_FisherRaymondBeaten
	msgbox LakeOfRage_Text_FisherRaymondAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Aaron::
	trainerbattle_single TRAINER_AARON_HNS, LakeOfRage_Text_CooltrainermAaronSeen, LakeOfRage_Text_CooltrainermAaronBeaten
	msgbox LakeOfRage_Text_CooltrainermAaronAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Lois::
	trainerbattle_single TRAINER_LOIS_HNS, LakeOfRage_Text_CooltrainerfLoisSeen, LakeOfRage_Text_CooltrainerfLoisBeaten
	msgbox LakeOfRage_Text_CooltrainerfLoisAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Gyarados::
	lock
	faceplayer
	msgbox LakeOfRage_Text_GyaradosCry, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_GYARADOS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattleshiny SPECIES_GYARADOS, 30
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, LakeOfRage_EventScript_Defeated_Gyarados
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, LakeOfRage_EventScript_Ran_Gyarados
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, LakeOfRage_EventScript_Ran_Gyarados
LakeOfRage_EventScript_Defeated_Gyarados::
	setflag FLAG_HIDE_LAKE_OF_RAGE_GYARADOS
	clearflag FLAG_TEMP_1
	removeobject LOCALID_LAKEOFRAGE_GYARADOS
	clearflag FLAG_HIDE_LAKE_OF_RAGE_LANCE
	addobject LOCALID_LAKEOFRAGE_LANCE
	giveitem ITEM_RED_SCALE
	setobjectxyperm LOCALID_LAKEOFRAGE_OLDMAN, 32, 38
	setvar VAR_MAHOGANY_TOWN_STATE, 2
	release
	end

LakeOfRage_EventScript_Ran_Gyarados::
	release
	end

LakeOfRage_EventScript_Item_Full_Restore::
	finditem ITEM_FULL_RESTORE
	end
LakeOfRage_EventScript_Item_Secret_Power::
    finditem ITEM_TM_SECRET_POWER
    end
LakeOfRage_EventScript_Item_Red_Flute::
	finditem ITEM_RED_FLUTE
	end

LakeOfRage_EventScript_Dragonite::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DRAGONITE, CRY_MODE_NORMAL
	msgbox LakeOfRage_Text_Dragonite, MSGBOX_DEFAULT
	waitmoncry
	turnobject LOCALID_LAKEOFRAGE_DRAGONITE, DIR_WEST
	release
	end

LakeOfRage_EventScript_Lance::
	lock
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 3, LakeOfRage_EventScript_Lance_Return
	msgbox LakeOfRage_Text_LanceForcedToEvolve, MSGBOX_DEFAULT
	closemessage
	delay 20
	faceplayer
	turnobject LOCALID_LAKEOFRAGE_OLDMAN, DIR_WEST
	msgbox LakeOfRage_Text_LanceIntro2, MSGBOX_DEFAULT
	setvar VAR_MAHOGANY_TOWN_STATE, 3
	msgbox LakeOfRage_Text_LanceIntro3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_EventScript_LancDeclined
LakeOfRage_EventScript_LanceAccept::
	lock
	msgbox LakeOfRage_Text_LanceRadioSignal, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, LakeOfRage_EventScript_LanceDragoniteLeaveNorth
	applymovement LOCALID_LAKEOFRAGE_LANCE, LakeOfRage_Movement_LanceLeave
	applymovement LOCALID_LAKEOFRAGE_DRAGONITE, LakeOfRage_Movement_DragoniteLeave
	waitmovement LOCALID_LAKEOFRAGE_LANCE
	waitmovement LOCALID_LAKEOFRAGE_DRAGONITE
LakeOfRage_EventScript_EndScene::
	setflag FLAG_HIDE_LAKE_OF_RAGE_LANCE
	removeobject LOCALID_LAKEOFRAGE_LANCE
	removeobject LOCALID_LAKEOFRAGE_DRAGONITE
	setvar VAR_MAHOGANY_TOWN_STATE, 4
	clearflag FLAG_HIDE_MAHOGANY_TOWN_SHOP_NPCS
	release
	end

LakeOfRage_EventScript_Lance_Return::
	lock
	faceplayer
	msgbox LakeOfRage_Text_LanceAskHelp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, LakeOfRage_EventScript_LanceAccept
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_EventScript_LancDeclined

LakeOfRage_EventScript_LancDeclined::
	msgbox LakeOfRage_Text_LanceRefused, MSGBOX_DEFAULT
	closemessage
	release
	end


LakeOfRage_EventScript_LanceDragoniteLeaveNorth::
	applymovement LOCALID_LAKEOFRAGE_LANCE, LakeOfRage_Movement_LanceLeaveNorth
	applymovement LOCALID_LAKEOFRAGE_DRAGONITE, LakeOfRage_Movement_DragoniteLeaveNorth
	waitmovement LOCALID_LAKEOFRAGE_LANCE
	waitmovement LOCALID_LAKEOFRAGE_DRAGONITE
	goto LakeOfRage_EventScript_EndScene

LakeOfRage_Movement_LanceLeaveNorth:
	walk_left
	walk_down
	delay_8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Movement_DragoniteLeaveNorth:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Movement_LanceLeave:
	walk_down
	delay_8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Movement_DragoniteLeave:
	delay_16
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Text_Dragonite:
	.string "DRAGONITE: Gyafuu!$"

LakeOfRage_Text_LanceForcedToEvolve:
    .string "Questo lago è pieno di GYARADOS\n"
    .string "ma nulla di più…\p"
    .string "Quindi i MAGIKARP sono costretti\n"
    .string "a evolversi…$"

LakeOfRage_Text_LanceIntro1:
    .string "Sei qui per via\n"
    .string "delle voci?\p"
    .string "Tu sei {PLAYER}? Io sono\n"
    .string "LANCE, un allenatore come te.$"

LakeOfRage_Text_LanceIntro2:
    .string "Quest'uomo mi ha parlato\n"
    .string "di alcune voci.\p"
    .string "Siamo venuti a indagare…$"

LakeOfRage_Text_LanceIntro3:
    .string "Ho visto come hai lottato\n"
    .string "prima, {PLAYER}.\p"
    .string "Sei un allenatore\n"
    .string "davvero abile.\p"
    .string "Se ti va, ci aiuti a\n"
    .string "indagare?$"

LakeOfRage_Text_LanceRadioSignal:
    .string "LANCE: Perfetto!\p"
    .string "Sembra che i MAGIKARP del lago\n"
    .string "vengano costretti a evolversi.\p"
    .string "La causa è una radio\n"
    .string "misteriosa da MAHOGANY.\p"
    .string "Ti aspettiamo,\n"
    .string "{PLAYER}.$"

LakeOfRage_Text_LanceRefused:
    .string "Oh… Se cambi idea,\n"
    .string "aiutaci.$"

LakeOfRage_Text_LanceAskHelp:
    .string "LANCE: Eh? Ci aiuti\n"
    .string "noi?$"

LakeOfRage_Text_GyaradosCry:
    .string "GYARADOS: Gyashaa!$"

LakeOfRage_Text_Gramps:
    .string "I GYARADOS sono furiosi!\p"
    .string "È un cattivo presagio!$"

LakeOfRage_Text_GrampsCleared:
    .string "Ahah! I MAGIKARP abboccano!$"

LakeOfRage_Text_SuperNerd:
    .string "Dicono che questo lago\n"
    .string "l'abbiano creato dei GYARADOS\p"
    .string "in furore.\n"
    .string "Chissà se c'entra la loro\l"
    .string "comparsa in massa?$"

LakeOfRage_Text_CooltrainerF:
    .string "Vedo male o c'era un\n"
    .string "GYARADOS rosso nel LAGO…\p"
    .string "Ma i GYARADOS non sono\n"
    .string "di solito blu?$"


LakeOfRage_Text_FisherAndreSeen:
    .string "Lotta col POKéMON che ho\n"
    .string "appena preso!$"

LakeOfRage_Text_FisherAndreBeaten:
    .string "Sarò un pescatore esperto,\n"
    .string "ma come allenatore faccio pena…$"

LakeOfRage_Text_FisherAndreAfter:
    .string "Non perdo come pescatore!\n"
    .string "Pesco POKéMON tutto il giorno.$"


LakeOfRage_Text_FisherRaymondSeen:
    .string "Faccio di tutto, ma prendo\n"
    .string "solo gli stessi POKéMON…$"

LakeOfRage_Text_FisherRaymondBeaten:
    .string "Ho il filo tutto aggrovigliato…$"

LakeOfRage_Text_FisherRaymondAfter:
    .string "Perché non prendo mai\n"
    .string "POKéMON forti?$"

LakeOfRage_Text_CooltrainermAaronSeen:
    .string "Se un allenatore ne vede un altro,\n"
    .string "deve sfidarlo.\p"
    .string "È il nostro destino.$"

LakeOfRage_Text_CooltrainermAaronBeaten:
    .string "Uff… Bella lotta.$"

LakeOfRage_Text_CooltrainermAaronAfter:
    .string "I POKéMON e il loro allenatore\n"
    .string "diventano forti lottando sempre.$"

LakeOfRage_Text_CooltrainerfLoisSeen:
    .string "Che fine ha fatto il\n"
    .string "GYARADOS rosso?\p"
    .string "È sparito?\p"
    .string "Oh, no. Sono venuta\n"
    .string "qui per niente?\p"
    .string "Sai che c'è? Lottiamo!$"

LakeOfRage_Text_CooltrainerfLoisBeaten:
    .string "Ben fatto!$"

LakeOfRage_Text_CooltrainerfLoisAfter:
    .string "A pensarci, ne ho visto uno\n"
    .string "di BUTTERFREE rosa.$"



LakeOfRage_EventScript_Wesley::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BLACK_BELT, LakeOfRage_EventScript_WesleyCompleted
	msgbox LakeOfRage_Text_MeetWesley, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, LakeOfRage_EventScript_WesleyNope
	case 1, LakeOfRage_EventScript_WesleyNope
	case 2, LakeOfRage_EventScript_WesleyNope
	case 3, LakeOfRage_EventScript_WesleyYes
	case 4, LakeOfRage_EventScript_WesleyNope
	case 5, LakeOfRage_EventScript_WesleyNope
	case 6, LakeOfRage_EventScript_WesleyNope
	case 7 LakeOfRage_EventScript_WesleyCancel
	case MULTI_B_PRESSED, LakeOfRage_EventScript_WesleyCancel
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyYes::
	msgbox LakeOfRage_Text_WesleyGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_BLACK_BELT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_BLACK_BELT
	msgbox LakeOfRage_Text_WesleyGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyNope::
	msgbox LakeOfRage_Text_WesleyNotWednesday, MSGBOX_DEFAULT
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyCancel::
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyCompleted::
	msgbox LakeOfRage_Text_WesleyWednesday, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_Text_MeetWesley:
    .string "WESLEY: Come va? Sono dei\p"
    .string "fratelli dei GIORNI!\n"
	.string "Indovini il mio giorno preferito?$"

LakeOfRage_Text_WesleyGivesGift:
    .string "Piacere! Prendi un\n"
    .string "ricordo.$"

LakeOfRage_Text_WesleyGaveGift:
    .string "WESLEY: La CINTURA NERA\n"
    .string "aumenta la forza delle mosse di Lotta.$"

LakeOfRage_Text_WesleyWednesday:
    .string "WESLEY: Se mi hai trovato,\n"
    .string "hai visto i miei fratelli.\l"
    .string "O sei stato solo\p"
    .string "fortunato?$"

LakeOfRage_Text_WesleyNotWednesday:
    .string "WESLEY: Non proprio…$"

LakeOfRage_EventScript_Sign1::
	msgbox LakeOfRage_Text_Sign, MSGBOX_SIGN
	end

LakeOfRage_EventScript_Sign2::
	msgbox LakeOfRage_Text_FishingGuruSign, MSGBOX_SIGN
	end

LakeOfRage_Text_Sign:
    .string "LAGO D'IRA,\n"
    .string "detto anche LAGO GYARADOS.$"

LakeOfRage_Text_FishingGuruSign:
    .string "CASA DEL GURU DELLA PESCA$"
