LavenderTown_VolunteerPokemonHouse_Frlg_MapScripts::
	.byte 0

LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji::
	lock
	faceplayer
	goto_if_set FLAG_GOT_POKE_FLUTE, LavenderTown_VolunteerPokemonHouse_EventScript_AlreadyHavePokeFlute
	msgbox LavenderTown_VolunteerPokemonHouse_Text_IdLikeYouToHaveThis
	checkitemspace ITEM_POKE_FLUTE
	goto_if_eq VAR_RESULT, FALSE, LavenderTown_VolunteerPokemonHouse_EventScript_NoRoomForPokeFlute
	setflag FLAG_GOT_POKE_FLUTE
	giveitem_msg LavenderTown_VolunteerPokemonHouse_Text_ReceivedPokeFluteFromMrFuji, ITEM_POKE_FLUTE, 1, MUS_RG_OBTAIN_KEY_ITEM
	msgbox LavenderTown_VolunteerPokemonHouse_Text_ExplainPokeFlute
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_AlreadyHavePokeFlute::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_HasPokeFluteHelpedYou
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_NoRoomForPokeFlute::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MustMakeRoomForThis
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_LittleGirl::
	lock
	faceplayer
	famechecker FAMECHECKER_MRFUJI, 0
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MrFujiLooksAfterOrphanedMons
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_LittleBoy::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MonsNiceToHug, MSGBOX_NPC
	end

LavenderTown_VolunteerPokemonHouse_EventScript_Youngster::
	lock
	faceplayer
	goto_if_set FLAG_RESCUED_MR_FUJI, LavenderTown_VolunteerPokemonHouse_EventScript_YoungsterFujiBack
	msgbox LavenderTown_VolunteerPokemonHouse_Text_WhereDidMrFujiGo
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_YoungsterFujiBack::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MrFujiWasPrayingForCubonesMother
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_Nidorino::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_NIDORINO, CRY_MODE_NORMAL
	msgbox LavenderTown_VolunteerPokemonHouse_Text_Nidorino
	waitmoncry
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_Psyduck::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PSYDUCK, CRY_MODE_NORMAL
	msgbox LavenderTown_VolunteerPokemonHouse_Text_Psyduck
	waitmoncry
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_PokemonFanMagazine::
	lockall
	famechecker FAMECHECKER_MRFUJI, 2
	msgbox LavenderTown_VolunteerPokemonHouse_Text_GrandPrizeDrawingClipped
	releaseall
	end

LavenderTown_VolunteerPokemonHouse_EventScript_Bookshelf::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_PokemonMagazinesLineShelf, MSGBOX_SIGN
	end

LavenderTown_PokemonCenter_1F_Text_HearMrFujiNotFromAroundHere::
	.string "Mi sono trasferito qui da poco.\p"
	.string "Ho sentito che neanche il SIG. FUJI\n"
	.string "è di queste parti.$"

LavenderTown_VolunteerPokemonHouse_Text_WhereDidMrFujiGo::
	.string "Il SIG. FUJI non c'è.\n"
	.string "Dove sarà?$"

LavenderTown_VolunteerPokemonHouse_Text_MrFujiWasPrayingForCubonesMother::
	.string "Il SIG. FUJI pregava da solo\n"
	.string "per la madre di CUBONE.$"

LavenderTown_VolunteerPokemonHouse_Text_MrFujiLooksAfterOrphanedMons::
	.string "Questa è la casa del SIGNOR FUJI.\p"
	.string "È davvero gentile.\p"
	.string "Si prende cura dei POKéMON\n"
	.string "abbandonati e orfani.$"

LavenderTown_VolunteerPokemonHouse_Text_MonsNiceToHug::
	.string "Che caldo!\n"
	.string "I POKéMON sono così belli da abbracciare.$"

LavenderTown_VolunteerPokemonHouse_Text_Nidorino::
	.string "NIDORINO: Gaoo!$"

LavenderTown_VolunteerPokemonHouse_Text_Psyduck::
	.string "PSYDUCK: Gwappa!$"

LavenderTown_VolunteerPokemonHouse_Text_IdLikeYouToHaveThis::
	.string "SIG. FUJI: {PLAYER}…\p"
	.string "La tua impresa del POKéDEX\n"
	.string "richiede grande dedizione.\p"
	.string "Senza un profondo amore per i POKéMON,\n"
	.string "potrebbe fallire.\p"
	.string "Non so se ti aiuterà,\n"
	.string "ma vorrei che lo avessi.$"

LavenderTown_VolunteerPokemonHouse_Text_ReceivedPokeFluteFromMrFuji::
	.string "{PLAYER} riceve il FLAUTO\n"
	.string "dal SIG. FUJI.$"

LavenderTown_VolunteerPokemonHouse_Text_ExplainPokeFlute::
	.string "Al suono del POKé FLAUTO,\n"
	.string "i POKéMON addormentati si svegliano.\p"
	.string "Provalo sui POKéMON che sono\n"
	.string "ostacoli dormienti.$"

LavenderTown_VolunteerPokemonHouse_Text_MustMakeRoomForThis::
	.string "Devi fare spazio per questo!$"

LavenderTown_VolunteerPokemonHouse_Text_HasPokeFluteHelpedYou::
	.string "SIG. FUJI: Il mio POKé FLAUTO\n"
	.string "ti è stato utile?$"

LavenderTown_VolunteerPokemonHouse_Text_GrandPrizeDrawingClipped::
	.string "RIVISTA PER FAN POKéMON\n"
	.string "Estrazione Premio Mensile!\p"
	.string "Il modulo di richiesta è…\p"
	.string "Via! È stato ritagliato.\n"
	.string "Qualcuno l'avrà già inviato.$"

LavenderTown_VolunteerPokemonHouse_Text_PokemonMagazinesLineShelf::
	.string "La mensola è piena di riviste POKéMON.\p"
	.string "POKéMON INSIDER…\p"
	.string "POKéMON FAN…$"

