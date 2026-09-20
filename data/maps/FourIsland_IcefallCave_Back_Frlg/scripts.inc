FourIsland_IcefallCave_Back_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FourIsland_IcefallCave_Back_OnTransition
	.byte 0

FourIsland_IcefallCave_Back_OnTransition::
	call_if_eq VAR_MAP_SCENE_ICEFALL_CAVE_BACK, 1, FourIsland_IcefallCave_Back_EventScript_HideLorelei
	end

FourIsland_IcefallCave_Back_EventScript_HideLorelei::
	setflag FLAG_HIDE_ICEFALL_CAVE_LORELEI
	return

FourIsland_IcefallCave_Back_EventScript_LoreleiRocketsScene::
	lockall
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox FourIsland_IcefallCave_Back_Text_LoreleiKeepHandsOffMons
	applymovement LOCALID_ICEFALL_ROCKET1, FourIsland_IcefallCave_Back_Movement_WalkInPlaceDown
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox FourIsland_IcefallCave_Back_Text_ShutItLadyLeaveUsBe
	closemessage
	playse SE_PIN
	applymovement LOCALID_ICEFALL_LORELEI, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ICEFALL_LORELEI, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_ICEFALL_LORELEI, Common_Movement_Delay48
	waitmovement 0
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox FourIsland_IcefallCave_Back_Text_LoreleiPlayerHelpMeKickPoachersOut
	closemessage
	applymovement LOCALID_ICEFALL_LORELEI, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 18
	applymovement LOCALID_ICEFALL_LORELEI, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 35
	applymovement LOCALID_ICEFALL_ROCKET3, FourIsland_IcefallCave_Back_Movement_Rocket3FaceLorelei
	applymovement LOCALID_ICEFALL_LORELEI, FourIsland_IcefallCave_Back_Movement_LoreleiToRockets
	applymovement LOCALID_PLAYER, FourIsland_IcefallCave_Back_Movement_PlayerToRockets
	waitmovement 0
	applymovement LOCALID_ICEFALL_ROCKET2, FourIsland_IcefallCave_Back_Movement_WalkInPlaceDown
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox FourIsland_IcefallCave_Back_Text_GruntIntro
	setvar VAR_LAST_TALKED, LOCALID_ICEFALL_ROCKET3
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_45, FourIsland_IcefallCave_Back_Text_GruntDefeat
	applymovement LOCALID_ICEFALL_LORELEI, FourIsland_IcefallCave_Back_Movement_WalkInPlaceUp
	waitmovement 0
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox FourIsland_IcefallCave_Back_Text_LoreleiWhereHaveYouTakenMons
	textcolor NPC_TEXT_COLOR_MALE
	msgbox FourIsland_IcefallCave_Back_Text_NotTellingYouThat
	textcolor NPC_TEXT_COLOR_FEMALE
	message FourIsland_IcefallCave_Back_Text_LoreleiWellDeepFreezeYou
	waitmessage
	waitse
	playmoncry SPECIES_LAPRAS, CRY_MODE_ENCOUNTER
	waitbuttonpress
	waitmoncry
	applymovement LOCALID_ICEFALL_ROCKET1, FourIsland_IcefallCave_Back_Movement_Rocket1ReactToThreat
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox FourIsland_IcefallCave_Back_Text_OkayRocketWareHouseFiveIsland
	closemessage
	applymovement LOCALID_ICEFALL_LORELEI, FourIsland_IcefallCave_Back_Movement_LoreleiWatchRocketsExit
	applymovement LOCALID_PLAYER, FourIsland_IcefallCave_Back_Movement_PlayerWatchRocketsExit
	applymovement LOCALID_ICEFALL_ROCKET1, FourIsland_IcefallCave_Back_Movement_Rocket1Exit
	applymovement LOCALID_ICEFALL_ROCKET2, FourIsland_IcefallCave_Back_Movement_Rocket2Exit
	applymovement LOCALID_ICEFALL_ROCKET3, FourIsland_IcefallCave_Back_Movement_Rocket3Exit
	waitmovement 0
	removeobject LOCALID_ICEFALL_ROCKET1
	removeobject LOCALID_ICEFALL_ROCKET2
	removeobject LOCALID_ICEFALL_ROCKET3
	delay 50
	applymovement LOCALID_ICEFALL_LORELEI, FourIsland_IcefallCave_Back_Movement_LoreleiWalkToPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox FourIsland_IcefallCave_Back_Text_ThankYouThisIsAwful
	setflag FLAG_HIDE_RUIN_VALLEY_SCIENTIST
	clearflag FLAG_HIDE_LORELEI_IN_HER_HOUSE
	setvar VAR_MAP_SCENE_ICEFALL_CAVE_BACK, 1
	releaseall
	end

FourIsland_IcefallCave_Back_Movement_PlayerToRockets::
	walk_up
	walk_up
	walk_right
	walk_up
	step_end

