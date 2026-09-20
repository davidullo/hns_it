SeafloorCavern_Room3_MapScripts::
	.byte 0

SeafloorCavern_Room3_EventScript_Shelly::
	trainerbattle_single TRAINER_SHELLY_SEAFLOOR_CAVERN, SeafloorCavern_Room3_Text_ShellyIntro, SeafloorCavern_Room3_Text_ShellyDefeat
	msgbox SeafloorCavern_Room3_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_5, SeafloorCavern_Room3_Text_Grunt5Intro, SeafloorCavern_Room3_Text_Grunt5Defeat
	msgbox SeafloorCavern_Room3_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_Text_ShellyIntro:
	.string "Ahahahaha!\p"
	.string "How did you manage to get here without\n"
	.string "a submarine?\l"
	.string "What an impressive child!\p"
	.string "But… It won't do to have you\n"
	.string "meddling about here.\p"
	.string "And, I do want payback for what\n"
	.string "happened at the WEATHER INSTITUTE…\p"
	.string "I'm going to give you a little taste\n"
	.string "of pain! Resign yourself to it!$"

SeafloorCavern_Room3_Text_ShellyDefeat:
	.string "Ahahahaha!\p"
	.string "Ahi!$"

SeafloorCavern_Room3_Text_ShellyPostBattle:
	.string "Ahahahaha!\n"
	.string "Sei davvero forte.\p"
	.string "È un peccato che tu non sia\n"
	.string "un membro del TEAM AQUA.\p"
	.string "Avresti potuto goderti il favoloso\n"
	.string "mondo promesso dal nostro BOSS\l"
	.string "con noi…$"

SeafloorCavern_Room3_Text_Grunt5Intro:
	.string "Per realizzare il nostro sogno, ci serve\n"
	.string "la forza dei POKéMON.\p"
	.string "Ma tipi come te usano la forza dei\n"
	.string "POKéMON per ostacolarci anche in\l"
	.string "un posto come questo!\p"
	.string "La Creazione non va mai come\n"
	.string "vogliamo noi!$"

SeafloorCavern_Room3_Text_Grunt5Defeat:
	.string "Gwah!$"

SeafloorCavern_Room3_Text_Grunt5PostBattle:
	.string "Sai, non osiamo mettere in dubbio\n"
	.string "i motivi del nostro capo.\p"
	.string "E tu, un semplice punk,\n"
	.string "sfidi il nostro BOSS.\p"
	.string "Forse…\n"
	.string "Devi essere forte…$"

