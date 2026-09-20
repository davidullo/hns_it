SSAnne_B1F_Room3_Frlg_MapScripts::
	.byte 0

SSAnne_B1F_Room3_EventScript_Dylan::
	trainerbattle_single TRAINER_SAILOR_DYLAN, SSAnne_B1F_Room3_Text_DylanIntro, SSAnne_B1F_Room3_Text_DylanDefeat
	msgbox SSAnne_B1F_Room3_Text_DylanPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room3_Text_DylanIntro::
	.string "Mi piacciono i tipi tosti come te!$"

SSAnne_B1F_Room3_Text_DylanDefeat::
	.string "Argh!\n"
	.string "Che sconfitta!$"

SSAnne_B1F_Room3_Text_DylanPostBattle::
	.string "I POKéMON marini vivono in fondo al mare.\n"
	.string "Serve una CANNA per pescarli!$"

