SaffronCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_OnTransition
	.byte 0

SaffronCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SAFFRON_CITY
	call_if_unset FLAG_RESCUED_MR_FUJI, SaffronCity_EventScript_MoveDoorGuardGrunt
	end

SaffronCity_EventScript_MoveDoorGuardGrunt::
	setobjectxyperm LOCALID_SAFFRON_DOOR_GUARD_GRUNT, 33, 31
	return

SaffronCity_EventScript_RocketGrunt1::
	msgbox SaffronCity_Text_WhatDoYouWantGetLost, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt2::
	msgbox SaffronCity_Text_BossTakeTownForTeamRocket, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt3::
	msgbox SaffronCity_Text_DontGetDefiantOrIllHurtYou, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt4::
	msgbox SaffronCity_Text_SaffronBelongsToTeamRocket, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt5::
	msgbox SaffronCity_Text_CriminalLifeMakesMeFeelAlive, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt6::
	msgbox SaffronCity_Text_WatchWhereYoureWalking, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt7::
	msgbox SaffronCity_Text_WeCanExploitMonsAroundWorld, MSGBOX_NPC
	end

SaffronCity_EventScript_DoorGuardGrunt::
	lock
	goto_if_set FLAG_RESCUED_MR_FUJI, SaffronCity_EventScript_DoorGuardAsleep
	applymovement LOCALID_SAFFRON_DOOR_GUARD_GRUNT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SaffronCity_Text_ImASecurityGuard
	release
	end

SaffronCity_EventScript_DoorGuardAsleep::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox SaffronCity_Text_HesTakingASnooze
	release
	end

SaffronCity_EventScript_WorkerM::
	msgbox SaffronCity_Text_YouBeatTeamRocket, MSGBOX_NPC
	end

SaffronCity_EventScript_Youngster::
	msgbox SaffronCity_Text_SafeToGoOutAgain, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass::
	msgbox SaffronCity_Text_PeopleComingBackToSaffron, MSGBOX_NPC
	end

SaffronCity_EventScript_Boy::
	msgbox SaffronCity_Text_FlewHereOnPidgeot, MSGBOX_NPC
	end

SaffronCity_EventScript_Pidgeot::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEOT, CRY_MODE_NORMAL
	msgbox SaffronCity_Text_Pidgeot
	waitmoncry
	release
	end

SaffronCity_EventScript_Man::
	msgbox SaffronCity_Text_SawRocketBossEscaping, MSGBOX_NPC
	end

SaffronCity_EventScript_CitySign::
	msgbox SaffronCity_Text_CitySign, MSGBOX_SIGN
	end

SaffronCity_EventScript_DojoSign::
	msgbox SaffronCity_Text_FightingDojo, MSGBOX_SIGN
	end

SaffronCity_EventScript_GymSign::
	lockall
	famechecker FAMECHECKER_SABRINA, 0
	msgbox SaffronCity_Text_GymSign
	releaseall
	end

SaffronCity_EventScript_TrainerTips1::
	msgbox SaffronCity_Text_FullHealCuresStatus, MSGBOX_SIGN
	end

SaffronCity_EventScript_TrainerTips2::
	msgbox SaffronCity_Text_GreatBallImprovedCatchRate, MSGBOX_SIGN
	end

SaffronCity_EventScript_SilphCoSign::
	msgbox SaffronCity_Text_SilphCoSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_MrPsychicsHouseSign::
	msgbox SaffronCity_Text_MrPsychicsHouse, MSGBOX_SIGN
	end

SaffronCity_EventScript_SilphProductSign::
	msgbox SaffronCity_Text_SilphsLatestProduct, MSGBOX_SIGN
	end

SaffronCity_EventScript_TrainerFanClubSign::
	msgbox SaffronCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

SaffronCity_Text_WhatDoYouWantGetLost::
	.string "Che vuoi?\n"
	.string "Vattene!$"

SaffronCity_Text_BossTakeTownForTeamRocket::
	.string "Il BOSS dice che prenderà la città\n"
	.string "in nome del TEAM ROCKET!$"

SaffronCity_Text_DontGetDefiantOrIllHurtYou::
	.string "Non fare l'agonista!\n"
	.string "O dovrò farti male!$"

