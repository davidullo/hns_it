RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_CUT, RustboroCity_CuttersHouse_EventScript_ExplainCut
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainCut::
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse:
	.string "Quell'espressione decisa…\n"
	.string "Quel modo agile di muoverti…\l"
	.string "E i tuoi POKéMON ben allenati…\p"
	.string "Sei chiaramente un ALLENATORE abile!\p"
	.string "No, aspetta, non dire una parola.\n"
	.string "Si capisce solo guardandoti.\p"
	.string "Sono certo che saprai usare bene\n"
	.string "questa MACCHINA NASCOSTA.\p"
	.string "Non fare il modesto o il timido.\n"
	.string "Forza, prendila!$"

RustboroCity_CuttersHouse_Text_ExplainCut:
	.string "Quella MACCHINA NASCOSTA, o MN in\n"
	.string "breve, è TAGLIO.\p"
	.string "Una mossa MN può essere usata\n"
	.string "dai POKéMON fuori dalla lotta.\p"
	.string "Ogni POKéMON che ha imparato TAGLIO può\n"
	.string "tagliare gli alberelli se l'ALLENATORE\l"
	.string "ha ottenuto la MEDAGLIA PIETRA.\p"
	.string "E, a differenza di una MT, una MN si può\n"
	.string "usare più di una volta.$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.string "Quando ampliavano la città di\n"
	.string "RUSTBORO, mio papà ha dato una mano.\p"
	.string "Ha fatto usare TAGLIO ai suoi POKéMON\n"
	.string "per liberare il terreno dagli alberi.$"

