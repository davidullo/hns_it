Route15_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route15_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route15_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route15_EventScript_Colette::
	trainerbattle_single TRAINER_COLETTE_HNS, Route15_Text_TeacherColetteSeen, Route15_Text_TeacherColetteBeaten
	msgbox Route15_Text_TeacherColetteAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Hillary::
	trainerbattle_single TRAINER_HILLARY_HNS, Route15_Text_TeacherHillarySeen, Route15_Text_TeacherHillaryBeaten, Route15_EventScript_RegisterHillary
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route15_EventScript_RematchHillary
	msgbox Route15_Text_TeacherHillaryAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_RegisterHillary::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route15_Text_HillaryRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_HILLARY_HNS
	release
	end

Route15_EventScript_RematchHillary::
	trainerbattle_rematch TRAINER_HILLARY_HNS, Route15_Text_HillaryRematchIntro, Route15_Text_HillaryRematchDefeat
	msgbox Route15_Text_HillaryPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_HILLARY_2_HNS, Route15_EventScript_RematchHillaryTryGiveItem
	end

Route15_EventScript_RematchHillaryTryGiveItem::
	checkitem ITEM_TM_ENERGY_BALL
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_ENERGY_BALL
	closemessage
	end

Route15_EventScript_Kipp::
	trainerbattle_single TRAINER_KIPP_HNS, Route15_Text_SchoolboyKippSeen, Route15_Text_SchoolboyKippBeaten
	msgbox Route15_Text_SchoolboyKippAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY_HNS, Route15_Text_SchoolboyTommySeen, Route15_Text_SchoolboyTommyBeaten
	msgbox Route15_Text_SchoolboyTommyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Johnny::
	trainerbattle_single TRAINER_JOHNNY_HNS, Route15_Text_SchoolboyJohnnySeen, Route15_Text_SchoolboyJohnnyBeaten
	msgbox Route15_Text_SchoolboyJohnnyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Billy::
	trainerbattle_single TRAINER_BILLY_HNS, Route15_Text_SchoolboyBillySeen, Route15_Text_SchoolboyBillyBeaten, Route15_EventScript_RegisterBilly
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route15_EventScript_RematchBilly
	msgbox Route15_Text_SchoolboyBillyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_RegisterBilly::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route15_Text_BillyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BILLY_HNS
	release
	end

Route15_EventScript_RematchBilly::
	trainerbattle_rematch TRAINER_BILLY_HNS, Route15_Text_BillyRematchIntro, Route15_Text_BillyRematchDefeat
	msgbox Route15_Text_BillyPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_BILLY_2_HNS, Route15_EventScript_RematchBillyTryGiveItem
	end

Route15_EventScript_RematchBillyTryGiveItem::
	checkitem ITEM_TM_FACADE
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_FACADE
	closemessage
	end

Route15_EventScript_Sign::
	msgbox Route15_Text_Sign, MSGBOX_SIGN
	end

Route15_EventScript_PPup::
	finditem ITEM_PP_UP
	end

Route15_Text_TeacherColetteSeen:
	.string "Hai dimenticato qualcosa?$"

Route15_Text_TeacherColetteBeaten:
	.string "Ahiaaah!$"

Route15_Text_TeacherColetteAfterBattle:
	.string "Prima di fare l'insegnante\n"
	.string "dimenticavo un sacco di cose.$"

Route15_Text_TeacherHillarySeen:
	.string "Nei giorni di sole, penso che i\n"
	.string "ragazzi preferirebbero giocare in\l"
	.string "cortile invece di studiare in classe.$"

Route15_Text_TeacherHillaryBeaten:
	.string "Non volevo perdere…$"

Route15_Text_TeacherHillaryAfterBattle:
	.string "Studiare è importante, ma\n"
	.string "anche muoversi lo è.$"

Route15_Text_HillaryRegister:
	.string "Mi hai dato una bella lezione!\n"
	.string "Posso avere il tuo numero?$"

Route15_Text_HillaryRematchIntro:
	.string "Stavolta ti faccio scuola!$"

Route15_Text_HillaryRematchDefeat:
	.string "Torno a studiare…$"

Route15_Text_HillaryPostRematch:
	.string "Insegnare ai POKéMON è come\n"
	.string "ai bambini. Ci vuole pazienza!$"

Route15_Text_SchoolboyKippSeen:
	.string "Aspetta, devo chiamare la mamma.$"

Route15_Text_SchoolboyKippBeaten:
	.string "Scusa, mamma! Ho perso!$"

Route15_Text_SchoolboyKippAfterBattle:
	.string "Mia mamma si preoccupa così tanto\n"
	.string "che devo chiamarla di continuo.$"

Route15_Text_SchoolboyTommySeen:
	.string "Lottiamo. Non perderò!$"

Route15_Text_SchoolboyTommyBeaten:
	.string "Ho dimenticato i compiti!$"

Route15_Text_SchoolboyTommyAfterBattle:
	.string "Sayonara! L'ho appena imparato\n"
	.string "a lezione di giapponese.$"

Route15_Text_SchoolboyJohnnySeen:
	.string "Siamo in gita alla TORRE RADIO\n"
	.string "di LAVANDIA per geografia.$"

Route15_Text_SchoolboyJohnnyBeaten:
	.string "Sei davvero forte!$"

Route15_Text_SchoolboyJohnnyAfterBattle:
	.string "Sono stanco di camminare. Devo\n"
	.string "fare una pausa.$"

Route15_Text_SchoolboyBillySeen:
	.string "La mia materia preferita è la Palestra!$"

Route15_Text_SchoolboyBillyBeaten:
	.string "Oh, no! Come ho potuto perdere?$"

Route15_Text_SchoolboyBillyAfterBattle:
	.string "Se i POKéMON fossero una materia\n"
	.string "a scuola, sarei il migliore!$"

Route15_Text_BillyRegister:
	.string "Dovevo stare più attento in classe.\n"
	.string "Posso avere il tuo numero?$"

Route15_Text_BillyRematchIntro:
	.string "Ho studiato tanto!\n"
	.string "Ti mostro cosa ho imparato!$"

Route15_Text_BillyRematchDefeat:
	.string "Devo studiare di più…$"

Route15_Text_BillyPostRematch:
	.string "La cultura non è tutto.\n"
	.string "Mi serve esperienza sul campo!$"

Route15_Text_Sign:
	.string "PERCORSO 15\p"
	.string "FUCHSIA - LAVANDIA$"

