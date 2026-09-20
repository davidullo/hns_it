RustboroCity_DevonCorp_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_1F_OnTransition
	.byte 0

RustboroCity_DevonCorp_1F_OnTransition:
	call_if_unset FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_BlockStairs
	end

RustboroCity_DevonCorp_1F_EventScript_BlockStairs::
	setobjectxyperm LOCALID_DEVON_CORP_STAIR_GUARD, 14, 2
	setobjectmovementtype LOCALID_DEVON_CORP_STAIR_GUARD, MOVEMENT_TYPE_FACE_DOWN
	return

RustboroCity_DevonCorp_1F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright
	msgbox RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright::
	msgbox RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered::
	msgbox RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StairGuard::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome::
	msgbox RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_Greeter::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp::
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_StaffGotRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RocksMetalDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_EventScript_ProductsDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_ProductDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp:
	.string "Ciao e benvenuto alla DEVON\n"
	.string "CORPORATION.\p"
	.string "Siamo orgogliosi produttori di oggetti e\n"
	.string "medicine che migliorano la tua vita.$"

RustboroCity_DevonCorp_1F_Text_StaffGotRobbed:
	.string "Un nostro ricercatore, stupidamente,\n"
	.string "si è fatto rubare un pacco importante.$"

RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct:
	.string "Ehi, quelle SCARPE DA GINNASTICA!\n"
	.string "Sono uno dei nostri prodotti!\p"
	.string "Sono felice quando vedo qualcuno\n"
	.string "usare ciò che produciamo.$"

RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright:
	.string "Quel pacco rubato…\p"
	.string "Beh, certo è importante, ma non è\n"
	.string "una cosa che possa usare chiunque.\p"
	.string "Secondo me, quel ladro non doveva\n"
	.string "essere molto brillante.$"

RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered:
	.string "Sembra che abbiano recuperato\n"
	.string "la MERCE DEVON rubata.$"

RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter:
	.string "Mi dispiace, solo le persone autorizzate\n"
	.string "possono entrare qui.$"

RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed:
	.string "È una stupidaggine assurda.\n"
	.string "Come hanno potuto derubarci?$"

RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere:
	.string "Ciao!\n"
	.string "Qui sei sempre il benvenuto!$"

RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay:
	.string "Campioni di rocce e metallo sono\n"
	.string "esposti nella vetrina di vetro.\p"
	.string "C'è un pannello con sopra\n"
	.string "qualcosa scritto…\p"
	.string "“La DEVON CORPORATION è nata come\n"
	.string "produttrice di pietre da cave.\p"
	.string "“L'azienda produceva anche ferro da\n"
	.string "limature nella sabbia.\p"
	.string "“Da quell'umile inizio come produttrice\n"
	.string "di materie prime, la DEVON si è evoluta.\p"
	.string "“Ora la DEVON produce una vasta\n"
	.string "gamma di prodotti industriali.”$"

RustboroCity_DevonCorp_1F_Text_ProductDisplay:
	.string "Prototipi e prodotti di prova riempiono\n"
	.string "la vetrina di cristallo.\p"
	.string "C'è un pannello con una descrizione…\p"
	.string "“Oltre ai prodotti industriali,\n"
	.string "la DEVON vende ora generi vari e\l"
	.string "farmaci per uno stile di vita migliore.\p"
	.string "“Da poco la DEVON produce anche\n"
	.string "strumenti per gli ALLENATORI, come\l"
	.string "POKé BALL e sistemi POKéNAV.”$"

