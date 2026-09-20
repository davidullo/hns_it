FortreeCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_Gym_OnWarp
	.byte 0

FortreeCity_Gym_OnTransition:
	special RotatingGate_InitPuzzle
	setflag FLAG_TEMP_HIDE_FOLLOWER @ Hide follower bc of rotating gates
	end

FortreeCity_Gym_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeCity_Gym_EventScript_InitRotatingGates
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_3
FortreeCity_Gym_EventScript_InitRotatingGates::
	special RotatingGate_InitPuzzleAndGraphics
	end

FortreeCity_Gym_EventScript_Winona::
	trainerbattle_single TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaIntro, FortreeCity_Gym_Text_WinonaDefeat, FortreeCity_Gym_EventScript_WinonaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_Gym_EventScript_WinonaRematch
	goto_if_unset FLAG_RECEIVED_TM_AERIAL_ACE, FortreeCity_Gym_EventScript_GiveAerialAce2
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_WinonaDefeated::
	message FortreeCity_Gym_Text_ReceivedFeatherBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_FORTREE_GYM
	setflag FLAG_BADGE06_GET
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers
	call FortreeCity_Gym_EventScript_GiveAerialAce
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
	setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_FORTREE_GYM
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce2::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	return

FortreeCity_Gym_EventScript_WinonaRematch::
	trainerbattle_rematch_double TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaPreRematch, FortreeCity_Gym_Text_WinonaRematchDefeat, FortreeCity_Gym_Text_WinonaRematchNeedTwoMons
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED, FortreeCity_Gym_Text_JaredIntro, FortreeCity_Gym_Text_JaredDefeat
	msgbox FortreeCity_Gym_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Edwardo::
	trainerbattle_single TRAINER_EDWARDO, FortreeCity_Gym_Text_EdwardoIntro, FortreeCity_Gym_Text_EdwardoDefeat
	msgbox FortreeCity_Gym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Flint::
	trainerbattle_single TRAINER_FLINT, FortreeCity_Gym_Text_FlintIntro, FortreeCity_Gym_Text_FlintDefeat
	msgbox FortreeCity_Gym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Ashley::
	trainerbattle_single TRAINER_ASHLEY, FortreeCity_Gym_Text_AshleyIntro, FortreeCity_Gym_Text_AshleyDefeat
	msgbox FortreeCity_Gym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Humberto::
	trainerbattle_single TRAINER_HUMBERTO, FortreeCity_Gym_Text_HumbertoIntro, FortreeCity_Gym_Text_HumbertoDefeat
	msgbox FortreeCity_Gym_Text_HumbertoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Darius::
	trainerbattle_single TRAINER_DARIUS, FortreeCity_Gym_Text_DariusIntro, FortreeCity_Gym_Text_DariusDefeat
	msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_GymGuidePostVictory
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_GymGuidePostVictory::
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_GymStatueCertified::
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_EventScript_GymStatue::
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_Text_GymGuideAdvice:
	.string "Ehi, come va, aspirante\n"
	.string "CAMPIONE {PLAYER}?\p"
	.string "La CAPOPALESTRA WINONA è\n"
	.string "una maestra di POKéMON VOLANTE.\p"
	.string "Ti aspetta in fondo alla PALESTRA,\n"
	.string "dietro le porte girevoli.\p"
	.string "Attende nuovi sfidanti\n"
	.string "pronti a spiccare il volo!\p"
	.string "Forza, vai!$"

FortreeCity_Gym_Text_GymGuidePostVictory:
	.string "Ben fatto!\n"
	.string "Hai spiccato il volo!$"

FortreeCity_Gym_Text_JaredIntro:
	.string "Ammira l'elegante stile di lotta\n"
	.string "dei POKéMON UCCELLO!$"

FortreeCity_Gym_Text_JaredDefeat:
	.string "Tu…\n"
	.string "Sei forte…$"

FortreeCity_Gym_Text_JaredPostBattle:
	.string "Un ALLENATORE deve stare al passo\n"
	.string "con gli imprevisti.\p"
	.string "Sei sveglio abbastanza per\n"
	.string "arrivare alla CAPO?$"

FortreeCity_Gym_Text_EdwardoIntro:
	.string "Chi ama i POKéMON UCCELLO vuole\n"
	.string "la PALESTRA.\p"
	.string "Membro della PALESTRA di FORTREE,\n"
	.string "non posso perdere!$"

FortreeCity_Gym_Text_EdwardoDefeat:
	.string "Per me era un peso troppo grande\n"
	.string "da reggere…$"

FortreeCity_Gym_Text_EdwardoPostBattle:
	.string "Il mondo è grande e ci sono\n"
	.string "tanti ALLENATORI forti.\p"
	.string "Continuerò ad allenarmi per\n"
	.string "diventare più forte.$"

FortreeCity_Gym_Text_FlintIntro:
	.string "Non serve WINONA, la nostra\n"
	.string "CAPOPALESTRA, per te!\p"
	.string "Io basto e avanzo per te!$"

FortreeCity_Gym_Text_FlintDefeat:
	.string "WINONA, io…\n"
	.string "Ho perso!$"

FortreeCity_Gym_Text_FlintPostBattle:
	.string "WINONA è carina e forte.\n"
	.string "È la CAPOPALESTRA suprema!\p"
	.string "Arrossisco…$"

