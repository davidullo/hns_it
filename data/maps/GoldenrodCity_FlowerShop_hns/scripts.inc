GoldenrodCity_FlowerShop_hns_MapScripts::
	.byte 0


GoldenrodCity_FlowerShop_EventScript_MintClerk::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE03_GET, GoldenrodCity_FlowerShop_EventScript_MintClerkNotReady
	message gText_HowMayIServeYou
	waitmessage
	pokemart GoldenrodCity_FlowerShop_Mints
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_FlowerShop_EventScript_MintClerkNotReady::
	msgbox GoldenrodCity_FlowerShop_Text_MintClerkNotReady, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_Text_MintClerkNotReady:
	.string "Al momento siamo esauriti.\p"
	.string "Torna piu' tardi.$"

	.align 2
GoldenrodCity_FlowerShop_Mints:
	.2byte ITEM_SERIOUS_MINT
	.2byte ITEM_ADAMANT_MINT
	.2byte ITEM_BOLD_MINT
	.2byte ITEM_BRAVE_MINT
	.2byte ITEM_CALM_MINT
	.2byte ITEM_CAREFUL_MINT
	.2byte ITEM_GENTLE_MINT
	.2byte ITEM_HASTY_MINT
	.2byte ITEM_IMPISH_MINT
	.2byte ITEM_JOLLY_MINT
	.2byte ITEM_LAX_MINT
	.2byte ITEM_LONELY_MINT
	.2byte ITEM_MILD_MINT
	.2byte ITEM_MODEST_MINT
	.2byte ITEM_NAIVE_MINT
	.2byte ITEM_NAUGHTY_MINT
	.2byte ITEM_QUIET_MINT
	.2byte ITEM_RASH_MINT
	.2byte ITEM_RELAXED_MINT
	.2byte ITEM_SASSY_MINT
	.2byte ITEM_TIMID_MINT
	pokemartlistend


GoldenrodCity_FlowerShop_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, GoldenrodCity_FlowerShop_EventScript_Normal
	goto_if_set FLAG_RECEIVED_SQUIRTBOTTLE, GoldenrodCity_FlowerShop_EventScript_GotSquirtBottle
	goto_if_set FLAG_BADGE03_GET, GoldenrodCity_FlowerShop_EventScript_GiveSquirtBottle
	msgbox GoldenrodCity_FlowerShop_Text_Owner1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_GiveSquirtBottle::
	lock
	faceplayer
	msgbox GoldenrodCity_FlowerShop_Text_Owner2, MSGBOX_DEFAULT
	giveitem ITEM_SQUIRT_BOTTLE
	setflag FLAG_RECEIVED_SQUIRTBOTTLE
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_GotSquirtBottle::
	lock
	faceplayer
	msgbox GoldenrodCity_FlowerShop_Text_Owner3, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_Normal::
	lock
	faceplayer
	msgbox GoldenrodCity_FlowerShop_Text_Owner4, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_Floria1::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, GoldenrodCity_FlowerShop_EventScript_Floria3
	goto_if_set FLAG_BADGE03_GET, GoldenrodCity_FlowerShop_EventScript_Floria2
	msgbox GoldenrodCity_FlowerShop_Text_Floria, MSGBOX_DEFAULT
	closemessage
	release
	end
	
GoldenrodCity_FlowerShop_EventScript_Floria2::
	msgbox GoldenrodCity_FlowerShop_Text_FloriaYouBeatWhitney, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_Floria3::
	msgbox GoldenrodCity_FlowerShop_Text_FloriaItWasAMon, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_Text_Floria:
	.string "Quando ho detto a mia sorella\n"
	.string "dell'albero, ha detto che e' pericoloso.\p"
	.string "Se batto CHIARA, chissa' se\n"
	.string "mi presta la bottiglia d'acqua…$"

GoldenrodCity_FlowerShop_Text_Owner1:
.string "Pare ci sia un albero strano\n"
.string "PERCORSO 36.\p"
.string "Dicono che balli se lo innaffi\n"
.string "...\p"
.string "Oh, ma no!\p"
.string "Qui è un negozio di fiori, e\n"
.string "sì, annaffiatoi...\p"
.string "Ma non posso dartene uno!\n"
.string "È pericoloso!\p"
.string "Beh, forse se riesci a\n"
.string "battere CHIARA, forse\l"
.string "va bene.$"

GoldenrodCity_FlowerShop_Text_Owner2:
.string "Pare ci sia un albero strano\n"
.string "sul PERCORSO 36.\p"
.string "Dicono che balli se lo innaffi\n"
.string "...\p"
.string "Oh, è una MEDAGLIA PIANA\n"
.string "PALESTRA di FIORDOROPOLI!\p"
.string "Hai battuto CHIARA?!\p"
.string "Beh, allora non c'è da\n"
.string "preoccuparsi, no?\p"
.string "Ti presto questa\n"
.string "SQUIRTBOTTLE per un po'.\l"
.string "...\p"
.string "Oh, lascia perdere. Tienila!$"

GoldenrodCity_FlowerShop_Text_Owner3:
.string "L'albero strano e' sul PERCORSO 36.\n"
.string "Fai attenzione!$"

GoldenrodCity_FlowerShop_Text_Owner4:
    .string "Lalala lalalala. Bevi molta\n"
    .string "acqua, tesoro!$"

GoldenrodCity_FlowerShop_Text_FloriaYouBeatWhitney:
    .string "Wow, hai battuto CHIARA? Che forte!$"

GoldenrodCity_FlowerShop_Text_FloriaItWasAMon:
    .string "Quindi era davvero un POKéMON!$"


GoldenrodCity_FlowerShop_EventScript_RandomBerryGirl::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY_HNS, GoldenrodCity_FlowerShop_EventScript_AlreadyReceivedBerry
	msgbox Route104_PrettyPetalFlowerShop_Text_ImGrowingFlowers, MSGBOX_DEFAULT
	random 8
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY_HNS
	msgbox Route104_PrettyPetalFlowerShop_Text_MachineMixesBerries, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_FlowerShop_EventScript_AlreadyReceivedBerry::
	msgbox Route104_PrettyPetalFlowerShop_Text_MachineMixesBerries, MSGBOX_DEFAULT
	release
	end

