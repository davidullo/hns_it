UnionCave_B2F_hns_MapScripts::
	.byte 0

UnionCave_B2F_EventScript_CooltrainerNick::
	trainerbattle_single TRAINER_NICK_HNS, UnionCave_B2F_Text_CooltrainermNickSeen, UnionCave_B2F_Text_CooltrainermNickBeaten
	msgbox UnionCave_B2F_Text_CooltrainermNickAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B2F_EventScript_CooltrainerfGwen::
	trainerbattle_single TRAINER_GWEN_HNS, UnionCave_B2F_Text_CooltrainerfGwenSeen, UnionCave_B2F_Text_CooltrainerfGwenBeaten
	msgbox UnionCave_B2F_Text_CooltrainerfGwenAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B2F_EventScript_CooltrainerfEmma::
	trainerbattle_single TRAINER_EMMA_HNS, UnionCave_B2F_Text_CooltrainerfEmmaSeen, UnionCave_B2F_Text_CooltrainerfEmmaBeaten
	msgbox UnionCave_B2F_Text_CooltrainerfEmmaAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B2F_EventScript_Lapras::
	lock
	faceplayer
	playmoncry SPECIES_LAPRAS, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_LAPRAS, 20
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, UnionCave_B2F_EventScript_LaprasRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_UNION_CAVE_LAPRAS
	setflag FLAG_HIDE_UNION_CAVE_LAPRAS
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

UnionCave_B2F_EventScript_LaprasRan::
	release
	end


UnionCave_B2F_EventScript_Item_Ether::
	finditem ITEM_ETHER
	end

UnionCave_B2F_EventScript_Item_HyperPotion::
	finditem ITEM_HYPER_POTION
	end

UnionCave_B2F_EventScript_Item_MaxRevive::
	finditem ITEM_MAX_REVIVE
	end

UnionCave_B2F_Text_CooltrainermNickSeen:
	.string "Esistono due tipi di persone.\p"
	.string "Quelli con stile e quelli\n"
	.string "senza.\p"
	.string "E tu che tipo sei?$"

UnionCave_B2F_Text_CooltrainermNickBeaten:
	.string "Hai uno stile corposgargiante!$"

UnionCave_B2F_Text_CooltrainermNickAfter:
	.string "Lo stile dei tuoi POKéMON è superbo e\n"
	.string "colorato, lo ammetto.\p"
	.string "Migliorerai sempre di più!$"

UnionCave_B2F_Text_CooltrainerfGwenSeen:
	.string "Mi sto allenando. Ti va un round?$"

UnionCave_B2F_Text_CooltrainerfGwenBeaten:
	.string "Oh no! Sei troppo forte per me.$"

UnionCave_B2F_Text_CooltrainerfGwenAfter:
	.string "Mi allenerò da sola finché non\n"
	.string "miglioro.$"

UnionCave_B2F_Text_CooltrainerfEmmaSeen:
	.string "Se ci fosse il POKéMON che amo,\n"
	.string "andrei ovunque.\p"
	.string "È ciò che fa un vero allenatore.$"

UnionCave_B2F_Text_CooltrainerfEmmaBeaten:
	.string "Preferisco coccolare i miei piccoli!$"

UnionCave_B2F_Text_CooltrainerfEmmaAfter:
	.string "Una volta a settimana un POKéMON viene\n"
	.string "sulla riva.\p"
	.string "Volevo vedere quel POKéMON…$"
