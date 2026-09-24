.equ RECEIVED_TOWN_MAP, VAR_TEMP_1

PalletTown_RivalsHouse_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_RivalsHouse_OnTransition
	.byte 0

PalletTown_RivalsHouse_OnTransition::
	call_if_lt VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, PalletTown_RivalsHouse_EventScript_MoveDaisyToTable
	call_if_ge VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, PalletTown_RivalsHouse_EventScript_AlreadyReceivedTownMap
	end

PalletTown_RivalsHouse_EventScript_MoveDaisyToTable::
	setobjectmovementtype LOCALID_DAISY, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_DAISY, 5, 4
	return

PalletTown_RivalsHouse_EventScript_AlreadyReceivedTownMap::
	setvar RECEIVED_TOWN_MAP, TRUE
	return

PalletTown_RivalsHouse_EventScript_Daisy::
	lock
	faceplayer
	famechecker FAMECHECKER_DAISY, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	goto_if_set FLAG_SYS_GAME_CLEAR, PalletTown_RivalsHouse_EventScript_GroomMon
	goto_if_eq RECEIVED_TOWN_MAP, TRUE, PalletTown_RivalsHouse_EventScript_PleaseGiveMonsRest
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, PalletTown_RivalsHouse_EventScript_ExplainTownMap
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 1, PalletTown_RivalsHouse_EventScript_GiveTownMap
	goto_if_ge VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1, PalletTown_RivalsHouse_EventScript_HeardBattledRival
	msgbox PalletTown_RivalsHouse_Text_HiBrothersAtLab
	closemessage
	applymovement LOCALID_DAISY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PalletTown_RivalsHouse_EventScript_HeardBattledRival::
	msgbox PalletTown_RivalsHouse_Text_HeardYouBattledRival
	release
	end

PalletTown_RivalsHouse_EventScript_GroomMon::
	goto_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 500, PalletTown_RivalsHouse_EventScript_RateMonFriendship
	msgbox PalletTown_RivalsHouse_Text_LikeMeToGroomMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PalletTown_RivalsHouse_EventScript_DeclineGrooming
	msgbox PalletTown_RivalsHouse_Text_GroomWhichOne
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	goto_if_ge VAR_0x8004, PARTY_SIZE, PalletTown_RivalsHouse_EventScript_DeclineGrooming
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, PalletTown_RivalsHouse_EventScript_CantGroomEgg
	msgbox PalletTown_RivalsHouse_Text_LookingNiceInNoTime
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special DaisyMassageServices
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox PalletTown_RivalsHouse_Text_ThereYouGoAllDone
	release
	end

PalletTown_RivalsHouse_EventScript_CantGroomEgg::
	msgbox PalletTown_RivalsHouse_Text_CantGroomAnEgg
	release
	end

PalletTown_RivalsHouse_EventScript_DeclineGrooming::
	msgbox PalletTown_RivalsHouse_Text_DontNeedAnyGrooming
	release
	end

PalletTown_RivalsHouse_EventScript_RateMonFriendship::
	msgbox PalletTown_RivalsHouse_Text_MayISeeFirstMon
	specialvar VAR_RESULT, GetLeadMonFriendship
	switch VAR_RESULT
	case 0, PalletTown_RivalsHouse_EventScript_MonFriendshipLowest
	case 1, PalletTown_RivalsHouse_EventScript_MonFriendshipLower
	case 2, PalletTown_RivalsHouse_EventScript_MonFriendshipLow
	case 3, PalletTown_RivalsHouse_EventScript_MonFriendshipMid
	case 4, PalletTown_RivalsHouse_EventScript_MonFriendshipHigh
	case 5, PalletTown_RivalsHouse_EventScript_MonFriendshipHigher
	case 6, PalletTown_RivalsHouse_EventScript_MonFriendshipHighest
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipLowest::
	msgbox PalletTown_RivalsHouse_Text_WhyWouldMonHateYouSoMuch
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipLower::
	msgbox PalletTown_RivalsHouse_Text_DontLikeWayItGlaresAtYou
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipLow::
	msgbox PalletTown_RivalsHouse_Text_NotFamiliarWithYouYet
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipMid::
	msgbox PalletTown_RivalsHouse_Text_ItsWarmingUpToYou
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipHigh::
	msgbox PalletTown_RivalsHouse_Text_ItsQuiteFriendly
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipHigher::
	msgbox PalletTown_RivalsHouse_Text_ItLooksVeryHappy
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipHighest::
	msgbox PalletTown_RivalsHouse_Text_CouldntLoveYouMore
	release
	end

