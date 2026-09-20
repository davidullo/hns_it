SSAnne_B1F_Room2_Frlg_MapScripts::
	.byte 0

SSAnne_B1F_Room2_EventScript_Huey::
	trainerbattle_single TRAINER_SAILOR_HUEY, SSAnne_B1F_Room2_Text_HueyIntro, SSAnne_B1F_Room2_Text_HueyDefeat
	msgbox SSAnne_B1F_Room2_Text_HueyPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room2_Text_HueyIntro::
	.string "Anche noi marinai abbiamo POKéMON!$"

SSAnne_B1F_Room2_Text_HueyDefeat::
	.string "Ok, niente male.$"

SSAnne_B1F_Room2_Text_HueyPostBattle::
	.string "Abbiamo preso tutti i POKéMON\n"
	.string "mentre eravamo in mare.$"

