SinjohRuins_House1_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SinjohRuins_Lab_OnFrame
	map_script 	MAP_SCRIPT_ON_TRANSITION, SinjohRuins_Lab_OnTransition
	.byte 0

SinjohRuins_Lab_OnTransition::
	call_if_eq VAR_SINJOH_STORYLINE, 7, SinjohRuins_Lab_SetupFinalPlateScene
	end

SinjohRuins_Lab_OnFrame::
	map_script_2 VAR_SINJOH_STORYLINE, 7, SinjohRuins_Lab_FinalPlateScene
	.2byte 0

@==========================Intro Cutscene SCRIPTS================================================================================

SinjohRuins_Lab_EventScript_TriggerIntroTop::
	lock
	playse SE_PIN
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene1, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_PLAYER, Common_Movement_WalkDown1
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenMeetPlayer
	waitmovement 0
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	goto SinjohRuins_Lab_EventScript_TriggerIntro

SinjohRuins_Lab_EventScript_TriggerIntroMid::
	lock
	playse SE_PIN
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene1, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenMeetPlayer
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	goto SinjohRuins_Lab_EventScript_TriggerIntro

SinjohRuins_Lab_EventScript_TriggerIntroBot::
	lock
	playse SE_PIN
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene1, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_PLAYER, Common_Movement_WalkUp1
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenMeetPlayer
	waitmovement 0
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	goto SinjohRuins_Lab_EventScript_TriggerIntro

SinjohRuins_Lab_EventScript_TriggerIntro::
	turnobject LOCALID_PLAYER, DIR_EAST
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene2, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenSitsDown
	delay 10
	applymovement LOCALID_PLAYER, SinjohRuins_Lab_Movement_PlayerGoesToTable
	delay 40
	applymovement2 LOCALID_NEWSINJOH_LAB_LINGUIST, SinjohRuins_Lab_Movement_LinguistWalkDown
	waitmovement 0
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	waitmovement LOCALID_NEWSINJOH_LAB_LINGUIST
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene3, MSGBOX_DEFAULT
	closemessage
	delay 10
	applymovement2 LOCALID_NEWSINJOH_LAB_LINGUIST, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene4, MSGBOX_DEFAULT
	closemessage
	delay 10
	applymovement LOCALID_NEWSINJOH_LAB_LINGUIST, SinjohRuins_Lab_Movement_LinguistWalkUp
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene5, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, SinjohRuins_Lab_EventScript_IntroChoseYes
SinjohRuins_Lab_EventScript_IntroChoice::
	msgbox SinjohRuins_Lab_Text_StevenIntroCutsceneRefused, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, SinjohRuins_Lab_EventScript_IntroChoseYes
	goto SinjohRuins_Lab_EventScript_IntroChoice

SinjohRuins_Lab_EventScript_IntroChoseYes::
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene6, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SINJOH_STORYLINE, 6
	setvar VAR_NOBLE_SNEASLER, 1
	setvar VAR_NOBLE_OVERQWIL, 1
	setvar VAR_NOBLE_WYRDEER, 1
	setvar VAR_NOBLE_ARCANINE, 1
	setvar VAR_NOBLE_URSALUNA, 1
	setvar VAR_NOBLE_KLEAVOR, 1
	setvar VAR_NOBLE_ELECTRODE, 1
	setvar VAR_NOBLE_TYPHLOSION, 1
	release
	end

SinjohRuins_Lab_Movement_StevenMeetPlayer:
	walk_up
	walk_up
	walk_up
	face_left
	step_end

SinjohRuins_Lab_Movement_StevenSitsDown:
	walk_down
	walk_down
	walk_down
	face_right
	step_end

SinjohRuins_Lab_Movement_PlayerGoesToTable:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	face_left
	step_end

SinjohRuins_Lab_Movement_LinguistWalkDown:
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	face_down
	step_end

SinjohRuins_Lab_Movement_LinguistWalkUp:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	step_end


SinjohRuins_Lab_Text_StevenIntroCutscene1:
   	.string "RUPERT: Hm?$"

