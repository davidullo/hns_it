MtPyre_3F_MapScripts::
	.byte 0

MtPyre_3F_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM, MtPyre_3F_Text_WilliamIntro, MtPyre_3F_Text_WilliamDefeat
	msgbox MtPyre_3F_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Kayla::
	trainerbattle_single TRAINER_KAYLA, MtPyre_3F_Text_KaylaIntro, MtPyre_3F_Text_KaylaDefeat
	msgbox MtPyre_3F_Text_KaylaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Gabrielle::
	trainerbattle_single TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleIntro, MtPyre_3F_Text_GabrielleDefeat, MtPyre_3F_EventScript_RegisterGabrielle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_3F_EventScript_RematchGabrielle
	msgbox MtPyre_3F_Text_GabriellePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_3F_EventScript_RegisterGabrielle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_3F_Text_GabrielleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GABRIELLE_1
	release
	end

MtPyre_3F_EventScript_RematchGabrielle::
	trainerbattle_rematch TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleRematchIntro, MtPyre_3F_Text_GabrielleRematchDefeat
	msgbox MtPyre_3F_Text_GabriellePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_Text_WilliamIntro:
	.string "L'aria ricca della montagna\n"
	.string "ha accresciuto il mio potere psichico!\p"
	.string "Un semplice bambino come te…\n"
	.string "Speri di vincere?$"

MtPyre_3F_Text_WilliamDefeat:
	.string "Affogo nell'autocommiserazione…$"

MtPyre_3F_Text_WilliamPostBattle:
	.string "I miei poteri psichici sono certo\n"
	.string "cresciuti più volte, ma…$"

MtPyre_3F_Text_KaylaIntro:
	.string "Ahahahaha!\p"
	.string "Non è un posto per bambini, tanto\n"
	.string "meno per te!$"

MtPyre_3F_Text_KaylaDefeat:
	.string "Ho perso nettamente…$"

MtPyre_3F_Text_KaylaPostBattle:
	.string "Vuol dire che il mio allenamento non\n"
	.string "basta ancora…\p"
	.string "Devo continuare a puntare alla\n"
	.string "vetta…\p"
	.string "Forza, io!$"

MtPyre_3F_Text_GabrielleIntro:
	.string "Perché sei venuto qui?$"

MtPyre_3F_Text_GabrielleDefeat:
	.string "Che bravo!\n"
	.string "Sei un TRAINER davvero speciale.$"

MtPyre_3F_Text_GabriellePostBattle:
	.string "POKéMON no longer of this world.\n"
	.string "POKéMON that are with you now.\p"
	.string "And the POKéMON that you will meet\n"
	.string "in the future…\p"
	.string "They are all to be equally cherished.\n"
	.string "Please remember that.$"

MtPyre_3F_Text_GabrielleRegister:
	.string "Vorrei vedere i tuoi POKéMON\n"
	.string "quando saranno cresciuti ancora…\p"
	.string "Ti prego, fammi vedere il POKéNAV.$"

MtPyre_3F_Text_GabrielleRematchIntro:
	.string "Oh, sei tu…\p"
	.string "Sei venuto a mostrarmi i tuoi\n"
	.string "POKéMON cresciuti?$"

MtPyre_3F_Text_GabrielleRematchDefeat:
	.string "Che bravo!\n"
	.string "Sei una persona speciale.$"

MtPyre_3F_Text_GabriellePostRematch:
	.string "POKéMON non più di questo mondo.\n"
	.string "POKéMON che sono con te ora.\p"
	.string "E i POKéMON che incontrerai\n"
	.string "in futuro…\p"
	.string "Vanno tutti amati allo stesso modo.\n"
	.string "Vedo che te ne sei ricordato.$"

