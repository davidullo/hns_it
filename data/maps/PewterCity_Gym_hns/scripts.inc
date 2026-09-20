PewterCity_Gym_hns_MapScripts::
	.byte 0



PewterCity_Gym_EventScript_Jerry::
	trainerbattle_single TRAINER_JERRY_HNS, PewterCity_Gym_Text_CamperJerry_Seen, PewterCity_Gym_Text_CamperJerry_Beaten
	msgbox PewterCity_Gym_Text_CamperJerry_AfterBattle, MSGBOX_AUTOCLOSE
	end

PewterCity_Gym_EventScript_Brock::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_PEWTER_GYM, PewterCity_Gym_EventScript_Brock_Defeated
	msgbox PewterCity_Gym_Text_Brock_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BROCK_HNS, PewterCity_Gym_Text_Brock_WinLoss
	message PewterCity_Gym_Text_ReceivedBoulderBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox PewterCity_Gym_Text_Brock_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_ROCK_SLIDE
	msgbox PewterCity_Gym_Text_Brock_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE09_GET
	setflag FLAG_DEFEATED_PEWTER_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 9
	call Common_EventScript_SetGymTrainers_hns
	clearflag FLAG_HIDE_DIGLETT_BROCK
	closemessage
	release
	end

PewterCity_Gym_EventScript_Brock_Defeated::
	goto_if_unset FLAG_HIDE_DOJO_BROCK, PewterCity_Gym_EventScript_Brock_Trade
	msgbox PewterCity_Gym_Text_Brock_FightDone, MSGBOX_DEFAULT
	closemessage
	release
	end


PewterCity_Gym_Text_Brock_Intro:
	.string "BROCK: Wow, non capita spesso che arrivi\n"
	.string "una sfida da JOHTO.\p"
	.string "Sono BROCK, il CAPOPALESTRA di PEWTER.\p"
	.string "Sono esperto di POKéMON di tipo ROCIA.\p"
	.string "I miei POKéMON sono immuni a quasi\n"
	.string "tutti gli attacchi fisici. Farai\l"
	.string "fatica a infliggergli danni.\p"
	.string "Forza!$"

PewterCity_Gym_Text_Brock_WinLoss:
	.string "BROCK: I potenti attacchi dei tuoi\n"
	.string "POKéMON hanno vinto la mia difesa…\p"
	.string "Sei più forte di quanto pensassi…\p"
	.string "Avanti, prendi questa MEDAGLIA.$"

PewterCity_Gym_Text_ReceivedBoulderBadge:
	.string "{PLAYER} riceve la MEDAGLIA SASSO.$"

PewterCity_Gym_Text_Brock_GiveTM:
	.string "Tieni, prendi questa MT con te.$"

PewterCity_Gym_Text_Brock_ExplainTM:
	.string "Contiene FRANA.\p"
	.string "Fa cadere rocce sugli avversari\n"
	.string "con la possibilità di farli vacillare.\p"
	.string "Usala per fermarli sul posto.$"

PewterCity_Gym_Text_Brock_BoulderBadge:
	.string "BROCK: {PLAYER}, grazie. Mi sono divertito\n"
	.string "a lottare con te, anche se sono un po'\l"
	.string "deluso.\p"
	.string "La MEDAGLIA SASSO renderà i tuoi\n"
	.string "POKéMON ancora più forti.$"

PewterCity_Gym_Text_Brock_FightDone:
	.string "BROCK: Il mondo è immenso. Ci sono\n"
	.string "ancora molti allenatori forti come te.\p"
	.string "Aspetta e vedrai. Diventerò\n"
	.string "molto più forte anch'io.$"

PewterCity_Gym_Text_CamperJerry_Seen:
	.string "Gli allenatori di questa PALESTRA usano\n"
	.string "POKéMON di tipo ROCIA.\p"
	.string "Il tipo ROCIA ha una DIFESA alta.\p"
	.string "Le lotte possono durare a lungo.\n"
	.string "Sei pronto?$"

PewterCity_Gym_Text_CamperJerry_Beaten:
	.string "Devo vincere queste lotte…$"

