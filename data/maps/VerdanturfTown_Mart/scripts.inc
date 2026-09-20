VerdanturfTown_Mart_MapScripts::
	.byte 0

VerdanturfTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart VerdanturfTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
VerdanturfTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_FLUFFY_TAIL
	pokemartlistend

VerdanturfTown_Mart_EventScript_Boy::
	msgbox VerdanturfTown_Mart_Text_XSpecialIsCrucial, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_ExpertF::
	msgbox VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_Lass::
	msgbox VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon, MSGBOX_NPC
	end

VerdanturfTown_Mart_Text_XSpecialIsCrucial:
	.string "In qualsiasi lotta POKéMON, la\n"
	.string "X SPECIAL è cruciale.\p"
	.string "Aumenta la potenza di alcune mosse\n"
	.string "anche se dura una sola lotta.$"

VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent:
	.string "Non sembrano vendere guide\n"
	.string "strategiche per il TENTE LOTTA…\p"
	.string "A quanto pare bisogna affidarsi\n"
	.string "al proprio ingegno…$"

VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon:
	.string "La NEST BALL funziona meglio sui\n"
	.string "POKéMON indeboliti.\p"
	.string "VERDANTURF è l'unico posto dove\n"
	.string "si può comprare.$"

