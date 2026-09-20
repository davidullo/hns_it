PacifidlogTown_House1_MapScripts::
	.byte 0

PacifidlogTown_House1_EventScript_Man::
	msgbox PacifidlogTown_House1_Text_RegiStory, MSGBOX_NPC
	end

PacifidlogTown_House1_EventScript_Woman::
	msgbox PacifidlogTown_House1_Text_SixDotsOpenThreeDoors, MSGBOX_NPC
	end

PacifidlogTown_House1_Text_RegiStory:
	.string "Nella regione di HOENN ci sono tre\n"
	.string "POKéMON che rappresentano la forza di\l"
	.string "roccia, ghiaccio e acciaio.\p"
	.string "Si dice che ognuno di loro si nasconda\n"
	.string "in fondo alle caverne.\p"
	.string "Questa è la storia che sentivo\n"
	.string "quando ero solo un bambino.$"

PacifidlogTown_House1_Text_SixDotsOpenThreeDoors:
	.string "“Sei punti aprono tre porte.”\p"
	.string "Lo diceva il nonno, ma non so\n"
	.string "cosa intendesse.$"

