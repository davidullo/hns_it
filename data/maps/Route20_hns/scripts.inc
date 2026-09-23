Route20_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route20_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route20_EventScript_ShellBell::
	finditem ITEM_SHELL_BELL
	end

Route20_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route20_EventScript_Nicole::
	trainerbattle_single TRAINER_NICOLE_HNS, Route20_Text_SwimmerfNicoleSeen, Route20_Text_SwimmerfNicoleBeaten, Route20_EventScript_RegisterNicole
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route20_EventScript_RematchNicole
	msgbox Route20_Text_SwimmerfNicoleAfterBattle, MSGBOX_AUTOCLOSE
	end

Route20_EventScript_RegisterNicole::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route20_Text_NicoleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NICOLE_HNS
	release
	end

Route20_EventScript_RematchNicole::
	trainerbattle_rematch TRAINER_NICOLE_HNS, Route20_Text_NicoleRematchIntro, Route20_Text_NicoleRematchDefeat
	msgbox Route20_Text_NicolePostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_NICOLE_2_HNS, Route20_EventScript_RematchNicoleTryGiveItem
	end

Route20_EventScript_RematchNicoleTryGiveItem::
	checkitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_HEART_SCALE
	closemessage
	end

Route20_EventScript_Lori::
	trainerbattle_single TRAINER_LORI_HNS, Route20_Text_SwimmerfLoriSeen, Route20_Text_SwimmerfLoriBeaten
	msgbox Route20_Text_SwimmerfLoriAfterBattle, MSGBOX_AUTOCLOSE
	end	

Route20_EventScript_Cameron::
	trainerbattle_single TRAINER_CAMERON_HNS, Route20_Text_SwimmermCameronSeen, Route20_Text_SwimmermCameronBeaten
	msgbox Route20_Text_SwimmermCameronAfterBattle, MSGBOX_AUTOCLOSE
	end	

Route20_EventScript_SeafoamSign::
	msgbox Route20_Text_SeafoamSign, MSGBOX_SIGN
	end

Route20_EventScript_GymSign::
	msgbox Route20_Text_CinnabarIsland_GymUnusedSign, MSGBOX_SIGN
	end

Route20_EventScript_Seel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SEEL, CRY_MODE_NORMAL
	msgbox Route20_Text_Seel, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route20_EventScript_Dewgong::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DEWGONG, CRY_MODE_NORMAL
	msgbox Route20_Text_Dewgong, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route20_EventScript_Dennis::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAGIKARP, CRY_MODE_NORMAL
	msgbox Route20_Text_Dennis, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route20_EventScript_Headlocker::
	lock
	faceplayer
	msgbox Route20_Text_Headlocker, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROUTE20_HEADLOCKER, DIR_SOUTH
	release
	end

Route20_Text_Dennis:
	.string "DENNIS: SHAAAAAAAA!$"

Route20_Text_Headlocker:
	.string "C'è un POKéMON raro su questa\n"
	.string "rotta.\p"
	.string "E a volte porta un raro\n"
	.string "oggetto evolutivo.\p"
	.string "Doppia rarità!\p"
	.string "Devo finire il POKéDEX, quindi\n"
	.string "pesco qui da ore!$"

Route20_Text_Seel:
	.string "SEEL: Seel seel!$"

Route20_Text_Dewgong:
	.string "DEWGONG: Goooong!$"

Route20_Text_SeafoamSign:
	.string "ISOLE SEAFOAM$"

Route20_Text_NicoleRegister:
	.string "I tuoi POKéMON nuotano veloci!\n"
	.string "Dammi il tuo numero!$"

Route20_Text_NicoleRematchIntro:
	.string "Nuotare ha reso forti i miei\n"
	.string "POKéMON! Lottiamo!$"

Route20_Text_NicoleRematchDefeat:
	.string "Travolta di nuovo…$"

Route20_Text_NicolePostRematch:
	.string "Vinca o perda, mi sto allenando\n"
	.string "e anche i miei POKéMON!$"

Route20_Text_SwimmerfNicoleSeen:
	.string "Nell'acqua mi sento più leggera.$"

Route20_Text_SwimmerfNicoleBeaten:
	.string "Oh, no!$"

Route20_Text_SwimmerfNicoleAfterBattle:
	.string "Nuotare allena tutto il corpo.\p"
	.string "Fa davvero bene.$"

Route20_Text_SwimmerfLoriSeen:
	.string "Che collezione di MEDAGLIE!\n"
	.string "Dovremmo lottare!$"

Route20_Text_SwimmerfLoriBeaten:
	.string "No!$"

Route20_Text_SwimmerfLoriAfterBattle:
	.string "SURF non è più l'unica MN\n"
	.string "che usi in acqua.$"

Route20_Text_SwimmermCameronSeen:
	.string "Immagino sia impossibile\n"
	.string "nuotare fino a JOHTO.$"

Route20_Text_SwimmermCameronBeaten:
	.string "Ahi!$"

Route20_Text_SwimmermCameronAfterBattle:
	.string "Oltre al mare, so nuotare\n"
	.string "anche in laghi e fiumi.$"

Route20_Text_CinnabarIsland_GymUnusedSign:
	.string "Cosa dice questo cartello?\p"
	.string "CAPOPALESTRA DI ISOLA\nCANNELLA: BLAINE$"

