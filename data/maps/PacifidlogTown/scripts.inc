PacifidlogTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
	.byte 0

PacifidlogTown_OnTransition:
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	end

PacifidlogTown_OnResume:
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
	end

PacifidlogTown_EventScript_NinjaBoy::
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Girl::
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Fisherman::
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
	end

PacifidlogTown_EventScript_TownSign::
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
	end

PacifidlogTown_Text_FastRunningCurrent:
	.string "Il mare fra PACIFIDLOG e\n"
	.string "SLATEPORT ha una corrente rapida.\p"
	.string "Se decidi di usare SURF, rischi\n"
	.string "di finire chissà dove.$"

PacifidlogTown_Text_NeatHousesOnWater:
	.string "Visto? Non è fantastico?\n"
	.string "Queste case sono sull'acqua!\p"
	.string "Io sono nato qui!$"

PacifidlogTown_Text_SkyPillarTooScary:
	.string "La TORRE DEI CIELI?\p"
	.string "…Ah, intendi quella torre\n"
	.string "altissima poco più in là.\p"
	.string "Io non ci salirei di certo.\n"
	.string "Fa troppa paura arrivare così in alto.\p"
	.string "La vita al livello del mare a PACIFIDLOG,\n"
	.string "per me va benissimo.$"

PacifidlogTown_Text_TownSign:
	.string "OROCEA\p"
	.string "“Dove il sole del mattino sorride\n"
	.string "alle acque.”$"

