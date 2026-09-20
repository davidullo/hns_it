NewSinjoh_House4_hns_MapScripts::
	.byte 0

NewSinjoh_Cafe_Script_Sister::
	lock
	faceplayer
	message NewSinjoh_Cafe_Text_ResturantGreeting
	waitmessage
	pokemart NewSinjoh_Cafe_Pokemart_Resturant
	msgbox NewSinjoh_Cafe_Text_ResturantEnd, MSGBOX_DEFAULT
	release
	end

	.align 2
NewSinjoh_Cafe_Pokemart_Resturant:
	.2byte ITEM_YACHE_BERRY
    .2byte ITEM_LANSAT_BERRY
    .2byte ITEM_ROWAP_BERRY
    .2byte ITEM_BERRY_JUICE
	.2byte ITEM_SODA_POP
	.2byte ITEM_LAVA_COOKIE
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_LEEK
	.2byte ITEM_BIG_ROOT
	.2byte ITEM_NONE
	release
	end

NewSinjoh_Cafe_Text_ResturantGreeting:
	.string "C-ciao! Benvenuto al nostro Caffè!\n"
	.string "Come posso aiutarti?$"

NewSinjoh_Cafe_Text_ResturantEnd:
	.string "Torna a trovarci!$"

NewSinjoh_Cafe_EventScript_BaldingMan::
	msgbox NewSinjoh_Cafe_Text_BaldingMan, MSGBOX_NPC
	end

NewSinjoh_Cafe_Text_BaldingMan:
	.string "Una famiglia del posto gestisce\n"
	.string "questo caffè da che\l"
	.string "si ricordi.\p"
	.string "La figlia più piccola, là,\n"
	.string "non è abituata a servire tanti\l"
	.string "stranieri.$"

NewSinjoh_Cafe_EventScript_ScientistF::
	msgbox NewSinjoh_Cafe_Text_ScientistF, MSGBOX_NPC
	end

NewSinjoh_Cafe_Text_ScientistF:
	.string "Questa bevanda è buo--ona!\n"
	.string ".......\p"
	.string ".......\p"
	.string "Hahaha\p"
	.string ".......$"

NewSinjoh_Cafe_EventScript_ScientistM::
	lock
	faceplayer
	msgbox NewSinjoh_Cafe_Text_ScientistM, MSGBOX_DEFAULT
	closemessage
	release
	end

NewSinjoh_Cafe_Text_ScientistM:
	.string "Perdona la mia collega...\p"
	.string "Le bevande qui sono più forti\n"
	.string "di quelle a cui siamo abituati a HOENN.\p"
	.string "L'avevo avvertita, ma ha detto\n"
	.string "che doveva distendersi.\p"
	.string "Questa spedizione è stata\n"
	.string "dura per tutti noi.$"

NewSinjoh_Cafe_EventScript_Gentleman::
	msgbox NewSinjoh_Cafe_Text_Gentleman, MSGBOX_NPC
	end

NewSinjoh_Cafe_Text_Gentleman:
	.string "Cosa guardi, ragazzo?\p"
	.string "Non c'è niente di male se un uomo e il suo\n"
	.string "POKéMON mangiano allo stesso tavolo.$"

NewSinjoh_EventScript_Scyther::
	lock
	faceplayer
	playmoncry SPECIES_SCYTHER, 0
	msgbox NewSinjoh_Text_Scyther, MSGBOX_DEFAULT
	waitmoncry
    closemessage
	release
	end

NewSinjoh_Text_Scyther:
	.string "Scyyy!$"
