Route20_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route20_OnTransition
	.byte 0

Route20_OnTransition::
	call_if_unset FLAG_STOPPED_SEAFOAM_B3F_CURRENT, Route20_EventScript_ResetSeafoamBouldersForB3F
	call_if_unset FLAG_STOPPED_SEAFOAM_B4F_CURRENT, Route20_EventScript_ResetSeafoamBouldersForB4F
	end

Route20_EventScript_ResetSeafoamBouldersForB3F::
	clearflag FLAG_HIDE_SEAFOAM_1F_BOULDER_1
	clearflag FLAG_HIDE_SEAFOAM_1F_BOULDER_2
	setflag FLAG_HIDE_SEAFOAM_B1F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B1F_BOULDER_2
	setflag FLAG_HIDE_SEAFOAM_B2F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B2F_BOULDER_2
	setflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_2
	return

Route20_EventScript_ResetSeafoamBouldersForB4F::
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_3
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_4
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_5
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_6
	setflag FLAG_HIDE_SEAFOAM_B4F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B4F_BOULDER_2
	return

Route20_EventScript_SeafoamIslandsSign::
	msgbox Route20_Text_SeafoamIslands, MSGBOX_SIGN
	end

Route20_Text_BarryIntro::
	.string "Qui l'acqua è bassa.\n"
	.string "C'è un sacco di gente che nuota.$"

Route20_Text_BarryDefeat::
	.string "Splash$"

Route20_Text_BarryPostBattle::
	.string "Vorrei cavalcare il mio POKéMON.\n"
	.string "Scommetto che tu non sei stanco.$"

Route20_Text_ShirleyIntro::
	.string "SEAFOAM è un posto tranquillo.\n"
	.string "Sono qui in vacanza.$"

Route20_Text_ShirleyDefeat::
	.string "Smettila!$"

Route20_Text_ShirleyPostBattle::
	.string "Sotto quest'isola c'è una\n"
	.string "caverna enorme.$"

Route20_Text_TiffanyIntro::
	.string "Adoro fluttuare tra i pesci,\n"
	.string "qui tra le onde.$"

Route20_Text_TiffanyDefeat::
	.string "Ahia!$"

Route20_Text_TiffanyPostBattle::
	.string "Vuoi fluttuare con me?$"

Route20_Text_IreneIntro::
	.string "Anche tu in vacanza?$"

Route20_Text_IreneDefeat::
	.string "Nessuna pietà, eh!$"

Route20_Text_IrenePostBattle::
	.string "Tanto tempo fa SEAFOAM\n"
	.string "era un'unica isola.$"

Route20_Text_DeanIntro::
	.string "Guarda che muscoli scolpiti!$"

Route20_Text_DeanDefeat::
	.string "Che pippa!$"

Route20_Text_DeanPostBattle::
	.string "Dovevo allenare i miei\n"
	.string "POKéMON, non me stesso!$"

Route20_Text_DarrinIntro::
	.string "Perché cavalchi un POKéMON?\n"
	.string "Non sai nuotare?$"

Route20_Text_DarrinDefeat::
	.string "Ahi!\n"
	.string "Silurato!$"

Route20_Text_DarrinPostBattle::
	.string "Cavalcando un POKéMON ci si diverte!$"

Route20_Text_RogerIntro::
	.string "Sono arrivato qui in volo.$"

Route20_Text_RogerDefeat::
	.string "Oh, no!\n"
	.string "E adesso che faccio?$"

Route20_Text_RogerPostBattle::
	.string "I miei uccelli sono esausti.\n"
	.string "Non possono portarmi via in VOLO!$"

Route20_Text_NoraIntro::
	.string "Il mio ragazzo mi ha dato perle giganti.$"

Route20_Text_NoraDefeat::
	.string "Oh, no!\n"
	.string "Dentro c'erano le mie perle!$"

Route20_Text_NoraPostBattle::
	.string "Le mie perle diventeranno più\n"
	.string "grosse dentro CLOYSTER?$"

Route20_Text_MissyIntro::
	.string "Ho nuotato fin qui da CINNABAR.\n"
	.string "Non è stato facile, sai.$"

Route20_Text_MissyDefeat::
	.string "Che delusione!$"

Route20_Text_MissyPostBattle::
	.string "I POKéMON hanno occupato una\n"
	.string "villa abbandonata a CINNABAR.\p"
	.string "La chiamano VILLA POKéMON\n"
	.string "ormai.$"

Route20_Text_MelissaIntro::
	.string "A ovest, a CINNABAR c'è un LAB\n"
	.string "per i POKéMON.\p"
	.string "Ci lavora il mio papà.$"

Route20_Text_MelissaDefeat::
	.string "Aspetta!\n"
	.string "Dovevi aspettare!$"

Route20_Text_MelissaPostBattle::
	.string "CINNABAR è un'isola vulcanica.\p"
	.string "Ho sentito che emerse dal mare\n"
	.string "quando eruttò un vulcano.$"

Route20_Text_SeafoamIslands::
	.string "ISOLE SEAFOAM$"

Route20_Text_MistyTrainsHere::
	.string "Qui si vedono spesso ALLENATORI\n"
	.string "forti e POKéMON ACQUA.\p"
	.string "Dicono che MISTY della\n"
	.string "PALESTRA di CERULEAN si allena qui.$"
