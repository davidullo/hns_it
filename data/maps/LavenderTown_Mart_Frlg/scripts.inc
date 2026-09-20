LavenderTown_Mart_Frlg_MapScripts::
	.byte 0

LavenderTown_Mart_EventScript_BaldingMan::
	msgbox LavenderTown_Mart_Text_SearchingForStatRaiseItems, MSGBOX_NPC
	end

LavenderTown_Mart_EventScript_Rocker::
	msgbox LavenderTown_Mart_Text_DidYouBuyRevives, MSGBOX_NPC
	end

LavenderTown_Mart_EventScript_Youngster::
	msgbox LavenderTown_Mart_Text_TrainerDuosCanChallengeYou, MSGBOX_NPC
	end

LavenderTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LavenderTown_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
LavenderTown_Mart_Items::
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_NONE
	release
	end

LavenderTown_Mart_Text_SearchingForStatRaiseItems::
	.string "Cerco oggetti che aumentino\n"
	.string "le statistiche dei POKéMON.\p"
	.string "Durano per il corso\n"
	.string "di una sola lotta.\p"
	.string "ATTACCO X, DIFESA X, VELOCITÀ X\n"
	.string "e ATT. SPECIALE X. Ecco cosa cerco.\p"
	.string "Sai dove posso trovarli?$"

LavenderTown_Mart_Text_DidYouBuyRevives::
	.string "Hai comprato dei REVITALIZZANTI?\n"
	.string "Rianimano i POKéMON esausti!$"

LavenderTown_Mart_Text_TrainerDuosCanChallengeYou::
	.string "Certe volte una coppia di\n"
	.string "ALLENATORI ti sfida con due POKéMON\l"
	.string "in contemporanea.\p"
	.string "Se succede, devi mandare\n"
	.string "in campo due POKéMON anche tu.$"

LavenderTown_Mart_Text_SoldNuggetFromMountainsFor5000::
	.string "この　あいだ　やまおくで\n"
	.string "きんのたまを　ひろい　ましてね！\p"
	.string "つかえない　しなもの　ですが\n"
	.string "うったら　なんと　5000¥でした$"
