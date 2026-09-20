LavenderTown_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_OnTransition
	.byte 0

LavenderTown_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_LAVENDER_TOWN
	setvar VAR_MAP_SCENE_S_S_ANNE_2F_CORRIDOR, 1
	setflag FLAG_HIDE_SS_ANNE_RIVAL
	end

LavenderTown_EventScript_LittleGirl::
	lock
	faceplayer
	msgbox LavenderTown_Text_DoYouBelieveInGhosts, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LavenderTown_EventScript_LittleGirlBelieve
	msgbox LavenderTown_Text_JustImaginingWhiteHand
	release
	end

LavenderTown_EventScript_LittleGirlBelieve::
	msgbox LavenderTown_Text_SoThereAreBelievers
	release
	end

LavenderTown_EventScript_WorkerM::
	msgbox LavenderTown_Text_TownKnownAsMonGraveSite, MSGBOX_NPC
	end

LavenderTown_EventScript_Boy::
	msgbox LavenderTown_Text_GhostsAppearedInTower, MSGBOX_NPC
	end

LavenderTown_EventScript_TownSign::
	msgbox LavenderTown_Text_TownSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_SilphScopeNotice::
	msgbox LavenderTown_Text_SilphScopeNotice, MSGBOX_SIGN
	end

LavenderTown_EventScript_VolunteerHouseSign::
	msgbox LavenderTown_Text_VolunteerPokemonHouse, MSGBOX_SIGN
	end

LavenderTown_EventScript_PokemonTowerSign::
	msgbox LavenderTown_Text_PokemonTowerSign, MSGBOX_SIGN
	end

LavenderTown_Text_DoYouBelieveInGhosts::
	.string "Credi nei fantasmi?$"

LavenderTown_Text_SoThereAreBelievers::
	.string "Davvero?\n"
	.string "Quindi ci sono dei credenti…$"

LavenderTown_Text_JustImaginingWhiteHand::
	.string "Ah ah ah, immaginavo.\p"
	.string "Quella mano bianca sulla tua spalla…\n"
	.string "Me la sono solo immaginata.$"

LavenderTown_Text_TownKnownAsMonGraveSite::
	.string "Questa città è nota come il\n"
	.string "cimitero dei POKéMON.\p"
	.string "Le funzioni si tengono alla\n"
	.string "TORRE POKéMON.$"

LavenderTown_Text_GhostsAppearedInTower::
	.string "Sono apparsi fantasmi alla TORRE\p"
	.string "POKéMON. Credo siano gli spiriti dei\n"
	.string "POKéMON uccisi dai ROCKET.$"

LavenderTown_Text_TownSign::
	.string "LAVENDER\n"
	.string "La nobile città viola$"

LavenderTown_Text_SilphScopeNotice::
	.string "Nuovo SPETTROSCOPIO!\n"
	.string "Rendi visibile l'invisibile!\p"
	.string "SILPH SPA$"

LavenderTown_Text_VolunteerPokemonHouse::
	.string "CASA DEI POKéMON\n"
	.string "DEI VOLONTARI$"

LavenderTown_Text_PokemonTowerSign::
	.string "TORRE POKéMON\n"
	.string "Placa gli spiriti dei POKéMON$"

