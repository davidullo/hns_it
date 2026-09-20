PokemonTower_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonTower_1F_OnTransition
	.byte 0

PokemonTower_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_POKEMON_TOWER_1F
	end

PokemonTower_1F_EventScript_Channeler::
	msgbox PokemonTower_1F_Text_SenseSpiritsUpToMischief, MSGBOX_NPC
	end

PokemonTower_1F_EventScript_Woman1::
	msgbox PokemonTower_1F_Text_GrowlitheWhyDidYouDie, MSGBOX_NPC
	end

PokemonTower_1F_EventScript_BaldingMan::
	msgbox PokemonTower_1F_Text_CameToPrayForDepartedClefairy, MSGBOX_NPC
	end

PokemonTower_1F_EventScript_Woman2::
	lock
	faceplayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, PokemonTower_1F_EventScript_Woman2MalePlayer
	msgbox PokemonTower_1F_Text_ComeToPayRespectsGirl
	release
	end

PokemonTower_1F_EventScript_Woman2MalePlayer::
	msgbox PokemonTower_1F_Text_ComeToPayRespectsSon
	release
	end

PokemonTower_1F_EventScript_WorkerF::
	msgbox PokemonTower_1F_Text_ErectedInMemoryOfDeadMons, MSGBOX_NPC
	end

PokemonTower_1F_Text_ErectedInMemoryOfDeadMons::
	.string "La TORRE POKéMON fu eretta in\n"
	.string "memoria dei POKéMON morti.$"

PokemonTower_1F_Text_ComeToPayRespectsSon::
	.string "Sei venuto a rendere omaggio?\p"
	.string "Benedetto il tuo cuore di\n"
	.string "amante dei POKéMON, figliolo.$"

PokemonTower_1F_Text_ComeToPayRespectsGirl::
	.string "Sei venuto a rendere omaggio?\p"
	.string "Benedetto il tuo cuore di\n"
	.string "amante dei POKéMON, ragazzo.$"

PokemonTower_1F_Text_CameToPrayForDepartedClefairy::
	.string "Pregavo per il mio caro\n"
	.string "CLEFAIRY defunto.\p"
	.string "Singhiozzo!\n"
	.string "Sono in lacrime…$"

PokemonTower_1F_Text_GrowlitheWhyDidYouDie::
	.string "Il mio GROWLITHE…\n"
	.string "Perché sei morto?$"

PokemonTower_1F_Text_SenseSpiritsUpToMischief::
	.string "Sono una MEDIUM.\p"
	.string "Ci sono spiriti che fanno Birba.\n"
	.string "Li sento in alto nella TORRE.$"

