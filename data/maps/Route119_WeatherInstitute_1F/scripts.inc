Route119_WeatherInstitute_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_OnTransition
	.byte 0

Route119_WeatherInstitute_1F_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos
	end

Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos::
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, 0, 5
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_1F_EventScript_LittleBoy::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	goto_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere
	msgbox Route119_WeatherInstitute_1F_Text_WowYoureStrong, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere::
	msgbox Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker1::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_1F_EventScript_StudyingRain
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_1F_EventScript_StudyingRain  @ Both defeated
	msgbox Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_1F_EventScript_StudyingRain::
	msgbox Route119_WeatherInstitute_1F_Text_ProfStudyingRain, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2::
	msgbox Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo, MSGBOX_NPC
	end

Route119_WeatherInstitute_1F_EventScript_Bed::
	lockall
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

Route119_WeatherInstitute_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_1, Route119_WeatherInstitute_1F_Text_Grunt1Intro, Route119_WeatherInstitute_1F_Text_Grunt1Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_4, Route119_WeatherInstitute_1F_Text_Grunt4Intro, Route119_WeatherInstitute_1F_Text_Grunt4Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_Text_Grunt1Intro:
	.string "The BOSS got interested in\n"
	.string "the research they have going here,\l"
	.string "so he sent us out.\p"
	.string "You quit meddling!$"

Route119_WeatherInstitute_1F_Text_Grunt1Defeat:
	.string "Accidenti…\n"
	.string "Battuto da un ragazzino…$"

Route119_WeatherInstitute_1F_Text_Grunt1PostBattle:
	.string "Il nostro CAPO sa tutto.\p"
	.string "Ma io sono solo una RECLUTA. Come faccio\n"
	.string "a sapere cosa pensa?$"

Route119_WeatherInstitute_1F_Text_Grunt4Intro:
	.string "Eh?\n"
	.string "Che ci fa un ragazzino qui?$"

Route119_WeatherInstitute_1F_Text_Grunt4Defeat:
	.string "Eh?\n"
	.string "Ho perso?!$"

Route119_WeatherInstitute_1F_Text_Grunt4PostBattle:
	.string "Oh, no…\n"
	.string "Perderò contro una bambina…\p"
	.string "Meglio farsi un sonnellino nel letto…$"

Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs:
	.string "Mentre dormivo, sono andati\n"
	.string "tutti di sopra!$"

Route119_WeatherInstitute_1F_Text_WowYoureStrong:
	.string "Wow, sei davvero forte!\p"
	.string "Vorrei diventare un ALLENATORE\n"
	.string "di POKéMON come te!$"

Route119_WeatherInstitute_1F_Text_ProfStudyingRain:
	.string "Il PROFESSORE adora la pioggia.\n"
	.string "È un dato di fatto.\p"
	.string "Ma se continua a piovere, la gente avrà\n"
	.string "problemi. È un altro dato di fatto.\p"
	.string "E così il PROFESSORE studia\n"
	.string "come usare bene la pioggia.$"

Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather:
	.string "Al 2º piano dell'ISTITUTO\n"
	.string "studiamo le condizioni meteo\l"
	.string "della regione di HOENN.\p"
	.string "Ultimamente notiamo casi isolati e\n"
	.string "temporanei di siccità e\l"
	.string "forti piogge…$"

Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo:
	.string "Hello!\n"
	.string "We've been saved by your actions!\p"
	.string "What I don't understand is what on\n"
	.string "earth the AQUAS were up to.$"

Route119_WeatherInstitute_1F_Text_TakeRestInBed:
	.string "C'è un letto…\n"
	.string "Riposiamoci un po'.$"

