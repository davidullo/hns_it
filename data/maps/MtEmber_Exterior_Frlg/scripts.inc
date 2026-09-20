MtEmber_Exterior_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtEmber_Exterior_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, MtEmber_Exterior_OnLoad
	.byte 0

MtEmber_Exterior_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_MT_EMBER_EXTERIOR
	call_if_eq VAR_MAP_SCENE_MT_EMBER_EXTERIOR, 2, MtEmber_Exterior_EventScript_RocketsFaceDown
	end

MtEmber_Exterior_EventScript_RocketsFaceDown::
	setobjectmovementtype LOCALID_MT_EMBER_GRUNT1, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_MT_EMBER_GRUNT2, MOVEMENT_TYPE_FACE_DOWN
	return

MtEmber_Exterior_OnLoad::
	call_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 4, MtEmber_Exterior_EventScript_OpenCave
	end

MtEmber_Exterior_EventScript_OpenCave::
	setmetatile 42, 39, METATILE_MtEmber_CaveEntrance, 0
	return

MtEmber_Exterior_EventScript_Grunt1::
	lock
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_43, MtEmber_Exterior_EventScript_Grunt1Defeated
	goto_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 4, MtEmber_Exterior_EventScript_BattleGrunt1
	msgbox MtEmber_Exterior_Text_WellTryDiggingHere
	release
	end

MtEmber_Exterior_EventScript_Grunt1Defeated::
	msgbox MtEmber_Exterior_Text_Grunt1PostBattle
	release
	end

MtEmber_Exterior_EventScript_BattleGrunt1::
	applymovement LOCALID_MT_EMBER_GRUNT1, Common_Movement_FacePlayer
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	msgbox MtEmber_Exterior_Text_Grunt1Intro
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_43, MtEmber_Exterior_Text_Grunt1Defeat
	msgbox MtEmber_Exterior_Text_Grunt1PostBattle
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_44, MtEmber_Exterior_EventScript_DefeatedBothGrunts
	release
	end

MtEmber_Exterior_EventScript_DefeatedBothGrunts::
	msgbox MtEmber_Exterior_Text_WellRegroupDontStepInsideThere
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_MT_EMBER_GRUNT1
	removeobject LOCALID_MT_EMBER_GRUNT2
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

MtEmber_Exterior_EventScript_Grunt2::
	lock
	faceplayer
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_44, MtEmber_Exterior_EventScript_DefeatedGrunt2
	goto_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 4, MtEmber_Exterior_EventScript_BattleGrunt2
	msgbox MtEmber_Exterior_Text_YoureInTheWayGetLost
	closemessage
	applymovement LOCALID_MT_EMBER_GRUNT2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MtEmber_Exterior_EventScript_DefeatedGrunt2::
	msgbox MtEmber_Exterior_Text_Grunt2PostBattle
	release
	end

MtEmber_Exterior_EventScript_BattleGrunt2::
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	msgbox MtEmber_Exterior_Text_Grunt2Intro
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_44, MtEmber_Exterior_Text_Grunt2Defeat
	msgbox MtEmber_Exterior_Text_Grunt2PostBattle
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_43, MtEmber_Exterior_EventScript_DefeatedBothGrunts
	release
	end

MtEmber_Exterior_EventScript_RocketPasswordScene::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	msgbox MtEmber_Exterior_Text_PunchedThroughAtLast
	message MtEmber_Exterior_Text_WhatsPasswordAgain
	waitmessage
	playse SE_PIN
	applymovement LOCALID_MT_EMBER_GRUNT2, Common_Movement_QuestionMark
	waitmovement 0
	waitbuttonpress
	msgbox MtEmber_Exterior_Text_FirstPasswordGoldeen
	applymovement LOCALID_MT_EMBER_GRUNT1, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MT_EMBER_GRUNT1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MT_EMBER_GRUNT1, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MT_EMBER_GRUNT2, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	call MtEmber_Exterior_EventScript_RocketsFaceDown
	msgbox MtEmber_Exterior_Text_SnoopsBeenListeningIn
	setvar VAR_MAP_SCENE_MT_EMBER_EXTERIOR, 2
	releaseall
	end

MtEmber_Exterior_EventScript_Logan::
	trainerbattle_single TRAINER_PKMN_RANGER_LOGAN, MtEmber_Exterior_Text_LoganIntro, MtEmber_Exterior_Text_LoganDefeat
	msgbox MtEmber_Exterior_Text_LoganPostBattle, MSGBOX_AUTOCLOSE
	end

MtEmber_Exterior_EventScript_Beth::
	trainerbattle_single TRAINER_PKMN_RANGER_BETH, MtEmber_Exterior_Text_BethIntro, MtEmber_Exterior_Text_BethDefeat
	msgbox MtEmber_Exterior_Text_BethPostBattle, MSGBOX_AUTOCLOSE
	end

MtEmber_Exterior_EventScript_Jocelyn::
	trainerbattle_single TRAINER_CRUSH_GIRL_JOCELYN, MtEmber_Exterior_Text_JocelynIntro, MtEmber_Exterior_Text_JocelynDefeat
	msgbox MtEmber_Exterior_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

