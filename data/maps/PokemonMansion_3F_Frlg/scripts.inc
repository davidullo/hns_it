PokemonMansion_3F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonMansion_3F_OnLoad
	.byte 0

PokemonMansion_3F_OnLoad::
	call_if_set FLAG_POKEMON_MANSION_SWITCH_STATE, PokemonMansion_EventScript_PressSwitch_3F
	end

PokemonMansion_3F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 2
	call PokemonMansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

PokemonMansion_3F_EventScript_DiaryFeb6th::
	msgbox PokemonMansion_1F_Text_MewGaveBirthToMewtwo, MSGBOX_SIGN
	end

PokemonMansion_3F_EventScript_Simon::
	trainerbattle_single TRAINER_BURGLAR_SIMON, PokemonMansion_1F_Text_SimonIntro, PokemonMansion_1F_Text_SimonDefeat
	msgbox PokemonMansion_1F_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_3F_EventScript_Braydon::
	trainerbattle_single TRAINER_SCIENTIST_BRAYDON, PokemonMansion_1F_Text_BraydonIntro, PokemonMansion_1F_Text_BraydonDefeat
	msgbox PokemonMansion_1F_Text_BraydonPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_1F_Text_SimonIntro::
	.string "Questo posto è enorme!$"

PokemonMansion_1F_Text_SimonDefeat::
	.string "Ahi!$"

PokemonMansion_1F_Text_SimonPostBattle::
	.string "Chissà dove è finito il mio socio.$"

PokemonMansion_1F_Text_BraydonIntro::
	.string "Il mio mentore viveva qui.$"

PokemonMansion_1F_Text_BraydonDefeat::
	.string "Uff!\n"
	.string "Travolgente!$"

PokemonMansion_1F_Text_BraydonPostBattle::
	.string "Sei bloccato?\n"
	.string "Prova a saltare laggiù!$"

PokemonMansion_1F_Text_MewGaveBirthToMewtwo::
	.string "Diario: 6 feb.\n"
	.string "MEW ha partorito.\p"
	.string "Il piccolo si chiama MEWTWO.$"

