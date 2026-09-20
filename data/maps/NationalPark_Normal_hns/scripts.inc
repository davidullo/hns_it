NationalPark_Normal_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NationalPark_Normal_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

NationalPark_Normal_OnTransition: 
	callnative SetTimeBasedEncounters
	end

NationalPark_Normal_EventScript_Lass::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Youngster1::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Youngster1, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Youngster2::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Youngster2, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Teacher2::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Teacher2, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	release
	end

NationalPark_Normal_EventScript_TeacherQuickclaw::
	lock
	faceplayer
	goto_if_set FLAG_GOT_QUICK_CLAW, NationalPark_Normal_EventScript_TeacherQuickclaw2
	msgbox NationalPark_Normal_Text_Teacher1, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_GOT_QUICK_CLAW
NationalPark_Normal_EventScript_TeacherQuickclaw2::
	msgbox NationalPark_Normal_Text_Teacher1_QuickClaw, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Persian::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PERSIAN, CRY_MODE_NORMAL
	msgbox NationalPark_Normal_Text_Persian, MSGBOX_DEFAULT
	waitmoncry
	release
	end



NationalPark_Normal_Text_Lass:
	.string "Guarda! Che bella borsa!\p"
	.string "Ho stampato i miei preferiti dal\n"
	.string "POKéDEX e li ho attaccati qui.$"

NationalPark_Normal_Text_PokefanF:
	.string "Questa è una LETTERA di mia figlia.\n"
	.string "Mi tira su il morale.$"

NationalPark_Normal_Text_Teacher1:
	.string "Attenti, per favore!\p"
	.string "…Ops, non posso pensare sempre\n"
	.string "come una maestra.\p"
	.string "Devi essere un allenatore.\p"
	.string "Dato che ti impegni tanto,\n"
	.string "voglio darti questo.$"

NationalPark_Normal_Text_Teacher1_QuickClaw:
	.string "Fai tenere a un POKéMON lo\p"
	.string "ARTIGLIO VELOCE. A volte colpirà\n"
	.string "per primo in lotta.$"

NationalPark_Normal_Text_Youngster1:
	.string "Gioco con gli adesivi che ho stampato\n"
	.string "dal POKéDEX.$"

NationalPark_Normal_Text_Youngster2:
	.string "Se vinco, prendo l'adesivo del\n"
	.string "POKéDEX dell'altro.$"

NationalPark_Normal_Text_Teacher2:
	.string "Passeggio nel PARCO, ma non\n"
	.string "vado mai nell'erba.\p"
	.string "Gli allenatori vogliono sempre lottare…\p"
	.string "Avrai fatto molte lotte.\n"
	.string "Lascia che curi i tuoi POKéMON.$"

NationalPark_Normal_Text_Persian:
	.string "PERSIAN: Fssshaa!$"

NationalPark_Normal_EventScript_Jack::
	trainerbattle_single TRAINER_JACK_HNS, NationalPark_Normal_Text_SchoolboyJack1_Seen, NationalPark_Normal_Text_SchoolboyJack1_Beaten, NationalPark_Normal_EventScript_RegisterJack
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, NationalPark_Normal_EventScript_RematchJack
	msgbox NationalPark_Normal_Text_SchoolboyJack_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_RegisterJack::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox NationalPark_Normal_Text_JackRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JACK_HNS
	release
	end

NationalPark_Normal_EventScript_RematchJack::
	trainerbattle_rematch TRAINER_JACK_HNS, NationalPark_Normal_Text_JackRematchIntro, NationalPark_Normal_Text_JackRematchDefeat
	msgbox NationalPark_Normal_Text_JackPostRematch, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_Beverly::
	trainerbattle_single TRAINER_BEVERLY_HNS, NationalPark_Normal_Text_PokefanFBeverly1_Seen, NationalPark_Normal_Text_PokefanFBeverly1_Beaten, NationalPark_Normal_EventScript_RegisterBeverly
	goto_if_set FLAG_BEVERLY_HAS_ITEM_HNS, NationalPark_Normal_EventScript_BeverlyGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, NationalPark_Normal_EventScript_RematchBeverly
	msgbox NationalPark_Normal_Text_PokefanFBeverly_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_RematchBeverly::
	trainerbattle_rematch TRAINER_BEVERLY_HNS, NationalPark_Normal_Text_PokefanFBeverly1_Seen, NationalPark_Normal_Text_PokefanFBeverly1_Beaten
	msgbox NationalPark_Normal_Text_PokefanFBeverly_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_RegisterBeverly::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox NationalPark_Normal_Text_BeverlyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BEVERLY_HNS
	release
	end

