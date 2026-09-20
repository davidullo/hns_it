ViridianCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_EventScript_CityEnter
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ViridianCity_OnFrame
	.byte 0

ViridianCity_EventScript_CityEnter::
	setflag FLAG_VISITED_VIRIDIAN_CITY
	end

ViridianCity_OnFrame::
	map_script_2 VAR_OAK_MT_SILVER_CALL, 1, ViridianCity_EventScript_OakCall
	.2byte 0

ViridianCity_EventScript_OakCall::
	lock
	setspeaker ViridianCity_Text_OakName
	pokenavcall ViridianCity_Text_OakCall
	waitmessage
	delay 30
	setvar VAR_OAK_MT_SILVER_CALL, 2
	release
	end

ViridianCity_Text_OakName:
	.string "OAK$"

ViridianCity_Text_OakCall:
	.string "OAK: Ah, {PLAYER}!\p"
	.string "Vieni a trovarmi al\n"
	.string "LAB a BIANCAVILLA\l"
	.string "quando puoi.$"

ViridianCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox ViridianCity_Text_CoffeeGramps_Question, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, ViridianCity_EventScript_GrampsDoubted
	msgbox ViridianCity_Text_CoffeeGramps_Believed, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_EventScript_GrampsDoubted::
	msgbox ViridianCity_Text_CoffeeGramps_Doubted, MSGBOX_DEFAULT
	closemessage
	release
	end

VirianCity_EventScript_GymGramps::
	goto_if_set FLAG_HIDE_CINNABAR_BLUE, VirianCity_EventScript_GymGrampsBlue
	msgbox ViridianCity_Text_GrampsNearGym, MSGBOX_NPC
	end

VirianCity_EventScript_GymGrampsBlue::
	msgbox ViridianCity_Text_GrampsNearGym_BlueReturned, MSGBOX_NPC
	end

ViridianCity_EventScript_Fisher::
	goto_if_set FLAG_GOT_VIRIDIAN_TM_DREAM_EATER, ViridianCity_EventScript_FisherAfter
	msgbox ViridianCity_Text_DreamEaterFisher, MSGBOX_NPC
	giveitem ITEM_TM_DREAM_EATER
	setflag FLAG_GOT_VIRIDIAN_TM_DREAM_EATER
	end

ViridianCity_EventScript_FisherAfter::
	msgbox ViridianCity_Text_DreamEaterFisher_GotTM, MSGBOX_NPC
	end

ViridianCity_EventScript_Youngster::
	msgbox ViridianCity_Text_Youngster, MSGBOX_NPC
	end

ViridianCity_EventScript_CitySign::
	msgbox ViridianCity_Text_WelcomeSign, MSGBOX_SIGN
	end

ViridianCity_EventScript_CitySign2::
	msgbox ViridianCity_Text_Sign, MSGBOX_SIGN
	end

ViridianCity_EventScript_GymSign::
	msgbox ViridianCity_Text_GymSign, MSGBOX_SIGN
	end

ViridianCity_Text_CoffeeGramps_Question:
	.string "Ehi, ragazzo! Ho bevuto un doppio\n"
	.string "espresso e sono carichissimo!\p"
	.string "Devo parlare con qualcuno, quindi\n"
	.string "tocca a te!\p"
	.string "Ora non sembro granché, ma ero un\n"
	.string "esperto di cattura POKéMON.\p"
	.string "Mi credi?$"

ViridianCity_Text_CoffeeGramps_Believed:
	.string "Bene, bene. Sì, ero un tipo\n"
	.string "fuori dal comune, te lo\l"
	.string "assicuro!$"

ViridianCity_Text_CoffeeGramps_Doubted:
	.string "Cosa? Ragazzino insolente!\p"
	.string "Se fossi un po' più giovane, ti\n"
	.string "farei vedere io. Umpf!$"

ViridianCity_Text_GrampsNearGym:
	.string "Questa PALESTRA non aveva un CAPO\n"
	.string "fino a poco tempo fa.\p"
	.string "Un giovane di PALLET è diventato\n"
	.string "CAPO, ma è spesso via.$"

ViridianCity_Text_GrampsNearGym_BlueReturned:
	.string "Sfiderai il\n"
	.string "CAPO?\p"
	.string "Buona fortuna. Ti servirà.$"

ViridianCity_Text_DreamEaterFisherNew:
	.string "…Zzzzz…\p" 
	.string "Yawn!\p"
	.string "Devo essermi appisolato al sole.\p"
	.string "Cosa? Ti ricordo qualcuno?\p"
	.string "Non so, tieni, prendi questo.$"


ViridianCity_Text_DreamEaterFisher_GotTM::
	.string "…Zzzzz…$"

ViridianCity_Text_DreamEaterFisher:
	.string "Yawn!\p"
	.string "Devo essermi appisolato al sole.\p"
	.string "…Ho sognato un DROWZEE che si\n"
	.string "mangiava il mio sogno. Strano, eh?\p"
	.string "Eh? Che cos'è questo?\p"
	.string "Da dove salta fuori questa MT?\p"
	.string "Che brivido! Tieni, è tua\n"
	.string "questa MT.$"

ViridianCity_Text_DreamEaterFisher_GotDreamEater:
	.string "La MT42 contiene MANGIASOGNI…\p"
	.string "…Zzzzz…$"

ViridianCity_Text_Youngster:
	.string "Ho sentito che ci sono molti\n"
	.string "strumenti a terra nella FORESTA.$"

ViridianCity_Text_Sign:
	.string "SMERALDOPOLI\p"
	.string "Il paradiso sempre verde$"

ViridianCity_Text_GymSign:
	.string "PALESTRA POKéMON di SMERALDOPOLI\n"
	.string "CAPO: …\p"
	.string "Il resto del testo è illeggibile…$"

ViridianCity_Text_WelcomeSign:
	.string "BENVENUTI A SMERALDOPOLI,\p"
	.string "LA PORTA DELL'ALTIPIANO INDIGO$"

ViridianCity_Text_TrainerHouseSign:
	.string "CASA ALLENATORI\p"
	.string "Il club delle lotte migliori$"
