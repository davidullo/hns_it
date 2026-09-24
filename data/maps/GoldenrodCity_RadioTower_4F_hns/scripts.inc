GoldenrodCity_RadioTower_4F_hns_MapScripts::
	.byte 0

GoldenrodCity_RadioTower_4F4_EventScript_Sign1::
	lock
	msgbox GoldenrodCity_RadioTower_4F4_Text_Studio2Sign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Sign2::
	lock
	msgbox GoldenrodCity_RadioTower_4F4_Text_ProductionSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodRaidoTower4_EventScript_Grunt28::
	trainerbattle_single TRAINER_GRUNT_28_HNS, GoldenrodCity_RadioTower_4F4_Text_GruntF4Seen, GoldenrodCity_RadioTower_4F4_Text_GruntF4Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_GruntF4After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower4_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_9_HNS, GoldenrodCity_RadioTower_4F4_Text_GruntM10Seen, GoldenrodCity_RadioTower_4F4_Text_GruntM10Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_GruntM10After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower4_EventScript_Proton::
	trainerbattle_single TRAINER_PROTON_2_HNS, GoldenrodCity_RadioTower_4F4_Text_Proton_Seen, GoldenrodCity_RadioTower_4F4_Text_Proton_Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_Proton_After, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_4F4_EventScript_Fisher::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_4F4_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Scientist::
	trainerbattle_single TRAINER_RICH_HNS, GoldenrodCity_RadioTower_4F4_Text_ScientistRichSeen, GoldenrodCity_RadioTower_4F4_Text_ScientistRichBeaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_ScientistRichAfter, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_4F4_EventScript_Mary::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 7, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 8, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 9, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_unset FLAG_GOT_MARY_BRIGHT_POWDER, GoldenrodCity_RadioTower_4F4_EventScript_Mary3
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMaryAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Mary2::
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMary, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Mary3::
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMaryCleared, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_BRIGHT_POWDER
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMaryPinkBow, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_GOT_MARY_BRIGHT_POWDER
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Meowth::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MEOWTH, CRY_MODE_NORMAL
	msgbox GoldenrodCity_RadioTower_4F4_Text_Meowth, MSGBOX_DEFAULT
	waitmoncry
	release
	end


GoldenrodCity_RadioTower_4F4_Text_Proton_Seen:
	.string "MILAS: Aspetta un attimo!\p"
	.string "Non sei quello che ci ha\n"
	.string "intralciato al POZZO SLOWPOKE?\p"
	.string "Capisco… Fai tutto questo\n"
	.string "per farmi arrabbiare.\l"
	.string "Attento!\p"
	.string "Ma visto che lo Desideri, ti\n"
	.string "mostro tutta l'ira di un\l"
	.string "DIRIGENTE del TEAM ROCKET!$"

GoldenrodCity_RadioTower_4F4_Text_Proton_Beaten:
	.string "Fiuuu…$"

GoldenrodCity_RadioTower_4F4_Text_Proton_After:
	.string "MILAS: Stavolta hai vinto…\n"
	.string "Ma hai solo fatto crescere\p"
	.string "l'ira del TEAM ROCKET.$"

GoldenrodCity_RadioTower_4F4_Text_Fisher:
	.string "Ascoltavo la radio mentre ero\n"
	.string "alle ROVINE.\p"
	.string "Ho sentito una strana trasmissione.$"

GoldenrodCity_RadioTower_4F4_Text_DJMary:
	.string "MARY: Perché? Perché devo\n"
	.string "soffrire così?\p"
	.string "MEOWTH, aiutami!$"

GoldenrodCity_RadioTower_4F4_Text_DJMaryCleared:
	.string "MARY: Oh! Il mio piccolo eroe!\p"
	.string "Accetti questo come ringraziamento?$"

GoldenrodCity_RadioTower_4F4_Text_DJMaryPinkBow:
	.string "MARY: Serve a schivare gli\n"
	.string "attacchi del nemico.$"

GoldenrodCity_RadioTower_4F4_Text_DJMaryAfter:
	.string "MARY: Sintonizzati sulla mia\n"
	.string "POKéMON TALK del PROF. OAK!$"

GoldenrodCity_RadioTower_4F4_Text_Meowth:
	.string "MEOWTH: Meowth…$"

GoldenrodCity_RadioTower_4F4_Text_GruntM10Seen:
	.string "Vuoi salvare il DIRETTORE?\p"
	.string "Impossibile, perché\n"
	.string "ti batterò!$"

GoldenrodCity_RadioTower_4F4_Text_GruntM10Beaten:
	.string "No! Incredibile!$"

GoldenrodCity_RadioTower_4F4_Text_GruntM10After:
	.string "Non ci credo! Mi hai battuto!$"

GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2Seen:
	.string "Fermo! Sono la fortezza del\n"
	.string "TEAM ROCKET!\p"
	.string "Non farai un altro passo!$"

GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2Beaten:
	.string "La fortezza è caduta!$"

GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2After:
	.string "Ti sei guadagnato il mio rispetto:\n"
	.string "un consiglio.\p"
	.string "Non è troppo tardi. Puoi ancora\n"
	.string "tornare indietro.$"

GoldenrodCity_RadioTower_4F4_Text_GruntF4Seen:
	.string "POKéMON carini? Io li amo…\p"
	.string "I miei saranno carini\p"
	.string "dopo aver battuto i tuoi…$"

GoldenrodCity_RadioTower_4F4_Text_GruntF4Beaten:
	.string "Oh, no! Sono inutili!$"

GoldenrodCity_RadioTower_4F4_Text_GruntF4After:
	.string "Amo la mia bellezza!\p"
	.string "Chi se ne importa dei POKéMON?$"

GoldenrodCity_RadioTower_4F4_Text_ScientistRichSeen:
	.string "Eccellente.\p"
	.string "Questa TORRE RADIO realizzerà\n"
	.string "il nostro grande piano.$"

GoldenrodCity_RadioTower_4F4_Text_ScientistRichBeaten:
	.string "Hmmm…\p"
	.string "Ogni gran piano ha intoppi.$"

GoldenrodCity_RadioTower_4F4_Text_ScientistRichAfter:
	.string "Credi davvero di poter fermare\n"
	.string "il TEAM ROCKET?$"

GoldenrodCity_RadioTower_4F4_Text_ProductionSign:
	.string "PRODUZIONE 4P$"

GoldenrodCity_RadioTower_4F4_Text_Studio2Sign:
	.string "STUDIO 2, 4P$"
