IndigoPlateau_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IndigoPlateau_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

IndigoPlateau_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_INDIGO_PLATEAU
	specialvar VAR_RESULT, IsNationalPokedexEnabled
	call_if_eq VAR_RESULT, TRUE, IndigoPlateau_PokemonCenter_1F_EventScript_CheckBlockDoor
	end

IndigoPlateau_PokemonCenter_1F_EventScript_CheckBlockDoor::
	goto_if_set FLAG_IS_CHAMPION, Common_EventScript_NopReturn
	setobjectxyperm LOCALID_LEAGUE_DOOR_GUARD, 4, 2
	return

IndigoPlateau_PokemonCenter_1F_EventScript_DoorGuard::
	lock
	faceplayer
	specialvar VAR_RESULT, IsNationalPokedexEnabled
	goto_if_eq VAR_RESULT, TRUE, IndigoPlateau_PokemonCenter_1F_EventScript_CheckSeviiIslandComplete
	msgbox IndigoPlateau_PokemonCenter_1F_Text_FaceEliteFourGoodLuck
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_CheckSeviiIslandComplete::
	goto_if_set FLAG_IS_CHAMPION, IndigoPlateau_PokemonCenter_1F_EventScript_SeviiIslandComplete
	msgbox IndigoPlateau_PokemonCenter_1F_Text_LoreleiIsAbsentClosedForTimeBeing
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_SeviiIslandComplete::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_FaceEliteFourGoodLuck
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_GymGuy::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_GymGuyAdvice, MSGBOX_NPC
	end

IndigoPlateau_PokemonCenter_1F_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart IndigoPlateau_PokemonCenter_1F_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
IndigoPlateau_PokemonCenter_1F_Items::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

IndigoPlateau_PokemonCenter_1F_Text_GymGuyAdvice::
	.string "Ehi!\n"
	.string "Futuro campione!\p"
	.string "Alla LEGA POKéMON affronterai\n"
	.string "i SUPERQUATTRO di fila.\p"
	.string "Se perdi, ricominci tutto\n"
	.string "da capo!\p"
	.string "È il momento!\n"
	.string "Dacci dentro!$"

IndigoPlateau_PokemonCenter_1F_Text_FaceEliteFourGoodLuck::
	.string "Da qui in poi affronti il\n"
	.string "SUPERQUATTRO uno alla volta.\p"
	.string "Se vinci, una porta si apre per l'\n"
	.string "altro ALLENATORE. Buona fortuna!$"

IndigoPlateau_PokemonCenter_1F_Text_LoreleiIsAbsentClosedForTimeBeing::
	.string "Mi dispiace, ma hai fatto\n"
	.string "un viaggio a vuoto.\p"
	.string "LORELEI dei SUPERQUATTRO è\n"
	.string "assente, sai.\p"
	.string "Perciò la LEGA POKéMON è\n"
	.string "chiusa per il momento.$"

IndigoPlateau_PokemonCenter_1F_Text_AgathaWhuppedUs::
	.string "I POKéMON di tipo SPETTRO di AGATHA\n"
	.string "sono di una forza spaventosa.\p"
	.string "Ho preso POKéMON di tipo LOTTA\n"
	.string "e li ho allenati al massimo.\p"
	.string "Ho affrontato AGATHA sicuro\n"
	.string "di me, ma ci ha battuti.\p"
	.string "Quella signora ha anche un\n"
	.string "carattere bollente.\p"
	.string "Basta niente per far\n"
	.string "urlare quella tipa spaventosa.$"

IndigoPlateau_PokemonCenter_1F_Text_LancesCousinGymLeaderFarAway::
	.string "Forse fare il SUPERQUATTRO\n"
	.string "è questione di sangue.\p"
	.string "Ho sentito che LANCE ha\n"
	.string "un cugino CAPOPALESTRA\l"
	.string "lontano lontano.$"

