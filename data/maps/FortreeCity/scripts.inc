FortreeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
	.byte 0

FortreeCity_OnTransition:
	setflag FLAG_VISITED_FORTREE_CITY
	end

FortreeCity_OnResume:
	setstepcallback STEP_CB_FORTREE_BRIDGE
	end

FortreeCity_EventScript_Man::
	msgbox FortreeCity_Text_SawGiganticPokemonInSky, MSGBOX_NPC
	end

FortreeCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_KECLEON_FLED_FORTREE, FortreeCity_EventScript_WomanGymAccessible
	msgbox FortreeCity_Text_SomethingBlockingGym, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_WomanGymAccessible::
	msgbox FortreeCity_Text_ThisTimeIllBeatWinona, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_Girl::
	msgbox FortreeCity_Text_TreesGrowByDrinkingRainwater, MSGBOX_NPC
	end

FortreeCity_EventScript_OldMan::
	msgbox FortreeCity_Text_EveryoneHealthyAndLively, MSGBOX_NPC
	end

FortreeCity_EventScript_Boy::
	msgbox FortreeCity_Text_BugPokemonComeThroughWindow, MSGBOX_NPC
	end

FortreeCity_EventScript_GameboyKid::
	msgbox FortreeCity_Text_PokemonThatEvolveWhenTraded, MSGBOX_NPC
	end

FortreeCity_EventScript_CitySign::
	msgbox FortreeCity_Text_CitySign, MSGBOX_SIGN
	end

FortreeCity_EventScript_GymSign::
	msgbox FortreeCity_Text_GymSign, MSGBOX_SIGN
	end

FortreeCity_EventScript_Kecleon::
	lock
	faceplayer
	checkitem ITEM_DEVON_SCOPE
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_EventScript_AskUseDevonScope
	msgbox FortreeCity_Text_SomethingUnseeable, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_AskUseDevonScope::
	msgbox FortreeCity_Text_UnseeableUseDevonScope, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FortreeCity_EventScript_UseDevonScope
	release
	end

FortreeCity_EventScript_UseDevonScope::
	msgbox FortreeCity_Text_UsedDevonScopePokemonFled, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Movement_KecleonAppears
	waitmovement 0
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement VAR_LAST_TALKED, FortreeCity_Movement_KecleonFlee
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_KECLEON_FLED_FORTREE
	release
	end

FortreeCity_Movement_KecleonFlee:
	walk_right
	step_end

FortreeCity_Text_SawGiganticPokemonInSky:
	.string "Nessuno mi crede, ma ho visto\n"
	.string "un POKéMON gigante lassù.\p"
	.string "Si dimenava mentre volava verso la\n"
	.string "PERCORSO 131.\p"
	.string "Comunque… Sniff…\n"
	.string "Ehm… Tu…senti bruciato.\p"
	.string "Eri su un vulcano o roba simile?$"

FortreeCity_Text_SomethingBlockingGym:
	.string "Voglio andare alla PALESTRA,\n"
	.string "ma qualcosa ostruisce la via.\p"
	.string "Dopo tutti i guai che ho passato\n"
	.string "sulla PERCORSO 120…$"

FortreeCity_Text_ThisTimeIllBeatWinona:
	.string "Ho con me i POKéMON più cari\n"
	.string "Stavolta batto WINONA!$"

FortreeCity_Text_TreesGrowByDrinkingRainwater:
	.string "Il terreno assorbe la pioggia e\n"
	.string "gli alberi crescono bevendola…\p"
	.string "La nostra FORESTOPOLI esiste\n"
	.string "perché c'è acqua e terra.$"

FortreeCity_Text_EveryoneHealthyAndLively:
	.string "La CITTÀ è fatta di case sui\n"
	.string "rami.\p"
	.string "Forse per questo stile di vita,\n"
	.string "tutti sono sani e vivaci.\p"
	.string "Perfino io mi sento come se\n"
	.string "avessi 30 anni di meno.$"

FortreeCity_Text_BugPokemonComeThroughWindow:
	.string "Vivere sugli alberi va bene.\p"
	.string "Ma i POKéMON COLEOTTERO entrano\n"
	.string "dalle finestre.\l"
	.string "Fa davvero paura.$"

FortreeCity_Text_PokemonThatEvolveWhenTraded:
	.string "Ci sono POKéMON che si evolvono\n"
	.string "quando li scambi! Dicono così.$"

FortreeCity_Text_SomethingUnseeable:
	.string "Qualcosa di invisibile intralcia.$"

FortreeCity_Text_UnseeableUseDevonScope:
	.string "Qualcosa di invisibile intralcia.\p"
	.string "Vuoi usare il DEVON SCOPE?$"

FortreeCity_Text_UsedDevonScopePokemonFled:
	.string "{PLAYER} usa il DEVON SCOPE.\p"
	.string "Un POKéMON invisibile è diventato\n"
	.string "visibile!\p"
	.string "POKéMON spaventato fugge!$"

FortreeCity_Text_CitySign:
	.string "FORESTOPOLI\n"
	.string "“La città fra gli alberi e la\l"
	.string "natura.”$"

FortreeCity_Text_GymSign:
	.string "PALESTRA POKéMON DI FORTREE\n"
	.string "CAPO: WINONA\p"
	.string "“L'asso degli UCCELLO in volo\n"
	.string "nel mondo.”$"

