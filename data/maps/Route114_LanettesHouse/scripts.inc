Route114_LanettesHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
	.byte 0

Route114_LanettesHouse_OnTransition:
	setflag FLAG_LANDMARK_LANETTES_HOUSE
	end

Route114_LanettesHouse_EventScript_Lanette::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DOLL_LANETTE, Route114_LanettesHouse_EventScript_OfferAdvice
	setflag FLAG_SYS_PC_LANETTE
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
	givedecoration DECOR_LOTAD_DOLL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowNoRoomForDecor
	setflag FLAG_RECEIVED_DOLL_LANETTE
	release
	end

Route114_LanettesHouse_EventScript_OfferAdvice::
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_Notebook::
	lockall
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage2
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage2::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage3
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage3::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_PC::
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end

Route114_LanettesHouse_Text_EverythingClutteredKeepThis:
	.string "LANETTE: Oh! {PLAYER}{KUN}!\p"
	.string "Scusa per tutto questo disordine…\n"
	.string "Quando mi immergo nella ricerca,\l"
	.string "finisce sempre così…\p"
	.string "Che imbarazzo… Tieni questo e\n"
	.string "non dirlo a nessuno.$"

Route114_LanettesHouse_Text_OrganizeYourBoxes:
	.string "Vuoi un consiglio sul mio Sistema\n"
	.string "di Archivio POKéMON?\p"
	.string "Dovresti organizzare i BOX così sai\n"
	.string "quali POKéMON contengono.$"

Route114_LanettesHouse_Text_ResearchNotesPage1:
	.string "Sono gli appunti di LANETTE.\n"
	.string "Ci sono informazioni sui BOX.\p"
	.string "Progettare BOX da 30 POKéMON ciascuno.\p"
	.string "Ogni ALLENATORE deve poter archiviarne\n"
	.string "420 nel sistema PC.\p"
	.string "Continuare a leggere?$"

Route114_LanettesHouse_Text_ResearchNotesPage2:
	.string "Aggiungere un sistema di contrassegni\n"
	.string "per organizzare meglio i POKéMON.\p"
	.string "Nome e sfondo di ogni BOX saranno\n"
	.string "modificabili per piacere ai POKéMON\l"
	.string "archiviati.\p"
	.string "Continuare a leggere?$"

Route114_LanettesHouse_Text_ResearchNotesPage3:
	.string "Quando si archivia un POKéMON, va\n"
	.string "inviato all'ultimo BOX esaminato.\p"
	.string "Se quel BOX è pieno, il POKéMON\n"
	.string "va nel BOX successivo.\p"
	.string "In altre parole, esaminando un BOX\n"
	.string "lo si seleziona come BOX in cui\l"
	.string "inviare i POKéMON.$"

Route114_LanettesHouse_Text_ClosedTheNotebook:
	.string "{PLAYER} ha chiuso il quaderno.$"

Route114_LanettesHouse_Text_EmailFromBill:
	.string "C'è un'e-mail da qualcuno sul\n"
	.string "PC.\p"
	.string "“… … … … … … …\p"
	.string "“Il tuo Sistema di Archivio è più\n"
	.string "comodo del mio.\p"
	.string "“Ha tante funzioni semplici\n"
	.string "e lo rendono utile e divertente.\p"
	.string "“Sono orgoglioso di aver\n"
	.string "partecipato al suo sviluppo.\p"
	.string "“Spero che continuerai la\n"
	.string "ricerca sui Sistemi di Archivio.\p"
	.string "“Da BILL\n"
	.string "… … … … … … … …”$"

