.set SPOKE_TO_WOMAN_LAST,   FLAG_TEMP_2
.set SPOKE_TO_FAT_MAN_LAST, FLAG_TEMP_3

VermilionCity_PokemonFanClub_Frlg_MapScripts::
	.byte 0

VermilionCity_PokemonFanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BIKE_VOUCHER, VermilionCity_PokemonFanClub_EventScript_AlreadyHeardStory
	msgbox VermilionCity_PokemonFanClub_Text_DidYouComeToHearAboutMyMons, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, VermilionCity_PokemonFanClub_EventScript_ChairmanStory
	msgbox VermilionCity_PokemonFanClub_Text_ComeBackToHearStory
	release
	end

VermilionCity_PokemonFanClub_EventScript_AlreadyHeardStory::
	msgbox VermilionCity_PokemonFanClub_Text_DidntComeToSeeAboutMonsAgain
	release
	end

VermilionCity_PokemonFanClub_EventScript_ChairmanStory::
	msgbox VermilionCity_PokemonFanClub_Text_ChairmansStory
	checkitemspace ITEM_BIKE_VOUCHER
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_PokemonFanClub_EventScript_NoRoomForBikeVoucher
	setflag FLAG_GOT_BIKE_VOUCHER
	giveitem_msg VermilionCity_PokemonFanClub_Text_ReceivedBikeVoucherFromChairman, ITEM_BIKE_VOUCHER, 1, MUS_RG_OBTAIN_KEY_ITEM
	msgbox VermilionCity_PokemonFanClub_Text_ExplainBikeVoucher
	release
	end

VermilionCity_PokemonFanClub_EventScript_NoRoomForBikeVoucher::
	msgbox VermilionCity_PokemonFanClub_Text_MakeRoomForThis
	release
	end

VermilionCity_PokemonFanClub_EventScript_WorkerF::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, VermilionCity_PokemonFanClub_EventScript_WorkerFGameClear
	msgbox VermilionCity_PokemonFanClub_Text_ChairmanVeryVocalAboutPokemon
	release
	end

VermilionCity_PokemonFanClub_EventScript_WorkerFGameClear::
	famechecker FAMECHECKER_DAISY, 1
	msgbox VermilionCity_PokemonFanClub_Text_ChairmanReallyAdoresHisMons
	release
	end

VermilionCity_PokemonFanClub_EventScript_Woman::
	lock
	faceplayer
	goto_if_set SPOKE_TO_FAT_MAN_LAST, VermilionCity_PokemonFanClub_EventScript_WomanSpokeToFatMan
	msgbox VermilionCity_PokemonFanClub_Text_AdoreMySeel
	closemessage
	applymovement LOCALID_POKEMON_FAN_CLUB_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag SPOKE_TO_WOMAN_LAST
	release
	end

VermilionCity_PokemonFanClub_EventScript_WomanSpokeToFatMan::
	msgbox VermilionCity_PokemonFanClub_Text_SeelFarMoreAttractive
	closemessage
	applymovement LOCALID_POKEMON_FAN_CLUB_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	clearflag SPOKE_TO_FAT_MAN_LAST
	release
	end

VermilionCity_PokemonFanClub_EventScript_FatMan::
	lock
	faceplayer
	goto_if_set SPOKE_TO_WOMAN_LAST, VermilionCity_PokemonFanClub_EventScript_FatManSpokeToWoman
	msgbox VermilionCity_PokemonFanClub_Text_AdmirePikachusTail
	closemessage
	applymovement LOCALID_POKEMON_FAN_CLUB_FAT_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag SPOKE_TO_FAT_MAN_LAST
	release
	end

VermilionCity_PokemonFanClub_EventScript_FatManSpokeToWoman::
	msgbox VermilionCity_PokemonFanClub_Text_PikachuTwiceAsCute
	closemessage
	applymovement LOCALID_POKEMON_FAN_CLUB_FAT_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	clearflag SPOKE_TO_WOMAN_LAST
	release
	end

VermilionCity_PokemonFanClub_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox VermilionCity_PokemonFanClub_Text_Pikachu
	waitmoncry
	release
	end

VermilionCity_PokemonFanClub_EventScript_Seel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SEEL, CRY_MODE_NORMAL
	msgbox VermilionCity_PokemonFanClub_Text_Seel
	waitmoncry
	release
	end

VermilionCity_PokemonFanClub_EventScript_RulesSign1::
	msgbox VermilionCity_PokemonFanClub_Text_ListenPolitelyToOtherTrainers, MSGBOX_SIGN
	end

VermilionCity_PokemonFanClub_EventScript_RulesSign2::
	msgbox VermilionCity_PokemonFanClub_Text_SomeoneBragsBragBack, MSGBOX_SIGN
	end

