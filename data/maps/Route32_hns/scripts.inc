Route32_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route32_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route32_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route32_EventScript_FisherJustin::
	trainerbattle_single TRAINER_JUSTIN_HNS, Route32_Text_FisherJustin_Seen, Route32_Text_FisherJustin_Beaten
	msgbox Route32_Text_FisherJustin_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_FisherRalph::
	trainerbattle_single TRAINER_RALPH_HNS, Route32_Text_FisherRalph1_Seen, Route32_Text_FisherRalph1_Beaten, Route32_EventScript_RegisterRalph
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_RematchRalph
	msgbox Route32_Text_FisherRalph1_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_RegisterRalph::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route32_Text_RalphRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_RALPH_HNS
	release
	end

Route32_EventScript_RematchRalph::
	trainerbattle_rematch TRAINER_RALPH_HNS, Route32_Text_RalphRematchIntro, Route32_Text_RalphRematchDefeat
	msgbox Route32_Text_RalphPostRematch, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_FisherHenry::
	trainerbattle_single TRAINER_HENRY_HNS, Route32_Text_FisherHenry_Seen, Route32_Text_FisherHenry_Beaten
	msgbox Route32_Text_FisherHenry_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_YoungsterAlbert::
	trainerbattle_single TRAINER_ALBERT_HNS, Route32_Text_YoungsterAlbert_Seen, Route32_Text_YoungsterAlbert_Beaten
	msgbox Route32_Text_YoungsterAlbert_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_YoungsterGordon::
	trainerbattle_single TRAINER_GORDON_HNS, Route32_Text_YoungsterGordon_Seen, Route32_Text_YoungsterGordon_Beaten
	msgbox Route32_Text_YoungsterGordon_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_CamperRoland::
	trainerbattle_single TRAINER_ROLAND_HNS, Route32_Text_CamperRoland_Seen, Route32_Text_CamperRoland_Beaten
	msgbox Route32_Text_CamperRoland_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_PicnickerLiz::
	trainerbattle_single TRAINER_LIZ_HNS, Route32_Text_PicnickerLiz1_Seen, Route32_Text_PicnickerLiz1_Beaten, Route32_EventScript_RegisterLiz
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_RematchLiz
	msgbox Route32_Text_PicnickerLiz1_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_RegisterLiz::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route32_Text_LizRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_LIZ_HNS
	release
	end

Route32_EventScript_RematchLiz::
	trainerbattle_rematch TRAINER_LIZ_HNS, Route32_Text_LizRematchIntro, Route32_Text_LizRematchDefeat
	msgbox Route32_Text_LizPostRematch, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_BirdkeeperPeter::
	trainerbattle_single TRAINER_PETER_HNS, Route32_Text_BirdKeeperPeter_Seen, Route32_Text_BirdKeeperPeter_Beaten
	msgbox Route32_Text_BirdKeeperPeter_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_Roar::
	lock
	faceplayer
	checkitem ITEM_TM_ROAR
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_Roar2
	msgbox Route32_Text_RoarIntro, MSGBOX_DEFAULT
	giveitem ITEM_TM_ROAR
	msgbox Route32_Text_RoarOutro, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_Roar2::
	msgbox Route32_Text_RoarOutro, MSGBOX_DEFAULT
	closemessage
	release
	end

Route32_EventScript_SlowpokeTail_TriggerLeft::
	lock
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SLOWPOKETAIL_MAN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeLeft
	waitmovement 0
	goto Route32_EventScript_SlowpokeTail_Trigger

Route32_EventScript_SlowpokeTail_TriggerMid::
	lock
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SLOWPOKETAIL_MAN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeMid
	waitmovement 0
	goto Route32_EventScript_SlowpokeTail_Trigger

Route32_EventScript_SlowpokeTail_TriggerRight::
	lock
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SLOWPOKETAIL_MAN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeRight
	waitmovement 0
	goto Route32_EventScript_SlowpokeTail_Trigger

Route32_EventScript_SlowpokeTail_Trigger::
	msgbox Route32_Text_SlowpokeTailOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_SlowpokeTail_Trigger2
	msgbox Route32_Text_RefusedSlowpokeTail, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SLOWPOKE_TAIL, 1
	release
	end	
Route32_EventScript_SlowpokeTail_Trigger2::
	msgbox Route32_Text_ThoughtKidsLoaded, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 16, Route32_EventScript_Movement_Left
	call_if_eq VAR_TEMP_0, 17, 	Route32_EventScript_Movement_Right
	setvar VAR_SLOWPOKE_TAIL, 1
	release
	end

Route32_EventScript_Movement_Left::
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
	waitmovement 0
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	return 

