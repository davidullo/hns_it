AlolaWater_hns_MapScripts::
	.byte 0


Alola_MelemeleSea_TrainerBattleSwimmer::
	trainerbattle_single TRAINER_MELEMELE_SWIMMER_2_HNS, Alola_MelemeleSea_TrainerBattleSwimmer_Text_0, Alola_MelemeleSea_TrainerBattleSwimmer_Text_1
	msgbox Alola_MelemeleSea_TrainerBattleSwimmer_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Alola_MelemeleSea_TrainerBattleSwimmer_Text_0:
	.string "Che mare aperto!$"

Alola_MelemeleSea_TrainerBattleSwimmer_Text_1:
	.string "Ahi,\ncrampo…$"

Alola_MelemeleSea_TrainerBattleSwimmer_Text_2:
	.string "Qui le correnti sono forti.\n"
	.string "E attirano POKéMON forti!$"