FourIsland_IcefallCave_Back_Movement_PlayerWatchRocketsExit::
	delay_16
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

FourIsland_IcefallCave_Back_Movement_WalkInPlaceDown::
	walk_in_place_down
	step_end

FourIsland_IcefallCave_Back_Movement_UnusedPushRight::
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

FourIsland_IcefallCave_Back_Movement_Rocket1ReactToThreat::
	walk_in_place_fast_down
	step_end

FourIsland_IcefallCave_Back_Movement_Rocket1Exit::
	walk_right
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

FourIsland_IcefallCave_Back_Movement_Rocket2Exit::
	delay_16
	walk_left
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

FourIsland_IcefallCave_Back_Movement_Rocket3Exit::
	delay_16
	walk_down
	delay_16
	walk_down
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

FourIsland_IcefallCave_Back_Movement_Rocket3FaceLorelei::
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

FourIsland_IcefallCave_Back_Movement_UnusedWalkLeft::
	walk_left
	walk_left
	step_end

FourIsland_IcefallCave_Back_Movement_LoreleiToRockets::
	walk_left
	walk_up
	step_end

FourIsland_IcefallCave_Back_Movement_WalkInPlaceUp::
	walk_in_place_up
	step_end

FourIsland_IcefallCave_Back_Movement_LoreleiWatchRocketsExit::
	delay_8
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

FourIsland_IcefallCave_Back_Movement_LoreleiWalkToPlayer::
	walk_right
	step_end

FourIsland_IcefallCave_Back_EventScript_Lorelei::
	msgbox FourIsland_IcefallCave_Back_Text_ThankYouThisIsAwful, MSGBOX_NPC
	end

FourIsland_IcefallCave_Back_Text_LoreleiKeepHandsOffMons::
	.string "LORELEI: Giù le mani sporche\n"
	.string "dai POKéMON nella grotta!\p"
	.string "Ubbidisci o dovrai vedertela\n"
	.string "con me!$"

FourIsland_IcefallCave_Back_Text_ShutItLadyLeaveUsBe::
	.string "Zitta, signora, e lasciaci\n"
	.string "stare.\p"
	.string "Non far appannare gli\n"
	.string "occhiali!$"

FourIsland_IcefallCave_Back_Text_LoreleiPlayerHelpMeKickPoachersOut::
	.string "LORELEI: {PLAYER}?!\n"
	.string "Che ci fai qui?\p"
	.string "No, ne parliamo dopo.\n"
	.string "Ora mi serve il tuo aiuto.\p"
	.string "Scacciamo i bracconieri\n"
	.string "prima che facciano altro.\p"
	.string "Catturavano i POKéMON\n"
	.string "e poi li rivendevano!\p"
	.string "Pronti?\n"
	.string "Tu occupati di quello!$"

FourIsland_IcefallCave_Back_Text_GruntIntro::
	.string "C-cosa?!\p"
	.string "Chi dice che non posso fare quel\n"
	.string "che voglio coi POKéMON?$"

FourIsland_IcefallCave_Back_Text_GruntDefeat::
	.string "Non l'avevamo previsto!$"

FourIsland_IcefallCave_Back_Text_LoreleiWhereHaveYouTakenMons::
	.string "LORELEI: Bah.\n"
	.string "Deboli e patetici.\p"
	.string "Tu!\n"
	.string "Dimmi!\p"
	.string "Dove avete portato i\n"
	.string "POKéMON?\p"
	.string "Distruggerò la vostra banda\n"
	.string "e basta!$"

FourIsland_IcefallCave_Back_Text_NotTellingYouThat::
	.string "N-no!\n"
	.string "Non te lo dico!$"

FourIsland_IcefallCave_Back_Text_LoreleiWellDeepFreezeYou::
	.string "LORELEI: Se non confessi,\n"
	.string "ti congeleremo.\p"
	.string "LAPRAS è furioso per quello\n"
	.string "che hai fatto ai suoi amici!\p"
	.string "Vai, LAPRAS!\n"
	.string "GELORAGGIO…$"

FourIsland_IcefallCave_Back_Text_OkayRocketWareHouseFiveIsland::
	.string "Uaaah! Sì!\n"
	.string "Parlo!\p"
	.string "I POKéMON sono nel MAGAZZINO\n"
	.string "ROCKET, ISOLA CINQUE.\p"
	.string "Ecco! Detto!\n"
	.string "Noi ce ne andiamo!\p"
	.string "…Ma dubito che arriverete\n"
	.string "al MAGAZZINO ROCKET!\p"
	.string "Eh eh eh!$"

FourIsland_IcefallCave_Back_Text_ThankYouThisIsAwful::
	.string "{PLAYER}, grazie.\n"
	.string "Ma è terribile…\p"
	.string "Sono nata e cresciuta qui\n"
	.string "tra le isole.\p"
	.string "Non sapevo che quei loschi\n"
	.string "criminali fossero qui…$"

