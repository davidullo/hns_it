TrainerHill_Roof_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Roof_hns_OnLoad
	.byte 0

TrainerHill_Roof_hns_OnLoad::
	setflag FLAG_TEMP_HIDE_FOLLOWER
	end

TrainerHill_Roof_hns_EventScript_Owner::
	trainerhill_settrainerflags
	lock
	faceplayer
	trainerhill_getownerstate
	switch VAR_RESULT
	case 0, TrainerHill_Roof_hns_EventScript_Arrived
	case 1, TrainerHill_Roof_hns_EventScript_GivePrize
	case 2, TrainerHill_Roof_hns_EventScript_AlreadyReceivedPrize
TrainerHill_Roof_hns_EventScript_Arrived::
	msgbox TrainerHill_Roof_hns_Text_YouFinallyCameBravo, MSGBOX_DEFAULT
TrainerHill_Roof_hns_EventScript_GivePrize::
	trainerhill_giveprize
	switch VAR_RESULT
	case 0, TrainerHill_Roof_hns_EventScript_ReceivePrize
	case 1, TrainerHill_Roof_hns_EventScript_NoRoomForPrize
	case 2, TrainerHill_Roof_hns_EventScript_CheckFinalTime
TrainerHill_Roof_hns_EventScript_ReceivePrize::
	msgbox TrainerHill_Roof_hns_Text_HaveTheMostMarvelousGift, MSGBOX_DEFAULT
	playfanfare MUS_LEVEL_UP
	message gText_ObtainedTheItem
	waitfanfare
	waitmessage
	goto TrainerHill_Roof_hns_EventScript_CheckFinalTime

TrainerHill_Roof_hns_EventScript_NoRoomForPrize::
	msgbox TrainerHill_Roof_hns_Text_HaveTheMostMarvelousGift, MSGBOX_DEFAULT
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	msgbox TrainerHill_Roof_hns_Text_FullUpBeBackLaterForThis, MSGBOX_DEFAULT
	goto TrainerHill_Roof_hns_EventScript_CheckFinalTime

TrainerHill_Roof_hns_EventScript_CheckFinalTime::
	trainerhill_finaltime
	switch VAR_RESULT
	case 0, TrainerHill_Roof_hns_EventScript_NewRecord
	case 1, TrainerHill_Roof_hns_EventScript_NoNewRecord
	case 2, TrainerHill_Roof_hns_EventScript_EndSpeakToOwner
TrainerHill_Roof_hns_EventScript_NewRecord::
	msgbox TrainerHill_Roof_hns_Text_GotHereMarvelouslyQuickly, MSGBOX_DEFAULT
	goto TrainerHill_Roof_hns_EventScript_EndSpeakToOwner
	end

TrainerHill_Roof_hns_EventScript_NoNewRecord::
	msgbox TrainerHill_Roof_hns_Text_YouWerentVeryQuick, MSGBOX_DEFAULT
	goto TrainerHill_Roof_hns_EventScript_EndSpeakToOwner
	end

TrainerHill_Roof_hns_EventScript_EndSpeakToOwner::
	msgbox TrainerHill_Roof_hns_Text_ArriveZippierNextTime, MSGBOX_DEFAULT
	release
	end

TrainerHill_Roof_hns_EventScript_AlreadyReceivedPrize::
	msgbox TrainerHill_Roof_hns_Text_ArriveZippierNextTime, MSGBOX_DEFAULT
	release
	end

TrainerHill_Roof_hns_Text_YouFinallyCameBravo:
	.string "Hm! Hm!\p"
	.string "Finalmente sei arrivato!\n"
	.string "Sì, sei giunto!\p"
	.string "Aspetta! Non dirlo!\n"
	.string "So perché sei venuto fin qui\l"
	.string "da solo!\p"
	.string "Volevi vedere me, il titolare\n"
	.string "del MONTE ALLENATORI, perché…\p"
	.string "Vuoi formare una coppia con me!\n"
	.string "Wa-hoo!\p"
	.string "…Eh?\n"
	.string "Non è così?\p"
	.string "Comunque, ti ho guardato salire.\n"
	.string "Che lotte meravigliose! Bravo, davvero!$"

TrainerHill_Roof_hns_Text_HaveTheMostMarvelousGift:
	.string "Per qualcuno meraviglioso come te,\n"
	.string "ho il regalo più meraviglioso,\l"
	.string "più dei soldi per il tuo sforzo!$"

TrainerHill_Roof_hns_Text_FullUpBeBackLaterForThis:
	.string "Oh, no, ho le tasche piene!\n"
	.string "Tornerai più tardi per questo!$"

TrainerHill_Roof_hns_Text_GotHereMarvelouslyQuickly:
	.string "Oh, un momento! Saresti forse arrivato\n"
	.string "qui in tempo meraviglioso?\p"
	.string "Che splendore! Non dovevi\n"
	.string "correre tanto per vedermi!\p"
	.string "Che delizia. Farò aggiornare la Bacheca\n"
	.string "dei Tempi alla reception!$"

TrainerHill_Roof_hns_Text_YouWerentVeryQuick:
	.string "Ma, oh…\n"
	.string "Non sei stato molto rapido ad arrivare.$"

TrainerHill_Roof_hns_Text_ArriveZippierNextTime:
	.string "Forse sarei più contento se arrivassi\n"
	.string "più svelto la prossima volta.\p"
	.string "Allora sì che sarei felice di formare\n"
	.string "una coppia con te!\p"
	.string "Alla prossima, amico!$"
