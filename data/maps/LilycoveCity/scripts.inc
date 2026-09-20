LilycoveCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
	.byte 0

LilycoveCity_OnTransition:
	setflag FLAG_VISITED_LILYCOVE_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	call Common_EventScript_SetupRivalGfxId
	end

LilycoveCity_OnLoad:
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
	end

LilycoveCity_EventScript_SetWailmerMetatiles::
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
	return

LilycoveCity_EventScript_BerryGentleman::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ReceivedBerry::
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man3::
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
	end

LilycoveCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_GirlAquaGone::
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_RichBoy::
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
	end

LilycoveCity_EventScript_Sailor2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor2AquaGone::
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2AquaGone::
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man2::
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
	end

LilycoveCity_EventScript_ExpertM1::
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertF::
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertM2::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ExpertM2AquaGone::
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor1::
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
	end

LilycoveCity_EventScript_FatMan::
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
	end

LilycoveCity_EventScript_Man1::
	lockall
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
	applymovement LOCALID_LILYCOVE_MAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_Woman1::
	lockall
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
	applymovement LOCALID_LILYCOVE_WOMAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_CitySign::
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ContestHallSign::
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MotelSign::
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MuseumSign::
	lockall
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_MuseumSignNoPaintings::
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSignFerryReady::
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_TrainerFanClubSign::
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_DepartmentStoreSign::
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MoveDeletersHouseSign::
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_WailmerTrainerGrunt::
	lockall
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_MET_WAILMER_TRAINER
	releaseall
	end

LilycoveCity_EventScript_MetWailmerTrainer::
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_AquaGrunt1::
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt2::
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt3::
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt4::
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
	end

LilycoveCity_EventScript_Rival::
	lock
	faceplayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_EventScript_May
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_EventScript_Brendan
	end

LilycoveCity_EventScript_May::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleMayTreecko
	case 1, LilycoveCity_EventScript_BattleMayTorchic
	case 2, LilycoveCity_EventScript_BattleMayMudkip
	end

LilycoveCity_EventScript_MayAskToBattleAgain::
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_MayAskToBattle::
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineMayBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_Brendan::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleBrendanTreecko
	case 1, LilycoveCity_EventScript_BattleBrendanTorchic
	case 2, LilycoveCity_EventScript_BattleBrendanMudkip
	end

LilycoveCity_EventScript_BrendanAskToBattleAgain::
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_BrendanAskToBattle::
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineBrendanBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_DefeatedMay::
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_CheckFinalBadge::
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
	return

LilycoveCity_EventScript_HasFinalBadge::
	setvar VAR_RESULT, TRUE
	return

LilycoveCity_EventScript_MayCollectBadges::
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayBattleFrontier::
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DefeatedBrendan::
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_BrendanCollectBadges::
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanBattleFrontier::
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_RivalFlyAway::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject VAR_LAST_TALKED
	waitfieldeffect FLDEFF_NPCFLY_OUT
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_MET_RIVAL_LILYCOVE
	release
	end

LilycoveCity_EventScript_SchoolKidM::
	lock
	faceplayer
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
	release
	end

LilycoveCity_EventScript_KnowAboutBerryBlender::
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DontKnowAboutBerryBlender::
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
	return

LilycoveCity_Text_MayShoppingLetsBattle:
	.string "MAY: Oh, ciao?\n"
	.string "{PLAYER}{KUN}, fai compere anche tu?\p"
	.string "Ho comprato un sacco di PUPAZZI e\n"
	.string "POSTER.\p"
	.string "Certo, ho preso anche molti\n"
	.string "POKéMON, e li alleno\l"
	.string "per bene.\p"
	.string "Anzi, mi preoccupo se li\n"
	.string "alleni bene, {PLAYER}{KUN}.\p"
	.string "Lotto con te, così mi mostri\n"
	.string "i tuoi POKéMON, {PLAYER}{KUN}.$"

LilycoveCity_Text_MayNotRaisingPokemon:
	.string "MAY: Oh, perché? {PLAYER}{KUN}, non hai\n"
	.string "allenato i tuoi POKéMON?\p"
	.string "Non è una bella figura per\n"
	.string "un ALLENATORE…$"

LilycoveCity_Text_MayBattleMe:
	.string "MAY: Dai, lotta con me, così vedo\n"
	.string "i tuoi POKéMON!$"

LilycoveCity_Text_MayWontBeBeaten:
	.string "MAY: I POKéMON che ho allenato non\n"
	.string "perderanno coi tuoi, {PLAYER}{KUN}!$"

