GoldenrodCity_RadioTower_2F_hns_MapScripts::
	.byte 0

GoldenrodRaidoTower2_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_3_HNS, GoldenrodCity_RadioTower_2F_Text_GruntM4Seen, GoldenrodCity_RadioTower_2F_Text_GruntM4Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntM4After, MSGBOX_AUTOCLOSE
	end
GoldenrodRaidoTower2_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_4_HNS, GoldenrodCity_RadioTower_2F_Text_GruntM5Seen, GoldenrodCity_RadioTower_2F_Text_GruntM5Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntM5After, MSGBOX_AUTOCLOSE
	end
GoldenrodRaidoTower2_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_5_HNS, GoldenrodCity_RadioTower_2F_Text_GruntM6Seen, GoldenrodCity_RadioTower_2F_Text_GruntM6Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntM6After, MSGBOX_AUTOCLOSE
	end
GoldenrodRaidoTower2_EventScript_GruntF2::
	trainerbattle_single TRAINER_GRUNT_26_HNS, GoldenrodCity_RadioTower_2F_Text_GruntF2Seen, GoldenrodCity_RadioTower_2F_Text_GruntF2Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntF2After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_RadioTower_2F_EventScript_Sign1::
	lock
	msgbox GoldenrodCity_RadioTower_2F_Text_SalesSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Sign2::
	lock
	msgbox GoldenrodCity_RadioTower_2F_Text_OakTalkSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Boy::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_2F_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Policeman::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_2F_Text_Policeman, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Buena::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 7, GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 8, GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 9, GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket
	goto_if_set FLAG_DAILY_BUENAS_PASSWORD_GUESSED, GoldenrodCity_RadioTower_2F_EventScript_BuenaAlreadyPlayed
	goto_if_unset FLAG_DAILY_BUENAS_PASSWORD, GoldenrodCity_RadioTower_2F_EventScript_BuenaNoShow
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaAskPassword, MSGBOX_DEFAULT
	special Special_BuenaPasswordShowMultichoice
	waitstate
	compare VAR_RESULT, 127
	goto_if_eq GoldenrodCity_RadioTower_2F_EventScript_BuenaCancelled
	special Special_BuenaCheckAnswer
	compare VAR_RESULT, TRUE
	goto_if_eq GoldenrodCity_RadioTower_2F_EventScript_BuenaCorrect
	setflag FLAG_DAILY_BUENAS_PASSWORD_GUESSED
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaWrong, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaCorrect::
	special Special_BuenaRollReward
	copyvar VAR_0x8004, VAR_RESULT
	checkitemspace VAR_0x8004, 1
	compare VAR_RESULT, FALSE
	goto_if_eq GoldenrodCity_RadioTower_2F_EventScript_BuenaBagFull
	giveitem VAR_0x8004, 1
	setflag FLAG_DAILY_BUENAS_PASSWORD_GUESSED
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaCorrect, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaBagFull::
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaBagFull, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaCancelled::
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaComeBack, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaAlreadyPlayed::
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaAlreadyPlayed, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaNoShow::
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaShowPromo, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket::
	msgbox RadioTower2FBuenaPasswordIsHelpText, MSGBOX_DEFAULT
	closemessage
	release
	end


GoldenrodCity_RadioTower_2F_EventScript_Teacher::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_2F_EventScript_Teacher2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 7, GoldenrodCity_RadioTower_2F_EventScript_Teacher2 
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 8, GoldenrodCity_RadioTower_2F_EventScript_Teacher2 
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 9, GoldenrodCity_RadioTower_2F_EventScript_Teacher2 
	msgbox GoldenrodCity_RadioTower_2F_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Teacher2::
	msgbox GoldenrodCity_RadioTower_2F_Text_TeacherRockets, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Jigglypuff::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_JIGGLYPUFF, CRY_MODE_NORMAL
	msgbox GoldenrodCity_RadioTower_2F_Text_Jigglypuff, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RadioTower2FBuenaPasswordIsHelpText:
	.string "BUENA: Come? La parola d'oggi?\n"
	.string "HELP, ovvio!$"

GoldenrodCity_RadioTower_2F_Text_SuperNerd:
	.string "Puoi ascoltare la radio\n"
	.string "ovunque. Sintonizzati!$"

GoldenrodCity_RadioTower_2F_Text_Policeman:
	.string "Accesso vietato oltre questo\n"
	.string "punto.$"

GoldenrodCity_RadioTower_2F_Text_Teacher:
	.string "Le ninne nanne alla radio\n"
	.string "addormentano i POKéMON.$"

GoldenrodCity_RadioTower_2F_Text_TeacherRockets:
	.string "Perché mai vorranno prendere\n"
	.string "la TORRE RADIO?$"

