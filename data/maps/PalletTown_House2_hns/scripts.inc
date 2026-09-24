PalletTown_House2_hns_MapScripts::
	.byte 0

PalletTown_House2_EventScript_Daisy::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_CINNABAR_BLUE, PalletTown_House2_EventScript_Blue
	goto_if_unset FLAG_DAILY_DAISY_GROOMED, PalletTown_House2_EventScript_DaisyGrooming
	msgbox PalletTown_House2_Text_AlreadyGroomed, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_House2_EventScript_Blue::
	msgbox PalletTown_House2_Text_Hello, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_House2_EventScript_DaisyDeclineGrooming::
	msgbox PalletTown_House2_Text_Refused, MSGBOX_DEFAULT
	closemessage
	release
	end
PalletTown_House2_EventScript_Egg::
	msgbox PalletTown_House2_Text_CantGroomEgg, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_House2_EventScript_DaisyGrooming::
	msgbox PalletTown_House2_Text_OfferGrooming, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, PalletTown_House2_EventScript_DaisyDeclineGrooming
	msgbox PalletTown_House2_Text_WhichMon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	bufferpartymonnick STR_VAR_1, VAR_0x8004
	goto_if_ge VAR_0x8004, PARTY_SIZE, PalletTown_House2_EventScript_DaisyDeclineGrooming
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, PalletTown_House2_EventScript_Egg
	goto_if_eq VAR_RESULT, FALSE, PalletTown_House2_EventScript_DaisyDeclineGrooming
	
	msgbox PalletTown_House2_Text_Alright
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HaircutBrother1
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox PalletTown_House2_Text_AllDone
	setflag FLAG_DAILY_DAISY_GROOMED
	release
	end

PalletTown_House2_Text_Hello:
	.string "MARGI: Ciao! Mio fratello minore è il\n"
	.string "CAPOPALESTRA di SMERALDOPOLI.\p"
	.string "Ma va fuori città così\n"
	.string "spesso che crea problemi\l"
	.string "agli allenatori.$"

PalletTown_House2_Text_OfferGrooming:
	.string "MARGI: Ciao! Che tempismo. Sto per\n"
	.string "prendere un tè.\p"
	.string "Vuoi unirti a me?\p"
	.string "Oh, i tuoi POKéMON sono un po' sporchi.\p"
	.string "Vuoi che ne lavi uno?$"

PalletTown_House2_Text_WhichMon:
	.string "MARGI: Quale devo lavare?$"

PalletTown_House2_Text_Alright:
	.string "MARGI: OK, lo farò diventare\n"
	.string "bello in un attimo.$"

PalletTown_House2_Text_AllDone:
	.string "MARGI: Ecco fatto! Tutto pronto.\p"
	.string "Visto? {STR_VAR_1} non è\n"
	.string "carino?\p"
	.string "È un POKéMON adorabile.$"

PalletTown_House2_Text_AlreadyGroomed:
	.string "MARGI: Prendo sempre il tè\n"
	.string "a quest'ora. Unisciti a me.$"

PalletTown_House2_Text_Refused:
	.string "MARGI: Non vuoi farne\n"
	.string "lavare uno?\p"
	.string "OK, prendiamo solo il tè.$"

PalletTown_House2_Text_CantGroomEgg:
	.string "MARGI: Oh, scusa. Non posso\n"
	.string "davvero toelettare un UOVO.$"
