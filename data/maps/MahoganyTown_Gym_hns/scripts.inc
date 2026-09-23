MahoganyTown_Gym_hns_MapScripts::
	.byte 0


MahoganyTown_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM,  MahoganyTown_Gym_EventScript_Statue2
	msgbox MahoganyTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_EventScript_Statue2::
	msgbox MahoganyTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_Text_GymStatue:
	.string "PALESTRA POKéMON DI MOGANIA$"

MahoganyTown_Gym_Text_GymStatueCertified:
	.string "PALESTRA POKéMON DI MOGANIA\p"
	.string "ALLENATORI CERTIFICATI DA ALFREDO:\n"
	.string "{PLAYER}$"


MahoganyTown_GymEventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, MahoganyTown_Gym_EventScript_GymGuy2
	msgbox MahoganyTown_Gym_Text_Guide, MSGBOX_DEFAULT
	closemessage
	release
	end
	
MahoganyTown_Gym_EventScript_GymGuy2::
	msgbox MahoganyTown_Gym_Text_GuideWin, MSGBOX_DEFAULT
	release
	end	

MahoganyTown_Gym_EventScript_Ronald::
	trainerbattle_single TRAINER_RONALD_HNS, MahoganyTown_Gym_Text_BoarderRonaldSeen, MahoganyTown_Gym_Text_BoarderRonaldBeaten
	msgbox MahoganyTown_Gym_Text_BoarderRonaldAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Brad::
	trainerbattle_single TRAINER_BRAD_HNS, MahoganyTown_Gym_Text_BoarderBradSeen, MahoganyTown_Gym_Text_BoarderBradBeaten
	msgbox MahoganyTown_Gym_Text_BoarderBradAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Douglas::
	trainerbattle_single TRAINER_DOUGLAS_HNS, MahoganyTown_Gym_Text_BoarderDouglasSeen, MahoganyTown_Gym_Text_BoarderDouglasBeaten
	msgbox MahoganyTown_Gym_Text_BoarderDouglasAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_HNS, MahoganyTown_Gym_Text_SkierRoxanneSeen, MahoganyTown_Gym_Text_SkierRoxanneBeaten
	msgbox MahoganyTown_Gym_Text_SkierRoxanneAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Clarissa::
	trainerbattle_single TRAINER_CLARISSA_HNS, MahoganyTown_Gym_Text_SkierClarissaSeen, MahoganyTown_Gym_Text_SkierClarissaBeaten
	msgbox MahoganyTown_Gym_Text_SkierClarissaAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Pryce::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, MahoganyTown_Gym_EventScript_Pryce_Defeated
	msgbox MahoganyTown_Gym_Text_PryceIntro, MSGBOX_DEFAULT
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, MahoganyTown_Gym_EventScript_OlivineCheckCianwood
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, MahoganyTown_Gym_EventScript_CianwoodCheckOlivine
	goto MahoganyTown_Gym_EventScript_Pryce_Battle1

MahoganyTown_Gym_EventScript_PryceVictory::
	message MahoganyTown_Gym_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MahoganyTown_Gym_Text_GlacierBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE07_GET
	setflag FLAG_DEFEATED_MAHOGANY_TOWN_GYM
    addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_HAIL
	msgbox MahoganyTown_Gym_Text_HailSpeech, MSGBOX_DEFAULT
	setvar VAR_MAHOGANY_TOWN_STATE, 15
    setrespawn HEAL_LOCATION_MAHOGANY_TOWN_HNS
    call_if_eq VAR_NUM_BADGES, 7, MahoganyTown_Gym_EventScript_SetupElmRocketCall
	closemessage
	release
	end

MahoganyTown_Gym_EventScript_SetupElmRocketCall::
    setvar VAR_TRIGGER_ELM_ROCKET_CALL, 1
    return

MahoganyTown_Gym_EventScript_OlivineCheckCianwood::
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, MahoganyTown_Gym_EventScript_Pryce_Battle3
	goto MahoganyTown_Gym_EventScript_Pryce_Battle2

MahoganyTown_Gym_EventScript_CianwoodCheckOlivine::
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, MahoganyTown_Gym_EventScript_Pryce_Battle3
	goto MahoganyTown_Gym_EventScript_Pryce_Battle2
	
MahoganyTown_Gym_EventScript_Pryce_Battle1::
	trainerbattle_no_intro TRAINER_PRYCE_1_HNS, MahoganyTown_Gym_Text_PryceImpressed
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Battle2::
	trainerbattle_no_intro TRAINER_PRYCE_1_2_HNS, MahoganyTown_Gym_Text_PryceImpressed
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Battle3::
	trainerbattle_no_intro TRAINER_PRYCE_1_3_HNS, MahoganyTown_Gym_Text_PryceImpressed
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Defeated::
	msgbox MahoganyTown_Gym_Text_CherishPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_Text_PryceIntro:
    .string "I POKéMON vivono molte\n"
    .string "esperienze, come noi.\p"
    .string "Anch'io ho visto e sofferto\n"
    .string "molto nella vita.\p"
    .string "Dato che sono il tuo anziano,\n"
    .string "lascia che ti mostri.\p"
    .string "Sto con i POKéMON da\n"
    .string "prima che tu nascessi.\p"
    .string "Non perdo facilmente.\p"
    .string "Io, ALFREDO, allenatore d'inverno,\n"
    .string "ti mostrerò la mia forza!$"