SinjohRuins_Lab_Text_StevenIntroCutscene2:
	.string "STEVEN: {PLAYER}!\p"
	.string "Riconoscerei quei tuoi occhi ovunque.\p"
	.string "Cosa ti porta così a nord?\p"
	.string ".............\p"
	.string "Capisco, le KIMONO GIRL di NEW ROVINE SINJOH\n"
	.string "ti hanno mandato ad aiutarci\l"
	.string "nella ricerca.\p"
	.string "In tal caso, lascia che ti\n"
	.string "aggiorni.$"

SinjohRuins_Lab_Text_StevenIntroCutscene3:
	.string "STEVEN: Quando ho saputo di\n"
	.string "queste rovine, sono dovuto venire\l"
	.string "a vederle di persona.\p"
	.string "Ho messo su una squadra della DEVON SPA.\n"
	.string "e siamo partiti per una spedizione\l"
	.string "di ricerca.\p"
	.string "Chissà cosa troveremo sepolto\n"
	.string "qui.\p"
	.string "Abbiamo già imparato\n"
	.string "parecchio.$"

SinjohRuins_Lab_Text_StevenIntroCutscene4:
	.string "LINGUISTA: La traduzione completa\n"
	.string "dei glifi trovati attorno alle rovine\l"
	.string "mi sfugge ancora, ma sono riuscito\l"
	.string "a decifrarne alcuni aspetti.\p"
	.string "Ci sono 17 PIASTRE singolari.\p"
	.string "Hanno un certo significato\n"
	.string "per le rovine, ma ne abbiamo\l"
	.string "trovata solo 1 finora.\p"
	.string "Si dice che le altre siano custodite\n"
	.string "da POKéMON e allenatori di\l"
	.string "enorme potenza.$"

SinjohRuins_Lab_Text_StevenIntroCutscene5:
	.string "STEVEN: Questo è quanto, {PLAYER}.\p"
	.string "I NOBILI POKéMON che custodiscono le\n"
	.string "PIASTRE rimaste sono troppo forti\l"
	.string "per la mia squadra, temo.\p"
	.string "E io devo restare qui a seguire\n"
	.string "la ricerca.\p"
	.string "Ma credo che tu potresti farcela.\n"
	.string "Ci aiuterai?$"

SinjohRuins_Lab_Text_StevenIntroCutscene6:
	.string "Ottimo.\p"
	.string "I glifi dicono che le PIASTRE sono\n"
	.string "tenute da NOBILI POKéMON e\l"
	.string "da allenatori forti di tutto ROVINE SINJOH.\p"
	.string "Ti chiamerò sul POKéGEAR se\n"
	.string "scopriamo qualcosa.\p"
	.string "Grazie, {PLAYER}.$"

SinjohRuins_Lab_Text_StevenIntroCutsceneRefused:
	.string "Sei sicuro?\p"
	.string "Chissà cosa troveremo sepolto\n"
	.string "qui.\p"
	.string "Non ci ripensi?$"

@==========================Final plate Cutscene SCRIPTS================================================================================

SinjohRuins_Lab_SetupFinalPlateScene::
	setobjectxyperm LOCALID_SINJOHRUINS_LAB_STEVEN, 4, 7
	setobjectmovementtype LOCALID_SINJOHRUINS_LAB_STEVEN, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_NEWSINJOH_LAB_LINGUIST, 5, 7
	setobjectmovementtype LOCALID_NEWSINJOH_LAB_LINGUIST, MOVEMENT_TYPE_FACE_LEFT
	return

SinjohRuins_Lab_FinalPlateScene::
	lock
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	turnobject LOCALID_SINJOHRUINS_LAB_STEVEN, DIR_SOUTH
	delay 30
	applymovement LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_WalkDown1
	turnobject LOCALID_NEWSINJOH_LAB_LINGUIST, DIR_SOUTH
	delay 30
	msgbox SinjohRuins_Lab_Text_FinalPlateScene1, MSGBOX_DEFAULT
	closemessage
	dofieldeffectsparkle 3, 8, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 3
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	delay 200
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 40  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	msgbox SinjohRuins_Lab_Text_FinalPlateScene2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, SinjohRuins_Lab_Movement_PlayerLeaveLab
	applymovement LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenLeaveLab
	waitmovement 0
	waitmovement 0
	setvar VAR_SINJOH_STORYLINE, 8
	warp MAP_SINJOH_RUINS_HNS, 0
	waitstate
	end

