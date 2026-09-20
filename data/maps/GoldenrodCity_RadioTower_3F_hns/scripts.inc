GoldenrodCity_RadioTower_3F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_RadioTower_3F_OnLoad
	.byte 0

GoldenrodCity_RadioTower_3F_OnLoad::
	call_if_set FLAG_HIDE_RADIOTOWER_GATE, GoldenrodCity_RadioTower_3F_HideGate
	end
	
GoldenrodCity_RadioTower_3F_HideGate::
	setmetatile 25, 8, 0x335, FALSE
	setmetatile 25, 9, 0x335, FALSE

	setmetatile 26, 8, 0X334, FALSE
	setmetatile 26, 9, 0X334, FALSE

	setmetatile 27, 8, 0X334, FALSE
	setmetatile 27, 9, 0X334, FALSE

	setmetatile 28, 8, 0X334, FALSE
	setmetatile 28, 9, 0X334, FALSE

	setmetatile 29, 8, 0X334, FALSE
	setmetatile 29, 9, 0X334, FALSE

	setmetatile 30, 8, 0X334, FALSE
	setmetatile 30, 9, 0X334, FALSE

	setmetatile 31, 8, 0X334, FALSE
	setmetatile 31, 9, 0X334, FALSE
	return


GoldenrodRaidoTower3_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_6_HNS, GoldenrodCity_RadioTower_3F_Text_GruntM7Seen, GoldenrodCity_RadioTower_3F_Text_GruntM7Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM7After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_7_HNS, GoldenrodCity_RadioTower_3F_Text_GruntM8Seen, GoldenrodCity_RadioTower_3F_Text_GruntM8Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM8After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_8_HNS, GoldenrodCity_RadioTower_3F_Text_GruntM9Seen, GoldenrodCity_RadioTower_3F_Text_GruntM9Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM9After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Scientist::
	trainerbattle_single TRAINER_MARC_HNS, GoldenrodCity_RadioTower_3F_Text_ScientistMarcSeen, GoldenrodCity_RadioTower_3F_Text_ScientistMarcBeaten
	msgbox GoldenrodCity_RadioTower_3F_Text_ScientistMarcAfter, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SUNNY_DAY, GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer3
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 10, GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer2

	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFPleaseSave, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer2::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFHeroGift, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_TM_SUNNY_DAY
	setflag FLAG_GOT_SUNNY_DAY
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFSunnyDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer3::
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFMarvelous, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Nerd::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_3F_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Gate::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_CardKeySlot, MSGBOX_SIGN
	goto_if_set FLAG_HIDE_RADIOTOWER_GATE, GoldenrodCity_RadioTower_3F_EventScript_GateOpened
	checkitem ITEM_CARD_KEY
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_RadioTower_3F_EventScript_OpenGate
	closemessage
	release
	end


GoldenrodCity_RadioTower_3F_EventScript_GateOpened::
	msgbox GoldenrodCity_RadioTower_3F_Text_Open, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_OpenGate::
	msgbox GoldenrodCity_RadioTower_3F_Text_InsertedCardKey, MSGBOX_SIGN
	call GoldenrodCity_RadioTower_3F_HideGate
	playse SE_CLICK
	special DrawWholeMapView
	msgbox GoldenrodCity_RadioTower_3F_Text_Open, MSGBOX_SIGN
	setflag FLAG_HIDE_RADIOTOWER_GATE
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Sign1::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_PersonnelSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Sign2::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_PokemonMusicSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_Text_CardKeySlot:
	.string "È la fessura della CARD KEY.$"

GoldenrodCity_RadioTower_3F_Text_InsertedCardKey:
	.string "{PLAYER} ha inserito la CARD KEY.$"
 
GoldenrodCity_RadioTower_3F_Text_Open:
	.string "Il cancello è aperto.$"

GoldenrodCity_RadioTower_3F_Text_PersonnelSign:
	.string "PERSONALE 3P$"

GoldenrodCity_RadioTower_3F_Text_PokemonMusicSign:
	.string "MUSICA POKéMON con DJ BEN$"

GoldenrodCity_RadioTower_3F_Text_SuperNerd:
	.string "Abbiamo le registrazioni dei versi\n"
	.string "di tutti i POKéMON che sono\l"
	.string "stati trovati.\p"
	.string "Saranno circa 400 specie.$"

GoldenrodCity_RadioTower_3F_Text_GymGuideRockets:
	.string "Per gli allenatori i POKéMON sono\n"
	.string "amati compagni.\p"
	.string "È orribile che il TEAM ROCKET\n"
	.string "voglia controllarli.$"

GoldenrodCity_RadioTower_3F_Text_GymGuide:
	.string "Trasmettiamo 24 ore al giorno\n"
	.string "programmi divertenti.\p"
	.string "Anch'io farò del mio meglio\n"
	.string "giorno e notte!$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFPleaseSave:
	.string "Il capo del TEAM ROCKET si è\n"
	.string "chiuso dentro.\p"
	.string "Ma il DIRETTORE può aprirla.\p"
	.string "È al quinto piano.\p"
	.string "Salvalo, ti prego!$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFDirectorSafe:
	.string "Il DIRETTORE sta bene?$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFHeroGift:
	.string "Grazie! Sei il mio eroe!\p"
	.string "Un segno della mia gratitudine.$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFSunnyDay:
	.string "È GIORNO DI SOLE.\p"
	.string "Potenzia le mosse di tipo\n"
	.string "Fuoco per un po'.$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFMarvelous:
	.string "Sei stato semplicemente magnifico!$"

GoldenrodCity_RadioTower_3F_Text_GruntM7Seen:
	.string "Ho ordini severi.\p"
	.string "Devo schiacciare chi sfida\n"
	.string "il TEAM ROCKET!$"

GoldenrodCity_RadioTower_3F_Text_GruntM7Beaten:
	.string "Cosa?!$"

GoldenrodCity_RadioTower_3F_Text_GruntM7After:
	.string "Ho fallito nel mio compito…\p"
	.string "ARCHER si arrabbierà molto...$"

GoldenrodCity_RadioTower_3F_Text_GruntM8Seen:
	.string "È bello ordinare ai POKéMON\n"
	.string "di commettere crimini.$"

GoldenrodCity_RadioTower_3F_Text_GruntM8Beaten:
	.string "Stai scherzando!$"

GoldenrodCity_RadioTower_3F_Text_GruntM8After:
	.string "Che male perdere!\p"
	.string "Dannazione! Odio i POKéMON inutili!$"

GoldenrodCity_RadioTower_3F_Text_GruntM9Seen:
	.string "Perché la saracinesca è\n"
	.string "aperta? C'entri qualcosa?$"

GoldenrodCity_RadioTower_3F_Text_GruntM9Beaten:
	.string "Sono finito!$"

GoldenrodCity_RadioTower_3F_Text_GruntM9After:
	.string "Cosa?! Hai superato i nostri\n"
	.string "nel SOTTERRANEO?\p"
	.string "Come hai fatto?$"

GoldenrodCity_RadioTower_3F_Text_ScientistMarcSeen:
	.string "Un bambino sconosciuto qui?\p"
	.string "Chi sei?$"

GoldenrodCity_RadioTower_3F_Text_ScientistMarcBeaten:
	.string "Tch! Ti ho sottovalutato!$"

GoldenrodCity_RadioTower_3F_Text_ScientistMarcAfter:
	.string "Bwahahaha…\p"
	.string "Posso trasmettere un segnale\n"
	.string "forte quanto voglio da qui.$"

