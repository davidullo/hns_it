Route31_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route31_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route31_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route31_EventScript_Bugcatcher_Wade::
	trainerbattle_single TRAINER_WADE_HNS, Route31_Text_BugCatcherWade1_Seen, Route31_Text_BugCatcherWade1_Beaten, Route31_EventScript_RegisterWade
	goto_if_set FLAG_WADE_HAS_ITEM_HNS, Route31_EventScript_WadeGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route31_EventScript_RematchWade
	msgbox Route31_Text_BugCatcherWade1_After, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_RegisterWade::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route31_Text_WadeRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_WADE_HNS
	release
	end

Route31_EventScript_RematchWade::
	trainerbattle_rematch TRAINER_WADE_HNS, Route31_Text_WadeRematchIntro, Route31_Text_WadeRematchDefeat
	msgbox Route31_Text_WadePostRematch, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_WadeGiveItem::
	msgbox Route31_Text_WadeHasItem, MSGBOX_DEFAULT
	giveitem VAR_WADE_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route31_EventScript_WadeNoRoom
	clearflag FLAG_WADE_HAS_ITEM_HNS
	msgbox Route31_Text_WadeGaveItem, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_WadeNoRoom::
	msgbox Route31_Text_WadeNoRoom, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route31_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan::
	lock
	faceplayer
	goto_if_eq VAR_KENYA, 1, Route31_EventScript_SleepyMan_AskForKenya
	msgbox Route31_Text_SleepyMan, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan_AskForKenya::
	msgbox Route31_Text_SleepyManGotMail, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route31_EventScript_SleepyMan_GiveKenya
	msgbox Route31_Text_SleepyManFail, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan_GiveKenya::
	removenamedmon 1
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Route31_EventScript_SleepyMan_Fail
	msgbox Route31_Text_HandOverMailMon, MSGBOX_DEFAULT
	delay 55
	callnative UpdateFollowingPokemon
	msgbox Route31_Text_ReadingMail, MSGBOX_DEFAULT
	giveitem ITEM_TM_REST
	msgbox Route31_Text_DescribeRest, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KENYA, 2
	release
	end

Route31_EventScript_SleepyMan_Fail::
	msgbox Route31_Text_SleepyManFail, MSGBOX_DEFAULT
	release
	end


Route31_EventScript_Boy::
	lock
	faceplayer
	msgbox Route31_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_DarkCaveSign::
	lock
	msgbox Route31_Text_DarkCaveSign, MSGBOX_SIGN
	closemessage
	release
	end

Route31_EventScript_Sign::
	lock
	msgbox Route31_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route31_EventScript_ItemPokeBall::
	finditem ITEM_POKE_BALL
	end

Route31_EventScript_ItemAntidote::
	finditem ITEM_ANTIDOTE
	end

Route31_Text_CooltrainerM:
	.string "GROTTA BUIO…\p"
	.string "Se i POKéMON la illuminassero,\n"
	.string "la esplorerei.$"

Route31_Text_BugCatcherWade1_Seen:
	.string "Ho preso un sacco di POKéMON.\n"
	.string "Lottiamo insieme!$"

Route31_Text_BugCatcherWade1_Beaten:
	.string "Noooooo…$"

Route31_Text_BugCatcherWade1_After:
	.string "Puoi catturare POKéMON anche se\n"
	.string "ne hai già sei con te.\p"
	.string "Se ne catturi uno, va nel tuo\n"
	.string "BOX automaticamente.$"

Route31_Text_SleepyMan:
	.string "… Hnuurg… Eh?\p"
	.string "Oggi ho camminato troppo cercando\n"
	.string "dei POKéMON.\p"
	.string "Ho i piedi doloranti e sonno…\p"
	.string "Se fossi un POKéMON selvatico,\n"
	.string "sarei facile da catturare…\p"
	.string "…Zzzz…$"

Route31_Text_SleepyManGotMail:
	.string "…Zzzz… Eh?\p"
	.string "Cos'è? Hai una LETTERA\n"
	.string "per me?$"

Route31_Text_SleepyManFail:
	.string "…Zzzz…$"

Route31_Text_HandOverMailMon:
	.string "{PLAYER} ha consegnato il\n"
	.string "POKéMON con la LETTERA.$"

Route31_Text_ReadingMail:
	.string "Vediamo…\p"
	.string "Grazie per avermela\n"
	.string "portata.\p"
	.string "Il mio amico è un bravo tipo, e\n"
	.string "anche tu sei in gamba!\p"
	.string "Vorrei fare qualcosa di buono\n"
	.string "anch'io in cambio!\p"
	.string "Lo so! Voglio che tu abbia\n"
	.string "questo!$"

Route31_Text_DescribeRest:
	.string "...Zzz...\p"
	.string "...Umm... Riposo!\p"
	.string "La frase 'riprendersi in fretta' è\n"
	.string "stata abbreviata in 'Riposo', sai?\p"
	.string "È una mossa che fa dormire e\n"
	.string "recuperare PS.$"

Route31_Text_WrongMail:
	.string "Questa LETTERA non è per me.$"

Route31_Text_MissingMail:
	.string "Perché è così speciale?\p"
	.string "Non ha nessuna LETTERA.$"

Route31_Text_DeclinedToHandOverMail:
	.string "Come? Non vuoi\n"
	.string "niente?$"

Route31_Text_CantTakeLastMon:
	.string "Se ti prendo quel POKéMON,\n"
	.string "cosa\p"
	.string "useresti in\n"
	.string "lotta?$"

Route31_Text_Youngster:
	.string "Ho trovato un POKéMON forte nella\n"
	.string "GROTTA BUIO.\p"
	.string "Lo alleverò per sfidare\n"
	.string "FALKNER.\p"
	.string "È il capo della PALESTRA di\n"
	.string "VIOLETTO.$"

Route31_Text_Sign:
	.string "PERCORSO 31\p"
	.string "VIOLETTO - CHERRYGROVE$"

Route31_Text_WadeRegister:
	.string "Sei fantastico! Mi piaci!\p"
	.string "Cerco POKéMON qui ogni\n"
	.string "giorno.\p"
	.string "Quando sono nell'erba, trovo\n"
	.string "un sacco di BACCHE.\p"
	.string "Se vuoi, te ne do\n"
	.string "alcune.$"

Route31_Text_WadeRematchIntro:
	.string "Ti stavo aspettando.\n"
	.string "Lottiamo!$"

Route31_Text_WadeRematchDefeat:
	.string "Noooooo…$"

Route31_Text_WadePostRematch:
	.string "Ti farò sapere appena\n"
	.string "trovo qualcosa che\l"
	.string "ti piaccia.$"

Route31_Text_WadeHasItem:
	.string "Ehi! Ti stavo\n"
	.string "cercando!\p"
	.string "Ho trovato una cosa mentre\n"
	.string "ero nell'erba.\p"
	.string "Tieni, prendila!$"

Route31_Text_WadeGaveItem:
	.string "Ti farò sapere se trovo\n"
	.string "altro!$"

Route31_Text_WadeNoRoom:
	.string "Hmm, la tua BORSA\n"
	.string "è piena.\p"
	.string "Torna quando hai\n"
	.string "spazio!$"

Route31_Text_DarkCaveSign:
	.string "GROTTA BUIO$"
