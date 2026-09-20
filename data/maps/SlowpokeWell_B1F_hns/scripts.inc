SlowpokeWell_B1F_hns_MapScripts::
	.byte 0

SlowpokeWell_B1F_EventScript_Item_Super_Potion_1::
	finditem ITEM_SUPER_POTION
	end

SlowpokeWell_B1F_EventScript_Item_Super_Potion_2::
	finditem ITEM_SUPER_POTION
	end

SlowpokeWell_B1F_EventScript_Item_Great_Ball::
	finditem ITEM_GREAT_BALL
	end

SlowpokeWell_B1F_EventScript_Item_Full_Heal::
	finditem ITEM_FULL_HEAL
	end

SlowpokeWell_B1F_EventScript_Kurt::
	lock
	msgbox SlowpokeWell_B1F_Text_KurtIntro, MSGBOX_DEFAULT
	closemessage
	end

SlowpokeWell_B1F_EventScript_Grunt21::
	trainerbattle_single TRAINER_GRUNT_21_HNS, SlowpokeWell_B1F_Text_GruntM29Seen, SlowpokeWell_B1F_Text_GruntM29Beaten
	msgbox SlowpokeWell_B1F_Text_GruntM29After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Grunt22F::
	trainerbattle_single TRAINER_GRUNT_22_HNS, SlowpokeWell_B1F_Text_GruntF1Seen, SlowpokeWell_B1F_Text_GruntF1Beaten
	msgbox SlowpokeWell_B1F_Text_GruntF1After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Eto::
	trainerbattle_single TRAINER_ETO_HNS, SlowpokeWell_B1F_Text_GruntM2Seen, SlowpokeWell_B1F_Text_GruntM2Beaten
	msgbox SlowpokeWell_B1F_Text_GruntM2After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Proton::
	lock
	faceplayer
	msgbox SlowpokeWell_B1F_Text_ProtonSeen, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_PROTON_1_HNS, SlowpokeWell_B1F_Text_ProtonBeaten
	msgbox SlowpokeWell_B1F_Text_ProtonAfter, MSGBOX_AUTOCLOSE
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_AZALEA_TOWN_ROCKETS
	clearflag FLAG_HIDE_KURT_1
	addobject LOCALID_WELL_KURT
	removeobject 11
	removeobject 12
	removeobject 13
	delay 120
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement LOCALID_WELL_KURT, SlowpokeWell_B1F_Movement_Kurt
	waitmovement 0
	msgbox SlowpokeWell_B1F_Text_KurtAfter, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_SLOWPOKE_WELL_KURT
	setflag FLAG_HIDE_KURT_1
	clearflag FLAG_HIDE_KURT_2
	clearflag FLAG_HIDE_AZALEA_TOWN_SLOWPOKE
	setvar VAR_AZALEA_TOWN_STATE, 3
	warp MAP_AZALEA_TOWN_KURTS_HOUSE_HNS, 15, 4
	waitstate
	end

SlowpokeWell_B1F_Movement_Kurt:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

SlowpokeWell_B1F_Text_KurtIntro:
	.string "KURT: Ehi, {PLAYER}!\p"
	.string "La guardia di sopra è scappata quando\n"
	.string "gli ho urlato contro.\p"
	.string "Ma poi sono caduto\n"
	.string "nel POZZO.\p"
	.string "Ho battuto forte la schiena,\n"
	.string "quindi non mi muovo.\p"
	.string "Accidenti! Se stessi bene, i miei POKéMON\n"
	.string "li avrebbero puniti…\p"
	.string "Ah, non ci posso fare nulla.\p"
	.string "{PLAYER}, mostra loro quanto coraggio\n"
	.string "hai, al posto mio!$"

SlowpokeWell_B1F_Text_KurtAfter:
	.string "KURT: Ben fatto, {PLAYER}!\p"
	.string "Il TEAM ROCKET se n'è andato.\p"
	.string "Anche la mia schiena va meglio.\n"
	.string "Andiamo via di qui.$"

SlowpokeWell_B1F_Text_GruntM29Seen:
	.string "Accidenti! Ero di guardia\n"
	.string "in cima quando un vecchio\l"
	.string "mi ha urlato contro.\p"
	.string "Mi ha spaventato così tanto che\n"
	.string "sono caduto qui.\p"
	.string "Sfogherò la rabbia\n"
	.string "prendendomela con te!$"

SlowpokeWell_B1F_Text_GruntM29Beaten:
	.string "Argh! Non è giornata!$"

SlowpokeWell_B1F_Text_GruntM29After:
	.string "Certo, tagliamo le\n"
	.string "code agli SLOWPOKE e le\l"
	.string "vendiamo.\p"
	.string "Tutto ciò che facciamo è per profitto.\p"
	.string "Proprio così! Siamo il TEAM ROCKET,\n"
	.string "e faremmo di tutto per soldi!$"

SlowpokeWell_B1F_Text_ProtonSeen:
	.string "Cosa vuoi?\p"
	.string "Se interrompi il nostro lavoro,\n"
	.string "non aspettarti pietà!$"

SlowpokeWell_B1F_Text_ProtonBeaten:
	.string "Oggi te la sei cavata,\n"
	.string "ma aspetta la prossima volta!$"

SlowpokeWell_B1F_Text_ProtonAfter:
	.string "Sì, il TEAM ROCKET è stato sciolto\n"
	.string "tre anni fa.\p"
	.string "Il capo si è nascosto.\p"
	.string "Ma noi abbiamo continuato le attività\n"
	.string "in segreto!\p"
	.string "Un piccolo ostacolo come te non sarà\n"
	.string "un problema per la nostra missione.\p"
	.string "Ti consiglio di temere molto\n"
	.string "quello che verrà!$"

SlowpokeWell_B1F_Text_GruntM2Seen:
	.string "Hyuck-hyuck-hyuck!\n"
	.string "Smettere di prendere le CODE?\p"
	.string "Sei matto!\n"
	.string "Se ti obbedissimo, la reputazione\l"
	.string "del TEAM ROCKET sarebbe rovinata!$"

SlowpokeWell_B1F_Text_GruntM2Beaten:
	.string "Hyuck…\n"
	.string "Troppo forte…$"

SlowpokeWell_B1F_Text_GruntM2After:
	.string "Ci servono i soldi,\n"
	.string "ma vendere le CODE DI SLOWPOKE?\p"
	.string "È dura fare la RECLUTA ROCKET!$"

SlowpokeWell_B1F_Text_GruntF1Seen:
	.string "Smettiamo di prendere le CODE?\p"
	.string "Già, prova a batterci\n"
	.string "tutti!$"

SlowpokeWell_B1F_Text_GruntF1Beaten:
	.string "Brutta mocciosa!$"

SlowpokeWell_B1F_Text_GruntF1After:
	.string "Le SLOWPOKETAIL crescono in fretta!\p"
	.string "Cosa c'è di male a venderle?$"

SlowpokeWell_B1F_Text_SlowpokeWithMail:
	.string "Uno SLOWPOKE con la CODA tagliata…\p"
	.string "Eh? Ha una LETTERA.\n"
	.string "Leggerla?$"

SlowpokeWell_B1F_Text_SlowpokeMail:
	.string "{PLAYER} legge la LETTERA.\p"
	.string "Fai il bravo e bada alla\n"
	.string "casa con il nonno e SLOWPOKE.\p"
	.string "Con affetto, papà$"

SlowpokeWell_B1F_Text_TaillessSlowpoke:
	.string "Uno SLOWPOKE con la CODA tagliata…$"