SinjohRuins_Lab_Text_FinalPlateScene1:
	.string "STEVEN: {PLAYER}!\p"
	.string "Credo di sapere cosa succederà\n"
	.string "quando uniremo tutte e 17 le\l"
	.string "LASTRE.\p"
	.string "Sento che…\l"
	.string ".....................$"

SinjohRuins_Lab_Text_FinalPlateScene2:
	.string "STEVEN: Devo vederlo con i\n"
	.string "miei occhi!\p"
	.string "Fuori, {PLAYER}!$" 

SinjohRuins_Lab_Movement_PlayerLeaveLab:
	walk_fast_down
	walk_fast_down
	walk_in_place_fast_down
	step_end

SinjohRuins_Lab_Movement_StevenLeaveLab:
	walk_fast_down
	walk_fast_down
	walk_in_place_fast_down
	step_end

@==========================NPC SCRIPTS================================================================================

SinjohRuins_Lab_EventScript_Steven::
	lock
	faceplayer
	buffernumberstring STR_VAR_1, VAR_PLATECOUNTER
	goto_if_ge VAR_PLATECOUNTER, 17, SinjohRuins_Lab_EventScript_StevenAfterAllPlates
	goto_if_ge VAR_PLATECOUNTER, 15, SinjohRuins_Lab_EventScript_StevenAfter15Plates
	goto_if_ge VAR_PLATECOUNTER, 12, SinjohRuins_Lab_EventScript_StevenAfter12Plates
	goto_if_ge VAR_PLATECOUNTER, 9, SinjohRuins_Lab_EventScript_StevenAfter9Plates
	goto_if_ge VAR_PLATECOUNTER, 6, SinjohRuins_Lab_EventScript_StevenAfter6Plates
	goto_if_ge VAR_PLATECOUNTER, 3, SinjohRuins_Lab_EventScript_StevenAfter3Plates
	msgbox SinjohRuins_Lab_Text_StevenFindPlates, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter3Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates3, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter6Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates3, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter9Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates9, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter12Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates9, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter15Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates9, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfterAllPlates::
	msgbox SinjohRuins_Lab_Text_StevenAfterAll, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_Text_StevenFindPlates:
	.string "STEVEN: Ah, {PLAYER}.\p"
	.string "{STR_VAR_1} PIASTRE finora.\n"
	.string "Niente male.\p"
	.string "Devo ammettere che sono curioso\n"
	.string "di sapere cosa succederà quando\l"
	.string "le avrai tutte.\p"
	.string "Bene, vediamo cosa trovi.$"

SinjohRuins_Lab_Text_StevenFindPlates3:
	.string "STEVEN: Ah, {PLAYER}.\p"
	.string "{STR_VAR_1} PIASTRE finora.\n"
	.string "Niente male.\p"
	.string "Hai già esplorato quella\n"
	.string "camera?\l"
	.string "È tutto molto misterioso.$"

SinjohRuins_Lab_Text_StevenFindPlates9:
	.string "STEVEN: Ah, {PLAYER}.\p"
	.string "{STR_VAR_1} PIASTRE finora.\n"
	.string "Ottimi progressi.\p"
	.string "Le camere che si sono aperte\n"
	.string "sono molto simili\l"
	.string "a una serie di camere\l"
	.string "della regione di HOENN.\p"
	.string "Ognuna ospitava\n"
	.string "un POKéMON leggendario.\p"
	.string "Ma a HOENN ne sono state\n"
	.string "scoperte solo 3.\p"
	.string "E qui ce ne sono almeno 6.\p"
	.string "Chissà cosa troveremo.$"

