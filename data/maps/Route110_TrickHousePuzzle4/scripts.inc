Route110_TrickHousePuzzle4_MapScripts::
	.byte 0

Route110_TrickHousePuzzle4_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0, Route110_TrickHousePuzzle4_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle4_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle4_EventScript_Cora::
	trainerbattle_single TRAINER_CORA, Route110_TrickHousePuzzle4_Text_CoraIntro, Route110_TrickHousePuzzle4_Text_CoraDefeat
	msgbox Route110_TrickHousePuzzle4_Text_CoraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Yuji::
	trainerbattle_single TRAINER_YUJI, Route110_TrickHousePuzzle4_Text_YujiIntro, Route110_TrickHousePuzzle4_Text_YujiDefeat
	msgbox Route110_TrickHousePuzzle4_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA, Route110_TrickHousePuzzle4_Text_PaulaIntro, Route110_TrickHousePuzzle4_Text_PaulaDefeat
	msgbox Route110_TrickHousePuzzle4_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} ha scritto il codice segreto\n"
	.string "sulla porta.\p"
	.string "“TRICK MASTER è forte.”\n"
	.string "… … … … … … … …\p"
	.string "La serratura si è aperta!$"

Route110_TrickHousePuzzle4_Text_CoraIntro:
	.string "È troppo faticoso ragionarci su.\n"
	.string "Volevo solo lottare!$"

Route110_TrickHousePuzzle4_Text_CoraDefeat:
	.string "Anche se ho perso, lottare resta\n"
	.string "la cosa che amo di più!$"

Route110_TrickHousePuzzle4_Text_CoraPostBattle:
	.string "Non sei d'accordo? Andresti\n"
	.string "ovunque ci siano ALLENATORI.$"

Route110_TrickHousePuzzle4_Text_YujiIntro:
	.string "Heh! Boulders like this, I can brush\n"
	.string "aside with one finger!$"

Route110_TrickHousePuzzle4_Text_YujiDefeat:
	.string "Sposto i massi, ma non so risolvere\n"
	.string "l'enigma…$"

Route110_TrickHousePuzzle4_Text_YujiPostBattle:
	.string "Non basta essere forzuti…\n"
	.string "Bisogna usare la testa. Cervello!$"

Route110_TrickHousePuzzle4_Text_PaulaIntro:
	.string "La TRICK HOUSE si fa più insidiosa,\n"
	.string "vero?$"

Route110_TrickHousePuzzle4_Text_PaulaDefeat:
	.string "Aaaah!$"

Route110_TrickHousePuzzle4_Text_PaulaPostBattle:
	.string "Qualcuno è mai arrivato alla fine?$"

