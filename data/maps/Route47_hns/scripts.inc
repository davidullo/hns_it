Route47_hns_MapScripts::
	.byte 0


Route47_EventScript_Hiker::
	trainerbattle_single TRAINER_DEVIN_HNS, Route47_Text_HikerSeen, Route47_Text_HikerBeaten
	msgbox Route47_Text_HikerAfter, MSGBOX_AUTOCLOSE
	end

Route47_Text_HikerSeen::
	.string "Desiderare gli altri è...\n"
	.string "così. \p"
	.string "Ma le lotte son lotte,\n"
	.string "quindi andiamo!$"

Route47_Text_HikerBeaten::
	.string "Ahahah!$"

Route47_Text_HikerAfter::
	.string "Dopo una lotta bisogna sempre\n"
	.string "congedarsi con una risata!$"

Route47_EventScript_Camper::
	trainerbattle_single TRAINER_GRANT_HNS, Route47_Text_CamperSeen, Route47_Text_CamperBeaten
	msgbox Route47_Text_CamperAfter, MSGBOX_AUTOCLOSE
	end

Route47_Text_CamperSeen::
	.string "Non amo la folla, quindi\n"
	.string "mi accampo qui con i\l"
	.string "miei POKéMON!$"

Route47_Text_CamperBeaten::
	.string "Credo che andrò più in fondo\n"
	.string "nella montagna…$"

Route47_Text_CamperAfter::
	.string "Ci vediamo!$"

Route47_EventScript_Thom::
	trainerbattle_double TRAINER_THOM_AND_KAE_HNS, Route47_Text_Couple1Seen, Route47_Text_Couple1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple1After1, MSGBOX_AUTOCLOSE
	end

Route47_EventScript_Kae::
	trainerbattle_double TRAINER_THOM_AND_KAE_HNS, Route47_Text_Couple1Seen, Route47_Text_Couple1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple1After2, MSGBOX_AUTOCLOSE
	end

Route47_Text_Couple1Seen::
	.string "THOM: Uno più uno fa due. Ma noi\n"
	.string "due insieme siamo molto\l"
	.string "più forti!\p"
	.string "KAE: Noi due non siamo una\n"
	.string "coppia noiosa!$"

Route47_Text_Couple1Beaten::
	.string "THOM: Non me l'aspettavo.\l"
	.string "KAE: Sei fuori dal comune anche tu!$"

Route47_Text_Couple1After1::
	.string "THOM: Sembra che la tua forza sia\n"
	.string "impossibile da prevedere!$"

Route47_Text_Couple1After2::
	.string "KAE: Pensavo fossi un normale\n"
	.string "allenatore solitario. Mi sbagliavo!$"

Route47_EventScript_Duff::
	trainerbattle_double TRAINER_DUFF_AND_EDA_HNS, Route47_Text_Couple2Seen, Route47_Text_Couple2Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple2After1, MSGBOX_AUTOCLOSE
	end

Route47_EventScript_Eda::
	trainerbattle_double TRAINER_DUFF_AND_EDA_HNS, Route47_Text_Couple2Seen, Route47_Text_Couple2Beaten, Route104_Text_GinaNotEnoughMons
	msgbox Route47_Text_Couple2After2, MSGBOX_AUTOCLOSE
	end

Route47_Text_Couple2Seen::
	.string "DUFF: Guardare la mia ragazza\n"
	.string "mi fa volare il cuore!\p"
	.string "EDA: I miei sentimenti per il mio\n"
	.string "ragazzo sono ampi e profondi\l"
	.string "come l'oceano!$"

Route47_Text_Couple2Beaten::
	.string "DUFF: Non ero alla tua altezza...\l"
	.string "EDA: Sei davvero forte...$"

Route47_Text_Couple2After1::
	.string "DUFF: Grazie per la lotta\n"
	.string "fantastica! Ciao!$"

Route47_Text_Couple2After2::
	.string "EDA: Dovresti trovarti anche tu\n"
	.string "un partner fantastico!$"

Route47_EventScript_Sage::
	lock
	faceplayer
	msgbox EmbeddedTower_Text_OldManIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

EmbeddedTower_Text_OldManIntro:
	.string "Well, hello!\p"
	.string "It's said that past this hole used to\n"
	.string "be a huge tower reaching far into\l"
	.string "the sky.\p"
	.string "They say that it was a rather strange\n"
	.string "tower with half of it embedded\l"
	.string "in the cliff.\p"
	.string "It was not just a tall tower reaching\n"
	.string "up to the sky, but also reaching deep\l"
	.string "down underground!\p"
	.string "It is rumored that it even reached\n"
	.string "the bottom of the ocean!\p"
	.string "In short, the ruins used to connect\n"
	.string "the sky, the land, and the sea to\l"
	.string "each other...\p"
	.string "Most of the tower is now crumbled,\n"
	.string "and the only things that remain are\l"
	.string "the entrance and its interior, where\l"
	.string "you'll see strange patterns.$"

Route47_EventScript_Item_Pearl::
    finditem ITEM_PEARL
    end

Route47_EventScript_Item_Revive::
    finditem ITEM_REVIVE
    end

Route47_EventScript_Item_WhiteFlute::
    finditem ITEM_WHITE_FLUTE
    end

Route47_EventScript_Item_Stardust::
	finditem ITEM_STARDUST
	end

Route47_EventScript_Item_LuckyPunch::
	finditem ITEM_LUCKY_PUNCH
	end

Route47_EventScript_Chinchou::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHINCHOU, CRY_MODE_NORMAL
	msgbox Route47_Text_Chinchou, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route47_Text_Chinchou:
	.string "CHINCHOU: Chou!$"
