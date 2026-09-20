CeruleanCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

CeruleanCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_CERULEAN_CITY
	end

CeruleanCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

CeruleanCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox CeruleanCity_PokemonCenter_1F_Text_EveryoneCallsBillPokemaniac, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_1F_EventScript_Rocker::
	msgbox CeruleanCity_PokemonCenter_1F_Text_BillDoesWhateverForRareMons, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_1F_EventScript_Youngster::
	lock
	faceplayer
	famechecker FAMECHECKER_BILL, 1
	msgbox CeruleanCity_PokemonCenter_1F_Text_BillCollectsRareMons
	release
	end

CeruleanCity_PokemonCenter_1F_EventScript_Lass::
	msgbox CeruleanCity_PokemonCenter_1F_Text_TryTradingUpstairs, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_1F_Text_BillDoesWhateverForRareMons::
	.string "Quel BILL!\p"
	.string "Ho sentito che farebbe\n"
	.string "di tutto per POKéMON rari.\p"
	.string "Non si fa problemi a fare\n"
	.string "qualsiasi cosa.$"

CeruleanCity_PokemonCenter_1F_Text_EveryoneCallsBillPokemaniac::
	.string "Hai sentito di BILL?\p"
	.string "Tutti lo chiamano POKéMANIAC!\p"
	.string "Credo che siano invidiosi di\n"
	.string "BILL, però.\p"
	.string "Chi non vorrebbe vantarsi\n"
	.string "dei POKéMON?$"

CeruleanCity_PokemonCenter_1F_Text_BillCollectsRareMons::
	.string "BILL ha molti POKéMON!\n"
	.string "E colleziona quelli rari!$"

CeruleanCity_PokemonCenter_1F_Text_TryTradingUpstairs::
	.string "Perché non sali di sopra a\n"
	.string "scambiare POKéMON con gli amici?\p"
	.string "Con gli scambi avresti più\n"
	.string "varietà.\p"
	.string "I POKéMON scambiati crescono\n"
	.string "in fretta.$"

