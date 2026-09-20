EcruteakCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

EcruteakCity_OnTransition::
	callnative SetTimeBasedEncounters
	end

EcruteakCity_Test_Lugia::
	setvar VAR_LUGIA_OR_HOOH, 1
	end
EcruteakCity_Test_League::
	setvar VAR_COMPLETED_HO_OH, 4
	setvar VAR_COMPLETED_LUGIA, 4
	end


EcruteakCity_EventScript_Trigger::
	@flagheap
	clearflag FLAG_RELEASED_BEASTS
	clearflag FLAG_AMPHAROS_HEALED
	clearflag FLAG_HIDE_ECRUTEAK_BILL
	clearflag FLAG_DEFEATED_HO_OH
	clearflag FLAG_CAUGHT_HO_OH
	clearflag FLAG_DEFEATED_LUGIA
	clearflag FLAG_CAUGHT_LUGIA
	clearflag FLAG_HIDE_ECRUTEAK_ROCKET
	clearflag FLAG_HIDE_BURNED_TOWER_NPCS  
	clearflag FLAG_HIDE_BURNED_TOWER_BEASTS
	clearflag FLAG_HIDE_BURNED_TOWER_B1F_EUSINE
	clearflag FLAG_HIDE_ECRUTEAK_CITY_SAGE
	clearflag FLAG_CAUGHT_ENTEI
	clearflag FLAG_CAUGHT_RAIKOU
	clearflag FLAG_GOT_TM_SNATCH
	clearflag FLAG_HIDE_ROUTE42_SUICUNE
	clearflag FLAG_GOT_TYROGUE
	clearflag FLAG_BEAT_KIYO
	clearflag FLAG_ENABLE_BAOBA_MATCH_CALL
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_ZUKI
	clearflag FLAG_HIDE_TINTOWER_GUARD
	clearflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	clearflag FLAG_HIDE_LUGIA
	clearflag FLAG_HIDE_HO_OH

	setflag FLAG_VISITED_ECRUTEAK_CITY
	setflag FLAG_HIDE_ROUTE42_EUSINE

	setflag FLAG_HIDE_TIN_TOWER_KIMONO_GIRLS
	setflag FLAG_HIDE_WHIRL_ISLANDS_KIMONO_GIRLS
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	setflag FLAG_HIDE_ROUTE39_SHADOW
	setflag FLAG_HIDE_ECRUTEAK_SILVER
	setvar VAR_COMPLETED_HO_OH, 0
	setvar VAR_COMPLETED_LUGIA, 0
	setvar VAR_ECRUTEAK_CITY_THEATER, 0 
	setvar VAR_ECRUTEAK_CITY_STATE, 1
	end

EcruteakCity_Trigger_Silver::
	lockall
	opendoor 39, 40
	waitdooranim
	delay 10
	clearflag FLAG_HIDE_ECRUTEAK_SILVER
	addobject LOCALID_ECRUTEK_SILVER
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	playse SE_BANG
	applymovement LOCALID_ECRUTEK_SILVER, EcruteakCity_Movement_Silver1
	applymovement OBJ_EVENT_ID_PLAYER, EcruteakCity_Movement_Silver1
	message EcruteakCity_Text_Silver1
	
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_ECRUTEK_SILVER
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	closedoor 39, 40
	waitdooranim
	msgbox EcruteakCity_Text_Silver2, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_ECRUTEK_SILVER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ECRUTEK_SILVER
	turnobject LOCALID_ECRUTEK_SILVER, DIR_SOUTH
	msgbox EcruteakCity_Text_Silver3, MSGBOX_DEFAULT
	closemessage

	applymovement LOCALID_ECRUTEK_SILVER, EcruteakCity_Movement_Silver2
	waitmovement LOCALID_ECRUTEK_SILVER


	setflag FLAG_HIDE_ECRUTEAK_SILVER
	removeobject LOCALID_ECRUTEK_SILVER
	fadedefaultbgm

	setvar VAR_ECRUTEAK_CITY_THEATER, 5
	releaseall
	end

EcruteakCity_Movement_Silver1:
	delay_16
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

EcruteakCity_Movement_Silver2:
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

EcruteakCity_Text_Silver1:
	.string "TONF!!$"

EcruteakCity_Text_Silver2:
	.string "{RIVAL}: Come…? Come è\n"
	.string "possibile? Perdere contro delle\l"
	.string "RAGAZZE KIMONO…?$"

EcruteakCity_Text_Silver3:
	.string "{RIVAL}: Mi stavi guardando,\n"
	.string "{PLAYER}...\p"
	.string "Sì, proprio così!\p"
	.string "Non credevo che battere\n"
	.string "cinque RAGAZZE KIMONO\p"
	.string "fosse così duro: mi hanno\p"
	.string "conciato male.\p"
	.string "Sei qui per lo stesso\n"
	.string "motivo, vero?\p"
	.string "Non fare il gradasso per aver\n"
	.string "battuto TEAM ROCKET!\p"
	.string "Le RAGAZZE KIMONO sono\n"
	.string "forti.\p"
	.string "Prova a batterle.\p"
	.string "Ma non torno, non voglio\n"
	.string "vederti vincere.$"

EcruteakCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps1, MSGBOX_DEFAULT
	closemessage
	release
	end
		