Route32_EventScript_Movement_Right::
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
	waitmovement 0
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	return 	

Route32_EventScript_SlowpokeTail::
	lock
	faceplayer
	msgbox Route32_Text_SlowpokeTailOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_SlowpokeTail2
	msgbox Route32_Text_RefusedSlowpokeTail, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_SlowpokeTail2::
	msgbox Route32_Text_ThoughtKidsLoaded, MSGBOX_DEFAULT
	closemessage
	release
	end


Route32_EventScript_Frieda::
	lock
	faceplayer
	goto_if_set FLAG_GOT_POISON_BARB, Route32_EventScript_FriedaCompleted
	msgbox Route32_Text_MeetFrieda, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route32_EventScript_FriedaNope
	case 1, Route32_EventScript_FriedaNope
	case 2, Route32_EventScript_FriedaNope
	case 3, Route32_EventScript_FriedaNope
	case 4, Route32_EventScript_FriedaNope
	case 5, Route32_EventScript_FriedaYes
	case 6, Route32_EventScript_FriedaNope
	case 7, Route32_EventScript_FriedaCancel
	case MULTI_B_PRESSED, Route32_EventScript_FriedaCancel
	closemessage
	release
	end
Route32_EventScript_FriedaYes::
	msgbox Route32_Text_FriedaGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_POISON_BARB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_POISON_BARB
	msgbox Route32_Text_FriedaGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_FriedaNope::
	msgbox Route32_Text_FriedaNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_FriedaCancel::
	closemessage
	release
	end
Route32_EventScript_FriedaCompleted::
	msgbox Route32_Text_FriedaFriday, MSGBOX_DEFAULT
	closemessage
	release
	end

Route32_EventScript_BaldingMan::
	lock
	faceplayer
	msgbox Route32_Text_CooltrainerM_Experiences, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROUTE32_BALDINGMAN, DIR_EAST
	release
	end

Route32_EventScript_BaldingManTriggerLeft::
	lock
	playse SE_PIN
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ROUTE32_BALDINGMAN
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	goto Route32_EventScript_BaldingManCheck
	end
Route32_EventScript_BaldingManTriggerMid::
	lock
	playse SE_PIN
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ROUTE32_BALDINGMAN
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_StartMid
	waitmovement 0
	goto Route32_EventScript_BaldingManCheck
	end
Route32_EventScript_BaldingManTriggerRight::
	lock
	playse SE_PIN
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ROUTE32_BALDINGMAN
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movment_StartRight
	waitmovement 0
	goto Route32_EventScript_BaldingManCheck
	end
Route32_EventScript_BaldingManCheck::
	goto_if_unset FLAG_HIDE_SPROUT_TOWER_SILVER, Route32_EventScript_BaldingManTower
	goto_if_unset FLAG_DEFEATED_VIOLET_GYM, Route32_EventScript_BaldingManGym
	goto_if_unset FLAG_RECEIVED_TOGEPI_EGG, Route32_EventScript_BaldingManEgg
	msgbox Route32_Text_CooltrainerM_HaveThisSeed, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setvar VAR_VIOLET_CITY_STATE, 5
	release
	end
Route32_EventScript_BaldingManTower::
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
	msgbox Route32_Text_CooltrainerM_SproutTower, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
	waitmovement 0
	release
	end
Route32_EventScript_BaldingManGym::
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
	msgbox Route32_Text_CooltrainerM_VioletGym, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
	waitmovement 0
	release
	end
Route32_EventScript_BaldingManEgg::
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
	msgbox Route32_Text_CooltrainerM_AideIsWaiting, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
	waitmovement 0
	release
	end

Route32_EventScript_Item_Bullet_Seed::
    finditem ITEM_TM_BULLET_SEED
    end
	
Route32_EventScript_GreatBall::
	finditem ITEM_GREAT_BALL
	end
Route32_EventScript_GreatBallII::
	finditem ITEM_GREAT_BALL
	end
Route32_EventScript_SuperPotion::
	finditem ITEM_SUPER_POTION
	end

Route32_EventScript_Sign1::
	lock
	msgbox Route32_Text_Sign1, MSGBOX_SIGN
	closemessage
	release
	end

Route32_EventScript_Sign2::
	lock
	msgbox Route32_Text_Sign2, MSGBOX_SIGN
	closemessage
	release
	end

Route32_EventScript_Sign3::
	lock
	msgbox Route32_Text_Sign3, MSGBOX_SIGN
	closemessage
	release
	end

Route32_Movement_Turnback:
	walk_up
	step_end

Route32_Movement_StartMid:
	walk_left
	step_end

