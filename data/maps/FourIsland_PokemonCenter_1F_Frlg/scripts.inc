FourIsland_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FourIsland_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FourIsland_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_FOUR_ISLAND
	end

FourIsland_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

FourIsland_PokemonCenter_1F_EventScript_Man::
	msgbox FourIsland_PokemonCenter_1F_Text_RareIceMonsInCave, MSGBOX_NPC
	end

FourIsland_PokemonCenter_1F_EventScript_Woman::
	msgbox FourIsland_PokemonCenter_1F_Text_DayCarePeopleFoundEggBefore, MSGBOX_NPC
	end

FourIsland_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FourIsland_PokemonCenter_1F_Text_NewPokemonJournalHasntArrived, MSGBOX_NPC
	end

@ The 5 texts below are supposed to be in FourIsland_House1
Text_BodySlamTeach::
	.string "Si va?\n"
	.string "Boing!\p"
	.string "Facciamo a CORPOSCONTRO\n"
	.string "chi molla per primo.\p"
	.string "Se ti unissi a noi, finiresti\n"
	.string "schiacciato come un insetto…\p"
	.string "Ti insegno CORPOSCONTRO\n"
	.string "a un tuo POKéMON, va bene?$"

Text_BodySlamDeclined::
	.string "Ripassa!\n"
	.string "Boing!$"

Text_BodySlamWhichMon::
	.string "Quale POKéMON vuole imparare\n"
	.string "SCHIANTO?$"

Text_BodySlamTaught::
	.string "Boioing!$"

FourIsland_House1_Text_FatMan::
	.string "それ　ぼよーん！\n"
	.string "おまえ　おもいなあー！$"

FourIsland_PokemonCenter_1F_Text_RareIceMonsInCave::
	.string "C'è un raro POKéMON GHIACCIO\n"
	.string "che vive nella grotta.\p"
	.string "Molti visitatori sperano\n"
	.string "di vederlo.$"

FourIsland_PokemonCenter_1F_Text_DayCarePeopleFoundEggBefore::
	.string "Un UOVO POKéMON?\n"
	.string "…Non ne ho idea.\p"
	.string "…Ah, aspetta. Alla PENSIONE\n"
	.string "in città dicevano qualcosa.\p"
	.string "Dicevano di aver trovato UOVA\n"
	.string "già nel loro terreno.$"

FourIsland_PokemonCenter_1F_Text_NewPokemonJournalHasntArrived::
	.string "Cos'è?\p"
	.string "La nuova AGENDA POKéMON non\n"
	.string "è arrivata sull'isola?$"

