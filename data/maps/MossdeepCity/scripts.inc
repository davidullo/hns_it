MossdeepCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
	.byte 0

MossdeepCity_OnTransition:
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

MossdeepCity_EventScript_PokefanF::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_PokefanFMagmaGone
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_PokefanFMagmaGone::
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_SailorMagmaGone
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_SailorMagmaGone::
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_NinjaBoy::
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
	end

MossdeepCity_EventScript_ExpertM::
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
	end

MossdeepCity_EventScript_Girl::
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
	end

MossdeepCity_EventScript_Woman::
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
	end

MossdeepCity_EventScript_WhiteRock::
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
	end

MossdeepCity_EventScript_GymSign::
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_CitySign::
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_SpaceCenterSign::
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_VisitedMossdeep::
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_TEMP_1, 1
	end

MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter::
	lockall
	applymovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
	waitmovement 0
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
	waitmovement 0
	applymovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
	waitmovement 0
	removeobject LOCALID_MOSSDEEP_MAXIE
	removeobject LOCALID_MOSSDEEP_GRUNT_1
	removeobject LOCALID_MOSSDEEP_GRUNT_2
	removeobject LOCALID_MOSSDEEP_GRUNT_3
	removeobject LOCALID_MOSSDEEP_GRUNT_4
	delay 30
	setvar VAR_MOSSDEEP_CITY_STATE, 2
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	releaseall
	end

MossdeepCity_Movement_MaxieGestureToSpaceCenter:
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_GruntFaceSpaceCenter:
	face_right
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_MaxieEnterSpaceCenter:
	walk_down
	walk_right
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
	step_end

MossdeepCity_Movement_Grunt1EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
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
	step_end

MossdeepCity_Movement_Grunt2EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_right
	walk_right
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
	step_end

MossdeepCity_Movement_Grunt3EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_right
	walk_right
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
	step_end

MossdeepCity_Movement_Grunt4EnterSpaceCenter:
	delay_16
	delay_8
	walk_right
	walk_right
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
	step_end

MossdeepCity_EventScript_Man::
	lock
	faceplayer
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_EventScript_KingsRockBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_EventScript_DeclineKingsRock
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
	giveitem ITEM_KINGS_ROCK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_KINGS_ROCK
	release
	end

MossdeepCity_EventScript_ReceivedKingsRock::
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DeclineKingsRock::
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_BlackBelt::
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
	end

MossdeepCity_EventScript_Scott::
	lock
	faceplayer
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MossdeepCity_EventScript_ScottExitEast
	addvar VAR_SCOTT_STATE, 1
	removeobject LOCALID_MOSSDEEP_SCOTT
	release
	end

MossdeepCity_EventScript_ScottExitNorth::
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitNorth
	waitmovement 0
	return

MossdeepCity_EventScript_ScottExitEast::
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitEast
	waitmovement 0
	return

MossdeepCity_Movement_PlayerWatchScottExit:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MossdeepCity_Movement_ScottExitNorth:
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

MossdeepCity_Movement_ScottExitEast:
	walk_down
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

MossdeepCity_Text_WantKingsRockStevenGaveMe:
	.string "Me l'ha dato STEVEN, ma non so\n"
	.string "a cosa serva.\p"
	.string "Credo si chiami ROCCIA DEL RE.\n"
	.string "La vuoi?$"

MossdeepCity_Text_YouCanKeepIt:
	.string "Perché la vorresti?\n"
	.string "Sei strano.\p"
	.string "Puoi tenerla, ma non dirlo\n"
	.string "a STEVEN.$"

MossdeepCity_Text_StevensHouseOverThere:
	.string "La casa di STEVEN è proprio là!$"

MossdeepCity_Text_WhatToDoWithWeirdRock:
	.string "Sì, lo pensi anche tu! Che cosa\n"
	.string "dovresti fare con una roccia strana?$"

MossdeepCity_Text_WailmerWatching:
	.string "Intorno a MOSSDEEP si possono vedere\n"
	.string "WAILMER selvatici.\p"
	.string "Si chiama, ehm…\n"
	.string "Come era…\p"
	.string "WAI, WAI, WAI…\p"
	.string "WAILMER watching!$"

MossdeepCity_Text_SpaceCenterReceivedLetter:
	.string "Il CENTRO SPAZIALE dell'isola sta\n"
	.string "lanciando enormi razzi.\p"
	.string "C'è stato un gran trambusto\n"
	.string "per una lettera che hanno ricevuto.$"

