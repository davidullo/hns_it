CianwoodGym_hns_MapScripts::
	.byte 0


CianwoodGym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, CianwoodGym_EventScript_Statue2
	msgbox CianwoodGym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_EventScript_Statue2::
	msgbox CianwoodGym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_Text_GymStatue:
	.string "PALESTRA POKéMON DI FIORLISOPOLI$"

CianwoodGym_Text_GymStatueCertified:
	.string "PALESTRA POKéMON DI FIORLISOPOLI\p"
	.string "CERTIFICATI DA FURIO:\n"
	.string "{PLAYER}$"

CianwoodGym_EventScript_Chuck::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_DOJO_CHUCK, CianwoodGym_EventScript_ChuckAtDojo
	goto_if_set FLAG_VISITED_VERMILION_CITY, CianwoodGym_EventScript_ChuckGotoDojo
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, CianwoodGym_EventScript_Chuck_Defeated
	msgbox CianwoodGym_Text_ChuckIntro1, MSGBOX_DEFAULT
	applymovement LOCALID_CIANWOOD_CHUCK, CianwoodGym_Movement_ChuckLeft
	waitmovement 0
	message CianwoodGym_Text_ChuckIntro2
	applymovement LOCALID_CIANWOOD_CHUCK_ROCK_LEFT, Movement_SmashRock
	playse SE_M_ROCK_THROW
	waitmovement 0

	delay 20

	applymovement LOCALID_CIANWOOD_CHUCK, CianwoodGym_Movement_ChuckRight
	waitmovement 0
	applymovement LOCALID_CIANWOOD_CHUCK_ROCK_RIGHT, Movement_SmashRock
	playse SE_M_ROCK_THROW
	waitmovement 0
	waitmessage
	turnobject LOCALID_CIANWOOD_CHUCK, DIR_SOUTH
	msgbox CianwoodGym_Text_ChuckIntro3, MSGBOX_DEFAULT
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, CianwoodGym_EventScript_OlivineCheckMahog
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, CianwoodGym_EventScript_MahogCheckOlivine
	goto CianwoodGym_EventScript_Chuck_Battle1

CianwoodGym_EventScript_ChuckVictory::
	message CianwoodGym_Text_GetStormBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox CianwoodGym_Text_ChuckBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE05_GET
	setflag FLAG_DEFEATED_CIANWOOD_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 5
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_FOCUS_PUNCH
	msgbox CianwoodGym_Text_ChuckTMSpeech, MSGBOX_DEFAULT
	setvar VAR_GETFLY, 1
	setrespawn HEAL_LOCATION_CIANWOOD_CITY_HNS
    call_if_eq VAR_NUM_BADGES, 7, MahoganyTown_Gym_EventScript_SetupElmRocketCall
	closemessage
	release
	end

CianwoodGym_EventScript_ChuckGotoDojo::
	msgbox CianwoodGym_Text_ChuckGotoDojo, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_DOJO_CHUCK
	release
	end

CianwoodGym_Text_ChuckGotoDojo:
	.string "WAHAHAHA {PLAYER}!\n"
	.string "Sono in mezzo all'allenamento!\p"
	.string "Se vuoi un'altra sfida, vieni\n"
	.string "al DOJO DI LOTTA di ZAFFRONA!$"	

CianwoodGym_EventScript_ChuckAtDojo::
	msgbox CianwoodGym_Text_ChuckAtDojo, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_Text_ChuckAtDojo:
	.string "Ci vediamo al DOJO!\n"
	.string "WAHAHAHAHAHA$"

CianwoodGym_EventScript_OlivineCheckMahog::
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, CianwoodGym_EventScript_Chuck_Battle3
	goto CianwoodGym_EventScript_Chuck_Battle2

CianwoodGym_EventScript_MahogCheckOlivine::
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, CianwoodGym_EventScript_Chuck_Battle3
	goto CianwoodGym_EventScript_Chuck_Battle2
	
CianwoodGym_EventScript_Chuck_Battle1::
	trainerbattle_no_intro TRAINER_CHUCK_1_HNS, CianwoodGym_Text_ChuckIntro2
	goto CianwoodGym_EventScript_ChuckVictory

CianwoodGym_EventScript_Chuck_Battle2::
	trainerbattle_no_intro TRAINER_CHUCK_1_2_HNS, CianwoodGym_Text_ChuckIntro2
	goto CianwoodGym_EventScript_ChuckVictory

CianwoodGym_EventScript_Chuck_Battle3::
	trainerbattle_no_intro TRAINER_CHUCK_1_3_HNS, CianwoodGym_Text_ChuckIntro2
	goto CianwoodGym_EventScript_ChuckVictory

CianwoodGym_EventScript_Chuck_Defeated::
	msgbox CianwoodGym_Text_ChuckAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_Movement_ChuckLeft:
	jump_in_place_left
	step_end

CianwoodGym_Movement_ChuckRight:
	jump_in_place_right
	step_end

