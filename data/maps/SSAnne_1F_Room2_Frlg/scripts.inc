SSAnne_1F_Room2_Frlg_MapScripts::
	.byte 0

SSAnne_1F_Room2_EventScript_Woman::
	msgbox SSAnne_1F_Room2_Text_CruisingAroundWorld, MSGBOX_NPC
	end

SSAnne_1F_Room2_EventScript_Ann::
	trainerbattle_single TRAINER_LASS_ANN, SSAnne_1F_Room2_Text_AnnIntro, SSAnne_1F_Room2_Text_AnnDefeat
	msgbox SSAnne_1F_Room2_Text_AnnPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room2_EventScript_Tyler::
	trainerbattle_single TRAINER_YOUNGSTER_TYLER, SSAnne_1F_Room2_Text_TylerIntro, SSAnne_1F_Room2_Text_TylerDefeat
	msgbox SSAnne_1F_Room2_Text_TylerPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room2_Text_TylerIntro::
	.string "Adoro i POKéMON!\n"
	.string "E tu?$"

SSAnne_1F_Room2_Text_TylerDefeat::
	.string "Wow! \n"
	.string "Sei grande!$"

SSAnne_1F_Room2_Text_TylerPostBattle::
	.string "Senti, senti!\n"
	.string "Facciamo amicizia, ok?\p"
	.string "Così possiamo scambiare POKéMON e\n"
	.string "fare cose.$"

SSAnne_1F_Room2_Text_AnnIntro::
	.string "Ho collezionato questi POKéMON\n"
	.string "da tutto il mondo!$"

SSAnne_1F_Room2_Text_AnnDefeat::
	.string "Oh, no!\n"
	.string "Li ho presi in giro per il mondo!$"

SSAnne_1F_Room2_Text_AnnPostBattle::
	.string "Hai fatto male ai miei POKéMON!\p"
	.string "Pretendo che li curi al\n"
	.string "CENTRO POKéMON!$"

SSAnne_1F_Room2_Text_CruisingAroundWorld::
	.string "Facciamo il giro del mondo,\n"
	.string "io e i miei figli.$"

