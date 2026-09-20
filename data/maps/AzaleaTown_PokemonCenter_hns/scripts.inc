AzaleaTown_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_Pokecenter_OnTransition
	.byte 0

AzaleaTown_Pokecenter_OnTransition::
	setrespawn HEAL_LOCATION_AZALEA_TOWN_HNS
	end

AzaleaPokeCenter_EventScript_Gentleman::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokeCenter_EventScript_Fisher::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_FishingGuru, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokeCenter_EventScript_PokefanF::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_PokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokecenter_Text_Gentleman:
	.string "I tuoi POKéMON conoscono\p"
	.string "mosse MN? Si usano anche\n"
	.string "con un POKéMON esausto.$"

AzaleaPokecenter_Text_UnusedPCExplanation:
	.string "Quel BILL ha creato il sistema\n"
	.string "per salvare i POKéMON nel PC.\p"
	.string "Il PC di BILL contiene fino\n"
	.string "a 30 POKéMON per BOX.$"

AzaleaPokecenter_Text_FishingGuru:
	.string "Il PC di BILL contiene fino\n"
	.string "a 30 POKéMON per BOX.$"

AzaleaPokecenter_Text_PokefanF:
	.string "Conosci le BACCHE?\p"
	.string "Se la svuoti e ci monti\n"
	.string "un marchingegno speciale,\p"
	.string "catturi i POKéMON con essa.\p"
	.string "Prima che nascessero le\n"
	.string "POKé BALL si usavano BACCHE.$"
