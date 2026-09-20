BlackthornCity_House1_hns_MapScripts::
	.byte 0

BlackthornCity_House1EventScript_Granny::
	msgbox BlackthornCity_House1_Text_Granny, MSGBOX_NPC
	end

BlackthornCity_House1EventScript_Dratini::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DRATINI, CRY_MODE_NORMAL
	msgbox BlackthornCity_House1_Text_Dratini, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BlackthornCity_House1_Text_Granny:
	.string "Un clan di allenatori che sa\n"
	.string "comandare i Draghi vive qui a\l"
	.string "FIOCCONIGLIA.\p"
	.string "Perciò in questa città ci sono\n"
	.string "molte leggende sui Draghi.$"

BlackthornCity_House1_Text_Dratini:
	.string "DRATINI: Draa!$"
