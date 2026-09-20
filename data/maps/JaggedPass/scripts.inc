JaggedPass_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, JaggedPass_OnLoad
	.byte 0

JaggedPass_OnResume:
	setstepcallback STEP_CB_ASH
	call_if_eq VAR_JAGGED_PASS_STATE, 0, JaggedPass_EventScript_CheckHasMagmaEmblem
	end

JaggedPass_EventScript_CheckHasMagmaEmblem::
	checkitem ITEM_MAGMA_EMBLEM
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_SetReadyToOpenHideout
	return

JaggedPass_EventScript_SetReadyToOpenHideout::
	setvar VAR_JAGGED_PASS_STATE, 1
	return

JaggedPass_OnTransition:
	call_if_eq VAR_JAGGED_PASS_ASH_WEATHER, 1, JaggedPass_EventScript_SetWeatherAsh
	end

JaggedPass_EventScript_SetWeatherAsh::
	setweather WEATHER_VOLCANIC_ASH
	doweather
	return

JaggedPass_OnLoad:
	goto_if_le VAR_JAGGED_PASS_STATE, 1, JaggedPass_EventScript_ConcealHideoutEntrance
	end

JaggedPass_EventScript_ConcealHideoutEntrance::
	setmetatile 16, 17, METATILE_Lavaridge_RockWall, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_RockWall, TRUE
	end

JaggedPass_EventScript_OpenMagmaHideout::
	lockall
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	msgbox JaggedPass_Text_BoulderShakingInResponseToEmblem, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 3   @ shake delay
	special ShakeCamera
	waitstate
	playse SE_EFFECTIVE
	setmetatile 16, 17, METATILE_Lavaridge_CaveEntrance_Top, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_CaveEntrance_Bottom, FALSE
	special DrawWholeMapView
	delay 30
	setvar VAR_JAGGED_PASS_STATE, 2
	waitse
	releaseall
	end

JaggedPass_EventScript_MagmaHideoutGuard::
	lockall
	goto_if_set FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS, JaggedPass_EventScript_GuardDefeated
	waitse
	playse SE_PIN
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GruntIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_JAGGED_PASS, JaggedPass_Text_GruntDefeat
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_GuardDefeated::
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GoWhereverYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_Eric::
	trainerbattle_single TRAINER_ERIC, JaggedPass_Text_EricIntro, JaggedPass_Text_EricDefeat
	msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Diana::
	trainerbattle_single TRAINER_DIANA_1, JaggedPass_Text_DianaIntro, JaggedPass_Text_DianaDefeat, JaggedPass_EventScript_RegisterDiana
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_DianaRematch
	msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterDiana::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_DianaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DIANA_1
	release
	end

JaggedPass_EventScript_DianaRematch::
	trainerbattle_rematch TRAINER_DIANA_1, JaggedPass_Text_DianaRematchIntro, JaggedPass_Text_DianaRematchDefeat
	msgbox JaggedPass_Text_DianaPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Ethan::
	trainerbattle_single TRAINER_ETHAN_1, JaggedPass_Text_EthanIntro, JaggedPass_Text_EthanDefeat, JaggedPass_EventScript_RegisterEthan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_EthanRematch
	msgbox JaggedPass_Text_EthanPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterEthan::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_EthanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ETHAN_1
	release
	end

JaggedPass_EventScript_EthanRematch::
	trainerbattle_rematch TRAINER_ETHAN_1, JaggedPass_Text_EthanRematchIntro, JaggedPass_Text_EthanRematchDefeat
	msgbox JaggedPass_Text_EthanPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Julio::
	trainerbattle_single TRAINER_JULIO, JaggedPass_Text_JulioIntro, JaggedPass_Text_JulioDefeat
	msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Autumn::
	trainerbattle_single TRAINER_AUTUMN, JaggedPass_Text_AutumnIntro, JaggedPass_Text_AutumnDefeat
	msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_Text_EricIntro:
	.string "Il PASSAGGIO di MONTE CAMINO…\p"
	.string "Ecco ciò che ho sempre voluto\n"
	.string "da una montagna.\p"
	.string "Questa sconnessione…\n"
	.string "Mi scuote l'anima!$"

