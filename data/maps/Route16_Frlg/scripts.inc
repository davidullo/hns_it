Route16_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route16_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route16_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route16_OnWarp
	.byte 0

Route16_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route16_EventScript_RemoveSnorlax
	end

Route16_EventScript_RemoveSnorlax::
	removeobject VAR_LAST_TALKED
	return

Route16_OnTransition::
	call_if_eq VAR_MAP_SCENE_ROUTE16, 1, Route16_OnTransitionCyclingRoad
	end

Route16_OnTransitionCyclingRoad::
	setflag FLAG_SYS_ON_CYCLING_ROAD
	return

Route16_OnWarp::
	map_script_2 VAR_MAP_SCENE_ROUTE16, 1, Route16_OnWarpCyclingRoad
	.2byte 0

Route16_OnWarpCyclingRoad::
	special ForcePlayerOntoBike
	end

Route16_EventScript_Snorlax::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_POKE_FLUTE, Route16_EventScript_SnorlaxNoPokeFlute
	msgbox Text_WantToUsePokeFlute, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route16_EventScript_DontUsePokeFlute
	call EventScript_AwakenSnorlax
	setwildbattle SPECIES_SNORLAX, 30
	waitse
	playmoncry SPECIES_SNORLAX, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_HIDE_ROUTE_16_SNORLAX
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route16_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route16_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route16_EventScript_FoughtSnorlax
	release
	end

Route16_EventScript_DontUsePokeFlute::
	release
	end

Route16_EventScript_FoughtSnorlax::
	msgbox Text_SnorlaxReturnedToMountains
	release
	end

Route16_EventScript_SnorlaxNoPokeFlute::
	msgbox Route16_Text_MonSprawledOutInSlumber
	release
	end

Route16_EventScript_CyclingRoadSign::
	msgbox Route16_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route16_EventScript_RouteSign::
	msgbox Route16_Text_RouteSign, MSGBOX_SIGN
	end

Route16_Text_LaoIntro::
	.string "Cosa vuoi?$"

Route16_Text_LaoDefeat::
	.string "Non osare ridere!$"

Route16_Text_LaoPostBattle::
	.string "Ci piace stare qui.\n"
	.string "Sono affari tuoi?$"

Route16_Text_KojiIntro::
	.string "Bella BICICLETTA!\n"
	.string "Dammela!$"

Route16_Text_KojiDefeat::
	.string "KO!$"

Route16_Text_KojiPostBattle::
	.string "Che importa, chi vuole la tua BICICLETTA!$"

Route16_Text_LukeIntro::
	.string "Vieni fuori a giocare, topolino!$"

Route16_Text_LukeDefeat::
	.string "Topastro!$"

Route16_Text_LukePostBattle::
	.string "Odio perdere!\n"
	.string "Togliti di torno!$"

Route16_Text_HideoIntro::
	.string "Ehi, mi hai appena urtato!$"

Route16_Text_HideoDefeat::
	.string "Boom!$"

Route16_Text_HideoPostBattle::
	.string "Restiamo sempre qui in giro,\n"
	.string "che ti piaccia o no.\p"
	.string "Puoi passare da VERMILION\n"
	.string "seguendo la costa da FUCHSIA.$"

Route16_Text_CamronIntro::
	.string "Ho fame e sono nervoso!\n"
	.string "Mi serve un sacco da boxe!$"

Route16_Text_CamronDefeat::
	.string "Male, male, male!$"

Route16_Text_CamronPostBattle::
	.string "Se devo avere dei POKéMON,\n"
	.string "tanto vale che siano feroci.\p"
	.string "Li userei per ridurre\n"
	.string "i miei nemici a brandelli.$"

Route16_Text_RubenIntro::
	.string "Ehi, ciao!\n"
	.string "Divertiamoci un po'!$"

Route16_Text_RubenDefeat::
	.string "Non farmi arrabbiare!$"

Route16_Text_RubenPostBattle::
	.string "Mi diverto a importunare la gente\n"
	.string "con i miei POKéMON puzzolenti.\p"
	.string "Spaventano tutti che è un piacere.\n"
	.string "E mordono anche.$"

Route16_Text_MonSprawledOutInSlumber::
	.string "Un POKéMON è spaparanzato in\n"
	.string "un sonno profondo e beato.$"

Route16_Text_CyclingRoadSign::
	.string "Goditi la discesa!\n"
	.string "PISTA CICLABILE$"

Route16_Text_RouteSign::
	.string "PERCORSO 16\n"
	.string "CELESTOPOLI - FUCHSIA$"

Route16_Text_JedIntro::
	.string "JED: Il nostro amore è infinito.\n"
	.string "Ci amiamo e lo dimostriamo!$"

Route16_Text_JedDefeat::
	.string "JED: Oh, no!\n"
	.string "Il mio amore mi ha visto perdere!$"

Route16_Text_JedPostBattle::
	.string "JED: Senti, LEA.\n"
	.string "Dovresti pensare meno a me.$"

Route16_Text_JedNotEnoughMons::
	.string "JED: Hai un solo POKéMON?\n"
	.string "Non c'è amore nel tuo cuore?$"

Route16_Text_LeaIntro::
	.string "LEA: A volte l'intensità del\n"
	.string "nostro amore mi spaventa.$"

Route16_Text_LeaDefeat::
	.string "LEA: Ohh! Ma JED è forte\n"
	.string "anche quando perde!$"

Route16_Text_LeaPostBattle::
	.string "LEA: Ehehe, mi dispiace.\n"
	.string "JED è così forte.$"

Route16_Text_LeaNotEnoughMons::
	.string "LEA: Oh, non hai due\n"
	.string "POKéMON con te?\p"
	.string "Non ti senti solo, tu o\n"
	.string "i tuoi POKéMON?$"
