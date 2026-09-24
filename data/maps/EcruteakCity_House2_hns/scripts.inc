EcruteakCity_House2_hns_MapScripts::
	.byte 0

Ecruteak_Text_ItemfinderAdventure:
	.string "Ah. Sei in viaggio con\n"
	.string "i tuoi POKéMON?\p"
	.string "E che avventura è senza\n"
	.string "caccia al tesoro?\p"
	.string "Ho ragione o no?$"

Ecruteak_Text_ItemfinderTrueSpirit:
	.string "Bene! Hai capito il vero\n"
	.string "spirito d'avventura.\p"
	.string "Mi piace! Prendi questo.$"

Ecruteak_Text_ItemfinderExplanation:
	.string "Ci sono molti strumenti in giro\n"
	.string "che non si vedono.\p"
	.string "Usa RICERCAOGGETTI per vedere se\n"
	.string "c'è uno strumento vicino a te.\p"
	.string "Non mostra il punto esatto,\n"
	.string "quindi cerca tu da solo.\p"
	.string "Ah sì, ci sono degli oggetti nella\n"
	.string "TORRE ARSA di AMARANTOPOLI.$"

Ecruteak_Text_ItemfinderToEachHisOwn:
	.string "Oh… Ognuno ha i suoi gusti…$"

EcruteakCity_House2_EventScript_ItemFinderMan::
	lock
	faceplayer
	checkitem ITEM_DOWSING_MACHINE
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_AlreadyGotItemfinder
	msgbox Ecruteak_Text_ItemfinderAdventure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_GiveItemFinder
	msgbox Ecruteak_Text_ItemfinderToEachHisOwn, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_House2_EventScript_GiveItemFinder::
	msgbox Ecruteak_Text_ItemfinderTrueSpirit, MSGBOX_DEFAULT
	giveitem ITEM_DOWSING_MACHINE
EcruteakCity_House2_EventScript_AlreadyGotItemfinder::
	msgbox Ecruteak_Text_ItemfinderExplanation, MSGBOX_DEFAULT
	closemessage
	release
	end


EcruteakCity_House2_EventScript_Book::
	lock
	msgbox Ecruteak_Text_HistoryBook, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_Book2
	closemessage
	release
	end

EcruteakCity_House2_EventScript_Book2::
	msgbox Ecruteak_Text_TwoTowers, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_Book3
	release
	end

EcruteakCity_House2_EventScript_Book3::
	msgbox Ecruteak_Text_ThreeMon, MSGBOX_DEFAULT
	closemessage
	release
	end

Ecruteak_Text_ItemFinderMan::
	.string "AMARANTOPOLI è molto antica.\n"
	.string "Generazioni tramandano\l"
	.string "la loro storia in libri così.$"

Ecruteak_Text_HistoryBook:
	.string "STORIA DI AMARANTOPOLI\p"
	.string "Vuoi leggerlo?$"

Ecruteak_Text_TwoTowers:
	.string "Ad AMARANTOPOLI c'erano due torri.\p"
	.string "Ognuna era il trespolo di\n"
	.string "potenti POKéMON volanti.\p"
	.string "Ma una torre bruciò fino al\n"
	.string "suolo.\p"
	.string "I due POKéMON non si sono più\n"
	.string "visti…\p"
	.string "Continuo?$"

Ecruteak_Text_ThreeMon:
	.string "AMARANTOPOLI ospitava anche tre\n"
	.string "POKéMON che correvano in città.\p"
	.string "Si dice che siano nati\n"
	.string "da acqua, fulmini e fuoco.\p"
	.string "Ma non riuscivano a contenere\n"
	.string "il loro potere.\p"
	.string "Si dice che i tre corsero come il\n"
	.string "vento nella prateria.$"
