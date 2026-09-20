RustboroCity_PokemonSchool_MapScripts::
	.byte 0

RustboroCity_PokemonSchool_EventScript_Blackboard::
	lockall
	msgbox RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic::
	message RustboroCity_PokemonSchool_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_PokemonSchool_EventScript_Poison
	case 1, RustboroCity_PokemonSchool_EventScript_Paralysis
	case 2, RustboroCity_PokemonSchool_EventScript_Sleep
	case 3, RustboroCity_PokemonSchool_EventScript_Burn
	case 4, RustboroCity_PokemonSchool_EventScript_Freeze
	case 5, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	case MULTI_B_PRESSED, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	end

RustboroCity_PokemonSchool_EventScript_Poison::
	msgbox RustboroCity_PokemonSchool_Text_ExplainPoison, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Paralysis::
	msgbox RustboroCity_PokemonSchool_Text_ExplainParalysis, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Sleep::
	msgbox RustboroCity_PokemonSchool_Text_ExplainSleep, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Burn::
	msgbox RustboroCity_PokemonSchool_Text_ExplainBurn, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Freeze::
	msgbox RustboroCity_PokemonSchool_Text_ExplainFreeze, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ExitTopicSelect::
	releaseall
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid1::
	msgbox RustboroCity_PokemonSchool_Text_TradingRightNow, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid2::
	msgbox RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_RichBoy::
	msgbox RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_Lass::
	msgbox RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_SchoolKidM::
	msgbox RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_StudentNotebook::
	msgbox RustboroCity_PokemonSchool_Text_StudentsNotes, MSGBOX_SIGN
	end

RustboroCity_PokemonSchool_EventScript_Teacher::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, RustboroCity_PokemonSchool_EventScript_GaveQuickClaw
	call_if_eq VAR_FACING, DIR_EAST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast
	call_if_eq VAR_FACING, DIR_WEST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest
	msgbox RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setflag FLAG_RECEIVED_QUICK_CLAW
	release
	end

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_GaveQuickClaw::
	msgbox RustboroCity_PokemonSchool_Text_ExplainQuickClaw, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	release
	end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	step_end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

RustboroCity_PokemonSchool_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE, RustboroCity_PokemonSchool_EventScript_ScottWatchStudents
	goto_if_set FLAG_MET_SCOTT_RUSTBORO, RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_RUSTBORO
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready::
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge::
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottWatchStudents::
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges:
	.string "La lavagna elenca i problemi di stato\n"
	.string "che possono colpire i POKéMON.$"

RustboroCity_PokemonSchool_Text_ReadWhichTopic:
	.string "Quale argomento vuoi leggere?$"

RustboroCity_PokemonSchool_Text_ExplainPoison:
	.string "Se un POKéMON è avvelenato,\n"
	.string "perde PS costantemente.\p"
	.string "Gli effetti del veleno restano\n"
	.string "dopo la lotta.\p"
	.string "I PS calano anche mentre\n"
	.string "si cammina.\p"
	.string "Curalo con un ANTIDOTO.$"

RustboroCity_PokemonSchool_Text_ExplainParalysis:
	.string "Se un POKéMON è paralizzato,\n"
	.string "la sua VELOCITÀ cala.\p"
	.string "E può anche non riuscire a muoversi\n"
	.string "durante la lotta.\p"
	.string "La paralisi resta dopo la lotta.\n"
	.string "Curala con un ANTIPARALISI.$"

RustboroCity_PokemonSchool_Text_ExplainSleep:
	.string "Se un POKéMON si addormenta, non\n"
	.string "può attaccare.\p"
	.string "Può svegliarsi da solo, ma se\n"
	.string "la lotta finisce mentre dorme,\l"
	.string "resterà addormentato.\p"
	.string "Sveglialo con una SVEGLIA.$"

RustboroCity_PokemonSchool_Text_ExplainBurn:
	.string "Una scottatura riduce l'ATTACCO e\n"
	.string "calano costantemente i PS.\p"
	.string "Resta anche dopo la lotta.\n"
	.string "Curala con un'ANTISCOTTATURA.$"

RustboroCity_PokemonSchool_Text_ExplainFreeze:
	.string "Se un POKéMON è congelato, diventa\n"
	.string "del tutto indifeso.\p"
	.string "Resta congelato dopo la lotta.\n"
	.string "Scongelalo con una SVEGLIA GELO.$"

RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw:
	.string "Gli studenti che non studiano\n"
	.string "assaggiano il mio RAPIDARTIGLIO.\p"
	.string "Se sei un bravo studente\n"
	.string "si capirà da come usi\l"
	.string "questo strumento.$"

RustboroCity_PokemonSchool_Text_ExplainQuickClaw:
	.string "Un POKéMON con la RAPIDARTIGLIO\n"
	.string "a volte si velocizza e agisce\l"
	.string "prima dell'avversario.\p"
	.string "Ci sono molti altri strumenti\n"
	.string "da far tenere ai POKéMON.\p"
	.string "Solo questi ti daranno molti\n"
	.string "argomenti da studiare!$"

RustboroCity_PokemonSchool_Text_TradingRightNow:
	.string "Sto scambiando POKéMON con un amico\n"
	.string "proprio ora.$"

RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot:
	.string "Ho sempre voluto uno SEEDOT, e\n"
	.string "finalmente ne avrò uno!$"

RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems:
	.string "I POKéMON possono tenere strumenti, ma\n"
	.string "non sanno usare quelli artificiali\l"
	.string "come POZIONE e ANTIDOTO.$"

RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself:
	.string "Sai che alcune mosse possono\n"
	.string "confondere un POKéMON?\p"
	.string "Un POKéMON confuso a volte\n"
	.string "si attacca da solo senza volere.\p"
	.string "Ma appena esce dalla lotta,\n"
	.string "torna normale.$"

RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry:
	.string "Un POKéMON con una BACCA si cura\n"
	.string "da solo…\p"
	.string "Ci sono molti tipi di strumenti\n"
	.string "che può tenere…\p"
	.string "Cavoli, è proprio difficile\n"
	.string "prendere appunti…$"

RustboroCity_PokemonSchool_Text_StudentsNotes:
	.string "È il quaderno di uno studente…\p"
	.string "I POKéMON si catturano con\n"
	.string "le POKé BALL.\p"
	.string "Fino a sei POKéMON possono\n"
	.string "accompagnare un ALLENATORE.\p"
	.string "Un ALLENATORE cattura i\n"
	.string "POKéMON, li alleva e lotta\l"
	.string "con loro.\p"
	.string "Il compito di un ALLENATORE è\n"
	.string "battere i forti ALLENATORI\l"
	.string "delle PALESTRE POKéMON.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut:
	.string "Ehi? Non ci siamo già visti?\n"
	.string "Mi pare a PETALBURG.\p"
	.string "Fammi presentare.\n"
	.string "Mi chiamo SCOTT.\p"
	.string "Ho girato ovunque in cerca\n"
	.string "di ALLENATORI eccezionali.\p"
	.string "Più precisamente, cerco\n"
	.string "esperti di lotte POKéMON.\p"
	.string "E tu cosa fai in questa SCUOLA?\n"
	.string "Anche tu sei un ALLENATORE?\p"
	.string "La prima cosa da fare è insegnare\n"
	.string "TAGLIO a un POKéMON.\p"
	.string "Se ricordo bene, qualcuno in\n"
	.string "questa città ha TAGLIO.$"

RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown:
	.string "SCOTT: Hmm…\p"
	.string "Il talento degli studenti qui\n"
	.string "è ignoto. Ma il potenziale c'è.$"

RustboroCity_PokemonSchool_Text_ScottStoneBadge:
	.string "SCOTT: Oh, cos'è quello?\p"
	.string "È una MEDAGLIA SASSO, vero?\n"
	.string "Notevole, direi.\p"
	.string "Ma sai, mi sarebbe piaciuto\n"
	.string "vederti in lotta.\p"
	.string "Difficile capire come sei\n"
	.string "da una MEDAGLIA della LEGA.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge:
	.string "Ciao? Ci siamo già visti?\n"
	.string "Mi pare a PETALBURG.\p"
	.string "Lascia che mi presenti.\n"
	.string "Mi chiamo SCOTT.\p"
	.string "Giro ovunque in cerca di\n"
	.string "ALLENATORI eccezionali.\p"
	.string "Più precisamente, cerco\n"
	.string "esperti di lotte POKéMON.\p"
	.string "Oh, cos'è quello?\n"
	.string "È una MEDAGLIA SASSO, vero?\p"
	.string "Notevole, direi, per un\n"
	.string "ALLENATORE alle prime armi.\p"
	.string "Ma sai, mi sarebbe piaciuto\n"
	.string "vederti in lotta.\p"
	.string "Difficile capire come sei\n"
	.string "da una MEDAGLIA della LEGA.$"

