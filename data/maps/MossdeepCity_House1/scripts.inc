MossdeepCity_House1_MapScripts::
	.byte 0

MossdeepCity_House1_EventScript_BlackBelt::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox MossdeepCity_House1_Text_HmmYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetPokeblockNameByMonNature
	goto_if_eq VAR_RESULT, 0, MossdeepCity_House1_EventScript_NeutralNature
	msgbox MossdeepCity_House1_Text_ItLikesXPokeblocks, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House1_EventScript_NeutralNature::
	msgbox MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House1_EventScript_Woman::
	msgbox MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes, MSGBOX_NPC
	end

MossdeepCity_House1_Text_HmmYourPokemon:
	.string "Hmm!\n"
	.string "Il tuo {STR_VAR_1}…$"

MossdeepCity_House1_Text_ItLikesXPokeblocks:
	.string "Gli piacciono i {STR_VAR_1},\n"
	.string "vero?\p"
	.string "No, ne sono certo! Gli piacciono\n"
	.string "proprio i {STR_VAR_1}!$"

MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks:
	.string "Sembra che non gradisca né disprezzi\n"
	.string "alcun {POKEBLOCK}.$"

MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes:
	.string "Mio marito capisce che tipo di\n"
	.string "{POKEBLOCK} piace a un POKéMON al volo.$"

