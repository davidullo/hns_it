ThreeIsland_Port_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ThreeIsland_Port_OnTransition
	.byte 0

ThreeIsland_Port_OnTransition::
	clearflag FLAG_SYS_PC_STORAGE_DISABLED
	setflag FLAG_SEVII_DETOUR_FINISHED
	end

ThreeIsland_Port_EventScript_Woman::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 2, ThreeIsland_Port_EventScript_WomanLostelleFound
	goto_if_ge VAR_MAP_SCENE_THREE_ISLAND, 4, ThreeIsland_Port_EventScript_WomanBikersGone
	msgbox ThreeIsland_Port_Text_IllCallThePolice
	release
	end

ThreeIsland_Port_EventScript_WomanLostelleFound::
	msgbox ThreeIsland_Port_Text_EverythingTurnedOutForBest
	release
	end

ThreeIsland_Port_EventScript_WomanBikersGone::
	msgbox ThreeIsland_Port_Text_ThankGoodnessBikersGone
	release
	end

ThreeIsland_Port_EventScript_Biker1::
	msgbox ThreeIsland_Port_Text_WereKantoRiderFederation, MSGBOX_NPC
	end

ThreeIsland_Port_EventScript_Biker2::
	lock
	msgbox ThreeIsland_Port_Text_ForkOverMoney
	release
	end

ThreeIsland_Port_Text_WereKantoRiderFederation::
	.string "Siamo la FEDERAZIONE CENTAURI DI KANTO!\n"
	.string "Vroom! Vavavavooom! Vroom!\p"
	.string "La mia bici è fiacca, quindi\n"
	.string "faccio i rumori del motore io!$"

ThreeIsland_Port_Text_ForkOverMoney::
	.string "Ehi, ehi, signora!\n"
	.string "Tira fuori un po' di soldi!$"

ThreeIsland_Port_Text_IllCallThePolice::
	.string "Aiyeeh!\p"
	.string "Ch-chi sei?!\n"
	.string "Io… io chiamo la polizia!$"

ThreeIsland_Port_Text_ThankGoodnessBikersGone::
	.string "Quei BIKER…\n"
	.string "Se ne sono andati?\p"
	.string "Oh, grazie al cielo!\n"
	.string "Mi avevano terrorizzata!$"

ThreeIsland_Port_Text_EverythingTurnedOutForBest::
	.string "Quei BIKER se ne sono andati, e\n"
	.string "LOSTELLE è stata trovata sana e salva.\p"
	.string "È finito tutto per il meglio!$"

