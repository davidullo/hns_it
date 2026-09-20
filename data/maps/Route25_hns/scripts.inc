Route25_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route25_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route25_MapScript_OnTransition::
	callnative SetTimeBasedEncounters
	goto_if_eq VAR_SUICUNE_ENCOUNTERS, 7, Route25_EventScript_SetSuicuneSceneMid
	end

Route25_EventScript_SetSuicuneSceneMid::
	setobjectxyperm LOCALID_ROUTE25_EUSINE, 98, 14
	end

Route25_EventScript_MistyRematch::
    lock
    faceplayer
    msgbox Route25_Text_Misty, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_CAPE_MISTY
    removeobject LOCALID_CAPE_MISTY
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_MISTY
    release
    end

Route25_Text_Misty:
    .string "MISTY: Adoro il tramonto qui!\n"
	.string "Mi dà il coraggio di andare\l"
	.string "avanti, sai?\p"
	.string "Già!\p"
	.string "Se vuoi un vero tuffo,\n"
	.string "ci vediamo al DOJO LOTTA!$"

Route25_EventScript_Dudley::
	trainerbattle_single TRAINER_DUDLEY_HNS, Route25_Text_SchoolboyDudleySeen, Route25_Text_SchoolboyDudleyBeaten
	msgbox Route25_Text_SchoolboyDudleyAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Ellen::
	trainerbattle_single TRAINER_ELLEN_HNS, Route25_Text_LassEllenSeen, Route25_Text_LassEllenBeaten
	msgbox Route25_Text_LassEllenAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Joe::
	trainerbattle_single TRAINER_JOE_HNS, Route25_Text_SchoolboyJoeSeen, Route25_Text_SchoolboyJoeBeaten
	msgbox Route25_Text_SchoolboyJoeAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Laura::
	trainerbattle_single TRAINER_LAURA_HNS, Route25_Text_LassLauraSeen, Route25_Text_LassLauraBeaten
	msgbox Route25_Text_LassLauraAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Lloyd::
	trainerbattle_single TRAINER_LLOYD_HNS, Route25_Text_CamperLloydSeen, Route25_Text_CamperLloydBeaten
	msgbox Route25_Text_CamperLloydAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Shannon::
	trainerbattle_single TRAINER_SHANNON_HNS, Route25_Text_LassShannonSeen, Route25_Text_LassShannonBeaten
	msgbox Route25_Text_LassShannonAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Pat::
	trainerbattle_single TRAINER_PAT_HNS, Route25_Text_SupernerdPatSeen, Route25_Text_SupernerdPatBeaten
	msgbox Route25_Text_SupernerdPatAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Kevin::
	lock
	faceplayer
	goto_if_set FLAG_ROUTE25_GOT_NUGGET, Route25_EventScript_KevinAfter
	msgbox Route25_Text_CooltrainerKevinNugget, MSGBOX_DEFAULT
	giveitem ITEM_BIG_NUGGET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_ROUTE25_GOT_NUGGET
	msgbox Route25_Text_CooltrainerKevinSeen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KEVIN_HNS, Route25_Text_CooltrainerKevinBeaten
	msgbox Route25_Text_CooltrainerKevinAfter, MSGBOX_DEFAULT
	closemessage
	release
	end
Route25_EventScript_KevinAfter::
	msgbox Route25_Text_CooltrainerKevinAfter, MSGBOX_NPC
	end

Route25_EventScript_BillsHouseSign::
	msgbox Route25_Text_BillsHouseSign, MSGBOX_SIGN
	end

Route25_Trigger_MistyRight::
	lock
	turnobject LOCALID_ROUTE25_MISTY, DIR_SOUTH
	delay 40
	turnobject LOCALID_ROUTE25_MAN, DIR_SOUTH
	playse SE_PIN
	applymovement2 LOCALID_ROUTE25_MAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ROUTE25_MAN
	applymovement2 LOCALID_ROUTE25_MAN, Route25_Movement_ManLeaveRight
	waitmovement 0
	applymovement2 LOCALID_ROUTE25_MISTY, Route25_Movement_MistyWalkToPlayerRight
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	goto Route25_EventScript_Misty
Route25_Trigger_MistyLeft::
	lock
	turnobject LOCALID_ROUTE25_MISTY, DIR_SOUTH
	delay 40
	turnobject LOCALID_ROUTE25_MAN, DIR_SOUTH
	playse SE_PIN
	applymovement2 LOCALID_ROUTE25_MAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ROUTE25_MAN
	applymovement2 LOCALID_ROUTE25_MAN, Route25_Movement_ManLeaveLeft
	waitmovement 0
	applymovement2 LOCALID_ROUTE25_MISTY, Route25_Movement_MistyWalkToPlayerLeft
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	goto Route25_EventScript_Misty
Route25_EventScript_Misty::
	msgbox Route25_Text_MistyDate, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_ROUTE25_MISTY, Route25_Movement_MistyLeave
	waitmovement 0
	removeobject LOCALID_ROUTE25_MISTY
	removeobject LOCALID_ROUTE25_MAN
	setflag FLAG_HIDE_ROUTE25_MISTY
	clearflag FLAG_HIDE_CERULEAN_GYM_TRAINERS
	setflag FLAG_HIDE_CERULEAN_GYM_POKEMON
	setvar VAR_CERULEAN_CITY_STATE, 3
	release
	end

