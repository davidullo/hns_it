ViridianForest_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianForest_OnTransition
	.byte 0

ViridianForest_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_VIRIDIAN_FOREST
	end

ViridianForest_EventScript_Youngster::
	msgbox ViridianForest_Text_FriendsItchingToBattle, MSGBOX_NPC
	end

ViridianForest_EventScript_Boy::
	msgbox ViridianForest_Text_RanOutOfPokeBalls, MSGBOX_NPC
	end

ViridianForest_EventScript_TrainerTips1::
	msgbox ViridianForest_Text_AvoidGrassyAreasWhenWeak, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips2::
	msgbox ViridianForest_Text_UseAntidoteForPoison, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips3::
	msgbox ViridianForest_Text_ContactOakViaPCToRatePokedex, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips4::
	msgbox ViridianForest_Text_CantCatchOwnedMons, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips5::
	msgbox ViridianForest_Text_WeakenMonsBeforeCapture, MSGBOX_SIGN
	end

ViridianForest_EventScript_ExitSign::
	msgbox ViridianForest_Text_LeavingViridianForest, MSGBOX_SIGN
	end

ViridianForest_EventScript_Rick::
	trainerbattle_single TRAINER_BUG_CATCHER_RICK, ViridianForest_Text_RickIntro, ViridianForest_Text_RickDefeat
	msgbox ViridianForest_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Doug::
	trainerbattle_single TRAINER_BUG_CATCHER_DOUG, ViridianForest_Text_DougIntro, ViridianForest_Text_DougDefeat
	msgbox ViridianForest_Text_DougPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Sammy::
	trainerbattle_single TRAINER_BUG_CATCHER_SAMMY, ViridianForest_Text_SammyIntro, ViridianForest_Text_SammyDefeat
	msgbox ViridianForest_Text_SammyPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Anthony::
	trainerbattle_single TRAINER_BUG_CATCHER_ANTHONY, ViridianForest_Text_AnthonyIntro, ViridianForest_Text_AnthonyDefeat
	msgbox ViridianForest_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Charlie::
	trainerbattle_single TRAINER_BUG_CATCHER_CHARLIE, ViridianForest_Text_CharlieIntro, ViridianForest_Text_CharlieDefeat
	msgbox ViridianForest_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_Text_FriendsItchingToBattle::
	.string "Sono venuto con degli amici a\n"
	.string "catturare POKéMON COLEOTTERO!\p"
	.string "Non vedono l'ora di fare\n"
	.string "qualche lotta POKéMON!$"

ViridianForest_Text_RickIntro::
	.string "Ehi! Hai dei POKéMON!\n"
	.string "Forza!\l"
	.string "Lottiamo!$"

ViridianForest_Text_RickDefeat::
	.string "No!\nCATERPIE non ce la fa!$"

ViridianForest_Text_RickPostBattle::
	.string "Ssh! Spaventerai gli insetti.\n"
	.string "Un'altra volta, ok?$"

ViridianForest_Text_DougIntro::
	.string "Yo!\n"
	.string "Non puoi suonare se sei un\l"
	.string "ALLENATORE POKéMON!$"

ViridianForest_Text_DougDefeat::
	.string "Eh?\n"
	.string "Ho finito i POKéMON!$"

ViridianForest_Text_DougPostBattle::
	.string "Che roba! Me ne vado a\n"
	.string "catturare di più forti!$"

ViridianForest_Text_SammyIntro::
	.string "Ehi, aspetta!\n"
	.string "Che fretta hai? Perché corri?$"

ViridianForest_Text_SammyDefeat::
	.string "Mi arrendo!\n"
	.string "Sei bravo!$"

ViridianForest_Text_SammyPostBattle::
	.string "A volte si trovano cose per\n"
	.string "terra.\p"
	.string "Cerco la roba che ho\n"
	.string "perso. Mi aiuti?$"

ViridianForest_Text_AnthonyIntro::
	.string "Sarò piccolo, ma non mi piace\n"
	.string "se ti trattieni con me!$"

ViridianForest_Text_AnthonyDefeat::
	.string "Oh, che peccato.\n"
	.string "Non mi è andato niente bene.$"

ViridianForest_Text_AnthonyPostBattle::
	.string "Ho perso parte della paghetta…$"

ViridianForest_Text_CharlieIntro::
	.string "Lo sapevi che i POKéMON si evolvono?$"

ViridianForest_Text_CharlieDefeat::
	.string "Oh!\n"
	.string "Ho perso!$"

ViridianForest_Text_CharliePostBattle::
	.string "I POKéMON COLEOTTERO evolvono\n"
	.string "in fretta. Sono uno spasso!$"

ViridianForest_Text_RanOutOfPokeBalls::
	.string "Lanciavo POKé BALL per\n"
	.string "catturare POKéMON e sono finite.\p"
	.string "Per questo non hai mai troppe\n"
	.string "POKé BALL.$"

ViridianForest_Text_AvoidGrassyAreasWhenWeak::
	.string "CONSIGLI PER ALLENATORI\p"
	.string "Se i POKéMON sono deboli e vuoi\n"
	.string "evitare le lotte, stai lontano\l"
	.string "dall'erba alta!$"

ViridianForest_Text_UseAntidoteForPoison::
	.string "Per il veleno usa l'ANTIDOTO!\n"
	.string "Lo trovi ai MART POKéMON!$"

ViridianForest_Text_ContactOakViaPCToRatePokedex::
	.string "CONSIGLI PER ALLENATORI\p"
	.string "Contatta il PROF. OAK via PC per\n"
	.string "far valutare il POKéDEX!$"

ViridianForest_Text_CantCatchOwnedMons::
	.string "CONSIGLI PER ALLENATORI\p"
	.string "Non puoi catturare un POKéMON\n"
	.string "che appartiene a qualcun altro.\p"
	.string "Lancia le POKé BALL solo sui\n"
	.string "POKéMON selvatici per catturarli!$"

ViridianForest_Text_WeakenMonsBeforeCapture::
	.string "CONSIGLI PER ALLENATORI\p"
	.string "Indebolisci i POKéMON prima di\n"
	.string "catturarli!\p"
	.string "Se in salute, possono scappare!$"

ViridianForest_Text_LeavingViridianForest::
	.string "USCITA DALLA FORESTA DI VIRIDIAN\n"
	.string "PROSSIMA TAPPA PLUMBEOPOLI$"

