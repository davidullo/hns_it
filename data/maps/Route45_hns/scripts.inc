Route45_hns_MapScripts::
	.byte 0

Route45_EventScript_Erik::
	trainerbattle_single TRAINER_ERIK_HNS, Route45_Text_HikerErikSeen, Route45_Text_HikerErikBeaten
	msgbox Route45_Text_HikerErikAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Michael::
	trainerbattle_single TRAINER_MICHAEL_HNS, Route45_Text_HikerMichaelSeen, Route45_Text_HikerMichaelBeaten
	msgbox Route45_Text_HikerMichaelAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Parry::
	trainerbattle_single TRAINER_PARRY_HNS, Route45_Text_HikerParrySeen, Route45_Text_HikerParryBeaten, Route45_EventScript_RegisterParry
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route45_EventScript_RematchParry
	msgbox Route45_Text_HikerParryAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_RegisterParry::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route45_Text_ParryRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_PARRY_HNS
	release
	end

Route45_EventScript_RematchParry::
	trainerbattle_rematch TRAINER_PARRY_HNS, Route45_Text_ParryRematchIntro, Route45_Text_ParryRematchDefeat
	msgbox Route45_Text_ParryPostRematch, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Timothy::
	trainerbattle_single TRAINER_TIMOTHY_HNS, Route45_Text_HikerTimothySeen, Route45_Text_HikerTimothyBeaten
	msgbox Route45_Text_HikerTimothyAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Kenji::
	trainerbattle_single TRAINER_KENJI_HNS, Route45_Text_BlackbeltKenjiSeen, Route45_Text_BlackbeltKenjiBeaten, Route45_EventScript_RegisterKenji
	goto_if_set FLAG_KENJI_HAS_ITEM_HNS, Route45_EventScript_KenjiGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route45_EventScript_RematchKenji
	msgbox Route45_Text_BlackbeltKenjiAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_RegisterKenji::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route45_Text_KenjiRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KENJI_HNS
	release
	end

Route45_EventScript_RematchKenji::
	trainerbattle_rematch TRAINER_KENJI_HNS, Route45_Text_KenjiRematchIntro, Route45_Text_KenjiRematchDefeat
	msgbox Route45_Text_KenjiPostRematch, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_KenjiGiveItem::
	msgbox Route45_Text_KenjiHasItem, MSGBOX_DEFAULT
	giveitem VAR_KENJI_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route45_EventScript_KenjiNoRoom
	clearflag FLAG_KENJI_HAS_ITEM_HNS
	msgbox Route45_Text_KenjiGaveItem, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_KenjiNoRoom::
	msgbox Route45_Text_KenjiNoRoom, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Ryan::
	trainerbattle_single TRAINER_RYAN_HNS, Route45_Text_CooltrainermRyanSeen, Route45_Text_CooltrainermRyanBeaten
	msgbox Route45_Text_CooltrainermRyanAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Kelly::
	trainerbattle_single TRAINER_KELLY_HNS, Route45_Text_CooltrainerfKellySeen, Route45_Text_CooltrainerfKellyBeaten
	msgbox Route45_Text_CooltrainerfKellyAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Quentin::
	trainerbattle_single TRAINER_QUENTIN_HNS, Route45_Text_CamperQuentinSeen, Route45_Text_CamperQuentinBeaten
	msgbox Route45_Text_CamperQuentinAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Sign::
	msgbox Route45_Text_Sign, MSGBOX_SIGN
	end

Route45_EventScript_Item_Elixir::
	finditem ITEM_ELIXIR
	end

Route45_EventScript_Item_Max_Potion::
	finditem ITEM_MAX_POTION
	end

Route45_EventScript_Item_Full_Heal::
	finditem ITEM_FULL_HEAL
	end

Route45_EventScript_Item_Nugget::
	finditem ITEM_NUGGET
	end

Route45_Text_HikerErikSeen:
    .string "Preparati a tutto!\p"
    .string "Vediamo se i tuoi POKéMON\n"
    .string "sono cresciuti bene!$"

Route45_Text_HikerErikBeaten:
    .string "Oh, ho perso!$"

Route45_Text_HikerErikAfter:
    .string "Torno alla GROTTA GHIACCIO\n"
    .string "di BORGOFRANCO ad allenarmi.$"

Route45_Text_HikerMichaelSeen:
    .string "Ehi! Hai grinta! Ma sai\n"
    .string "una cosa?\p"
    .string "Quanto a grinta\n"
    .string "pura, il re sono io!$"

Route45_Text_HikerMichaelBeaten:
    .string "I miei POKéMON erano troppo deboli!$"

Route45_Text_HikerMichaelAfter:
    .string "Come amo gli HP UP! Mmm, che buoni!\p"
    .string "Continuo a bere quelli dei POKéMON!\p"
    .string "Non resisto!$"

Route45_Text_HikerParrySeen:
    .string "I miei POKéMON sono pieni di potenza!$"

Route45_Text_HikerParryBeaten:
    .string "Wahahah! Sono il gran perdente!$"

