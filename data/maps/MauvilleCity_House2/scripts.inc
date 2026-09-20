MauvilleCity_House2_MapScripts::
	.byte 0

MauvilleCity_House2_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_COIN_CASE, MauvilleCity_House2_EventScript_ReceivedCoinCase
	msgbox MauvilleCity_House2_Text_BuyHarborMailAtSlateport, MSGBOX_DEFAULT
	checkitem ITEM_HARBOR_MAIL
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_House2_EventScript_AskToTradeForHarborMail
	release
	end

MauvilleCity_House2_EventScript_AskToTradeForHarborMail::
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_House2_Text_TradeHarborMailForCoinCase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_House2_EventScript_AcceptTrade
	goto_if_eq VAR_RESULT, NO, MauvilleCity_House2_EventScript_DeclineTrade
	end

MauvilleCity_House2_EventScript_AcceptTrade::
	msgbox MauvilleCity_House2_Text_IllTradeYouCoinCase, MSGBOX_DEFAULT
	giveitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeitem ITEM_HARBOR_MAIL
	setflag FLAG_RECEIVED_COIN_CASE
	goto MauvilleCity_House2_EventScript_ReceivedCoinCase
	end

MauvilleCity_House2_EventScript_ReceivedCoinCase::
	msgbox MauvilleCity_House2_Text_UseCoinCaseAtGameCorner, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_EventScript_DeclineTrade::
	msgbox MauvilleCity_House2_Text_ThatsDisappointing, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_Text_BuyHarborMailAtSlateport:
	.string "Con una BICICLETTA, andrei in un baleno a\n"
	.string "PORTOVECCHIO a fare compere.\p"
	.string "Potrei comprare la LETTERA PORTO al\n"
	.string "MART di PORTOVECCHIO…$"

MauvilleCity_House2_Text_TradeHarborMailForCoinCase:
	.string "Oh! Hai la LETTERA PORTO?\n"
	.string "La scambi con un PORTAGETTONI?$"

MauvilleCity_House2_Text_IllTradeYouCoinCase:
	.string "Oh, che felicità!\n"
	.string "Ok, ti do un PORTAGETTONI!$"

MauvilleCity_House2_Text_UseCoinCaseAtGameCorner:
	.string "Quel PORTAGETTONI si usa\n"
	.string "alla SALA GIOCHI.$"

MauvilleCity_House2_Text_ThatsDisappointing:
	.string "Oh, che delusione.\p"
	.string "Serve un PORTAGETTONI per la\n"
	.string "SALA GIOCHI.$"

