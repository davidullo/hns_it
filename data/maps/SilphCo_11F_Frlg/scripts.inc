SilphCo_11F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_11F_OnLoad
	.byte 0

SilphCo_11F_OnLoad::
	call_if_unset FLAG_SILPH_11F_DOOR, EventScript_Close11FDoor
	end

SilphCo_11F_EventScript_President::
	lock
	faceplayer
	goto_if_set FLAG_GOT_MASTER_BALL_FROM_SILPH, SilphCo_11F_EventScript_AlreadyGotMasterBall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, SilphCo_11F_EventScript_PresidentThanksMale
	call_if_eq VAR_RESULT, FEMALE, SilphCo_11F_EventScript_PresidentThanksFemale
	checkitemspace ITEM_MASTER_BALL
	goto_if_eq VAR_RESULT, FALSE, SilphCo_11F_EventScript_NoRoomForMasterBall
	giveitem_msg SilphCo_11F_Text_ObtainedMasterBallFromPresident, ITEM_MASTER_BALL, 1, MUS_RG_OBTAIN_KEY_ITEM
	msgbox SilphCo_11F_Text_ThatsOurSecretPrototype
	setflag FLAG_GOT_MASTER_BALL_FROM_SILPH
	release
	end

SilphCo_11F_EventScript_PresidentThanksMale::
	msgbox SilphCo_11F_Text_ThanksForSavingMeDearBoy
	return

SilphCo_11F_EventScript_PresidentThanksFemale::
	msgbox SilphCo_11F_Text_ThanksForSavingMeDearGirl
	return

SilphCo_11F_EventScript_NoRoomForMasterBall::
	msgbox SilphCo_11F_Text_YouHaveNoRoomForThis
	release
	end

SilphCo_11F_EventScript_AlreadyGotMasterBall::
	msgbox SilphCo_11F_Text_ThatsOurSecretPrototype
	release
	end

SilphCo_11F_EventScript_Secretary::
	msgbox SilphCo_11F_Text_ThanksForRescuingUs, MSGBOX_NPC
	end

SilphCo_11F_EventScript_GiovanniTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto SilphCo_11F_EventScript_BattleGiovanni
	end

SilphCo_11F_EventScript_GiovanniTriggerRight::
	lockall
	setvar VAR_TEMP_1, 1
	goto SilphCo_11F_EventScript_BattleGiovanni
	end

SilphCo_11F_EventScript_BattleGiovanni::
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_SILPH_CO_GIOVANNI, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 25
	msgbox SilphCo_11F_Text_GiovanniIntro
	closemessage
	call_if_eq VAR_TEMP_1, 0, SilphCo_11F_EventScript_GiovanniApproachLeft
	call_if_eq VAR_TEMP_1, 1, SilphCo_11F_EventScript_GiovanniApproachRight
	setvar VAR_LAST_TALKED, LOCALID_SILPH_CO_GIOVANNI
	trainerbattle_no_intro TRAINER_BOSS_GIOVANNI_2, SilphCo_11F_Text_GiovanniDefeat
	msgbox SilphCo_11F_Text_GiovanniPostBattle
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_SILPH_CO_GIOVANNI
	removeobject LOCALID_SILPH_CO_11F_GRUNT1
	removeobject LOCALID_SILPH_CO_11F_GRUNT2
	fadescreen FADE_FROM_BLACK
	setvar VAR_MAP_SCENE_SILPH_CO_11F, 1
	setflag FLAG_HIDE_SAFFRON_ROCKETS
	clearflag FLAG_HIDE_SAFFRON_CIVILIANS
	releaseall
	end

SilphCo_11F_EventScript_GiovanniApproachLeft::
	applymovement LOCALID_SILPH_CO_GIOVANNI, SilphCo_11F_Movement_GiovanniApproachLeft
	applymovement LOCALID_PLAYER, SilphCo_11F_Movement_PlayerFaceGiovanni
	waitmovement 0
	return

SilphCo_11F_EventScript_GiovanniApproachRight::
	applymovement LOCALID_SILPH_CO_GIOVANNI, SilphCo_11F_Movement_GiovanniApproachRight
	waitmovement 0
	return

SilphCo_11F_Movement_GiovanniApproachLeft::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

SilphCo_11F_Movement_GiovanniApproachRight::
	walk_down
	walk_down
	walk_down
	step_end

SilphCo_11F_Movement_PlayerFaceGiovanni::
	delay_16
	delay_16
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_right
	step_end

@ Unused
SilphCo_11F_EventScript_Monitor::
	msgbox SilphCo_11F_Text_MonitorHasMonsOnIt, MSGBOX_SIGN
	end

