OlivineCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OlivineCity_OnFrame
	.byte 0

OlivineCity_MapScript_OnTransition::
	callnative SetTimeBasedEncounters
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, OlivineCity_MapScript_ClearWeather
	end

OlivineCity_MapScript_ClearWeather::
	setweather WEATHER_NONE
	end

OlivineCity_OnFrame::
	map_script_2 VAR_SAFARI_ZONE_GATE_STATE, 1, OlivineCity_EventScript_BaobaCall
	map_script_2 VAR_TRIGGER_ELM_ROCKET_CALL, 1, Mahoganytown_EventScript_RocketTrigger
	.2byte 0

OlivineCity_EventScript_BaobaCall::
	lock
	setspeaker OlivineCity_Text_BaobaName
	pokenavcall OlivineCity_Text_Baoba
	waitmessage
	delay 30
	setvar VAR_SAFARI_ZONE_GATE_STATE, 2
	release
	end

OlivineCity_Text_BaobaName:
	.string "BAOBA$"

OlivineCity_Text_Baoba:
	.string "{PLAYER}!\p"
	.string "Sono il GUARDIANO BAOBA.\p"
	.string "Scusa se ti ho fatto aspettare.\n"
	.string "Abbiamo finalmente aperto la\l"
	.string "ZONA SAFARI!\p"
	.string "Sai dov'è?\p"
	.string "Conosci il CANCELLO nella caverna\n"
	.string "di CIANWOOD?\p"
	.string "Se lo attraversi e cammini per\n"
	.string "un po', dovresti vedere subito\l"
	.string "la ZONA SAFARI!\p"
	.string "È un po' fuori mano, ma\n"
	.string "vieni a trovarci!$"

OlivineCity_EventScript_CityTrigger:: @FLAGHEAP
	setflag FLAG_HIDE_OLIVINE_CITY_GYM_JASMINE
	setflag FLAG_HIDE_OLIVINE_SILVER
	setflag FLAG_VISITED_OLIVINE_CITY
	clearflag FLAG_SAFARI_ZONE_WEST_EXPANSION
	clearflag FLAG_SAFARI_ZONE_EAST_EXPANSION
	clearflag FLAG_HIDE_BATTLEFRONTIER_ENGINEER
	clearflag FLAG_HIDE_LIGHTHOUSE_JASMINE
	clearflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	setvar VAR_GETFLY, 0
	
	setvar VAR_OLIVINE_CITY_STATE, 1

	@cianwood flags
	setvar VAR_SUICUNE_ENCOUNTERS, 1
	clearflag FLAG_HIDE_CIANWOOD_SUICUNE
	setflag FLAG_HIDE_CIANWOOD_EUSINE
	setvar VAR_CIANWOOD_CITY_STATE, 1
	end

OlivineCity_EventScript_SilverTrigger::
	lock
	clearflag FLAG_HIDE_OLIVINE_SILVER
	opendoor 11, 27
	addobject LOCALID_OLIVINE_SILVER
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	delay 20 
	closedoor 11, 27
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_1, 28, OlivineCity_EventScript_SilverWalkToPlayer1
	call_if_eq VAR_TEMP_1, 29, OlivineCity_EventScript_SilverWalkToPlayer2
	call_if_eq VAR_TEMP_1, 30, OlivineCity_EventScript_SilverWalkToPlayer3
	msgbox OlivineCity_Text_SilverEncounter, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_TEMP_1, 28, OlivineCity_EventScript_SilverLeaveAdjust1
	call_if_eq VAR_TEMP_1, 29, OlivineCity_EventScript_SilverLeaveAdjust2
	call_if_eq VAR_TEMP_1, 30, OlivineCity_EventScript_SilverLeaveAdjust2
	applymovement LOCALID_OLIVINE_SILVER, OlivineCity_Movement_SilverLeave
	waitmovement 0
	setvar VAR_OLIVINE_CITY_STATE, 2
	setflag FLAG_HIDE_OLIVINE_SILVER
	removeobject LOCALID_OLIVINE_SILVER
	fadedefaultbgm
	release
	end

OlivineCity_EventScript_SilverWalkToPlayer1::
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer1
	waitmovement 0
	return

OlivineCity_EventScript_SilverWalkToPlayer2::
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer2
	waitmovement 0
	return

OlivineCity_EventScript_SilverWalkToPlayer3::
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer3
	waitmovement 0
	return

OlivineCity_EventScript_SilverLeaveAdjust1::
	applymovement LOCALID_OLIVINE_SILVER Common_Movement_WalkDown1
	waitmovement 0
	return

OlivineCity_EventScript_SilverLeaveAdjust2::
	applymovement LOCALID_OLIVINE_SILVER Common_Movement_WalkUp1
	waitmovement 0
	return

OlivineCity_Movement_SilverWalkToPlayer1:
	walk_down
	walk_right
	walk_right
	walk_right
	step_end
OlivineCity_Movement_SilverWalkToPlayer2:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end
OlivineCity_Movement_SilverWalkToPlayer3:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end


