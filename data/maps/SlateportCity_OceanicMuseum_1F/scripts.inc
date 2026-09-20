SlateportCity_OceanicMuseum_1F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_1F_EventScript_EntranceAttendant::
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeLeft::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeRight::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee::
	showmoneybox 0, 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee::
	checkmoney 50
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney
	playse SE_SHOP
	removemoney 50
	updatemoneybox
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney::
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway
	msgbox SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt5::
	msgbox SlateportCity_OceanicMuseum_1F_Text_RustboroBungled, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt6::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_WhirlpoolExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_WaterfallExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanSoilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_BeachSandDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_FossilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_FossilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_DepthMeasuringMachine::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGrunt::
	lock
	faceplayer
	delay 8
	playse SE_PIN
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_THIEF
	goto_if_eq VAR_RESULT, 0, SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief
	setflag FLAG_RECEIVED_TM_THIEF
	msgbox SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth
	goto_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth
	goto_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	goto_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth::
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited::
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT
	playse SE_EXIT
	removeobject LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief::
	msgbox SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis, MSGBOX_DEFAULT
	release
	end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast:
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit:
	face_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter:
	.string "Welcome to the OCEANIC MUSEUM.\p"
	.string "The entrance fee is ¥50.\n"
	.string "Would you like to enter?$"

SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself:
	.string "Buona visita.$"

SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney:
	.string "Oh? Mi dispiace, ma non sembri\n"
	.string "avere abbastanza soldi.$"

SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup:
	.string "Oh? Sei con quel gruppo che\n"
	.string "è entrato prima?\p"
	.string "Sei l'unico in ritardo.\n"
	.string "Corri a raggiungerli!$"

SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll:
	.string "Noi, TEAM AQUA, esistiamo per il bene\n"
	.string "di tutti!$"

SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere:
	.string "Ci hanno detto di radunarci qui,\n"
	.string "e l'abbiamo fatto, ma…\p"
	.string "Il nostro CAPO, il perno di tutto, non c'è.$"

SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich:
	.string "Se rubassi la roba qui,\n"
	.string "diventerei ricco?$"

SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds:
	.string "Ciò che imparo qui lo userò per\n"
	.string "fini malvagi…$"

SlateportCity_OceanicMuseum_1F_Text_RustboroBungled:
	.string "Se i nostri scagnozzi non avessero\n"
	.string "sbagliato a RUSTBORO, non saremmo qui!$"

SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney:
	.string "Non avevo ¥50, quindi ci ho messo\n"
	.string "un bel po' a passare la reception.$"

SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling:
	.string "Voglio studiare il mare e\n"
	.string "usare ciò che imparo per lottare.$"

SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel:
	.string "Mi sciolgo tutto quando\n"
	.string "vedo il mare!\p"
	.string "Per me il CAP. STERN è il modello\n"
	.string "numero uno!$"

SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow:
	.string "Il mare è vasto e senza fine,\n"
	.string "infinitamente profondo…\p"
	.string "Ci saranno molti POKéMON che\n"
	.string "non conosciamo.$"

SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon:
	.string "Voglio un POKéMON di mare.\p"
	.string "Penso che sarebbe fresco e bello\n"
	.string "da abbracciare.$"

SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis:
	.string "Aiyeeeh!\n"
	.string "Che ci fai qui?\p"
	.string "Io? Sono il membro del TEAM AQUA\n"
	.string "che hai battuto, ricordi?\l"
	.string "Nella GALLERIA RUSTURF?\p"
	.string "Tieni, prendi questo!\n"
	.string "Devi perdonarmi!$"

SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain:
	.string "Quella MT ti dona più che\n"
	.string "a me.\p"
	.string "Spero di non rivederti mai più!\n"
	.string "Wahahaha!$"

SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis:
	.string "Awww, andiamo!\n"
	.string "Prendi questo e lasciami andare!$"

SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment:
	.string "Un fluido blu ruota a spirale\n"
	.string "dentro un recipiente di vetro.\p"
	.string "“È un esperimento per creare un\n"
	.string "MULINELLO usando il vento.”$"

SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment:
	.string "Una palla rossa va su e giù\n"
	.string "dentro un recipiente di vetro.\p"
	.string "“È un esperimento che simula una\n"
	.string "CASCATA con la spinta della palla.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay:
	.string "È un campione di suolo del fondo\n"
	.string "marino.\p"
	.string "“In molti anni, i resti degli\n"
	.string "esseri viventi si depositano sul\l"
	.string "fondo del mare, formando strati.\p"
	.string "“Analizzando questi strati, si\n"
	.string "svela il passato remoto.”$"

SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay:
	.string "È un campione di sabbia di spiaggia.\p"
	.string "“Le pietre dei monti sono portate\n"
	.string "dai fiumi, che le spezzano\l"
	.string "e le consumano.\p"
	.string "“Diventano granelli e finiscono\n"
	.string "come sabbia sulle spiagge.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1:
	.string "“CURIOSITÀ MARINA 1\n"
	.string "Perché l'acqua di mare è blu?\p"
	.string "“La luce è fatta di molti colori.\p"
	.string "“Quando la luce attraversa l'acqua,\n"
	.string "quasi tutti i colori si perdono.\p"
	.string "“Il blu invece conserva il suo\n"
	.string "colore, e il mare appare blu.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2:
	.string "“CURIOSITÀ MARINA 2\n"
	.string "Perché il mare è salato?\p"
	.string "“L'acqua marina contiene sale\n"
	.string "sotto forma di ioni di sodio e cloro.\p"
	.string "“Questi ioni escono dalle rocce\n"
	.string "e la pioggia li porta al mare.\p"
	.string "“La concentrazione di sale\n"
	.string "rende il mare salato.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3:
	.string "“CURIOSITÀ MARINA 3\n"
	.string "Cosa è più grande? Il mare o la terra?\p"
	.string "“Il mare copre circa il 70% del\n"
	.string "pianeta, il resto è terra.\p"
	.string "“Il mare è quindi più del doppio\n"
	.string "della terraferma.”$"

SlateportCity_OceanicMuseum_1F_Text_FossilDisplay:
	.string "È un fossile con creste ondulate.\p"
	.string "“Il suolo del fondo marino è eroso\n"
	.string "dalla marea.\p"
	.string "“L'acqua che scorre segna il suolo\n"
	.string "con piccole creste e valli.\p"
	.string "“Se questo suolo si fossilizza,\n"
	.string "si parla di impronte ondulate.”$"

SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine:
	.string "Una strana macchina ruota sotto\n"
	.string "una cupola di vetro.\p"
	.string "Forse misura la profondità\n"
	.string "di qualcosa…$"

