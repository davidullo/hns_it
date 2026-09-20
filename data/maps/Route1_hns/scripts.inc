Route1_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route1_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route1_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route1_EventScript_SchoolboyDanny::
	trainerbattle_single TRAINER_DANNY_HNS, Route1_Text_SchoolboyDanny_Seen, Route1_Text_SchoolboyDanny_Beaten
	msgbox Route1_Text_SchoolboyDanny_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route1_EventScript_Quinn::
	trainerbattle_single TRAINER_QUINN_HNS, Route1_Text_CooltrainerFQuinn_Seen, Route1_Text_CooltrainerFQuinn_Beaten
	msgbox Route1_Text_CooltrainerFQuinn_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route1_EventScript_Sign::
	msgbox Route1_Text_Sign, MSGBOX_SIGN
	end

Route1_Text_SchoolboyDanny_Seen:
	.string "Se due allenatori si incontrano,\n"
	.string "prima si lotta.$"

Route1_Text_SchoolboyDanny_Beaten:
	.string "Uffa… che sconfitta…$"

Route1_Text_SchoolboyDanny_AfterBattle:
	.string "Noi allenatori lottiamo\n"
	.string "sempre quando ci incontriamo.$"

Route1_Text_CooltrainerFQuinn_Seen:
	.string "Ehi, tu! Ti va di lottare?$"

Route1_Text_CooltrainerFQuinn_Beaten:
	.string "Kappa…$"

Route1_Text_CooltrainerFQuinn_AfterBattle:
	.string "Sei forte.\p"
	.string "Si vede che ti sei allenato\n"
	.string "sodo.$"

Route1_Text_Sign:
	.string "ROUTE 1\p"
	.string "PALLET TOWN - VIRIDIAN CITY$"
