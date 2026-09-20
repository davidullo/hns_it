SaffronCity_Tunnel_NS_hns_MapScripts::
	.byte 0

SaffronCity_Tunnel_NS_EventScript_BaldingMan::
	lock
	faceplayer
	goto_if_set FLAG_ITEM_UNDERGROUND_PATH_TM_EXPLOSION, SaffronCity_Tunnel_NS_EventScript_BaldingManAfter
	msgbox SaffronCity_Tunnel_NS_Text_BaldingManIntro, MSGBOX_DEFAULT
	checkitem ITEM_RAGE_CANDY_BAR
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_Tunnel_NS_EventScript_BaldingManDetected
	closemessage
	release
	end

SaffronCity_Tunnel_NS_EventScript_BaldingManDetected::
	playse SE_PIN
	applymovement LOCALID_SAFFRONTUNNEL_UNCLE_RAGE, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SAFFRONTUNNEL_UNCLE_RAGE
	msgbox SaffronCity_Tunnel_NS_Text_BaldingManCandybarDetected, MSGBOX_DEFAULT
	removeitem ITEM_RAGE_CANDY_BAR
	msgbox SaffronCity_Tunnel_NS_Text_BaldingManGaveCandybar, MSGBOX_DEFAULT
	giveitem ITEM_TM_EXPLOSION
	setflag FLAG_ITEM_UNDERGROUND_PATH_TM_EXPLOSION
SaffronCity_Tunnel_NS_EventScript_BaldingManAfter::
	msgbox SaffronCity_Tunnel_NS_Text_BaldingManGaveTm, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_Tunnel_NS_Text_BaldingManIntro:
	.string "Non temere, non sono una brutta\n"
	.string "persona.\p"
	.string "Un posto così...\n"
	.string "attira gente meschina.\p"
	.string "Prima o poi creerebbero\n"
	.string "problemi...\p"
	.string "Mi arrabbio solo a pensarci.\n"
	.string "Già.$"

SaffronCity_Tunnel_NS_Text_BaldingManCandybarDetected:
	.string "Aha!\n"
	.string "È una CARAMELLA IRA!\p"
	.string "Me la dai?\n"
	.string "Ti prego!$"

SaffronCity_Tunnel_NS_Text_BaldingManGaveCandybar:
	.string "{PLAYER} ha dato la Caramella Ira\n"
	.string "al tizio del sottopassaggio.\p"
	.string "Gnam!\p"
	.string "Che rabbia!\p"
	.string "Ma è buonissima!\p"
	.string "Gnam gnam!\p"
	.string "Argh! Mi fa arrabbiare!\p"
	.string "Gnam gnam!\p"
	.string "Argh...\p"
	.string "...................Ah!\p"
	.string "Mi sento molto meglio!\n"
	.string "Grazie per la caramella!\l"
	.string "Voglio darti questo!$"

SaffronCity_Tunnel_NS_Text_BaldingManGaveTm:
	.string "La MT 64 contiene........\p"
	.string "tic-\n"
	.string "            tac\l"
	.string "tic-\l"
	.string "            tac\l"
	.string "tic-\l"
	.string "            tac\l"
	.string "tic-\l"
	.string "            tac\l"
	.string "tic.....\l"
	.string "......................\l"
	.string "......................\l"
	.string "KA-BOOM!!!$"	