SinjohRuins_Lab_Text_StevenAfterAll:
	.string "STEVEN: {PLAYER}!\p"
	.string "Questa spedizione è stata\n"
	.string "l'esperienza di una vita.\p"
	.string "Da quando ho sentito di queste rovine,\n"
	.string "ho avuto questa sensazione.\p"
	.string "Pensavo che avremmo scoperto qualcosa\n"
	.string "di straordinario.\p"
	.string "E le mie previsioni di solito si avverano.\p"
	.string "Grazie per tutto il tuo aiuto,\n"
	.string "Campione.\p"
	.string "Dove andrai adesso?\p"
	.string "Spero ci rivedremo da qualche parte.$"

SinjohRuins_Lab_EventScript_Geologist::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SinjohRuins_Lab_EventScript_GeologistAfterEvent
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_GeologistDuringEvent
	msgbox SinjohRuins_Lab_Text_Geologist MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_GeologistDuringEvent::
	msgbox SinjohRuins_Lab_Text_GeologistDuring, MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_GeologistAfterEvent::
	msgbox SinjohRuins_Lab_Text_GeologistAfter, MSGBOX_NPC
	end

SinjohRuins_Lab_Text_Geologist:
    .string "Il radar penetrante mostra\n"
	.string "6 camere sotterranee in questa\l"
	.string "valle.\p"
	.string "5 sembrano più vicine\n"
	.string "alla superficie, mentre 1\l"
	.string "è sepolta ancora più in fondo.$"
SinjohRuins_Lab_Text_GeologistDuring:
	.string "Per tutto questo tempo ho puntato\n"
	.string "le apparecchiature in basso a\l"
	.string "immagine del sottosuolo.\p"
	.string "Quando invece dovevo puntarle\n"
	.string "in alto!$"
SinjohRuins_Lab_Text_GeologistAfter:
	.string "Quelle LASTRE erano legate ai\n"
	.string "POKéMON più potenti??\p"
	.string "Vorrei avere più tempo per studiarle.$"

SinjohRuins_Lab_EventScript_Linguist::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SinjohRuins_Lab_EventScript_LinguistAfterEvent
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_LinguistDuringEvent
	msgbox SinjohRuins_Lab_Text_Linguist MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_LinguistDuringEvent::
	msgbox SinjohRuins_Lab_Text_LinguistDuring, MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_LinguistAfterEvent::
	msgbox SinjohRuins_Lab_Text_LinguistAfter, MSGBOX_NPC
	end

SinjohRuins_Lab_Text_Linguist:
    .string "Ugh....\n"
	.string "Ci sono così tanti glifi da\l"
	.string "tradurre..\p"
	.string "Non abbiamo niente del genere\n"
	.string "nella regione di HOENN.$"
SinjohRuins_Lab_Text_LinguistDuring:
    .string "Immagina la mia sorpresa nel\n"
	.string "tradurre i glifi!\p"
	.string "Ho controllato tre e quattro\n"
	.string "volte prima di dirlo a STEVEN!\p"
	.string "Cioè, davvero, il Dio dei\n"
	.string "POKéMON?\p"
	.string "È incredibile.$"
SinjohRuins_Lab_Text_LinguistAfter:
    .string "Questa spedizione è stata una\n"
	.string "gioia, {PLAYER}.\p"
	.string "Grazie per esserti occupato di\n"
	.string "tutto il lavoro sul campo.$"

SinjohRuins_Lab_EventScript_Archaeologist::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SinjohRuins_Lab_EventScript_ArchaeologistAfterEvent
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_ArchaeologistDuringEvent
	msgbox SinjohRuins_Lab_Text_Archaeologist MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_ArchaeologistDuringEvent::
	msgbox SinjohRuins_Lab_Text_ArchaeologistDuring, MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_ArchaeologistAfterEvent::
	msgbox SinjohRuins_Lab_Text_ArchaeologistAfter, MSGBOX_NPC
	end

SinjohRuins_Lab_Text_Archaeologist:
	.string "L'esistenza di una civiltà\n"
    .string "in questa zona cambia tutta\l"
	.string "la nostra storia.\p"
	.string "Molti reperti che abbiamo trovato\n"
	.string "hanno oltre mille anni.\p"
	.string "La datazione al carbonio coincide\n"
	.string "con reperti trovati a SINNOH.\p"
	.string "Però quel flauto che hai trovato…\n"
	.string "sembra molto più antico.$"
