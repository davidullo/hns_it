MossdeepCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_Gym_OnLoad
	.byte 0

@ NOTE: Mossdeep Gym was redesigned between R/S and E. Leftover (and now functionally unused) scripts are commented below

MossdeepCity_Gym_OnTransition:
	setflag FLAG_TEMP_HIDE_FOLLOWER @ Hide follower since it can collide with moving statues
	end

@ All the below checks are leftover from RS. FLAG_MOSSDEEP_GYM_SWITCH_X is never set
MossdeepCity_Gym_OnLoad:
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_SetSwitch1Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_CheckSwitch2::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_SetSwitch2Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_CheckSwitch3::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_SetSwitch3Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_CheckSwitch4::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_SetSwitch4Metatiles
	end

@ All the below set metatile scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_SetSwitch1Metatiles::
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_SetSwitch2Metatiles::
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_SetSwitch3Metatiles::
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_SetSwitch4Metatiles::
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	end

MossdeepCity_Gym_EventScript_TateAndLiza::
	trainerbattle_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaIntro, MossdeepCity_Gym_Text_TateAndLizaDefeat, MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons, MossdeepCity_Gym_EventScript_TateAndLizaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_Gym_EventScript_TateAndLizaRematch
	goto_if_unset FLAG_RECEIVED_TM_CALM_MIND, MossdeepCity_Gym_EventScript_GiveCalmMind2
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_TateAndLizaDefeated::
	message MossdeepCity_Gym_Text_ReceivedMindBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
	setflag FLAG_BADGE07_GET
	setflag FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
	clearflag FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY
	clearflag FLAG_UNKNOWN_0x393
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	clearflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
	setvar VAR_MOSSDEEP_CITY_STATE, 1
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	call MossdeepCity_Gym_EventScript_GiveCalmMind
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MossdeepCity_Gym_Text_RegisteredTateAndLiza, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind2::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	return

MossdeepCity_Gym_EventScript_TateAndLizaRematch::
	trainerbattle_rematch_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaPreRematch, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat, MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostRematch, MSGBOX_AUTOCLOSE
	end

@ All the below switch scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_ClearSwitch1
	setflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed::
	special DrawWholeMapView
	playse SE_CLICK
	releaseall
	end

MossdeepCity_Gym_EventScript_ClearSwitch1::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_ClearSwitch2
	setflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch2::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Down, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_ClearSwitch3
	setflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch3::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_ClearSwitch4
	setflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch4::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_WarpToEntrance::
	lockall
	warpmossdeepgym MAP_MOSSDEEP_CITY_GYM, 7, 30
	waitstate
	releaseall
	end

MossdeepCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_PRESTON, MossdeepCity_Gym_Text_PrestonIntro, MossdeepCity_Gym_Text_PrestonDefeat
	msgbox MossdeepCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Virgil::
	trainerbattle_single TRAINER_VIRGIL, MossdeepCity_Gym_Text_VirgilIntro, MossdeepCity_Gym_Text_VirgilDefeat
	msgbox MossdeepCity_Gym_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Blake::
	trainerbattle_single TRAINER_BLAKE, MossdeepCity_Gym_Text_BlakeIntro, MossdeepCity_Gym_Text_BlakeDefeat
	msgbox MossdeepCity_Gym_Text_BlakePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Hannah::
	trainerbattle_single TRAINER_HANNAH, MossdeepCity_Gym_Text_HannahIntro, MossdeepCity_Gym_Text_HannahDefeat
	msgbox MossdeepCity_Gym_Text_HannahPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Samantha::
	trainerbattle_single TRAINER_SAMANTHA, MossdeepCity_Gym_Text_SamanthaIntro, MossdeepCity_Gym_Text_SamanthaDefeat
	msgbox MossdeepCity_Gym_Text_SamanthaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Maura::
	trainerbattle_single TRAINER_MAURA, MossdeepCity_Gym_Text_MauraIntro, MossdeepCity_Gym_Text_MauraDefeat
	msgbox MossdeepCity_Gym_Text_MauraPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Sylvia::
	trainerbattle_single TRAINER_SYLVIA, MossdeepCity_Gym_Text_SylviaIntro, MossdeepCity_Gym_Text_SylviaDefeat
	msgbox MossdeepCity_Gym_Text_SylviaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nate::
	trainerbattle_single TRAINER_NATE, MossdeepCity_Gym_Text_NateIntro, MossdeepCity_Gym_Text_NateDefeat
	msgbox MossdeepCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Macey::
	trainerbattle_single TRAINER_MACEY, MossdeepCity_Gym_Text_MaceyIntro, MossdeepCity_Gym_Text_MaceyDefeat
	msgbox MossdeepCity_Gym_Text_MaceyPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Clifford::
	trainerbattle_single TRAINER_CLIFFORD, MossdeepCity_Gym_Text_CliffordIntro, MossdeepCity_Gym_Text_CliffordDefeat
	msgbox MossdeepCity_Gym_Text_CliffordPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nicholas::
	trainerbattle_single TRAINER_NICHOLAS, MossdeepCity_Gym_Text_NicholasIntro, MossdeepCity_Gym_Text_NicholasDefeat
	msgbox MossdeepCity_Gym_Text_NicholasPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Kathleen::
	trainerbattle_single TRAINER_KATHLEEN, MossdeepCity_Gym_Text_KathleenIntro, MossdeepCity_Gym_Text_KathleenDefeat
	msgbox MossdeepCity_Gym_Text_KathleenPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MOSSDEEP_GYM, MossdeepCity_Gym_EventScript_GymGuidePostVictory
	msgbox MossdeepCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MossdeepCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

