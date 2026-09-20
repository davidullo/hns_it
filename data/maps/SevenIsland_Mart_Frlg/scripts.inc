SevenIsland_Mart_Frlg_MapScripts::
	.byte 0

SevenIsland_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SevenIsland_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
SevenIsland_Mart_Items::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

SevenIsland_Mart_EventScript_Lass::
	msgbox SevenIsland_Mart_Text_MonHavePersonalitiesOfTheirOwn, MSGBOX_NPC
	end

SevenIsland_Mart_EventScript_Hiker::
	msgbox SevenIsland_Mart_Text_PreparationsCompleteForRuins, MSGBOX_NPC
	end

SevenIsland_Mart_EventScript_Fisher::
	msgbox SevenIsland_Mart_Text_NeedToFishOnSevenIsland, MSGBOX_NPC
	end

SevenIsland_Mart_Text_MonHavePersonalitiesOfTheirOwn::
	.string "I POKéMON hanno una personalità\n"
	.string "propria, come le persone.\p"
	.string "Il mio PIKACHU ha una natura LESTA,\n"
	.string "quindi è cresciuto velocissimo.$"

SevenIsland_Mart_Text_PreparationsCompleteForRuins::
	.string "Okay, i preparativi sono completi\n"
	.string "per esplorare le ROVINE.$"

SevenIsland_Mart_Text_NeedToFishOnSevenIsland::
	.string "Devo pescare a SETTE ISOLA.\p"
	.string "Così completerò il mio giro di pesca\n"
	.string "nelle ISOLE SETTIMANE.\p"
	.string "Ma prima farò scorta di\n"
	.string "POKé BALL.$"

