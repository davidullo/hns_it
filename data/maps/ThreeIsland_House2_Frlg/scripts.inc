ThreeIsland_House2_Frlg_MapScripts::
	.byte 0

ThreeIsland_House2_EventScript_Man::
	lock
	faceplayer
	famechecker FAMECHECKER_SABRINA, 1
	msgbox ThreeIsland_House2_Text_IAdmireSabrina
	release
	end

ThreeIsland_House2_EventScript_Rocker::
	msgbox ThreeIsland_House2_Text_CantMakeThisSpoonBend, MSGBOX_NPC
	end

ThreeIsland_House2_Text_CantMakeThisSpoonBend::
	.string "Urrrrrrrrgggghhhh…\n"
	.string "Kwaaaaah!\p"
	.string "…Non serve a niente! Non riesco\n"
	.string "a piegare il cucchiaio col\p"
	.string "pensiero. Forse non ho proprio\n"
	.string "poteri psichici.$"

ThreeIsland_House2_Text_IAdmireSabrina::
	.string "Conosci una ragazza CAPOPALESTRA\n"
	.string "di ZAFFERANOPOLI?\p"
	.string "Usa POKéMON di tipo PSICO,\n"
	.string "vero?\p"
	.string "La ammiro, davvero.\p"
	.string "Ho sentito che è una tipa\n"
	.string "tosta e anche bella.$"

