Gate_SaffronCity_Route6_hns_MapScripts::
	.byte 0

Gate_SaffronCity_Route6_EventScript_Guard::
	goto_if_eq VAR_TEMP_0, 1, Gate_SaffronCity_Route6_EventScript_Guard2
	msgbox Route6_Text_SaffronGuardWelcome, MSGBOX_NPC
	setvar VAR_TEMP_0, 1
	end
Gate_SaffronCity_Route6_EventScript_Guard2::
	msgbox Route6_Text_SaffronGuardMagnetTrain, MSGBOX_NPC
	end

Route6_Text_SaffronGuardWelcome:
	.string "Benvenuto a ZAFFERANOPOLI, sede\n"
	.string "del MAGNETOTRENO!\p"
	.string "…Di solito direi così,\n"
	.string "ma il MAGNETOTRENO non\l"
	.string "funziona ora.\p"
	.string "Non riceve elettricità\n"
	.string "perché c'è un guasto\l"
	.string "alla CENTRALE ELETTRICA.$"

Route6_Text_SaffronGuardMagnetTrain:
	.string "Il TRENO CALAMITA è la\n"
	.string "fama di ZAFFRONIA.$"
