SaffronCity_CopyCatsHouse_2F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_CopyCatsHouse_2F_OnTransition
	.byte 0

SaffronCity_CopyCatsHouse_2F_OnTransition::
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_3
	end

@VAR_FAN_CLUB_CLEFAIRY

SaffronCity_CopyCatsHouse_2F_EventScript_Dodrio::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DODRIO, CRY_MODE_NORMAL
	msgbox Copycat_Text_Dodrio1, MSGBOX_DEFAULT
	waitmoncry
	msgbox Copycat_Text_Dodrio2, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_CopyCatsHouse_2F_EventScript_Dolls::
	msgbox Copycat_Text_2FDoll, MSGBOX_SIGN
	end

SaffronCity_CopyCatsHouse_2F_EventScript_Copycat::
	lock
	faceplayer
	goto_if_ge VAR_FAN_CLUB_CLEFAIRY, 3, SaffronCity_CopyCatsHouse_2F_EventScript_CopycatAfterDollReturned
	goto_if_eq VAR_FAN_CLUB_CLEFAIRY, 2, SaffronCity_CopyCatsHouse_2F_EventScript_CopycatReturnDoll
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_CopyCatsHouse_2F_EventScript_CopycatReturnedMachinePart
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, SaffronCity_CopyCatsHouse_2F_EventScript_Copycat1_Male
	goto_if_eq VAR_RESULT, FEMALE, SaffronCity_CopyCatsHouse_2F_EventScript_Copycat1_Female

SaffronCity_CopyCatsHouse_2F_EventScript_Copycat1_Male::
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_COPYCAT
	clearflag FLAG_TEMP_3
	addobject LOCALID_GOLD
	applymovement LOCALID_GOLD, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_GOLD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_Male_1, MSGBOX_NPC
	applymovement LOCALID_GOLD, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_GOLD
	clearflag FLAG_TEMP_1
	addobject LOCALID_COPYCAT
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_COPYCAT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_QuickMimicking, MSGBOX_NPC
	closemessage
	release
	end

SaffronCity_CopyCatsHouse_2F_EventScript_Copycat1_Female::
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_COPYCAT
	clearflag FLAG_TEMP_2
	addobject LOCALID_KRIS
	applymovement LOCALID_KRIS, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_KRIS, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_Male_1, MSGBOX_NPC
	applymovement LOCALID_KRIS, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_KRIS
	clearflag FLAG_TEMP_1
	addobject LOCALID_COPYCAT
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_COPYCAT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_QuickMimicking, MSGBOX_NPC
	closemessage
	release
	end

SaffronCity_CopyCatsHouse_2F_EventScript_CopycatReturnedMachinePart::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, SaffronCity_CopyCatsHouse_2F_EventScript_CopycatReturnedMachinePart_Male
	goto_if_eq VAR_RESULT, FEMALE, SaffronCity_CopyCatsHouse_2F_EventScript_CopycatReturnedMachinePart_Female

SaffronCity_CopyCatsHouse_2F_EventScript_CopycatReturnedMachinePart_Male::
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_COPYCAT
	clearflag FLAG_TEMP_3
	addobject LOCALID_GOLD
	applymovement LOCALID_GOLD, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_GOLD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_Male_2, MSGBOX_NPC
	applymovement LOCALID_GOLD, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_GOLD
	clearflag FLAG_TEMP_1
	addobject LOCALID_COPYCAT
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_COPYCAT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_Worried, MSGBOX_NPC
	closemessage
	setvar VAR_FAN_CLUB_CLEFAIRY, 1
	end

SaffronCity_CopyCatsHouse_2F_EventScript_CopycatReturnedMachinePart_Female::
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_COPYCAT
	clearflag FLAG_TEMP_2
	addobject LOCALID_KRIS
	applymovement LOCALID_KRIS, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_KRIS, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_Male_2, MSGBOX_NPC
	applymovement LOCALID_KRIS, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_KRIS
	clearflag FLAG_TEMP_1
	addobject LOCALID_COPYCAT
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_COPYCAT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_Worried, MSGBOX_NPC
	closemessage
	setvar VAR_FAN_CLUB_CLEFAIRY, 1
	end

SaffronCity_CopyCatsHouse_2F_EventScript_CopycatReturnDoll::
	msgbox Copycat_Text_GiveDoll, MSGBOX_DEFAULT
	fadescreenswapbuffers FADE_TO_BLACK
	removeitem ITEM_LOST_ITEM
	clearflag FLAG_HIDE_COPYCAT_CLEFAIRY_DOLL
	addobject LOCALID_COPYCAT_CLEFAIRY
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox Copycat_Text_GivePass, MSGBOX_DEFAULT
	giveitem ITEM_PASS
	msgbox Copycat_Text_ExplainPass, MSGBOX_DEFAULT
	closemessage
	setvar VAR_FAN_CLUB_CLEFAIRY, 3
	release
	end

