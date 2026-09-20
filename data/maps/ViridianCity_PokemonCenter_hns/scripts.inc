ViridianCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_PokemonCenter_OnTransition
	.byte 0

ViridianCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_VIRIDIAN_CITY_HNS
	end

ViridianCity_PokemonCenter_EventScript_CooltrainerM::
	goto_if_set FLAG_HIDE_CINNABAR_BLUE, VirianCity_EventScript_GymGrampsBlue
	msgbox ViridianCity_PokemonCenter_Text_1FCooltrainerM, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_EventScript_CooltrainerMBlue::
	msgbox ViridianCity_PokemonCenter_Text_1FCooltrainerM_BlueReturned, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_EventScript_CooltrainerF::
	msgbox ViridianCity_PokemonCenter_Text_1FCooltrainerF, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_EventScript_BugCatcher::
	msgbox ViridianCity_PokemonCenter_Text_1FBugCatcher, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_Text_1FCooltrainerM:
	.string "Dov'è finito il CAPOPALESTRA di\n"
	.string "VIRIDIAN? Volevo sfidarlo.$"

ViridianCity_PokemonCenter_Text_1FCooltrainerM_BlueReturned:
	.string "Non ci sono ALLENATORI alla\n"
	.string "PALESTRA di VIRIDIAN.\p"
	.string "Il CAPO dice che la sua politica è\n"
	.string "vincere senza sottoposti.$"

ViridianCity_PokemonCenter_Text_1FCooltrainerF:
	.string "Ho sentito che la PALESTRA di\n"
	.string "CINNABAR non c'è più.\p"
	.string "Chissà che fine ha fatto BLAINE,\n"
	.string "il CAPOPALESTRA.$"

ViridianCity_PokemonCenter_Text_1FBugCatcher:
	.string "Il mio sogno è diventare CAPOPALESTRA.$"