@ Leftover from RS, functionally unused
MossdeepCity_Gym_Movement_WaitAfterSwitchUse:
	delay_16
	delay_16
	step_end

MossdeepCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_GymStatueCertified::
	msgbox MossdeepCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_GymStatue::
	msgbox MossdeepCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_YellowFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 0
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_BlueFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 1
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_GreenFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 2
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_PurpleFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 3
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_RedFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 4
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_Text_GymGuideAdvice:
	.string "Ehi, come va, campione in erba\n"
	.string "{PLAYER}?\p"
	.string "I CAPIPALESTRA qui usano\n"
	.string "POKéMON di tipo PSICHICO.\p"
	.string "Se li affronti con POKéMON di tipo\n"
	.string "LOTTA o VELENO,\l"
	.string "ti faranno danni tremendi!\p"
	.string "E ti attaccano anche con\n"
	.string "combinazioni eccezionali.\p"
	.string "Per vincere devi mostrare loro\n"
	.string "quanto siete affiatati tu e i tuoi\l"
	.string "POKéMON. Vai e combatti!$"

MossdeepCity_Gym_Text_GymGuidePostVictory:
	.string "Caspita, sei incredibile!\n"
	.string "Sei un ALLENATORE formidabile!$"

MossdeepCity_Gym_Text_PrestonIntro:
	.string "Le lotte dipendono dalla forza del tuo\n"
	.string "spirito! I deboli non vincono mai!$"

MossdeepCity_Gym_Text_PrestonDefeat:
	.string "Ho perso!\n"
	.string "Devo temprare di nuovo il mio spirito!$"

MossdeepCity_Gym_Text_PrestonPostBattle:
	.string "Gli indecisi perdono.\n"
	.string "Questo è il mio avvertimento.$"

MossdeepCity_Gym_Text_VirgilIntro:
	.string "Mostrami il tuo talento!$"

MossdeepCity_Gym_Text_VirgilDefeat:
	.string "Hai un talento spettacolare!$"

MossdeepCity_Gym_Text_VirgilPostBattle:
	.string "Se esistono i prodigi al mondo,\n"
	.string "i nostri CAPIPALESTRA lo sono!\p"
	.string "Però tu potresti essere ancora più\n"
	.string "bravo di loro…$"

MossdeepCity_Gym_Text_BlakeIntro:
	.string "Fufufufu… Guarda come sollevo una\n"
	.string "POKé BALL col pensiero!\p"
	.string "Wrooooooooaaaar!\n"
	.string "… … … … … … …\p"
	.string "A volte sono fuori fase…$"

MossdeepCity_Gym_Text_BlakeDefeat:
	.string "Anche le mie doti di ALLENATORE\n"
	.string "sono fuori fase!$"

MossdeepCity_Gym_Text_BlakePostBattle:
	.string "Una POKé BALL era troppo pesante\n"
	.string "per la psicocinesi. Ma questo piumino…\p"
	.string "Whoooooooooooooooh!\n"
	.string "… … … … … …\p"
	.string "No, non sto barando!\n"
	.string "Non ci ho soffiato sopra! Davvero!$"

MossdeepCity_Gym_Text_HannahIntro:
	.string "Se perdi contro di me, non essere\n"
	.string "troppo severo con te stesso.\p"
	.string "Non sei debole, sono io\n"
	.string "troppo forte!$"

MossdeepCity_Gym_Text_HannahDefeat:
	.string "Sei davvero troppo forte!$"

MossdeepCity_Gym_Text_HannahPostBattle:
	.string "Non mi abbatto per una sconfitta.\n"
	.string "Devo solo allenarmi di più.\p"
	.string "Il pensiero positivo è il mio\n"
	.string "punto forte!$"

