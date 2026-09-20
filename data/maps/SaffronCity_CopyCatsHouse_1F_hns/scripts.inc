SaffronCity_CopyCatsHouse_1F_hns_MapScripts::
	.byte 0

SaffronCity_CopyCatsHouse_1F_EventScript_Mom::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_CopyCatsHouse_1F_EventScript_MomAfter
	msgbox CopycatsHouse1F_Text_PokefanF, MSGBOX_NPC
	end

SaffronCity_CopyCatsHouse_1F_EventScript_MomAfter::
	msgbox CopycatsHouse1F_Text_PokefanF_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_CopyCatsHouse_1F_EventScript_Dad::
	msgbox CopycatsHouse1F_Text_PokefanM, MSGBOX_NPC
	end

SaffronCity_CopyCatsHouse_1F_EventScript_Blissey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BLISSEY, CRY_MODE_NORMAL
	msgbox CopycatsHouse1F_Text_Blissey, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CopycatsHouse1F_Text_PokefanM:
	.string "Mia figlia adora imitare la gente.\p"
	.string "La sua mimica le è valsa il\n"
	.string "soprannome COPIONA, qui in zona.$"

CopycatsHouse1F_Text_PokefanF:
	.string "Mia figlia è così egocentrica…\p"
	.string "Ha solo pochi amici.$"

CopycatsHouse1F_Text_PokefanF_ReturnedPart:
	.string "Ha perso il POKé DOLL\n"
	.string "che un bambino le regalò\l"
	.string "tre anni fa.\p"
	.string "Da allora, è ancora più\n"
	.string "brava a imitare…$"

CopycatsHouse1F_Text_Blissey:
	.string "BLISSEY: Bliisii!$"
