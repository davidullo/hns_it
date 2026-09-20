PokemonMansion_B1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonMansion_B1F_OnLoad
	.byte 0

PokemonMansion_B1F_OnLoad::
	call_if_set FLAG_POKEMON_MANSION_SWITCH_STATE, PokemonMansion_EventScript_PressSwitch_B1F
	end

PokemonMansion_B1F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 3
	call PokemonMansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

PokemonMansion_B1F_EventScript_DiarySep1st::
	msgbox PokemonMansion_B1F_Text_MewtwoIsFarTooPowerful, MSGBOX_SIGN
	end

PokemonMansion_B1F_EventScript_Lewis::
	trainerbattle_single TRAINER_BURGLAR_LEWIS, PokemonMansion_B1F_Text_LewisIntro, PokemonMansion_B1F_Text_LewisDefeat
	msgbox PokemonMansion_B1F_Text_LewisPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_B1F_EventScript_Ivan::
	trainerbattle_single TRAINER_SCIENTIST_IVAN, PokemonMansion_B1F_Text_IvanIntro, PokemonMansion_B1F_Text_IvanDefeat
	msgbox PokemonMansion_B1F_Text_IvanPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_B1F_Text_LewisIntro::
	.string "Uh-oh…\n"
	.string "Dove sono finito?$"

PokemonMansion_B1F_Text_LewisDefeat::
	.string "Ahuu!$"

PokemonMansion_B1F_Text_LewisPostBattle::
	.string "Si trovano oggetti in giro.\n"
	.string "Li avranno lasciati gli inquilini.$"

PokemonMansion_B1F_Text_IvanIntro::
	.string "Questo posto è ideale per un lab.\n"
	.string "Guarda che spazio.$"

PokemonMansion_B1F_Text_IvanDefeat::
	.string "E questo perché?$"

PokemonMansion_B1F_Text_IvanPostBattle::
	.string "Mi piace questo posto.\n"
	.string "Favorisce i miei studi.$"

PokemonMansion_B1F_Text_MewtwoIsFarTooPowerful::
	.string "Diario: 1 set.\n"
	.string "MEWTWO è troppo potente.\p"
	.string "Non freniamo le sue tendenze\n"
	.string "violente…$"

