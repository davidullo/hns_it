VerdanturfTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
	.byte 0

VerdanturfTown_OnTransition:
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	end

VerdanturfTown_EventScript_Twin::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_TwinTunnelOpen
	msgbox VerdanturfTown_Text_ManTryingToDigTunnel, MSGBOX_DEFAULT
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_TwinTunnelOpen::
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_Man::
	msgbox VerdanturfTown_Text_AirCleanHere, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Camper::
	msgbox VerdanturfTown_Text_MakeBattleTentDebut, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_BoyTunnelOpen
	msgbox VerdanturfTown_Text_GuyTryingToBustThroughCave, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_BoyTunnelOpen::
	msgbox VerdanturfTown_Text_EasyToGetToRustboroNow, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_TownSign::
	msgbox VerdanturfTown_Text_TownSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_WandasHouseSign::
	msgbox VerdanturfTown_Text_WandasHouse, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_BattleTentSign::
	msgbox VerdanturfTown_Text_BattleTentSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_RusturfTunnelSign::
	msgbox VerdanturfTown_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

VerdanturfTown_Text_ManTryingToDigTunnel:
	.string "Me l'ha detto il mio papà.\p"
	.string "Dice che questo tunnel è pieno di\n"
	.string "POKéMON timidi.\p"
	.string "Si spaventano per i rumori forti e\n"
	.string "fanno una gran baraonda.\p"
	.string "Così hanno dovuto fermare il grande\n"
	.string "progetto del tunnel.\p"
	.string "Ma c'è un uomo. Prova a scavare\n"
	.string "il tunnel tutto da solo!$"

VerdanturfTown_Text_ManDugTunnelForLove:
	.string "C'era un uomo che scavò un tunnel per\n"
	.string "la donna che amava.\p"
	.string "Io non lo capisco, ma vabbè!$"

VerdanturfTown_Text_AirCleanHere:
	.string "Per come soffiano i venti, la cenere\n"
	.string "vulcanica non arriva mai da questa parte.\p"
	.string "L'aria qui è pulita e deliziosa.\n"
	.string "Vivere qui fa bene persino alle persone\l"
	.string "deboli e malaticce.$"

VerdanturfTown_Text_MakeBattleTentDebut:
	.string "Io e i miei POKéMON stiamo\n"
	.string "vincendo alla grande.\p"
	.string "Così ho deciso di esordire nella\n"
	.string "TENDA LOTTA di questa città.$"

VerdanturfTown_Text_GuyTryingToBustThroughCave:
	.string "Hai visto la grotta accanto al\n"
	.string "MART POKéMON?\p"
	.string "C'è un tipo là dentro che prova a\n"
	.string "spaccare i massi per aprirsi un varco\l"
	.string "fino all'altro lato.\p"
	.string "Sarebbe bello poter passare…\n"
	.string "Renderebbe facile andare a RUSTBORO.$"

VerdanturfTown_Text_EasyToGetToRustboroNow:
	.string "Quella grotta vicino al MART POKéMON\n"
	.string "ora è un tunnel per l'altro lato.\p"
	.string "Che bello, ora è facile andare a comprare\n"
	.string "i nuovi prodotti DEVON a FERRUGIPPA.$"

VerdanturfTown_Text_TownSign:
	.string "VERDANTURF\p"
	.string "“Gli altopiani ventosi con la dolce\n"
	.string "fragranza dell'erba.”$"

VerdanturfTown_Text_WandasHouse:
	.string "CASA DI WANDA$"

VerdanturfTown_Text_BattleTentSign:
	.string "TENDA LOTTA SEDE DI VERDANTURF\n"
	.string "“Uno spettacolo di lotte!”$"

VerdanturfTown_Text_RusturfTunnelSign:
	.string "TUNNEL MENFERRO\n"
	.string "“Collega RUSTBORO e VERDANTURF\p"
	.string "“Il progetto della galleria è stato\n"
	.string "annullato.””$"

