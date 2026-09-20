VictoryRoad_3F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VictoryRoad_3F_OnLoad
	.byte 0

VictoryRoad_3F_OnLoad::
	call_if_ne VAR_MAP_SCENE_VICTORY_ROAD_3F, 100, VictoryRoad_3F_EventScript_SetRockBarrier
	end

VictoryRoad_3F_EventScript_SetRockBarrier::
	setmetatile 12, 12, METATILE_Cave_RockBarrier_Top, 1
	setmetatile 12, 13, METATILE_Cave_RockBarrier_Bottom, 1
	return

VictoryRoad_3F_EventScript_FloorSwitch::
	lockall
	goto_if_eq VAR_MAP_SCENE_VICTORY_ROAD_3F, 100, VictoryRoad_3F_EventScript_FloorSwitchAlreadyPressed
	setmetatile 12, 12, METATILE_Cave_Floor_Ledge_Top, 0
	setmetatile 12, 13, METATILE_Cave_Floor_Ledge_Bottom, 0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	copyobjectxytoperm LOCALID_VICTORY_ROAD_3F_BOULDER1
	copyobjectxytoperm LOCALID_VICTORY_ROAD_3F_BOULDER2
	setvar VAR_MAP_SCENE_VICTORY_ROAD_3F, 100
	releaseall
	end

VictoryRoad_3F_EventScript_FloorSwitchAlreadyPressed::
	releaseall
	end

VictoryRoad_3F_EventScript_George::
	trainerbattle_single TRAINER_COOLTRAINER_GEORGE, VictoryRoad_3F_Text_GeorgeIntro, VictoryRoad_3F_Text_GeorgeDefeat
	msgbox VictoryRoad_3F_Text_GeorgePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Colby::
	trainerbattle_single TRAINER_COOLTRAINER_COLBY, VictoryRoad_3F_Text_ColbyIntro, VictoryRoad_3F_Text_ColbyDefeat
	msgbox VictoryRoad_3F_Text_ColbyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Caroline::
	trainerbattle_single TRAINER_COOLTRAINER_CAROLINE, VictoryRoad_3F_Text_CarolineIntro, VictoryRoad_3F_Text_CarolineDefeat
	msgbox VictoryRoad_3F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Alexa::
	trainerbattle_single TRAINER_COOLTRAINER_ALEXA, VictoryRoad_3F_Text_AlexaIntro, VictoryRoad_3F_Text_AlexaDefeat
	msgbox VictoryRoad_3F_Text_AlexaPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Ray::
	trainerbattle_double TRAINER_COOL_COUPLE_RAY_TYRA, VictoryRoad_3F_Text_RayIntro, VictoryRoad_3F_Text_RayDefeat, VictoryRoad_3F_Text_RayNotEnoughMons
	msgbox VictoryRoad_3F_Text_RayPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Tyra::
	trainerbattle_double TRAINER_COOL_COUPLE_RAY_TYRA, VictoryRoad_3F_Text_TyraIntro, VictoryRoad_3F_Text_TyraDefeat, VictoryRoad_3F_Text_TyraNotEnoughMons
	msgbox VictoryRoad_3F_Text_TyraPostBattle, MSGBOX_AUTOCLOSE
	end

Text_DoubleEdgeTeach::
	.string "Devi essere fiero di te,\n"
	.string "hai attraversato\l"
	.string "la VICTORY ROAD con coraggio.\p"
	.string "In riconoscenza dell'impresa,\n"
	.string "t'insegnerò DOUBLE-EDGE.\p"
	.string "Vuoi che t'insegni quella\n"
	.string "tecnica?$"

Text_DoubleEdgeDeclined::
	.string "T'Insegnerò la tecnica\n"
	.string "quando vuoi.$"

Text_DoubleEdgeWhichMon::
	.string "A quale POKéMON insegno\n"
	.string "DOUBLE-EDGE?$"

Text_DoubleEdgeTaught::
	.string "Mantieni questa carica per la\n"
	.string "POKéMON LEAGUE!\p"
	.string "Scagliati contro di loro e\n"
	.string "buttali giù!$"

VictoryRoad_3F_Text_GeorgeIntro::
	.string "Ho sentito voci su un bimbo prodigio.$"

VictoryRoad_3F_Text_GeorgeDefeat::
	.string "Le voci erano vere!$"

VictoryRoad_3F_Text_GeorgePostBattle::
	.string "Quindi sei tu che hai battuto GIOVANNI\n"
	.string "del TEAM ROCKET?$"

VictoryRoad_3F_Text_AlexaIntro::
	.string "Gli ALLENATORI vivono per cercare\n"
	.string "avversari più forti.$"

VictoryRoad_3F_Text_AlexaDefeat::
	.string "Oh!\n"
	.string "Che forza!$"

VictoryRoad_3F_Text_AlexaPostBattle::
	.string "Affrontando lotte dure, si diventa\n"
	.string "più forti.$"

VictoryRoad_3F_Text_CarolineIntro::
	.string "Ti mostrerò quanto sei bravo.\n"
	.string "Ma no!$"

VictoryRoad_3F_Text_CarolineDefeat::
	.string "Sono furiosa!$"

VictoryRoad_3F_Text_CarolinePostBattle::
	.string "Mi hai mostrato quanto ero\n"
	.string "brava…$"

VictoryRoad_3F_Text_ColbyIntro::
	.string "Qui passa solo chi è prescelto!$"

VictoryRoad_3F_Text_ColbyDefeat::
	.string "Non ci credo!$"

VictoryRoad_3F_Text_ColbyPostBattle::
	.string "Tutti gli ALLENATORI qui vanno\n"
	.string "alla POKéMON LEAGUE.\p"
	.string "Non abbassare la guardia.$"

VictoryRoad_3F_Text_RayIntro::
	.string "RAY: Insieme saremo\n"
	.string "destinati alla gloria!$"

VictoryRoad_3F_Text_RayDefeat::
	.string "RAY: Assurdo!\n"
	.string "Non può essere!$"

VictoryRoad_3F_Text_RayPostBattle::
	.string "RAY: Ci hai battuti.\n"
	.string "La gloria resta lontana…$"

VictoryRoad_3F_Text_RayNotEnoughMons::
	.string "RAY: Insieme miriamo\n"
	.string "alla vetta.\p"
	.string "Ci servono due POKéMON\n"
	.string "per lottare con noi.$"

VictoryRoad_3F_Text_TyraIntro::
	.string "TYRA: Vogliamo diventare\n"
	.string "campioni insieme.$"

VictoryRoad_3F_Text_TyraDefeat::
	.string "TYRA: Oh, ma…$"

VictoryRoad_3F_Text_TyraPostBattle::
	.string "TYRA: Mi hai insegnato che la forza\n"
	.string "può avere infinite forme.$"

VictoryRoad_3F_Text_TyraNotEnoughMons::
	.string "TYRA: Non puoi lottare con noi\n"
	.string "se hai un solo POKéMON.$"

