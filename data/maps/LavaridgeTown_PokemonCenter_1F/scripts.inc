LavaridgeTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

LavaridgeTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_LAVARIDGE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_LAVARIDGE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Youngster::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_HotSpringCanInvigorate, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Woman::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_TrainersPokemonSpendTimeTogether, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_TrainersShouldRestToo, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_Text_TrainersPokemonSpendTimeTogether:
	.string "Credo che i POKéMON si affezionino\n"
	.string "di più stando con gli ALLENATORI.\p"
	.string "Più tempo, meglio è.\n"
	.string "Ecco cosa penso.$"

LavaridgeTown_PokemonCenter_1F_Text_HotSpringCanInvigorate:
	.string "È quasi magico come basti stare\n"
	.string "in una fonte calda per rinvigorirsi.\p"
	.string "Vorrei far immergere\n"
	.string "anche i miei POKéMON.$"

LavaridgeTown_PokemonCenter_1F_Text_TrainersShouldRestToo:
	.string "Oh oh oh! Ehi, ragazzo, di qui\n"
	.string "arrivi alle terme.\p"
	.string "Se i POKéMON riposano,\n"
	.string "anche gli ALLENATORI dovrebbero.$"

