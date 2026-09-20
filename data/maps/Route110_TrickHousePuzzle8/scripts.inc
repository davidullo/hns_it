Route110_TrickHousePuzzle8_MapScripts::
	.byte 0

Route110_TrickHousePuzzle8_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_8_STATE, 0, Route110_TrickHousePuzzle8_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle8_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_8_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle8_EventScript_Vincent::
	trainerbattle_single TRAINER_VINCENT, Route110_TrickHousePuzzle8_Text_VincentIntro, Route110_TrickHousePuzzle8_Text_VincentDefeat
	msgbox Route110_TrickHousePuzzle8_Text_VincentPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Keira::
	trainerbattle_single TRAINER_KEIRA, Route110_TrickHousePuzzle8_Text_KeiraIntro, Route110_TrickHousePuzzle8_Text_KeiraDefeat
	msgbox Route110_TrickHousePuzzle8_Text_KeiraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Leroy::
	trainerbattle_single TRAINER_LEROY, Route110_TrickHousePuzzle8_Text_LeroyIntro, Route110_TrickHousePuzzle8_Text_LeroyDefeat
	msgbox Route110_TrickHousePuzzle8_Text_LeroyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} ha scritto il codice segreto\n"
	.string "sulla porta.\p"
	.string "“TRICK MASTER ti amo.”\n"
	.string "… … … … … … … …\p"
	.string "La serratura si è aperta!$"

Route110_TrickHousePuzzle8_Text_VincentIntro:
	.string "Pochi ALLENATORI sono arrivati\n"
	.string "fin qui.$"

Route110_TrickHousePuzzle8_Text_VincentDefeat:
	.string "Allora vuol dire che sei forte anche tu…$"

Route110_TrickHousePuzzle8_Text_VincentPostBattle:
	.string "Hai battuto il CAMPIONE della\n"
	.string "LEGA POKÉMON? Troppo forte!$"

Route110_TrickHousePuzzle8_Text_KeiraIntro:
	.string "Considerati fortunato a\n"
	.string "lottare contro di me!$"

Route110_TrickHousePuzzle8_Text_KeiraDefeat:
	.string "Non è giusto!\n"
	.string "Non posso perdere!$"

Route110_TrickHousePuzzle8_Text_KeiraPostBattle:
	.string "È un miracolo che mi hai battuto.\n"
	.string "Puoi vantartene.$"

Route110_TrickHousePuzzle8_Text_LeroyIntro:
	.string "Anche tu stai affrontando la sfida\n"
	.string "della TRICK HOUSE.$"

Route110_TrickHousePuzzle8_Text_LeroyDefeat:
	.string "Capisco…\n"
	.string "Hai uno stile straordinario.$"

Route110_TrickHousePuzzle8_Text_LeroyPostBattle:
	.string "Vedere uno come te farà piacere\n"
	.string "al TRICK MASTER.$"

