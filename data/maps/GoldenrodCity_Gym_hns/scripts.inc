GoldenrodCity_Gym_hns_MapScripts::
	.byte 0
@Carrie, Bridget, Victoria, Samantha, gym guy


GoldenrodCity_Gym_EventScript_Carrie::
	trainerbattle_single TRAINER_CARRIE_HNS, GoldenrodCity_Gym_Text_LassCarrieSeen, GoldenrodCity_Gym_Text_LassCarrieBeaten
	msgbox GoldenrodCity_Gym_Text_LassCarrieAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Bridget::
	trainerbattle_single TRAINER_BRIDGET_HNS, GoldenrodCity_Gym_Text_LassBridgetSeen, GoldenrodCity_Gym_Text_LassBridgetBeaten
	msgbox GoldenrodCity_Gym_Text_LassBridgetAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Victoria::
	trainerbattle_single TRAINER_VICTORIA_HNS, GoldenrodCity_Gym_Text_BeautyVictoriaSeen, GoldenrodCity_Gym_Text_BeautyVictoriaBeaten
	msgbox GoldenrodCity_Gym_Text_BeautyVictoriaAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Samantha::
	trainerbattle_single TRAINER_SAMANTHA_HNS, GoldenrodCity_Gym_Text_BeautySamanthaSeen, GoldenrodCity_Gym_Text_BeautySamanthaBeaten
	msgbox GoldenrodCity_Gym_Text_BeautySamanthaAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Gym_Guy::
	lock
	faceplayer
	goto_if_set FLAG_BADGE03_GET, GoldenrodCity_Gym_EventScript_Gym_Guy_After
	msgbox GoldenrodCity_Gym_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Gym_Guy_After::
	msgbox GoldenrodCity_Gym_Text_GymGuideWin, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Whitney::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 3, GoldenrodCity_Gym_EventScript_WhitneyCrying
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 4, GoldenrodCity_Gym_EventScript_WhitneyBadge
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, GoldenrodCity_Gym_EventScript_WhitneyDefeated
	msgbox GoldenrodCity_Gym_Text_WhitneyBefore, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WHITNEY_1_HNS, GoldenrodCity_Gym_Text_WhitneyShouldntBeSoSerious
	msgbox GoldenrodCity_Gym_Text_WhitneyYouMeanie, MSGBOX_DEFAULT
	setvar VAR_GOLDENROD_CITY_STATE, 3
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_WhitneyCrying::
	lock
	faceplayer
	msgbox GoldenrodCity_Gym_Text_WhitneyYouMeanie, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_WhitneyBadge::
	lock
	faceplayer
	msgbox GoldenrodCity_Gym_Text_WhitneyWhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	message GoldenrodCity_Gym_Text_PlayerReceivedPlainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox GoldenrodCity_Gym_Text_WhitneyPlainBadge, MSGBOX_DEFAULT
	setflag FLAG_BADGE03_GET
	setflag FLAG_DEFEATED_GOLDENROD_CITY_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_ATTRACT
	msgbox GoldenrodCity_Gym_Text_WhitneyAttract, MSGBOX_DEFAULT
	setvar VAR_GOLDENROD_CITY_STATE, 5
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_WhitneyDefeated::
	lock
	faceplayer
	msgbox GoldenrodCity_Gym_Text_WhitneyGoodCry, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Trigger::	
	turnobject LOCALID_GOLDENROD_CITY_GYM_BRIDGET DIR_WEST
	msgbox GoldenrodCity_Gym_Text_BridgetWhitneyCries, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	setvar VAR_GOLDENROD_CITY_STATE, 4
	closemessage
	release
	end


GoldenrodCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, GoldenrodCity_Gym_EventScript_Statue2
	msgbox GoldenrodCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Statue2::
	msgbox GoldenrodCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_Text_GymStatue:
	.string "PALESTRA POKéMON GOLDENROD$"

GoldenrodCity_Gym_Text_GymStatueCertified:
	.string "PALESTRA POKéMON DI GOLDENROD\p"
	.string "ALLENATORI CERTIFICATI DI WHITNEY:\n"
	.string "{PLAYER}$"

GoldenrodCity_Gym_Text_WhitneyBefore:
    .string "Ciao! Sono WHITNEY!\p"
    .string "Tutti amavano i POKéMON, così\n"
    .string "ho iniziato anch'io!\p"
    .string "I POKéMON sono troppo carini!\p"
    .string "Vuoi lottare? Ti avviso,\n"
    .string "sono forte!$"

GoldenrodCity_Gym_Text_WhitneyShouldntBeSoSerious:
    .string "Sob…\p"
    .string "…Waaaaaaah! Che cattivo!\p"
    .string "Non devi fare la seria!\n"
    .string "Sei un bambino!$"

