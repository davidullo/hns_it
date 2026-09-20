CeladonCity_GameCorner_hns_MapScripts::
	.byte 0

CeladonGameCorner_EventScript_PokefanM::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_PokefanM, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceLeft
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_Teacher::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_Teacher, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceRight
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_FishingGuru::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_FishingGuru, MSGBOX_NPC
	closemessage
	release
	end

CeladonGameCorner_EventScript_Fisher1::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_Fisher1, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceLeft
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_Fisher2::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_Fisher2, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceLeft
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_GymGuide::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_GymGuide, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceRight
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_Gramps::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_Gramps, MSGBOX_NPC
	closemessage
	release
	end

CeladonGameCorner_EventScript_PokefanF::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_PokefanF, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceRight
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_Woman::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_Woman, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonGameCorner_Text_PokefanM:
	.string "Le slot sono tutte all'ultimo\n"
	.string "grido.$"

CeladonGameCorner_Text_Teacher:
	.string "Voglio questa macchina.\p"
	.string "Ieri mi ha spennato, quindi\n"
	.string "oggi dovrebbe pagare.$"

CeladonGameCorner_Text_FishingGuru:
	.string "Secondo me questa slot pagherà\n"
	.string "bene…\p"
	.string "Le probabilità variano.$"

CeladonGameCorner_Text_Fisher1:
	.string "Gahahaha!\p"
	.string "Che fiume di gettoni!\p"
	.string "Ei? Vuoi giocare anche tu?\p"
	.string "Ti passo un po' di fortuna!$"

CeladonGameCorner_Text_Fisher2:
	.string "Gahahaha!\p"
	.string "It makes me feel good to do nice\n"
	.string "things for other people!$"

CeladonGameCorner_Text_GymGuide:
	.string "Ehi! Futuro CAMPIONE!\p"
	.string "Giochi anche tu alle slot?\p"
	.string "Voglio gettoni per un\n"
	.string "POKéMON in palio.\p"
	.string "Ma non ne ho ancora abbastanza…$"

CeladonGameCorner_Text_PokefanF:
	.string "Roulette…\p"
	.string "La preferisco alle slot perché\n"
	.string "è facile capire le probabilità.\p"
	.string "Ma la vincita è più bassa.$"

CeladonGameCorner_Text_Gramps:
	.string "Hmmm… Le probabilità sono\n"
	.string "migliori puntando tutto su blu,\l"
	.string "ma… che fare?$"

CeladonGameCorner_Text_Woman:
	.string "Sto vincendo sempre!$"
