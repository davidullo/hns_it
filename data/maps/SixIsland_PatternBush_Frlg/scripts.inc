SixIsland_PatternBush_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SixIsland_PatternBush_OnTransition
	.byte 0

SixIsland_PatternBush_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SIX_ISLAND_PATTERN_BUSH
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	call_if_ge VAR_TEMP_1, 50, SixIsland_PatternBush_EventScript_SetEscapeRightExit
	call_if_le VAR_TEMP_1, 49, SixIsland_PatternBush_EventScript_SetEscapeLeftExit
	end

SixIsland_PatternBush_EventScript_SetEscapeRightExit::
	setescapewarp MAP_SIX_ISLAND_GREEN_PATH, 255, 64, 10
	return

SixIsland_PatternBush_EventScript_SetEscapeLeftExit::
	setescapewarp MAP_SIX_ISLAND_GREEN_PATH, 255, 45, 10
	return

SixIsland_PatternBush_EventScript_Bethany::
	trainerbattle_single TRAINER_PKMN_BREEDER_BETHANY, SixIsland_PatternBush_Text_BethanyIntro, SixIsland_PatternBush_Text_BethanyDefeat
	msgbox SixIsland_PatternBush_Text_BethanyPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Allison::
	trainerbattle_single TRAINER_PKMN_BREEDER_ALLISON, SixIsland_PatternBush_Text_AllisonIntro, SixIsland_PatternBush_Text_AllisonDefeat
	msgbox SixIsland_PatternBush_Text_AllisonPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Garret::
	trainerbattle_single TRAINER_BUG_CATCHER_GARRET, SixIsland_PatternBush_Text_GarretIntro, SixIsland_PatternBush_Text_GarretDefeat
	msgbox SixIsland_PatternBush_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Jonah::
	trainerbattle_single TRAINER_BUG_CATCHER_JONAH, SixIsland_PatternBush_Text_JonahIntro, SixIsland_PatternBush_Text_JonahDefeat
	msgbox SixIsland_PatternBush_Text_JonahPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Vance::
	trainerbattle_single TRAINER_BUG_CATCHER_VANCE, SixIsland_PatternBush_Text_VanceIntro, SixIsland_PatternBush_Text_VanceDefeat
	msgbox SixIsland_PatternBush_Text_VancePostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Nash::
	trainerbattle_single TRAINER_YOUNGSTER_NASH, SixIsland_PatternBush_Text_NashIntro, SixIsland_PatternBush_Text_NashDefeat
	msgbox SixIsland_PatternBush_Text_NashPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Cordell::
	trainerbattle_single TRAINER_YOUNGSTER_CORDELL, SixIsland_PatternBush_Text_CordellIntro, SixIsland_PatternBush_Text_CordellDefeat
	msgbox SixIsland_PatternBush_Text_CordellPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Dalia::
	trainerbattle_single TRAINER_LASS_DALIA, SixIsland_PatternBush_Text_DaliaIntro, SixIsland_PatternBush_Text_DaliaDefeat
	msgbox SixIsland_PatternBush_Text_DaliaPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Joana::
	trainerbattle_single TRAINER_LASS_JOANA, SixIsland_PatternBush_Text_JoanaIntro, SixIsland_PatternBush_Text_JoanaDefeat
	msgbox SixIsland_PatternBush_Text_JoanaPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Riley::
	trainerbattle_single TRAINER_CAMPER_RILEY, SixIsland_PatternBush_Text_RileyIntro, SixIsland_PatternBush_Text_RileyDefeat
	msgbox SixIsland_PatternBush_Text_RileyPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Marcy::
	trainerbattle_single TRAINER_PICNICKER_MARCY, SixIsland_PatternBush_Text_MarcyIntro, SixIsland_PatternBush_Text_MarcyDefeat
	msgbox SixIsland_PatternBush_Text_MarcyPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Layton::
	trainerbattle_single TRAINER_RUIN_MANIAC_LAYTON, SixIsland_PatternBush_Text_LaytonIntro, SixIsland_PatternBush_Text_LaytonDefeat
	msgbox SixIsland_PatternBush_Text_LaytonPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_Text_BethanyIntro::
	.string "Sono curiosa, come allevi i tuoi\n"
	.string "POKéMON?$"

SixIsland_PatternBush_Text_BethanyDefeat::
	.string "Allevi i tuoi POKéMON con\n"
	.string "tantissimo amore!$"

SixIsland_PatternBush_Text_BethanyPostBattle::
	.string "Come tua madre ha allevato\n"
	.string "te con amore, dovresti allevare\l"
	.string "i tuoi POKéMON.$"

SixIsland_PatternBush_Text_AllisonIntro::
	.string "Lavoro per preservare l'ecologia\n"
	.string "naturale dei POKéMON qui.$"

SixIsland_PatternBush_Text_AllisonDefeat::
	.string "Oh, per essere così giovane, sei\n"
	.string "formidabile!$"

SixIsland_PatternBush_Text_AllisonPostBattle::
	.string "Non dico che non dovresti\n"
	.string "catturare POKéMON.\p"
	.string "Voglio solo che la gente li allevi\n"
	.string "con responsabilità.$"

