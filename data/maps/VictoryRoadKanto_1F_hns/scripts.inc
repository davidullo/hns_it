VictoryRoadKanto_1F_hns_MapScripts::
	.byte 0

VictoryRoadKanto_1F_EventScript_Item_RareCandy::
	finditem ITEM_RARE_CANDY
	end
VictoryRoadKanto_1F_EventScript_Item_MaxEther::
	finditem ITEM_MAX_ETHER
	end
VictoryRoadKanto_EventScript_Item_Dark_Pulse::
    finditem ITEM_TM_DARK_PULSE
    end

VictoryRoadKanto_1F_Trigger::
	lock
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	delay 5
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	addobject LOCALID_VICTORYROAD_SILVER
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 27, VictoryRoadKanto_1F_EventScript_SilverEnterLeft
	call_if_eq VAR_TEMP_0, 28, VictoryRoadKanto_1F_EventScript_SilverEnterMid
	call_if_eq VAR_TEMP_0, 29, VictoryRoadKanto_1F_EventScript_SilverEnterRight
	msgbox VictoryRoad_Text_RivalBefore, MSGBOX_DEFAULT
	call_if_eq VAR_STARTER_MON, 0, VictoryRoadKanto_1F_Silver_Battle_Cyndaquil
	call_if_eq VAR_STARTER_MON, 1, VictoryRoadKanto_1F_Silver_Battle_Totodile
	call_if_eq VAR_STARTER_MON, 2, VictoryRoadKanto_1F_Silver_Battle_Chikorita
	playbgm MUS_HG_RIVAL_EXIT, FALSE
	msgbox VictoryRoad_Text_RivalAfter, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_VICTORYROAD_SILVER, VictoryRoadKanto_1F_Movement_SilverLeave
	waitmovement 0
	removeobject LOCALID_VICTORYROAD_SILVER
	fadedefaultbgm
	release
	setvar VAR_ROUTE27_STATE, 3
	end

VictoryRoadKanto_1F_EventScript_SilverEnterLeft::
	applymovement2 LOCALID_VICTORYROAD_SILVER, VictoryRoadKanto_1F_Movement_SilverEnterLeft
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	applymovement2 OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkUp1
	waitmovement LOCALID_VICTORYROAD_SILVER
	return

VictoryRoadKanto_1F_EventScript_SilverEnterMid::
	applymovement2 LOCALID_VICTORYROAD_SILVER, VictoryRoadKanto_1F_Movement_SilverEnterMid
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	applymovement2 OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkUp1
	waitmovement LOCALID_VICTORYROAD_SILVER
	return

VictoryRoadKanto_1F_EventScript_SilverEnterRight::
	applymovement2 LOCALID_VICTORYROAD_SILVER, VictoryRoadKanto_1F_Movement_SilverEnterRight
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	applymovement2 OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkUp1
	waitmovement LOCALID_VICTORYROAD_SILVER
	return


VictoryRoadKanto_1F_Silver_Battle_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_5_HNS, VictoryRoad_Text_RivalDefeat
	return

VictoryRoadKanto_1F_Silver_Battle_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_5_HNS, VictoryRoad_Text_RivalDefeat
	return

VictoryRoadKanto_1F_Silver_Battle_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_5_HNS, VictoryRoad_Text_RivalDefeat
	return

VictoryRoadKanto_1F_Movement_SilverEnterLeft:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end
VictoryRoadKanto_1F_Movement_SilverEnterMid:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end
VictoryRoadKanto_1F_Movement_SilverEnterRight:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end
VictoryRoadKanto_1F_Movement_SilverLeave:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

VictoryRoad_Text_RivalBefore:
    .string "Fermo.\p"
    .string "…Vuoi affrontare la sfida della\n"
    .string "LEGA POKéMON?\p"
    .string "…Non farmi ridere.\p"
    .string "Sei molto più debole di me.\p"
    .string "Non sono più quello di prima.\p"
    .string "Ora ho con me i POKéMON\n"
    .string "migliori e più forti.\p"
    .string "Sono invincibile!\p"
    .string "{PLAYER}!\n"
    .string "Ti sfido!$"

VictoryRoad_Text_RivalDefeat:
    .string "…Non ho potuto vincere…\p"
    .string "Ho dato tutto quello che avevo…\p"
    .string "Ciò che tu possiedi, e ciò che a me manca…\p"
    .string "Comincio a capire quello che\n"
    .string "mi ha detto quel maestro di draghi…$"

VictoryRoad_Text_RivalAfter:
    .string "…Non ho rinunciato a diventare il\n"
    .string "più grande allenatore…\p"
    .string "Scoprirò perché non riesco a\n"
    .string "vincere e diventerò più forte…\p"
    .string "Quando ci riuscirò, ti sfiderò.\p"
    .string "E ti batterò con tutta la mia\n"
    .string "forza.\p"
    .string "…Umpf! Nel frattempo, continua così.$"