NationalPark_Normal_EventScript_BeverlyGiveItem::
	msgbox NationalPark_Normal_Text_BeverlyHasItem, MSGBOX_DEFAULT
	giveitem VAR_BEVERLY_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, NationalPark_Normal_EventScript_BeverlyNoRoom
	clearflag FLAG_BEVERLY_HAS_ITEM_HNS
	msgbox NationalPark_Normal_Text_BeverlyGaveItem, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_BeverlyNoRoom::
	msgbox NationalPark_Normal_Text_BeverlyNoRoom, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM_HNS, NationalPark_Normal_Text_PokefanmWilliam_Seen, NationalPark_Normal_Text_PokefanmWilliam_Beaten
	msgbox NationalPark_Normal_Text_PokefanmWilliam_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_Krise::
	trainerbattle_single TRAINER_KRISE_HNS, NationalPark_Normal_Text_LassKrise_Seen, NationalPark_Normal_Text_LassKrise_Beaten
	msgbox NationalPark_Normal_Text_LassKrise_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_TM_Dig::
	finditem ITEM_TM_DIG
	end

NationalPark_Normal_EventScript_Item_Soothe_Bell::
	finditem ITEM_SOOTHE_BELL
	end

NationalPark_Normal_Text_SchoolboyJack1_Seen:
	.string "Il mondo dei POKéMON è profondo.\p"
	.string "Ci sono ancora tante cose che\n"
	.string "non sappiamo.\p"
	.string "Ma io ne so più di te!$"

NationalPark_Normal_Text_SchoolboyJack1_Beaten:
	.string "Co-cosa-cosa?$"

NationalPark_Normal_Text_SchoolboyJack_After:
	.string "C'è tanto da imparare.\p"
	.string "Per esempio…\p"
	.string "Ci sono 92 tipi di MT.\p"
	.string "I POKéMON scambiati crescono prima.$"

NationalPark_Normal_Text_JackRegister:
	.string "C'è tanto da imparare.\p"
	.string "Per esempio…\p"
	.string "Ci sono 92 tipi di MT.\p"
	.string "I POKéMON scambiati crescono prima.$"

NationalPark_Normal_Text_JackRematchIntro:
	.string "Ho imparato molto dall'ultima\n"
	.string "volta! Forza, lottiamo!$"

NationalPark_Normal_Text_JackRematchDefeat:
	.string "Co-cosa-cosa?$"

NationalPark_Normal_Text_JackPostRematch:
	.string "C'è tanto da imparare.\p"
	.string "Per esempio…\p"
	.string "Ci sono 92 tipi di MT.\p"
	.string "I POKéMON scambiati crescono prima.$"

NationalPark_Normal_Text_PokefanFBeverly1_Seen:
	.string "I miei POKéMON sono adorabili.\p"
	.string "Ti dico quanto orgoglio mi\n"
	.string "danno i miei tesori.$"

NationalPark_Normal_Text_PokefanFBeverly1_Beaten:
	.string "Ti batto in orgoglio, ma…$"

NationalPark_Normal_Text_PokefanFBeverly_After:
	.string "Devo dire che i tuoi POKéMON sono\n"
	.string "proprio carini.$"

NationalPark_Normal_Text_PokefanmWilliam_Seen:
	.string "Adoriamo i nostri POKéMON, anche se\n"
	.string "non ci sopportano.\p"
	.string "Questo è essere FAN.$"

NationalPark_Normal_Text_PokefanmWilliam_Beaten:
	.string "I-i miei POKéMON!$"

NationalPark_Normal_Text_PokefanmWilliam_After:
	.string "Ho perso, ma i miei POKéMON vincono\n"
	.string "il premio di più belli.$"

NationalPark_Normal_Text_LassKrise_Seen:
	.string "Ehi? Perché mi fissi?\p"
	.string "Ah, una lotta?$"

NationalPark_Normal_Text_LassKrise_Beaten:
	.string "…Mmm…$"

NationalPark_Normal_Text_LassKrise_After:
	.string "Pensavo mi fissassi perché\n"
	.string "sono carina!$"

NationalPark_Normal_Text_Sign_RelaxationSquare:
	.string "ZONA RELAX\n"
	.string "PARCO NAZIONALE$"

NationalPark_Normal_Text_Sign_BattleNotice:
	.string "Che avviso è?\p"
	.string "Lottate solo nell'erba.\p"
	.string "UFFICIO GUARDIANO PARCO NAZIONALE$"

NationalPark_Normal_Text_TrainerTips:
	.string "CONSIGLI ALLENATORI\p"
	.string "Stampa la LETTERA aprendola e\n"
	.string "premendo START.$"

NationalPark_Normal_Text_BeverlyRegister:
	.string "Devo dire che i tuoi POKéMON sono\n"
	.string "proprio carini.$"

NationalPark_Normal_Text_BeverlyHasItem:
	.string "Oh, ciao! Ho qualcosa\n"
	.string "per te.\p"
	.string "Prendilo come segno della\n"
	.string "mia gratitudine!$"

NationalPark_Normal_Text_BeverlyGaveItem:
	.string "Io e il mio adorato POKéMON\n"
	.string "tiferemo per te!$"

NationalPark_Normal_Text_BeverlyNoRoom:
	.string "Hmm, la tua BORSA è piena.\p"
	.string "Torna quando avrai spazio.$"