Text_ExplosionTeach::
	.string "Te lo immagini?\n"
	.string "Se questo Vulcano eruttasse?\p"
	.string "L'esplosione sarebbe la nostra\n"
	.string "fine. Che terrore, no?\p"
	.string "Mentre siamo terrorizzati, vuoi\n"
	.string "che ti insegni ESPLOSIONE?$"

Text_ExplosionDeclined::
	.string "Sì, hai ragione.\n"
	.string "È troppo terrificante.$"

Text_ExplosionWhichMon::
	.string "Sei davvero Audace!\p"
	.string "A quale POKéMON insegno\n"
	.string "ESPLOSIONE?$"

Text_ExplosionTaught::
	.string "Usare ESPLOSIONE su questo\n"
	.string "Vulcano…\p"
	.string "Che brivido terrificante!$"

MtEmber_Exterior_Text_WellTryDiggingHere::
	.string "Da questa parte.\n"
	.string "Proveremo a scavare qui.\p"
	.string "Il tesoro di cui parlano\n"
	.string "gli ADMIN dovrebbe essere qui.$"

MtEmber_Exterior_Text_YoureInTheWayGetLost::
	.string "Ma che…?\n"
	.string "Sei d'intralcio. Sparisci.$"

MtEmber_Exterior_Text_PunchedThroughAtLast::
	.string "Fiu, ce l'abbiamo fatta.\n"
	.string "Andiamo a caccia di tesori!$"

MtEmber_Exterior_Text_WhatsPasswordAgain::
	.string "Ogni tesoro trovato lo portiamo\n"
	.string "al WAREHOUSE, chiaro?\p"
	.string "…Oh, e quali sono le password?\n"
	.string "Al ROCKET WAREHOUSE, intendo.$"

MtEmber_Exterior_Text_FirstPasswordGoldeen::
	.string "Come, hai dimenticato la password?\n"
	.string "In realtà sono due.\p"
	.string "La prima è “GOLDEEN need\n"
	.string "log.”\p"
	.string "E la seconda è…$"

MtEmber_Exterior_Text_SnoopsBeenListeningIn::
	.string "Ehi!\n"
	.string "Questo ficcanaso ci ha spiato!$"

MtEmber_Exterior_Text_Grunt1Intro::
	.string "Ci stavi origliando,\n"
	.string "vero?$"

MtEmber_Exterior_Text_Grunt1Defeat::
	.string "Eh, cosa?$"

MtEmber_Exterior_Text_Grunt1PostBattle::
	.string "Perché dovevi vincere?$"

MtEmber_Exterior_Text_Grunt2Intro::
	.string "Vuoi mettere le mani sul nostro tesoro?\n"
	.string "Non contarci!$"

MtEmber_Exterior_Text_Grunt2Defeat::
	.string "Aspetta!\n"
	.string "Ma come?$"

MtEmber_Exterior_Text_Grunt2PostBattle::
	.string "Dimentica tutto per comodità e\n"
	.string "scorda quello che hai sentito!$"

MtEmber_Exterior_Text_WellRegroupDontStepInsideThere::
	.string "Che batosta…\n"
	.string "Dobbiamo riorganizzarci.\p"
	.string "Tu! Non azzardarti a fare\n"
	.string "un passo qui dentro!\p"
	.string "Se ti è cara la pelle,\n"
	.string "non pensarci nemmeno!$"

MtEmber_Exterior_Text_LoganIntro::
	.string "Un Vulcano attivo è quello che\n"
	.string "erutta, o sta per farlo.$"

MtEmber_Exterior_Text_LoganDefeat::
	.string "Fiu… Che caldo!\n"
	.string "Sto sudando come un Vulcano!$"

MtEmber_Exterior_Text_LoganPostBattle::
	.string "Dicono che ci siano oltre 1.500\n"
	.string "Vulcani attivi nel mondo.\p"
	.string "Solo a pensarci mi sento\n"
	.string "tutto caldo e viscido dentro!$"

MtEmber_Exterior_Text_BethIntro::
	.string "Sai come si formano le grotte\n"
	.string "dentro i vulcani?$"

MtEmber_Exterior_Text_BethDefeat::
	.string "Atchah!\n"
	.string "Sei bravo da far paura!$"

MtEmber_Exterior_Text_BethPostBattle::
	.string "Quando la lava in superficie si\n"
	.string "raffredda e il magma sotto scorre\l"
	.string "via, restano delle caverne.$"

MtEmber_Exterior_Text_JocelynIntro::
	.string "Mi sono allenata per guarire\n"
	.string "il mio cuore spezzato…\p"
	.string "Almeno mi ha temprata fisicamente!\n"
	.string "Hi-yah!$"

MtEmber_Exterior_Text_JocelynDefeat::
	.string "Credo di aver esagerato…$"

MtEmber_Exterior_Text_JocelynPostBattle::
	.string "Il tuo modo di lottare mi ricorda\n"
	.string "il ragazzo che mi ha lasciata…$"

