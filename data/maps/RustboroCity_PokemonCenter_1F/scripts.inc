RustboroCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

RustboroCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_RUSTBORO_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_Man::
	msgbox RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Boy::
	msgbox RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Girl::
	msgbox RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities:
	.string "Il mio POKéMON ha natura INGENUA,\n"
	.string "quello del mio amico è GIOCOSO.\p"
	.string "È affascinante come i POKéMON\n"
	.string "abbiano personalità!$"

RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon:
	.string "Come le persone, esistono POKéMON\n"
	.string "maschi e femmine.\p"
	.string "Ma nessuno sembra sapere come\n"
	.string "siano diversi.$"

RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor:
	.string "L'uomo qui accanto mi ha dato una MN!\p"
	.string "L'ho usata per insegnare al mio\n"
	.string "POKéMON a TAGLIARE gli alberi.$"

