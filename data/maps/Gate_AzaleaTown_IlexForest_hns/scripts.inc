Gate_AzaleaTown_IlexForest_hns_MapScripts::
	.byte 0

Gate_AzaleaTown_IlexForest_EventScript_Officer::
	lock
	faceplayer
	msgbox Gate_AzaleaTown_IlexForest_Text_Officer, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_AzaleaTown_IlexForest_EventScript_Granny::
	lock
	faceplayer
	msgbox Gate_AzaleaTown_IlexForest_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_AzaleaTown_IlexForest_Text_Officer:
	.string "ILEX FOREST è vasto.\n"
	.string "Cautela!\l"
	.string "Non perderti.$"

Gate_AzaleaTown_IlexForest_Text_Granny:
	.string "L'ILEX FOREST è protetto\n"
	.string "dal suo protettore.\p"
	.string "Non fate i birbanti!$"
