Route46_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route29_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route46_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route46_EventScript_Bailey::
	trainerbattle_single TRAINER_BAILEY_HNS, Route46_Text_HikerBaileySeen, Route46_Text_HikerBaileyBeaten
	msgbox Route46_Text_HikerBaileyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Ted::
	trainerbattle_single TRAINER_TED_HNS, Route46_Text_CamperTedSeen, Route46_Text_CamperTedBeaten
	msgbox Route46_Text_CamperTedAfterBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Erin::
	trainerbattle_single TRAINER_ERIN_HNS, Route46_Text_PicnickerErinSeen, Route46_Text_PicnickerErinBeaten, Route46_EventScript_RegisterErin
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route46_EventScript_RematchErin
	msgbox Route46_Text_PicnickerErinAfterBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_RegisterErin::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route46_Text_ErinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ERIN_HNS
	release
	end

Route46_EventScript_RematchErin::
	trainerbattle_rematch TRAINER_ERIN_HNS, Route46_Text_ErinRematchIntro, Route46_Text_ErinRematchDefeat
	msgbox Route46_Text_ErinPostRematch, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Sign::
	lock
	msgbox Route46_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route46_EventScript_Item_Revive::
	finditem ITEM_REVIVE
	end

Route46_Text_HikerBaileySeen:
	.string "Bene! Ti mostro la\n"
	.string "forza dei POKéMON di montagna!$"

Route46_Text_HikerBaileyBeaten:
	.string "Pietà! Mi hai mostrato la\n"
	.string "tua forza!$"

Route46_Text_HikerBaileyAfterBattle:
	.string "È finita. Non mi importa.\n"
	.string "Noi MONTANARI siamo così.$"

Route46_Text_CamperTedSeen:
	.string "Anch'io alleno POKéMON!\p"
	.string "Ti va di lottare con me?$"

Route46_Text_CamperTedBeaten:
	.string "Cosa…?$"

Route46_Text_CamperTedAfterBattle:
	.string "Ho dato il massimo ma non\n"
	.string "è bastato.\p"
	.string "Niente scuse, ammetto di aver perso.$"

Route46_Text_PicnickerErinSeen:
	.string "Anch'io alleno POKéMON!\p"
	.string "Ti va di lottare con me?$"

Route46_Text_PicnickerErinBeaten:
	.string "Oh, cavoli!$"

Route46_Text_PicnickerErinAfterBattle:
	.string "Ho visto molte PALESTRE, ma quella\n"
	.string "di FIORDOROPOLI è la mia preferita.\p"
	.string "È piena di bei fiori!$"

Route46_Text_ErinRegister:
	.string "Ho visto molte PALESTRE, ma quella\n"
	.string "di FIORDOROPOLI è la mia preferita.\p"
	.string "È piena di bei fiori!$"

Route46_Text_ErinRematchIntro:
	.string "Anch'io alleno POKéMON!\p"
	.string "Ti va di lottare con me?$"

Route46_Text_ErinRematchDefeat:
	.string "Oh, cavoli!$"

Route46_Text_ErinPostRematch:
	.string "Ho visto molte PALESTRE, ma quella\n"
	.string "di FIORDOROPOLI è la mia preferita.\p"
	.string "È piena di bei fiori!$"

Route46_Text_PicnickerErin2Beaten:
	.string "Aww… I keep losing all the time!\p"
	.string "I'll just have to try harder!\n"
	.string "Anyway, thanks for battling\n"
	.string "me again and again.\p"
	.string "Here's that present from the\n"
	.string "other time.$"

Route46_Text_Sign:
	.string "PERCORSO 46\n"
	.string "STRADA MONTANA AVANTI$"
