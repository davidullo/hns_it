SlateportCity_SternsShipyard_1F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_1F_EventScript_Dock::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_SternsShipyard_1F_EventScript_FerryReady
	goto_if_set FLAG_BADGE07_GET, SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_GoFindStern
	msgbox SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails, MSGBOX_DEFAULT
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_DOCK_REJECTED_DEVON_GOODS
	setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_FerryReady::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_FerryIsReady, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_GoFindStern::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Briney::
	msgbox SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails:
	.string "Uhm… Se questo va qui, e quello\n"
	.string "va laggiù…\p"
	.string "Allora dove va questa cosa?\n"
	.string "E quell'aggeggio?\p"
	.string "Aaah! Non ci capisco\n"
	.string "niente!$"

SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern:
	.string "Hm?\n"
	.string "Ciao, sono DOCK.\p"
	.string "Il CAPITANO STERN mi ha incaricato di\n"
	.string "progettare un traghetto.\p"
	.string "Oh! Quello lì…\n"
	.string "Sono i PEZZI DEVON?\p"
	.string "Ma, hmm…\n"
	.string "Così non va…\p"
	.string "Il CAPITANO STERN è andato via.\n"
	.string "Ha detto che aveva del lavoro.\p"
	.string "Potresti trovare il CAPITANO\n"
	.string "STERN e consegnarglielo?$"

SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern:
	.string "DOCK: Dove sarà finito il\n"
	.string "CAPITANO STERN?\p"
	.string "Potresti trovare il CAPITANO STERN e\n"
	.string "consegnargli quel pacco?$"

SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran:
	.string "DOCK: Costruire navi è un'arte.\p"
	.string "Molte cose non si capiscono\n"
	.string "solo con i calcoli.\p"
	.string "Mi servirebbe il consiglio di un veterano\n"
	.string "che conosce i mari…$"

SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs:
	.string "DOCK: Ciao! Il SIG. BRINEY è qui\n"
	.string "a darci una mano.\p"
	.string "Grazie al marinaio esperto, il\n"
	.string "traghetto prende forma pian piano.$"

SlateportCity_SternsShipyard_1F_Text_FerryIsReady:
	.string "DOCK: Il traghetto è pronto!\p"
	.string "Il nuovo S.S. TIDAL è una vera meraviglia\n"
	.string "della tecnologia!\p"
	.string "Ma sento che possiamo\n"
	.string "fare anche di meglio.\p"
	.string "Sai, il progresso della tecnologia\n"
	.string "non si ferma mai.$"

SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock:
	.string "CAP. BRINEY: Ah, {PLAYER}{KUN}!\n"
	.string "È passato troppo tempo!\p"
	.string "Da quando ti ho visto, questo\n"
	.string "vecchio lupo di mare è rinato!\p"
	.string "Così ho deciso di aiutare DOCK a\n"
	.string "fare un traghetto.\p"
	.string "Un traghetto può\n"
	.string "portare molta gente.\p"
	.string "Ma sai, quel DOCK è davvero\n"
	.string "speciale.\p"
	.string "Col suo talento per la tecnologia e\n"
	.string "la mia esperienza, costruiremo di\l"
	.string "sicuro una nave fantastica!$"

SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing:
	.string "Le stagioni, il meteo, dove\n"
	.string "sta la luna nel cielo…\p"
	.string "Queste e altre condizioni fanno\n"
	.string "cambiare espressione al mare.\p"
	.string "Proprio così!\n"
	.string "Il mare è come un essere vivente!$"

SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily:
	.string "Mi viene il mal di mare facilissimo.\n"
	.string "Quindi aiuto qui, invece.$"

