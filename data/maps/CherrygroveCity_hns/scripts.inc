CherrygroveCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CherryGroveCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

CherryGroveCity_OnTransition::
	callnative SetTimeBasedEncounters
	end

CherryGroveCity_EventScript_TriggerGent_Top::
	lock
	setflag FLAG_VISITED_CHERRYGROVE_CITY
	setflag FLAG_HIDE_CHERRYGROVE_GUIDE_GENT_HOUSE
	playse SE_PIN
	applymovement LOCALID_GUIDE_GENT, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GUIDE_GENT
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox CherrygroveCity_Text_GuideGentIntro, MSGBOX_YESNO
	waitmessage
	goto_if_eq VAR_RESULT, NO, CherryGroveCity_EventScript_TriggerGent_Cancel
	msgbox CherrygroveCity_Text_GuideGentTourStart, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Trigger_Top
	waitmovement 0 
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Trigger_Gent
	waitmovement 0 
	goto CherryGroveCity_EventScript_GentTour
	release
	end

CherryGroveCity_EventScript_TriggerGent_Mid::
	lock
	setflag FLAG_VISITED_CHERRYGROVE_CITY
	setflag FLAG_HIDE_CHERRYGROVE_GUIDE_GENT_HOUSE
	playse SE_PIN
	applymovement LOCALID_GUIDE_GENT, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GUIDE_GENT
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox CherrygroveCity_Text_GuideGentIntro, MSGBOX_YESNO
	waitmessage
	goto_if_eq VAR_RESULT, NO, CherryGroveCity_EventScript_TriggerGent_Cancel
	msgbox CherrygroveCity_Text_GuideGentTourStart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Trigger_Gent
	waitmovement 0 
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	goto CherryGroveCity_EventScript_GentTour
	release
	end

CherryGroveCity_EventScript_TriggerGent_Bottom::
	lock
	setflag FLAG_VISITED_CHERRYGROVE_CITY
	setflag FLAG_HIDE_CHERRYGROVE_GUIDE_GENT_HOUSE
	playse SE_PIN
	applymovement LOCALID_GUIDE_GENT, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GUIDE_GENT
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox CherrygroveCity_Text_GuideGentIntro, MSGBOX_YESNO
	waitmessage
	goto_if_eq VAR_RESULT, NO, CherryGroveCity_EventScript_TriggerGent_Cancel
	msgbox CherrygroveCity_Text_GuideGentTourStart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Trigger_Gent
	waitmovement 0 
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Trigger_Bottom
	waitmovement 0 
	goto CherryGroveCity_EventScript_GentTour
	release
	end

CherryGroveCity_EventScript_TriggerGent_Cancel::
	msgbox CherrygroveCity_Text_GuideGentDecline, MSGBOX_DEFAULT
	closemessage
	setvar VAR_CHERRYGROVE_CITY_STATE, 1 @ CHANGE THIS TO 1 LATER
	release
	end

CherryGroveCity_EventScript_GentTour::
	playbgm MUS_HG_FOLLOW_ME_2, FALSE
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Pokecenter
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Pokecenter
	waitmovement 0
	waitmovement 0
	msgbox CherrygroveCity_Text_GuideGentPokecenter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Pokemart
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Pokemart
	waitmovement 0
	waitmovement 0
	msgbox CherrygroveCity_Text_GuideGentMart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Route30
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Route30
	waitmovement 0
	waitmovement 0
	msgbox CherrygroveCity_Text_GuideGentRoute30, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Sea
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Sea
	waitmovement 0
	waitmovement 0
	msgbox CherrygroveCity_Text_GuideGentSea, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_House_Gent
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_House_Player
	waitmovement 0
	waitmovement 0
	delay 20
	msgbox CherrygroveCity_Text_GuideGentMap, MSGBOX_DEFAULT
	closemessage

	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Gent_Leave
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	delay 20
	opendoor 42, 14
	waitdooranim
	waitmovement 0
	removeobject LOCALID_GUIDE_GENT
	closedoor 42, 14
	waitdooranim
	
	clearflag FLAG_HIDE_CHERRYGROVE_GUIDE_GENT_HOUSE
	setflag FLAG_HIDE_GUIDE_GENT_CHERRYGROVE
	setvar VAR_CHERRYGROVE_CITY_STATE, 1
	fadedefaultbgm
	release
	end

CherryGroveCity_EventScript_Fisherman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_MYSTICWATER, CherryGroveCity_EventScript_Fisherman2
	msgbox CherrygroveCity_Text_MysticWaterGuyBefore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CherryGroveCity_EventScript_Fisherman2
	giveitem ITEM_MYSTIC_WATER
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull 
	closemessage
	setflag FLAG_GOT_MYSTICWATER
	release
	end

