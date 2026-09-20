LavenderTown_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_EventScript_CityEnter
	.byte 0

LavenderTown_EventScript_CityEnter::
	setflag FLAG_VISITED_LAVENDER_TOWN
	end

LavenderTown_EventScript_PokefanM::
	msgbox LavenderTown_Text_PokefanM, MSGBOX_NPC
	end

LavenderTown_EventScript_Teacher::
	msgbox LavenderTown_Text_Teacher, MSGBOX_NPC
	end

LavenderTown_EventScript_Gramps::
	msgbox LavenderTown_Text_Gramps, MSGBOX_NPC
	end

LavenderTown_EventScript_Youngster::
	msgbox LavenderTown_Text_Youngster, MSGBOX_NPC
	end

LavenderTown_EventScript_TownSign::
	msgbox LavenderTown_Text_Sign, MSGBOX_SIGN
	end

LavenderTown_EventScript_RadioTowerSign::
	msgbox LavenderTown_Text_KantoRadioStationSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_VolunteerSign::
	msgbox LavenderTown_Text_VolunteerPokemonHouseSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_SoulHouseSign::
	msgbox LavenderTown_Text_SoulHouseSign, MSGBOX_SIGN
	end

LavenderTown_Text_PokefanM:
	.string "Che palazzo, eh?\p"
	.string "È la TORRE RADIO.$"

LavenderTown_Text_Teacher:
	.string "A KANTO la radio è ottima.$"

LavenderTown_Text_Gramps:
	.string "Vengono da ogni dove\n"
	.string "a onorare le\l"
	.string "anime dei POKéMON.$"

LavenderTown_Text_Youngster:
	.string "Serve un POKé FLUTE per svegliare\n"
	.string "i POKéMON che dormono.\p"
	.string "Tutti gli allenatori lo sanno!$"

LavenderTown_Text_Sign:
	.string "LAVANDONIA\p"
	.string "La Città Viola$"

LavenderTown_Text_KantoRadioStationSign:
	.string "RADIO KANTO\p"
	.string "I tuoi programmi\n"
	.string "Sempre in onda!$"

LavenderTown_Text_VolunteerPokemonHouseSign:
	.string "CASA POKéMON\n"
	.string "VOLONTARI$"

LavenderTown_Text_SoulHouseSign:
	.string "CASA DELLE ANIME\p"
	.string "Che i POKéMON\n"
	.string "riposino in pace$"
