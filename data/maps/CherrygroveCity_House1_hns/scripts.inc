CherrygroveCity_House1_hns_MapScripts::
	.byte 0

CherrygroveCity_House1_EventScript_Baldingman::
	lock
	faceplayer
	msgbox CherrygroveCity_GymSpeechHouse_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_House1_EventScript_Kid::
	lock
	faceplayer
	msgbox CherrygroveCity_GymSpeechHouse_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_GymSpeechHouse_Text_PokefanM:
	.string "Vuoi scoprire quanto sei\n"
	.string "bravo come allenatore?\p"
	.string "Visita le PALESTRE POKéMON\n"
	.string "di tutto JOHTO e raccogli\l"
	.string "MEDAGLIE.$"

CherrygroveCity_GymSpeechHouse_Text_BugCatcher:
	.string "Da grande diventerò\n"
	.string "CAPOPALESTRA!\p"
	.string "Faccio lottare i miei POKéMON\n"
	.string "con gli amici per farli\l"
	.string "più forti!$"
