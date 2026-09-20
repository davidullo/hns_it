BattleFrontier_ReceptionGate_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_ReceptionGate_OnFrame_hns
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_ReceptionGate_OnTransition_hns
	.byte 0

BattleFrontier_ReceptionGate_OnTransition_hns:
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
	end

BattleFrontier_ReceptionGate_OnFrame_hns:
	map_script_2 VAR_HAS_ENTERED_BATTLE_FRONTIER, 0, BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering_hns
	.2byte 0

BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering_hns::
	lockall
	setvar VAR_HAS_ENTERED_BATTLE_FRONTIER, 1
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_FRONTIER_RECEPTION_GREETER
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_Delay48
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter_hns
	waitmovement 0
	goto BattleFrontier_ReceptionGate_EventScript_ScottScene_hns
	end

BattleFrontier_ReceptionGate_EventScript_ScottScene_hns::
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier_hns, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IssueFrontierPass_hns, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass_hns
	waitfanfare
	waitmessage
	msgbox BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass_hns, MSGBOX_DEFAULT
	setflag FLAG_SYS_FRONTIER_PASS
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_ExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_PLAYER
	msgbox BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, BattleFrontier_ReceptionGate_Movement_GreeterFaceScott_hns
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott_hns
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerFaceScott_hns
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottEnter_hns
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottExit_hns
	waitmovement 0
	removeobject LOCALID_FRONTIER_RECEPTION_SCOTT
	releaseall
	end

BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter_hns:
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_PlayerFaceScott_hns:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

@ Unused
BattleFrontier_ReceptionGate_Movement_WalkDown_hns:
	walk_down
	walk_down
	step_end

BattleFrontier_ReceptionGate_Movement_ScottEnter_hns:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_ScottExit_hns:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_ReceptionGate_Movement_GreeterFaceScott_hns:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott_hns:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

BattleFrontier_ReceptionGate_EventScript_Greeter_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier_hns, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FacilityGuide_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFacilities_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich2_hns
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BF_RECEPTIONIST
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_BattleTower_hns
	case 1, BattleFrontier_ReceptionGate_EventScript_BattleDome_hns
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePalace_hns
	case 3, BattleFrontier_ReceptionGate_EventScript_BattleArena_hns
	case 4, BattleFrontier_ReceptionGate_EventScript_BattleFactory_hns
	case 5, BattleFrontier_ReceptionGate_EventScript_BattlePike_hns
	case 6, BattleFrontier_ReceptionGate_EventScript_BattlePyramid_hns
	case 7, BattleFrontier_ReceptionGate_EventScript_RankingHall_hns
	case 8, BattleFrontier_ReceptionGate_EventScript_ExchangeCorner_hns
	case 9, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide_hns
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattleTower_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattleTowerInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattleDome_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattleDomeInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattlePalace_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePalaceInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattleArena_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattleArenaInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattleFactory_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattleFactoryInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattlePike_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePikeInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattlePyramid_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePyramidInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_RankingHall_hns::
	msgbox BattleFrontier_ReceptionGate_Text_RankingHallInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ExchangeCorner_hns::
	msgbox BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide_hns::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_RulesGuide_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhat_hns
	waitmessage
	multichoice 15, 0, MULTI_FRONTIER_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_LevelMode_hns
	case 1, BattleFrontier_ReceptionGate_EventScript_Level50_hns
	case 2, BattleFrontier_ReceptionGate_EventScript_OpenLevel_hns
	case 3, BattleFrontier_ReceptionGate_EventScript_MonEntry_hns
	case 4, BattleFrontier_ReceptionGate_EventScript_HoldItems_hns
	case 5, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide_hns
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide_hns
	end

BattleFrontier_ReceptionGate_EventScript_LevelMode_hns::
	msgbox BattleFrontier_ReceptionGate_Text_LevelModeInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_Level50_hns::
	msgbox BattleFrontier_ReceptionGate_Text_Level50Info_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_OpenLevel_hns::
	msgbox BattleFrontier_ReceptionGate_Text_OpenLevelInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_MonEntry_hns::
	msgbox BattleFrontier_ReceptionGate_Text_MonEntryInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_HoldItems_hns::
	msgbox BattleFrontier_ReceptionGate_Text_HoldItemsInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide_hns::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FrontierPassGuide_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout_hns::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich1_hns
	waitmessage
	multichoice 16, 4, MULTI_FRONTIER_PASS_INFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_Symbols_hns
	case 1, BattleFrontier_ReceptionGate_EventScript_RecordBattle_hns
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePoints_hns
	case 3, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide_hns
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide_hns
	end

