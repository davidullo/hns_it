Route12_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route12_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route12_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route12_EventScript_Martin::
	trainerbattle_single TRAINER_MARTIN_HNS, Route12_Text_FisherMartinSeen, Route12_Text_FisherMartinBeaten
	msgbox Route12_Text_FisherMartinAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Stephen::
	trainerbattle_single TRAINER_STEPHEN_HNS, Route12_Text_FisherStephenSeen, Route12_Text_FisherStephenBeaten
	msgbox Route12_Text_FisherStephenAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Barney::
	trainerbattle_single TRAINER_BARNEY_HNS, Route12_Text_FisherBarneySeen, Route12_Text_FisherBarneyBeaten
	msgbox Route12_Text_FisherBarneyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Kyle::
	trainerbattle_single TRAINER_KYLE_HNS, Route12_Text_FisherKyleSeen, Route12_Text_FisherKyleBeaten, Route12_EventScript_RegisterKyle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route12_EventScript_RematchKyle
	msgbox Route12_Text_FisherKyleAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_RegisterKyle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route12_Text_KyleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KYLE_HNS
	release
	end

Route12_EventScript_RematchKyle::
	trainerbattle_rematch TRAINER_KYLE_HNS, Route12_Text_KyleRematchIntro, Route12_Text_KyleRematchDefeat
	msgbox Route12_Text_KylePostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_KYLE_2_HNS, Route12_EventScript_RematchKyleTryGiveItem
	end

Route12_EventScript_RematchKyleTryGiveItem::
	checkitem ITEM_BLUE_SHARD
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_BLUE_SHARD
	closemessage
	end

Route12_EventScript_NewFisher::
	msgbox Route12_Text_NewFisher, MSGBOX_NPC
	end

Route12_EventScript_Elixir::
	finditem ITEM_ELIXIR
	end

Route12_EventScript_Calcium::
	finditem ITEM_CALCIUM
	end

Route12_EventScript_Magikarp::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAGIKARP, CRY_MODE_NORMAL
	msgbox Route12_Text_Magikarp, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route12_EventScript_Tentacruel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route12_Text_Magikarp:
	.string "MAGIKARP: Kaaaarp.$"

Route12_Text_NewFisher:
	.string "Attento, in queste acque vive\n"
	.string "qualcosa di feroce.$"

Route12_Text_FisherMartinSeen:
	.string "La pazienza è la chiave sia per\n"
	.string "pescare sia per i POKéMON.$"

Route12_Text_FisherMartinBeaten:
	.string "Guaaah!$"

Route12_Text_FisherMartinAfterBattle:
	.string "Sono troppo impaziente per pescare…$"

Route12_Text_FisherStephenSeen:
	.string "Sto così bene, pesco mentre\n"
	.string "ascolto un po' di musica\l"
	.string "alla radio.$"

Route12_Text_FisherStephenBeaten:
	.string "La mia stupida radio mi ha distratto!$"

Route12_Text_FisherStephenAfterBattle:
	.string "Hai sentito i programmi radio di\n"
	.string "KANTO? Qui c'è una bella\l"
	.string "varietà.$"

Route12_Text_FisherBarneySeen:
	.string "Qual è la cosa più importante\n"
	.string "nella vita di tutti i giorni?$"

Route12_Text_FisherBarneyBeaten:
	.string "La risposta arriva subito dopo!$"

Route12_Text_FisherBarneyAfterBattle:
	.string "Penso che l'elettricità sia la cosa\n"
	.string "più importante della nostra vita\l"
	.string "quotidiana.\p"
	.string "Altrimenti la gente non avrebbe\n"
	.string "fatto tanto chiasso quando la\l"
	.string "CENTRALE è andata fuori\l"
	.string "servizio.$"

Route12_Text_KyleRegister:
	.string "Me lo ricorderò.\n"
	.string "Dammi il tuo numero!$"

Route12_Text_KyleRematchIntro:
	.string "Hai dimenticato?\n"
	.string "Vediamo!$"

Route12_Text_KyleRematchDefeat:
	.string "Te ne sei ricordato.$"

Route12_Text_KylePostRematch:
	.string "Il brivido della lotta è quasi\n"
	.string "bello come una bella cattura!$"

Route12_Text_FisherKyleSeen:
	.string "Ti ricordi?$"

Route12_Text_FisherKyleBeaten:
	.string "Te lo ricordi?$"

Route12_Text_FisherKyleAfterBattle:
	.string "Lo strattone che senti sulla CANNA\n"
	.string "quando abbocca un POKéMON…\p"
	.string "È la sensazione più bella per\n"
	.string "un pescatore come me.$"

Route12_EventScript_Sign::
	msgbox Route12_Text_Sign, MSGBOX_SIGN
	end

Route12_EventScript_FishingSign::
	msgbox Route12_Text_FishingSpotSign, MSGBOX_SIGN
	end

Route12_Text_Sign:
	.string "PERCORSO 12\p"
	.string "A NORD VERSO LAVANDONIA$"

Route12_Text_FishingSpotSign:
	.string "ZONA DI PESCA$"

