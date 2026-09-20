LavaridgeTown_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_1F_OnTransition
	.byte 0

LavaridgeTown_Gym_1F_OnTransition:
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	call LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers
	end

@ Unclear where/if these temp vars are getting checked
LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars::
	setvar VAR_TEMP_B, 0
	setvar VAR_TEMP_C, 0
	setvar VAR_TEMP_D, 0
	setvar VAR_TEMP_E, 0
	setvar VAR_TEMP_F, 0
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar
	setvar VAR_TEMP_B, 1
LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar
	setvar VAR_TEMP_C, 1
LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar
	setvar VAR_TEMP_D, 1
LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars
	setvar VAR_TEMP_E, 1
LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars::
	return

LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers::
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald
	setobjectmovementtype LOCALID_COLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle
	setobjectmovementtype LOCALID_GERALD, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle
	setobjectmovementtype LOCALID_AXLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers
	setobjectmovementtype LOCALID_DANIELLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers::
	return

LavaridgeTown_Gym_1F_EventScript_Flannery::
	trainerbattle_single TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryIntro, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_Gym_1F_EventScript_FlanneryRematch
	goto_if_unset FLAG_RECEIVED_TM_OVERHEAT, LavaridgeTown_Gym_1F_EventScript_GiveOverheat2
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated::
	message LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_BADGE04_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
	call LavaridgeTown_Gym_1F_EventScript_GiveOverheat
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat2::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	return

LavaridgeTown_Gym_1F_EventScript_FlanneryRematch::
	trainerbattle_rematch_double TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryPreRematch, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat, LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Cole::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_COLE, TRAINER_COLE, LavaridgeTown_Gym_1F_Text_ColeIntro, LavaridgeTown_Gym_1F_Text_ColeDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_1F_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_EventScript_CheckTrainerScript::
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	release
	special ShouldTryGetTrainerScript
	goto_if_eq VAR_RESULT, 1, EventScript_GotoTrainerScript
	end

LavaridgeTown_Gym_1F_EventScript_Axle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_AXLE, TRAINER_AXLE, LavaridgeTown_Gym_1F_Text_AxleIntro, LavaridgeTown_Gym_1F_Text_AxleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_1F_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Keegan::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_KEEGAN, TRAINER_KEEGAN, LavaridgeTown_Gym_B1F_Text_KeeganIntro, LavaridgeTown_Gym_B1F_Text_KeeganDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_B1F_Text_KeeganPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Danielle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_DANIELLE, TRAINER_DANIELLE, LavaridgeTown_Gym_1F_Text_DanielleIntro, LavaridgeTown_Gym_1F_Text_DanielleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_1F_Text_DaniellePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Gerald::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_GERALD, TRAINER_GERALD, LavaridgeTown_Gym_1F_Text_GeraldIntro, LavaridgeTown_Gym_1F_Text_GeraldDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_1F_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jace::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_JACE, TRAINER_JACE, LavaridgeTown_Gym_B1F_Text_JaceIntro, LavaridgeTown_Gym_B1F_Text_JaceDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_B1F_Text_JacePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jeff::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_JEFF, TRAINER_JEFF, LavaridgeTown_Gym_B1F_Text_JeffIntro, LavaridgeTown_Gym_B1F_Text_JeffDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_B1F_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Eli::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_ELI, TRAINER_ELI, LavaridgeTown_Gym_B1F_Text_EliIntro, LavaridgeTown_Gym_B1F_Text_EliDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_B1F_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox LavaridgeTown_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_GymStatueCertified::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_GymStatue::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_Text_GymGuideAdvice:
	.string "Ehi, campione in erba,\n"
	.string "{PLAYER}?\p"
	.string "FLANNERY, la CAPOPALESTRA,\n"
	.string "usa POKéMON di FUOCO.\p"
	.string "La sua passione brucia più forte\n"
	.string "più calda di un vulcano.\p"
	.string "Non avvicinarti troppo: scotterai!\n"
	.string "Raffreddala con l'acqua e poi\l"
	.string "attacca!$"

LavaridgeTown_Gym_1F_Text_GymGuidePostVictory:
	.string "Wow! Che lotta incandescente!$"

LavaridgeTown_Gym_1F_Text_ColeIntro:
	.string "Ahia ahia ahia!\n"
	.string "Accidenti, che caldo!$"

