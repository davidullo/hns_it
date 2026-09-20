GoldenrodCity_BikeShop_hns_MapScripts::
	.byte 0

GoldenrodCity_BikeShop_EventScript_Clerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, GoldenrodCity_BikeShop_EventScript_Clerk_BikeReceived
	msgbox GoldenrodCity_BikeShop_Text_ClerkIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_BikeShop_EventScript_Clerk_BikeAgreed
	msgbox GoldenrodCity_BikeShop_Text_Refused, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk_BikeAgreed::
	msgbox GoldenrodCity_BikeShop_Text_ClerkAgreed, MSGBOX_DEFAULT
	giveitem ITEM_BICYCLE
	setflag FLAG_RECEIVED_BIKE
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk_BikeReceived::
	msgbox GoldenrodCity_BikeShop_Text_Mainshop, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk2::
	lock
	faceplayer
	msgbox GoldenrodCity_BikeShop_Text_Clerk2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Bike::
	lock
	msgbox GoldenrodCity_BikeShop_Text_Bicycle, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_Text_Clerk2:
	.string "Riding the BIKE is as simple as\n"
	.string "pressing a button if you\l"
	.string "REGISTER it from the BAG.\p"
	.string "If you need to go faster,\n"
	.string "you first need to come to a stop!\p"
	.string "That might seem like strange\n"
	.string "advice, but you can only change\l"
	.string "gears on the BIKE while stopped.\p"
	.string "Press your R button when stopped\n"
	.string "and the next time you pedal,\l"
	.string "you will reach greater speeds!$"

GoldenrodCity_BikeShop_Text_ClerkIntro:
    .string "…sigh… Mi sono trasferito, ma non\n"
    .string "vendo BICICLETTE. Perché?\p"
    .string "Potresti andare in BICICLETTA e\n"
    .string "farmi pubblicità?$"

GoldenrodCity_BikeShop_Text_ClerkAgreed:
    .string "Davvero? Ottimo!\p"
    .string "Dammi nome e numero di telefono,\n"
    .string "e ti presto una BICICLETTA.$"

GoldenrodCity_BikeShop_Text_BorrowedBicycle:
    .string "{PLAYER} prende in prestito una BICICLETTA.$"

GoldenrodCity_BikeShop_Text_Mainshop:
	.string "Gli affari vanno male\n"
	.string "da quando ci siamo spostati da KANTO.\l"
	.string "Grazie per l'aiuto!\p"
	.string "Puoi mostrare in giro\n"
	.string "la nostra tecnologia brevettata?\p"
	.string "Basta premere R quando\n"
	.string "sei fermo sulla BICICLETTA.\p"
	.string "Attenzione! Andrai più veloce!$"

GoldenrodCity_BikeShop_Text_Refused:
    .string "…sigh… Ah, la gentilezza\n"
    .string "della gente…$"

GoldenrodCity_BikeShop_Text_JustReleasedCompact:
    .string "Appena uscite!\p"
    .string "BICICLETTE compatte di prima scelta!$"

GoldenrodCity_BikeShop_Text_Bicycle:
    .string "È una BICICLETTA nuova!$"
