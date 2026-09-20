RuinsOfAlph_Outside_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RuinsOfAlph_Outside_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

RuinsOfAlph_Outside_OnTransition: 
	callnative SetTimeBasedEncounters
	end	

RuinsOfAlph_Outside_EventScript_Quagsire::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_QUAGSIRE, CRY_MODE_NORMAL
	msgbox RuinsOfAlph_Outside_Text_Quagsire, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RuinsOfAlph_Outside_Text_Quagsire:
	.string "QUAGSIRE: Quag Quag$"

RuinsOfAlph_Outside_EventScript_Stan::
	trainerbattle_single TRAINER_STAN_HNS, RuinsOfAlph_Outside_Text_SuperNerdStan_Seen, RuinsOfAlph_Outside_Text_SuperNerdStan_Beaten
	msgbox RuinsOfAlph_Outside_Text_SuperNerdStan_After, MSGBOX_AUTOCLOSE
	end

RuinsOfAlph_Outside_EventScript_Nathan::
	trainerbattle_single TRAINER_NATHAN_HNS, RuinsOfAlph_Outside_Text_PsychicNathan_Seen, RuinsOfAlph_Outside_Text_PsychicNathan_Beaten
	msgbox RuinsOfAlph_Outside_Text_PsychicNathan_After, MSGBOX_AUTOCLOSE
	end

RuinsOfAlph_Outside_EventScript_Youngster1::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Youngster1, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Youngster2::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Youngster2, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Fisher1::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Fisher1, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Fisher2::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Fisher2, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign1::
	lock
	msgbox RuinsOfAlph_Outside_Text_MainSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign2::
	lock
	msgbox RuinsOfAlph_Outside_Text_ResearchSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign3::
	lock
	msgbox RuinsOfAlph_Outside_Text_MysteryChamberSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_Text_Scientist:
	.string "Hm? Quello è un POKéDEX, no?\n"
	.string "Posso vederlo?\p"
	.string "Ci sono tante specie di\n"
	.string "POKéMON.\p"
	.string "Hm? Cos'è questo?\p"
	.string "Che POKéMON è?\p"
	.string "Sembra la strana\n"
	.string "scrittura sui muri delle\p"
	.string "ROVINE.\p"
	.string "Se quei disegni sono davvero\n"
	.string "POKéMON, ce ne devono essere\n"
	.string "altri.\p"
	.string "Ci sono! Ti aggiorno il\n"
	.string "POKéDEX. Seguimi.$"

RuinsOfAlph_Outside_Text_SuperNerdStan_Seen:
	.string "Cosa vuoi? Sto studiando--\n"
	.string "non disturbarmi!$"

RuinsOfAlph_Outside_Text_SuperNerdStan_Beaten:
	.string "Scusa…\n"
	.string "Sono frustrato dalla nostra mancanza\p"
	.string "di vera comprensione…$"

RuinsOfAlph_Outside_Text_SuperNerdStan_After:
	.string "Le ROVINE risalgono a circa 1500\n"
	.string "anni fa.\p"
	.string "Nessuno sa chi le abbia costruite.\p"
	.string "Non si sa se le statue di POKéMON\n"
	.string "abbiano un significato.\p"
	.string "È tutto un grande mistero…$"

RuinsOfAlph_Outside_Text_PsychicNathan_Seen:
	.string "Mmmh… Che posto strano.$"

RuinsOfAlph_Outside_Text_PsychicNathan_Beaten:
	.string "…$"

RuinsOfAlph_Outside_Text_PsychicNathan_After:
	.string "Mi piace pensare qui.$"

RuinsOfAlph_Outside_Text_MysteryChamberSign:
	.string "SALA DELLA PIETRA MISTERIOSA$"

RuinsOfAlph_Outside_Text_MainSign:
	.string "RUINS OF ALPH\n"
	.string "VISITATORI BENVENUTI$"

RuinsOfAlph_Outside_Text_ResearchSign:
	.string "CENTRO RICERCHE ROVINE D'ALFA\p"
	.string "AUTORITÀ SULLE\n"
	.string "ROVINE D'ALFA$"

RuinsOfAlph_Outside_Text_Fisher1:
	.string "Mentre esploravamo le RUINS,\n"
	.string "abbiamo notato un' strana presenza.\p"
	.string "Ci siamo spaventati e siamo scappati.\n"
	.string "Anche tu dovresti stare attento.$"

RuinsOfAlph_Outside_Text_Fisher2:
	.string "Le RUINS nascondono un enorme segreto!\p"
	.string "…Credo…$"

RuinsOfAlph_Outside_Text_Youngster1:
	.string "Ci sono tanti tipi di UNOWN, così\n"
	.string "li usiamo per i nostri codici segreti.$"

RuinsOfAlph_Outside_Text_Youngster2:
	.string "A… H… E… A… D… Mmmh…\p"
	.string "Cosa?\p"
	.string "Sto decifrando questo messaggio!$"
