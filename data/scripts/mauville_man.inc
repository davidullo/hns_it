MauvilleCity_PokemonCenter_1F_EventScript_MauvilleOldMan::
	special Script_GetCurrentMauvilleMan
	switch VAR_RESULT
	case MAUVILLE_MAN_BARD, MauvilleCity_PokemonCenter_1F_EventScript_Bard
	case MAUVILLE_MAN_HIPSTER, MauvilleCity_PokemonCenter_1F_EventScript_Hipster
	case MAUVILLE_MAN_TRADER, MauvilleCity_PokemonCenter_1F_EventScript_Trader
	case MAUVILLE_MAN_STORYTELLER, MauvilleCity_PokemonCenter_1F_EventScript_Storyteller
	case MAUVILLE_MAN_GIDDY, MauvilleCity_PokemonCenter_1F_EventScript_Giddy
	end

@ Bard
MauvilleCity_PokemonCenter_1F_EventScript_Bard::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_PlaySong
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong
	end

MauvilleCity_PokemonCenter_1F_EventScript_PlaySong::
	setvar VAR_0x8004, FALSE  @ Play his current song
	special PlayBardSong
	delay 60
	special HasBardSongBeenChanged
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	end

MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics::
	setvar VAR_0x8004, EASY_CHAT_TYPE_BARD_SONG
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, TRUE  @ Play the new song
	special PlayBardSong
	delay 60
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	special SaveBardSongLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2, MSGBOX_DEFAULT
	release
	end

@ Hipster
MauvilleCity_PokemonCenter_1F_EventScript_Hipster::
	lock
	faceplayer
	setflag FLAG_UNLOCKED_TRENDY_SAYINGS
	msgbox MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening, MSGBOX_DEFAULT
	special HasHipsterTaughtWord
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord::
	special HipsterTryTeachWord
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_TeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TeachWord::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord, MSGBOX_DEFAULT
	special SetHipsterTaughtWord
	release
	end

@ Trader
MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor:
	.string "Ciao, sono lo SCAMBISTA.\n"
	.string "Vuoi scambiare decorazioni con me?$"

MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues:
	.string "Oh…\n"
	.string "Mi hai lasciato un po' giù…$"

MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded:
	.string "Ma abbiamo già scambiato\n"
	.string "decorazioni, io e te.$"

MauvilleCity_PokemonCenter_1F_Text_PickADecorItem:
	.string "Se vedi qualche soprammobile\n"
	.string "mio che ti piace, chiedi pure.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything:
	.string "Non vuoi niente?\n"
	.string "Mi sento rifiutato…$"

MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt:
	.string "Quel soprammobile apparteneva\n"
	.string "a {STR_VAR_1}.\p"
	.string "Lo vuoi?$"

MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor:
	.string "Ehm… un momento. Non hai\n"
	.string "nemmeno una decorazione!$"

MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade:
	.string "Ok, scegli la decorazione che vuoi\n"
	.string "scambiarmi.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade:
	.string "Non vuoi scambiare con me?\n"
	.string "Mi sento rifiutato…$"

MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis:
	.string "Hai già tutti i {STR_VAR_2}S che\n"
	.string "si possono tenere. Non c'è spazio.$"

MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor:
	.string "Ok, quindi scambiamo il mio {STR_VAR_3}\n"
	.string "con il tuo {STR_VAR_2}?$"

MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse:
	.string "Quell'oggetto è già in uso.\n"
	.string "Non puoi scambiarlo.$"

MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC:
	.string "Allora facciamo uno scambio!\n"
	.string "Manderò il mio oggetto al tuo PC.$"

MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne:
	.string "Ops! Scusa! È un pezzo\n"
	.string "d'arredamento davvero raro.\l"
	.string "Non posso scambiarlo!\p"
	.string "Ti interessa qualcos'altro?$"

MauvilleCity_PokemonCenter_1F_EventScript_Trader::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade
	special GetTraderTradedFlag
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade::
	msgbox MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive::
	special TraderMenuGetDecoration
	waitstate
	goto_if_eq VAR_0x8004, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor
	goto_if_eq VAR_0x8004, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor
	special DoesPlayerHaveNoDecorations
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor::
	message MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor::
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive::
	msgbox MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade, MSGBOX_DEFAULT
	special TraderShowDecorationMenu
	waitstate
	goto_if_eq VAR_0x8006, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor
	goto_if_eq VAR_0x8006, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse
	special IsDecorationCategoryFull
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	special TraderDoDecorationTrade
	msgbox MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis, MSGBOX_DEFAULT
	release
	end