CherryGroveCity_EventScript_Fisherman2::
	msgbox CherrygroveCity_Text_MysticWaterGuyAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGroveCity_EventScript_Lass::
	lock
	faceplayer
	msgbox CherrygroveCity_Text_TeacherHaveMapCard, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGroveCity_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, CherryGroveCity_EventScript_Boy2
	msgbox CherrygroveCity_Text_YoungsterNoPokedex, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGroveCity_EventScript_Boy2::
	msgbox CherrygroveCity_Text_YoungsterHavePokedex, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGroveCity_EventScript_Staryu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_STARYU, CRY_MODE_NORMAL
	msgbox CherryGroveCity_Text_Staryu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CherryGroveCity_EventScript_Corsola::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CORSOLA, CRY_MODE_NORMAL
	msgbox CherryGroveCity_Text_Corsola, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CherryGroveCity_EventScript_Krabby::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KRABBY, CRY_MODE_NORMAL
	msgbox CherryGroveCity_Text_Krabby, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CherryGroveCity_EventScript_Sign::
	lock
	msgbox CherrygroveCity_Text_CitySign, MSGBOX_SIGN
	closemessage
	release
	end	

CherryGroveCity_EventScript_TriggerSilver_Top::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Trigger_Silver_Top
	waitmovement 0
	goto CherryGroveCity_EventScript_TriggerSilver
	end

CherryGroveCity_EventScript_TriggerSilver_Bottom::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Trigger_Silver_Bottom
	waitmovement 0
	goto CherryGroveCity_EventScript_TriggerSilver
	end

CherryGroveCity_EventScript_TriggerSilver::
	lock
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	applymovement LOCALID_CHERRYGROVE_SILVER, CherryGroveCity_Movement_Silver_Enter
	waitmovement 0
	msgbox CherrygroveCity_Text_RivalSeen, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_STARTER_MON, 0, CherryGroveCity_Silver_Battle_Cyndaquil
	goto_if_eq VAR_STARTER_MON, 1, CherryGroveCity_Silver_Battle_Totodile
	goto_if_eq VAR_STARTER_MON, 2, CherryGroveCity_Silver_Battle_Chikorita
	release
	end

CherryGroveCity_Silver_Battle_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_1_HNS, CherrygroveCity_Text_SilverWin
	goto CherryGroveCity_Silver_AfterBattle

CherryGroveCity_Silver_Battle_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_1_HNS, CherrygroveCity_Text_SilverWin
	goto CherryGroveCity_Silver_AfterBattle

CherryGroveCity_Silver_Battle_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_1_HNS, CherrygroveCity_Text_SilverWin
	goto CherryGroveCity_Silver_AfterBattle

CherryGroveCity_Silver_AfterBattle::
	playbgm MUS_HG_RIVAL_EXIT, FALSE
	msgbox CherrygroveCity_Text_RivalAfter, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Silver_Leave1Player
	applymovement LOCALID_CHERRYGROVE_SILVER, CherryGroveCity_Movement_Silver_Leave1
	waitmovement 0
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_CHERRYGROVE_SILVER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_CHERRYGROVE_SILVER
	turnobject LOCALID_CHERRYGROVE_SILVER, DIR_EAST
	delay 60
	turnobject LOCALID_CHERRYGROVE_SILVER, DIR_SOUTH
	delay 30
	applymovement LOCALID_CHERRYGROVE_SILVER, CherryGroveCity_Movement_Silver_Return
	waitmovement 0
	msgbox CherrygroveCity_Text_RivalID, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CHERRYGROVE_SILVER, CherryGroveCity_Movement_Silver_Leave2
	waitmovement 0
	removeobject LOCALID_CHERRYGROVE_SILVER
	setflag FLAG_HIDE_SILVER_CHERRYGROVE
	setvar VAR_CHERRYGROVE_CITY_STATE, 4
	fadedefaultbgm
	release
	end

CherrygroveCity_Text_GuideGentIntro:
	.string "Sei un principiante,\n"
	.string "vero? Si vede!\p"
	.string "Non c'è problema! Tutti\n"
	.string "si parte da zero!\p"
	.string "Se vuoi, ti insegno\n"
	.string "un paio di cose.$"

CherrygroveCity_Text_GuideGentTourStart:
	.string "Va bene!\n"
	.string "Seguimi!$"

CherrygroveCity_Text_GuideGentPokecenter:
	.string "È un POKéMON CENTER.\p"
	.string "Curano i tuoi POKéMON in un\n"
	.string "attimo.\p"
	.string "Ti serviranno spesso, quindi\n"
	.string "fai bene a conoscerli.$"

CherrygroveCity_Text_GuideGentMart:
	.string "È un POKéMON MART.\p"
	.string "Vendono BALL per catturare\n"
	.string "POKéMON e oggetti utili.$"

CherrygroveCity_Text_GuideGentRoute30:
	.string "Il PERCORSO 30 è di là.\p"
	.string "Gli allenatori si sfidano\n"
	.string "con i loro POKéMON.$"

