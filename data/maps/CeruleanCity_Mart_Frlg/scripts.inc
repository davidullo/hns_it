CeruleanCity_Mart_Frlg_MapScripts::
	.byte 0

CeruleanCity_Mart_EventScript_Youngster::
	msgbox CeruleanCity_Mart_Text_RepelWorksOnWeakMons, MSGBOX_NPC
	end

CeruleanCity_Mart_EventScript_Woman::
	msgbox CeruleanCity_Mart_Text_DoYouKnowAboutRareCandy, MSGBOX_NPC
	end

CeruleanCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeruleanCity_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
CeruleanCity_Mart_Items::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_NONE
	release
	end

CeruleanCity_Mart_Text_RepelWorksOnWeakMons::
	.string "Il REPELLENTE non scaccia solo\n"
	.string "gli insetti, ma anche i POKéMON\p"
	.string "deboli. Metti il più forte\n"
	.string "a sinistra nella LISTA.\p"
	.string "Se il primo POKéMON è forte,\n"
	.string "l'effetto è potenziato.$"

CeruleanCity_Mart_Text_DoYouKnowAboutRareCandy::
	.string "Sai cos'è la CARAMELLA RARA?\n"
	.string "Non la vendono nei negozi.\p"
	.string "Credo faccia crescere i\n"
	.string "POKéMON molto in fretta.$"

