MtPyre_6F_MapScripts::
	.byte 0

MtPyre_6F_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieIntro, MtPyre_6F_Text_ValerieDefeat, MtPyre_6F_EventScript_RegisterValerie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_6F_EventScript_RematchValerie
	msgbox MtPyre_6F_Text_ValeriePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_RegisterValerie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_6F_Text_ValerieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_VALERIE_1
	release
	end

MtPyre_6F_EventScript_RematchValerie::
	trainerbattle_rematch TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieRematchIntro, MtPyre_6F_Text_ValerieRematchDefeat
	msgbox MtPyre_6F_Text_ValeriePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_EventScript_Cedric::
	trainerbattle_single TRAINER_CEDRIC, MtPyre_6F_Text_CedricIntro, MtPyre_6F_Text_CedricDefeat
	msgbox MtPyre_6F_Text_CedricPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_Text_ValerieIntro:
	.string "Quando sono qui…\n"
	.string "Un potere curioso scorre in me…$"

MtPyre_6F_Text_ValerieDefeat:
	.string "Il potere si sta esaurendo…$"

MtPyre_6F_Text_ValeriePostBattle:
	.string "Forse il potere viene dagli spiriti\n"
	.string "dei POKéMON che dormono qui…$"

MtPyre_6F_Text_ValerieRegister:
	.string "Fufufu… Ho perso, ma…\n"
	.string "Ho questa piccola abilità…\p"
	.string "Senza toccare il\n"
	.string "tuo POKéNAV… Hiyah!$"

MtPyre_6F_Text_ValerieRematchIntro:
	.string "Dietro di te…\n"
	.string "Che cos'è…$"

MtPyre_6F_Text_ValerieRematchDefeat:
	.string "Qualcosa si è dissolta…$"

MtPyre_6F_Text_ValeriePostRematch:
	.string "I POKéMON che riposano qui…\n"
	.string "A volte giocano…$"

MtPyre_6F_Text_CedricIntro:
	.string "Hai perso l'orientamento?\n"
	.string "Non temere, ci sono io!$"

MtPyre_6F_Text_CedricDefeat:
	.string "Non eri mica perso?$"

MtPyre_6F_Text_CedricPostBattle:
	.string "Pensavo che un TRAINER perso\n"
	.string "fosse nel panico e facile da battere.\p"
	.string "È scorretto e non lo farò più…$"

