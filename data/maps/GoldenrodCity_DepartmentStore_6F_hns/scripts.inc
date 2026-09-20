GoldenrodCity_DepartmentStore_6F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore6_EventScript_Whitney::
	lock
	faceplayer
	msgbox GoldenrodDeptStore6_Text_Whitney, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_DEPTSTORE_WHITNEY
	removeobject LOCALID_STORE_WHITNEY
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_DOJO_WHITNEY
	release
	end

GoldenrodDeptStore6_Text_Whitney:
	.string "{PLAYER}! Che sorpresa!\p"
	.string "Devo prendere una cosa per\n"
	.string "il MILTANK.\p"
	.string "Se vuoi un'altra lotta, vieni\n"
	.string "al DOJO LOTTA!$"

GoldenrodCity_DepartmentStore_6F_EventScript_Jose::
	lock
	faceplayer
	goto_if_set FLAG_GOLDENROD_NPC_TRADE_COMPLETED, GoldenrodCity_DepartmentStore_6F_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_MACHOP, GoldenrodCity_DepartmentStore_6F_Text_YouWillTradeWontYou, GoldenrodCity_DepartmentStore_6F_EventScript_DeclineTrade, GoldenrodCity_DepartmentStore_6F_EventScript_NotRequestedMon, GoldenrodCity_DepartmentStore_6F_Text_MonYouTakeCare
	setflag FLAG_GOLDENROD_NPC_TRADE_COMPLETED
	release
	end

GoldenrodCity_DepartmentStore_6F_EventScript_DeclineTrade::
	msgbox GoldenrodCity_DepartmentStore_6F_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_DepartmentStore_6F_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox GoldenrodCity_DepartmentStore_6F_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_DepartmentStore_6F_EventScript_TradeCompleted::
	msgbox GoldenrodCity_DepartmentStore_6F_Text_After, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_DepartmentStore_6F_Text_YouWillTradeWontYou:
	.string "Colleziono POKéMON!\n"
	.string "Hai un {STR_VAR_1}?\p"
	.string "Lo vuoi scambiare col mio\n"
	.string "{STR_VAR_2}?$"

GoldenrodCity_DepartmentStore_6F_Text_MonYouTakeCare:
	.string "Evvai! Ho {STR_VAR_1}!\p"
	.string "Ciao, {STR_VAR_2}!$"

GoldenrodCity_DepartmentStore_6F_Text_ThisIsntAMon:
	.string "Ah, no, temo di no.\n"
	.string "Non è un {STR_VAR_1}.$"

GoldenrodCity_DepartmentStore_6F_Text_YouWontTradeMe:
	.string "Non vuoi scambiare? Oh…$"

GoldenrodCity_DepartmentStore_6F_Text_After:
	.string "Ciao, come sta il mio MACHOP?$"


GoldenrodDeptStore6_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_6FLass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore6_EventScript_Nerd::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_6FSuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore6_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_6FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_6FLass:
    .string "Ascolti il CANALE FORTUNA?\p"
    .string "Dicono che per vincere\n"
	.string "dovresti scambiare POKéMON con\l"
    .string "piu' persone possibile per avere\l"
    .string "ID diversi.\p"
	.string "Pero' gli scambi non sono piu'\n"
	.string "diffusi come una volta.$"

GoldenrodDeptStore_Text_6FSuperNerd:
    .string "Se sei stanco, prova le bibite\n"
    .string "del distributore.\p"
    .string "Piacera' anche ai tuoi POKéMON.$"

GoldenrodDeptStore_Text_6FDirectory:
    .string "Pausa dallo shopping!\p"
    .string "6F PIAZZA TRANQUILLA$"
