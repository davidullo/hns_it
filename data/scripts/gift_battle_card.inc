MysteryGiftScript_BattleCard::
	setvaddress MysteryGiftScript_BattleCard
	vgoto_if_set FLAG_MYSTERY_GIFT_DONE, MysteryGiftScript_BattleCardInfo
	setorcopyvar VAR_RESULT, GET_CARD_BATTLES_WON
	specialvar VAR_0x8008, GetMysteryGiftCardStat
	vgoto_if_ne VAR_0x8008, REQUIRED_CARD_BATTLES, MysteryGiftScript_BattleCardInfo
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard_WonPrize
	waitmessage
	waitbuttonpress
	giveitem ITEM_POTION
	release
	setflag FLAG_MYSTERY_GIFT_DONE
	end

MysteryGiftScript_BattleCardInfo:
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftBattleCountCard:
	.string "Grazie per aver usato il sistema\n"
	.string "REGALO SEGRETO.\p"
	.string "La CARTA SFIDE tiene traccia\n"
	.string "delle tue lotte contro gli\l"
	.string "ALLENATORI con la stessa CARTA.\p"
	.string "Cerca e sfida gli ALLENATORI che\n"
	.string "hanno la tua stessa CARTA.\p"
	.string "Puoi vedere la classifica\n"
	.string "leggendo le NOTIZIE.\p"
	.string "Prova, dai!$"

sText_MysteryGiftBattleCountCard_WonPrize:
	.string "Grazie per aver usato il sistema\n"
	.string "REGALO SEGRETO.\p"
	.string "Congratulazioni!\p"
	.string "Hai vinto un premio per aver vinto\n"
	.string "tre lotte!\p"
	.string "Speriamo che vorrai\n"
	.string "combattere ancora.$"
