Melemele_PlayerHouse_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Melemele_PlayerHouse_hns_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Melemele_PlayerHouse_hns_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_ALOLA_STATE, 1, Alola_Melemele_SamsonOakVillaIntro_Trigger
	.2byte 0


Alola_Melemele_SamsonOakVillaIntro_Trigger::
	lock
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVillaIntro_Trigger_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVillaIntro_Trigger_Text_0
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVillaIntro_Trigger_Movement_1
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVillaIntro_Trigger_Text_1, MSGBOX_AUTOCLOSE
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVillaIntro_Trigger_Movement_2
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVillaIntro_Trigger_Text_2, MSGBOX_AUTOCLOSE
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVillaIntro_Trigger_Movement_3
	waitmovement 0
	setvar VAR_ALOLA_STATE, 2
	release
	end


Alola_Melemele_SamsonOakVilla_Dialogue::
	lock
	faceplayer
	goto_if_set FLAG_BATTLED_TAPU_KOKO, Alola_Melemele_SamsonOakVilla_Dialogue_4
Alola_Melemele_SamsonOakVilla_Dialogue_2:
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_16
Alola_Melemele_SamsonOakVilla_Dialogue_14:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_10
	dynmultichoice 20, 4, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, Alola_Melemele_SamsonOakVilla_Dialogue_Text_11, Alola_Melemele_SamsonOakVilla_Dialogue_Text_12, Alola_Melemele_SamsonOakVilla_Dialogue_Text_13, Alola_Melemele_SamsonOakVilla_Dialogue_Text_14, Alola_Melemele_SamsonOakVilla_Dialogue_Text_15
	compare VAR_RESULT, 0
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_31
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_32
	compare VAR_RESULT, 2
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_33
	compare VAR_RESULT, 3
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_53
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_34, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_1:
	compare VAR_ALOLA_STATE, 3
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_10
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_2, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_3:
	goto_if_set FLAG_BATTLED_TAPU_BULU, Alola_Melemele_SamsonOakVilla_Dialogue_7
	goto Alola_Melemele_SamsonOakVilla_Dialogue_2

Alola_Melemele_SamsonOakVilla_Dialogue_4:
	goto_if_set FLAG_BATTLED_TAPU_LELE, Alola_Melemele_SamsonOakVilla_Dialogue_3
	goto Alola_Melemele_SamsonOakVilla_Dialogue_2

Alola_Melemele_SamsonOakVilla_Dialogue_7:
	goto_if_set FLAG_BATTLED_TAPU_FINI, Alola_Melemele_SamsonOakVilla_Dialogue_1
	goto Alola_Melemele_SamsonOakVilla_Dialogue_2

Alola_Melemele_SamsonOakVilla_Dialogue_10:
	msgbox Alola_Melemele_SamsonOakVillaIntro_Trigger_Text_0, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_0, MSGBOX_AUTOCLOSE
	giveitem ITEM_BEAST_BALL
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_1, MSGBOX_AUTOCLOSE
	setvar VAR_ALOLA_STATE, 4
	clearflag FLAG_HIDE_PHANT_OUTSIDE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_13:
	goto_if_set FLAG_DEFEATED_MELEMELE_TOTEM, Alola_Melemele_SamsonOakVilla_Dialogue_25
Alola_Melemele_SamsonOakVilla_Dialogue_23:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_9, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_15:
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_19
	goto Alola_Melemele_SamsonOakVilla_Dialogue_14

Alola_Melemele_SamsonOakVilla_Dialogue_16:
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_15
	goto Alola_Melemele_SamsonOakVilla_Dialogue_14

Alola_Melemele_SamsonOakVilla_Dialogue_19:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_13
	goto Alola_Melemele_SamsonOakVilla_Dialogue_14

Alola_Melemele_SamsonOakVilla_Dialogue_22:
	goto_if_set FLAG_DEFEATED_SAMSON_OAK, Alola_Melemele_SamsonOakVilla_Dialogue_40
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_3, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_55
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_8, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_24:
	goto_if_set FLAG_DEFEATED_ULAULA_TOTEM, Alola_Melemele_SamsonOakVilla_Dialogue_28
	goto Alola_Melemele_SamsonOakVilla_Dialogue_23

Alola_Melemele_SamsonOakVilla_Dialogue_25:
	goto_if_set FLAG_DEFEATED_AKALA_TOTEM, Alola_Melemele_SamsonOakVilla_Dialogue_24
	goto Alola_Melemele_SamsonOakVilla_Dialogue_23

