ViridianCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_OnTransition
	.byte 0

ViridianCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_VIRIDIAN_CITY
	call_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 0, ViridianCity_EventScript_SetOldManBlockingRoad
	call_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1, ViridianCity_EventScript_SetOldManStandingByRoad
	call_if_ge VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2, ViridianCity_EventScript_SetOldManNormal
	call_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_GYM_DOOR, 0, ViridianCity_EventScript_TryUnlockGym
	end

ViridianCity_EventScript_SetOldManNormal::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OLD_MAN_1
	return

ViridianCity_EventScript_SetOldManStandingByRoad::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OLD_MAN_1
	setobjectxyperm LOCALID_TUTORIAL_MAN, 21, 8
	setobjectmovementtype LOCALID_TUTORIAL_MAN, MOVEMENT_TYPE_LOOK_AROUND
	return

ViridianCity_EventScript_SetOldManBlockingRoad::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OLD_MAN_LYING_DOWN
	setobjectxyperm LOCALID_TUTORIAL_MAN, 21, 11
	setobjectmovementtype LOCALID_TUTORIAL_MAN, MOVEMENT_TYPE_FACE_DOWN
	return

ViridianCity_EventScript_TryUnlockGym::
	goto_if_unset FLAG_BADGE02_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_BADGE03_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_BADGE04_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_BADGE05_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_BADGE06_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_BADGE07_GET, Common_EventScript_NopReturn
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_GYM_DOOR, 1
	return

ViridianCity_EventScript_GymDoorLocked::
	lockall
	textcolor NPC_TEXT_COLOR_NEUTRAL
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	msgbox ViridianCity_Text_GymDoorsAreLocked
	closemessage
	applymovement LOCALID_PLAYER, ViridianCity_Movement_JumpDownLedge
	waitmovement 0
	releaseall
	end

ViridianCity_Movement_JumpDownLedge::
	jump_2_down
	step_end

ViridianCity_EventScript_CitySign::
	msgbox ViridianCity_Text_CitySign, MSGBOX_SIGN
	end

ViridianCity_EventScript_TrainerTips1::
	msgbox ViridianCity_Text_CatchMonsForEasierBattles, MSGBOX_SIGN
	end

ViridianCity_EventScript_TrainerTips2::
	msgbox ViridianCity_Text_MovesLimitedByPP, MSGBOX_SIGN
	end

ViridianCity_EventScript_GymSign::
	msgbox ViridianCity_Text_GymSign, MSGBOX_SIGN
	end

ViridianCity_EventScript_GymDoor::
	msgbox ViridianCity_Text_GymDoorsAreLocked, MSGBOX_SIGN
	end

ViridianCity_EventScript_Boy::
	msgbox ViridianCity_Text_CanCarryMonsAnywhere, MSGBOX_NPC
	end

@ Other old man, not the tutorial old man
ViridianCity_EventScript_OldMan::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_GYM_DOOR, 1, ViridianCity_EventScript_OldManGymLeaderReturned
	msgbox ViridianCity_Text_GymClosedWonderWhoLeaderIs
	closemessage
	applymovement LOCALID_VIRIDIAN_OLD_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

ViridianCity_EventScript_OldManGymLeaderReturned::
	msgbox ViridianCity_Text_ViridiansGymLeaderReturned
	release
	end

ViridianCity_EventScript_TutorialOldMan::
	lock
	faceplayer
	goto_if_set FLAG_BADGE01_GET, ViridianCity_EventScript_AskIfTeachyTVHelpful
	goto_if_ge VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2, ViridianCity_EventScript_TutorialCompleted
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1, ViridianCity_EventScript_TutorialStart
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 0, ViridianCity_EventScript_TutorialNotReady
	end

ViridianCity_EventScript_AskIfTeachyTVHelpful::
	msgbox ViridianCity_Text_HowsTeachyTVHelping, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_EventScript_TeachyTVNotHelpful
	msgbox ViridianCity_Text_MyGrandsonOnTheShow
	release
	end

ViridianCity_EventScript_TeachyTVNotHelpful::
	msgbox ViridianCity_Text_TooBusyForTeachyTV
	release
	end

ViridianCity_EventScript_TutorialCompleted::
	msgbox ViridianCity_Text_WeakenMonsFirstToCatch
	release
	end