SilphCo_11F_EventScript_FloorSign::
	msgbox SilphCo_11F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_11F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_40, SilphCo_11F_Text_Grunt1Intro, SilphCo_11F_Text_Grunt1Defeat
	msgbox SilphCo_11F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_11F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_41, SilphCo_11F_Text_Grunt2Intro, SilphCo_11F_Text_Grunt2Defeat
	msgbox SilphCo_11F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_11F_Text_ThanksForSavingMeDearBoy::
	.string "PRESIDENTE: Oh, ragazzo mio!\n"
	.string "Grazie per aver salvato la SILPH.\p"
	.string "Non dimenticherò mai che ci hai salvato\n"
	.string "nel nostro momento di pericolo.\p"
	.string "Devo ringraziarti in qualche modo.\p"
	.string "Dato che sono ricco, posso darti\n"
	.string "qualsiasi cosa.\p"
	.string "Tieni, forse questo andrà bene.$"

SilphCo_11F_Text_ThanksForSavingMeDearGirl::
	.string "PRESIDENTE: Oh, ragazza mia!\n"
	.string "Grazie per aver salvato la SILPH.\p"
	.string "Non dimenticherò mai che ci hai salvato\n"
	.string "nel nostro momento di pericolo.\p"
	.string "Devo ringraziarti in qualche modo.\p"
	.string "Dato che sono ricco, posso darti\n"
	.string "qualsiasi cosa.\p"
	.string "Tieni, forse questo andrà bene.$"

SilphCo_11F_Text_ObtainedMasterBallFromPresident::
	.string "{PLAYER} riceve una MASTER BALL\n"
	.string "dal PRESIDENTE!$"

SilphCo_11F_Text_ThatsOurSecretPrototype::
	.string "PRESIDENTE: Non puoi comprarla\n"
	.string "da nessuna parte.\p"
	.string "È il nostro prototipo segreto: la MASTER\n"
	.string "BALL.\p"
	.string "Cattura qualsiasi POKéMON senza\n"
	.string "fallire!\p"
	.string "Però è meglio non vantarsene\n"
	.string "in giro.$"

SilphCo_11F_Text_YouHaveNoRoomForThis::
	.string "Non hai spazio per questo.$"

SilphCo_11F_Text_ThanksForRescuingUs::
	.string "SEGRETARIA: Grazie per aver salvato\n"
	.string "tutti noi.\p"
	.string "Dal PRESIDENTE in giù,\n"
	.string "ti siamo debitori.$"

SilphCo_11F_Text_GiovanniIntro::
	.string "Ah, {PLAYER}!\n"
	.string "Ci incontriamo di nuovo!\p"
	.string "Il PRESIDENTE ed io stiamo discutendo\n"
	.string "un affare di vitale importanza.\p"
	.string "Fatti gli affari tuoi,\n"
	.string "ragazzino…\p"
	.string "O assaggerai un mondo di dolore!$"

SilphCo_11F_Text_GiovanniDefeat::
	.string "Argh!!\n"
	.string "Ho perso di nuovo!?$"

SilphCo_11F_Text_GiovanniPostBattle::
	.string "Maledizione!\n"
	.string "Hai rovinato i nostri piani per la SILPH!\p"
	.string "Ma il TEAM ROCKET non cadrà mai!\p"
	.string "{PLAYER}! Non dimenticare che tutti\n"
	.string "i POKéMON esistono per il TEAM ROCKET!\p"
	.string "Ora devo andare, ma tornerò!$"

SilphCo_11F_Text_Grunt2Intro::
	.string "Fermati!\n"
	.string "Non muoverti!$"

SilphCo_11F_Text_Grunt2Defeat::
	.string "No…\n"
	.string "Ti prego!$"

SilphCo_11F_Text_Grunt2PostBattle::
	.string "Vuoi vedere il mio CAPO, eh?$"

SilphCo_11F_Text_Grunt1Intro::
	.string "Fermo! Hai un appuntamento\n"
	.string "con il mio CAPO?$"

SilphCo_11F_Text_Grunt1Defeat::
	.string "Gah!\n"
	.string "Distrutto!$"

SilphCo_11F_Text_Grunt1PostBattle::
	.string "Guarda dove metti i piedi…\n"
	.string "Al mio CAPO piacciono i POKéMON tosti!$"

SilphCo_11F_Text_MonitorHasMonsOnIt::
	.string "Sul monitor ci sono dei POKéMON!$"

SilphCo_11F_Text_FloorSign::
	.string "SEDE SILPH SPA\n"
	.string "11P$"

