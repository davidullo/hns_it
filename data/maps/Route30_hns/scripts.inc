Route30_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route30_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route30_OnFrame
	.byte 0

Route30_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route30_OnFrame::
	map_script_2 VAR_CHERRYGROVE_CITY_STATE, 2, Route30_EventScript_ElmCall_Trigger
	.2byte 0
	
Route30_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, Route30_EventScript_Boy2
	msgbox Route30_Text_YoungsterDirectionsToMrPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Boy2::
	lock
	faceplayer
	msgbox Route30_Text_YoungsterEveryoneIsBattling, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Girl::
	lock
	faceplayer
	msgbox Route30_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Youngster_Joey_Fighting::
	lock
	msgbox Route30_Text_UseTackle, 	MSGBOX_AUTOCLOSE
	waitmessage
	playse SE_PIN
	applymovement LOCALID_ROUTE_30_JOEY, Common_Movement_QuestionMark
	delay 55
	waitmovement LOCALID_ROUTE_30_JOEY
	faceplayer
	msgbox Route30_Text_ThisIsABigBattle, MSGBOX_AUTOCLOSE
	waitmessage
	turnobject LOCALID_ROUTE_30_JOEY DIR_NORTH
	release
	end


Route30_EventScript_Youngster_Joey::
	trainerbattle_single TRAINER_JOEY_HNS, Route30_Text_YoungsterJoey1Seen, Route30_Text_YoungsterJoey1Beaten, Route30_EventScript_RegisterJoey
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route30_EventScript_RematchJoey
	msgbox Route30_Text_YoungsterJoey1After, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_RegisterJoey::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route30_Text_JoeyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOEY_HNS
	release
	end

Route30_EventScript_RematchJoey::
	trainerbattle_rematch TRAINER_JOEY_HNS, Route30_Text_JoeyRematchIntro, Route30_Text_JoeyRematchDefeat
	msgbox Route30_Text_JoeyPostRematch, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_Youngster_Mikey::
	trainerbattle_single TRAINER_MIKEY_HNS, Route30_Text_YoungsterMikeySeen, Route30_Text_YoungsterMikeyBeaten
	msgbox Route30_Text_YoungsterMikeyAfter, MSGBOX_AUTOCLOSE
	end
	
Route30_EventScript_Bugcatcher_Don::
	trainerbattle_single TRAINER_DON_HNS, Route30_Text_BugCatcherDonSeen, Route30_Text_BugCatcherDonBeaten
	msgbox Route30_Text_BugCatcherDonAfter, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_ElmCall_Trigger::
	lock
	setspeaker Route30_Text_ElmName
	pokenavcall Route30_Text_Elm_Disaster
	waitmessage
	delay 30
	setvar VAR_CHERRYGROVE_CITY_STATE, 3
	release
	end

Route30_EventScript_Sign::
	lock
	msgbox Route30_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route30_EventScript_TrainerTips::
	lock
	msgbox Route30_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end	

Route30_EventScript_Poliwag::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWAG, CRY_MODE_NORMAL
	msgbox Route30_Text_Poliwag, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route30_EventScript_Mailbox::
	msgbox Route30_Text_Mailbox, MSGBOX_SIGN
	end

Route30_Text_Mailbox:
	.string "Casa di MR. POKéMON$"

Route30_Text_UseTackle:
	.string "Vai, RATTATA!\p"
	.string "AZIONE!$"

Route30_Text_ThisIsABigBattle:
	.string "Come? Questa è una lotta importante!\n"
	.string "Lasciami in pace!$"

Route30_Text_YoungsterJoey1Seen:
	.string "Ho appena perso, quindi cerco\n"
	.string "altri POKéMON.\p"
	.string "Aspetta! Sembri debole! Forza,\n"
	.string "lottiamo!$"

Route30_Text_YoungsterJoey1Beaten:
	.string "Ah! Ho perso ancora!\n"
	.string "Accidenti!$"

Route30_Text_YoungsterJoey1After:
	.string "Devo avere più POKéMON\n"
	.string "per lottare meglio?\p"
	.string "No! Resto fedele a questo,\n"
	.string "qualunque cosa accada!$"

