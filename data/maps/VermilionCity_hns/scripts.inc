VermilionCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

VermilionCity_MapScript_OnTransition::
	setflag FLAG_VISITED_VERMILION_CITY
	goto_if_eq VAR_SUICUNE_ENCOUNTERS, 3, VermilionCity_EventScript_SetSuicuneScene
	setflag FLAG_HIDE_VERMILION_EUSINE_SUICUNE
	callnative SetTimeBasedEncounters
	end

VermilionCity_EventScript_SetSuicuneScene::
	clearflag FLAG_HIDE_VERMILION_EUSINE_SUICUNE
	callnative SetTimeBasedEncounters
	end

VermilionCity_EventScript_OldSeaMap::
	finditem ITEM_OLD_SEA_MAP
	end

VermilionCity_TriggerSuicuneNorth_Left::
	lock
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	goto VermilionCity_TriggerSuicuneNorth_Merge
VermilionCity_TriggerSuicuneNorth_Mid::
	lock
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	goto VermilionCity_TriggerSuicuneNorth_Merge
VermilionCity_TriggerSuicuneNorth_Right::
	lock
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	goto VermilionCity_TriggerSuicuneNorth_Merge
VermilionCity_TriggerSuicuneNorth_Merge::
	applymovement OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_NorthSuicune_PlayerWalkDown
	waitmovement 0
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement2 LOCALID_VERMILION_SUICUNE, VermilionCity_Movement_Suicune1
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_NorthSuicune_PlayerWalkDown
	delay 60
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	applymovement2 LOCALID_VERMILION_EUSINE, VermilionCity_Movement_EusineWalkToRail
	waitmovement LOCALID_VERMILION_EUSINE
	waitmovement OBJ_EVENT_ID_PLAYER
	goto VermilionCity_EventScript_SuicuneEpisode

VermilionCity_Movement_NorthSuicune_PlayerWalkDown:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

VermilionCity_TriggerSuicuneTop::
	lock
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement2 LOCALID_VERMILION_SUICUNE, VermilionCity_Movement_Suicune1
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_PlayerWalkToRailTop
	delay 60
	applymovement2 LOCALID_VERMILION_EUSINE, VermilionCity_Movement_EusineWalkToRail
	waitmovement LOCALID_VERMILION_EUSINE
	waitmovement OBJ_EVENT_ID_PLAYER
	goto VermilionCity_EventScript_SuicuneEpisode
VermilionCity_TriggerSuicuneMid::
	lock
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement2 LOCALID_VERMILION_SUICUNE, VermilionCity_Movement_Suicune1
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_PlayerWalkToRailMid
	delay 60
	applymovement2 LOCALID_VERMILION_EUSINE, VermilionCity_Movement_EusineWalkToRail
	waitmovement LOCALID_VERMILION_EUSINE
	waitmovement OBJ_EVENT_ID_PLAYER
	goto VermilionCity_EventScript_SuicuneEpisode
VermilionCity_TriggerSuicuneBot::
	lock
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement2 LOCALID_VERMILION_SUICUNE, VermilionCity_Movement_Suicune1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_PlayerWalkToRailBot
	waitmovement 0
	applymovement2 LOCALID_VERMILION_EUSINE, VermilionCity_Movement_EusineWalkToRail
	waitmovement LOCALID_VERMILION_EUSINE
	waitmovement OBJ_EVENT_ID_PLAYER
	goto VermilionCity_EventScript_SuicuneEpisode

VermilionCity_EventScript_SuicuneEpisode::
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement2 LOCALID_VERMILION_SUICUNE, VermilionCity_Movement_SuicuneLeave
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	waitmovement 0
	msgbox VermilionCity_Text_Eusine, MSGBOX_DEFAULT
	turnobject LOCALID_VERMILION_EUSINE, DIR_SOUTH
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox VermilionCity_Text_Eusine2, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_VERMILION_EUSINE, VermilionCity_Movement_EusineLeave
	waitmovement 0
	removeobject LOCALID_VERMILION_EUSINE
	removeobject LOCALID_VERMILION_SUICUNE
	setflag FLAG_HIDE_VERMILION_EUSINE_SUICUNE

	setvar VAR_SUICUNE_ENCOUNTERS, 4
	clearflag FLAG_HIDE_ROUTE14_SUICUNE
	release
	end

