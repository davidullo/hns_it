SaffronCity_CopycatsHouse_2F_Frlg_MapScripts::
	.byte 0

SaffronCity_CopycatsHouse_2F_EventScript_Doduo::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DODUO, CRY_MODE_NORMAL
	msgbox SaffronCity_CopycatsHouse_2F_Text_Doduo
	waitmoncry
	release
	end

SaffronCity_CopycatsHouse_2F_EventScript_Doll::
	lock
	msgbox SaffronCity_CopycatsHouse_2F_Text_RareMonOnlyDoll
	release
	end

SaffronCity_CopycatsHouse_2F_EventScript_Copycat::
	lock
	faceplayer
	checkitem ITEM_POKE_DOLL
	goto_if_eq VAR_RESULT, TRUE, EventScript_MimicTutor
	checkplayergender
	call_if_eq VAR_RESULT, MALE, SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerMale
	call_if_eq VAR_RESULT, FEMALE, SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerFemale
	release
	end

SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerMale::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyMale
	return

SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerFemale::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyFemale
	return

SaffronCity_CopycatsHouse_2F_EventScript_Computer::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MySecrets, MSGBOX_SIGN
	end

SaffronCity_CopycatsHouse_2F_EventScript_Game::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MarioWearingABucket, MSGBOX_SIGN
	end

SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyMale::
	.string "{PLAYER}: Ciao!\n"
	.string "Ti piacciono i POKéMON?\p"
	.string "{PLAYER}: No, ti ho appena chiesto io.\p"
	.string "{PLAYER}: Eh?\n"
	.string "Sei strano!\p"
	.string "COPIONA: Hmm? Smettere di imitare?\n"
	.string "Ma è il mio hobby preferito!$"

SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyFemale::
	.string "{PLAYER}: Ciao.\n"
	.string "Certo ti piacciono i POKéMON.\p"
	.string "{PLAYER}: No, non io.\n"
	.string "Ho chiesto a te.\p"
	.string "{PLAYER}: Come?\n"
	.string "Sei strana!\l"
	.string " \l"
	.string "COPIONA: Hmm? Smettere di imitare?\l"
	.string "Ma è il mio hobby preferito!$"

Text_MimicTeach::
	.string "Oh wow!\n"
	.string "Un POKé DOLL!\p"
	.string "Per me?\n"
	.string "Grazie!\p"
	.string "Sai cosa?\n"
	.string "Posso insegnare la mossa MIMICA.$"

Text_MimicDeclined::
	.string "Non ti piace MIMICA?$"

Text_MimicWhichMon::
	.string "Adoro MIMICA!\n"
	.string "Chi la imparerà?$"

Text_MimicTaughtMale::
	.string "{PLAYER}: Ciao!\n"
	.string "Grazie di prima!\p"
	.string "{PLAYER}: Come?\p"
	.string "{PLAYER}: Ti diverte così tanto imitare\n"
	.string "ogni mia mossa?\p"
	.string "COPIONA: Certo!\n"
	.string "È uno spasso!$"

Text_MimicTaughtFemale::
	.string "{PLAYER}: Ciao!\n"
	.string "Grazie per quello che hai fatto.\p"
	.string "{PLAYER}: Come?\p"
	.string "{PLAYER}: Ti diverte così tanto\n"
	.string "copiare quel che dico e faccio?\p"
	.string "COPIONA: Certo!\n"
	.string "È uno spasso!$"

SaffronCity_CopycatsHouse_2F_Text_Doduo::
	.string "DODUO: Giiih!\p"
	.string "SPECCHIO CARINO, GUARDAMI,\n"
	.string "VEDI QUANTO SON BELLA?$"

SaffronCity_CopycatsHouse_2F_Text_RareMonOnlyDoll::
	.string "Questo è un POKéMON raro!\n"
	.string "Eh? È solo una bambola!$"

SaffronCity_CopycatsHouse_2F_Text_MarioWearingABucket::
	.string "Un gioco con MARIO che ha un secchio\n"
	.string "in testa!$"

SaffronCity_CopycatsHouse_2F_Text_MySecrets::
	.string "…\p"
	.string "I miei segreti!\p"
	.string "Abilità: Mimetismo!\n"
	.string "Hobby: collezionare bambole!\l"
	.string "POKéMON preferito: CLEFAIRY!$"