Route30_Text_YoungsterMikeySeen:
	.string "Sei un allenatore di POKéMON,\n"
	.string "giusto?\p"
	.string "Allora devi lottare!$"

Route30_Text_YoungsterMikeyBeaten:
	.string "Che strano.\n"
	.string "Prima avevo vinto.$"

Route30_Text_YoungsterMikeyAfter:
	.string "Diventare un bravo allenatore è\n"
	.string "davvero dura.\p"
	.string "Lotterò con altre persone\n"
	.string "per migliorare.$"

Route30_Text_BugCatcherDonSeen:
	.string "Invece di un POKéMON insetto,\n"
	.string "ho trovato un allenatore!$"

Route30_Text_BugCatcherDonBeaten:
	.string "Argh! Sei troppo forte!$"

Route30_Text_BugCatcherDonAfter:
	.string "Ho finito le POKé BALL mentre\n"
	.string "catturavo POKéMON.\p"
	.string "Dovevo comprarne altre…$"

Route30_Text_YoungsterDirectionsToMrPokemon:
	.string "La casa di MR. POKéMON?\n"
	.string "È ancora un po' più avanti.$"

Route30_Text_YoungsterEveryoneIsBattling:
	.string "Tutti si divertono a\n"
	.string "lottare!\p"
	.string "Dovresti farlo anche tu!$"

Route30_Text_CooltrainerF:
	.string "Io non sono un'allenatrice.\p"
	.string "Ma se incroci lo sguardo di uno,\n"
	.string "preparati a lottare.$"

Route30_Text_Sign:
	.string "PERCORSO 30\p"
	.string "VIOLETTO - FOGLIANOVA$"

Route30_Text_MrPokemonsHouseDirectionsSign:
	.string "CASA DI MR. POKéMON\n"
	.string "SEMPRE DRITTO!$"

Route30_Text_MrPokemonsHouseSign:
	.string "CASA DI MR. POKéMON$"

Route30_Text_TrainerTips:
	.string "CONSIGLI ALLENATORI\p"
	.string "Non rubare i POKéMON\n"
	.string "degli altri!\p"
	.string "Le POKé BALL vanno lanciate\n"
	.string "solo ai POKéMON selvatici!$"

Route30_Text_JoeyRegister:
	.string "Sei davvero bravo!\p"
	.string "Il mio RATTATA è carico,\n"
	.string "come sempre.\p"
	.string "È l'unico che ho.\n"
	.string "Diventerò un grande\l"
	.string "ALLENATORE con lui!\p"
	.string "Lottiamo di nuovo, prima o poi!$"

Route30_Text_JoeyRematchIntro:
	.string "Ti avevo promesso che sarebbe\n"
	.string "andata diversa! Lottiamo!$"

Route30_Text_JoeyRematchDefeat:
	.string "Ah! Ho perso ancora!\n"
	.string "Accidenti!$"

Route30_Text_JoeyPostRematch:
	.string "Sto studiando le mosse del\n"
	.string "mio RATTATA e preparo\l"
	.string "delle strategie.\p"
	.string "Quando ne trovo una buona,\n"
	.string "facciamo una lotta!$"

Route30_Text_YoungsterJoeyGiveHPUp:
	.string "Ho perso di nuovo…\n"
	.string "Caspita, sei forte!\p"
	.string "Ah già, quasi dimenticavo che\n"
	.string "dovevo darti questo.\p"
	.string "Usalo per diventare più forte,\n"
	.string "OK?\p"
	.string "Anch'io diventerò più forte.$"

Route30_Text_ElmName:
	.string "PROF.ELM$"

Route30_Text_Elm_Disaster:
	.string "PROF. ELM: P-pronto? {PLAYER}? È\n"
	.string "una catastrofe!\p"
	.string "Ehm, ecco, è terribile!\p"
	.string "Che cosa devo fare? È…\n"
	.string "Oh, no…\p"
	.string "Torna qui subito, ti prego!$"


Route30_Text_Poliwag:
	.string "POLIWAG: Wag waag!$"
