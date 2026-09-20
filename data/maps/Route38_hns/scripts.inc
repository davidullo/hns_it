Route38_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route38_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route38_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route38_EventScript_Toby::
	trainerbattle_single TRAINER_TOBY_HNS, Route38_Text_BirdKeeperTobySeen, Route38_Text_BirdKeeperTobyBeaten
	msgbox Route38_Text_BirdKeeperTobyAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Chad::
	trainerbattle_single TRAINER_CHAD_HNS, Route38_Text_SchoolboyChad1Seen, Route38_Text_SchoolboyChad1Beaten, Route38_EventScript_RegisterChad
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route38_EventScript_RematchChad
	msgbox Route38_Text_SchoolboyChadAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_RegisterChad::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route38_Text_ChadRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CHAD_HNS
	release
	end

Route38_EventScript_RematchChad::
	trainerbattle_rematch TRAINER_CHAD_HNS, Route38_Text_ChadRematchIntro, Route38_Text_ChadRematchDefeat
	msgbox Route38_Text_ChadPostRematch, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Dana::
	trainerbattle_single TRAINER_DANA_HNS, Route38_Text_LassDana1Seen, Route38_Text_LassDana1Beaten, Route38_EventScript_RegisterDana
	goto_if_set FLAG_DANA_HAS_ITEM_HNS, Route38_EventScript_DanaGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route38_EventScript_RematchDana
	msgbox Route38_Text_LassDanaAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_RegisterDana::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route38_Text_DanaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DANA_HNS
	release
	end

Route38_EventScript_RematchDana::
	trainerbattle_rematch TRAINER_DANA_HNS, Route38_Text_DanaRematchIntro, Route38_Text_DanaRematchDefeat
	msgbox Route38_Text_DanaPostRematch, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_DanaGiveItem::
	msgbox Route38_Text_DanaHasItem, MSGBOX_DEFAULT
	giveitem VAR_DANA_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route38_EventScript_DanaNoRoom
	clearflag FLAG_DANA_HAS_ITEM_HNS
	msgbox Route38_Text_DanaGaveItem, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_DanaNoRoom::
	msgbox Route38_Text_DanaNoRoom, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE_HNS, Route38_Text_BeautyValerieSeen, Route38_Text_BeautyValerieBeaten
	msgbox Route38_Text_BeautyValerieAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Harry::
	trainerbattle_single TRAINER_HARRY_HNS, Route38_Text_SailorHarrySeen, Route38_Text_SailorHarryBeaten
	msgbox Route38_Text_SailorHarryAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Olivia::
	trainerbattle_single TRAINER_OLIVIA_HNS, Route38_Text_BeautyOliviaSeen, Route38_Text_BeautyOliviaBeaten
	msgbox Route38_Text_BeautyOliviaAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Sign1::
	lock
	msgbox Route38_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route38_EventScript_Sign2::
	lock
	msgbox Route38_Text_WaterSign, MSGBOX_SIGN
	closemessage
	release
	end

Route38_EventScript_Item_LaxIncense::
	finditem ITEM_LAX_INCENSE
	end

Route38_Text_BirdKeeperTobySeen:
	.string "Volate in alto nel cielo,\n"
	.string "miei amati POKéMON uccello!$"

Route38_Text_BirdKeeperTobyBeaten:
	.string "Mi sento come se volassi\n"
	.string "via.$"

Route38_Text_BirdKeeperTobyAfter:
	.string "Voglio allenarmi a CIANWOOD CITY\n"
	.string "per insegnare VOLO ai miei POKéMON.$"

Route38_Text_SchoolboyChad1Seen:
	.string "Lascia che provi una cosa\n"
	.string "imparata oggi.$"

Route38_Text_SchoolboyChad1Beaten:
	.string "Non ho studiato abbastanza,\n"
	.string "direi.$"

Route38_Text_SchoolboyChadAfter:
	.string "Ho così tanti compiti\n"
	.string "che non ho molto\l"
	.string "tempo per i POKéMON.\p"
	.string "Perciò quando gioco,\n"
	.string "mi concentro davvero.$"

Route38_Text_ChadRegister:
	.string "Ho così tanti compiti\n"
	.string "che non ho molto\l"
	.string "tempo per i POKéMON.\p"
	.string "Perciò quando gioco,\n"
	.string "mi concentro davvero.$"

