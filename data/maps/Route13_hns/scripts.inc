Route13_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route13_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_RESUME, Route13_hns_MapScripts_MAP_SCRIPT_ON_RESUME
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route13_hns_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route13_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

Route13_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call Route13_OnTransition
	return

Route13_hns_MapScripts_MAP_SCRIPT_ON_RESUME:
	call SetTimeEncounters
	return

Route13_hns_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_ALOLA_TRAVEL, 2, Route13_GetOffBoat
	.2byte 0

Route13_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	map_script_2 VAR_ALOLA_TRAVEL, 2, Route13_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

Route13_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
	applymovement Route13_Alola_Captain, Route13_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0
	applymovement LOCALID_PLAYER, Route13_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0
	return


Route13_OnTransition:
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 77, Route13_OnTransitionBoat
	callnative SetTimeBasedEncounters
	end

Route13_OnTransitionBoat::
	@addobject LOCALID_ROUTE13_BOAT
	clearflag FLAG_HIDE_ROUTE13_BOAT
	setobjectxyperm LOCALID_ROUTE13_BOAT, 78, 28
	return

Route13_EventScript_Alex::
	trainerbattle_single TRAINER_ALEX_HNS, Route13_Text_PokefanmAlexSeen, Route13_Text_PokefanmAlexBeaten, Route13_EventScript_RegisterAlex
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route13_EventScript_RematchAlex
	msgbox Route13_Text_PokefanmAlexAfterBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_RegisterAlex::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route13_Text_AlexRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ALEX_HNS
	release
	end

Route13_EventScript_RematchAlex::
	trainerbattle_rematch TRAINER_ALEX_HNS, Route13_Text_AlexRematchIntro, Route13_Text_AlexRematchDefeat
	msgbox Route13_Text_AlexPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_ALEX_2_HNS, Route13_EventScript_RematchAlexTryGiveItem
	end

Route13_EventScript_RematchAlexTryGiveItem::
	checkitem ITEM_RED_SHARD
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_RED_SHARD
	closemessage
	end

Route13_EventScript_Joshua::
	trainerbattle_single TRAINER_JOSHUA_HNS, Route13_Text_PokefanmJoshuaSeen, Route13_Text_PokefanmJoshuaBeaten
	msgbox Route13_Text_PokefanmJoshuaAfterBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Perry::
	trainerbattle_single TRAINER_PERRY_HNS, Route13_Text_BirdKeeperPerrySeen, Route13_Text_BirdKeeperPerryBeaten
	msgbox Route13_Text_BirdKeeperPerryAfterBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Bret::
	trainerbattle_single TRAINER_BRET_HNS, Route13_Text_BirdKeeperBretSeen, Route13_Text_BirdKeeperBretBeaten
	msgbox Route13_Text_BirdKeeperBretAfterBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Kenny::
	trainerbattle_single TRAINER_KENNY_HNS, Route13_Text_HikerKennySeen, Route13_Text_HikerKennyBeaten, Route13_EventScript_RegisterKenny
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route13_EventScript_RematchKenny
	msgbox Route13_Text_HikerKennyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_RegisterKenny::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route13_Text_KennyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KENNY_HNS
	release
	end

Route13_EventScript_RematchKenny::
	trainerbattle_rematch TRAINER_KENNY_HNS, Route13_Text_KennyRematchIntro, Route13_Text_KennyRematchDefeat
	msgbox Route13_Text_KennyPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_KENNY_2_HNS, Route13_EventScript_RematchKennyTryGiveItem
	end

Route13_EventScript_RematchKennyTryGiveItem::
	checkitem ITEM_TM_STONE_EDGE
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_STONE_EDGE
	closemessage
	end

Route13_EventScript_TrainerTips::
	msgbox Route13_Text_TrainerTips, MSGBOX_SIGN
	end

Route13_EventScript_RouteSign::
	msgbox Route13_Text_Sign, MSGBOX_SIGN
	end

Route13_EventScript_DirectionsSign::
	msgbox Route13_Text_DirectionsSign, MSGBOX_SIGN
	end

