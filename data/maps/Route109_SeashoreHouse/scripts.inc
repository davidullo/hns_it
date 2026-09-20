Route109_SeashoreHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route109_SeashoreHouse_OnTransition
	.byte 0

Route109_SeashoreHouse_OnTransition:
	setflag FLAG_LANDMARK_SEASHORE_HOUSE
	end

Route109_SeashoreHouse_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_6_SODA_POP, Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop
	goto_if_set FLAG_DEFEATED_SEASHORE_HOUSE, Route109_SeashoreHouse_EventScript_DefeatedTrainers
	goto_if_set FLAG_TEMP_2, Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction
	msgbox Route109_SeashoreHouse_Text_SeashoreHouseIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction::
	msgbox Route109_SeashoreHouse_Text_ShowMeSomeHotMatches, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_DefeatedTrainers::
	msgbox Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles, MSGBOX_DEFAULT
	giveitem ITEM_SODA_POP, 6
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_BagFull
	setflag FLAG_RECEIVED_6_SODA_POP
	release
	end

Route109_SeashoreHouse_EventScript_BagFull::
	msgbox Route109_SeashoreHouse_Text_BagFull, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop::
	showmoneybox 0, 0
	msgbox Route109_SeashoreHouse_Text_WantToBuySodaPop, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route109_SeashoreHouse_EventScript_BuySodaPop
	msgbox Route109_SeashoreHouse_Text_ThatsTooBad, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_BuySodaPop::
	checkmoney 300
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughMoney
	checkitemspace ITEM_SODA_POP
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughSpace
	msgbox Route109_SeashoreHouse_Text_HereYouGo, MSGBOX_DEFAULT
	removemoney 300
	updatemoneybox
.if OW_SHOW_ITEM_DESCRIPTIONS != OW_ITEM_DESCRIPTIONS_OFF
	hidemoneybox
	giveitem ITEM_SODA_POP
.else
	giveitem ITEM_SODA_POP
	hidemoneybox
.endif
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughMoney::
	msgbox Route109_SeashoreHouse_Text_NotEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughSpace::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE, Route109_SeashoreHouse_Text_DwayneIntro, Route109_SeashoreHouse_Text_DwayneDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Johanna::
	trainerbattle_single TRAINER_JOHANNA, Route109_SeashoreHouse_Text_JohannaIntro, Route109_SeashoreHouse_Text_JohannaDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_JohannaPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON, Route109_SeashoreHouse_Text_SimonIntro, Route109_SeashoreHouse_Text_SimonDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_CheckTrainersCompletion::
	goto_if_not_defeated TRAINER_DWAYNE, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_JOHANNA, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_SIMON, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	setflag FLAG_DEFEATED_SEASHORE_HOUSE
	release
	end

Route109_SeashoreHouse_EventScript_TrainersNotCompleted::
	release
	end

Route109_SeashoreHouse_Text_SeashoreHouseIntro:
	.string "Sono il proprietario della CASA SUL MARE.\n"
	.string "Ma puoi chiamarmi SIGNOR MARE!\p"
	.string "Ciò che amo più di tutto sono le\n"
	.string "battaglie infuocate fra POKéMON.\p"
	.string "Fammi vedere che il tuo cuore brucia!\p"
	.string "Se batti tutti gli ALLENATORI\n"
	.string "qui, ricompenserò i tuoi sforzi.$"

Route109_SeashoreHouse_Text_ShowMeSomeHotMatches:
	.string "Fammi vedere sfide infuocate!\p"
	.string "Ho aperto questa CASA SUL MARE solo\n"
	.string "per questo motivo!$"

Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles:
	.string "Sei un vero vulcano!\n"
	.string "Che battaglie infuocate!\l"
	.string "Sono più che soddisfatto!\p"
	.string "Come ringraziamento per la tua\n"
	.string "bravura, voglio darti questo.\p"
	.string "Sono sei bottiglie di SODA POP!$"

Route109_SeashoreHouse_Text_BagFull:
	.string "Oh, però ehi, la tua BORSA è piena zeppa.\n"
	.string "Te li tengo io questi.$"

Route109_SeashoreHouse_Text_WantToBuySodaPop:
	.string "Vuoi comprare una SODA POP?\n"
	.string "I POKéMON la adorano!\p"
	.string "Solo ¥300 a bottiglia!\n"
	.string "Compra!$"

Route109_SeashoreHouse_Text_HereYouGo:
	.string "Ecco a te!$"

Route109_SeashoreHouse_Text_NotEnoughMoney:
	.string "Non hai abbastanza soldi.$"

Route109_SeashoreHouse_Text_ThatsTooBad:
	.string "No?\n"
	.string "Che peccato.$"

Route109_SeashoreHouse_Text_DwayneIntro:
	.string "Se cerchi una battaglia nella\n"
	.string "CASA SUL MARE, non troverai un\l"
	.string "ALLENATORE più caldo di me, amico!$"

Route109_SeashoreHouse_Text_DwayneDefeated:
	.string "Che battaglia infuocata!\n"
	.string "Accetto la sconfitta, amico!$"

Route109_SeashoreHouse_Text_DwaynePostBattle:
	.string "Quando sono a PORTOVECCHIO, mi godo\n"
	.string "battaglie calde e SODA POP ghiacciata!$"

Route109_SeashoreHouse_Text_JohannaIntro:
	.string "Le lotte noiose non valgono la fatica.\p"
	.string "Sono le lotte infuocate che temprano\n"
	.string "ALLENATORI e POKéMON!$"

Route109_SeashoreHouse_Text_JohannaDefeated:
	.string "Che caldo!$"

Route109_SeashoreHouse_Text_JohannaPostBattle:
	.string "Fiu, che sete.\n"
	.string "Forse mi berrò una SODA POP.$"

Route109_SeashoreHouse_Text_SimonIntro:
	.string "Ti mostrerò quanto sono forti\n"
	.string "i miei POKéMON, ma non piangere!$"

Route109_SeashoreHouse_Text_SimonDefeated:
	.string "…Ho perso, ma non piangerò…$"

Route109_SeashoreHouse_Text_SimonPostBattle:
	.string "Se uno dei miei POKéMON sapesse la mossa\n"
	.string "per portarmi sull'acqua sulla sua\l"
	.string "schiena, potrei buttare questo canotto.$"

