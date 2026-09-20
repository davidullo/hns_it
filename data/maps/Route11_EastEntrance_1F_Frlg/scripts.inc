Route11_EastEntrance_1F_Frlg_MapScripts::
	.byte 0

Route11_EastEntrance_1F_EventScript_TopGuard::
	msgbox Route11_EastEntrance_1F_Text_ManInLavenderRatesNames, MSGBOX_NPC
	end

Route11_EastEntrance_1F_EventScript_BottomGuard::
	msgbox Route11_EastEntrance_1F_Text_RockTunnelToReachLavender, MSGBOX_NPC
	end

@ Unclear where this is originally from
Route11_EastEntrance_1F_Text_BagIsFull::
	.string "{PLAYER}{KUN}の　バッグ\n"
	.string "いっぱい　みたい　だね$"

Route11_EastEntrance_1F_Text_ManInLavenderRatesNames::
	.string "Non trovi difficile inventare\n"
	.string "bei nomi per i POKéMON?\p"
	.string "Soprattutto se ne hai catturati\n"
	.string "un bel po'?\p"
	.string "A LAVANDONIA c'è un uomo\n"
	.string "che valuta i soprannomi.\p"
	.string "Può anche aiutarti a rinominare\n"
	.string "i tuoi POKéMON.$"

Route11_EastEntrance_1F_Text_RockTunnelToReachLavender::
	.string "Se vuoi arrivare a LAVANDONIA,\n"
	.string "passa per la GROTTA ROCCIOSA.\p"
	.string "Ci si arriva da\n"
	.string "CELESTOPOLI.$"

