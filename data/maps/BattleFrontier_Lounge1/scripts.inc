BattleFrontier_Lounge1_MapScripts::
	.byte 0

@ NPC that rates pokemon based on their IVs
BattleFrontier_Lounge1_EventScript_Breeder::
	lock
	faceplayer
	call_if_unset FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_BreederIntro
	call_if_set FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder
	setflag FLAG_MET_BATTLE_FRONTIER_BREEDER
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder::
	chooseboxmon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_ShowMonToBreeder
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_CancelMonSelect
	end

BattleFrontier_Lounge1_EventScript_BreederIntro::
	msgbox BattleFrontier_Lounge1_Text_PokemonBreederIntro, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder::
	msgbox BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon, MSGBOX_DEFAULT
	return

@ BufferVarsForIVRater buffers the following values
@ VAR_0x8005: Sum of the mons IVs
@ VAR_0x8006: Stat id of highest IV stat
@ VAR_0x8007: IV of the highest IV stat
BattleFrontier_Lounge1_EventScript_ShowMonToBreeder::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge1_EventScript_ShowEggToBreeder
	special BufferVarsForIVRater
	goto_if_le VAR_0x8005, 90, BattleFrontier_Lounge1_EventScript_AverageTotalIVs       @ Average of 15
	goto_if_le VAR_0x8005, 120, BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs @ Average of 20
	goto_if_le VAR_0x8005, 150, BattleFrontier_Lounge1_EventScript_HighTotalIVs         @ Average of 25
	goto_if_ge VAR_0x8005, 151, BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs     @ Average of > 25
	end

BattleFrontier_Lounge1_EventScript_ShowEggToBreeder::
	msgbox BattleFrontier_Lounge1_Text_EvenICantTell, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

@ Comment on the highest IV stat
BattleFrontier_Lounge1_EventScript_HighestIVStat::
	goto_if_eq VAR_0x8006, STAT_HP, BattleFrontier_Lounge1_EventScript_HighestIVHP
	goto_if_eq VAR_0x8006, STAT_ATK, BattleFrontier_Lounge1_EventScript_HighestIVAtk
	goto_if_eq VAR_0x8006, STAT_DEF, BattleFrontier_Lounge1_EventScript_HighestIVDef
	goto_if_eq VAR_0x8006, STAT_SPEED, BattleFrontier_Lounge1_EventScript_HighestIVSpeed
	goto_if_eq VAR_0x8006, STAT_SPATK, BattleFrontier_Lounge1_EventScript_HighestIVSpAtk
	goto_if_eq VAR_0x8006, STAT_SPDEF, BattleFrontier_Lounge1_EventScript_HighestIVSpDef
	end

@ Comment on the highest IV value
BattleFrontier_Lounge1_EventScript_HighestIVValue::
	goto_if_le VAR_0x8007, 15, BattleFrontier_Lounge1_EventScript_HighestIVLow
	goto_if_le VAR_0x8007, 25, BattleFrontier_Lounge1_EventScript_HighestIVMid
	goto_if_le VAR_0x8007, 30, BattleFrontier_Lounge1_EventScript_HighestIVHigh
	goto_if_ge VAR_0x8007, 31, BattleFrontier_Lounge1_EventScript_HighestIVMax
	end

BattleFrontier_Lounge1_EventScript_EndBreederComments::
	release
	end

BattleFrontier_Lounge1_EventScript_AverageTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_AverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_BetterThanAverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_ImpressiveAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_OutstandingAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighestIVHP::
	msgbox BattleFrontier_Lounge1_Text_BestAspectHP, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVAtk::
	msgbox BattleFrontier_Lounge1_Text_BestAspectAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVDef::
	msgbox BattleFrontier_Lounge1_Text_BestAspectDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpeed::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpeed, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpAtk::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpDef::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVLow::
	msgbox BattleFrontier_Lounge1_Text_StatRelativelyGood, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMid::
	msgbox BattleFrontier_Lounge1_Text_StatImpressive, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVHigh::
	msgbox BattleFrontier_Lounge1_Text_StatOutstanding, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMax::
	msgbox BattleFrontier_Lounge1_Text_StatFlawless, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_CancelMonSelect::
	msgbox BattleFrontier_Lounge1_Text_NoTimeForMyAdvice, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge1_EventScript_Boy1::
	msgbox BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding, MSGBOX_NPC
	end

