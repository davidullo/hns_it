CeruleanCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_EventScript_CityEnter
	.byte 0

CeruleanCity_EventScript_CityEnter::
	setflag FLAG_VISITED_CERULEAN_CITY
	end

CeruleanCity_EventScript_CooltrainerM1::
	goto_if_set FLAG_RETURNED_MACHINE_PART, CeruleanCity_EventScript_CooltrainerMReturnedPart
	msgbox CeruleanCity_Text_CooltrainerM1, MSGBOX_NPC
	end

CeruleanCity_EventScript_CooltrainerMReturnedPart::
	msgbox CeruleanCity_Text_CooltrainerM2, MSGBOX_NPC
	end

CeruleanCity_EventScript_Boy::
	msgbox CeruleanCity_Text_SuperNerd, MSGBOX_NPC
	end

CeruleanCity_EventScript_Guard::
	msgbox CeruleanCity_Text_ThisIsCeruleanCave, MSGBOX_NPC
	end

CeruleanCity_Text_ThisIsCeruleanCave::
    .string "È la GROTTA CERULEAN.\p"
    .string "Dentro vivono POKéMON\n"
    .string "spaventosi.\p"
    .string "Ci vuole un ALLENATORE\n"
    .string "speciale per entrare.\p"
    .string "Devi essere forte abbastanza\n"
    .string "da diventare CAMPIONE della\l"
    .string "LEGA POKéMON KANTO.\p"
    .string "E dovresti anche aver\n"
    .string "fatto grandi imprese.$"

CeruleanCity_Text_CooltrainerM1:
	.string "La CENTRALE di KANTO?\p"
	.string "È vicino alla fine del\n"
	.string "PERCORSO 9, che porta a est.\p"
	.string "Lì credo sia successo\n"
	.string "un incidente.$"

CeruleanCity_Text_CooltrainerM2:
	.string "Stai collezionando ogni\n"
	.string "tipo di POKéMON?\p"
	.string "Sarà una bella sfida,\n"
	.string "ma sembra divertente.$"

CeruleanCity_Text_SuperNerd:
	.string "Il CAPO a nord piace alle\n"
	.string "ragazze: è ottimo per\p"
	.string "appuntamenti!$"

CeruleanCity_EventScript_Slowbro::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SLOWBRO, CRY_MODE_NORMAL
	msgbox CeruleanCity_Text_Slowbro, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeruleanCity_Text_Slowbro:
	.string "SLOWBRO: Yarah?$"

CeruleanCity_EventScript_SlowbroWoman::
	msgbox CeruleanCity_Text_CooltrainerF1, MSGBOX_NPC
	turnobject LOCALID_CERULEAN_CITY_WOMAN, DIR_EAST
	msgbox CeruleanCity_Text_CooltrainerF2, MSGBOX_DEFAULT
	delay 20
	playmoncry SPECIES_SLOWBRO, CRY_MODE_NORMAL
	applymovement2 LOCALID_CERULEAN_CITY_SLOWBRO, Common_Movement_QuestionMark
	turnobject LOCALID_CERULEAN_CITY_SLOWBRO DIR_WEST
	delay 30
	turnobject LOCALID_CERULEAN_CITY_SLOWBRO, DIR_EAST
	delay 30
	turnobject LOCALID_CERULEAN_CITY_SLOWBRO, DIR_SOUTH
	delay 70
	msgbox CeruleanCity_Text_CooltrainerF3, MSGBOX_NPC
	end

CeruleanCity_Text_CooltrainerF1:
	.string "Io e SLOWBRO siamo una\n"
	.string "gran coppia!$"

CeruleanCity_Text_CooltrainerF2:
	.string "SLOWBRO, usa Confusione!$"

CeruleanCity_Text_CooltrainerF3:
	.string "…$"

CeruleanCity_EventScript_Fisher::
	goto_if_eq VAR_CERULEAN_CITY_STATE, 2, CeruleanCity_EventScript_FisherDuringRocket
	msgbox CeruleanCity_Text_Fisher, MSGBOX_NPC
	end

CeruleanCity_EventScript_FisherDuringRocket::
	msgbox CeruleanCity_Text_Fisher_RocketTip, MSGBOX_NPC
	end

CeruleanCity_Text_Fisher:
	.string "Sono un grande fan di\n"
	.string "MISTY.$"

CeruleanCity_Text_Fisher_RocketTip:
	.string "Ho visto un tipo losco andare\n"
	.string "verso il CAPO.$"

CeruleanCity_EventScript_Youngster::
	msgbox CeruleanCity_Text_Youngster1, MSGBOX_NPC
	end

CeruleanCity_Text_Youngster1:
	.string "La grotta a nord è piena\n"
	.string "di POKéMON fortissimi.$"

CeruleanCity_Text_Youngster2:
	.string "Eh?\p"
	.string "Il mio DETECTOR reagisce…$"

CeruleanCity_EventScript_Sign::
	msgbox CeruleanCity_Text_Sign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_GymSign::
	msgbox CeruleanCity_Text_GymSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_BikeShopSign::
	msgbox CeruleanCity_Text_BikeShopSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_PoliceSign::
	msgbox CeruleanCity_Text_PoliceSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_CapeSign::
	msgbox CeruleanCity_Text_CapeSign, MSGBOX_SIGN
	end

CeruleanCity_Text_Sign:
	.string "CELESTOPOLI\p"
	.string "Un'aura blu misteriosa la avvolge$"

CeruleanCity_Text_GymSign:
	.string "CELESTOPOLI\n"
	.string "PALESTRA\n"
	.string "CAPO: MISTY\p"
	.string "Sirena Maschiaccio$"

CeruleanCity_Text_BikeShopSign:
	.string "C'è un avviso qui…\p"
	.string "Il negozio di BICICLETTE\n"
	.string "è a FIORDOROPOLI…$"

CeruleanCity_Text_PoliceSign:
	.string "C'è un avviso qui…\p"
	.string "Fermiamo i ladri e rendiamo\n"
	.string "la città più amichevole e\l"
	.string "lieta!\p"
	.string "POLIZIA LOCALE$"

CeruleanCity_Text_CapeSign:
	.string "CAPO CERULEAN\n"
	.string "AVANTI$"

CeruleanCity_Text_LockedDoor:
	.string "È chiuso…$"

