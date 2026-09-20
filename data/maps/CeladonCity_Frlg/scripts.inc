CeladonCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_OnTransition
	.byte 0

CeladonCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_CELADON_CITY
	end

CeladonCity_EventScript_LittleGirl::
	msgbox CeladonCity_Text_GotMyKoffingInCinnabar, MSGBOX_NPC
	end

CeladonCity_EventScript_OldMan1::
	lock
	msgbox CeladonCity_Text_GymIsGreatFullOfWomen
	release
	end

CeladonCity_EventScript_Woman::
	msgbox CeladonCity_Text_GameCornerIsBadForCitysImage, MSGBOX_NPC
	end

CeladonCity_EventScript_OldMan2::
	msgbox CeladonCity_Text_BlewItAllAtSlots, MSGBOX_NPC
	end

CeladonCity_EventScript_SoftboiledTutor::
	goto EventScript_SoftboiledTutor
	end

CeladonCity_EventScript_FatMan::
	lock
	faceplayer
	msgbox CeladonCity_Text_MyTrustedPalPoliwrath
	closemessage
	applymovement LOCALID_CELADON_FAT_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CeladonCity_EventScript_Poliwrath::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWRATH, CRY_MODE_NORMAL
	msgbox CeladonCity_Text_Poliwrath
	closemessage
	waitmoncry
	applymovement LOCALID_CELADON_POLIWRATH, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CeladonCity_EventScript_RocketGrunt1::
	msgbox CeladonCity_Text_KeepOutOfTeamRocketsWay, MSGBOX_NPC
	end

CeladonCity_EventScript_RocketGrunt2::
	msgbox CeladonCity_Text_GetLostOrIllPunchYou, MSGBOX_NPC
	end

CeladonCity_EventScript_Boy::
	msgbox CeladonCity_Text_ScaldedTongueOnTea, MSGBOX_NPC
	end

CeladonCity_EventScript_SilphCoScientist::
	msgbox CeladonCity_Text_SomeoneStoleSilphScope, MSGBOX_NPC
	end

CeladonCity_EventScript_TrainerTips1::
	msgbox CeladonCity_Text_ExplainXAccuracyDireHit, MSGBOX_SIGN
	end

CeladonCity_EventScript_CitySign::
	msgbox CeladonCity_Text_CitySign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GymSign::
	lockall
	famechecker FAMECHECKER_ERIKA, 0
	msgbox CeladonCity_Text_GymSign
	releaseall
	end

CeladonCity_EventScript_MansionSign::
	msgbox CeladonCity_Text_MansionSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_DeptStoreSign::
	msgbox CeladonCity_Text_DeptStoreSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_TrainerTips2::
	msgbox CeladonCity_Text_GuardSpecProtectsFromStatus, MSGBOX_SIGN
	end

CeladonCity_EventScript_PrizeExchangeSign::
	msgbox CeladonCity_Text_PrizeExchangeSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GameCornerSign::
	msgbox CeladonCity_Text_GameCornerSign, MSGBOX_SIGN
	end

CeladonCity_Text_GotMyKoffingInCinnabar::
	.string "Presi KOFFING a ISOLA CANNELLA.\p"
	.string "Di solito è buono, ma da\n"
	.string "arrabbiato sputa veleno.$"

CeladonCity_Text_GymIsGreatFullOfWomen::
	.string "Eheh! Bella PALESTRA!\n"
	.string "È piena di donne!$"

CeladonCity_Text_GameCornerIsBadForCitysImage::
	.string "CELADON si impegna con orgoglio\n"
	.string "a tenere bella la città.\p"
	.string "Perciò la nuova SALA GIOCHI è\n"
	.string "dannosa per la città.$"

CeladonCity_Text_BlewItAllAtSlots::
	.string "Ahi…\n"
	.string "Ho perso tutto alle slot!\p"
	.string "Avrei dovuto cambiare i miei\n"
	.string "GETTONI in premi!$"

CeladonCity_Text_MyTrustedPalPoliwrath::
	.string "Ecco il mio fidato POLIWRATH.\p"
	.string "Si è evoluto da POLIWHIRL con\n"
	.string "una PIETRA IDRO.$"

CeladonCity_Text_Poliwrath::
	.string "POLIWRATH: Cra cra!$"

CeladonCity_Text_GetLostOrIllPunchYou::
	.string "Che cosa guardi?\n"
	.string "Vattene o ti do un pugno!$"

CeladonCity_Text_KeepOutOfTeamRocketsWay::
	.string "Via dai piedi del TEAM ROCKET!$"

CeladonCity_Text_ExplainXAccuracyDireHit::
	.string "CONSIGLI UTILI\p"
	.string "PRECISIONE X rende più precise\n"
	.string "le mosse.\p"
	.string "SUPERCOLPO rende più probabili\n"
	.string "i colpi critici.\p"
	.string "Trovi tutto al CENTRO\n"
	.string "COMMERCIALE!$"

CeladonCity_Text_CitySign::
	.string "CELADON CITY\n"
	.string "Città dei sogni arcobaleno$"

CeladonCity_Text_GymSign::
	.string "PALESTRA POKéMON CELADON\n"
	.string "CAPO: ERIKA\l"
	.string "Principessa della natura!$"

CeladonCity_Text_MansionSign::
	.string "VILLA CELADON$"

CeladonCity_Text_DeptStoreSign::
	.string "Trovi ciò che ti serve al\n"
	.string "CENTRO COMMERCIALE!$"

CeladonCity_Text_GuardSpecProtectsFromStatus::
	.string "CONSIGLI UTILI\p"
	.string "ANTIDIFESA protegge i POKéMON\n"
	.string "dalle mosse che calano le\l"
	.string "statistiche in lotta.\p"
	.string "Trovi gli oggetti al\n"
	.string "CENTRO COMMERCIALE!$"

CeladonCity_Text_PrizeExchangeSign::
	.string "GETTONI in cambio di premi!\n"
	.string "SCAMBIO PREMI$"

CeladonCity_Text_GameCornerSign::
	.string "SALA GIOCHI ROCKET\n"
	.string "Il parco giochi per adulti!$"

CeladonCity_Text_ScaldedTongueOnTea::
	.string "Aaaah, ahi…\n"
	.string "Ho scottato la lingua!\p"
	.string "Una signora gentile della VILLA\n"
	.string "mi ha dato del Tè.\p"
	.string "Ma era bollente!\n"
	.string "Devo farlo raffreddare.$"

Text_SoftboiledTeach::
	.string "Ehi, ciao!\p"
	.string "Ti ho visto in giro, ma non ho\n"
	.string "mai potuto parlarti.\p"
	.string "Dev'essere stata la sorte che\n"
	.string "ci ha uniti alla fine.\p"
	.string "Per festeggiare, vorrei insegnarti\n"
	.string "la mossa COVAUOVA.$"

Text_SoftboiledDeclined::
	.string "Terrò sempre gli occhi aperti\n"
	.string "per te.\p"
	.string "Spero di riparlarti presto.$"

Text_SoftboiledWhichMon::
	.string "Allora, quale POKéMON vuole\n"
	.string "imparare COVAUOVA?$"

Text_SoftboiledTaught::
	.string "Ti auguro buona fortuna!$"

CeladonCity_Text_SomeoneStoleSilphScope::
	.string "Oh, che devo fare…\p"
	.string "Hanno rubato lo SPETTROVISORE!\p"
	.string "Il ladro è corso di qua,\n"
	.string "Ne sono sicuro.\p"
	.string "Ma l'ho perso di vista!\n"
	.string "Dov'è andato?$"

