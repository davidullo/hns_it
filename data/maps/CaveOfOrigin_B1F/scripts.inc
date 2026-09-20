CaveOfOrigin_B1F_MapScripts::
	.byte 0

CaveOfOrigin_B1F_EventScript_Wallace::
	lock
	faceplayer
	msgbox CaveOfOrigin_B1F_Text_WallaceStory, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_FacePlayer
	waitmovement 0
	message CaveOfOrigin_B1F_Text_WhereIsRayquaza
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_WheresRayquaza::
	multichoice 0, 0, MULTI_WHERES_RAYQUAZA, FALSE
	switch VAR_RESULT
	case 0, CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin
	case 1, CaveOfOrigin_B1F_EventScript_AtMtPyre
	case 2, CaveOfOrigin_B1F_EventScript_AtSkyPillar
	case 3, CaveOfOrigin_B1F_EventScript_DontRemember
	goto CaveOfOrigin_B1F_EventScript_DontRemember
	end

CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin::
	message CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtMtPyre::
	message CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_DontRemember::
	message CaveOfOrigin_B1F_Text_CantYouRememberSomehow
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtSkyPillar::
	msgbox CaveOfOrigin_B1F_Text_WellHeadToSkyPillar, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	fadescreenspeed FADE_TO_BLACK, 4
	setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR
	setvar VAR_SOOTOPOLIS_CITY_STATE, 3
	removeobject LOCALID_CAVE_OF_ORIGIN_WALLACE
	clearflag FLAG_HIDE_SKY_PILLAR_WALLACE
	fadescreen FADE_FROM_BLACK
	release
	end

CaveOfOrigin_B1F_Text_WallaceStory:
	.string "Sei {PLAYER}{KUN}?\n"
	.string "Ho sentito parlare delle tue gesta.\p"
	.string "Sono WALLACE.\p"
	.string "Ero il CAPOPALESTRA di\n"
	.string "PETROPOLI, ma poi è successo\p"
	.string "Ora ho affidato la PALESTRA al mio\n"
	.string "mentore JUAN.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "GROUDON e KYOGRE, i due POKéMON\n"
	.string "che seminano caos qui, sono\l"
	.string "detti POKéMON superantichi.\p"
	.string "Ma non sono solo due POKéMON\n"
	.string "superantichi.\p"
	.string "Un altro si nasconde altrove.\p"
	.string "Altrove si nasconde un POKéMON\n"
	.string "superantico chiamato RAYQUAZA.\p"
	.string "Si dice che sia stato RAYQUAZA\n"
	.string "a calmare i due in lotta, in un\l"
	.string "lontano passato.\p"
	.string "Ma nemmeno io so dove\n"
	.string "sia RAYQUAZA…$"

CaveOfOrigin_B1F_Text_WhereIsRayquaza:
	.string "WALLACE: {PLAYER}{KUN}, tu\n"
	.string "forse sai dove sia RAYQUAZA?\p"
	.string "Se lo sai, dimmelo.$"

CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin:
	.string "WALLACE: La GROTTA ORIGINE?\p"
	.string "Ma è proprio qui!\n"
	.string "Devi fare di meglio!\p"
	.string "Ti prego, pensa bene a\n"
	.string "dove possa essere ora RAYQUAZA.$"

CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat:
	.string "WALLACE: MT. CENERE?\p"
	.string "Ma quando ho incontrato là la\n"
	.string "vecchia non ne ha detto niente.\p"
	.string "Dubito che la vecchia volesse\n"
	.string "nascondermi qualcosa…\p"
	.string "{PLAYER}{KUN}, ripensaci con\n"
	.string "con più attenzione.$"

CaveOfOrigin_B1F_Text_CantYouRememberSomehow:
	.string "WALLACE: Eh? Non ricordi?\n"
	.string "Hmm… È un problema…\p"
	.string "Non ti viene in mente niente?$"

CaveOfOrigin_B1F_Text_WellHeadToSkyPillar:
	.string "WALLACE: Il PILASTRO CIELO?\p"
	.string "È quello!\n"
	.string "Dev'essere il PILASTRO CIELO!\p"
	.string "{PLAYER}{KUN}, non c'è tempo da perdere!\n"
	.string "Andiamo subito al PILASTRO CIELO!$"

