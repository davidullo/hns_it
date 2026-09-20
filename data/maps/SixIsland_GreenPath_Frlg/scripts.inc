SixIsland_GreenPath_Frlg_MapScripts::
	.byte 0

SixIsland_GreenPath_EventScript_RightRouteSign::
	msgbox SixIsland_GreenPath_Text_LeftRouteSign, MSGBOX_SIGN
	end

SixIsland_GreenPath_EventScript_LeftRouteSign::
	msgbox SixIsland_GreenPath_Text_RightRouteSign, MSGBOX_SIGN
	end

SixIsland_GreenPath_Text_JaclynIntro::
	.string "…Eh?\p"
	.string "Pensavo alla mia casa, ma\n"
	.string "sono finita qui col TELEPORT?$"

SixIsland_GreenPath_Text_JaclynDefeat::
	.string "Che sconfitta!$"

SixIsland_GreenPath_Text_JaclynPostBattle::
	.string "Ho la testa fra le nuvole!\p"
	.string "Devo concentrarmi per TELEPORTARE\n"
	.string "bene fino a casa mia!$"

SixIsland_GreenPath_Text_LeftRouteSign::
	.string "VIA VERDE\n"
	.string "CESPI A DISEGNO PIÙ AVANTI$"

SixIsland_GreenPath_Text_RightRouteSign::
	.string "VIA VERDE\n"
	.string "Verde è bello, tieni pulito il mondo!$"

