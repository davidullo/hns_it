RustboroCity_Flat1_2F_MapScripts::
	.byte 0

RustboroCity_Flat1_2F_EventScript_WaldasDad::
	lock
	faceplayer
	specialvar VAR_RESULT, TryBufferWaldaPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase

RustboroCity_Flat1_2F_EventScript_GivePhrase::
	special DoWaldaNamingScreen
	waitstate
	goto_if_eq VAR_0x8004, 1, RustboroCity_Flat1_2F_EventScript_CancelGivePhrase
	goto_if_eq VAR_0x8004, 2, RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase
	specialvar VAR_RESULT, TryGetWallpaperWithWaldaPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase::
	msgbox RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhIsThatRight, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhYouDontKnowAny, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry2, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_OhShesLaughing, MSGBOX_DEFAULT
	applymovement LOCALID_WALDAS_DAD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda::
	turnobject LOCALID_WALDAS_DAD, DIR_EAST
	return

RustboroCity_Flat1_2F_EventScript_WaldasMom::
	msgbox RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard, MSGBOX_NPC
	end

RustboroCity_Flat1_2F_EventScript_PokeDoll::
	msgbox RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll, MSGBOX_SIGN
	end

RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard:
	.string "Oh, è così difficile ogni giorno…\p"
	.string "Cosa è difficile?\n"
	.string "Devo chiedertelo?\p"
	.string "Cercare di capire cosa\n"
	.string "preparare per i pasti ogni giorno.\p"
	.string "Non è affatto facile inventarsi\n"
	.string "i pasti ogni giorno.$"

RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase:
	.string "Oh, ciao!\n"
	.string "Benvenuto dalla famiglia PEPPER.\p"
	.string "Ho una domanda per te.\n"
	.string "Hai mai fatto il baby-sitter?\p"
	.string "Vedi, sono un papà novello, allevare\n"
	.string "un figlio è tutto nuovo per me.\p"
	.string "E ho un problema. Mia figlia\n"
	.string "WALDA non ride abbastanza.\p"
	.string "Riderebbe, credo, se le dicessi\n"
	.string "qualcosa di divertente.\p"
	.string "Conosci una parola o una\n"
	.string "frase buffa da dirmi?$"

RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase:
	.string "Ultimamente le dico “{STR_VAR_1}”\n"
	.string "per farla ridere.\p"
	.string "Conosci una parola o\n"
	.string "una frase migliore?$"

RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion:
	.string "Oh, che meraviglia.\n"
	.string "Allora sentiamo, il tuo suggerimento.$"

RustboroCity_Flat1_2F_Text_OhIsThatRight:
	.string "Oh, davvero?\p"
	.string "Beh, se ti viene in mente un buon\n"
	.string "suggerimento, sono tutto orecchie.$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry2:
	.string "Ah, capisco.\n"
	.string "Beh, proviamo, che ne dici?$"

RustboroCity_Flat1_2F_Text_OhShesLaughing:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Oh, sì! Sta ridendo!\n"
	.string "Oh, sono felice quanto lei!$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry:
	.string "Ah, capisco.\n"
	.string "Beh, proviamo, che ne dici?$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Mmm… Non sta sorridendo affatto.\n"
	.string "Forse WALDA è una bambina seria…$"

RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase:
	.string "Oh, quindi non conosci parole belle.\n"
	.string "Meglio che ci pensi da solo, allora.\p"
	.string "Mmm…\n"
	.string "Che ne dici di “{STR_VAR_1}”?\l"
	.string "Vediamo se funziona.$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Mmm… Non sta sorridendo affatto.\n"
	.string "Forse WALDA è una bambina seria…$"

RustboroCity_Flat1_2F_Text_OhYouDontKnowAny:
	.string "Oh, quindi non conosci parole belle.\n"
	.string "Credo che proverò a farla ridere con\l"
	.string "la frase di prima.\p"
	.string "Comunque, se hai un buon suggerimento,\n"
	.string "non esitare a dirmelo, okay?$"

RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper:
	.string "Grazie!\p"
	.string "Grazie a te, la mia WALDA\n"
	.string "ha riso per me!\p"
	.string "In realtà posso non sembrare\n"
	.string "speciale, ma sono uno dei migliori\l"
	.string "ricercatori della DEVON CORPORATION.\p"
	.string "Quindi, che ne dici se ti ricambio\n"
	.string "il favore?\p"
	.string "Ecco, aggiungerò nuovi motivi\n"
	.string "di sfondo per i BOX nel sistema\l"
	.string "di archiviazione POKéMON del PC.\p"
	.string "Nel menu dei motivi di sfondo,\n"
	.string "seleziona “AMICI”.\p"
	.string "Così avrai accesso ai nuovi\n"
	.string "motivi di sfondo.$"

RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll:
	.string "È un PELUCHE POKéMON!$"