CianwoodGym_Text_ChuckIntro1:
	.string "WAHAHAH!\p"
	.string "Sei arrivato fin qui!\p"
	.string "Sappi che sono tosto!\p"
	.string "I miei POKéMON spaccano pietre\n"
	.string "e ossa!\p"
	.string "Guarda qua!$"

CianwoodGym_Text_ChuckIntro2:
	.string "FURIO: Urggh!\n"
	.string "…\p"
	.string "Oooarrgh!$"

CianwoodGym_Text_ChuckIntro3:
	.string "Ecco! Hai paura, vero?\p"
	.string "Come? Non c'entra nulla con i\n"
	.string "POKéMON?\p"
	.string "È vero!\p"
	.string "Dai, combattiamo!$"

CianwoodGym_Text_ChuckLoss:
	.string "Cosa? Ho perso?\p"
	.string "Ma pensa!\n"
	.string "Meriti la MEDAGLIA TEMPESTA!$"

CianwoodGym_Text_GetStormBadge:
	.string "{PLAYER} riceve MEDAGLIA TEMPESTA.$"

CianwoodGym_Text_ChuckBadgeSpeech:
	.string "La MEDAGLIA TEMPESTA fa obbedire\n"
	.string "i POKéMON fino al L70.\p"
	.string "Anche quelli scambiati. Fuori\n"
	.string "dalla lotta usi VOLO.\p"
	.string "Tieni, prendi!$"

CianwoodGym_Text_ChuckTMSpeech:
	.string "È il CENTRIPUGNO.\p"
	.string "Lento ma con danni enormi.\n"
	.string "Basta non farti colpire prima!$"

CianwoodGym_Text_ChuckAfter:
	.string "WAHAHAH! Mi sono divertito!\p"
	.string "Ma perder è perdere!\p"
	.string "D'ora in poi mi allenerò\n"
	.string "24 ore al giorno!$"

CianwoodGym_Text_ChuckRematch:
	.string "WAHAHAH! CAMPIONE JOHTO!\p"
	.string "Sei tornato per il bis!\p"
	.string "Vedo che sei migliorato!\p"
	.string "Vediamo chi è più forte?$"

CianwoodGym_Text_ChuckRematchDefeat:
	.string "Cosa? Ho perso?\n"
	.string "Ancora?$"

CianwoodGym_EventScript_Yoshi::
	trainerbattle_single TRAINER_YOSHI_HNS, CianwoodGym_Text_BlackbeltYoshiSeen, CianwoodGym_Text_BlackbeltYoshiBeaten
	msgbox CianwoodGym_Text_BlackbeltYoshiAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltYoshiSeen:
	.string "Io e il mio POKéMON siamo uniti\n"
	.string "dall'amicizia.\p"
	.string "Il nostro legame è eterno!$"

CianwoodGym_Text_BlackbeltYoshiBeaten:
	.string "Non è vero!$"

CianwoodGym_Text_BlackbeltYoshiAfter:
	.string "Sembri avere un forte legame\n"
	.string "anche coi tuoi POKéMON!$"

CianwoodGym_EventScript_Lao::
	trainerbattle_single TRAINER_LAO_HNS, CianwoodGym_Text_BlackbeltLaoSeen, CianwoodGym_Text_BlackbeltLaoBeaten
	msgbox CianwoodGym_Text_BlackbeltLaoAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltLaoSeen:
	.string "Noi lottatori non temiamo nulla!$"

CianwoodGym_Text_BlackbeltLaoBeaten:
	.string "Che shock!$"

CianwoodGym_Text_BlackbeltLaoAfter:
	.string "I POKéMON di Lotta temono\n"
	.string "i Psico…$"


CianwoodGym_EventScript_Nob::
	trainerbattle_single TRAINER_NOB_HNS, CianwoodGym_Text_BlackbeltNobSeen, CianwoodGym_Text_BlackbeltNobBeaten
	msgbox CianwoodGym_Text_BlackbeltNobAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltNobSeen:
	.string "Non servono parole.\n"
	.string "Fai parlare i pugni!$"

CianwoodGym_Text_BlackbeltNobBeaten:
	.string "…$"

CianwoodGym_Text_BlackbeltNobAfter:
	.string "Ho perso! Non ho parole!$"

CianwoodGym_EventScript_Lung::
	trainerbattle_single TRAINER_LUNG_HNS, CianwoodGym_Text_BlackbeltLungSeen, CianwoodGym_Text_BlackbeltLungBeaten
	msgbox CianwoodGym_Text_BlackbeltLungAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltLungSeen:
	.string "I miei pugni furiosi spaccano\n"
	.string "i POKéMON!$"

CianwoodGym_Text_BlackbeltLungBeaten:
	.string "Sono a pezzi!$"

CianwoodGym_Text_BlackbeltLungAfter:
	.string "Il mio POKéMON ha perso…\n"
	.string "Il mio orgoglio è a pezzi…$"