CherrygroveCity_Text_GuideGentSea:
	.string "Questo è il mare, come vedi.\p"
	.string "Alcuni POKéMON vivono solo\n"
	.string "in acqua.$"

CherrygroveCity_Text_GuideGentMap:
	.string "Ecco…\p"
	.string "È casa mia! Grazie della\n"
	.string "compagnia.\p"
	.string "E se ti perdi, controlla la\n"
	.string "MAPPA sul POKéGEAR!\p"
	.string "Buona fortuna per il viaggio!$"

CherrygroveCity_Text_GuideGentDecline:
	.string "Oh… È una cosa che adoro\n"
	.string "fare…\p"
	.string "Va bene. Passa quando\n"
	.string "vuoi.$"

CherrygroveCity_Text_RivalSeen:
	.string "… … … … … … … …\p"
	.string "Hai preso un POKéMON al LAB.\p"
	.string "Che spreco.\n"
	.string "Per uno come te.\p"
	.string "… … … … … … … …\p"
	.string "Non capisci quello che dico?\n"
	.string "Beh, anche io ho un bel POKéMON.\p"
	.string "Ti mostro cosa intendo!$"

CherrygroveCity_Text_SilverWin:
	.string "Umpf. Felice di aver vinto?$"

CherrygroveCity_Text_RivalAfter:
	.string "… … … … … … … …\p"
	.string "Vuoi sapere chi sono?\p"
	.string "Sarò il più grande\n"
	.string "allenatore di POKéMON.$"

CherrygroveCity_Text_RivalID:
	.string "Ridammelo!\n"
	.string "È la mia SCHEDA ALLENATORE!\p"
	.string "Oh no!\n"
	.string "Hai visto il nome…$"

CherrygroveCity_Text_TeacherHaveMapCard:
	.string "Con i POKéMON al seguito,\n"
	.string "andare ovunque è bello.$"

CherrygroveCity_Text_YoungsterNoPokedex:
	.string "La casa del SIG. POKéMON è\n"
	.string "poco più avanti.$"

CherrygroveCity_Text_YoungsterHavePokedex:
	.string "Ho sfidato gli allenatori\n"
	.string "sulla\p"
	.string "strada. I miei POKéMON\n"
	.string "hanno perso! Devo andare al\l"
	.string "CENTRO POKéMON!$"

CherrygroveCity_Text_MysticWaterGuyBefore:
	.string "Il POKéMON che ho preso\n"
	.string "ha un\p"
	.string "oggetto: ACQUA MAGICA.\p"
	.string "Non mi serve, lo\n"
	.string "vuoi?$"

CherrygroveCity_Text_MysticWaterGuyAfter:
	.string "Torno a pescare, allora.$"

CherrygroveCity_Text_CitySign:
	.string "FIORLISOPOLI\p"
	.string "La città dei bei fiori\n"
	.string "soavi$"

CherrygroveCity_Text_GuideGentsHouseSign:
	.string "CASA DELLA GUIDA$"

CherryGroveCity_Text_Staryu:
	.string "STARYU: Yuuuuuuuu.$"

CherryGroveCity_Text_Corsola:
	.string "CORSOLA: Corsola! La!$"

CherryGroveCity_Text_Krabby:
	.string "KRABBY: KOOOOKEEE!$"

CherryGroveCity_Movement_Trigger_Gent:
	walk_down
	walk_left
	walk_down
	face_left
	step_end

CherryGroveCity_Movement_Trigger_Top:
	walk_down
	face_up
	step_end

CherryGroveCity_Movement_Trigger_Bottom:
	walk_up
	face_up
	step_end

CherryGroveCity_Movement_Pokecenter:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

CherryGroveCity_Movement_Pokemart:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

CherryGroveCity_Movement_Route30:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

CherryGroveCity_Movement_Sea:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

CherryGroveCity_Movement_House_Gent:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
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
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

CherryGroveCity_Movement_House_Player:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
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
	walk_right
	walk_right
	walk_right
	face_up
	step_end

CherryGroveCity_Movement_Gent_Leave:
	walk_up
	walk_up
	step_end

CherryGroveCity_Movement_Trigger_Silver_Top:
	walk_down
	face_right
	step_end

CherryGroveCity_Movement_Trigger_Silver_Bottom:
	walk_up
	face_right
	step_end

CherryGroveCity_Movement_Silver_Enter:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

CherryGroveCity_Movement_Silver_Leave1:
	delay_16
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

CherryGroveCity_Movement_Silver_Leave1Player:
	lock_facing_direction
	walk_fast_down
	unlock_facing_direction
	face_up
	step_end

CherryGroveCity_Movement_Silver_Return:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_down
	step_end


CherryGroveCity_Movement_Silver_Leave2:
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
