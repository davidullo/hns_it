PalletTown_RedsHouse_2F_hns_MapScripts::
	.byte 0

PalletTown_RedsHouse_2F_EventScript_NES::
	msgbox RedsHouse_Text_NES, MSGBOX_SIGN
	end

PalletTown_RedsHouse_2F_EventScript_PC::
	msgbox RedsHouse_Text_PC, MSGBOX_SIGN
	end

RedsHouse_Text_NES:
	.string "{PLAYER} ha giocato al NES.\p"
	.string "Meglio andare, non c'è tempo da perdere!$"

RedsHouse_Text_PC:
	.string "Sembra che non venga usato\n"
	.string "da molto tempo…$"