Route32_Movment_StartRight:
	walk_left
	walk_left
	step_end

Route32_Movement_SlowpokeLeft::
	step_end

Route32_Movement_SlowpokeMid::
	walk_right
	step_end

Route32_Movement_SlowpokeRight::
	walk_right
	walk_right
	step_end

Route32_Text_CooltrainerM_WhatsTheHurry:
	.string "Aspetta!\n"
	.string "Che fretta hai?$"

Route32_Text_CooltrainerM_AideIsWaiting:
	.string "{PLAYER}, giusto?\n"
	.string "Un tipo con gli occhiali\p"
	.string "ti stava cercando.\p"
	.string "Guarda tu stesso. Ti aspetta\n"
	.string "al CENTRO POKéMON.$"

Route32_Text_CooltrainerM_SproutTower:
	.string "Sei andato alla TORRE SPROUT?\n"
	.string "Se vai a VIOLETTO,\p"
	.string "si aspetteranno che ti alleni lì.\n"
	.string "È la base per gli allenatori.\p"
	.string "Vai alla TORRE SPROUT!$"

Route32_Text_CooltrainerM_VioletGym:
	.string "Sei andato alla PALESTRA POKéMON?\n"
	.string "Lì puoi mettere alla prova i POKéMON\p"
	.string "e te stesso.\n"
	.string "È un rito di passaggio per tutti\p"
	.string "gli allenatori!$"

Route32_Text_CooltrainerM_HaveThisSeed:
	.string "Hai dei POKéMON niente male.\n"
	.string "Dev'essere per l'allenamento che\p"
	.string "hai dato loro a VIOLETTO.\n"
	.string "L'allenamento in PALESTRA dev'essere\p"
	.string "stato prezioso. In ricordo di\n"
	.string "VIOLETTO, prendi questo.\p"
	.string "Aumenta la potenza delle mosse di\n"
	.string "tipo ERBA.$"

Route32_Text_CooltrainerM_Experiences:
	.string "Le tue esperienze a VIOLETTO\n"
	.string "ti serviranno nel viaggio.$"

Route32_Text_SlowpokeTailOffer:
	.string "Ti piacerebbe avere questa\n"
	.string "gustosa e nutriente CODA SLOWPOKE?\p"
	.string "Per te, adesso, solo\n"
	.string "¥1.000.000!\p"
	.string "Ti servirà!$"

Route32_Text_ThoughtKidsLoaded:
	.string "Tch! Credevo che i bambini\n"
	.string "di oggi fossero pieni di soldi…$"

Route32_Text_RefusedSlowpokeTail:
	.string "Non lo vuoi?\n"
	.string "Allora sparisci. Vai via!$"

Route32_Text_FisherJustin_Seen:
	.string "Whoa!\p"
	.string "Mi hai fatto perdere quel pesce!$"

Route32_Text_FisherJustin_Beaten:
	.string "Splush!$"

Route32_Text_FisherJustin_After:
	.string "Calma, sangue freddo… La pesca e i\n"
	.string "POKéMON sono la stessa cosa.$"

Route32_Text_FisherRalph1_Seen:
	.string "Sono bravo sia a pescare\n"
	.string "sia con i POKéMON.\p"
	.string "Non perderò di certo con un bambino!$"

Route32_Text_FisherRalph1_Beaten:
	.string "Tch! Ho voluto\n"
	.string "fare in fretta…$"

Route32_Text_FisherRalph1_After:
	.string "La pesca è una passione\n"
	.string "per tutta la vita.\p"
	.string "I POKéMON sono amici per la vita!$"

Route32_Text_RalphRegister:
	.string "La pesca è una passione\n"
	.string "per tutta la vita.\p"
	.string "I POKéMON sono amici per la vita!$"

Route32_Text_RalphRematchIntro:
	.string "Sono bravo sia a pescare\n"
	.string "sia con i POKéMON.\p"
	.string "Non perderò di certo con un bambino!$"

Route32_Text_RalphRematchDefeat:
	.string "Tch! Ho voluto\n"
	.string "fare in fretta…$"

Route32_Text_RalphPostRematch:
	.string "La pesca è una passione\n"
	.string "per tutta la vita.\p"
	.string "I POKéMON sono amici per la vita!$"

Route32_Text_FisherHenry_Seen:
	.string "I miei POKéMON? Appena presi!$"

Route32_Text_FisherHenry_Beaten:
	.string "SPLASH?$"

Route32_Text_FisherHenry_After:
	.string "I POKéMON appena presi non reggono\n"
	.string "contro quelli allenati bene.$"

