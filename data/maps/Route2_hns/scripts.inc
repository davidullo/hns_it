Route2_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route2_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route2_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route2_EventScript_Sign::
	msgbox Route2_Text_Sign, MSGBOX_SIGN
	end

Route2_EventScript_CaveSign::
	msgbox Route2_Text_DiglettsCaveSign, MSGBOX_SIGN
	end

Route2_EventScript_Carbos::
    finditem ITEM_CARBOS
    end

Route2_EventScript_Nugget::
    finditem ITEM_NUGGET
    end

Route2_Text_RobRegister:
	.string "Fammi avere il tuo numero!$"

Route2_Text_RobRematchIntro:
	.string "Ho catturato ancora più Coleotteri!\n"
	.string "Guardali!$"

Route2_Text_RobRematchDefeat:
	.string "Mi servono Coleotteri migliori!$"

Route2_Text_RobPostRematch:
	.string "Ho preso ogni coleottero di VIRIDIAN.\n"
	.string "C'è una FORESTA migliore in giro?$"

Route2_Text_BugCatcherRob_Seen:
	.string "I miei POKéMON Coleottero sono forti.\n"
	.string "Preparati a perdere!$"

Route2_Text_BugCatcherRob_Beaten:
	.string "Mi hai battuto…$"

Route2_Text_BugCatcherRob_AfterBattle:
	.string "Vado a cercare POKéMON Coleottero\n"
	.string "più forti.$"

Route2_Text_BugCatcherEd_Seen:
	.string "Se cammini nell'erba alta in\n"
	.string "pantaloncini, ti graffi?$"

Route2_Text_BugCatcherEd_Beaten:
	.string "Ahia, ahia, ahia!$"

Route2_Text_BugCatcherEd_AfterBattle:
	.string "Pizzicheranno davvero quando fai\n"
	.string "il bagno.$"

Route2_Text_BugCatcherDoug_Seen:
	.string "Why don't girls like bug POKéMON?$"

Route2_Text_BugCatcherDoug_Beaten:
	.string "Non va bene!$"

Route2_Text_BugCatcherDoug_AfterBattle:
	.string "I POKéMON Coleottero si schiacciano\n"
	.string "come peluche se premi la pancia.\p"
	.string "Adoro come sono fatti!$"

Route2_Text_Sign:
	.string "PERCORSO 2\p"
	.string "VIRIDIAN CITY - PEWTER CITY$"

Route2_Text_DiglettsCaveSign:
	.string "GROTTA DIGLETT$"

