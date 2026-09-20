MysteryGiftScript_AuroraTicket::
	setvaddress MysteryGiftScript_AuroraTicket
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_AURORA_TICKET, AuroraTicket_Obtained
	vgoto_if_set FLAG_BATTLED_DEOXYS, AuroraTicket_Obtained
	checkitem ITEM_AURORA_TICKET
	vgoto_if_eq VAR_RESULT, TRUE, AuroraTicket_Obtained
	vmessage sText_AuroraTicketForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_AURORA_TICKET
	vgoto_if_eq VAR_RESULT, FALSE, AuroraTicket_NoBagSpace
	giveitem ITEM_AURORA_TICKET
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	setflag FLAG_RECEIVED_AURORA_TICKET
	vmessage sText_AuroraTicketUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_NoBagSpace:
	vmessage sText_AuroraTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_Obtained:
	vmessage sText_AuroraTicketThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_AuroraTicketForYou:
	.string "Grazie per aver usato il sistema\n"
	.string "REGALO SEGRETO.\p"
	.string "Tu devi essere {PLAYER}.\n"
	.string "C'è un biglietto per te.$"

sText_AuroraTicketUseAtPort:
	.string "Sembra serva per il porto di\n"
	.string "PORTOPOLIS.\p"
	.string "Perché non provi a vedere\n"
	.string "di cosa si tratta?$"

sText_AuroraTicketThankYou:
	.string "Grazie per aver usato il sistema\n"
	.string "REGALO SEGRETO.$"

sText_AuroraTicketBagFull:
	.string "Oh, mi dispiace, {PLAYER}.\n"
	.string "La tasca STRUMENTI della BORSA è piena.\p"
	.string "Metti qualcosa nel PC,\n"
	.string "poi torna a prendere questo.$"
