SaffronCity_Gym_hns_MapScripts::
	.byte 0

SaffronCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_SAFFRON_GYM, SaffronCity_Gym_EventScript_GymGuy2
	msgbox SaffronCity_Gym_Text_GymGuideIntro, MSGBOX_NPC
	end

SaffronCity_Gym_EventScript_GymGuy2::
	msgbox SaffronCity_Gym_Text_GymGuideWin, MSGBOX_NPC
	end

SaffronCity_Gym_EventScript_Rebecca::
	trainerbattle_single TRAINER_REBECCA_HNS, SaffronCity_Gym_Text_MediumRebeccaSeen, SaffronCity_Gym_Text_MediumRebeccaBeaten
	msgbox SaffronCity_Gym_Text_MediumRebeccaAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Franklin::
	trainerbattle_single TRAINER_FRANKLIN_HNS, SaffronCity_Gym_Text_PsychicFranklinSeen, SaffronCity_Gym_Text_PsychicFranklinBeaten
	msgbox SaffronCity_Gym_Text_PsychicFranklinAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Doris::
	trainerbattle_single TRAINER_DORIS_HNS, SaffronCity_Gym_Text_MediumDorisSeen, SaffronCity_Gym_Text_MediumDorisBeaten
	msgbox SaffronCity_Gym_Text_MediumDorisAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED_HNS, SaffronCity_Gym_Text_PsychicJaredSeen, SaffronCity_Gym_Text_PsychicJaredBeaten
	msgbox SaffronCity_Gym_Text_PsychicJaredAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Sabrina::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SAFFRON_GYM, SaffronCity_Gym_EventScript_Sabrina_Defeated
	msgbox SaffronCity_Gym_Text_SabrinaIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SABRINA_HNS, SaffronCity_Gym_Text_SabrinaWinLoss
	message SaffronCity_Gym_Text_ReceivedMarshBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SaffronCity_Gym_Text_MarshBadgeInfo, MSGBOX_DEFAULT
	msgbox SaffronCity_Gym_Text_Sabrina_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_SKILL_SWAP
	msgbox SaffronCity_Gym_Text_Sabrina_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE13_GET
	setflag FLAG_DEFEATED_SAFFRON_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 13
	call Common_EventScript_SetGymTrainers_hns
	closemessage
	clearflag FLAG_HIDE_OLIVINE_SABRINA
	release
	end

SaffronCity_Gym_EventScript_Sabrina_Defeated::
	msgbox SaffronCity_Gym_Text_SabrinaPostBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_Gym_Text_SabrinaIntro:
	.string "SABRINA: Sapevo che saresti arrivato…\p"
	.string "Tre anni fa ebbi una visione\n"
	.string "del tuo arrivo.\p"
	.string "Vuoi la mia MEDAGLIA.\p"
	.string "Non amo lottare, ma è mio\n"
	.string "dovere di CAPO conferire\l"
	.string "MEDAGLIE a chi ha dimostrato\l"
	.string "di esserne degno.\p"
	.string "Dato che lo vuoi, ti mostrerò\n"
	.string "i miei poteri psichici!$"

SaffronCity_Gym_Text_SabrinaWinLoss:
	.string "SABRINA: La tua forza…\p"
	.string "Supera di molto le mie previsioni…\p"
	.string "Forse non si può prevedere\n"
	.string "del tutto il futuro…\p"
	.string "OK, hai vinto. Ti sei guadagnato\n"
	.string "la MARSHBADGE.$"

SaffronCity_Gym_Text_ReceivedMarshBadge:
	.string "{PLAYER} riceve la MARSHBADGE.$"

SaffronCity_Gym_Text_MarshBadgeInfo:
	.string "SABRINA: la MEDAGLIA PALUDE tira fuori\n"
	.string "i tuoi poteri subliminali…\p"
	.string "Non ho saputo predire la tua\n"
	.string "forza con precisione, ma questo\l"
	.string "lo so per certo.\p"
	.string "Diventerai un CAMPIONE celebrato\n"
	.string "e amato!$"

SaffronCity_Gym_Text_Sabrina_GiveTM:
	.string "Tieni, prendi anche questo.$"

