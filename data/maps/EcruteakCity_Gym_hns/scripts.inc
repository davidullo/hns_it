EcruteakCity_Gym_hns_MapScripts::
	.byte 0

EcruteakCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_GymGuy2
	msgbox EcruteakCity_GymGuideText, MSGBOX_DEFAULT
	closemessage
	release
	end
	
EcruteakCity_Gym_EventScript_GymGuy2::
	msgbox EcruteakCity_GymGuideWinText, MSGBOX_DEFAULT
	release
	end	

EcruteakCity_Gym_EventScript_Jeffrey::
	trainerbattle_single TRAINER_JEFFREY_HNS, SageJeffreySeenText, SageJeffreyBeatenText
	msgbox SageJeffreyAfterBattleText, MSGBOX_AUTOCLOSE
	end
EcruteakCity_Gym_EventScript_Ping::
	trainerbattle_single TRAINER_PING_HNS, SagePingSeenText, SagePingBeatenText
	msgbox SagePingAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Martha::
	trainerbattle_single TRAINER_MARTHA_HNS, MediumMarthaSeenText, MediumMarthaBeatenText
	msgbox MediumMarthaAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Grace::
	trainerbattle_single TRAINER_GRACE_HNS, MediumGraceSeenText, MediumGraceBeatenText
	msgbox MediumGraceAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Morty::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_Morty_Defeated
	msgbox MortyIntroText, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MORTY_1_HNS, MortyWinLossText
	message Text_ReceivedFogBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MortyText_FogBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE04_GET
	setflag FLAG_DEFEATED_ECRUTEAK_CITY_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_SHADOW_BALL
	msgbox MortyText_ShadowBallSpeech, MSGBOX_DEFAULT
	setvar VAR_ECRUTEAK_CITY_STATE, 4
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Morty_Defeated::
	msgbox MortyFightDoneText, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_Statue2
	msgbox EcruteakCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Statue2::
	msgbox EcruteakCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_Text_GymStatue:
	.string "PALESTRA POKéMON DI AMARANTOPOLI$"

EcruteakCity_Gym_Text_GymStatueCertified:
	.string "PALESTRA POKéMON DI AMARANTOPOLI\p"
	.string "CERTIFICATI DA ANGELO:\n"
	.string "{PLAYER}$"

MortyIntroText:
	.string "Che bello vederti qui.\p"
	.string "Qui ad AMARANTOPOLI, i POKéMON\n"
	.string "son sempre venerati.\p"
	.string "Si dice che un POKéMON\n"
	.string "arcobaleno apparirà\l"
	.string "a un vero Allenatore.\p"
	.string "Ci ho creduto, e mi sono\n"
	.string "allenato in segreto.\p"
	.string "Perciò ora vedo quello che\n"
	.string "gli altri no.\p"
	.string "Ancora un po'…\p"
	.string "Con un po' di più potrei vedere\n"
	.string "un futuro in cui incontro\l"
	.string "il POKéMON arcobaleno.\p"
	.string "Mi aiuterai a raggiungere\n"
	.string "il livello!$"

MortyWinLossText:
	.string "Non sono ancora forte…\p"
	.string "Va bene. La MEDAGLIA è tua.$"

Text_ReceivedFogBadge:
	.string "{PLAYER} riceve la MEDAGLIA NEBBIA.$"

MortyText_FogBadgeSpeech:
	.string "La MEDAGLIA NEBBIA rende\n"
	.string "obbedienti fino al liv. 50.\p"
	.string "Inoltre, ogni POKéMON che\n"
	.string "conosce SURF potrà usarla\l"
	.string "sempre.\p"
	.string "Voglio darti anche questo.$"

MortyText_ShadowBallSpeech:
	.string "È Palla Ombra.\n"
	.string "Infligge danni e cala\l"
	.string "la DIF. SPEC.\p"
	.string "Usala se ti va.$"

MortyFightDoneText:
	.string "Capisco…\p"
	.string "Il tuo viaggio ti ha portato\n"
	.string "in luoghi remoti.\p"
	.string "Hai visto più cose\n"
	.string "di me.\p"
	.string "Ti invidio per questo…$"

MortyRematchText:
	.string "Ah, CAMPIONE di JOHTO!\n"
	.string "Piacere di vederti.\p"
	.string "Hai mostrato forza e abilità,\n"
	.string "ma hai fatto progressi\l"
	.string "dal duello?\p"
	.string "Da allora mi alleno coi\n"
	.string "POKéMON SPETTRO.\p"
	.string "Vediamo se sai superare\n"
	.string "di nuovo le ombre.\p"
	.string "Vuoi una rivincita?$"

Morty_RematchDefeatText:
	.string "Non sono ancora forte…\p"
	.string "Hai visto più cose\n"
	.string "di me.\p"
	.string "Ti invidio per questo…$"

SageJeffreySeenText:
	.string "Ho passato la primavera coi\n"
	.string "POKéMON.\p"
	.string "Poi estate, autunno e inverno…\p"
	.string "Tornò la primavera.\n"
	.string "Siamo insieme da tanto.$"

SageJeffreyBeatenText:
	.string "Vittorie e sconfitte, le ho\n"
	.string "entrambe.$"

SageJeffreyAfterBattleText:
	.string "Da dove vengono i POKéMON?$"

SagePingSeenText:
	.string "Sai fare danni ai nostri\n"
	.string "POKéMON?$"

SagePingBeatenText:
	.string "Ah! Ben fatto!$"

SagePingAfterBattleText:
	.string "Usiamo POKéMON SPETTRO.\p"
	.string "Nessun attacco NORMALE\n"
	.string "li ferisce!$"

MediumMarthaSeenText:
	.string "Vincerò!$"

MediumMarthaBeatenText:
	.string "Io...ho...perso!$"

MediumMarthaAfterBattleText:
	.string "Chi vuole vincere di più\n"
	.string "alla fine vincerà!$"

MediumGraceSeenText:
	.string "Ti confondono i corridoi?\n"
	.string "Battimi se vuoi un indizio!$"

MediumGraceBeatenText:
	.string "Come?!$"

MediumGraceAfterBattleText:
	.string "Va bene. Ti svelo il segreto\n"
	.string "delle ombre.\p"
	.string "Il sentiero è davanti ai tuoi\n"
	.string "occhi!$"

EcruteakCity_GymGuideText:
	.string "Ehi CAMPIONE! Sei quasi\n"
	.string "a metà strada!\p"
	.string "Qui usano POKéMON di tipo\n"
	.string "SPETTRO e BUIO.\p"
	.string "ANGELO è un esperto di tipo\n"
	.string "SPETTRO, attento al suo cervo\l"
	.string "magico.\p"
	.string "Si dice che causi strani\n"
	.string "incubi…$"

EcruteakCity_GymGuideWinText:
	.string "Uff, {PLAYER}. Bel lavoro!\p"
	.string "Me ne stavo in un angolo\n"
	.string "dal terrore!$"

EcruteakCity_GymClosedText:
	.string "ANGELO, il CAPOPALESTRA, è\n"
	.string "assente.\p"
	.string "Scusa, ma devi uscire\n"
	.string "ora.\p"
	.string "Ohohoho.$"
