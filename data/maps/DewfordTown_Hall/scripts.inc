DewfordTown_Hall_MapScripts::
	.byte 0

DewfordTown_Hall_EventScript_Girl::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special IsTrendyPhraseBoring
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Hall_EventScript_GirlBoredOfTrend
	msgbox DewfordTown_Hall_Text_CantImagineLifeWithoutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_GirlBoredOfTrend::
	msgbox DewfordTown_Hall_Text_GettingBoredOfTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Woman::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TeachingMonAboutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Man::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special BufferDeepLinkPhrase
	msgbox DewfordTown_Hall_Text_DeepLinkBetweenXAndY, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_Hall_EventScript_ConfirmTrendLink
	goto_if_eq VAR_RESULT, NO, DewfordTown_Hall_EventScript_RejectTrendLink
	end

DewfordTown_Hall_EventScript_ConfirmTrendLink::
	msgbox DewfordTown_Hall_Text_MyHunchWasRight, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_RejectTrendLink::
	msgbox DewfordTown_Hall_Text_NotEasyToKeepUp, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_ExpertM::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TVShowAboutTrend, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEWFORD_HALL_EXPERT_M, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_Twin::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEWFORD_HALL_TWIN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_LittleBoy::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_CollectTrendMerchandise, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Bookshelf::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_BooksAboutTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_Painting::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_ScreamTitle
	case 4, DewfordTown_Hall_EventScript_ScreamTitle
	case 1, DewfordTown_Hall_EventScript_SmileTitle
	case 5, DewfordTown_Hall_EventScript_ScreamTitle
	case 2, DewfordTown_Hall_EventScript_LastTitle
	case 6, DewfordTown_Hall_EventScript_LastTitle
	case 3, DewfordTown_Hall_EventScript_BirthTitle
	case 7, DewfordTown_Hall_EventScript_LastTitle
	end

DewfordTown_Hall_EventScript_ScreamTitle::
	msgbox DewfordTown_Hall_Text_TrendsScream, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SmileTitle::
	msgbox DewfordTown_Hall_Text_TrendsSmile, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_LastTitle::
	msgbox DewfordTown_Hall_Text_LastTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_BirthTitle::
	msgbox DewfordTown_Hall_Text_BirthOfTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SchoolKidM::
	lockall
	setvar VAR_0x8008, 0
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_PsychicM::
	lockall
	setvar VAR_0x8008, 1
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_DoTrendDebate::
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_TrendDebate1
	case 1, DewfordTown_Hall_EventScript_TrendDebate1
	case 2, DewfordTown_Hall_EventScript_TrendDebate2
	case 3, DewfordTown_Hall_EventScript_TrendDebate2
	case 4, DewfordTown_Hall_EventScript_TrendDebate3
	case 5, DewfordTown_Hall_EventScript_TrendDebate3
	case 6, DewfordTown_Hall_EventScript_TrendDebate4
	case 7, DewfordTown_Hall_EventScript_TrendDebate5
	end

DewfordTown_Hall_EventScript_TrendDebate1::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_SawTrendCoolestThing, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_AllegedTrendNotAuthentic, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate2::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_ComposedTrendThemeSong, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WorkOnYourSinging, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate3::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_OrganizeTrendParty, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_BrilliantIndeed, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate4::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_TrendHasBecomePartOfLife, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate5::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WellBeTrendDuo, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_DontMovePlayer1::
	return

DewfordTown_Hall_EventScript_DebateReact1::
	applymovement LOCALID_DEWFORD_HALL_PSYCHIC_M, DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactWest
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_DontMovePlayer2
	end

DewfordTown_Hall_EventScript_PlayerReactWest::
	goto_if_eq VAR_FACING, DIR_EAST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

DewfordTown_Hall_EventScript_DontMovePlayer2::
	return

DewfordTown_Hall_EventScript_DebateReact2::
	applymovement LOCALID_DEWFORD_HALL_SCHOOL_KID_M, DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactNorthSouth
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_PlayerReactEast
	end