Route25_Trigger_SuicuneLeft::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE25_SUICUNE, Route25_Movement_Suicune1
	playse SE_LEDGE
	waitse
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Route25_Movement_WalkToSuicune
	waitmovement 0
	goto Route25_EventScript_SuicuneMerge
Route25_Trigger_SuicuneRight::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE25_SUICUNE, Route25_Movement_Suicune1
	playse SE_LEDGE
	waitse
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Route25_Movement_WalkToSuicune
	waitmovement 0
	goto Route25_EventScript_SuicuneMerge
Route25_EventScript_SuicuneMerge::
	clearflag FLAG_HIDE_ROUTE25_EUSINE
	addobject LOCALID_ROUTE25_EUSINE
	applymovement LOCALID_ROUTE25_EUSINE, Route25_Movement_EusineEnter
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	msgbox Route25_Text_Eusine1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE25_EUSINE, Route25_Movement_EusineSide
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox Route25_Text_Eusine2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SUICUNE_ENCOUNTERS, 7
	release
	end
	
Route25_Trigger_SuicuneRightRight::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	goto Route25_Trigger_SuicuneRight
Route25_Trigger_SuicuneLeftLeft::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	goto Route25_Trigger_SuicuneLeft

Route25_Text_Eusine1:
	.string "ANGELO: Puff, puff...\n"
	.string "Non sono... all'altezza di te.\p"
	.string "...Come avevo previsto.\n"
	.string "..........................\l"
	.string "... Vai pure.\p"
	.string "Da quando ti ho incontrato alla TORRE\n"
	.string "BRUCIATA di ECRUTEAK CITY, sapevo\l"
	.string "che SUICUNE avrebbe scelto\l"
	.string "te.$"

Route25_Text_Eusine2:
	.string "Take a look at it!\p"
	.string "SUICUNE is waiting for you!\n"
	.string "It has been waiting for a battle\l"
	.string "with a worthy trainer to whom it\l"
	.string "can entrust itself.$"

Route25_Text_Eusine3:
	.string "{PLAYER}...\n"
	.string "Voi due siete davvero incredibili...\p"
	.string "Non ho mai visto una lotta così\n"
	.string "intensa!\l"
	.string "Non ho rimpianti...\p"
	.string "Addio, SUICUNE!\n"
	.string "Addio... {PLAYER}!$"

Route25_EventScript_Eusine::
	msgbox Route25_Text_Eusine2, MSGBOX_NPC
	end

Route25_EventScript_Suicune::
	lock
	faceplayer
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE25_SUICUNE, Route25_Movement_Suicune1
	playse SE_LEDGE
	waitse
	waitmovement 0
	playmoncry SPECIES_SUICUNE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	seteventmon SPECIES_SUICUNE, 50
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route25_EventScript_SuicuneRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_ROUTE25_SUICUNE
	setflag FLAG_HIDE_ROUTE25_SUICUNE
	fadescreenswapbuffers FADE_FROM_BLACK
	goto_if_ge VAR_SUICUNE_ENCOUNTERS, 8, Route25_EventScript_SuicunePostGame
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 99, Route25_AdjustPlayer
	call_if_eq VAR_TEMP_0, 100, Route25_AdjustPlayerTwice
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	turnobject LOCALID_ROUTE25_EUSINE, DIR_NORTH
	msgbox Route25_Text_Eusine3, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_ROUTE25_EUSINE, Route25_Movement_EusineLeave
	waitmovement 0
	removeobject LOCALID_ROUTE25_EUSINE
	setflag FLAG_HIDE_ROUTE25_EUSINE
	clearflag FLAG_HIDE_CELADON_EUSINE
	setvar VAR_SUICUNE_ENCOUNTERS, 8
	release
	end

Route25_EventScript_SuicuneRan::
	release
	end

Route25_AdjustPlayer::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	return

Route25_AdjustPlayerTwice::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	return

Route25_EventScript_SuicunePostGame::
	release
	end

Route25_Movement_EusineLeave:
	walk_down
	walk_down
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Route25_Movement_EusineSide:
	walk_slow_left
	walk_slow_up
	step_end

Route25_Movement_EusineEnter:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_slow_up
	step_end

Route25_Movement_Suicune1:
	jump_in_place_down
	step_end

Route25_Movement_WalkToSuicune:
	walk_up
	walk_up
	step_end

Route25_Movement_MistyLeave:
	walk_down
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

