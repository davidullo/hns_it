CeladonCity_DepartmentStore_3F_Frlg_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_3F_EventScript_CounterTutor::
	goto EventScript_CounterTutor
	end

CeladonCity_DepartmentStore_3F_EventScript_GBAKid1::
	msgbox CeladonCity_DepartmentStore_3F_Text_OTStandsForOriginalTrainer, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_3F_EventScript_GBAKid2::
	msgbox CeladonCity_DepartmentStore_3F_Text_BuddyTradingKangaskhanForHaunter, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_3F_EventScript_GBAKid3::
	msgbox CeladonCity_DepartmentStore_3F_Text_HaunterEvolvedOnTrade, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_3F_EventScript_LittleGirl::
	msgbox CeladonCity_DepartmentStore_3F_Text_CanIdentifyTradeMonsByID, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_3F_EventScript_SuperNES::
	msgbox CeladonCity_DepartmentStore_3F_Text_ItsSuperNES, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_TV1::
	msgbox CeladonCity_DepartmentStore_3F_Text_AnRPG, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_TV2::
	msgbox CeladonCity_DepartmentStore_3F_Text_SportsGame, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_TV3::
	msgbox CeladonCity_DepartmentStore_3F_Text_PuzzleGame, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_TV4::
	msgbox CeladonCity_DepartmentStore_3F_Text_FightingGame, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_3F_Text_TVGameShop, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_Poster::
	msgbox CeladonCity_DepartmentStore_3F_Text_RedGreenBothArePokemon, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_Text_OTStandsForOriginalTrainer::
	.string "Ogni POKéMON catturato è\n"
	.string "registrato con ID e OT.\p"
	.string "OT significa ALLENATORE ORIGINALE,\n"
	.string "cioè chi l'ha catturato prima.$"

CeladonCity_DepartmentStore_3F_Text_BuddyTradingKangaskhanForHaunter::
	.string "Perfetto!\p"
	.string "Il mio amico mi dà il suo\n"
	.string "KANGASKHAN per HAUNTER!$"

CeladonCity_DepartmentStore_3F_Text_HaunterEvolvedOnTrade::
	.string "Dai, HAUNTER!\p"
	.string "Adoro HAUNTER!\n"
	.string "Li colleziono!\p"
	.string "Oh?\p"
	.string "HAUNTER si è trasformato\n"
	.string "in un altro POKéMON!$"

CeladonCity_DepartmentStore_3F_Text_CanIdentifyTradeMonsByID::
	.string "I POKéMON ricevuti in scambio\n"
	.string "si riconoscono dal numero ID.$"

CeladonCity_DepartmentStore_3F_Text_ItsSuperNES::
	.string "È un Super NES.$"

CeladonCity_DepartmentStore_3F_Text_AnRPG::
	.string "Un GDR!\n"
	.string "Non ho tempo per questo!$"

CeladonCity_DepartmentStore_3F_Text_SportsGame::
	.string "Uno sport!\n"
	.string "Piacerà a papà!$"

CeladonCity_DepartmentStore_3F_Text_PuzzleGame::
	.string "Un rompicapo!\n"
	.string "Che dipendenza!$"

CeladonCity_DepartmentStore_3F_Text_FightingGame::
	.string "Un picchiaduro!\n"
	.string "Che tosto!$"

CeladonCity_DepartmentStore_3F_Text_TVGameShop::
	.string "3F: VIDEOGIOCHI$"

CeladonCity_DepartmentStore_3F_Text_RedGreenBothArePokemon::
	.string "Rosso e Verde!\n"
	.string "Sono due POKéMON!$"

Text_CounterTeach::
	.string "Ciao!\n"
	.string "POKéMON l'ho finito.\p"
	.string "Non ancora? Ti insegno una\n"
	.string "bella mossa:\p"
	.string "La mossa è CONTRATTACCO,\n"
	.string "eh,\p"
	.string "non quella su cui mi appoggio,\n"
	.string "intesi?$"

Text_CounterDeclined::
	.string "Non ti interessa? Torna da me\n"
	.string "se cambi idea.$"

Text_CounterWhichMon::
	.string "CONTRATTACCO: a quale\n"
	.string "POKéMON?$"

Text_CounterTaught::
	.string "Usi la mossa CONTRATTACCO\n"
	.string "che ti ho insegnato?$"
