PokemonTower_3F_Frlg_MapScripts::
	.byte 0

PokemonTower_3F_EventScript_Patricia::
	trainerbattle_single TRAINER_CHANNELER_PATRICIA, PokemonTower_3F_Text_PatriciaIntro, PokemonTower_3F_Text_PatriciaDefeat
	msgbox PokemonTower_3F_Text_PatriciaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_3F_EventScript_Carly::
	trainerbattle_single TRAINER_CHANNELER_CARLY, PokemonTower_3F_Text_CarlyIntro, PokemonTower_3F_Text_CarlyDefeat
	msgbox PokemonTower_3F_Text_CarlyPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_3F_EventScript_Hope::
	trainerbattle_single TRAINER_CHANNELER_HOPE, PokemonTower_3F_Text_HopeIntro, PokemonTower_3F_Text_HopeDefeat
	msgbox PokemonTower_3F_Text_HopePostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_3F_Text_HopeIntro::
	.string "Urrg… Awaa…\n"
	.string "Uhu… Graa…$"

PokemonTower_3F_Text_HopeDefeat::
	.string "Hwa!\n"
	.string "Sono salvo!$"

PokemonTower_3F_Text_HopePostBattle::
	.string "I fantasmi si identificano con\n"
	.string "lo SPETTROSCOPIO.$"

PokemonTower_3F_Text_CarlyIntro::
	.string "Kechehe…\n"
	.string "Kwaaah!$"

PokemonTower_3F_Text_CarlyDefeat::
	.string "Hmm?\n"
	.string "Che sto facendo?$"

PokemonTower_3F_Text_CarlyPostBattle::
	.string "Scusa!\n"
	.string "Ero posseduto!$"

PokemonTower_3F_Text_PatriciaIntro::
	.string "Via!\n"
	.string "Spirito malvagio!$"

PokemonTower_3F_Text_PatriciaDefeat::
	.string "Uff!\n"
	.string "Lo spirito se n'è andato!$"

PokemonTower_3F_Text_PatriciaPostBattle::
	.string "Quelli di sopra…\n"
	.string "Devono essere stati posseduti.$"

