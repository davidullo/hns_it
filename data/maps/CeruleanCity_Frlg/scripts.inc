CeruleanCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_OnTransition
	.byte 0

CeruleanCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_CERULEAN_CITY
	call_if_unset FLAG_GOT_SS_TICKET, CeruleanCity_EventScript_BlockExits
	end

CeruleanCity_EventScript_BlockExits::
	setobjectxyperm LOCALID_CERULEAN_POLICEMAN, 30, 12
	setobjectxyperm LOCALID_CERULEAN_SLOWBRO, 26, 31
	setobjectxyperm LOCALID_CERULEAN_LASS, 27, 31
	return

CeruleanCity_EventScript_RivalTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto CeruleanCity_EventScript_Rival
	end

CeruleanCity_EventScript_RivalTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	setobjectxyperm LOCALID_CERULEAN_RIVAL, 23, 0
	goto CeruleanCity_EventScript_Rival
	end

CeruleanCity_EventScript_RivalTriggerRight::
	lockall
	setvar VAR_TEMP_1, 2
	setobjectxyperm LOCALID_CERULEAN_RIVAL, 24, 0
	goto CeruleanCity_EventScript_Rival
	end

CeruleanCity_EventScript_Rival::
	textcolor NPC_TEXT_COLOR_MALE
	setvar VAR_MAP_SCENE_ROUTE22, 2
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	addobject LOCALID_CERULEAN_RIVAL
	applymovement LOCALID_CERULEAN_RIVAL, CeruleanCity_Movement_RivalEnter
	waitmovement 0
	msgbox CeruleanCity_Text_RivalIntro
	setvar VAR_LAST_TALKED, LOCALID_CERULEAN_RIVAL
	call_if_eq VAR_STARTER_MON, 2, CeruleanCity_EventScript_RivalSquirtle
	call_if_eq VAR_STARTER_MON, 1, CeruleanCity_EventScript_RivalBulbasaur
	call_if_eq VAR_STARTER_MON, 0, CeruleanCity_EventScript_RivalCharmander
	famechecker FAMECHECKER_BILL, 0
	msgbox CeruleanCity_Text_RivalPostBattle
	closemessage
	playbgm MUS_RG_RIVAL_EXIT, 0
	call_if_eq VAR_TEMP_1, 0, CeruleanCity_EventScript_RivalStartExit
	call_if_eq VAR_TEMP_1, 1, CeruleanCity_EventScript_RivalStartExit
	call_if_eq VAR_TEMP_1, 2, CeruleanCity_EventScript_RivalStartExitRight
	msgbox CeruleanCity_Text_OhRightLittlePresentAsFavor
	setvar VAR_MAP_SCENE_CERULEAN_CITY_RIVAL, 1
	setflag FLAG_GOT_FAME_CHECKER
	giveitem ITEM_FAME_CHECKER
	msgbox CeruleanCity_Text_ExplainFameCheckerSmellYa
	closemessage
	applymovement LOCALID_CERULEAN_RIVAL, CeruleanCity_Movement_RivalExit
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_CERULEAN_RIVAL
	releaseall
	end

CeruleanCity_EventScript_RivalSquirtle::
	trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_SQUIRTLE, CeruleanCity_Text_RivalDefeat
	return

CeruleanCity_EventScript_RivalBulbasaur::
	trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_BULBASAUR, CeruleanCity_Text_RivalDefeat
	return

CeruleanCity_EventScript_RivalCharmander::
	trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_CHARMANDER, CeruleanCity_Text_RivalDefeat
	return

CeruleanCity_EventScript_RivalStartExit::
	applymovement LOCALID_PLAYER, CeruleanCity_Movement_PlayerWatchRivalExit
	applymovement LOCALID_CERULEAN_RIVAL, CeruleanCity_Movement_RivalStartExit
	waitmovement 0
	return

CeruleanCity_EventScript_RivalStartExitRight::
	applymovement LOCALID_PLAYER, CeruleanCity_Movement_PlayerWatchRivalExitRight
	applymovement LOCALID_CERULEAN_RIVAL, CeruleanCity_Movement_RivalStartExitRight
	waitmovement 0
	return

CeruleanCity_Movement_PlayerWatchRivalExit::
	delay_16
	delay_8
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_down
	step_end

CeruleanCity_Movement_PlayerWatchRivalExitRight::
	delay_16
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