LavaridgeTown_Gym_1F_Text_ColeDefeat:
	.string "Il sudore mi acceca gli occhi…$"

LavaridgeTown_Gym_1F_Text_ColePostBattle:
	.string "La sabbia calda fa bene\n"
	.string "alla circolazione.\p"
	.string "Cura i dolori\n"
	.string "alle articolazioni.$"

LavaridgeTown_Gym_1F_Text_AxleIntro:
	.string "Sto cercando di sfogare lo stress.\n"
	.string "Non venirmi a stressare ancora!$"

LavaridgeTown_Gym_1F_Text_AxleDefeat:
	.string "Spero che FLANNERY ti bruci bene!$"

LavaridgeTown_Gym_1F_Text_AxlePostBattle:
	.string "Fiuuu… Uff…\p"
	.string "Troppa sabbia calda addosso\n"
	.string "stanca…$"

LavaridgeTown_Gym_B1F_Text_KeeganIntro:
	.string "Dovresti essere stanco ormai.\n"
	.string "Ti piacerebbe riposare nella\l"
	.string "sabbia calda, no?\p"
	.string "Ma sappi che mantenere\n"
	.string "la volontà è una dote importante\l"
	.string "per tutti gli ALLENATORI.$"

LavaridgeTown_Gym_B1F_Text_KeeganDefeat:
	.string "Chi gioca col fuoco si scotta…$"

LavaridgeTown_Gym_B1F_Text_KeeganPostBattle:
	.string "Sei davvero bravo…\n"
	.string "Ma la nostra CAPO FLANNERY è forte.\p"
	.string "Se non stai attento, ti\n"
	.string "scotti sul serio.$"

LavaridgeTown_Gym_1F_Text_GeraldIntro:
	.string "I tuoi POKéMON reggono\n"
	.string "i 392 gradi?$"

LavaridgeTown_Gym_1F_Text_GeraldDefeat:
	.string "Non ha bruciato abbastanza…$"

LavaridgeTown_Gym_1F_Text_GeraldPostBattle:
	.string "Il magma sta a\n"
	.string "392 gradi.\p"
	.string "I tuoi POKéMON mi hanno battuto:\n"
	.string "vivranno nel magma.$"

LavaridgeTown_Gym_1F_Text_DanielleIntro:
	.string "Uhm…\n"
	.string "Ok, lotto con te.$"

LavaridgeTown_Gym_1F_Text_DanielleDefeat:
	.string "Oh, ma sei troppo forte.$"

LavaridgeTown_Gym_1F_Text_DaniellePostBattle:
	.string "Sarò un'ALLENATRICE bella e\n"
	.string "forte come FLANNERY.$"

LavaridgeTown_Gym_B1F_Text_JaceIntro:
	.string "Dai, muoviti!\n"
	.string "Prima che mi passi!$"

LavaridgeTown_Gym_B1F_Text_JaceDefeat:
	.string "Fa caldissimo, eppure il mio\n"
	.string "cuore è stretto dal ghiaccio…$"

LavaridgeTown_Gym_B1F_Text_JacePostBattle:
	.string "Con lo spirito di lotta che\n"
	.string "brucia in te, puoi forse\l"
	.string "battere la nostra CAPO.$"

LavaridgeTown_Gym_B1F_Text_JeffIntro:
	.string "Vedi le fiamme?\n"
	.string "Bruciano per la mia vittoria!$"

LavaridgeTown_Gym_B1F_Text_JeffDefeat:
	.string "Qualcosa è andato storto.$"

LavaridgeTown_Gym_B1F_Text_JeffPostBattle:
	.string "E allora? E allora?\n"
	.string "Cammino sui carboni a piedi nudi!\p"
	.string "…Non provarci nemmeno!$"

LavaridgeTown_Gym_B1F_Text_EliIntro:
	.string "Amo molto la montagna,\n"
	.string "ma i vulcani ancora di più.$"

LavaridgeTown_Gym_B1F_Text_EliDefeat:
	.string "Beh, mi sa che ho perso senza\n"
	.string "mai controllare la lotta.$"

LavaridgeTown_Gym_B1F_Text_EliPostBattle:
	.string "Resto qui perché sono un fan\n"
	.string "della forza di FLANNERY.\p"
	.string "Eh eh eh eh.$"

