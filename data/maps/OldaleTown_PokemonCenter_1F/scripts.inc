OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_OLDALE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy::
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC:
	.string "Quel PC nell'angolo è\n"
	.string "a disposizione dei POKéMON TRAINER.\p"
	.string "Quindi, naturalmente,\n"
	.string "puoi usarlo anche tu.$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat:
	.string "I POKéMON CENTER sono fantastici!\p"
	.string "Puoi usare i loro servizi quanto\n"
	.string "vuoi, ed è tutto gratis.\l"
	.string "Nessun pensiero!$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
	.string "Il POKéMON WIRELESS CLUB al\n"
	.string "primo piano è stato aperto da poco.\p"
	.string "Ma dicono che stanno ancora\n"
	.string "facendo lavori.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
	.string "Il POKéMON WIRELESS CLUB al\n"
	.string "primo piano è stato aperto da poco.\p"
	.string "Ho scambiato subito dei POKéMON.$"