Route13_Text_PokefanmAlexSeen:
	.string "Inchinatevi ai miei POKéMON regali!$"

Route13_Text_PokefanmAlexBeaten:
	.string "Come… Come osi deridere la monarchia!$"

Route13_Text_PokefanmAlexAfterBattle:
	.string "Non desiderano tutti, un giorno,\n"
	.string "diventare un re?$"

Route13_Text_AlexRegister:
	.string "Non sei di sangue reale ma sei bravo.\n"
	.string "Dammi il tuo numero.$"

Route13_Text_AlexRematchIntro:
	.string "Ho aggiunto cavalieri alla mia corte!\n"
	.string "Lottiamo!$"

Route13_Text_AlexRematchDefeat:
	.string "Detronizzato di nuovo…$"

Route13_Text_AlexPostRematch:
	.string "Forse in fondo sono solo una pedina.$"

Route13_Text_PokefanmJoshuaSeen:
	.string "Nihihi! Vuoi lottare\n"
	.string "con la mia banda di PIKACHU?$"

Route13_Text_PokefanmJoshuaBeaten:
	.string "PI-PIKACHU!$"

Route13_Text_PokefanmJoshuaAfterBattle:
	.string "Sembra che tu abbia molti\n"
	.string "POKéMON, ma PIKACHU\l"
	.string "è comunque il migliore.$"

Route13_Text_BirdKeeperPerrySeen:
	.string "L'Agilità è la qualità chiave dei\n"
	.string "POKéMON uccello.$"

Route13_Text_BirdKeeperPerryBeaten:
	.string "Mi hai battuto con la tua velocità…$"

Route13_Text_BirdKeeperPerryAfterBattle:
	.string "I tuoi POKéMON sono allenati\n"
	.string "in modo straordinario.$"

Route13_Text_BirdKeeperBretSeen:
	.string "Ammira i miei POKéMON. Guarda\n"
	.string "il loro colore e il loro\l"
	.string "piumaggio.$"

Route13_Text_BirdKeeperBretBeaten:
	.string "Dannazione! Non ci siamo!$"

Route13_Text_BirdKeeperBretAfterBattle:
	.string "Se li spazzoli, i POKéMON diventano\n"
	.string "felici.$"

Route13_Text_HikerKennySeen:
	.string "Dovrei andare al ROCK TUNNEL a\n"
	.string "prendermi un ONIX.$"

Route13_Text_HikerKennyBeaten:
	.string "Ho perso…$"

Route13_Text_HikerKennyAfterBattle:
	.string "Le formazioni geologiche sembrano\n"
	.string "non cambiare.\p"
	.string "Ma in realtà cambiano, poco\n"
	.string "alla volta.$"

Route13_Text_KennyRegister:
	.string "Maybe POKéMON change over time too.\n"
	.string "Let's battle again sometime!$"

Route13_Text_KennyRematchIntro:
	.string "Ho imparato dalla geologia!\n"
	.string "Andiamo!$"

Route13_Text_KennyRematchDefeat:
	.string "Ancora non basta…$"

Route13_Text_KennyPostRematch:
	.string "La forza dei POKéMON è come\n"
	.string "l'erosione. Resisteremo!$"

Route13_Text_TrainerTips:
	.string "CONSIGLI PER ALLENATORI\p"
	.string "Guarda! Proprio lì, a sinistra\n"
	.string "del palo.$"

Route13_Text_Sign:
	.string "ROUTE 13\p"
	.string "A NORD VERSO SILENCE BRIDGE$"

Route13_Text_DirectionsSign:
	.string "A NORD VERSO LAVENDER TOWN\p"
	.string "A OVEST VERSO FUCHSIA CITY$"

