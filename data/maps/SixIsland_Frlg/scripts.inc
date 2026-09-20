SixIsland_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SixIsland_OnTransition
	.byte 0

SixIsland_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SIX_ISLAND
	end

SixIsland_EventScript_Hiker::
	msgbox SixIsland_Text_ThatWayToWaterPathRuinValley, MSGBOX_NPC
	end

SixIsland_EventScript_Boy::
	msgbox SixIsland_Text_SkyAtNightIsFantastic, MSGBOX_NPC
	end

SixIsland_EventScript_IslandSign::
	msgbox SixIsland_Text_IslandSign, MSGBOX_SIGN
	end

SixIsland_Text_IslandSign::
	.string "SIX ISLAND\n"
	.string "Isola della Fortuna e della Saggezza$"

SixIsland_Text_ThatWayToWaterPathRuinValley::
	.string "Continuando di qua arriverai\n"
	.string "al PERCORSO MARINO.\p"
	.string "Seguendolo arriverai\n"
	.string "alla VALLE DELLE ROVINE.$"

SixIsland_Text_SkyAtNightIsFantastic::
	.string "Quando sei così lontano dalla\n"
	.string "città, il cielo notturno è fantastico.$"

