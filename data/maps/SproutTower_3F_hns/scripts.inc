SproutTower_3F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SproutTower_3F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

SproutTower_3F_OnTransition: 
	callnative SetTimeBasedEncounters
	end


SproutTower_3F_EventScript_SageJin::
	trainerbattle_single TRAINER_JIN_HNS, SproutTower_Text_SageJin_Seen, SproutTower_Text_SageJin_Beaten
	msgbox SproutTower_Text_SageJin_AfterBattle, MSGBOX_AUTOCLOSE
	end


SproutTower_3F_EventScript_SageNeal::
	trainerbattle_single TRAINER_NEAL_HNS, SproutTower_Text_SageNeal_Seen, SproutTower_Text_SageNeal_Beaten
	msgbox SproutTower_Text_SageNeal_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_3F_EventScript_SageTroy::
	trainerbattle_single TRAINER_TROY_HNS, SproutTower_Text_SageTroy_Seen, SproutTower_Text_SageTroy_Beaten
	msgbox SproutTower_Text_SageTroy_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_3F_EventScript_Painting::
	lock
	msgbox SproutTower_Text_3F_Painting, MSGBOX_AUTOCLOSE
	release
	end

SproutTower_3F_EventScript_Potion::
	finditem ITEM_POTION
	end

SproutTower_3F_EventScript_EscapeRope::
	finditem ITEM_ESCAPE_ROPE
	end

SproutTower_3F_EventScript_TriggerSceneLeft::
	lock
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_Silver1
	waitmovement 0
	msgbox SproutTower_Text_ElderLecturesRival, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_SPROUT_TOWER_SILVER, Common_Movement_ExclamationMark	
	delay 55
	waitmovement LOCALID_SPROUT_TOWER_SILVER
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_SilverLeft
	waitmovement 0
	msgbox SproutTower_Text_RivalOnlyCaresStrong, MSGBOX_DEFAULT
	delay 30
	msgbox SproutTower_Text_RivalUsedEscapeRope, MSGBOX_DEFAULT
	applymovement LOCALID_SPROUT_TOWER_SILVER SproutTower_3F_Movement_EscapeRope
	waitmovement 0
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_SPROUT_TOWER_SILVER
	removeobject LOCALID_SPROUT_TOWER_SILVER
	delay 55
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	fadedefaultbgm
	setvar VAR_SPROUT_TOWER, 1
	release
	end

SproutTower_3F_EventScript_TriggerSceneRight::
	lock
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_Silver1
	waitmovement 0
	msgbox SproutTower_Text_ElderLecturesRival, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_SPROUT_TOWER_SILVER, Common_Movement_ExclamationMark	
	delay 55
	waitmovement LOCALID_SPROUT_TOWER_SILVER
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_SilverRight
	waitmovement 0
	waitmovement 0
	msgbox SproutTower_Text_RivalOnlyCaresStrong, MSGBOX_DEFAULT
	msgbox SproutTower_Text_RivalUsedEscapeRope, MSGBOX_DEFAULT
	applymovement LOCALID_SPROUT_TOWER_SILVER SproutTower_3F_Movement_EscapeRope
	waitmovement 0
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_SPROUT_TOWER_SILVER
	removeobject LOCALID_SPROUT_TOWER_SILVER
	delay 55
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	fadedefaultbgm
	setvar VAR_SPROUT_TOWER, 1
	release
	end

SproutTower_3F_EventScript_SageLi::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, SproutTower_3F_EventScript_SageLi_Beaten
	msgbox SproutTower_Text_SageLi_Seen, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LI_HNS, SproutTower_Text_SageLi_Beaten
	msgbox SproutTower_Text_SageLi_TakeFlash, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox SproutTower_Text_SageLi_FlashExplain, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_3F_EventScript_SageLi_Beaten::
	msgbox SproutTower_Text_SageLi_AfterBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_3F_Movement_Silver1:
	walk_fast_up
	walk_fast_up
	step_end

SproutTower_3F_Movement_SilverLeft:
	face_down
	delay_16
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

