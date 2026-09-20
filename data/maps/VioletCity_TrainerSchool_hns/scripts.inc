VioletCity_TrainerSchool_hns_MapScripts::
	.byte 0

VioletCity_TrainerSchool_EventScript_Earl::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_EarlIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Teacher::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Boy1::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_GameboyKid1, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Boy2::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_GameboyKid2, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Kid::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_Youngster1, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Girl::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_Youngster2, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Twin::
	msgbox VioletCity_TrainerSchool_Text_Twin, MSGBOX_NPC
	end

VioletCity_TrainerSchool_EventScript_BlackBoard::
	lock
	msgbox VioletCity_TrainerSchool_Text_Blackboard, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_Text_Twin:
	.string "Non ho il GBA, ma adoro\n"
	.string "giocare ai POKéMON!\p"
	.string "Nei vecchi giochi dovevi lottare\n"
	.string "contro molti POKéMON selvatici\l"
	.string "per l'ESP.\p"
	.string "Ma nei giochi nuovi la CONDIV. ESP.\n"
	.string "fa salire i livelli troppo in fretta.\p"
	.string "Qui la CONDIV. ESP. è\n"
	.string "bilanciata per darti il livello\l"
	.string "giusto. O poco più,\l"
	.string "a seconda di quante lotte fai.\p"
	.string "Se vuoi un'esperienza classica\n"
	.string "GEN 1-4, disattiva la CONDIV. ESP.\l"
	.string "Se vuoi un'esperienza moderna,\l"
	.string "attiva la CONDIV. ESP.\p"
	.string "Scegli tu come giocare!$"

VioletCity_TrainerSchool_Text_EarlIntro:
	.string "EARL, io sono!\p"
	.string "Meravigliosi sono i POKéMON, sì!\p"
	.string "Insegnare a te io farò come essere\n"
	.string "un allenatore migliore!$"

VioletCity_TrainerSchool_Text_Teacher:
	.string "Alcuni POKéMON partono deboli e\n"
	.string "richiedono molta più ESP per\l"
	.string "diventare forti degli altri.\p"
	.string "Per esempio, LARVITAR è debole\n"
	.string "ma diventerà alla fine un\l"
	.string "potente TYRANITAR, al costo di\l"
	.string "molta ESP.\p"
	.string "Solo gli allenatori più dediti\n"
	.string "dovrebbero provare ad allenare\l"
	.string "un simile POKéMON.$"

VioletCity_TrainerSchool_Text_TeachHowToWin:
	.string "Bene! Insegnare a te, io farò!\p"
	.string "In lotta, il POKéMON in cima alla\n"
	.string "lista entra per primo!\p"
	.string "Cambia l'ordine in lista, rendi\n"
	.string "la lotta facile, forse!\p"
	.string "Vuoi sentire altro da me?$"

VioletCity_TrainerSchool_Text_TeachMore:
	.string "Allora, vuoi sapere come allenare\n"
	.string "bene i POKéMON?$"

VioletCity_TrainerSchool_Text_TeachRaiseWell:
	.string "Bene! Insegnare a te, io farò!\p"
	.string "Se un POKéMON entra in lotta\n"
	.string "anche per poco, dei Punti ESP.\p"
	.string "riceve.\n"
	.string "Metti in cima i POKéMON deboli\p"
	.string "e cambiali in fretta in lotta!\n"
	.string "Così, i POKéMON deboli forti\p"
	.string "diventano!$"

VioletCity_TrainerSchool_Text_NoMoreToTeach:
	.string "Oh! Bravo studente tu sei!\n"
	.string "Nulla più io insegno!\p"
	.string "Se vuoi sapere altro, parla\n"
	.string "agli alunni!$"

VioletCity_TrainerSchool_Text_Youngster1:
	.string "I POKéMON che si credeva\n"
	.string "si evolvessero solo con lo scambio\p"
	.string "ora si evolvono salendo di livello.\n"
	.string "MACHOKE e GRAVELER si evolvono\p"
	.string "al LIV 38, KADABRA e\n"
	.string "HAUNTER al LIV 42.\p"
	.string "Alcuni oggetti, come il\n"
	.string "METALCOAT, sono stati trovati\p"
	.string "capaci di evolvere certi POKéMON\n"
	.string "se tenuti salendo di livello.$"

VioletCity_TrainerSchool_Text_GameboyKid1:
	.string "I POKéMON notevoli di una zona si\n"
	.string "vedono nella mappa del mondo!\p"
	.string "Ma controlla i percorsi\n"
	.string "di GIORNO e di NOTTE!$"

VioletCity_TrainerSchool_Text_GameboyKid2:
	.string "Le BACche di JOHTO sono\n"
	.string "buone per curarsi e fare BALL.\p"
	.string "Le BACche di KANTO riducono\n"
	.string "le statistiche dei POKéMON.\p"
	.string "Il DOJO di KANTO aiuta i POKéMON\n"
	.string "a perfezionare le stat singole.$"

VioletCity_TrainerSchool_Text_Youngster2:
	.string "Sappi che gli avversari\n"
	.string "ora usano squadre con miglior\l"
	.string "copertura di tipi, quindi aspettati\l"
	.string "un viaggio molto più impegnativo.$"

VioletCity_TrainerSchool_Text_Blackboard:
	.string "La lavagna descrive\n"
	.string "le mosse MN dei POKéMON.\p"
	.string "Le MN, una volta sbloccate, non\n"
	.string "vanno insegnate per usarle.$"

VioletCity_TrainerSchool_Text_Notebook:
	.string "È il quaderno di quel bimbo…\p"
	.string "Cattura POKéMON con le POKé BALL.\p"
	.string "Fino a sei nella squadra.\p"
	.string "Continuare a leggere?$"

VioletCity_TrainerSchool_Text_Notebook1:
	.string "Prima di lanciare una POKé BALL,\n"
	.string "indebolisci il bersaglio.\p"
	.string "Un POKéMON avvelenato o scottato\n"
	.string "si cattura più facilmente.\p"
	.string "Continuare a leggere?$"

VioletCity_TrainerSchool_Text_Notebook2:
	.string "Alcune mosse causano confusione.\p"
	.string "La confusione può far sì che un\n"
	.string "POKéMON si colpisca da solo.\p"
	.string "Uscire dalla lotta toglie ogni\n"
	.string "confusione.\p"
	.string "Continuare a leggere?$"

VioletCity_TrainerSchool_Text_Notebook3:
	.string "Chi cattura e usa i POKéMON\n"
	.string "in lotta è un allenatore di\n"
	.string "POKéMON.\p"
	.string "Ci si aspetta che visiti le\n"
	.string "PALESTRE POKéMON e batta altri\n"
	.string "allenatori.\p"
	.string "La pagina dopo è… Vuota!\p"
	.string "Bimbo: E-e-e…\p"
	.string "Non ho scritto altro…$"

VioletCity_TrainerSchool_Text_StickerMachine:
	.string "Questa super macchina stampa i dati\n"
	.string "sotto forma di adesivi!$"
