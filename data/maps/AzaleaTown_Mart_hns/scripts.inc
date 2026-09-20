AzaleaTown_Mart_hns_MapScripts::
	.byte 0

AzaleaTown_Mart_EventScriptCooltrainerM::
	lock
	faceplayer
	msgbox AzaleaMart_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_Mart_EventScriptBugCatcher::
	lock
	faceplayer
	msgbox AzaleaMart_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaMart_Text_CooltrainerM:
	.string "Puoi comprare una GREAT BALL?\n"
	.string "Io compro solo POKé BALL.\p"
	.string "Ho sentito che si sbloccano\n"
	.string "più oggetti quando ottieni\l"
	.string "MEDAGLIE!\p"
	.string "Vorrei che KURT mi creasse\n"
	.string "le sue SFERE speciali.$"

AzaleaMart_Text_BugCatcher:
	.string "Una GREAT BALL cattura\n"
	.string "i POKéMON meglio di una\p"
	.string "POKé BALL. Ma quelle di\n"
	.string "KURT a volte vince.$"

