SafariZone_EventScript_OutOfBallsMidBattle::
#if IS_FRLG
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 3
#elif IS_HNS
	setvar VAR_SAFARI_ZONE_STATE, 1
#else
	setvar VAR_SAFARI_ZONE_STATE, 1
#endif
	special ExitSafariMode
#if IS_FRLG
	setwarp MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 4, 1
#elif IS_HNS
	goto_if_set FLAG_IN_KANTO_SAFARI_ZONE, SafariZone_EventScript_ExitKantoMidBattle
	setwarp MAP_SAFARI_ZONE_GATE_SAFARI_ZONE_ENTRANCE_HNS, 9, 3
#else
	setwarp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
#endif
	end

SafariZone_EventScript_ExitKantoMidBattle::
	clearflag FLAG_IN_KANTO_SAFARI_ZONE
	setwarp MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE_HNS, 5, 6
	end

SafariZone_EventScript_Exit::
#if IS_FRLG
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 1
#elif IS_HNS
	setvar VAR_SAFARI_ZONE_STATE, 1
#else
	setvar VAR_SAFARI_ZONE_STATE, 1
#endif
	special ExitSafariMode
#if IS_FRLG
	warp MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 4, 1
#elif IS_HNS
	goto_if_set FLAG_IN_KANTO_SAFARI_ZONE, SafariZone_EventScript_ExitKanto
	warp MAP_SAFARI_ZONE_GATE_SAFARI_ZONE_ENTRANCE_HNS, 9, 3
#else
	warp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
#endif
	waitstate
	end

SafariZone_EventScript_ExitKanto::
	clearflag FLAG_IN_KANTO_SAFARI_ZONE
	warp MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE_HNS, 5, 6
	waitstate
	end

SafariZone_EventScript_RetirePrompt::
	lockall
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_Retire
	releaseall
	end

SafariZone_EventScript_Retire::
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_TimesUp
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_OutOfBalls::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_OutOfBalls
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

EventScript_PokeBlockFeeder::
	lockall
	special GetPokeblockFeederInFront
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPresent
	msgbox SafariZone_Text_PlacePokeblockOnFeeder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_ChoosePokeblock
	releaseall
	end

SafariZone_EventScript_ChoosePokeblock::
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseOnFeeder
	waitstate
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPlaced
#ifdef BUGFIX
	releaseall  @ Only gets called from EventScript_PokeBlockFeeder which uses lockall.
#endif
	end

SafariZone_EventScript_PokeblockPlaced::
	message SafariZone_Text_PokeblockWasPlaced
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_EventScript_PokeblockPresent::
	message SafariZone_Text_PokeblockStillHere
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_EventScript_PokeblockGone::
	lockall
	message SafariZone_Text_PokeblockGone
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_Text_PokeblockGone:
	.string "Il {STR_VAR_1} è stato\n"
	.string "mangiato tutto!$"

SafariZone_Text_WouldYouLikeToExit:
	.string "Vuoi uscire dalla ZONA\n"
	.string "SAFARI adesso?$"

SafariZone_Text_TimesUp:
	.string "Ding-dong! Tempo scaduto!\n"
	.string "La tua Gara SAFARI è finita.$"

SafariZone_Text_OutOfBalls:
	.string "Hai esaurito le SAFARI BALL.\n"
	.string "La tua Gara Safari è finita.$"

SafariZone_Text_PlacePokeblockOnFeeder:
	.string "Vuoi mettere un {POKEBLOCK}\n"
	.string "sul {POKEBLOCK} FEEDER?$"

SafariZone_Text_PokeblockStillHere:
	.string "Il {STR_VAR_1} che avevi\n"
	.string "lasciato è ancora qui.$"

SafariZone_Text_PokeblockWasPlaced:
	.string "Il {STR_VAR_1} è stato messo\n"
	.string "sul {POKEBLOCK} FEEDER.$"

Route121_SafariZoneEntrance_Text_WelcomeToSafariZone:
	.string "Benvenuto alla ZONA SAFARI!\p"
	.string "Qui puoi vedere molti tipi di\n"
	.string "POKéMON rari in questa regione.\p"
	.string "E li vedrai liberi e selvaggi\n"
	.string "nei loro habitat naturali.\p"
	.string "Inoltre, abbiamo aperto i\n"
	.string "cancelli agli ALLENATORI.\p"
	.string "Puoi catturare POKéMON\n"
	.string "e tenerli per sempre!\p"
	.string "Entra e divertiti alla ZONA SAFARI!$"

