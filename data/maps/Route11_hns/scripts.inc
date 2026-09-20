Route11_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route11_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route11_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route11_EventScript_Owen::
	trainerbattle_single TRAINER_OWEN_HNS, Route11_Text_YoungsterOwenSeen, Route11_Text_YoungsterOwenBeaten
	msgbox Route11_Text_YoungsterOwenAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Jason::
	trainerbattle_single TRAINER_JASON_HNS, Route11_Text_YoungsterJasonSeen, Route11_Text_YoungsterJasonBeaten
	msgbox Route11_Text_YoungsterJasonAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Herman::
	trainerbattle_single TRAINER_HERMAN_HNS, Route11_Text_PsychicHermanSeen, Route11_Text_PsychicHermanBeaten
	msgbox Route11_Text_PsychicHermanAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Fidel::
	trainerbattle_single TRAINER_FIDEL_HNS, Route11_Text_PsychicFidelSeen, Route11_Text_PsychicFidelBeaten
	msgbox Route11_Text_PsychicFidelAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Engineer::
	msgbox Route11_Text_Engineer, MSGBOX_NPC
	end

Route11_EventScript_Item_Grass_Knot::
    finditem ITEM_TM_GRASS_KNOT
    end

Route11_Text_Engineer:
	.string "Ho visto uno strano POKéMON\n"
	.string "arrampicarsi sugli alberi, ma non\l"
	.string "sembrava un MANKEY…$"

Route11_Text_YoungsterOwenSeen:
	.string "Nei POKéMON non si bara.\p"
	.string "Restiamo leali e corretti!$"

Route11_Text_YoungsterOwenBeaten:
	.string "Eh? Come è successo?$"

Route11_Text_YoungsterOwenAfterBattle:
	.string "Ho lottato lealmente con\n"
	.string "onore.\p"
	.string "Non me ne pento affatto.$"

Route11_Text_YoungsterJasonSeen:
	.string "Pizzica e solletica un po' quando\n"
	.string "indosso i pantaloncini nell'erba.$"

Route11_Text_YoungsterJasonBeaten:
	.string "Ahi ahi! Mi hai schiacciato!$"

Route11_Text_YoungsterJasonAfterBattle:
	.string "Catturerò altri POKéMON\n"
	.string "nell'erba.$"

Route11_Text_PsychicHermanSeen:
	.string "…$"

Route11_Text_PsychicHermanBeaten:
	.string "…$"

Route11_Text_PsychicHermanAfterBattle:
	.string "…\p"
	.string "Ho perso con gli occhi chiusi…$"

Route11_Text_PsychicFidelSeen:
	.string "Lo vedo…\p"
	.string "Vedo tutto di te…$"

Route11_Text_PsychicFidelBeaten:
	.string "Non avevo previsto la tua forza…$"

Route11_Text_PsychicFidelAfterBattle:
	.string "La forza sta nella convinzione…\p"
	.string "Sei forte perché credi\n"
	.string "nei tuoi POKéMON.$"

Route11_Text_Sign:
	.string "PERCORSO 11$"

