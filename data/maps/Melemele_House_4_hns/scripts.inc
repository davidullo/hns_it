Melemele_House_4_hns_MapScripts::
	.byte 0


Melemele_House4_Man::
	lock
	faceplayer
	msgbox Melemele_House4_Man_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House4_Woman::
	lock
	faceplayer
	msgbox Melemele_House4_Woman_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House4_Man_Text_0:
	.string "Siamo in vacanza sulle ISOLE DI ALOLA!\p"
	.string "È come la regione di ALOLA,\n"
	.string "ma più vicina a KANTO!\p"
	.string "Ho risparmiato un sacco sul viaggio!$"

Melemele_House4_Woman_Text_0:
	.string "Il mio ragazzo mi aveva detto che\n"
	.string "andavamo ad ALOLA…\p"
	.string "Credevo nella regione di ALOLA, non\n"
	.string "nelle isolette al largo della\l"
	.string "costa di KANTO.$"