Alola_Melemele_SamsonOakVilla_Dialogue_28:
	goto_if_set FLAG_DEFEATED_PONI_TOTEM, Alola_Melemele_SamsonOakVilla_Dialogue_22
	goto Alola_Melemele_SamsonOakVilla_Dialogue_23

Alola_Melemele_SamsonOakVilla_Dialogue_31:
	getcaughtmon SPECIES_MEOWTH_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_44
Alola_Melemele_SamsonOakVilla_Dialogue_43:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_23, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_32:
	getcaughtmon SPECIES_MAROWAK_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_47
Alola_Melemele_SamsonOakVilla_Dialogue_46:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_27, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_33:
	getcaughtmon SPECIES_VULPIX_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_50
Alola_Melemele_SamsonOakVilla_Dialogue_49:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_30, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_34:
	getcaughtmon SPECIES_RAICHU_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_68
	goto Alola_Melemele_SamsonOakVilla_Dialogue_46
	end

Alola_Melemele_SamsonOakVilla_Dialogue_52:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_33, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_40:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_2, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_44:
	getcaughtmon SPECIES_PERSIAN_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_58
	goto Alola_Melemele_SamsonOakVilla_Dialogue_43

Alola_Melemele_SamsonOakVilla_Dialogue_47:
	getcaughtmon SPECIES_DIGLETT_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_60
	goto Alola_Melemele_SamsonOakVilla_Dialogue_46

Alola_Melemele_SamsonOakVilla_Dialogue_50:
	getcaughtmon SPECIES_NINETALES_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_62
	goto Alola_Melemele_SamsonOakVilla_Dialogue_49

Alola_Melemele_SamsonOakVilla_Dialogue_53:
	getcaughtmon SPECIES_GEODUDE_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_64
	goto Alola_Melemele_SamsonOakVilla_Dialogue_52

Alola_Melemele_SamsonOakVilla_Dialogue_55:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_4
	trainerbattle_no_intro TRAINER_SAMSON_OAK_HNS, Alola_Melemele_SamsonOakVilla_Dialogue_Text_5
	special GivePartyMonMarineRibbon
	special HealPlayerParty
	setflag FLAG_DEFEATED_SAMSON_OAK
	setflag FLAG_FLYOVER_TAPU_KOKO
	setflag FLAG_FLYOVER_TAPU_LELE
	setflag FLAG_FLYOVER_TAPU_BULU
	setflag FLAG_FLYOVER_TAPU_FINI
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_6, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_7, MSGBOX_AUTOCLOSE
	setvar VAR_ALOLA_STATE, 3
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_58:
	getcaughtmon SPECIES_RATTATA_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_66
	goto Alola_Melemele_SamsonOakVilla_Dialogue_43

Alola_Melemele_SamsonOakVilla_Dialogue_60:
	getcaughtmon SPECIES_DUGTRIO_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_34
	goto Alola_Melemele_SamsonOakVilla_Dialogue_46

Alola_Melemele_SamsonOakVilla_Dialogue_62:
	getcaughtmon SPECIES_SANDSHREW_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_70
	goto Alola_Melemele_SamsonOakVilla_Dialogue_49

Alola_Melemele_SamsonOakVilla_Dialogue_64:
	getcaughtmon SPECIES_GRAVELER_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_72
	goto Alola_Melemele_SamsonOakVilla_Dialogue_52

Alola_Melemele_SamsonOakVilla_Dialogue_66:
	getcaughtmon SPECIES_RATICATE_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_74
	goto Alola_Melemele_SamsonOakVilla_Dialogue_43

Alola_Melemele_SamsonOakVilla_Dialogue_68:
	goto_if_unset FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_76
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_26, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_70:
	getcaughtmon SPECIES_SANDSLASH_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_79
	goto Alola_Melemele_SamsonOakVilla_Dialogue_49

Alola_Melemele_SamsonOakVilla_Dialogue_72:
	getcaughtmon SPECIES_GOLEM_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_81
	goto Alola_Melemele_SamsonOakVilla_Dialogue_52

