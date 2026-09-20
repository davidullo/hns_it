LakeOfRage_House2_hns_MapScripts::
	.byte 0

LakeOfRage_House2_EventScript_Fisher::
	lock
	faceplayer
	goto_if_ge VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_House2_EventScript_FisherAfterRockets
	goto_if_eq VAR_LAKE_OF_RAGE_FISHERMAN, 0, LakeOfRage_House2_EventScript_FisherFirstMeeting
	msgbox LakeOfRage_House2_Text_MenInBlack, MSGBOX_DEFAULT
	closemessage
	release
	end	

LakeOfRage_House2_EventScript_FisherFirstMeeting::
	msgbox LakeOfRage_House2_Text_LakeHistory, MSGBOX_DEFAULT
	msgbox LakeOfRage_House2_Text_MenInBlack, MSGBOX_DEFAULT
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 1
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherAfterRockets::
	goto_if_eq VAR_LAKE_OF_RAGE_FISHERMAN, 2, LakeOfRage_House2_EventScript_FisherAnotherMagikarp
	msgbox LakeOfRage_House2_Text_WorldsLargest, MSGBOX_DEFAULT
	msgbox LakeOfRage_House2_Text_ForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNo
	getpartysize
	goto_if_eq VAR_RESULT, 1, LakeOfRage_House2_EventScript_LastMon
	special ChoosePartyMon
	waitstate
	lock
	showmoneybox 0, 0
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LakeOfRage_House2_EventScript_FisherNoMoneyBox
	removegenericmon SPECIES_MAGIKARP
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNotMagikarp
	goto_if_eq VAR_RESULT, MON_SATISFACTORY, LakeOfRage_House2_EventScript_FisherSatisfied
	goto_if_eq VAR_RESULT, MON_UNSATISFACTORY, LakeOfRage_House2_EventScript_FisherSmallMagikarp

LakeOfRage_House2_EventScript_FisherNo::
	msgbox LakeOfRage_House2_Text_Refused, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherNoMoneyBox::
	msgbox LakeOfRage_House2_Text_Refused, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherNotMagikarp::
	msgbox LakeOfRage_House2_Text_NotMagikarp, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherSmallMagikarp::
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 2
	msgbox LakeOfRage_House2_Text_TooShort, MSGBOX_DEFAULT
	addmoney 2000
	updatemoneybox
	playse SE_SHOP
	waitse
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherAnotherMagikarp::
	msgbox LakeOfRage_House2_Text_ForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNo
	getpartysize
	goto_if_eq VAR_RESULT, 1, LakeOfRage_House2_EventScript_LastMon
	special ChoosePartyMon
	waitstate
	lock
	showmoneybox 0, 0
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LakeOfRage_House2_EventScript_FisherNoMoneyBox
	removegenericmon SPECIES_MAGIKARP
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNotMagikarp
	goto_if_eq VAR_RESULT, MON_SATISFACTORY, LakeOfRage_House2_EventScript_FisherSatisfied
	goto_if_eq VAR_RESULT, MON_UNSATISFACTORY, LakeOfRage_House2_EventScript_FisherSmallMagikarp

LakeOfRage_House2_EventScript_LastMon::
	msgbox LakeOfRage_House2_Text_LastMon, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherSatisfied::
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 2
	msgbox LakeOfRage_House2_Text_BigPayout, MSGBOX_DEFAULT
	addmoney 100000
	updatemoneybox
	playse SE_SHOP
	waitse
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_Text_LakeHistory:
    .string "Il LAGO D'IRA è in realtà un cratere\n"
    .string "creato da GYARADOS furiosi.\p"
    .string "Il cratere si riempì di pioggia\n"
    .string "e nacque il LAGO.\p"
    .string "È la storia tramandata dal\n"
    .string "bisnonno di mio nonno.\p"
    .string "Prima si potevano pescare\n"
    .string "MAGIKARP vivaci, ma…\p"
    .string "Non capisco cosa stia succedendo.$"

LakeOfRage_House2_Text_MenInBlack:
    .string "Il LAGO non è più normale da\n"
    .string "quando sono arrivati quelli in nero.$"

LakeOfRage_House2_Text_LastMon:
    .string "Non voglio il tuo ultimo\n"
    .string "POKéMON!$"

LakeOfRage_House2_Text_WorldsLargest:
    .string "Il LAGO D'IRA è tornato normale.\p"
    .string "I MAGIKARP sono tornati.\p"
    .string "Forse realizzerò il sogno di avere\n"
    .string "il MAGIKARP più grande del mondo.\p"
    .string "Anzi… ti pago ¥2000 per\n"
	.string "ogni MAGIKARP che mi dai, e\l"
	.string "¥100,000 per uno ENORME!$"

LakeOfRage_House2_Text_ForMe:
	.string "Allora… Hai un MAGIKARP per\n"
	.string "me?$"

LakeOfRage_House2_Text_HaveMagikarp:
    .string "Ah, hai un MAGIKARP! Vediamo\n"
    .string "quanto è grande.$"

LakeOfRage_House2_Text_BigPayout:
    .string "Wow! Questo è eccezionale!\p"
    .string "Ti faccio i complimenti!\p"
    .string "Ecco un pensiero per il\n"
	.string "disturbo.$"

LakeOfRage_House2_Text_Bonus:
    .string "Il record è la cosa importante.\p"
    .string "Consideralo un bonus!$"

LakeOfRage_House2_Text_TooShort:
    .string "Wow! Questo è eccezionale!\p"
    .string "…Vorrei dirlo, ma ne ho\n"
    .string "visto uno più grande.\p"
    .string "Varrà qualcosa, suppongo.$"

LakeOfRage_House2_Text_NotMagikarp:
    .string "Come? Non è un MAGIKARP!$"

LakeOfRage_House2_Text_Refused:
    .string "Oh… Quindi non ne hai uno\n"
    .string "bello? Sarà per un'altra volta.$"