@ Storyteller
MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale:
	.string "Sono il NARRATORE.\n"
	.string "Ti racconto storie di ALLENATORI\l"
	.string "leggendari.\p"
	.string "Vuoi sentire la mia storia?$"

MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues:
	.string "Oh…\n"
	.string "Mi hai lasciato un po' giù…$"

MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell:
	.string "Conosco queste leggende.\n"
	.string "Quale storia vuoi sentire?$"

MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales:
	.string "Ma non conosco ALLENATORI leggendari.\n"
	.string "Quindi non conosco storie.\p"
	.string "Dove si trova un ALLENATORE degno\n"
	.string "di una storia leggendaria?$"

MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes:
	.string "Come?!\n"
	.string "Tu… Tu…\p"
	.string "{STR_VAR_2}\n"
	.string "{STR_VAR_1} volta/e?!\p"
	.string "È davvero magnifico!\n"
	.string "È nata una nuova leggenda!$"

MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends:
	.string "Chissà, esistono altri ALLENATORI\n"
	.string "con imprese più grandiose,\l"
	.string "leggende tutte da scoprire?$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales:
	.string "Sei un ALLENATORE?\p"
	.string "Allora dimmi, hai qualche storia\n"
	.string "anche solo vagamente leggendaria?$"

@ Unused
MauvilleCity_PokemonCenter_1F_Text_HearAnotherLegendaryTale:
	.string "A proposito… Ti va di ascoltare\n"
	.string "un'altra storia leggendaria?$"

MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend:
	.string "Hmm…\n"
	.string "Non sono soddisfatto…\p"
	.string "Vorrei che mi portassi notizie degne\n"
	.string "di essere chiamate leggenda.$"

MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested:
	.string "Vorrei che più gente volesse ascoltare\n"
	.string "le mie epiche storie di ALLENATORI\l"
	.string "leggendari.$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameTitle::
	.string "L'ALLENATORE che salva sempre$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameAction::
	.string "Ha salvato$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Ha salvato il gioco\n"
	.string "{STR_VAR_1} volte!\p"
	.string "Un ALLENATORE più prudente\n"
	.string "di {STR_VAR_3} non esiste!$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedTitle::
	.string "L'ALLENATORE alla moda$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedAction::
	.string "Ha lanciato mode$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Ha lanciato nuove mode\n"
	.string "{STR_VAR_1} volte!\p"
	.string "{STR_VAR_3} lancia mode per tutta\n"
	.string "la regione di HOENN!$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedTitle::
	.string "L'ALLENATORE che pianta BACCHE$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedAction::
	.string "Piantato BACCHE$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Questo ALLENATORE ha piantato BACCHE\n"
	.string "{STR_VAR_1} volte!\p"
	.string "{STR_VAR_3} è un leggendario amante\n"
	.string "delle BACCHE!$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesTitle::
	.string "L'ALLENATORE amante delle BICI$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesAction::
	.string "Scambiato BICI$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Questo ALLENATORE ha scambiato BICI\n"
	.string "{STR_VAR_1} volte!\p"
	.string "{STR_VAR_3} deve amare le BICI\n"
	.string "alla follia!$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsTitle::
	.string "L'ALLENATORE intervistato$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsAction::
	.string "Interviste rilasciate$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Questo ALLENATORE è stato intervistato\n"
	.string "{STR_VAR_1} volte!\p"
	.string "{STR_VAR_3} deve essere un ALLENATORE\n"
	.string "che attira molta attenzione!$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesTitle::
	.string "L'ALLENATORE tutto lotte$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesAction::
	.string "Ha lottato$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Ha lottato {STR_VAR_1} volte!\p"
	.string "{STR_VAR_3} non rifiuta mai\n"
	.string "l'occasione di lottare!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtTitle::
	.string "L'ALLENATORE che cattura POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtAction::
	.string "POKéMON catturati$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Questo ALLENATORE ha catturato\n"
	.string "{STR_VAR_1} POKéMON!\p"
	.string "{STR_VAR_3} è un leggendario catturatore\n"
	.string "di POKéMON selvatici!$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtTitle::
	.string "L'ALLENATORE pescatore$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtAction::
	.string "POKéMON pescati con la LENZA$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Questo ALLENATORE ha pescato\n"
	.string "{STR_VAR_1} POKéMON!\p"
	.string "{STR_VAR_3} è un esperto\n"
	.string "di pesca leggendario!$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedTitle::
	.string "L'ALLENATORE covauova$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedAction::
	.string "Uova schiuse$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Ha schiuso {STR_VAR_1} POKéMON\n"
	.string "dalle UOVA!\p"
	.string "{STR_VAR_3} è un leggendario\n"
	.string "covauova!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedTitle::
	.string "L'ALLENATORE evolvitore$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedAction::
	.string "POKéMON evoluti$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Ha fatto evolvere {STR_VAR_1} POKéMON!\n"
	.string "Che evoluzione!\p"
	.string "{STR_VAR_3} è il supremo evolutore\n"
	.string "di POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterTitle::
	.string "L'ALLENATORE amante dei POKéMON CENTER$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterAction::
	.string "Ha usato i CENTRI POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterStory::
	.string "Ecco la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Ha curato i POKéMON\n"
	.string "{STR_VAR_1} volte ai CENTRI POKéMON!\p"
	.string "Nessuno ama i CENTRI POKéMON\n"
	.string "più di {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeTitle::
	.string "L'ALLENATORE pigrone$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeAction::
	.string "POKéMON curati a casa$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Questo ALLENATORE ha curato POKéMON\n"
	.string "{STR_VAR_1} volte a casa!\p"
	.string "Non può esserci uno più casalingo\n"
	.string "di {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesTitle::
	.string "L'ALLENATORE del PARCO SAFARI$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesAction::
	.string "Visite al PARCO SAFARI$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "È andato al PARCO SAFARI\n"
	.string "{STR_VAR_1} volte!\p"
	.string "{STR_VAR_3} deve per forza\n"
	.string "scatenarsi al PARCO SAFARI!$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutTitle::
	.string "L'ALLENATORE del TAGLIO$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutAction::
	.string "Ha usato TAGLIO$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Ha usato TAGLIO\n"
	.string "{STR_VAR_1} volte!\p"
	.string "{STR_VAR_3} adora\n"
	.string "usare TAGLIO!$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashTitle::
	.string "L'ALLENATORE SPACCAROCCE$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashAction::
	.string "Ha spaccato rocce$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashStory::
	.string "Ecco la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Ha usato SPACCAROCCIA\n"
	.string "{STR_VAR_1} volte!\p"
	.string "{STR_VAR_3} non lascia mai\n"
	.string "una pietra intatta!$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesTitle::
	.string "L'ALLENATORE traslocatore$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesAction::
	.string "BASI SEGRETE spostate$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Ha spostato la BASE SEGRETA\n"
	.string "{STR_VAR_1} volte!\p"
	.string "{STR_VAR_3} adora traslocare\n"
	.string "di continuo!$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashTitle::
	.string "L'ALLENATORE fan di SPLASH$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashAction::
	.string "Ha usato SPLASH$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashStory::
	.string "Ecco la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Ha usato SPLASH\n"
	.string "{STR_VAR_1} volte!\p"
	.string "{STR_VAR_3} adora proprio\n"
	.string "saltellare qua e là!$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleTitle::
	.string "L'ALLENATORE tenace$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleAction::
	.string "Ha dovuto usare SCONTRO$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleStory::
	.string "Ecco la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Ha dovuto usare SCONTRO\n"
	.string "{STR_VAR_1} volte!\p"
	.string "{STR_VAR_3} è tenace e non\n"
	.string "si arrende mai alle avversità!$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsTitle::
	.string "Il campione delle SLOT$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsAction::
	.string "Jackpot alle SLOT$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Ha fatto jackpot alle SLOT\n"
	.string "{STR_VAR_1} volte.\p"
	.string "{STR_VAR_3} è stato fortunato\n"
	.string "alle SLOT!$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsTitle::
	.string "Il campione della ROULETTE$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsAction::
	.string "Vincite consecutive alla ROULETTE$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Ha vinto alla ROULETTE\n"
	.string "{STR_VAR_1} volte di fila.\p"
	.string "{STR_VAR_3} è stato fortunato quando\n"
	.string "la pallina è caduta bene!$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesTitle::
	.string "Lo sfidante della TORRE LOTTA$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesAction::
	.string "Affrontato la TORRE LOTTA$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Questo ALLENATORE ha affrontato la\n"
	.string "TORRE LOTTA {STR_VAR_1} volte!\p"
	.string "{STR_VAR_3} è un ALLENATORE che punta\n"
	.string "all'eccellenza nella TORRE LOTTA!$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksTitle::
	.string "L'ALLENATORE amante delle miscele$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksAction::
	.string "{POKEBLOCK} creati$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksStory::
	.string "Ecco la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Ha creato {POKEBLOCK}\n"
	.string "{STR_VAR_1} volte!\p"
	.string "Nessuno usa il FRULLA BACCHE\n"
	.string "meglio di {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsTitle::
	.string "L'ALLENATORE amante delle GARE$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsAction::
	.string "Gare disputate$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Questo ALLENATORE ha partecipato a GARE\n"
	.string "{STR_VAR_1} volte!\p"
	.string "{STR_VAR_3} deve amare mostrare i\n"
	.string "POKéMON agli altri!$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsTitle::
	.string "Il Maestro delle GARE$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsAction::
	.string "Ha vinto GARE$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Ha vinto GARE\n"
	.string "{STR_VAR_1} volte!\p"
	.string "{STR_VAR_3} dev'essere un\n"
	.string "maestro delle GARE!$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedTitle::
	.string "Lo SHOPPER felice$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedAction::
	.string "Ha comprato$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Ha comprato nei negozi\n"
	.string "{STR_VAR_1} volte!\p"
	.string "{STR_VAR_3} è nato\n"
	.string "per fare compere.$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderTitle::
	.string "L'ALLENATORE cacciatore di oggetti$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderAction::
	.string "Ha usato il DETECTOR$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderStory::
	.string "Ecco la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Ha usato il DETECTOR\n"
	.string "{STR_VAR_1} volte!\p"
	.string "{STR_VAR_3} adora frugare\n"
	.string "il terreno in cerca di oggetti!$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedTitle::
	.string "L'ALLENATORE bagnato$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedAction::
	.string "Preso la pioggia$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "È stato bagnato dalla pioggia\n"
	.string "{STR_VAR_1} volte!\p"
	.string "Il carisma di {STR_VAR_3}\n"
	.string "attira la pioggia!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexTitle::
	.string "L'avido lettore di POKéDEX$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexAction::
	.string "Controllato un POKéDEX$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Ha consultato il POKéDEX\n"
	.string "{STR_VAR_1} volte!\p"
	.string "{STR_VAR_3} adora esaminare\n"
	.string "i POKéMON nel POKéDEX!$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsTitle::
	.string "Il collezionista di FIOCCHI$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsAction::
	.string "Fiocchi ricevuti$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Questo ALLENATORE ha ricevuto FIOCCHI\n"
	.string "{STR_VAR_1} volte!\p"
	.string "{STR_VAR_3} deve amare\n"
	.string "collezionare FIOCCHI!$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedTitle::
	.string "L'ALLENATORE saltadirupi$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedAction::
	.string "Salti giù dai dirupi$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Questo ALLENATORE è saltato dai dirupi\n"
	.string "{STR_VAR_1} volte!\p"
	.string "Se c'è un dirupo da saltare,\n"
	.string "{STR_VAR_3} non può ignorarlo!$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedTitle::
	.string "Il LEGGENDA della TV$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedAction::
	.string "Ha guardato la TV$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Ha guardato la TV\n"
	.string "{STR_VAR_1} volte!\p"
	.string "{STR_VAR_3} adora guardare la TV!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockTitle::
	.string "L'ALLENATORE attento al tempo$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockAction::
	.string "Controllato l'ora$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Questo ALLENATORE ha controllato l'ora\n"
	.string "{STR_VAR_1} volte!\p"
	.string "{STR_VAR_3} dev'essere un ALLENATORE\n"
	.string "puntuale, attento al tempo.$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryTitle::
	.string "Il Mago della LOTTERIA POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryAction::
	.string "Ha vinto alla LOTTERIA POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryStory::
	.string "Ecco la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Ha vinto alla LOTTERIA POKéMON\n"
	.string "{STR_VAR_1} volte!\p"
	.string "{STR_VAR_3} deve avere molti amici\n"
	.string "con cui scambiare POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareTitle::
	.string "L'ALLENATORE della PENSIONE$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareAction::
	.string "Ha lasciato POKéMON alla PENSIONE$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareStory::
	.string "Ecco la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Ha lasciato dei POKéMON alla\n"
	.string "PENSIONE {STR_VAR_1} volte!\p"
	.string "{STR_VAR_3} dev'essere un tipo\n"
	.string "che allena i POKéMON con grinta!$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarTitle::
	.string "L'ALLENATORE della FUNIVIA$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarAction::
	.string "Ha preso la FUNIVIA$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Ha preso la FUNIVIA\n"
	.string "{STR_VAR_1} volte!\p"
	.string "{STR_VAR_3} sarà sempre in giro,\n"
	.string "su e giù tutto il giorno!$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsTitle::
	.string "L'ALLENATORE amante dei bagni termali$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsAction::
	.string "Bagni termali$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Questo ALLENATORE ha fatto il bagno\n"
	.string "alle terme {STR_VAR_1} volte!\p"
	.string "{STR_VAR_3} deve avere una pelle\n"
	.string "liscia come quella di un bebè!$"


