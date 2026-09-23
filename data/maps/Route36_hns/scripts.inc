Route36_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route36_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route36_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route36_EventScript_RockSmashGuy::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, Route36_EventScript_RockSmashGuy2
	msgbox Route36_Text_RockSmashGuy1, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_RockSmashGuy2::
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, Route36_EventScript_RockSmashGuy3
	msgbox Route36_Text_RockSmashGuy2, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
Route36_EventScript_RockSmashGuy3::
	msgbox Route36_Text_RockSmashGuy3
	closemessage
	release
	end

Route36_EventScript_Lass::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, Route36_EventScript_Lass2
	msgbox Route36_Text_Lass1, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_Lass2::
	msgbox Route36_Text_Lass2_ClearedSudowoodo, MSGBOX_DEFAULT
	closemessage
	release
	end

Route36_EventScript_Arthur::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HARD_STONE, Route36_EventScript_ArthurCompleted
	msgbox Route36_Text_MeetArthur, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route36_EventScript_ArthurNope
	case 1, Route36_EventScript_ArthurNope
	case 2, Route36_EventScript_ArthurNope
	case 3, Route36_EventScript_ArthurNope
	case 4, Route36_EventScript_ArthurYes
	case 5, Route36_EventScript_ArthurNope
	case 6, Route36_EventScript_ArthurNope
	case 7, Route36_EventScript_ArthurCancel
	case MULTI_B_PRESSED, Route36_EventScript_ArthurCancel
	closemessage
	release
	end
Route36_EventScript_ArthurYes::
	msgbox Route36_Text_ArthurGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_HARD_STONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_HARD_STONE
	msgbox Route36_Text_ArthurGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_ArthurNope::
	msgbox Route36_Text_ArthurNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_ArthurCancel::
	closemessage
	release
	end
Route36_EventScript_ArthurCompleted::
	msgbox Route36_Text_ArthurThursday, MSGBOX_DEFAULT
	closemessage
	release
	end


Route36_EventScript_SudoWoodo::
	lock
	msgbox Route36_Text_OddTree, MSGBOX_DEFAULT
	checkitem ITEM_SQUIRT_BOTTLE
	goto_if_eq VAR_RESULT, TRUE, Route36_EventScript_SudoWoodoChoice
	closemessage
	release
	end
Route36_EventScript_SudoWoodoChoice::
	msgbox Route36_Text_UseSquirtbottle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route36_EventScript_SudoWoodoWater
	closemessage
	release
	end
Route36_EventScript_SudoWoodoWater::
	msgbox Route36_Text_UsedSquirtbottle, MSGBOX_DEFAULT
	playse SE_DOWNPOUR
	waitse
	closemessage
	playse SE_SUDOWOODO_SHAKE	
	applymovement LOCALID_ROUTE36_SUDOWOODO, Route36_Movement_SudoWoodo
	waitmovement 0
	faceplayer
	msgbox Route36_Text_SudowoodoAttacked	
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_ROUTE36_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 20
	@setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	@clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route36_EventScript_Defeated_Sudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route36_EventScript_RanSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route36_EventScript_RanSudowoodo
Route36_EventScript_Defeated_Sudowoodo::
	setflag FLAG_HIDE_SUDOWOODO
	removeobject LOCALID_ROUTE36_SUDOWOODO
	checkitem ITEM_HM_ROCK_SMASH
	call_if_eq VAR_RESULT, FALSE, Route36_EventScript_RockSmashGuySudoWoodo
	release
	end

Route36_EventScript_RanSudowoodo::
	turnobject LOCALID_ROUTE36_SUDOWOODO, DIR_NORTH
	release
	end

Route36_EventScript_RockSmashGuySudoWoodo:
	playse SE_PIN
	applymovement LOCALID_ROUTE36_ROCKSMASHGUY, Common_Movement_ExclamationMark
	turnobject LOCALID_ROUTE36_ROCKSMASHGUY, DIR_WEST
	waitmovement 0
	applymovement LOCALID_ROUTE36_ROCKSMASHGUY, Route36_Movement_RockSmashGuy
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitmovement 0
	return

Route36_Movement_RockSmashGuy:
	jump_in_place_left
	delay_2
	jump_in_place_left
	delay_2
	jump_in_place_left
	delay_2
	jump_in_place_left
	step_end

Route36_EventScript_Mark::
	trainerbattle_single TRAINER_MARK_HNS, Route36_Text_PsychicMarkSeen, Route36_Text_PsychicMarkBeaten
	msgbox Route36_Text_PsychicMarkAfter, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_Schoolboy::
	trainerbattle_single TRAINER_ALAN_HNS, Route36_Text_SchoolboyAlan1Seen, Route36_Text_SchoolboyAlan1Beaten, Route36_EventScript_RegisterAlan
	goto_if_set FLAG_ALAN_HAS_ITEM_HNS, Route36_EventScript_AlanGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route36_EventScript_RematchAlan
	msgbox Route36_Text_SchoolboyAlanAfter, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_RegisterAlan::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route36_Text_AlanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ALAN_HNS
	release
	end

Route36_EventScript_RematchAlan::
	trainerbattle_rematch TRAINER_ALAN_HNS, Route36_Text_AlanRematchIntro, Route36_Text_AlanRematchDefeat
	msgbox Route36_Text_AlanPostRematch, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_AlanGiveItem::
	msgbox Route36_Text_AlanHasItem, MSGBOX_DEFAULT
	giveitem VAR_ALAN_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route36_EventScript_AlanNoRoom
	clearflag FLAG_ALAN_HAS_ITEM_HNS
	msgbox Route36_Text_AlanGaveItem, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_AlanNoRoom::
	msgbox Route36_Text_AlanNoRoom, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_Sign::
	lock
	msgbox Route36_Text_Sign_RuinsNorth, MSGBOX_SIGN
	closemessage
	release
	end

