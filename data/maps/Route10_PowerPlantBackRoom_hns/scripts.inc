Route10_PowerPlantBackRoom_hns_MapScripts::
	.byte 0


Route10_PowerPlantBackRoom_EventScript_Manager::
	lock
	faceplayer
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 0, Route10_PowerPlantBackRoom_EventScript_ManagerInitial
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 1, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 2, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 3, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 6, Route10_PowerPlantBackRoom_EventScript_ManagerCheckPart
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 7, Route10_PowerPlantBackRoom_EventScript_ManagerDone
	msgbox Route10_PowerPlantBackRoom_Text_ManagerMyBelovedGenerator, MSGBOX_DEFAULT
	closemessage
	release
	end

Route10_PowerPlantBackRoom_EventScript_ManagerInitial::
	msgbox Route10_PowerPlantBackRoom_Text_ManagerWhoWouldRuinMyGenerator, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KANTO_ROCKET_STORY_STATE, 1
	release
	end

Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket::
	msgbox Route10_PowerPlantBackRoom_Text_ManagerIWontForgiveCulprit, MSGBOX_DEFAULT
	closemessage
	release
	end

Route10_PowerPlantBackRoom_EventScript_ManagerCheckPart::
	checkitem ITEM_MACHINE_PART
	goto_if_eq VAR_RESULT, FALSE, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	removeitem ITEM_MACHINE_PART
	msgbox Route10_PowerPlantBackRoom_Text_ManagerThatsThePart, MSGBOX_DEFAULT
	msgbox Route10_PowerPlantBackRoom_Text_ManagerTakeThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_THUNDER
	msgbox Route10_PowerPlantBackRoom_Text_ManagerTM07IsZapCannon, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KANTO_ROCKET_STORY_STATE, 7
	clearflag FLAG_HIDE_ROUTE25_MISTY
	setvar VAR_CERULEAN_CITY_STATE, 2
	setflag FLAG_HIDE_POWER_PLANT_ENGINEER
	setflag FLAG_RETURNED_MACHINE_PART
	setvar VAR_VERMILION_CITY_SAMSON, 1
	release
	end

Route10_PowerPlantBackRoom_EventScript_ManagerDone::
	msgbox Route10_PowerPlantBackRoom_Text_ManagerMyBelovedGenerator, MSGBOX_DEFAULT
	closemessage
	release
	end

Route10_PowerPlantBackRoom_EventScript_Engineer::
	msgbox Route10_PowerPlantBackRoom_Text_Engineer, MSGBOX_NPC
	end

Route10_PowerPlantBackRoom_Text_ManagerWhoWouldRuinMyGenerator:
	.string "MANAGER: Io, io, io sono pronto a far\n"
	.string "esplodere qualcuno!\p"
	.string "Chi oserebbe rovinare il mio\n"
	.string "generatore?\p"
	.string "Ci ho messo tanto tempo!\p"
	.string "Se lo prendo, assaggerà\n"
	.string "il mio CANNONE ESPLOSIVO!$"

Route10_PowerPlantBackRoom_Text_ManagerIWontForgiveCulprit:
	.string "MANAGER: Non lo perdonerò!\p"
	.string "Il colpevole può piangere e\n"
	.string "scusarsi,\p"
	.string "ma lo picchierò lo stesso!\p"
	.string "Gahahahah!$"

Route10_PowerPlantBackRoom_Text_ManagerThatsThePart:
	.string "MANAGER: Ah! Sì!\p"
	.string "È il PEZZO mancante del mio\n"
	.string "adorato generatore! L'hai trovato?$"

Route10_PowerPlantBackRoom_Text_ManagerTakeThisTM:
	.string "Wahah! Grazie!\p"
	.string "Tieni! Prendi questa MT come premio!$"

Route10_PowerPlantBackRoom_Text_ManagerTM07IsZapCannon:
	.string "MANAGER: Quella MT è TUONO.\p"
	.string "È una mossa potente!\p"
	.string "Non è certo precisa,\n"
	.string "ma colpisce\l"
	.string "duro!$"

Route10_PowerPlantBackRoom_Text_ManagerMyBelovedGenerator:
	.string "MANAGER: Generatore mio adorato!\p"
	.string "Continua a pompare elettricità!$"

Route10_PowerPlantBackRoom_Text_Engineer:
	.string "Senza corrente questa porta è insicura.$"