PalletTown_RivalsHouse_EventScript_PleaseGiveMonsRest::
	msgbox PalletTown_RivalsHouse_Text_PleaseGiveMonsRest
	release
	end

PalletTown_RivalsHouse_EventScript_GiveTownMap::
	msgbox PalletTown_RivalsHouse_Text_ErrandForGrandpaThisWillHelp
	closemessage
	checkitemspace ITEM_TOWN_MAP
	goto_if_eq VAR_RESULT, FALSE, PalletTown_RivalsHouse_EventScript_NoRoomForTownMap
	applymovement LOCALID_DAISY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	removeobject LOCALID_TOWN_MAP
	setvar VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2
	delay 15
	applymovement LOCALID_DAISY, Common_Movement_FacePlayer
	waitmovement 0
	delay 12
	giveitem_msg PalletTown_RivalsHouse_Text_ReceivedTownMapFromDaisy, ITEM_TOWN_MAP, 1, MUS_RG_OBTAIN_KEY_ITEM
	release
	end

PalletTown_RivalsHouse_EventScript_NoRoomForTownMap::
	msgbox PalletTown_RivalsHouse_Text_DontHaveSpaceForThis
	release
	end

PalletTown_RivalsHouse_EventScript_ExplainTownMap::
	msgbox PalletTown_RivalsHouse_Text_ExplainTownMap
	release
	end

PalletTown_RivalsHouse_EventScript_TownMap::
	msgbox PalletTown_RivalsHouse_Text_ItsBigMapOfKanto, MSGBOX_NPC
	end

PalletTown_RivalsHouse_EventScript_Bookshelf::
	msgbox PalletTown_RivalsHouse_Text_ShelvesCrammedFullOfBooks, MSGBOX_SIGN
	end

PalletTown_RivalsHouse_EventScript_Picture::
	msgbox PalletTown_RivalsHouse_Text_LovelyAndSweetClefairy, MSGBOX_SIGN
	end

PalletTown_RivalsHouse_Text_HiBrothersAtLab::
	.string "MARGI: Ciao, {PLAYER}!\p"
	.string "Mio fratello {RIVAL} è al\n"
	.string "LABORATORIO del nonno.$"

PalletTown_RivalsHouse_Text_HeardYouBattledRival::
	.string "MARGI: {PLAYER}, ho saputo che hai\n"
	.string "lottato contro {RIVAL}.\p"
	.string "Vorrei averlo visto!$"

PalletTown_RivalsHouse_Text_ErrandForGrandpaThisWillHelp::
	.string "Il nonno ti ha chiesto di fare\n"
	.string "una commissione?\p"
	.string "Che pigro che è.\n"
	.string "Tieni, questo ti aiuterà.$"

PalletTown_RivalsHouse_Text_ReceivedTownMapFromDaisy::
	.string "{PLAYER} riceve una MAPPA CITTÀ\n"
	.string "da MARGI.$"

PalletTown_RivalsHouse_Text_DontHaveSpaceForThis::
	.string "Non hai spazio per questo nello\n"
	.string "zaino.$"

PalletTown_RivalsHouse_Text_ExplainTownMap::
	.string "Con la MAPPA CITTÀ scopri dove\n"
	.string "ti trovi e puoi vedere i\l"
	.string "nomi dei luoghi.$"

PalletTown_RivalsHouse_Text_PleaseGiveMonsRest::
	.string "MARGI: Come le persone, i POKéMON\n"
	.string "sono esseri viventi.\p"
	.string "Quando sono stanchi, falli\n"
	.string "riposare.$"

PalletTown_RivalsHouse_Text_ItsBigMapOfKanto::
	.string "È una grande mappa della regione KANTO.\n"
	.string "Sarebbe proprio utile!$"

