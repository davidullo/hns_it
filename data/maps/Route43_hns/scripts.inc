Route43_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route43_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route43_MapScript_OnTransition::
	call_if_set FLAG_HIDE_ROUTE42_SUICUNE, Route42_MapScript_HideTrigger
	callnative SetTimeBasedEncounters
	end

Route43_EventScript_Ben::
	trainerbattle_single TRAINER_BEN_HNS, Route43_Text_PokemaniacBenSeen, Route43_Text_PokemaniacBenBeaten
	msgbox Route43_Text_PokemaniacBenAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Brent::
	trainerbattle_single TRAINER_BRENT_HNS, Route43_Text_PokemaniacBrentSeen, Route43_Text_PokemaniacBrentBeaten, Route43_EventScript_RegisterBrent
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route43_EventScript_RematchBrent
	msgbox Route43_Text_PokemaniacBrentAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_RegisterBrent::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route43_Text_BrentRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BRENT_HNS
	release
	end

Route43_EventScript_RematchBrent::
	trainerbattle_rematch TRAINER_BRENT_HNS, Route43_Text_BrentRematchIntro, Route43_Text_BrentRematchDefeat
	msgbox Route43_Text_BrentPostRematch, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Ron::
	trainerbattle_single TRAINER_RON_HNS, Route43_Text_PokemaniacRonSeen, Route43_Text_PokemaniacRonBeaten
	msgbox Route43_Text_PokemaniacRonAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Marvin::
	trainerbattle_single TRAINER_MARVIN_HNS, Route43_Text_FisherMarvinSeen, Route43_Text_FisherMarvinBeaten
	msgbox Route43_Text_FisherMarvinAfter, MSGBOX_AUTOCLOSE
	end
	
Route43_EventScript_Spencer::
	trainerbattle_single TRAINER_SPENCER_HNS, Route43_Text_CamperSpencerSeen, Route43_Text_CamperSpencerBeaten
	msgbox Route43_Text_CamperSpencerAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Tiffany::
	trainerbattle_single TRAINER_TIFFANY_HNS, Route43_Text_PicnickerTiffanySeen, Route43_Text_PicnickerTiffanyBeaten, Route43_EventScript_RegisterTiffany
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route43_EventScript_RematchTiffany
	msgbox Route43_Text_PicnickerTiffanyWantsPicnic, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_RegisterTiffany::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route43_Text_TiffanyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TIFFANY_HNS
	release
	end

Route43_EventScript_RematchTiffany::
	trainerbattle_rematch TRAINER_TIFFANY_HNS, Route43_Text_TiffanyRematchIntro, Route43_Text_TiffanyRematchDefeat
	msgbox Route43_Text_TiffanyPostRematch, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Sign1::
	msgbox Route43_Sign2, MSGBOX_SIGN
	end

Route43_EventScript_Sign2::
	msgbox Route43_TrainerTips, MSGBOX_SIGN
	end

Route43_EventScript_Item_Max_Ether::
	finditem ITEM_MAX_ETHER
	end

Route43_Text_PokemaniacBenSeen:
    .string "Adoro i POKéMON!\p"
    .string "Ecco perché ho iniziato, e continuerò\n"
    .string "a collezionare POKéMON!$"

Route43_Text_PokemaniacBenBeaten:
    .string "Come hai potuto farmi questo?$"

Route43_Text_PokemaniacBenAfter:
    .string "Cos'altro mi piace oltre ai\n"
    .string "POKéMON?\p"
    .string "MARY alla radio. Scommetto che è\n"
    .string "carina!$"

Route43_Text_PokemaniacBrentSeen:
    .string "Ehi! Hai POKéMON\n"
    .string "rari?$"

Route43_Text_PokemaniacBrentBeaten:
    .string "Oh, i miei poveri POKéMON! Tesori!$"

