VictoryRoad_B2F_MapScripts::
	.byte 0

VictoryRoad_B2F_EventScript_Vito::
	trainerbattle_single TRAINER_VITO, VictoryRoad_B2F_Text_VitoIntro, VictoryRoad_B2F_Text_VitoDefeat
	msgbox VictoryRoad_B2F_Text_VitoPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Owen::
	trainerbattle_single TRAINER_OWEN, VictoryRoad_B2F_Text_OwenIntro, VictoryRoad_B2F_Text_OwenDefeat
	msgbox VictoryRoad_B2F_Text_OwenPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Caroline::
	trainerbattle_single TRAINER_CAROLINE, VictoryRoad_B2F_Text_CarolineIntro, VictoryRoad_B2F_Text_CarolineDefeat
	msgbox VictoryRoad_B2F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Julie::
	trainerbattle_single TRAINER_JULIE, VictoryRoad_B2F_Text_JulieIntro, VictoryRoad_B2F_Text_JulieDefeat
	msgbox VictoryRoad_B2F_Text_JuliePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Felix::
	trainerbattle_single TRAINER_FELIX, VictoryRoad_B2F_Text_FelixIntro, VictoryRoad_B2F_Text_FelixDefeat
	msgbox VictoryRoad_B2F_Text_FelixPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Dianne::
	trainerbattle_single TRAINER_DIANNE, VictoryRoad_B2F_Text_DianneIntro, VictoryRoad_B2F_Text_DianneDefeat
	msgbox VictoryRoad_B2F_Text_DiannePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_Text_VitoIntro:
	.string "Mi sono allenato con tutta la famiglia,\n"
	.string "tutti quanti!\l"
	.string "Non perderò con nessuno!$"

VictoryRoad_B2F_Text_VitoDefeat:
	.string "Meglio della mia famiglia?!\n"
	.string "È possibile?!$"

VictoryRoad_B2F_Text_VitoPostBattle:
	.string "Ero il migliore della famiglia.\n"
	.string "Non avevo mai perso…\p"
	.string "Ho perso la fiducia…\n"
	.string "Forse torno a casa…$"

VictoryRoad_B2F_Text_OwenIntro:
	.string "Ho sentito che c'era un bambino\n"
	.string "tosto in giro. Sei tu?$"

VictoryRoad_B2F_Text_OwenDefeat:
	.string "Il piccolo è tosto!$"

VictoryRoad_B2F_Text_OwenPostBattle:
	.string "Le voci dicono che quel bambino\n"
	.string "tosto viene da PETALBURG.$"

VictoryRoad_B2F_Text_CarolineIntro:
	.string "Dovresti essere un po' stanco.$"

VictoryRoad_B2F_Text_CarolineDefeat:
	.string "Nessun segno di stanchezza!$"

VictoryRoad_B2F_Text_CarolinePostBattle:
	.string "VIA VITTORIA e LEGA POKÉMON\n"
	.string "sono sfide lunghe e dure.\l"
	.string "Attento alla stanchezza!$"

VictoryRoad_B2F_Text_JulieIntro:
	.string "Non montarti la testa solo\n"
	.string "perché hai tante MEDAGLIE.\p"
	.string "Ci sarà sempre qualcuno\n"
	.string "più forte di te!$"

VictoryRoad_B2F_Text_JulieDefeat:
	.string "Sei più forte di me!$"

VictoryRoad_B2F_Text_JuliePostBattle:
	.string "Guarda le MEDAGLIE che hai\n"
	.string "e ricorda gli ALLENATORI sfidati.$"

VictoryRoad_B2F_Text_FelixIntro:
	.string "Sono arrivato fin qui, ma la tensione\n"
	.string "mi fa male allo stomaco…$"

VictoryRoad_B2F_Text_FelixDefeat:
	.string "Ooh…\n"
	.string "Che male…$"

VictoryRoad_B2F_Text_FelixPostBattle:
	.string "Mi irrigidisco sapendo\n"
	.string "che sono vicino alla LEGA POKÉMON.\p"
	.string "Fingo calma, ma è dura.$"

VictoryRoad_B2F_Text_DianneIntro:
	.string "L'élite tra l'élite si raduna in\n"
	.string "questa grotta.\p"
	.string "Come la trovi?$"

VictoryRoad_B2F_Text_DianneDefeat:
	.string "Neanche un po' scosso!$"

VictoryRoad_B2F_Text_DiannePostBattle:
	.string "Hai fegato! Mi piace!\n"
	.string "Continua così!$"

