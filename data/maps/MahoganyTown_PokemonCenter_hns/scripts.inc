MahoganyTown_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MahoganyTown_PokemonCenter_OnTransition
	.byte 0

MahoganyTown_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_MAHOGANY_TOWN_HNS
	end

MahoganyTown_PokemonCenter_EventScript_Hiker::
	msgbox MahoganyTown_PokemonCenter_Text_PokefanM, MSGBOX_NPC
	end
	
MahoganyTown_PokemonCenter_EventScript_Boy::
	msgbox MahoganyTown_PokemonCenter_Text_Youngster, MSGBOX_NPC
	end

MahoganyTown_PokemonCenter_EventScript_Girl::
	msgbox MahoganyTown_PokemonCenter_Text_CooltrainerF, MSGBOX_NPC
	end

MahoganyTown_PokemonCenter_Text_PokefanM:
    .string "Come? Il TEAM ROCKET è\n"
    .string "tornato?\p"
    .string "Ho visto degli uomini in nero al\n"
    .string "LAGO D'IRA…$"

MahoganyTown_PokemonCenter_Text_Youngster:
    .string "Non lascio evolvere i POKéMON\n"
    .string "subito.\p"
    .string "Faccio imparare loro certe mosse\n"
    .string "prima di farli evolvere.$"

MahoganyTown_PokemonCenter_Text_CooltrainerF:
    .string "I POKéMON diventano più forti\n"
    .string "evolvendo,\p"
    .string "ma imparano le mosse più\n"
    .string "lentamente.$"
