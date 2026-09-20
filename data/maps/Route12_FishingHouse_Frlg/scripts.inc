Route12_FishingHouse_Frlg_MapScripts::
	.byte 0

Route12_FishingHouse_EventScript_FishingGuruBrother::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SUPER_ROD, Route12_FishingHouse_EventScript_CheckMagikarpRecord
	msgbox Route12_FishingHouse_Text_DoYouLikeToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route12_FishingHouse_EventScript_GiveSuperRod
	msgbox Route12_FishingHouse_Text_OhThatsDisappointing
	release
	end

Route12_FishingHouse_EventScript_GiveSuperRod::
	checkitemspace ITEM_SUPER_ROD
	goto_if_eq VAR_RESULT, FALSE, Route12_FishingHouse_EventScript_NoRoomForSuperRod
	additem ITEM_SUPER_ROD
	msgbox Route12_FishingHouse_Text_TakeThisAndFish
	msgreceiveditem Route12_FishingHouse_Text_ReceivedSuperRod, ITEM_SUPER_ROD
	setflag FLAG_GOT_SUPER_ROD
	msgbox Route12_FishingHouse_Text_IfYouCatchBigMagikarpShowMe
	release
	end

Route12_FishingHouse_EventScript_NoRoomForSuperRod::
	msgbox Route12_FishingHouse_Text_NoRoomForGift
	release
	end

Route12_FishingHouse_EventScript_CheckMagikarpRecord::
	setvar VAR_0x8004, SPECIES_MAGIKARP
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	goto_if_eq VAR_RESULT, FALSE, Route12_FishingHouse_EventScript_NoMagikarpInParty
	special GetMagikarpSizeRecordInfo
	msgbox Route12_FishingHouse_Text_OhMagikarpAllowMeToSee
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_ge VAR_RESULT, PARTY_SIZE, Route12_FishingHouse_EventScript_CancelShowMon
	special CompareMagikarpSize
	goto_if_eq VAR_RESULT, 1, Route12_FishingHouse_EventScript_NotMagikarp
	goto_if_eq VAR_RESULT, 2, Route12_FishingHouse_EventScript_NotRecordMagikarp
	goto_if_eq VAR_RESULT, 3, Route12_FishingHouse_EventScript_NewRecordMagikarp
	goto_if_eq VAR_RESULT, 4, Route12_FishingHouse_EventScript_TieRecordMagikarp
	release
	end

Route12_FishingHouse_EventScript_NoMagikarpInParty::
	msgbox Route12_FishingHouse_Text_TryFishingBringMeMagikarp
	release
	end

Route12_FishingHouse_EventScript_CancelShowMon::
	release
	end

Route12_FishingHouse_EventScript_NotMagikarp::
	msgbox Route12_FishingHouse_Text_DoesntLookLikeMagikarp
	release
	end

Route12_FishingHouse_EventScript_NotRecordMagikarp::
	goto_if_unset FLAG_GOT_RECORD_SETTING_MAGIKARP, Route12_FishingHouse_EventScript_NewRecordMagikarp
	msgbox Route12_FishingHouse_Text_HmmXInchesDoesntMeasureUp
	release
	end

Route12_FishingHouse_EventScript_TieRecordMagikarp::
	goto_if_unset FLAG_GOT_RECORD_SETTING_MAGIKARP, Route12_FishingHouse_EventScript_NewRecordMagikarp
	msgbox Route12_FishingHouse_Text_HuhXInchesSameSizeAsLast
	release
	end

Route12_FishingHouse_EventScript_NewRecordMagikarp::
	setflag FLAG_GOT_RECORD_SETTING_MAGIKARP
	msgbox Route12_FishingHouse_Text_WhoaXInchesTakeThis
	giveitem ITEM_NET_BALL
	goto_if_eq VAR_RESULT, FALSE, Route12_FishingHouse_EventScript_NoRoomForNetBall
	msgbox Route12_FishingHouse_Text_LookForwardToGreaterRecords
	release
	end

Route12_FishingHouse_EventScript_NoRoomForNetBall::
	msgbox Route12_FishingHouse_Text_NoRoomForGift
	release
	end

Route12_FishingHouse_EventScript_MagikarpRecordSign::
	lockall
	goto_if_set FLAG_GOT_RECORD_SETTING_MAGIKARP, Route12_FishingHouse_EventScript_MagikarpRecordSignRecordSet
	msgbox Route12_FishingHouse_Text_BlankChartOfSomeSort
	releaseall
	end

