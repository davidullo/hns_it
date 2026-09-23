EcruteakCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_PokemonCenter_OnTransition
	.byte 0

EcruteakCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_ECRUTEAK_CITY_HNS
	end

EcruteakCity_PokemonCenter_EventScript_Bill::
	lock
	delay 30
	playse SE_PC_OFF
	delay 55
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_Bill1, MSGBOX_DEFAULT
	msgbox EcruteakCity_PokemonCenter1F_Text_Bill2, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, EcruteakCity_PokemonCenter_EventScript_BillLeaveBot
	call_if_eq VAR_FACING, DIR_WEST, EcruteakCity_PokemonCenter_EventScript_BillLeaveTop
	playse SE_EXIT
	setflag FLAG_HIDE_ECRUTEAK_BILL
	removeobject LOCALID_ECRUTEAK_BILL
	setflag FLAG_SYS_PC_BILL
	clearflag FLAG_HIDE_GOLDENROD_BILL
	release
	end

EcruteakCity_PokemonCenter_EventScript_BillFaceDown::
	turnobject LOCALID_ECRUTEAK_BILL, DIR_SOUTH
	return

EcruteakCity_PokemonCenter_EventScript_BillFaceRight::
	turnobject LOCALID_ECRUTEAK_BILL, DIR_EAST
	return

EcruteakCity_PokemonCenter_EventScript_BillLeaveTop::
	applymovement LOCALID_ECRUTEAK_BILL, EcruteakCity_PokemonCenter_Movement_BillTop
	waitmovement 0
	return

EcruteakCity_PokemonCenter_EventScript_BillLeaveBot::
	applymovement LOCALID_ECRUTEAK_BILL, EcruteakCity_PokemonCenter_Movement_BillBot
	waitmovement 0
	return

EcruteakCity_PokemonCenter_EventScript_Hiker::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_EventScript_Woman::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_EventScript_Nerd::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_Movement_BillTop:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

EcruteakCity_PokemonCenter_Movement_BillBot:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end


EcruteakCity_PokemonCenter1F_Text_Bill1:
	.string "Ciao, sono BILL. E tu chi sei?\p"
	.string "Hmm, {PLAYER}, eh?\n"
	.string "Capiti al momento giusto.$"

EcruteakCity_PokemonCenter1F_Text_Bill2:
	.string "Ho appena finito di sistemare il\n"
	.string "SISTEMA POKéMON.\p"
	.string "Conosci il PC dove tieni i\n"
	.string "tuoi POKéMON?\p"
	.string "L'ho creato io!\p"
	.string "Ora che ho installato questo,\n"
	.string "il mio PC è attivo nei\l"
	.string "POKéMON CENTER di JOHTO e KANTO.\p"
	.string "Devo tornare di corsa a\n"
	.string "FIORDOROPOLI a trovare i miei. Se\l"
	.string "passa quando vuoi!\p"
	.string "Ciao!$"

EcruteakCity_PokemonCenter1F_Text_PokefanM:
	.string "Come danzano le RAGAZZE KIMONO è\n"
	.string "stupendo.\p"
	.string "Proprio come usano i loro\n"
	.string "POKéMON.$"

EcruteakCity_PokemonCenter1F_Text_PokefanM_Mobile:
	.string "Spererai di lottare con più\n"
	.string "gente, giusto?\p"
	.string "Sembra che ci sia un posto in cui\n"
	.string "si radunano gli ALLENATORI.\p"
	.string "Dove, dici?\p"
	.string "È poco oltre OLIVINOPOLI.$"

EcruteakCity_PokemonCenter1F_Text_CooltrainerF:
	.string "ANGELO, il CAPOPALESTRA, è un\n"
	.string "mito.\p"
	.string "Anche i suoi POKéMON sono tosti.$"

EcruteakCity_PokemonCenter1F_Text_GymGuide:
	.string "LAGO D'IRA…\p"
	.string "La comparsa di un GYARADOS\n"
	.string "in branco…\p"
	.string "Sento puzza di complotto. Lo so!$"