LilycoveCity_Text_MayDefeat:
	.string "… … … … … … … …\p"
	.string "Ricordo la lotta che ho fatto con te,\n"
	.string "{PLAYER}{KUN}, sul PERCORSO 103.\p"
	.string "Quella lotta ti ha reso forte,\n"
	.string "{PLAYER}{KUN}, vero?$"

LilycoveCity_Text_MayGoingBackToLittleroot:
	.string "MAY: Penso di tornare presto\n"
	.string "a LITTLEROOT.\p"
	.string "Ho preso dei POKéMON niente male,\n"
	.string "e il POKéDEX avanza, quindi\l"
	.string "torno a casa a mostrarli a papà.$"

LilycoveCity_Text_MayYouGoingToCollectBadges:
	.string "{PLAYER}{KUN}, cosa farai?\p"
	.string "Prendi tutte le MEDAGLIE e\n"
	.string "sfidi la LEGA POKéMON?\p"
	.string "Beh, mentre prendi le MEDAGLIE,\n"
	.string "{PLAYER}{KUN}, io lavoro al mio\l"
	.string "POKéDEX. Lo completo prima di te!\p"
	.string "Ci vediamo!$"

LilycoveCity_Text_MayYouGoingToPokemonLeague:
	.string "{PLAYER}{KUN}, cosa farai?\p"
	.string "Affronterai la sfida della\n"
	.string "LEGA POKéMON?\p"
	.string "O completerai il tuo\n"
	.string "POKéDEX?\p"
	.string "Forse ho perso in lotta,\n"
	.string "ma finirò il POKéDEX prima di te!\p"
	.string "Ci vediamo!$"

LilycoveCity_Text_MayYouGoingToBattleFrontier:
	.string "{PLAYER}{KUN}, cosa farai?\p"
	.string "Affronterai la sfida del\n"
	.string "BATTLE FRONTIER?\p"
	.string "O completerai il tuo\n"
	.string "POKéDEX?\p"
	.string "Forse ho perso in lotta,\n"
	.string "ma finirò il POKéDEX prima di te!\p"
	.string "Ci vediamo!$"

LilycoveCity_Text_BrendanShoppingLetsBattle:
	.string "BRENDAN: Oh, ciao, {PLAYER}.\p"
	.string "Faccio una commissione per papà.\n"
	.string "No, non compro PUPATTE.\p"
	.string "Comunque, è da un po'.\p"
	.string "Facciamo una lotta? Chi alleva\n"
	.string "meglio i POKéMON?$"

LilycoveCity_Text_BrendanNoConfidence:
	.string "BRENDAN: Oh, che c'è?\n"
	.string "Non hai coraggio?$"

LilycoveCity_Text_BrendanBattleMe:
	.string "BRENDAN: Facciamo una lotta?\n"
	.string "Chi alleva meglio i POKéMON?$"

LilycoveCity_Text_BrendanWontBeBeaten:
	.string "BRENDAN: Aww, ma lo sai che non\n"
	.string "perdo contro {PLAYER}.$"

LilycoveCity_Text_BrendanDefeat:
	.string "Uhm…\n"
	.string "Ti sei allenato sodo.\p"
	.string "Che bruciatura: ero partito\n"
	.string "in vantaggio…$"

LilycoveCity_Text_BrendanGoingBackToLittleroot:
	.string "BRENDAN: Io…\n"
	.string "Torno a casa, a LITTLEROOT.\p"
	.string "Aiuto papà col POKéDEX, lo sai.\n"
	.string "Sta venendo su bene,\l"
	.string "quindi vado a farglielo vedere.$"

LilycoveCity_Text_BrendanYouGoingToCollectBadges:
	.string "{PLAYER}, cosa farai?\p"
	.string "Collezionare tutte le MEDAGLIE e\n"
	.string "sfidare la LEGA POKéMON?\p"
	.string "Forse lo farò anch'io…\p"
	.string "Beh, comunque, non mollare!$"

LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
	.string "{PLAYER}, e ora cosa farai?\p"
	.string "Se sei così forte, punti\n"
	.string "alla LEGA POKéMON?\p"
	.string "Eh, anch'io, se allenassi un po'\n"
	.string "di più, sarei più forte di te,\l"
	.string "{PLAYER}.\p"
	.string "Beh, comunque, non mollare!$"

LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
	.string "{PLAYER}, cosa farai?\p"
	.string "Affronterai la sfida del BATTLE\n"
	.string "FRONTIER?\p"
	.string "O completerai il tuo\n"
	.string "POKéDEX?\p"
	.string "Dato che sei forte, dovresti\n"
	.string "provare il BATTLE FRONTIER.\p"
	.string "Eh, se alleno un po' i POKéMON,\n"
	.string "diventerò più forte di te, {PLAYER}.\p"
	.string "Forse dovrei andare al BATTLE\n"
	.string "FRONTIER.\p"
	.string "Beh, comunque, non mollare!$"

