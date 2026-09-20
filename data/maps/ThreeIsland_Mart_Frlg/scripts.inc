ThreeIsland_Mart_Frlg_MapScripts::
	.byte 0

ThreeIsland_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart ThreeIsland_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
ThreeIsland_Mart_Items::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

ThreeIsland_Mart_EventScript_Picnicker::
	msgbox ThreeIsland_Mart_Text_TrueThatCeldadonDeptStoreBigger, MSGBOX_NPC
	end

ThreeIsland_Mart_EventScript_BugCatcher::
	msgbox ThreeIsland_Mart_Text_PeopleHealWithBerriesFromForest, MSGBOX_NPC
	end

ThreeIsland_Mart_EventScript_Youngster::
	msgbox ThreeIsland_Mart_Text_BikersWereAboutToTrashMart, MSGBOX_NPC
	end

ThreeIsland_Mart_Text_TrueThatCeldadonDeptStoreBigger::
	.string "È vero?\p"
	.string "Il CENTRO COMMERCIALE di AZZURROPOLI\n"
	.string "è molto più grande di questo negozio?$"

ThreeIsland_Mart_Text_PeopleHealWithBerriesFromForest::
	.string "A volte compro medicine qui.\p"
	.string "Ma molti curano i POKéMON\n"
	.string "con le BACCHE della FORESTA BACCA.\p"
	.string "Dopotutto, le BACCHE sono gratis\n"
	.string "e non finiscono mai.$"

ThreeIsland_Mart_Text_BikersWereAboutToTrashMart::
	.string "Quei BIKER stavano per distruggere\n"
	.string "questo MART POKéMON.\p"
	.string "Che sollievo che se ne siano andati!$"
