LavenderTown_House1_hns_MapScripts::
	.byte 0

LavenderTown_House1_EventScript_Girl::
	msgbox LavenderTown_House1_Text_Girl, MSGBOX_NPC
	end

LavenderTown_House1_EventScript_Guy::
	msgbox LavenderTown_House1_Text_Guy, MSGBOX_NPC
	end

LavenderTown_House1_EventScript_Marowak::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAROWAK, CRY_MODE_NORMAL
	msgbox LavenderTown_House1_Text_Marowak, MSGBOX_DEFAULT
	waitmoncry
	msgbox LavenderTown_House1_Text_Marowak2, MSGBOX_DEFAULT
	closemessage
	release
	end

LavenderTown_House1_Text_Girl:
	.string "Ci credi?\p"
	.string "C'è chi si stanca di prendersi\n"
	.string "cura dei POKéMON.\p"
	.string "NONNO accoglie i POKéMON\n"
	.string "senza casa e si prende cura di loro.$"
LavenderTown_House1_Text_Guy:
	.string "Il SIG. FUJI vive qui, ma ora\n"
	.string "non c'è. Dovrebbe essere alla\l"
	.string "CASA DELLE ANIME.$"
LavenderTown_House1_Text_Marowak:
	.string ".............................$"

LavenderTown_House1_Text_Marowak2:
	.string "Il MAROWAK è quieto, ma\n"
	.string "sembra molto felice.$"

