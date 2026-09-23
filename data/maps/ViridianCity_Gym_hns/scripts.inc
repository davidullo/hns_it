ViridianCity_Gym_hns_MapScripts::
	.byte 0

ViridianCity_Gym_EventScript_Blue::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_DOJO_BLUE, ViridianCity_Gym_EventScript_BlueAtDojo
	goto_if_set FLAG_DEFEATED_VIRIDIAN_GYM, ViridianCity_Gym_EventScript_BlueGotoDojo
	goto_if_set FLAG_DEFEATED_VIRIDIAN_GYM, ViridianCity_Gym_EventScript_Blue_Defeated
	msgbox ViridianCity_Gym_Text_LeaderBlue_Before, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BLUE_HNS, ViridianCity_Gym_Text_LeaderBlue_Win
	message ViridianCity_Gym_Text_ReceivedEarthBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox ViridianCity_Gym_Text_LeaderBlue_After, MSGBOX_DEFAULT
	msgbox ViridianCity_Gym_Text_LeaderBlue_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_TRICK_ROOM
	msgbox ViridianCity_Gym_Text_LeaderBlue_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE16_GET
	setflag FLAG_DEFEATED_VIRIDIAN_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 16
	call Common_EventScript_SetGymTrainers_hns
	closemessage
	setflag FLAG_HIDE_LEAGUE_BLACKBELT
	setflag FLAG_HIDE_SEAFOAM_BLAINE
	clearflag FLAG_HIDE_CINNABAR_BLAINE
	setvar VAR_OAK_MT_SILVER_CALL, 1
	release
	end

ViridianCity_Gym_EventScript_Blue_Defeated::
	msgbox ViridianCity_Gym_Text_LeaderBlue_Epilogue, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_Gym_EventScript_BlueGotoDojo::
	msgbox ViridianCity_Gym_Text_BlueGotoDojo, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_DOJO_BLUE
	release
	end

ViridianCity_Gym_Text_BlueGotoDojo:
	.string "BLU: Già di ritorno?\p"
	.string "Se vuoi un'altra sfida,\n"
	.string "vieni al DOJO LOTTA!$"

ViridianCity_Gym_EventScript_BlueAtDojo::
	msgbox ViridianCity_Gym_Text_LeaderBlue_Epilogue, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_Gym_Text_LeaderBlue_Before:
	.string "BLU: Ehi! Finalmente sei qui?\p"
	.string "All'ISOLA CANNELLA non ne\navevo voglia,\p"
	.string "ma ora sono pronto a lottare.\p"
	.string "…\p"
	.string "Dici di aver conquistato tutte\n"
	.string "le PALESTRE di JOHTO?\p"
	.string "Eh! Allora le PALESTRE di JOHTO\n"
	.string "devono fare proprio pena.\p"
	.string "Ehi, non preoccuparti.\p"
	.string "Scoprirò se vali o no\n"
	.string "lottando con te adesso.\p"
	.string "Pronto, CAMPIONE di JOHTO?$"

ViridianCity_Gym_Text_LeaderBlue_Win:
	.string "BLU: Cosa?\p"
	.string "Come ho fatto a perdere?\p"
	.string "…\p"
	.string "Tch, va bene… Tieni, prendi--è la\n"
	.string "TERRABADGE.$"

ViridianCity_Gym_Text_ReceivedEarthBadge:
	.string "{PLAYER} riceve la TERRABADGE.$"

ViridianCity_Gym_Text_LeaderBlue_After:
	.string "BLU: …\p"
	.string "Va bene, mi sbagliavo. Sei forte\n"
	.string "davvero. Sei un bravo allenatore.\p"
	.string "Ma un giorno ti batterò.\p"
	.string "Non dimenticarlo!$"

ViridianCity_Gym_Text_LeaderBlue_GiveTM:
	.string "Prendi questo.$"

ViridianCity_Gym_Text_LeaderBlue_ExplainTM:
	.string "Questa è TRICK ROOM.\p"
	.string "I POKéMON in lotta cambiano velocità.\n"
	.string "I lenti vanno prima. I veloci dopo.\p"
	.string "Usala per ribaltare la lotta.$"

ViridianCity_Gym_Text_LeaderBlue_Epilogue:
	.string "BLU: Ascoltami.\p"
	.string "Non perdere finché non ti batto\n"
	.string "io. Chiaro?$"


ViridianCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_VIRIDIAN_GYM, ViridianCity_Gym_EventScript_GymGuyAfter
	msgbox ViridianCity_Gym_Text_Guide, MSGBOX_NPC
	end

ViridianCity_Gym_EventScript_GymGuyAfter::
	msgbox ViridianCity_Gym_Text_Guide_Win, MSGBOX_NPC
	end

ViridianCity_Gym_Text_Guide:
	.string "Ehi, CAMPIONE in erba!\p"
	.string "Come va? Sembra che tu sia in\n"
	.string "gran forma.\p"
	.string "Il CAPO della PALESTRA ha sfidato\n"
	.string "il CAMPIONE tre anni fa.\p"
	.string "Non è uno sprovveduto.\p"
	.string "Dagli il massimo!$"

ViridianCity_Gym_Text_Guide_Win:
	.string "Caspita, sei davvero forte…\p"
	.string "Che battaglia emozionante.\n"
	.string "Mi hai fatto commuovere.$"


ViridianCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE16_GET, ViridianCity_Gym_EventScript_GymStatuePostVictory
	msgbox ViridianCity_Gym_Text_GymStatue
	releaseall
	end

ViridianCity_Gym_EventScript_GymStatuePostVictory::
	msgbox ViridianCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

ViridianCity_Gym_Text_GymStatue::
    .string "PALESTRA POKéMON DI SMERALDOPOLI\n"
    .string "CAPO: BLU\p"
	.string "ALLENATORI VINCENTI:\n"
	.string "BLU, ROSSO$"

ViridianCity_Gym_Text_GymStatuePlayerWon::
    .string "PALESTRA POKéMON DI SMERALDOPOLI\n"
    .string "CAPO: BLU\p"
    .string "ALLENATORI VINCENTI:\n"
	.string "BLU, ROSSO, {PLAYER}$"

