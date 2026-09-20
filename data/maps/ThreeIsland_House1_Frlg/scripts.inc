ThreeIsland_House1_Frlg_MapScripts::
	.byte 0

ThreeIsland_House1_EventScript_Lostelle::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	msgbox ThreeIsland_House1_Text_YoureAlwaysSoCool
	release
	end

ThreeIsland_House1_EventScript_DisplayCase::
	msgbox ThreeIsland_House1_Text_RareRocksGemsDisplayed, MSGBOX_SIGN
	end

ThreeIsland_House1_Text_YoureAlwaysSoCool::
	.string "LOSTELLE: Ciao, {PLAYER}!\n"
	.string "Sei sempre così forte!\p"
	.string "Un giorno preparerò il pranzo\n"
	.string "anche per te, {PLAYER}.$"

ThreeIsland_House1_Text_RareRocksGemsDisplayed::
	.string "Sono esposte rocce e gemme rare.$"

