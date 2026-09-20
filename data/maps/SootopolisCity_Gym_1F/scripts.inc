SootopolisCity_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_Gym_1F_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_Gym_1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_Gym_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_Gym_1F_OnTransition
	.byte 0

SootopolisCity_Gym_1F_OnTransition:
	setvar VAR_ICE_STEP_COUNT, 1
	end

SootopolisCity_Gym_1F_OnResume:
	setstepcallback STEP_CB_SOOTOPOLIS_ICE
	end

SootopolisCity_Gym_1F_OnLoad:
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special SetSootopolisGymCrackedIceMetatiles
	end

SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles::
	goto_if_lt VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_StopCheckingStairs  @ All stairs ice
	goto_if_lt VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_OpenFirstStairs
	goto_if_lt VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs
	setmetatile 8, 4, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 5, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs::
	setmetatile 8, 10, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 11, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstStairs::
	setmetatile 8, 15, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 16, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_StopCheckingStairs::
	return

SootopolisCity_Gym_1F_OnFrame:
	map_script_2 VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs
	map_script_2 VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs
	map_script_2 VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs
	map_script_2 VAR_ICE_STEP_COUNT, 0, SootopolisCity_Gym_1F_EventScript_FallThroughIce
	.2byte 0

SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_FallThroughIce::
	lockall
	delay 20
	applymovement LOCALID_PLAYER, SootopolisCity_Gym_1F_Movement_FallThroughIce
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_SOOTOPOLIS_CITY_GYM_B1F
	waitstate
	end

SootopolisCity_Gym_1F_Movement_FallThroughIce:
	set_invisible
	step_end

SootopolisCity_Gym_1F_EventScript_Juan::
	trainerbattle_single TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanIntro, SootopolisCity_Gym_1F_Text_JuanDefeat, SootopolisCity_Gym_1F_EventScript_JuanDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_Gym_1F_EventScript_JuanRematch
	goto_if_unset FLAG_RECEIVED_TM_WATER_PULSE, SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2
	goto_if_unset FLAG_BADGE06_GET, SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge
	msgbox SootopolisCity_Gym_1F_Text_JuanPostBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanDefeated::
	message SootopolisCity_Gym_1F_Text_ReceivedRainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
	setflag FLAG_BADGE08_GET
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	setvar VAR_SOOTOPOLIS_CITY_STATE, 6
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers
	call SootopolisCity_Gym_1F_EventScript_GiveWaterPulse
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SootopolisCity_Gym_1F_Text_RegisteredJuan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_JUAN_MATCH_CALL
	release
	end

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	return

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	release
	end

SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge::
	msgbox SootopolisCity_Gym_1F_Text_GoGetFortreeBadge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanRematch::
	trainerbattle_rematch_double TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanPreRematch, SootopolisCity_Gym_1F_Text_JuanRematchDefeat, SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons
	msgbox SootopolisCity_Gym_1F_Text_JuanPostRematch, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SOOTOPOLIS_GYM, SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory
	msgbox SootopolisCity_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox SootopolisCity_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_GymStatueCertified::
	msgbox SootopolisCity_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_GymStatue::
	msgbox SootopolisCity_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_Text_GymGuideAdvice:
	.string "Ehi! Come va, futuro\n"
	.string "CAMPIONE {PLAYER}?\p"
	.string "JUAN, CAPOPALESTRA di SOOTOPOLIS,\n"
	.string "è un maestro dei POKéMON d'Acqua.\p"
	.string "E per arrivare a JUAN, un pavimento\n"
	.string "ghiacciato ti ostacolerà…\p"
	.string "Mi spiace, ma questo è tutto il\n"
	.string "consiglio che ho per te.\p"
	.string "Il resto del cammino devi\n"
	.string "farcela da solo!$"

SootopolisCity_Gym_1F_Text_GymGuidePostVictory:
	.string "Wow! Hai battuto persino JUAN, che\n"
	.string "era il più forte di tutta HOENN!\p"
	.string "Ok! Guarda la tua SCHEDA ALLENATORE.\p"
	.string "Con tutte le MEDAGLIE, sei pronto\n"
	.string "per la LEGA POKéMON!$"

SootopolisCity_Gym_1F_Text_JuanIntro:
	.string "Lascia che ti chieda.\n"
	.string "Lo sapevi?\l"
	.string "Ah, non sarò così sfuggente.\p"
	.string "Sono io che ho insegnato a WALLACE\n"
	.string "tutto sui POKéMON.\p"
	.string "Un tempo avevo lasciato il ruolo\n"
	.string "di CAPOPALESTRA.\p"
	.string "Al mio posto avevo affidato a WALLACE\n"
	.string "la PALESTRA.\p"
	.string "Però è sorta una ragione impellente\n"
	.string "per il mio ritorno.\p"
	.string "Ah, basta chiacchiere.\n"
	.string "Iniziamo la nostra sfida, va bene?\p"
	.string "Ti prego, sarai testimone\n"
	.string "della nostra arte.\p"
	.string "Una grande illusione d'acqua creata\n"
	.string "dai POKéMON e da me!$"

