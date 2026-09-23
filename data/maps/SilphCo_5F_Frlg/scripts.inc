SilphCo_5F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_5F_OnLoad
	.byte 0

SilphCo_5F_OnLoad::
	call_if_unset FLAG_SILPH_5F_DOOR_1, EventScript_Close5FDoor1
	call_if_unset FLAG_SILPH_5F_DOOR_2, EventScript_Close5FDoor2
	call_if_unset FLAG_SILPH_5F_DOOR_3, EventScript_Close5FDoor3
	end

SilphCo_5F_EventScript_WorkerM::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_5F_EventScript_WorkerMRocketsGone
	msgbox SilphCo_5F_Text_RocketsInUproarAboutIntruder
	release
	end

SilphCo_5F_EventScript_WorkerMRocketsGone::
	msgbox SilphCo_5F_Text_YoureOurHeroThankYou
	release
	end

SilphCo_5F_EventScript_PokemonReport1::
	msgbox SilphCo_5F_Text_PorygonFirstVRMon, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_PokemonReport2::
	msgbox SilphCo_5F_Text_Over350TechniquesConfirmed, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_PokemonReport3::
	msgbox SilphCo_5F_Text_SomeMonsEvolveWhenTraded, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_FloorSign::
	msgbox SilphCo_5F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_Beau::
	trainerbattle_single TRAINER_SCIENTIST_BEAU, SilphCo_5F_Text_BeauIntro, SilphCo_5F_Text_BeauDefeat
	msgbox SilphCo_5F_Text_BeauPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_28, SilphCo_5F_Text_Grunt1Intro, SilphCo_5F_Text_Grunt1Defeat
	msgbox SilphCo_5F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_29, SilphCo_5F_Text_Grunt2Intro, SilphCo_5F_Text_Grunt2Defeat
	msgbox SilphCo_5F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_EventScript_Dalton::
	trainerbattle_single TRAINER_JUGGLER_DALTON, SilphCo_5F_Text_DaltonIntro, SilphCo_5F_Text_DaltonDefeat
	msgbox SilphCo_5F_Text_DaltonPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_Text_RocketsInUproarAboutIntruder::
	.string "Il TEAM ROCKET è in subbuglio per\n"
	.string "un intruso.\p"
	.string "Sei tu, vero?$"

SilphCo_5F_Text_YoureOurHeroThankYou::
	.string "Il TEAM ROCKET se n'è andato!\n"
	.string "Sei il nostro eroe! Grazie!$"

SilphCo_5F_Text_Grunt1Intro::
	.string "Ho sentito che un bambino\n"
	.string "si aggirava qui.$"

SilphCo_5F_Text_Grunt1Defeat::
	.string "Boom!$"

SilphCo_5F_Text_Grunt1PostBattle::
	.string "Non è furbo sfidare\n"
	.string "il TEAM ROCKET!$"

SilphCo_5F_Text_BeauIntro::
	.string "Su questo piano studiamo la\n"
	.string "tecnologia delle POKé BALL.$"

SilphCo_5F_Text_BeauDefeat::
	.string "Dannazione!\n"
	.string "Che colpo!$"

SilphCo_5F_Text_BeauPostBattle::
	.string "Lavoravamo alla POKé BALL\n"
	.string "definitiva, che cattura qualsiasi cosa.$"

SilphCo_5F_Text_DaltonIntro::
	.string "Cooosa?\p"
	.string "Qui non dovrebbero esserci\n"
	.string "bambini!$"

SilphCo_5F_Text_DaltonDefeat::
	.string "Oh, santo cielo!$"

SilphCo_5F_Text_DaltonPostBattle::
	.string "Sei solo al 5P.\n"
	.string "Il mio CAPO è ancora lontano!$"

SilphCo_5F_Text_Grunt2Intro::
	.string "Porta un po' di rispetto al TEAM ROCKET!$"

SilphCo_5F_Text_Grunt2Defeat::
	.string "Coff…\n"
	.string "Coff…$"

SilphCo_5F_Text_Grunt2PostBattle::
	.string "A proposito.\p"
	.string "KOFFING si evolve in WEEZING!$"

SilphCo_5F_Text_PorygonFirstVRMon::
	.string "È un REPORT POKéMON!\p"
	.string "Il LAB POKéMON ha creato PORYGON,\n"
	.string "il primo POKéMON virtuale.$"

SilphCo_5F_Text_Over350TechniquesConfirmed::
	.string "È un REPORT POKéMON!\p"
	.string "Sono state confermate oltre 350\n"
	.string "tecniche POKéMON.$"

SilphCo_5F_Text_SomeMonsEvolveWhenTraded::
	.string "È un REPORT POKéMON!\p"
	.string "Alcuni POKéMON si sono confermati\n"
	.string "in grado di evolversi con lo scambio.$"

SilphCo_5F_Text_FloorSign::
	.string "SEDE SILPH CO.\n"
	.string "5P$"

SilphCo_5F_Text_RocketBossLookingForStrongMons::
	.string "Quei teppisti che hanno occupato il\n"
	.string "nostro palazzo…\p"
	.string "Il loro CAPO cercava\n"
	.string "POKéMON forti.\p"
	.string "Spero che il PRESIDENTE sia\n"
	.string "riuscito a evitare guai…$"
