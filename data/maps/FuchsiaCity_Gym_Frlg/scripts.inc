FuchsiaCity_Gym_Frlg_MapScripts::
	.byte 0

FuchsiaCity_Gym_EventScript_Koga::
	famechecker FAMECHECKER_KOGA, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_KOGA, FuchsiaCity_Gym_Text_KogaIntro, FuchsiaCity_Gym_Text_KogaDefeat, FuchsiaCity_Gym_EventScript_DefeatedKoga, NO_MUSIC
	goto_if_unset FLAG_GOT_TM06_FROM_KOGA, FuchsiaCity_Gym_EventScript_GiveTM06
	msgbox FuchsiaCity_Gym_Text_KogaPostBattle
	release
	end

FuchsiaCity_Gym_EventScript_DefeatedKoga::
	famechecker FAMECHECKER_KOGA, 1
	clearflag FLAG_HIDE_FAME_CHECKER_KOGA_JOURNAL
	setflag FLAG_DEFEATED_KOGA
	setflag FLAG_BADGE05_GET
	set_gym_trainers_frlg 5
	goto FuchsiaCity_Gym_EventScript_GiveTM06
	end

FuchsiaCity_Gym_EventScript_GiveTM06::
	msgbox FuchsiaCity_Gym_Text_KogaExplainSoulBadge
	checkitemspace ITEM_TM06
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_Gym_EventScript_NoRoomForTM06
	giveitem_msg FuchsiaCity_Gym_Text_ReceivedTM06FromKoga, ITEM_TM06
	setflag FLAG_GOT_TM06_FROM_KOGA
	msgbox FuchsiaCity_Gym_Text_KogaExplainTM06
	release
	end

FuchsiaCity_Gym_EventScript_NoRoomForTM06::
	msgbox FuchsiaCity_Gym_Text_MakeSpaceForThis
	release
	end

FuchsiaCity_Gym_EventScript_Phil::
	trainerbattle_single TRAINER_TAMER_PHIL, FuchsiaCity_Gym_Text_PhilIntro, FuchsiaCity_Gym_Text_PhilDefeat
	msgbox FuchsiaCity_Gym_Text_PhilPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Edgar::
	trainerbattle_single TRAINER_TAMER_EDGAR, FuchsiaCity_Gym_Text_EdgarIntro, FuchsiaCity_Gym_Text_EdgarDefeat
	msgbox FuchsiaCity_Gym_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Kirk::
	trainerbattle_single TRAINER_JUGGLER_KIRK, FuchsiaCity_Gym_Text_KirkIntro, FuchsiaCity_Gym_Text_KirkDefeat
	famechecker FAMECHECKER_KOGA, 2
	msgbox FuchsiaCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Shawn::
	trainerbattle_single TRAINER_JUGGLER_SHAWN, FuchsiaCity_Gym_Text_ShawnIntro, FuchsiaCity_Gym_Text_ShawnDefeat
	msgbox FuchsiaCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Kayden::
	trainerbattle_single TRAINER_JUGGLER_KAYDEN, FuchsiaCity_Gym_Text_KaydenIntro, FuchsiaCity_Gym_Text_KaydenDefeat
	msgbox FuchsiaCity_Gym_Text_KaydenPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Nate::
	trainerbattle_single TRAINER_JUGGLER_NATE, FuchsiaCity_Gym_Text_NateIntro, FuchsiaCity_Gym_Text_NateDefeat
	msgbox FuchsiaCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_KOGA, FuchsiaCity_Gym_EventScript_GymGuyPostVictory
	msgbox FuchsiaCity_Gym_Text_GymGuyAdvice
	release
	end

FuchsiaCity_Gym_EventScript_GymGuyPostVictory::
	msgbox FuchsiaCity_Gym_Text_GymGuyPostVictory
	release
	end

FuchsiaCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE05_GET, FuchsiaCity_Gym_EventScript_GymStatuePostVictory
	msgbox FuchsiaCity_Gym_Text_GymStatue
	releaseall
	end

FuchsiaCity_Gym_EventScript_GymStatuePostVictory::
	msgbox FuchsiaCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

FuchsiaCity_Gym_Text_KogaIntro::
	.string "KOGA: Uahahaha!\p"
	.string "Un semplice bambino osa\n"
	.string "sfidarmi?\p"
	.string "Solo l'idea mi fa tremare\n"
	.string "dal ridere!\p"
	.string "Molto bene, ti mostrerò\n"
	.string "il vero terrore ninja.\p"
	.string "Il Veleno porta rovina.\n"
	.string "Il Sonno blocca i nemici.\p"
	.string "Dispera davanti all'orrore\n"
	.string "dei POKéMON di tipo VELENO!{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

FuchsiaCity_Gym_Text_KogaDefeat::
	.string "Umpf!\n"
	.string "Hai dimostrato valore!\p"
	.string "Ecco!\n"
	.string "Prendi la MEDAGLIA ANIMA!$"

FuchsiaCity_Gym_Text_KogaPostBattle::
	.string "Se colpito da TOSSINA, un POKéMON\n"
	.string "soffre sempre di più.\p"
	.string "I danni peggiorano col passare\n"
	.string "della lotta!\p"
	.string "Seminerà di certo il terrore!$"