Route36_EventScript_Sign2::
	lock
	msgbox Route36_Text_Tips1, MSGBOX_SIGN
	closemessage
	release
	end

Route36_Movement_SudoWoodo:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

Route36_Text_UseSquirtbottle:
	.string "Usare l'ANNAFFIATOIO?$"

Route36_Text_UsedSquirtbottle:
	.string "{PLAYER} usa l'ANNAFFIATOIO.$"

Route36_Text_SudowoodoAttacked:
	.string "Lo strano albero non gradisce\n"
	.string "l'ANNAFFIATOIO!\p"
	.string "Lo strano albero ha attaccato!$"

Route36_Text_RockSmashGuy1:
	.string "Ehi!\p"
	.string "Volevo spezzare quell'albero\n"
	.string "con un pugno teso.\p"
	.string "Ma non ci sono riuscito! Che fallito!$"

Route36_Text_RockSmashGuy2:
	.string "Hai tolto di mezzo quell'albero?\p"
	.string "Sono impressionato!\n"
	.string "Voglio darti questo.$"

Route36_Text_RockSmashGuy3:
	.string "Si tratta di SPACCAROCCIA.\p"
	.string "Puoi frantumare le rocce con un\n"
	.string "solo colpo ben mirato.\p"
	.string "Se trovi rocce sul cammino,\n"
	.string "falle a pezzi!$"

Route36_Text_OddTree:
	.string "Un albero strano blocca la strada.$"

Route36_Text_Lass1:
	.string "Attenzione di notte su questo\p"
	.string "percorso! Ho visto un POKéMON\n"
	.string "simile a GROWLITHE, ma con\l"
	.string "un'aura spaventosa.$"

Route36_Text_Lass2_ClearedSudowoodo:
	.string "Quell'albero strano è sparito senza\n"
	.string "lasciare traccia.\p"
	.string "Oh! Quell'albero era davvero un\n"
	.string "POKéMON?$"

Route36_Text_PsychicMarkSeen:
	.string "Leggerò i tuoi pensieri!$"

Route36_Text_PsychicMarkBeaten:
	.string "Ti ho letto male!$"

Route36_Text_PsychicMarkAfter:
	.string "Sarei forte se solo sapessi\n"
	.string "cosa pensa il mio avversario.$"

Route36_Text_SchoolboyAlan1Seen:
	.string "Grazie ai miei studi, sono pronto\n"
	.string "per qualsiasi POKéMON!$"

Route36_Text_SchoolboyAlan1Beaten:
	.string "Ops! Errore di calcolo?$"

Route36_Text_SchoolboyAlanAfter:
	.string "Cavolo. Studio cinque ore al giorno.\p"
	.string "Imparare non è solo\n"
	.string "leggere libri.$"

Route36_Text_MeetArthur:
	.string "ARTHUR: Chi sei tu?\n"
	.string "Sono ARTHUR della FAMIGLIA GIORNI.\p"
	.string "Se indovini il mio giorno preferito,\n"
	.string "ti darò una ricompensa.$"

Route36_Text_ArthurNope:
	.string "Non è così!$"

Route36_Text_ArthurGivesGift:
	.string "Ecco. Prendi questo.$"

Route36_Text_ArthurGaveGift:
	.string "ARTHUR: Un POKéMON che usa mosse di\n"
	.string "tipo ROCCIA dovrebbe tenerlo.\p"
	.string "Potenzia gli attacchi ROCCIA.$"

Route36_Text_ArthurThursday:
	.string "ARTHUR: Sono ARTHUR del Giovedì.\n"
	.string "Sono il quinto di sette figli.$"

Route36_Text_Sign:
	.string "PERCORSO 36$"

Route36_Text_Sign_RuinsNorth:
	.string "ROVINE D'ALPH\n"
	.string "INGRESSO NORD$"

Route36_Text_Tips1:
	.string "CONSIGLI ALLENATORI\n"
	.string "Le statistiche dei POKéMON variano\l"
	.string "anche nella stessa specie.\p"
	.string "All'inizio possono sembrare simili.\p"
	.string "Ma le differenze diventeranno\n"
	.string "evidenti man mano che crescono.$"

Route36_Text_Tips2:
	.string "CONSIGLI ALLENATORI\n"
	.string "Usa FOSSA per tornare all'ingresso\n"
	.string "di ogni luogo.\p"
	.string "È comodo per esplorare\n"
	.string "grotte e altri luoghi.$"

Route36_Text_AlanRegister:
	.string "Cavolo. Studio cinque ore al giorno.\p"
	.string "Imparare non è solo\n"
	.string "leggere libri.$"

Route36_Text_AlanRematchIntro:
	.string "Grazie ai miei studi, sono pronto\n"
	.string "per qualsiasi POKéMON!$"

Route36_Text_AlanRematchDefeat:
	.string "Ops! Errore di calcolo?$"

Route36_Text_AlanPostRematch:
	.string "Cavolo. Studio cinque ore al giorno.\p"
	.string "Imparare non è solo\n"
	.string "leggere libri.$"

Route36_Text_AlanHasItem:
	.string "Ehi! Ho trovato qualcosa\n"
	.string "mentre studiavo!\p"
	.string "Tieni, prendilo!$"

Route36_Text_AlanGaveItem:
	.string "Ti farò sapere se trovo\n"
	.string "altro!$"

Route36_Text_AlanNoRoom:
	.string "Hmm, la tua BORSA è piena.\p"
	.string "Torna quando avrai spazio.$"
