ViridianCity_Gym_Frlg_MapScripts::
	.byte 0

ViridianCity_Gym_EventScript_Giovanni::
	famechecker FAMECHECKER_GIOVANNI, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_GIOVANNI, ViridianCity_Gym_Text_GiovanniIntro, ViridianCity_Gym_Text_GiovanniDefeat, ViridianCity_Gym_EventScript_DefeatedGiovanni, NO_MUSIC
	goto_if_unset FLAG_GOT_TM26_FROM_GIOVANNI, ViridianCity_Gym_EventScript_GiveTM26
	msgbox ViridianCity_Gym_Text_GiovanniPostBattle
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_VIRIDIAN_GIOVANNI
	fadescreen FADE_FROM_BLACK
	release
	end

ViridianCity_Gym_EventScript_DefeatedGiovanni::
	famechecker FAMECHECKER_GIOVANNI, 3
	setflag FLAG_HIDE_MISC_KANTO_ROCKETS
	setflag FLAG_DEFEATED_LEADER_GIOVANNI
	setflag FLAG_BADGE08_GET
	setvar VAR_MAP_SCENE_ROUTE22, 3
	set_gym_trainers_frlg 8
	goto ViridianCity_Gym_EventScript_GiveTM26
	end

ViridianCity_Gym_EventScript_GiveTM26::
	msgbox ViridianCity_Gym_Text_ExplainEarthBadgeTakeThis
	checkitemspace ITEM_TM26
	goto_if_eq VAR_RESULT, FALSE, ViridianCity_Gym_EventScript_NoRoomForTM26
	giveitem_msg ViridianCity_Gym_Text_ReceivedTM26FromGiovanni, ITEM_TM26
	setflag FLAG_GOT_TM26_FROM_GIOVANNI
	msgbox ViridianCity_Gym_Text_ExplainTM26
	release
	end

ViridianCity_Gym_EventScript_NoRoomForTM26::
	msgbox ViridianCity_Gym_Text_YouDoNotHaveSpace
	release
	end

ViridianCity_Gym_EventScript_Jason::
	trainerbattle_single TRAINER_TAMER_JASON, ViridianCity_Gym_Text_JasonIntro, ViridianCity_Gym_Text_JasonDefeat
	msgbox ViridianCity_Gym_Text_JasonPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Cole::
	trainerbattle_single TRAINER_TAMER_COLE, ViridianCity_Gym_Text_ColeIntro, ViridianCity_Gym_Text_ColeDefeat
	msgbox ViridianCity_Gym_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Atsushi::
	trainerbattle_single TRAINER_BLACK_BELT_ATSUSHI, ViridianCity_Gym_Text_AtsushiIntro, ViridianCity_Gym_Text_AtsushiDefeat
	msgbox ViridianCity_Gym_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Kiyo::
	trainerbattle_single TRAINER_BLACK_BELT_KIYO, ViridianCity_Gym_Text_KiyoIntro, ViridianCity_Gym_Text_KiyoDefeat
	msgbox ViridianCity_Gym_Text_KiyoPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Takashi::
	trainerbattle_single TRAINER_BLACK_BELT_TAKASHI, ViridianCity_Gym_Text_TakashiIntro, ViridianCity_Gym_Text_TakashiDefeat
	msgbox ViridianCity_Gym_Text_TakashiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Samuel::
	trainerbattle_single TRAINER_COOLTRAINER_SAMUEL, ViridianCity_Gym_Text_SamuelIntro, ViridianCity_Gym_Text_SamuelDefeat
	msgbox ViridianCity_Gym_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Yuji::
	trainerbattle_single TRAINER_COOLTRAINER_YUJI, ViridianCity_Gym_Text_YujiIntro, ViridianCity_Gym_Text_YujiDefeat
	msgbox ViridianCity_Gym_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Warren::
	trainerbattle_single TRAINER_COOLTRAINER_WARREN, ViridianCity_Gym_Text_WarrenIntro, ViridianCity_Gym_Text_WarrenDefeat
	msgbox ViridianCity_Gym_Text_WarrenPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LEADER_GIOVANNI, ViridianCity_Gym_EventScript_GymGuyPostVictory
	msgbox ViridianCity_Gym_Text_GymGuyAdvice
	release
	end