PewterCity_Gym_Text_CamperJerry_AfterBattle:
	.string "Ehi, tu! Allenatore da JOHTO! BROCK è\n"
	.string "tosto. Ti punirà se non lo prendi\l"
	.string "sul serio.$"

PewterCity_Gym_Text_Guide:
	.string "Yo! CAMPIONE in erba! Sei davvero\n"
	.string "in gamba.\p"
	.string "Stai sfidando i CAPIPALESTRA di\n"
	.string "KANTO?\p"
	.string "Sono persone forti e tenaci,\n"
	.string "proprio come i CAPIPALESTRA di JOHTO.$"

PewterCity_Gym_Text_Guide_Win:
	.string "Ehi! Campione in erba! Quella PALESTRA\n"
	.string "non ti ha dato problemi.\p"
	.string "Come hai preso in mano la situazione è\n"
	.string "stato davvero ispirante. Dico sul serio.$"

PewterCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_PEWTER_GYM, PewterCity_Gym_EventScript_GymGuyAfter
	msgbox PewterCity_Gym_Text_Guide, MSGBOX_NPC
	end

PewterCity_Gym_EventScript_GymGuyAfter::
	msgbox PewterCity_Gym_Text_Guide_Win, MSGBOX_NPC
	end


PewterCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE09_GET, PewterCity_Gym_EventScript_GymStatuePostVictory
	msgbox PewterCity_Gym_Text_GymStatue
	releaseall
	end

PewterCity_Gym_EventScript_GymStatuePostVictory::
	msgbox PewterCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

PewterCity_Gym_Text_GymStatue::
    .string "PALESTRA POKéMON di PLUMBEOPOLI\n"
    .string "CAPOPALESTRA: BROCK\p"
	.string "ALLENATORI VINCENTI:\n"
	.string "BLU, ROSSO$"

PewterCity_Gym_Text_GymStatuePlayerWon::
    .string "PALESTRA POKéMON di PLUMBEOPOLI\n"
    .string "CAPOPALESTRA: BROCK\p"
    .string "ALLENATORI VINCENTI:\n"
	.string "BLU, ROSSO, {PLAYER}$"

PewterCity_Gym_EventScript_Brock_Trade::
	goto_if_set FLAG_PEWTER_GYM_NPC_TRADE_COMPLETED, PewterCity_Gym_EventScript_BrockTradeCompleted
	ingame_trade INGAME_TRADE_BONSLY, PewterCity_Gym_Text_BrockWantToTrade, PewterCity_Gym_EventScript_BrockDeclineTrade, PewterCity_Gym_EventScript_BrockNotRequestedMon, PewterCity_Gym_Text_BrockTakeCare
	setflag FLAG_PEWTER_GYM_NPC_TRADE_COMPLETED
	release
	end

PewterCity_Gym_EventScript_BrockDeclineTrade::
	msgbox PewterCity_Gym_Text_BrockDeclineTrade, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_EventScript_BrockNotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PewterCity_Gym_Text_BrockNotRequestedMon, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_EventScript_BrockTradeCompleted::
	msgbox PewterCity_Gym_Text_BrockTradeCompleted, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_Text_BrockWantToTrade:
	.string "BROCK: Ehi, {PLAYER}. Ho trovato questo\n"
	.string "piccolo BONSLY mentre mi allenavo in\l"
	.string "montagna.\p"
	.string "È carino, ma credo che abbia bisogno\n"
	.string "di un altro tipo di allenatore.\p"
	.string "Scambieresti un {STR_VAR_1}\n"
	.string "con il mio {STR_VAR_2}?$"

PewterCity_Gym_Text_BrockTakeCare:
	.string "BROCK: Grazie! Prenditi cura\n"
	.string "di WOODY per me!$"

PewterCity_Gym_Text_BrockDeclineTrade:
	.string "BROCK: No? Va bene.\n"
	.string "Io e WOODY continueremo ad allenarci.$"

PewterCity_Gym_Text_BrockNotRequestedMon:
	.string "BROCK: Non è un {STR_VAR_1}.\n"
	.string "Non è quello che cerco.$"

PewterCity_Gym_Text_BrockTradeCompleted:
	.string "BROCK: Come se la cava WOODY?\n"
	.string "I BONSLY sono più duri di quel che sembra!$"
