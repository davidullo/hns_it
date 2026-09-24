MtChimney_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
	.byte 0

MtChimney_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
	end

MtChimney_OnResume:
	setstepcallback STEP_CB_ASH
	end

MtChimney_EventScript_Archie::
	lock
	faceplayer
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
	closemessage
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
	release
	end

MtChimney_EventScript_ArchieGoStopTeamMagma::
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
	return

MtChimney_EventScript_ArchieBusyFighting::
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
	return

MtChimney_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_Delay48
	waitmovement 0
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
	closemessage
	delay 30
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_MT_CHIMNEY_MAXIE
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_1
	removeobject LOCALID_MT_CHIMNEY_TABITHA
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_2
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
	fadescreenswapbuffers FADE_FROM_BLACK
	setobjectxyperm LOCALID_MT_CHIMNEY_ARCHIE, 10, 12
	addobject LOCALID_MT_CHIMNEY_ARCHIE
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
	removeobject LOCALID_MT_CHIMNEY_ARCHIE
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
	releaseall
	end

MtChimney_EventScript_ArchieApproachPlayerEast::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieApproachPlayerNorth::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitEast::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitNorth::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitNorth
	waitmovement 0
	return

MtChimney_EventScript_LavaCookieLady::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_DeclineLavaCookie
	checkmoney 200
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_NotEnoughMoney
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
	checkitemspace ITEM_LAVA_COOKIE
	call_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RemoveMoney
.if OW_SHOW_ITEM_DESCRIPTIONS == OW_ITEM_DESCRIPTIONS_OFF
	giveitem ITEM_LAVA_COOKIE
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
	hidemoneybox
	release
	end

MtChimney_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end
.else
	hidemoneybox
	giveitem ITEM_LAVA_COOKIE
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
	release
	end

MtChimney_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	release
	end
.endif @ OW_SHOW_ITEM_DESCRIPTIONS


MtChimney_EventScript_RemoveMoney::
	removemoney 200
	updatemoneybox
	return

MtChimney_EventScript_DeclineLavaCookie::
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_NotEnoughMoney::
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_Movement_ArchieApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

MtChimney_Movement_ArchieExitEast:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_ArchieApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

MtChimney_Movement_ArchieExitNorth:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused3:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused4:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused5:
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused6:
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused7:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused8:
	delay_16
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

MtChimney_Movement_Unused9:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused10:
	walk_down
	step_end

MtChimney_Movement_Unused11:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused12:
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused13:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused14:
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	face_right
	step_end

MtChimney_Movement_Unused15:
	walk_left
	walk_in_place_faster_right
	delay_16
	step_end

MtChimney_EventScript_BusyAquaGrunt1::
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt2::
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt3::
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_BusyMagmaGrunt1::
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt2::
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt3::
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt4::
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt5::
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt6::
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
	end

MtChimney_EventScript_MagmaPoochyena::
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
	end

MtChimney_EventScript_AquaPoochyena::
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
	end

MtChimney_EventScript_MeteoriteMachine::
	lockall
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_LeaveMeteoriteAlone
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
	giveitem ITEM_METEORITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_METEORITE
	releaseall
	end

MtChimney_EventScript_LeaveMeteoriteAlone::
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOff::
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOn::
	msgbox MtChimney_Text_MetoriteFittedOnMachine, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_RouteSign::
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
	end

MtChimney_EventScript_Shelby::
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RematchShelby
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_DefeatedShelby::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SHELBY_1
	release
	end

MtChimney_EventScript_RematchShelby::
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Melissa::
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sheila::
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sawyer::
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_SawyerRematch
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_SawyerDefeated::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SAWYER_1
	release
	end

MtChimney_EventScript_SawyerRematch::
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_Text_MeteoriteWillActivateVolcano:
	.string "Il potere racchiuso nel METEORITE…\p"
	.string "Amplificandolo con questa\n"
	.string "macchina, l'attività vulcanica del\l"
	.string "MT. CAMINO aumenterà all'istante…\p"
	.string "L'energia crescerà nel profondo\n"
	.string "del cratere e…\l"
	.string "Fufufu…$"

