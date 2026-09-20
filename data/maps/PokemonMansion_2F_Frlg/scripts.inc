PokemonMansion_2F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonMansion_2F_OnLoad
	.byte 0

PokemonMansion_2F_OnLoad::
	call_if_set FLAG_POKEMON_MANSION_SWITCH_STATE, PokemonMansion_EventScript_PressSwitch_2F
	end

PokemonMansion_2F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 1
	call PokemonMansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

PokemonMansion_2F_EventScript_DiaryJuly5th::
	msgbox PokemonMansion_1F_Text_NewMonDiscoveredInGuyanaJungle, MSGBOX_SIGN
	end

PokemonMansion_2F_EventScript_DiaryJuly10th::
	msgbox PokemonMansion_1F_Text_ChristenedDiscoveredMonMew, MSGBOX_SIGN
	end

PokemonMansion_2F_EventScript_Arnie::
	trainerbattle_single TRAINER_BURGLAR_ARNIE, PokemonMansion_1F_Text_ArnieIntro, PokemonMansion_1F_Text_ArnieDefeat
	msgbox PokemonMansion_1F_Text_ArniePostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_Text_PressSecretSwitch::
	.string "Un interruttore segreto!\p"
	.string "Premere?$"

PokemonMansion_Text_WhoWouldnt::
	.string "E chi no?$"

PokemonMansion_Text_NotQuiteYet::
	.string "Non ancora!$"

PokemonMansion_1F_Text_ArnieIntro::
	.string "Non riesco a uscire!\n"
	.string "Questo posto è un gran puzzle.$"

PokemonMansion_1F_Text_ArnieDefeat::
	.string "Oh, no!\n"
	.string "Il mio bottino!$"

PokemonMansion_1F_Text_ArniePostBattle::
	.string "Gli interruttori aprono e chiudono\n"
	.string "serie di porte alternate.$"

PokemonMansion_1F_Text_NewMonDiscoveredInGuyanaJungle::
	.string "Diario: 5 luglio\n"
	.string "Guyana, Sudamerica\p"
	.string "Un nuovo POKéMON è stato scoperto\n"
	.string "nel cuore della giungla.$"

PokemonMansion_1F_Text_ChristenedDiscoveredMonMew::
	.string "Diario: 10 luglio\n"
	.string "Abbiamo battezzato il POKéMON\l"
	.string "appena scoperto: MEW.$"

