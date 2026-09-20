AquaHideout_1F_MapScripts::
	.byte 0

@ The below two entrance guards give hints about what to do to progress the story
AquaHideout_1F_EventScript_HideoutEntranceGrunt1::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint1
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint1
	msgbox AquaHideout_1F_Text_OurBossIsSnatchingSomething, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint1::
	msgbox AquaHideout_1F_Text_WhereMightMagmaHideoutBe, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint1::
	msgbox AquaHideout_1F_Text_BossWentToJackASubmarine, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_HideoutEntranceGrunt2::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint2
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint2
	msgbox AquaHideout_1F_Text_BossIsOnRoute122, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint2::
	msgbox AquaHideout_1F_Text_TeamMagmaAtMtChimney, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint2::
	msgbox AquaHideout_1F_Text_BossIsInSlateportCity, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_1, AquaHideout_1F_Text_Grunt1Intro, AquaHideout_1F_Text_Grunt1Defeat, AquaHideout_1F_EventScript_Grunt1Defeated
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_1F_EventScript_Grunt1Defeated::
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_Text_OurBossIsSnatchingSomething:
	.string "Cosa? Cosa? Cosa vuoi dal\n"
	.string "TEAM ACQUA?\p"
	.string "Il nostro CAPO non c'è! È andato a\n"
	.string "fare uno Scippo importante!\p"
	.string "… …\n"
	.string "Dov'è andato?\p"
	.string "Wahaha! Pensi davvero che ti dica\n"
	.string "una cosa così importante?$"

AquaHideout_1F_Text_WhereMightMagmaHideoutBe:
	.string "Cosa? Cosa?\n"
	.string "Sei un recluta del TEAM MAGMA?\p"
	.string "Ho saputo che il TEAM MAGMA vuole\n"
	.string "risvegliare un POKéMON fortissimo\l"
	.string "nel loro RIFUGIO.\p"
	.string "Ma dov'è il loro RIFUGIO?$"

AquaHideout_1F_Text_BossWentToJackASubmarine:
	.string "Cosa? Cosa? Cosa vuoi dal\n"
	.string "TEAM ACQUA?\p"
	.string "Il nostro CAPO non c'è!\n"
	.string "È andato a rubare un sottomarino!\p"
	.string "… …\n"
	.string "Dov'è andato?\p"
	.string "Wahaha! Pensi davvero che ti dica\n"
	.string "una cosa così importante?$"

AquaHideout_1F_Text_BossIsOnRoute122:
	.string "Cosa? Cosa? Cosa vuoi dal\n"
	.string "TEAM ACQUA?\p"
	.string "Il nostro CAPO non c'è! È in viaggio\n"
	.string "verso MT. PYRE sul PERCORSO 122!\p"
	.string "… …\n"
	.string "Perché è andato?\p"
	.string "Wahaha! Pensi davvero che ti dica\n"
	.string "una cosa così importante?$"

AquaHideout_1F_Text_TeamMagmaAtMtChimney:
	.string "Cosa? Cosa?\n"
	.string "Sei un recluta del TEAM MAGMA?\p"
	.string "Ho saputo che il TEAM MAGMA è\n"
	.string "dopo un POKéMON fortissimo\p"
	.string "al MT. CENERE. Come sarà?$"

AquaHideout_1F_Text_BossIsInSlateportCity:
	.string "Cosa? Cosa? Cosa vuoi dal\n"
	.string "TEAM ACQUA?\p"
	.string "Il nostro CAPO non c'è!\n"
	.string "È in viaggio verso PORTALBA!\p"
	.string "… …\n"
	.string "Perché è andato?\p"
	.string "Wahaha! Pensi davvero che ti dica\n"
	.string "una cosa così importante?$"

AquaHideout_1F_Text_Grunt1Intro:
	.string "Ayiyiyi!\n"
	.string "Visto un tipo sospetto!$"

AquaHideout_1F_Text_Grunt1Defeat:
	.string "Grrrrr…\n"
	.string "Ho perso!$"

AquaHideout_1F_Text_Grunt1PostBattle:
	.string "Ho perso per la SQUADRA,\n"
	.string "ma ho fatto il mio dovere…$"

