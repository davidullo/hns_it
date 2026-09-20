Route41_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route41_MapScript_OnTransition
	.byte 0

Route41_MapScript_OnTransition::
	goto_if_eq VAR_COMPLETED_LUGIA, 4, Route41_MapScript_DoNothing
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, OlivineCity_MapScript_ClearWeather
	end

Route41_MapScript_DoNothing::
	end

Route41_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE_HNS, Route41_Text_SwimmermCharlieSeen, Route41_Text_SwimmermCharlieBeaten
	msgbox Route41_Text_SwimmermCharlieAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermCharlieSeen:
	.string "L'acqua qui è calda.\n"
	.string "Sono sciolto e agile.\p"
	.string "Certo, ti sfido!$"

Route41_Text_SwimmermCharlieBeaten:
	.string "Ahia! Ho la pelle raggrinzita!$"

Route41_Text_SwimmermCharlieAfter:
	.string "Non è rilassante stare\n"
	.string "così a galla?$"

Route41_EventScript_George::
	trainerbattle_single TRAINER_GEORGE_HNS, Route41_Text_SwimmermGeorgeSeen, Route41_Text_SwimmermGeorgeBeaten
	msgbox Route41_Text_SwimmermGeorgeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermGeorgeSeen:
	.string "Sono un po' stanco.\n"
	.string "Se vinco, prestami un POKéMON.$"

Route41_Text_SwimmermGeorgeBeaten:
	.string "Pant, pant…$"

Route41_Text_SwimmermGeorgeAfter:
	.string "FIORLISOPRA è così lontana.\p"
	.string "Ma neanche tornare\n"
	.string "a OLIVINPOLI è facile.\p"
	.string "Che faccio?$"

Route41_EventScript_Berke::
	trainerbattle_single TRAINER_BERKE_HNS, Route41_Text_SwimmermBerkeSeen, Route41_Text_SwimmermBerkeBeaten
	msgbox Route41_Text_SwimmermBerkeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermBerkeSeen:
	.string "Vedi quelle isole\n"
	.string "bloccate dai vortici?\p"
	.string "Nascondono di sicuro un segreto!$"

Route41_Text_SwimmermBerkeBeaten:
	.string "Qual è il segreto della tua\n"
	.string "forza?$"

Route41_Text_SwimmermBerkeAfter:
	.string "It was a dark and stormy night…\p"
	.string "I saw this giant POKéMON flying\n"
	.string "from the islands.\p"
	.string "It was scattering feathers\n"
	.string "from its silver wings.$"

Route41_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK_HNS, Route41_Text_SwimmermKirkSeen, Route41_Text_SwimmermKirkBeaten
	msgbox Route41_Text_SwimmermKirkAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermKirkSeen:
	.string "Le onde qui sono agitate.\p"
	.string "Ti stancano mentre\n"
	.string "nuoti.$"

Route41_Text_SwimmermKirkBeaten:
	.string "Sono a terra!$"

Route41_Text_SwimmermKirkAfter:
	.string "Le correnti mi impediscono\n"
	.string "di raggiungere quell'isola.$"

Route41_EventScript_Mathew::
	trainerbattle_single TRAINER_MATHEW_HNS, Route41_Text_SwimmermMathewSeen, Route41_Text_SwimmermMathewBeaten
	msgbox Route41_Text_SwimmermMathewAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermMathewSeen:
	.string "Cerchi i segreti\n"
	.string "delle ISOLE VORTICE?$"

Route41_Text_SwimmermMathewBeaten:
	.string "Ooh, che resistenza!$"

Route41_Text_SwimmermMathewAfter:
	.string "Un segreto sulle ISOLE VORTICE…\p"
	.string "Dentro è buio pesto!$"

Route41_EventScript_Kaylee::
	trainerbattle_single TRAINER_KAYLEE_HNS, Route41_Text_SwimmerfKayleeSeen, Route41_Text_SwimmerfKayleeBeaten
	msgbox Route41_Text_SwimmerfKayleeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfKayleeSeen:
	.string "Vado alle ISOLE VORTICE.\p"
	.string "Vado a esplorare con gli amici.$"

