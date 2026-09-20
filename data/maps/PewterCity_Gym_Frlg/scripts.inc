PewterCity_Gym_Frlg_MapScripts::
	.byte 0

PewterCity_Gym_EventScript_Brock::
	famechecker FAMECHECKER_BROCK, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_BROCK, PewterCity_Gym_Text_BrockIntro, PewterCity_Gym_Text_BrockDefeat, PewterCity_Gym_EventScript_DefeatedBrock, NO_MUSIC
	goto_if_unset FLAG_GOT_TM39_FROM_BROCK, PewterCity_Gym_EventScript_GiveTM39
	msgbox PewterCity_Gym_Text_BrockPostBattle
	release
	end

PewterCity_Gym_EventScript_DefeatedBrock::
	famechecker FAMECHECKER_BROCK, 1
	setflag FLAG_DEFEATED_BROCK
	setflag FLAG_BADGE01_GET
	setvar VAR_MAP_SCENE_PEWTER_CITY, 1
	setflag FLAG_HIDE_PEWTER_CITY_GYM_GUIDE
	clearflag FLAG_HIDE_PEWTER_CITY_RUNNING_SHOES_GUY
	set_gym_trainers_frlg 1
	goto PewterCity_Gym_EventScript_GiveTM39
	end

PewterCity_Gym_EventScript_GiveTM39::
	msgbox PewterCity_Gym_Text_TakeThisWithYou
	checkitemspace ITEM_TM39
	goto_if_eq VAR_RESULT, FALSE, PewterCity_Gym_EventScript_NoRoomForTM39
	giveitem_msg PewterCity_Gym_Text_ReceivedTM39FromBrock, ITEM_TM39
	setflag FLAG_GOT_TM39_FROM_BROCK
	msgbox PewterCity_Gym_Text_ExplainTM39
	release
	end

PewterCity_Gym_EventScript_NoRoomForTM39::
	msgbox PewterCity_Gym_Text_DontHaveRoomForThis
	release
	end

PewterCity_Gym_EventScript_Liam::
	trainerbattle_single TRAINER_CAMPER_LIAM, PewterCity_Gym_Text_LiamIntro, PewterCity_Gym_Text_LiamDefeat
	msgbox PewterCity_Gym_Text_LiamPostBattle, MSGBOX_AUTOCLOSE
	end

PewterCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_BROCK, PewterCity_Gym_EventScript_GymGuyPostVictory
	msgbox PewterCity_Gym_Text_LetMeTakeYouToTheTop, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PewterCity_Gym_EventScript_GymGuyTakeMeToTop
	goto_if_eq VAR_RESULT, NO, PewterCity_Gym_EventScript_GymGuyDontTakeMeToTop
	end

PewterCity_Gym_EventScript_GymGuyPostVictory::
	msgbox PewterCity_Gym_Text_YoureChampMaterial
	release
	end

PewterCity_Gym_EventScript_GymGuyTakeMeToTop::
	msgbox PewterCity_Gym_Text_LetsGetHappening
	goto PewterCity_Gym_EventScript_GymGuyAdvice
	end

PewterCity_Gym_EventScript_GymGuyDontTakeMeToTop::
	msgbox PewterCity_Gym_Text_ItsFreeLetsGetHappening
	goto PewterCity_Gym_EventScript_GymGuyAdvice
	end

PewterCity_Gym_EventScript_GymGuyAdvice::
	msgbox PewterCity_Gym_Text_TryDifferentPartyOrders
	release
	end

PewterCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, PewterCity_Gym_EventScript_GymStatuePostVictory
	msgbox PewterCity_Gym_Text_GymStatue
	releaseall
	end

PewterCity_Gym_EventScript_GymStatuePostVictory::
	msgbox PewterCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

PewterCity_Gym_Text_BrockIntro::
	.string "Eccoti. Sono BROCK.\n"
	.string "Sono il CAPOPALESTRA di PLUMBEOPOLI.\p"
	.string "La mia volontà di roccia si vede\n"
	.string "anche nei miei POKéMON.\p"
	.string "I miei POKéMON sono duri come rocce e\n"
	.string "pieni di determinazione.\p"
	.string "Esatto, i miei POKéMON sono tutti\n"
	.string "di tipo Roccia!\p"
	.string "Ah ah! Mi sfidi sapendo\n"
	.string "che perderai?\p"
	.string "È l'onore degli ALLENATORI che\n"
	.string "ti spinge a sfidarmi.\p"
	.string "Va bene allora!\n"
	.string "Dammi il meglio!{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