SinjohRuins_Lab_Text_ArchaeologistDuring:
	.string "Quelle lastre…\n"
	.string "Il legame con la regione\l"
	.string "di SINNOH…\l"
	.string "Quel flauto…\l"
	.string "Ora tutto comincia ad avere senso.$"
SinjohRuins_Lab_Text_ArchaeologistAfter:
	.string "Il valore storico di ciò\n"
	.string "che ci hai aiutato a riportare\l"
	.string "alla luce è immenso, \l"
	.string "{PLAYER}.\p"
	.string "Grazie davvero.$"

SinjohRuins_Lab_EventScript_Growlithe_Hisui::
    lock
	faceplayer
	playmoncry SPECIES_GROWLITHE, 0
	msgbox SinjohRuins_Lab_Text_Growlithe_Cry, MSGBOX_DEFAULT
	waitmoncry
    closemessage
	release
	end

SinjohRuins_Lab_Text_Growlithe_Cry:
    .string "Growh owh!!$"

SinjohRuins_Lab_EventScript_GrowlithePokeball::
    msgbox SinjohRuins_Lab_Text_GrowlitheBall MSGBOX_SIGN
	end

SinjohRuins_Lab_Text_GrowlitheBall:
    .string "Sembra la Ball di Growlithe..\n"
	.string "Meglio lasciarla stare.$"

SinjohRuins_Lab_EventScript_Biologist::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SinjohRuins_Lab_EventScript_BiologistAfterEvent
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_BiologistDuringEvent
	msgbox SinjohRuins_Lab_Text_Biologist MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_BiologistDuringEvent::
	msgbox SinjohRuins_Lab_Text_BiologistDuring, MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_BiologistAfterEvent::
	msgbox SinjohRuins_Lab_Text_BiologistAfter, MSGBOX_NPC
	end

SinjohRuins_Lab_Text_Biologist:
    .string "Guarda che esemplare stupendo!\p"
	.string "Questa specie di GROWLITHE è diversa\n"
	.string "da quelle che si trovano in tutto\l"
	.string "il mondo.\p"
	.string "L'analisi del DNA rivela che ha\n"
	.string "un antenato comune con i GROWLITHE\l"
	.string "di altre regioni.\p"
	.string "Eppure carattere e tipo\n"
	.string "sono molto diversi.\p"
	.string "Le descrizioni di GROWLITHE negli\n"
	.string "antichi scritti di SINNOH combaciano.\p"
	.string "Forse questa specie occupava\n"
	.string "un territorio molto più vasto, fino\l"
	.string "a nord nell'antica SINNOH.$"
SinjohRuins_Lab_Text_BiologistDuring:
	.string "Se la creatura in cima\n"
	.string "a quelle scale è davvero il Dio\l"
	.string "dei POKéMON, vuol dire che\l"
	.string "è il primo antenato comune?$"
SinjohRuins_Lab_Text_BiologistAfter:
	.string "Ho raccolto tantissimi\n"
	.string "dati sulle forme regionali e\l"
	.string "sull'evoluzione divergente in\l"
	.string "questa spedizione. Grazie,\l"
	.string "{PLAYER}.$"

SinjohRuins_Lab_EventScript_Hiker::
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_HikerDuringAfter
	msgbox SinjohRuins_Lab_Text_Hiker MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_HikerDuringAfter::
	msgbox SinjohRuins_Lab_Text_HikerDuringAfter, MSGBOX_NPC
	end
SinjohRuins_Lab_Text_Hiker:
   	.string "Per dieci anni ho esplorato queste\n"
	.string "terre selvagge.\p"
	.string "No, diciamo venti anni.\p"
	.string "Finché un giorno trovai quelle\n"
	.string "grandi colonne di pietra e quel\l"
	.string "tempio sinistro.\p"
	.string "Sono le ROVINE ROVINE SINJOH.\n"
	.string "O così ho sentito dire.\p"
	.string "Allora non sapevo del paese.\p"
	.string "Dissi solo a qualche\n"
	.string "amico. Ma la voce corre.\p"
	.string "Non pensavo avrebbe attirato\n"
	.string "tanta attenzione qui.\p"
	.string "Mi fa un certo effetto.\n"
	.string "Sai?$"
