DewfordTown_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_Gym_OnTransition
	.byte 0

DewfordTown_Gym_OnTransition:
	call DewfordTown_Gym_EventScript_SetFlashLevel
	end

DewfordTown_Gym_EventScript_SetFlashLevel::
	goto_if_defeated TRAINER_BRAWLY_1, DewfordTown_Gym_EventScript_SetLightsOn
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 0, DewfordTown_Gym_EventScript_SetFlashLevel7
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_SetFlashLevel6
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_SetFlashLevel5
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_SetFlashLevel4
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_SetFlashLevel3
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_SetFlashLevel2
	goto DewfordTown_Gym_EventScript_SetFlashLevel1

DewfordTown_Gym_EventScript_SetLightsOn::
	setflashlevel 0
	return

@ Brightest
DewfordTown_Gym_EventScript_SetFlashLevel1::
	setflashlevel 1
	return

DewfordTown_Gym_EventScript_SetFlashLevel2::
	setflashlevel 2
	return

DewfordTown_Gym_EventScript_SetFlashLevel3::
	setflashlevel 3
	return

DewfordTown_Gym_EventScript_SetFlashLevel4::
	setflashlevel 4
	return

DewfordTown_Gym_EventScript_SetFlashLevel5::
	setflashlevel 5
	return

DewfordTown_Gym_EventScript_SetFlashLevel6::
	setflashlevel 6
	return

@ Darkest
DewfordTown_Gym_EventScript_SetFlashLevel7::
	setflashlevel 7
	return

DewfordTown_Gym_EventScript_BrightenRoom::
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	nop1
	goto_if_eq VAR_0x8000, VAR_0x8001, DewfordTown_Gym_EventScript_NoLightChange
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_AnimateFlash1Trainer
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_AnimateFlash2Trainers
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_AnimateFlash3Trainers
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_AnimateFlash4Trainers
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_AnimateFlash5Trainers
	goto_if_eq VAR_0x8000, 6, DewfordTown_Gym_EventScript_AnimateFlash6Trainers

DewfordTown_Gym_EventScript_NoLightChange::
	return

@ NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius
DewfordTown_Gym_EventScript_AnimateFlash1Trainer::
	playse SE_SWITCH
	animateflash 6
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash2Trainers::
	playse SE_SWITCH
	animateflash 5
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash3Trainers::
	playse SE_SWITCH
	animateflash 4
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash4Trainers::
	playse SE_SWITCH
	animateflash 3
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash5Trainers::
	playse SE_SWITCH
	animateflash 2
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash6Trainers::
	playse SE_SWITCH
	animateflash 1
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlashFullBrightness::
	playse SE_SWITCH
	animateflash 0
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_CountTrainersDefeated::
	setvar VAR_0x8000, 0
	goto_if_not_defeated TRAINER_TAKAO, DewfordTown_Gym_EventScript_CheckJocelyn
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckJocelyn::
	goto_if_not_defeated TRAINER_JOCELYN, DewfordTown_Gym_EventScript_CheckLaura
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLaura::
	goto_if_not_defeated TRAINER_LAURA, DewfordTown_Gym_EventScript_CheckBrenden
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckBrenden::
	goto_if_not_defeated TRAINER_BRENDEN, DewfordTown_Gym_EventScript_CheckCristian
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckCristian::
	goto_if_not_defeated TRAINER_CRISTIAN, DewfordTown_Gym_EventScript_CheckLilith
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLilith::
	goto_if_not_defeated TRAINER_LILITH, DewfordTown_Gym_EventScript_StopCountingTrainers
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_StopCountingTrainers::
	return

DewfordTown_Gym_EventScript_Brawly::
	trainerbattle_single TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyIntro, DewfordTown_Gym_Text_BrawlyDefeat, DewfordTown_Gym_EventScript_BrawlyDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Gym_EventScript_BrawlyRematch
	goto_if_unset FLAG_RECEIVED_TM_BULK_UP, DewfordTown_Gym_EventScript_GiveBulkUp2
	msgbox DewfordTown_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_BrawlyDefeated::
	call DewfordTown_Gym_EventScript_AnimateFlashFullBrightness
	message DewfordTown_Gym_Text_ReceivedKnuckleBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_BADGE02_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	call DewfordTown_Gym_EventScript_GiveBulkUp
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox DewfordTown_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	release
	end

DewfordTown_Gym_EventScript_GiveBulkUp::
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	return

DewfordTown_Gym_EventScript_GiveBulkUp2:
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	release
	end