Route12_FishingHouse_EventScript_MagikarpRecordSignRecordSet::
	special GetMagikarpSizeRecordInfo
	msgbox Route12_FishingHouse_Text_MostGiganticMagikarpXInches
	releaseall
	end

Route12_FishingHouse_Text_DoYouLikeToFish::
	.string "Sono il fratello minore del\n"
	.string "GURU DELLA PESCA.\p"
	.string "Adoro pescare!\n"
	.string "Non posso farne a meno.\p"
	.string "Dimmi, ti piace pescare?$"

Route12_FishingHouse_Text_TakeThisAndFish::
	.string "Grande! Mi piaci.\n"
	.string "Possiamo diventare amici.\p"
	.string "Prendi e pesca, amico mio!$"

Route12_FishingHouse_Text_ReceivedSuperRod::
	.string "{PLAYER} riceve una SUPER CANNA\n"
	.string "dal fratello del GURU DELLA PESCA.$"

Route12_FishingHouse_Text_IfYouCatchBigMagikarpShowMe::
	.string "Pescare è uno stile di vita!\n"
	.string "È come la poesia più fine.\p"
	.string "Dai mari ai fiumi, va' e prendi\n"
	.string "il pesce grosso, amico mio.\p"
	.string "Ora, ho una richiesta.\p"
	.string "Se prendi un grosso MAGIKARP\n"
	.string "con quella CANNA, voglio vederlo.\p"
	.string "Amo pescare, ma anche\n"
	.string "vedere MAGIKARP giganteschi.$"

Route12_FishingHouse_Text_OhThatsDisappointing::
	.string "Oh…\n"
	.string "Che delusione…$"

Route12_FishingHouse_Text_TryFishingBringMeMagikarp::
	.string "Ciao, {PLAYER}!\n"
	.string "Sei andato a pescare?\p"
	.string "Prova a pescare con la SUPER CANNA\n"
	.string "in qualsiasi specchio d'acqua.\p"
	.string "Troverai POKéMON diversi in\n"
	.string "posti diversi.\p"
	.string "Oh, e non dimenticare di portarmi\n"
	.string "MAGIKARP giganteschi.$"

Route12_FishingHouse_Text_OhMagikarpAllowMeToSee::
	.string "Oh? {PLAYER}?\n"
	.string "Ma quello è un MAGIKARP!\p"
	.string "Fammelo vedere, presto!$"

Route12_FishingHouse_Text_WhoaXInchesTakeThis::
	.string "… … …Accidenti!\n"
	.string "{STR_VAR_2} pollici!\p"
	.string "Hai un raro apprezzamento per\n"
	.string "il lato poetico della pesca!\p"
	.string "Devi prendere questo.\n"
	.string "Insisto!$"

Route12_FishingHouse_Text_LookForwardToGreaterRecords::
	.string "Non vedo l'ora di vedere record\n"
	.string "ancora più grandi da te!$"

Route12_FishingHouse_Text_HuhXInchesSameSizeAsLast::
	.string "Eh?\n"
	.string "{STR_VAR_2} pollici?\p"
	.string "È grande come quello\n"
	.string "che ho visto prima.$"

Route12_FishingHouse_Text_HmmXInchesDoesntMeasureUp::
	.string "Hmm…\n"
	.string "Questo è lungo {STR_VAR_2} pollici.\p"
	.string "Non arriva a quello da\n"
	.string "{STR_VAR_3} pollici che mi hai portato.$"

Route12_FishingHouse_Text_DoesntLookLikeMagikarp::
	.string "Uh… Non sembra proprio\n"
	.string "un MAGIKARP.$"

Route12_FishingHouse_Text_NoRoomForGift::
	.string "Oh, no!\p"
	.string "Avevo un regalo per te, ma non\n"
	.string "hai spazio.$"

Route12_FishingHouse_Text_MostGiganticMagikarpXInches::
	.string "Il MAGIKARP più gigantesco\n"
	.string "che abbia mai visto…\p"
	.string "{STR_VAR_3} pollici!$"

Route12_FishingHouse_Text_BlankChartOfSomeSort::
	.string "È una specie di tabella vuota.\p"
	.string "Ha spazi per annotare\n"
	.string "qualche tipo di record.$"