MtChimney_Text_MaxieIntro:
	.string "MAX: Hm?\n"
	.string "Chi sei?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Avevo sentito FLAVIANO lamentarsi di un\n"
	.string "bambino che si intromette negli\l"
	.string "affari del TEAM AQUA.\p"
	.string "Dovevi essere tu.\p"
	.string "Uhm! Quindi pensi di\n"
	.string "intrometterti con noi, TEAM MAGMA?\p"
	.string "Ora ascolta.\n"
	.string "Molto tempo fa, gli esseri viventi\l"
	.string "usavano la terra per vivere e crescere.\p"
	.string "Ecco perché la terra è tutto!\n"
	.string "È la culla di ogni cosa!\p"
	.string "Ecco perché il TEAM MAGMA si dedica\n"
	.string "all'espansione della terraferma.\p"
	.string "È per il progresso dell'\n"
	.string "umanità e dei POKéMON!\p"
	.string "E per questo ci serve il potere di\n"
	.string "ciò che dorme in questa montagna…\p"
	.string "Oh! Non dovevo dirti\n"
	.string "così tanto.\p"
	.string "Ma non importa!\n"
	.string "Ti insegnerò le conseguenze dell'\l"
	.string "intromettersi nel nostro grande piano!$"

MtChimney_Text_MaxieDefeat:
	.string "Cosa?!\p"
	.string "Io, MAX, colto di sorpresa?!$"

MtChimney_Text_MaxieYouHaventSeenLastOfMagma:
	.string "MAX: Ma basta.\n"
	.string "Questa volta mi ritiro.\p"
	.string "Ma non credere che sia l'ultima\n"
	.string "volta che vedi il TEAM MAGMA.\p"
	.string "Fufufu…\p"
	.string "Anche senza il METEORITE, se ci\n"
	.string "procuriamo quell'ORB… Fufufu…$"

MtChimney_Text_TabithaIntro:
	.string "Eh eh eh!\p"
	.string "Quindi sei arrivato fin qui!\p"
	.string "Ma sei troppo tardi!\n"
	.string "Ho già consegnato il METEORITE\l"
	.string "dalle CASCATE METEORA al CAPO!$"

MtChimney_Text_TabithaDefeat:
	.string "Eh eh eh…\p"
	.string "Anche se ho perso, se il nostro capo\n"
	.string "risveglia quella cosa…$"

MtChimney_Text_TabithaPostBattle:
	.string "CAPO, presto!\n"
	.string "Dagli l'energia del METEORITE!\p"
	.string "Eh eh eh…$"

MtChimney_Text_Grunt2Intro:
	.string "Noi del TEAM MAGMA lavoriamo sodo per\n"
	.string "il bene di tutti.\p"
	.string "Se il potere di quella cosa creasse\n"
	.string "più terra, ci sarebbero più posti.\p"
	.string "Sarebbero tutti felici!$"

MtChimney_Text_Grunt2Defeat:
	.string "Eh?\n"
	.string "Come sarebbe che ho perso?$"

MtChimney_Text_Grunt2PostBattle:
	.string "Il nostro CAPO dice: “Renderà tutti\n"
	.string "felici.”\p"
	.string "Ma perché tutti continuano a\n"
	.string "mettersi sulla nostra strada?$"

MtChimney_Text_Grunt1Intro:
	.string "Con più terra, potrei avere\n"
	.string "una bella casa tutta mia!\p"
	.string "La costruirò sulla lava indurita!$"

MtChimney_Text_Grunt1Defeat:
	.string "La mia casa dei sogni…$"

MtChimney_Text_Grunt1PostBattle:
	.string "Un ragazzino come te dovrebbe\n"
	.string "sguazzare tra le onde!$"

MtChimney_Text_TeamAquaAlwaysMessingWithPlans:
	.string "Quel fastidioso TEAM AQUA…\n"
	.string "Si intromette sempre nei nostri piani!$"

MtChimney_Text_MeteoritesPackAmazingPower:
	.string "I METEORITI hanno un potere incredibile!$"

MtChimney_Text_YouBetterNotMessWithUs:
	.string "Faresti meglio a non intrometterti!\p"
	.string "Vogliamo risvegliare quella cosa\n"
	.string "per il bene di tutti!$"