PewterCity_Gym_Text_BrockDefeat::
	.string "Ti ho sottovalutato, e così\n"
	.string "ho perso.\p"
	.string "Come prova della tua vittoria, ti\n"
	.string "conferisco… la POKéMON\l"
	.string "LEGA MEDAGLIA SASSOMASSICCIO.\p"
	.string "{FONT_NORMAL}{PLAYER} riceve la MEDAGLIA SASSOMASSICCIO\n"
	.string "da BROCK!{PAUSE_MUSIC}{PLAY_BGM}{MUS_OBTAIN_BADGE}{PAUSE 0xFE}{PAUSE 0x56}{RESUME_MUSIC}\p"
	.string "{FONT_MALE}Avere la MEDAGLIA SASSOMASSICCIO rende\n"
	.string "più forti i tuoi POKéMON.\p"
	.string "Consente anche di usare la\n"
	.string "mossa FLASH fuori dalla lotta.\p"
	.string "Ovvio, un POKéMON deve conoscere la\n"
	.string "mossa FLASH per usarla.$"

PewterCity_Gym_Text_TakeThisWithYou::
	.string "Aspetta!\n"
	.string "Prendi questo con te.$"

PewterCity_Gym_Text_ReceivedTM39FromBrock::
	.string "{PLAYER} riceve la MT39\n"
	.string "da BROCK.$"

PewterCity_Gym_Text_ExplainTM39::
	.string "Una MT, Macchina Tecnica, contiene una\n"
	.string "tecnica per i POKéMON.\p"
	.string "Usare una MT insegna la mossa che\n"
	.string "contiene a un POKéMON.\p"
	.string "Una MT si usa una sola volta.\p"
	.string "Quindi, quando ne usi una, scegli\n"
	.string "il POKéMON con cura.\p"
	.string "Comunque…\n"
	.string "La MT39 contiene ROCK TOMB.\p"
	.string "Scaglia massi contro il nemico e\n"
	.string "ne riduce la VELOCITÀ.$"

PewterCity_Gym_Text_BrockPostBattle::
	.string "Ci sono ALLENATORI di ogni tipo in\n"
	.string "questo nostro enorme mondo.\p"
	.string "Sembri molto dotato come\n"
	.string "ALLENATORE di POKéMON.\p"
	.string "Lascia che ti dia un consiglio.\p"
	.string "Vai alla PALESTRA di CERULEOPOLI e metti\n"
	.string "alla prova le tue capacità.$"

PewterCity_Gym_Text_DontHaveRoomForThis::
	.string "Non hai spazio per questo.$"

PewterCity_Gym_Text_LiamIntro::
	.string "Fermo lì, ragazzo!\p"
	.string "Sei a diecimila anni luce \n"
	.string "dal poter sfidare BROCK!$"

PewterCity_Gym_Text_LiamDefeat::
	.string "Accidenti!\p"
	.string "L'anno luce non è tempo…\n"
	.string "Misura le distanze!$"

PewterCity_Gym_Text_LiamPostBattle::
	.string "Sei proprio forte.\n"
	.string "…Ma non quanto BROCK!$"

PewterCity_Gym_Text_LetMeTakeYouToTheTop::
	.string "Ciao!\n"
	.string "Vuoi sognare in grande?\p"
	.string "Osi sognare di diventare\n"
	.string "il campione POKéMON?\p"
	.string "Non sono un ALLENATORE, ma posso\n"
	.string "consigliarti come vincere.\p"
	.string "Ti porto io in cima!$"

PewterCity_Gym_Text_LetsGetHappening::
	.string "Benissimo!\n"
	.string "Diamoci da fare!$"

PewterCity_Gym_Text_TryDifferentPartyOrders::
	.string "Il primo POKéMON in campo è\n"
	.string "a sinistra nell'ELENCO POKéMON.\p"
	.string "Cambiando l'ordine dei POKéMON,\n"
	.string "puoi ottenere un vantaggio.\p"
	.string "Prova ordini diversi adatti alla\n"
	.string "squadra dell'avversario.$"

PewterCity_Gym_Text_ItsFreeLetsGetHappening::
	.string "È un servizio gratuito!\n"
	.string "Diamoci da fare!$"

PewterCity_Gym_Text_YoureChampMaterial::
	.string "Proprio come pensavo!\n"
	.string "Sei fatto per diventare CAMPIONE!$"

PewterCity_Gym_Text_GymStatue::
	.string "PALESTRA POKéMON di PLUMBEOPOLI\n"
	.string "CAPO: BROCK\p"
	.string "ALLENATORI VINCENTI:\n"
	.string "{RIVAL}$"

PewterCity_Gym_Text_GymStatuePlayerWon::
	.string "PALESTRA POKéMON di PLUMBEOPOLI\n"
	.string "CAPO: BROCK\p"
	.string "ALLENATORI VINCENTI:\n"
	.string "{RIVAL}, {PLAYER}$"