VermilionCity_EventScript_Teacher::
	msgbox VermilionCity_Text_Teacher, MSGBOX_NPC
	end

VermilionCity_EventScript_Oldman::
	msgbox VermilionCity_Text_MachopOwner, MSGBOX_NPC
	end

VermilionCity_EventScript_Machop::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
	msgbox VermilionCity_Text_Machop1, MSGBOX_DEFAULT
	waitmoncry
	msgbox VermilionCity_Text_Machop2, MSGBOX_DEFAULT
	release
	end

VermilionCity_EventScript_Nerd::
	msgbox VermilionCity_Text_SuperNerd, MSGBOX_NPC
	end

VermilionCity_EventScript_Snorlax::
	lock
	special CheckRadioStation
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_SnorlaxWakeUp
	@goto_if_set FLAG_KANTO_RADIO_GOT, VermilionCity_EventScript_SnorlaxWakeUp
	msgbox VermilionCity_Text_SnorlaxSleeping, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_EventScript_SnorlaxWakeUp::
    playbgm MUS_HG_RADIO_POKE_FLUTE, FALSE
    msgbox VermilionCity_Text_RadioNearSnorlax, MSGBOX_DEFAULT
    playmoncry SPECIES_SNORLAX, CRY_MODE_ENCOUNTER
    delay 40
    waitmoncry
    setwildbattle SPECIES_SNORLAX, 50
    dowildbattle
    specialvar VAR_RESULT, GetBattleOutcome
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VermilionCity_EventScript_SnorlaxRan
    fadescreenswapbuffers FADE_TO_BLACK
    removeobject LOCALID_VERMILION_SNORLAX
    removeobject 8
    removeobject 9
    removeobject 10
    removeobject 11
    setflag FLAG_HIDE_VERMILION_SNORLAX
    fadescreenswapbuffers FADE_FROM_BLACK
    setflag FLAG_INDIGOJUNCTION_HIDE_KANTO_GUARD
    fadedefaultbgm
    release
    end

VermilionCity_EventScript_SnorlaxRan::
    fadedefaultbgm
    release
    end

VermilionCity_EventScript_BadgeGuy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_VERMILION_HP_UP, VermilionCity_EventScript_BadgeGuyAfter
	goto_if_ge VAR_NUM_BADGES, 16, VermilionCity_EventScript_BadgeGuyAll
	goto_if_ge VAR_NUM_BADGES, 12, VermilionCity_EventScript_BadgeGuyMost
	goto_if_ge VAR_NUM_BADGES, 9, VermilionCity_EventScript_BadgeGuySome
	msgbox VermilionCity_Text_BadgeGuy_Trainer, MSGBOX_DEFAULT
	closemessage
	release
	end
VermilionCity_EventScript_BadgeGuySome::
	msgbox VermilionCity_Text_BadgeGuy_SomeBadges, MSGBOX_DEFAULT
	closemessage
	release
	end
VermilionCity_EventScript_BadgeGuyMost::
	msgbox VermilionCity_Text_BadgeGuy_MostBadges, MSGBOX_DEFAULT
	closemessage
	release
	end
VermilionCity_EventScript_BadgeGuyAll::
	msgbox VermilionCity_Text_BadgeGuy_AllBadges, MSGBOX_DEFAULT
	giveitem ITEM_HP_UP
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_VERMILION_HP_UP
	closemessage
	release
	end
VermilionCity_EventScript_BadgeGuyAfter::
	msgbox VermilionCity_Text_BadgeGuy_BattleEdge, MSGBOX_DEFAULT
	closemessage
	release
	end


VermilionCity_Movement_Suicune1:
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	step_end

