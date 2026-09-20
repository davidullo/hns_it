MauvilleCity_House1_MapScripts::
	.byte 0

MauvilleCity_House1_EventScript_RockSmashDude::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, MauvilleCity_House1_EventScript_ReceivedRockSmash
	msgbox MauvilleCity_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
	msgbox MauvilleCity_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_EventScript_ReceivedRockSmash::
	msgbox MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_Text_ImRockSmashDudeTakeThis:
	.string "Woohoo!\p"
	.string "Mi chiamano TIPO SPACCAROCCIA,\n"
	.string "ma lo trovo un po' sminuente.\p"
	.string "Merito più rispetto,\n"
	.string "chessò, il TIZIO SPACCAROCCIA.\p"
	.string "Woohoo!\p"
	.string "Comunque, i tuoi POKéMON sembrano\n"
	.string "forti.\p"
	.string "Mi piace!\n"
	.string "Tieni, prendi questa MACCHINA NASCOSTA!$"

MauvilleCity_House1_Text_ExplainRockSmash:
	.string "Quella MN contiene SPACCAROCCIA.\p"
	.string "Se trovi massi enormi\n"
	.string "che ti bloccano la strada…\p"
	.string "Beh, usa quella mossa MN e\n"
	.string "spaccali via!\p"
	.string "Sì, signore! Spacca i sassi!\n"
	.string "Woohoo!$"

MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock:
	.string "Ah, sì, se spacchi un sasso, un POKéMON\n"
	.string "può saltare fuori dal nascondiglio.\p"
	.string "Woohoo!$"

