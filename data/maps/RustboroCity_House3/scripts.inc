RustboroCity_House3_MapScripts::
	.byte 0

RustboroCity_House3_EventScript_OldMan::
	msgbox RustboroCity_House3_Text_IGivePerfectlySuitedNicknames, MSGBOX_NPC
	end

RustboroCity_House3_EventScript_OldWoman::
	msgbox RustboroCity_House3_Text_NamingPikachuPekachu, MSGBOX_NPC
	end

@ Misspelling on purpose, see nickname
RustboroCity_House3_EventScript_Pekachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox RustboroCity_House3_Text_Pekachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_House3_Text_IGivePerfectlySuitedNicknames:
	.string "Ai miei POKéMON do soprannomi\n"
	.string "perfetti per loro!\p"
	.string "È la mia espressione di, uh…\n"
	.string "originalità, sì, proprio così!$"

RustboroCity_House3_Text_NamingPikachuPekachu:
	.string "Ma dare il nome PEKACHU a\n"
	.string "un PIKACHU? Sembra inutile.\p"
	.string "Suppongo sia utile un nome\n"
	.string "facile da capire, ma…$"

RustboroCity_House3_Text_Pekachu:
	.string "PEKACHU: Peka!$"