VermilionCity_Movement_PlayerWalkToRailTop: @goal tile = 51, 28
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	step_end
VermilionCity_Movement_PlayerWalkToRailMid:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_right
	step_end
VermilionCity_Movement_PlayerWalkToRailBot:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

VermilionCity_Movement_EusineWalkToRail:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	step_end

VermilionCity_Movement_SuicuneLeave:
	jump_in_place_left
	jump_2_right
	jump_2_right
	jump_2_right
	step_end

VermilionCity_Movement_EusineLeave:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

VermilionCity_Text_Eusine:
	.string "EUSINE: Ci siamo quasi!\n"
	.string "Pensavo di poterlo mettere alle\l"
	.string "strette tendendogli un'imboscata.\p"
	.string "Ma correre sull'acqua è oltre\n"
	.string "le mie capacità.\p"
	.string "Però comincio a vedere\n"
	.string "uno schema.\p"
	.string "SUICUNE preferisce l'acqua!\p"
	.string "Il che significa…$"

VermilionCity_Text_Eusine2:
	.string "Scusa {PLAYER}, devo andare!$"

VermilionCity_Text_Teacher:
	.string "Il PORTO DI VERMILION è la porta\n"
	.string "sul mare di KANTO.\p"
	.string "Transatlantici di lusso da tutto\n"
	.string "il mondo attraccano qui.$"

VermilionCity_Text_MachopOwner:
	.string "Il mio POKéMON prepara il terreno\n"
	.string "per la costruzione.\p"
	.string "Ma non ho i soldi per iniziare il\n"
	.string "progetto…$"

VermilionCity_Text_Machop1:
	.string "MACHOP: Guooh gogogoh!$"

VermilionCity_Text_Machop2:
	.string "Un MACHOP ringhia mentre\n"
	.string "spiana il terreno a colpi di piede.$"

VermilionCity_Text_SuperNerd:
	.string "Ci sono otto PALESTRE a KANTO.\p"
	.string "Quel grande edificio è la\n"
	.string "PALESTRA POKéMON di VERMILION.$"

VermilionCity_Text_SnorlaxSleeping:
	.string "SNORLAX dorme serenamente…$"

VermilionCity_Text_RadioNearSnorlax:
	.string "Il POKéGEAR è stato messo vicino\n"
	.string "allo SNORLAX addormentato…\p"
	.string "…\p"
	.string "SNORLAX si è svegliato!$"

VermilionCity_Text_BadgeGuy_Trainer:
	.string "Allenatori abili si radunano a KANTO.\p"
	.string "I CAPOPALESTRA sono molto forti.\p"
	.string "Non sarà facile batterli.$"

VermilionCity_Text_BadgeGuy_SomeBadges:
	.string "Hai iniziato a collezionare le MEDAGLIE\n"
	.string "PALESTRA di KANTO?\p"
	.string "Non trovi che gli allenatori\n"
	.string "qui siano forti?$"

VermilionCity_Text_BadgeGuy_MostBadges:
	.string "Immagino che finirai presto\n"
	.string "la tua conquista delle PALESTRE di KANTO.\p"
	.string "Fammi sapere quando avrai tutte e otto\n"
	.string "le MEDAGLIE.$"

VermilionCity_Text_BadgeGuy_AllBadges:
	.string "Congratulazioni!\p"
	.string "Hai tutte le MEDAGLIE PALESTRA di KANTO.\p"
	.string "Ho una ricompensa per i tuoi sforzi.$"

VermilionCity_Text_BadgeGuy_BattleEdge:
	.string "Avere POKéMON di tipi diversi\n"
	.string "ti dà un vantaggio in battaglia.\p"
	.string "Sono certo che le MEDAGLIE di KANTO\n"
	.string "ti aiuteranno.$"

VermilionCity_EventScript_CitySign::
	msgbox VermilionCity_Text_Sign, MSGBOX_SIGN
	end
VermilionCity_EventScript_GymSign::
	msgbox VermilionCity_Text_GymSign, MSGBOX_SIGN
	end