Route25_Movement_ManLeaveRight:
	walk_fast_left
	walk_fast_left
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
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end
Route25_Movement_ManLeaveLeft:
	walk_fast_left
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
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route25_Movement_MistyWalkToPlayerRight:
	walk_fast_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	face_right
	step_end
Route25_Movement_MistyWalkToPlayerLeft:
	walk_fast_left
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	step_end

Route25_Text_MistyDate:
	.string "MISTY: Oh! Perché sei dovuto\n"
	.string "comparire proprio ora a seccarci?\p"
	.string "Sai come chiamano\n"
	.string "quelli come te?\p"
	.string "Seccatori! Hai capito bene,\n"
	.string "seccatore!\p"
	.string "…\p"
	.string "…Oh? Quelle MEDAGLIE che hai…\n"
	.string "Sono MEDAGLIE della PALESTRA di JOHTO?\p"
	.string "Se ne hai otto, devi essere\n"
	.string "bravo.\p"
	.string "Va bene. Vieni alla PALESTRA di CERULEAN.\p"
	.string "Sarò felice di affrontarti.\p"
	.string "Sono MISTY, la CAPOPALESTRA di\n"
	.string "CERULEAN.$"

Route25_Text_SchoolboyDudleySeen:
	.string "Beat the six of us trainers to\n"
	.string "win a fabulous prize!\p"
	.string "Think you've got what it takes?$"

Route25_Text_SchoolboyDudleyBeaten:
	.string "Uao! Roba buona.$"

Route25_Text_SchoolboyDudleyAfter:
	.string "Ho dato il massimo.\n"
	.string "Non ho rimpianti.$"

Route25_Text_LassEllenSeen:
	.string "Sono la seconda.\n"
	.string "Ora faccio sul serio!$"

Route25_Text_LassEllenBeaten:
	.string "Come ho potuto perdere?$"

Route25_Text_LassEllenAfter:
	.string "Ho dato il massimo.\n"
	.string "Non ho rimpianti.$"

Route25_Text_SchoolboyJoeSeen:
	.string "Ecco il n. 3!\n"
	.string "Non sarò facile.$"

Route25_Text_SchoolboyJoeBeaten:
	.string "Ahia! Mi hai schiacciato!$"

Route25_Text_SchoolboyJoeAfter:
	.string "Ho dato il massimo.\n"
	.string "Non ho rimpianti.$"

Route25_Text_LassLauraSeen:
	.string "Sono la n. 4!\n"
	.string "Ti stanchi?$"

Route25_Text_LassLauraBeaten:
	.string "Ho perso anch'io…$"

Route25_Text_LassLauraAfter:
	.string "Ho dato il massimo.\n"
	.string "Non ho rimpianti.$"

Route25_Text_CamperLloydSeen:
	.string "OK! Sono il n. 5.\n"
	.string "Ti pesto!$"

Route25_Text_CamperLloydBeaten:
	.string "Uau! Troppo forte.$"

Route25_Text_CamperLloydAfter:
	.string "Ho dato il massimo.\n"
	.string "Non ho rimpianti.$"

Route25_Text_LassShannonSeen:
	.string "Sono l'ultima della fila, ma\n"
	.string "ti dico, sono tosta!$"

Route25_Text_LassShannonBeaten:
	.string "Stai scherzando.$"

Route25_Text_LassShannonAfter:
	.string "Ho dato il massimo.\n"
	.string "Non ho rimpianti.$"

Route25_Text_SupernerdPatSeen:
	.string "Mufufufu…\p"
	.string "Non c'entro nulla con gli\n"
	.string "allenatori dei sei.\p"
	.string "Ti ho aspettato qui per batterti\n"
	.string "mentre eri stanco per tutte\l"
	.string "le lotte.$"

Route25_Text_SupernerdPatBeaten:
	.string "Non sei stanco per niente?$"

Route25_Text_SupernerdPatAfter:
	.string "Mi dispiace… non imbroglierò\n"
	.string "più…$"

Route25_Text_CooltrainerKevinNugget:
	.string "Hai affrontato una lotta in più\n"
	.string "del previsto, ma hai vinto\l"
	.string "comunque.\p"
	.string "Come promesso, ecco un premio.$"

Route25_Text_CooltrainerKevinSeen:
	.string "Ma vedendoti lottare,\n"
	.string "voglio mettermi alla prova.\p"
	.string "Che ne dici? Ti sfido.\n"
	.string "Forza.$"

Route25_Text_CooltrainerKevinBeaten:
	.string "Non ho mai fatto una lotta\n"
	.string "così bella!$"

Route25_Text_CooltrainerKevinAfter:
	.string "Che bella lotta!\p"
	.string "Tu e i tuoi POKéMON siete\n"
	.string "eccezionali!$"

Route25_Text_BillsHouseSign:
	.string "CASA DEL MARE\n"
	.string "CASA DI BILL$"

