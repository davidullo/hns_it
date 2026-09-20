MtMortar_B1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMortar_B1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtMortar_B1F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

MtMortar_B1F_EventScript_Item_HyperPotion::
    finditem ITEM_HYPER_POTION
    end

MtMortar_B1F_EventScript_Item_Carbos::
    finditem ITEM_CARBOS
    end

MtMortar_B1F_EventScript_Item_PPUp::
    finditem ITEM_PP_UP
    end

MtMortar_B1F_EventScript_Item_MaxEther::
    finditem ITEM_MAX_ETHER
    end

MtMortar_B1F_EventScript_Item_MaxRevive::
    finditem ITEM_MAX_REVIVE
    end

MountMortar4_EventScript_Kiyo::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TYROGUE, MountMortar4_EventScript_KiyoAfter
	goto_if_set FLAG_BEAT_KIYO, MountMortar4_EventScript_KiyoTryGiveTyrogue
	msgbox MountMortar4_Text_KiyoIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KIYO_HNS, MountMortar4_Text_KiyoWin
	setflag FLAG_BEAT_KIYO
MountMortar4_EventScript_KiyoTryGiveTyrogue::
	msgbox MountMortar4_Text_KiyoTyrogueReward, MSGBOX_DEFAULT
	@HnS gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TYROGUE
	bufferspeciesname STR_VAR_1, SPECIES_TYROGUE
	givemon SPECIES_TYROGUE, 25
	call Common_EventScript_GiftMon
	setflag FLAG_GOT_TYROGUE
MountMortar4_EventScript_KiyoAfter::
	msgbox MountMortar4_Text_KiyoGotTyrogue, MSGBOX_DEFAULT
	closemessage
	release
	end


MountMortar4_Text_KiyoIntro:
	.string "Ehi!\p"
	.string "Sono il RE DEL KARATE!\n"
	.string "Mi alleno da solo qui al buio!\p"
	.string "Tu! Lotta con me!\n"
	.string "Hwaaarggh!$"

MountMortar4_Text_KiyoWin:
	.string "Waaaarggh!\n"
	.string "Sono battuto!$"

MountMortar4_Text_KiyoTyrogueReward:
	.string "Io... sono distrutto...\p"
	.string "Il mio allenamento non\n"
	.string "basta ancora...\p"
	.string "Ma una sconfitta è una sconfitta.\n"
	.string "Lo ammetto.\p"
	.string "Come prova che mi hai battuto,\n"
	.string "ti darò un raro POKéMON\l"
	.string "di tipo lotta.$"

MountMortar4_Text_ReceiveTyrogue:
	.string "{PLAYER} ha ricevuto TYROGUE.$"

MountMortar4_Text_KiyoGotTyrogue:
	.string "TYROGUE è di tipo LOTTA.\p"
	.string "Si evolve in un POKéMON\n"
	.string "più forte.\p"
	.string "Continua a impegnarti.\n"
	.string "Anch'io continuerò ad allenarmi.\p"
	.string "Addio!$"

MountMortar4_Text_KiyoFullParty:
	.string "Non hai spazio nella squadra!$"