VermilionCity_EventScript_FanClubSign::
	msgbox VermilionCity_Text_FanClubSign, MSGBOX_SIGN
	end
VermilionCity_EventScript_DiglettsCaveSign::
	msgbox VermilionCity_Text_DiglettsCaveSign, MSGBOX_SIGN
	end

VermilionCity_Text_Sign:
	.string "ARANCIOPOLI\p"
	.string "Il porto dai tramonti splendidi$"

VermilionCity_Text_GymSign:
	.string "ARANCIOPOLI\n"
	.string "PALESTRA POKéMON\p"
	.string "CAPOPALESTRA: LT. SURGE\p"
	.string "L'americano fulmineo$"

VermilionCity_Text_FanClubSign:
	.string "FAN CLUB POKéMON\p"
	.string "Tutti i fan dei POKéMON sono benvenuti!$"

VermilionCity_Text_DiglettsCaveSign:
	.string "GROTTA DIGLETT$"

VermilionCity_Text_PortSign:
	.string "PORTO DI VERMILION\n"
	.string "INGRESSO$"

VermilionCity_EventScript_TriggerStevenLeft::
	lock
	playse SE_PIN
	applymovement2 LOCALID_PLAYER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_PLAYER
	applymovement2 LOCALID_VERMILIONCITY_STEVEN, Common_Movement_WalkLeft1
	waitmovement 0
	call VermilionCity_EventScript_LatiChoice
	applymovement2 LOCALID_VERMILIONCITY_STEVEN, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 LOCALID_VERMILIONCITY_STEVEN, VermilionCity_Movement_StevenWalkToPlayer
	waitmovement 0
	applymovement2 LOCALID_VERMILIONCITY_STEVEN, Common_Movement_WalkDown1
	waitmovement 0
	setvar VAR_VERMILION_CITY_STEVEN, 1
	removeobject LOCALID_VERMILIONCITY_STEVEN
	release
	end

VermilionCity_EventScript_TriggerStevenMiddle::
	lock
	playse SE_PIN
	applymovement2 LOCALID_PLAYER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_PLAYER
	call VermilionCity_EventScript_LatiChoice
	applymovement2 LOCALID_VERMILIONCITY_STEVEN, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 LOCALID_VERMILIONCITY_STEVEN, VermilionCity_Movement_StevenWalkToPlayer
	waitmovement 0
	applymovement2 LOCALID_VERMILIONCITY_STEVEN, Common_Movement_WalkDown1
	waitmovement 0
	setvar VAR_VERMILION_CITY_STEVEN, 1
	removeobject LOCALID_VERMILIONCITY_STEVEN
	release
	end
 
VermilionCity_EventScript_TriggerStevenRight::
	lock
	playse SE_PIN
	applymovement2 LOCALID_PLAYER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_PLAYER
	applymovement2 LOCALID_VERMILIONCITY_STEVEN, Common_Movement_WalkRight1
	waitmovement 0
	call VermilionCity_EventScript_LatiChoice
	applymovement2 LOCALID_VERMILIONCITY_STEVEN, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 LOCALID_VERMILIONCITY_STEVEN, VermilionCity_Movement_StevenWalkToPlayer
	waitmovement 0
	applymovement2 LOCALID_VERMILIONCITY_STEVEN, Common_Movement_WalkDown1
	waitmovement 0
	setvar VAR_VERMILION_CITY_STEVEN, 1
	removeobject LOCALID_VERMILIONCITY_STEVEN
	release
	end


VermilionCity_EventScript_LatiChoice::
	applymovement2 LOCALID_VERMILIONCITY_STEVEN, VermilionCity_Movement_StevenWalkToPlayer
	waitmovement LOCALID_VERMILIONCITY_STEVEN
	msgbox VermilionCity_Text_StevenIntro, MSGBOX_DEFAULT
	multichoice 20, 8, MULTI_TV_LATI, TRUE
	@goto_if_eq VAR_RESULT, MULTI_B_PRESSED, VermilionCity_EventScript_LatiCancel
	copyvar VAR_0x8004, VAR_RESULT
	copyvar VAR_ROAMER_POKEMON_HNS, VAR_RESULT
	special InitKantoRoamers
	setflag FLAG_LATIOS_OR_LATIAS_ROAMING
	msgbox VermilionCity_Text_StevenOutro, MSGBOX_DEFAULT
	closemessage
	return

