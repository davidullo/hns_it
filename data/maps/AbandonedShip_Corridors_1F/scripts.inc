AbandonedShip_Corridors_1F_MapScripts::
	.byte 0

AbandonedShip_Corridors_1F_EventScript_Youngster::
	msgbox AbandonedShip_Corridors_1F_Text_IsntItFunHere, MSGBOX_NPC
	end

AbandonedShip_Corridors_1F_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE, AbandonedShip_Corridors_1F_Text_CharlieIntro, AbandonedShip_Corridors_1F_Text_CharlieDefeat
	msgbox AbandonedShip_Corridors_1F_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_1F_Text_CharlieIntro:
	.string "Cosa c'è di strano se ho\n"
	.string "il salvagente in nave?$"

AbandonedShip_Corridors_1F_Text_CharlieDefeat:
	.string "Ohibò, mi hai sommerso!$"

AbandonedShip_Corridors_1F_Text_CharliePostBattle:
	.string "Non è facile lanciare POKé BALL\n"
	.string "aggrappato a un salvagente!$"

AbandonedShip_Corridors_1F_Text_IsntItFunHere:
	.string "Non è bello qui?\n"
	.string "Mi esalto solo a starci!$"
