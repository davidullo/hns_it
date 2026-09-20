Akala_Forest_hns_MapScripts::
	.byte 0


Alola_Akala_Forest_FindItem1::
	finditem ITEM_FULL_RESTORE, 1
	end


Alola_Akala_Forest_FindItem2::
	finditem ITEM_PP_UP, 1
	end


Alola_AkalaForest_TrainerBattleBugCatcher1::
	trainerbattle_single TRAINER_AKALA_FOREST_BUGCATCHER_1_HNS, Alola_AkalaForest_TrainerBattleBugCatcher1_Text_0, Alola_AkalaForest_TrainerBattleBugCatcher1_Text_1
	msgbox Alola_AkalaForest_TrainerBattleBugCatcher1_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Alola_AkalaForest_TrainerBattleBugCatcher2::
	trainerbattle_single TRAINER_AKALA_FOREST_BUGCATCHER_2_HNS, Alola_AkalaForest_TrainerBattleBugCatcher2_Text_0, Alola_AkalaForest_TrainerBattleBugCatcher2_Text_1
	msgbox Alola_AkalaForest_TrainerBattleBugCatcher2_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Alola_Akala_BattleRaichu::
	lock
	faceplayer
	setflag FLAG_BATTLED_RAICHU
	playmoncry SPECIES_RAICHU_ALOLA, 0
	msgbox Alola_Akala_BattleRaichu_Text_0, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_RAICHU_ALOLA, 60
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Alola_Akala_BattleRaichu_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Alola_Akala_BattleRaichu_3
	release
	end

	release
	end

Alola_Akala_BattleRaichu_2:
	setflag FLAG_HIDE_RAICHU_ALOLA
	removeobject LOCALID_AKALA_RAICHU
	release
	end

Alola_Akala_BattleRaichu_3:
	setflag FLAG_HIDE_RAICHU_ALOLA
	removeobject LOCALID_AKALA_RAICHU
	release
	end


Alola_AkalaForest_TrainerBattleBugCatcher1_Text_0:
	.string "Guarda quanti COLEOTTERI\nrestelli qui!$"

Alola_AkalaForest_TrainerBattleBugCatcher1_Text_1:
	.string "Ahi, che bruciore!$"

Alola_AkalaForest_TrainerBattleBugCatcher1_Text_2:
	.string "Le ISOLE sono lontane da terra,\n"
	.string "quindi i POKéMON COLEOTTERO qui si\l"
	.string "sono adattati all'ambiente.$"

Alola_AkalaForest_TrainerBattleBugCatcher2_Text_0:
	.string "Guarda che cosa ho preso!$"

Alola_AkalaForest_TrainerBattleBugCatcher2_Text_1:
	.string "Ahi, che morso!$"

Alola_AkalaForest_TrainerBattleBugCatcher2_Text_2:
	.string "Il clima è un po' diverso alle\n"
	.string "ISOLE DI ALOLA…\p"
	.string "Ecco perché qui ci sono\n"
	.string "POKéMON COLEOTTERO unici.$"


Alola_Akala_BattleRaichu_Text_0:
	.string "Aaah!$"

