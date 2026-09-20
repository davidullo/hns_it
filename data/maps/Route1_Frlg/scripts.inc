Route1_Frlg_MapScripts::
	.byte 0

Route1_EventScript_MartClerk::
	lock
	faceplayer
	goto_if_set FLAG_GOT_POTION_ON_ROUTE_1, Route1_EventScript_AlreadyGotPotion
	msgbox Route1_Text_WorkAtPokeMartTakeSample
	textcolor NPC_TEXT_COLOR_NEUTRAL
	checkitemspace ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	bufferitemname STR_VAR_2, ITEM_POTION
	playfanfare MUS_LEVEL_UP
	message gText_ObtainedTheItem
	waitmessage
	waitfanfare
	additem ITEM_POTION
	msgbox Route1_Text_PutPotionAway
	call EventScript_RestorePrevTextColor
	setflag FLAG_GOT_POTION_ON_ROUTE_1
	release
	end

Route1_EventScript_AlreadyGotPotion::
	msgbox Route1_Text_ComeSeeUsIfYouNeedPokeBalls
	release
	end

Route1_EventScript_Boy::
	msgbox Route1_Text_CanJumpFromLedges, MSGBOX_NPC
	end

Route1_EventScript_RouteSign::
	msgbox Route1_Text_RouteSign, MSGBOX_SIGN
	end

Route1_Text_WorkAtPokeMartTakeSample::
	.string "Ciao!\n"
	.string "Lavoro in un MART POKéMON.\p"
	.string "Fa parte di una catena\n"
	.string "che vende di tutto.\p"
	.string "Passa a trovarci a SMERALDOPOLI.\p"
	.string "Sai che c'è? Ti do un campione.\n"
	.string "Ecco qua!$"

Route1_Text_ComeSeeUsIfYouNeedPokeBalls::
	.string "Passa a trovarci se ti servono\n"
	.string "POKé BALL per catturare POKéMON.$"

Route1_Text_PutPotionAway::
	.string "{PLAYER} mette la POZIONE\n"
	.string "nella TASCA STRUMENTI.$"

Route1_Text_CanJumpFromLedges::
	.string "Vedi quei dirupi lungo la strada?\p"
	.string "Fa un po' paura, ma puoi\n"
	.string "saltarci giù.\p"
	.string "Così torni a BIANCAVILLA\n"
	.string "più in fretta.$"

Route1_Text_RouteSign::
	.string "PERCORSO 1\n"
	.string "BIANCAVILLA - SMERALDOPOLI$"