Route13_GetOffBoat::
	lock
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 77
	goto_if_ne Route13_GetOffBoat_2
	compare VAR_TEMP_1, 26
	goto_if_ne Route13_GetOffBoat_2
	delay 30
	applymovement Route13_Alola_Captain, Route13_GetOffBoat_Movement_0
	applymovement LOCALID_PLAYER, Route13_GetOffBoat_Movement_1
	waitmovement 0
	msgbox Route13_GetOffBoat_Text_0, MSGBOX_AUTOCLOSE
	setvar VAR_ALOLA_TRAVEL, 0
	applymovement LOCALID_ROUTE13_BOAT, Route13_TravelToAlola_Movement_2
	waitmovement 0
	setobjectxyperm LOCALID_ROUTE13_BOAT, 89, 28
	removeobject LOCALID_ROUTE13_BOAT
	applymovement LOCALID_PLAYER, Route13_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0
	waitmovement 0
	release
	end

Route13_GetOffBoat_2:
	setvar VAR_ALOLA_TRAVEL, 0
	release
	end


Route13_TravelToAlola::
	lock
	faceplayer
	checkitem ITEM_STRANGE_SOUVENIR
	compare VAR_RESULT, 0
	goto_if_ne Route13_TravelToAlola_1
	msgbox Route13_TravelToAlola_Text_4, MSGBOX_AUTOCLOSE
	release
	end

Route13_TravelToAlola_1:
	goto_if_unset FLAG_VISITED_ALOLA, Route13_TravelToAlola_4
	msgbox Route13_TravelToAlola_Text_3, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route13_TravelToAlola_10
	msgbox Route13_TravelToAlola_Text_2, MSGBOX_AUTOCLOSE
	release
	end

Route13_TravelToAlola_4:
	msgbox Route13_TravelToAlola_Text_0, MSGBOX_DEFAULT
	closemessage
	helpwindow HELP_ALOLA_WINDOW
	msgbox Route13_TravelToAlola_Text_0_5, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route13_TravelToAlola_7
	msgbox Route13_TravelToAlola_Text_2, MSGBOX_AUTOCLOSE
	release
	end

Route13_TravelToAlola_7:
	msgbox Route13_TravelToAlola_Text_1, MSGBOX_AUTOCLOSE
	goto_if_eq VAR_FACING, DIR_SOUTH, Route13_TravelToAlola_14
Route13_TravelToAlola_13:
	addobject LOCALID_ROUTE13_BOAT
	clearflag FLAG_HIDE_ROUTE13_BOAT
	applymovement LOCALID_ROUTE13_BOAT, Route13_Movement_BoatArrive
	waitmovement 0
	applymovement Route13_Alola_Captain, Route13_TravelToAlola_Movement_1
	applymovement LOCALID_PLAYER, Route13_TravelToAlola_Movement_1
	waitmovement 0
	fadescreenswapbuffers FADE_TO_BLACK
	hidefollower
	playse SE_EXIT
	special SpawnCameraObject
	hideobjectat LOCALID_PLAYER, MAP_ROUTE13_HNS
	hideobjectat Route13_Alola_Captain, MAP_ROUTE13_HNS
	applymovement OBJ_EVENT_ID_CAMERA, Route13_TravelToAlola_Movement_1
	waitmovement 0
	waitse
	delay 30
	fadescreenswapbuffers FADE_FROM_BLACK
	playse SE_RG_SS_ANNE_HORN

	playse SE_M_SURF
	applymovement LOCALID_ROUTE13_BOAT, Route13_TravelToAlola_Movement_2
	setvar VAR_ALOLA_TRAVEL, 1
	setflag FLAG_HIDE_MELEMELE_TOTEM
	setflag FLAG_HIDE_AKALA_TOTEM
	setflag FLAG_HIDE_ULAULA_TOTEM
	setflag FLAG_HIDE_PONI_TOTEM
	setflag FLAG_HIDE_SAMSONOAK_INTRO
	setflag FLAG_HIDE_TAPU_KOKO
	setflag FLAG_HIDE_TAPU_LELE
	setflag FLAG_HIDE_TAPU_BULU
	setflag FLAG_HIDE_TAPU_FINI
	setflag FLAG_HIDE_FLYOVER
	setflag FLAG_HIDE_PHANT_OUTSIDE
	setflag FLAG_HIDE_PHANT_INSIDE
	delay 90
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_ROUTE13_BOAT
	special RemoveCameraObject
	warp MAP_MELEMELE_ISLE_HNS, 25, 33
	waitstate
	end