MossdeepCity_Gym_Text_SamanthaIntro:
	.string "Vedo…\n"
	.string "Vedo il tuo futuro…\p"
	.string "Se riesci a battermi, ti dirò\n"
	.string "il tuo futuro!$"

MossdeepCity_Gym_Text_SamanthaDefeat:
	.string "Mi arrendo!$"

MossdeepCity_Gym_Text_SamanthaPostBattle:
	.string "Affronterai una lotta terribilmente\n"
	.string "intensa con i nostri CAPIPALESTRA…\p"
	.string "Il risultato…\n"
	.string "Non lo sentirai da me!$"

MossdeepCity_Gym_Text_MauraIntro:
	.string "Le strade che hai percorso…\n"
	.string "Ciò che hai imparato…\p"
	.string "Attaccami con tutto quello che\n"
	.string "sai fare!$"

MossdeepCity_Gym_Text_MauraDefeat:
	.string "Hai percorso la via della grandezza!$"

MossdeepCity_Gym_Text_MauraPostBattle:
	.string "Un futuro brillante attende chi ha\n"
	.string "lavorato con impegno.\p"
	.string "Per chi è stato pigro, alla fine\n"
	.string "c'è solo disperazione.\p"
	.string "Chi semina raccoglie…$"

MossdeepCity_Gym_Text_SylviaIntro:
	.string "Anche a rischio della vita, vincerò\n"
	.string "questa lotta!$"

MossdeepCity_Gym_Text_SylviaDefeat:
	.string "Ciò che fai…\n"
	.string "Mi inorridisce…$"

MossdeepCity_Gym_Text_SylviaPostBattle:
	.string "Come osi battermi…\p"
	.string "Non sarà colpa mia se ti accadrà\n"
	.string "qualcosa di orribile…$"

MossdeepCity_Gym_Text_NateIntro:
	.string "Hohoho.\p"
	.string "Devo mostrarti quanto può essere\n"
	.string "tenace il tipo PSICO.$"

MossdeepCity_Gym_Text_NateDefeat:
	.string "Oh! Perbacco!\n"
	.string "Il tuo stile di lotta è fantastico!$"

MossdeepCity_Gym_Text_NatePostBattle:
	.string "Io… io non mi lascio turbare da una\n"
	.string "sconfitta, per brutta che sia.$"

MossdeepCity_Gym_Text_KathleenIntro:
	.string "Ti farò passare un momento\n"
	.string "davvero orribile!$"

MossdeepCity_Gym_Text_KathleenDefeat:
	.string "N-noooooo!$"

MossdeepCity_Gym_Text_KathleenPostBattle:
	.string "La tua vitalità è contagiosa!\n"
	.string "Allontanati subito da me!$"

MossdeepCity_Gym_Text_CliffordIntro:
	.string "Sarò pure vecchio, ma ti consiglio\n"
	.string "di non prendermi in giro.$"

MossdeepCity_Gym_Text_CliffordDefeat:
	.string "Ah, trabocchi della forza\n"
	.string "della gioventù!$"

MossdeepCity_Gym_Text_CliffordPostBattle:
	.string "A quanto pare non ho saputo reggere\n"
	.string "la tua energia giovanile.$"

MossdeepCity_Gym_Text_MaceyIntro:
	.string "Non arriverai fino in fondo!\n"
	.string "Non se posso impedirlo!$"

MossdeepCity_Gym_Text_MaceyDefeat:
	.string "Come puoi essere così assurda-\n"
	.string "mente forte?$"

MossdeepCity_Gym_Text_MaceyPostBattle:
	.string "Umpf! Sarai pure forte, ma non sei\n"
	.string "adatto al tipo PSICO!\p"
	.string "Il tuo modo di lottare è brutale!$"

MossdeepCity_Gym_Text_NicholasIntro:
	.string "Wroooar! Assaggia la mia super\n"
	.string "potenza in lotta POKéMON!$"

MossdeepCity_Gym_Text_NicholasDefeat:
	.string "Oh!\n"
	.string "Sconfitto!$"

MossdeepCity_Gym_Text_NicholasPostBattle:
	.string "Bene! Ora svilupperò un potere\n"
	.string "POKéMON invincibile speciale.$"

MossdeepCity_Gym_Text_TateAndLizaIntro:
	.string "TATE: Eh eh… Sorpresa?\p"
	.string "LIZA: Ih ih… Sorpresa?\p"
	.string "TATE: Che ci sono due CAPIPALESTRA?\n"
	.string "LIZA: Che ci sono due CAPIPALESTRA?\p"
	.string "TATE: Siamo gemelli!\n"
	.string "LIZA: Siamo gemelli!\p"
	.string "TATE: Non ci serve parlare perché…\n"
	.string "LIZA: Possiamo capire cosa…\p"
	.string "TATE: Pensa l'altro…\n"
	.string "LIZA: Tutto con la mente!\p"
	.string "TATE: Questa nostra combinazione…\n"
	.string "LIZA: Saprai batterla?$"

