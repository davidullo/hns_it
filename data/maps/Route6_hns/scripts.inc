Route6_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route6_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route6_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route6_EventScript_Rex::
	trainerbattle_single TRAINER_REX_HNS, PokefanM_Text_RexSeen, PokefanM_Text_RexBeaten
	msgbox PokefanM_Text_RexAfter, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Allan::
	trainerbattle_single TRAINER_ALLAN_HNS, PokefanM_Text_AllanSeen, PokefanM_Text_AllanBeaten
	msgbox PokefanM_Text_AllanAfter, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Pokefan::
	msgbox Route6_Text_PokefanM, MSGBOX_NPC
	end

Route6_EventScript_Sign::
	msgbox Route6_Text_UndergroundPathSign, MSGBOX_SIGN
	end

Route6_EventScript_Item_Silver_Wind::
    finditem ITEM_TM_SILVER_WIND
    end

Route6_Text_PokefanM:
	.string "La strada è chiusa finché non\n"
	.string "si risolve il problema alla\l"
	.string "CENTRALE ELETTRICA.$"

Route6_Text_UndergroundPathSign:
	.string "VIA SOTTERRANEA\p"
	.string "CELESTOPOLI - ARANCIOPOLI$"

PokefanM_Text_RexSeen:
	.string "Il mio STANTLER è il più tenero del\n"
	.string "mondo.$"

PokefanM_Text_RexBeaten:
	.string "Il mio STANTLER!$"

PokefanM_Text_RexAfter:
	.string "Guarda che tenero che fa il mio\n"
	.string "STANTLER!\p"
	.string "Non è così dolce da\n"
	.string "scioglierti il cuore?$"

PokefanM_Text_AllanSeen:
	.string "Il mio GRANBULL è il più tenero del\n"
	.string "mondo.$"

PokefanM_Text_AllanBeaten:
	.string "Il mio GRANBULL!$"

PokefanM_Text_AllanAfter:
	.string "Guarda che tenero che fa il mio\n"
	.string "GRANBULL!\p"
	.string "Non è così dolce da\n"
	.string "scioglierti il cuore?$"

