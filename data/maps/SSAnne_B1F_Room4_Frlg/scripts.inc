SSAnne_B1F_Room4_Frlg_MapScripts::
	.byte 0

SSAnne_B1F_Room4_EventScript_Leonard::
	trainerbattle_single TRAINER_SAILOR_LEONARD, SSAnne_B1F_Room4_Text_LeonardIntro, SSAnne_B1F_Room4_Text_LeonardDefeat
	msgbox SSAnne_B1F_Room4_Text_LeonardPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room4_EventScript_Duncan::
	trainerbattle_single TRAINER_SAILOR_DUNCAN, SSAnne_B1F_Room4_Text_DuncanIntro, SSAnne_B1F_Room4_Text_DuncanDefeat
	msgbox SSAnne_B1F_Room4_Text_DuncanPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room4_Text_LeonardIntro::
	.string "Sai cosa dicono dei marinai\n"
	.string "e delle lotte?$"

SSAnne_B1F_Room4_Text_LeonardDefeat::
	.string "Giusto!\n"
	.string "Bel lotta, amico!$"

SSAnne_B1F_Room4_Text_LeonardPostBattle::
	.string "Ahahah!\n"
	.string "Vuoi fare il marinaio, amico?$"

SSAnne_B1F_Room4_Text_DuncanIntro::
	.string "Forza, vieni!\n"
	.string "È in gioco l'orgoglio del marinaio!$"

SSAnne_B1F_Room4_Text_DuncanDefeat::
	.string "Il tuo spirito mi ha affondato!$"

SSAnne_B1F_Room4_Text_DuncanPostBattle::
	.string "Hai visto il GURU DELLA PESCA a\n"
	.string "ARANCIOPOLI?$"

