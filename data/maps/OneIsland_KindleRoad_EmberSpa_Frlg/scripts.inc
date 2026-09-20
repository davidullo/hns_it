OneIsland_KindleRoad_EmberSpa_Frlg_MapScripts::
	.byte 0

OneIsland_KindleRoad_EmberSpa_EventScript_OldMan::
	msgbox OneIsland_KindleRoad_EmberSpa_Text_WaterWarmsMeToCore, MSGBOX_NPC
	end

OneIsland_KindleRoad_EmberSpa_EventScript_BaldingMan1::
	msgbox OneIsland_KindleRoad_EmberSpa_Text_EnjoyBowlOfChowder, MSGBOX_NPC
	end

OneIsland_KindleRoad_EmberSpa_EventScript_BaldingMan2::
	msgbox OneIsland_KindleRoad_EmberSpa_Text_HotSpringIsTherapeutic, MSGBOX_NPC
	end

OneIsland_KindleRoad_EmberSpa_EventScript_OldWoman::
	msgbox OneIsland_KindleRoad_EmberSpa_Text_SeeHowSmoothMySkinIs, MSGBOX_NPC
	end

OneIsland_KindleRoad_EmberSpa_EventScript_BlackBelt::
	lock
	faceplayer
	famechecker FAMECHECKER_BRUNO, 3
	msgbox OneIsland_KindleRoad_EmberSpa_Text_BrunoVisitsSpaOnOccasion
	release
	end

OneIsland_KindleRoad_EmberSpa_EventScript_RockSmashMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HM06, OneIsland_KindleRoad_EmberSpa_EventScript_AlreadyGotHM06
	msgbox OneIsland_KindleRoad_EmberSpa_Text_UsedThisToMakeEmberSpa
	giveitem ITEM_HM06
	setflag FLAG_GOT_HM06
	msgbox OneIsland_KindleRoad_EmberSpa_Text_ExplainHM06
	release
	end

OneIsland_KindleRoad_EmberSpa_EventScript_AlreadyGotHM06::
	msgbox OneIsland_KindleRoad_EmberSpa_Text_ExplainHM06
	release
	end

OneIsland_KindleRoad_EmberSpa_EventScript_SpaHeal::
	lockall
	fadescreen FADE_TO_WHITE
	special HealPlayerParty
	fadescreen FADE_FROM_WHITE
	msgbox OneIsland_KindleRoad_EmberSpa_Text_WaterExquisiteFullyRefreshed
	setvar VAR_TEMP_1, 1
	releaseall
	end

OneIsland_KindleRoad_EmberSpa_Text_WaterWarmsMeToCore::
	.string "Hm!\n"
	.string "Haaaaaaaaaaah!\p"
	.string "Aaaah! Che paradiso!\n"
	.string "L'acqua mi scalda fino al midollo!\p"
	.string "Dovresti buttarti anche tu.\p"
	.string "Vai al centro, rilassati e\n"
	.string "scaldati per bene!$"

OneIsland_KindleRoad_EmberSpa_Text_EnjoyBowlOfChowder::
	.string "La mia parte preferita del bagno arriva\n"
	.string "proprio dopo.\p"
	.string "Mi godo una scodella di zuppa per\n"
	.string "scaldarmi anche dentro!$"

OneIsland_KindleRoad_EmberSpa_Text_WaterExquisiteFullyRefreshed::
	.string "L'acqua è perfettamente calda.\n"
	.string "È squisita...\p"
	.string "{PLAYER} e i POKéMON sono\n"
	.string "completamente ristorati!$"

OneIsland_KindleRoad_EmberSpa_Text_HotSpringIsTherapeutic::
	.string "Farsi il bagno in una vasca termale\n"
	.string "è terapeutico, dicono.$"

OneIsland_KindleRoad_EmberSpa_Text_SeeHowSmoothMySkinIs::
	.string "Guarda la mia faccia.\n"
	.string "Vedi che pelle liscia?\p"
	.string "L'acqua termale mantiene la mia\n"
	.string "pelle più giovane della mia età.$"

OneIsland_KindleRoad_EmberSpa_Text_BrunoVisitsSpaOnOccasion::
	.string "Dopo una giornata di duro allenamento,\n"
	.string "niente batte un rilassante bagno\l"
	.string "nella vasca termale.\p"
	.string "BRUNO, che è più anziano di me,\n"
	.string "visita le TERME ogni tanto.\p"
	.string "Viene a curare infortuni, i suoi\n"
	.string "e quelli dei suoi POKéMON.$"

OneIsland_KindleRoad_EmberSpa_Text_UsedThisToMakeEmberSpa::
	.string "Le terme vanno a braccetto con\n"
	.string "i vulcani.\p"
	.string "Le TERME SFARILLANTE qui, beh,\n"
	.string "le ho fatte anni fa.\p"
	.string "Ho scavato la vasca da un\n"
	.string "gigantesco masso a mano.\p"
	.string "A quei tempi usavo questo.\n"
	.string "Suppongo di potermene separare.$"

OneIsland_KindleRoad_EmberSpa_Text_ExplainHM06::
	.string "Frantuma i massi come se\n"
	.string "fossero cracker.$"

