ViridianCity_School_Frlg_MapScripts::
	.byte 0

ViridianCity_School_EventScript_Lass::
	lock
	faceplayer
	msgbox ViridianCity_School_Text_TryingToMemorizeNotes
	closemessage
	applymovement LOCALID_SCHOOL_LASS, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

ViridianCity_School_EventScript_Woman::
	lock
	faceplayer
	msgbox ViridianCity_School_Text_ReadBlackboardCarefully
	closemessage
	applymovement LOCALID_SCHOOL_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

ViridianCity_School_EventScript_Notebook::
	lockall
	msgbox ViridianCity_School_Text_NotebookFirstPage
	msgbox ViridianCity_School_Text_TurnThePage, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_School_EventScript_StopReadingNotebook
	msgbox ViridianCity_School_Text_NotebookSecondPage
	msgbox ViridianCity_School_Text_TurnThePage, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_School_EventScript_StopReadingNotebook
	msgbox ViridianCity_School_Text_NotebookThirdPage
	msgbox ViridianCity_School_Text_TurnThePage, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_School_EventScript_StopReadingNotebook
	msgbox ViridianCity_School_Text_NotebookFourthPage
	applymovement LOCALID_SCHOOL_LASS, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox ViridianCity_School_Text_HeyDontLookAtMyNotes
	releaseall
	end

ViridianCity_School_EventScript_StopReadingNotebook::
	releaseall
	end

ViridianCity_School_EventScript_Blackboard::
	lockall
	msgbox ViridianCity_School_Text_BlackboardListsStatusProblems
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ChooseBlackboardTopic::
	message ViridianCity_School_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 7, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, ViridianCity_School_EventScript_ReadSleep
	case 1, ViridianCity_School_EventScript_ReadPoison
	case 2, ViridianCity_School_EventScript_ReadParalysis
	case 3, ViridianCity_School_EventScript_ReadBurn
	case 4, ViridianCity_School_EventScript_ReadFreeze
	case 5, ViridianCity_School_EventScript_ExitBlackboard
	case 127, ViridianCity_School_EventScript_ExitBlackboard
	end

ViridianCity_School_EventScript_ReadSleep::
	msgbox ViridianCity_School_Text_ExplainSleep
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ReadBurn::
	msgbox ViridianCity_School_Text_ExplainBurn
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ReadPoison::
	msgbox ViridianCity_School_Text_ExplainPoison
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ReadFreeze::
	msgbox ViridianCity_School_Text_ExplainFreeze
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ReadParalysis::
	msgbox ViridianCity_School_Text_ExplainParalysis
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ExitBlackboard::
	releaseall
	end

ViridianCity_School_Text_TryingToMemorizeNotes::
	.string "Uff! Sto cercando di imparare a\n"
	.string "memoria tutti i miei appunti.$"

ViridianCity_School_Text_ReadBlackboardCarefully::
	.string "Okay!\p"
	.string "Leggi con attenzione quello che\n"
	.string "c'è scritto sulla lavagna!$"

ViridianCity_School_Text_NotebookFirstPage::
	.string "Diamo un'occhiata al quaderno.\p"
	.string "Prima pagina…\p"
	.string "Le POKé BALL servono a catturare\n"
	.string "i POKéMON.\p"
	.string "Puoi portare fino a sei POKéMON\n"
	.string "nella tua squadra.\p"
	.string "Chi alleva e fa lottare i POKéMON\n"
	.string "si chiama ALLENATORE.$"

ViridianCity_School_Text_NotebookSecondPage::
	.string "Seconda pagina…\p"
	.string "Un POKéMON in salute è difficile\n"
	.string "da catturare, prima indeboliscilo.\p"
	.string "Avvelenalo, scottalo o dagli un\n"
	.string "altro problema di stato.$"

ViridianCity_School_Text_NotebookThirdPage::
	.string "Terza pagina…\p"
	.string "Gli ALLENATORI cercano altri per\n"
	.string "fare lotte POKéMON.\p"
	.string "Per loro il sapore della vittoria\n"
	.string "è davvero dolce.\p"
	.string "Si lotta di continuo nelle\n"
	.string "PALESTRE POKéMON ovunque.$"

ViridianCity_School_Text_NotebookFourthPage::
	.string "Quarta pagina…\p"
	.string "L'obiettivo di ogni ALLENATORE di\n"
	.string "POKéMON è semplice.\p"
	.string "Battere i primi otto\n"
	.string "CAPOPALESTRA POKéMON.\p"
	.string "Così otterrai il diritto di sfidare…\p"
	.string "I SUPERQUATTRO della LEGA\n"
	.string "POKéMON!$"

ViridianCity_School_Text_TurnThePage::
	.string "Girare la pagina?$"

ViridianCity_School_Text_HeyDontLookAtMyNotes::
	.string "RAGAZZA: Ehi!\n"
	.string "Non guardare i miei appunti!$"

ViridianCity_School_Text_BlackboardListsStatusProblems::
	.string "La lavagna elenca i problemi di\n"
	.string "STATO dei POKéMON in lotta.$"

ViridianCity_School_Text_ReadWhichTopic::
	.string "Quale argomento vuoi leggere?$"

ViridianCity_School_Text_ExplainSleep::
	.string "Un POKéMON non può attaccare se\n"
	.string "è addormentato.\p"
	.string "Resta addormentato anche dopo\n"
	.string "la fine della lotta.\p"
	.string "Usa la SVEGLIA per risvegliarlo\n"
	.string "dal sonno.$"

ViridianCity_School_Text_ExplainBurn::
	.string "Una scottatura riduce l'ATTACCO.\n"
	.string "Inoltre fa perdere PS a ogni turno.\p"
	.string "La scottatura resta dopo la lotta.\n"
	.string "Usa l'ANTISCOTTATURA per curarla.$"

ViridianCity_School_Text_ExplainPoison::
	.string "Un POKéMON avvelenato perde PS\n"
	.string "poco alla volta.\p"
	.string "Il veleno resta dopo la lotta.\n"
	.string "Usa l'ANTIDOTO per curare il veleno!$"

ViridianCity_School_Text_ExplainFreeze::
	.string "Un POKéMON congelato non può\n"
	.string "muoversi per niente.\p"
	.string "Resta congelato anche dopo la\n"
	.string "fine della lotta.\p"
	.string "Usa il DISGELO per scongelare il\n"
	.string "povero POKéMON.$"

ViridianCity_School_Text_ExplainParalysis::
	.string "La paralisi riduce la VELOCITÀ e\n"
	.string "può impedire di muoversi.\p"
	.string "La paralisi resta dopo la lotta.\n"
	.string "Usa l'ANTIPARALISI per curarla.$"