Route43_Text_PokemaniacBrentAfter:
    .string "Mi basterebbe avere un solo\n"
    .string "POKéMON raro.$"

Route43_Text_BrentRegister:
    .string "Mi basterebbe avere un solo\n"
    .string "POKéMON raro.$"

Route43_Text_BrentRematchIntro:
    .string "Ehi! Hai POKéMON\n"
    .string "rari?$"

Route43_Text_BrentRematchDefeat:
    .string "Oh, i miei poveri POKéMON! Tesori!$"

Route43_Text_BrentPostRematch:
    .string "Mi basterebbe avere un solo\n"
    .string "POKéMON raro.$"

Route43_Text_PokemaniacRonSeen:
    .string "Ci credi?\p"
    .string "Un tale di nome {RIVAL} ha preso\n"
    .string "in giro i miei POKéMON!\p"
    .string "Dannazione! Sono fortissimi!$"

Route43_Text_PokemaniacRonBeaten:
    .string "Il mio NIDOKING se l'è cavata bene!$"

Route43_Text_PokemaniacRonAfter:
    .string "Va bene che alla gente piacciano\n"
    .string "tipi diversi di POKéMON.\p"
    .string "Non conta avere il POKéMON\n"
    .string "più forte.$"

Route43_Text_FisherMarvinSeen:
    .string "Sono in crisi.\p"
    .string "Forse è l'attrezzatura.\p"
    .string "Lottiamo per cambiare ritmo!$"

Route43_Text_FisherMarvinBeaten:
    .string "Ho perso, ma sto meglio comunque.$"

Route43_Text_FisherMarvinAfter:
    .string "La ESCA BALL di KURT è la migliore\n"
    .string "per prendere i POKéMON abboccati.\p"
    .string "È molto più efficace di una\n"
    .string "ULTRA BALL.$"

Route43_Text_CamperSpencerSeen:
    .string "Con i miei POKéMON posso fare\n"
    .string "tanto, è divertentissimo!$"

Route43_Text_CamperSpencerBeaten:
    .string "Perdere non è divertente…$"

Route43_Text_CamperSpencerAfter:
    .string "Cosa succede al LAGO D'IRA?\p"
    .string "Volevamo campeggiare lì.$"

Route43_Text_PicnickerTiffanySeen:
    .string "Vai anche tu al LAGO D'IRA?\p"
    .string "Giochiamo un po'!$"

Route43_Text_PicnickerTiffanyBeaten:
    .string "Ho giocato troppo!$"

Route43_Text_PicnickerTiffanyWantsPicnic:
    .string "Faccio un picnic con i POKéMON.\p"
    .string "Vuoi unirti a noi?$"

Route43_Text_TiffanyRegister:
    .string "Faccio un picnic con i POKéMON.\p"
    .string "Vuoi unirti a noi?$"

Route43_Text_TiffanyRematchIntro:
    .string "Vai anche tu al LAGO D'IRA?\p"
    .string "Giochiamo un po'!$"

Route43_Text_TiffanyRematchDefeat:
    .string "Ho giocato troppo!$"

Route43_Text_TiffanyPostRematch:
    .string "Faccio un picnic con i POKéMON.\p"
    .string "Vuoi unirti a noi?$"

Route43_Sign1:
    .string "PERCORSO 43\p"
    .string "LAGO D'IRA - POKéMONNETEOPOLI$"

Route43_Sign2:
    .string "PERCORSO 43\p"
    .string "LAGO D'IRA - POKéMONNETEOPOLI$"

Route43_TrainerTips:
    .string "CONSIGLI PER ALLENATORI\p"
    .string "Ogni POKéMON ha pregi e difetti\n"
    .string "a seconda del suo tipo.\p"
    .string "Se i tipi sono diversi, un POKéMON\n"
    .string "di livello più alto può perdere.\p"
    .string "Impara quali tipi sono forti e\n"
    .string "deboli contro il tuo POKéMON.$"