DewfordTown_Gym_EventScript_BrawlyRematch::
	trainerbattle_rematch_double TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyPreRematch, DewfordTown_Gym_Text_BrawlyRematchDefeat, DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons
	msgbox DewfordTown_Gym_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_Takao::
	trainerbattle_single TRAINER_TAKAO, DewfordTown_Gym_Text_TakaoIntro, DewfordTown_Gym_Text_TakaoDefeat, DewfordTown_Gym_EventScript_TakaoBrightenRoom
	msgbox DewfordTown_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_TakaoBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Jocelyn::
	trainerbattle_single TRAINER_JOCELYN, DewfordTown_Gym_Text_JocelynIntro, DewfordTown_Gym_Text_JocelynDefeat, DewfordTown_Gym_EventScript_JocelynBrightenRoom
	msgbox DewfordTown_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_JocelynBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Laura::
	trainerbattle_single TRAINER_LAURA, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LauraBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Brenden::
	trainerbattle_single TRAINER_BRENDEN, DewfordTown_Gym_Text_BrendenIntro, DewfordTown_Gym_Text_BrendenDefeat, DewfordTown_Gym_EventScript_BrendenBrightenRoom
	msgbox DewfordTown_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_BrendenBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Cristian::
	trainerbattle_single TRAINER_CRISTIAN, DewfordTown_Gym_Text_CristianIntro, DewfordTown_Gym_Text_CristianDefeat, DewfordTown_Gym_EventScript_CristianBrightenRoom
	msgbox DewfordTown_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_CristianBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Lilith::
	trainerbattle_single TRAINER_LILITH, DewfordTown_Gym_Text_LilithIntro, DewfordTown_Gym_Text_LilithDefeat, DewfordTown_Gym_EventScript_LilithBrightenRoom
	msgbox DewfordTown_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LilithBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_DEWFORD_GYM, DewfordTown_Gym_EventScript_GymGuidePostVictory
	msgbox DewfordTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_GymGuidePostVictory::
	msgbox DewfordTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_GymStatueCertified::
	msgbox DewfordTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_EventScript_GymStatue::
	msgbox DewfordTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_Text_GymGuideAdvice:
	.string "Ehi, come va, futuro CAMPIONE\n"
	.string "{PLAYER}?\p"
	.string "Il CAPOPALESTRA RUDI di DEWFORD usa\n"
	.string "POKéMON di tipo LOTTA.\p"
	.string "Con i POKéMON di tipo NORMALE\n"
	.string "non ti conviene proprio.\p"
	.string "I POKéMON di tipo LOTTA fanno\n"
	.string "a pezzi quelli NORMALE,\l"
	.string "stai attento!\p"
	.string "E la PALESTRA è buia come\n"
	.string "il fondale.\p"
	.string "Ma si illuminerà dopo aver\n"
	.string "battuto gli ALLENATORI.\p"
	.string "Ehi, forza, vai!$"

DewfordTown_Gym_Text_GymGuidePostVictory:
	.string "Whoah! Qui c'è troppa luce!\p"
	.string "E il tuo futuro è brillante!$"

DewfordTown_Gym_Text_TakaoIntro:
	.string "La forza vince!\n"
	.string "Forza!$"

DewfordTown_Gym_Text_TakaoDefeat:
	.string "Manca la forza…$"

DewfordTown_Gym_Text_TakaoPostBattle:
	.string "La tua abilità batte la forza!\n"
	.string "La tua tecnica è ammirevole!$"

DewfordTown_Gym_Text_JocelynIntro:
	.string "Non c'è bisogno di RUDI:\n"
	.string "ci penso io!\p"
	.string "Ti schiaccio!$"

DewfordTown_Gym_Text_JocelynDefeat:
	.string "Ma… Come?\n"
	.string "Come ho perso così facile?$"

DewfordTown_Gym_Text_JocelynPostBattle:
	.string "Non sprecherò questa sconfitta.\n"
	.string "Mi servirà per allenarmi di più!\p"
	.string "Un giorno sarò CAPOPALESTRA…\p"
	.string "No, il CAMPIONE della LEGA\n"
	.string "POKéMON!$"

DewfordTown_Gym_Text_LauraIntro:
	.string "Non osare ignorarmi!\n"
	.string "Non è colpa mia se piangi!$"

DewfordTown_Gym_Text_LauraDefeat:
	.string "Waaaaaah!\n"
	.string "Ho perso!$"

DewfordTown_Gym_Text_LauraPostBattle:
	.string "Lotto nel buio per rendere il cuore\n"
	.string "più forte.\p"
	.string "Ma è così buio che non vedo mai\n"
	.string "RUDI in faccia…$"

