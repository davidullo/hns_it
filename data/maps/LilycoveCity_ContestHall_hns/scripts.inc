@ All the LOCALID constants used in this file are essentially redundant.
@ They're all used to have the NPC the player talked to turn back so they're facing
@ their original direction (because they're watching/participating in the contests).
@ They could all be substituted for VAR_LAST_TALKED.
LilycoveCity_ContestHall_hns_MapScripts::
	.byte 0

LilycoveCity_ContestHall_EventScript_Boy1_hns::
	msgbox LilycoveCity_ContestHall_Text_TodayWonSmartnessContest_hns, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Boy2_hns::
	msgbox LilycoveCity_ContestHall_Text_EnteredBunchOfContests_hns, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Girl_hns::
	msgbox LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks_hns, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Sailor_hns::
	msgbox LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous_hns, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_SmartContestMC_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestJudge_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant1_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EnteredWrongContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_RaisedMonToBeSmart_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant4_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience1_hns::
	msgbox LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa_hns, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience4_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_StillLoveSmartnessContests_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestMC_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestJudge_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant1_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_OverdidGrooming_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant4_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience1_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestMC_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_InTheMiddleOfContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestJudge_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant1_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyAzurillWasDistracted_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_NeverWonBattleButContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PetalDanceIsMarvel_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant4_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience1_hns::
	lockall
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_ContestHall_Text_MyChildIsInContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 25
	msgbox LilycoveCity_ContestHall_Text_ComeOnDear_hns, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyStageSign_hns::
	msgbox LilycoveCity_ContestHall_Text_BeautyContestStage_hns, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_CuteStageSign_hns::
	msgbox LilycoveCity_ContestHall_Text_CuteContestStage_hns, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartStageSign_hns::
	msgbox LilycoveCity_ContestHall_Text_SmartContestStage_hns, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Text_TodayWonSmartnessContest_hns:
	.string "Questo POKéMON ha vinto la GARA DI\n"
	.string "BELLEZZA qui.\p"
	.string "E indovina? Oggi l'ho fatto\n"
	.string "vincere una GARA DI INTELLIGENZA!\p"
	.string "Le mie capacità spaventano me…$"

LilycoveCity_ContestHall_Text_EnteredBunchOfContests_hns:
	.string "Ho partecipato a molte GARE,\n"
	.string "quindi vedo come funzionano.\p"
	.string "In una GARA DI CLASSE,\n"
	.string "le mosse cool piacciono al pubblico.\p"
	.string "Ma le mosse intelligenti e carine\n"
	.string "non funzionano bene, per esempio.$"

LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks_hns:
	.string "Il ragazzo che ha vinto prima aveva\n"
	.string "un mucchio di {POKEBLOCK} diversi.\p"
	.string "Si può vincere con tutti quei\n"
	.string "cosi?$"

LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous_hns:
	.string "Uau, che posto enorme!\p"
	.string "C'è tensione nell'aria… Non è\n"
	.string "come una sala GARE di provincia.$"

LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal_hns:
	.string "MC: Ok, POKéMON INTELLIGENTI e\n"
	.string "ALLENATORI, pronti?!\p"
	.string "Date il meglio!\n"
	.string "Esibitevi!$"

LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest_hns:
	.string "GIUDICE: Ti piace questa GARA?\p"
	.string "Torna con tre amici, e\n"
	.string "potrete entrarci tutti!$"

LilycoveCity_ContestHall_Text_EnteredWrongContest_hns:
	.string "Ayayayay…\n"
	.string "Ho sbagliato GARA.\p"
	.string "Ho iscritto questo POKéMON forte\n"
	.string "alla GARA DI INTELLIGENZA…\p"
	.string "Forza, stupiscili con\n"
	.string "ROCK SMASH.$"

LilycoveCity_ContestHall_Text_RaisedMonToBeSmart_hns:
	.string "Ho passato anni, e tutta la mia\n"
	.string "saggezza, ad allenare questo POKéMON\l"
	.string "per renderlo intelligente.\p"
	.string "Non sarà facile batterlo per il\n"
	.string "POKéMON di un pivello.\p"
	.string "Mia cara moglie, lo vedi?$"

LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext_hns:
	.string "Eccoci!\p"
	.string "Se il mio POKéMON usa una mossa\n"
	.string "intelligente, il pubblico esplode!$"

LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife_hns:
	.string "Oh, no, no!\p"
	.string "Il LEECH LIFE del mio ZUBAT è così\n"
	.string "carino che l'ho usato all'infinito!\p"
	.string "Ma questa gente antipatica non lo\n"
	.string "apprezza affatto!$"

LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa_hns:
	.string "Kiyaaah! Sei bellissimo, nonno!$"

LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves_hns:
	.string "Anche se gli ALLENATORI usano\n"
	.string "POKéMON simili, tutti usano\l"
	.string "mosse diverse per esibirsi.\p"
	.string "Come le persone, che hanno\n"
	.string "stili diversi nel lottare.$"

LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers_hns:
	.string "Trovo i POKéMON più intelligenti\n"
	.string "dei loro ALLENATORI. E di molto.$"

LilycoveCity_ContestHall_Text_StillLoveSmartnessContests_hns:
	.string "Tutto sommato, amo ancora le\n"
	.string "GARE DI INTELLIGENZA.\p"
	.string "Quel verde intellettuale…\n"
	.string "È così… Così… Cool.$"

LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest_hns:
	.string "MC: Partecipi anche tu alla\n"
	.string "GARA BELLEZZA? Buona fortuna!$"

LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty_hns:
	.string "GIUDICE: Ah, ogni POKéMON qui è\n"
	.string "un modello di pura bellezza!\p"
	.string "Quasi dimenticavo di valutarli!$"

LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty_hns:
	.string "Un POKéMON così bello…\n"
	.string "Non ce n'è un altro uguale.\p"
	.string "Tutti avranno gli occhi puntati\n"
	.string "sulla mia bellezza.$"

LilycoveCity_ContestHall_Text_OverdidGrooming_hns:
	.string "Waaaah!\p"
	.string "Ho spazzolato e toelettato il POKéMON\n"
	.string "con cura per questa GARA…\p"
	.string "Ma ho esagerato…\n"
	.string "Il pelo è diventato tutto arruffato…\p"
	.string "Che faccio?$"

LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam_hns:
	.string "Questo AURORA BEAM è così abbagliante\n"
	.string "che il GIUDICE non lo vedrà.\p"
	.string "Uh, aspetta un attimo…\n"
	.string "Allora non servirebbe a niente!$"

LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe_hns:
	.string "Questo bel POKéMON mi somiglia\n"
	.string "quando ero giovane.\p"
	.string "Appena l'ho detto, mio marito\n"
	.string "ha sputato il caffè che beveva.\p"
	.string "Ho detto qualcosa di buffo?$"

LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy_hns:
	.string "Sai, se vinco una GARA DI\n"
	.string "BELLEZZA, certo mi rende\l"
	.string "felice. Più del solito, insomma.$"

LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon_hns:
	.string "Wahahahah!\p"
	.string "Guardate che bei\n"
	.string "POKéMON!\l"
	.string "Adoro questo sfarzo!$"

LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone_hns:
	.string "Non basta la bellezza da sola\n"
	.string "per vincere.\p"
	.string "Devi toelettare i POKéMON così\n"
	.string "sono lucidi come i miei.$"

LilycoveCity_ContestHall_Text_InTheMiddleOfContest_hns:
	.string "MC: Oh-oh! Ciao!\n"
	.string "Siamo nel mezzo di una GARA!\p"
	.string "Entra al banco delle iscrizioni\n"
	.string "e poi esci, ok?$"

LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals_hns:
	.string "GIUDICE: Oh, che esibizioni carine\n"
	.string "e affascinanti!\p"
	.string "Oh, cielo! Che esibizione WATER\n"
	.string "SPORT adorabile!$"

LilycoveCity_ContestHall_Text_MyAzurillWasDistracted_hns:
	.string "Oh, no… Il mio dolce AZURILL è stato\n"
	.string "distratto da un altro POKéMON.$"

LilycoveCity_ContestHall_Text_NeverWonBattleButContest_hns:
	.string "Il mio POKéMON non ha mai vinto una\n"
	.string "lotta, ma mettilo in una GARA e vedrai!$"

LilycoveCity_ContestHall_Text_PetalDanceIsMarvel_hns:
	.string "Il PETAL DANCE del mio POKéMON è una\n"
	.string "meraviglia di eleganza.\p"
	.string "Non lascerò che nessuno disturbi\n"
	.string "la sua esibizione.$"

LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter_hns:
	.string "I POKéMON di tutti sono molto carini.\p"
	.string "Però, se il mio POKéMON facesse\n"
	.string "un'esibizione carina…\p"
	.string "Sono certo che sarebbe molto \n"
	.string "più carino degli altri.$"

LilycoveCity_ContestHall_Text_MyChildIsInContest_hns:
	.string "Mio figlio è in questa GARA.$"

LilycoveCity_ContestHall_Text_ComeOnDear_hns:
	.string "Dai, forza!\n"
	.string "Il tuo POKéMON è il migliore!$"

LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest_hns:
	.string "Penso che quella ragazza là sia\n"
	.string "la più carina di tutte.\p"
	.string "Come? Giudicano i POKéMON\n"
	.string "dal loro aspetto?$"

LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn_hns:
	.string "Ohh, vedere tutti questi POKéMON\n"
	.string "carini mi fa venire voglia di averne uno!\p"
	.string "Vado a catturarne qualcuno!$"

LilycoveCity_ContestHall_Text_BeautyContestStage_hns:
	.string "PALCO GARA BELLEZZA\n"
	.string "LASCIATI AMMALIARE DAI POKéMON!$"

LilycoveCity_ContestHall_Text_CuteContestStage_hns:
	.string "PALCO GARA GRAZIA\n"
	.string "FATTI INCANTARE DAI POKéMON!$"

LilycoveCity_ContestHall_Text_SmartContestStage_hns:
	.string "PALCO GARA BELLEZZA\n"
	.string "FATTI STUPIRE DAI POKéMON BELLI!$"

