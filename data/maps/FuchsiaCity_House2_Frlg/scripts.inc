FuchsiaCity_House2_Frlg_MapScripts::
	.byte 0

FuchsiaCity_House2_EventScript_FishingGurusBrother::
	lock
	faceplayer
	goto_if_set FLAG_GOT_GOOD_ROD, FuchsiaCity_House2_EventScript_AlreadyGotGoodRod
	msgbox FuchsiaCity_House2_Text_DoYouLikeToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_House2_EventScript_GiveGoodRod
	msgbox FuchsiaCity_House2_Text_OhThatsDisappointing
	release
	end

FuchsiaCity_House2_EventScript_AlreadyGotGoodRod::
	msgbox FuchsiaCity_House2_Text_HowAreTheFishBiting
	release
	end

FuchsiaCity_House2_EventScript_GiveGoodRod::
	msgbox FuchsiaCity_House2_Text_LikeYourStyleTakeThis
	checkitemspace ITEM_GOOD_ROD
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_House2_EventScript_NoRoomForGoodRod
	giveitem_msg FuchsiaCity_House2_Text_ReceivedGoodRod, ITEM_GOOD_ROD
	msgbox FuchsiaCity_House2_Text_GoodRodCanCatchBetterMons
	setflag FLAG_GOT_GOOD_ROD
	release
	end

FuchsiaCity_House2_EventScript_NoRoomForGoodRod::
	msgbox FuchsiaCity_House2_Text_YouHaveNoRoomForGift
	release
	end

FuchsiaCity_House2_Text_DoYouLikeToFish::
	.string "Il GURU DELLA PESCA è mio\n"
	.string "fratello maggiore.\p"
	.string "Adoro, adoro pescare!\n"
	.string "Non ne posso fare a meno.\p"
	.string "Dimmi, ti piace pescare?$"

FuchsiaCity_House2_Text_LikeYourStyleTakeThis::
	.string "Grande! Mi piaci.\n"
	.string "Possiamo diventare amici.\p"
	.string "Prendi e pesca, amico mio!$"

FuchsiaCity_House2_Text_ReceivedGoodRod::
	.string "{PLAYER} riceve un AMO BUONO dal\n"
	.string "fratello del GURU PESCA.$"

FuchsiaCity_House2_Text_GoodRodCanCatchBetterMons::
	.string "La pesca è la mia vita!\n"
	.string "È la più fine delle poesie.\p"
	.string "Un AMO VECCHIO può prendere solo\n"
	.string "MAGIKARP, sì?\p"
	.string "Ma con un AMO BUONO prendi\n"
	.string "POKéMON molto migliori.$"

FuchsiaCity_House2_Text_OhThatsDisappointing::
	.string "Oh…\n"
	.string "Che delusione…$"

FuchsiaCity_House2_Text_HowAreTheFishBiting::
	.string "Ciao, {PLAYER}!\p"
	.string "Come abboccano i pesci?$"

FuchsiaCity_House2_Text_YouHaveNoRoomForGift::
	.string "Oh, no!\p"
	.string "Avevo un regalo per te, ma non\n"
	.string "hai spazio!$"