@ NOTE: This defeat text actually causes a buffer overflow. It's about 50 bytes too long for
@ the gDisplayedStringBattle buffer that it's put into, and it stomps all over the gBattleTextBuffs
@ after, as well as the otherwise unused array after that. One wonders if that's the reason for
@ the existence of that unused array of ints.
SootopolisCity_Gym_1F_Text_JuanDefeat:
	.string "Ahahaha, eccellente!\n"
	.string "Molto bene, hai vinto.\p"
	.string "Da te sento lo splendore\n"
	.string "di un'abilità che vincerà tutto.\p"
	.string "Però, rispetto a me o a\n"
	.string "WALLACE, ti manca l'eleganza.\p"
	.string "Forse dovrei prestarti\n"
	.string "il mio abito?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Ahahaha, scherzavo!\p"
	.string "Invece dei miei vestiti, ti darò\n"
	.string "questo, la MEDAGLIA PIOGGIA!$"

SootopolisCity_Gym_1F_Text_ReceivedRainBadge:
	.string "{PLAYER} riceve la MEDAGLIA PIOGGIA\n"
	.string "da JUAN.$"

SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis:
	.string "Con la MEDAGLIA PIOGGIA avrai\n"
	.string "la totale obbedienza di tutti i POKéMON\l"
	.string "a ogni tuo comando.\p"
	.string "La MEDAGLIA PIOGGIA consente anche\n"
	.string "di usare la MN CASCATA per scalare\l"
	.string "pareti d'acqua che precipitano.\p"
	.string "E perché tu non dimentichi mai la\n"
	.string "battaglia che abbiamo fatto, prendi…$"

SootopolisCity_Gym_1F_Text_ExplainWaterPulse:
	.string "La MT che ti ho dato\n"
	.string "contiene IDROGETTO.\p"
	.string "A volte confonde il bersaglio\n"
	.string "con onde ultrasoniche.\p"
	.string "… … … … … …$"

SootopolisCity_Gym_1F_Text_RegisteredJuan:
	.string "CAPOPALESTRA JUAN registrato\n"
	.string "nel POKéNAV.$"

SootopolisCity_Gym_1F_Text_JuanPostBattle:
	.string "Gli ALLENATORI che hanno tutte\n"
	.string "le MEDAGLIE di HOENN devono\l"
	.string "andare alla meta finale.\p"
	.string "La LEGA POKéMON.\p"
	.string "Recati all'estremo est\n"
	.string "di HOENN, sull'isola EVER GRANDE.\p"
	.string "Lì troverai la LEGA\n"
	.string "POKéMON.$"

SootopolisCity_Gym_1F_Text_GoGetFortreeBadge:
	.string "Resta solo una MEDAGLIA da\n"
	.string "ottenere a HOENN.\p"
	.string "Per sfidare la LEGA POKéMON\n"
	.string "devi prendere l'ultima MEDAGLIA\l"
	.string "dalla PALESTRA di FORTREE.$"

SootopolisCity_Gym_1F_Text_GymStatue:
	.string "PALESTRA POKéMON DI SOOTOPOLIS$"

SootopolisCity_Gym_1F_Text_GymStatueCertified:
	.string "PALESTRA POKéMON DI SOOTOPOLIS\p"
	.string "ALLENATORI CERTIFICATI DA JUAN:\n"
	.string "{PLAYER}$"

SootopolisCity_Gym_1F_Text_JuanPreRematch:
	.string "JUAN: Ah, questa PALESTRA era tornata\n"
	.string "alla sua solita serenità…\p"
	.string "Ma il nostro giovane tifone è tornato\n"
	.string "a metterci di nuovo alla prova!\p"
	.string "Ebbene, amico mio, certo!\p"
	.string "Sarò felice di danzare con te\n"
	.string "tutte le volte che vorrai!$"

SootopolisCity_Gym_1F_Text_JuanRematchDefeat:
	.string "Ahahaha, hai vinto!\n"
	.string "Mi hai battuto di nuovo!$"

SootopolisCity_Gym_1F_Text_JuanPostRematch:
	.string "JUAN: Se ti chiedessi di diventare\n"
	.string "mio allievo, sono certo che rifiuteresti.\p"
	.string "Vorrei regalarti il mio\n"
	.string "cappotto.\p"
	.string "Ma anche così, rifiuteresti.\n"
	.string "Immagino di sì.\p"
	.string "E questo, amico mio, è segno\n"
	.string "di nobiltà!$"

SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons:
	.string "JUAN: Ah, questa PALESTRA era tornata\n"
	.string "alla sua solita serenità…\p"
	.string "Ma il nostro giovane tifone è tornato\n"
	.string "a metterci di nuovo alla prova!\p"
	.string "Ebbene, amico mio, certo!\n"
	.string "Sarò felice di danzare con te…\p"
	.string "Ah, no, no, no.\n"
	.string "Hai con te un solo POKéMON.\p"
	.string "Vorrei che tornassi con\n"
	.string "due, o forse più, POKéMON.$"