CeruleanCity_Movement_RivalEnter::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CeruleanCity_Movement_RivalStartExit::
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_16
	delay_16
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CeruleanCity_Movement_RivalStartExitRight::
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_16
	delay_16
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CeruleanCity_Movement_RivalExit::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CeruleanCity_EventScript_Grunt::
	lock
	faceplayer
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_EventScript_GruntDefeated
	message CeruleanCity_Text_GruntIntro
	waitmessage
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	waitbuttonpress
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_Text_GruntDefeat
	setvar VAR_MAP_SCENE_CERULEAN_CITY_ROCKET, 1
	goto CeruleanCity_EventScript_GruntDefeated
	end

CeruleanCity_EventScript_GruntDefeated::
	msgbox CeruleanCity_Text_OkayIllReturnStolenTM
	checkitemspace ITEM_TM28
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_EventScript_NoRoomForTM28
	giveitem_msg CeruleanCity_Text_RecoveredTM28FromGrunt, ITEM_TM28
	msgbox CeruleanCity_Text_BetterGetMovingBye
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_CERULEAN_GRUNT
	fadescreenswapbuffers FADE_FROM_BLACK
	setflag FLAG_GOT_TM28_FROM_ROCKET
	release
	end

CeruleanCity_EventScript_NoRoomForTM28::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox CeruleanCity_Text_MakeRoomForThisCantRun
	release
	end

CeruleanCity_EventScript_GruntTriggerTop::
	lockall
	setvar VAR_TEMP_1, 0
	applymovement LOCALID_CERULEAN_GRUNT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	goto CeruleanCity_EventScript_GruntTrigger
	end

CeruleanCity_EventScript_GruntTriggerBottom::
	lockall
	setvar VAR_TEMP_1, 1
	applymovement LOCALID_CERULEAN_GRUNT, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto CeruleanCity_EventScript_GruntTrigger
	end

CeruleanCity_EventScript_GruntTrigger::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox CeruleanCity_Text_GruntIntro
	setvar VAR_LAST_TALKED, LOCALID_CERULEAN_GRUNT
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_Text_GruntDefeat
	setvar VAR_MAP_SCENE_CERULEAN_CITY_ROCKET, 1
	goto CeruleanCity_EventScript_GruntDefeated
	end

CeruleanCity_EventScript_Policeman::
	lock
	faceplayer
	msgbox CeruleanCity_Text_PeopleHereWereRobbed
	closemessage
	applymovement LOCALID_CERULEAN_POLICEMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CeruleanCity_EventScript_LittleBoy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SS_TICKET, CeruleanCity_EventScript_LittleBoySlowbroMoved
	msgbox CeruleanCity_Text_IfSlowbroWasntThereCouldCutTree
	release
	end

CeruleanCity_EventScript_LittleBoySlowbroMoved::
	msgbox CeruleanCity_Text_YouCanCutDownSmallTrees
	release
	end

CeruleanCity_EventScript_BaldingMan::
	msgbox CeruleanCity_Text_PokemonEncyclopediaAmusing, MSGBOX_NPC
	end

CeruleanCity_EventScript_Youngster::
	msgbox CeruleanCity_Text_TrainerLifeIsToughIsntIt, MSGBOX_NPC
	end

CeruleanCity_EventScript_CeruleanCaveGuard::
	msgbox CeruleanCity_Text_ThisIsCeruleanCave, MSGBOX_NPC
	end

CeruleanCity_EventScript_Woman::
	lock
	faceplayer
	msgbox CeruleanCity_Text_WantBrightRedBicycle
	closemessage
	applymovement LOCALID_CERULEAN_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CeruleanCity_EventScript_Lass::
	lock
	random 3
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, CeruleanCity_EventScript_SlowbroCommand1
	call_if_eq VAR_0x8008, 1, CeruleanCity_EventScript_SlowbroCommand2
	call_if_eq VAR_0x8008, 2, CeruleanCity_EventScript_SlowbroCommand3
	waitmessage
	delay 40
	playse SE_PIN
	applymovement LOCALID_CERULEAN_SLOWBRO, Common_Movement_QuestionMark
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 0, CeruleanCity_EventScript_SlowbroFailed1
	call_if_eq VAR_0x8008, 1, CeruleanCity_EventScript_SlowbroFailed2
	call_if_eq VAR_0x8008, 2, CeruleanCity_EventScript_SlowbroFailed3
	release
	end

CeruleanCity_EventScript_SlowbroCommand1::
	message CeruleanCity_Text_SlowbroUseSonicboom
	return

CeruleanCity_EventScript_SlowbroCommand2::
	message CeruleanCity_Text_SlowbroPunch
	return

CeruleanCity_EventScript_SlowbroCommand3::
	message CeruleanCity_Text_SlowbroWithdraw
	return

