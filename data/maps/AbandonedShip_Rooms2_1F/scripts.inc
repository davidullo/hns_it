AbandonedShip_Rooms2_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms2_1F_EventScript_Dan::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanIntro, AbandonedShip_Rooms2_1F_Text_DanDefeat, AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterDan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_DanRematch
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterDan::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT  @ Kira speaks for both when registering KiraAndDan
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_DanRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanRematchIntro, AbandonedShip_Rooms2_1F_Text_DanRematchDefeat, AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Kira::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraIntro, AbandonedShip_Rooms2_1F_Text_KiraDefeat, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterKira
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_KiraRematch
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterKira::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_KiraRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraRematchIntro, AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat, AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Jani::
	trainerbattle_single TRAINER_JANI, AbandonedShip_Rooms2_1F_Text_JaniIntro, AbandonedShip_Rooms2_1F_Text_JaniDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_JaniPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Garrison::
	trainerbattle_single TRAINER_GARRISON, AbandonedShip_Rooms2_1F_Text_GarrisonIntro, AbandonedShip_Rooms2_1F_Text_GarrisonDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_Text_DanIntro:
	.string "DAN: Cercando tesori, abbiamo\n"
	.string "trovato un ALLENATORE!$"

AbandonedShip_Rooms2_1F_Text_DanDefeat:
	.string "DAN: Abbiamo perso anche se\n"
	.string "combattevamo insieme…$"

AbandonedShip_Rooms2_1F_Text_DanPostBattle:
	.string "DAN: Non troviamo tesori…\n"
	.string "Chissà se li ha presi qualcuno.$"

AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons:
	.string "DAN: Hai meno di due POKéMON.\n"
	.string "Così non puoi batterci.$"

AbandonedShip_Rooms2_1F_Text_KiraIntro:
	.string "KIRA: Oh?\n"
	.string "Cercavamo tesori.\l"
	.string "Ma abbiamo trovato un ALLENATORE!$"

AbandonedShip_Rooms2_1F_Text_KiraDefeat:
	.string "KIRA: Oh, ma che forte!$"

AbandonedShip_Rooms2_1F_Text_KiraPostBattle:
	.string "KIRA: Dove saranno i tesori?\p"
	.string "Ho già deciso cosa comprerò\n"
	.string "quando troveremo i tesori!$"

AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons:
	.string "KIRA: Oh, non hai due POKéMON?\n"
	.string "Lotteremo un'altra volta!$"

AbandonedShip_Rooms2_1F_Text_KiraRegister:
	.string "KIRA: Oh, mi fai arrabbiare!\n"
	.string "Ti sfido di nuovo per questo!$"

AbandonedShip_Rooms2_1F_Text_DanRematchIntro:
	.string "DAN: Cerchiamo tesori\n"
	.string "da un pezzo ormai.\p"
	.string "I nostri POKéMON sono più forti.\n"
	.string "Fallo vedere, dai!$"

AbandonedShip_Rooms2_1F_Text_DanRematchDefeat:
	.string "DAN: Sei forte come sempre!$"

AbandonedShip_Rooms2_1F_Text_DanPostRematch:
	.string "DAN: Non troviamo tesori,\n"
	.string "perdiamo pure…\p"
	.string "Voglio andare a casa… Ma se lo dico,\n"
	.string "lei si arrabbia…$"

AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons:
	.string "DAN: Hai meno di due POKéMON.\n"
	.string "Così non puoi batterci.$"

AbandonedShip_Rooms2_1F_Text_KiraRematchIntro:
	.string "KIRA: Oh? Ci rincontriamo!\p"
	.string "Anche tu non hai smesso di\n"
	.string "cercare tesori, vero?\p"
	.string "Facciamo che chi perde\n"
	.string "smette di cercare?$"

AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat:
	.string "KIRA: Oh, abbiamo perso di nuovo…$"

AbandonedShip_Rooms2_1F_Text_KiraPostRematch:
	.string "KIRA: Non ce ne andiamo finché\n"
	.string "non alleniamo i POKéMON e\l"
	.string "troviamo i tesori!$"

AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons:
	.string "KIRA: Oh, non hai due POKéMON?\n"
	.string "Lotteremo un'altra volta!$"

AbandonedShip_Rooms2_1F_Text_JaniIntro:
	.string "Nuoto non sono bravo,\n"
	.string "ma alle lotte sì!$"

AbandonedShip_Rooms2_1F_Text_JaniDefeat:
	.string "Uffa.\n"
	.string "Non è andata per niente bene.$"

AbandonedShip_Rooms2_1F_Text_JaniPostBattle:
	.string "Girare a piedi nudi su questa nave\n"
	.string "è un po' schifoso.$"

AbandonedShip_Rooms2_1F_Text_GarrisonIntro:
	.string "Forza e cuore…\n"
	.string "Sono i tesori di un ALLENATORE!$"

AbandonedShip_Rooms2_1F_Text_GarrisonDefeat:
	.string "Ah, in te c'è qualcosa\n"
	.string "che brilla.$"

AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle:
	.string "In una cabina di bordo\n"
	.string "ho visto qualcosa che brilla.$"
