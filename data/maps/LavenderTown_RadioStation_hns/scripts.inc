LavenderTown_RadioStation_hns_MapScripts::
	.byte 0

LavenderTown_RadioStation_EventScript_Officer::
	msgbox LavenderTown_RadioStation_Text_Officer, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Receptionist::
	msgbox LavenderTown_RadioStation_Text_Receptionist, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_SuperNerd::
	msgbox LavenderTown_RadioStation_Text_SuperNerd1, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Director::
	lock
	faceplayer
	goto_if_set FLAG_KANTO_RADIO_GOT, LavenderTown_RadioStation_EventScript_DirectorGotRadio
	goto_if_set FLAG_RETURNED_MACHINE_PART, LavenderTown_RadioStation_EventScript_DirectorReturnedMachinePart
	msgbox LavenderTown_RadioStation_Text_Gentleman, MSGBOX_NPC
	end
LavenderTown_RadioStation_EventScript_DirectorReturnedMachinePart::
	msgbox LavenderTown_RadioStation_Text_Gentleman_ReturnedMachinePart, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	msgbox LavendertownRadioStation_Text_Upgraded_Radio, MSGBOX_DEFAULT
	waitfanfare
	msgbox LavenderTown_RadioStation_Text_Gentleman_GotExpnCard, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_KANTO_RADIO_GOT
	release
	end
LavenderTown_RadioStation_EventScript_DirectorGotRadio::	
	msgbox LavenderTown_RadioStation_Text_Gentleman_GotExpnCard, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Host::
	goto_if_set FLAG_KANTO_RADIO_GOT, LavenderTown_RadioStation_EventScript_Host2
	msgbox LavenderTown_RadioStation_Text_SuperNerd2, MSGBOX_NPC
	end
LavenderTown_RadioStation_EventScript_Host2::
	msgbox LavenderTown_RadioStation_Text_SuperNerd2_GotExpnCard, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Directory::
	msgbox LavenderTown_RadioStation_Text_Directory, MSGBOX_SIGN
	end
LavenderTown_RadioStation_EventScript_Sign::
	msgbox LavenderTown_RadioStation_Text_PokeFluteSign, MSGBOX_SIGN
	end
LavenderTown_RadioStation_EventScript_Library::
	msgbox LavenderTown_RadioStation_Text_ReferenceLibrary, MSGBOX_SIGN
	end

LavenderTown_RadioStation_Text_Receptionist:
	.string "Benvenuto! Guarda pure\n"
	.string "dove vuoi su questo piano.$"

LavenderTown_RadioStation_Text_Officer:
	.string "Scusa, puoi visitare solo il\n"
	.string "piano terra.\p"
	.string "Da quando la TORRE RADIO di JOHTO\n"
	.string "è stata presa da una banda di\l"
	.string "criminali, abbiamo dovuto\l"
	.string "aumentare la sicurezza.$"

LavenderTown_RadioStation_Text_SuperNerd1:
	.string "Molte persone lavorano sodo\n"
	.string "alla TORRE RADIO.\p"
	.string "Devono fare del loro meglio per\n"
	.string "creare bei programmi.$"

LavenderTown_RadioStation_Text_Gentleman:
	.string "Oh, no, no, no!\p"
	.string "Siamo fuori onda da quando\n"
	.string "la CENTRALE si è fermata.\p"
	.string "Tutti i miei sforzi per aprire\n"
	.string "questa radio sarebbero sprecati se\l"
	.string "non trasmetto.\p"
	.string "Sarei rovinato!$"

LavenderTown_RadioStation_Text_Gentleman_ReturnedMachinePart:
	.string "Ah! Sei il {PLAYER}\n"
	.string "che ha risolto il guaio?\p"
	.string "Grazie, non ho perso\n"
	.string "il posto.\p"
	.string "Mi hai proprio\n"
	.string "salvato!\p"
	.string "Prendi questo. Grazie.$"

LavendertownRadioStation_Text_Upgraded_Radio:
	.string "{PLAYER} ha ottenuto\n"
	.string "il RADIO UPGRADE!$"

LavenderTown_RadioStation_Text_Gentleman_GotExpnCard:
	.string "Con quello puoi sintonizzarti\n"
	.string "sui programmi radio qui a KANTO.\p"
	.string "Ahahahah!$"

LavenderTown_RadioStation_Text_SuperNerd2:
	.string "Ehi!\p"
	.string "Sono il super DIRETTORE MUSICALE!\p"
	.string "Eh? La tua RADIO non capta\n" @POKéGEAR
	.string "i miei programmi. Che peccato!\p"
	.string "Con un EXPANSION CARD\n"
	.string "puoi sintonizzarti. Faresti bene a\l"
	.string "prenderlo!$"

LavenderTown_RadioStation_Text_SuperNerd2_GotExpnCard:
	.string "Ehi!\p"
	.string "Sono il super DIRETTORE MUSICALE!\p"
	.string "Sono responsabile delle belle\n"
	.string "melodie che vanno in onda.\p"
	.string "Non fare il vecchio. Prendi la musica\n"
	.string "dall'etere!$"

LavenderTown_RadioStation_Text_Directory:
	.string "1P RECEPTION 2P VENDITE\p"
	.string "3P PERSONALE 4P PRODUZIONE\p"
	.string "5P UFFICIO DEL DIRETTORE$"

LavenderTown_RadioStation_Text_PokeFluteSign:
	.string "Rallegra i POKéMON con le dolci\n"
	.string "note del POKé FLAUTO su\l"
	.string "CANALE 20$"

LavenderTown_RadioStation_Text_ReferenceLibrary:
	.string "Wow! Uno scaffale pieno di CD\n"
	.string "e video POKéMON.\p"
	.string "Questa dev'essere la\n"
	.string "biblioteca.$"

