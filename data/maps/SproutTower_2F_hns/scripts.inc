SproutTower_2F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SproutTower_2F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

SproutTower_2F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

SproutTower_2F_EventScript_SageNico::
	trainerbattle_single TRAINER_NICO_HNS, SproutTower_Text_SageNico_Seen, SproutTower_Text_SageNico_Beaten
	msgbox SproutTower_Text_SageNico_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_2F_EventScript_SageEdmond::
	trainerbattle_single TRAINER_EDMOND_HNS, SproutTower_Text_SageEdmond_Seen, SproutTower_Text_SageEdmond_Beaten
	msgbox SproutTower_Text_SageEdmond_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_2F_EventScript_Statue::
	lock
	msgbox SproutTower_Text_2F_Statue, MSGBOX_AUTOCLOSE
	release
	end

SproutTower_2F_EventScript_Xdefend::
	finditem ITEM_X_DEFEND
	end

SproutTower_Text_SageNico_Seen:
	.string "Per quanto dura sia la lotta,\n"
	.string "la TORRE resterà salda.$"

SproutTower_Text_SageNico_Beaten:
	.string "Ho lottato, ma sono troppo debole.$"

SproutTower_Text_SageNico_AfterBattle:
	.string "Il pilastro flessibile protegge la\n"
	.string "TORRE, persino dai terremoti.$"

SproutTower_Text_SageEdmond_Seen:
	.string "…Ondeggia come foglie al vento…$"

SproutTower_Text_SageEdmond_Beaten:
	.string "Oh, sono debole!$"

SproutTower_Text_SageEdmond_AfterBattle:
	.string "Ho provato a copiare i movimenti\n"
	.string "gentili di BELLSPROUT…\p"
	.string "Ma non mi sono allenato abbastanza.$"

SproutTower_Text_2F_Statue:
	.string "Una statua di POKéMON…\p"
	.string "Sembra molto distinta.$"
