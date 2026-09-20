SSAnne_B1F_Room1_Frlg_MapScripts::
	.byte 0

SSAnne_B1F_Room1_EventScript_Barny::
	trainerbattle_single TRAINER_FISHERMAN_BARNY, SSAnne_B1F_Room1_Text_BarnyIntro, SSAnne_B1F_Room1_Text_BarnyDefeat
	msgbox SSAnne_B1F_Room1_Text_BarnyPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room1_EventScript_Phillip::
	trainerbattle_single TRAINER_SAILOR_PHILLIP, SSAnne_B1F_Room1_Text_PhillipIntro, SSAnne_B1F_Room1_Text_PhillipDefeat
	msgbox SSAnne_B1F_Room1_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room1_Text_PhillipIntro::
	.string "Amico, se perdi finisci\n"
	.string "sulla passerella!$"

SSAnne_B1F_Room1_Text_PhillipDefeat::
	.string "Argh!\n"
	.string "Battuto da un bambino!$"

SSAnne_B1F_Room1_Text_PhillipPostBattle::
	.string "Quando siamo in mare aperto,\n"
	.string "passano POKéMON medusa.$"

SSAnne_B1F_Room1_Text_BarnyIntro::
	.string "Ciao, straniero!\p"
	.string "Non so se vieni dal mare\n"
	.string "o dai monti, ma fermati a parlare.\p"
	.string "I miei POKéMON vengono dal mare.$"

SSAnne_B1F_Room1_Text_BarnyDefeat::
	.string "Accidenti!\n"
	.string "Me lo sono fatto scappare!$"

SSAnne_B1F_Room1_Text_BarnyPostBattle::
	.string "Volevo fare di te\n"
	.string "il mio assistente!$"

