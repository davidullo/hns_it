SilphCo_6F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_6F_OnLoad
	.byte 0

SilphCo_6F_OnLoad::
	call_if_unset FLAG_SILPH_6F_DOOR, EventScript_Close6FDoor
	end

SilphCo_6F_EventScript_WorkerM2::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_6F_EventScript_WorkerM2RocketsGone
	msgbox SilphCo_6F_Text_TargetedSilphForOurMonProducts
	release
	end

SilphCo_6F_EventScript_WorkerM2RocketsGone::
	msgbox SilphCo_6F_Text_ComeWorkForSilphWhenYoureOlder
	release
	end

SilphCo_6F_EventScript_WorkerM3::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_6F_EventScript_WorkerM3RocketsGone
	msgbox SilphCo_6F_Text_RocketsTookOverBuilding
	release
	end

SilphCo_6F_EventScript_WorkerM3RocketsGone::
	msgbox SilphCo_6F_Text_BetterGetBackToWork
	release
	end

SilphCo_6F_EventScript_WorkerM1::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_6F_EventScript_WorkerM1RocketsGone
	msgbox SilphCo_6F_Text_HelpMePlease
	release
	end

SilphCo_6F_EventScript_WorkerM1RocketsGone::
	msgbox SilphCo_6F_Text_WeGotEngaged
	release
	end

SilphCo_6F_EventScript_WorkerF1::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_6F_EventScript_WorkerF1RocketsGone
	msgbox SilphCo_6F_Text_ThatManIsSuchACoward
	release
	end

SilphCo_6F_EventScript_WorkerF1RocketsGone::
	msgbox SilphCo_6F_Text_NeedsMeToLookAfterHim
	release
	end

SilphCo_6F_EventScript_WorkerF2::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_6F_EventScript_WorkerF2RocketsGone
	msgbox SilphCo_6F_Text_RocketsTryingToConquerWorld
	release
	end

SilphCo_6F_EventScript_WorkerF2RocketsGone::
	msgbox SilphCo_6F_Text_RocketsRanAwayBecauseOfYou
	release
	end

SilphCo_6F_EventScript_FloorSign::
	msgbox SilphCo_6F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_6F_EventScript_Taylor::
	trainerbattle_single TRAINER_SCIENTIST_TAYLOR, SilphCo_6F_Text_TaylorIntro, SilphCo_6F_Text_TaylorDefeat
	msgbox SilphCo_6F_Text_TaylorPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_6F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_30, SilphCo_6F_Text_Grunt1Intro, SilphCo_6F_Text_Grunt1Defeat
	msgbox SilphCo_6F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_6F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_31, SilphCo_6F_Text_Grunt2Intro, SilphCo_6F_Text_Grunt2Defeat
	msgbox SilphCo_6F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_6F_Text_RocketsTookOverBuilding::
	.string "È arrivato il TEAM ROCKET e ha\n"
	.string "occupato l'edificio!$"

SilphCo_6F_Text_BetterGetBackToWork::
	.string "Beh, meglio tornare al lavoro.$"

SilphCo_6F_Text_HelpMePlease::
	.string "Oh, povero me.\n"
	.string "Aiutatemi, vi prego!$"

SilphCo_6F_Text_WeGotEngaged::
	.string "Ci siamo fidanzati.\n"
	.string "Eh eh!$"

SilphCo_6F_Text_ThatManIsSuchACoward::
	.string "Quell'uomo accanto a me…\n"
	.string "È un vero codardo!$"

SilphCo_6F_Text_NeedsMeToLookAfterHim::
	.string "È così indifeso che gli serve\n"
	.string "qualcuno come me che lo accudisca.$"

SilphCo_6F_Text_RocketsTryingToConquerWorld::
	.string "Il TEAM ROCKET vuole conquistare\n"
	.string "il mondo coi POKéMON.$"

SilphCo_6F_Text_RocketsRanAwayBecauseOfYou::
	.string "Il TEAM ROCKET è fuggito, e tutto\n"
	.string "merito tuo!$"

SilphCo_6F_Text_TargetedSilphForOurMonProducts::
	.string "Avranno preso di mira la SILPH per\n"
	.string "i nostri prodotti POKéMON.$"

SilphCo_6F_Text_ComeWorkForSilphWhenYoureOlder::
	.string "Vieni a lavorare per la SILPH quando\n"
	.string "sarai più grande.$"

SilphCo_6F_Text_Grunt1Intro::
	.string "Sono uno dei quattro FRATELLI\n"
	.string "ROCKET!$"

SilphCo_6F_Text_Grunt1Defeat::
	.string "Che fiammata!$"

SilphCo_6F_Text_Grunt1PostBattle::
	.string "Non importa!\n"
	.string "I miei fratelli mi vendicheranno!$"

SilphCo_6F_Text_TaylorIntro::
	.string "Che PRESIDENTE infame!\p"
	.string "Ben gli sta per avermi spedito\n"
	.string "alla FILIALE DI TIKSI!\p"
	.string "Ecco perché il TEAM ROCKET ci ha\n"
	.string "attaccato, ne sono certo!$"

SilphCo_6F_Text_TaylorDefeat::
	.string "Perbacco!$"

SilphCo_6F_Text_TaylorPostBattle::
	.string "FILIALE DI TIKSI?\n"
	.string "È in mezzo al nulla russo!$"

SilphCo_6F_Text_Grunt2Intro::
	.string "Osi tradire il TEAM ROCKET?$"

SilphCo_6F_Text_Grunt2Defeat::
	.string "Traditore!$"

SilphCo_6F_Text_Grunt2PostBattle::
	.string "Se stai dalla parte della giustizia,\n"
	.string "tradisci noi cattivi!$"

SilphCo_6F_Text_FloorSign::
	.string "SEDE SILPH CO.\n"
	.string "6F$"