Alola_Melemele_SamsonOakVilla_Dialogue_74:
	goto_if_unset FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_83
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_22, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_76:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_86
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_86
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_86
	setflag FLAG_CAUGHT_ALL_AKALA
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_16, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_17
	playfanfare MUS_HG_OBTAIN_EGG
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_24
	waitfanfare
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_21
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_79:
	getcaughtmon SPECIES_GRIMER_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_93
	goto Alola_Melemele_SamsonOakVilla_Dialogue_49

Alola_Melemele_SamsonOakVilla_Dialogue_81:
	getcaughtmon SPECIES_EXEGGUTOR_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_95
	goto Alola_Melemele_SamsonOakVilla_Dialogue_52

Alola_Melemele_SamsonOakVilla_Dialogue_83:
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_97
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_97
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_97
	setflag FLAG_CAUGHT_ALL_MELEMELE
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_16, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_17
	playfanfare MUS_HG_OBTAIN_EGG
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_18
	waitfanfare
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_21, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_86:
	setflag FLAG_CAUGHT_ALL_AKALA
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_16, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_17
	playfanfare MUS_HG_OBTAIN_EGG
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_24
	waitfanfare
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_107
Alola_Melemele_SamsonOakVilla_Dialogue_105:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_21
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_93:
	getcaughtmon SPECIES_MUK_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_113
	goto Alola_Melemele_SamsonOakVilla_Dialogue_49

Alola_Melemele_SamsonOakVilla_Dialogue_95:
	goto_if_unset FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_115
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_32, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_97:
	setflag FLAG_CAUGHT_ALL_MELEMELE
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_16, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_17
	playfanfare MUS_HG_OBTAIN_EGG
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_18
	waitfanfare
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_121
Alola_Melemele_SamsonOakVilla_Dialogue_119:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_21, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_104:
	playfanfare MUS_HG_BUG_CONTEST_1ST_PLACE
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_19, MSGBOX_AUTOCLOSE
	waitfanfare
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_25
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_106:
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_110
	goto Alola_Melemele_SamsonOakVilla_Dialogue_105

Alola_Melemele_SamsonOakVilla_Dialogue_107:
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_106
	goto Alola_Melemele_SamsonOakVilla_Dialogue_105

Alola_Melemele_SamsonOakVilla_Dialogue_110:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_104
	goto Alola_Melemele_SamsonOakVilla_Dialogue_105

Alola_Melemele_SamsonOakVilla_Dialogue_113:
	goto_if_unset FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_127
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_29, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_115:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_130
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_130
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_130
	setflag FLAG_CAUGHT_ALL_PONI
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_16, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_17
	playfanfare MUS_HG_OBTAIN_EGG
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_31
	waitfanfare
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_21, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_118:
	playfanfare MUS_HG_BUG_CONTEST_1ST_PLACE
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_19, MSGBOX_AUTOCLOSE
	waitfanfare
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_20, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_120:
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_124
	goto Alola_Melemele_SamsonOakVilla_Dialogue_119

Alola_Melemele_SamsonOakVilla_Dialogue_121:
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_120
	goto Alola_Melemele_SamsonOakVilla_Dialogue_119

Alola_Melemele_SamsonOakVilla_Dialogue_124:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_118
	goto Alola_Melemele_SamsonOakVilla_Dialogue_119

Alola_Melemele_SamsonOakVilla_Dialogue_127:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_137
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_137
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_137
	setflag FLAG_CAUGHT_ALL_ULAULA
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_16, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_17
	playfanfare MUS_HG_OBTAIN_EGG
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_28
	waitfanfare
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_21, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_130:
	setflag FLAG_CAUGHT_ALL_PONI
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_16, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_17
	playfanfare MUS_HG_OBTAIN_EGG
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_31
	waitfanfare
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_147
Alola_Melemele_SamsonOakVilla_Dialogue_145:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_21, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_137:
	setflag FLAG_CAUGHT_ALL_ULAULA
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_16, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_17
	playfanfare MUS_HG_OBTAIN_EGG
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_28
	waitfanfare
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_156
Alola_Melemele_SamsonOakVilla_Dialogue_154:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_21, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_144:
	playfanfare MUS_HG_BUG_CONTEST_1ST_PLACE
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_19, MSGBOX_AUTOCLOSE
	waitfanfare
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_25, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_146:
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_150
	goto Alola_Melemele_SamsonOakVilla_Dialogue_145

Alola_Melemele_SamsonOakVilla_Dialogue_147:
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_146
	goto Alola_Melemele_SamsonOakVilla_Dialogue_145

