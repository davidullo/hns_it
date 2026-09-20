Gate_GoldenrodCity_Route35_hns_MapScripts::
	.byte 0

Gate_GoldenrodCity_Route35_EventScript_Randy::
	lock
	faceplayer
	goto_if_eq VAR_KENYA, 3, Gate_GoldenrodCity_Route35_EventScript_RandyPostKenya
	goto_if_eq VAR_KENYA, 2, Gate_GoldenrodCity_Route35_EventScript_RandyDeliveredKenya
	goto_if_eq VAR_KENYA, 1, Gate_GoldenrodCity_Route35_EventScript_RandyHaveKenya
	msgbox Route35GoldenrodGate_Text_RandyAskFavor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Gate_GoldenrodCity_Route35_EventScript_RandyCancel
	closemessage

	msgbox Route35GoldenrodGate_Text_RandyThanks, MSGBOX_DEFAULT

	@HnS named gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SPEAROW
	bufferspeciesname STR_VAR_1, SPECIES_SPEAROW
	givenamedmon 1
	call Common_EventScript_GiftMonNamed

	setvar VAR_KENYA, 1
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyCancel::
	msgbox Route35GoldenrodGate_Text_RandyNeverMind, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyHaveKenya::
	msgbox Route35GoldenrodGate_Text_RandyWeirdTree, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyDeliveredKenya::
	msgbox Route35GoldenrodGate_Text_ThanksForDelivery, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_HP_UP
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox Route35GoldenrodGate_Text_RandyMyPalSnoozing, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KENYA, 3
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyPostKenya::
	msgbox Route35GoldenrodGate_Text_RandyMyPalSnoozing, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Lady::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, Gate_GoldenrodCity_Route35_EventScript_Lady2
	msgbox Route35GoldenrodGate_Text_PokefanF_TreeBlocking, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Lady2::
	msgbox Route35GoldenrodGate_Text_PokefanF_Lullaby, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Fisher::
	lock
	faceplayer
	msgbox Route35GoldenrodGate_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35GoldenrodGate_Text_RandyAskFavor:
	.string "Ehi, scusa! Mi fai un\n"
	.string "favore?\p"
	.string "Puoi portare questo POKéMON\n"
	.string "a un amico?\p"
	.string "È su PERCORSO 31.$"

Route35GoldenrodGate_Text_RandyThanks:
	.string "Davvero? Perfetto! Grazie!\p"
	.string "Il mio è un ciccione che\n"
	.string "dorme tanto.\p"
	.string "Lo riconoscerai subito!$"

Route35GoldenrodGate_Text_ReceivedMonWithMail:
	.string "{PLAYER} ha un POKéMON con MESSAGGIO.$"

Route35GoldenrodGate_Text_RandyWeirdTree:
	.string "Mettilo in testa alla squadra\n"
	.string "quando trovi il mio amico!\p"
	.string "PERCORSO 31!\p"
	.string "Ah, già. C'era un albero strano\n"
	.string "sulla strada.\p"
	.string "Chissà se l'hanno tolto?$"

Route35GoldenrodGate_Text_CantCarryMoreMon:
	.string "Non puoi avere altri POKéMON…$"

Route35GoldenrodGate_Text_RandyNeverMind:
	.string "Oh… Niente, allora…$"

Route35GoldenrodGate_Text_ThanksForDelivery:
	.string "Grazie! Hai fatto la consegna\n"
	.string "per me!\p"
	.string "Ecco qualcosa per il disturbo!$"

Route35GoldenrodGate_Text_RandyMyPalSnoozing:
	.string "Il mio amico dormiva, no? Eh,\n"
	.string "che dicevo?$"

Route35GoldenrodGate_Text_PokefanF_TreeBlocking:
	.string "Un albero strano blocca la strada.\p"
	.string "Si dimena se gli parli.\p"
	.string "Ho sentito che è diventato\n"
	.string "selvatico con l'ANNAFFIATOIO.$"

Route35GoldenrodGate_Text_PokefanF_Lullaby:
	.string "Mi piace la Ninna nanna POKéMON\n"
	.string "alla radio.$"

Route35GoldenrodGate_Text_Fisher:
	.string "Chissà quante specie di POKéMON\n"
	.string "ci sono al mondo.\p"
	.string "Tre anni fa il PROF. OAK disse\n"
	.string "che c'erano 150 specie.\p"
	.string "Ma di recente ho sentito\n"
	.string "oltre 400!$"
