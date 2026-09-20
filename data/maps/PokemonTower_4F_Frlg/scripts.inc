PokemonTower_4F_Frlg_MapScripts::
	.byte 0

PokemonTower_4F_EventScript_Paula::
	trainerbattle_single TRAINER_CHANNELER_PAULA, PokemonTower_4F_Text_PaulaIntro, PokemonTower_4F_Text_PaulaDefeat
	msgbox PokemonTower_4F_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_4F_EventScript_Laurel::
	trainerbattle_single TRAINER_CHANNELER_LAUREL, PokemonTower_4F_Text_LaurelIntro, PokemonTower_4F_Text_LaurelDefeat
	msgbox PokemonTower_4F_Text_LaurelPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_4F_EventScript_Jody::
	trainerbattle_single TRAINER_CHANNELER_JODY, PokemonTower_4F_Text_JodyIntro, PokemonTower_4F_Text_JodyDefeat
	msgbox PokemonTower_4F_Text_JodyPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_4F_Text_PaulaIntro::
	.string "Spettro! No!\n"
	.string "Kwaaah!$"

PokemonTower_4F_Text_PaulaDefeat::
	.string "Dov'è lo spettro?$"

PokemonTower_4F_Text_PaulaPostBattle::
	.string "Devo aver sognato…$"

PokemonTower_4F_Text_LaurelIntro::
	.string "Sii maledetto con me!\n"
	.string "Kwaaah!$"

PokemonTower_4F_Text_LaurelDefeat::
	.string "Cosa!$"

PokemonTower_4F_Text_LaurelPostBattle::
	.string "Non riusciamo a capire l'identità\n"
	.string "degli spettri…$"

PokemonTower_4F_Text_JodyIntro::
	.string "Huhuhu…\n"
	.string "Non battermi!$"

PokemonTower_4F_Text_JodyDefeat::
	.string "Eh?\n"
	.string "Chi? Cosa?$"

PokemonTower_4F_Text_JodyPostBattle::
	.string "Che i POKéMON defunti riposino\n"
	.string "in pace…$"