LavaridgeTown_Gym_1F_Text_FlanneryIntro:
	.string "Benvenuto… No, aspetta.\p"
	.string "Allenatore scarso, che bello\n"
	.string "vederti arrivare!\p"
	.string "Mi è stato affidato il…\n"
	.string "No, aspetta.\p"
	.string "Sono FLANNERY, e sono la\n"
	.string "CAPOPALESTRA qui!\p"
	.string "Ehm…\n"
	.string "Non sottovalutarmi, anche se\l"
	.string "sono CAPO da poco!\p"
	.string "Con le doti ereditate da mio\n"
	.string "nonno, ti mostrerò, ehm… le\l"
	.string "mosse calde di questa terra!$"

LavaridgeTown_Gym_1F_Text_FlanneryDefeat:
	.string "Oh…\n"
	.string "Ci ho provato troppo…\p"
	.string "Sono… da poco diventata\n"
	.string "CAPOPALESTRA.\p"
	.string "Ho provato a essere qualcuno\n"
	.string "che non sono.\p"
	.string "Devo fare a modo mio. Se no, i\n"
	.string "miei POKéMON si confondono.\p"
	.string "Grazie per avermelo insegnato.\n"
	.string "Per questo, ti meriti questo.$"

LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge:
	.string "{PLAYER} riceve la MEDAGLIA CALORE\n"
	.string "da FLANNERY.$"

LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis:
	.string "Con una MEDAGLIA CALORE, tutti i\n"
	.string "POKéMON fino al Livello 50, anche\l"
	.string "quelli ricevuti in scambio,\l"
	.string "ti obbediranno.\p"
	.string "E i POKéMON potranno usare la mossa\n"
	.string "MN FORZA fuori dalla lotta.\p"
	.string "Questo è un segno di stima.\n"
	.string "Prendilo, non fare complimenti!$"

LavaridgeTown_Gym_1F_Text_ExplainOverheat:
	.string "La MT50 contiene VAMPATA.\p"
	.string "Quella mossa fa gravi danni\n"
	.string "all'avversario.\p"
	.string "Ma riduce molto l'ATT. SPEC.\n"
	.string "di chi la usa. Non è adatta\l"
	.string "alle lotte lunghe.$"

LavaridgeTown_Gym_1F_Text_RegisteredFlannery:
	.string "CAPOPALESTRA FLANNERY registrata\n"
	.string "nel POKéNAV.$"

LavaridgeTown_Gym_1F_Text_FlanneryPostBattle:
	.string "La tua forza mi ricorda qualcuno…\p"
	.string "Oh! Lo so! Lotti come NORMAN,\n"
	.string "il CAPOPALESTRA di PETALBURG.$"

LavaridgeTown_Gym_1F_Text_GymStatue:
	.string "PALESTRA POKéMON di LAVARIDGE$"

LavaridgeTown_Gym_1F_Text_GymStatueCertified:
	.string "PALESTRA POKéMON di LAVARIDGE\p"
	.string "ALLENATORI CERTIFICATI di FLANNERY:\n"
	.string "{PLAYER}$"

LavaridgeTown_Gym_1F_Text_FlanneryPreRematch:
	.string "FLANNERY: Perdere non mi\n"
	.string "demoralizza.\p"
	.string "Amo i POKéMON.\n"
	.string "Amo lottare.\l"
	.string "E… amo questa PALESTRA!\p"
	.string "Scambiamoci mosse calde\n"
	.string "in un'altra lotta!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat:
	.string "Uff!\n"
	.string "Sull'orlo dell'eruzione!$"

LavaridgeTown_Gym_1F_Text_FlanneryPostRematch:
	.string "FLANNERY: Ho perso,\n"
	.string "ma sono soddisfatta.\p"
	.string "Non mi capita spesso una lotta\n"
	.string "così accesa.\p"
	.string "Rifacciamone un'altra\n"
	.string "un'altra volta!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons:
	.string "FLANNERY: Perdere non mi\n"
	.string "demoralizza.\p"
	.string "Amo i POKéMON.\n"
	.string "Amo lottare.\l"
	.string "E… amo questa PALESTRA!\p"
	.string "Scambiamoci mosse calde\n"
	.string "in un'altra lotta!\p"
	.string "Oh, aspetta. Hai solo un POKéMON\n"
	.string "che può lottare?\p"
	.string "Mi spiace, ma quando vieni\n"
	.string "porta almeno due POKéMON.$"