VermilionCity_Movement_StevenWalkToPlayer:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_down
	step_end

VermilionCity_Text_StevenIntro:
	.string "Ciao!\n"
	.string "Mi chiamo Steven.\l"
	.string "Il Campione della regione di HOENN.\p"
	.string "Ci siamo già visti… prima?\p"
	.string "Non è possibile. \n"
	.string "I trainers che ho sfidato\l"
	.string "mi sembrano tutti uguali, comunque.\p"
	.string "Soprattutto quelli che mi hanno\n"
	.string "dato filo da torcere.\p"
	.string "Sono a KANTO per lavoro.\n"
	.string "Ultimamente molti POKéMON di HOENN sono\l"
	.string "migrati in questa regione.\l"
	.string "Quest'afflusso rischia di sconvolgere\l"
	.string "l'ecosistema naturale di qui.\p"
	.string "Così, con l'aiuto della mia azienda,\n"
	.string "sto creando un habitat speciale\l"
	.string "per attirare e contenere le specie\l"
	.string "più invasive.\p"
	.string "Tieni gli occhi aperti\n"
	.string "e cattura i POKéMON di HOENN che vedi.\p"
	.string "Alcuni trainers hanno persino segnalato\n"
	.string "uno che sfreccia nel cielo come\l"
	.string "un jet… Di che colore era, già?$"

VermilionCity_Text_StevenOutro:
	.string "Ah, giusto.\p"
	.string "Devo andare.\n"
	.string "Che i nostri viaggi si incrocino ancora.$"

VermilionCity_EventScript_TriggerSamson::
	lock
	clearflag FLAG_HIDE_VERMILION_CITY_SAMSON
	addobject LOCALID_VERMILION_CITY_SAMSON
	playse SE_BANG
	applymovement LOCALID_VERMILION_CITY_SAMSON, VermilionCity_Movement_SamsonEnter
	applymovement LOCALID_PLAYER, VermilionCity_Movement_PlayerSlideback
	waitmovement LOCALID_VERMILION_CITY_SAMSON
	waitmovement LOCALID_PLAYER
	msgbox VermilionCity_Text_Samson, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VERMILION_CITY_SAMSON, VermilionCity_Movement_SamsonLeave
	waitmovement LOCALID_VERMILION_CITY_SAMSON
	removeobject LOCALID_VERMILION_CITY_SAMSON
	setflag FLAG_HIDE_VERMILION_CITY_SAMSON
	setvar VAR_VERMILION_CITY_SAMSON, 2
	release
	end

VermilionCity_Movement_PlayerSlideback:
	lock_facing_direction
	walk_fast_down
	walk_fast_down
	unlock_facing_direction
	step_end

VermilionCity_Movement_SamsonEnter:
	walk_fast_down
	walk_fast_down
	step_end

VermilionCity_Movement_SamsonLeave:
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
	walk_fast_right
	step_end

VermilionCity_Text_Samson:
	.string "Uau!\p"
	.string "Scusa piccolo, ho fretta!\p"
	.string "Il traghetto sulla PERCORSO 13\n"
	.string "partirà presto per le ISOLE,\l"
	.string "e devo esserci anche io!\p"
	.string "Fiuh... Fiuh...\p"
	.string "Ho corso fin qui da\n"
	.string "MONTE LUNA.\p"
	.string "Vedi questo gingillo?\p"
	.string "Ho preso questo SOUVENIR STRANO\n"
	.string "al NEGOZIO DI SOUVENIR.\p"
	.string "È il mio biglietto per le ISOLE.\p"
	.string "Beh, ci vediamo!$"
