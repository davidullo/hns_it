PalletTown_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_EventScript_CityEnter
	.byte 0

PalletTown_EventScript_CityEnter::
	setflag FLAG_VISITED_PALLET_TOWN
	end

PalletTown_EventScript_Woman::
	msgbox PalletTown_Text_Teacher, MSGBOX_NPC
	end
PalletTown_EventScript_Fatman::
	msgbox PalletTown_Text_Fisher, MSGBOX_NPC
	end
PalletTown_EventScript_TownSign::
	msgbox PalletTown_Text_Sign, MSGBOX_SIGN
	end	
PalletTown_EventScript_RedsHouseSign::
	msgbox PalletTown_Text_RedsHouseSign, MSGBOX_SIGN
	end
PalletTown_EventScript_BluesHouseSign::
	msgbox PalletTown_Text_BluesHouseSign, MSGBOX_SIGN
	end	
PalletTown_EventScript_OaksLabSign::
	msgbox PalletTown_Text_OaksLabSign, MSGBOX_SIGN
	end	

PalletTown_Text_Teacher:
	.string "Anch'io allevo POKéMON.\p"
	.string "Mi fanno da guardie\n"
	.string "del corpo.$"

PalletTown_Text_Fisher:
	.string "La tecnologia è incredibile!\p"
	.string "Ora puoi scambiare POKéMON\n"
	.string "nel tempo come e-mail.$"

PalletTown_Text_Sign:
	.string "BIANCAVILLA\p"
	.string "Un tranquillo angolo di pace\n"
	.string "e purezza$"

PalletTown_Text_RedsHouseSign:
	.string "CASA DI RED$"

PalletTown_Text_OaksLabSign:
	.string "LABORATORIO DI RICERCHE\n"
	.string "POKéMON DI OAK$"

PalletTown_Text_BluesHouseSign:
	.string "CASA DI BLUE$"
