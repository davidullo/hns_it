VerdanturfTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VerdanturfTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_VERDANTURF_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_VERDANTURF_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon:
	.string "Non puoi considerarti un vero\n"
	.string "ALLENATORE se non credi\l"
	.string "nei tuoi POKéMON.\p"
	.string "Solo chi crede nei POKéMON\n"
	.string "che lotta con lui può vincere\l"
	.string "fino alla fine.$"

VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent:
	.string "Il motivo per cui si visita\n"
	.string "VERDANTURF…\p"
	.string "È il TENTE LOTTA. Inutile\n"
	.string "dirlo.\p"
	.string "O c'è qualcuno che sei\n"
	.string "venuto a trovare?$"

