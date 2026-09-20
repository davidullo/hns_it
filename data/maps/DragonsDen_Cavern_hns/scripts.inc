DragonsDen_Cavern_hns_MapScripts::
	@map_script MAP_SCRIPT_ON_FRAME_TABLE, DragonsDen_Cavern_OnFrame
	.byte 0

DragonsDen_Cavern_OnFrame::
	map_script_2 VAR_BLACKTHORN_CITY_STATE, 3, DragonsDen_Cavern_EventScript_Clair
	.2byte 0

DragonsDen_EventScript_ClairRematch::
    lock
    faceplayer
    msgbox DragonsDen_Text_Clair, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_DEN_CLAIR
    removeobject LOCALID_DEN_CLAIR
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_CLAIR
    release
    end

DragonsDen_Text_Clair:
    .string "{PLAYER}… Sei qui.\p"
	.string "Se pensi di tenermi il passo,\n"
	.string "vieni alla DOJO di LOTTA a\l"
	.string "ZAFFERANOPOLI.$"

DragonsDen_Cavern_Trigger_ClairLeft::
	lock
	setflag FLAG_TEMP_HIDE_FOLLOWER 
	playse SE_PIN
	playbgm MUS_HG_CLAIR, FALSE
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_DRAGONSDEN2_CLAIR
	call DragonsDen_Cavern_EventScript_Clair
	applymovement OBJ_EVENT_ID_PLAYER, DragonsDen_Cavern_Movement_ClairLeaveLeftPLAYER
	waitmovement 0
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveLeft
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	setrespawn HEAL_LOCATION_BLACKTHORN_CITY_HNS
	releaseall
	end

DragonsDen_Cavern_Trigger_ClairMid::
	lock 
	playse SE_PIN
	playbgm MUS_HG_CLAIR, FALSE
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_DRAGONSDEN2_CLAIR
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	call DragonsDen_Cavern_EventScript_Clair
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveMid
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	release
	end

DragonsDen_Cavern_Trigger_ClairRight::
	lock 
	playse SE_PIN
	playbgm MUS_HG_CLAIR, FALSE
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_DRAGONSDEN2_CLAIR
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	call DragonsDen_Cavern_EventScript_Clair
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveRight
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	release
	end

DragonsDen_Cavern_EventScript_Clair::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox DragonsDen_Cavern_Text_Clair_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_DRAGON_PULSE
	msgbox DragonsDen_Cavern_Text_Clair_ExplainTM, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox DragonsDen_Cavern_Text_ClairWhatsTheMatter, MSGBOX_DEFAULT
	closemessage
	delay 10
	clearflag FLAG_GOT_DRATINI
	return

DragonsDen_Cavern_Movement_ClairLeaveLeftPLAYER:
	walk_fast_down
	face_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveLeft:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveMid:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveRight:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Text_Clair_GiveTM:
    .string "CLAIR: ASPETTA!\p"
	.string "Scusa per questo.\n"
    .string "Tieni, questo è per scusarmi.$"

DragonsDen_Cavern_Text_Clair_ExplainTM:
    .string "DRAGOPULSAR è una specie di\n"
	.string "ehm… lascia stare!\p"
	.string "È una specie di energia enorme.\p"
	.string "Se non lo vuoi, non devi\n"
	.string "prenderlo.$"

DragonsDen_Cavern_Text_ClairWhatsTheMatter:
    .string "Che succede? Non vai\n"
    .string "alla LEGA POKéMON?\l"
    .string "Dopo che diventi\p"
    .string "CAMPIONE, potrai sfidare di\n"
    .string "nuovo ogni CAPOPALESTRA\l"
    .string "che vuoi.\p"
    .string "Vai alla LEGA POKéMON.\p"
    .string "Sai come arrivarci?\p"
    .string "Da qui vai a NEW BARK TOWN.\p"
    .string "Poi SURF a est fino alla LEGA\p"
    .string "POKéMON. La strada è dura.\p"
    .string "Non osare perdere alla LEGA\n"
    .string "POKéMON!\p"
    .string "Se perdi, mi sentirò\n"
    .string "ancora peggio per averti\p"
    .string "perso! Dai il massimo.$"

DragonsDen_Cavern_EventScript_Darin::
	trainerbattle_single TRAINER_DARIN_HNS, DragonsDen_Cavern_Text_CooltrainermDarinSeen, DragonsDen_Cavern_Text_CooltrainermDarinBeaten
	msgbox DragonsDen_Cavern_Text_CooltrainermDarinAfter, MSGBOX_AUTOCLOSE
	end

