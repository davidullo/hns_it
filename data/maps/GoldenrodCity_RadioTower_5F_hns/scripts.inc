GoldenrodCity_RadioTower_5F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_RadioTower_5F_OnLoad
	.byte 0

GoldenrodCity_RadioTower_5F_OnLoad::
	call_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_5F_MapScript_HidePetrel
	end

GoldenrodCity_RadioTower_5F_MapScript_HidePetrel::
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	return


@=======[OFFICE]==============================================================================================================================

GoldenrodCity_RadioTower_5F_EventScript_Petrel::
	lock
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 10, GoldenrodCity_RadioTower_5F_EventScript_Director
	goto_if_eq VAR_FACING, DIR_SOUTH, GoldenrodCity_RadioTower_5F_EventScript_PetrelNorth
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirector1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DIRECTOR_OFFICE, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	removeobject LOCALID_DIRECTOR_OFFICE
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	addobject LOCALID_PETREL_OFFICE
	applymovement LOCALID_PETREL_OFFICE, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirector2, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PETREL_2_HNS, GoldenrodCity_RadioTower_5F_Text_FakeDirectorWin
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter, MSGBOX_DEFAULT
	giveitem ITEM_BASEMENT_KEY
	setvar VAR_GOLDENROD_CITY_STATE, 7
	clearflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	closemessage
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_PetrelNorth::
	end

GoldenrodCity_RadioTower_5F_EventScript_Petrel2::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_Director::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_5F_Movement_Spin:
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_4
	face_up
	delay_4
	face_left
	delay_4
	face_down
	delay_4
	face_right
	delay_2
	face_up
	delay_2
	face_left
	delay_2
	face_down
	step_end


GoldenrodCity_RadioTower_5F_Movement_Spin2:
	face_right
	delay_2
	face_up
	delay_2
	face_left
	delay_2
	face_down
	step_end


GoldenrodCity_RadioTower_5F_Text_FakeDirector1:
	.string "T-tu! Sei qui per salvarmi?$"

GoldenrodCity_RadioTower_5F_Text_FakeDirector2:
	.string "Is that what you were expecting?\p"
	.string "Wrong! I'm an imposter!\p"
	.string "I pretended to be the real thing to\n"
	.string "prepare for our takeover.\p"
	.string "Do you want to know where we hid\n"
	.string "the real DIRECTOR?\p"
	.string "Sure, I'll tell you. But only if you\n"
	.string "can beat me!$"

GoldenrodCity_RadioTower_5F_Text_FakeDirectorWin:
	.string "OK, OK. Ti dico dov'è.$"

GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter:
	.string "The boss stashed the DIRECTOR in\n"
	.string "the UNDERGROUND WAREHOUSE.\p"
	.string "It's at the far end of the UNDER-\n"
	.string "GROUND.\p"
	.string "I am a nice guy, I will give you\n"
	.string "the BASEMENT KEY to get to the\l"
	.string "UNDERGROUND WAREHOUSE.\p"
	.string "But I doubt you'll get that far.$"

GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter2:
	.string "Il capo ha rinchiuso il DIRETTORE\n"
	.string "nel MAGAZZINO SOTTERRANEO.\p"
	.string "È in fondo al SOTTER-\n"
	.string "RANEO.\p"
	.string "Puoi usare la CHIAVE SEMINTERRATO\n"
	.string "per il MAGAZZINO SOTTERRANEO.\p"
	.string "Ma dubito che arriverai fin lì.$"

@=======[STUDIO]==============================================================================================================================