BattleFrontier_ReceptionGate_EventScript_Symbols_hns::
	msgbox BattleFrontier_ReceptionGate_Text_SymbolsInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_RecordBattle_hns::
	msgbox BattleFrontier_ReceptionGate_Text_RecordedBattleInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattlePoints_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePointsInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide_hns::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay_hns:
	.string "È la tua prima volta qui?\n"
	.string "Ti prego, seguimi!$"

BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier_hns:
	.string "L'avanguardia delle lotte POKéMON!\n"
	.string "Benvenuto alla ZONA LOTTA!$"

BattleFrontier_ReceptionGate_Text_IssueFrontierPass_hns:
	.string "Ai nuovi visitatori rilasciamo\n"
	.string "il PASS FRONTERA.\p"
	.string "Serve in tutte le strutture\n"
	.string "della ZONA LOTTA.\p"
	.string "Eccoti!$"

BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass_hns:
	.string "{PLAYER} ha ottenuto\n"
	.string "il PASS FRONTERA.$"

BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass_hns:
	.string "{PLAYER} ha messo la SCHEDA\n"
	.string "nel PASS FRONTERA.$"

BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns:
	.string "Buon divertimento con tutto\n"
	.string "ciò che offre la ZONA LOTTA!$"

BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame_hns:
	.string "???: Ma se non è {PLAYER}{KUN}!\n"
	.string "Sei venuto fin qui!$"

BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay_hns:
	.string "GUIDA: Oh! SIGNOR SCOTT!\n"
	.string "Buongiorno, egregio!$"

BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere_hns:
	.string "SCOTT: Che bello vederti qui,\n"
	.string "davvero!\p"
	.string "Spero che prenderai tempo ed\n"
	.string "esplorerai ogni angolo.\p"
	.string "E naturalmente spero che provi\n"
	.string "la vera essenza della lotta.\p"
	.string "Abito anch'io qui, quindi\n"
	.string "vieni a trovarmi quando vuoi.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFacilities_hns:
	.string "Sono la guida alle strutture\n"
	.string "della ZONA LOTTA.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich2_hns:
	.string "Quale argomento preferisci?$"

BattleFrontier_ReceptionGate_Text_BattleTowerInfo_hns:
	.string "È la torre gigante, considerata\n"
	.string "il simbolo della ZONA LOTTA.\p"
	.string "Nella torre ci sono quattro tipi\n"
	.string "di STANZE DI LOTTA per SINGOLA,\l"
	.string "DOPPIA, MULTI E MULTI IN RETE.$"

BattleFrontier_ReceptionGate_Text_BattleDomeInfo_hns:
	.string "Il DOMO LOTTA è il grande\n"
	.string "edificio a forma di uovo.\p"
	.string "Vi si svolgono tornei\n"
	.string "di lotta.\p"
	.string "I tornei si svolgono in\n"
	.string "due modalità: SINGOLO e DOPPIO\l"
	.string "LOTTE.$"

BattleFrontier_ReceptionGate_Text_BattlePalaceInfo_hns:
	.string "Il PALAZZO LOTTA è l'edificio\n"
	.string "rosso a destra della FRONTIERA.\p"
	.string "Esistono due tipi di SALA LOTTA\n"
	.string "per lotte SINGOLO e DOPPIO.$"

BattleFrontier_ReceptionGate_Text_BattleArenaInfo_hns:
	.string "La LOTTA ARENA è l'edificio\n"
	.string "tipo dojo a centro-destra\l"
	.string "della FRONTIERA LOTTA.\p"
	.string "Alla LOTTA ARENA si tiene\n"
	.string "il torneo Set KO.$"

BattleFrontier_ReceptionGate_Text_BattleFactoryInfo_hns:
	.string "La FABBRICA LOTTA è il grande\n"
	.string "edificio più vicino a noi.\p"
	.string "Lì si svolge lo Scambio\n"
	.string "di lotta.\p"
	.string "Lo Scambio di lotta si fa in\n"
	.string "due modalità: LOTTE SINGOLE e\l"
	.string "DOPPIE.$"

