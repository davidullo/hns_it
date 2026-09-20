gText_PkmnTransferredSomeonesPC::
	.string "{STR_VAR_2} è stato inviato\n"
	.string "al PC di QUALCUNO.\p"
	.string "È stato messo nel \n"
	.string "BOX “{STR_VAR_1}.”$"

gText_PkmnTransferredLanettesPC::
	.string "{STR_VAR_2} è stato inviato\n"
#if IS_FRLG || IS_HNS
	.string "al PC di BILL.\p"
#else
	.string "LANETTE'S PC.\p"
#endif
	.string "È stato messo nel \n"
	.string "BOX “{STR_VAR_1}.”$"

gText_PkmnTransferredSomeonesPCBoxFull::
	.string "Il BOX “{STR_VAR_3}” del\n"
	.string "PC di QUALCUNO era pieno.\p"
	.string "{STR_VAR_2} è stato inviato\n"
	.string "al BOX “{STR_VAR_1}.”$"

gText_PkmnTransferredLanettesPCBoxFull::
	.string "Il BOX “{STR_VAR_3}” del\n"
#if IS_FRLG || IS_HNS
	.string "PC di BILL era pieno.\p"
#else
	.string "LANETTE'S PC was full.\p"
#endif
	.string "{STR_VAR_2} è stato inviato\n"
	.string "al BOX “{STR_VAR_1}.”$"

gText_PkmnSentToPCAfterCatch::
	.string "{STR_VAR_2} è stato inviato\n"
	.string "al PC di {B_PC_CREATOR_NAME}.\p"
	.string "È stato messo nel \n"
	.string "BOX “{STR_VAR_1}”.$"

gText_PlayerObtainedTheMon::
	.string "{PLAYER} ha ottenuto\n"
	.string "il {STR_VAR_1}!$"

gText_NoMoreRoomForPokemon::
	.string "Non c'è più spazio per i POKéMON!\p"
	.string "I BOX POKéMON sono pieni e\n"
	.string "non ne accettano altri!$"

gText_NicknameThisPokemon::
	.string "Vuoi dare un soprannome a\n"
	.string "questo {STR_VAR_1}?$"