ViridianCity_Gym_EventScript_GymGuyPostVictory::
	famechecker FAMECHECKER_GIOVANNI, 4
	msgbox ViridianCity_Gym_Text_GymGuyPostVictory
	release
	end

ViridianCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, ViridianCity_Gym_EventScript_GymStatuePostVictory
	msgbox ViridianCity_Gym_Text_GymStatue
	releaseall
	end

ViridianCity_Gym_EventScript_GymStatuePostVictory::
	msgbox ViridianCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

ViridianCity_Gym_Text_GiovanniIntro::
	.string "Fwahahaha!\n"
	.string "Benvenuto nel mio covo!\p"
	.string "Lo sarà finché non riuscirò a restituire\n"
	.string "al TEAM ROCKET la sua antica gloria.\p"
	.string "Ma mi hai trovato di nuovo.\n"
	.string "E sia.\l"
	.string "Questa volta non mi trattengo!\p"
	.string "Ancora una volta affronterai\n"
	.string "GIOVANNI, il più grande ALLENATORE!{PLAY_BGM}{MUS_RG_ENCOUNTER_ROCKET}$"

ViridianCity_Gym_Text_GiovanniDefeat::
	.string "Ha!\n"
	.string "È stata una lotta davvero intensa.\l"
	.string "Hai vinto!\p"
	.string "Come prova, ecco il TERRASTENDARDO!\n"
	.string "{PAUSE_MUSIC}{PLAY_BGM}{MUS_OBTAIN_BADGE}{PAUSE 0xFE}{PAUSE 0x56}{RESUME_MUSIC}$"

ViridianCity_Gym_Text_GiovanniPostBattle::
	.string "Avendo perso in questo modo, \n"
	.string "non posso affrontare i miei seguaci.\l"
	.string "Ho tradito la loro fiducia.\p"
	.string "Da oggi, il TEAM ROCKET è\n"
	.string "finito per sempre!\p"
	.string "Quanto a me, dedicherò\n"
	.string "di nuovo la mia vita all'allenamento.\p"
	.string "Ci rivedremo un giorno!\n"
	.string "Addio!$"

ViridianCity_Gym_Text_ExplainEarthBadgeTakeThis::
	.string "La TERRASTENDARDO fa obbedire i POKéMON\n"
	.string "di ogni livello senza discussioni.\p"
	.string "È la prova della tua maestria come\n"
	.string "ALLENATORE POKéMON.\p"
	.string "Con essa puoi sfidare la\n"
	.string "LEGA POKéMON.\p"
	.string "Inoltre, prendi questa MT.\p"
	.string "Considerala un regalo per la tua\n"
	.string "sfida alla LEGA POKéMON.$"

ViridianCity_Gym_Text_ReceivedTM26FromGiovanni::
	.string "{PLAYER} riceve la MT26\n"
	.string "da GIOVANNI.$"

ViridianCity_Gym_Text_ExplainTM26::
	.string "La MT26 contiene TERREMOTO.\p"
	.string "È un attacco potente che causa\n"
	.string "un enorme tremito.\p"
	.string "L'ho creata quando dirigevo la PALESTRA,\n"
	.string "molto tempo fa… $"

ViridianCity_Gym_Text_YouDoNotHaveSpace::
	.string "Non hai spazio per questo!$"

ViridianCity_Gym_Text_YujiIntro::
	.string "Eh!\n"
	.string "Dovresti essere a corto di vapore\l"
	.string "ormai!$"

ViridianCity_Gym_Text_YujiDefeat::
	.string "Sono a corto di gas!$"

ViridianCity_Gym_Text_YujiPostBattle::
	.string "Ti serve forza per tenere testa\n"
	.string "al CAPO della nostra PALESTRA.$"

ViridianCity_Gym_Text_AtsushiIntro::
	.string "Rrrroar!\n"
	.string "Mi sto facendo prendere dall'ira!$"

