Route39_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route39_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route39_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route39_EventScript_Item_TM::
	finditem ITEM_TM_DRAIN_PUNCH
	end

Route39_EventScript_Item_Nugget::
	finditem ITEM_BIG_NUGGET
	end

Route39_EventScript_LegendaryTrigger::
	lock
	clearflag FLAG_HIDE_ROUTE39_SHADOW
	addobject LOCALID_R39_SHADOW
	playse SE_M_RAZOR_WIND
	applymovement LOCALID_R39_SHADOW, Route39_Movement_ShadowSlideDown
	waitmovement 0
	setflag FLAG_HIDE_ROUTE39_SHADOW
	removeobject LOCALID_R39_SHADOW
	playse SE_PIN
	applymovement LOCALID_R39_BAOBA, Common_Movement_QuestionMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	turnobject LOCALID_R39_BAOBA DIR_SOUTH
	turnobject OBJ_EVENT_ID_PLAYER DIR_SOUTH
	delay 60

	getplayerxy VAR_TEMP_0, VAR_TEMP_1

	call_if_eq VAR_TEMP_1, 20, Route39_EventScript_BaobaMovement1
	call_if_eq VAR_TEMP_1, 21, Route39_EventScript_BaobaMovement2
	call_if_eq VAR_TEMP_1, 22, Route39_EventScript_BaobaMovement3
	call_if_eq VAR_TEMP_1, 23, Route39_EventScript_BaobaMovement4

	turnobject LOCALID_R39_BAOBA DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER DIR_WEST
Route39_EventScript_ChooseLegend::
	msgbox Route39_Text_ChooseLegend, MSGBOX_DEFAULT
	multichoice 20, 8, MULTI_GOLDSILVER, FALSE
	switch VAR_RESULT
	case 0, Route39_EventScript_LegendaryTriggerGold
	case 1, Route39_EventScript_LegendaryTriggerSilver
	case MULTI_B_PRESSED, Route39_EventScript_ChooseLegend
	release
	end

Route39_EventScript_BaobaMovement1::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba1
	waitmovement 0
	return
Route39_EventScript_BaobaMovement2::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba2
	waitmovement 0
	return
Route39_EventScript_BaobaMovement3::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba3
	waitmovement 0
	return
Route39_EventScript_BaobaMovement4::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba4
	waitmovement 0
	return

Route39_Movement_Baoba1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end
Route39_Movement_Baoba2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end
Route39_Movement_Baoba3:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end
Route39_Movement_Baoba4:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

Route39_EventScript_LegendaryTriggerGold::
	setvar VAR_LUGIA_OR_HOOH, 2
	goto Route39_EventScript_BaobaIntro

Route39_EventScript_LegendaryTriggerSilver::
	setvar VAR_LUGIA_OR_HOOH, 1
	goto Route39_EventScript_BaobaIntro

Route39_EventScript_BaobaIntro::
	msgbox Route39_Text_BaobaIntro, MSGBOX_DEFAULT
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox Route39_Text_Registered, MSGBOX_DEFAULT
	waitfanfare
	msgbox Route39_Text_WillCall, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_R39_BAOBA, Route39_Movement_BaobaLeave
	waitmovement 0
	setflag FLAG_ENABLE_BAOBA_MATCH_CALL
	removeobject LOCALID_R39_BAOBA
	release
	end

Route39_Text_ChooseLegend::
	.string "BAOBA: SANTO CIELO! Quell'\n"
	.string "ombra era di un POKéMON?\p"
	.string "L'hai vista bene?\n"
	.string "Non capisco di che colore fosse...$"

