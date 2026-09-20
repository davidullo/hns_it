VermilionCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VermilionCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_VERMILION_CITY
	end

VermilionCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

VermilionCity_PokemonCenter_1F_EventScript_Man::
	msgbox VermilionCity_PokemonCenter_1F_Text_PoisonedMonFaintedWhileWalking, MSGBOX_NPC
	end

VermilionCity_PokemonCenter_1F_EventScript_Hiker::
	msgbox VermilionCity_PokemonCenter_1F_Text_TrainerMonsStrongerThanWild, MSGBOX_NPC
	end

VermilionCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox VermilionCity_PokemonCenter_1F_Text_AllMonWeakToSpecificTypes, MSGBOX_NPC
	end

VermilionCity_PokemonCenter_1F_EventScript_VSSeekerWoman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_VS_SEEKER, VermilionCity_PokemonCenter_1F_EventScript_ExplainVSSeeker
	msgbox VermilionCity_PokemonCenter_1F_Text_UrgeToBattleSomeoneAgain
	setflag FLAG_GOT_VS_SEEKER
	giveitem ITEM_VS_SEEKER
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	msgbox VermilionCity_PokemonCenter_1F_Text_UseDeviceForRematches
	release
	end

VermilionCity_PokemonCenter_1F_EventScript_ExplainVSSeeker::
	msgbox VermilionCity_PokemonCenter_1F_Text_ExplainVSSeeker
	release
	end

VermilionCity_PokemonCenter_1F_Text_TrainerMonsStrongerThanWild::
	.string "Anche allo stesso livello, i\n"
	.string "POKéMON possono avere statistiche\l"
	.string "e abilità molto diverse.\p"
	.string "Un POKéMON cresciuto da un ALLENATORE\n"
	.string "è più forte di uno selvatico.$"

VermilionCity_PokemonCenter_1F_Text_PoisonedMonFaintedWhileWalking::
	.string "Il mio POKéMON era avvelenato!\n"
	.string "È svenuto mentre camminavamo!$"

VermilionCity_PokemonCenter_1F_Text_AllMonWeakToSpecificTypes::
	.string "È vero che un POKéMON di livello\n"
	.string "più alto sarà più forte…\p"
	.string "Ma tutti i POKéMON hanno punti\n"
	.string "deboli contro tipi specifici.\p"
	.string "Quindi non sembra esistere un\n"
	.string "POKéMON forte contro tutto.$"

VermilionCity_PokemonCenter_1F_Text_UrgeToBattleSomeoneAgain::
	.string "La voglia di lottare con qualcuno\n"
	.string "che hai già affrontato…\p"
	.string "Ti è mai capitato?\n"
	.string "Sono certo di sì.\p"
	.string "Anch'io volevo lottare con certa\n"
	.string "gente più e più volte.\p"
	.string "Perciò li ho regalati.\n"
	.string "Prego, prendine uno!$"

VermilionCity_PokemonCenter_1F_Text_UseDeviceForRematches::
	.string "Usa quel dispositivo e troverai\n"
	.string "ALLENATORI in cerca di rivincita.\p"
	.string "Però devi caricarne la batteria\n"
	.string "per usarlo.$"

VermilionCity_PokemonCenter_1F_Text_ExplainVSSeeker::
	.string "Come si usa il VS SEEKER?\n"
	.string "Non è affatto difficile.\p"
	.string "Usalo tipo bip-bip-bip e gli\n"
	.string "ALLENATORI intorno ti noteranno.\p"
	.string "Se un ALLENATORE vuole la rivincita,\n"
	.string "te lo dirà subito.\p"
	.string "Carica la batteria e usalo\n"
	.string "mentre sei in cammino.$"
