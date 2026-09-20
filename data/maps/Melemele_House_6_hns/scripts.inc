Melemele_House_6_hns_MapScripts::
	.byte 0


Melemele_House6_Hiker::
	lock
	faceplayer
	msgbox Melemele_House6_Hiker_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House6_GameboyKid::
	lock
	faceplayer
	msgbox Melemele_House6_GameboyKid_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House6_Hiker_Text_0:
	.string "Ho comprato questo posto per poter\n"
	.string "esplorare la natura con mio figlio…\p"
	.string "Ma lui vuole solo giocare su quel\n"
	.string "Game Boy Advance.$"

Melemele_House6_GameboyKid_Text_0:
	.string "Ho un gioco sul mio Game Boy Advance\n"
	.string "che mi fa esplorare la regione di ALOLA!\p"
	.string "È come quella vera.\p"
	.string "Si chiama ULTRA ECLIPSE,\n"
	.string "di PHANTONOMY!\p"
	.string "Ah ah, guarda!\n"
	.string "Cavalco un NOIVERN ghiacciato!$"
