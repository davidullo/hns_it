.equ PLAYER_X_POS, VAR_0x8004
.equ PLAYER_Y_POS, VAR_0x8005

FiveIsland_RocketWarehouse_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, FiveIsland_RocketWarehouse_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, FiveIsland_RocketWarehouse_OnTransition
	.byte 0

FiveIsland_RocketWarehouse_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_FIVE_ISLAND_ROCKET_WAREHOUSE
	end

FiveIsland_RocketWarehouse_OnLoad::
	call_if_defeated TRAINER_TEAM_ROCKET_ADMIN, FiveIsland_RocketWarehouse_EventScript_SetArrowsForReEntry
	end

FiveIsland_RocketWarehouse_EventScript_SetArrowsForReEntry::
	setmetatile 26, 20, METATILE_SilphCo_Arrow_Up, 0
	setmetatile 27, 20, METATILE_SilphCo_Arrow_Up, 0
	return

FiveIsland_RocketWarehouse_EventScript_Cage::
	lockall
	goto_if_set FLAG_DEFEATED_ROCKETS_IN_WAREHOUSE, FiveIsland_RocketWarehouse_EventScript_CageUnlocked
	msgbox FiveIsland_RocketWarehouse_Text_ManyMonsLockedInPen
	releaseall
	end

FiveIsland_RocketWarehouse_EventScript_CageUnlocked::
	msgbox FiveIsland_RocketWarehouse_Text_PenUnlockedMonsFled
	releaseall
	end

FiveIsland_RocketWarehouse_EventScript_Computer::
	msgbox FiveIsland_RocketWarehouse_Text_ReportWithGraphsAndText, MSGBOX_SIGN
	end

FiveIsland_RocketWarehouse_EventScript_Admin2Trigger::
	lockall
	applymovement LOCALID_WAREHOUSE_ADMIN2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	setvar VAR_MAP_SCENE_ROCKET_WAREHOUSE, 1
	releaseall
	end

FiveIsland_RocketWarehouse_EventScript_Gideon::
	trainerbattle_single TRAINER_SCIENTIST_GIDEON, FiveIsland_RocketWarehouse_Text_GideonIntro, FiveIsland_RocketWarehouse_Text_GideonDefeat, FiveIsland_RocketWarehouse_EventScript_DefeatedGideon
	goto_if_set FLAG_IS_CHAMPION, FiveIsland_RocketWarehouse_EventScript_MentionGiovannisKid
	msgbox FiveIsland_RocketWarehouse_Text_GetLostLeaveMeBe, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_MentionGiovannisKid::
	famechecker FAMECHECKER_GIOVANNI, 5
	msgbox FiveIsland_RocketWarehouse_Text_GiovannisKidHasRedHair, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_DefeatedGideon::
	msgbox FiveIsland_RocketWarehouse_Text_GideonPostBattle
	setflag FLAG_RECOVERED_SAPPHIRE
	giveitem ITEM_SAPPHIRE
	release
	end

FiveIsland_RocketWarehouse_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_47, FiveIsland_RocketWarehouse_Text_Grunt2Intro, FiveIsland_RocketWarehouse_Text_Grunt2Defeat
	msgbox FiveIsland_RocketWarehouse_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_48, FiveIsland_RocketWarehouse_Text_Grunt3Intro, FiveIsland_RocketWarehouse_Text_Grunt3Defeat
	msgbox FiveIsland_RocketWarehouse_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_Admin2::
	trainerbattle_single TRAINER_TEAM_ROCKET_ADMIN_2, FiveIsland_RocketWarehouse_Text_Admin2Intro, FiveIsland_RocketWarehouse_Text_Admin2Defeat, FiveIsland_RocketWarehouse_EventScript_DefeatedAdmin2
	msgbox FiveIsland_RocketWarehouse_Text_Admin2PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_DefeatedAdmin2::
	getplayerxy PLAYER_X_POS, PLAYER_Y_POS
	call_if_le PLAYER_X_POS, 24, FiveIsland_RocketWarehouse_EventScript_PlayerFaceAdmin2
	msgbox FiveIsland_RocketWarehouse_Text_Admin2PostBattle
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_WAREHOUSE_GRUNT2
	removeobject LOCALID_WAREHOUSE_GRUNT3
	removeobject LOCALID_WAREHOUSE_ADMIN2
	removeobject LOCALID_WAREHOUSE_ADMIN1
	setflag FLAG_HIDE_FIVE_ISLAND_ROCKETS
	fadescreen FADE_FROM_BLACK
	setvar VAR_MAP_SCENE_ROCKET_WAREHOUSE, 1
	setflag FLAG_DEFEATED_ROCKETS_IN_WAREHOUSE
	release
	end

