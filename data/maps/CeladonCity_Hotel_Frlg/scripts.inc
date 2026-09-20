CeladonCity_Hotel_Frlg_MapScripts::
	.byte 0

CeladonCity_Hotel_EventScript_Receptionist::
	msgbox CeladonCity_Hotel_Text_ThisHotelIsForPeople, MSGBOX_NPC
	end

CeladonCity_Hotel_EventScript_Beauty::
	msgbox CeladonCity_Hotel_Text_OnVacationWithBrotherAndBoyfriend, MSGBOX_NPC
	end

CeladonCity_Hotel_EventScript_BeautyBoyfriend::
	msgbox CeladonCity_Hotel_Text_WhyDidSheBringBrother, MSGBOX_NPC
	end

CeladonCity_Hotel_EventScript_BeautyBrother::
	msgbox CeladonCity_Hotel_Text_SisBroughtMeOnVacation, MSGBOX_NPC
	end

CeladonCity_Hotel_Text_ThisHotelIsForPeople::
	.string "POKéMON?\n"
	.string "No, è un hotel per persone.\p"
	.string "Purtroppo siamo al completo.$"

CeladonCity_Hotel_Text_OnVacationWithBrotherAndBoyfriend::
	.string "In vacanza col mio fratello e il\n"
	.string "mio ragazzo.\p"
	.string "CELADON è una bella città!$"

CeladonCity_Hotel_Text_WhyDidSheBringBrother::
	.string "Perché?\n"
	.string "Perché ha portato suo fratello?$"

CeladonCity_Hotel_Text_SisBroughtMeOnVacation::
	.string "Evviva! Sono in vacanza!\n"
	.string "Mia sorella mi ha portato! Forte!$"

