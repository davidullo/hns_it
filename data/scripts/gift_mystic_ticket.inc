MysteryGiftScript_MysticTicket::
	setvaddress MysteryGiftScript_MysticTicket
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_MYSTIC_TICKET, MysticTicket_Obtained
	vgoto_if_set FLAG_CAUGHT_LUGIA, MysticTicket_Obtained
	vgoto_if_set FLAG_CAUGHT_HO_OH, MysticTicket_Obtained
	checkitem ITEM_MYSTIC_TICKET
	vgoto_if_eq VAR_RESULT, TRUE, MysticTicket_Obtained
	vmessage sText_MysticTicketForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_MYSTIC_TICKET
	vgoto_if_eq VAR_RESULT, FALSE, MysticTicket_NoBagSpace
	giveitem ITEM_MYSTIC_TICKET
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	setflag FLAG_RECEIVED_MYSTIC_TICKET
	vmessage sText_MysticTicketUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_NoBagSpace:
	vmessage sText_MysticTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_Obtained:
	vmessage sText_MysticTicketThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_MysticTicketForYou:
	.string "Grazie per aver usato il sistema\n"
	.string "REGALO SEGRETO.\p"
	.string "Tu devi essere {PLAYER}.\n"
	.string "C'è un biglietto per te.$"

sText_MysticTicketUseAtPort:
	.string "Sembra serva per il porto di\n"
	.string "PORTOPOLIS.\p"
	.string "Perché non provi a vedere\n"
	.string "di cosa si tratta?$"

sText_MysticTicketThankYou:
	.string "Grazie per aver usato il sistema\n"
	.string "REGALO SEGRETO.$"

sText_MysticTicketBagFull:
	.string "Oh, mi dispiace, {PLAYER}.\n"
	.string "La tasca STRUMENTI della BORSA è piena.\p"
	.string "Metti qualcosa nel PC,\n"
	.string "poi torna a prendere questo.$"