MtChimney_Text_AquasNameSimilar:
	.string "Noi siamo il TEAM MAGMA!\p"
	.string "Loro sono il TEAM AQUA!\p"
	.string "Mi dà fastidio che usino un nome\n"
	.string "simile al nostro!$"

MtChimney_Text_DouseThemInFire:
	.string "Sì!\n"
	.string "Ardete nel fuoco!$"

MtChimney_Text_KeepMakingMoreLand:
	.string "Continueremo a creare altra terra!$"

MtChimney_Text_Bufoh:
	.string "Bufoh!$"

MtChimney_Text_ArchieGoStopTeamMagma:
	.string "FLAVIANO: Grr, {PLAYER}!\n"
	.string "Immaginavo che saresti arrivato!\p"
	.string "Guarda con i tuoi occhi cosa\n"
	.string "combinano i fanatici del TEAM MAGMA!\p"
	.string "Vogliono iniettare l'energia del\n"
	.string "METEORITE rubato nel vulcano!\p"
	.string "Una cosa del genere causerà\n"
	.string "l'eruzione del vulcano!$"

MtChimney_Text_ArchieIHaveMyHandsFull:
	.string "FLAVIANO: Grrr…\p"
	.string "Voglio fermare MAX,\n"
	.string "ma non posso!\p"
	.string "Non con tre avversari da battere\n"
	.string "tutti in una volta!$"

MtChimney_Text_ArchieThankYou:
	.string "FLAVIANO: {PLAYER}!\n"
	.string "Grazie!\p"
	.string "Con il tuo aiuto abbiamo fermato il\n"
	.string "piano distruttivo del TEAM MAGMA!\p"
	.string "Ma… Tu…\n"
	.string "Da che parte stai?\p"
	.string "Ah, non importa.\p"
	.string "Resteremo vigili e continueremo\n"
	.string "a inseguire il TEAM MAGMA.\p"
	.string "{PLAYER}, ci rivedremo!$"

MtChimney_Text_MagmaOutnumbersUs:
	.string "Dannazione… il TEAM MAGMA è più\n"
	.string "numeroso! Non riusciamo a fermarli!$"

MtChimney_Text_LessHabitatForWaterPokemon:
	.string "Se espandono la terra, ci sarà\n"
	.string "meno habitat per i POKéMON ACQUA!$"

MtChimney_Text_MagmasNameSimilar:
	.string "Noi siamo il TEAM AQUA!\p"
	.string "Loro sono il TEAM MAGMA!\p"
	.string "Mi fa arrabbiare che usino un nome\n"
	.string "così confondente!$"

MtChimney_Text_Bushaa:
	.string "Bushaa!$"

MtChimney_Text_LavaCookiesJust200:
	.string "I BISCOTTI LAVA sono la specialità del\n"
	.string "MT. CAMINO.\p"
	.string "Provali. Costano solo ¥200.$"

MtChimney_Text_ThankYouDear:
	.string "Grazie, caro!$"

MtChimney_Text_YouveNotGotTheMoney:
	.string "Oh, caro. Non puoi comprare niente\n"
	.string "se non hai i soldi.$"

MtChimney_Text_OhFineThen:
	.string "Oh, va bene allora.$"

MtChimney_Text_MetoriteFittedOnMachine:
	.string "Un METEORITE è incastonato su una\n"
	.string "macchina misteriosa…\p"
	.string "La macchina sembra immagazzinare\n"
	.string "energia nel METEORITE.$"

MtChimney_Text_RemoveTheMeteorite:
	.string "Un METEORITE è incastonato su una\n"
	.string "macchina misteriosa…\p"
	.string "Vuoi rimuovere il METEORITE?$"

MtChimney_Text_PlayerRemovedMeteorite:
	.string "{PLAYER} rimuove il METEORITE dalla\n"
	.string "macchina misteriosa.$"

MtChimney_Text_PlayerLeftMeteorite:
	.string "{PLAYER} ha lasciato il METEORITE dove\n"
	.string "stava.$"

MtChimney_Text_MachineMakesNoResponse:
	.string "Questa macchina misteriosa…\n"
	.string "Non dà alcuna risposta.$"