CeruleanCity_EventScript_SlowbroFailed1::
	msgbox CeruleanCity_Text_SlowbroPayAttention
	return

CeruleanCity_EventScript_SlowbroFailed2::
	msgbox CeruleanCity_Text_NoYouBlewItAgain
	return

CeruleanCity_EventScript_SlowbroFailed3::
	msgbox CeruleanCity_Text_HardToControlMonsObedience
	return

CeruleanCity_EventScript_Slowbro::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, CeruleanCity_EventScript_SlowbroText1
	call_if_eq VAR_0x8008, 1, CeruleanCity_EventScript_SlowbroText2
	call_if_eq VAR_0x8008, 2, CeruleanCity_EventScript_SlowbroText3
	call_if_eq VAR_0x8008, 3, CeruleanCity_EventScript_SlowbroText4
	release
	end

CeruleanCity_EventScript_SlowbroText1::
	msgbox CeruleanCity_Text_SlowbroTookSnooze
	return

CeruleanCity_EventScript_SlowbroText2::
	msgbox CeruleanCity_Text_SlowbroLoafingAround
	return

CeruleanCity_EventScript_SlowbroText3::
	msgbox CeruleanCity_Text_SlowbroTurnedAway
	return

CeruleanCity_EventScript_SlowbroText4::
	msgbox CeruleanCity_Text_SlowbroIgnoredOrders
	return

CeruleanCity_EventScript_CitySign::
	msgbox CeruleanCity_Text_CitySign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_TrainerTips::
	msgbox CeruleanCity_Text_TrainerTipsHeldItems, MSGBOX_SIGN
	end

CeruleanCity_EventScript_BikeShopSign::
	msgbox CeruleanCity_Text_BikeShopSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_GymSign::
	lockall
	famechecker FAMECHECKER_MISTY, 0
	msgbox CeruleanCity_Text_GymSign
	releaseall
	end

CeruleanCity_Text_RivalIntro::
	.string "{RIVAL}: Ehi! {PLAYER}!\p"
	.string "Stai ancora arrancando da\n"
	.string "qui?\p"
	.string "Io sto una favola! Ho preso\n"
	.string "dei POKéMON forti e svegli!\p"
	.string "Fammi vedere cosa hai preso,\n"
	.string "{PLAYER}!$"

CeruleanCity_Text_RivalDefeat::
	.string "Ehi!\n"
	.string "Vacci piano!\l"
	.string "Hai già vinto!$"

CeruleanCity_Text_RivalPostBattle::
	.string "{RIVAL}: Sai cosa?\p"
	.string "Sono andato da BILL e mi ha\n"
	.string "fatto vedere POKéMON rari.\p"
	.string "Un sacco di pagine in più al mio\n"
	.string "POKéDEX!\p"
	.string "Dopotutto BILL è famoso come\n"
	.string "POKéMANIAC.\p"
	.string "Ha inventato anche il Sistema\n"
	.string "POKéMON su PC.\p"
	.string "Visto che usi il suo sistema,\n"
	.string "vai a ringraziarlo.\p"
	.string "Beh, io me ne vado!\n"
	.string "Ci vediamo!$"

CeruleanCity_Text_OhRightLittlePresentAsFavor::
	.string "Ah, già, certo.\p"
	.string "Mi fai pena. No, davvero.\n"
	.string "Arranchi sempre dietro di me.\p"
	.string "Tieni, ti do un piccolo\n"
	.string "regalino, dai.$"

CeruleanCity_Text_ExplainFameCheckerSmellYa::
	.string "Chi chiacchiera come te…\n"
	.string "È perfetto per te.\p"
	.string "Non mi serve, non m'importa\n"
	.string "degli altri.\p"
	.string "Ok, stavolta me ne vado\n"
	.string "davvero. Ciao!$"

CeruleanCity_Text_GruntIntro::
	.string "Ehi! Vattene!\n"
	.string "Non è casa tua!\p"
	.string "…Eh?\n"
	.string "Io?\p"
	.string "Un passante innocente!\n"
	.string "Non mi credi?{PLAY_BGM}{MUS_RG_ENCOUNTER_ROCKET}$"

CeruleanCity_Text_GruntDefeat::
	.string "RECLUTA: Mi arrendo!\n"
	.string "Me ne vado zitto!$"

CeruleanCity_Text_OkayIllReturnStolenTM::
	.string "…Ok.\n"
	.string "Ridò la MT che ho rubato.$"

CeruleanCity_Text_RecoveredTM28FromGrunt::
	.string "{PLAYER} ha ripreso la MT28\n"
	.string "dal RECLUTA ROCKET.$"

