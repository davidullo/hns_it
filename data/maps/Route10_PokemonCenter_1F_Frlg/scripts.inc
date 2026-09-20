.equ REQUIRED_OWNED_MONS, 20

Route10_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route10_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

Route10_PokemonCenter_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_ROUTE10_POKEMON_CENTER_1F
	setrespawn HEAL_LOCATION_ROUTE10
	end

Route10_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

Route10_PokemonCenter_1F_EventScript_FatMan::
	msgbox Route10_PokemonCenter_1F_Text_NuggetUselessSoldFor5000, MSGBOX_NPC
	end

Route10_PokemonCenter_1F_EventScript_Gentleman::
	msgbox Route10_PokemonCenter_1F_Text_EveryTypeStrongerThanOthers, MSGBOX_NPC
	end

Route10_PokemonCenter_1F_EventScript_Youngster::
	msgbox Route10_PokemonCenter_1F_Text_HeardGhostsHauntLavender, MSGBOX_NPC
	end

Route10_PokemonCenter_1F_EventScript_Aide::
	lock
	faceplayer
	call Route10_PokemonCenter_1F_EventScript_GetAideRequestInfo
	goto_if_set FLAG_GOT_EVERSTONE_FROM_OAKS_AIDE, Route10_PokemonCenter_1F_EventScript_AlreadyGotEverstone
	msgbox Route10_PokemonCenter_1F_Text_GiveEverstoneIfCaught20Mons, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Aide_EventScript_DeclineCheckMons
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetFrlgPokedexCount
	buffernumberstring STR_VAR_3, VAR_0x8006
	call Route10_PokemonCenter_1F_EventScript_GetAideRequestInfo
	goto_if_lt VAR_0x8006, REQUIRED_OWNED_MONS, Aide_EventScript_HaventCaughtEnough
	msgbox Route10_PokemonCenter_1F_Text_GreatHereYouGo
	checkitemspace ITEM_EVERSTONE
	goto_if_eq VAR_RESULT, FALSE, Aide_EventScript_NoRoomForItem
	giveitem_msg Route10_PokemonCenter_1F_Text_ReceivedEverstoneFromAide, ITEM_EVERSTONE
	setflag FLAG_GOT_EVERSTONE_FROM_OAKS_AIDE
	msgbox Route10_PokemonCenter_1F_Text_ExplainEverstone
	release
	end

Route10_PokemonCenter_1F_EventScript_AlreadyGotEverstone::
	msgbox Route10_PokemonCenter_1F_Text_ExplainEverstone
	release
	end

Route10_PokemonCenter_1F_EventScript_GetAideRequestInfo::
	buffernumberstring STR_VAR_1, REQUIRED_OWNED_MONS
	bufferitemname STR_VAR_2, ITEM_EVERSTONE
	return

Route10_PokemonCenter_1F_Text_EveryTypeStrongerThanOthers::
	.string "I tipi dei POKéMON si abbinano\n"
	.string "diversamente tra loro.\p"
	.string "Ogni tipo è più forte di alcuni\n"
	.string "tipi e più debole di altri.$"

Route10_PokemonCenter_1F_Text_NuggetUselessSoldFor5000::
	.string "Una PEPITA è del tutto inutile.\n"
	.string "Così l'ho venduta per ¥5000.$"

Route10_PokemonCenter_1F_Text_HeardGhostsHauntLavender::
	.string "Ho sentito che i fantasmi\n"
	.string "infestano LAVENDER TOWN.$"

Route10_PokemonCenter_1F_Text_GiveEverstoneIfCaught20Mons::
	.string "Oh… {PLAYER}!\n"
	.string "Ti stavo cercando!\p"
	.string "Sono io, uno degli ASSISTENTI\n"
	.string "sempre presenti del PROF. OAK.\p"
	.string "Se il tuo POKéDEX ha i dati\n"
	.string "completi su venti specie,\l"
	.string "devo darti un premio dal PROF. OAK.\p"
	.string "Mi ha affidato questa\n"
	.string "PIETRASTANTE.\p"
	.string "Allora, {PLAYER}, ti chiedo.\p"
	.string "Hai raccolto dati su almeno\n"
	.string "venti specie di POKéMON?$"

Route10_PokemonCenter_1F_Text_GreatHereYouGo::
	.string "Bene! Hai catturato o posseduto\n"
	.string "{STR_VAR_3} specie di POKéMON!\p"
	.string "Congratulazioni!\n"
	.string "Tieni!$"

Route10_PokemonCenter_1F_Text_ReceivedEverstoneFromAide::
	.string "{PLAYER} riceve la PIETRASTANTE\n"
	.string "dall'ASSISTENTE.$"

Route10_PokemonCenter_1F_Text_ExplainEverstone::
	.string "Far evolvere i POKéMON può\n"
	.string "certo arricchire il POKéDEX.\p"
	.string "Però a volte potresti non\n"
	.string "voler far evolvere un POKéMON.\p"
	.string "In tal caso, dai la PIETRASTANTE\n"
	.string "a quel POKéMON.\p"
	.string "Impedirà l'evoluzione secondo\n"
	.string "il PROFESSORE.$"