SinjohRuins_Lab_Text_HikerDuringAfter:
   	.string "Non dirlo a nessuno, {PLAYER},\n"
	.string "ma vidi quel tempio in cima\l"
	.string "alla montagna quando scoprii\l"
	.string "questo posto per primo.\p"
	.string "Me lo sono tenuto per me.\p"
	.string "Ho già spifferato abbastanza\n"
	.string "su queste rovine.\p"
	.string "Almeno sembra che sia andato\n"
	.string "tutto bene.$"

@ENVIRONMENT
SinjohRuins_Lab_EventScript_Notes1::
	msgbox SinjohRuins_Lab_Text_Note1 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes2::
	msgbox SinjohRuins_Lab_Text_Note2 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes3::
	msgbox SinjohRuins_Lab_Text_Note3 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes4::
	msgbox SinjohRuins_Lab_Text_Note4 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes5::
	msgbox SinjohRuins_Lab_Text_Note5 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes6::
	msgbox SinjohRuins_Lab_Text_Note6 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes7::
	msgbox SinjohRuins_Lab_Text_Note7 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes8::
	msgbox SinjohRuins_Lab_Text_Note8 MSGBOX_SIGN
	end

SinjohRuins_Lab_Text_Note1:
    .string "Diario 1: 3 maggio 1975\p"
	.string "Siamo arrivati sul luogo\n"
	.string "delle rovine.\p"
	.string "Il freddo pungente del MT. ARGENTO\n"
	.string "si sente anche quassù,\l"
	.string "fin dentro le ossa…\p"
	.string "Presto la squadra di scavo\n"
	.string "riuscirà ad aprire un varco..\l"
	.string "Non vedo l'ora di scoprire cosa\l"
	.string "ci attende sotto i nostri piedi!$"

SinjohRuins_Lab_Text_Note2:
    .string "Diario 2: 10 maggio 1975\p"
	.string "Una settimana di scavi non ha\n"
	.string "dato alcun risultato.\p"
	.string "Il ghiaccio qui è spesso in modo assurdo,\n"
	.string "e la roccia rompe la nostra\l"
	.string "attrezzatura del tutto.\p"
	.string "Nemmeno MACHAMP è riuscito a\n"
	.string "scalfirlo.\p"
	.string "Che posto è questo?\p"
	.string "Dobbiamo scoprirlo.$"

SinjohRuins_Lab_Text_Note3:
    .string "Diario 3: 14 maggio 1975\p"
	.string "Non si va avanti\n"
	.string "stando fermi a non far nulla.\p"
	.string "Sono solo un operaio.\p"
	.string "Ma ho avuto un'idea su come\n"
	.string "rompere il ghiaccio.\p"
	.string "Anzi, scioglierlo.\p"
	.string "Servono POKéMON di tipo FUOCO e\n"
	.string "in gran numero.\p"
	.string "Ma come li portiamo qui\n"
	.string "da SINNOH?$"

SinjohRuins_Lab_Text_Note4:
    .string "Diario 4:  21 maggio 1975\p"
	.string "Siamo stati impegnati.\p"
	.string "La mia idea ha funzionato per passare\n"
	.string "il ghiaccio. Solo che non abbiamo i\l"
	.string "POKéMON di tipo FUOCO di casa.\p"
	.string "Il capo ha voluto prenderli sul posto.\p"
	.string "Abbiamo trovato una fonte termale\n"
	.string "vicino a un villaggio....\p"
	.string "E ci siamo presi ciò che serviva...\p"
	.string "Non ne vado fiero. Ma a volte servono\n"
	.string "sacrifici per andare avanti.\p"
	.string "Così, il ghiaccio è sparito.\p"
	.string "Ci sono 6 camere e un tempio\n"
	.string "sigillato al centro.\p"
	.string "L'architettura della struttura\n"
	.string "principale indica che potrebbe\l"
	.string "appartenere agli antichi Celestica...\p"
	.string "I nostri antenati. Prima di andare a nord.\p"
	.string "Il capo vuole quel tempio aperto il\n"
	.string "prima possibile...$"