EcruteakCity_EventScript_Lass::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Lass1, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RELEASED_BEASTS, EcruteakCity_EventScript_Girl2
	msgbox EcruteakCity_Text_Lass2, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Girl2::
	msgbox EcruteakCity_Text_Lass2_ReleasedBeasts, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScrip_Man::
	lock
	faceplayer
	goto_if_set FLAG_AMPHAROS_HEALED, EcruteakCity_EventScrip_Man2
	msgbox EcruteakCity_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScrip_Man2::
	msgbox EcruteakCity_Text_Fisher_JasmineReturned, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageRight::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps2, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageTower::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps3, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageGym::
	lock
	faceplayer
	msgbox EcruteakCity_Text_SageGym, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_TheaterSign::
	lock
	msgbox EcruteakCity_Text_DanceTheaterSign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_OfficeSign::
	lock
	msgbox EcruteakCity_Text_OfficeSign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_BurnedSign::
	lock
	msgbox EcruteakCity_Text_BurnedTowerSign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_CitySign::
	lock
	msgbox EcruteakCity_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_GymSign::
	lock
	msgbox EcruteakCity_Text_GymSign, MSGBOX_SIGN
	closemessage
	release
	end

EcruteakCity_EventScript_Eevee::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_EEVEE, CRY_MODE_NORMAL
	msgbox EcruteakCity_Text_Eevee, MSGBOX_DEFAULT
	waitmoncry
	release
	end

EcruteakCity_EventScript_Vulpix::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VULPIX, CRY_MODE_NORMAL
	msgbox EcruteakCity_Text_Vulpix, MSGBOX_DEFAULT
	waitmoncry
	release
	end

EcruteakCity_EventScript_Item_RareCandy::
	finditem ITEM_RARE_CANDY
	end

EcruteakCity_Text_Eevee:
	.string "EEVEE: Veee!$"

EcruteakCity_Text_Vulpix:
	.string "VULPIX: Vulll Pix!$"


EcruteakCity_Text_UnusedMissingDaughter:
	.string "Oddio, no…\p"
	.string "Mia figlia è sparita.\p"
	.string "No… Non può essere andata alla\n"
	.string "TORRE BRUCIATA.\p"
	.string "Le ho detto di non andarci…\p"
	.string "Sembra che la gente sparisca…\p"
	.string "Oh, che faccio…?$"

EcruteakCity_Text_Gramps1:
	.string "ECRUTEAK aveva due torri:\n"
	.string "una a est e una a ovest.$"

EcruteakCity_Text_Gramps2:
	.string "Ah, tesoro. Hai imparato a\n"
	.string "ballare come le RAGAZZE KIMONO?\p"
	.string "Se vai al loro TEATRO DI DANZA,\n"
	.string "un vecchietto strano ti darà\l"
	.string "una cosa carina, dicono.$"

EcruteakCity_Text_Lass1:
	.string "Vado a esercitarmi al TEATRO\n"
	.string "DI DANZA. Vieni con me?$"

EcruteakCity_Text_Lass2:
	.string "La torre che c'era qui…\p"
	.string "Mia nonna dice che era molto\n"
	.string "più alta.\p"
	.string "Dicono che ora ci siano fantasmi.$"

EcruteakCity_Text_Lass2_ReleasedBeasts:
	.string "Tre grossi POKéMON sono fuggiti in\n"
	.string "direzioni diverse. Chi erano?$"

EcruteakCity_Text_Fisher:
	.string "Ho sentito una voce su OLIVINE\n"
	.string "FARO.\p"
	.string "Il POKéMON che fa da\n"
	.string "faro si è ammalato. Sembra che\l"
	.string "siano nei guai.$"

EcruteakCity_Text_Fisher_JasmineReturned:
	.string "Il POKéMON del FARO DI OLIVINE\n"
	.string "è guarito.\p"
	.string "Le navi escono di nuovo in mare\n"
	.string "di notte.$"

EcruteakCity_Text_Youngster:
	.string "Al LAGO D'IRA i POKéMON\n"
	.string "si scatenano: vorrei vederli!$"

EcruteakCity_Text_Gramps3:
	.string "Tanto tempo fa…\p"
	.string "La torre bruciò. Tre POKéMON\n"
	.string "senza nome persero la vita.\p"
	.string "Un POKéMON arcobaleno discese\n"
	.string "dal cielo e li riportò in vita…\p"
	.string "È una leggenda tramandata\n"
	.string "dai CAPIPALESTRA di ECRUTEAK.\p"
	.string "Io?\p"
	.string "Allenavo, tanto tempo fa.\n"
	.string "Ahahah!$"

EcruteakCity_Text_SageGym:
	.string "Il Capopalestra MORTY non è qui\n"
	.string "adesso. Forse lo trovi alla\l"
	.string "TORRE BRUCIATA.$"

EcruteakCity_Text_Sign:
	.string "ECRUTEAK\n"
	.string "Città storica\p"
	.string "Il passato incontra il presente$"

EcruteakCity_Text_TinTowerSign:
	.string "TORRE CAMPANA\p"
	.string "Si dice che un POKéMON\n"
	.string "leggendario riposi qui.$"

EcruteakCity_Text_OfficeSign:
	.string "Barriera per la TORRE CAMPANA\p"
	.string "Vietato l'accesso agli indegni.$"

EcruteakCity_Text_GymSign:
	.string "PALESTRA POKéMON DI ECRUTEAK\n"
	.string "CAPO: MORTY\p"
	.string "Il Magico Veggente del Futuro$"

EcruteakCity_Text_DanceTheaterSign:
	.string "TEATRO DI DANZA ECRUTEAK$"

EcruteakCity_Text_BurnedTowerSign:
	.string "TORRE BRUCIATA\p"
	.string "Distrutta da un misterioso\n"
	.string "rogo.\p"
	.string "Non avvicinarti: è pericoloso.$"
