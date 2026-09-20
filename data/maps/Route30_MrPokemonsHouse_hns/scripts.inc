Route30_MrPokemonsHouse_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MrPokemonHouse_OnFrame
	.byte 0

MrPokemonHouse_OnFrame::
	map_script_2 VAR_CHERRYGROVE_CITY_STATE, 1, MrPokemonHouse_EventScript_GiveEgg
	.2byte 0

MrPokemonHouse_EventScript_GiveEgg::
	lock
	playse SE_PIN
	applymovement LOCALID_MRPOKEMON, Common_Movement_ExclamationMark	
	delay 55
	waitmovement LOCALID_MRPOKEMON
	turnobject LOCALID_MRPOKEMON, DIR_SOUTH
	msgbox MrPokemonHouse_Text_Intro1, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MrPokemonHouse_Movement_MeetMrPokemon
	waitmovement 0
	msgbox MrPokemonHouse_Text_Intro2, MSGBOX_DEFAULT

	giveitem ITEM_MYSTERY_EGG

	msgbox MrPokemonHouse_Text_Intro3, MSGBOX_DEFAULT
	msgbox MrPokemonHouse_Text_Intro4, MSGBOX_DEFAULT
	turnobject LOCALID_ROUTE30_OAK, DIR_WEST
	msgbox MrPokemonHouse_Text_Intro5, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_HG_OAK, FALSE
	applymovement LOCALID_ROUTE30_OAK, MrPokemonHouse_Movement_OakToPlayer
	waitmovement 0 
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox MrPokemonHouse_Text_OakIntro, MSGBOX_DEFAULT
	

	playfanfare MUS_OBTAIN_ITEM
	message MrPokemonHouse_Text_GetDex
	waitfanfare

	
	msgbox MrPokemonHouse_Text_OakParting, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE30_OAK, MrPokemonHouse_Movement_OakLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_ROUTE30_OAK
	setflag FLAG_DELIVERED_EGG
	turnobject OBJ_EVENT_ID_PLAYER DIR_NORTH
	fadedefaultbgm
	msgbox MrPokemonHouse_Text_Heal, MSGBOX_DEFAULT
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox MrPokemonHouse_Text_DependingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MRPOKEMON, MrPokemonHouse_Movement_MrPokemon_Leave
	waitmovement 0
	removeobject LOCALID_MRPOKEMON
	clearflag FLAG_HIDE_MRPOKEMON
	addobject LOCALID_MRPOKEMON2
	
	setvar VAR_NEWBARKTOWN_LABSTATE, 4
	setflag FLAG_HIDE_SILVER_NEWBARKTOWN
	setflag FLAG_SYS_POKEDEX_GET
	checkrandomizer
	call_if_eq VAR_RESULT, TRUE, MrPokemonHouse_EventScript_GiveNatDexRandomizer
	clearflag FLAG_HIDE_LAB_POLICEMAN
	setvar VAR_CHERRYGROVE_CITY_STATE, 2
	setrespawn HEAL_LOCATION_CHERRYGROVE_CITY_HNS
	clearflag FLAG_HIDE_SILVER_CHERRYGROVE
	setflag FLAG_HIDE_GUIDE_GENT_CHERRYGROVE
	clearflag FLAG_HIDE_CHERRYGROVE_GUIDE_GENT_HOUSE
	release
	end

MrPokemonHouse_EventScript_GiveNatDexRandomizer::
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	return

MrPokemonHouse_EventScript_MrPokemon::
	lock
	faceplayer
	checkitem ITEM_RED_SCALE
	goto_if_eq VAR_RESULT, TRUE, MrPokemonHouse_EventScript_MrPokemon_RedScale
	msgbox MrPokemonHouse_Text_AlwaysNewDiscoveries, MSGBOX_DEFAULT
	closemessage
	release
	end

MrPokemonHouse_EventScript_MrPokemon_RedScale::
	msgbox MrPokemonHouse_Text_GimmeTheScale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, MrPokemonHouse_EventScript_MrPokemon_RedScale_Accepted
	msgbox MrPokemonHouse_Text_Disappointed, MSGBOX_DEFAULT
	closemessage
	release
	end	

MrPokemonHouse_EventScript_MrPokemon_RedScale_Accepted::
	removeitem ITEM_RED_SCALE
	giveitem ITEM_EXP_SHARE_SMALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	release
	end


MrPokemonHouse_EventScript_Computer::
	lock
	msgbox MrPokemonHouse_Text_BrokenComputer, MSGBOX_SIGN
	release
	end

MrPokemonHouse_EventScript_Magazine::
	lock
	msgbox MrPokemonHouse_Text_ForeignMagazines, MSGBOX_SIGN
	release
	end

MrPokemonHouse_EventScript_Coins::
	lock
	msgbox MrPokemonHouse_Text_StrangeCoins, MSGBOX_SIGN
	release
	end

MrPokemonHouse_Movement_MeetMrPokemon:
	walk_up
	walk_up
	walk_right
	walk_right
	face_up
	step_end

MrPokemonHouse_Movement_OakToPlayer:
	walk_down
	face_left
	step_end

