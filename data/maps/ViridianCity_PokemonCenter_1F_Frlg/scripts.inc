ViridianCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

ViridianCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_VIRIDIAN_CITY
	end

ViridianCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

ViridianCity_PokemonCenter_1F_EventScript_Boy::
	msgbox ViridianCity_PokemonCenter_1F_Text_PokeCenterInEveryTown, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox ViridianCity_PokemonCenter_1F_Text_FeelFreeToUsePC, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox ViridianCity_PokemonCenter_1F_Text_PokeCentersHealMons, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_1F_Text_FeelFreeToUsePC::
	.string "Puoi usare quel PC nell'angolo,\n"
	.string "se vuoi.\p"
	.string "Me l'ha detto la receptionist.\n"
	.string "Che gentile!$"

ViridianCity_PokemonCenter_1F_Text_PokeCenterInEveryTown::
	.string "C'è un CENTRO POKéMON in ogni\n"
	.string "città più avanti.\p"
	.string "Non chiedono soldi, quindi non\n"
	.string "temere di curare i POKéMON.$"

ViridianCity_PokemonCenter_1F_Text_PokeCentersHealMons::
	.string "I CENTRI POKéMON curano i POKéMON\n"
	.string "stanchi, feriti o esausti.\p"
	.string "Rimettono tutti i POKéMON in\n"
	.string "piena salute.$"

