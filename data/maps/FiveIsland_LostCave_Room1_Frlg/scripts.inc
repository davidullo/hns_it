FiveIsland_LostCave_Room1_Frlg_MapScripts::
	.byte 0

FiveIsland_LostCave_Room1_EventScript_Lawson::
	trainerbattle_single TRAINER_RUIN_MANIAC_LAWSON, FiveIsland_LostCave_Room1_Text_LawsonIntro, FiveIsland_LostCave_Room1_Text_LawsonDefeat
	msgbox FiveIsland_LostCave_Room1_Text_LawsonPostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_LostCave_Room1_Text_LawsonIntro::
	.string "Ahiieeeeh!\p"
	.string "Credevo fosse un'antica rovina.\n"
	.string "Ma è piena di fantasmi!$"

FiveIsland_LostCave_Room1_Text_LawsonDefeat::
	.string "Ahiieeeeh!\n"
	.string "Pietà!$"

FiveIsland_LostCave_Room1_Text_LawsonPostBattle::
	.string "Cerco di uscire di qui, ma\n"
	.string "finisco sempre allo stesso punto.\p"
	.string "Forse il numero di massi è\n"
	.string "un indizio…$"

