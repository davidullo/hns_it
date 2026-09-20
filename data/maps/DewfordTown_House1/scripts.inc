DewfordTown_House1_MapScripts::
	.byte 0

DewfordTown_House1_EventScript_Man::
	msgbox DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Woman::
	msgbox DewfordTown_House1_Text_LifeGoesSlowlyOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox DewfordTown_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland:
	.string "C'è tanto da dire sul vivere\n"
	.string "su un'isola come questa, in armonia con\l"
	.string "POKéMON e famiglia.$"

DewfordTown_House1_Text_LifeGoesSlowlyOnIsland:
	.string "Ho lasciato il porto di SLATEPORT\n"
	.string "CITY quando ho sposato mio marito.\p"
	.string "La vita scorre lenta su questa\n"
	.string "isoletta. Ma essere circondati dal\l"
	.string "bel mare, anche questa è felicità.$"

DewfordTown_House1_Text_Zigzagoon:
	.string "ZIGZAGOON: Guguuh!$"

