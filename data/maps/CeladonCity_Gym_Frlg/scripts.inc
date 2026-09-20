CeladonCity_Gym_Frlg_MapScripts::
	.byte 0

CeladonCity_Gym_EventScript_Erika::
	famechecker FAMECHECKER_ERIKA, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_ERIKA, CeladonCity_Gym_Text_ErikaIntro, CeladonCity_Gym_Text_ErikaDefeat, CeladonCity_Gym_EventScript_DefeatedErika, NO_MUSIC
	goto_if_unset FLAG_GOT_TM19_FROM_ERIKA, CeladonCity_Gym_EventScript_GiveTM19
	famechecker FAMECHECKER_ERIKA, 4
	msgbox CeladonCity_Gym_Text_ErikaPostBattle
	release
	end

CeladonCity_Gym_EventScript_DefeatedErika::
	famechecker FAMECHECKER_ERIKA, 1
	clearflag FLAG_HIDE_FAME_CHECKER_ERIKA_JOURNALS
	setflag FLAG_DEFEATED_ERIKA
	setflag FLAG_BADGE04_GET
	set_gym_trainers_frlg 4
	goto CeladonCity_Gym_EventScript_GiveTM19
	end

CeladonCity_Gym_EventScript_GiveTM19::
	msgbox CeladonCity_Gym_Text_ExplainRainbowBadgeTakeThis
	checkitemspace ITEM_TM19
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_Gym_EventScript_NoRoomForTM19
	giveitem_msg CeladonCity_Gym_Text_ReceivedTM19FromErika, ITEM_TM19
	setflag FLAG_GOT_TM19_FROM_ERIKA
	msgbox CeladonCity_Gym_Text_ExplainTM19
	release
	end

CeladonCity_Gym_EventScript_NoRoomForTM19::
	msgbox CeladonCity_Gym_Text_ShouldMakeRoomForThis
	release
	end

CeladonCity_Gym_EventScript_Kay::
	trainerbattle_single TRAINER_LASS_KAY, CeladonCity_Gym_Text_KayIntro, CeladonCity_Gym_Text_KayDefeat
	msgbox CeladonCity_Gym_Text_KayPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Lisa::
	trainerbattle_single TRAINER_LASS_LISA, CeladonCity_Gym_Text_LisaIntro, CeladonCity_Gym_Text_LisaDefeat
	famechecker FAMECHECKER_ERIKA, 2
	msgbox CeladonCity_Gym_Text_LisaPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Tina::
	trainerbattle_single TRAINER_PICNICKER_TINA, CeladonCity_Gym_Text_TinaIntro, CeladonCity_Gym_Text_TinaDefeat
	msgbox CeladonCity_Gym_Text_TinaPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Bridget::
	trainerbattle_single TRAINER_BEAUTY_BRIDGET, CeladonCity_Gym_Text_BridgetIntro, CeladonCity_Gym_Text_BridgetDefeat
	msgbox CeladonCity_Gym_Text_BridgetPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Tamia::
	trainerbattle_single TRAINER_BEAUTY_TAMIA, CeladonCity_Gym_Text_TamiaIntro, CeladonCity_Gym_Text_TamiaDefeat
	famechecker FAMECHECKER_ERIKA, 3
	msgbox CeladonCity_Gym_Text_TamiaPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Lori::
	trainerbattle_single TRAINER_BEAUTY_LORI, CeladonCity_Gym_Text_LoriIntro, CeladonCity_Gym_Text_LoriDefeat
	msgbox CeladonCity_Gym_Text_LoriPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Mary::
	trainerbattle_single TRAINER_COOLTRAINER_MARY, CeladonCity_Gym_Text_MaryIntro, CeladonCity_Gym_Text_MaryDefeat
	msgbox CeladonCity_Gym_Text_MaryPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, CeladonCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeladonCity_Gym_Text_GymStatue
	releaseall
	end

CeladonCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeladonCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeladonCity_Gym_Text_ErikaIntro::
	.string "Ciao…\n"
	.string "Che bel METEO, vero?\l"
	.string "Che pace…\p"
	.string "…Oh, cielo…\n"
	.string "Mi sono appisolata. Prego.\p"
	.string "Mi chiamo ERIKA.\n"
	.string "Sono la CAPO della PALESTRA.\p"
	.string "Sono un'esperta dell'arte\n"
	.string "floreale.\p"
	.string "I miei POKéMON sono solo di\n"
	.string "tipo ERBA.\p"
	.string "…Oh, scusa, non sapevo che\n"
	.string "volessi sfidarmi.\p"
	.string "Va bene, ma non perderò.{PLAY_BGM MUS_RG_ENCOUNTER_GYM_LEADER}$"

CeladonCity_Gym_Text_ErikaDefeat::
	.string "Oh!\n"
	.string "Mi arrendo.\l"
	.string "Sei davvero forte.\p"
	.string "Ti conferisco la\n"
	.string "RAINBOWBADGE.$"

