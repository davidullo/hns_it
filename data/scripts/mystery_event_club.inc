.equ GAVE_PROFILE,  VAR_TEMP_1

MysteryEventClub_EventScript_Woman::
	lock
	faceplayer
	goto_if_eq GAVE_PROFILE, TRUE, EventScript_AlreadyGaveProfile
	goto_if_set FLAG_SYS_SET_TRAINER_CARD_PROFILE, EventScript_GivenProfileBefore
	msgbox Text_IdLoveToHearYourProfile
	goto EventScript_AskForProfile
	end

EventScript_AlreadyGaveProfile:
	msgbox Text_TellMoreNextTime
	release
	end

EventScript_AskForProfile:
	message Text_TellMeWhatsYourProfile
	waitmessage
	multichoice 18, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, EventScript_AcceptGiveProfile
	case 1, EventScript_DeclineGiveProfile
	case 2, EventScript_ProfileInfo
	case MULTI_B_PRESSED, EventScript_DeclineGiveProfile
	end

EventScript_ProfileInfo:
	msgbox Text_ExplainProfile
	goto EventScript_AskForProfile
	end

EventScript_AcceptGiveProfile:
	msgbox Text_WhatsYourProfile
	closemessage
	goto EventScript_GiveProfile
	end

EventScript_CancelGiveProfile:
	msgbox Text_DecidedNotTo
	release
	end

EventScript_GaveProfile:
	setvar GAVE_PROFILE, TRUE
	setvar VAR_0x8004, 0
	special ShowEasyChatProfile
	waitmessage
	delay 80
	msgbox Text_ProfileSaysSomethingAboutYou
	release
	end

EventScript_DeclineGiveProfile:
	msgbox Text_DontBeLikeThat
	release
	end

EventScript_GivenProfileBefore:
	msgbox Text_HiWeMeetAgain
	goto EventScript_AskForNewProfile
	end

EventScript_AskForNewProfile:
	message Text_ChangeYourProfile
	waitmessage
	multichoice 18, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, EventScript_AcceptGiveNewProfile
	case 1, EventScript_DeclineGiveNewProfile
	case 2, EventScript_ProfileInfo2
	@case MULTI_B_PRESSED, EventScript_DeclineGiveNewProfile
	end

EventScript_ProfileInfo2:
	msgbox Text_ExplainProfile
	goto EventScript_AskForNewProfile
	end

EventScript_AcceptGiveNewProfile:
	msgbox Text_WhatAreYouLikeNow
	closemessage
	goto EventScript_GiveProfile
	end

EventScript_DeclineGiveNewProfile:
	msgbox Text_LikeProfileWayItIs
	release
	end

EventScript_GaveSpecialProfile:
	setvar GAVE_PROFILE, TRUE
	setvar VAR_0x8004, 0
	special ShowEasyChatProfile
	waitmessage
	delay 80
	msgbox Text_HeardThatBefore
	release
	end

EventScript_GiveProfile:
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_0x8004, 0, EventScript_GaveSpecialProfile
	goto_if_eq VAR_RESULT, FALSE, EventScript_CancelGiveProfile
	goto_if_eq VAR_RESULT, TRUE, EventScript_GaveProfile
	end

Text_IdLoveToHearYourProfile:
	.string "Hi, glad to meet you!\p"
	.string "…That's unfriendly of you.\n"
	.string "How about saying hi back?\p"
	.string "So, come on, tell me about\n"
	.string "yourself.\p"
	.string "I'd love to hear your profile!$"

Text_TellMeWhatsYourProfile:
	.string "Dimmi qualcosa di bello su\n"
	.string "di te. Qual è il tuo profilo?$"

Text_ExplainProfile:
	.string "A profile is written using four\n"
	.string "words or phrases.\p"
	.string "There're plenty of words to choose\n"
	.string "from for your profile.\p"
	.string "The words and phrases are placed\n"
	.string "in several convenient groups.\p"
	.string "First, choose a group, then choose\n"
	.string "a word or phrase.\p"
	.string "…It's easier than it sounds.\n"
	.string "Why don't you try it?$"

Text_WhatsYourProfile:
	.string "Qual è il tuo profilo?$"

Text_DontBeLikeThat:
	.string "Aww… Non fare così.\n"
	.string "Puoi dirmi il tuo profilo.$"

Text_DecidedNotTo:
	.string "Oh, hai deciso di no?\n"
	.string "Sei proprio volubile, sai?$"

Text_HiWeMeetAgain:
	.string "Ciao!\n"
	.string "Ci rivediamo!$"

Text_ChangeYourProfile:
	.string "Vuoi cambiare il tuo\n"
	.string "profilo?$"

Text_WhatAreYouLikeNow:
	.string "Come sei adesso?\n"
	.string "Lo voglio proprio sapere.$"

Text_LikeProfileWayItIs:
	.string "Ok, il tuo profilo ti piace\n"
	.string "così com'è.\p"
	.string "Lo penso anch'io.$"

Text_ProfileSaysSomethingAboutYou:
	.string "Hmhm…\p"
	.string "Your profile really says something\n"
	.string "about who you are.\p"
	.string "Now that I know you better, it \n"
	.string "makes us better friends than ever!$"

Text_HeardThatBefore:
	.string "Oh, l'ho già sentito…\p"
	.string "Mio cugino, che vive lontano,\n"
	.string "lo diceva sempre, credo.$"

Text_TellMoreNextTime:
	.string "La prossima volta dimmi\n"
	.string "qualcosa in più su di te!$"
