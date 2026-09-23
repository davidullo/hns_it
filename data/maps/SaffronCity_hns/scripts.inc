SaffronCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_EventScript_CityEnter
	.byte 0

SaffronCity_EventScript_CityEnter::
	setflag FLAG_VISITED_SAFFRON_CITY
	end

SaffronCity_Text_BaobaName:
	.string "BAOBA$"

SaffronCity_Text_Baoba:
	.string "GUARDIA BAOBA: {PLAYER}!\p"
	.string "Sono la GUARDIA BAOBA.\p"
	.string "Ti chiamo per dirti che la\n"
	.string "ZONA SAFARI si è ampliata!\p"
	.string "Finalmente la mia ZONA SAFARI\n"
	.string "è completa!\p"
	.string "Ti ricordi dov'è, vero?\p"
	.string "Appena a ovest di FIORLISOPOLI!\n"
	.string "A presto!$"

SaffronCity_EventScript_Lass1A::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_Lass1B
	msgbox SaffronCity_Text_Lass1, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass1B::
	msgbox SaffronCity_Text_Lass1_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass2::
	msgbox SaffronCity_Text_Lass2, MSGBOX_NPC
	end

SaffronCity_EventScript_PokefanM::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_PokefanM2
	msgbox SaffronCity_Text_PokefanM, MSGBOX_NPC
	end

SaffronCity_EventScript_PokefanM2::
	msgbox SaffronCity_Text_PokefanM_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_CooltrainerM::
	msgbox SaffronCity_Text_CooltrainerM, MSGBOX_NPC
	end

SaffronCity_EventScript_CooltrainerF::
	msgbox SaffronCity_Text_CooltrainerF, MSGBOX_NPC
	end

SaffronCity_EventScript_Fisher::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_Fisher2
	msgbox SaffronCity_Text_Fisher, MSGBOX_NPC
	end

SaffronCity_EventScript_Fisher2::
	msgbox SaffronCity_Text_Fisher_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_Youngster1::
	msgbox SaffronCity_Text_Youngster1, MSGBOX_NPC
	end

SaffronCity_EventScript_Youngster2::
	msgbox SaffronCity_Text_Youngster2, MSGBOX_NPC
	end
SaffronCity_EventScript_CitySign::
	msgbox SaffronCity_Text_Sign, MSGBOX_SIGN
	end

SaffronCity_EventScript_GymSign::
	msgbox SaffronCity_Text_GymSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_DojoSign::
	msgbox SaffronCity_Text_FightingDojoSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_SilphCoSign::
	msgbox SaffronCity_Text_SilphCoSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_MrPsychicSign::
	msgbox SaffronCity_Text_MrPsychicHouseSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_MagnetTrainSign::
	msgbox SaffronCity_Text_MagnetTrainStationSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_Elli::
	msgbox SaffronCity_Text_Elli, MSGBOX_NPC
	end

SaffronCity_Text_Elli:
	.string "Adoro VULPIX! :D$"

SaffronCity_Text_Lass1:
	.string "Qui vive una bimba esperta\n"
	.string "nell'imitare la gente.\p"
	.string "Imita anche chi le parla.\n"
	.string "È una cosa confusa.$"

SaffronCity_Text_Lass1_ReturnedPart:
	.string "La ragazza COPIONE sembrava triste.\p"
	.string "Dice che ha perso il suo\n"
	.string "POKé DOLL preferito, CLEFAIRY.$"

SaffronCity_Text_PokefanM:
	.string "Vieni da JOHTO?\p"
	.string "Puoi tornare a casa in un lampo\n"
	.string "se il MAGNETOTRENO funziona.$"

SaffronCity_Text_PokefanM_ReturnedPart:
	.string "Vieni da JOHTO?\p"
	.string "Puoi tornare a casa saltando\n"
	.string "sul MAGNETOTRENO.$"

SaffronCity_Text_CooltrainerM:
	.string "Sono andato in PALESTRA, pronto\n"
	.string "a sfidare gli allenatori…\p"
	.string "Invece sono finito nella\n"
	.string "PALESTRA in disuso accanto.\p"
	.string "Che figuraccia.$"

SaffronCity_Text_CooltrainerF:
	.string "Questa è la SILPH CO., famosa per\n"
	.string "il merchandising POKéMON.\p"
	.string "In passato il TEAM ROCKET la\n"
	.string "voleva proprio per quello.$"

SaffronCity_Text_Fisher:
	.string "Gnam… Gnam…\p"
	.string "Sento che ci sono grossi guai\n"
	.string "alla CENTRALE ELETTRICA.\p"
	.string "Gnam… Gnam…$"

SaffronCity_Text_Fisher_ReturnedPart:
	.string "Gnam… Gnam…\p"
	.string "Sento che ci sono stati grossi guai\n"
	.string "alla CENTRALE ELETTRICA.\p"
	.string "Gnam… Gnam… Ah, sono sazio!$"

SaffronCity_Text_Youngster1:
	.string "Entrare in un vicolo la prima\n"
	.string "volta mi mette un po' d'ansia.$"

SaffronCity_Text_Youngster2:
	.string "C'è un posto chiamato SALA\n"
	.string "CONCORSI a SMERALDOPOLI, dove gli\l"
	.string "allenatori arrivano da ovunque.$"

SaffronCity_Text_Lass2:
	.string "La nostra città è stata in un\n"
	.string "programma radio.\p"
	.string "Fa piacere sentire elogi sulla tua\n"
	.string "città, ma è anche un po'\l"
	.string "imbarazzante.$"

SaffronCity_Text_Sign:
	.string "ZAFFIRIOPOLI\p"
	.string "Luminosa terra d'oro e commercio$"

SaffronCity_Text_GymSign:
	.string "ZAFFIRIOPOLI\n"
	.string "PALESTRA POKéMON\l"
	.string "CAPO: SABRINA\p"
	.string "La maestra dei POKéMON Psichico!$"

SaffronCity_Text_FightingDojoSign:
	.string "Aperti a tutti!\n"
	.string "DOJO LOTTA$"

SaffronCity_Text_SilphCoSign:
	.string "SILPH CO.\n"
	.string "PALAZZO$"

SaffronCity_Text_MrPsychicHouseSign:
	.string "CASA DEL\n"
	.string "SIGNOR PSICHICO$"

SaffronCity_Text_MagnetTrainStationSign:
	.string "ZAFFIRIOPOLI\n"
	.string "STAZIONE MAGNETOTRENO$"
