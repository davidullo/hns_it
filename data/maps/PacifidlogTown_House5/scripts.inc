PacifidlogTown_House5_MapScripts::
	.byte 0

PacifidlogTown_House5_EventScript_MirageIslandWatcher::
	lock
	faceplayer
	specialvar VAR_RESULT, IsMirageIslandPresent
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_House5_EventScript_MirageIslandPresent
	msgbox PacifidlogTown_House5_Text_CantSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_MirageIslandPresent::
	msgbox PacifidlogTown_House5_Text_CanSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_Gentleman::
	msgbox PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather, MSGBOX_NPC
	end

PacifidlogTown_House5_Text_CantSeeMirageIslandToday:
	.string "Oggi non vedo l'ISOLA MIRAGGIO…$"

PacifidlogTown_House5_Text_CanSeeMirageIslandToday:
	.string "Oh! Perbacco!\n"
	.string "Oggi vedo l'ISOLA MIRAGGIO!$"

PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather:
	.string "ISOLA MIRAGGIO…\p"
	.string "Diventa visibile e invisibile\n"
	.string "a seconda delle condizioni del meteo\l"
	.string "che fanno apparire i miraggi.\p"
	.string "O appare e scompare\n"
	.string "davvero?$"

