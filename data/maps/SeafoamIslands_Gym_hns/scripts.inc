SeafoamIslands_Gym_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SeafoamIslands_Gym_OnTransition
	.byte 0

SeafoamIslands_Gym_OnTransition: 
	setflag FLAG_TEMP_1
	end

SeafoamIslands_Gym_EventScript_Blaine::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CINNABAR_ISLAND_GYM, SeafoamIslands_Gym_EventScript_Blaine_Defeated
	msgbox SeafoamIslands_Gym_Text_BlaineIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BLAINE_HNS, SeafoamIslands_Gym_Text_BlaineWinLoss
	message SeafoamIslands_Gym_Text_ReceivedVolcanoBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SeafoamIslands_Gym_Text_Blaine_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_OVERHEAT
	msgbox SeafoamIslands_Gym_Text_Blaine_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE15_GET
	setflag FLAG_DEFEATED_CINNABAR_ISLAND_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 15
	clearflag FLAG_HIDE_SEAFOAM_GYMGUY
	call Common_EventScript_SetGymTrainers_hns
	closemessage
	release
	end

SeafoamIslands_Gym_EventScript_Blaine_Defeated::
	msgbox SeafoamIslands_Gym_Text_BlaineAfterBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

SeafomIslands2_EventScript_GymGuide::
	goto_if_set FLAG_TEMP_2, SeafomIslands2_EventScript_GymGuide2
	msgbox SeafoamIslands_Gym_Text_GymGuideWin, MSGBOX_NPC
	setflag FLAG_TEMP_2
	end
SeafomIslands2_EventScript_GymGuide2::
	msgbox SeafoamIslands_Gym_Text_GymGuideWin2, MSGBOX_NPC
	end

SeafoamIslands_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE15_GET, SeafoamIslands_Gym_EventScript_GymStatuePostVictory
	msgbox SeafoamIslands_Gym_Text_GymStatue
	releaseall
	end

SeafoamIslands_Gym_EventScript_GymStatuePostVictory::
	msgbox SeafoamIslands_Gym_Text_GymStatuePlayerWon
	releaseall
	end

SeafoamIslands_Gym_Text_GymStatue::
    .string "PALESTRA POKéMON di ISOLA CANNELLA\n"
    .string "CAPOPALESTRA: BLAINE\p"
	.string "ALLENATORI VINCENTI:\n"
	.string "BLU, ROSSO$"

SeafoamIslands_Gym_Text_GymStatuePlayerWon::
    .string "PALESTRA POKéMON di ISOLA CANNELLA\n"
    .string "CAPOPALESTRA: BLAINE\p"
    .string "ALLENATORI VINCENTI:\n"
	.string "BLU, ROSSO, {PLAYER}$"

SeafoamIslands_Gym_Text_Blaine_GiveTM:
	.string "Prendi anche questa!$"

SeafoamIslands_Gym_Text_Blaine_ExplainTM:
	.string "Questa MT contiene\n"
	.string "la potente VAMPATA!\p"
	.string "Il calore travolgente brucia gli\n"
	.string "avversari, ma poi ti indebolisce.\p"
	.string "Spero che il prossimo avversario abbia\n"
	.string "un'ANTISCOTTATURA! Uaah!$"

SeafoamIslands_Gym_Text_BlaineIntro:
	.string "BLAINE: Waaah!\p"
	.string "La mia PALESTRA di ISOLA CANNELLA\nè bruciata.\p"
	.string "Io e i miei POKéMON sputafuoco siamo\n"
	.string "senza tetto per colpa del vulcano.\p"
	.string "Waaah!\p"
	.string "Ma ho ripreso l'attività come CAPO\n"
	.string "PALESTRA qui in questa grotta.\p"
	.string "Se riesci a battermi, ti darò\n"
	.string "una MEDAGLIA.\p"
	.string "Ah! Meglio che tu abbia un ANTISCOTT.$"

SeafoamIslands_Gym_Text_BlaineWinLoss:
	.string "BLAINE: Fantastico. Mi sono bruciato…\p"
	.string "Ti sei guadagnato il VULCANOBADGE!$"

SeafoamIslands_Gym_Text_ReceivedVolcanoBadge:
	.string "{PLAYER} riceve il VULCANOBADGE.$"

SeafoamIslands_Gym_Text_BlaineAfterBattle:
	.string "BLAINE: Questa volta ho perso, ma\n"
	.string "la prossima vincerò.\p"
	.string "Quando ricostruirò la mia PALESTRA\n"
	.string "di ISOLA CANNELLA, ci rivedremo.$"

SeafoamIslands_Gym_Text_BlaineFightDone:
	.string "BLAINE: I miei POKéMON di fuoco\n"
	.string "saranno ancora più forti.\p"
	.string "Vedrai!$"

SeafoamIslands_Gym_Text_BlaineRematch:
	.string "BLAINE: Uao!\p"
	.string "Vedo che sei diventato CAMPIONE\n"
	.string "di KANTO!\p"
	.string "Che fuoco!\p"
	.string "Le tue doti sono eccellenti.\p"
	.string "Non rifiuto mai una sfida.\p"
	.string "Vuoi una rivincita con me?$"

SeafoamIslands_Gym_Text_BlaineRematchDefeat:
	.string "BLAINE: Le tue abilità sono di fuoco!\p"
	.string "Hai bruciato tutte le mie\n"
	.string "difese.$"

SeafoamIslands_Gym_Text_GymGuideWin:
	.string "Ehi!\p"
	.string "… Come? È già finita?\p"
	.string "Scusa, scusa!\p"
	.string "La PALESTRA di ISOLA CANNELLA non\n"
	.string "c'era più, non sapevo dove fossi.\p"
	.string "Ma sei forte anche senza i miei\n"
	.string "consigli. Sapevo che avresti vinto!$"

SeafoamIslands_Gym_Text_GymGuideWin2:
	.string "Una PALESTRA POKéMON può stare\n"
	.string "ovunque, se c'è il CAPO PALESTRA.\p"
	.string "Non serve un edificio.$"