FiveIsland_RocketWarehouse_EventScript_PlayerFaceAdmin2::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_42, FiveIsland_RocketWarehouse_Text_Grunt1Intro, FiveIsland_RocketWarehouse_Text_Grunt1Defeat
	msgbox FiveIsland_RocketWarehouse_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_Admin1::
	trainerbattle_single TRAINER_TEAM_ROCKET_ADMIN, FiveIsland_RocketWarehouse_Text_Admin1Intro, FiveIsland_RocketWarehouse_Text_Admin1Defeat, FiveIsland_RocketWarehouse_EventScript_DefeatedAdmin1
	msgbox FiveIsland_RocketWarehouse_Text_MadeItSoYouCanComeBackThrough, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_DefeatedAdmin1::
	getplayerxy PLAYER_X_POS, PLAYER_Y_POS
	specialvar VAR_RESULT, GetPlayerFacingDirection
	call_if_eq VAR_RESULT, DIR_NORTH, FiveIsland_RocketWarehouse_EventScript_PlayerFaceAdmin1
	msgbox FiveIsland_RocketWarehouse_Text_Admin1PostBattle
	closemessage
	call_if_le PLAYER_X_POS, 24, FiveIsland_RocketWarehouse_EventScript_AdminWalkToSwitchFar
	call_if_eq PLAYER_X_POS, 25, FiveIsland_RocketWarehouse_EventScript_AdminWalkToSwitch
	call_if_eq PLAYER_X_POS, 26, FiveIsland_RocketWarehouse_EventScript_AdminFaceSwitch
	call_if_eq PLAYER_X_POS, 27, FiveIsland_RocketWarehouse_EventScript_AdminFaceSwitch
	playse SE_PIN
	call FiveIsland_RocketWarehouse_EventScript_SetArrowsForReEntry
	special DrawWholeMapView
	waitse
	call_if_le PLAYER_X_POS, 24, FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerLeft
	call_if_eq PLAYER_X_POS, 25, FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerLeft
	call_if_eq PLAYER_X_POS, 26, FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerLeft
	call_if_eq PLAYER_X_POS, 27, FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerDown
	msgbox FiveIsland_RocketWarehouse_Text_MadeItSoYouCanComeBackThrough
	release
	end

FiveIsland_RocketWarehouse_EventScript_PlayerFaceAdmin1::
	goto_if_eq PLAYER_X_POS, 27, Common_EventScript_NopReturn
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_AdminWalkToSwitchFar::
	applymovement LOCALID_WAREHOUSE_ADMIN1, FiveIsland_RocketWarehouse_Movement_AdminWalkToSwitchFar
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_AdminWalkToSwitch::
	applymovement LOCALID_WAREHOUSE_ADMIN1, FiveIsland_RocketWarehouse_Movement_AdminWalkToSwitch
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_AdminFaceSwitch::
	applymovement LOCALID_WAREHOUSE_ADMIN1, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerLeft::
	applymovement LOCALID_WAREHOUSE_ADMIN1, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerDown::
	applymovement LOCALID_WAREHOUSE_ADMIN1, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

FiveIsland_RocketWarehouse_Movement_AdminWalkToSwitchFar::
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

FiveIsland_RocketWarehouse_Movement_AdminWalkToSwitch::
	walk_right
	walk_in_place_faster_up
	step_end

FiveIsland_RocketWarehouse_Text_ManyMonsLockedInPen::
	.string "Ci sono molti POKéMON chiusi\n"
	.string "nel recinto…$"

FiveIsland_RocketWarehouse_Text_PenUnlockedMonsFled::
	.string "Il recinto è aperto.\n"
	.string "I POKéMON sembrano fuggiti.$"

FiveIsland_RocketWarehouse_Text_Grunt2Intro::
	.string "Sapevi che è il MAGAZZINO\n"
	.string "del TEAM ROCKET?$"

FiveIsland_RocketWarehouse_Text_Grunt2Defeat::
	.string "Cosa credi di fare?!$"

FiveIsland_RocketWarehouse_Text_Grunt2PostBattle::
	.string "Il TEAM ROCKET finito?\n"
	.string "Da che pianeta vieni?$"

FiveIsland_RocketWarehouse_Text_Grunt1Intro::
	.string "Oh, i tuoi POKéMON son forti.\n"
	.string "Vuoi venderli?\p"
	.string "Oh?\n"
	.string "Volevi lottare?$"

FiveIsland_RocketWarehouse_Text_Grunt1Defeat::
	.string "Oh, ma…\n"
	.string "Troppo!$"

