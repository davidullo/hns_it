VerdanturfTown_WandasHouse_MapScripts::
	.byte 0

VerdanturfTown_WandasHouse_EventScript_Wally::
	lock
	faceplayer
	goto_if_set FLAG_WALLY_SPEECH, VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeech, MSGBOX_DEFAULT
	setflag FLAG_WALLY_SPEECH
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech::
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeechShort, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff
	msgbox VerdanturfTown_WandasHouse_Text_WallysNextDoor, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff::
	msgbox VerdanturfTown_WandasHouse_Text_WallySlippedOff, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyGoneThatFar, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandasBoyfriend::
	msgbox VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay, MSGBOX_NPC
	end

VerdanturfTown_WandasHouse_EventScript_Wanda::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WandaDontWorry
	goto_if_set FLAG_DEFEATED_WALLY_MAUVILLE, VerdanturfTown_WandasHouse_EventScript_MeetWanda
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_MeetWanda::
	msgbox VerdanturfTown_WandasHouse_Text_MeetWanda, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandaDontWorry::
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAunt::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen::
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened::
	msgbox VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_Text_StrongerSpeech:
	.string "WALLY: Ho perso con te, {PLAYER}, ma non\n"
	.string "mi sento più giù.\p"
	.string "Perché ho un nuovo scopo nella vita.\n"
	.string "Insieme al mio RALTS,\l"
	.string "sfiderò le PALESTRE POKéMON e diventerò\l"
	.string "un grande ALLENATORE.\p"
	.string "Guardami, {PLAYER}.\n"
	.string "Sarò più forte di te.\p"
	.string "E quando lo sarò, ti sfiderò\n"
	.string "per un'altra lotta.$"

VerdanturfTown_WandasHouse_Text_StrongerSpeechShort:
	.string "WALLY: Guardami, {PLAYER}.\n"
	.string "Diventerò più forte di te.\p"
	.string "E quando lo sarò, ti sfiderò\n"
	.string "per un'altra lotta.$"

VerdanturfTown_WandasHouse_Text_WallysNextDoor:
	.string "ZIO: Oh! {PLAYER}{KUN}!\n"
	.string "WALLY è qui accanto.\p"
	.string "Ma, ragazzo, devo dirti\n"
	.string "una cosa.\p"
	.string "Quest'ambiente naturale sta facendo\n"
	.string "miracoli per la salute di WALLY.\p"
	.string "Forse non è solo l'ambiente.\n"
	.string "Potrebbero essere i POKéMON a dare\l"
	.string "speranza al ragazzo.$"

VerdanturfTown_WandasHouse_Text_WallySlippedOff:
	.string "WALLY è andato via…\n"
	.string "È sgusciato via da solo…$"

VerdanturfTown_WandasHouse_Text_WallyGoneThatFar:
	.string "ZIO: Davvero?\n"
	.string "WALLY è andato così lontano tutto\l"
	.string "da solo…\p"
	.string "Beh, devo riconoscerglielo, è\n"
	.string "il figlio di mio fratello.$"

VerdanturfTown_WandasHouse_Text_MeetWanda:
	.string "WANDA: Tu sei?\n"
	.string "Ah, giusto, capisco!\p"
	.string "Sei {PLAYER}, quello di cui WALLY\n"
	.string "mi ha parlato.\p"
	.string "Sono la cugina di WALLY.\n"
	.string "Piacere di conoscerti!\p"
	.string "Credo che WALLY sia molto più vivace\n"
	.string "e in salute da quando è qui.$"

VerdanturfTown_WandasHouse_Text_DontWorryAboutWally:
	.string "WANDA: Non preoccuparti per WALLY.\n"
	.string "Starà benissimo.\p"
	.string "Conosco mio cugino, e ha\n"
	.string "anche dei POKéMON con sé.$"

VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay:
	.string "Grazie a te, posso vedere la mia\n"
	.string "ragazza ogni giorno.\l"
	.string "Felice? Altroché!$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven:
	.string "Il fidanzato di mia figlia è molto\n"
	.string "determinato e passionale.\p"
	.string "Scava un tunnel senza sosta\n"
	.string "solo per vedere mia figlia.\p"
	.string "Mia figlia è un po' preoccupata,\n"
	.string "quindi va spesso al tunnel.$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging:
	.string "Incredibile. Il fidanzato di mia figlia\n"
	.string "scavava il tunnel a mano!\p"
	.string "È davvero incredibile!$"

VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally:
	.string "Se dovesse succedere qualcosa a WALLY,\n"
	.string "non potrei mai guardare i suoi\l"
	.string "genitori a PETALBURG negli occhi…$"

VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande:
	.string "WALLY era a EVER GRANDE?\p"
	.string "I suoi genitori a PETALBURG\n"
	.string "ne resterebbero sbalorditi!$"