SaffronCity_Gym_Text_Sabrina_ExplainTM:
	.string "It holds SKILL SWAP.\p"
	.string "It can take your opponents' abilities\n"
	.string "away from them and give them your own.\p"
	.string "Use it wisely...$"

SaffronCity_Gym_Text_SabrinaPostBattle:
	.string "SABRINA: Il tuo amore per i\n"
	.string "POKéMON ha vinto il mio potere\l"
	.string "psichico…\p"
	.string "La forza dell'amore, credo,\n"
	.string "è anch'essa un potere psichico…$"

SaffronCity_Gym_Text_SabrinaRematch:
	.string "SABRINA: Ah, il CAMPIONE di KANTO.\p"
	.string "Ho sentito il tuo ritorno.\p"
	.string "La tua forza è cresciuta molto.\p"
	.string "Ancora ora sento la tua aura.\p"
	.string "Vuoi una rivincita con me?$"

SaffronCity_Gym_Text_SabrinaRematchDefeat:
	.string "SABRINA: Il tuo amore per i\n"
	.string "POKéMON ha di nuovo vinto il\l"
	.string "mio potere psichico…$"

SaffronCity_Gym_Text_MediumRebeccaSeen:
	.string "La forza di chi hai battuto\n"
	.string "arriva fino a me!$"

SaffronCity_Gym_Text_MediumRebeccaBeaten:
	.string "Forte… Troppo forte…$"

SaffronCity_Gym_Text_MediumRebeccaAfter:
	.string "Qual è la fonte del tuo potere?$"

SaffronCity_Gym_Text_PsychicFranklinSeen:
	.string "Il potere psichico è la forza\n"
	.string "della tua anima.$"

SaffronCity_Gym_Text_PsychicFranklinBeaten:
	.string "La tua anima ha più forza\n"
	.string "della mia!$"

SaffronCity_Gym_Text_PsychicFranklinAfter:
	.string "Hai reso più forte l'anima, non\n"
	.string "solo le tue abilità.$"

SaffronCity_Gym_Text_MediumDorisSeen:
	.string "Fufufufu… lo vedo chiaramente.\p"
	.string "Vedo dentro la tua anima!$"

SaffronCity_Gym_Text_MediumDorisBeaten:
	.string "Ti avevo letto, ma ho perso lo stesso…$"

SaffronCity_Gym_Text_MediumDorisAfter:
	.string "Accidenti! Avevo previsto che\n"
	.string "avrei perso contro di te.$"

SaffronCity_Gym_Text_PsychicJaredSeen:
	.string "Il DOJO LOTTA qui accanto era\n"
	.string "un tempo la PALESTRA di città.$"

SaffronCity_Gym_Text_PsychicJaredBeaten:
	.string "Non ero alla tua altezza…$"

SaffronCity_Gym_Text_PsychicJaredAfter:
	.string "Il RE DEL KARATE, maestro del\n"
	.string "DOJO LOTTA, è stato appena\l"
	.string "distrutto da SABRINA.$"

SaffronCity_Gym_Text_GymGuideIntro:
	.string "Ehi, CAMPIONE in erba!\p"
	.string "Un allenatore abile come te\n"
	.string "non ha bisogno di sapere come\l"
	.string "affrontare i POKéMON di tipo PSICO,\l"
	.string "vero?\p"
	.string "Mi aspetto grandi cose da te!\p"
	.string "Buona fortuna!$"

SaffronCity_Gym_Text_GymGuideWin:
	.string "È stata un'altra lotta fantastica!$"

SaffronCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE13_GET, SaffronCity_Gym_EventScript_GymStatuePostVictory
	msgbox SaffronCity_Gym_Text_GymStatue
	releaseall
	end

SaffronCity_Gym_EventScript_GymStatuePostVictory::
	msgbox SaffronCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end


SaffronCity_Gym_Text_GymStatue::
    .string "PALESTRA POKéMON ZAFFIRO\n"
    .string "CAPO: SABRINA\p"
	.string "ALLENATORI VINCENTI:\n"
	.string "BLU, ROSSO$"

SaffronCity_Gym_Text_GymStatuePlayerWon::
    .string "PALESTRA POKéMON ZAFFIRO\n"
    .string "CAPO: SABRINA\p"
    .string "ALLENATORI VINCENTI:\n"
	.string "BLU, ROSSO, {PLAYER}$"