DewfordTown_Hall_EventScript_PlayerReactNorthSouth::
	call_if_eq VAR_FACING, DIR_NORTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp
	call_if_eq VAR_FACING, DIR_SOUTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerReactEast::
	goto_if_eq VAR_FACING, DIR_WEST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft:
	walk_in_place_left
	step_end

DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight:
	walk_in_place_right
	step_end

DewfordTown_Hall_EventScript_SludgeBombMan::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	goto_if_set FLAG_RECEIVED_TM_SLUDGE_BOMB, DewfordTown_Hall_EventScript_ReceivedSludgeBomb
	msgbox DewfordTown_Hall_Text_GiveYouSludgeBomb, MSGBOX_DEFAULT
	giveitem ITEM_TM_SLUDGE_BOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SLUDGE_BOMB
	release
	end

DewfordTown_Hall_EventScript_ReceivedSludgeBomb::
	msgbox DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_Text_CantImagineLifeWithoutTrend:
	.string "Cosa va di moda? Ma è ovvio:\n"
	.string "“{STR_VAR_1}”!\p"
	.string "Non riesco a immaginare la vita\n"
	.string "senza “{STR_VAR_1}”!$"

DewfordTown_Hall_Text_GettingBoredOfTrend:
	.string "Cosa va di moda? Ma è ovvio:\n"
	.string "“{STR_VAR_1}”!\p"
	.string "Ma comincio a stufarmene.\p"
	.string "Devo cercare la prossima novità.$"

DewfordTown_Hall_Text_TeachingMonAboutTrend:
	.string "Sto insegnando al mio POKéMON\n"
	.string "“{STR_VAR_1},”\l"
	.string "ma non va bene.\p"
	.string "È un po' troppo, credo.$"

DewfordTown_Hall_Text_DeepLinkBetweenXAndY:
	.string "Sto studiando il fenomeno\n"
	.string "“{STR_VAR_1}”.\p"
	.string "È vero che c'è un legame profondo\n"
	.string "tra “{STR_VAR_1}”\l"
	.string "e “{STR_VAR_2}”?$"

DewfordTown_Hall_Text_MyHunchWasRight:
	.string "Oh!\n"
	.string "Avevo ragione!\p"
	.string "Sono più vicino a essere alla moda,\n"
	.string "e moderno, urrà!$"

DewfordTown_Hall_Text_NotEasyToKeepUp:
	.string "Cosa?!\n"
	.string "Davvero?!\p"
	.string "Non è facile per uno come me\n"
	.string "stare dietro alle mode!$"

DewfordTown_Hall_Text_TVShowAboutTrend:
	.string "Tutta questa storia su\n"
	.string "“{STR_VAR_1}”…\l"
	.string "Non c'è un programma TV?$"

DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea:
	.string "Oltre il mare…\p"
	.string "È “{STR_VAR_1}”\n"
	.string "ancora più in voga?$"

DewfordTown_Hall_Text_CollectTrendMerchandise:
	.string "Colleziono\n"
	.string "“{STR_VAR_1}”\l"
	.string "ufficiali su licenza.\p"
	.string "Ho i\n"
	.string "PELUCHE “{STR_VAR_1}”…\p"
	.string "Vestiti “{STR_VAR_1}”\n"
	.string "firmati…\p"
	.string "E persino libri\n"
	.string "“{STR_VAR_1}”\l"
	.string "illustrati.\p"
	.string "Eheh, è mia!\n"
	.string "Non divido niente con te!$"

DewfordTown_Hall_Text_BooksAboutTrend:
	.string "DISTINGUERE BUON\n"
	.string "“{STR_VAR_1}” E\l"
	.string "CATTIVO “{STR_VAR_1}”…\p"
	.string "IL LEGAME TRA\n"
	.string "“{STR_VAR_1}” E\l"
	.string "POKéMON…\p"
	.string "UTILE\n"
	.string "“{STR_VAR_1}”…\p"
	.string "È pieno zeppo di libri su\n"
	.string "“{STR_VAR_1}.”$"

DewfordTown_Hall_Text_TrendsScream:
	.string "“L'URLO DI {STR_VAR_1}”\n"
	.string "è il titolo.$"

DewfordTown_Hall_Text_TrendsSmile:
	.string "“IL SORRISO DI {STR_VAR_1}”\n"
	.string "è il titolo.$"

