CianwoodShop_hns_MapScripts::
	.byte 0

CianwoodShop_EventScriptMan::	
	setvar VAR_OLIVINE_CITY_STATE, 4
	giveitem ITEM_SECRET_POTION
	end

CianwoodCity_EventScript_Pharmacist::
	lock
	faceplayer
	checkitem ITEM_SECRET_POTION
	goto_if_eq VAR_RESULT, TRUE, CianwoodCity_EventScript_PharmacistAfter
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, CianwoodCity_EventScript_PharmacistAfter
	msgbox CianwoodCity_Text_PharmacistGivePotion, MSGBOX_DEFAULT
	giveitem ITEM_SECRET_POTION
	closemessage
	setvar VAR_OLIVINE_CITY_STATE, 4
	release
	end

CianwoodCity_EventScript_PharmacistAfter::
	msgbox CianwoodCity_Text_PharmacistDescribePotion, MSGBOX_DEFAULT
	closemessage
	release
	end


CianwoodCity_Text_PharmacistGivePotion:
	.string "I tuoi POKéMON stanno bene.\p"
	.string "Qualcosa ti preoccupa?\p"
	.string "…\p"
	.string "Il POKéMON del FARO è nei\n"
	.string "guai?\p"
	.string "Capito!\p"
	.string "Questo dovrebbe bastare.$"

CianwoodCity_Text_ReceivedSecretpotion:
	.string "{PLAYER} riceve POZIONE SEGRETA.$"

CianwoodCity_Text_PharmacistDescribePotion:
	.string "La mia POZIONE SEGRETA è\n"
	.string "troppo forte, la do solo in\l"
	.string "emergenza.$"