MossdeepCity_Gym_Text_TateAndLizaDefeat:
	.string "TATE: Cosa?! La nostra combinazione…\n"
	.string "LIZA: È andata in frantumi!\p"
	.string "TATE: Non c'è rimedio. Avete vinto…\n"
	.string "LIZA: In segno di ciò, prendi questo.$"

MossdeepCity_Gym_Text_ReceivedMindBadge:
	.string "{PLAYER} riceve la MENTEBADGE\n"
	.string "da TATE e LIZA.$"

MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis:
	.string "TATE: La MEDAGLIA MENTE potenzia\n"
	.string "l'ATT. SP. e la DIF. SP. dei POKéMON.\p"
	.string "LIZA: Inoltre ti fa usare la mossa MN\n"
	.string "SUB fuori dalla lotta.\p"
	.string "TATE: E prendi anche questa.$"

MossdeepCity_Gym_Text_ExplainCalmMind:
	.string "TATE: In questa MT04 c'è…\n"
	.string "LIZA: CALMA MENTALE!\p"
	.string "TATE: Alza l'ATT. SP. e…\n"
	.string "LIZA: Alza la DIF. SP.!\p"
	.string "TATE: È una mossa perfetta…\n"
	.string "LIZA: Per i POKéMON PSICO!\p"
	.string "… … … … … …$"

MossdeepCity_Gym_Text_RegisteredTateAndLiza:
	.string "CAPOPALESTRA TATE e LIZA\n"
	.string "registrati nel POKéNAV.$"

MossdeepCity_Gym_Text_TateAndLizaPostBattle:
	.string "TATE: Il legame tra te e i tuoi\n"
	.string "POKéMON è molto più forte\l"
	.string "del legame che ci unisce come gemelli.\p"
	.string "LIZA: Diventerai ancora più forte!\n"
	.string "Ti abbiamo sfidato, quindi lo sappiamo.$"

MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons:
	.string "TATE: Eh eh… Sorpresa?\p"
	.string "LIZA: Che ci sono due CAPIPALESTRA?\p"
	.string "TATE: Ops, ne hai solo uno…\n"
	.string "LIZA: di POKéMON che può lottare.\p"
	.string "TATE: Così non possiamo lottare!\p"
	.string "LIZA: Se vuoi sfidarci,\n"
	.string "porta altri POKéMON.$"

MossdeepCity_Gym_Text_GymStatue:
	.string "PALESTRA POKéMON DI MOSSDEEP$"

MossdeepCity_Gym_Text_GymStatueCertified:
	.string "PALESTRA POKéMON DI MOSSDEEP\p"
	.string "ALLENATORI CERTIFICATI DA LIZA E TATE:\n"
	.string "{PLAYER}$"

MossdeepCity_Gym_Text_TateAndLizaPreRematch:
	.string "TATE: POKéMON…\n"
	.string "LIZA: POKéMON…\p"
	.string "TATE: Cambiando la squadra…\n"
	.string "LIZA: Cambia lo stile di lotta.\p"
	.string "TATE: Ma io…\n"
	.string "LIZA: Ma io…\p"
	.string "TATE: Sarò sempre con LIZA!\n"
	.string "LIZA: Sarò sempre con TATE!\p"
	.string "TATE: La nostra combinazione…\n"
	.string "LIZA: Te la mostreremo ancora e ancora!$"

MossdeepCity_Gym_Text_TateAndLizaRematchDefeat:
	.string "TATE: Tu e i tuoi POKéMON…\n"
	.string "LIZA: Sembrate fratelli!$"

MossdeepCity_Gym_Text_TateAndLizaPostRematch:
	.string "TATE: Puoi buttarci giù,\n"
	.string "ma non resteremo mai a terra!\p"
	.string "LIZA: Perché noi due,\n"
	.string "ci sosteniamo sempre a vicenda!$"

MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons:
	.string "TATE: Sei tornato…\n"
	.string "LIZA: Sei tornato…\p"
	.string "TATE: Per la rivincita.\n"
	.string "LIZA: Per la rivincita.\p"
	.string "TATE: Ma…\n"
	.string "LIZA: Per la nostra lotta…\p"
	.string "TATE: Hai portato un solo POKéMON!\n"
	.string "LIZA: Hai portato un solo POKéMON!\p"
	.string "TATE: Devi portarne almeno…\n"
	.string "LIZA: Due quando torni.$"
