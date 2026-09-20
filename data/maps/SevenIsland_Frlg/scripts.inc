SevenIsland_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_OnTransition
	.byte 0

SevenIsland_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SEVEN_ISLAND
	end

SevenIsland_EventScript_IslandSign::
	msgbox SevenIsland_Text_IslandSign, MSGBOX_SIGN
	end

SevenIsland_EventScript_OldWoman::
	msgbox SevenIsland_Text_IslandsMadeInSevenDays, MSGBOX_NPC
	end

SevenIsland_EventScript_Scientist::
	msgbox SevenIsland_Text_IslandVirtuallyUntouched, MSGBOX_NPC
	end

Text_SwordsDanceTeach::
	.string "Qui non viene quasi nessuno.\p"
	.string "Se mi alleno qui, sono convinto che\n"
	.string "diventerò sempre più forte.\p"
	.string "Sì, sempre più forte…\p"
	.string "Ti va di imparare una mossa\n"
	.string "così? È DANZASPADA.$"

Text_SwordsDanceDeclined::
	.string "Beh, va bene lo stesso.$"

Text_SwordsDanceWhichMon::
	.string "Bene, scegli a quale POKéMON\n"
	.string "devo insegnarla.$"

Text_SwordsDanceTaught::
	.string "Se solo potessimo diventare\n"
	.string "sempre più forti, eh?$"

SevenIsland_Text_IslandSign::
	.string "SETTE ISOLA\n"
	.string "L'isola della ricerca infinita$"

SevenIsland_Text_IslandsMadeInSevenDays::
	.string "Queste isole si chiamano ISOLE\n"
	.string "SETTIMANE perché sono sette.\p"
	.string "…O almeno è quello che credono\n"
	.string "i giovani.\p"
	.string "In realtà si chiamano così perché\n"
	.string "si dice che siano state create\l"
	.string "in sette giorni.$"

SevenIsland_Text_IslandVirtuallyUntouched::
	.string "Quest'isola è rimasta quasi\n"
	.string "intatta, allo stato naturale.\p"
	.string "Per questo potrebbe essere un po'\n"
	.string "difficile girarla a piedi.$"

