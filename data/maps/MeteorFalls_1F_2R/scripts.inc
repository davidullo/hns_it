MeteorFalls_1F_2R_MapScripts::
	.byte 0

MeteorFalls_1F_2R_EventScript_Nicolas::
	trainerbattle_single TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasIntro, MeteorFalls_1F_2R_Text_NicolasDefeat, MeteorFalls_1F_2R_EventScript_RegisterNicolas
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchNicolas
	msgbox MeteorFalls_1F_2R_Text_NicolasPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterNicolas::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MeteorFalls_1F_2R_Text_NicolasRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NICOLAS_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchNicolas::
	trainerbattle_rematch TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasRematchIntro, MeteorFalls_1F_2R_Text_NicolasRematchDefeat
	msgbox MeteorFalls_1F_2R_Text_NicolasPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_John::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnIntro, MeteorFalls_1F_2R_Text_JohnDefeat, MeteorFalls_1F_2R_Text_JohnNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJohn
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJohn
	msgbox MeteorFalls_1F_2R_Text_JohnPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJohn::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJohn::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnRematchIntro, MeteorFalls_1F_2R_Text_JohnRematchDefeat, MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JohnPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_Jay::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayIntro, MeteorFalls_1F_2R_Text_JayDefeat, MeteorFalls_1F_2R_Text_JayNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJay
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJay
	msgbox MeteorFalls_1F_2R_Text_JayPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJay::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT  @ John speaks for both during register
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJay::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayRematchIntro, MeteorFalls_1F_2R_Text_JayRematchDefeat, MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JayPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_Text_NicolasIntro:
	.string "Qui noi che usiamo i DRAGO ci\n"
	.string "alleniamo.\p"
	.string "Ci passa anche il CAMPIONE.\n"
	.string "Capisci quanto è speciale?$"

MeteorFalls_1F_2R_Text_NicolasDefeat:
	.string "Urgh!\n"
	.string "Non credevo fossi così forte!$"

MeteorFalls_1F_2R_Text_NicolasPostBattle:
	.string "La strada davanti è lunga e dura.\p"
	.string "Quando diventeremo io e i miei\n"
	.string "POKéMON i più forti?$"

MeteorFalls_1F_2R_Text_NicolasRegister:
	.string "Voglio sapere di più sulla tua forza.\n"
	.string "Lascia che ti registri nel POKéNAV.$"

MeteorFalls_1F_2R_Text_NicolasRematchIntro:
	.string "Da quando ci siamo incontrati, ci siamo\n"
	.string "allenati puntando al primo posto.\p"
	.string "Facci vedere quanto siamo\n"
	.string "diventati forti!$"

MeteorFalls_1F_2R_Text_NicolasRematchDefeat:
	.string "Urgh!\n"
	.string "Non credevo fossi così forte!$"

MeteorFalls_1F_2R_Text_NicolasPostRematch:
	.string "Hai continuato ad allenare\n"
	.string "i tuoi POKéMON.\p"
	.string "Se resti forte, anch'io\n"
	.string "posso diventare più forte!$"

MeteorFalls_1F_2R_Text_JohnIntro:
	.string "JOHN: Abbiamo sempre lottato\n"
	.string "insieme come coppia.\l"
	.string "Abbiamo fiducia in noi stessi.$"

MeteorFalls_1F_2R_Text_JohnDefeat:
	.string "JOHN: Oh, mio.\n"
	.string "Abbiamo perso, cara moglie.$"

MeteorFalls_1F_2R_Text_JohnPostBattle:
	.string "JOHN: Siamo sposati da\n"
	.string "cinquant'anni.\p"
	.string "A pensarci, non ho mai battuto\n"
	.string "mia moglie in una lotta.$"

MeteorFalls_1F_2R_Text_JohnNotEnoughMons:
	.string "JOHN: Bene, bene, che ALLENATORE!\p"
	.string "Vuoi lottare con noi? Allora devi\n"
	.string "tornare con altri POKéMON.$"

MeteorFalls_1F_2R_Text_JohnRegister:
	.string "JOHN: Giovane ALLENATORE, se ne avrai\n"
	.string "l'occasione, lotterai di nuovo con noi?$"

MeteorFalls_1F_2R_Text_JayIntro:
	.string "JAY: Siamo sposati da\n"
	.string "cinquant'anni.\p"
	.string "Il legame che ci unisce non\n"
	.string "potrà mai spezzarsi.$"

MeteorFalls_1F_2R_Text_JayDefeat:
	.string "JAY: Oh, cielo.\n"
	.string "Abbiamo perso, caro marito.$"

MeteorFalls_1F_2R_Text_JayPostBattle:
	.string "JAY: Cinquant'anni di matrimonio…\p"
	.string "Se litigavamo, risolvevamo sempre\n"
	.string "con una lotta POKéMON…$"

MeteorFalls_1F_2R_Text_JayNotEnoughMons:
	.string "JAY: Bene, bene, ma non sei un\n"
	.string "giovane ALLENATORE?\p"
	.string "Se vuoi lottare con noi, torna\n"
	.string "con altri POKéMON.$"

MeteorFalls_1F_2R_Text_JohnRematchIntro:
	.string "JOHN: Abbiamo sempre lottato\n"
	.string "insieme come coppia.\l"
	.string "Abbiamo fiducia in noi stessi.$"

MeteorFalls_1F_2R_Text_JohnRematchDefeat:
	.string "JOHN: Oh, mio.\n"
	.string "Abbiamo perso, cara moglie.$"

MeteorFalls_1F_2R_Text_JohnPostRematch:
	.string "JOHN: Sposati da cinquant'anni…\p"
	.string "Ripensandoci, io e mia moglie\n"
	.string "lottavamo giorno dopo giorno…$"

MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons:
	.string "JOHN: Bene, bene, che ALLENATORE!\p"
	.string "Vuoi lottare con noi? Allora devi\n"
	.string "tornare con altri POKéMON.$"

MeteorFalls_1F_2R_Text_JayRematchIntro:
	.string "JAY: Siamo sposati da\n"
	.string "cinquant'anni.\p"
	.string "Ci siamo sostenuti per tutto\n"
	.string "questo tempo. Siamo diventati forti.$"

MeteorFalls_1F_2R_Text_JayRematchDefeat:
	.string "JAY: Oh, cielo.\n"
	.string "Abbiamo perso, caro marito.$"

MeteorFalls_1F_2R_Text_JayPostRematch:
	.string "JAY: Cinquant'anni di matrimonio…\n"
	.string "Ne sono successe tante.\p"
	.string "Spero che continueremo a creare\n"
	.string "bei ricordi insieme.$"

MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons:
	.string "JAY: Bene, bene, ma non sei un\n"
	.string "giovane ALLENATORE?\p"
	.string "Se vuoi lottare con noi, torna\n"
	.string "con altri POKéMON.$"

