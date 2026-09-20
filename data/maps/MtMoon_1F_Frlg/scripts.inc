MtMoon_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMoon_1F_OnTransition
	.byte 0

MtMoon_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_MT_MOON_1F
	end

MtMoon_1F_EventScript_ZubatSign::
	msgbox MtMoon_1F_Text_ZubatIsABloodsucker, MSGBOX_SIGN
	end

MtMoon_1F_EventScript_Marcos::
	trainerbattle_single TRAINER_HIKER_MARCOS, MtMoon_1F_Text_MarcosIntro, MtMoon_1F_Text_MarcosDefeat
	msgbox MtMoon_1F_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Josh::
	trainerbattle_single TRAINER_YOUNGSTER_JOSH, MtMoon_1F_Text_JoshIntro, MtMoon_1F_Text_JoshDefeat
	msgbox MtMoon_1F_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Miriam::
	trainerbattle_single TRAINER_LASS_MIRIAM, MtMoon_1F_Text_MiriamIntro, MtMoon_1F_Text_MiriamDefeat
	msgbox MtMoon_1F_Text_MiriamPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Iris::
	trainerbattle_single TRAINER_LASS_IRIS, MtMoon_1F_Text_IrisIntro, MtMoon_1F_Text_IrisDefeat
	msgbox MtMoon_1F_Text_IrisPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Jovan::
	trainerbattle_single TRAINER_SUPER_NERD_JOVAN, MtMoon_1F_Text_JovanIntro, MtMoon_1F_Text_JovanDefeat
	msgbox MtMoon_1F_Text_JovanPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Kent::
	trainerbattle_single TRAINER_BUG_CATCHER_KENT, MtMoon_1F_Text_KentIntro, MtMoon_1F_Text_KentDefeat
	msgbox MtMoon_1F_Text_KentPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Robby::
	trainerbattle_single TRAINER_BUG_CATCHER_ROBBY, MtMoon_1F_Text_RobbyIntro, MtMoon_1F_Text_RobbyDefeat
	msgbox MtMoon_1F_Text_RobbyPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_Text_MarcosIntro::
	.string "WHOA!\n"
	.string "Mi hai spaventato!\l"
	.string "…Oh, sei solo un bambino!$"

MtMoon_1F_Text_MarcosDefeat::
	.string "Wow!\n"
	.string "Shock di nuovo!$"

MtMoon_1F_Text_MarcosPostBattle::
	.string "I bambini come te non dovrebbero\n"
	.string "gironzolare qui al buio.$"

MtMoon_1F_Text_JoshIntro::
	.string "Sei qui per esplorare la Grotta\n"
	.string "anche tu?$"

MtMoon_1F_Text_JoshDefeat::
	.string "Perdere fa schifo!\n"
	.string "Che figuraccia.$"

MtMoon_1F_Text_JoshPostBattle::
	.string "Sono sceso fin qui per\n"
	.string "farmi vedere dalle ragazze.$"

MtMoon_1F_Text_MiriamIntro::
	.string "Wow! È molto più grande di\n"
	.string "quanto pensassi!$"

MtMoon_1F_Text_MiriamDefeat::
	.string "Oh!\n"
	.string "Ho perso!$"

MtMoon_1F_Text_MiriamPostBattle::
	.string "Come si esce da qui?\n"
	.string "È così grande, mi perderò.$"

MtMoon_1F_Text_JovanIntro::
	.string "Cosa!\n"
	.string "Non sbucarmi alle spalle!$"

MtMoon_1F_Text_JovanDefeat::
	.string "I miei POKéMON non bastano!$"

MtMoon_1F_Text_JovanPostBattle::
	.string "Devo trovare POKéMON più forti.\n"
	.string "Dove saranno?$"

MtMoon_1F_Text_IrisIntro::
	.string "Cosa?\n"
	.string "Aspetto che i miei amici mi\l"
	.string "trovino qui.$"

MtMoon_1F_Text_IrisDefeat::
	.string "Ho perso?$"

MtMoon_1F_Text_IrisPostBattle::
	.string "Sono venuta perché ho sentito\n"
	.string "che qui ci sono fossili rari.$"

MtMoon_1F_Text_KentIntro::
	.string "Ci sono tipi sospetti nella Grotta.\n"
	.string "E tu?$"

MtMoon_1F_Text_KentDefeat::
	.string "Mi hai battuto!$"

MtMoon_1F_Text_KentPostBattle::
	.string "Li ho visti!\n"
	.string "Sono del TEAM ROCKET, ne sono certo!$"

MtMoon_1F_Text_RobbyIntro::
	.string "Devi attraversare questa Grotta\n"
	.string "per arrivare a CELESTOPOLI.$"

MtMoon_1F_Text_RobbyDefeat::
	.string "Ho perso.$"

MtMoon_1F_Text_RobbyPostBattle::
	.string "Zubat è tosto!\n"
	.string "Ma se ne catturi uno, potrai\l"
	.string "contare su di lui.$"

MtMoon_1F_Text_ZubatIsABloodsucker::
	.string "Attento!\n"
	.string "Zubat succhia il sangue!$"

MtMoon_1F_Text_BrockHelpsExcavateFossils::
	.string "Ciao, sto scavando fossili qui\n"
	.string "sotto il MONTE LUNA.\p"
	.string "A volte BROCK della PEWTER GYM\n"
	.string "mi dà una mano.$"
