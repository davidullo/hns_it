SafariZoneGate_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SafariZoneGate_PokemonCenter_OnTransition
	.byte 0

SafariZoneGate_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_SAFARI_ZONE_GATE_HNS
	end

SafariZoneGate_PokemonCenter_EventScript_NPC1::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_NPC1, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_EventScript_NPC2::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_NPC2, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_Text_Boy::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_SafariSong, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_Text_NPC1:
	.string "Chi viene a un CENTRO POKéMON\n"
	.string "spesso cura bene i suoi POKéMON.\p"
	.string "Non sei d'accordo?$"

SafariZoneGate_PokemonCenter_Text_NPC2:
	.string "Dopo una lunga camminata in montagna\n"
	.string "per trovare un CENTRO POKéMON,\l"
	.string "quando stai per crollare…\p"
	.string "Ti sembra di essere in paradiso!$"

SafariZoneGate_PokemonCenter_Text_SafariSong:
	.string "Safari, safari, che bel divertimento.\n"
	.string "Safari, safari, che interesse, eh!\p"
	.string "Tanti POKéMON ci aspettano!\p"
	.string "...È una canzone che ho inventato.\n"
	.string "La canto quando sono nella ZONA SAFARI.$"