GoldenrodCity_RadioTower_2F_Text_Jigglypuff:
	.string "JIGGLYPUFF: Jiggly…$"

GoldenrodCity_RadioTower_2F_Text_BlackBelt1:
	.string "Scusa. Solo il personale\n"
	.string "autorizzato oltre questo punto.\p"
	.string "Prima non era così.\p"
	.string "C'è qualcosa che non va nel\n"
	.string "DIRETTORE…$"

GoldenrodCity_RadioTower_2F_Text_BlackBelt2:
	.string "Guarda pure dove vuoi.\p"
	.string "Il DIRETTORE è di nuovo gentile,\n"
	.string "come prima.$"

GoldenrodCity_RadioTower_2F_Text_GruntM4Seen:
	.string "Tre anni fa il TEAM ROCKET è\n"
	.string "stato sciolto.\p"
	.string "Ma qui stiamo tornando!$"

GoldenrodCity_RadioTower_2F_Text_GruntM4Beaten:
	.string "Gwah! Non fare il furbo!$"

GoldenrodCity_RadioTower_2F_Text_GruntM4After:
	.string "Non ti lasceremo rovinare i\n"
	.string "piani per il ritorno!$"

GoldenrodCity_RadioTower_2F_Text_GruntM5Seen:
	.string "Siamo il TEAM ROCKET, che\n"
	.string "sfrutta i POKéMON!\p"
	.string "Amiamo il male! Paura?$"

GoldenrodCity_RadioTower_2F_Text_GruntM5Beaten:
	.string "Ti credi un eroe?$"

GoldenrodCity_RadioTower_2F_Text_GruntM5After:
	.string "Non siamo sempre cattivi.\n"
	.string "Facciamo ciò che ci va.$"

GoldenrodCity_RadioTower_2F_Text_GruntM6Seen:
	.string "Ehi, ehi! Sta' fuori dai piedi!$"

GoldenrodCity_RadioTower_2F_Text_GruntM6Beaten:
	.string "Arggh. Ci rinuncio.$"

GoldenrodCity_RadioTower_2F_Text_GruntM6After:
	.string "I nostri DIRIGENTI vogliono\n"
	.string "prendere il posto.\p"
	.string "Hanno un gran piano. Chissà\n"
	.string "quale sarà?$"

GoldenrodCity_RadioTower_2F_Text_GruntF2Seen:
	.string "Hahaha!\p"
	.string "Che noia. È stato fin troppo\n"
	.string "facile occupare il posto!\p"
	.string "Forza, fammi divertire!$"

GoldenrodCity_RadioTower_2F_Text_GruntF2Beaten:
	.string "Ch-chi sei?$"

GoldenrodCity_RadioTower_2F_Text_GruntF2After:
	.string "Mi hai battuto, e non lo\n"
	.string "dimentico!$"

GoldenrodCity_RadioTower_2F_Text_BuenaShowPromo:
	.string "BUENA: Ascolta il mio\n"
	.string "PASSWORD SHOW!\p"
	.string "La password di oggi\n"
	.string "è in onda!$"

GoldenrodCity_RadioTower_2F_Text_BuenaAskPassword:
	.string "BUENA: Ciao!\p"
	.string "Allora, sai la password\n"
	.string "di oggi?\p"
	.string "OK! Quale sarà?$"

GoldenrodCity_RadioTower_2F_Text_BuenaCorrect:
	.string "BUENA: Hai indovinato!\p"
	.string "Tieni, prendi {STR_VAR_1}\n"
	.string "come premio!$"

GoldenrodCity_RadioTower_2F_Text_BuenaWrong:
	.string "BUENA: Bzzt! Peccato!\p"
	.string "Riprova domani!$"

GoldenrodCity_RadioTower_2F_Text_BuenaComeBack:
	.string "BUENA: Non provi?\n"
	.string "Torna quando sei pronto!$"

GoldenrodCity_RadioTower_2F_Text_BuenaAlreadyPlayed:
	.string "BUENA: Hai già indovinato\n"
	.string "la password di oggi!\p"
	.string "Riascoltaci domani!$"

GoldenrodCity_RadioTower_2F_Text_BuenaBagFull:
	.string "BUENA: Hai indovinato, ma\n"
	.string "la BORSA è piena!\p"
	.string "Fai spazio e torna\n"
	.string "a parlarmi!$"

GoldenrodCity_RadioTower_2F_Text_SalesSign:
	.string "VENDITE 2P$"

GoldenrodCity_RadioTower_2F_Text_OakTalkSign:
	.string "POKéMON TALK DEL PROF.OAK\p"
	.string "Il programma più ascoltato!$"

GoldenrodCity_RadioTower_2F_Text_PokemonRadioSign:
	.string "POKéMON Radio ovunque, sempre$"
