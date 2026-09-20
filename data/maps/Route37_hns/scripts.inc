Route37_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route37_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route37_OnTransition: 
	callnative SetTimeBasedEncounters
	end



Route37_EventScript_TwinAnn::
	trainerbattle_double TRAINER_ANN_AND_ANNE_HNS, Route37_Text_TwinsAnnAndAnne1_Seen, Route37_Text_TwinsAnnAndAnne1_Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route37_Text_TwinsAnnAndAnne1_After, MSGBOX_DEFAULT
	release
	end
	
Route37_EventScript_TwinAnne::
	trainerbattle_double TRAINER_ANN_AND_ANNE_HNS, Route37_Text_TwinsAnnAndAnne2_Seen, Route37_Text_TwinsAnnAndAnne2_Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route37_Text_TwinsAnnAndAnne2_After, MSGBOX_DEFAULT
	release
	end

Route37_EventScript_Greg::
	trainerbattle_single TRAINER_GREG_HNS, Route37_Text_PsychicGreg_Seen, Route37_Text_PsychicGreg_Beaten
	msgbox Route37_Text_PsychicGreg_After, MSGBOX_AUTOCLOSE
	end


Route37_EventScript_Sunny::
	lock
	faceplayer
	goto_if_set FLAG_GOT_MAGNET, Route37_EventScript_SunnyCompleted
	msgbox Route37_Text_Sunny_Meet, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route37_EventScript_SunnyYes
	case 1, Route37_EventScript_SunnyNope
	case 2, Route37_EventScript_SunnyNope
	case 3, Route37_EventScript_SunnyNope
	case 4, Route37_EventScript_SunnyNope
	case 5, Route37_EventScript_SunnyNope
	case 6, Route37_EventScript_SunnyNope
	case 7 Route37_EventScript_SunnyCancel
	case MULTI_B_PRESSED, Route37_EventScript_SunnyCancel
	closemessage
	release
	end
Route37_EventScript_SunnyYes::
	msgbox Route37_Text_Sunny_GiveGift2, MSGBOX_DEFAULT
	giveitem ITEM_MAGNET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_MAGNET
	msgbox Route37_Text_Sunny_GaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route37_EventScript_SunnyNope::
	msgbox Route29_Text_TuscanyNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route37_EventScript_SunnyCancel::
	closemessage
	release
	end
Route37_EventScript_SunnyCompleted::
	msgbox Route37_Text_Sunny_Sunday, MSGBOX_DEFAULT
	closemessage
	release
	end

Route37_EventScript_Sign::
	lock
	msgbox Route37_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route37_Text_TwinsAnnAndAnne1_Seen:
	.string "ANN: ANNE e io lottiamo\n"
	.string "insieme!$"

Route37_Text_TwinsAnnAndAnne1_Beaten:
	.string "ANN & ANNE: Nnn… Un po' troppo\n"
	.string "forti.$"

Route37_Text_TwinsAnnAndAnne1_After:
	.string "ANN: So cosa pensano mia sorella e\n"
	.string "i miei POKéMON.$"

Route37_Text_TwinsAnnAndAnne2_Seen:
	.string "ANNE: ANN e io lottiamo\n"
	.string "insieme!$"

Route37_Text_TwinsAnnAndAnne2_Beaten:
	.string "ANN & ANNE: Nnn… Un po' troppo\n"
	.string "forti.$"

Route37_Text_TwinsAnnAndAnne2_After:
	.string "ANNE: Proviamo gli stessi sentimenti\n"
	.string "dei nostri POKéMON.$"

Route37_Text_PsychicGreg_Seen:
	.string "I POKéMON addormentati non possono\n"
	.string "fare nulla.\p"
	.string "Ti mostrerò quanto è spaventoso!$"

Route37_Text_PsychicGreg_Beaten:
	.string "Ho perso. Che tristezza…$"

Route37_Text_PsychicGreg_After:
	.string "Addormentare o paralizzare i POKéMON\n"
	.string "è una buona tecnica di lotta.$"

Route37_Text_Sunny_Meet:
	.string "SUNNY: Ciao!\p"
	.string "Sono SUNNY della famiglia WEEKDAY!\p"
	.string "Se indovini il mio giorno preferito,\n"
	.string "ti darò una ricompensa.$"

Route37_Text_Sunny_GiveGift1:
	.string "Mi hanno detto di darti questo se ti\n"
	.string "avessi visto!$"

Route37_Text_Sunny_GiveGift2:
	.string "Mi hanno detto di darti questo se ti\n"
	.string "avessi visto!$"

Route37_Text_Sunny_GaveGift:
	.string "SUNNY: Quella cosa…\p"
	.string "Ehm…\p"
	.string "… Come si chiamava…\p"
	.string "…\p"
	.string "Ah! Ora ricordo!\p"
	.string "Un POKéMON che conosce mosse\n"
	.string "elettriche dovrebbe tenerla.\p"
	.string "Mia sorella MONICA dice che potenzia\n"
	.string "le mosse elettriche!$"

Route37_Text_Sunny_Sunday:
	.string "SUNNY: I miei fratelli e sorelle sono\n"
	.string "MONICA, TUSCANY, WESLEY, ARTHUR,\l"
	.string "FRIEDA e SANTOS.\p"
	.string "Sono tutti più grandi di me!$"

Route37_Text_Sunny_NotSunday:
	.string "SUNNY: Oggi non è domenica?\n"
	.string "Ehm… me lo sono scordato!$"

Route37_Text_Sign:
	.string "PERCORSO 37\n"
	.string "AMILCITÀ PIÙ AVANTI$"