Route39_Text_BaobaIntro::
	.string "Che strano...\p"
	.string "...Ohh!\n"
	.string "Quello che hai in mano è...\l"
	.string "il cosiddetto... POKéDEX!\p"
	.string "Non ne vedevo uno da secoli.\p"
	.string "Mi chiamo BAOBA!\n"
	.string "Gestivo una ZONA SAFARI a\l"
	.string "FUCHSIA, ma stava diventando\l"
	.string "obsoleta con le nuove forme di\l"
	.string "intrattenimento.\p"
	.string "Ho deciso di andare all'estero a studiare\n"
	.string "le nuove tecnologie e aprire una\l"
	.string "ZONA SAFARI all'avanguardia\l"
	.string "a CIANWOOD.\p"
	.string "Forse non è un caso\n"
	.string "che stiamo parlando.\p"
	.string "Perché non ci scambiamo i numeri\n"
	.string "nel POKéGEAR?\p"
	.string "Ti chiamerò appena la ZONA\n"
	.string "SAFARI apre, prima di\l"
	.string "chiunque altro!$"

Route39_Text_Registered:
	.string "{PLAYER} ha registrato BAOBA\n"
	.string "nel POKéGEAR!$"


Route39_Text_WillCall:
	.string "BAOBA: Ti farò sapere\n"
	.string "presto col POKéGEAR!$"

Route39_Movement_BaobaLeave:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route39_Movement_ShadowSlideDown:
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	step_end

Route39_EventScript_Woman::
	lock
	faceplayer
	msgbox Route39_Text_Woman, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_Text_Woman:
	.string "Quell'ombra... Forse era un gigante\n"
	.string "PIDGEY?$"

Route39_EventScript_Miltank::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MILTANK, CRY_MODE_NORMAL
	msgbox Route39_Text_Miltank, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route39_Text_Miltank:
	.string "MILTANK: Muuu!$"

Route39_EventScript_Eugene::
	trainerbattle_single TRAINER_EUGENE_HNS, Route39_Text_SailorEugeneSeen, Route39_Text_SailorEugeneBeaten
	msgbox Route39_Text_SailorEugeneAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_SailorEugeneSeen:
	.string "Sono appena tornato a OLIVINE.\p"
	.string "Che ne dici di una lotta POKéMON?$"

Route39_Text_SailorEugeneBeaten:
	.string "Aaaargh!$"

Route39_Text_SailorEugeneAfter:
	.string "I miei POKéMON sono stati presi\n"
	.string "e cresciuti oltremare.\p"
	.string "Sono i miei compagni nei\n"
	.string "lunghi viaggi.$"

Route39_EventScript_Derek::
	trainerbattle_single TRAINER_DEREK_HNS, Route39_Text_PokefanMDerekSeen, Route39_Text_PokefanMDerekBeaten, Route39_EventScript_RegisterDerek
	goto_if_set FLAG_DEREK_HAS_ITEM_HNS, Route39_EventScript_DerekGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route39_EventScript_RematchDerek
	msgbox Route39_Text_PokefanMDerekAfter, MSGBOX_AUTOCLOSE
	end

Route39_EventScript_RematchDerek::
	trainerbattle_rematch TRAINER_DEREK_HNS, Route39_Text_PokefanMDerekSeen, Route39_Text_PokefanMDerekBeaten
	msgbox Route39_Text_PokefanMDerekAfter, MSGBOX_AUTOCLOSE
	end

Route39_EventScript_RegisterDerek::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route39_Text_DerekRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DEREK_HNS
	release
	end

Route39_EventScript_DerekGiveItem::
	msgbox Route39_Text_DerekHasItem, MSGBOX_DEFAULT
	giveitem VAR_DEREK_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route39_EventScript_DerekNoRoom
	clearflag FLAG_DEREK_HAS_ITEM_HNS
	msgbox Route39_Text_DerekGaveItem, MSGBOX_AUTOCLOSE
	end

Route39_EventScript_DerekNoRoom::
	msgbox Route39_Text_DerekNoRoom, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanMDerekSeen:
	.string "È il momento giusto per vantarsi\n"
	.string "del mio PIKACHU!$"

Route39_Text_PokefanMDerekBeaten:
	.string "Non ho avuto tempo di mostrare\n"
	.string "PIKACHU…$"

Route39_Text_PokefanMDerekAfter:
	.string "Non ascolto le tue\n"
	.string "vanterie!\p"
	.string "Noi POKé FAN abbiamo una regola:\n"
	.string "niente vanterie!$"

