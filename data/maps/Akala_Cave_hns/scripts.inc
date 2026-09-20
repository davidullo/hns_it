Akala_Cave_hns_MapScripts::
	.byte 0


Alola_Melemele_BattleMarowak::
	lock
	faceplayer
	setflag FLAG_BATTLED_MAROWAK
	playmoncry SPECIES_MAROWAK_ALOLA, 0
	msgbox Alola_Melemele_BattleMarowak_Text_0, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_MAROWAK_ALOLA, 60
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Alola_Melemele_BattleMarowak_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Alola_Melemele_BattleMarowak_3
	release
	end

	release
	end

Alola_Melemele_BattleMarowak_2:
	setflag FLAG_HIDE_MAROWAK_ALOLA
	removeobject Alola_Melemele_Marowak
	release
	end

Alola_Melemele_BattleMarowak_3:
	setflag FLAG_HIDE_MAROWAK_ALOLA
	removeobject Alola_Melemele_Marowak
	release
	end


Alola_Melemele_BattleDugtrio::
	lock
	faceplayer
	setflag FLAG_BATTLED_DUGTRIO
	playmoncry SPECIES_DUGTRIO_ALOLA, 0
	msgbox Alola_Melemele_BattleDugtrio_Text_0, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_DUGTRIO_ALOLA, 60
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Alola_Melemele_BattleDugtrio_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Alola_Melemele_BattleDugtrio_3
	release
	end

	release
	end

Alola_Melemele_BattleDugtrio_2:
	setflag FLAG_HIDE_DUGTRIO_ALOLA
	removeobject Alola_Melemele_Dugtrio
	release
	end

Alola_Melemele_BattleDugtrio_3:
	setflag FLAG_HIDE_DUGTRIO_ALOLA
	removeobject Alola_Melemele_Dugtrio
	release
	end


Alola_Akala_Cave_FindItem1::
	finditem ITEM_CARBOS, 1
	end


Alola_Akala_Cave_FindItem2::
	finditem ITEM_HP_UP, 1
	end


Alola_AkalaCave_TrainerBattleHiker::
	trainerbattle_single TRAINER_AKALA_CAVE_HIKER_HNS, Alola_AkalaCave_TrainerBattleHiker_Text_0, Alola_AkalaCave_TrainerBattleHiker_Text_1
	msgbox Alola_AkalaCave_TrainerBattleHiker_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Alola_AkalaCave_TrainerBattlePicnicker::
	trainerbattle_single TRAINER_AKALA_CAVE_PICNICKER_HNS, Alola_AkalaCave_TrainerBattlePicnicker_Text_0, Alola_AkalaCave_TrainerBattlePicnicker_Text_1
	msgbox Alola_AkalaCave_TrainerBattlePicnicker_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Alola_AkalaCave_TrainerBattleCamper::
	trainerbattle_single TRAINER_AKALA_CAVE_CAMPER_HNS, Alola_AkalaCave_TrainerBattleCamper_Text_0, Alola_AkalaCave_TrainerBattleCamper_Text_1
	msgbox Alola_AkalaCave_TrainerBattleCamper_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Alola_Melemele_BattleMarowak_Text_0:
	.string "Raah!$"

Alola_Melemele_BattleDugtrio_Text_0:
	.string "Cia-Cia!$"

Alola_AkalaCave_TrainerBattleHiker_Text_0:
	.string "Se sei arrivato fin qui su,\nsei tosto!$"

Alola_AkalaCave_TrainerBattleHiker_Text_1:
	.string "Più tosto di me!$"

Alola_AkalaCave_TrainerBattleHiker_Text_2:
	.string "Ho smesso di salire perché\n"
	.string "faceva troppo caldo.\p"
	.string "Sembra che qualcuno accenda un fuoco\n"
	.string "sulla vetta…$"

Alola_AkalaCave_TrainerBattlePicnicker_Text_0:
	.string "Camminare mi ha stancato,\nfacciamo una lotta!$"

Alola_AkalaCave_TrainerBattlePicnicker_Text_1:
	.string "Che rinfrescata!$"

Alola_AkalaCave_TrainerBattlePicnicker_Text_2:
	.string "Di solito non mi stanco,\n"
	.string "ma il caldo della grotta sfida!$"

Alola_AkalaCave_TrainerBattleCamper_Text_0:
	.string "Guardate!\nHo catturato POKéMON forti!$"

Alola_AkalaCave_TrainerBattleCamper_Text_1:
	.string "Niente male,\nma non abbastanza!$"

Alola_AkalaCave_TrainerBattleCamper_Text_2:
	.string "Fa caldo qui, o sono solo io?$"
