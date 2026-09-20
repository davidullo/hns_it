MossdeepCity_Mart_MapScripts::
	.byte 0

MossdeepCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MossdeepCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MossdeepCity_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	pokemartlistend

MossdeepCity_Mart_EventScript_Woman::
	msgbox MossdeepCity_Mart_Text_ReviveIsFantastic, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Boy::
	msgbox MossdeepCity_Mart_Text_MaxRepelLastsLongest, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Sailor::
	msgbox MossdeepCity_Mart_Text_NetAndDiveBallsRare, MSGBOX_NPC
	end

MossdeepCity_Mart_Text_ReviveIsFantastic:
	.string "Il REVITALIZZANTE è fantastico!\p"
	.string "Dallo a un POKéMON esausto,\n"
	.string "e il POKéMON si riprenderà.\p"
	.string "Ma attento, non ripristina\n"
	.string "i PP delle mosse già usati.$"

MossdeepCity_Mart_Text_MaxRepelLastsLongest:
	.string "Il SUPERREPELLENTE tiene via i POKéMON\p"
	.string "deboli. Fra tutti gli spray REPELLENTE,\n"
	.string "dura di più.$"

MossdeepCity_Mart_Text_NetAndDiveBallsRare:
	.string "La RETE BALL e la SUB BALL sono POKé\n"
	.string "BALL rare, prodotte solo a MOSSDEEP.\p"
	.string "La RETE BALL è efficace contro i\n"
	.string "POKéMON di tipo Coleottero e Acqua.\p"
	.string "La SUB BALL funziona meglio sui POKéMON\n"
	.string "in fondo al mare.$"