SaffronCity_Text_SaffronBelongsToTeamRocket::
	.string "ZAFFERANOPOLI è del TEAM ROCKET!$"

SaffronCity_Text_CriminalLifeMakesMeFeelAlive::
	.string "La vita da criminale mi fa sentire\n"
	.string "così vivo!$"

SaffronCity_Text_WatchWhereYoureWalking::
	.string "Ahia!\n"
	.string "Guarda dove cammini!$"

SaffronCity_Text_WeCanExploitMonsAroundWorld::
	.string "Con la SILPH sotto controllo, possiamo\n"
	.string "sfruttare i POKéMON di tutto il mondo!\p"
	.string "Diventeremo ricchi sfondati, yeahah!$"

SaffronCity_Text_YouBeatTeamRocket::
	.string "Hai battuto il TEAM ROCKET da solo?\n"
	.string "Incredibile!$"

SaffronCity_Text_SafeToGoOutAgain::
	.string "Sì! Il TEAM ROCKET se n'è andato!\n"
	.string "Ora si può uscire di nuovo!$"

SaffronCity_Text_PeopleComingBackToSaffron::
	.string "La gente fuggì via in massa\n"
	.string "quando arrivarono quei ROCKET.\p"
	.string "Ora dovrebbero tornare in massa\n"
	.string "a ZAFFERANOPOLI.$"

SaffronCity_Text_FlewHereOnPidgeot::
	.string "Ho volato qui sul mio PIDGEOT\n"
	.string "quando ho letto della SILPH.\p"
	.string "È già finita?\n"
	.string "Mi sono perso i media…$"

SaffronCity_Text_Pidgeot::
	.string "PIDGEOT: Bii bibii!$"

SaffronCity_Text_SawRocketBossEscaping::
	.string "Ho visto il CAPO ROCKET fuggire\n"
	.string "dal palazzo della SILPH.$"

SaffronCity_Text_ImASecurityGuard::
	.string "Sono una guardia giurata.\p"
	.string "Non faccio entrare i ragazzini sospetti!$"

SaffronCity_Text_HesTakingASnooze::
	.string "…\n"
	.string "Zzz…\p"
	.string "Ah! Si sta facendo un pisolino!$"

SaffronCity_Text_CitySign::
	.string "AURORA CITY\n"
	.string "Splendida terra d'oro e commercio$"

SaffronCity_Text_FightingDojo::
	.string "DOJO LOTTA$"

SaffronCity_Text_GymSign::
	.string "PALESTRA POKéMON DI ZAFFERANOPOLI\n"
	.string "CAPO: SABRINA\l"
	.string "La maestra dei POKéMON PSICHICI!$"

SaffronCity_Text_FullHealCuresStatus::
	.string "CONSIGLI PER ALLENATORI\p"
	.string "IL CURA TUTTO cura tutti i problemi\n"
	.string "come scottature, paralisi,\l"
	.string "avvelenamento, glaciale e sonno.\p"
	.string "Costa un po' di più, ma è più\n"
	.string "comodo di altri oggetti.$"

SaffronCity_Text_GreatBallImprovedCatchRate::
	.string "CONSIGLI PER ALLENATORI\p"
	.string "La nuova MEGA BALL cattura\n"
	.string "i POKéMON più facilmente.\p"
	.string "Provala su quelli difficili\n"
	.string "da prendere.$"

SaffronCity_Text_SilphCoSign::
	.string "SEDE DELLA SILPH SPA$"

SaffronCity_Text_MrPsychicsHouse::
	.string "CASA DEL SIGNOR PSYCHIC$"

SaffronCity_Text_SilphsLatestProduct::
	.string "L'ultimo prodotto della SILPH!\n"
	.string "Uscita da definire…$"

SaffronCity_Text_TrainerFanClubSign::
	.string "FAN CLUB POKéMON\p"
	.string "Molti ALLENATORI hanno scarabocchiato\n"
	.string "il loro nome qui.$"

SaffronCity_Text_HowCanClubNotRecognizeLance::
	.string "Questo FAN CLUB…\n"
	.string "Nessuno qui ha idea di niente!\p"
	.string "Come fanno a non riconoscere\n"
	.string "il genio che è LANCE?\p"
	.string "È il simbolo della giustizia!\n"
	.string "È forte e appassionato!\l"
	.string "È il più grande, LANCE!$"

