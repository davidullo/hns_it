SSAnne_2F_Room2_Frlg_MapScripts::
	.byte 0

SSAnne_2F_Room2_EventScript_Dale::
	trainerbattle_single TRAINER_FISHERMAN_DALE, SSAnne_2F_Room2_Text_DaleIntro, SSAnne_2F_Room2_Text_DaleDefeat
	msgbox SSAnne_2F_Room2_Text_DalePostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_2F_Room2_EventScript_Brooks::
	trainerbattle_single TRAINER_GENTLEMAN_BROOKS, SSAnne_2F_Room2_Text_BrooksIntro, SSAnne_2F_Room2_Text_BrooksDefeat
	msgbox SSAnne_2F_Room2_Text_BrooksPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_2F_Room2_Text_BrooksIntro::
	.string "Sfidare i giovani mi\n"
	.string "mantiene giovane.$"

SSAnne_2F_Room2_Text_BrooksDefeat::
	.string "Bella sfida!\n"
	.string "Ah, mi sento di nuovo giovane!$"

SSAnne_2F_Room2_Text_BrooksPostBattle::
	.string "Quindici anni fa\n"
	.string "avrei vinto io!$"

SSAnne_2F_Room2_Text_DaleIntro::
	.string "Guarda cosa ho pescato!$"

SSAnne_2F_Room2_Text_DaleDefeat::
	.string "Sono a secco!$"

SSAnne_2F_Room2_Text_DalePostBattle::
	.string "Festa?\p"
	.string "La festa della nave ormai\n"
	.string "sarà finita.$"

