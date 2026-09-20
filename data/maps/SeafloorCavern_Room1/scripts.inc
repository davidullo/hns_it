SeafloorCavern_Room1_MapScripts::
	.byte 0

SeafloorCavern_Room1_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_1, SeafloorCavern_Room1_Text_Grunt1Intro, SeafloorCavern_Room1_Text_Grunt1Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_2, SeafloorCavern_Room1_Text_Grunt2Intro, SeafloorCavern_Room1_Text_Grunt2Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_Text_Grunt1Intro:
	.string "Non ci serve un bambino qui!\n"
	.string "Torna a casa, su!$"

SeafloorCavern_Room1_Text_Grunt1Defeat:
	.string "Voglio andare a casa…$"

SeafloorCavern_Room1_Text_Grunt1PostBattle:
	.string "Voglio una promozione per poter\n"
	.string "comandare le RECLUTE…$"

SeafloorCavern_Room1_Text_Grunt2Intro:
	.string "Quel sottomarino… È minuscolo dentro.\n"
	.string "Ho male dappertutto!$"

SeafloorCavern_Room1_Text_Grunt2Defeat:
	.string "Perdere mi fa arrabbiare!$"

SeafloorCavern_Room1_Text_Grunt2PostBattle:
	.string "Quel sottomarino che abbiamo rubato,\n"
	.string "è brutale come viaggio.\l"
	.string "È troppo stretto là dentro!$"