LilycoveCity_Text_MovedLootIntoHideoutToday:
	.string "Fufufu…\p"
	.string "Oggi abbiamo portato altro bottino\n"
	.string "nel nostro COVO segreto…\p"
	.string "C-chi sei?!\n"
	.string "Parlavo da sola!$"

LilycoveCity_Text_ChanceToDoBigThings:
	.string "Sono un RECLUTA, non so\n"
	.string "cosa pensi il CAPO…\p"
	.string "Ma nel TEAM AQUA\n"
	.string "farò grandi cose!\p"
	.string "E tu chi sei?!\n"
	.string "Parlavo da solo!$"

LilycoveCity_Text_DontGoNearCaveInCove:
	.string "Ehi, tu!\p"
	.string "Sta' lontano dalla grotta!\p"
	.string "Perché? Non serve un perché!\n"
	.string "Sono adulto, ubbidisci!$"

LilycoveCity_Text_IfWorldBecomesOurs:
	.string "Se tutto il mondo diventa nostro,\n"
	.string "del TEAM AQUA, sarà un posto\l"
	.string "più felice anche per i POKéMON.$"

LilycoveCity_Text_WailmerLeapOutOfWater:
	.string "Ora! WAILMER!\n"
	.string "Salta fuori dall'acqua!$"

LilycoveCity_Text_GetLostMessingUpTraining:
	.string "Eh? Che vuoi?\p"
	.string "Ci rovini l'allenamento,\n"
	.string "quindi sparisci?$"

LilycoveCity_Text_ContestHallInTown:
	.string "C'è una SALA GARE\n"
	.string "proprio qui in città.\p"
	.string "Quindi POKéMON allevati bene\n"
	.string "arrivano da tutto il paese.\p"
	.string "Il cuore mi esplode!$"

LilycoveCity_Text_StrangeCaveInCove:
	.string "Hai visto quella grotta strana\n"
	.string "nella cala ai margini del paese?$"

LilycoveCity_Text_GoingToMoveDeleterForHMs:
	.string "Insegno ai POKéMON mosse nuove\n"
	.string "per una GARA.\p"
	.string "Quindi vado dal DIMENTICAMOSSE\n"
	.string "a far dimenticare le MN.$"

LilycoveCity_Text_ImFromKanto:
	.string "Vengo da KANTO.\p"
	.string "La regione di HOENN è bella,\n"
	.string "con acqua e natura rigogliosa.\p"
	.string "Eh? Un attimo…\p"
	.string "Esistono POKéMON rari che\n"
	.string "vivono solo qui?$"

LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
	.string "Il TEAM AQUA allenava i suoi\n"
	.string "WAILMER nella cala.\p"
	.string "Noi MARINAI non riusciamo a\n"
	.string "portare le barche in mare!$"

LilycoveCity_Text_SomeonePuntedTeamAquaOut:
	.string "Ehi, lo sai?\p"
	.string "Qualcuno ha cacciato via\n"
	.string "il TEAM AQUA!\p"
	.string "I WAILMER se ne sono andati,\n"
	.string "e possiamo riprendere le barche.$"

LilycoveCity_Text_SomeoneStoleMyPokemon:
	.string "Dormivo tranquillo alla locanda\n"
	.string "sul mare, cullato dalle onde…\p"
	.string "Quando mi hanno rubato i POKéMON!\p"
	.string "Chi è il ladro?\n"
	.string "Il TEAM AQUA? È il TEAM AQUA?$"

LilycoveCity_Text_MissingPokemonCameBack:
	.string "Il mio POKéMON sparito…\n"
	.string "È tornato senza che me ne accorgessi!$"

LilycoveCity_Text_ImArtDealer:
	.string "Sono un MERCANTE D'ARTE.\p"
	.string "Compro e vendo belle opere,\n"
	.string "soprattutto quadri.\p"
	.string "Ho sentito che il MUSEO qui\n"
	.string "espone opere magnifiche…$"

LilycoveCity_Text_SeaRemainsForeverYoung:
	.string "Anche se invecchiamo e ci\n"
	.string "spieghiamo, il mare resta giovane,\l"
	.string "con il vivo splendore della vita…\p"
	.string "Fuooho fuoohohoho…$"

LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
	.string "Sessant'anni fa mio marito\n"
	.string "mi chiese qui di sposarlo.\l"
	.string "Il mare è bello come allora.\p"
	.string "Mufufufu mufufufufufu…$"

