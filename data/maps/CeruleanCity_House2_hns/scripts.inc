CeruleanCity_House2_hns_MapScripts::
	.byte 0

CeruleanCity_House2_EventScript_Woman::
	msgbox CeruleanPolice_Text_PokefanF, MSGBOX_NPC
	end

CeruleanCity_House2_EventScript_Man::
	msgbox CeruleanPolice_Text_FishingGuru, MSGBOX_NPC
	end

CeruleanCity_House2_EventScript_Diglett::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DIGLETT, CRY_MODE_NORMAL
	msgbox CeruleanPolice_Text_Diglett, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeruleanPolice_Text_FishingGuru:
	.string "Ho sentito che un losco tipo\n"
	.string "gira nei paraggi.\p"
	.string "Non lo tollererò se si rivela\n"
	.string "un ladro.$"

CeruleanPolice_Text_PokefanF:
	.string "Ci hanno rapinato già una volta.$"

CeruleanPolice_Text_Diglett:
	.string "DIGLETT: Scav!$"
