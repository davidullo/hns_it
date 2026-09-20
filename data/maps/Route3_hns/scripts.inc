Route3_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route3_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route3_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route3_EventScript_Otis::
	trainerbattle_single TRAINER_OTIS_HNS, Route3_Text_FirebreatherOtis_Seen, Route3_Text_FirebreatherOtis_Beaten
	msgbox Route3_Text_FirebreatherOtis_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Warren::
	trainerbattle_single TRAINER_WARREN_HNS, Route3_Text_YoungsterWarren_Seen, Route3_Text_YoungsterWarren_Beaten
	msgbox Route3_Text_YoungsterWarren_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Jimmy::
	trainerbattle_single TRAINER_JIMMY_HNS, Route3_Text_YoungsterJimmy_Seen, Route3_Text_YoungsterJimmy_Beaten
	msgbox Route3_Text_YoungsterJimmy_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Burt::
	trainerbattle_single TRAINER_BURT_HNS, Route3_Text_FirebreatherBurt_Seen, Route3_Text_FirebreatherBurt_Beaten
	msgbox Route3_Text_FirebreatherBurt_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Sign::
	msgbox Route3_Text_MtMoonSquareSign, MSGBOX_SIGN
	end

Route3_Text_FirebreatherOtis_Seen:
	.string "Ah! Il tempo è bello come sempre.$"

Route3_Text_FirebreatherOtis_Beaten:
	.string "C'è il sole, ma sono tutto bagnato…$"

Route3_Text_FirebreatherOtis_AfterBattle:
	.string "Quando piove, è difficile\n"
	.string "accendersi…$"

Route3_Text_YoungsterWarren_Seen:
	.string "Hmmm… non so cosa fare…$"

Route3_Text_YoungsterWarren_Beaten:
	.string "Sapevo che avrei perso…$"

Route3_Text_YoungsterWarren_AfterBattle:
	.string "Sembravi forte.\p"
	.string "Avevo paura di sfidarti…$"

Route3_Text_YoungsterJimmy_Seen:
	.string "Corro veloce come il vento!$"

Route3_Text_YoungsterJimmy_Beaten:
	.string "Che botta!$"

Route3_Text_YoungsterJimmy_AfterBattle:
	.string "Porto i pantaloncini tutto l'anno.\p"
	.string "È la mia filosofia di moda.$"

Route3_Text_FirebreatherBurt_Seen:
	.string "Fatevi avanti e guardate!$"

Route3_Text_FirebreatherBurt_Beaten:
	.string "Uao! Che caldo!$"

Route3_Text_FirebreatherBurt_AfterBattle:
	.string "Il più grande mangiafuoco di KANTO,\n"
	.string "sono io.\p"
	.string "Ma non il miglior allenatore…$"

Route3_Text_MtMoonSquareSign:
	.string "PIAZZA MONTE LUNA\p"
	.string "Sali le scale.$"

