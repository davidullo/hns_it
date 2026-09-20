OldaleTown_House2_MapScripts::
	.byte 0

OldaleTown_House2_EventScript_Woman::
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man::
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_House2_Text_PokemonLevelUp:
	.string "Quando i POKéMON lottano, alla fine\n"
	.string "salgono di livello e si rafforzano.$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon:
	.string "Se i POKéMON con te diventano\n"
	.string "più forti, potrai andare più\l"
	.string "lontano da qui.$"