MahoganyTown_Gym_Text_PryceImpressed:
    .string "Ah, sono colpito dalla tua\n"
    .string "bravura.\p"
    .string "Con la tua forza so che\n"
    .string "supererai ogni ostacolo.\p"
    .string "Meriti questa MEDAGLIA!$"

MahoganyTown_Gym_Text_ReceivedBadge:
    .string "{PLAYER} riceve la MEDAGLIA GELO.$"

MahoganyTown_Gym_Text_GlacierBadgeSpeech:
    .string "Quella MEDAGLIA alza l'ATTACCO\n"
    .string "SPECIALE dei POKéMON.\p"
    .string "Permette anche ai POKéMON di usare\n"
    .string "MULINELLO per attraversare\l"
    .string "i veri mulinelli.\p"
    .string "E questo… è un regalo per te!$"

MahoganyTown_Gym_Text_HailSpeech:
    .string "Questa MT contiene GRANDINE.\p"
    .string "Infligge danni ogni\n"
    .string "turno per 5 turni.\p"
    .string "Mostra la durezza\n"
    .string "dell'inverno.$"

MahoganyTown_Gym_Text_CherishPokemon:
    .string "Quando ghiaccio e neve si sciolgono,\n"
    .string "arriva la primavera.\p"
    .string "Tu e i tuoi POKéMON starete\n"
    .string "insieme per molti anni.\p"
    .string "Godetevi il tempo insieme!$"

MahoganyTown_Gym_Text_PryceRematch:
    .string "Ah, CAMPIONE DI JOHTO!\p"
    .string "Le tue abilità sono davvero\n"
    .string "notevoli.\p"
    .string "Sono colpito.\p"
    .string "Ma c'è ancora molto da\n"
    .string "imparare l'uno dall'altro.\p"
    .string "Io, ALFREDO, allenatore d'inverno,\n"
    .string "ho ancora qualche trucco.\p"
    .string "Vuoi una rivincita con me?$"

MahoganyTown_Gym_Text_PryceRematchDefeat:
    .string "Ah, di nuovo colpito dalla\n"
    .string "tua bravura.\p"
    .string "Con la tua forza so che\n"
    .string "supererai ogni ostacolo.$"

MahoganyTown_Gym_Text_Guide:
    .string "ALFREDO è un veterano che allena\n"
    .string "POKéMON da 50 anni.\p"
    .string "Ha una squadra solida di\n"
    .string "POKéMON per coprire qualsiasi\l"
    .string "cosa tu gli porti.\p"
    .string "Il FUOCO è un buon inizio,\n"
    .string "ma attento alla pioggia!$"

MahoganyTown_Gym_Text_GuideWin:
    .string "ALFREDO è forte, ma tu sei\n"
    .string "un'altra cosa!\p"
    .string "È stata una bella lotta che\n"
    .string "ha unito le generazioni!$"

MahoganyTown_Gym_Text_BoarderRonaldSeen:
    .string "Congelerò i tuoi POKéMON,\n"
    .string "così non farai nulla!$"

MahoganyTown_Gym_Text_BoarderRonaldBeaten:
    .string "Dannazione. Non ho fatto nulla.$"

MahoganyTown_Gym_Text_BoarderRonaldAfter:
    .string "Credo ci sia una mossa che un\n"
    .string "POKéMON può usare mentre è\l"
    .string "congelato.$"

MahoganyTown_Gym_Text_BoarderBradSeen:
    .string "Questa PALESTRA ha il pavimento liscio.\p"
    .string "È divertente, no?\p"
    .string "Ma non siamo qui\n"
    .string "per giocare!$"

MahoganyTown_Gym_Text_BoarderBradBeaten:
    .string "Vedi quanto siamo seri?$"

MahoganyTown_Gym_Text_BoarderBradAfter:
    .string "Questa PALESTRA è grande.\n"
    .string "Adoro scendere con i miei\l"
    .string "POKéMON!$"

MahoganyTown_Gym_Text_BoarderDouglasSeen:
    .string "So il segreto di ALFREDO.$"

MahoganyTown_Gym_Text_BoarderDouglasBeaten:
    .string "OK. Ti dico il segreto di ALFREDO.$"

MahoganyTown_Gym_Text_BoarderDouglasAfter:
    .string "Il segreto di ALFREDO…\p"
    .string "Medita sotto una cascata\n"
    .string "ogni giorno per temprare mente\l"
    .string "e corpo.$"

MahoganyTown_Gym_Text_SkierRoxanneSeen:
    .string "Per arrivare a ALFREDO, il nostro\n"
    .string "CAPOPALESTRA, pensa prima di scendere.$"

MahoganyTown_Gym_Text_SkierRoxanneBeaten:
    .string "Sugli sci non ti perderei!$"

MahoganyTown_Gym_Text_SkierRoxanneAfter:
    .string "Se non scendi con precisione,\n"
    .string "non andrai lontano qui.$"

MahoganyTown_Gym_Text_SkierClarissaSeen:
    .string "Guarda la mia curva parallela!$"

MahoganyTown_Gym_Text_SkierClarissaBeaten:
    .string "No! Mi hai fatto cadere!$"

MahoganyTown_Gym_Text_SkierClarissaAfter:
    .string "Non avrei dovuto vantarmi\n"
    .string "della mia sciata…$"