DragonsDen_Cavern_EventScript_Cara::
	trainerbattle_single TRAINER_CARA_HNS, DragonsDen_Cavern_Text_CooltrainerfCaraSeen, DragonsDen_Cavern_Text_CooltrainerfCaraBeaten
	msgbox DragonsDen_Cavern_Text_CooltrainerfCaraAfter, MSGBOX_AUTOCLOSE
	end

DragonsDen_Cavern_EventScript_TwinLea::
	trainerbattle_double TRAINER_LEA_AND_PIA_HNS, DragonsDen_Cavern_Text_TwinsLeaandPia1Seen, DragonsDen_Cavern_Text_TwinsLeaandPia1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox DragonsDen_Cavern_Text_TwinsLeaandPia1After, MSGBOX_DEFAULT
	release
	end
	
DragonsDen_Cavern_EventScript_TwinPia::
	trainerbattle_double TRAINER_LEA_AND_PIA_HNS, DragonsDen_Cavern_Text_TwinsLeaandPia2Seen, DragonsDen_Cavern_Text_TwinsLeaandPia2Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox DragonsDen_Cavern_Text_TwinsLeaandPia2After, MSGBOX_DEFAULT
	release
	end

DragonsDen_Cavern_EventScript_Item_Dragon_Fang::
	finditem ITEM_DRAGON_FANG
	end
DragonsDen_Cavern_EventScript_Item_Max_Potion::
	finditem ITEM_MAX_POTION
	end
DragonsDen_Cavern_EventScript_Item_PP_Max::
	finditem ITEM_PP_MAX
	end



DragonsDen_Cavern_Text_DragonShrineSign:
    .string "DRAGON SHRINE\p"
    .string "Un santuario per il drago\n"
    .string "POKéMON\p"
    .string "che si dice vivesse nel\n"
    .string "DRAGON'S DEN.$"

DragonsDen_Cavern_Text_SilverTraining1:
    .string "…\n"
    .string "Cosa? {PLAYER}?\p"
    .string "…No, non ti sfido adesso…\p"
    .string "I miei POKéMON non sono pronti\n"
    .string "a batterti.\p"
    .string "Non posso forzarli troppo ora.\p"
    .string "Devo essere disciplinato per\n"
    .string "diventare il miglior allenatore POKéMON…$"

DragonsDen_Cavern_Text_SilverTraining2:
    .string "…\p"
    .string "Fiu…\p"
    .string "Impara a non intralciarmi…$"

DragonsDen_Cavern_Text_CooltrainermDarinSeen:
    .string "Tu! Come osi entrare\n"
    .string "senza invito!$"

DragonsDen_Cavern_Text_CooltrainermDarinBeaten:
    .string "F-forte!$"

DragonsDen_Cavern_Text_CooltrainermDarinAfter:
    .string "Il SANTUARIO davanti è la\n"
    .string "casa del MAESTRO del nostro\p"
    .string "clan di draghi. Non si entra!$"

DragonsDen_Cavern_Text_CooltrainerfCaraSeen:
    .string "Non dovresti stare qui!$"

DragonsDen_Cavern_Text_CooltrainerfCaraBeaten:
    .string "Oh, ho perso!$"

DragonsDen_Cavern_Text_CooltrainerfCaraAfter:
    .string "Presto avrò il permesso del\n"
    .string "nostro MAESTRO di usare i draghi.\p"
    .string "Allora diventerò un'abile\n"
    .string "allenatrice di draghi e avrò\l"
    .string "la sua approvazione.$"

DragonsDen_Cavern_Text_TwinsLeaandPia1Seen:
    .string "È uno sconosciuto.$"

DragonsDen_Cavern_Text_TwinsLeaandPia1Beaten:
    .string "Ahia!$"

DragonsDen_Cavern_Text_TwinsLeaandPia1After:
    .string "È stato come lottare contro\n"
    .string "LANCE.$"

DragonsDen_Cavern_Text_TwinsLeaandPia2Seen:
    .string "Chi sei?$"

DragonsDen_Cavern_Text_TwinsLeaandPia2Beaten:
    .string "Peste!$"

DragonsDen_Cavern_Text_TwinsLeaandPia2After:
    .string "Lo diremo.\p"
    .string "Il MASTER si arrabbierà.$"
