PalletTown_Lab_hns_MapScripts::
	.byte 0

PalletTown_Lab_EventScript_Oak::
	lock
	faceplayer
	call_if_unset FLAG_SYS_NATIONAL_DEX, PalletTown_Lab_EventScript_OakGiveNatDex_ForPlaytesters
	goto_if_eq VAR_PALLETTOWN_LABSTATE, 1, PalletTown_Lab_EventScript_OakBadgeCheck
	goto_if_eq VAR_PALLETTOWN_LABSTATE, 2, PalletTown_Lab_EventScript_OakDex
	msgbox PalletTown_Lab_Text_OakWelcomeKanto, MSGBOX_DEFAULT
	msgbox PalletTown_Lab_Text_OakLabGoodbye, MSGBOX_DEFAULT
	setvar VAR_PALLETTOWN_LABSTATE, 1
	goto_if_ge VAR_NUM_BADGES, 16, PalletTown_Lab_EventScript_OakBadgeCheck
	closemessage
	release
	end

PalletTown_Lab_EventScript_OakGiveNatDex_ForPlaytesters::
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	return

PalletTown_Lab_EventScript_OakBadgeCheck::
	goto_if_ge VAR_NUM_BADGES, 16, PalletTown_Lab_EventScript_Oak16Badges
	goto_if_ge VAR_NUM_BADGES, 9, PalletTown_Lab_EventScript_Oak9Badges
	msgbox PalletTown_Lab_Text_OakNoKantoBadges, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_Oak16Badges::
	msgbox PalletTown_Lab_Text_OakOpenMtSilver, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_INDIGOJUNCTION_HIDE_SILVER_GUARD
	setvar VAR_ROUTE28_SCIENTIST, 1
	setvar VAR_PALLETTOWN_LABSTATE, 2
	call_if_unset FLAG_IS_KANTO_CHAMPION, PalletTown_Lab_EventScript_OakKantoLeague
	release
	end

PalletTown_Lab_EventScript_OakKantoLeague::
	msgbox PalletTown_Lab_Text_OakOpenIndigoPlateau, MSGBOX_DEFAULT
	closemessage
	return

PalletTown_Lab_EventScript_Oak9Badges::
	msgbox PalletTown_Lab_Text_OakYesKantoBadges, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_OakDex::
	msgbox PalletTown_Lab_Text_OakLabDexCheck, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_Assistant1::
	msgbox PalletTown_Lab_Text_OaksAssistant1, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_Assistant2::
	msgbox PalletTown_Lab_Text_OaksAssistant2, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_Assistant3::
	msgbox PalletTown_Lab_Text_OaksAssistant3, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_PC::
	msgbox PalletTown_Lab_Text_OaksLabPC, MSGBOX_SIGN
	end

PalletTown_Lab_Text_OakLabDexCheck:
	.string "Come procede il POKéDEX?$"

PalletTown_Lab_Text_OakWelcomeKanto:
	.string "OAK: Ah, {PLAYER}!\n"
	.string "Che bello che tu sia venuto fin\l"
	.string "qui a KANTO.\p"
	.string "Cosa pensi degli allenatori\n"
	.string "di qui? Tosti, eh?$"

PalletTown_Lab_Text_OakLabGoodbye:
	.string "Se passi da queste parti,\n"
	.string "torna a trovarmi.$"

PalletTown_Lab_Text_OakOpenMtSilver:
	.string "OAK: Wow! Eccezionale!\p"
	.string "Hai collezionato le MEDAGLIE delle\n"
	.string "PALESTRE di KANTO. Ben fatto!\p"
	.string "Avevo ragione a valutarti\n"
	.string "bene.\p"
	.string "Sai cosa, {PLAYER}. Prenderò\n"
	.string "accordi perché tu possa andare\l"
	.string "al MT.SILVER.\p"
	.string "Il MT.SILVER è una grande montagna\n"
	.string "abitata da molti POKéMON selvatici.\p"
	.string "È troppo pericolosa per un\n"
	.string "allenatore comune, quindi è vietata. Ma\l"
	.string "possiamo fare un'eccezione per il tuo\l"
	.string "caso, {PLAYER}.\p"
	.string "Sali all'ALTIPIANO INDIGO. Da lì\n"
	.string "puoi raggiungere il MT.SILVER.$"

PalletTown_Lab_Text_OakOpenIndigoPlateau:
	.string "Ah, e a proposito dell'ALTIPIANO\n"
	.string "INDIGO: ora che hai ottenuto\l"
	.string "16 medaglie, la LEGA di KANTO\l"
	.string "sarà pronta ad accogliere\l"
	.string "di nuovo la tua sfida.\p"
	.string "Ma attento: LANCE e il suo\n"
	.string "ELITE FOUR non si risparmieranno\l"
	.string "stavolta.\p"
	.string "Buona fortuna, {PLAYER}!$"

PalletTown_Lab_Text_OakNoKantoBadges:
	.string "OAK: Hmm? Non stai collezionando\n"
	.string "le MEDAGLIE di KANTO?\p"
	.string "I CAPOPALESTRA di KANTO sono forti\n"
	.string "come quelli che hai affrontato a JOHTO.\p"
	.string "Ti consiglio di sfidarli.$"

PalletTown_Lab_Text_OakYesKantoBadges:
	.string "OAK: Ah, stai collezionando le\n"
	.string "MEDAGLIE di KANTO.\p"
	.string "Immagino sia dura, ma\n"
	.string "l'esperienza ti aiuterà.\p"
	.string "Vieni da me quando le avrai tutte.\p"
	.string "Avrò un regalo per te.\p"
	.string "Continua così, {PLAYER}!$"

PalletTown_Lab_Text_OaksAssistant1:
	.string "Il programma radio del PROF\n"
	.string "POKéMON TALK non va in onda a KANTO.\p"
	.string "Peccato, mi piacerebbe sentirlo.$"

PalletTown_Lab_Text_OaksAssistant2:
	.string "Grazie al tuo lavoro sul POKéDEX,\n"
	.string "la ricerca del PROF sta procedendo\l"
	.string "bene.$"

PalletTown_Lab_Text_OaksAssistant3:
	.string "Non dirlo a nessuno, ma POKéMON TALK\n"
	.string "del PROF.OAK non è in diretta.$"

PalletTown_Lab_Text_OaksLabPC:
	.string "C'è un'e-mail sul PC.\p"
	.string "…\p"
	.string "PROF.OAK, come procede\n"
	.string "la sua ricerca?\p"
	.string "Io continuo a lavorarci.\p"
	.string "Ho sentito voci che {PLAYER}\n"
	.string "si sta facendo una bella reputazione.\p"
	.string "Ne sono felice.\p"
	.string "ELM di NEW BARK TOWN 8-)$"
