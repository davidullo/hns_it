SixIsland_RuinValley_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SixIsland_RuinValley_OnLoad
	.byte 0

SixIsland_RuinValley_OnLoad::
	call_if_set FLAG_USED_CUT_ON_RUIN_VALLEY_BRAILLE, SixIsland_RuinValley_EventScript_OpenDottedHoleDoor
	end

SixIsland_RuinValley_EventScript_OpenDottedHoleDoor::
	setmetatile 24, 24, METATILE_SeviiIslands67_DottedHoleDoor_Open, 0
	return

SixIsland_RuinValley_EventScript_Scientist::
	lock
	msgbox SixIsland_RuinValley_Text_CantFigureOutHowToGetInside
	applymovement LOCALID_RUIN_VALLEY_SCIENTIST, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SixIsland_RuinValley_Text_IFoundThisPlace
	applymovement LOCALID_RUIN_VALLEY_SCIENTIST, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SixIsland_RuinValley_EventScript_DottedHoleDoor::
	lockall
	goto_if_set FLAG_USED_CUT_ON_RUIN_VALLEY_BRAILLE, SixIsland_RuinValley_EventScript_DottedHoleDoorOpen
	msgbox SixIsland_RuinValley_Text_CheckDoorMoreThoroughly, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SixIsland_RuinValley_EventScript_IgnoreDottedHoleDoor
	msgbox SixIsland_RuinValley_Text_SeveralDotsOnTheDoor
	braillemsgbox Braille_Text_Cut
	releaseall
	end

SixIsland_RuinValley_EventScript_DottedHoleDoorOpen::
	msgbox SixIsland_RuinValley_Text_DoorIsOpen
	releaseall
	end

SixIsland_RuinValley_EventScript_IgnoreDottedHoleDoor::
	msgbox SixIsland_RuinValley_Text_LeftDoorAlone
	releaseall
	end

SixIsland_RuinValley_Text_CantFigureOutHowToGetInside::
	.string "Non riesco a capire come si\n"
	.string "possa entrare.$"

SixIsland_RuinValley_Text_IFoundThisPlace::
	.string "Lascia che te lo dica, ho trovato\n"
	.string "io questo posto.\p"
	.string "Non fare l'invidioso, eh?$"

SixIsland_RuinValley_Text_CheckDoorMoreThoroughly::
	.string "La porta non si muove di un millimetro.\n"
	.string "Controllarla meglio?$"

SixIsland_RuinValley_Text_LeftDoorAlone::
	.string "{PLAYER} lascia perdere la porta.$"

SixIsland_RuinValley_Text_SeveralDotsOnTheDoor::
	.string "Guardando meglio, sulla porta\n"
	.string "ci sono diversi puntini…$"

SixIsland_RuinValley_Text_DoorIsOpen::
	.string "La porta è aperta.$"

SixIsland_RuinValley_Text_StanlyIntro::
	.string "Sembra che in questo mondo restino\n"
	.string "molti segreti irrisolti.$"

SixIsland_RuinValley_Text_StanlyDefeat::
	.string "Hmm…$"

SixIsland_RuinValley_Text_StanlyPostBattle::
	.string "Ti consiglio di pensare anche tu\n"
	.string "ai segreti e ai misteri del\l"
	.string "nostro mondo, una volta al giorno.$"

SixIsland_RuinValley_Text_FosterIntro::
	.string "Sono curioso, cosa ti ha spinto a\n"
	.string "venire qui?$"

SixIsland_RuinValley_Text_FosterDefeat::
	.string "È da tanto che non lotto,\n"
	.string "ho perso il ritmo.$"

SixIsland_RuinValley_Text_FosterPostBattle::
	.string "Ci sono diverse rovine sulle\n"
	.string "ISOLE SEVII.\p"
	.string "La maggior parte risale\n"
	.string "a molto tempo fa.$"

SixIsland_RuinValley_Text_LarryIntro::
	.string "Si dice che su quest'isola ci siano\n"
	.string "pietre misteriose.\p"
	.string "Sospetto che c'entri qualcosa\n"
	.string "con le rovine qui.$"

SixIsland_RuinValley_Text_LarryDefeat::
	.string "Oh, interessante.$"

SixIsland_RuinValley_Text_LarryPostBattle::
	.string "Quelle rovine laggiù…\p"
	.string "Non ho ancora capito\n"
	.string "come si entra.$"

SixIsland_RuinValley_Text_DarylIntro::
	.string "Una lotta con te, quassù!$"

SixIsland_RuinValley_Text_DarylDefeat::
	.string "Oh, che crepacuore perdere così\n"
	.string "facilmente contro di te!$"

SixIsland_RuinValley_Text_DarylPostBattle::
	.string "Prova la gioia di arrampicarti!$"

SixIsland_RuinValley_Text_HectorIntro::
	.string "Conosco piuttosto bene la terra\n"
	.string "da queste parti.$"

SixIsland_RuinValley_Text_HectorDefeat::
	.string "Non devi essere così insistente.\n"
	.string "Te lo dico volentieri.$"

SixIsland_RuinValley_Text_HectorPostBattle::
	.string "La porta delle rovine…\n"
	.string "Ha strani disegni\l"
	.string "incisi all'esterno.\p"
	.string "Però non so cosa\n"
	.string "significhino.$"