MauvilleCity_PokemonCenter_1F_EventScript_Storyteller::
	lock
	faceplayer
	setvar VAR_0x8008, 0
	setvar VAR_0x8009, 0
	setvar VAR_0x800A, 0
	setvar VAR_0x800B, 0
	msgbox MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, StorytellerGetFreeStorySlot
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales
	message MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell
	waitmessage
	special StorytellerStoryListMenu
	waitstate
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection
	setvar VAR_0x8008, 1
	special Script_StorytellerDisplayStory
	waitmessage
	waitbuttonpress
	specialvar VAR_RESULT, StorytellerUpdateStat
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales
	goto MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale

MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection::
	goto MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	end

MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasStorytellerAlreadyRecorded
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd
	goto MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales

MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales, MSGBOX_DEFAULT
MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, Script_StorytellerInitializeRandomStat
	goto_if_eq VAR_RESULT, 1, MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale
	msgbox MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller::
	msgbox MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

@ Unused
MauvilleCity_PokemonCenter_1F_EventScript_WaitingForRecordMix::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd::
	release
	end

@ Giddy
MauvilleCity_PokemonCenter_1F_Text_HearMyStory:
	.string "Sono elettrizzato!\n"
	.string "Ho una storia strepitosa per te!\p"
	.string "Vuoi ascoltare la mia storia?$"

MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues:
	.string "Oh…\n"
	.string "Mi hai lasciato un po' giù…$"

MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking:
	.string "E poi stavo pensando…$"

MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain:
	.string "Direi che è tutto…\p"
	.string "Dobbiamo riparlare!\n"
	.string "Ciao ciao!$"

MauvilleCity_PokemonCenter_1F_EventScript_Giddy::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_HearMyStory, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	end

@ Giddy will continue to tell stories regardless of whether yes or no is selected below.
@ Each story there is a 10% chance it will be his last. Otherwise he will stop at 10 stories.
MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale::
	special GenerateGiddyLine
	special ShowFieldMessageStringVar4
	waitmessage
	yesnobox 20, 8
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy::
	msgbox MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong:
	.string "Ciao, sono il BARDO.\n"
	.string "Vuoi sentire la mia canzone?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1:
	.string "Oh…\n"
	.string "Mi hai lasciato un po' giù…$"

MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers:
	.string "Che canzone commovente…\n"
	.string "Vorrei suonarla per gli altri…$"

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics:
	.string "Allora?\n"
	.string "Ti piace la mia canzone?\p"
	.string "Ma non sono del tutto contento\n"
	.string "del testo.\p"
	.string "Ti va di scrivermi un\n"
	.string "nuovo testo?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2:
	.string "Oh…\n"
	.string "Mi hai lasciato un po' giù…$"

MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou:
	.string "Grazie mille!\n"
	.string "Lascia che te la canti.$"

MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo:
	.string "Volevi che la canzone\n"
	.string "andasse così?$"

MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile:
	.string "Okay! Allora è deciso.\n"
	.string "Canterò questa canzone per un po'.$"

MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening:
	.string "Ehi, ciao! Mi chiamano il TIPO GIUSTO.\n"
	.string "Ti insegno cosa va di moda adesso.$"

MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou:
	.string "Ma ehi, ti ho già insegnato cosa\n"
	.string "va di moda adesso.\p"
	.string "Vorrei diffondere la buona novella\n"
	.string "ad altra gente.$"

MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach:
	.string "Ma ehi, sai già molto su\n"
	.string "cosa va di moda adesso.\p"
	.string "Non ho nulla di nuovo da insegnarti!$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord:
	.string "Ehi, hai mai sentito parlare di\n"
	.string "“{STR_VAR_1}”?\p"
	.string "Che vuol dire? Beh…\n"
	.string "Chiedilo a mamma o papà, okay?$"
