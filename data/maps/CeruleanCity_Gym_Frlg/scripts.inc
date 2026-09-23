CeruleanCity_Gym_Frlg_MapScripts::
	.byte 0

CeruleanCity_Gym_EventScript_Misty::
	famechecker FAMECHECKER_MISTY, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_MISTY, CeruleanCity_Gym_Text_MistyIntro, CeruleanCity_Gym_Text_MistyDefeat, CeruleanCity_Gym_EventScript_MistyDefeated, NO_MUSIC
	goto_if_unset FLAG_GOT_TM03_FROM_MISTY, CeruleanCity_Gym_EventScript_GiveTM03
	msgbox CeruleanCity_Gym_Text_ExplainTM03
	release
	end

CeruleanCity_Gym_EventScript_MistyDefeated::
	famechecker FAMECHECKER_MISTY, 1
	setflag FLAG_DEFEATED_MISTY
	setflag FLAG_BADGE02_GET
	setrespawn HEAL_LOCATION_CERULEAN_CITY
	set_gym_trainers_frlg 2
	goto CeruleanCity_Gym_EventScript_GiveTM03
	end

CeruleanCity_Gym_EventScript_GiveTM03::
	msgbox CeruleanCity_Gym_Text_ExplainCascadeBadge
	checkitemspace ITEM_TM03
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_Gym_EventScript_NoRoomForTM03
	giveitem_msg CeruleanCity_Gym_Text_ReceivedTM03FromMisty, ITEM_TM03
	setflag FLAG_GOT_TM03_FROM_MISTY
	msgbox CeruleanCity_Gym_Text_ExplainTM03
	release
	end

CeruleanCity_Gym_EventScript_NoRoomForTM03::
	msgbox CeruleanCity_Gym_Text_BetterMakeRoomForThis
	release
	end

CeruleanCity_Gym_EventScript_Diana::
	trainerbattle_single TRAINER_PICNICKER_DIANA, CeruleanCity_Gym_Text_DianaIntro, CeruleanCity_Gym_Text_DianaDefeat
	msgbox CeruleanCity_Gym_Text_DianaPostBattle, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_Luis::
	trainerbattle_single TRAINER_SWIMMER_MALE_LUIS, CeruleanCity_Gym_Text_LuisIntro, CeruleanCity_Gym_Text_LuisDefeat
	famechecker FAMECHECKER_MISTY, 2
	msgbox CeruleanCity_Gym_Text_LuisPostBattle, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MISTY, CeruleanCity_Gym_EventScript_GymGuyPostVictory
	msgbox CeruleanCity_Gym_Text_GymGuyAdvice
	release
	end

CeruleanCity_Gym_EventScript_GymGuyPostVictory::
	msgbox CeruleanCity_Gym_Text_WeMakePrettyGoodTeam
	release
	end

CeruleanCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, CeruleanCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeruleanCity_Gym_Text_GymStatue
	releaseall
	end

CeruleanCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeruleanCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeruleanCity_Gym_Text_MistyIntro::
	.string "Ciao, sei nuovo qui!\p"
	.string "Solo gli ALLENATORI con una\n"
	.string "politica sui POKéMON diventano pro.\p"
	.string "Come la pensi quando catturi\n"
	.string "e alleni i POKéMON?\p"
	.string "La mia è un attacco totale con\n"
	.string "POKéMON di tipo ACQUA!{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

CeruleanCity_Gym_Text_ExplainTM03::
	.string "MT03 insegna PULSAR.\p"
	.string "Usala su un POKéMON d'acqua!$"

CeruleanCity_Gym_Text_ExplainCascadeBadge::
	.string "La CASCADEBADGE fa obbedire\n"
	.string "i POKéMON fino al Lv. 30.\p"
	.string "Vale anche per i POKéMON\n"
	.string "scambiati.\p"
	.string "E c'è di più. Ora puoi usare\n"
	.string "TAGLIO sempre, fuori lotta.\p"
	.string "Puoi TAGLIARE gli alberelli\n"
	.string "e aprire nuove vie.\p"
	.string "E ti do anche la mia MT preferita.$"

CeruleanCity_Gym_Text_ReceivedTM03FromMisty::
	.string "{PLAYER} riceve MT03\n"
	.string "da MISTY.$"

CeruleanCity_Gym_Text_BetterMakeRoomForThis::
	.string "Meglio fare spazio a questo!$"

CeruleanCity_Gym_Text_MistyDefeat::
	.string "Wow!\n"
	.string "Troppo forte!\p"
	.string "Va bene!\p"
	.string "Tieni la CASCADEBADGE:\n"
	.string "hai vinto tu!$"

CeruleanCity_Gym_Text_DianaIntro::
	.string "Cosa? Tu?\n"
	.string "Sono più che all'altezza per te!\p"
	.string "MISTY non dovrà disturbarsi.$"

CeruleanCity_Gym_Text_DianaDefeat::
	.string "Mi hai travolto!$"

CeruleanCity_Gym_Text_DianaPostBattle::
	.string "Devi sfidare altri ALLENATORI\n"
	.string "per capire quanto vali davvero.$"

CeruleanCity_Gym_Text_LuisIntro::
	.string "Splash!\p"
	.string "Tocca a me!\n"
	.string "Andiamo!$"

CeruleanCity_Gym_Text_LuisDefeat::
	.string "Impossibile!$"

CeruleanCity_Gym_Text_LuisPostBattle::
	.string "MISTY è una ALLENATRICE in\n"
	.string "crescita.\p"
	.string "Non perderà contro uno come te!$"

CeruleanCity_Gym_Text_GymGuyAdvice::
	.string "Ehi!\n"
	.string "Campione in erba!\p"
	.string "Ti do un consiglio!\p"
	.string "MISTY, la CAPO, è una pro che\n"
	.string "usa POKéMON di tipo ACQUA.\p"
	.string "Puoi prosciugare l'acqua con\n"
	.string "POKéMON di tipo ERBA.\p"
	.string "Oppure usa POKéMON di tipo\n"
	.string "ELETTRICO e folgorali!$"

CeruleanCity_Gym_Text_WeMakePrettyGoodTeam::
	.string "MISTY battuta!\n"
	.string "Visto? Lo dicevo io!\p"
	.string "Tu e io, ragazzo, formiamo una\n"
	.string "squadra forte!$"

CeruleanCity_Gym_Text_GymStatue::
	.string "PALESTRA DI CELESTE\n"
	.string "CAPO: MISTY\p"
	.string "VINCITORI:\n"
	.string "{RIVAL}$"

CeruleanCity_Gym_Text_GymStatuePlayerWon::
	.string "PALESTRA DI CELESTE\n"
	.string "CAPO: MISTY\p"
	.string "VINCITORI:\n"
	.string "{RIVAL}, {PLAYER}$"

