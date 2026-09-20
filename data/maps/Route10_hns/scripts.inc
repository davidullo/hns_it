Route10_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route10_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route10_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route10_EventScript_Surge::
    lock
    faceplayer
    msgbox Route10_Text_Surge, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_PLANT_SURGE
    removeobject LOCALID_ROUTE10_SURGE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_SURGE
    release
    end

Route10_Text_Surge:
    .string "Ehi, ragazzo!\p"
	.string "Tieni alta la guardia qui fuori,\n"
	.string "questo posto scoppietta di energia!\p"
	.string "Se vuoi la rivincita, presentati al\n"
	.string "DOJO LOTTA!$"

Route10_EventScript_Item_Rock_Polish::
    finditem ITEM_TM_ROCK_POLISH
    end

Route10_EventScript_Jim::
	trainerbattle_single TRAINER_JIM_HNS, Route10_Text_HikerJimSeen, Route10_Text_HikerJimBeaten
	msgbox Route10_Text_HikerJimAfter, MSGBOX_AUTOCLOSE
	end

Route10_EventScript_Robert::
	trainerbattle_single TRAINER_ROBERT_HNS, Route10_Text_PokefanmRobertSeen, Route10_Text_PokefanmRobertBeaten
	msgbox Route10_Text_PokefanmRobertAfter, MSGBOX_AUTOCLOSE
	end

Route10_EventScript_Sign::
	msgbox Route10_Text_Sign, MSGBOX_SIGN
	end

Route10_EventScript_PPSign::
	msgbox Route10_Text_PowerPlant, MSGBOX_SIGN
	end

Route10_EventScript_Zapdos::
	lock
	faceplayer
	playmoncry SPECIES_ZAPDOS, CRY_MODE_ENCOUNTER
	msgbox SeafoamIslands_B1F_Text_ArticunoBattle
	delay 40
	waitmoncry
	seteventmon SPECIES_ZAPDOS, 50
	special BattleSetup_StartLegendaryBattle
waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route10_EventScript_ZapdosRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_ROUTE10_ZAPDOS
	setflag FLAG_HIDE_ZAPDOS
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

Route10_EventScript_ZapdosRan::
	release
	end


Route10_Text_HikerJimSeen:
	.string "Ahahahah!$"

Route10_Text_HikerJimBeaten:
	.string "Ahahaha-ecciù!$"

Route10_Text_HikerJimAfter:
	.string "Il raffreddore mi fa starnutire!\n"
	.string "Ahahah-ECCIÙ!$"

Route10_Text_PokefanmRobertSeen:
	.string "Ti piacciono i POKéMON, vero?\p"
	.string "Anche a me!$"

Route10_Text_PokefanmRobertBeaten:
	.string "Devo dire che è una mia sconfitta.$"

Route10_Text_PokefanmRobertAfter:
	.string "Guarda cosa hai fatto ai miei POKéMON…\p"
	.string "Non lo dimenticherò…$"

Route10_Text_PowerPlant:
	.string "CENTRALE ELETTRICA$"

Route10_Text_Sign:
	.string "ROUTE 10\p"
	.string "CERULEAN CITY - LAVENDER TOWN$"