Alola_Melemele_SamsonOakVilla_Dialogue_150:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_144
	goto Alola_Melemele_SamsonOakVilla_Dialogue_145

Alola_Melemele_SamsonOakVilla_Dialogue_153:
	playfanfare MUS_HG_BUG_CONTEST_1ST_PLACE
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_19, MSGBOX_AUTOCLOSE
	waitfanfare
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_25, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_155:
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_159
	goto Alola_Melemele_SamsonOakVilla_Dialogue_154

Alola_Melemele_SamsonOakVilla_Dialogue_156:
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_155
	goto Alola_Melemele_SamsonOakVilla_Dialogue_154

Alola_Melemele_SamsonOakVilla_Dialogue_159:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_153
	goto Alola_Melemele_SamsonOakVilla_Dialogue_154


Alola_Melemele_SamsonOakVillaIntro_Trigger_Movement_0:
	emote_exclamation_mark
	face_down
	step_end

Alola_Melemele_SamsonOakVillaIntro_Trigger_Movement_1:
	walk_down
	walk_left
	face_down
	step_end

Alola_Melemele_SamsonOakVillaIntro_Trigger_Movement_2:
	walk_in_place_down
	walk_in_place_down
	step_end

Alola_Melemele_SamsonOakVillaIntro_Trigger_Movement_3:
	walk_right
	walk_up
	face_right
	step_end

Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0:
	emote_exclamation_mark
	step_end

Alola_Melemele_SamsonOakVillaIntro_Trigger_Text_0:
	.string "Alola, {PLAYER}!$"

Alola_Melemele_SamsonOakVillaIntro_Trigger_Text_1:
	.string "Sono contento che tu sia qui!\n"
	.string "Benvenuto nella mia villa!\p"
	.string "Resto qui mentre studio le\n"
	.string "ISOLE DI ALOLA e la loro somiglianza\l"
	.string "con la regione di ALOLA.\p"
	.string "Mi interessa in particolare il\n"
	.string "fenomeno delle “Forme Regionali”.$"