DewfordTown_Gym_Text_LilithIntro:
	.string "Ufufu…\n"
	.string "Stai brancolando nel buio?$"

DewfordTown_Gym_Text_LilithDefeat:
	.string "Oh, tu…\n"
	.string "Non ti voglio conoscere!$"

DewfordTown_Gym_Text_LilithPostBattle:
	.string "Meriti di perderti e finire\n"
	.string "di nuovo all'ingresso!$"

DewfordTown_Gym_Text_BrendenIntro:
	.string "Ti mostro lo spirito di\n"
	.string "un marinaio!$"

DewfordTown_Gym_Text_BrendenDefeat:
	.string "Come è successo?\n"
	.string "Non è da me perdere così!$"

DewfordTown_Gym_Text_BrendenPostBattle:
	.string "Oh! Puoi vedere il nostro\n"
	.string "CAPOPALESTRA.$"

DewfordTown_Gym_Text_CristianIntro:
	.string "Se vuoi passare, devi farlo\n"
	.string "da me!$"

DewfordTown_Gym_Text_CristianDefeat:
	.string "Grrrr!\n"
	.string "Sopraffatto!$"

DewfordTown_Gym_Text_CristianPostBattle:
	.string "Hai vinto!\n"
	.string "Prendi la MEDAGLIA!$"

DewfordTown_Gym_Text_BrawlyIntro:
	.string "Sono RUDI!\n"
	.string "CAPOPALESTRA di DEWFORD!\p"
	.string "Sono stato sballottato dalle onde\n"
	.string "di questi mari, e mi sono temprato\l"
	.string "nella grotta buia!\p"
	.string "Quindi vuoi sfidarmi?\n"
	.string "Vediamo di che pasta sei!$"

DewfordTown_Gym_Text_BrawlyDefeat:
	.string "Uau! Hai fatto un'onda molto più\n"
	.string "grande del previsto!\p"
	.string "Mi hai travolto!\p"
	.string "Ok, mi hai battuto.\n"
	.string "Prendi la MEDAGLIA!$"

DewfordTown_Gym_Text_ReceivedKnuckleBadge:
	.string "{PLAYER} riceve la MEDAGLIA PUGNO\n"
	.string "da RUDI.$"

DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis:
	.string "La MEDAGLIA PUGNO fa obbedire\n"
	.string "tutti i POKéMON fino al Livello 30,\l"
	.string "anche quelli scambiati.\p"
	.string "E potrai usare la mossa MN\n"
	.string "BALENO fuori dalla lotta.\p"
	.string "Se vuoi, usa anche questa\n"
	.string "MT.$"

DewfordTown_Gym_Text_ExplainBulkUp:
	.string "La MT08 contiene BULK UP.\p"
	.string "È una mossa che alza ATTACCO\n"
	.string "e DIFESA.\p"
	.string "… … … … … …$"

DewfordTown_Gym_Text_RegisteredBrawly:
	.string "CAPOPALESTRA RUDI\n"
	.string "nel POKéNAV.$"

DewfordTown_Gym_Text_BrawlyPostBattle:
	.string "Vedo il tuo talento diventare un'onda\n"
	.string "gigante che un giorno stupirà\l"
	.string "gli ALLENATORI!$"

DewfordTown_Gym_Text_GymStatue:
	.string "PALESTRA POKéMON DEWFORD$"

DewfordTown_Gym_Text_GymStatueCertified:
	.string "PALESTRA POKéMON DEWFORD\p"
	.string "CERTIFICATI DA RUDI:\n"
	.string "{PLAYER}$"

DewfordTown_Gym_Text_BrawlyPreRematch:
	.string "RUDI: L'onda si ritira, ma poi\n"
	.string "torna sempre a riva.\p"
	.string "Un'onda enorme di talento…\n"
	.string "Sapevo che tornerai!\p"
	.string "Fammi vedere quanto\n"
	.string "sei salito!$"

DewfordTown_Gym_Text_BrawlyRematchDefeat:
	.string "Wow!\n"
	.string "Battuto ancora!$"

DewfordTown_Gym_Text_BrawlyPostRematch:
	.string "RUDI: Lottare è vasto e profondo.\n"
	.string "Non se ne vede il fondo.\l"
	.string "È come il mare di HOENN!$"

DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons:
	.string "RUDI: L'onda si ritira, ma poi\n"
	.string "torna sempre a riva.\p"
	.string "Un'onda enorme di talento…\n"
	.string "Sapevo che tornerai!\p"
	.string "Oh? Hai un solo POKéMON\n"
	.string "che può lottare.\p"
	.string "Mi spiace, torna quando hai\n"
	.string "almeno due POKéMON.$"
