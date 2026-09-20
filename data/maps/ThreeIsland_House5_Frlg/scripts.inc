ThreeIsland_House5_Frlg_MapScripts::
	.byte 0

ThreeIsland_House5_EventScript_LittleGirl::
	lock
	faceplayer
	goto_if_set FLAG_RESCUED_LOSTELLE, ThreeIsland_House5_EventScript_LittleGirlLostelleFound
	msgbox ThreeIsland_House5_Text_ImNotLostelle
	release
	end

ThreeIsland_House5_EventScript_LittleGirlLostelleFound::
	msgbox ThreeIsland_House5_Text_IllGoPlayWithLostelle
	release
	end

ThreeIsland_House5_Text_ImNotLostelle::
	.string "Io?\n"
	.string "Non sono LOSTELLE.\p"
	.string "Lei sarà andata nella\n"
	.string "FORESTA BACCA, credo.\p"
	.string "Raccoglie le BACCHE lì per\n"
	.string "preparare il pranzo.$"

ThreeIsland_House5_Text_IllGoPlayWithLostelle::
	.string "Oggi penso che andrò a giocare\n"
	.string "con LOSTELLE.$"
