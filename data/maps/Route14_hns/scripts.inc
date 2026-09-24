Route14_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route14_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route14_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route14_TriggerSuicune_5::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Route14_Movement_5
	waitmovement 0
	goto Route14_EventScript_Suicune

Route14_TriggerSuicune_4::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Route14_Movement_4
	waitmovement 0
	goto Route14_EventScript_Suicune

Route14_TriggerSuicune_3::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Route14_Movement_3
	waitmovement 0
	goto Route14_EventScript_Suicune

Route14_TriggerSuicune_2::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	goto Route14_EventScript_Suicune

Route14_TriggerSuicune_1::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 60
	goto Route14_EventScript_Suicune

Route14_Movement_5:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route14_Movement_4:
	walk_right
	walk_right
	walk_right
	step_end

Route14_Movement_3:
	walk_right
	walk_right
	step_end

Route14_EventScript_Suicune::
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE14_SUICUNE, Route14_Movement_SuicuneLeave
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	waitmovement 0
	clearflag FLAG_HIDE_ROUTE14_EUSINE
	addobject LOCALID_ROUTE14_EUSINE
	applymovement LOCALID_ROUTE14_EUSINE, Route14_Movement_EusineEnter
	delay 60
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	waitmovement 0
	msgbox Route14_Text_Eusine, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE14_EUSINE, Route14_Movement_EusineLeave
	waitmovement 0
	setflag FLAG_HIDE_ROUTE14_EUSINE
	setflag FLAG_HIDE_ROUTE14_SUICUNE
	removeobject LOCALID_ROUTE14_SUICUNE
	removeobject LOCALID_ROUTE14_EUSINE
	setvar VAR_SUICUNE_ENCOUNTERS, 5
	call_if_ge VAR_CERULEAN_CITY_STATE, 3, CeruleanCity_Gym_SetSuicuneScene
	closemessage
	release
	end

Route14_Movement_SuicuneLeave:
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_2_up
	jump_2_up
	jump_2_up
	jump_2_up
	jump_2_up
	jump_2_up
	step_end

Route14_Movement_EusineEnter:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_up
	walk_slow_up
	walk_slow_up
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_slow_down
	walk_slow_down
	walk_slow_right
	step_end

Route14_Movement_EusineLeave:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route14_EventScript_Carter::
	trainerbattle_single TRAINER_CARTER_HNS, Route14_Text_PokefanmCarterSeen, Route14_Text_PokefanmCarterBeaten, Route14_EventScript_RegisterCarter
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route14_EventScript_RematchCarter
	msgbox Route14_Text_PokefanmCarterAfterBattle, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_RegisterCarter::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route14_Text_CarterRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CARTER_HNS
	release
	end

Route14_EventScript_RematchCarter::
	trainerbattle_rematch TRAINER_CARTER_HNS, Route14_Text_CarterRematchIntro, Route14_Text_CarterRematchDefeat
	msgbox Route14_Text_CarterPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_CARTER_2_HNS, Route14_EventScript_RematchCarterTryGiveItem
	end

Route14_EventScript_RematchCarterTryGiveItem::
	checkitem ITEM_TM_THUNDER_WAVE
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_THUNDER_WAVE
	closemessage
	end

Route14_EventScript_Roy::
	trainerbattle_single TRAINER_ROY_HNS, Route14_Text_BirdKeeperRoySeen, Route14_Text_BirdKeeperRoyBeaten
	msgbox Route14_Text_BirdKeeperRoyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_Trevor::
	trainerbattle_single TRAINER_TREVOR_HNS, Route14_Text_PokefanmTrevorSeen, Route14_Text_PokefanmTrevorBeaten, Route14_EventScript_RegisterTrevor
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route14_EventScript_RematchTrevor
	msgbox Route14_Text_PokefanmTrevorAfterBattle, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_RegisterTrevor::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route14_Text_TrevorRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TREVOR_HNS
	release
	end

Route14_EventScript_RematchTrevor::
	trainerbattle_rematch TRAINER_TREVOR_HNS, Route14_Text_TrevorRematchIntro, Route14_Text_TrevorRematchDefeat
	msgbox Route14_Text_TrevorPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_TREVOR_2_HNS, Route14_EventScript_RematchTrevorTryGiveItem
	end

Route14_EventScript_RematchTrevorTryGiveItem::
	checkitem ITEM_TM_WILL_O_WISP
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_WILL_O_WISP
	closemessage
	end



Route14_Text_Eusine:
	.string "EUGENIUS: {PLAYER}! Ancora tu!\n"
	.string "Stavolta arrivo prima io!\p"
	.string "Seguendolo fin qui,\n"
	.string "comincio a capire cosa\l"
	.string "cerchi SUICUNE.\p"
	.string "A dire il vero, vorrei\n"
	.string "tenermele per me.\p"
	.string "Ma voglio essere onesto\n"
	.string "davanti a SUICUNE!\p"
	.string "Perciò ti do un indizio.\n"
	.string "Sembra che...\p"
	.string "SUICUNE preferisca i\n"
	.string "luoghi collinari...\l"
	.string "Vicino all'acqua...\l"
	.string "Da qualche parte a nord...\p"
	.string "Non so ancora dove.\n"
	.string "Saremo io e te!\p"
	.string "Chi lo trova prima?\n"
	.string "Ti sfido!$"