ViridianCity_EventScript_TutorialStart::
	call ViridianCity_EventScript_DoTutorialBattle
	release
	end

@ Unused
ViridianCity_EventScript_WatchToLearnBasics::
	msgbox ViridianCity_Text_WatchThatToLearnBasics
	release
	end

@ Unused. Starts battle after the post battle text, which is odd.
ViridianCity_EventScript_TutorialUnused::
	msgbox ViridianCity_Text_ThatWasEducationalTakeThis
	special StartOldManTutorialBattle
	waitstate
	release
	end

ViridianCity_EventScript_TutorialNotReady::
	msgbox ViridianCity_Text_ThisIsPrivateProperty
	closemessage
	release
	end

ViridianCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox ViridianCity_Text_WantToKnowAboutCaterpillarMons, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, ViridianCity_EventScript_YoungsterExplainCaterpillars
	goto_if_eq VAR_RESULT, NO, ViridianCity_EventScript_YoungsterDeclineExplanation
	end

ViridianCity_EventScript_YoungsterExplainCaterpillars::
	msgbox ViridianCity_Text_ExplainCaterpieWeedle
	release
	end

ViridianCity_EventScript_YoungsterDeclineExplanation::
	msgbox ViridianCity_Text_OhOkayThen
	release
	end

ViridianCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 0, ViridianCity_EventScript_WomanRoadBlocked
	msgbox ViridianCity_Text_GoShoppingInPewterOccasionally
	release
	end

ViridianCity_EventScript_WomanRoadBlocked::
	msgbox ViridianCity_Text_GrandpaHasntHadCoffeeYet
	closemessage
	applymovement LOCALID_VIRIDIAN_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

ViridianCity_EventScript_DreamEaterTutor::
	goto EventScript_DreamEaterTutor
	end

ViridianCity_EventScript_RoadBlocked::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	msgbox ViridianCity_Text_ThisIsPrivateProperty
	closemessage
	applymovement LOCALID_PLAYER, ViridianCity_Movement_WalkDown
	waitmovement 0
	releaseall
	end

ViridianCity_Movement_WalkDown::
	walk_down
	step_end

ViridianCity_EventScript_TutorialTriggerLeft::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_TUTORIAL_MAN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	call ViridianCity_EventScript_DoTutorialBattle
	release
	end

ViridianCity_EventScript_TutorialTriggerRight::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_TUTORIAL_MAN, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	call ViridianCity_EventScript_DoTutorialBattle
	release
	end

ViridianCity_EventScript_DoTutorialBattle::
	msgbox ViridianCity_Text_ShowYouHowToCatchMons
	closemessage
	special StartOldManTutorialBattle
	waitstate
	lock
	faceplayer
	msgbox ViridianCity_Text_ThatWasEducationalTakeThis
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2
	giveitem ITEM_TEACHY_TV
	msgbox ViridianCity_Text_WatchThatToLearnBasics
	return

ViridianCity_Text_CanCarryMonsAnywhere::
	.string "Quelle POKé BALL alla cintura!\n"
	.string "Hai dei POKéMON, vero?\p"
	.string "È fantastico poter portare e\n"
	.string "usare i POKéMON sempre, ovunque.$"

ViridianCity_Text_GymClosedWonderWhoLeaderIs::
	.string "Questa POKéMON GYM è sempre chiusa.\p"
	.string "Chissà chi è il LEADER?$"

ViridianCity_Text_ViridiansGymLeaderReturned::
	.string "Il CAPOPALESTRA di SMERALDOPOLI\nè tornato!$"

ViridianCity_Text_WantToKnowAboutCaterpillarMons::
	.string "Vuoi sapere dei due\n"
	.string "tipi di POKéMON bruco?$"

ViridianCity_Text_OhOkayThen::
	.string "Oh, va bene allora!$"

ViridianCity_Text_ExplainCaterpieWeedle::
	.string "CATERPIE non ha veleno,\n"
	.string "ma WEEDLE sì.\p"
	.string "Fa' che i tuoi POKéMON non\n"
	.string "siano colpiti dal VELENOSPINA.$"

ViridianCity_Text_GrandpaHasntHadCoffeeYet::
	.string "Oh, nonno!\n"
	.string "Non fare il cattivo!\p"
	.string "Mi dispiace tanto.\n"
	.string "Non ha ancora preso il caffè.$"

