LilycoveCity_House3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_House3_OnTransition
	.byte 0

LilycoveCity_House3_OnTransition:
	random 4
	copyvar VAR_TEMP_1, VAR_RESULT
	end

LilycoveCity_House3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_House3_EventScript_DeclinePokeblockLearn
	msgbox LilycoveCity_House3_Text_ExplainPokeblocks, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_DeclinePokeblockLearn::
	msgbox LilycoveCity_House3_Text_OhAreYouSure, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_Man::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_HappyToHaveQuadruplets, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_GameBoyKid1::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid2::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid3::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid4::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_WereDoingMultiBattle::
	msgbox LilycoveCity_House3_Text_GoingToWinMultiBattles, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereMixingRecords::
	msgbox LilycoveCity_House3_Text_LikeMixingAtRecordCorner, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereBlendingBerries::
	msgbox LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereDoingContest::
	msgbox LilycoveCity_House3_Text_GoingToEnterContest, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks:
	.string "Oh, ciao! Viaggi da solo?\n"
	.string "Ma sei così giovane! Bravo!\p"
	.string "I miei figli potrebbero imparare\n"
	.string "qualcosa da te!\p"
	.string "Io? Sono un maestro di {POKEBLOCK}.\p"
	.string "Se mi impegno un pochino,\n"
	.string "so creare {POKEBLOCK} fantastiche.\p"
	.string "Vuoi imparare da me,\n"
	.string "maestro di {POKEBLOCK}?$"

LilycoveCity_House3_Text_OhAreYouSure:
	.string "Oh? Sicuro?\p"
	.string "Non devi fare sempre\n"
	.string "tutto da solo, caro!$"

LilycoveCity_House3_Text_ExplainPokeblocks:
	.string "Oh, bene! Sei una persona sveglia!\n"
	.string "È un po' lunga, quindi ascolta!\p"
	.string "Sei pronta?\p"
	.string "Se guardi le {POKEBLOCK}, vedrai\n"
	.string "che hanno un giudizio sulla sensazione.\p"
	.string "Più basso è il giudizio,\n"
	.string "meglio è. Non scordarlo!\p"
	.string "Una buona {POKEBLOCK} ha una sensazione\n"
	.string "bassa e un livello alto.\p"
	.string "Un POKéMON può mangiarne più di\n"
	.string "{POKEBLOCK} normali, inoltre.\p"
	.string "E questo è importante.\p"
	.string "Se vuoi {POKEBLOCK} morbide,\n"
	.string "usa BACCHE diverse.\p"
	.string "Non essere tirchia, i tipi di BACCHE\n"
	.string "cambiano la morbidezza delle {POKEBLOCK}.\p"
	.string "E un'altra cosa.\p"
	.string "Più persone frullano le BACCHE,\n"
	.string "più morbide sono le {POKEBLOCK}.\p"
	.string "Ecco perché dovresti parlare con\n"
	.string "altri e fare {POKEBLOCK} assieme.\p"
	.string "Questo è tutto quello che serve per\n"
	.string "fare buone {POKEBLOCK}.\p"
	.string "Se tutti avessero POKéMON amati,\n"
	.string "{POKEBLOCK} morbide e una bella famiglia,\l"
	.string "il mondo sarebbe più felice.\p"
	.string "Non arrenderti, cara!$"

LilycoveCity_House3_Text_HappyToHaveQuadruplets:
	.string "Quando mia moglie ha partorito 4 gemelli,\n"
	.string "sono rimasto scioccato.\p"
	.string "Ma ora, vedendoli giocare insieme,\n"
	.string "sono felice.$"

LilycoveCity_House3_Text_GoingToWinMultiBattles:
	.string "Facciamo LOTTE MULTIPLE, ma so\n"
	.string "che vincerò.$"

LilycoveCity_House3_Text_LikeMixingAtRecordCorner:
	.string "Ci piace mescolare cose al\n"
	.string "RECORD CORNER.\p"
	.string "Ma cosa si mescola?$"

LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender:
	.string "Faremo {POKEBLOCK} super\n"
	.string "con un FRULLA BACCHE!$"

LilycoveCity_House3_Text_GoingToEnterContest:
	.string "Voglio vantarmi di quanto è forte il mio\n"
	.string "POKéMON, quindi andiamo\l"
	.string "a una GARA insieme.$"

