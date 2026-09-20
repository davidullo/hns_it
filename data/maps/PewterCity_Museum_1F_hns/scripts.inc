PewterCity_Museum_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RuinsOfAlph_Lab_OnTransition
	.byte 0

PewterCity_Museum_1F_EventScript_RootFossil::
	finditem ITEM_ROOT_FOSSIL
	setflag FLAG_HIDE_PEWTER_ROOT_FOSSIL
	removeobject LOCALID_MUSEUM_ROOTFOSSIL
	end

PewterCity_Museum_1F_EventScript_ClawFossil::
	finditem ITEM_CLAW_FOSSIL
	setflag FLAG_HIDE_PEWTER_CLAW_FOSSIL
	removeobject LOCALID_MUSEUM_CLAWFOSSIL
	end

PewterCity_Museum_1F_EventScript_Receptionist::
	msgbox PewterCity_Museum_1F_Text_Recptionist, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_FossilWoman::
	goto_if_set FLAG_HIDE_PEWTER_CLAW_FOSSIL, PewterCity_Museum_1F_EventScript_FossilWoman2
	goto_if_set FLAG_HIDE_PEWTER_ROOT_FOSSIL, PewterCity_Museum_1F_EventScript_FossilWoman2
	goto_if_ge VAR_TEMP_2, 1, PewterCity_Museum_1F_EventScript_FossilWoman2
	msgbox PewterCity_Museum_1F_Text_FossilWoman, MSGBOX_NPC
	setvar VAR_TEMP_2, 1
	end

PewterCity_Museum_1F_EventScript_FossilWoman2::
	msgbox PewterCity_Museum_1F_Text_FossilWomanAfter, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_Oldman::
	msgbox PewterCity_Museum_1F_Text_Oldman, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_Bones::
	msgbox PewterCity_Museum_1F_Text_Bones, MSGBOX_SIGN
	end

PewterCity_Museum_1F_Text_Recptionist:
	.string "Benvenuto!\p"
	.string "Sappi che tutti gli esemplari\n"
	.string "grandi sono stati portati negli\l"
	.string "altri musei per l'esposizione.\p"
	.string "Quindi per ora l'ingresso è\n"
	.string "gratuito!\p"
	.string "Prego, accomodati.$"

PewterCity_Museum_1F_Text_FossilWoman:
	.string "You must be a strong trainer.\p"
	.string "We don't have much use for the\n"
	.string "fossils on the counter over there.\p"
	.string "A strange man with silver hair\n"
	.string "dropped a ton of them off here.\p"
	.string "Go ahead and take them if you like.$"

PewterCity_Museum_1F_Text_FossilWomanAfter:
	.string "Spesso condividiamo le ricerche\n"
	.string "con gli studiosi delle ROVINE D'ALFA.\p"
	.string "Condividiamo i fossili anche con\n"
	.string "loro, tramite il PC!$"

PewterCity_Museum_1F_Text_Oldman:
	.string "Devo essere grato per la mia\n"
	.string "lunga vita.\p"
	.string "Non avrei mai pensato di poter\n"
	.string "vedere le ossa di un drago!$"

PewterCity_Museum_1F_Text_Bones:
	.string "Ossa di un antico POKéMON\n"
	.string "drago.$"