LilycoveCity_Text_TeamAquaRenovatedCavern:
	.string "Mh, conosci la caverna strana\n"
	.string "di questa cala?\p"
	.string "Era una formazione naturale,\n"
	.string "ma poi è arrivato il TEAM AQUA\l"
	.string "e l'ha ristrutturata.\p"
	.string "Si fanno chiamare\n"
	.string "il “TEAM AQUA amante della natura”!\p"
	.string "Ma fanno e dicono\n"
	.string "cose del tutto diverse!$"

LilycoveCity_Text_TeamAquaLotGoneForGood:
	.string "Quella grotta nella cala…\p"
	.string "Non l'avevo notato subito,\n"
	.string "ma ora è del tutto vuota.\p"
	.string "Quei del TEAM AQUA se ne\n"
	.string "sono andati per sempre.$"

LilycoveCity_Text_CitySign:
	.string "PORTO ALGHEPOLI\p"
	.string "“Dove la terra finisce\n"
	.string "e inizia il mare.”$"

LilycoveCity_Text_ContestHallSign:
	.string "SALA GARE POKéMON\n"
	.string "“Il ritrovo degli ALLENATORI!”$"

LilycoveCity_Text_MotelSign:
	.string "MOTEL COVE LILY\p"
	.string "“Ricordaci come COVE LILY di\n"
	.string "LILYCOVE.”$"

LilycoveCity_Text_MuseumSign:
	.string "MUSEO DI LILYCOVE\p"
	.string "“Collezione di capolavori\n"
	.string "POKéMON in mostra!”$"

LilycoveCity_Text_MuseumSignPlayersExhibit:
	.string "MUSEO DI LILYCOVE\p"
	.string "“Collezione POKéMON di {PLAYER}\n"
	.string "in mostra!”$"

LilycoveCity_Text_HarborSignUnderConstruction:
	.string "PORTO DI LILYCOVE\p"
	.string "“Il traghetto S.S. TIDAL è in\n"
	.string "costruzione a SLATEPORT.\p"
	.string "“Il servizio inizierà\n"
	.string "a breve.”$"

LilycoveCity_Text_HarborSign:
	.string "PORTO DI PORTO ALGHEPOLI\p"
	.string "“Goditi la crociera\n"
	.string "sul S.S. TIDAL.”$"

LilycoveCity_Text_TrainerFanClubSign:
	.string "FAN CLUB ALLENATORI POKéMON\p"
	.string "I nomi degli ALLENATORI sono\n"
	.string "scritti su tutto il cartello…$"

LilycoveCity_Text_DepartmentStoreSign:
	.string "GRANDI MAGAZZINI DI PORTO ALGHEPOLI\p"
	.string "“Pieni di merce\n"
	.string "ed emozioni!\p"
	.string "“Il posto giusto per ciò\n"
	.string "che ti serve!”$"

LilycoveCity_Text_MoveDeletersHouseSign:
	.string "CASA ELIMINAMOSSE\p"
	.string "“Eliminiamo le mosse inutili.”$"

LilycoveCity_Text_DoYouKnowAboutBerryBlender:
	.string "Conosci la macchina\n"
	.string "FRULLABACCHE?$"

LilycoveCity_Text_FasterSpinBetterPokeblocks:
	.string "Bisogna girarlo insieme\n"
	.string "per farlo girare più veloce.\p"
	.string "Più gira veloce, migliori\n"
	.string "{POKEBLOCK} ottieni, si dice.$"

LilycoveCity_Text_ExplainBerryBlender:
	.string "Serve a fare una specie di caramella\n"
	.string "chiamata {POKEBLOCK}.\p"
	.string "Dai un {POKEBLOCK} buono a un POKéMON\n"
	.string "e la sua condizione migliora molto.$"

LilycoveCity_Text_HeardTowerCalledSkyPillar:
	.string "Ho sentito che c'è una torre\n"
	.string "sulle rotte marine.\p"
	.string "Si chiama SKY PILLAR, dicono.$"

LilycoveCity_Text_SawTallTowerOnRoute131:
	.string "Ho visto una torre alta\n"
	.string "vicino al PERCORSO 131.\p"
	.string "Che sia…?$"

LilycoveCity_Text_JustArrivedAndSawRarePokemon:
	.string "Siamo appena arrivati per il\n"
	.string "viaggio di nozze.\p"
	.string "Abbiamo visto un POKéMON\n"
	.string "di tipo Drago volare in cielo.\p"
	.string "POKéMON così vivono nella\n"
	.string "regione di HOENN?$"

LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
	.string "In viaggio di nozze abbiamo promesso\n"
	.string "di vedere tanti POKéMON rari.\p"
	.string "Perciò siamo stati felici di vederne\n"
	.string "uno appena arrivati.\p"
	.string "Siamo davvero contenti!$"