Route41_Text_SwimmerfKayleeBeaten:
	.string "Is that how you do it?$"

Route41_Text_SwimmerfKayleeAfter:
	.string "Dicono che ci sia un grosso\n"
	.string "POKéMON sotto le ISOLE VORTICE.\p"
	.string "Chissà quale sarà?$"

Route41_EventScript_Susie::
	trainerbattle_single TRAINER_SUSIE_HNS, Route41_Text_SwimmerfSusieSeen, Route41_Text_SwimmerfSusieBeaten
	msgbox Route41_Text_SwimmerfSusieAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfSusieSeen:
	.string "Sei così elegante,\n"
	.string "sul tuo POKéMON.$"

Route41_Text_SwimmerfSusieBeaten:
	.string "Sono a pezzi…$"

Route41_Text_SwimmerfSusieAfter:
	.string "Non c'era una canzone famosa\n"
	.string "su un ragazzo su LAPRAS?$"

Route41_EventScript_Denise::
	trainerbattle_single TRAINER_DENISE_HNS, Route41_Text_SwimmerfDeniseSeen, Route41_Text_SwimmerfDeniseBeaten
	msgbox Route41_Text_SwimmerfDeniseAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfDeniseSeen:
	.string "Il meteo è stupendo,\n"
	.string "sono in estasi!$"

Route41_Text_SwimmerfDeniseBeaten:
	.string "Oooh!$"

Route41_Text_SwimmerfDeniseAfter:
	.string "Le scottature rovinano la pelle.\p"
	.string "Ma io non uso creme solari.\p"
	.string "Non voglio inquinare l'acqua.$"

Route41_EventScript_Kara::
	trainerbattle_single TRAINER_KARA_HNS, Route41_Text_SwimmerfKaraSeen, Route41_Text_SwimmerfKaraBeaten
	msgbox Route41_Text_SwimmerfKaraAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfKaraSeen:
	.string "Se devi riposare,\n"
	.string "fai il morto.\p"
	.string "Recuperi il fiato,\n"
	.string "e poi riparti alla grande.$"

Route41_Text_SwimmerfKaraBeaten:
	.string "Oh! Hai più energia di me.$"

Route41_Text_SwimmerfKaraAfter:
	.string "Ho sentito dei ruggiti\n"
	.string "dalle ISOLE.$"

Route41_EventScript_Wendy::
	trainerbattle_single TRAINER_WENDY_HNS, Route41_Text_SwimmerfWendySeen, Route41_Text_SwimmerfWendyBeaten
	msgbox Route41_Text_SwimmerfWendyAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfWendySeen:
	.string "Di notte, gli STARYU si radunano\n"
	.string "in superficie.$"

Route41_Text_SwimmerfWendyBeaten:
	.string "Oh, no…$"

Route41_Text_SwimmerfWendyAfter:
	.string "I gruppi di STARYU si illuminano\n"
	.string "tutti insieme.\p"
	.string "È bellissimo, fa paura.$"

Route41_EventScript_Tentacruel1::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_0, 2, Route41_EventScript_TentacruelAttack1
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_0, 1
	release
	end
Route41_EventScript_TentacruelAttack1::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_SHINY
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_0, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel2::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_1, 2, Route41_EventScript_TentacruelAttack2
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_1, 1
	release
	end
Route41_EventScript_TentacruelAttack2::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel3::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_2, 2, Route41_EventScript_TentacruelAttack3
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_2, 1
	release
	end
Route41_EventScript_TentacruelAttack3::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_3, 2, Route41_EventScript_TentacruelAttack4
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_3, 1
	release
	end
Route41_EventScript_TentacruelAttack4::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_3, 0
	closemessage
	release
	end

Route41_Text_Tentacruel:
	.string "TENTACRUEL: Cruooo...$"

Route41_Text_TentacruelAttack:
	.string "TENTACRUEL: CRUOOOOOO!$"

Route41_Text_TentacruelHeal:
	.string "Il TENTACRUEL ha usato RIPRESA!\n"
	.string "È guarito del tutto!$"