Route121_SafariZoneEntrance_Text_WelcomeFirstTime:
	.string "Benvenuto alla ZONA SAFARI!\n"
	.string "È la tua prima volta qui?$"

Route121_SafariZoneEntrance_Text_ComeInAndEnjoy:
	.string "Entra e divertiti alla ZONA SAFARI!$"

Route121_SafariZoneEntrance_Text_FirstTimeInfo:
	.string "Entrando nella ZONA SAFARI, ricevi\n"
	.string "30 SAFARI BALL per catturare\l"
	.string "i POKéMON.\p"
	.string "La Gara Safari finisce quando\n"
	.string "esaurisci le SAFARI BALL o dopo\l"
	.string "500 passi.\p"
	.string "Entra e divertiti alla ZONA SAFARI!$"

Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay:
	.string "Benvenuto alla ZONA SAFARI!\p"
	.string "Cattura quanto vuoi per soli ¥500!\n"
	.string "Vuoi fare una Gara Safari?$"

Route121_SafariZoneEntrance_Text_PlayAnotherTime:
	.string "Va bene.\n"
	.string "Torna a giocare un'altra volta!$"

Route121_SafariZoneEntrance_Text_NotEnoughMoney:
	.string "Non hai abbastanza soldi.\n"
	.string "Mi dispiace.$"

Route121_SafariZoneEntrance_Text_ThatWillBe500Please:
	.string "Sono ¥500, prego.$"

Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls:
	.string "Ecco le tue SAFARI BALL.$"

Route121_SafariZoneEntrance_Text_Received30SafariBalls:
	.string "{PLAYER} riceve 30 SAFARI BALL.$"

Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself:
	.string "Ti avviseremo quando la tua gara\n"
	.string "sarà finita.\p"
	.string "Fino ad allora, divertiti, mi raccomando!\n"
	.string "Buona escursione nel selvaggio!$"

Route121_SafariZoneEntrance_Text_PCIsFull:
	.string "Scusi!\n"
	.string "Il tuo BOX del PC è pieno.$"

Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase:
	.string "Scusa!\n"
	.string "Sembra che tu non abbia un {POKEBLOCK} CASE.\p"
	.string "Il tuo gioco al SAFARI sarà molto più\n"
	.string "fruttuoso se userai i {POKEBLOCK}.\p"
	.string "Torna quando avrai un {POKEBLOCK} CASE.\p"
	.string "Puoi ottenere un {POKEBLOCK} CASE da\n"
#if IS_HNS
	.string "quel ragazzo laggiù.$"
#else
	.string "the LILYCOVE CONTEST HALL.$"
#endif

SafariZone_South_Text_StillHaveTimeExit:
	.string "Hai ancora tempo. Vuoi\n"
	.string "uscire ora dalla ZONA SAFARI?$"

SafariZone_South_Text_EnjoyTheRestOfYourAdventure:
	.string "Goditi il resto della tua\n"
	.string "avventura selvaggia!$"

SafariZone_South_Text_ExitEarlyThankYouForPlaying:
	.string "Va bene.\p"
	.string "Riprendo le tue SAFARI\n"
	.string "BALL rimaste.\p"
	.string "Grazie per aver giocato.\n"
	.string "Speriamo di rivederti.$"

SafariZone_South_Text_GoodLuck:
	.string "Buona fortuna!\p"
	.string "Se ti serve qualcosa, non esitare\n"
	.string "a chiedermelo!$"

SafariZone_South_Text_Boy:
	.string "Lo sapevi?\p"
	.string "Se metti un {POKEBLOCK} in quel box quadrato,\n"
	.string "i POKéMON si radunano.$"

SafariZone_South_Text_Man:
	.string "Vorrei andare più a fondo, ma ho\n"
	.string "dimenticato la BICICLETTA.\p"
	.string "Qualcosa mi dice che POKéMON rari\n"
	.string "vivono nelle zone più lontane.$"

