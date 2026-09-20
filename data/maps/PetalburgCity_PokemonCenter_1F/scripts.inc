PetalburgCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PetalburgCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

PetalburgCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_PETALBURG_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_FatMan::
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	msgbox PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsStarterInParty
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo::
	call_if_eq VAR_STARTER_MON, 0, PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType
	call_if_eq VAR_STARTER_MON, 1, PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType
	call_if_eq VAR_STARTER_MON, 2, PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem:
	.string "Quel sistema di conservazione\n"
	.string "POKéMON del PC…\p"
	.string "Chi l'ha creato dev'essere un vero\n"
	.string "mago della scienza!$"

PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP:
	.string "Quando il mio POKéMON ha mangiato\n"
	.string "una BACCA ORAN, ha recuperato PS!$"

PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon:
	.string "Esistono molti tipi di POKéMON.\p"
	.string "Ogni tipo ha punti di forza e\n"
	.string "debolezze verso gli altri tipi.\p"
	.string "A seconda dei tipi dei POKéMON,\n"
	.string "una lotta può essere facile o difficile.$"

PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType:
	.string "Per esempio, il tuo TREECKO\n"
	.string "è di tipo ERBA.\p"
	.string "È forte contro i tipi ACQUA e\n"
	.string "TERRA.\p"
	.string "Ma è debole contro i POKéMON di tipo\n"
	.string "FUOCO.$"

PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType:
	.string "Per esempio, il tuo TORCHIC\n"
	.string "è di tipo FUOCO.\p"
	.string "È forte contro i tipi ERBA e\n"
	.string "COLEOTTERO.\p"
	.string "Ma è debole contro i POKéMON di tipo\n"
	.string "ACQUA.$"

PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType:
	.string "Per esempio, il tuo MUDKIP\n"
	.string "è di tipo ACQUA.\p"
	.string "È forte contro il tipo FUOCO.\p"
	.string "Ma è debole contro i POKéMON di tipo\n"
	.string "ERBA ed ELETTRICO.$"

