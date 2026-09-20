PetalburgCity_WallysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_WallysHouse_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_WallysHouse_OnWarp
	.byte 0

PetalburgCity_WallysHouse_OnWarp:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther
	.2byte 0

PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther::
	turnobject LOCALID_PLAYER, DIR_EAST
	turnobject LOCALID_WALLYS_HOUSE_WALLYS_DAD, DIR_WEST
	end

PetalburgCity_WallysHouse_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_GiveHMSurf
	.2byte 0

PetalburgCity_WallysHouse_EventScript_GiveHMSurf::
	lockall
	msgbox PetalburgCity_WallysHouse_Text_PleaseExcuseUs, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_CITY_STATE, 5
	releaseall
	end

PetalburgCity_WallysHouse_EventScript_WallysDad::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, PetalburgCity_WallysHouse_EventScript_PlayedWithWally
	msgbox PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally, MSGBOX_DEFAULT
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad::
	msgbox PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_PlayedWithWally::
	msgbox PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_WallysMom::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf
	msgbox PetalburgCity_WallysHouse_Text_WallyWasReallyHappy, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally:
	.string "Tu sei…\n"
	.string "Ah, devi essere {PLAYER}{KUN}, vero?\p"
	.string "Grazie per aver giocato con WALLY\n"
	.string "poco fa.\p"
	.string "È sempre stato fragile e malaticcio\n"
	.string "fin da quando era Bebè.\p"
	.string "L'abbiamo mandato da miei parenti\n"
	.string "a VERDANTURF per un po'.\p"
	.string "L'aria è molto più pulita lì\n"
	.string "che qui.\p"
	.string "Come? Dov'è WALLY?\n"
	.string "È già partito, il nostro WALLY.\p"
	.string "Chissà dove sarà\n"
	.string "arrivato ormai?$"

PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing:
	.string "Chissà come sta il nostro WALLY?$"

PetalburgCity_WallysHouse_Text_PleaseExcuseUs:
	.string "{PLAYER}{KUN}! Scusa se ti abbiamo\n"
	.string "trascinato qui così.\p"
	.string "Ma il nostro WALLY è molto più sano\n"
	.string "da quando è andato a VERDANTURF.\p"
	.string "È merito tuo!\p"
	.string "Quando WALLY lasciò la città, l'hai\n"
	.string "aiutato a catturare un POKéMON, vero?\p"
	.string "Credo che questo abbia reso WALLY\n"
	.string "davvero felice.\p"
	.string "Anzi, non solo WALLY.\n"
	.string "Ha reso felice anche me, suo padre.\p"
	.string "Felice che abbia trovato un amico\n"
	.string "speciale come te.\p"
	.string "Non è una ricompensa, ma\n"
	.string "vorrei davvero che prendessi questo.$"

PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces:
	.string "Se il tuo POKéMON sa usare SURF, potrai\n"
	.string "andare in tantissimi posti.$"

PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon:
	.string "WALLY's coming home soon.\n"
	.string "I'm looking forward to that.$"

PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity:
	.string "Oh? You met WALLY in\n"
	.string "EVER GRANDE CITY?\p"
	.string "Oh, {PLAYER}{KUN}, don't be silly.\p"
	.string "He may have gotten healthy, but he\n"
	.string "can't go somewhere far away like\l"
	.string "that all by himself.$"

PetalburgCity_WallysHouse_Text_WallyWasReallyHappy:
	.string "WALLY era davvero felice quando ci ha\n"
	.string "detto che aveva catturato un POKéMON.\p"
	.string "Era da tanto che non lo vedevo\n"
	.string "sorridere così.$"

PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling:
	.string "Voglio che tu tenga il segreto\n"
	.string "con mio marito…\p"
	.string "Ma il nostro WALLY ha lasciato PORTOALTO\n"
	.string "senza dirlo a nessuno.\p"
	.string "Sai, WALLY è fragile, ma\n"
	.string "ha una volontà di ferro.\p"
	.string "Sono certa che tornerà sano\n"
	.string "e salvo un giorno!$"

