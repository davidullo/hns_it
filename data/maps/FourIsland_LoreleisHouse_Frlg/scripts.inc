FourIsland_LoreleisHouse_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FourIsland_LoreleisHouse_OnTransition
	.byte 0

FourIsland_LoreleisHouse_OnTransition::
	special UpdateLoreleiDollCollection
	end

FourIsland_LoreleisHouse_EventScript_Lorelei::
	lock
	faceplayer
	goto_if_set FLAG_TALKED_TO_LORELEI_AFTER_WAREHOUSE, FourIsland_LoreleisHouse_EventScript_Lorelei3
	goto_if_set FLAG_DEFEATED_ROCKETS_IN_WAREHOUSE, FourIsland_LoreleisHouse_EventScript_Lorelei2
	msgbox FourIsland_LoreleisHouse_Text_IfAnythingWereToHappenToIsland
	release
	end

FourIsland_LoreleisHouse_EventScript_Lorelei2::
	setflag FLAG_TALKED_TO_LORELEI_AFTER_WAREHOUSE
	msgbox FourIsland_LoreleisHouse_Text_IllReturnToLeagueInShortWhile
	release
	end

FourIsland_LoreleisHouse_EventScript_Lorelei3::
	msgbox FourIsland_LoreleisHouse_Text_WillDoWhatICanHereAndNow
	release
	end

FourIsland_LoreleisHouse_EventScript_Doll::
	lock
	msgbox FourIsland_LoreleisHouse_Text_StuffedMonDollsGalore
	release
	end

FourIsland_LoreleisHouse_Text_IfAnythingWereToHappenToIsland::
	.string "LORELEI: Ho un pensiero che\n"
	.string "mi pesa molto.\p"
	.string "Se accadesse qualcosa\n"
	.string "sull'isola dove sono nata…\p"
	.string "non lo saprei se fossi\n"
	.string "alla LEGA POKéMON.\p"
	.string "Non so se sarei\n"
	.string "sleale verso casa mia…$"

FourIsland_LoreleisHouse_Text_IllReturnToLeagueInShortWhile::
	.string "LORELEI: Hai risolto\n"
	.string "tutti i problemi qui?\p"
	.string "Che meraviglia.\p"
	.string "Quindi non c'è motivo\n"
	.string "che io resti qui sempre.\p"
	.string "Grazie…\p"
	.string "Tornerò alla LEGA POKéMON\n"
	.string "tra poco.$"

FourIsland_LoreleisHouse_Text_WillDoWhatICanHereAndNow::
	.string "Non so cosa succederà\n"
	.string "in futuro, ma…\p"
	.string "Farò ciò che posso, qui e ora.\n"
	.string "Questo posso fare.$"

FourIsland_LoreleisHouse_Text_StuffedMonDollsGalore::
	.string "Peluche di POKéMON a iosa!$"

