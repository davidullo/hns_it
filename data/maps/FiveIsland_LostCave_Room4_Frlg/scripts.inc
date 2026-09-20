FiveIsland_LostCave_Room4_Frlg_MapScripts::
	.byte 0

FiveIsland_LostCave_Room4_EventScript_Laura::
	trainerbattle_single TRAINER_PSYCHIC_LAURA, FiveIsland_LostCave_Room4_Text_LauraIntro, FiveIsland_LostCave_Room4_Text_LauraDefeat
	msgbox FiveIsland_LostCave_Room4_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_LostCave_Room4_Text_LauraIntro::
	.string "In questa grotta c'è\n"
	.string "un potere misterioso.$"

FiveIsland_LostCave_Room4_Text_LauraDefeat::
	.string "Se non prendi il tunnel\n"
	.string "giusto, non vai avanti.$"

FiveIsland_LostCave_Room4_Text_LauraPostBattle::
	.string "Prima, una signora è entrata\n"
	.string "nelle grotte avanti.$"