SaffronCity_CopyCatsHouse_2F_EventScript_CopycatAfterDollReturned::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, SaffronCity_CopyCatsHouse_2F_EventScript_CopycatAfterDollReturned_Male
	goto_if_eq VAR_RESULT, FEMALE, SaffronCity_CopyCatsHouse_2F_EventScript_CopycatAfterDollReturned_Female

SaffronCity_CopyCatsHouse_2F_EventScript_CopycatAfterDollReturned_Male::
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_COPYCAT
	clearflag FLAG_TEMP_3
	addobject LOCALID_GOLD
	applymovement LOCALID_GOLD, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_GOLD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_Male_3, MSGBOX_NPC
	applymovement LOCALID_GOLD, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_GOLD
	clearflag FLAG_TEMP_1
	addobject LOCALID_COPYCAT
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_COPYCAT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_ItsAScream, MSGBOX_NPC
	closemessage
	end

SaffronCity_CopyCatsHouse_2F_EventScript_CopycatAfterDollReturned_Female::
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_COPYCAT
	clearflag FLAG_TEMP_2
	addobject LOCALID_KRIS
	applymovement LOCALID_KRIS, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_KRIS, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_Male_3, MSGBOX_NPC
	applymovement LOCALID_KRIS, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_KRIS
	clearflag FLAG_TEMP_1
	addobject LOCALID_COPYCAT
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_COPYCAT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_ItsAScream, MSGBOX_NPC
	closemessage
	end

Copycat_Text_Male_1:
	.string "{PLAYER}: Ciao! Ti piacciono i POKéMON?\p"
	.string "{PLAYER}: No, ti ho chiesto io.\p"
	.string "{PLAYER}: Eh? Sei strano!$"

Copycat_Text_QuickMimicking:
	.string "COPIONA: Hmm? Smettere di imitare?\p"
	.string "Ma è il mio hobby preferito!$"

Copycat_Text_Male_2:
	.string "{PLAYER}: Ciao! Ho saputo che\n"
	.string "hai perso il tuo POKé DOLL.\p"
	.string "{PLAYER}: Se lo trovo, mi dai\n"
	.string "un SUPERpass?\p"
	.string "{PLAYER}: Vado a cercarlo per te.\p"
	.string "Pensi di averlo perso quando\n"
	.string "sei andata a VERMILION CITY?$"

Copycat_Text_Worried:
	.string "COPIONA: Come?\p"
	.string "Non dovrei decidere io cosa\n"
	.string "devi fare?\p"
	.string "Ma sono preoccupata… E se\n"
	.string "qualcuno lo trova?$"

Copycat_Text_GiveDoll:
	.string "COPIONA: Evviva! È il mio POKé DOLL\n"
	.string "di CLEFAIRY!\p"
	.string "Vedi lo strappo dove è cucita\n"
	.string "la zampa destra? È la prova!$"

Copycat_Text_GivePass:
	.string "OK. Ecco il SUPERpass del MAGNET TRAIN,\n"
	.string "come promesso!$"

Copycat_Text_ExplainPass:
	.string "COPIONA: È il SUPERpass per il\n"
	.string "MAGNET TRAIN.\p"
	.string "Me l'ha dato l'uomo della\n"
	.string "ferrovia quando hanno demolito\l"
	.string "casa nostra per la STAZIONE.$"

Copycat_Text_Male_3:
	.string "{PLAYER}: Ciao! Grazie mille per il\n"
	.string "SUPERpass!\p"
	.string "{PLAYER}: Come?\p"
	.string "{PLAYER}: Ti diverte così tanto imitare\n"
	.string "ogni mia mossa?$"

Copycat_Text_ItsAScream:
	.string "COPIONA: Certo! È uno spasso!$"

Copycat_Text_Dodrio1:
	.string "DODRIO: Ghiii ghiii!$"

Copycat_Text_Dodrio2:
	.string "SPECCHIO, SPECCHIO DELLE MIE BRAME,\n"
	.string "CHI È LA PIÙ BELLA DEL REAME?$"

Copycat_Text_2FDoll:
	.string "Questo è un POKéMON raro! Eh?\p"
	.string "È solo una bambola…$"
