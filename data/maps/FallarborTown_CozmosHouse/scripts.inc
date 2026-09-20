FallarborTown_CozmosHouse_MapScripts::
	.byte 0

FallarborTown_CozmosHouse_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_GaveMeteorite
	checkitem ITEM_METEORITE
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite::
	call_if_unset FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_NoticeMeteorite
	call_if_set FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_AskForMeteorite
	goto_if_eq VAR_RESULT, NO, FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite
	msgbox FallarborTown_CozmosHouse_Text_PleaseUseThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_RETURN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_0x8004, ITEM_METEORITE
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_RECEIVED_TM_RETURN
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_NoticeMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	msgbox FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_AskForMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MayIHaveMeteorite, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite::
	setflag FLAG_TEMP_2
	msgbox FallarborTown_CozmosHouse_Text_CrushedWithDisappointment, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_GaveMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmosWife::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_CozmoIsHappy
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_CozmosHouse_EventScript_CozmoIsSad
	msgbox FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsSad::
	msgbox FallarborTown_CozmosHouse_Text_FeelSorryForCozmo, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsHappy::
	msgbox FallarborTown_CozmosHouse_Text_CozmoIsSoHappy, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow:
	.string "PROF. COZMO: Oh…\n"
	.string "Non avrei mai dovuto farmi\l"
	.string "ingannare e dire al TEAM MAGMA\l"
	.string "dove trovare i METEORITI…\p"
	.string "Il METEORITE delle CASCATE\n"
	.string "METEORA non sarà mai mio…$"

FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt:
	.string "Oh!\n"
	.string "Eh?\p"
	.string "L'oggetto…\p"
	.string "Può essere?\p"
	.string "È il METEORITE che il TEAM MAGMA\n"
	.string "ha preso alle CASCATE METEORA?\p"
	.string "Me lo dai, per favore?\p"
	.string "Non te lo chiedo gratis.\n"
	.string "In cambio, ti do questa MT.$"

FallarborTown_CozmosHouse_Text_PleaseUseThisTM:
	.string "PROF. COZMO: Questa MT esprime la\n"
	.string "mia gratitudine.\l"
	.string "Usala, dai!$"

FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch:
	.string "PROF. COZMO: Non ci credo!\n"
	.string "È davvero fantastico!\p"
	.string "Aiuterà molto la mia ricerca!$"

FallarborTown_CozmosHouse_Text_CrushedWithDisappointment:
	.string "PROF. COZMO: Oh, ma…\n"
	.string "Sono distrutto dalla delusione…$"

FallarborTown_CozmosHouse_Text_MayIHaveMeteorite:
	.string "PROF. COZMO: Per favore, mi dai il\n"
	.string "METEORITE?\p"
	.string "Non te lo chiedo gratis.\n"
	.string "In cambio, ti do questa MT.$"

FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls:
	.string "Il PROF. COZMO è andato alle\n"
	.string "CASCATE METEORA con gente del\l"
	.string "TEAM MAGMA.$"

FallarborTown_CozmosHouse_Text_FeelSorryForCozmo:
	.string "Povero PROF. COZMO…\n"
	.string "È così depresso… mi fa pena.$"

FallarborTown_CozmosHouse_Text_CozmoIsSoHappy:
	.string "Guarda PROF. COZMO…\n"
	.string "È così felice! Che tenero.$"

