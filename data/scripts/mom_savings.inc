EventScript_MomGiftCall_Item::
	lockall
	pokenavcall Mom_Text_GiftCall_Item
	waitmessage
	delay 30
	clearflag FLAG_MOM_HAS_GIFT
	releaseall
	end

EventScript_MomGiftCall_Berry::
	lockall
	pokenavcall Mom_Text_GiftCall_Berry
	waitmessage
	delay 30
	clearflag FLAG_MOM_HAS_GIFT
	releaseall
	end

EventScript_MomGiftCall_Decoration::
	lockall
	pokenavcall Mom_Text_GiftCall_Decoration
	waitmessage
	delay 30
	clearflag FLAG_MOM_HAS_GIFT
	releaseall
	end

Mom_Text_GiftCall_Item:
	.string "MAMMA: Ciao, tesoro!\p"
	.string "Ho comprato una bella cosa\n"
	.string "con i tuoi risparmi!\p"
	.string "Te l'ho mandata al PC.\n"
	.string "Ciao!$"

Mom_Text_GiftCall_Berry:
	.string "MAMMA: Ciao, tesoro!\p"
	.string "Ho trovato delle belle BACCHE\n"
	.string "al negozio per te!\p"
	.string "Te le ho mandate al PC.\n"
	.string "Ciao!$"

Mom_Text_GiftCall_Decoration:
	.string "MAMMA: Ciao, tesoro!\p"
	.string "Ho comprato un bel POKé DOLL\n"
	.string "per la tua stanza!\p"
	.string "Controlla le DECORAZIONI quando\n"
	.string "torni a casa. Ciao!$"
