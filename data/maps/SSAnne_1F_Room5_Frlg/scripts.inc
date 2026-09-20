SSAnne_1F_Room5_Frlg_MapScripts::
	.byte 0

SSAnne_1F_Room5_EventScript_Arthur::
	trainerbattle_single TRAINER_GENTLEMAN_ARTHUR, SSAnne_1F_Room5_Text_ArthurIntro, SSAnne_1F_Room5_Text_ArthurDefeat
	msgbox SSAnne_1F_Room5_Text_ArthurPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room5_Text_ArthurIntro::
	.string "Tu, insolente ragazzino!\n"
	.string "Come osi irrompere!$"

SSAnne_1F_Room5_Text_ArthurDefeat::
	.string "Humph! Ragazzo maleducato!\n"
	.string "Non hai senso di cortesia!$"

SSAnne_1F_Room5_Text_ArthurPostBattle::
	.string "Voglio essere lasciato solo!\n"
	.string "Fuori!$"

