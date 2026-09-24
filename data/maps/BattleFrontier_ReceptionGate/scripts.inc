BattleFrontier_ReceptionGate_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_ReceptionGate_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_ReceptionGate_OnTransition
	.byte 0

BattleFrontier_ReceptionGate_OnTransition:
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
	end

BattleFrontier_ReceptionGate_OnFrame:
	map_script_2 VAR_HAS_ENTERED_BATTLE_FRONTIER, 0, BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering
	.2byte 0

BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering::
	lockall
	setvar VAR_HAS_ENTERED_BATTLE_FRONTIER, 1
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_Delay48
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter
	waitmovement 0
	goto BattleFrontier_ReceptionGate_EventScript_ScottScene
	end

BattleFrontier_ReceptionGate_EventScript_ScottScene::
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IssueFrontierPass, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass
	waitfanfare
	waitmessage
	msgbox BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass, MSGBOX_DEFAULT
	setflag FLAG_SYS_FRONTIER_PASS
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_ExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, BattleFrontier_ReceptionGate_Movement_GreeterFaceScott
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerFaceScott
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottEnter
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_FRONTIER_RECEPTION_SCOTT
	releaseall
	end

BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter:
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_PlayerFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

@ Unused
BattleFrontier_ReceptionGate_Movement_WalkDown:
	walk_down
	walk_down
	step_end

BattleFrontier_ReceptionGate_Movement_ScottEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_ScottExit:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_ReceptionGate_Movement_GreeterFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

BattleFrontier_ReceptionGate_EventScript_Greeter::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FacilityGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFacilities, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich2
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BF_RECEPTIONIST
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_BattleTower
	case 1, BattleFrontier_ReceptionGate_EventScript_BattleDome
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePalace
	case 3, BattleFrontier_ReceptionGate_EventScript_BattleArena
	case 4, BattleFrontier_ReceptionGate_EventScript_BattleFactory
	case 5, BattleFrontier_ReceptionGate_EventScript_BattlePike
	case 6, BattleFrontier_ReceptionGate_EventScript_BattlePyramid
	case 7, BattleFrontier_ReceptionGate_EventScript_RankingHall
	case 8, BattleFrontier_ReceptionGate_EventScript_ExchangeCorner
	case 9, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	end

BattleFrontier_ReceptionGate_EventScript_BattleTower::
	msgbox BattleFrontier_ReceptionGate_Text_BattleTowerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleDome::
	msgbox BattleFrontier_ReceptionGate_Text_BattleDomeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePalace::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePalaceInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleArena::
	msgbox BattleFrontier_ReceptionGate_Text_BattleArenaInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleFactory::
	msgbox BattleFrontier_ReceptionGate_Text_BattleFactoryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePike::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePikeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePyramid::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePyramidInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RankingHall::
	msgbox BattleFrontier_ReceptionGate_Text_RankingHallInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExchangeCorner::
	msgbox BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_RulesGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToRules, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhat
	waitmessage
	multichoice 15, 0, MULTI_FRONTIER_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_LevelMode
	case 1, BattleFrontier_ReceptionGate_EventScript_Level50
	case 2, BattleFrontier_ReceptionGate_EventScript_OpenLevel
	case 3, BattleFrontier_ReceptionGate_EventScript_MonEntry
	case 4, BattleFrontier_ReceptionGate_EventScript_HoldItems
	case 5, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	end

BattleFrontier_ReceptionGate_EventScript_LevelMode::
	msgbox BattleFrontier_ReceptionGate_Text_LevelModeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_Level50::
	msgbox BattleFrontier_ReceptionGate_Text_Level50Info, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_OpenLevel::
	msgbox BattleFrontier_ReceptionGate_Text_OpenLevelInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_MonEntry::
	msgbox BattleFrontier_ReceptionGate_Text_MonEntryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_HoldItems::
	msgbox BattleFrontier_ReceptionGate_Text_HoldItemsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FrontierPassGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich1
	waitmessage
	multichoice 16, 4, MULTI_FRONTIER_PASS_INFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_Symbols
	case 1, BattleFrontier_ReceptionGate_EventScript_RecordBattle
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePoints
	case 3, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	end

BattleFrontier_ReceptionGate_EventScript_Symbols::
	msgbox BattleFrontier_ReceptionGate_Text_SymbolsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RecordBattle::
	msgbox BattleFrontier_ReceptionGate_Text_RecordedBattleInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePoints::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePointsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay:
	.string "È la tua prima volta qui?\n"
	.string "Ti prego, seguimi!$"

BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier:
	.string "L'avanguardia delle lotte POKéMON!\n"
	.string "Benvenuto alla ZONA LOTTA!$"

BattleFrontier_ReceptionGate_Text_IssueFrontierPass:
	.string "Ai nuovi visitatori rilasciamo\n"
	.string "il PASS FRONTERA.\p"
	.string "Serve in tutte le strutture\n"
	.string "della ZONA LOTTA.\p"
	.string "Eccoti!$"

BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass:
	.string "{PLAYER} ha ottenuto\n"
	.string "il PASS FRONTERA.$"

BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass:
	.string "{PLAYER} ha messo la SCHEDA\n"
	.string "nel PASS FRONTERA.$"

BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier:
	.string "Buon divertimento con tutto\n"
	.string "ciò che offre la ZONA LOTTA!$"

BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame:
	.string "???: Ma se non è {PLAYER}{KUN}!\n"
	.string "Sei venuto fin qui!$"

BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay:
	.string "GUIDA: Oh! SIGNOR SAVERIO!\n"
	.string "Buongiorno, egregio!$"

BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere:
	.string "SAVERIO: Che bello vederti qui,\n"
	.string "davvero!\p"
	.string "Spero che prenderai tempo ed\n"
	.string "esplorerai ogni angolo.\p"
	.string "E naturalmente spero che provi\n"
	.string "la vera essenza della lotta.\p"
	.string "Abito anch'io qui, quindi\n"
	.string "vieni a trovarmi quando vuoi.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFacilities:
	.string "Sono la guida alle strutture\n"
	.string "della ZONA LOTTA.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich2:
	.string "Quale argomento preferisci?$"

BattleFrontier_ReceptionGate_Text_BattleTowerInfo:
	.string "È la torre gigante, considerata\n"
	.string "il simbolo della ZONA LOTTA.\p"
	.string "Nella torre ci sono quattro tipi\n"
	.string "di STANZE DI LOTTA per SINGOLA,\l"
	.string "DOPPIA, MULTI E MULTI IN RETE.$"

BattleFrontier_ReceptionGate_Text_BattleDomeInfo:
	.string "Il DOMO LOTTA è il grande\n"
	.string "edificio a forma di uovo.\p"
	.string "Vi si svolgono tornei\n"
	.string "di lotta.\p"
	.string "I tornei si svolgono in\n"
	.string "due modalità: SINGOLO e DOPPIO\l"
	.string "LOTTE.$"

BattleFrontier_ReceptionGate_Text_BattlePalaceInfo:
	.string "Il PALAZZO LOTTA è l'edificio\n"
	.string "rosso a destra della FRONTIERA.\p"
	.string "Esistono due tipi di SALA LOTTA\n"
	.string "per lotte SINGOLO e DOPPIO.$"

BattleFrontier_ReceptionGate_Text_BattleArenaInfo:
	.string "La LOTTA ARENA è l'edificio\n"
	.string "tipo dojo a centro-destra\l"
	.string "della FRONTIERA LOTTA.\p"
	.string "Alla LOTTA ARENA si tiene\n"
	.string "il torneo Set KO.$"

BattleFrontier_ReceptionGate_Text_BattleFactoryInfo:
	.string "La FABBRICA LOTTA è il grande\n"
	.string "edificio più vicino a noi.\p"
	.string "Lì si svolge lo Scambio\n"
	.string "di lotta.\p"
	.string "Lo Scambio di lotta si fa in\n"
	.string "due modalità: LOTTE SINGOLE e\l"
	.string "DOPPIE.$"

BattleFrontier_ReceptionGate_Text_BattlePikeInfo:
	.string "La LOTTA PIKE è l'edificio a forma\n"
	.string "di POKéMON al centro-sinistra\l"
	.string "della ZONA LOTTA.\p"
	.string "Lì si svolge l'evento Scelta\n"
	.string "di Combattimento.$"

BattleFrontier_ReceptionGate_Text_BattlePyramidInfo:
	.string "La LOTTA PIRAMIDE è l'enorme\n"
	.string "piramide.\p"
	.string "Lì si svolge l'evento Ricerca\n"
	.string "di Combattimento.$"

BattleFrontier_ReceptionGate_Text_RankingHallInfo:
	.string "La SALA CLASSIFICHE è vicino\n"
	.string "alla LOTTA TORRE.\p"
	.string "Lì puoi ammirare i record\n"
	.string "straordinari lasciati dagli\l"
	.string "ALLENATORI che hanno affrontato\l"
	.string "la ZONA LOTTA.$"

BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo:
	.string "Il SERVIZIO SCAMBI è vicino\n"
	.string "alla LOTTA TORRE.\p"
	.string "I Punti Lotta ottenuti nella\n"
	.string "ZONA LOTTA si possono scambiare\l"
	.string "con premi favolosi.$"

BattleFrontier_ReceptionGate_Text_YourGuideToRules:
	.string "Sono la guida alle regole di base\n"
	.string "comuni a tutte le sfide\l"
	.string "proposte dalle strutture della\l"
	.string "ZONA LOTTA.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhat:
	.string "Cosa vuoi conoscere?$"

BattleFrontier_ReceptionGate_Text_LevelModeInfo:
	.string "Le sfide delle strutture della\n"
	.string "ZONA LOTTA hanno due corsi:\l"
	.string "Livello 50 e Livello Libero.$"

BattleFrontier_ReceptionGate_Text_Level50Info:
	.string "Il corso Livello 50 è aperto ai\n"
	.string "POKéMON fino al Livello 50.\p"
	.string "Ricorda però che nessun\n"
	.string "ALLENATORE avrà POKéMON\l"
	.string "sotto il Livello 50.\p"
	.string "Questo corso è quello base\n"
	.string "per la ZONA LOTTA.\p"
	.string "Per iniziare, ti consigliamo\n"
	.string "questo corso.$"

BattleFrontier_ReceptionGate_Text_OpenLevelInfo:
	.string "Il corso Livello Libero non ha\n"
	.string "limiti di livello per i POKéMON\l"
	.string "iscritti.\p"
	.string "Il livello degli avversari si\n"
	.string "adatta a quello dei tuoi\l"
	.string "POKéMON.\p"
	.string "Però nessun ALLENATORE avrà\n"
	.string "POKéMON sotto il Livello 60.$"

BattleFrontier_ReceptionGate_Text_MonEntryInfo:
	.string "Quasi ogni tipo di POKéMON può\n"
	.string "affrontare le sfide delle strutture.\p"
	.string "UOVA e certi POKéMON però\n"
	.string "non sono ammessi.\p"
	.string "Il numero di POKéMON richiesto\n"
	.string "dipende dalla struttura.\p"
	.string "In ogni caso, due o più POKéMON\n"
	.string "dello stesso tipo non\l"
	.string "sono ammessi.$"

BattleFrontier_ReceptionGate_Text_HoldItemsInfo:
	.string "Quando inizi una sfida in una\n"
	.string "struttura della ZONA LOTTA, i\l"
	.string "POKéMON non possono portare lo\p"
	.string "stesso strumento. Assicurati che\n"
	.string "tutti i POKéMON iscritti abbiano\l"
	.string "strumenti diversi.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass:
	.string "Sono la guida al PASS FRONTERA.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich1:
	.string "Quale argomento preferisci?$"

BattleFrontier_ReceptionGate_Text_SymbolsInfo:
	.string "Ci sono sette strutture alla\n"
	.string "FRONTIERA LOTTA.\p"
	.string "Gli ALLENATORI che si distinguono\n"
	.string "per le abilità possono ricevere\l"
	.string "dei simboli da ogni struttura.\p"
	.string "Per un simbolo, gli ALLENATORI\n"
	.string "devono battere altri ALLENATORI\l"
	.string "e vincere più volte di seguito.\p"
	.string "Non è certo facile vincere simboli.\n"
	.string "Ti auguro buona fortuna!$"

BattleFrontier_ReceptionGate_Text_RecordedBattleInfo:
	.string "Puoi registrare una lotta\n"
	.string "sul tuo PASS FRONTIERA.\p"
	.string "Puoi registrare una lotta fatta\n"
	.string "con un amico o più amici.\p"
	.string "O una lotta svolta alla\n"
	.string "FRONTIERA LOTTA, escluse quelle\l"
	.string "alla LOTTA PIKE o alla\l"
	.string "LOTTA PIRAMIDE.\p"
	.string "Puoi registrare la tua partita\n"
	.string "alla fine di una lotta.$"

BattleFrontier_ReceptionGate_Text_BattlePointsInfo:
	.string "I Punti Lotta sono premi dati ai\n"
	.string "ALLENATORI che hanno lottato bene\l"
	.string "alla FRONTIERA LOTTA.\p"
	.string "Puoi scambiare i tuoi Punti Lotta\n"
	.string "per premi allo SPORTELLO\l"
	.string "SCAMBI.$"

