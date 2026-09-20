SSAnne_1F_Room7_Frlg_MapScripts::
	.byte 0

SSAnne_1F_Room7_EventScript_Thomas::
	trainerbattle_single TRAINER_GENTLEMAN_THOMAS, SSAnne_1F_Room7_Text_ThomasIntro, SSAnne_1F_Room7_Text_ThomasDefeat
	msgbox SSAnne_1F_Room7_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room7_Text_ThomasIntro::
	.string "Sono solo un viaggiatore solitario…\p"
	.string "I miei unici amici sono i\n"
	.string "POKéMON che ho preso in viaggio…$"

SSAnne_1F_Room7_Text_ThomasDefeat::
	.string "Amici miei…$"

SSAnne_1F_Room7_Text_ThomasPostBattle::
	.string "Con gli amici sii gentile!$"

