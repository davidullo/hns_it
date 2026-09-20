EcruteakCity_SageOffice1_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_SageOffice1_OnTransition
	.byte 0

EcruteakCity_SageOffice1_OnTransition::
	goto_if_set FLAG_HIDE_TINTOWER_GUARD, EcruteakCity_SageOffice1_EventScript_SageAside
	end

EcruteakCity_SageOffice1_EventScript_SageAside::
	setobjectxyperm LOCALID_SAGEOFFICE_SAGE, 15, 2
	end

EcruteakCity_SageOffice1_EventScript_Sign::
	msgbox EcruteakCity_SageOffice1_Text_Sign, MSGBOX_SIGN
	end

EcruteakCity_SageOffice1_Text_Sign:
	.string "Il sonaglio di stagno risuona per\n"
	.string "chi sta sotto l'ala della torre.$"

EcruteakCity_SageOffice2_EventScript_SageA::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_TINTOWER_GUARD, EcruteakCity_SageOffice2_EventScript_SageA4
	checkitem ITEM_CLEAR_BELL
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_SageOffice2_EventScript_SageA2
	msgbox EcruteakTinTowerEntrance_Text_SageNoBadge, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA2::
	msgbox EcruteakTinTowerEntrance_Text_SageHearsClearBell1, MSGBOX_DEFAULT
	waitmessage
	playse SE_M_PETAL_DANCE
	waitse
	playse SE_PIN
	applymovement LOCALID_SAGEOFFICE_SAGE, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SAGEOFFICE_SAGE
	msgbox EcruteakTinTowerEntrance_Text_SageHearsClearBell2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SAGEOFFICE_SAGE, EcruteakCity_SageOffice2_Movement_StandAside
	waitmovement 0
	setobjectxyperm LOCALID_SAGEOFFICE_SAGE, 15, 2
	setflag FLAG_HIDE_TINTOWER_GUARD
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA3::
	msgbox EcruteakTinTowerEntrance_Text_SagePleaseDoGoOn, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA4::
	msgbox EcruteakTinTowerEntrance_Text_SageDone, MSGBOX_DEFAULT
	closemessage
	release
	end
	
EcruteakCity_SageOffice2_EventScript_SageB::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 10, EcruteakCity_SageOffice2_EventScript_B2
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, EcruteakCity_SageOffice2_EventScript_B2
	msgbox EcruteakTinTowerEntrance_Text_WanderingSage, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_B2::
	msgbox EcruteakTinTowerEntrance_Text_WanderingSageClearBell, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageC::
	lock
	faceplayer
	msgbox EcruteakTinTowerEntrance_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_Movement_StandAside:
	walk_left
	face_down
	step_end

EcruteakTinTowerEntrance_Text_SageNoBadge:
	.string "La TORRE CAMPANA è vietata ai\n"
	.string "non degni. Scusa, ma devi\l"
	.string "andartene.$"

EcruteakTinTowerEntrance_Text_SageWithBadge:
	.string "La TORRE CAMPANA è vietata a chi\n"
	.string "non ha la MEDAGLIA ECRUTEAK.\p"
	.string "Ah!\p"
	.string "La MEDAGLIA di ECRUTEAK! Prego,\n"
	.string "accomodati.$"

EcruteakTinTowerEntrance_Text_SageNoClearBell:
	.string "È accaduto un evento solenne.\p"
	.string "Chiedo scusa, ma devo chiederti\n"
	.string "di uscire.\p"
	.string "…Ciò che calma l'anima…\p"
	.string "Il WISE TRIO dice cose davvero\n"
	.string "difficili da capire…$"

EcruteakTinTowerEntrance_Text_SageHearsClearBell1:
	.string "È accaduto un evento solenne.\p"
	.string "Chiedo scusa, ma devo pregarti\n"
	.string "di andartene.\p"
	.string "..............................$"
EcruteakTinTowerEntrance_Text_SageHearsClearBell2:
	.string "Ah!\p"
	.string "Il suono del SONAGLIO CHIARO!\p"
	.string "È… È sublime!\p"
	.string "Non ho mai sentito un suono\n"
	.string "così bello!\p"
	.string "Il suono di quel sonaglio indica\n"
	.string "l'anima di chi lo porta.\p"
	.string "Tu…\p"
	.string "Forse riuscirai ad attraversare\n"
	.string "la TORRE CAMPANA.\p"
	.string "Prego, prosegui.$"

EcruteakTinTowerEntrance_Text_SagePleaseDoGoOn:
	.string "Prego, continua.$"

EcruteakTinTowerEntrance_Text_SageDone:
	.string "Il suono di quel sonaglio indica\n"
	.string "l'anima di chi lo porta.\p"
	.string "Tu…\n"
	.string "Lo meriti davvero.$"

EcruteakTinTowerEntrance_Text_WanderingSage:
	.string "La TORRE CAMPANA davanti è una\n"
	.string "torre divina a nove piani.\p"
	.string "Placa l'anima di chiunque la\n"
	.string "veda.$"

EcruteakTinTowerEntrance_Text_WanderingSageClearBell:
	.string "La TORRE CAMPANA ha tremato!\n"
	.string "Un POKéMON è tornato su!$"

EcruteakTinTowerEntrance_Text_Gramps:
	.string "Due torri… Due POKéMON…\p"
	.string "Ma quando una bruciò, i due\n"
	.string "POKéMON volarono via per non tornare.$"