SafariZone_Southwest_Text_Woman:
	.string "A volte, quando lancio un {POKEBLOCK} ai\n"
	.string "POKéMON, viene ignorato.\p"
	.string "I POKéMON hanno gusti e disgusti\n"
	.string "su ciò che mangiano?$"

SafariZone_Northwest_Text_Man:
	.string "Ansimo… Ansimo…\n"
	.string "Sono… arrivato fin qui… ma…\p"
	.string "Sono esausto… non ho l'energia\n"
	.string "per catturare POKéMON…$"

SafariZone_North_Text_Fisherman:
	.string "Sono in missione per trovare POKéMON\n"
	.string "ACQUA che non si vedono a HOENN.\p"
	.string "Sai per caso dov'è il lago?$"

SafariZone_North_Text_Man:
	.string "Catturerò molti POKéMON rari\n"
	.string "qui e li scambierò con gli amici!$"

SafariZone_South_Text_Youngster:
	.string "Ho messo un {POKEBLOCK} sul {POKEBLOCK} FEEDER.\n"
	.string "Ma sembra sparito.\p"
	.string "Immagino che qualche POKéMON l'abbia\n"
	.string "mangiato senza che me ne accorgessi.$"

Route121_SafariZoneEntrance_Text_TrainerTip:
	.string "CONSIGLIO ZONA SAFARI!\p"
	.string "Lancia {POKEBLOCK} ai POKéMON selvatici per\n"
	.string "farli fuggire meno.$"

SafariZone_Southwest_Text_RestHouseSign:
	.string "“Riposa i tuoi piedi stanchi.”\n"
	.string "CASA RIPOSO$"

SafariZone_RestHouse_Text_Youngster:
	.string "Non ho {POKEBLOCK}, ma ho catturato\n"
	.string "parecchi POKéMON.\p"
	.string "Puoi aumentare le tue possibilità\n"
	.string "avvicinandoti a loro\l"
	.string "prima di lanciare una SAFARI BALL.$"

SafariZone_RestHouse_Text_PsychicM:
	.string "Se usi i {POKEBLOCK}, i POKéMON selvatici non\n"
	.string "fuggiranno così in fretta.\p"
	.string "Non serve molto dare {POKEBLOCK} ai\n"
	.string "POKéMON che non fuggono facilmente.$"

SafariZone_RestHouse_Text_FatMan:
	.string "Se metti un {POKEBLOCK} sulla MANGIATOIA,\n"
	.string "i POKéMON ne sono attratti.\p"
	.string "Credo che i POKéMON della stessa\n"
	.string "natura siano attratti da un certo {POKEBLOCK}.$"

SafariZone_South_Text_AreaOffLimits1:
	.string "Questa zona è ancora in costruzione.\n"
	.string "È vietata, mi dispiace!$"

SafariZone_Southeast_Text_ExpansionIsFinished:
	.string "Il progetto di ampliamento della\n"
	.string "ZONA SAFARI è finito.\p"
	.string "Speriamo che la nuova area vi piaccia.$"

SafariZone_South_Text_AreaOffLimits2:
	.string "Questa zona è ancora in costruzione.\n"
	.string "È vietata, mi dispiace!$"

SafariZone_Southeast_Text_LittleGirl:
	.string "Wow! Uau! Non ho mai visto\n"
	.string "nessuno di questi POKéMON!$"

SafariZone_Southeast_Text_FatMan:
	.string "I POKéMON di quest'area sono tutti\n"
	.string "nuovi per me.\p"
	.string "E posso catturare questi POKéMON\n"
	.string "rari! Che forte!$"

SafariZone_Southeast_Text_RichBoy:
	.string "I POKéMON qui intorno sembrano\n"
	.string "venire da un luogo diverso da HOENN.$"

SafariZone_Northeast_Text_Boy:
	.string "Mi restano solo un paio di SAFARI BALL.\p"
	.string "Non riesco a decidere\n"
	.string "cosa catturare.$"

SafariZone_Northeast_Text_Woman:
	.string "Ho sentito che qui si vedono i PIKACHU.\n"
	.string "Dove potrebbe essere?$"

SafariZone_Northeast_Text_Girl:
	.string "Oh, che pizza!\n"
	.string "Non riesco a catturare niente!\p"
	.string "Sprecherò il prezzo del biglietto\n"
	.string "se non prendo qualcosa!$"
