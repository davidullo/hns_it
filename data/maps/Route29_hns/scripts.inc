Route29_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route29_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route29_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route29_Trigger_Monview::
	special SpawnCameraObject
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1 
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	message Route29_Text_PressAorB
	waitbuttonpress
	closemessage
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	special RemoveCameraObject
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	end

Route29_Text_PressAorB:
	.string "Premi A o B per smettere di guardare.$"

Route29_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, Route29_EventScript_OldMan2
	msgbox Route29_Text_OldMan1, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_OldMan2::
	msgbox Route29_Text_OldMan2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route29_EventScript_OldMan_Tutorial
	waitmessage
	msgbox Route29_Text_OldManDeclined, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_OldMan_Tutorial::
	msgbox Route29_Text_OldManExplanation, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Lass::
	lock
	faceplayer
	msgbox Route29_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route29_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end


Route29_EventScript_Tuscany::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SILK_SCARF, Route29_EventScript_TuscanyCompleted
	msgbox Route29_Text_MeetTuscany, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route29_EventScript_TuscanyNope
	case 1, Route29_EventScript_TuscanyNope
	case 2, Route29_EventScript_TuscanyYes
	case 3, Route29_EventScript_TuscanyNope
	case 4, Route29_EventScript_TuscanyNope
	case 5, Route29_EventScript_TuscanyNope
	case 6, Route29_EventScript_TuscanyNope
	case 7 Route29_EventScript_TuscanyCancel
	case MULTI_B_PRESSED, Route29_EventScript_TuscanyCancel
	closemessage
	release
	end
Route29_EventScript_TuscanyYes::
	msgbox Route29_Text_TuscanyGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_SILK_SCARF
	msgbox Route29_Text_TuscanyGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route29_EventScript_TuscanyNope::
	msgbox Route29_Text_TuscanyNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route29_EventScript_TuscanyCancel::
	closemessage
	release
	end
Route29_EventScript_TuscanyCompleted::
	msgbox Route29_Text_TuscanyTuesday, MSGBOX_DEFAULT
	closemessage
	release
	end



Route29_EventScript_Girl::
	lock
	faceplayer
	msgbox Route29_Text_Girl, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_NIGHT_POKEMON, Route29_EventScript_Boy2
	msgbox Route29_Text_Boy_WaitingForDay, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Boy2::
	msgbox Route29_Text_Boy_WaitingForNight, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Sign::
	lock
	msgbox Route29_Text_Sign1, MSGBOX_SIGN
	closemessage
	release
	end

Route29_EventScript_ItemPotion::
	finditem ITEM_POTION
	end

Route29_Text_OldMan1:
	.string "I POKéMON si nascondono nell'erba.\n"
	.string "Chissà quando saltano fuori…$"

Route29_Text_OldMan2:
	.string "Ti ho visto un paio di volte.\n"
	.string "Quanti POKéMON hai catturato?\p"
	.string "Vuoi che ti spieghi\n"
	.string "come catturare i POKéMON?$"

Route29_Text_OldManExplanation:
	.string "Se li indebolisci prima,\n"
	.string "i POKéMON sono più facili da catturare.\p"
	.string "Poi lancia una Ball dalla\n"
	.string "borsa! Va bene qualsiasi Ball.\p"
	.string "Se vuoi saperne di più,\n"
	.string "vai all'ACCADEMIA di VIOLETTO!\p"
	.string "Gli studenti lì ne sanno molto\n"
	.string "di POKéMON.$"

Route29_Text_OldManDeclined:
	.string "Oh. Va bene, allora.\p"
	.string "Esplora ogni percorso per trovare\n"
	.string "POKéMON diversi.\p"
	.string "Il POKéDEX ti mostra anche dove\n"
	.string "trovarli!\p"
	.string "Se vuoi saperne di più,\n"
	.string "vai all'ACCADEMIA di VIOLETTO!\p"
	.string "Gli studenti ne sanno molto\n"
	.string "di POKéMON.$"

Route29_Text_Youngster:
	.string "Ehi. Come stanno i tuoi POKéMON?\p"
	.string "Se sono deboli e non pronti\n"
	.string "alla lotta, stai fuori dall'erba.$"

Route29_Text_Lass:
	.string "Vedi quei dirupi?\n"
	.string "Fa paura saltarci giù.\p"
	.string "Ma puoi andare a NEW BARK\n"
	.string "senza passare nell'erba.$"

Route29_Text_Girl:
	.string "Volevo fare una pausa,\n"
	.string "quindi ho salvato i progressi.$"

Route29_Text_Boy_WaitingForDay:
	.string "Aspetto POKéMON che\n"
	.string "compaiono solo più tardi.$"

Route29_Text_Boy_WaitingForNight:
	.string "Aspetto POKéMON che\n"
	.string "compaiono solo di notte.$"

Route29_Text_MeetTuscany:
	.string "TUSCANY: Credo proprio che\n"
	.string "sia la prima volta che ci vediamo.\p"
	.string "Sono TUSCANY della FAMIGLIA DEI GIORNI.\p"
	.string "Se indovini il mio giorno preferito,\n"
	.string "ti darò una ricompensa.$"

Route29_Text_TuscanyNope:
	.string "Non è così!$"

Route29_Text_TuscanyGivesGift:
	.string "Sì! Come presentazione,\n"
	.string "accetta questo regalo: una SILK\l"
	.string "SCARF.$"

Route29_Text_TuscanyGaveGift:
	.string "TUSCANY: Non trovi\n"
	.string "che sia adorabile?\p"
	.string "Potenzia le mosse di\n"
	.string "tipo NORMALE.\p"
	.string "Sono certa che ti sarà utile.$"

Route29_Text_TuscanyTuesday:
	.string "TUSCANY: Hai conosciuto MONICA,\n"
	.string "mia sorella maggiore?\p"
	.string "O mio fratello minore, WESLEY?\p"
	.string "Sono la terza di sette\n"
	.string "figli.$"

Route29_Text_Sign1:
	.string "PERCORSO 29\p"
	.string "FIORPESCOPOLI - BORGO FOGLIANOVA$"

