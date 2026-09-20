SSAnne_1F_Room6_Frlg_MapScripts::
	.byte 0

SSAnne_1F_Room6_EventScript_Woman::
	lock
	faceplayer
	msgbox SSAnne_1F_Room6_Text_TakeAShortRest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_DeclineHeal
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox SSAnne_1F_Room6_Text_GladEveryoneIsRefreshed
	release
	end

SSAnne_1F_Room6_EventScript_DeclineHeal::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, SSAnne_1F_Room6_EventScript_DeclineHealMale
	msgbox SSAnne_1F_Room6_Text_SorryYouLookLikeMySister
	release
	end

SSAnne_1F_Room6_EventScript_DeclineHealMale::
	msgbox SSAnne_1F_Room6_Text_SorryYouLookLikeMyBrother
	release
	end

SSAnne_1F_Room6_Text_TakeAShortRest::
	.string "Sembri stanco. Vuoi\n"
	.string "riposare un po'?$"

SSAnne_1F_Room6_Text_GladEveryoneIsRefreshed::
	.string "Sono contento di vedere tutti\n"
	.string "freschi e pimpanti.$"

SSAnne_1F_Room6_Text_SorryYouLookLikeMyBrother::
	.string "Oh, scusa se ti ho assillato.\n"
	.string "Somigli al mio fratellino…$"

SSAnne_1F_Room6_Text_SorryYouLookLikeMySister::
	.string "Oh, scusa se ti ho assillato.\n"
	.string "Somigli alla mia sorellina…$"