MrPokemonHouse_Movement_OakLeave:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_in_place_down
	step_end

MrPokemonHouse_Movement_MrPokemon_Leave:
	walk_up
	walk_left
	walk_left
	step_end

MrPokemonHouse_Text_Intro1:
	.string "Ciao, ciao! Tu devi essere\n"
	.string "{PLAYER}.\p"
	.string "Il PROF. ELM mi aveva detto\n"
	.string "che saresti passato.$"

MrPokemonHouse_Text_Intro2:
	.string "Questo è ciò che voglio far\n"
	.string "esaminare al PROF. ELM.$"

MrPokemonHouse_Text_GotEgg:
	.string "{PLAYER} riceve l'UOVO MISTERO.$"

MrPokemonHouse_Text_Intro3:
	.string "Conosco una coppia che gestisce\n"
	.string "un PENSIONE POKéMON.\p"
	.string "Mi hanno dato quell'UOVO.\p"
	.string "Ero incuriosito, così ho scritto\n"
	.string "al PROF. ELM.\p"
	.string "Sull'evoluzione dei POKéMON\n"
	.string "il PROF. ELM è un'autorità.$"


MrPokemonHouse_Text_Intro4:
	.string "Persino il PROF. OAK qui lo\n"
	.string "riconosce.$"

MrPokemonHouse_Text_Intro5:
	.string "Se la mia ipotesi è giusta,\n"
	.string "il PROF. ELM lo capirà.$"

MrPokemonHouse_Text_Heal:
	.string "Torni dal PROF. ELM?\p"
	.string "Ecco. I tuoi POKéMON hanno\n"
	.string "bisogno di riposo.$"

MrPokemonHouse_Text_DependingOnYou:
	.string "Conto su di te!$"

MrPokemonHouse_Text_AlwaysNewDiscoveries:
	.string "La vita è meravigliosa!\n"
	.string "Sempre nuove scoperte da fare.$"

MrPokemonHouse_Text_OakIntro:
	.string "OAK: Ah! Quindi sei {PLAYER}!\p"
	.string "Io sono OAK! Ricercatore POKéMON.\p"
	.string "Ero qui a trovare il mio vecchio amico\n"
	.string "MR. POKéMON.\p"
	.string "Ho saputo che avevi una commissione\n"
	.string "per il PROF. ELM, così ho aspettato.\p"
	.string "Oh! Che cos'è? Un POKéMON raro!\p"
	.string "Vediamo…\n"
	.string "Mmm, capisco!\p"
	.string "Capisco perché il PROF. ELM ti ha\n"
	.string "dato un POKéMON per la commissione.\p"
	.string "Per ricercatori come il PROF. ELM e\n"
	.string "me, i POKéMON sono amici.\p"
	.string "Ha visto che tratteresti i tuoi\n"
	.string "POKéMON con amore e cura.\p"
	.string "…Ah!\p"
	.string "Sembri affidabile. Ti andrebbe\n"
	.string "di darmi una mano?\p"
	.string "Vedi? È l'ultima versione del\n"
	.string "POKéDEX.\p"
	.string "Registra da solo i dati sui\n"
	.string "POKéMON visti o catturati.\p"
	.string "È un'enciclopedia hi-tech!\p"
	.string "Mostra gli habitat, come\n"
	.string "si evolvono e le loro mosse.$"

MrPokemonHouse_Text_GetDex:
	.string "{PLAYER} riceve il POKéDEX!$"

MrPokemonHouse_Text_OakParting:
	.string "Incontra molti POKéMON e\n"
	.string "completa quel POKéDEX!\p"
	.string "Ma mi sono fermato troppo.\p"
	.string "Devo andare a FIORDARGENTO\n"
	.string "per la mia solita trasmissione.\p"
	.string "{PLAYER}, conto su di te!$"

MrPokemonHouse_Text_GimmeTheScale:
	.string "Eh? Quella FARFASCAGLIA! Cos'è?\n"
	.string "Un GYARADOS rosso?\p"
	.string "È raro! Io, io la voglio…\p"
	.string "{PLAYER}, la vorresti\n"
	.string "scambiare?\p"
	.string "Ti offro questo CONDIVISORE\n"
	.string "avuto dal PROF. OAK.$"

MrPokemonHouse_Text_Disappointed:
	.string "Che delusione.\n"
	.string "È una cosa molto rara.$"

MrPokemonHouse_Text_ExpShare:
	.string "Ho anche un oggetto speciale\n"
	.string "per te.$"

MrPokemonHouse_Text_ForeignMagazines:
	.string "È pieno di riviste\n"
	.string "straniere.\p"
	.string "Non so leggere i titoli…$"

MrPokemonHouse_Text_BrokenComputer:
	.string "È un computer grande.\n"
	.string "Mmm. È rotto.$"

MrPokemonHouse_Text_StrangeCoins:
	.string "Un mucchio di monete strane!\p"
	.string "Forse vengono da un altro\n"
	.string "paese…$"

MrPokemonHouse_Text_GotExpShare:
	.string "{PLAYER} riceve CONDIV. ESP.!$"
