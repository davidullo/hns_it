FourIsland_Mart_Frlg_MapScripts::
	.byte 0

FourIsland_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FourIsland_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
FourIsland_Mart_Items::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

FourIsland_Mart_EventScript_Camper::
	msgbox FourIsland_Mart_Text_IcefallCaveIsFrigid, MSGBOX_NPC
	end

FourIsland_Mart_Text_LoreleiGrewUpOnThisIsland::
	.string "Qui è cresciuto un\n"
	.string "ALLENATORE fortissimo.\p"
	.string "Scommetto che la conosci.\n"
	.string "È LORELEI del SUPERQUATTRO!\p"
	.string "Quando LORELEI era piccola,\n"
	.string "le insegnavo i POKéMON.$"

FourIsland_Mart_Text_IcefallCaveIsFrigid::
	.string "Le ISOLE SEVII sono in una\n"
	.string "zona calda.\p"
	.string "Ma c'è un'eccezione\n"
	.string "da conoscere.\p"
	.string "La GROTTA ICEFALL è gelida\n"
	.string "per i POKéMON che ci vivono.$"