ViridianCity_Gym_Text_AtsushiDefeat::
	.string "Argh!$"

ViridianCity_Gym_Text_AtsushiPostBattle::
	.string "Non sono ancora degno!$"

ViridianCity_Gym_Text_JasonIntro::
	.string "Io e i POKéMON suoniamo una\n"
	.string "musica meravigliosa!$"

ViridianCity_Gym_Text_JasonDefeat::
	.string "Siete in perfetta armonia!$"

ViridianCity_Gym_Text_JasonPostBattle::
	.string "Sai chi è il nostro\n"
	.string "CAPO della PALESTRA?$"

ViridianCity_Gym_Text_KiyoIntro::
	.string "Il Karate è la forma suprema di\n"
	.string "arti marziali!$"

ViridianCity_Gym_Text_KiyoDefeat::
	.string "Ahi!$"

ViridianCity_Gym_Text_KiyoPostBattle::
	.string "Se i miei POKéMON fossero bravi nel\n"
	.string "karate quanto me…$"

ViridianCity_Gym_Text_WarrenIntro::
	.string "I veri talenti vincono con stile.$"

ViridianCity_Gym_Text_WarrenDefeat::
	.string "Ho perso la presa!$"

ViridianCity_Gym_Text_WarrenPostBattle::
	.string "Il CAPO mi sgriderà per aver\n"
	.string "perso così…$"

ViridianCity_Gym_Text_TakashiIntro::
	.string "Sono il RE del KARATE!\n"
	.string "Il tuo destino è nelle mie mani!$"

ViridianCity_Gym_Text_TakashiDefeat::
	.string "Ahi!$"

ViridianCity_Gym_Text_TakashiPostBattle::
	.string "La LEGA POKéMON?\n"
	.string "Tu? Non montarti la testa!$"

ViridianCity_Gym_Text_ColeIntro::
	.string "I tuoi POKéMON tremeranno al\n"
	.string "crepitio della mia frusta!$"

ViridianCity_Gym_Text_ColeDefeat::
	.string "Ahia!\n"
	.string "Che frustata!$"

ViridianCity_Gym_Text_ColePostBattle::
	.string "Aspetta!\n"
	.string "Sono stato solo distratto!$"

ViridianCity_Gym_Text_SamuelIntro::
	.string "La PALESTRA di SMERALDOPOLI è\n"
	.string "rimasta chiusa a lungo.\p"
	.string "Ma ora il nostro CAPO è tornato!$"

ViridianCity_Gym_Text_SamuelDefeat::
	.string "Mi hai battuto?$"

ViridianCity_Gym_Text_SamuelPostBattle::
	.string "Per andare alla LEGA POKéMON\n"
	.string "devi battere il CAPO della\l"
	.string "nostra PALESTRA!$"

ViridianCity_Gym_Text_GymGuyAdvice::
	.string "Yo!\n"
	.string "Campione in erba!\p"
	.string "Neppure io conosco l'identità del\n"
	.string "CAPO di SMERALDOPOLI.\p"
	.string "Ma una cosa è certa.\n"
	.string "Sarà il più forte di tutti\l"
	.string "i CAPOPALESTRA.\p"
	.string "Inoltre, ho sentito che gli ALLENATORI\n"
	.string "qui amano i POKéMON di tipo TERRA.$"

ViridianCity_Gym_Text_GymGuyPostVictory::
	.string "Ma dai! GIOVANNI era il\n"
	.string "CAPO della PALESTRA\ndi SMERALDOPOLI?$"

ViridianCity_Gym_Text_GymStatue::
	.string "PALESTRA POKéMON DI SMERALDOPOLI\n"
	.string "CAPO: ?\p"
	.string "ALLENATORI VINCENTI:\n"
	.string "{RIVAL}$"

ViridianCity_Gym_Text_GymStatuePlayerWon::
	.string "PALESTRA POKéMON DI SMERALDOPOLI\n"
	.string "CAPO: GIOVANNI\p"
	.string "ALLENATORI VINCENTI:\n"
	.string "{RIVAL}, {PLAYER}$"