OlivineCity_Movement_SilverLeave:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OlivineCity_Text_SilverEncounter:
	.string "Di nuovo tu?\n"
	.string "Non serve stare in guardia.\p"
	.string "Non perdo tempo con i deboli\n"
	.string "come te.\p"
	.string "A proposito di deboli, la\n"
	.string "CAPOPALESTRA della città non c'è,\l"
	.string "e pare che si occupi\l"
	.string "di un POKéMON malato al\l"
	.string "FARO.\p"
	.string "Umpf! Buu!\n"
	.string "Lascia perdere i POKéMON malati!\p"
	.string "Un POKéMON che non lotta\n"
	.string "è inutile!\p"
	.string "Perché non vai ad allenarti al\n"
	.string "FARO?\p"
	.string "Chissà? Magari diventi un\n"
	.string "Allenatore un po' migliore!$"

OlivineCity_EventScript_Sailor1::
	lock
	faceplayer
	msgbox OlivineCity_Text_Sailor1, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Sailor2::
	lock
	faceplayer
	msgbox OlivineCity_Text_Sailor2, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox OlivineCity_Text_YoungsterPokegear, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Machoke::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOKE, CRY_MODE_NORMAL
	msgbox OlivineCity_Text_Machoke, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OlivineCity_EventScript_Sign::
	lock
	msgbox OlivineCity_Text_Sign, MSGBOX_SIGN
	end

OlivineCity_EventScript_PortSign::
	lock
	msgbox OlivineCity_Text_PortSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_CafeSign::
	msgbox OlivineCity_Text_CafeSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_GymSign::
	lock
	msgbox OlivineCity_Text_GymSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_LighthouseSign::
	lock
	msgbox OlivineCity_Text_LighthouseSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_Item_ChargeBeam::
	finditem ITEM_TM_CHARGE_BEAM
	end

OlivineCity_EventScript_EonTicketWoman::
	lock
	faceplayer
	checkitem ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, TRUE, OlivineCity_EventScript_EonTicketWomanAfter
	goto_if_set FLAG_IS_KANTO_CHAMPION, OlivineCity_EventScript_EonTicketWomanChamp
	msgbox OlivineCity_Text_EonTicketWoman1, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_EonTicketWomanChamp::
	msgbox OlivineCity_Text_EonTicketWoman2, MSGBOX_DEFAULT
	giveitem ITEM_AURORA_TICKET
	closemessage
	release
	end

OlivineCity_EventScript_EonTicketWomanAfter::
	msgbox OlivineCity_Text_EonTicketWoman3, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_CafeSign:
	.string "OLIVINE CAFE\n"
	.string "DOVE I FORTI MARINAI GUSTANO\l"
	.string "PASTI ROBUSTI E FORTI$"

OlivineCity_Text_EonTicketWoman1:
	.string "Mi chiamo MARY!\p"
	.string "Scherzo, ma adoro il\n"
	.string "programma radio di MARY!$"

OlivineCity_Text_EonTicketWoman2:
	.string "Tu devi essere {PLAYER}!!!\p"
	.string "Oh, santo cielo! Il campione!\p"
	.string "Ho sentito parlare di te alla\n"
	.string "radio di MARY!\p"
	.string "Tieni, prendi questo!$"

OlivineCity_Text_EonTicketWoman3:
	.string "Non ci credo di aver incontrato il\n"
	.string "campione!!!$"

OlivineCity_Text_Sailor1:
	.string "Le strade buie sono pericolose\n"
	.string "di notte.\p"
	.string "Ma nel buio più fitto,\n"
	.string "il mare è ancora più\l"
	.string "infido!\p"
	.string "Senza il faro del\n"
	.string "FARO a guidarla,\l"
	.string "nessuna nave può salpare.$"

OlivineCity_Text_YoungsterPokegear:
	.string "Quella cosa che hai...\n"
	.string "è un POKéGEAR, vero?\l"
	.string "Wow, che forte.$"

OlivineCity_Text_YoungsterPokedex:
	.string "Wow, hai un POKéDEX!\p"
	.string "Che cosa fantastica.$"

OlivineCity_Text_Sailor2:
	.string "La lega considera JASMINE\n"
	.string "la sesta\l"
	.string "CAPOPALESTRA più forte!\p"
	.string "Ah! Che sciocchezza.\p"
	.string "PRYCE non potrebbe mai\n"
	.string "ferire i POKéMON di tipo\l"
	.string "ACCIAIO di JASMINE!\p"
	.string "Burocrazia, secondo me.\p"
	.string "È una da temere,\n"
	.string "questo è certo!$"

OlivineCity_Text_Sign:
	.string "OLIVINE\p"
	.string "Il porto più vicino alle terre lontane$"

OlivineCity_Text_PortSign:
	.string "PORTO DI OLIVINE\n"
	.string "MOLO DEL FAST SHIP$"

OlivineCity_Text_GymSign:
	.string "PALESTRA POKéMON DI OLIVINE\n"
	.string "CAPO: JASMINE\p"
	.string "La ragazza dalla difesa d'ACCIAIO$"

OlivineCity_Text_LighthouseSign:
	.string "FARO DI OLIVINE\n"
	.string "Detto anche il FARO\l"
	.string "SCINTILLANTE$"

OlivineCity_Text_BattleTowerSign:
	.string "COLLINA ALLENATORI e\n"
	.string "TENDE LOTTA AVANTI.\p"
	.string "Aperte ora!$"

OlivineCity_Text_Machoke:
	.string "MACHOKE: CHO!$"
