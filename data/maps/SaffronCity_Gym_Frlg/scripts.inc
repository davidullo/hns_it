SaffronCity_Gym_Frlg_MapScripts::
	.byte 0

SaffronCity_Gym_EventScript_Sabrina::
	famechecker FAMECHECKER_SABRINA, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_SABRINA, SaffronCity_Gym_Text_SabrinaIntro, SaffronCity_Gym_Text_SabrinaDefeat, SaffronCity_Gym_EventScript_DefeatedSabrina, NO_MUSIC
	goto_if_unset FLAG_GOT_TM04_FROM_SABRINA, SaffronCity_Gym_EventScript_GiveTM04
	msgbox SaffronCity_Gym_Text_ExplainTM04
	release
	end

SaffronCity_Gym_EventScript_DefeatedSabrina::
	famechecker FAMECHECKER_SABRINA, 2
	famechecker FAMECHECKER_SABRINA, 3
	clearflag FLAG_HIDE_SAFFRON_CITY_POKECENTER_SABRINA_JOURNALS
	setflag FLAG_DEFEATED_SABRINA
	setflag FLAG_BADGE06_GET
	set_gym_trainers_frlg 6
	goto SaffronCity_Gym_EventScript_GiveTM04
	end

SaffronCity_Gym_EventScript_GiveTM04::
	msgbox SaffronCity_Gym_Text_ExplainMarshBadgeTakeThis
	checkitemspace ITEM_TM04
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_Gym_EventScript_NoRoomForTM04
	giveitem_msg SaffronCity_Gym_Text_ReceivedTM04FromSabrina, ITEM_TM04
	setflag FLAG_GOT_TM04_FROM_SABRINA
	msgbox SaffronCity_Gym_Text_SabrinaPostBattle
	release
	end

SaffronCity_Gym_EventScript_NoRoomForTM04::
	msgbox SaffronCity_Gym_Text_BagFullOfOtherItems
	release
	end

SaffronCity_Gym_EventScript_Johan::
	trainerbattle_single TRAINER_PSYCHIC_JOHAN, SaffronCity_Gym_Text_JohanIntro, SaffronCity_Gym_Text_JohanDefeat
	msgbox SaffronCity_Gym_Text_JohanPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Tyron::
	trainerbattle_single TRAINER_PSYCHIC_TYRON, SaffronCity_Gym_Text_TyronIntro, SaffronCity_Gym_Text_TyronDefeat
	famechecker FAMECHECKER_SABRINA, 5
	msgbox SaffronCity_Gym_Text_TyronPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Cameron::
	trainerbattle_single TRAINER_PSYCHIC_CAMERON, SaffronCity_Gym_Text_CameronIntro, SaffronCity_Gym_Text_CameronDefeat
	msgbox SaffronCity_Gym_Text_CameronPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_PSYCHIC_PRESTON, SaffronCity_Gym_Text_PrestonIntro, SaffronCity_Gym_Text_PrestonDefeat
	msgbox SaffronCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Amanda::
	trainerbattle_single TRAINER_CHANNELER_AMANDA, SaffronCity_Gym_Text_AmandaIntro, SaffronCity_Gym_Text_AmandaDefeat
	msgbox SaffronCity_Gym_Text_AmandaPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Stacy::
	trainerbattle_single TRAINER_CHANNELER_STACY, SaffronCity_Gym_Text_StacyIntro, SaffronCity_Gym_Text_StacyDefeat
	msgbox SaffronCity_Gym_Text_StacyPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Tasha::
	trainerbattle_single TRAINER_CHANNELER_TASHA, SaffronCity_Gym_Text_TashaIntro, SaffronCity_Gym_Text_TashaDefeat
	msgbox SaffronCity_Gym_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SABRINA, SaffronCity_Gym_EventScript_GymGuyPostVictory
	msgbox SaffronCity_Gym_Text_GymGuyAdvice
	release
	end

SaffronCity_Gym_EventScript_GymGuyPostVictory::
	msgbox SaffronCity_Gym_Text_GymGuyPostVictory
	release
	end

SaffronCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, SaffronCity_Gym_EventScript_GymStatuePostVictory
	msgbox SaffronCity_Gym_Text_GymStatue
	releaseall
	end

SaffronCity_Gym_EventScript_GymStatuePostVictory::
	msgbox SaffronCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

SaffronCity_Gym_Text_SabrinaIntro::
	.string "Avevo previsto il tuo arrivo.\p"
	.string "Ho poteri psichici da quando\n"
	.string "ero bambina.\p"
	.string "Tutto iniziò quando un cucchiaio\n"
	.string "che lanciai con noncuranza si piegò.\p"
	.string "Non amo lottare, ma se vuoi,\n"
	.string "ti mostrerò i miei poteri!{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

SaffronCity_Gym_Text_SabrinaDefeat::
	.string "Questa sconfitta mi sconvolge!\n"
	.string "Ma una sconfitta è una sconfitta.\p"
	.string "Ammetto di non essermi impegnata\n"
	.string "abbastanza per vincere.\p"
	.string "La tua vittoria ti ha fatto meritare\n"
	.string "la MEDAGLIA PALUDE.$"

SaffronCity_Gym_Text_SabrinaPostBattle::
	.string "Il potere psichico non è di\n"
	.string "pochi eletti.\p"
	.string "Tutti hanno poteri psichici.\n"
	.string "Solo che non lo sanno.$"