Route38_Text_ChadRematchIntro:
	.string "Lascia che provi una cosa\n"
	.string "imparata oggi.$"

Route38_Text_ChadRematchDefeat:
	.string "Non ho studiato abbastanza,\n"
	.string "direi.$"

Route38_Text_ChadPostRematch:
	.string "Ho così tanti compiti\n"
	.string "che non ho molto\l"
	.string "tempo per i POKéMON.\p"
	.string "Perciò quando gioco,\n"
	.string "mi concentro davvero.$"

Route38_Text_LassDana1Seen:
	.string "Sembri bravo con i\n"
	.string "POKéMON.\p"
	.string "Se è così, mi dai\n"
	.string "qualche consiglio?$"

Route38_Text_LassDana1Beaten:
	.string "Capisco. Lotti proprio\n"
	.string "così.$"

Route38_Text_LassDanaAfter:
	.string "So una cosa buona!\p"
	.string "Il latte della FATTORIA MUUMUU è\n"
	.string "famosa per il suo sapore.$"

Route38_Text_BeautyValerieSeen:
	.string "Ciao! Non sei un allenatore\n"
	.string "carino!\p"
	.string "Posso vedere i tuoi POKéMON?$"

Route38_Text_BeautyValerieBeaten:
	.string "Sono felice di aver visto\n"
	.string "i tuoi POKéMON!$"

Route38_Text_BeautyValerieAfter:
	.string "Vedere i POKéMON\n"
	.string "mi calma i nervi.$"

Route38_Text_SailorHarrySeen:
	.string "Ho girato il mondo,\n"
	.string "quindi conosco ogni\l"
	.string "tipo di POKéMON!$"

Route38_Text_SailorHarryBeaten:
	.string "La tua bravura è mondiale!$"

Route38_Text_SailorHarryAfter:
	.string "Gente di ogni parte\n"
	.string "del mondo vive felice con\l"
	.string "i POKéMON.$"

Route38_Text_BeautyOliviaSeen:
	.string "Non trovi che io e i miei POKéMON\n"
	.string "siamo bellissimi?$"

Route38_Text_BeautyOliviaBeaten:
	.string "Beviamo LATTE MUUMUU ogni\n"
	.string "giorno.$"

Route38_Text_BeautyOliviaAfter:
	.string "Il LATTE MUUMUU fa bene\n"
	.string "alla bellezza e alla salute,\p"
	.string "ma purtroppo ne vendono\n"
	.string "solo una bottiglia alla volta.$"

Route38_Text_Sign:
	.string "PERCORSO 38\p"
	.string "OLIVINE - AMANZIA$"

Route38_Text_TrainerTips:
	.string "CONSIGLI PER ALLENATORI\p"
	.string "Se un POKéMON sta per\n"
	.string "evolversi, puoi fermarlo.\p"
	.string "Premi il tasto B durante\n"
	.string "l'evoluzione per annullarla.\p"
	.string "Ciò spaventa il POKéMON\n"
	.string "e ne blocca l'evoluzione.$"


Route38_Text_WaterSign:
	.string "VIETATO NUOTARE E PESCARE.\n"
	.string "ACQUA SOLO PER L'AGRICOLTURA.\p"
	.string "-CONSIGLIO DI AMANZIA$"

Route38_Text_DanaRegister:
	.string "So una cosa buona!\p"
	.string "Il latte della FATTORIA MUUMUU è\n"
	.string "famosa per il suo sapore.$"

Route38_Text_DanaRematchIntro:
	.string "Sembri bravo con i\n"
	.string "POKéMON.\p"
	.string "Se è così, mi dai\n"
	.string "qualche consiglio?$"

Route38_Text_DanaRematchDefeat:
	.string "Capisco. Lotti proprio\n"
	.string "così.$"

Route38_Text_DanaPostRematch:
	.string "So una cosa buona!\p"
	.string "Il latte della FATTORIA MUUMUU è\n"
	.string "famosa per il suo sapore.$"

Route38_Text_DanaHasItem:
	.string "Ehi! Ho trovato una cosa\n"
	.string "interessante!\p"
	.string "Tieni, è per te!$"

Route38_Text_DanaGaveItem:
	.string "Ti farò sapere se trovo\n"
	.string "altro!$"

Route38_Text_DanaNoRoom:
	.string "Hmm, la tua BORSA è piena.\p"
	.string "Torna quando avrai spazio.$"
