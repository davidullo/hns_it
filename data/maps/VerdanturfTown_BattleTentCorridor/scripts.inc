VerdanturfTown_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VerdanturfTown_BattleTentCorridor_OnFrame
	.byte 0

VerdanturfTown_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_VERDANTURF_TENT_CORRIDOR_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_VERDANTURF_TENT_CORRIDOR_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	setvar VAR_0x8006, 0
	warp MAP_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM, 6, 5
	waitstate
	releaseall
	end

VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor:
	walk_up
VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end


@ Leftover text from when this was a Contest Hall in R/S
@ Unused
VerdanturfTown_ContestHall_Text_WhichContestYouEntering:
	.string "A quale GARA partecipi?\n"
	.string "Vuoi un consiglio?\p"
	.string "In ogni GARA, per esempio una GARA\n"
	.string "BELLEZZA, non credo ti giudichino\l"
	.string "solo sulla bellezza al primo turno.\p"
	.string "Devi trovare il modo di far crescere\n"
	.string "meglio i POKéMON.$"

@ Unused
VerdanturfTown_ContestHall_Text_RaisedMonToBeCute:
	.string "Ho allevato il mio POKéMON per farlo bello.\p"
	.string "Ho scoperto che puoi iscrivere i POKéMON\n"
	.string "a una GARA di bellezza!\p"
	.string "Sono così felice di averlo allevato\n"
	.string "con tanto amore…$"

@ Unused
VerdanturfTown_ContestHall_Text_MyMonRules:
	.string "I miei POKéMON dominano!\p"
	.string "È forte, bello, dolce e\n"
	.string "intelligente. È perfetto!\p"
	.string "Tanto vale che vinca in ogni\n"
	.string "singola GARA.$"

@ Unused
VerdanturfTown_ContestHall_Text_NormalRankStage:
	.string "GARE POKéMON\n"
	.string "PALCO CLASSE NORMALE!$"

