FiveIsland_WaterLabyrinth_Frlg_MapScripts::
	.byte 0

FiveIsland_WaterLabyrinth_EventScript_EggGentleman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TOGEPI_EGG, FiveIsland_WaterLabyrinth_EventScript_PostEggComment
	goto_if_set FLAG_NO_ROOM_FOR_TOGEPI_EGG, FiveIsland_WaterLabyrinth_EventScript_ReturnForEgg
	msgbox FiveIsland_WaterLabyrinth_Text_LetMeTakeLookAtMons
	specialvar VAR_RESULT, GetLeadMonFriendship
	goto_if_eq VAR_RESULT, 6, FiveIsland_WaterLabyrinth_EventScript_LeadMonMaxFriendship
	msgbox FiveIsland_WaterLabyrinth_Text_HmmISeeIsee
	release
	end

FiveIsland_WaterLabyrinth_EventScript_MonDaisyComment::
	famechecker FAMECHECKER_DAISY, 2
	msgbox FiveIsland_WaterLabyrinth_Text_CuteMonRemindsMeOfDaisy
	release
	end

FiveIsland_WaterLabyrinth_EventScript_LeadMonMaxFriendship::
	msgbox FiveIsland_WaterLabyrinth_Text_TreatMonRightHaveThis
	goto FiveIsland_WaterLabyrinth_EventScript_TryGiveEgg
	end

FiveIsland_WaterLabyrinth_EventScript_TryGiveEgg::
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, FiveIsland_WaterLabyrinth_EventScript_NoRoomForEgg
	setflag FLAG_GOT_TOGEPI_EGG
	giveegg SPECIES_TOGEPI
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message FiveIsland_WaterLabyrinth_Text_ReceivedEggFromMan
	waitfanfare
	waitmessage
	call EventScript_RestorePrevTextColor
	goto FiveIsland_WaterLabyrinth_EventScript_PostEggComment
	end

@ If the player has a Togepi/Togetic from this game (assumed to be the one the man gave you) then comment on it
@ Otherwise make normal comment
FiveIsland_WaterLabyrinth_EventScript_PostEggComment::
	bufferspeciesname STR_VAR_2, SPECIES_TOGEPI
	setvar VAR_0x8004, SPECIES_TOGEPI
	specialvar VAR_RESULT, PlayerPartyContainsSpeciesWithPlayerID
	goto_if_eq VAR_RESULT, TRUE, FiveIsland_WaterLabyrinth_EventScript_MonDaisyComment
	bufferspeciesname STR_VAR_2, SPECIES_TOGETIC
	setvar VAR_0x8004, SPECIES_TOGETIC
	specialvar VAR_RESULT, PlayerPartyContainsSpeciesWithPlayerID
	goto_if_eq VAR_RESULT, TRUE, FiveIsland_WaterLabyrinth_EventScript_MonDaisyComment
	msgbox FiveIsland_WaterLabyrinth_Text_GladIMetSomeoneLikeYou
	release
	end

FiveIsland_WaterLabyrinth_EventScript_NoRoomForEgg::
	setflag FLAG_NO_ROOM_FOR_TOGEPI_EGG
	msgbox FiveIsland_WaterLabyrinth_Text_DontHaveSpaceInYourParty
	release
	end

FiveIsland_WaterLabyrinth_EventScript_ReturnForEgg::
	goto FiveIsland_WaterLabyrinth_EventScript_TryGiveEgg
	end

FiveIsland_WaterLabyrinth_Text_LetMeTakeLookAtMons::
	.string "Vai in giro per il mondo,\n"
	.string "vero?\p"
	.string "Non stressi troppo i tuoi\n"
	.string "POKéMON, vero?\p"
	.string "Fammi vedere.\n"
	.string "… … …   … … …$"

FiveIsland_WaterLabyrinth_Text_HmmISeeIsee::
	.string "Ah, mmh…\n"
	.string "Capito bene…$"

FiveIsland_WaterLabyrinth_Text_TreatMonRightHaveThis::
	.string "Oh, notevole.\n"
	.string "Tratti bene i tuoi POKéMON.\p"
	.string "Credo che ti spetti\n"
	.string "ciò.\p"
	.string "Per favore, prendilo.$"

FiveIsland_WaterLabyrinth_Text_ReceivedEggFromMan::
	.string "{PLAYER} riceve l'UOVO\n"
	.string "dall'uomo!$"

FiveIsland_WaterLabyrinth_Text_DontHaveSpaceInYourParty::
	.string "…Purtroppo non hai\n"
	.string "posto in squadra per questo.\p"
	.string "Meglio tornare a prenderlo\n"
	.string "più tardi.$"

@ Unused
FiveIsland_WaterLabyrinth_Text_YouveComeBackForTheEgg::
	.string "やあ\n"
	.string "タマゴを　もらいに\l"
	.string "きて　くれたんだね$"

FiveIsland_WaterLabyrinth_Text_GladIMetSomeoneLikeYou::
	.string "Ho ricevuto quell'UOVO in\n"
	.string "viaggio.\p"
	.string "Sono felice di conoscerti.$"

FiveIsland_WaterLabyrinth_Text_CuteMonRemindsMeOfDaisy::
	.string "Oh, ciao.\n"
	.string "Che bel {STR_VAR_2}.\p"
	.string "Vedendolo penso a una\n"
	.string "dolce bimba incontrata in viaggio.\p"
	.string "Pettinava con dolcezza i POKéMON…\n"
	.string "Era un piccolo angelo.\p"
	.string "Il nome di quella bimba…\n"
	.string "Credo fosse DAISY.$"

FiveIsland_WaterLabyrinth_Text_AlizeIntro::
	.string "È un ottimo ambiente per\n"
	.string "allevare POKéMON.$"

FiveIsland_WaterLabyrinth_Text_AlizeDefeat::
	.string "I tuoi POKéMON crescono\n"
	.string "alla grande!$"

FiveIsland_WaterLabyrinth_Text_AlizePostBattle::
	.string "Sai, credo che tu abbia il\n"
	.string "talento da ALLEVATORE.$"
