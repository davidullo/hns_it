BattleFrontier_Lounge5_MapScripts::
	.byte 0

BattleFrontier_Lounge5_EventScript_NatureGirl::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	chooseboxmon
	waitstate
	lock
	faceplayer
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_Lounge5_EventScript_NatureGirlEgg
	special ShowNatureGirlMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlEgg::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_BlackBelt::
	msgbox BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_LittleBoy::
	msgbox BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot, MSGBOX_NPC
	end

BattleFrontier_Lounge5_Text_NatureGirlGreeting::
	.string "Ehehe!\n"
	.string "So capire i pensieri dei POKéMON!\p"
	.string "Dai!\n"
	.string "Vediamo i tuoi POKéMON?$"

BattleFrontier_Lounge5_Text_NatureGirlNoneShown::
	.string "Boo!\n"
	.string "Avaro!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighAttackLow::
	.string "Hmhm…\p"
	.string "Questo dice che ama lottare!\n"
	.string "Combatterà anche se ha tante\l"
	.string "ferite!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighDefenseLow::
	.string "Hmhm…\p"
	.string "Questo dice che ama lottare!\n"
	.string "Ma se prende troppe ferite,\l"
	.string "si preoccuperà!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighSupportLow::
	.string "Hmhm…\p"
	.string "Questo dice che ama lottare!\n"
	.string "Ma se prende troppe ferite,\l"
	.string "diventa subdolo!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighAttackLow::
	.string "Hmhm…\p"
	.string "Questo dice che si prende cura\n"
	.string "di sé! Ma con troppe ferite\l"
	.string "colpirà!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighDefenseLow::
	.string "Hmhm…\p"
	.string "Questo dice che si prende cura di sé!\n"
	.string "Dice che si preoccupa per le sue\l"
	.string "ferite, anche tante!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighSupportLow::
	.string "Hmhm…\p"
	.string "Questo dice che si prende cura!\n"
	.string "Ma se prende troppe ferite,\l"
	.string "diventa subdolo!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighAttackLow::
	.string "Hmhm…\p"
	.string "Questo dice che ama essere subdolo!\n"
	.string "Ma se prende troppe ferite,\l"
	.string "colpirà!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighDefenseLow::
	.string "Hmhm…\p"
	.string "Questo dice che ama essere subdolo!\n"
	.string "Ma se prende troppe ferite,\l"
	.string "si preoccuperà!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighSupportLow::
	.string "Hmhm…\p"
	.string "Questo dice che ama essere subdolo!\n"
	.string "Dice che gli piace, anche se ha\l"
	.string "tante ferite!$"

BattleFrontier_Lounge5_Text_NatureGirlEgg::
	.string "Che scemata! L'UOVO dorme!\n"
	.string "Non posso parlargli!$"

BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon::
	.string "Che carina!\n"
	.string "Quella signorina dice di capire\l"
	.string "i POKéMON!$"

BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound::
	.string "Ho la sensazione che quella bambina\n"
	.string "dica qualcosa di profondo.$"

BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot::
	.string "Ne so qualcosa!\p"
	.string "Quella bimba giocata spesso alla casa\n"
	.string "rossa!$"

