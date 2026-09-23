VioletCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VioletCity_Pokecenter_OnTransition
	.byte 0

VioletCity_Pokecenter_OnTransition::
	setrespawn HEAL_LOCATION_VIOLET_CITY_HNS
	end

VioletCity_PokemonCenter_EventScript_Aide::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TOGEPI_EGG, VioletCity_PokemonCenter_EventScript_Aide_Received
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	goto_if_eq VAR_0x8004, 1, VioletCity_PokemonCenter_EventScript_Aide_Offer @ party limit of 1: the Egg goes to the PC
	getpartysize
	goto_if_eq VAR_RESULT, VAR_0x8004, VioletCity_PokemonCenter_EventScript_AideNoRoom
VioletCity_PokemonCenter_EventScript_Aide_Offer::
	msgbox VioletCity_PokeCenter_Text_ElmsAideFavor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VioletCity_PokemonCenter_EventScript_Aide_Refuse
	goto_if_eq VAR_RESULT, YES, VioletCity_PokemonCenter_EventScript_Aide_Accepted
	release
	end


VioletCity_PokemonCenter_EventScript_Aide_FullParty::
	msgbox VioletCity_PokeCenter_Text_ElmsAideFullParty, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_AideNoRoom::
	msgbox VioletCity_PokeCenter_Text_ElmsAideNoRoom, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_Aide_Refuse::
	msgbox VioletCity_PokeCenter_Text_ElmsAideRefuse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VioletCity_PokemonCenter_EventScript_Aide_Refuse
	goto_if_eq VAR_RESULT, YES, VioletCity_PokemonCenter_EventScript_Aide_Accepted
	release
	end

VioletCity_PokemonCenter_EventScript_Aide_Accepted::
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	goto_if_eq VAR_0x8004, 1, VioletCity_PokemonCenter_EventScript_Aide_GiveEgg @ party limit of 1: the Egg goes to the PC
	getpartysize
	goto_if_eq VAR_RESULT, VAR_0x8004, VioletCity_PokemonCenter_EventScript_Aide_FullParty
VioletCity_PokemonCenter_EventScript_Aide_GiveEgg::
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	msgbox VioletCity_PokeCenter_Text_ElmsAideGiveEgg, MSGBOX_DEFAULT
	closemessage
	giveegg SPECIES_TOGEPI
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Common_EventScript_NoMoreRoomForPokemon @ party limit of 1 and every BOX full
	call_if_eq VAR_RESULT, MON_GIVEN_TO_PC, VioletCity_PokemonCenter_EventScript_Aide_EggSentToPC
	setflag FLAG_RECEIVED_TOGEPI_EGG
	msgbox VioletCity_PokeCenter_Text_ElmsAideGiveItem, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE_SMALL
	setflag FLAG_HIDE_VIOLET_CITY_AIDE
	setvar VAR_VIOLET_CITY_KIMONO_GIRL, 1
	clearflag FLAG_HIDE_VIOLET_CITY_KIMONO_GIRL
	clearflag FLAG_HIDE_NEWBARKTOWN_LAB_AIDE
	release
	end

VioletCity_PokemonCenter_EventScript_Aide_EggSentToPC::
	msgbox VioletCity_PokeCenter_Text_ElmsAideEggToPC, MSGBOX_DEFAULT
	closemessage
	return

VioletCity_PokemonCenter_EventScript_Aide_Received::
	msgbox VioletCity_PokeCenter_Text_ElmsAideGiveEgg, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_Gentleman::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EVentScript_Kid::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_GameboyKid, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_Man::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_Text_BookshelfWoman::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_BooksAreGreat, MSGBOX_DEFAULT
	closemessage
	release
	end


VioletCity_PokeCenter_Text_ElmsAideFavor:
	.string "{PLAYER}, è da tanto!\p"
	.string "Il PROF.ELM mi ha chiesto di trovarti.\p"
	.string "Ha un altro favore da chiederti.\p"
	.string "Vuoi prendere l'UOVO POKéMON?$"

VioletCity_PokeCenter_Text_ElmsAideNoRoom:
	.string "{PLAYER}, è da tanto!\p"
	.string "Il PROF.ELM mi ha chiesto di trovarti.\p"
	.string "Ha un altro favore da chiederti.\p"
	.string "Vuoi prendere l'UOVO POKéMON?\p"
	.string "Oh, aspetta… Prima devi fare spazio\n"
	.string "nel tuo team.$"

VioletCity_PokeCenter_Text_ElmsAideGiveEgg:
	.string "Abbiamo scoperto che un POKéMON non\n"
	.string "nasce finché non cresce nell'UOVO.\p"
	.string "Deve anche stare con altri\n"
	.string "POKéMON attivi per schiudersi.\p"
	.string "{PLAYER}, sei l'unico di cui\n"
	.string "possiamo fidarci.$"

VioletCity_PokeCenter_Text_ElmsAideGiveItem:
	.string "Oh, e questo aiuta quando si schiude.$"

VioletCity_PokeCenter_Text_ElmsAideFullParty:
	.string "Oh, no. Non puoi portare altri\n"
	.string "POKéMON con te.\p"
	.string "Aspetto qui mentre fai\n"
	.string "spazio per l'UOVO.$"

VioletCity_PokeCenter_Text_ElmsAideEggToPC:
	.string "Oh, ma non puoi portare altri\n"
	.string "POKéMON con te.\p"
	.string "Non temere, ho mandato l'UOVO al\n"
	.string "PC DI BILL per te.$"

VioletCity_PokeCenter_Text_ElmsAideRefuse:
	.string "M-ma… Il PROF.ELM ti ha chiesto…$"

VioletCity_PokeCenter_Text_BooksAreGreat:
	.string "Mentre i miei POKéMON si riprendono\n"
	.string "adoro leggere un buon libro.$"

VioletCity_PokeCenter_Text_MobileAdapter:
	.string "Ho appena lottato con un amico a\n"
	.string "FIORLISOPOLI via link.\p"
	.string "Se colleghi un MOBILE ADAPTER,\n"
	.string "puoi collegarti con un amico\l"
	.string "lontano.$"

VioletCity_PokeCenter_Text_GameboyKid:
	.string "Un tizio di nome BILL ha creato il\n"
	.string "sistema di deposito POKéMON del PC.$"

VioletCity_PokeCenter_Text_Gentleman:
	.string "Era circa tre anni fa.\p"
	.string "Il TEAM ROCKET combinava guai\n"
	.string "con i POKéMON.\p"
	.string "Ma la giustizia ha vinto: un giovane\n"
	.string "ragazzo li ha fermati.$"

VioletCity_PokeCenter_Text_Youngster:
	.string "I POKéMON sono intelligenti. Non\n"
	.string "obbediscono a chi non rispettano.\p"
	.string "Senza le MEDAGLIE giuste,\n"
	.string "fanno solo ciò che vogliono.$"
