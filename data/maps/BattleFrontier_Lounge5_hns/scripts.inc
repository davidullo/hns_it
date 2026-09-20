BattleFrontier_Lounge5_hns_MapScripts::
	.byte 0

BattleFrontier_Lounge5_EventScript_NatureGirl_hns::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting_hns, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge5_EventScript_NatureGirl_hnsNoneShown_hns
	chooseboxmon
	waitstate
	lock
	faceplayer
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge5_EventScript_NatureGirl_hnsNoneShown_hns
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_Lounge5_EventScript_NatureGirl_hnsEgg_hns
	special ShowNatureGirlMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirl_hnsEgg_hns::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirl_hnsNoneShown_hns::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_Gentleman_hns::
	msgbox BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_BlackBelt_hns::
	msgbox BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_LittleBoy_hns::
	msgbox BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge5_Text_NatureGirlGreeting_hns::
	.string "Ehehe!\n"
	.string "So capire i pensieri dei POKéMON!\p"
	.string "Dai!\n"
	.string "Vediamo i tuoi POKéMON?$"

BattleFrontier_Lounge5_Text_NatureGirlNoneShown_hns::
	.string "Boo!\n"
	.string "Avaro!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighAttackLow_hns::
	.string "Hmhm…\p"
	.string "Questo dice che ama lottare!\n"
	.string "Combatterà anche se ha tante\l"
	.string "ferite!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighDefenseLow_hns::
	.string "Hmhm…\p"
	.string "Questo dice che ama lottare!\n"
	.string "Ma se prende troppe ferite,\l"
	.string "si preoccuperà!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighSupportLow_hns::
	.string "Hmhm…\p"
	.string "Questo dice che ama lottare!\n"
	.string "Ma se prende troppe ferite,\l"
	.string "diventa subdolo!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighAttackLow_hns::
	.string "Hmhm…\p"
	.string "Questo dice che si prende cura\n"
	.string "di sé! Ma con troppe ferite\l"
	.string "colpirà!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighDefenseLow_hns::
	.string "Hmhm…\p"
	.string "Questo dice che si prende cura di sé!\n"
	.string "Dice che si preoccupa per le sue\l"
	.string "ferite, anche tante!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighSupportLow_hns::
	.string "Hmhm…\p"
	.string "Questo dice che si prende cura!\n"
	.string "Ma se prende troppe ferite,\l"
	.string "diventa subdolo!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighAttackLow_hns::
	.string "Hmhm…\p"
	.string "Questo dice che ama essere subdolo!\n"
	.string "Ma se prende troppe ferite,\l"
	.string "colpirà!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighDefenseLow_hns::
	.string "Hmhm…\p"
	.string "Questo dice che ama essere subdolo!\n"
	.string "Ma se prende troppe ferite,\l"
	.string "si preoccuperà!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighSupportLow_hns::
	.string "Hmhm…\p"
	.string "Questo dice che ama essere subdolo!\n"
	.string "Dice che gli piace, anche se ha\l"
	.string "tante ferite!$"

BattleFrontier_Lounge5_Text_NatureGirlEgg_hns::
	.string "Che scemata! L'UOVO dorme!\n"
	.string "Non posso parlargli!$"

BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon_hns::
	.string "Che carina!\n"
	.string "Quella signorina dice di capire\l"
	.string "i POKéMON!$"

BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound_hns::
	.string "Ho la sensazione che quella bambina\n"
	.string "dica qualcosa di profondo.$"

BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot_hns::
	.string "Ne so qualcosa!\p"
	.string "Quella bimba giocata spesso alla casa\n"
	.string "rossa!$"

