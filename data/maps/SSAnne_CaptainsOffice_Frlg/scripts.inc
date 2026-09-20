SSAnne_CaptainsOffice_Frlg_MapScripts::
	.byte 0

SSAnne_CaptainsOffice_EventScript_Captain::
	lock
	goto_if_set FLAG_GOT_HM01, SSAnne_CaptainsOffice_EventScript_AlreadyGotCut
	msgbox SSAnne_CaptainsOffice_Text_CaptainIFeelSeasick
	textcolor NPC_TEXT_COLOR_NEUTRAL
	message SSAnne_CaptainsOffice_Text_RubbedCaptainsBack
	waitmessage
	playfanfare MUS_HEAL
	waitfanfare
	call EventScript_RestorePrevTextColor
	delay 50
	applymovement LOCALID_SS_ANNE_CAPTAIN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SSAnne_CaptainsOffice_Text_ThankYouHaveHMForCut
	giveitem_msg SSAnne_CaptainsOffice_Text_ObtainedHM01FromCaptain, ITEM_HM01, 1, MUS_RG_OBTAIN_KEY_ITEM
	msgbox SSAnne_CaptainsOffice_Text_ExplainCut
	setflag FLAG_GOT_HM01
	setvar VAR_MAP_SCENE_VERMILION_CITY, 1
	release
	end

@ Unused
SSAnne_CaptainsOffice_EventScript_NoRoomForCut::
	msgbox SSAnne_CaptainsOffice_Text_YouHaveNoRoomForThis
	closemessage
	applymovement LOCALID_SS_ANNE_CAPTAIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SSAnne_CaptainsOffice_EventScript_AlreadyGotCut::
	applymovement LOCALID_SS_ANNE_CAPTAIN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SSAnne_CaptainsOffice_Text_SSAnneWillSetSailSoon
	release
	end

SSAnne_CaptainsOffice_EventScript_TrashCan::
	msgbox SSAnne_CaptainsOffice_Text_YuckShouldntHaveLooked, MSGBOX_SIGN
	end

SSAnne_CaptainsOffice_EventScript_Book::
	msgbox SSAnne_CaptainsOffice_Text_HowToConquerSeasickness, MSGBOX_SIGN
	end

SSAnne_CaptainsOffice_Text_CaptainIFeelSeasick::
	.string "CAPITANO: Ooargh…\n"
	.string "Sto malissimo…\l"
	.string "Urrp! Mal di mare…$"

SSAnne_CaptainsOffice_Text_RubbedCaptainsBack::
	.string "{PLAYER} ha massaggiato la\n"
	.string "schiena del CAPITANO!\p"
	.string "Fric-fric…\n"
	.string "Fric-fric…$"

SSAnne_CaptainsOffice_Text_ThankYouHaveHMForCut::
	.string "CAPITANO: Fiuu! Grazie!\n"
	.string "Ora mi sento molto meglio.\p"
	.string "Vuoi vedere la mia tecnica\n"
	.string "segreta di TAGLIO?\p"
	.string "Ti mostrerei il mio TAGLIO\n"
	.string "se non fossi così malato…\p"
	.string "Ci sono! Prendi questo!\n"
	.string "Questa MACCHINA NASCOSTA!\p"
	.string "Insegna TAGLIO ai POKéMON e\n"
	.string "potrai TAGLIARE quando vuoi!$"

SSAnne_CaptainsOffice_Text_ObtainedHM01FromCaptain::
	.string "{PLAYER} ha ottenuto la MN01\n"
	.string "dal CAPITANO!$"

SSAnne_CaptainsOffice_Text_ExplainCut::
	.string "Con TAGLIO puoi abbattere\n"
	.string "i piccoli alberi.\p"
	.string "Perché non provi sugli alberi\n"
	.string "di VERMILION CITY?$"

SSAnne_CaptainsOffice_Text_SSAnneWillSetSailSoon::
	.string "CAPITANO: …Fiuu!\p"
	.string "Ora che sto meglio,\n"
	.string "credo sia ora.\p"
	.string "La S.S. ANNE salperà presto!\p"
	.string "Addio, al nostro ritorno a\n"
	.string "VERMILION CITY!$"

SSAnne_CaptainsOffice_Text_YouHaveNoRoomForThis::
	.string "Oh, no!\n"
	.string "Non hai spazio per questo!$"

SSAnne_CaptainsOffice_Text_YuckShouldntHaveLooked::
	.string "Che schifo!\n"
	.string "Non dovevo guardare!$"

SSAnne_CaptainsOffice_Text_HowToConquerSeasickness::
	.string "Come vincere il mal di mare…\n"
	.string "Il CAPITANO sta leggendo questo!$"

