EverGrandeCity_ChampionsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_ChampionsRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_ChampionsRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_ChampionsRoom_OnFrame
	.byte 0

EverGrandeCity_ChampionsRoom_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

EverGrandeCity_ChampionsRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

EverGrandeCity_ChampionsRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_EnterRoom
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_EnterRoom::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp4
	waitmovement 0
	delay 40
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace
	waitmovement 0
	setvar VAR_TEMP_1, 1
	goto EverGrandeCity_ChampionsRoom_EventScript_Wallace
	releaseall
	end

EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_EventScript_Wallace::
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
	msgbox EverGrandeCity_ChampionsRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLACE, EverGrandeCity_ChampionsRoom_Text_Defeat
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
	end

EverGrandeCity_ChampionsRoom_EventScript_Defeated::
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
	special DrawWholeMapView
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic
	addobject LOCALID_CHAMPIONS_ROOM_RIVAL
	call EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	end

EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_MayAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF::
	closemessage
	addobject LOCALID_CHAMPIONS_ROOM_BIRCH
	applymovement LOCALID_CHAMPIONS_ROOM_BIRCH, EverGrandeCity_ChampionsRoom_Movement_BirchArrives
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex, MSGBOX_DEFAULT
	call ProfBirch_EventScript_RatePokedex
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchCongratulations, MSGBOX_DEFAULT
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
	applymovement LOCALID_CHAMPIONS_ROOM_BIRCH, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalFollows
	waitmovement 0
	delay 20
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside, MSGBOX_DEFAULT
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
	closemessage
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExit
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
	waitstate
	releaseall
	end

EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer::
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth::
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_PlayerExit:
	walk_up
	delay_16
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_in_place_faster_right
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth:
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_up
	delay_8
	walk_in_place_faster_right
	delay_16
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalFollows:
	walk_right
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart:
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExit:
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_BirchArrives:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_in_place_faster_left
	step_end

EverGrandeCity_ChampionsRoom_Text_IntroSpeech:
	.string "WALLACE: Salve, {PLAYER}{KUN}.\p"
	.string "Quell'incidente a SOOTOPOLIS…\n"
	.string "Un lavoro superbo: hai messo\l"
	.string "fine alla crisi, tutto da te.\p"
	.string "Ops!\p"
	.string "Non sarebbe giusto dire che\n"
	.string "l'hai risolta da te.\p"
	.string "Hai superato quella difficile\n"
	.string "situazione insieme ai tuoi POKéMON.\p"
	.string "Noi ALLENATORI cresciamo i\n"
	.string "POKéMON con strumenti e\l"
	.string "nuove mosse di lotta.\p"
	.string "Ma anche noi impariamo\n"
	.string "molto dai POKéMON.\p"
	.string "Ed è qui che le tue imprese\n"
	.string "si misurano con quelle\l"
	.string "di chi è come te.\p"
	.string "Ora!\p"
	.string "Chi danza con più eleganza\n"
	.string "coi POKéMON a HOENN?\p"
	.string "Mostramelo qui e ora!$"

EverGrandeCity_ChampionsRoom_Text_Defeat:
	.string "Io, CAMPIONE, vengo sconfitto…\p"
	.string "Che lavoro splendido.\n"
	.string "Elegante, in modo irritante.\l"
	.string "Eppure è stato glorioso!\p"
	.string "Complimenti, {PLAYER}{KUN}!\p"
	.string "Sei davvero un nobile\n"
	.string "ALLENATORE!$"

EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech:
	.string "WALLACE: I POKéMON che hai\n"
	.string "mandato in lotta…\p"
	.string "A volte danzavano come\n"
	.string "brezza, a volte colpivano\l"
	.string "come un fulmine.\p"
	.string "Con leggerezza e passo\n"
	.string "sicuro guidavi i POKéMON.\p"
	.string "Persino io sono rimasto\n"
	.string "incantato: che prova!\p"
	.string "Ora sei sulla gloriosa vetta\n"
	.string "della LEGA POKéMON.\p"
	.string "Ti proclamo CAMPIONE\n"
	.string "di HOENN…$"

EverGrandeCity_ChampionsRoom_Text_MayAdvice:
	.string "MAY: {PLAYER}{KUN}!\p"
	.string "Un consiglio prima di sfidare\n"
	.string "il CAMPIONE…$"

EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver:
	.string "MAY: Eh?\n"
	.string "Che, che, che?\p"
	.string "{PLAYER}{KUN}…\n"
	.string "Non dirmi che…\l"
	.string "È già finita?$"

EverGrandeCity_ChampionsRoom_Text_BrendanAdvice:
	.string "BRENDAN: {PLAYER}!\p"
	.string "Ti serve un consiglio prima\n"
	.string "di sfidare il CAMPIONE?…$"

EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon:
	.string "BRENDAN: {PLAYER}…\p"
	.string "Vuoi dirmi che…\n"
	.string "Hai battuto il CAMPIONE?$"

EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex:
	.string "PROF. BIRCH: Vedi?\n"
	.string "Cosa t'avevo detto, {RIVAL}?\p"
	.string "Che non devi preoccuparti\n"
	.string "di {PLAYER}{KUN}?\p"
	.string "… … … … … … … …\n"
	.string "{PLAYER}{KUN}, ce l'hai fatta.\p"
	.string "Quando ho saputo che avevi\n"
	.string "battuto tuo padre alla\l"
	.string "PALESTRA di PETALBURG, ho\p"
	.string "pensato che potevi farcela…\n"
	.string "Ma sei il CAMPIONE!\p"
	.string "Ah, sì!\p"
	.string "Che fine ha fatto il POKéDEX?\n"
	.string "Fammi vedere.$"

EverGrandeCity_ChampionsRoom_Text_BirchCongratulations:
	.string "PROF. BIRCH: Comunque,\n"
	.string "complimenti!\p"
	.string "Ora avanza fiero nella stanza finale!$"

EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe:
	.string "WALLACE: {PLAYER}{KUN}…\p"
	.string "No, lasciami riformulare bene.\p"
	.string "Il nuovo CAMPIONE!\p"
	.string "Vieni con me.$"

EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside:
	.string "WALLACE: Mi spiace, ma…\p"
	.string "Da qui in poi possono passare solo gli\n"
	.string "ALLENATORI diventati CAMPIONI.\p"
	.string "Dovrai aspettare fuori con\n"
	.string "PROF. BIRCH.$"

EverGrandeCity_ChampionsRoom_Text_MayCongratulations:
	.string "MAY: Uff…\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Scherzo! Va tutto bene!\n"
	.string "Sono le regole!\p"
	.string "{PLAYER}{KUN}!\n"
	.string "Congratulazioni sincere!$"

EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations:
	.string "BRENDAN: Cosa?! … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Se è la regola, pazienza.\p"
	.string "{PLAYER}, grande!\n"
	.string "Congratulazioni!$"

