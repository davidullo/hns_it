PalletTown_RedsHouse_1F_hns_MapScripts::
	.byte 0

PalletTown_RedsHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_ge VAR_TEMP_0, 1, PalletTown_RedsHouse_1F_EventScript_MomAfter
	msgbox RedsHouse_Text_Mom1, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 1
	release
	end

PalletTown_RedsHouse_1F_EventScript_MomAfter::
	msgbox RedsHouse_Text_Mom2, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_RedsHouse_1F_EventScript_TV::
	msgbox RedsHouse_Text_TV, MSGBOX_SIGN
	end

RedsHouse_Text_Mom1:
	.string "Ciao!\p"
	.string "RED se n'è andato da molto tempo.\p"
	.string "Non ha nemmeno chiamato, quindi non\n"
	.string "ho idea di dove sia o di cosa\l"
	.string "abbia fatto.\p"
	.string "Dicono che il silenzio sia prova che\n"
	.string "sta bene, ma io mi preoccupo\l"
	.string "per lui.$"

RedsHouse_Text_Mom2:
	.string "Temo che ROSSO si faccia male o\n"
	.string "si ammali, ma è un ragazzo.\p"
	.string "Sono orgogliosa che faccia ciò che\n"
	.string "vuole.$"

RedsHouse_Text_TV:
	.string "Danno programmi che non\n"
	.string "trasmettono a JOHTO…$"