Route14_Text_PokefanmTrevorSeen:
	.string "Ciao. Lo sapevi…?\p"
	.string "I POKéMON diventano più amichevoli\n"
	.string "se li alleni in un luogo che\l"
	.string "ricordano.$"

Route14_Text_PokefanmTrevorBeaten:
	.string "Dove ho incontrato questo SCIZOR?$"

Route14_Text_PokefanmTrevorAfterBattle:
	.string "Se solo ci fosse un modo facile\n"
	.string "per sapere dove ho preso i POKéMON…$"

Route14_Text_TrevorRegister:
	.string "Sei interessante!\n"
	.string "Posso avere il tuo numero?$"

Route14_Text_TrevorRematchIntro:
	.string "Mi sono allenato con i miei\n"
	.string "POKéMON in luoghi familiari!$"

Route14_Text_TrevorRematchDefeat:
	.string "Forse mi servono posti nuovi…$"

Route14_Text_TrevorPostRematch:
	.string "L'amicizia rende i POKéMON\n"
	.string "più forti. Ne sono certo!$"

Route14_Text_PokefanmCarterSeen:
	.string "Ti dico, ho faticato non poco\n"
	.string "a catturare i miei POKéMON.$"

Route14_Text_PokefanmCarterBeaten:
	.string "Aaaah!$"

Route14_Text_PokefanmCarterAfterBattle:
	.string "TOTODILE, CYNDAQUIL, CHIKORITA…\p"
	.string "Direi un mix ben equilibrato.$"

Route14_Text_CarterRegister:
	.string "Te ne intendi di starter!\n"
	.string "Dammi il tuo numero!$"

Route14_Text_CarterRematchIntro:
	.string "Ho trovato starter ancora più rari\n"
	.string "da sfoggiare! Lottiamo!$"

Route14_Text_CarterRematchDefeat:
	.string "I miei preziosi starter…$"

Route14_Text_CarterPostRematch:
	.string "Ci sono tanti starter di regioni\n"
	.string "diverse da collezionare!$"

Route14_Text_BirdKeeperRoySeen:
	.string "Sogno di volare col mio amato\n"
	.string "POKéMON uccello.$"

Route14_Text_BirdKeeperRoyBeaten:
	.string "Posso sognarlo, ma non volerò mai…$"

Route14_Text_BirdKeeperRoyAfterBattle:
	.string "Hai POKéMON che conoscono la MN\n"
	.string "VOLO, vero? Ti invidio.$"

Route14_EventScript_Pidgeotto::
	lockall
	faceplayer
	playmoncry SPECIES_PIDGEOTTO, CRY_MODE_NORMAL
	msgbox Route14_Text_Pidgeotto, MSGBOX_DEFAULT
	waitmoncry
	goto_if_set FLAG_GOT_ROUTE_14_AERIAL_ACE, Route14_EventScript_PidgeottoBlowPlayer
	msgbox Route14_Text_PidgeottoBerry, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route14_EventScript_PidgeottoBlowPlayer
	fadescreen FADE_TO_BLACK
	special Bag_ChooseBerry
	waitstate
	removeitem VAR_ITEM_ID, 1
	goto_if_ne VAR_ITEM_ID, ITEM_QUALOT_BERRY, Route14_EventScript_PidgeottoDislikedBerry
	msgbox Route14_Text_PidgeottoAteBerry, MSGBOX_DEFAULT
	giveitem ITEM_TM_AERIAL_ACE
	setflag FLAG_GOT_ROUTE_14_AERIAL_ACE
Route14_EventScript_PidgeottoBlowPlayer::
	closemessage
	playse SE_M_TWISTER
	call_if_eq VAR_FACING, DIR_EAST, Route14_EventScript_PidgeottoBlowPlayerLeft
	releaseall
	end
Route14_EventScript_PidgeottoDislikedBerry::
	msgbox Route14_Text_PidgeottoTurnedAway, MSGBOX_DEFAULT
	goto Route14_EventScript_PidgeottoBlowPlayer

Route14_EventScript_PidgeottoBlowPlayerLeft::
	applymovement LOCALID_ROUTE14_PIDGEOTTO, Route14_Movement_JumpLeft
	applymovement OBJ_EVENT_ID_PLAYER, Route14_Movement_Player_BlownLeft
	waitmovement 0
	return

Route14_Movement_Player_BlownUp:
	lock_facing_direction
	walk_up
	walk_up
	unlock_facing_direction
	step_end

Route14_Movement_Player_BlownLeft:
	face_up
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	lock_facing_direction
	walk_left
	walk_left
	unlock_facing_direction
	step_end

Route14_Movement_JumpUp:
	jump_in_place_up
	step_end

Route14_Movement_JumpLeft:
	jump_in_place_left
	step_end

Route14_Movement_StuckPidgeottoJump0:
	jump_in_place_up
	step_end

Route14_Movement_StuckPidgeottoJump:
	jump_2_up
	jump_in_place_left_right
	jump_in_place_left_right
	face_left
	step_end

Route14_Text_Pidgeotto:
	.string "PIDGEOTTO: Kaaaaa!$"
Route14_Text_PidgeottoBerry:
	.string "Dare una BACCA al PIDGEOTTO?$"
Route14_Text_PidgeottoAteBerry:
	.string "PIDGEOTTO ha mangiato la BACCA QUALOT!$"
Route14_Text_PidgeottoTurnedAway:
	.string "Al PIDGEOTTO non piace!$"