FiveIsland_RocketWarehouse_Text_Grunt1PostBattle::
	.string "Ti diamo un ottimo prezzo.\n"
	.string "Vendici i POKéMON!$"

FiveIsland_RocketWarehouse_Text_Grunt3Intro::
	.string "Ho saputo di te dagli\n"
	.string "altri.\p"
	.string "Ma un ragazzino non può conoscere\n"
	.string "il nostro CAPO GIOVANNI!$"

FiveIsland_RocketWarehouse_Text_Grunt3Defeat::
	.string "Non…osare…ridere…$"

FiveIsland_RocketWarehouse_Text_Grunt3PostBattle::
	.string "Non t'impicciare degli affari\n"
	.string "dei grandi, saputello!$"

FiveIsland_RocketWarehouse_Text_Admin1Intro::
	.string "Non so se quel che faccio\n"
	.string "è giusto o sbagliato…\p"
	.string "Mi fido di GIOVANNI\n"
	.string "e obbedisco.$"

FiveIsland_RocketWarehouse_Text_Admin1Defeat::
	.string "Io…\n"
	.string "Sono a pezzi…$"

FiveIsland_RocketWarehouse_Text_Admin1PostBattle::
	.string "Agisci secondo le tue\n"
	.string "convinzioni e valori.\p"
	.string "Ora capisco…$"

FiveIsland_RocketWarehouse_Text_MadeItSoYouCanComeBackThrough::
	.string "Ho fatto in modo che tu possa\n"
	.string "rientrare da lì.\p"
	.string "Perché non ti riposi e ti\n"
	.string "ricarichi per quel che verrà?\p"
	.string "L'TENENTE dopo di me è più\n"
	.string "forte come ALLENATORE.\p"
	.string "Faresti meglio a prepararti per\n"
	.string "una dura sfida.$"

FiveIsland_RocketWarehouse_Text_Admin2Intro::
	.string "Ora basta, smettila di\n"
	.string "fare l'eroe, ragazzo.\p"
	.string "Dici in giro che il TEAM\n"
	.string "ROCKET si è sciolto…\p"
	.string "È un tentativo palese di\n"
	.string "creare confusione nei ranghi.\p"
	.string "Fortuna che non siamo così\n"
	.string "sciocchi da credere a un bimbo!\p"
	.string "E ora vedrai quanto è\n"
	.string "spaventoso un adulto!$"

FiveIsland_RocketWarehouse_Text_Admin2Defeat::
	.string "Ugh…\n"
	.string "Sei troppo forte…\p"
	.string "…\n"
	.string "È la MEDAGLIA di GIOVANNI!\p"
	.string "È tutto vero?\n"
	.string "Il TEAM ROCKET si è sciolto?$"

FiveIsland_RocketWarehouse_Text_Admin2PostBattle::
	.string "Lasciamo questo MAGAZZINO…\p"
	.string "Ma non è finita qui.\n"
	.string "Non sarà la fine.\p"
	.string "Troverò GIOVANNI.\n"
	.string "E risorgerà il TEAM ROCKET!\l"
	.string "Io…\p"
	.string "Addio, a presto!$"

FiveIsland_RocketWarehouse_Text_ReportWithGraphsAndText::
	.string "Un rapporto con grafici e testo è\n"
	.string "sul monitor.\p"
	.string "“Effetto onde magnetiche su\n"
	.string "Evoluzione POKéMON”…\p"
	.string "… … … … … …\p"
	.string "È troppo difficile da capire…$"

FiveIsland_RocketWarehouse_Text_GideonIntro::
	.string "Stavo per vendere lo ZAFFIRO\n"
	.string "per un sacco di soldi…\p"
	.string "Poi sei arrivato tu a\n"
	.string "mandare tutto all'aria!\p"
	.string "Eh… Eh eh eh…\n"
	.string "Non c'è perdono per te!$"

FiveIsland_RocketWarehouse_Text_GideonDefeat::
	.string "Argh!\n"
	.string "Accidenti!$"

FiveIsland_RocketWarehouse_Text_GideonPostBattle::
	.string "Se non posso venderlo, è inutile!\n"
	.string "Prendilo, forza!$"

FiveIsland_RocketWarehouse_Text_GetLostLeaveMeBe::
	.string "Cosa vuoi adesso?\n"
	.string "Vai via, lasciami in pace.$"

FiveIsland_RocketWarehouse_Text_GiovannisKidHasRedHair::
	.string "Ancora tu?\p"
	.string "Non sei figlio di GIOVANNI,\n"
	.string "vero?\p"
	.string "No, impossibile!\n"
	.string "Il figlio ha capelli rossi.\p"
	.string "Non hai motivi per\n"
	.string "seccarmi. Lasciami stare!$"

