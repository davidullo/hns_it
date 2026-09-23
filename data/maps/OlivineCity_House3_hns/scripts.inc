OlivineCity_House3_hns_MapScripts::
	.byte 0

OlivineCityHouse3_EventScriptFishingGuru::
	lock
	faceplayer
	checkitem ITEM_GOOD_ROD
	goto_if_eq VAR_RESULT, TRUE, OlivineCityHouse3_EventScriptFishingGuru2
	msgbox OlivineCity_Text_OfferGoodRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, OlivineCityHouse3_EventScriptFishingGuruRefused
	msgbox OlivineCity_Text_GiveGoodRod, MSGBOX_DEFAULT
	giveitem ITEM_GOOD_ROD
	msgbox OlivineCity_Text_GaveGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCityHouse3_EventScriptFishingGuru2::
	msgbox OlivineCity_Text_HaveGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCityHouse3_EventScriptFishingGuruRefused::
	msgbox OlivineCity_Text_DontWantGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_OfferGoodRod:
	.string "OLIVINOPOLI è sul mare!\p"
	.string "E se è sul mare, ci saranno\n"
	.string "di certo dei pesci!\p"
	.string "Pesco qui da 30 anni.\p"
	.string "Vuoi provare a pescare\n"
	.string "dando le spalle al mare?$"

OlivineCity_Text_GiveGoodRod:
	.string "Ah, ahah! Ecco un nuovo\n"
	.string "pescatore in erba!$"

OlivineCity_Text_GaveGoodRod:
	.string "I pesci non stanno solo nel\n"
	.string "mare, sono ovunque ci sia\l"
	.string "acqua.\p"
	.string "A proposito, il POKéDEX mostra\n"
	.string "i gruppi di pesca dei POKéMON.\p"
	.string "Posti diversi possono avere\n"
	.string "pesci simili.$"

OlivineCity_Text_DontWantGoodRod:
	.string "Cosa?! Non ti piace pescare!?\n"
	.string "Incomprensibile!$"

OlivineCity_Text_HaveGoodRod:
	.string "Come va?\n"
	.string "Hai preso il pesce grosso?$"
