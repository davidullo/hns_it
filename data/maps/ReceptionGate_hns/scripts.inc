ReceptionGate_hns_MapScripts::
	.byte 0

ReceptionGate_EventScript_Janine::
    lock
    faceplayer
    msgbox ReceptionGate_Text_Janine, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_ROUTE22_JANINE
    removeobject LOCALID_INDIGOJUNCTION_JANINE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_JANINE
    release
    end

ReceptionGate_Text_Janine:
    .string "NINA: Sto andando a casa di mio\n"
    .string "padre a portargli il pranzo.\p"
    .string "L'ELITE FOUR non riposa mai,\n"
    .string "giorno e notte. È un duro lavoro,\l"
    .string "sai?\p"
    .string "Se sei pronto per un'altra lotta,\n"
    .string "più tardi sarò al DOJO.$"


ReceptionGate_EventScript_Officer::
    msgbox VictoryRoadGate_Text_EightBadges, MSGBOX_NPC
    end

ReceptionGate_Trigger::
    lock
    playse SE_PIN
    applymovement LOCALID_INDIGOJUNCTION_POLICEMAN, Common_Movement_ExclamationMark
    delay 55
    waitmovement LOCALID_INDIGOJUNCTION_POLICEMAN
    goto_if_lt VAR_ECRUTEAK_CITY_THEATER, 8, ReceptionGate_EventScript_Kimono
    msgbox VictoryRoadGate_Text_Officer, MSGBOX_DEFAULT
    goto_if_unset FLAG_BADGE08_GET, ReceptionGate_EventScript_NotEnough
    msgbox VictoryRoadGate_Text_EightBadges, MSGBOX_DEFAULT
    closemessage
    setvar VAR_ROUTE27_STATE, 2
    release
    end

ReceptionGate_EventScript_Kimono::
    msgbox VictoryRoadGate_Text_Kimono, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
    waitmovement 0
    release
    end 

ReceptionGate_EventScript_NotEnough::
    msgbox VictoryRoadGate_Text_NotEnoughBadges, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
    waitmovement 0
    release
    end

ReceptionGate_EventScript_SilverGuard::
    msgbox VictoryRoadGate_Text_LeftBlackBelt, MSGBOX_NPC
    end
ReceptionGate_EventScript_KantoGuard::
    msgbox VictoryRoadGate_Text_RightBlackBelt, MSGBOX_NPC
    end

VictoryRoadGate_Text_Officer:
    .string "Passano solo gli allenatori che\n"
    .string "lo hanno dimostrato.$"

VictoryRoadGate_Text_Kimono:
    .string "Mi spiace, di qui è chiuso finché\n"
    .string "qualcuno non sistema quel POKéMON\l"
    .string "LEGGENDARIO…$"

VictoryRoadGate_Text_NotEnoughBadges:
    .string "Non hai tutte le MEDAGLIE\n"
    .string "di JOHTO.\p"
    .string "Mi spiace, ma non posso\n"
    .string "farti passare.$"

VictoryRoadGate_Text_EightBadges:
    .string "Oh! Le otto MEDAGLIE di JOHTO!\p"
    .string "Prego, passa pure!$"

VictoryRoadGate_Text_LeftBlackBelt:
    .string "Di qui si va al MT.SILVER.\p"
    .string "Ci sono POKéMON spaventosamente\n"
    .string "forti.$"

VictoryRoadGate_Text_RightBlackBelt:
    .string "Vai alla LEGA POKéMON, eh?\p"
    .string "L'ELITE FOUR è così forte da fare\n"
    .string "paura, e ti sta aspettando!$"