CeladonCity_Gym_Text_ErikaPostBattle::
	.string "Stai catalogando i POKéMON?\n"
	.string "Sono davvero colpita.\p"
	.string "Non collezionerei POKéMON se\n"
	.string "non fossero attraenti.$"

CeladonCity_Gym_Text_ExplainRainbowBadgeTakeThis::
	.string "La RAINBOWBADGE farà\n"
	.string "obbedire fino al Lv. 50.\p"
	.string "Permette anche di usare\n"
	.string "FORZA dentro e fuori lotta.\p"
	.string "Prendi anche questo.$"

CeladonCity_Gym_Text_ReceivedTM19FromErika::
	.string "{PLAYER} riceve TM19\n"
	.string "da ERIKA.$"

CeladonCity_Gym_Text_ExplainTM19::
	.string "MT19: GIGASSORBIMENTO.\p"
	.string "Metà del danno inflitto\n"
	.string "cura i tuoi POKéMON.\p"
	.string "Non è forse una\n"
	.string "mossa stupenda?$"

CeladonCity_Gym_Text_ShouldMakeRoomForThis::
	.string "Dovresti fare spazio.$"

CeladonCity_Gym_Text_KayIntro::
	.string "Ti spiego questa PALESTRA.\p"
	.string "Qui entrano solo vere\n"
	.string "dame!$"

CeladonCity_Gym_Text_KayDefeat::
	.string "Sei troppo rude!$"

CeladonCity_Gym_Text_KayPostBattle::
	.string "Bleah!\n"
	.string "Spero che ERIKA ti batta!$"

CeladonCity_Gym_Text_BridgetIntro::
	.string "Oh, ciao.\n"
	.string "Mi stavo annoiando.$"

CeladonCity_Gym_Text_BridgetDefeat::
	.string "Il trucco!$"

CeladonCity_Gym_Text_BridgetPostBattle::
	.string "Il tipo ERBA è forte\n"
	.string "contro il tipo ACQUA.\p"
	.string "Vantaggio anche su ROCCIA e\n"
	.string "POKéMON di tipo TERRA.$"

CeladonCity_Gym_Text_TinaIntro::
	.string "…Non sbirciavi qui\n"
	.string "prima?$"

CeladonCity_Gym_Text_TinaDefeat::
	.string "Mi hai stupito!$"

CeladonCity_Gym_Text_TinaPostBattle::
	.string "Oh, guardavi ERIKA…\n"
	.string "Non guardavi me…$"

CeladonCity_Gym_Text_TamiaIntro::
	.string "Oh, guarda!\n"
	.string "Vedi i POKéMON!\p"
	.string "Adoro il tipo ERBA.\n"
	.string "Sono facili da allenare.$"

CeladonCity_Gym_Text_TamiaDefeat::
	.string "No!$"

CeladonCity_Gym_Text_TamiaPostBattle::
	.string "Nella PALESTRA usiamo POKéMON\n"
	.string "d'ERBA.\p"
	.string "Perché? Ci servono anche per\n"
	.string "comporre fiori!$"

CeladonCity_Gym_Text_LisaIntro::
	.string "Oh, ehi!\p"
	.string "Qui non amiamo i tipi\n"
	.string "COLEOTTERO o FUOCO!$"

CeladonCity_Gym_Text_LisaDefeat::
	.string "Oh!\n"
	.string "Tu!$"

CeladonCity_Gym_Text_LisaPostBattle::
	.string "La nostra CAPO ERIKA sembra\n"
	.string "silenziosa, ma è famosa.$"

CeladonCity_Gym_Text_LoriIntro::
	.string "Molto piacere.\n"
	.string "Adoro allenare i POKéMON.$"

CeladonCity_Gym_Text_LoriDefeat::
	.string "Oh!\n"
	.string "Splendido!$"

CeladonCity_Gym_Text_LoriPostBattle::
	.string "Ho un appuntamento al buio.\n"
	.string "Devo essere gentile,\l"
	.string "soprattutto in lotta.$"

CeladonCity_Gym_Text_MaryIntro::
	.string "Benvenuti in PALESTRA!\p"
	.string "Non sottovalutare le nostre\n"
	.string "gentili signore!$"

CeladonCity_Gym_Text_MaryDefeat::
	.string "Oh!\n"
	.string "Battuta!$"

CeladonCity_Gym_Text_MaryPostBattle::
	.string "Non ho portato i POKéMON\n"
	.string "più forti, aspetta!$"

CeladonCity_Gym_Text_GymStatue::
	.string "PALESTRA AZZURROPOLI\n"
	.string "CAPO: ERIKA\p"
	.string "VINCITORI:\n"
	.string "{RIVAL}$"

CeladonCity_Gym_Text_GymStatuePlayerWon::
	.string "PALESTRA AZZURROPOLI\n"
	.string "CAPO: ERIKA\p"
	.string "VINCITORI:\n"
	.string "{RIVAL}, {PLAYER}$"

