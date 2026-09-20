Melemele_House_3_hns_MapScripts::
	.byte 0


Melemele_House3_Woman::
	lock
	faceplayer
	msgbox Melemele_House3_Woman_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House3_Man::
	lock
	faceplayer
	msgbox Melemele_House3_Man_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House3_Woman_Text_0:
	.string "La vita sull'isola è così tranquilla!\p"
	.string "Ed è bello che i nipoti siano a due\n"
	.string "passi in barca da KANTO!$"

Melemele_House3_Man_Text_0:
	.string "Maledetti turisti!\p"
	.string "L'agente diceva che qui sarebbe stato\n"
	.string "tranquillo… ma venire qui costa\l"
	.string "meno che andare fino ad ALOLA.$"
