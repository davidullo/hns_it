MysteryGiftScript_OldSeaMap::
	setvaddress MysteryGiftScript_OldSeaMap
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_OLD_SEA_MAP, OldSeaMap_Obtained
	vgoto_if_set FLAG_CAUGHT_MEW, OldSeaMap_Obtained
	checkitem ITEM_OLD_SEA_MAP
	vgoto_if_eq VAR_RESULT, TRUE, OldSeaMap_Obtained
	vmessage sText_MysteryGiftOldSeaMapForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_OLD_SEA_MAP
	vgoto_if_eq VAR_RESULT, FALSE, OldSeaMap_NoBagSpace
	giveitem ITEM_OLD_SEA_MAP
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	setflag FLAG_RECEIVED_OLD_SEA_MAP
	vmessage sText_MysteryGiftOldSeaMapUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_NoBagSpace:
	vmessage sText_MysteryGiftOldSeaMapBagFull
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_Obtained:
	vmessage sText_MysteryGiftOldSeaMapThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftOldSeaMapForYou:
	.string "Grazie per aver usato il sistema\n"
	.string "REGALO SEGRETO.\p"
	.string "Confermo, tu sei {PLAYER}?\p"
	.string "Abbiamo ricevuto questa VECCHIA MAPPA\n"
	.string "indirizzata a te.$"

sText_MysteryGiftOldSeaMapUseAtPort:
	.string "Sembra serva per il porto di\n"
	.string "PORTOPOLIS.\p"
	.string "Perché non provi a vedere\n"
	.string "di cosa si tratta?$"

sText_MysteryGiftOldSeaMapThankYou:
	.string "Grazie per aver usato il sistema\n"
	.string "REGALO SEGRETO.$"

sText_MysteryGiftOldSeaMapBagFull:
	.string "Oh, mi dispiace, {PLAYER}.\n"
	.string "La tasca STRUMENTI della BORSA è piena.\p"
	.string "Metti qualcosa nel PC,\n"
	.string "poi torna a prendere questo.$"