MtChimney_Text_RouteSign:
	.string "{DOWN_ARROW} SENTIERO ASPRO\n"
	.string "PERCORSO 112 AVANTI$"

MtChimney_Text_ShelbyIntro:
	.string "Sono stata alle terme e\n"
	.string "ho rinfrescato le mie ossa stanche.\l"
	.string "Adesso mi sento forte!$"

MtChimney_Text_ShelbyDefeat:
	.string "Oh, santo cielo.\n"
	.string "Ma guarda un po' che forza!$"

MtChimney_Text_ShelbyPostBattle:
	.string "Beh, ho perso. Non posso più\n"
	.string "definirmi un'ESPERTO, vero?$"

MtChimney_Text_ShelbyRegister:
	.string "Grazie, piccolino. È stato bello, come\n"
	.string "lottare con mio nipote.\p"
	.string "Torna a trovarmi per\n"
	.string "una rivincita.$"

MtChimney_Text_ShelbyRematchIntro:
	.string "Se unisci il tuo cuore a quello\n"
	.string "dei tuoi POKéMON, potrai\l"
	.string "realizzare grandi cose.$"

MtChimney_Text_ShelbyRematchDefeat:
	.string "Oh, santo cielo.\n"
	.string "Ma guarda un po' che forza!$"

MtChimney_Text_ShelbyPostRematch:
	.string "Forse il tuo cuore è diventato uno\n"
	.string "con i cuori dei tuoi POKéMON.$"

MtChimney_Text_MelissaIntro:
	.string "Ho il fuoco dentro, tesoro.\n"
	.string "Non resisto! Devo lottare!$"

MtChimney_Text_MelissaDefeat:
	.string "Ooh, che lotta incandescente!$"

MtChimney_Text_MelissaPostBattle:
	.string "Il calore del MT. CAMINO mi\n"
	.string "riscalda, tesoro!$"

MtChimney_Text_SheilaIntro:
	.string "Finalmente sono arrivata al MT. CAMINO.\n"
	.string "Voglio far lottare i miei POKéMON!$"

MtChimney_Text_SheilaDefeat:
	.string "Il tuo modo di lottare…\n"
	.string "È come un'eruzione del MT. CAMINO!$"

MtChimney_Text_SheilaPostBattle:
	.string "Come dicevo, sono arrivata al\n"
	.string "MT. CAMINO. Sarebbe un peccato\l"
	.string "fare solo un po' di turismo…\p"
	.string "Voglio fare qualche lotta e comprare\n"
	.string "dei BISCOTTI come souvenir.$"

MtChimney_Text_ShirleyIntro:
	.string "Da quando ho fatto il bagno alle terme,\n"
	.string "mi sento benissimo!\l"
	.string "Sono certa che vincerò!$"

MtChimney_Text_ShirleyDefeat:
	.string "Ahi!\n"
	.string "L'acqua mi sta dando i brividi.$"

MtChimney_Text_ShirleyPostBattle:
	.string "Dovrò fare un altro bagno alle\n"
	.string "terme. Vuoi venire con me?\p"
	.string "Scherzo!$"

MtChimney_Text_SawyerIntro:
	.string "Che bella montagna! Piena di\n"
	.string "gente focosa che mi fa compagnia!$"

MtChimney_Text_SawyerDefeat:
	.string "Oh, sei anche tu un tipo focoso!$"

MtChimney_Text_SawyerPostBattle:
	.string "Dovrei farmi un bagno alle TERME\n"
	.string "DI LAVARIDGE con la gente del posto!$"

MtChimney_Text_SawyerRegister:
	.string "Mi piacciono le palle di fuoco come te.\n"
	.string "Ti registro nel POKéNAV.$"

MtChimney_Text_SawyerRematchIntro:
	.string "Sono circondato da gente focosa\n"
	.string "da queste parti. Non perderò!$"

MtChimney_Text_SawyerRematchDefeat:
	.string "Cavolo, sei sempre la stessa\n"
	.string "testa calda di prima!$"

MtChimney_Text_SawyerPostRematch:
	.string "In realtà, qui fa davvero caldo.\n"
	.string "Sono vestito troppo pesante.$"