BattleFrontier_ReceptionGate_Text_BattlePikeInfo_hns:
	.string "La LOTTA PIKE è l'edificio a forma\n"
	.string "di POKéMON al centro-sinistra\l"
	.string "della ZONA LOTTA.\p"
	.string "Lì si svolge l'evento Scelta\n"
	.string "di Combattimento.$"

BattleFrontier_ReceptionGate_Text_BattlePyramidInfo_hns:
	.string "La LOTTA PIRAMIDE è l'enorme\n"
	.string "piramide.\p"
	.string "Lì si svolge l'evento Ricerca\n"
	.string "di Combattimento.$"

BattleFrontier_ReceptionGate_Text_RankingHallInfo_hns:
	.string "La SALA CLASSIFICHE è vicino\n"
	.string "alla LOTTA TORRE.\p"
	.string "Lì puoi ammirare i record\n"
	.string "straordinari lasciati dagli\l"
	.string "ALLENATORI che hanno affrontato\l"
	.string "la ZONA LOTTA.$"

BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo_hns:
	.string "Il SERVIZIO SCAMBI è vicino\n"
	.string "alla LOTTA TORRE.\p"
	.string "I Punti Lotta ottenuti nella\n"
	.string "ZONA LOTTA si possono scambiare\l"
	.string "con premi favolosi.$"

BattleFrontier_ReceptionGate_Text_YourGuideToRules_hns:
	.string "Sono la guida alle regole di base\n"
	.string "comuni a tutte le sfide\l"
	.string "proposte dalle strutture della\l"
	.string "ZONA LOTTA.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhat_hns:
	.string "Cosa vuoi conoscere?$"

BattleFrontier_ReceptionGate_Text_LevelModeInfo_hns:
	.string "Le sfide delle strutture della\n"
	.string "ZONA LOTTA hanno due corsi:\l"
	.string "Livello 50 e Livello Libero.$"

BattleFrontier_ReceptionGate_Text_Level50Info_hns:
	.string "Il corso Livello 50 è aperto ai\n"
	.string "POKéMON fino al Livello 50.\p"
	.string "Ricorda però che nessun\n"
	.string "ALLENATORE avrà POKéMON\l"
	.string "sotto il Livello 50.\p"
	.string "Questo corso è quello base\n"
	.string "per la ZONA LOTTA.\p"
	.string "Per iniziare, ti consigliamo\n"
	.string "questo corso.$"

BattleFrontier_ReceptionGate_Text_OpenLevelInfo_hns:
	.string "Il corso Livello Libero non ha\n"
	.string "limiti di livello per i POKéMON\l"
	.string "iscritti.\p"
	.string "Il livello degli avversari si\n"
	.string "adatta a quello dei tuoi\l"
	.string "POKéMON.\p"
	.string "Però nessun ALLENATORE avrà\n"
	.string "POKéMON sotto il Livello 60.$"

BattleFrontier_ReceptionGate_Text_MonEntryInfo_hns:
	.string "Quasi ogni tipo di POKéMON può\n"
	.string "affrontare le sfide delle strutture.\p"
	.string "UOVA e certi POKéMON però\n"
	.string "non sono ammessi.\p"
	.string "Il numero di POKéMON richiesto\n"
	.string "dipende dalla struttura.\p"
	.string "In ogni caso, due o più POKéMON\n"
	.string "dello stesso tipo non\l"
	.string "sono ammessi.$"

BattleFrontier_ReceptionGate_Text_HoldItemsInfo_hns:
	.string "Quando inizi una sfida in una\n"
	.string "struttura della ZONA LOTTA, i\l"
	.string "POKéMON non possono portare lo\p"
	.string "stesso strumento. Assicurati che\n"
	.string "tutti i POKéMON iscritti abbiano\l"
	.string "strumenti diversi.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass_hns:
	.string "Sono la guida al PASS FRONTERA.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich1_hns:
	.string "Quale argomento preferisci?$"

BattleFrontier_ReceptionGate_Text_SymbolsInfo_hns:
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

BattleFrontier_ReceptionGate_Text_RecordedBattleInfo_hns:
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

BattleFrontier_ReceptionGate_Text_BattlePointsInfo_hns:
	.string "I Punti Lotta sono premi dati ai\n"
	.string "ALLENATORI che hanno lottato bene\l"
	.string "alla FRONTIERA LOTTA.\p"
	.string "Puoi scambiare i tuoi Punti Lotta\n"
	.string "per premi allo SPORTELLO\l"
	.string "SCAMBI.$"

