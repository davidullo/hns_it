Route4_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route4_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route4_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route4_EventScript_HpUp::
	finditem ITEM_HP_UP
	end

Route4_EventScript_UltraBall::
	finditem ITEM_ULTRA_BALL
	end

Route4_EventScript_Hank::
	trainerbattle_single TRAINER_HANK_HNS, Route4_Text_BirdKeeperHank_Seen, Route4_Text_BirdKeeperHank_Beaten
	msgbox Route4_Text_BirdKeeperHank_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Hope::
	trainerbattle_single TRAINER_HOPE_HNS, Route4_Text_PicnickerHope_Seen, Route4_Text_PicnickerHope_Beaten
	msgbox Route4_Text_PicnickerHope_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Sharon::
	trainerbattle_single TRAINER_SHARON_HNS, Route4_Text_PicnickerSharon_Seen, Route4_Text_PicnickerSharon_Beaten
	msgbox Route4_Text_PicnickerSharon_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Sign::
	msgbox Route4_Text_MtMoonSquareSign, MSGBOX_SIGN
	end

Route4_Text_BirdKeeperHank_Seen:
	.string "Sto allenando i miei POKéMON. Vuoi\n"
	.string "combattere con me?$"

Route4_Text_BirdKeeperHank_Beaten:
	.string "Ah! L'ho persa…$"

Route4_Text_BirdKeeperHank_AfterBattle:
	.string "Se hai un POKéMON che vuoi\n"
	.string "allenare, mandalo in campo per primo,\l"
	.string "poi cambialo subito.\p"
	.string "Ecco come si fa.$"

Route4_Text_PicnickerHope_Seen:
	.string "Ho la sensazione che posso vincere.\p"
	.string "Vediamo se ho ragione!$"

Route4_Text_PicnickerHope_Beaten:
	.string "Uffa, sei troppo forte.$"

Route4_Text_PicnickerHope_AfterBattle:
	.string "Ho sentito che i CLEFAIRY appaiono\p"
	.string "al MONTE LUNA. Ma dove saranno?$"

Route4_Text_PicnickerSharon_Seen:
	.string "Ehm…\n"
	.string "Io…$"

Route4_Text_PicnickerSharon_Beaten:
	.string "…$"

Route4_Text_PicnickerSharon_AfterBattle:
	.string "……Vado ad allenarmi ancora…$"

Route4_Text_MtMoonSquareSign:
	.string "NUOVO INGRESSO MONTE LUNA\n"
	.string "PER FRANA\p"
	.string "ATTENZIONE AI PASSI$"