VermilionCity_PokemonFanClub_Text_AdmirePikachusTail::
	.string "Non ammiri la splendida\n"
	.string "coda del mio PIKACHU?$"

VermilionCity_PokemonFanClub_Text_PikachuTwiceAsCute::
	.string "Umpf!\p"
	.string "Il mio PIKACHU è il doppio più\n"
	.string "carino di quello!$"

VermilionCity_PokemonFanClub_Text_AdoreMySeel::
	.string "Adoro il mio SEEL!\n"
	.string "È così adorabile!\p"
	.string "Fa “Kyuuuh” quando lo\n"
	.string "abbraccio!$"

VermilionCity_PokemonFanClub_Text_SeelFarMoreAttractive::
	.string "Oh, cielo!\p"
	.string "Il mio SEEL è molto più attraente.\n"
	.string "Direi il doppio.$"

VermilionCity_PokemonFanClub_Text_Pikachu::
	.string "PIKACHU: Chu! Pikachu!$"

VermilionCity_PokemonFanClub_Text_Seel::
	.string "SEEL: Kyuoo!$"

VermilionCity_PokemonFanClub_Text_DidYouComeToHearAboutMyMons::
	.string "Presiedo il FAN CLUB POKéMON!\p"
	.string "Allevo più di cento\n"
	.string "POKéMON!\p"
	.string "Sono molto pignolo quando si tratta\n"
	.string "di POKéMON! Proprio così!\p"
	.string "Allora…\p"
	.string "Sei venuto a sentire parlare\n"
	.string "dei miei POKéMON?$"

VermilionCity_PokemonFanClub_Text_ChairmansStory::
	.string "Bene!\n"
	.string "Allora ascolta!\p"
	.string "Il mio RAPIDASH preferito…\p"
	.string "È…carino…adorabile…intelligente… \n"
	.string "poi…stupendo…dici così?…\l"
	.string "oh sì…è…sbalorditivo…\l"
	.string "gentile…lo adoro!\p"
	.string "Lo abbraccio…quando…dorme…caldo\n"
	.string "e coccoloso…spettacolare…\l"
	.string "meraviglioso…\l"
	.string "…Ops! Guarda l'ora!\l"
	.string "Ti ho trattenuto troppo!\p"
	.string "Grazie per avermi ascoltato!\n"
	.string "Voglio che tu abbia questo!$"

VermilionCity_PokemonFanClub_Text_ReceivedBikeVoucherFromChairman::
	.string "{PLAYER} riceve un BUONO BICI\n"
	.string "dal PRESIDENTE.$"

VermilionCity_PokemonFanClub_Text_ExplainBikeVoucher::
	.string "Porta quel BUONO BICI al\n"
	.string "NEGOZIO DI BICI di CELESTOPOLI.\p"
	.string "Scambialo con una BICICLETTA\n"
	.string "senza pagare nulla!\p"
	.string "Non temere, il mio FEAROW preferito\n"
	.string "mi porta ovunque col VOLO.\p"
	.string "Quindi non mi serve una BICICLETTA.\p"
	.string "Spero che ti piaccia pedalare!$"

VermilionCity_PokemonFanClub_Text_ComeBackToHearStory::
	.string "Oh. Torna quando vuoi\n"
	.string "sentire la mia storia!$"

VermilionCity_PokemonFanClub_Text_DidntComeToSeeAboutMonsAgain::
	.string "Ciao, {PLAYER}!\p"
	.string "Sei venuto a parlare di nuovo\n"
	.string "dei miei POKéMON?\p"
	.string "No?\n"
	.string "Peccato!$"

VermilionCity_PokemonFanClub_Text_MakeRoomForThis::
	.string "Fate largo a questo!$"

VermilionCity_PokemonFanClub_Text_ChairmanVeryVocalAboutPokemon::
	.string "Il nostro PRESIDENTE parla sempre\n"
	.string "dei POKéMON.$"

VermilionCity_PokemonFanClub_Text_ListenPolitelyToOtherTrainers::
	.string "Ascoltiamo tutti con educazione gli\n"
	.string "altri ALLENATORI!$"

VermilionCity_PokemonFanClub_Text_SomeoneBragsBragBack::
	.string "Se qualcuno si vanta, vantati anche tu!$"

VermilionCity_PokemonFanClub_Text_ChairmanReallyAdoresHisMons::
	.string "Il nostro PRESIDENTE adora davvero i\n"
	.string "suoi POKéMON.\p"
	.string "Ma chi è più amato dai POKéMON\n"
	.string "è DAISY, credo.$"