SinjohRuins_Lab_Text_Note5:
    .string "Diario 5:  2 giugno 1975\p"
	.string "Siamo riusciti ad aprirlo...\p"
	.string "Credevo che avrei gioito...\p"
	.string "Ma abbiamo perso brav'uomini nell'onda\n"
	.string "di energia sprigionata dal\l"
	.string "tempio.\p"
	.string "Per non parlare dei POKéMON che\n"
	.string "ci hanno aiutato ad aprirlo.\l"
	.string "Che riposino in pace...\p"
	.string "........................\p"
	.string "Comunque.\p"
	.string "Il tempio è aperto, ma abbiamo\n"
	.string "solo più domande.\p"
	.string "Non c'è nessun POKéMON leggendario\n"
	.string "dentro. Nessun tesoro.\p"
	.string "Le provviste stanno finendo\n"
	.string "e non abbiamo nulla da mostrare\l"
	.string "per i nostri sforzi...$"

SinjohRuins_Lab_Text_Note6:
  	.string "Diario 6: 10 giugno 1975\p"
    .string "La spedizione è finita.\n"
	.string "Gli altri fanno i bagagli.\p"
	.string "Ma io no.\p"
	.string "Non abbandono la missione.\n"
	.string "Non dopo quello che abbiamo perso.\p"
	.string "Io resto qui.$"

SinjohRuins_Lab_Text_Note7:
  	.string "Diario 7: 10 settembre 1975\p"
	.string "Sono mesi che siamo qui.\n"
	.string "Che io sono qui.\p"
	.string "Gli altri se ne sono andati.\p"
	.string "Ora ci siamo solo io e i\n"
	.string "POKéMON catturati per aiutarci\l"
	.string "nel lavoro.\p"
	.string "Li ho allenati per renderli\n"
	.string "più forti.\p"
	.string "Soprattutto il mio TYPHLOSION.\p"
	.string "Dobbiamo scoprire cosa c'è sotto\n"
	.string "il tempio.$"

SinjohRuins_Lab_Text_Note8:
  	.string "Diario 8: 15 settembre 1975\p"
	.string "Fallimento.\p"
	.string "......................\p"
	.string "I miei POKéMON....\p"
	.string "Insieme, tutti e 6 i miei POKéMON\n"
	.string "sono riusciti ad abbattere\n"
	.string "un muro falso del tempio.\p"
	.string "Ma ci stava aspettando...\p"
	.string "Qualcosa come un titano gigante...\p"
	.string "L'energia che ha rilasciato era\n"
	.string "come quella di prima.\p"
	.string "Sono stati tutti distrutti...\p"
	.string "E, cosa peggiore, quella bestia\n"
	.string "ha richiuso il muro.\p"
	.string "Non posso tornare a casa.\n"
	.string "Non mi riconoscerebbero più...\p"
	.string "Questo posto mi ha cambiato...\p"
	.string "Andrò a parlare con gli\n"
	.string "abitanti del villaggio.\p"
	.string "Non sanno cosa ho fatto.\p"
	.string "Dato che gli altri sono spariti\n"
	.string "da tempo, mi prenderanno per un\l"
	.string "escursionista smarrito.\p"
	.string "Non mi resta nessun posto\n"
	.string "tranne questo.$"

SinjohRuins_EventScript_DisplayCase::
    lock
	msgbox SinjohRuins_DisplayCase_Text MSGBOX_DEFAULT
	release
	end

SinjohRuins_DisplayCase_Text:
    .string "È una vetrina piena\n"
	.string "zeppa di campioni\l"
	.string "e reperti!$"

SinjohRuins_EventScript_WallSign::
    lock
	msgbox SinjohRuins_WallSign_Text MSGBOX_DEFAULT
	release
	end

SinjohRuins_WallSign_Text:
   .string "Laboratorio di stampa e raggi X.$"