CeruleanCity_Text_BetterGetMovingBye::
	.string "È meglio che vada!\n"
	.string "Ciao!$"

CeruleanCity_Text_MakeRoomForThisCantRun::
	.string "Fai posto!\n"
	.string "Non scappo finché non te lo do!$"

CeruleanCity_Text_TrainerLifeIsToughIsntIt::
	.string "Anche tu ALLENATORE?\p"
	.string "Catturare, lottare…\n"
	.string "È una vita dura, no?$"

CeruleanCity_Text_YouCanCutDownSmallTrees::
	.string "Sapevi che puoi TAGLIARE gli\n"
	.string "alberelli?\p"
	.string "Perfino l'alberello davanti\n"
	.string "al negozio si può TAGLIARE.\p"
	.string "Credo ci sia un modo,\n"
	.string "però.$"

CeruleanCity_Text_IfSlowbroWasntThereCouldCutTree::
	.string "Se quel SLOWBRO non fosse lì,\n"
	.string "potresti TAGLIARE l'alberello.\p"
	.string "Così potresti arrivare\n"
	.string "di là.\p"
	.string "Credo ci sia un altro modo,\n"
	.string "però.$"

CeruleanCity_Text_PokemonEncyclopediaAmusing::
	.string "Stai facendo un'enciclopedia sui\n"
	.string "POKéMON? Che divertente.$"

CeruleanCity_Text_PeopleHereWereRobbed::
	.string "Qui hanno derubato tutti.\p"
	.string "È ovvio che il TEAM ROCKET è\n"
	.string "dietro questo orribile crimine!\p"
	.string "Perfino la nostra POLIZIA\n"
	.string "ha problemi con i ROCKET!$"

CeruleanCity_Text_SlowbroUseSonicboom::
	.string "Ok! SLOWBRO!\n"
	.string "Usa SONICBOOM!$"

CeruleanCity_Text_SlowbroPayAttention::
	.string "Dai, SLOWBRO, stai attento!$"

CeruleanCity_Text_SlowbroPunch::
	.string "SLOWBRO, pugno!$"

CeruleanCity_Text_NoYouBlewItAgain::
	.string "No!\n"
	.string "Di nuovo un flop!$"

CeruleanCity_Text_SlowbroWithdraw::
	.string "SLOWBRO, RITIRATA!$"

CeruleanCity_Text_HardToControlMonsObedience::
	.string "No! Sbagliato!\n"
	.string "Controllare i POKéMON è dura!\p"
	.string "L'obbedienza dei tuoi POKéMON\n"
	.string "dipende da te come ALLENATORE.$"

CeruleanCity_Text_SlowbroTookSnooze::
	.string "SLOWBRO si appisola…$"

CeruleanCity_Text_SlowbroLoafingAround::
	.string "SLOWBRO bighellona…$"

CeruleanCity_Text_SlowbroTurnedAway::
	.string "SLOWBRO si volta…$"

CeruleanCity_Text_SlowbroIgnoredOrders::
	.string "SLOWBRO non ascolta…$"

CeruleanCity_Text_WantBrightRedBicycle::
	.string "Voglio una Bicicletta rossa\p"
	.string "La tengo a casa, così non\n"
	.string "si sporca.$"

CeruleanCity_Text_ThisIsCeruleanCave::
	.string "È la GROTTA CELESTE.\p"
	.string "Dentro vivono POKéMON molto\n"
	.string "forti.\p"
	.string "Per entrare serve un ALLENATORE\n"
	.string "davvero speciale.\p"
	.string "Devi essere forte abbastanza da\n"
	.string "diventare CAMPIONE della\l"
	.string "LEGA POKéMON.\p"
	.string "E devi aver compiuto\n"
	.string "una grande impresa.$"

CeruleanCity_Text_CitySign::
	.string "CELESTOPOLI\n"
	.string "Un'aura blu e misteriosa la\l"
	.string "avvolge.$"

CeruleanCity_Text_TrainerTipsHeldItems::
	.string "CONSIGLI\p"
	.string "Un POKéMON può tenere un\n"
	.string "oggetto.\p"
	.string "Alcuni sono persino usati dal\n"
	.string "POKéMON che li tiene in lotta.$"

CeruleanCity_Text_BikeShopSign::
	.string "Erba e grotte senza problemi!\n"
	.string "NEGOZIO BICI$"

CeruleanCity_Text_GymSign::
	.string "PALESTRA POKéMON DI\n"
	.string "CELESTOPOLI: MISTY\l"
	.string "La sirena maschiaccio!$"

