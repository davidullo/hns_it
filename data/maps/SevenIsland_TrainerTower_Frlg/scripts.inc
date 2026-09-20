SevenIsland_TrainerTower_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_TrainerTower_OnTransition
	.byte 0

SevenIsland_TrainerTower_OnTransition::
	setvar VAR_MAP_SCENE_TRAINER_TOWER, 0
	end

SevenIsland_TrainerTower_EventScript_TrainerTowerSign::
	msgbox SevenIsland_TrainerTower_Text_TrainerTowerSign, MSGBOX_SIGN
	end

SevenIsland_TrainerTower_EventScript_TrainerTowerAheadSign::
	msgbox SevenIsland_TrainerTower_Text_TrainerTowerAhead, MSGBOX_SIGN
	end

SevenIsland_TrainerTower_Text_DarioIntro::
	.string "Ho percepito il tuo arrivo.$"

SevenIsland_TrainerTower_Text_DarioDefeat::
	.string "Mi arrendo…$"

SevenIsland_TrainerTower_Text_DarioPostBattle::
	.string "Nel tuo futuro vedo che\n"
	.string "incontrerai molti altri.\p"
	.string "Credo che sarete legati l'uno\n"
	.string "all'altro da uno strano potere.$"

SevenIsland_TrainerTower_Text_RodetteIntro::
	.string "Da qualche parte su quest'isola\n"
	.string "dormono POKéMON singolari.$"

SevenIsland_TrainerTower_Text_RodetteDefeat::
	.string "Che ALLENATORE fantastico!$"

SevenIsland_TrainerTower_Text_RodettePostBattle::
	.string "Da qualche parte su quest'isola\n"
	.string "dormono POKéMON singolari.\p"
	.string "Che stiano aspettando\n"
	.string "proprio te?$"

SevenIsland_TrainerTower_Text_TrainerTowerSign::
	.string "INGRESSO TORRE ALLENATORI\n"
	.string "Raccogli la sfida, ALLENATORI!$"

SevenIsland_TrainerTower_Text_TrainerTowerAhead::
	.string "TORRE ALLENATORI PIÙ AVANTI$"