Route39_EventScript_Ruth::
	trainerbattle_single TRAINER_RUTH_HNS, Route39_Text_PokefanFRuthSeen, Route39_Text_PokefanFRuthBeaten
	msgbox Route39_Text_PokefanFRuthAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanFRuthSeen:
	.string "Che POKéMON adorabili.\p"
	.string "Mostriamo i nostri POKéMON\n"
	.string "insieme allo stesso tempo.$"

Route39_Text_PokefanFRuthBeaten:
	.string "Non mi importa perdere.$"

Route39_Text_PokefanFRuthAfter:
	.string "Conosci i POKéMON\n"
	.string "bebè?\p"
	.string "Scommetto che sono adorabili!$"

Route39_EventScript_Norman::
	trainerbattle_single TRAINER_NORMAN_HNS, Route39_Text_PsychicNormanSeen, Route39_Text_PsychicNormanBeaten
	msgbox Route39_Text_PsychicNormanAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PsychicNormanSeen:
	.string "Fammi vedere di cosa\n"
	.string "sono capaci i tuoi POKéMON.$"

Route39_Text_PsychicNormanBeaten:
	.string "Ooh, i tuoi POKéMON hanno\n"
	.string "potenziale.$"

Route39_Text_PsychicNormanAfter:
	.string "Sai che i POKéMON hanno\n"
	.string "abilità diverse?\p"
	.string "Anche le persone sono così.\n"
	.string "Ognuno ha un potenziale\l"
	.string "diverso.$"

Route39_EventScript_Jamie::
	trainerbattle_single TRAINER_JAMIE_HNS, Route39_Text_PokefanFJaimeSeen, Route39_Text_PokefanFJaimeBeaten
	msgbox Route39_Text_PokefanFJaimeAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanFJaimeSeen:
	.string "Sei arrivato al momento\n"
	.string "giusto.\p"
	.string "Lottiamo.$"

Route39_Text_PokefanFJaimeBeaten:
	.string "Oh, che delusione…$"

Route39_Text_PokefanFJaimeAfter:
	.string "Ho incontrato UMBREON di notte proprio\n"
	.string "qui al PERCORSO 39.\p"
	.string "Non so perché, ma\n"
	.string "sembra gradire che mi\l"
	.string "alleni qui.\p"
	.string "Sembra diventare più amichevole\n"
	.string "allenandosi qui che\l"
	.string "altrove.$"

Route39_EventScript_Sign1::
	lock
	msgbox Route39_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_Sign:
	.string "PERCORSO 39\p"
	.string "OLIVINOPOLI - AMARANTOPOLI$"

Route39_EventScript_Sign2::
	lock
	msgbox Route39_Text_MoomooFarmSign, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_MoomooFarmSign:
	.string "FATTORIA MOOMOO\p"
	.string "Goditi il nostro latte fresco e gustoso$"

Route39_EventScript_Sign3::
	lock
	msgbox Route39_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_TrainerTips:
	.string "CONSIGLI\p"
	.string "Usa BOTTINTESTA sugli alberi per\n"
	.string "far uscire i POKéMON.\p"
	.string "Diversi tipi di POKéMON\n"
	.string "cadono dagli alberi.\p"
	.string "Usa BOTTINTESTA su ogni albero\n"
	.string "che vedi!$"

Route39_Text_DerekRegister:
	.string "Non ascolto le tue\n"
	.string "vanterie!\p"
	.string "Noi POKé FAN abbiamo una regola:\n"
	.string "niente vanterie!$"

Route39_Text_DerekHasItem:
	.string "Ehi! Mentre mostravo il mio\n"
	.string "PIKACHU ho trovato una cosa.\p"
	.string "Tieni, è per te!$"

Route39_Text_DerekGaveItem:
	.string "PIKACHU è il migliore!\n"
	.string "Non sei d'accordo?$"

Route39_Text_DerekNoRoom:
	.string "Hmm, la tua BORSA è piena.\p"
	.string "Torna quando avrai spazio.$"