JaggedPass_Text_EricDefeat:
	.string "Perdere mi ha lasciato l'amaro!$"

JaggedPass_Text_EricPostBattle:
	.string "Sì, ho perso ai POKéMON…\p"
	.string "Ma sull'amore per la montagna\n"
	.string "ti batto!$"

JaggedPass_Text_DianaIntro:
	.string "Questo posto non è una passeggiata.\n"
	.string "Non è adatto a un picnic.$"

JaggedPass_Text_DianaDefeat:
	.string "Oh, no!\n"
	.string "Il terreno è troppo sconnesso…$"

JaggedPass_Text_DianaPostBattle:
	.string "Lo sapevi?\p"
	.string "C'è chi sale in BICICLETTA\n"
	.string "su questo passo malridotto.$"

JaggedPass_Text_DianaRegister:
	.string "Tornerai da queste parti?\n"
	.string "Se torni, mi piacerebbe la rivincita.$"

JaggedPass_Text_DianaRematchIntro:
	.string "I picnic sono belli ovunque.\n"
	.string "Proprio come i POKéMON!$"

JaggedPass_Text_DianaRematchDefeat:
	.string "Ho perso solo perché il terreno\n"
	.string "è troppo sconnesso!$"

JaggedPass_Text_DianaPostRematch:
	.string "Dimentico la sconfitta e mi\n"
	.string "godo questa camminata sconnessa.$"

JaggedPass_Text_EthanIntro:
	.string "Sul PASSAGGIO si cammina male.\n"
	.string "È un buon posto per allenarsi.$"

JaggedPass_Text_EthanDefeat:
	.string "Era già finita mentre cercavamo\n"
	.string "un appoggio stabile…$"

JaggedPass_Text_EthanPostBattle:
	.string "Con la BICI da cross potrei\n"
	.string "saltare i dirupi.$"

JaggedPass_Text_EthanRegister:
	.string "Quando sarò abituato a questo\n"
	.string "terreno, vincerò di sicuro!\p"
	.string "Mi registri sul POKéNAV?$"

JaggedPass_Text_EthanRematchIntro:
	.string "Mi sono abituato al terreno.\n"
	.string "Ora canto mentre salgo.$"

JaggedPass_Text_EthanRematchDefeat:
	.string "Non è ancora facile lottare\n"
	.string "su questo terreno sconnesso…$"

JaggedPass_Text_EthanPostRematch:
	.string "Dovrei prendere la BICI da cross\n"
	.string "da RYDEL a MAUVILLE…$"

JaggedPass_Text_GruntIntro:
	.string "Wah!\n"
	.string "Che ci fai tu qui?\p"
	.string "E io che ci faccio in un posto così?\p"
	.string "E a te che importa?$"

JaggedPass_Text_GruntDefeat:
	.string "Urrrgh…\p"
	.string "Dovevo filare al NOSTRO\n"
	.string "nascondiglio subito…$"

JaggedPass_Text_GoWhereverYouWant:
	.string "Va bene, va bene!\n"
	.string "Ammetto che sei forte!\p"
	.string "Non pensare a me.\n"
	.string "Vai dove vuoi!$"

JaggedPass_Text_BoulderShakingInResponseToEmblem:
	.string "Oh! Questo masso trema in risposta\n"
	.string "all'EMBLEMA MAGMA!$"

JaggedPass_Text_JulioIntro:
	.string "Ahi! Fa un male cane scendere\n"
	.string "dal monte tutto d'un fiato!$"

JaggedPass_Text_JulioDefeat:
	.string "Mi sento a pezzi…$"

JaggedPass_Text_JulioPostBattle:
	.string "La mia BICICLETTA ha sobbalzato\n"
	.string "così tanto che ho male al sedere…$"

JaggedPass_Text_AutumnIntro:
	.string "Scolo questa collina ogni giorno.\n"
	.string "Ho fiducia nella mia forza!$"

JaggedPass_Text_AutumnDefeat:
	.string "Mmm…\n"
	.string "Cosa è andato storto?$"

JaggedPass_Text_AutumnPostBattle:
	.string "Cos'è quella strana sporgenza\n"
	.string "rocciosa poco più su?$"