DewfordTown_Hall_Text_LastTrend:
	.string "Titolo: “L'ULTIMO\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_BirthOfTrend:
	.string "S'intitola “LA NASCITA DI\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_SawTrendCoolestThing:
	.string "Ho visto “{STR_VAR_1}”!\n"
	.string "Forte, no?\p"
	.string "È tipo la cosa più forte in giro!\p"
	.string "Che spettacolo!\n"
	.string "Era quello vero, oh sì!$"

DewfordTown_Hall_Text_AllegedTrendNotAuthentic:
	.string "Oh, no, no, no.\p"
	.string "Il presunto\n"
	.string "“{STR_VAR_1}”\l"
	.string "di aver visto non è autentico.\p"
	.string "Quello autentico è molto…\n"
	.string "Come dire?\l"
	.string "Più forte, ma più dolce!\p"
	.string "Ah, non importa. Sconvolgente!$"

DewfordTown_Hall_Text_ComposedTrendThemeSong:
	.string "Ehi, ho composto una sigla\n"
	.string "per “{STR_VAR_1}.”\p"
	.string "“{STR_VAR_1}”\n"
	.string "va molto di moda adesso.\p"
	.string "Ok, ascolta!\n"
	.string "… …\p"
	.string "Oh!\n"
	.string "{STR_VAR_1}!\p"
	.string "Magnifico\n"
	.string "{STR_VAR_1}!$"

DewfordTown_Hall_Text_WorkOnYourSinging:
	.string "… …\p"
	.string "Oserei dire, amico, ti converrebbe\n"
	.string "esercitare la voce prima di\l"
	.string "impicciarti con\l"
	.string "“{STR_VAR_1}.”$"

DewfordTown_Hall_Text_OrganizeTrendParty:
	.string "Come dicevo prima, dovremmo\n"
	.string "riunirci e organizzare una\l"
	.string "festa “{STR_VAR_1}”\l"
	.string "sull'isola.$"

DewfordTown_Hall_Text_BrilliantIndeed:
	.string "Oh, che bella idea!\p"
	.string "Deciderà una volta per tutte\n"
	.string "chi eccelle in\l"
	.string "“{STR_VAR_1}.”\l"
	.string "Geniale, davvero!\p"
	.string "Da oggi le nostre vite ruotano\n"
	.string "su “{STR_VAR_1}”!$"

DewfordTown_Hall_Text_TrendHasBecomePartOfLife:
	.string "Pensavo, però…\p"
	.string "Non credi anche tu che\n"
	.string "“{STR_VAR_1}” sia\l"
	.string "passato dall'essere una moda a\l"
	.string "far parte della nostra vita?$"

DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind:
	.string "Come dici?\n"
	.string "Così tanto, eh?\p"
	.string "Però è vero che\n"
	.string "“{STR_VAR_1}”\l"
	.string "ti pesa sulla mente, sia da sveglio\l"
	.string "che da addormentato.\p"
	.string "Assolutamente, sei il\n"
	.string "“{STR_VAR_1}”\l"
	.string "PROFESSORE, amico!$"

DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible:
	.string "Se facciamo squadra io e te,\n"
	.string "saremo invincibili in tutto\l"
	.string "su “{STR_VAR_1}”!$"

DewfordTown_Hall_Text_WellBeTrendDuo:
	.string "Esatto, amico mio!\p"
	.string "Saremo il\n"
	.string "DUO “{STR_VAR_1}”!\p"
	.string "Che bella immagine, no?\n"
	.string "Ahahah!$"

DewfordTown_Hall_Text_GiveYouSludgeBomb:
	.string "Per me BOMBA MELMA è al top\n"
	.string "della moda. È quella giusta.\p"
	.string "Eh? Stai dicendo che non\n"
	.string "conosci BOMBA MELMA?\p"
	.string "È proprio penoso.\n"
	.string "Te ne do uno.$"

DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo:
	.string "Adoro MELMABOMBA.\p"
	.string "Ma i POKéMON con la mossa\n"
	.string "“{STR_VAR_1}”\l"
	.string "son di moda.$"

