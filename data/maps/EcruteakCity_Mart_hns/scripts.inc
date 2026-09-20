EcruteakCity_Mart_hns_MapScripts::
	.byte 0

EcruteakCity_Mart_EventScript_Nerd::
	lock
	faceplayer
	msgbox EcruteakMart_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Mart_EventScript_Granny::
	lock
	faceplayer
	msgbox EcruteakMart_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakMart_Text_SuperNerd:
	.string "Il mio EEVEE è diventato ESPEON.\p"
	.string "Ma l'EEVEE del mio amico è un\n"
	.string "UMBREON.\p"
	.string "Chissà perché? Entrambi allevavamo\n"
	.string "l'EEVEE allo stesso modo…$"

EcruteakMart_Text_Granny:
	.string "Usa REVITALIZZANTE e il POKéMON\n"
	.string "esausto si sveglia subito.$"
