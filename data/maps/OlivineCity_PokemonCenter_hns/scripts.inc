OlivineCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_PokemonCenter_OnTransition
	.byte 0

OlivineCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_OLIVINE_CITY_HNS
	end

OlivineCity_EventScript_Fisher::
	lock
	faceplayer
	msgbox OlivineCity_Text_PokecenterFisher, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Teacher::
	lock
	faceplayer
	msgbox OlivineCity_Text_PokecenterTeacher, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_PokecenterFisher:
	.string "Il MARINAIO del CAFFÈ di OLIVINOPOLI\n"
	.string "qui accanto è generoso.\p"
	.string "Ha insegnato FORZA al mio POKéMON.\p"
	.string "Ora sposta i massi\n"
	.string "senza sforzo.$"

OlivineCity_Text_PokecenterTeacher:
	.string "C'è una persona a FIORLISOPOLI\n"
	.string "oltre il mare.\p"
	.string "L'ho sentito vantarsi del suo\n"
	.string "raro POKéMON di continuo.$"