SixIsland_PatternBush_Text_GarretIntro::
	.string "Ho preso un POKéMON COLEOTTERO che vive\n"
	.string "solo da queste parti!$"

SixIsland_PatternBush_Text_GarretDefeat::
	.string "Eh eh…\n"
	.string "Il mio POKéMON non è fantastico?$"

SixIsland_PatternBush_Text_GarretPostBattle::
	.string "C'è una ragazza vicino al CESPO che\n"
	.string "misura gli HERACROSS per gli ALLENATORI.$"

SixIsland_PatternBush_Text_JonahIntro::
	.string "Sai, non mi sembra giusto\n"
	.string "se non uso POKéMON COLEOTTERO.$"

SixIsland_PatternBush_Text_JonahDefeat::
	.string "Va bene, perdere è anche un bel\n"
	.string "lato dei POKéMON.$"

SixIsland_PatternBush_Text_JonahPostBattle::
	.string "A proposito, “lato” è una parola\n"
	.string "strana, se ci pensi.\p"
	.string "Tipo, è come una buccia d'arancia?\n"
	.string "O come un sonaglio che suona?$"

SixIsland_PatternBush_Text_VanceIntro::
	.string "Sì, sì, sì!\n"
	.string "Guarda quanti POKéMON COLEOTTERO!$"

SixIsland_PatternBush_Text_VanceDefeat::
	.string "Mi hai battuto mentre ero ancora\n"
	.string "a festeggiare!$"

SixIsland_PatternBush_Text_VancePostBattle::
	.string "La prossima volta porto qui\n"
	.string "mio fratellino.$"

SixIsland_PatternBush_Text_NashIntro::
	.string "Guarda, guarda! Ci sono dei disegni\n"
	.string "buffi per terra.$"

SixIsland_PatternBush_Text_NashDefeat::
	.string "Troppo forte!$"

SixIsland_PatternBush_Text_NashPostBattle::
	.string "I disegni buffi per terra…\p"
	.string "Sembrano i disegni sui vestiti\n"
	.string "di mio nonno.$"

SixIsland_PatternBush_Text_CordellIntro::
	.string "Scommetto che mi credi uno\n"
	.string "qualunque, vero, eh?$"

SixIsland_PatternBush_Text_CordellDefeat::
	.string "Scommetto che mi credi debole,\n"
	.string "vero, eh?$"

SixIsland_PatternBush_Text_CordellPostBattle::
	.string "Già, voi cittadini arrivate tutti\n"
	.string "eleganti con un cappello così…\p"
	.string "Perché non me lo dai?$"

SixIsland_PatternBush_Text_DaliaIntro::
	.string "Fai un respiro profondo.\n"
	.string "Non è deliziosa l'aria?$"

SixIsland_PatternBush_Text_DaliaDefeat::
	.string "Se vuoi, ti insegno a\n"
	.string "respirare bene.$"

SixIsland_PatternBush_Text_DaliaPostBattle::
	.string "Prima, espira.\n"
	.string "Butta fuori tutto.\p"
	.string "Quando non puoi più espirare,\n"
	.string "inspira l'aria pulita!\p"
	.string "Non è rinfrescante?$"

SixIsland_PatternBush_Text_JoanaIntro::
	.string "Adoro i POKéMON COLEOTTERO.\n"
	.string "Per questo sto qui tutto il tempo.\p"
	.string "Sono l'unica ragazza così?$"

SixIsland_PatternBush_Text_JoanaDefeat::
	.string "Ho perso, ma sto ancora ridendo.\n"
	.string "Sono l'unica ragazza così?$"

SixIsland_PatternBush_Text_JoanaPostBattle::
	.string "Continuerò a collezionare\n"
	.string "POKéMON COLEOTTERO.\p"
	.string "Sono l'unica ragazza così?$"

SixIsland_PatternBush_Text_RileyIntro::
	.string "Bel posticino.\n"
	.string "Pianto qui la tenda.$"

SixIsland_PatternBush_Text_RileyDefeat::
	.string "Mi sono arreso…$"

SixIsland_PatternBush_Text_RileyPostBattle::
	.string "Osserverò il cielo notturno\n"
	.string "qui.$"

SixIsland_PatternBush_Text_MarcyIntro::
	.string "Che schifo!\n"
	.string "Credo che un insetto mi abbia punto!$"

SixIsland_PatternBush_Text_MarcyDefeat::
	.string "Non era un insetto.\n"
	.string "Mi sono tagliata lo stinco sull'erba.$"

SixIsland_PatternBush_Text_MarcyPostBattle::
	.string "Un taglietto così…\n"
	.string "Basta un po' di saliva e passa!$"

SixIsland_PatternBush_Text_LaytonIntro::
	.string "Hai notato qualcosa di strano\n"
	.string "da queste parti?$"

SixIsland_PatternBush_Text_LaytonDefeat::
	.string "Hai dato una bella occhiata\n"
	.string "sotto i piedi?$"

SixIsland_PatternBush_Text_LaytonPostBattle::
	.string "Qui a BOSCO DISEGNATO ci sono punti\n"
	.string "dove l'erba non cresce.\p"
	.string "Cosa può causare un simile\n"
	.string "fenomeno?$"

