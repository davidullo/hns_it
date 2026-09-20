ViridianCity_House1_hns_MapScripts::
	.byte 0

ViridianCity_House1_EventScript_Pokefan::
	msgbox ViridianCity_House1_Text_PokefanM, MSGBOX_NPC
	end

ViridianCity_House1_EventScript_Lass::
	msgbox ViridianCity_House1_Text_Lass, MSGBOX_NPC
	end


ViridianCity_House1_EventScript_Speary::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SPEAROW, CRY_MODE_NORMAL
	msgbox ViridianCity_House1_Text_Speary, MSGBOX_DEFAULT
	waitmoncry
	release
	end

ViridianCity_House1_EventScript_Rattey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_RATTATA, CRY_MODE_NORMAL
	msgbox ViridianCity_House1_Text_Rattey, MSGBOX_DEFAULT
	waitmoncry
	release
	end

ViridianCity_House1_Text_PokefanM:
	.string "Ci pensi bene prima di dare\n"
	.string "un nome ai tuoi POKéMON?\p"
	.string "Dei bei soprannomi rendono più\n"
	.string "divertente scambiare con gli altri.$"

ViridianCity_House1_Text_Lass:
	.string "Sono SPEARY, uno SPEAROW, e\n"
	.string "RATTEY, un RATTATA.$"

ViridianCity_House1_Text_Speary:
	.string "SPEARY: Ch-chun!$"

ViridianCity_House1_Text_Rattey:
	.string "RATTEY: Kikiii!$"