MossdeepCity_Text_SpaceCenterLaunchingRockets:
	.string "Il CENTRO SPAZIALE dell'isola sta\n"
	.string "lanciando enormi razzi.$"

MossdeepCity_Text_MossdeepTargetedByMagma:
	.string "Un amico MARINAIO mi ha detto che\n"
	.string "il TEAM AQUA si è stabilito a PORTOALGHE.\p"
	.string "Ho anche sentito che qualcuno è arrivato\n"
	.string "e li ha sistemati per bene!\p"
	.string "Ma MOSSDEEP è stata presa di mira\n"
	.string "da quel TEAM MAGMA.\p"
	.string "Se vuoi sapere cosa tramano,\n"
	.string "vai al CENTRO SPAZIALE.$"

MossdeepCity_Text_FeelReliefOnLand:
	.string "Sono un MARINAIO, quindi il mare\n"
	.string "per me è ovviamente più importante.\p"
	.string "Ma sai? Quando torno a terra\n"
	.string "dopo un lungo viaggio, che sollievo!$"

MossdeepCity_Text_NiceIfWorldCoveredByFlowers:
	.string "Non sarebbe bello?\p"
	.string "Se il mondo intero fosse coperto di\n"
	.string "piante e fiori come questa isola?$"

MossdeepCity_Text_LifeNeedsSeaToLive:
	.string "La vita ha bisogno del mare, anche\n"
	.string "se vive sulla terraferma.\p"
	.string "La vita, finito il suo corso, diventa\n"
	.string "terra e ritorna al suolo.\p"
	.string "E il mare è sempre legato alla\n"
	.string "terraferma.\p"
	.string "Sì, come questa riva.$"

MossdeepCity_Text_SurfExhilarating:
	.string "Un viaggio in nave va bene.\p"
	.string "Ma attraversare il mare con i POKéMON\n"
	.string "usando SURF…\p"
	.string "Quello sì che è un viaggio emozionante!\n"
	.string "Non sei d'accordo, ragazzo?$"

MossdeepCity_Text_SpecialSpaceCenterRock:
	.string "Questa roccia ha un significato speciale\n"
	.string "per la gente del CENTRO SPAZIALE.\p"
	.string "L'hanno messa qui come augurio\n"
	.string "che i razzi volino in sicurezza.\p"
	.string "Quando esprimi un desiderio, cosa usi?\n"
	.string "Desideri guardando una stella?\p"
	.string "Io uso un tag portafortuna.\n"
	.string "Ecco cosa faccio.$"

MossdeepCity_Text_ItsAWhiteRock:
	.string "È una roccia bianca.$"

MossdeepCity_Text_GymSign:
	.string "PALESTRA POKéMON DI VERDEAZZUPOLI\n"
	.string "CAPIPALESTRA: LIZA & TATE\p"
	.string "“La combinazione magica!”$"

MossdeepCity_Text_CitySign:
	.string "VERDEAZZUPOLI\n"
	.string "“Il nostro motto: Ama i POKéMON!”$"

MossdeepCity_Text_SpaceCenterSign:
	.string "CENTRO SPAZIALE di MOSSDEEP\n"
	.string "“Il luogo più vicino allo spazio.”$"

MossdeepCity_Text_ScottSomethingWrongWithTown:
	.string "SCOTT: {PLAYER}{KUN}, tutto bene?\n"
	.string "Io sto alla grande!\p"
	.string "Ho sentito che il CAPOPALESTRA di\n"
	.string "MOSSDEEP è forte, così ho deciso\l"
	.string "di venire a dare un'occhiata.\p"
	.string "Ma c'è qualcosa che non va\n"
	.string "in questa città.\p"
	.string "La gente parla di una lettera\n"
	.string "di avvertimento e del CENTRO SPAZIALE…\p"
	.string "Non credo che mi riguardi,\n"
	.string "però.$"

MossdeepCity_Text_SootopolisNewGymLeader:
	.string "Ahh… Che bello lasciare che le onde\n"
	.string "mi lavino i piedi…\p"
	.string "A proposito di onde, la conosci quella\n"
	.string "città sull'isola, SOOTOPOLIS?\p"
	.string "Credo che nella sua PALESTRA sia\n"
	.string "arrivato un nuovo CAPO.\p"
	.string "Dicono che il nuovo CAPO una volta\n"
	.string "sia stato il mentore di WALLACE.$"

