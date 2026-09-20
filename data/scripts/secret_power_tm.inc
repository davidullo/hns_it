Route111_Text_MakingRoomUseTMToMakeYourOwn:
	.string "Che c'è?\n"
	.string "Cosa sto facendo?\p"
	.string "Sto pensando di crearmi una stanza qui\n"
	.string "usando una mossa POKéMON.\p"
	.string "Ci sono! Ti darò questa MT.\n"
	.string "La userai per creare la tua stanza?$"

Route111_Text_ExplainSecretPower:
	.string "Trova un albero grande che sembri\n"
	.string "sul punto di far cadere liane.\p"
	.string "Usa SECRET POWER davanti all'albero.\n"
	.string "Qualche liana si libererà e cadrà,\l"
	.string "così potrai arrampicarti.\p"
	.string "Troverai tanto spazio per mettere\n"
	.string "le tue cose preferite.\p"
	.string "Sarà la tua stanza segreta…\n"
	.string "Una BASE SEGRETA!\p"
	.string "Dovresti farne una anche tu.\p"
	.string "Un'altra cosa: non devi per forza\n"
	.string "fare la BASE SEGRETA su un albero.\p"
	.string "Prova a usare SECRET POWER sulle pareti\n"
	.string "rocciose con delle fessure.\p"
	.string "Cercherò anche altri posti.\n"
	.string "Okay, ciao!$"

Route111_Text_DontWantThis:
	.string "Oh, non lo vuoi?\n"
	.string "Se cambi idea, dimmelo, okay?$"

Route111_Text_DontHaveAnyRoom:
	.string "Oh, non hai spazio per questo.\p"
	.string "Lo tengo io, torna a prenderlo\n"
	.string "un'altra volta, okay?$"

Route111_EventScript_SecretPowerMan::
	lock
	faceplayer
	msgbox Route111_Text_MakingRoomUseTMToMakeYourOwn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_EventScript_GiveSecretPower
	msgbox Route111_Text_DontWantThis, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_GiveSecretPower::
	giveitem ITEM_TM_SECRET_POWER
	goto_if_eq VAR_RESULT, FALSE, Route111_EventScript_NoRoomForSecretPower
	msgbox Route111_Text_ExplainSecretPower, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RECEIVED_SECRET_POWER
	clearflag FLAG_HIDE_SLATEPORT_CITY_TM_SALESMAN
	call_if_eq VAR_FACING, DIR_WEST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_EAST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_NORTH, Route111_EventScript_SecretPowerManExitNorth
	removeobject VAR_LAST_TALKED
	release
	end

Route111_EventScript_SecretPowerManExit::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExit
	waitmovement 0
	return

Route111_EventScript_SecretPowerManExitNorth::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExitNorth
	waitmovement 0
	return

Route111_EventScript_NoRoomForSecretPower::
	msgbox Route111_Text_DontHaveAnyRoom, MSGBOX_DEFAULT
	release
	end

Route111_Movement_SecretPowerManExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Route111_Movement_SecretPowerManExitNorth:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end