ViridianCity_Text_GoShoppingInPewterOccasionally::
	.string "A volte vado a fare shopping a\n"
	.string "PLUMBEOPOLI.\p"
	.string "Per andarci devo prendere il\n"
	.string "sentiero tortuoso della FORESTA.$"

ViridianCity_Text_ThisIsPrivateProperty::
	.string "Ti proibisco assolutamente di\n"
	.string "passare di qui!\p"
	.string "È proprietà privata!$"

ViridianCity_Text_ShowYouHowToCatchMons::
	.string "Bene, ho preso il caffè, e\n"
	.string "mi ci voleva per mettermi in moto!\p"
	.string "Hm?\n"
	.string "Cos'è quella scatola rossa?\p"
	.string "Ah, stai lavorando al tuo\n"
	.string "POKéDEX.\p"
	.string "Allora lascia che ti dia un\n"
	.string "consiglio.\p"
	.string "Ogni volta che catturi un POKéMON,\n"
	.string "il POKéDEX aggiorna\l"
	.string "i suoi dati.\p"
	.string "…Non sai come catturare\n"
	.string "un POKéMON?\p"
	.string "Allora sarà meglio che\n"
	.string "te lo mostri!$"

ViridianCity_Text_ThatWasEducationalTakeThis::
	.string "Ecco! Ora dimmi, è stato\n"
	.string "istruttivo, no?\p"
	.string "E tieni, prendi anche questo.$"

ViridianCity_Text_WatchThatToLearnBasics::
	.string "Se c'è qualcosa che non\n"
	.string "capisci, guarda quello.\p"
	.string "Ti insegnerà le basi\n"
	.string "per essere un ALLENATORE POKéMON.$"

ViridianCity_Text_WeakenMonsFirstToCatch::
	.string "Bene, ho preso il caffè, e\n"
	.string "mi ci voleva per mettermi in moto!\p"
	.string "Ma l'ho fatto troppo forte.\n"
	.string "Mi ha fatto venire il mal di testa…\p"
	.string "A proposito, stai riempiendo il\n"
	.string "POKéDEX?\p"
	.string "All'inizio, indebolisci il\n"
	.string "POKéMON prima di catturarlo.$"

ViridianCity_Text_HowsTeachyTVHelping::
	.string "Bene, ho preso il caffè, e\n"
	.string "mi ci voleva per mettermi in moto!\p"
	.string "Ma l'ho fatto troppo forte.\n"
	.string "Mi ha fatto venire il mal di testa…\p"
	.string "A proposito, il mio vecchio TEACHY TV\n"
	.string "ti sta aiutando?$"

ViridianCity_Text_MyGrandsonOnTheShow::
	.string "Wahaha!\n"
	.string "Mio nipote è in TV!\p"
	.string "Dato che insegna lui,\n"
	.string "imparerai di sicuro.$"

ViridianCity_Text_TooBusyForTeachyTV::
	.string "Hm… Sei troppo occupato per\n"
	.string "trovare il tempo per il TEACHY TV…\p"
	.string "Il tempo è denaro, e nessuno dei due\n"
	.string "va sprecato…$"

ViridianCity_Text_CitySign::
	.string "SMERALDOPOLI \n"
	.string "Il Paradiso Eternamente Verde$"

ViridianCity_Text_CatchMonsForEasierBattles::
	.string "CONSIGLI PER GLI ALLENATORI\p"
	.string "Cattura POKéMON e amplia la tua\n"
	.string "collezione.\p"
	.string "Più ne hai, più facile\n"
	.string "è lottare.$"

ViridianCity_Text_MovesLimitedByPP::
	.string "CONSIGLI PER GLI ALLENATORI\p"
	.string "Le mosse dei POKéMON sono\n"
	.string "limitate dai PUNTI POTERE, PP.\p"
	.string "Per ripristinare i PP, riposa i\n"
	.string "POKéMON stanchi in un CENTRO POKéMON.$"

ViridianCity_Text_GymSign::
	.string "PALESTRA POKéMON DI SMERALDOPOLI$"

ViridianCity_Text_GymDoorsAreLocked::
	.string "Le porte della PALESTRA\ndi SMERALDOPOLI sono chiuse…$"

