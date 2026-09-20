MtPyre_1F_MapScripts::
	.byte 0

MtPyre_1F_EventScript_CleanseTagWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_ReceivedCleanseTag
	msgbox MtPyre_1F_Text_TakeThisForYourOwnGood, MSGBOX_DEFAULT
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CLEANSE_TAG
	release
	end

MtPyre_1F_EventScript_ReceivedCleanseTag::
	msgbox MtPyre_1F_Text_ExplainCleanseTag, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_EventScript_PokefanF::
	msgbox MtPyre_1F_Text_ComeToPayRespects, MSGBOX_NPC
	end

MtPyre_1F_EventScript_Man::
	msgbox MtPyre_1F_Text_RestingPlaceOfZigzagoon, MSGBOX_NPC
	end

MtPyre_1F_Text_TakeThisForYourOwnGood:
	.string "Ogni sorta di esseri vaga sui pendii\n"
	.string "del MT. PYRE…\p"
	.string "Non si sa mai cosa può succedere.\n"
	.string "Prendi questo. È per il tuo bene.$"

MtPyre_1F_Text_ExplainCleanseTag:
	.string "Fai tenere a un POKéMON la\n"
	.string "MEDAGLIA PURA.\p"
	.string "Aiuterà a scacciare i POKéMON selvatici.$"

MtPyre_1F_Text_ComeToPayRespects:
	.string "Sei venuto a rendere omaggio\n"
	.string "agli spiriti dei POKéMON defunti?\p"
	.string "Tieni molto ai tuoi POKéMON, vero.$"

MtPyre_1F_Text_RestingPlaceOfZigzagoon:
	.string "Qui riposa il mio ZIGZAGOON.\n"
	.string "Gli volevo bene…$"

