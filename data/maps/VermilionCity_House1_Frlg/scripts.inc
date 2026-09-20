VermilionCity_House1_Frlg_MapScripts::
	.byte 0

VermilionCity_House1_EventScript_FishingGuru::
	lock
	faceplayer
	goto_if_set FLAG_GOT_OLD_ROD, VermilionCity_House1_EventScript_AlreadyGotOldRod
	msgbox VermilionCity_House1_Text_ImFishingGuruDoYouLikeToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, VermilionCity_House1_EventScript_GiveOldRod
	msgbox VermilionCity_House1_Text_OhThatsSoDisappointing
	release
	end

VermilionCity_House1_EventScript_AlreadyGotOldRod::
	msgbox VermilionCity_House1_Text_HowAreTheFishBiting
	release
	end

VermilionCity_House1_EventScript_GiveOldRod::
	checkitemspace ITEM_OLD_ROD
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_House1_EventScript_NoRoomForOldRod
	additem ITEM_OLD_ROD
	msgbox VermilionCity_House1_Text_TakeThisAndFish
	msgreceiveditem VermilionCity_House1_Text_ReceivedOldRodFromFishingGuru, ITEM_OLD_ROD
	setflag FLAG_GOT_OLD_ROD
	msgbox VermilionCity_House1_Text_FishingIsAWayOfLife
	release
	end

VermilionCity_House1_EventScript_NoRoomForOldRod::
	msgbox VermilionCity_House1_Text_NoRoomForNiceGift
	release
	end

VermilionCity_House1_Text_ImFishingGuruDoYouLikeToFish::
	.string "Sono il GURU DELLA PESCA!\p"
	.string "Adoro adoro pescare!\n"
	.string "Non posso farne a meno.\p"
	.string "Dimmi, ti piace pescare?$"

VermilionCity_House1_Text_TakeThisAndFish::
	.string "Grande! Mi piaci.\n"
	.string "Possiamo diventare amici.\p"
	.string "Prendi e pesca, amico mio!$"

VermilionCity_House1_Text_ReceivedOldRodFromFishingGuru::
	.string "{PLAYER} riceve una VECCHIA CANNA\n"
	.string "dal GURU DELLA PESCA.$"

VermilionCity_House1_Text_FishingIsAWayOfLife::
	.string "Pescare è uno stile di vita!\n"
	.string "È come la poesia più bella.\p"
	.string "Dai mari ai fiumi, esci\n"
	.string "e prendi il pesce grosso, amico.$"

VermilionCity_House1_Text_OhThatsSoDisappointing::
	.string "Oh…\n"
	.string "Che delusione…$"

VermilionCity_House1_Text_HowAreTheFishBiting::
	.string "Ciao, {PLAYER}!\p"
	.string "Come abboccano i pesci?$"

VermilionCity_House1_Text_NoRoomForNiceGift::
	.string "Oh, no!\p"
	.string "Avevo un bel regalo per te, ma non\n"
	.string "hai spazio!$"