SinjohRuins_EventScript_Artifact::
   lock
   msgbox SinjohRuins_Artifact_Text MSGBOX_DEFAULT
   release
   end

SinjohRuins_Artifact_Text:
   .string "È un reperto trovato\n"
   .string "dentro le rovine!$"


@==========================Unified other map SCRIPTS================================================================================

SinjohRuins_Lab_EventScript_NoOp::
	release
	end

SinjohRuins_Lab_Text_PlayFlute:
	.string "Il FLAUTO AZZURRO reagisce.\n"
	.string "Suonare il flauto?$"

SinjohRuins_Lab_Text_DropedItem:
	.string "Il NOBILE {STR_VAR_1} ha lasciato\n"
	.string "un oggetto…$"

SinjohRuins_Lab_Text_StevenName:
	.string "STEVEN$"

SinjohRuins_Lab_EventScript_3Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall3Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_6Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall6Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_9Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall9Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_12Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall12Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_15Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall15Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_16Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall16Plates
	waitmessage
	delay 30
	setvar VAR_SINJOH_STORYLINE, 7
	return

SinjohRuins_Lab_Text_StevenCall3Plates:
	.string "STEVEN: {PLAYER}.\p"
	.string "Abbiamo sentito un tremito alle rovine\n"
	.string "proprio ora.\p"
	.string "Stanno tutti bene, non preoccuparti.\p"
	.string "È molto curioso, una delle\n"
	.string "camere sotterranee sotto le\l"
	.string "rovine si è aperta.\p"
	.string "I segni all'interno mi\n"
	.string "ricordano qualcosa di HOENN.\p"
	.string "Dovresti venire a dare un'occhiata\n"
	.string "quando puoi.$"

SinjohRuins_Lab_Text_StevenCall6Plates:
	.string "STEVEN: {PLAYER}.\p"
	.string "Come va la ricerca?\p"
	.string "Qui c'è stato un altro tremito.\n"
	.string "Si è aperta una\l"
	.string "seconda camera.\p"
	.string "Ho chiesto al geologo di tenere\n"
	.string "pronti gli strumenti se\l"
	.string "succede ancora.\p"
	.string "Più scaviamo... Più domande\n"
	.string "troviamo.$"

SinjohRuins_Lab_Text_StevenCall9Plates:
	.string "STEVEN: {PLAYER}.\p"
	.string "Un altro tremito qui alle rovine.\p"
	.string "I dati dipingono un quadro\n"
	.string "curioso.\p"
	.string "Non era affatto un terremoto.\p"
	.string "Una specie di energia si è accumulata\n"
	.string "sottoterra e ha spaccato la\l"
	.string "roccia dall'interno.\p"
	.string "Cosa può causarlo...\n"
	.string "Sinceramente non lo so.$"

SinjohRuins_Lab_Text_StevenCall12Plates:
	.string "STEVEN: {PLAYER}.\p"
	.string "Un altro tremito. Un'altra camera\n"
	.string "che si apre.\p"
	.string "Ancora non capiamo lo\n"
	.string "schema dei tempi.\p"
	.string "Dimmi, {PLAYER}... non è\n"
	.string "che sei tu a causare tutto\l"
	.string "questo, vero?\p"
	.string "No, impossibile.$"

SinjohRuins_Lab_Text_StevenCall15Plates:
	.string "STEVEN: {PLAYER}.\p"
	.string "Hai appena trovato un'altra PIASTRA?\p"
	.string ".................\p"
	.string "Ovvio.\p"
	.string "I POKéMON leggendari che\n"
	.string "giacciono in queste rovine... ti stanno\l"
	.string "rispondendo, vero?\p"
	.string "Come se volessero essere trovati.\p"
	.string "Le mie previsioni di solito si avverano.\n"
	.string "Avrei dovuto saperlo, che non\l"
	.string "dovevo dubitare di te.$"

SinjohRuins_Lab_Text_StevenCall16Plates:
	.string "STEVEN: {PLAYER}.\p"
	.string "Siamo vicinissimi ora. Lo sento.\p"
	.string "..................\p"
	.string "Dovresti venire a vederlo di\n"
	.string "persona.$"