FuchsiaCity_Gym_Text_KogaExplainSoulBadge::
	.string "Ora che hai la MEDAGLIA ANIMA,\n"
	.string "la DIFESA dei POKéMON aumenta.\p"
	.string "Fuori dalla lotta puoi usare\n"
	.string "SURF.\p"
	.string "Ah!\n"
	.string "Anche questo!$"

FuchsiaCity_Gym_Text_ReceivedTM06FromKoga::
	.string "{PLAYER} riceve la MT06\n"
	.string "da KOGA.$"

FuchsiaCity_Gym_Text_KogaExplainTM06::
	.string "Dentro la MT06 è racchiusa\n"
	.string "TOSSINA!\p"
	.string "È una tecnica segreta che\n"
	.string "risale a quattro secoli fa.$"

FuchsiaCity_Gym_Text_MakeSpaceForThis::
	.string "Fai largo, piccolo!$"

FuchsiaCity_Gym_Text_KaydenIntro::
	.string "Per i POKéMON la Forza non è\n"
	.string "la chiave. Lo capisci?\p"
	.string "POKéMON è strategia!\p"
	.string "Ti mostro come la strategia\n"
	.string "batte la forza bruta.$"

FuchsiaCity_Gym_Text_KaydenDefeat::
	.string "Cosa?\n"
	.string "Straordinario!$"

FuchsiaCity_Gym_Text_KaydenPostBattle::
	.string "Unisci muscoli e cervello?\n"
	.string "Che strategia!\p"
	.string "Notevole per un ragazzo\n"
	.string "ALLENATORE.$"

FuchsiaCity_Gym_Text_KirkIntro::
	.string "Facevo il prestigiatore, un tempo.\p"
	.string "Ma sognavo di diventare ninja,\n"
	.string "mi unii alla PALESTRA.$"

FuchsiaCity_Gym_Text_KirkDefeat::
	.string "Sono finito!$"

FuchsiaCity_Gym_Text_KirkPostBattle::
	.string "Anche se ho perso, continuerò\n"
	.string "ad allenarmi seguendo gli\l"
	.string "insegnamenti di KOGA.$"

FuchsiaCity_Gym_Text_NateIntro::
	.string "Vediamo se superi le mie\n"
	.string "tecniche speciali!$"

FuchsiaCity_Gym_Text_NateDefeat::
	.string "Mi hai ingannato!$"

FuchsiaCity_Gym_Text_NatePostBattle::
	.string "Mi piacciono le tecniche di veleno\n"
	.string "che durano dopo la lotta!$"

FuchsiaCity_Gym_Text_PhilIntro::
	.string "Fermati lì!\p"
	.string "I muri invisibili della\n"
	.string "PALESTRA FUCHSIA ti ingannano?$"

FuchsiaCity_Gym_Text_PhilDefeat::
	.string "Uau!\n"
	.string "Ci sai fare!$"

FuchsiaCity_Gym_Text_PhilPostBattle::
	.string "Mi hai colpito!\n"
	.string "Un indizio!\p"
	.string "Cerca bene le fessure nei\n"
	.string "muri invisibili!$"

FuchsiaCity_Gym_Text_EdgarIntro::
	.string "Studio anche la via del ninja\n"
	.string "col Maestro KOGA!\p"
	.string "Da sempre i ninja si servono di\n"
	.string "animali!$"

FuchsiaCity_Gym_Text_EdgarDefeat::
	.string "Awoo!$"

FuchsiaCity_Gym_Text_EdgarPostBattle::
	.string "Devo ancora imparare molto.$"

FuchsiaCity_Gym_Text_ShawnIntro::
	.string "Il maestro KOGA è di lunga stirpe\n"
	.string "ninja.\p"
	.string "E tu da chi discendi?$"

FuchsiaCity_Gym_Text_ShawnDefeat::
	.string "Sei più bravo di quanto\n"
	.string "credevo!$"

FuchsiaCity_Gym_Text_ShawnPostBattle::
	.string "Dove c'è la luce, c'è\n"
	.string "ombra!\p"
	.string "Luce e ombra!\n"
	.string "Quale scegli?$"

FuchsiaCity_Gym_Text_GymGuyAdvice::
	.string "Ehi!\n"
	.string "Campione in erba!\p"
	.string "La PALESTRA di FUCHSIA è un\n"
	.string "posto pieno di muri invisibili!\p"
	.string "KOGA può sembrare vicino, ma è\n"
	.string "bloccato.\p"
	.string "Devi trovare i varchi nei muri\n"
	.string "per arrivarci.$"

FuchsiaCity_Gym_Text_GymGuyPostVictory::
	.string "I ninja incutono terrore\n"
	.string "tuttora!$"

FuchsiaCity_Gym_Text_GymStatue::
	.string "PALESTRA POKéMON\n"
	.string "CAPO: KOGA\p"
	.string "VINCITORI:\n"
	.string "{RIVAL}$"

FuchsiaCity_Gym_Text_GymStatuePlayerWon::
	.string "PALESTRA POKéMON\n"
	.string "CAPO: KOGA\p"
	.string "VINCITORI:\n"
	.string "{RIVAL}, {PLAYER}$"

