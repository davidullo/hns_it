SeafloorCavern_Room4_MapScripts::
	.byte 0

SeafloorCavern_Room4_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_3, SeafloorCavern_Room4_Text_Grunt3Intro, SeafloorCavern_Room4_Text_Grunt3Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_4, SeafloorCavern_Room4_Text_Grunt4Intro, SeafloorCavern_Room4_Text_Grunt4Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_Text_Grunt3Intro:
	.string "Chi sei?\n"
	.string "Da dove sei entrato?$"

SeafloorCavern_Room4_Text_Grunt3Defeat:
	.string "Ho perso…$"

SeafloorCavern_Room4_Text_Grunt3PostBattle:
	.string "Non trovo l'uscita!\p"
	.string "Non ho paura. Non fraintendere!$"

SeafloorCavern_Room4_Text_Grunt4Intro:
	.string "Chi sei?\n"
	.string "Dove credi di andare?$"

SeafloorCavern_Room4_Text_Grunt4Defeat:
	.string "Non sono riuscito a vincere!$"

SeafloorCavern_Room4_Text_Grunt4PostBattle:
	.string "Il mio compagno ha dimenticato la mappa\n"
	.string "nel sottomarino!\p"
	.string "Ti sembra utile?$"

