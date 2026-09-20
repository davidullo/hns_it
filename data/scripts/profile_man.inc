ProfileMan_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_SYS_CHAT_USED, ProfileMan_EventScript_GivenProfileBefore
	msgbox ProfileMan_Text_CollectTrainerProfiles, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_AskToSeeProfile::
	msgbox ProfileMan_Text_MayISeeYourProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateProfile
	case 1, ProfileMan_EventScript_DeclineShowProfile
	case 2, ProfileMan_EventScript_Info
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineShowProfile
	end

ProfileMan_EventScript_Info::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_CreateProfile::
	msgbox ProfileMan_Text_LetsSeeItThen, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_CancelShowProfile::
	msgbox ProfileMan_Text_NotIntoItRightNow, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_ShowProfile::
	setvar VAR_0x8004, 0
	special ShowEasyChatProfile
	waitmessage
	delay 80
	msgbox ProfileMan_Text_FantasticProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_DeclineShowProfile::
	msgbox ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_GivenProfileBefore::
	msgbox ProfileMan_Text_YouHaveWonderfulSmile, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_AskToSeeNewProfile::
	msgbox ProfileMan_Text_MayISeeYourNewProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateNewProfile
	case 1, ProfileMan_EventScript_DeclineNewProfile
	case 2, ProfileMan_EventScript_InfoNewProfile
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineNewProfile
	end

ProfileMan_EventScript_InfoNewProfile::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_CreateNewProfile::
	msgbox ProfileMan_Text_EvenBetterThanLastProfile, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_DeclineNewProfile::
	msgbox ProfileMan_Text_LikeProfileWayItIs, MSGBOX_DEFAULT
	release
	end

@ Unused
ProfileMan_EventScript_Ret::
	return

ProfileMan_Text_CollectTrainerProfiles:
	.string "Ciao, ALLENATORE!\n"
	.string "Hai un sorriso meraviglioso.\p"
	.string "Ho un hobby: collezionare i profili\n"
	.string "degli ALLENATORI di POKéMON.$"

ProfileMan_Text_MayISeeYourProfile:
	.string "Allora, che ne dici?\n"
	.string "Posso vedere il tuo profilo?$"

ProfileMan_Text_EasyChatExplanation:
	.string "Il tuo profilo lo crei mettendo\n"
	.string "insieme quattro parole o frasi.\p"
	.string "Ecco, ti mostro un esempio di\n"
	.string "profilo con quattro testi.\p"
	.string "Puoi scambiare quei quattro testi\n"
	.string "con altri a piacere per creare\l"
	.string "il tuo profilo.\p"
	.string "Ci sono tanti testi che\n"
	.string "puoi usare.\p"
	.string "Sono divisi in gruppi come\n"
	.string "POKéMON, stili di vita e hobby,\l"
	.string "così è più facile trovarli.\p"
	.string "Prima scegli il gruppo di testi\n"
	.string "e ne vedi l'elenco.\p"
	.string "Poi scegli quello che vuoi.\p"
	.string "Ripeti per gli altri testi\n"
	.string "e avrai il tuo profilo personale.$"

ProfileMan_Text_LetsSeeItThen:
	.string "Sì! Grazie!\n"
	.string "Allora, vediamolo.$"

ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile:
	.string "Oh, no, davvero?\p"
	.string "Immagino che uno come te abbia\n"
	.string "un profilo meraviglioso…$"

ProfileMan_Text_NotIntoItRightNow:
	.string "Oh? Non ti va adesso?\p"
	.string "Beh, per me va bene sempre!$"

ProfileMan_Text_YouHaveWonderfulSmile:
	.string "Ciao, ALLENATORE!\n"
	.string "Hai un sorriso meraviglioso.$"

ProfileMan_Text_MayISeeYourNewProfile:
	.string "Posso vedere il tuo nuovo profilo?$"

ProfileMan_Text_EvenBetterThanLastProfile:
	.string "Sì! Grazie!\p"
	.string "Spero sia anche meglio del profilo\n"
	.string "che mi hai mostrato prima.$"

ProfileMan_Text_LikeProfileWayItIs:
	.string "Oh, il tuo profilo ti piace così.\p"
	.string "Non ti biasimo, è un profilo\n"
	.string "meraviglioso così com'è.$"

ProfileMan_Text_FantasticProfile:
	.string "F-fantastico!\p"
	.string "Il tuo profilo è meraviglioso!\n"
	.string "Dice davvero chi sei.\p"
	.string "Chi sente questo profilo resterebbe\n"
	.string "incantato da te!\p"
	.string "Grazie!$"

@ Unused
ProfileMan_Text_YouKnowSecretSaying:
	.string "Oh?\n"
	.string "Conosci il motto segreto!\p"
	.string "Allora sei un nuovo membro\n"
	.string "del CLUB EVENTI MISTERIOSI!$"