Route32_Text_YoungsterAlbert_Seen:
	.string "Non ti ho mai visto da queste parti.\n"
	.string "Quindi credi di essere forte?$"

Route32_Text_YoungsterAlbert_Beaten:
	.string "Sei forte!$"

Route32_Text_YoungsterAlbert_After:
	.string "Voglio diventare il\n"
	.string "migliore con i miei preferiti.\p"
	.string "Non uso gli stessi POKéMON\n"
	.string "forti di tutti gli altri.$"

Route32_Text_YoungsterGordon_Seen:
	.string "Ho trovato dei bei POKéMON\n"
	.string "nell'erba!\p"
	.string "Credo che mi basteranno!$"

Route32_Text_YoungsterGordon_Beaten:
	.string "Accidenti. Credevo di vincere.$"

Route32_Text_YoungsterGordon_After:
	.string "L'erba è piena di\n"
	.string "bestie appiccicose.$"

Route32_Text_CamperRoland_Seen:
	.string "Quello sguardo… È intrigante.$"

Route32_Text_CamperRoland_Beaten:
	.string "Hmmm. Che delusione.$"

Route32_Text_CamperRoland_After:
	.string "Se non vuoi lottare,\n"
	.string "evita il contatto visivo.$"

Route32_Text_PicnickerLiz1_Seen:
	.string "Uh-huh. Sì, e sai…\p"
	.string "Come? Lotta? Sono al telefono.\n"
	.string "Oh, va bene. Ma fa' in fretta.$"

Route32_Text_PicnickerLiz1_Beaten:
	.string "Oh! Devo sfogare\n"
	.string "la mia rabbia!$"

Route32_Text_PicnickerLiz1_After:
	.string "Stavo facendo una bella chiacchierata.$"

Route32_Text_LizRegister:
	.string "Stavo facendo una bella chiacchierata.$"

Route32_Text_LizRematchIntro:
	.string "Uh-huh. Sì, e sai…\p"
	.string "Come? Lotta? Sono al telefono.\n"
	.string "Oh, va bene. Ma fa' in fretta.$"

Route32_Text_LizRematchDefeat:
	.string "Oh! Devo sfogare\n"
	.string "la mia rabbia!$"

Route32_Text_LizPostRematch:
	.string "Stavo facendo una bella chiacchierata.$"

Route32_Text_BirdKeeperPeter_Seen:
	.string "Quella MEDAGLIA! È di VIOLETTO!\n"
	.string "Hai battuto FALKNER?$"

Route32_Text_BirdKeeperPeter_Beaten:
	.string "Conosco le mie debolezze.$"

Route32_Text_BirdKeeperPeter_After:
	.string "Dovrei allenarmi di nuovo alla\n"
	.string "PALESTRA di VIOLETTO.$"

Route32_Text_RoarIntro:
	.string "WROOOOAR! LA GENTE SCAPPA AL MIO\n"
	.string "BOATO! MA TU SEI VENUTO!\p"
	.string "MI FA PIACERE! ORA PRENDI QUESTO!$"

Route32_Text_RoarOutro:
	.string "WROOOOAR! È BOATO!\p"
	.string "ANCHE I POKéMON SCAPPANO DA UN BUON\n"
	.string "BOATO!$"

Route32_Text_MeetFrieda:
	.string "FRIEDA: Yahoo!\p"
	.string "Sono FRIEDA della FAMIGLIA GIORNI!\n"
	.string "Piacere di conoscerti!\p"
	.string "Se indovini il mio giorno preferito,\n"
	.string "ti darò una ricompensa.$"

Route32_Text_FriedaGivesGift:
	.string "Ecco a te una PUNGIGLIA VELENO!$"

Route32_Text_FriedaGaveGift:
	.string "FRIEDA: Dallo a un POKéMON\n"
	.string "che ha mosse di tipo VELENO.\p"
	.string "Oh!\p"
	.string "È burbero!\p"
	.string "Vedrai quanto potenzia le\n"
	.string "mosse velenose!$"

Route32_Text_FriedaFriday:
	.string "FRIEDA: Ciao! Quale giorno\n"
	.string "ti piace?\p"
	.string "Adoro il venerdì. Senza\n"
	.string "dubbio!\p"
	.string "Non lo trovi fantastico anche tu?$"

Route32_Text_FriedaNope:
	.string "FRIEDA: Non quello!$"

Route32_Text_Sign1:
	.string "PERCORSO 32\p"
	.string "VIOLAPOLI - AZALINA$"

Route32_Text_Sign2:
	.string "ROVINE DI ALPH\n"
	.string "ENTRATA EST$"

Route32_Text_Sign3:
	.string "GROTTA UNION\n"
	.string "AVANTI$"