GoldenrodCity_RadioTower_5F_EventScript_Ben::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_Ben, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodRaidoTower4_EventScript_ARIANA::
	trainerbattle_single TRAINER_ARIANA_2_HNS GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Seen, GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Beaten
	msgbox GoldenrodCity_RadioTower_5F_Text_ExecutiveF1After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_RadioTower_5F_EventScript_Archer::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_RocketBossSeen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ARCHER_HNS, GoldenrodCity_RadioTower_5F_Text_RocketBossBeaten
	msgbox GoldenrodCity_RadioTower_5F_Text_RocketBossAfter, MSGBOX_DEFAULT
	delay 55
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_GOLDENROD_ROCKETS
	playse SE_EXIT
	setvar VAR_GOLDENROD_CITY_STATE, 10
	removeobject LOCALID_GOLDENROD_ARCHER
	removeobject LOCALID_GOLDENROD_ARIANA
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	removeobject LOCALID_PETREL_OFFICE
	addobject LOCALID_DIRECTOR_STUDIO
	playbgm MUS_HG_GOLDENROD, TRUE
	delay 120
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_FACING, DIR_SOUTH, GoldenrodCity_RadioTower_5F_EventScript_WingTop
	goto_if_eq VAR_FACING, DIR_WEST, GoldenrodCity_RadioTower_5F_EventScript_WingMid
	goto_if_eq VAR_FACING, DIR_NORTH, GoldenrodCity_RadioTower_5F_EventScript_WingBot
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_WingTop::
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerTop
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorThanks, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_LUGIA_OR_HOOH, 1,  GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing
	call_if_eq VAR_LUGIA_OR_HOOH, 2, GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_LeaveTop
	waitmovement 0
	goto GoldenrodCity_RadioTower_5F_Fakeout
	end

GoldenrodCity_RadioTower_5F_EventScript_WingMid::
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerMid
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorThanks, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_LUGIA_OR_HOOH, 1,  GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing
	call_if_eq VAR_LUGIA_OR_HOOH, 2, GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_LeaveMid
	waitmovement 0
	goto GoldenrodCity_RadioTower_5F_Fakeout
	end

GoldenrodCity_RadioTower_5F_EventScript_WingBot::
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerBot
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorThanks, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_LUGIA_OR_HOOH, 1,  GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing
	call_if_eq VAR_LUGIA_OR_HOOH, 2, GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_LeaveBot
	waitmovement 0
	goto GoldenrodCity_RadioTower_5F_Fakeout
	end

GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing::
	giveitem ITEM_SILVER_WING
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorTidalWingExplanation, MSGBOX_DEFAULT
	closemessage
	release
	return

GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing::
	giveitem ITEM_RAINBOW_WING
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorClearWingExplanation, MSGBOX_DEFAULT
	closemessage
	release
	return

GoldenrodCity_RadioTower_5F_Fakeout::
	playse SE_PIN
	applymovement LOCALID_DIRECTOR_STUDIO, Common_Movement_ExclamationMark
	delay 60
	turnobject LOCALID_DIRECTOR_STUDIO, DIR_WEST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorLegendary, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_Leave1
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DIRECTOR_STUDIO, Common_Movement_ExclamationMark
	delay 60
	turnobject LOCALID_DIRECTOR_STUDIO, DIR_SOUTH
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorFakeout, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_Leave2
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR_2
	removeobject LOCALID_DIRECTOR_STUDIO
	setvar VAR_MAHOGANY_TOWN_STATE, 17
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_Trigger_NPCS::
	clearflag FLAG_HIDE_GOLDENROD_NPCS
	setvar VAR_GOLDENROD_CITY_STATE, 11
	end

GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerTop:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_RadioTower_5F_Movement_LeaveTop:
	walk_right
	walk_right
	walk_right
	step_end

GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerMid:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	step_end


GoldenrodCity_RadioTower_5F_Movement_LeaveMid:
	walk_right
	walk_right
	step_end

GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerBot:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_RadioTower_5F_Movement_LeaveBot:
	walk_right
	walk_right
	walk_right
	step_end

GoldenrodCity_RadioTower_5F_Movement_Leave1:
	walk_up
	walk_up
	step_end

GoldenrodCity_RadioTower_5F_Movement_Leave2:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Seen:
	.string "Ti ricordi del NASCONDIGLIO di\n"
	.string "MAHOGANY?\p"
	.string "Il capo mi ha sgridato, ma sono\p"
	.string "più forte. Allora persi, ora no.$"

GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Beaten:
	.string "Non può essere vero!\p"
	.string "Ho lottato tanto, ma ho perso…\p"
	.string "Perdonami GIOVANNI…$"

GoldenrodCity_RadioTower_5F_Text_ExecutiveF1After:
	.string "{PLAYER}, vero?\p"
	.string "Un moccioso come te non capirà\n"
	.string "la grandezza del TEAM ROCKET.\p"
	.string "Peccato. Ammiro molto\n"
	.string "la tua forza.$"

