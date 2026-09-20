VioletCity_Gym_hns_MapScripts::
	.byte 0

VioletCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_GymGuy2
	msgbox VioletGym_Text_GymGuide_Intro, MSGBOX_DEFAULT
	closemessage
	release
	end
	
VioletCity_Gym_EventScript_GymGuy2::
	msgbox VioletGym_Text_GymGuide_Win, MSGBOX_DEFAULT
	release
	end	

VioletCity_Gym_EventScript_Rod::
	trainerbattle_single TRAINER_ROD_HNS, VioletGym_Text_BirdKeeperRod_Seen, VioletGym_Text_BirdKeeperRod_Beaten
	msgbox VioletGym_Text_BirdKeeperRod_After, MSGBOX_AUTOCLOSE
	end

VioletCity_Gym_EventScript_Abe::
	trainerbattle_single TRAINER_ABE_HNS, VioletGym_Text_BirdKeeperAbe_Seen, VioletGym_Text_BirdKeeperAbe_Beaten
	msgbox VioletGym_Text_BirdKeeperAbe_After, MSGBOX_AUTOCLOSE
	end

VioletCity_Gym_EventScript_Falkner::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_Falkner_Defeated
	msgbox VioletGym_Text_Falkner_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_FALKNER_1_HNS, VioletGym_Text_Falkner_WinLoss
	message VioletGym_Text_ReceivedZephyrBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox VioletGym_Text_Falkner_BadgeExplain, MSGBOX_DEFAULT
	setflag FLAG_BADGE01_GET
	setflag FLAG_DEFEATED_VIOLET_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_ROOST
	msgbox VioletGym_Text_Falkner_TMExplain, MSGBOX_DEFAULT
	setvar VAR_VIOLET_CITY_STATE, 3
	setrespawn HEAL_LOCATION_VIOLET_CITY_HNS
	closemessage
	release
	end

VioletCity_Gym_EventScript_Falkner_Defeated::
	msgbox VioletGym_Text_Falkner_AfterFight, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletGym_Text_Falkner_Intro:
	.string "Sono FALKNER, il capo della\n"
	.string "PALESTRA di VIOLET!\p"
	.string "Dicono che basti una scarica\n"
	.string "elettrica per tarpare le ali\p"
	.string "ai POKéMON di tipo VOLANTE…\n"
	.string "Non permetterò simili insulti ai\l"
	.string "POKéMON uccello!\p"
	.string "Ti mostrerò la vera forza\n"
	.string "dei magnifici POKéMON uccello!$"

VioletGym_Text_Falkner_WinLoss:
	.string "…Accidenti! I POKéMON uccello\n"
	.string "cari a mio padre…\p"
	.string "Va bene. Prendi questo.\p"
	.string "È la ZEPHYRBADGE ufficiale\n"
	.string "della LEGA POKéMON.$"

VioletGym_Text_ReceivedZephyrBadge:
	.string "{PLAYER} riceve la ZEPHYRBADGE.$"

VioletGym_Text_Falkner_BadgeExplain:
	.string "La ZEPHYRBADGE aumenta la POTENZA\n"
	.string "d'attacco dei POKéMON.\p"
	.string "Permette anche ai POKéMON di usare\n"
	.string "BALENO, se possono impararla,\l"
	.string "in qualsiasi momento.\p"
	.string "Tieni, prendi anche questo.$"

VioletGym_Text_Falkner_TMExplain:
	.string "Usando una MT, un POKéMON impara\n"
	.string "subito una nuova mossa.\p"
	.string "Questa MT contiene TRESPOLO.\p"
	.string "Recupera PS fino a metà dei PS\n"
	.string "massimi del tuo POKéMON.\p"
	.string "In altre parole, cura il tuo\n"
	.string "POKéMON.$"

VioletGym_Text_Falkner_AfterFight:
	.string "Ci sono PALESTRE POKéMON nelle città\n"
	.string "e nei paesi più avanti.\p"
	.string "Dovresti mettere alla prova le tue\n"
	.string "capacità in queste PALESTRE.\p"
	.string "Mi allenerò di più per diventare\n"
	.string "il più grande maestro di uccelli!$"

VioletGym_Text_Falkner_Rematch:
	.string "Congratulazioni per aver battuto\n"
	.string "l'ELITE 4!\p"
	.string "Ho allenato i miei POKéMON\n"
	.string "di tipo VOLANTE ancora di più.\p"
	.string "Pensi di reggere di nuovo\n"
	.string "la forza dei cieli?$"

VioletGym_Text_Falkner_RematchLoss:
	.string "Wow… Mi hai battuto di nuovo.\p"
	.string "Mi allenerò di più per\n"
	.string "diventare il più grande Uccello!$"

VioletGym_Text_BirdKeeperRod_Seen:
	.string "La parola d'ordine è fegato!\p"
	.string "Qui ci si allena giorno e notte\n"
	.string "per diventare maestri di POKéMON uccello.\p"
	.string "Forza!$"

VioletGym_Text_BirdKeeperRod_Beaten:
	.string "Aaah!$"

VioletGym_Text_BirdKeeperRod_After:
	.string "FALKNER è davvero forte!\p"
	.string "Non montarti la testa\n"
	.string "solo perché mi hai battuto!$"

VioletGym_Text_BirdKeeperAbe_Seen:
	.string "Vediamo se sei forte\n"
	.string "abbastanza per FALKNER!$"

VioletGym_Text_BirdKeeperAbe_Beaten:
	.string "Non è possibile!$"

VioletGym_Text_BirdKeeperAbe_After:
	.string "Che pena, perdere contro una\n"
	.string "recluta…$"

VioletGym_Text_GymGuide_Intro:
	.string "Ehi! Come va? Non sono un allenatore,\n"
	.string "ma posso darti qualche consiglio!\p"
	.string "Credimi! Se credi in te, il sogno\n"
	.string "di diventare campione si avvera.\p"
	.string "Ci credi? Allora ascolta.\p"
	.string "Il pezzo forte di FALKNER è un grosso\n"
	.string "gufo che adora mangiare le BACche.\p"
	.string "Non è il più forte,\n"
	.string "ma incassa molti colpi.\p"
	.string "Puoi colpirlo con mosse Elettro\n"
	.string "e Roccia, ma attento a\l"
	.string "FANGOSBERLA!\p"
	.string "Se vuoi altro aiuto, vai all'\n"
	.string "ACCADEMIA POKéMON.\p"
	.string "Gli studenti lì ne sanno\n"
	.string "davvero parecchio!$"

VioletGym_Text_GymGuide_Win:
	.string "Bella lotta! Continua così\n"
	.string "e diventerai CAMPIONE in un\l"
	.string "battibaleno!$"

VioletCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_Statue2
	msgbox VioletCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Gym_EventScript_Statue2::
	msgbox VioletCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Gym_Text_GymStatue:
	.string "PALESTRA POKéMON DI VIOLET$"

VioletCity_Gym_Text_GymStatueCertified:
	.string "PALESTRA POKéMON DI VIOLET\p"
	.string "ALLENATORI CERTIFICATI DA FALKNER:\n"
	.string "{PLAYER}$"