SaffronCity_Gym_Text_ExplainMarshBadgeTakeThis::
	.string "La MEDAGLIA PALUDE fa obbedire i\n"
	.string "POKéMON fino al liv. 70.\p"
	.string "I più forti diventeranno ribelli e\n"
	.string "ignoreranno i tuoi ordini.\p"
	.string "Non allenare troppo i POKéMON\n"
	.string "per evitare il problema.\p"
	.string "Aspetta, prendi questa MT.$"

SaffronCity_Gym_Text_ReceivedTM04FromSabrina::
	.string "{PLAYER} riceve la MT04 da\n"
	.string "SABRINA.$"

SaffronCity_Gym_Text_ExplainTM04::
	.string "La MT04 è CALMA MENTALE.\p"
	.string "Fa concentrare il POKéMON per\n"
	.string "aumentare ATT. SP. e DIF. SP.$"

SaffronCity_Gym_Text_BagFullOfOtherItems::
	.string "La tua BORSa è piena di oggetti.$"

SaffronCity_Gym_Text_AmandaIntro::
	.string "SABRINA è molto più giovane di me,\n"
	.string "ma si è guadagnata il mio rispetto.$"

SaffronCity_Gym_Text_AmandaDefeat::
	.string "Non basta!$"

SaffronCity_Gym_Text_AmandaPostBattle::
	.string "In una lotta fra pari, vince\n"
	.string "chi ha la volontà più forte.\p"
	.string "Per battere SABRINA, concentrati\n"
	.string "e imponiti di vincere.$"

SaffronCity_Gym_Text_JohanIntro::
	.string "Ti spaventa il nostro potere invisibile?$"

SaffronCity_Gym_Text_JohanDefeat::
	.string "Non l'avevo previsto!$"

SaffronCity_Gym_Text_JohanPostBattle::
	.string "I POKéMON PSICO temono solo i\n"
	.string "fantasmi e gli insetti!$"

SaffronCity_Gym_Text_StacyIntro::
	.string "I POKéMON assumono l'aspetto dei\n"
	.string "loro ALLENATORI.\p"
	.string "I tuoi POKéMON devono essere forti!$"

SaffronCity_Gym_Text_StacyDefeat::
	.string "Lo sapevo!$"

SaffronCity_Gym_Text_StacyPostBattle::
	.string "Ho ancora molto da imparare…\p"
	.string "Devo padroneggiare PSICO e insegnarlo\n"
	.string "ai miei POKéMON…$"

SaffronCity_Gym_Text_TyronIntro::
	.string "Hai capito, vero?\p"
	.string "Che la sola forza non basta per\n"
	.string "vincere nel mondo POKéMON?$"

SaffronCity_Gym_Text_TyronDefeat::
	.string "Non ci credo!$"

SaffronCity_Gym_Text_TyronPostBattle::
	.string "SABRINA ha appena stracciato il MAESTRO\n"
	.string "DI KARATE qui accanto.$"

SaffronCity_Gym_Text_TashaIntro::
	.string "Tu e io, i nostri POKéMON\n"
	.string "si batteranno!$"

SaffronCity_Gym_Text_TashaDefeat::
	.string "Ho perso, dopotutto!$"

SaffronCity_Gym_Text_TashaPostBattle::
	.string "Sapevo che questo sarebbe\n"
	.string "accaduto.$"

SaffronCity_Gym_Text_CameronIntro::
	.string "SABRINA è giovane, ma è anche\n"
	.string "la nostra abilissima CAPO.\p"
	.string "Non la raggiungerai facilmente!$"

SaffronCity_Gym_Text_CameronDefeat::
	.string "Ah!\n"
	.string "K.O. totale!$"

SaffronCity_Gym_Text_CameronPostBattle::
	.string "C'erano due PALESTRE POKéMON\n"
	.string "a ZAFFIRO.\p"
	.string "Il DOJO LOTTA qui accanto ha perso\n"
	.string "lo status di PALESTRA.\p"
	.string "Li abbiamo stracciati quando abbiamo\n"
	.string "deciso di tenerne una sola.$"

SaffronCity_Gym_Text_PrestonIntro::
	.string "La PALESTRA di ZAFFERANOPOLI è famosa\n"
	.string "per gli allenatori psichici.\p"
	.string "Vuoi vedere SABRINA, vero?\n"
	.string "Si vede!$"

SaffronCity_Gym_Text_PrestonDefeat::
	.string "Argh!$"

SaffronCity_Gym_Text_PrestonPostBattle::
	.string "Esatto! Ho letto la tua mente\n"
	.string "con la telepatia!$"

SaffronCity_Gym_Text_GymGuyAdvice::
	.string "Ehi!\n"
	.string "Campione in erba!\p"
	.string "I POKéMON di SABRINA usano la\n"
	.string "forza psichica, non quella fisica.\p"
	.string "I POKéMON LOTTA sono molto\n"
	.string "deboli contro quelli PSICO.\p"
	.string "Vengono distrutti prima di\n"
	.string "poter sferrare un pugno!$"

SaffronCity_Gym_Text_GymGuyPostVictory::
	.string "Poteri psichici, eh?\p"
	.string "Se li avessi, farei un sacco\n"
	.string "di soldi alle slot!$"

SaffronCity_Gym_Text_GymStatue::
	.string "PALESTRA POKéMON ZAFFIRO\n"
	.string "CAPO: SABRINA\p"
	.string "ALLENATORI VINCENTI:\n"
	.string "{RIVAL}$"

SaffronCity_Gym_Text_GymStatuePlayerWon::
	.string "PALESTRA POKéMON ZAFFIRO\n"
	.string "CAPO: SABRINA\p"
	.string "ALLENATORI VINCENTI:\n"
	.string "{RIVAL}, {PLAYER}$"

