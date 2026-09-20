SixIsland_WaterPath_House1_Frlg_MapScripts::
	.byte 0

SixIsland_WaterPath_House1_EventScript_Beauty::
	lock
	faceplayer
	setvar VAR_0x8004, SPECIES_HERACROSS
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	goto_if_eq VAR_RESULT, FALSE, SixIsland_WaterPath_House1_EventScript_NoHeracrossInParty
	special GetHeracrossSizeRecordInfo
	msgbox SixIsland_WaterPath_House1_Text_MayIMeasureHeracross
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_ge VAR_RESULT, PARTY_SIZE, SixIsland_WaterPath_House1_EventScript_DontShowMon
	special CompareHeracrossSize
	goto_if_eq VAR_RESULT, 1, SixIsland_WaterPath_House1_EventScript_ShownNonHeracross
	goto_if_eq VAR_RESULT, 2, SixIsland_WaterPath_House1_EventScript_ShownSmallHeracross
	goto_if_eq VAR_RESULT, 3, SixIsland_WaterPath_House1_EventScript_ShownBigHeracross
	goto_if_eq VAR_RESULT, 4, SixIsland_WaterPath_House1_EventScript_ShownTiedHeracross
	release
	end

SixIsland_WaterPath_House1_EventScript_NoHeracrossInParty::
	msgbox SixIsland_WaterPath_House1_Text_LoveItNeedItHeracross
	release
	end

SixIsland_WaterPath_House1_EventScript_DontShowMon::
	release
	end

SixIsland_WaterPath_House1_EventScript_ShownNonHeracross::
	msgbox SixIsland_WaterPath_House1_Text_ThisWontDo
	release
	end

SixIsland_WaterPath_House1_EventScript_ShownSmallHeracross::
	goto_if_unset FLAG_GOT_NEST_BALL_FROM_WATER_PATH_HOUSE_1, SixIsland_WaterPath_House1_EventScript_ShownBigHeracross
	msgbox SixIsland_WaterPath_House1_Text_ItsXInchesYInchesWasBiggest
	release
	end

SixIsland_WaterPath_House1_EventScript_ShownTiedHeracross::
	goto_if_unset FLAG_GOT_NEST_BALL_FROM_WATER_PATH_HOUSE_1, SixIsland_WaterPath_House1_EventScript_ShownBigHeracross
	msgbox SixIsland_WaterPath_House1_Text_ItsXInchesSameAsBefore
	release
	end

SixIsland_WaterPath_House1_EventScript_ShownBigHeracross::
	setflag FLAG_GOT_NEST_BALL_FROM_WATER_PATH_HOUSE_1
	msgbox SixIsland_WaterPath_House1_Text_ItsXInchesDeserveReward
	giveitem ITEM_NEST_BALL
	goto_if_eq VAR_RESULT, FALSE, SixIsland_WaterPath_House1_EventScript_NoRoomForNestBall
	msgbox SixIsland_WaterPath_House1_Text_WantToSeeBiggerOne
	release
	end

SixIsland_WaterPath_House1_EventScript_NoRoomForNestBall::
	msgbox SixIsland_WaterPath_House1_Text_YourBagIsFull
	release
	end

SixIsland_WaterPath_House1_EventScript_SizeRecord::
	lockall
	goto_if_set FLAG_GOT_NEST_BALL_FROM_WATER_PATH_HOUSE_1, SixIsland_WaterPath_House1_EventScript_SizeRecordNonEmpty
	msgbox SixIsland_WaterPath_House1_Text_BlankChartOfSomeSort
	releaseall
	end

SixIsland_WaterPath_House1_EventScript_SizeRecordNonEmpty::
	special GetHeracrossSizeRecordInfo
	msgbox SixIsland_WaterPath_House1_Text_BiggestHeracrossIsXInches
	releaseall
	end

SixIsland_WaterPath_House1_Text_LoveItNeedItHeracross::
	.string "Hera, hera, HERACROSS!\n"
	.string "Grande e lucente, è il re dei coleotteri!\l"
	.string "Lo amo, mi serve, HERACROSS!$"

SixIsland_WaterPath_House1_Text_MayIMeasureHeracross::
	.string "Ihhh!\n"
	.string "Che HERACROSS!\p"
	.string "Per favore, posso misurare\n"
	.string "quanto è grande?$"

SixIsland_WaterPath_House1_Text_ItsXInchesDeserveReward::
	.string "Ihhh, è di {STR_VAR_2} pollici!\n"
	.string "Non ho mai visto niente del genere!\l"
	.string "Ti meriti un premio!$"

SixIsland_WaterPath_House1_Text_WantToSeeBiggerOne::
	.string "Voglio vedere un HERACROSS\n"
	.string "molto, molto più grande.\p"
	.string "Oh, come li adoro, i grandi\n"
	.string "HERACROSS!$"

SixIsland_WaterPath_House1_Text_ItsXInchesSameAsBefore::
	.string "Eh? Questa misura di {STR_VAR_2} pollici…\n"
	.string "Che noia! È come prima.$"

SixIsland_WaterPath_House1_Text_ItsXInchesYInchesWasBiggest::
	.string "Oh, è solo {STR_VAR_2} pollici.\n"
	.string "Il HERACROSS di prima era più grande.\p"
	.string "Era di {STR_VAR_3} pollici, il più grande\n"
	.string "che mi hai portato.$"

SixIsland_WaterPath_House1_Text_ThisWontDo::
	.string "Oh, no! Così non va!\p"
	.string "HERACROSS è molto più macho\n"
	.string "e tosto, e ha un corno stupendo!$"

SixIsland_WaterPath_House1_Text_YourBagIsFull::
	.string "La tua BORSA è piena.\n"
	.string "Il mio premio non ci sta.$"

SixIsland_WaterPath_House1_Text_BiggestHeracrossIsXInches::
	.string "Il HERACROSS più grande che abbia\n"
	.string "mai visto finora misura:\p"
	.string "{STR_VAR_3} pollici!$"

SixIsland_WaterPath_House1_Text_BlankChartOfSomeSort::
	.string "È una specie di tabella vuota.\p"
	.string "Ha spazi per annotare\n"
	.string "qualche tipo di record.$"