BattleFrontier_Lounge1_EventScript_Boy2::
	msgbox BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt, MSGBOX_NPC
	end

BattleFrontier_Lounge1_Text_PokemonBreederIntro:
	.string "Allevio POKéMON da 70 anni!\n"
	.string "Sono colui che tutti chiamano\l"
	.string "il leggendario miglior ALLEVATORE!\p"
	.string "Quando sarai esperto come me,\n"
	.string "vedrai le qualità dei POKéMON\l"
	.string "a colpo d'occhio.\p"
	.string "Sei un ALLENATORE. Non ti\n"
	.string "interessa conoscere le qualità\l"
	.string "dei tuoi POKéMON?\p"
	.string "Ecco!\n"
	.string "Ti mostro i tuoi POKéMON!$"

BattleFrontier_Lounge1_Text_AverageAbility:
	.string "…Mah…\p"
	.string "Questo, nel complesso,\n"
	.string "è di abilità nella media.$"

BattleFrontier_Lounge1_Text_BetterThanAverageAbility:
	.string "…Mah…\p"
	.string "Questo, nel complesso,\n"
	.string "è sopra la media.$"

BattleFrontier_Lounge1_Text_ImpressiveAbility:
	.string "…Mah…\p"
	.string "Questo, nel complesso,\n"
	.string "è notevole!$"

BattleFrontier_Lounge1_Text_OutstandingAbility:
	.string "…Mah…\p"
	.string "Questo, nel complesso,\n"
	.string "è fuori dal comune!$"

BattleFrontier_Lounge1_Text_BestAspectHP:
	.string "Peraltro, il suo punto\n"
	.string "migliore sono i PS…$"

BattleFrontier_Lounge1_Text_BestAspectAtk:
	.string "Peraltro, il suo punto\n"
	.string "migliore è l'ATTACCO…$"

BattleFrontier_Lounge1_Text_BestAspectDef:
	.string "Peraltro, il suo punto\n"
	.string "migliore è la DIFESA…$"

BattleFrontier_Lounge1_Text_BestAspectSpAtk:
	.string "Peraltro, il suo punto\n"
	.string "migliore è l'ATTACCO SPEC…$"

BattleFrontier_Lounge1_Text_BestAspectSpDef:
	.string "Peraltro, il suo punto\n"
	.string "migliore è la DIFESA SPEC…$"

BattleFrontier_Lounge1_Text_BestAspectSpeed:
	.string "Peraltro, il suo punto\n"
	.string "migliore è la VELOCITÀ…$"

BattleFrontier_Lounge1_Text_StatRelativelyGood:
	.string "Quel valore è abbastanza buono.\n"
	.string "…Eh… Così lo chiamo io.$"

BattleFrontier_Lounge1_Text_StatImpressive:
	.string "Quella statistica è notevole.\n"
	.string "…Hm… Così lo chiamo io.$"

BattleFrontier_Lounge1_Text_StatOutstanding:
	.string "Quella statistica è eccezionale!\n"
	.string "…Hm… Così lo chiamo io.$"

BattleFrontier_Lounge1_Text_StatFlawless:
	.string "È perfetto, impeccabile!\n"
	.string "…Hm… Così lo chiamo io.$"

BattleFrontier_Lounge1_Text_NoTimeForMyAdvice:
	.string "Cosa?\n"
	.string "Niente tempo per i miei consigli?\p"
	.string "Dovresti imparare sempre\n"
	.string "dagli anziani!$"

@ Unused
BattleFrontier_Lounge1_Text_HaveBusinessNeedsTending:
	.string "Sì, che c'è?\p"
	.string "Ho affari che aspettano!\n"
	.string "Rimandiamo alla prossima!$"

BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon:
	.string "Ah, giovane! Ti incuriosiscono\n"
	.string "le qualità dei tuoi POKéMON?\p"
	.string "Dai, dai!\n"
	.string "Ti mostro i tuoi POKéMON!$"

BattleFrontier_Lounge1_Text_EvenICantTell:
	.string "Sono un esperto, ma di un\n"
	.string "UOVO non capisco nulla!\p"
	.string "Mostrami un POKéMON!\n"
	.string "Mi serve vedere un POKéMON!$"

BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding:
	.string "Ha detto che è eccezionale!\n"
	.string "L'ho allevato con cura, evvai!$"

BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt:
	.string "Ha detto che è eccezionale!\n"
	.string "Ma non ho fatto nulla\l"
	.string "di speciale…$"