Route13_TravelToAlola_10:
	msgbox Route13_TravelToAlola_Text_1, MSGBOX_AUTOCLOSE
	goto_if_eq VAR_FACING, DIR_SOUTH, Route13_TravelToAlola_17
Route13_TravelToAlola_16:
	addobject LOCALID_ROUTE13_BOAT
	clearflag FLAG_HIDE_ROUTE13_BOAT
	applymovement LOCALID_ROUTE13_BOAT, Route13_Movement_BoatArrive
	waitmovement 0
	applymovement Route13_Alola_Captain, Route13_TravelToAlola_Movement_1
	applymovement LOCALID_PLAYER, Route13_TravelToAlola_Movement_1
	waitmovement 0
	fadescreenswapbuffers FADE_TO_BLACK
	hidefollower
	playse SE_EXIT
	special SpawnCameraObject
	hideobjectat LOCALID_PLAYER, MAP_ROUTE13_HNS
	hideobjectat Route13_Alola_Captain, MAP_ROUTE13_HNS
	applymovement OBJ_EVENT_ID_CAMERA, Route13_TravelToAlola_Movement_1
	waitmovement 0
	waitse
	delay 30
	fadescreenswapbuffers FADE_FROM_BLACK
	playse SE_RG_SS_ANNE_HORN
	waitse
	playse SE_M_SURF
	applymovement LOCALID_ROUTE13_BOAT, Route13_TravelToAlola_Movement_2
	setvar VAR_ALOLA_TRAVEL, 1
	delay 90
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_ROUTE13_BOAT
	special RemoveCameraObject
	warp MAP_MELEMELE_ISLE_HNS, 25, 33
	waitstate
	end

Route13_TravelToAlola_14:
	applymovement LOCALID_PLAYER, Route13_TravelToAlola_Movement_0
	waitmovement 0
	goto Route13_TravelToAlola_13

Route13_TravelToAlola_17:
	applymovement LOCALID_PLAYER, Route13_TravelToAlola_Movement_0
	waitmovement 0
	goto Route13_TravelToAlola_16


Route13_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0:
	face_up
	step_end

Route13_GetOffBoat_Movement_0:
	face_left
	step_end

Route13_GetOffBoat_Movement_1:
	face_right
	step_end

Route13_TravelToAlola_Movement_0:
	walk_left
	walk_down
	step_end

Route13_TravelToAlola_Movement_1:
	walk_down
	step_end

Route13_TravelToAlola_Movement_2:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route13_Movement_BoatArrive:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route13_GetOffBoat_Text_0:
	.string "Bentornato nella terraferma di Kanto!\p"
	.string "Torna quando vuoi fare un viaggio\n"
	.string "verso le ISOLE DI ALOLA!$"

Route13_TravelToAlola_Text_0:
	.string "Ehi, tu!\p"
	.string "Che strano souvenir.\n"
	.string "Vieni dalle ISOLE!$"
Route13_TravelToAlola_Text_0_5:
	.string "Vuoi prendere la prossima nave?\n"
	.string "Parte tra poco!$"

Route13_TravelToAlola_Text_1:
	.string "Ahoy! Ti faccio salire a bordo!$"

Route13_TravelToAlola_Text_2:
	.string "Ahoy!\n"
	.string "Torna quando vuoi salpare.$"

Route13_TravelToAlola_Text_3:
	.string "Ah, sei di nuovo tu!\n"
	.string "Vuoi andare alle ISOLE DI ALOLA?$"

Route13_TravelToAlola_Text_4:
	.string "Ehi!\n"
	.string "Questo porto è per i residenti.\p"
	.string "Tutti i residenti di queste ISOLE\n"
	.string "portano… {PAUSE 30}strani souvenir.\p"
	.string "Così li riconosco subito,\n"
	.string "non devo nemmeno controllare i biglietti!$"
