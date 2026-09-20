SSAnne_2F_Room4_Frlg_MapScripts::
	.byte 0

SSAnne_2F_Room4_EventScript_Lamar::
	trainerbattle_single TRAINER_GENTLEMAN_LAMAR, SSAnne_2F_Room4_Text_LamarIntro, SSAnne_2F_Room4_Text_LamarDefeat
	msgbox SSAnne_2F_Room4_Text_LamarPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_2F_Room4_EventScript_Dawn::
	trainerbattle_single TRAINER_LASS_DAWN, SSAnne_2F_Room4_Text_DawnIntro, SSAnne_2F_Room4_Text_DawnDefeat
	msgbox SSAnne_2F_Room4_Text_DawnPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_2F_Room4_Text_LamarIntro::
	.string "Cosa reputi più degno,\n"
	.string "un POKéMON forte o uno raro?$"

SSAnne_2F_Room4_Text_LamarDefeat::
	.string "Ti devo fare i complimenti!$"

SSAnne_2F_Room4_Text_LamarPostBattle::
	.string "Io preferisco i POKéMON\n"
	.string "forti e rari.$"

SSAnne_2F_Room4_Text_DawnIntro::
	.string "Non mi pare di averti visto alla\n"
	.string "festa?$"

SSAnne_2F_Room4_Text_DawnDefeat::
	.string "Vai piano!$"

SSAnne_2F_Room4_Text_DawnPostBattle::
	.string "Oh, adoro i tuoi POKéMON forti!\n"
	.string "Oh, come ti invidio!$"

