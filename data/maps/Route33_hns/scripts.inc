Route33_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route33_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route33_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route33_EventScript_HikerAnthony::
	trainerbattle_single TRAINER_ANTHONY_HNS, Route33_Text_HikerAnthony2Seen, Route33_Text_HikerAnthony2Beaten, Route33_EventScript_RegisterAnthony
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route33_EventScript_RematchAnthony
	msgbox Route33_Text_HikerAnthony2After, MSGBOX_AUTOCLOSE
	end

Route33_EventScript_RegisterAnthony::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route33_Text_AnthonyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ANTHONY_HNS
	release
	end

Route33_EventScript_RematchAnthony::
	trainerbattle_rematch TRAINER_ANTHONY_HNS, Route33_Text_AnthonyRematchIntro, Route33_Text_AnthonyRematchDefeat
	msgbox Route33_Text_AnthonyPostRematch, MSGBOX_AUTOCLOSE
	end

Route33_EventScript_Lass::
	lock
	faceplayer
	msgbox Route33_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route33_Text_HikerAnthony2Seen:
	.string "Ho attraversato il tunnel,\n"
	.string "ma ho ancora un sacco\l"
	.string "di energia.$"

Route33_Text_HikerAnthony2Beaten:
	.string "Whoa! Hai più energia\n"
	.string "di me!$"

Route33_Text_HikerAnthony2After:
	.string "Noi ALPINISTI diamo il meglio\n"
	.string "in montagna.$"

Route33_Text_AnthonyRegister:
	.string "Noi ALPINISTI diamo il meglio\n"
	.string "in montagna.$"

Route33_Text_AnthonyRematchIntro:
	.string "Ho attraversato il tunnel,\n"
	.string "ma ho ancora un sacco\l"
	.string "di energia.$"

Route33_Text_AnthonyRematchDefeat:
	.string "Whoa! Hai più energia\n"
	.string "di me!$"

Route33_Text_AnthonyPostRematch:
	.string "Noi ALPINISTI diamo il meglio\n"
	.string "in montagna.$"

Route33_Text_HikerAnthonyDunsparce:
	.string "Ehi, hai preso un DUNSPARCE?\p"
	.string "Ne ho preso uno anch'io.\p"
	.string "Guardalo contro la luce.\n"
	.string "Ha una faccia buffa!$"

Route33_Text_Lass:
	.string "Pant, pant…\p"
	.string "Quella grotta era più grande\n"
	.string "del previsto.\p"
	.string "Mi sono stancata cercando\n"
	.string "MARILL, così sono uscita.$"
