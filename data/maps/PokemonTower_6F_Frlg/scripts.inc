PokemonTower_6F_Frlg_MapScripts::
	.byte 0

PokemonTower_6F_EventScript_MarowakGhost::
	lockall
	textcolor NPC_TEXT_COLOR_MON
	msgbox PokemonTower_6F_Text_BeGoneIntruders
	setwildbattle SPECIES_MAROWAK, 30
	special StartMarowakBattle
	waitstate
	goto_if_eq VAR_RESULT, FALSE, PokemonTower_6F_EventScript_DefeatedMarowakGhost  @ VAR_RESULT set by CB2_EndMarowakBattle
	applymovement LOCALID_PLAYER, PokemonTower_6F_Movement_ForcePlayerUp
	waitmovement 0
	releaseall
	end

PokemonTower_6F_EventScript_DefeatedMarowakGhost::
	message PokemonTower_6F_Text_GhostWasCubonesMother
	waitmessage
	waitse
	playmoncry SPECIES_MAROWAK, CRY_MODE_NORMAL
	waitbuttonpress
	waitmoncry
	msgbox PokemonTower_6F_Text_MothersSpiritWasCalmed
	setvar VAR_MAP_SCENE_POKEMON_TOWER_6F, 1
	releaseall
	end

PokemonTower_6F_Movement_ForcePlayerUp::
	walk_up
	step_end

PokemonTower_6F_EventScript_Angelica::
	trainerbattle_single TRAINER_CHANNELER_ANGELICA, PokemonTower_6F_Text_AngelicaIntro, PokemonTower_6F_Text_AngelicaDefeat
	msgbox PokemonTower_6F_Text_AngelicaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_6F_EventScript_Emilia::
	trainerbattle_single TRAINER_CHANNELER_EMILIA, PokemonTower_6F_Text_EmiliaIntro, PokemonTower_6F_Text_EmiliaDefeat
	msgbox PokemonTower_6F_Text_EmiliaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_6F_EventScript_Jennifer::
	trainerbattle_single TRAINER_CHANNELER_JENNIFER, PokemonTower_6F_Text_JenniferIntro, PokemonTower_6F_Text_JenniferDefeat
	msgbox PokemonTower_6F_Text_JenniferPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_6F_Text_AngelicaIntro::
	.string "Dammi…\n"
	.string "sangue…$"

PokemonTower_6F_Text_AngelicaDefeat::
	.string "Ugh!$"

PokemonTower_6F_Text_AngelicaPostBattle::
	.string "Mi sento anemica e debole…$"

PokemonTower_6F_Text_EmiliaIntro::
	.string "Uff…\n"
	.string "Kwaah!$"

PokemonTower_6F_Text_EmiliaDefeat::
	.string "È caduto qualcosa!$"

PokemonTower_6F_Text_EmiliaPostBattle::
	.string "Non mi sono caduti i capelli!\n"
	.string "Era uno spirito malvagio!$"

PokemonTower_6F_Text_JenniferIntro::
	.string "Ke…ke…ke…\n"
	.string "ke…ke…ke!$"

PokemonTower_6F_Text_JenniferDefeat::
	.string "Kiii!$"

PokemonTower_6F_Text_JenniferPostBattle::
	.string "Che succede qui?$"

PokemonTower_6F_Text_BeGoneIntruders::
	.string "Andate via…\n"
	.string "Intrusi…$"

PokemonTower_6F_Text_GhostWasCubonesMother::
	.string "Lo spettro era il Fatuanima\n"
	.string "irrequieto della madre di CUBONE!$"

PokemonTower_6F_Text_MothersSpiritWasCalmed::
	.string "Lo spirito della madre si è calmato.\p"
	.string "È partito per l'aldilà…$"

