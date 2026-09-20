Route110_TrickHousePuzzle6_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle6_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHousePuzzle6_OnWarp
	.byte 0

Route110_TrickHousePuzzle6_OnTransition:
	special RotatingGate_InitPuzzle
	end

Route110_TrickHousePuzzle6_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, Route110_TrickHousePuzzle6_EventScript_InitPuzzle
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_5
Route110_TrickHousePuzzle6_EventScript_InitPuzzle::
	special RotatingGate_InitPuzzleAndGraphics
	end

Route110_TrickHousePuzzle6_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_6_STATE, 0, Route110_TrickHousePuzzle6_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle6_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_6_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle6_EventScript_Sophia::
	trainerbattle_single TRAINER_SOPHIA, Route110_TrickHousePuzzle6_Text_SophiaIntro, Route110_TrickHousePuzzle6_Text_SophiaDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SophiaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Benny::
	trainerbattle_single TRAINER_BENNY, Route110_TrickHousePuzzle6_Text_BennyIntro, Route110_TrickHousePuzzle6_Text_BennyDefeat
	msgbox Route110_TrickHousePuzzle6_Text_BennyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Sebastian::
	trainerbattle_single TRAINER_SEBASTIAN, Route110_TrickHousePuzzle6_Text_SebastianIntro, Route110_TrickHousePuzzle6_Text_SebastianDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SebastianPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} ha scritto il codice segreto\n"
	.string "sulla porta.\p"
	.string "“TRICK MASTER è la mia vita.”\n"
	.string "… … … … … … … …\p"
	.string "La serratura si è aperta!$"

Route110_TrickHousePuzzle6_Text_SophiaIntro:
	.string "Quando ho saputo di una casa\n"
	.string "strana, sono dovuta venire.$"

Route110_TrickHousePuzzle6_Text_SophiaDefeat:
	.string "Ho trovato un ALLENATORE tosto!$"

Route110_TrickHousePuzzle6_Text_SophiaPostBattle:
	.string "Mi sto divertendo un sacco a esplorare\n"
	.string "questo posto.\p"
	.string "È una sfida che vale la pena\n"
	.string "ripetere!$"

Route110_TrickHousePuzzle6_Text_BennyIntro:
	.string "Forse col mio POKéMON Uccello\n"
	.string "potrei volare oltre il muro…$"

Route110_TrickHousePuzzle6_Text_BennyDefeat:
	.string "Gwaaah! Ho sbagliato tutto!$"

Route110_TrickHousePuzzle6_Text_BennyPostBattle:
	.string "Ehehehe… credo di aver perso perché\n"
	.string "stavo cercando di imbrogliare.$"

Route110_TrickHousePuzzle6_Text_SebastianIntro:
	.string "Queste porte girevoli mi fanno\n"
	.string "girare la testa…$"

Route110_TrickHousePuzzle6_Text_SebastianDefeat:
	.string "Mi gira tutto intorno.\n"
	.string "Non ce la faccio più…$"

Route110_TrickHousePuzzle6_Text_SebastianPostBattle:
	.string "Sembri immune a tutto questo.\n"
	.string "O hai la faccia di pietra?$"

