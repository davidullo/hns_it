@ All the LOCALID constants used in this file are essentially redundant.
@ They're all used to have the NPC the player talked to turn back so they're facing
@ their original direction (because they're watching/participating in the contests).
@ They could all be substituted for VAR_LAST_TALKED.
LilycoveCity_ContestHall_MapScripts::
	.byte 0

LilycoveCity_ContestHall_EventScript_Boy1::
	msgbox LilycoveCity_ContestHall_Text_TodayWonSmartnessContest, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Boy2::
	msgbox LilycoveCity_ContestHall_Text_EnteredBunchOfContests, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Girl::
	msgbox LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Sailor::
	msgbox LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_SmartContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EnteredWrongContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_RaisedMonToBeSmart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience1::
	msgbox LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_StillLoveSmartnessContests, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_OverdidGrooming, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_InTheMiddleOfContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyAzurillWasDistracted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_NeverWonBattleButContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PetalDanceIsMarvel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience1::
	lockall
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_ContestHall_Text_MyChildIsInContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 25
	msgbox LilycoveCity_ContestHall_Text_ComeOnDear, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyStageSign::
	msgbox LilycoveCity_ContestHall_Text_BeautyContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_CuteStageSign::
	msgbox LilycoveCity_ContestHall_Text_CuteContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartStageSign::
	msgbox LilycoveCity_ContestHall_Text_SmartContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Text_TodayWonSmartnessContest:
	.string "Questo POKéMON ha vinto la GARA DI\n"
	.string "BELLEZZA qui.\p"
	.string "E indovina? Oggi l'ho fatto\n"
	.string "vincere una GARA DI INTELLIGENZA!\p"
	.string "Le mie capacità spaventano me…$"

LilycoveCity_ContestHall_Text_EnteredBunchOfContests:
	.string "Ho partecipato a molte GARE,\n"
	.string "quindi vedo come funzionano.\p"
	.string "In una GARA DI CLASSE,\n"
	.string "le mosse cool piacciono al pubblico.\p"
	.string "Ma le mosse intelligenti e carine\n"
	.string "non funzionano bene, per esempio.$"

LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks:
	.string "Il ragazzo che ha vinto prima aveva\n"
	.string "un mucchio di {POKEBLOCK} diversi.\p"
	.string "Si può vincere con tutti quei\n"
	.string "cosi?$"

LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous:
	.string "Uau, che posto enorme!\p"
	.string "C'è tensione nell'aria… Non è\n"
	.string "come una sala GARE di provincia.$"

LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal:
	.string "MC: Ok, POKéMON INTELLIGENTI e\n"
	.string "ALLENATORI, pronti?!\p"
	.string "Date il meglio!\n"
	.string "Esibitevi!$"

LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest:
	.string "GIUDICE: Ti piace questa GARA?\p"
	.string "Torna con tre amici, e\n"
	.string "potrete entrarci tutti!$"

LilycoveCity_ContestHall_Text_EnteredWrongContest:
	.string "Ayayayay…\n"
	.string "Ho sbagliato GARA.\p"
	.string "Ho iscritto questo POKéMON forte\n"
	.string "alla GARA DI INTELLIGENZA…\p"
	.string "Forza, stupiscili con\n"
	.string "ROCK SMASH.$"

LilycoveCity_ContestHall_Text_RaisedMonToBeSmart:
	.string "Ho passato anni, e tutta la mia\n"
	.string "saggezza, ad allenare questo POKéMON\l"
	.string "per renderlo intelligente.\p"
	.string "Non sarà facile batterlo per il\n"
	.string "POKéMON di un pivello.\p"
	.string "Mia cara moglie, lo vedi?$"

LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext:
	.string "Eccoci!\p"
	.string "Se il mio POKéMON usa una mossa\n"
	.string "intelligente, il pubblico esplode!$"

LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife:
	.string "Oh, no, no!\p"
	.string "Il LEECH LIFE del mio ZUBAT è così\n"
	.string "carino che l'ho usato all'infinito!\p"
	.string "Ma questa gente antipatica non lo\n"
	.string "apprezza affatto!$"

LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa:
	.string "Kiyaaah! Sei bellissimo, nonno!$"

LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves:
	.string "Anche se gli ALLENATORI usano\n"
	.string "POKéMON simili, tutti usano\l"
	.string "mosse diverse per esibirsi.\p"
	.string "Come le persone, che hanno\n"
	.string "stili diversi nel lottare.$"

LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers:
	.string "Trovo i POKéMON più intelligenti\n"
	.string "dei loro ALLENATORI. E di molto.$"

LilycoveCity_ContestHall_Text_StillLoveSmartnessContests:
	.string "Tutto sommato, amo ancora le\n"
	.string "GARE DI INTELLIGENZA.\p"
	.string "Quel verde intellettuale…\n"
	.string "È così… Così… Cool.$"

LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest:
	.string "MC: Partecipi anche tu alla\n"
	.string "GARA BELLEZZA? Buona fortuna!$"

LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty:
	.string "GIUDICE: Ah, ogni POKéMON qui è\n"
	.string "un modello di pura bellezza!\p"
	.string "Quasi dimenticavo di valutarli!$"

LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty:
	.string "Un POKéMON così bello…\n"
	.string "Non ce n'è un altro uguale.\p"
	.string "Tutti avranno gli occhi puntati\n"
	.string "sulla mia bellezza.$"

LilycoveCity_ContestHall_Text_OverdidGrooming:
	.string "Waaaah!\p"
	.string "Ho spazzolato e toelettato il POKéMON\n"
	.string "con cura per questa GARA…\p"
	.string "Ma ho esagerato…\n"
	.string "Il pelo è diventato tutto arruffato…\p"
	.string "Che faccio?$"

LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam:
	.string "Questo AURORA BEAM è così abbagliante\n"
	.string "che il GIUDICE non lo vedrà.\p"
	.string "Uh, aspetta un attimo…\n"
	.string "Allora non servirebbe a niente!$"

LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe:
	.string "Questo bel POKéMON mi somiglia\n"
	.string "quando ero giovane.\p"
	.string "Appena l'ho detto, mio marito\n"
	.string "ha sputato il caffè che beveva.\p"
	.string "Ho detto qualcosa di buffo?$"

LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy:
	.string "Sai, se vinco una GARA DI\n"
	.string "BELLEZZA, certo mi rende\l"
	.string "felice. Più del solito, insomma.$"

LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon:
	.string "Wahahahah!\p"
	.string "Guardate quanti bei\n"
	.string "POKéMON!\l"
	.string "Adoro tutto questo sfarzo!$"

LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone:
	.string "Non basta la bellezza da sola\n"
	.string "per vincere.\p"
	.string "Devi toelettare i POKéMON così\n"
	.string "sono lucidi come i miei.$"

LilycoveCity_ContestHall_Text_InTheMiddleOfContest:
	.string "MC: Oh-oh! Ciao!\n"
	.string "Siamo nel mezzo di una GARA!\p"
	.string "Entra al banco delle iscrizioni\n"
	.string "e poi esci, ok?$"

LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals:
	.string "GIUDICE: Oh, che esibizioni carine\n"
	.string "e affascinanti!\p"
	.string "Oh, cielo! Che esibizione WATER\n"
	.string "SPORT adorabile!$"

LilycoveCity_ContestHall_Text_MyAzurillWasDistracted:
	.string "Oh, no… Il mio dolce AZURILL è stato\n"
	.string "distratto da un altro POKéMON.$"

LilycoveCity_ContestHall_Text_NeverWonBattleButContest:
	.string "Il mio POKéMON non ha mai vinto una\n"
	.string "lotta, ma mettilo in una GARA e vedrai!$"

LilycoveCity_ContestHall_Text_PetalDanceIsMarvel:
	.string "Il PETAL DANCE del mio POKéMON è una\n"
	.string "meraviglia di eleganza.\p"
	.string "Non lascerò che nessuno disturbi\n"
	.string "la sua esibizione.$"

LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter:
	.string "I POKéMON di tutti sono molto carini.\p"
	.string "Però, se il mio POKéMON facesse\n"
	.string "un'esibizione carina…\p"
	.string "Sono certo che sarebbe molto \n"
	.string "più carino degli altri.$"

LilycoveCity_ContestHall_Text_MyChildIsInContest:
	.string "Mio figlio è in questa GARA.$"

LilycoveCity_ContestHall_Text_ComeOnDear:
	.string "Dai, forza!\n"
	.string "Il tuo POKéMON è il migliore!$"

LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest:
	.string "Penso che quella ragazza là sia\n"
	.string "la più carina di tutte.\p"
	.string "Come? Giudicano i POKéMON\n"
	.string "dal loro aspetto?$"

LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn:
	.string "Ohh, vedere tutti questi POKéMON\n"
	.string "carini mi fa venire voglia di averne uno!\p"
	.string "Vado a catturarne qualcuno!$"

LilycoveCity_ContestHall_Text_BeautyContestStage:
	.string "PALCO GARA BELLEZZA\n"
	.string "LASCIATI AMMALIARE DAI POKéMON!$"

LilycoveCity_ContestHall_Text_CuteContestStage:
	.string "PALCO GARA GRAZIA\n"
	.string "FATTI INCANTARE DAI POKéMON!$"

LilycoveCity_ContestHall_Text_SmartContestStage:
	.string "PALCO GARA BELLEZZA\n"
	.string "FATTI STUPIRE DAI POKéMON BELLI!$"