GoldenrodCity_Gym_Text_WhitneyYouMeanie:
    .string "Waaaaah!\p"
    .string "Waaaaah!\p"
    .string "…Singhiozzo… …Che cattivo!$"

GoldenrodCity_Gym_Text_WhitneyWhatDoYouWant:
    .string "…Sniff…\p"
    .string "Cosa? Cosa vuoi? Una MEDAGLIA?\p"
    .string "Ah, giusto. Me n'ero scordata.\n"
    .string "Ecco la PLAINBADGE.$"

GoldenrodCity_Gym_Text_PlayerReceivedPlainBadge:
    .string "{PLAYER} riceve PLAINBADGE.$"

GoldenrodCity_Gym_Text_WhitneyPlainBadge:
    .string "PLAINBADGE fa usare FORZA\n"
    .string "ai POKéMON fuori dalla lotta.\p"
    .string "E aumenta anche la loro\n"
	.string "DIFESA.\p"
    .string "Oh, prendi anche questo!$"

GoldenrodCity_Gym_Text_WhitneyAttract:
    .string "È ATTRACT! Sfrutta il\n"
    .string "fascino dei POKéMON.\p"
    .string "Non è perfetto per una\n"
    .string "carina come me?$"

GoldenrodCity_Gym_Text_WhitneyGoodCry:
    .string "Ah, che bel pianto!$"

GoldenrodCity_Gym_Text_WhitneyRematch:
    .string "Ciao! Sei tu!\p"
    .string "Wow, CAMPIONE JOHTO ora?\p"
    .string "Sei davvero incredibile!\p"
    .string "Voglio vedere quanto sei forte.\p"
    .string "Vuoi una rivincita con me?$"

GoldenrodCity_Gym_Text_WhitneyRematchDefeat:
    .string "Waaaaah!\p"
    .string "Waaaaah!\p"
    .string "…Singhiozzo… …Che cattivo!$"

GoldenrodCity_Gym_Text_LassCarrieSeen:
    .string "Non farti ingannare dal\n"
    .string "loro aspetto.\p"
    .string "Ti faranno fuori!$"

GoldenrodCity_Gym_Text_LassCarrieBeaten:
    .string "Accidenti… Ti credevo debole…$"

GoldenrodCity_Gym_Text_LassCarrieAfter:
    .string "I miei POKéMON mi trovano carina?$"

GoldenrodCity_Gym_Text_LassBridgetSeen:
    .string "Preferisco i POKéMON carini\n"
    .string "a quelli forti.\p"
    .string "Ma ne ho forti e carini!$"

GoldenrodCity_Gym_Text_LassBridgetBeaten:
    .string "Oh, no, no, no!$"

GoldenrodCity_Gym_Text_LassBridgetAfter:
    .string "Provo a battere WHITNEY, ma…\n"
    .string "Che tristezza.\p"
    .string "Va bene! Se perdo, mi impegnerò\n"
    .string "di più la prossima volta!$"

GoldenrodCity_Gym_Text_BridgetWhitneyCries:
    .string "Oh, no. Hai fatto piangere WHITNEY.\p"
    .string "Va bene. Le passerà. Piange\n"
    .string "sempre quando perde.$"

GoldenrodCity_Gym_Text_BeautyVictoriaSeen:
    .string "Oh, che bel trainerino!\p"
    .string "Mi piaci, ma non mi tratterrò!$"

GoldenrodCity_Gym_Text_BeautyVictoriaBeaten:
    .string "Vediamo… Ops, è finita?$"

GoldenrodCity_Gym_Text_BeautyVictoriaAfter:
    .string "Wow, devi essere forte per battermi!\n"
    .string "Continua così!$"

GoldenrodCity_Gym_Text_BeautySamanthaSeen:
    .string "Datti da fare, o ti batterò\n"
    .string "subito!$"

GoldenrodCity_Gym_Text_BeautySamanthaBeaten:
    .string "No! Oh, MEOWTH, mi dispiace!$"

GoldenrodCity_Gym_Text_BeautySamanthaAfter:
    .string "Ho insegnato mosse a MEOWTH per\n"
    .string "ogni tipo…$"

GoldenrodCity_Gym_Text_GymGuide:
    .string "Ehi! Campione in erba!\p"
    .string "Questa PALESTRA è di WHITNEY,\n"
    .string "esperta di POKéMON di tipo NORMALE.\p"
    .string "Attento al suo team carino.\p"
    .string "Alcuni POKéMON qui\n"
    .string "hanno anche il nuovo tipo\l"
    .string "MAGICO.\p"
    .string "Vai sulla PERCORSO 34 se vuoi\n"
    .string "tipi LOTTA o VELENO.$"

GoldenrodCity_Gym_Text_GymGuideWin:
    .string "Hai vinto? Grande! Ammiravo\n"
    .string "le ragazze qui.$"