Alola_Melemele_SamsonOakVillaIntro_Trigger_Text_2:
	.string "Sembri davvero in gamba.\p"
	.string "Saresti perfetto per il mio studio\n"
	.string "delle ISOLE DI ALOLA!\p"
	.string "Esplora tutto ciò che offrono le ISOLE,\n"
	.string "e se trovi POKéMON familiari\l"
	.string "simili a quelli di KANTO…\l"
	.string "torna e mostrami il tuo POKéDEX!\p"
	.string "Sarò qui ad aspettare di sentire\n"
	.string "i tuoi progressi!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_0:
	.string "Wow!\n"
	.string "Hai visto le Divinità Guardiane!\p"
	.string "Lavoro incredibile, {PLAYER}.\p"
	.string "L'ho trovato mentre giravo.\p"
	.string "Non so bene a cosa serva,\n"
	.string "ma dovresti prenderlo.$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_1:
	.string "Le ISOLE DI ALOLA devono essere speciali\n"
	.string "se sono venuti i Guardiani in persona!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_2:
	.string "Grazie per il tuo aiuto con le ricerche,\n"
	.string "{PLAYER}!\p"
	.string "Grazie a te la nostra conoscenza delle\n"
	.string "ISOLE DI ALOLA è molto migliorata!\p"
	.string "Spero che continuerai a esplorare le\n"
	.string "ISOLE per scoprire tutti i segreti\l"
	.string "che nascondono!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_3:
	.string "Alola {PLAYER}!\p"
	.string "Quindi hai sconfitto tutti i POKéMON\n"
	.string "Totem delle ISOLE, vero?\p"
	.string "Un vero bellissimo traguardo!\p"
	.string "È passato abbastanza tempo…\p"
	.string "Direi che è ora di fare una lotta,\n"
	.string "non credi?$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_4:
	.string "Perfetto!\n"
	.string "Non andrò affatto leggero con te!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_5:
	.string "Incredibile, {PLAYER}!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_6:
	.string "Wow, {PLAYER}!\n"
	.string "Sei davvero un Allenatore forte!\p"
	.string "Ti sei guadagnato un segreto che\n"
	.string "custodivo su queste ISOLE…\p"
	.string "Non sono il solo ad aver notato una\n"
	.string "forte somiglianza tra le ISOLE DI ALOLA\l"
	.string "e la regione di ALOLA…\p"
	.string "Sembra che gli stessi Tapu Guardiani\n"
	.string "abbiano visitato le ISOLE.\p"
	.string "Se li vedi volare sopra le ISOLE, vai\n"
	.string "ai totem… Potrebbero essere lì \l"
	.string "ad aspettarti!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_7:
	.string "Cosa aspetti, {PLAYER}?\n"
	.string "Vai là fuori ed esplora!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_8:
	.string "Nessun problema, {PLAYER}!\p"
	.string "Prenditi il tuo tempo per prepararti alla\n"
	.string "lotta, e torna quando sei\l"
	.string "pronto!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_9:
	.string "Alola {PLAYER}!\p"
	.string "Hai trovato tutte le varianti di Alola\n"
	.string "delle ISOLE, ma hai battuto tutti i\l"
	.string "POKéMON Totem?\p"
	.string "Cerca uno strano pilastro su\n"
	.string "ogni isola, i POKéMON Totem lo\l"
	.string "staranno sorvegliando!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_10:
	.string "Ciao di nuovo, {PLAYER}!\p"
	.string "Come procedono le ricerche sulle ISOLE\n"
	.string "DI ALOLA?\p"
	.string "Vuoi aggiornarmi sui tuoi progressi\n"
	.string "riguardo a un'isola in particolare?$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_11:
	.string "ISOLA MELEMELE$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_12:
	.string "ISOLA AKALA$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_13:
	.string "ISOLA ULA'ULA$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_14:
	.string "ISOLA PONI$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_15:
	.string "Non ora.$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_16:
	.string "Fammi dare un'occhiata al tuo POKéDEX{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_17:
	.string "Wow, {PLAYER}!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_18:
	.string "Hai trovato tutte le forme di Alola\n"
	.string "sull'ISOLA DI MELEMELE!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_19:
	.string "E hai trovato tutte le forme\n"
	.string "di Alola anche sulle altre ISOLE!\p"
	.string "È fantastico, {PLAYER}!\p"
	.string "Dovresti essere molto fiero di te!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_20:
	.string "Mi hai aiutato a confermare che tutte\n"
	.string "le forme di Alola sono presenti sulle\l"
	.string "ISOLE DI ALOLA!\p"
	.string "Vorrei il tuo aiuto per un'altra\n"
	.string "cosa…\p"
	.string "Puoi indagare sui POKéMON Totem\n"
	.string "che si dice proteggano i totem\l"
	.string "di ogni ISOLA?\p"
	.string "Ma attento! Quei POKéMON Totem\n"
	.string "sono molto più forti dei loro\l"
	.string "simili normali…\p"
	.string "Chissà chi ti osserva per vedere\n"
	.string "se sei un degno avversario!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_21:
	.string "Continua a esplorare le altre ISOLE e\n"
	.string "riferiscimi i tuoi progressi!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_22:
	.string "Hai già trovato tutte le forme\n"
	.string "di Alola sull'ISOLA DI MELEMELE!\p"
	.string "Ottimo lavoro!\p"
	.string "Continua a esplorare le altre ISOLE e\n"
	.string "riferiscimi i tuoi progressi!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_23:
	.string "Fammi dare un'occhiata al tuo POKéDEX{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\p"
	.string "Sembra che tu non abbia ancora trovato\n"
	.string "tutte le varianti di Alola su MELEMELE.\l"
	.string "\p"
	.string "Ho sentito che MELEMELE ha {COLOR RED}4 {COLOR DARK_GRAY}varianti\n"
	.string "di Alola da trovare…\p"
	.string "{COLOR RED}RATTATA{COLOR DARK_GRAY}, {COLOR RED}RATICATE{COLOR DARK_GRAY}, {COLOR RED}MEOWTH{COLOR DARK_GRAY} e\n"
	.string "{COLOR RED}PERSIAN{COLOR DARK_GRAY}.\p"
	.string "Continua a cercare e torna quando\n"
	.string "le avrai catturate tutte!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_24:
	.string "Hai trovato tutte le forme di Alola\n"
	.string "sull'ISOLA DI AKALA!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_25:
	.string "Ora che mi hai aiutato a confermare che\n"
	.string "tutte le forme di Alola sono presenti\l"
	.string "sulle ISOLE DI ALOLA.\p"
	.string "Vorrei il tuo aiuto per un'altra\n"
	.string "cosa…\p"
	.string "Puoi indagare sui POKéMON Totem\n"
	.string "che si dice proteggano i totem\l"
	.string "di ogni isola?\p"
	.string "Ma attento! Quei POKéMON Totem\n"
	.string "sono molto più forti dei loro\l"
	.string "simili normali…\p"
	.string "Chissà chi ti osserva per vedere\n"
	.string "se sei un degno avversario!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_26:
	.string "Hai già trovato tutte le forme\n"
	.string "di Alola sull'ISOLA DI AKALA!\p"
	.string "Ottimo lavoro!\p"
	.string "Continua a esplorare le altre ISOLE e\n"
	.string "riferiscimi i tuoi progressi!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_27:
	.string "Fammi dare un'occhiata al tuo POKéDEX{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\p"
	.string "Sembra che tu non abbia ancora trovato\n"
	.string "tutte le varianti di Alola su AKALA.\l"
	.string "\p"
	.string "Ho sentito che AKALA ha {COLOR RED}4 {COLOR DARK_GRAY}varianti\n"
	.string "di Alola da trovare…\p"
	.string "{COLOR RED}RAICHU{COLOR DARK_GRAY}, {COLOR RED}MAROWAK{COLOR DARK_GRAY}, {COLOR RED}DIGLETT{COLOR DARK_GRAY} e {COLOR RED}DUGTRIO{COLOR DARK_GRAY}.\p"
	.string "Continua a cercare e torna quando\n"
	.string "le avrai catturate tutte!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_28:
	.string "Hai trovato tutte le forme di Alola\n"
	.string "sull'ISOLA DI ULA'ULA!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_29:
	.string "Hai già trovato tutte le forme\n"
	.string "di Alola sull'ISOLA DI ULA'ULA!\p"
	.string "Ottimo lavoro!\p"
	.string "Continua a esplorare le altre ISOLE e\n"
	.string "riferiscimi i tuoi progressi!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_30:
	.string "Fammi dare un'occhiata al tuo POKéDEX{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\p"
	.string "Sembra che tu non abbia ancora trovato\n"
	.string "tutte le varianti di Alola su ULA'ULA.\l"
	.string "\p"
	.string "Ho sentito che ULA'ULA ha {COLOR RED}6 {COLOR DARK_GRAY}varianti\n"
	.string "di Alola da trovare…\p"
	.string "{COLOR RED}VULPIX{COLOR DARK_GRAY}, {COLOR RED}NINETALES{COLOR DARK_GRAY}, {COLOR RED}SANDSHREW{COLOR DARK_GRAY}, {COLOR RED}SANDSLASH{COLOR DARK_GRAY},\n"
	.string "{COLOR RED}GRIMER{COLOR DARK_GRAY} e {COLOR RED}MUK{COLOR DARK_GRAY}.\p"
	.string "Continua a cercare e torna quando\n"
	.string "le avrai catturate tutte!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_31:
	.string "Hai trovato tutte le varianti di Alola che\n"
	.string "vivono su PONI ISLE!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_32:
	.string "Sembra che tu abbia già trovato tutte le\n"
	.string "varianti di Alola su PONI ISLE!\p"
	.string "Ottimo lavoro!\p"
	.string "Continua a esplorare le altre ISOLE e\n"
	.string "aggiornami sui tuoi progressi!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_33:
	.string "Fammi dare un'occhiata al tuo POKéDEX{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\p"
	.string "Sembra che tu non abbia ancora trovato\n"
	.string "tutte le varianti di Alola su PONI.\l"
	.string "\p"
	.string "Ho sentito che PONI ha {COLOR RED}4 {COLOR DARK_GRAY}varianti\n"
	.string "di Alola da trovare…\p"
	.string "{COLOR RED}GEODUDE{COLOR DARK_GRAY}, {COLOR RED}GRAVELER{COLOR DARK_GRAY}, {COLOR RED}GOLEM{COLOR DARK_GRAY} e\n"
	.string "{COLOR RED}EXEGGUTOR{COLOR DARK_GRAY}.\p"
	.string "Continua a cercare e torna quando\n"
	.string "le avrai catturate tutte!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_34:
	.string "Nessun problema, {PLAYER}!\p"
	.string "Torna quando vuoi aggiornarmi sulle tue\n"
	.string "scoperte riguardo alle ISOLE DI ALOLA!$"
