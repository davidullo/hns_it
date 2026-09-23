CeladonCity_Gym_hns_MapScripts::
	.byte 0


CeladonCity_Gym_EventScript_Erika::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CELADON_GYM, CeladonCity_Gym_EventScript_Erika_Defeated
	msgbox CeladonCity_Gym_Text_ErikaBeforeBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ERIKA_HNS, CeladonCity_Gym_Text_ErikaBeaten
	message CeladonCity_Gym_Text_PlayerReceivedRainbowBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox CeladonCity_Gym_Text_Erika_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_GIGA_DRAIN
	msgbox CeladonCity_Gym_Text_Erika_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE12_GET
	setflag FLAG_DEFEATED_CELADON_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 12
	call Common_EventScript_SetGymTrainers_hns
	clearflag FLAG_HIDE_FOUNTAIN_ERIKA
	closemessage
	release
	end

CeladonCity_Gym_EventScript_Erika_Defeated::
	msgbox CeladonCity_Gym_Text_ErikaAfterBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonCity_Gym_Text_ErikaBeforeBattle:
	.string "ERIKA: Ciao… Bel tempo,\n"
	.string "vero? Che piacevole…\p"
	.string "…Rischio di appisolarmi…\p"
	.string "Sono ERIKA, la CAPOPALESTRA\n"
	.string "di AZZURROPOLI.\p"
	.string "…Oh? Arrivi da JOHTO,\n"
	.string "dici? Bello…\p"
	.string "Oh, scusa, non avevo capito\n"
	.string "che volevi sfidarmi.\p"
	.string "Bene, ma non perderò.$"

CeladonCity_Gym_Text_ErikaBeaten:
	.string "ERIKA: Oh! Mi arrendo…\p"
	.string "Sei molto forte…\p"
	.string "Ti do la MEDAGLIA ARCOBALENO…$"

CeladonCity_Gym_Text_PlayerReceivedRainbowBadge:
	.string "{PLAYER} riceve MEDAGLIA ARCOBALENO.$"

CeladonCity_Gym_Text_Erika_GiveTM:
	.string "ERIKA: È stata una bella\n"
	.string "gara.\p"
	.string "Mi sono ispirata. Vorrei\n"
	.string "darti questa TM.$"

CeladonCity_Gym_Text_Erika_ExplainTM:
	.string "GIGASSORBIMENTO.\p"
	.string "È una mossa fantastica che\n"
	.string "assorbe metà del danno inflitto\l"
	.string "e cura i POKéMON.\p"
	.string "Usala se ti fa piacere…$"

CeladonCity_Gym_Text_ErikaAfterBattle:
	.string "ERIKA: Perdere lascia\n"
	.string "l'amaro…\p"
	.string "Ma sapere che ci sono\n"
	.string "allenatori forti mi sprona…$"

CeladonCity_Gym_Text_ErikaRematch:
	.string "ERIKA: Oh, ciao.\p"
	.string "Che sorpresa, CAMPIONE di KANTO!\p"
	.string "Che bello rivederti.\p"
	.string "Il tuo viaggio sarà stato\n"
	.string "intenso.\p"
	.string "Anche i campioni amano le sfide.\p"
	.string "Vuoi una rivincita con me?$"

CeladonCity_Gym_Text_ErikaRematchDefeat:
	.string "ERIKA: Anche perdere\n"
	.string "lascia l'amaro…\p"
	.string "Ma sapere che ci sono\n"
	.string "allenatori forti mi sprona…$"

CeladonCity_Gym_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE_HNS, CeladonCity_Gym_Text_LassMichelleSeen, CeladonCity_Gym_Text_LassMichelleBeaten
	msgbox CeladonCity_Gym_Text_LassMichelleAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_LassMichelleSeen:
	.string "Pensi che una PALESTRA di sole\n"
	.string "ragazze sia rara?$"

CeladonCity_Gym_Text_LassMichelleBeaten:
	.string "Oh, bleah!$"

CeladonCity_Gym_Text_LassMichelleAfter:
	.string "Mi sono solo distratta!$"


CeladonCity_Gym_EventScript_Tanya::
	trainerbattle_single TRAINER_TANYA_HNS, CeladonCity_Gym_Text_PicnickerTanyaSeen, CeladonCity_Gym_Text_PicnickerTanyaBeaten
	msgbox CeladonCity_Gym_Text_PicnickerTanyaAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_PicnickerTanyaSeen:
	.string "Oh, una lotta? Fa un po' paura,\n"
	.string "ma OK!$"

CeladonCity_Gym_Text_PicnickerTanyaBeaten:
	.string "Oh, tutto qui?$"

CeladonCity_Gym_Text_PicnickerTanyaAfter:
	.string "Guarda quante MEDAGLIE hai!\n"
	.string "Ecco perché ho perso!$"

CeladonCity_Gym_EventScript_Julia::
	trainerbattle_single TRAINER_JULIA_HNS, CeladonCity_Gym_Text_BeautyJuliaSeen, CeladonCity_Gym_Text_BeautyJuliaBeaten
	msgbox CeladonCity_Gym_Text_BeautyJuliaAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_BeautyJuliaSeen:
	.string "Guardavi questi fiori\n"
	.string "o me?$"

CeladonCity_Gym_Text_BeautyJuliaBeaten:
	.string "Che noia!$"

CeladonCity_Gym_Text_BeautyJuliaAfter:
	.string "Come divento raffinata\n"
	.string "come ERIKA?$"

CeladonCity_Gym_EventScript_Jo::
	trainerbattle_double TRAINER_JO_AND_ZOE_HNS, CeladonCity_Gym_Text_TwinsJoAndZoe1Seen, CeladonCity_Gym_Text_TwinsJoAndZoe1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox CeladonCity_Gym_Text_TwinsJoAndZoe1After, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Zoe::
	trainerbattle_double TRAINER_JO_AND_ZOE_HNS, CeladonCity_Gym_Text_TwinsJoAndZoe2Seen, CeladonCity_Gym_Text_TwinsJoAndZoe2Beaten, Route104_Text_GinaNotEnoughMons
	msgbox CeladonCity_Gym_Text_TwinsJoAndZoe2After, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_TwinsJoAndZoe1Seen:
	.string "Le mosse POKéMON che ci ha\n"
	.string "insegnato ERIKA!$"

CeladonCity_Gym_Text_TwinsJoAndZoe1Beaten:
	.string "Oh… abbiamo perso…$"

CeladonCity_Gym_Text_TwinsJoAndZoe1After:
	.string "ERIKA ci vendicherà!$"

CeladonCity_Gym_Text_TwinsJoAndZoe2Seen:
	.string "Proteggeremo ERIKA!$"

CeladonCity_Gym_Text_TwinsJoAndZoe2Beaten:
	.string "Abbiamo perso…$"

CeladonCity_Gym_Text_TwinsJoAndZoe2After:
	.string "ERIKA è molto più forte!$"

CeladonCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE12_GET, CeladonCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeladonCity_Gym_Text_GymStatue
	releaseall
	end

CeladonCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeladonCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeladonCity_Gym_Text_GymStatue::
    .string "PALESTRA DI AZZURROPOLI\n"
    .string "CAPO: ERIKA\p"
	.string "VINCITORI:\n"
	.string "BLU,ROSSO$"

CeladonCity_Gym_Text_GymStatuePlayerWon::
    .string "PALESTRA DI AZZURROPOLI\n"
    .string "CAPO: ERIKA\p"
    .string "VINCITORI:\n"
	.string "BLU,ROSSO,{PLAYER}$"