SproutTower_3F_Movement_SilverRight:
	face_down
	delay_16
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

SproutTower_3F_Movement_EscapeRope:
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	step_end

SproutTower_Text_ElderLecturesRival:
	.string "ANZIANO: Sei davvero abile\n"
	.string "come allenatore.\p"
	.string "Come promesso, ecco la tua MN.\p"
	.string "Ma lascia che ti dica una cosa:\n"
	.string "dovresti trattare meglio i POKéMON.\p"
	.string "Il tuo modo di lottare è troppo\n"
	.string "duro.\p"
	.string "I POKéMON non sono armi…$"

SproutTower_Text_RivalOnlyCaresStrong:
	.string "…\n"
	.string "…Umpf!\p"
	.string "Dice di essere l'ANZIANO ma\n"
	.string "è debole.\p"
	.string "C'è da aspettarselo.\p"
	.string "Non perderei mai con chi blatera\n"
	.string "di essere gentile coi POKéMON.\p"
	.string "Mi interessano solo i POKéMON\n"
	.string "forti che sanno vincere.\p"
	.string "Non me ne importa nulla\n"
	.string "dei POKéMON deboli.$"

SproutTower_Text_RivalUsedEscapeRope:
	.string "{RIVAL} usa una CORDA FUGA!$"

SproutTower_Text_SageLi_Seen:
	.string "Che bello che tu sia qui!\p"
	.string "La TORRE SPROUT è un luogo\n"
	.string "di allenamento.\p"
	.string "Persone e POKéMON mettono alla\n"
	.string "prova il loro legame per un\l"
	.string "futuro brillante.\p"
	.string "Io sono la prova finale.\p"
	.string "Fammi vedere il legame\n"
	.string "tra te e i tuoi POKéMON!$"

SproutTower_Text_SageLi_Beaten:
	.string "Ah, eccellente!$"

SproutTower_Text_SageLi_TakeFlash:
	.string "Tu e i tuoi POKéMON\n"
	.string "non avrete problemi con questa mossa.\p"
	.string "Prendi questa MN BALENO.$"

SproutTower_Text_SageLi_FlashExplain:
	.string "BALENO illumina anche\n"
	.string "i luoghi più bui.\p"
	.string "Ma per usarlo fuori dalla lotta serve\n"
	.string "la MEDAGLIA della PALESTRA di VIOLET.$"

SproutTower_Text_SageLi_AfterBattle:
	.string "Spero che il tuo viaggio ti insegni\n"
	.string "e ti faccia crescere.$"

SproutTower_Text_SageJin_Seen:
	.string "Mi alleno per trovare l'illuminazione\n"
	.string "nei POKéMON!$"

SproutTower_Text_SageJin_Beaten:
	.string "Il mio allenamento è incompleto…$"

SproutTower_Text_SageJin_AfterBattle:
	.string "Se i POKéMON crescono,\n"
	.string "cresce anche l'allenatore.\p"
	.string "No, aspetta. Se cresce\n"
	.string "l'allenatore, crescono\l"
	.string "anche i POKéMON.$"

SproutTower_Text_SageTroy_Seen:
	.string "Vediamo quanto ti fidi\n"
	.string "dei tuoi POKéMON.$"

SproutTower_Text_SageTroy_Beaten:
	.string "Sì, la tua fiducia è vera!$"

SproutTower_Text_SageTroy_AfterBattle:
	.string "L'ANZIANO non è lontano.$"

SproutTower_Text_SageNeal_Seen:
	.string "La MN dell'ANZIANO illumina\n"
	.string "anche il buio più pesto.$"

SproutTower_Text_SageNeal_Beaten:
	.string "È la mia testa a essere brillante!$"

SproutTower_Text_SageNeal_AfterBattle:
	.string "Che la luce ti accompagni\n"
	.string "nel viaggio.$"

SproutTower_Text_3F_Painting:
	.string "È un potente dipinto di un\n"
	.string "BELLSPROUT.$"
