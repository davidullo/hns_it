MeteorFalls_StevensCave_MapScripts::
	.byte 0

MeteorFalls_StevensCave_EventScript_Steven::
	lock
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, MeteorFalls_StevensCave_EventScript_Defeated
	waitse
	playse SE_PIN
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, MeteorFalls_StevensCave_Text_StevenDefeat
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_METEOR_FALLS_STEVEN
	release
	end

MeteorFalls_StevensCave_EventScript_Defeated::
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst:
	.string "ROCCO: Oh, wow, {PLAYER}{KUN}.\n"
	.string "Mi stupisci, sapevi dove trovarmi.\p"
	.string "Forse… mi consideri solo un\n"
	.string "maniaco delle rocce?\p"
	.string "No, non può essere.\p"
	.string "Abbiamo lottato fianco a fianco al\n"
	.string "CENTRO SPAZIALE di ALGARPOLI.\p"
	.string "Dovresti avere un'idea molto chiara\n"
	.string "di quanto io sia forte.\p"
	.string "Ok, {PLAYER}{KUN}, se vuoi lanciarti\n"
	.string "in una sfida seria, aspettati il peggio!$"

MeteorFalls_StevensCave_Text_StevenDefeat:
	.string "Tu…\n"
	.string "Non sapevo fossi diventato così forte…$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue:
	.string "ROCCO: A pensarci, da quando le nostre\n"
	.string "strade si incrociarono nella GROTTA\l"
	.string "GRANITO a PORTOALGHE, l'ho sentito.\p"
	.string "Pensavo che alla fine saresti\n"
	.string "diventato il CAMPIONE.\p"
	.string "Le mie previsioni di solito si avverano.\p"
	.string "E ora dove andrai?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Fufufu, nemmeno io saprei dirtelo.$"

