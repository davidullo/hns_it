AbandonedShip_Rooms_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms_1F_EventScript_Gentleman::
	msgbox AbandonedShip_Rooms_1F_Text_TakingALookAround, MSGBOX_NPC
	end

AbandonedShip_Rooms_1F_EventScript_Demetrius::
	trainerbattle_single TRAINER_DEMETRIUS, AbandonedShip_Rooms_1F_Text_DemetriusIntro, AbandonedShip_Rooms_1F_Text_DemetriusDefeat
	msgbox AbandonedShip_Rooms_1F_Text_DemetriusPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_EventScript_Thalia::
	trainerbattle_single TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaIntro, AbandonedShip_Rooms_1F_Text_ThaliaDefeat, AbandonedShip_Rooms_1F_EventScript_RegisterThalia
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms_1F_EventScript_ThaliaRematch
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms_1F_EventScript_RegisterThalia::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_THALIA_1
	release
	end

AbandonedShip_Rooms_1F_EventScript_ThaliaRematch::
	trainerbattle_rematch TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro, AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_Text_TakingALookAround:
	.string "Navi di questo tipo sono rare, quindi\n"
	.string "do un'occhiata in giro.\p"
	.string "Umm…\n"
	.string "Sembra esserci altre cabine…$"

AbandonedShip_Rooms_1F_Text_ThaliaIntro:
	.string "Cosa ti spinge a venire in un\n"
	.string "posto così? Sarai curioso!$"

AbandonedShip_Rooms_1F_Text_ThaliaDefeat:
	.string "Non solo curiosa, ma anche forte…$"

AbandonedShip_Rooms_1F_Text_ThaliaPostBattle:
	.string "Il tipo della porta accanto…\p"
	.string "Dice che è solo in vacanza,\n"
	.string "ma non mi convince.$"

AbandonedShip_Rooms_1F_Text_ThaliaRegister:
	.string "Che ALLENATORE tosto!\n"
	.string "Ti registrerò come Memento!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro:
	.string "Cosa ti spinge ancora a\n"
	.string "tornare qui? Sarai proprio curioso!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat:
	.string "Ma non sei troppo forte?$"

AbandonedShip_Rooms_1F_Text_ThaliaPostRematch:
	.string "Quel tipo sta combinando qualcosa!\n"
	.string "Si comporta in modo sospetto!$"

AbandonedShip_Rooms_1F_Text_DemetriusIntro:
	.string "Waaah!\n"
	.string "Mi hai trovato! …Eh?$"

AbandonedShip_Rooms_1F_Text_DemetriusDefeat:
	.string "Oh, tu non sei la mamma.$"

AbandonedShip_Rooms_1F_Text_DemetriusPostBattle:
	.string "La mamma è arrabbiata, sono fuggito.\n"
	.string "Non dire a nessuno dove sono!$"

