Route24_Frlg_MapScripts::
	.byte 0

Route24_EventScript_Rocket::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_ROUTE24, 1, Route24_EventScript_RocketPostBattle
	msgbox Route24_Text_JustEarnedFabulousPrize
	checkitemspace ITEM_NUGGET
	goto_if_eq VAR_RESULT, FALSE, Route24_EventScript_NoRoomForNugget
	call Route24_EventScript_BattleRocket
	release
	end

Route24_EventScript_NoRoomForNugget::
	msgbox Route24_Text_YouDontHaveAnyRoom
	release
	end

Route24_EventScript_RocketPostBattle::
	msgbox Route24_Text_YoudBecomeTopRocketLeader
	release
	end

Route24_EventScript_RocketTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto Route24_EventScript_RocketTrigger
	end

Route24_EventScript_RocketTriggerRight::
	lockall
	setvar VAR_TEMP_1, 1
	goto Route24_EventScript_RocketTrigger
	end

Route24_EventScript_RocketTrigger::
	textcolor NPC_TEXT_COLOR_MALE
	call_if_eq VAR_TEMP_1, 0, Route24_EventScript_RocketApproachPlayer
	call_if_eq VAR_TEMP_1, 1, Route24_EventScript_RocketMotionToPlayer
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox Route24_Text_JustEarnedFabulousPrize
	checkitemspace ITEM_NUGGET
	goto_if_eq VAR_RESULT, FALSE, Route24_EventScript_NoRoomForNuggetTrigger
	call Route24_EventScript_BattleRocket
	releaseall
	end

Route24_EventScript_BattleRocket::
	giveitem_msg Route24_Text_ReceivedNuggetFromMysteryTrainer, ITEM_NUGGET
	message Route24_Text_JoinTeamRocket
	waitmessage
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	waitbuttonpress
	setvar VAR_LAST_TALKED, LOCALID_ROUTE24_ROCKET
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_6, Route24_Text_RocketDefeat
	msgbox Route24_Text_YoudBecomeTopRocketLeader
	setvar VAR_MAP_SCENE_ROUTE24, 1
	return

Route24_EventScript_RocketApproachPlayer::
	applymovement LOCALID_ROUTE24_ROCKET, Route24_Movement_RocketApproachPlayer
	waitmovement 0
	return

Route24_EventScript_RocketMotionToPlayer::
	applymovement LOCALID_ROUTE24_ROCKET, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

Route24_EventScript_NoRoomForNuggetTrigger::
	msgbox Route24_Text_YouDontHaveAnyRoom
	closemessage
	applymovement LOCALID_PLAYER, Route24_Movement_WalkDown
	waitmovement 0
	call_if_eq VAR_TEMP_1, 0, Route24_EventScript_RocketWalkBackToPos
	release
	end

Route24_EventScript_RocketWalkBackToPos::
	applymovement LOCALID_ROUTE24_ROCKET, Route24_Movement_RocketWalkBackToPos
	waitmovement 0
	return

Route24_Movement_RocketApproachPlayer::
	walk_left
	step_end

Route24_Movement_RocketWalkBackToPos::
	walk_right
	walk_in_place_faster_left
	step_end

Route24_Movement_WalkDown::
	walk_down
	step_end

Route24_Text_JustEarnedFabulousPrize::
	.string "Congratulazioni! Hai battuto i nostri\n"
	.string "cinque ALLENATORI del torneo!\p"
	.string "Hai appena vinto un premio favoloso!$"

Route24_Text_ReceivedNuggetFromMysteryTrainer::
	.string "{PLAYER} riceve una PEPITA\n"
	.string "dal misterioso ALLENATORE!$"

Route24_Text_YouDontHaveAnyRoom::
	.string "Non hai spazio!$"

Route24_Text_JoinTeamRocket::
	.string "A proposito, ti va di entrare\n"
	.string "nel TEAM ROCKET?\p"
	.string "Siamo un gruppo di criminali\n"
	.string "professionisti specializzati in POKéMON!\p"
	.string "Vuoi entrare?\p"
	.string "Sei sicuro?\p"
	.string "Dai, unisciti a noi!\p"
	.string "Ti sto dicendo di entrare!\p"
	.string "…Okay, ti serve un incentivo!\p"
	.string "Ti farò un'offerta che non puoi\n"
	.string "rifiutare!$"

Route24_Text_RocketDefeat::
	.string "Arrgh!\n"
	.string "Sei forte!$"

Route24_Text_YoudBecomeTopRocketLeader::
	.string "Con il tuo talento diventeresti\n"
	.string "un capo del TEAM ROCKET.\p"
	.string "Dai, pensa all'occasione!\n"
	.string "Non sprecare questa chance.$"

Route24_Text_ShaneIntro::
	.string "Ho visto la tua impresa dall'erba!$"

Route24_Text_ShaneDefeat::
	.string "Lo immaginavo!$"

Route24_Text_ShanePostBattle::
	.string "Mi sono nascosto perché la gente sul\n"
	.string "ponte mi spaventava.$"

Route24_Text_EthanIntro::
	.string "Okay! Sono il n. 5!\n"
	.string "Ti pesto per bene!$"

Route24_Text_EthanDefeat::
	.string "Whoa!\n"
	.string "Troppo forte!$"

Route24_Text_EthanPostBattle::
	.string "Ho dato il massimo. Non rimpiango nulla!$"

Route24_Text_ReliIntro::
	.string "Sono la n. 4!\n"
	.string "Ti stanchi?$"

Route24_Text_ReliDefeat::
	.string "Ho perso anche io!$"

Route24_Text_ReliPostBattle::
	.string "Ho dato il massimo, non rimpiango nulla!$"

Route24_Text_TimmyIntro::
	.string "Ecco il n. 3!\n"
	.string "Non sarò facile!$"

Route24_Text_TimmyDefeat::
	.string "Ow!\n"
	.string "Pestato a terra!$"

Route24_Text_TimmyPostBattle::
	.string "Ho dato il massimo. Non rimpiango nulla!$"

Route24_Text_AliIntro::
	.string "Sono il secondo!\n"
	.string "Ora si fa sul serio!$"

Route24_Text_AliDefeat::
	.string "Come ho potuto perdere?$"

Route24_Text_AliPostBattle::
	.string "Ho dato il massimo. Non rimpiango nulla!$"

Route24_Text_CaleIntro::
	.string "La chiamano tutti il PONTE\n"
	.string "PEPITA!\p"
	.string "Batti noi cinque ALLENATORI e\n"
	.string "vinci un fantastico premio!\p"
	.string "Pensi di farcela?$"

Route24_Text_CaleDefeat::
	.string "Wow!\n"
	.string "Niente male!$"

Route24_Text_CalePostBattle::
	.string "Ho dato il massimo. Non rimpiango nulla!$"