FortreeCity_Gym_Text_AshleyIntro:
	.string "Me l'ha insegnato WINONA!\n"
	.string "Non mi batti facilmente!$"

FortreeCity_Gym_Text_AshleyDefeat:
	.string "Ho perso…$"

FortreeCity_Gym_Text_AshleyPostBattle:
	.string "Grazie a WINONA, la gente di\n"
	.string "FORTREE vive senza paura.$"

FortreeCity_Gym_Text_HumbertoIntro:
	.string "Quando WINONA lotta, il suo volto\n"
	.string "brilla di splendida determinazione…\p"
	.string "Non ti lascio ammirare\n"
	.string "tale incanto!$"

FortreeCity_Gym_Text_HumbertoDefeat:
	.string "Argh!\n"
	.string "Non ti ho fermato.$"

FortreeCity_Gym_Text_HumbertoPostBattle:
	.string "Occhio!\n"
	.string "Non distrarti fissando WINONA\l"
	.string "o finirai a terra con un tonfo!$"

FortreeCity_Gym_Text_DariusIntro:
	.string "Sappi che ci sono davvero molti\n"
	.string "POKéMON di tipo VOLANTE.\p"
	.string "Lo sai già, vero?$"

FortreeCity_Gym_Text_DariusDefeat:
	.string "Sembri saperne parecchio!$"

FortreeCity_Gym_Text_DariusPostBattle:
	.string "Certo, mi hai battuto.\n"
	.string "Ma stai attento! Il nostro CAPO\l"
	.string "Quelli di WINONA non scherzano.$"

FortreeCity_Gym_Text_WinonaIntro:
	.string "Sono WINONA. Guido la PALESTRA\n"
	.string "POKéMON di FORTREE.\p"
	.string "Sono tutt'uno con i POKéMON\n"
	.string "UCCELLO e ho solcato i cieli…\p"
	.string "Per quanto dura sia la lotta,\n"
	.string "vinciamo con grazia…\p"
	.string "Ammira l'elegante coreografia\n"
	.string "dei miei POKéMON UCCELLO!$"

FortreeCity_Gym_Text_WinonaDefeat:
	.string "Mai visto un ALLENATORE\n"
	.string "comandare POKéMON con grazia\l"
	.string "di me…\p"
	.string "Per il tuo valore,\n"
	.string "ti dono questa MEDAGLIA.$"

FortreeCity_Gym_Text_ReceivedFeatherBadge:
	.string "{PLAYER} riceve la MEDAGLIA PIUMA\n"
	.string "da WINONA.$"

FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis:
	.string "Con la PIUMASTRELLA, tutti i POKéMON\n"
	.string "fino al Lv. 70, anche quelli\l"
	.string "scambiati, ti obbediranno in tutto.\p"
	.string "Potrai anche usare\n"
	.string "la MN VOLO fuori dalla lotta.\p"
	.string "E questo…\n"
	.string "È un mio regalo.$"

FortreeCity_Gym_Text_ExplainAerialAce:
	.string "MT40 contiene AEROASSALTO.\p"
	.string "Velocità…\n"
	.string "Nessun POKéMON può schivarla.\p"
	.string "… … … … … …$"

FortreeCity_Gym_Text_RegisteredWinona:
	.string "Registrato CAPOPALESTRA WINONA\n"
	.string "nel POKéNAV.$"

FortreeCity_Gym_Text_WinonaPostBattle:
	.string "Anche se ho perso, resterò\n"
	.string "fedele ai POKéMON UCCELLO.$"

FortreeCity_Gym_Text_GymStatue:
	.string "PALESTRA POKéMON DI FORTREE$"

FortreeCity_Gym_Text_GymStatueCertified:
	.string "PALESTRA POKéMON DI FORTREE\p"
	.string "CERTIFICATI DA WINONA:\n"
	.string "{PLAYER}$"

FortreeCity_Gym_Text_WinonaPreRematch:
	.string "WINONA: Noi umani non possiamo\n"
	.string "sfuggire alla gravità.\p"
	.string "Ma puntando all'eccellenza,\n"
	.string "possiamo spiccare il volo!\p"
	.string "Hai scalato la vetta come\n"
	.string "CAMPIONE in carica.\p"
	.string "Ti prego, fammi vedere la tua\n"
	.string "forza in volo!$"

FortreeCity_Gym_Text_WinonaRematchDefeat:
	.string "Non ho raggiunto la tua altezza…$"

FortreeCity_Gym_Text_WinonaPostRematch:
	.string "WINONA: Anche se ho perso,\n"
	.string "le ali del mio cuore sono intatte.\p"
	.string "Posso risollevarmi e volare\n"
	.string "ancora e ancora.\p"
	.string "Ne sono convinta!$"

FortreeCity_Gym_Text_WinonaRematchNeedTwoMons:
	.string "WINONA: Noi umani non sfuggiamo\n"
	.string "alla forza di gravità.\p"
	.string "Ma puntando all'eccellenza,\n"
	.string "possiamo spiccare il volo!\p"
	.string "Hai raggiunto la vetta come\n"
	.string "CAMPIONE in carica.\p"
	.string "Fammi vedere la tua forza\n"
	.string "in pieno volo!\p"
	.string "Oh, no… Hai solo un\n"
	.string "POKéMON con te?\p"
	.string "Torna con due POKéMON,\n"
	.string "come minimo.$"
