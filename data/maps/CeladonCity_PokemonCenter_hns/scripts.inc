CeladonCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_PokemonCenter_OnTransition
	.byte 0

CeladonCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_CELADON_CITY_HNS
	end

CeladonCity_PokemonCenter_EventScript_CooltrainerF::
	msgbox CeladonCity_PokemonCenter1F_Text_CooltrainerF, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_EventScript_Pharmacist::
	msgbox CeladonCity_PokemonCenter1F_Text_Pharmacist, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_EventScript_Eusine::
	msgbox Celadon_Text_Eusine1, MSGBOX_NPC
	end

CeladonCity_PokemonCenter1F_Text_CooltrainerF:
	.string "ERIKA è maestra di POKéMON\n"
	.string "d'ERBA.\p"
	.string "Ti farà pagare se non fai\n"
	.string "attenzione.$"

CeladonCity_PokemonCenter1F_Text_Pharmacist:
	.string "Il covo del TEAM ROCKET è nel\n"
	.string "seminterrato del GAME CORNER.\p"
	.string "Oh, aspetta. Sono passati tre\n"
	.string "anni.$"

Celadon_Text_Eusine1:
	.string "EUSINE: Ehi!\p"
	.string "Rivedo il mio paese natale.\p"
	.string "Ne è passato di tempo.$"

Celadon_Text_EusineLeaves:
	.string "{PLAYER}, hai saputo?\p"
	.string "Ci sono nuove voci su un\n"
	.string "POKéMON arcobaleno che\n"
	.string "appare alla TIN TOWER.\p"
	.string "Ho appena curato la squadra,\n"
	.string "quindi ora vado a ECRUTEAK.\p"
	.string "Ci vediamo, {PLAYER}!$"

Celadon_Text_NoBeasts:
	.string "A proposito, {PLAYER}.\p"
	.string "Hai catturato i POKéMON\n"
	.string "LEGGENDARI RAIKOU ed ENTEI?\p"
	.string "<……><……><……>\p"
	.string "Ok…\p"
	.string "Se ne catturi anche solo uno,\n"
	.string "voglio saperlo.\p"
	.string "Conto su di te, {PLAYER}!$"