Route45_Text_HikerParryAfter:
    .string "Non sono bravo a pensare,\n"
    .string "vedi?\p"
    .string "Quindi vado avanti di potenza!$"

Route45_Text_ParryRegister:
    .string "Non sono bravo a pensare,\n"
    .string "vedi?\p"
    .string "Quindi vado avanti di potenza!$"

Route45_Text_ParryRematchIntro:
    .string "I miei POKéMON sono pieni di potenza!$"

Route45_Text_ParryRematchDefeat:
    .string "Wahahah! Sono il gran perdente!$"

Route45_Text_ParryPostRematch:
    .string "Non sono bravo a pensare,\n"
    .string "vedi?\p"
    .string "Quindi vado avanti di potenza!$"

Route45_Text_HikerTimothySeen:
    .string "Perché scalò le montagne?\p"
    .string "Perché ci sono.\p"
    .string "Perché alleno POKéMON?\p"
    .string "Perché ci sono!$"

Route45_Text_HikerTimothyBeaten:
    .string "Le sconfitte… Ci sono anche quelle!$"

Route45_Text_HikerTimothyAfter:
    .string "La cosa più bella che mi sia\n"
    .string "capitata è scoprire i POKéMON.$"

Route45_Text_HikerParryGivesIron:
    .string "Non riesco proprio a vincere!\p"
    .string "Continua così!\p"
    .string "Oh, e prendi questo, è il\n"
    .string "regalo che non hai potuto\n"
    .string "prendere l'altra volta.$"

Route45_Text_BlackbeltKenjiSeen:
    .string "Mi allenavo qui da solo.\p"
    .string "Ammira i frutti del mio lavoro!$"

Route45_Text_BlackbeltKenjiBeaten:
    .string "Waaaargh!$"

Route45_Text_BlackbeltKenjiAfter:
    .string "Ci vogliono misure estreme.\p"
    .string "Devo andare sui monti ad\n"
    .string "allenarmi in solitudine.$"

Route45_Text_KenjiRegister:
    .string "Ci vogliono misure estreme.\p"
    .string "Devo andare sui monti ad\n"
    .string "allenarmi in solitudine.$"

Route45_Text_KenjiRematchIntro:
    .string "Mi allenavo qui da solo.\p"
    .string "Ammira i frutti del mio lavoro!$"

Route45_Text_KenjiRematchDefeat:
    .string "Waaaargh!$"

Route45_Text_KenjiPostRematch:
    .string "Ci vogliono misure estreme.\p"
    .string "Devo andare sui monti ad\n"
    .string "allenarmi in solitudine.$"

Route45_Text_KenjiHasItem:
    .string "Ehi! Mi sto riposando\n"
    .string "dall'allenamento.\p"
    .string "Ho trovato una cosa buona in giro.\n"
    .string "Tieni, prendila!$"

Route45_Text_KenjiGaveItem:
    .string "Usalo bene!\p"
    .string "Devo tornare ad\n"
    .string "allenarmi. Oooooaaarrrgh!$"

Route45_Text_KenjiNoRoom:
    .string "Hmm, la tua BORSA è piena.\p"
    .string "Torna quando avrai spazio.$"

Route45_Text_BlackbeltKenjiMorning:
    .string "Mi alleno ancora un po'\n"
    .string "prima della pausa pranzo.$"

Route45_Text_BlackbeltKenjiNight:
    .string "Ci siamo riposati a pranzo, quindi\p"
    .string "ora siamo pronti a ripartire!\p"
    .string "Ci alleniamo di nuovo!$"

Route45_Text_CooltrainermRyanSeen:
    .string "Cosa pensi dell'allenare\n"
    .string "i POKéMON?$"

Route45_Text_CooltrainermRyanBeaten:
    .string "Ti sei guadagnato il mio rispetto.$"

Route45_Text_CooltrainermRyanAfter:
    .string "Vedo che allevi i POKéMON\n"
    .string "con cura.\p"
    .string "Il legame che crei ti salverà\n"
    .string "nei momenti difficili.$"

Route45_Text_CooltrainerfKellySeen:
    .string "Qual è la tua strategia?\p"
    .string "È sciocco usare mosse forti\n"
    .string "alla cieca.$"

Route45_Text_CooltrainerfKellyBeaten:
    .string "Va bene. Ho perso.$"

Route45_Text_CooltrainerfKellyAfter:
    .string "Non amo le mosse troppo\n"
    .string "potenti.\p"
    .string "Voglio vincere, ma non voglio\n"
    .string "far male ai POKéMON.$"

Route45_Text_CamperQuentinSeen:
    .string "Sono davvero, davvero forte!$"

Route45_Text_CamperQuentinBeaten:
    .string "Alla COLLINA ALLENATORI ero forte…$"

Route45_Text_CamperQuentinAfter:
    .string "Sei stato alla COLLINA ALLENATORI?\p"
    .string "Io non perdo mai lì, ma…$"

Route45_Text_Sign:
    .string "PERCORSO 45\n"
    .string "STRADA MONTANA AVANTI$"
