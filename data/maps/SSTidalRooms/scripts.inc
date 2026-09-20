SSTidalRooms_MapScripts::
	.byte 0

SSTidalRooms_EventScript_SnatchGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_SNATCH, SSTidalRooms_EventScript_ExplainSnatch
	msgbox SSTidalRooms_Text_NotSuspiciousTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_SNATCH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SNATCH
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_ExplainSnatch::
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_Bed::
	lockall
	msgbox SSTidalRooms_Text_TakeRestOnBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	call SSTidalRooms_EventScript_ProgessCruiseAfterBed
	releaseall
	end

SSTidalRooms_EventScript_Colton::
	trainerbattle_single TRAINER_COLTON, SSTidalRooms_Text_ColtonIntro, SSTidalRooms_Text_ColtonDefeat
	msgbox SSTidalRooms_Text_ColtonPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Micah::
	trainerbattle_single TRAINER_MICAH, SSTidalRooms_Text_MicahIntro, SSTidalRooms_Text_MicahDefeat
	msgbox SSTidalRooms_Text_MicahPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Thomas::
	trainerbattle_single TRAINER_THOMAS, SSTidalRooms_Text_ThomasIntro, SSTidalRooms_Text_ThomasDefeat
	msgbox SSTidalRooms_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Jed::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_JedIntro, SSTidalRooms_Text_JedDefeat, SSTidalRooms_Text_JedNotEnoughMons
	msgbox SSTidalRooms_Text_JedPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Lea::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_LeaIntro, SSTidalRooms_Text_LeaDefeat, SSTidalRooms_Text_LeaNotEnoughMons
	msgbox SSTidalRooms_Text_LeaPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Garret::
	trainerbattle_single TRAINER_GARRET, SSTidalRooms_Text_GarretIntro, SSTidalRooms_Text_GarretDefeat
	msgbox SSTidalRooms_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Naomi::
	trainerbattle_single TRAINER_NAOMI, SSTidalRooms_Text_NaomiIntro, SSTidalRooms_Text_NaomiDefeat
	msgbox SSTidalRooms_Text_NaomiPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_Text_TakeRestOnBed:
	.string "C'è un letto…\n"
	.string "Riposiamoci un po'.$"

SSTidalRooms_Text_ColtonIntro:
	.string "Vado spesso a LILYCOVE.\p"
	.string "Mi piace partecipare alle GARE,\n"
	.string "sai.$"

SSTidalRooms_Text_ColtonDefeat:
	.string "Che bella lotta!$"

SSTidalRooms_Text_ColtonPostBattle:
	.string "Mi emoziono immaginando che tipi\n"
	.string "di POKéMON vedrò alla prossima\l"
	.string "GARA. Il Presagio mi entusiasma!$"

SSTidalRooms_Text_MicahIntro:
	.string "I tuoi amici sono forti?$"

SSTidalRooms_Text_MicahDefeat:
	.string "I tuoi amici sono davvero forti.$"

SSTidalRooms_Text_MicahPostBattle:
	.string "Gli amici non devono essere umani.\n"
	.string "Per me i POKéMON sono amici preziosi!$"

SSTidalRooms_Text_ThomasIntro:
	.string "Ragazzo…\n"
	.string "Hai bussato alla porta?$"

SSTidalRooms_Text_ThomasDefeat:
	.string "Una sconfitta va accettata senza fretta\n"
	.string "né panico.$"

SSTidalRooms_Text_ThomasPostBattle:
	.string "Mai perdere la calma in ogni situazione:\n"
	.string "è il codice del GENTLEMAN.$"

SSTidalRooms_Text_JedIntro:
	.string "JED: Mi imbarazza un po', ma…\n"
	.string "Ti mostreremo la nostra forza amorosa!$"

SSTidalRooms_Text_JedDefeat:
	.string "JED: Uff…$"

SSTidalRooms_Text_JedPostBattle:
	.string "JED: È la prima volta che la nostra\n"
	.string "forza amorosa non prevale!\l"
	.string "Devi essere un allenatore forte!$"

SSTidalRooms_Text_JedNotEnoughMons:
	.string "JED: Hai un solo POKéMON?\n"
	.string "Non ti senti troppo solo?$"

SSTidalRooms_Text_LeaIntro:
	.string "LEA: Mi sento un po' sciocca, ma…\n"
	.string "Ti mostreremo la nostra forza amorosa!$"

SSTidalRooms_Text_LeaDefeat:
	.string "LEA: Oh, che noia!$"

SSTidalRooms_Text_LeaPostBattle:
	.string "LEA: Non ci credo!\n"
	.string "La nostra forza amorosa ha fallito…\l"
	.string "Devi essere un allenatore forte!$"

SSTidalRooms_Text_LeaNotEnoughMons:
	.string "LEA: Volevo lottare…\n"
	.string "Ma non hai nemmeno due POKéMON…$"

SSTidalRooms_Text_GarretIntro:
	.string "Ah, sei arrivato giusto in tempo.\p"
	.string "Sai, mi annoio.\n"
	.string "Puoi divertirmi un po'.$"

SSTidalRooms_Text_GarretDefeat:
	.string "…Può bastare.$"

SSTidalRooms_Text_GarretPostBattle:
	.string "Forse chiederò a papà di comprarmi\n"
	.string "uno yacht.\l"
	.string "Uno yacht per me e i POKéMON!$"

SSTidalRooms_Text_NaomiIntro:
	.string "Oh, sei un allenatore adorabile.\n"
	.string "Ti va di bere un tè?\l"
	.string "O preferisci lottare?$"

SSTidalRooms_Text_NaomiDefeat:
	.string "Capisco.\n"
	.string "Sei il tipo attivo.$"

SSTidalRooms_Text_NaomiPostBattle:
	.string "Una crociera su un transatlantico ha il\n"
	.string "suo fascino, devo dire…\p"
	.string "Ma ammetto che c'è un lato allettante\n"
	.string "nel girare HOENN in traghetto.$"

SSTidalRooms_Text_NotSuspiciousTakeThis:
	.string "Uh… Ciao! Io… non sono sospetto!\n"
	.string "Uh… Puoi prenderlo! Gratis!\p"
	.string "Io… Davvero, non l'ho rubato a\n"
	.string "nessuno! Non farei mai una cosa così!\l"
	.string "È pulito! Puoi usarlo!$"

SSTidalRooms_Text_ExplainSnatch:
	.string "Scippo ruba gli effetti positivi\n"
	.string "di certe mosse prima che le usi\l"
	.string "un nemico o un alleato.$"

