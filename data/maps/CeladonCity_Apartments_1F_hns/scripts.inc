CeladonCity_Apartments_1F_hns_MapScripts::
	.byte 0

CeladonCity_Apartments_1F_EventScript_Manager::
	msgbox CeladonMansion_Text_Manager, MSGBOX_NPC
	end

CeladonCity_Apartments_1F_EventScript_Sign::
	msgbox CeladonMansion_Text_ManagersSuiteSign, MSGBOX_SIGN
	end

CeladonMansion_Text_Manager:
	.string "I miei cari POKéMON mi fanno\n"
	.string "compagnia, non mi sento mai\p"
	.string "solo. MEOWTH porta anche soldi.$"

CeladonMansion_Text_ManagersSuiteSign:
	.string "SUITE DEL GESTORE MANSIONE FUCSIA$"