GoldenrodCity_RadioTower_5F_Text_RocketBossSeen:
	.string "Oh? Sei arrivato fin qui?\p"
	.string "Devi essere un bravo allenatore.\p"
	.string "Vogliamo prendere questa\n"
	.string "RADIO e annunciare il ritorno.\p"
	.string "Così il capo GIOVANNI tornerà\n"
	.string "dal suo allenamento solitario.\p"
	.string "Riconquisteremo la nostra\n"
	.string "antica gloria...\p"
	.string "Non ti lascerò interferire coi\n"
	.string "nostri piani!$"

GoldenrodCity_RadioTower_5F_Text_RocketBossBeaten:
	.string "No! Perdonami, GIOVANNI!$"

GoldenrodCity_RadioTower_5F_Text_RocketBossAfter:
	.string "Come può essere?\p"
	.string "I nostri sogni sono svaniti.\p"
	.string "Non ero all'altezza, dopotutto.\p"
	.string "Come GIOVANNI prima di me,\n"
	.string "sciolgo il TEAM ROCKET oggi.\p"
	.string "Addio.$"

GoldenrodCity_RadioTower_5F_Text_DirectorThanks:
	.string "DIRETTORE: {PLAYER}, grazie!\p"
	.string "Il tuo coraggio ha salvato i\n"
	.string "POKéMON di tutto il paese.\p"
	.string "So che è poco, ma prendi\n"
	.string "questo.$"

GoldenrodCity_RadioTower_5F_Text_DirectorClearWingExplanation:
	.string "Qui c'era una torre,\n"
	.string "a GOLDENROD CITY.\p"
	.string "Ma era vecchia e scricchiolava.\p"
	.string "Così l'abbiamo sostituita con la\n"
	.string "TORRE RADIO.\p"
	.string "Abbiamo trovato quell'ala durante\n"
	.string "i lavori.\p"
	.string "Ho sentito che ogni tipo di POKéMON\n"
	.string "viveva a GOLDENROD in passato.\p"
	.string "Forse…\p"
	.string "Quell'ala ha un legame con la\n"
	.string "TORRE CAMPANA di ECRUTEAK…\p"
	.string "OK, meglio che vada in UFFICIO.$"

GoldenrodCity_RadioTower_5F_Text_DirectorTidalWingExplanation:
	.string "Qui c'era una torre,\n"
	.string "a GOLDENROD CITY.\p"
	.string "Ma era vecchia e scricchiolava.\p"
	.string "Così l'abbiamo sostituita con la\n"
	.string "TORRE RADIO.\p"
	.string "Abbiamo trovato quell'ala durante\n"
	.string "i lavori.\p"
	.string "Ho sentito che ogni tipo di POKéMON\n"
	.string "viveva a GOLDENROD in passato.\p"
	.string "Forse…\p"
	.string "Quell'ala ha un legame con le\n"
	.string "ISOLE VORTICOSE vicino a CIANWOOD…\p"
	.string "OK, meglio che vada in UFFICIO.$"

GoldenrodCity_RadioTower_5F_Text_DirectorLegendary:
	.string "Ah!\p"
	.string "Mi hai ricordato una cosa…\p"
	.string "Quell'ala che ti ho dato… credo\n"
	.string "sia legata al POKéMON\l"
	.string "leggendario.\p"
	.string "Ma il POKéMON leggendario non\n"
	.string "appare solo con quell'ala…\p"
	.string "Sembra serva qualcos'altro…\n"
	.string "O qualcosa del genere.\p"
	.string "Chissà cos'era…\p"
	.string "Non ricordo.$"

GoldenrodCity_RadioTower_5F_Text_DirectorFakeout:
	.string "Ti aspettavi qualcosa?\n"
	.string "Questo si chiama BRUCIAPELO.\p"
	.string "Stavolta devo proprio tornare in\n"
	.string "UFFICIO. Alla prossima!$"

GoldenrodCity_RadioTower_5F_Text_DirectorIntro:
	.string "DIRETTORE: Ciao, {PLAYER}!\p"
	.string "Sai, adoro i POKéMON.\p"
	.string "Ho costruito la TORRE RADIO per\n"
	.string "esprimere il mio amore.\p"
	.string "Sarebbe bello se la gente\n"
	.string "apprezzasse i programmi.$"

GoldenrodCity_RadioTower_5F_Text_Ben:
	.string "BEN: Ascolti la nostra musica?$"

GoldenrodCity_RadioTower_5F_Text_DirectorOfficeSign:
	.string "UFFICIO DEL DIRETTORE 5P$"

GoldenrodCity_RadioTower_5F_Text_Studio1Sign:
	.string "5F STUDIO 1$"