PalletTown_RivalsHouse_Text_ShelvesCrammedFullOfBooks::
	.string "Gli scaffali sono pieni di\n"
	.string "libri sui POKéMON.$"

PalletTown_RivalsHouse_Text_LikeMeToGroomMon::
	.string "MARGI: Ciao, {PLAYER}!\n"
	.string "Che tempismo.\p"
	.string "Sto per prendere il tè.\n"
	.string "Vuoi unirti a me?\p"
	.string "Oh, ma guarda.\n"
	.string "I tuoi POKéMON sono un po' sporchi.\p"
	.string "Vuoi che ne pettini uno?$"

PalletTown_RivalsHouse_Text_DontNeedAnyGrooming::
	.string "Non vuoi farlo pettinare?\n"
	.string "Va bene, prendiamo il tè.$"

PalletTown_RivalsHouse_Text_GroomWhichOne::
	.string "Quale vuoi che pettini?$"

PalletTown_RivalsHouse_Text_LookingNiceInNoTime::
	.string "MARGI: Okay, lo renderò\n"
	.string "bello in un attimo.$"

PalletTown_RivalsHouse_Text_ThereYouGoAllDone::
#ifdef BUGFIX @ The localizers missed what should be a textcolor change in the localizations.
	.string "{COLOR DARK_GRAY}{STR_VAR_1} sembra felice e sognante…\p"
	.string "{COLOR RED}MARGI: Ecco fatto! Tutto a posto.\n"
#else @ In the JP games, gender-based text used a different font instead of different colors.
	.string "{FONT_NORMAL}{STR_VAR_1} looks dreamily content…\p"
	.string "{FONT_FEMALE}MARGI: There you go! All done.\n"
#endif
	.string "Visto? Non è carino?\p"
	.string "Eh eh…\n"
	.string "È un POKéMON così tenero.$"

PalletTown_RivalsHouse_Text_CantGroomAnEgg::
	.string "Oh, scusa. Non posso certo\n"
	.string "pettinare un UOVO.$"

PalletTown_RivalsHouse_Text_MayISeeFirstMon::
	.string "MARGI: I POKéMON imparano a volerti\n"
	.string "bene se li cresci con amore.\p"
	.string "Per esempio, {PLAYER}, posso vedere\n"
	.string "il tuo primo POKéMON?$"

PalletTown_RivalsHouse_Text_CouldntLoveYouMore::
	.string "Non potrebbe volerti più\n"
	.string "bene di così.\p"
	.string "Il tuo POKéMON è felice oltre\n"
	.string "ogni parola.$"

PalletTown_RivalsHouse_Text_ItLooksVeryHappy::
	.string "Sembra molto felice.\p"
	.string "Vorrei che {RIVAL} lo vedesse e\n"
	.string "imparasse qualcosa.$"

PalletTown_RivalsHouse_Text_ItsQuiteFriendly::
	.string "È piuttosto amichevole con te.\n"
	.string "Continua a trattarlo bene!$"

PalletTown_RivalsHouse_Text_ItsWarmingUpToYou::
	.string "Si sta affezionando a te.\n"
	.string "La fiducia cresce tra voi.$"

PalletTown_RivalsHouse_Text_NotFamiliarWithYouYet::
	.string "Non ha ancora confidenza\n"
	.string "con te.\p"
	.string "I POKéMON sono diffidenti appena\n"
	.string "li prendi.$"

PalletTown_RivalsHouse_Text_DontLikeWayItGlaresAtYou::
	.string "{PLAYER}, non mi piace come ti\n"
	.string "guarda male.\p"
	.string "Potresti provare a essere un po' più\n"
	.string "gentile con lui?$"

PalletTown_RivalsHouse_Text_WhyWouldMonHateYouSoMuch::
	.string "Ehm, non è facile per me\n"
	.string "dirtelo, ma…\p"
	.string "C'è un motivo per cui il tuo\n"
	.string "POKéMON ti odia così tanto?$"

PalletTown_RivalsHouse_Text_LovelyAndSweetClefairy::
	.string "“La dolce e adorabile\n"
	.string "CLEFAIRY”$"

