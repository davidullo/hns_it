Route26_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route26_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route26_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route26_EventScript_Jake::
	trainerbattle_single TRAINER_JAKE_HNS, Route26_Text_CooltrainermJakeSeen, Route26_Text_CooltrainermJakeBeaten
	msgbox Route26_Text_CooltrainermJakeAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Gaven::
	trainerbattle_single TRAINER_GAVEN_HNS, Route26_Text_CooltrainermGavenSeen, Route26_Text_CooltrainermGavenBeaten, Route26_EventScript_RegisterGaven
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route26_EventScript_RematchGaven
	msgbox Route26_Text_CooltrainermGavenAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_RegisterGaven::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route26_Text_GavenRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GAVEN_HNS
	release
	end

Route26_EventScript_RematchGaven::
	trainerbattle_rematch TRAINER_GAVEN_HNS, Route26_Text_GavenRematchIntro, Route26_Text_GavenRematchDefeat
	msgbox Route26_Text_GavenPostRematch, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Joyce::
	trainerbattle_single TRAINER_JOYCE_HNS, Route26_Text_CooltrainerfJoyceSeen, Route26_Text_CooltrainerfJoyceBeaten
	msgbox Route26_Text_CooltrainerfJoyceAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Beth::
	trainerbattle_single TRAINER_BETH_HNS, Route26_Text_CooltrainerfBethSeen, Route26_Text_CooltrainerfBethBeaten, Route26_EventScript_RegisterBeth
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route26_EventScript_RematchBeth
	msgbox Route26_Text_CooltrainerfBethAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_RegisterBeth::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route26_Text_BethRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BETH_HNS
	release
	end

Route26_EventScript_RematchBeth::
	trainerbattle_rematch TRAINER_BETH_HNS, Route26_Text_BethRematchIntro, Route26_Text_BethRematchDefeat
	msgbox Route26_Text_BethPostRematch, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Richard::
	trainerbattle_single TRAINER_RICHARD_HNS, Route26_Text_PsychicRichardSeen, Route26_Text_PsychicRichardBeaten
	msgbox Route26_Text_PsychicRichardAfter, MSGBOX_AUTOCLOSE
	end

Route26_Text_CooltrainermJakeSeen:
    .string "Sto facendo gli ultimi preparativi\n"
    .string "per la LEGA POKéMON.$"

Route26_Text_CooltrainermJakeBeaten:
    .string "Ho fatto un pasticcio!$"

Route26_Text_CooltrainermJakeAfter:
    .string "It's going to be tough to win at\n"
    .string "the LEAGUE.\p"
    .string "I need to do some more training.\p"
    .string "I hear that the LEAGUE's ELITE\n"
    .string "FOUR are tougher than GYM LEADERS.$"

Route26_Text_CooltrainermGavenSeen:
    .string "Affrontando lotte dure,\n"
    .string "si guadagna forza.$"

Route26_Text_CooltrainermGavenBeaten:
    .string "Ahh! La vita è ancora più dura!$"

Route26_Text_CooltrainermGavenAfter:
    .string "Per arrivare alla LEGA POKéMON devi\n"
    .string "passare per la STRADA VITTORIA.\p"
    .string "Ma la STRADA VITTORIA è dura.\p"
    .string "Praticamente nessuno ci va!$"

Route26_Text_GavenRegister:
    .string "Per arrivare alla LEGA POKéMON devi\n"
    .string "passare per la STRADA VITTORIA.\p"
    .string "Ma la STRADA VITTORIA è dura.\p"
    .string "Praticamente nessuno ci va!$"

Route26_Text_GavenRematchIntro:
    .string "Affrontando lotte dure,\n"
    .string "si guadagna forza.$"

Route26_Text_GavenRematchDefeat:
    .string "Ahh! La vita è ancora più dura!$"

Route26_Text_GavenPostRematch:
    .string "Per arrivare alla LEGA POKéMON devi\n"
    .string "passare per la STRADA VITTORIA.\p"
    .string "Ma la STRADA VITTORIA è dura.\p"
    .string "Praticamente nessuno ci va!$"

Route26_Text_CooltrainerfJoyceSeen:
    .string "Se sei arrivato fin qui,\n"
    .string "devi essere forte.\p"
    .string "In questa lotta darò\n"
    .string "tutto me stessa!$"

Route26_Text_CooltrainerfJoyceBeaten:
    .string "No! Non ci credo!$"

Route26_Text_CooltrainerfJoyceAfter:
    .string "Ho battuto otto CAPOPALESTRA,\n"
    .string "quindi ero sicura di me.\p"
    .string "La prossima volta mi impegnerò di più.$"

Route26_Text_CooltrainerfBethSeen:
    .string "Ho perso contro un allenatore di nome {RIVAL}.\p"
    .string "Era davvero forte, ma…\p"
    .string "Era come se dovesse vincere a\n"
    .string "tutti i costi.\p"
    .string "Mi ha fatto pena il suo POKéMON.$"

Route26_Text_CooltrainerfBethBeaten:
    .string "I POKéMON non sono armi.$"

Route26_Text_CooltrainerfBethAfter:
    .string "I POKéMON sono compagni\n"
    .string "preziosi per tutta la vita.$"

Route26_Text_BethRegister:
    .string "I POKéMON sono compagni\n"
    .string "preziosi per tutta la vita.$"

Route26_Text_BethRematchIntro:
    .string "Ho perso contro un allenatore di nome {RIVAL}.\p"
    .string "Ma contro di te non perderò!$"

Route26_Text_BethRematchDefeat:
    .string "I POKéMON non sono armi.$"

Route26_Text_BethPostRematch:
    .string "I POKéMON sono compagni\n"
    .string "preziosi per tutta la vita.$"

Route26_Text_PsychicRichardSeen:
    .string "Wow, look at all those BADGES!\n"
    .string "I'm impressed.\p"
    .string "But you're not satisfied by just\n"
    .string "collecting them, right?$"

Route26_Text_PsychicRichardBeaten:
    .string "Bella lotta!$"

Route26_Text_PsychicRichardAfter:
    .string "Persone e POKéMON crescono con le\n"
    .string "esperienze.\p"
    .string "Non diventare pigro e svogliato.$"

Route26_Text_Sign:
    .string "PERCORSO 26\p"
    .string "LEGA POKéMON\n"
    .string "INGRESSO$"

