FortreeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FortreeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FORTREE_CITY
	end

FortreeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_FORTREE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FortreeCity_PokemonCenter_1F_Text_GoToSafariZone, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Man::
	msgbox FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Boy::
	msgbox FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_Text_GoToSafariZone:
	.string "Senti, piccolo, lavori a un\n"
	.string "POKéDEX?\p"
	.string "Mmm… Vai alla ZONA SAFARI.\n"
	.string "Te lo consiglio.$"

FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat:
	.string "Hai fatto qualcosa al\n"
	.string "RECORD CORNER?\p"
	.string "È carino: mescola e abbina i\n"
	.string "record degli ALLENATORI.\p"
	.string "Non so bene come funziona,\n"
	.string "ma è bello. Anzi, emozionante!$"

FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav:
	.string "Oh, wow, hai un POKéNAV!\n"
	.string "Ed è uguale al mio!\p"
	.string "Conosci il sistema MATCH\n"
	.string "CALL del POKéNAV?\p"
	.string "Accedi per parlare con gli\n"
	.string "ALLENATORI registrati.\p"
	.string "Ti mostra anche quali ALLENATORI\n"
	.string "vogliono la rivincita.\p"
	.string "È davvero utile! Quei tizi DEVON\n"
	.string "sanno il fatto loro!$"

