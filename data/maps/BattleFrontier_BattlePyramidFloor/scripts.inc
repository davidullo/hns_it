BattleFrontier_BattlePyramidFloor_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidFloor_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidFloor_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidFloor_OnTransition
	.byte 0

BattleFrontier_BattlePyramidFloor_OnFrame:
	map_script_2 VAR_TEMP_D, 1, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight
	map_script_2 VAR_TEMP_PLAYING_PYRAMID_MUSIC, 0, BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName
	.2byte 0

BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight::
	lockall
	@ pyramid_updatelight, cant use macro because it straddles the loop
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, PYRAMID_LIGHT_INCR_RADIUS
	setvar VAR_0x8007, SE_SAVE
	setvar VAR_RESULT, 0
BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop::
	special CallBattlePyramidFunction
	delay 2
	goto_if_ne VAR_RESULT, 2, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop
	setvar VAR_TEMP_D, 0
	releaseall
	end

BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName::
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic::
	playbgm MUS_B_PYRAMID, FALSE
	setvar VAR_TEMP_PLAYING_PYRAMID_MUSIC, 1
	end

BattleFrontier_BattlePyramidFloor_OnResume:
	pyramid_setfloorpal
	frontier_getstatus
	switch VAR_TEMP_CHALLENGE_STATUS
	case 0, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	frontier_isbattletype BATTLE_TYPE_TRAINER  @ VAR_RESULT seems to be ignored here
	setvar VAR_TEMP_D, 1
BattleFrontier_BattlePyramidFloor_EventScript_ResetParty::
	pyramid_resetparty
	end

BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	pyramid_set PYRAMID_DATA_TRAINER_FLAGS, 255
BattleFrontier_BattlePyramid_EventScript_WarpToLobby::
	pyramid_updatelight 0, PYRAMID_LIGHT_SET_RADIUS
	pyramid_clearhelditems
	special HealPlayerParty
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge::
	pyramid_save CHALLENGE_STATUS_SAVING
	special SavePlayerParty
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	pyramid_settrainers
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_OnTransition:
	call BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius::
	pyramid_updatelight 32, PYRAMID_LIGHT_SET_RADIUS
	return

BattlePyramid_WarpToNextFloor::
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Floor number
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	goto_if_eq VAR_RESULT, 7, BattlePyramid_WarpToTop
	pyramid_seedfloor
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	waitstate
	end

BattlePyramid_WarpToTop::
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP, 17, 17
	waitstate
	end

@ TRAINER_PHILLIP is used as a placeholder
BattlePyramid_TrainerBattle::
	facilitytrainerbattle FACILITY_BATTLE_PYRAMID
	pyramid_showhint
	waitmessage
	waitbuttonpress
	closemessage
	releaseall
	end

BattlePyramid_FindItemBall::
	pyramid_setitem
	callstd STD_FIND_ITEM
	goto_if_eq VAR_0x8007, 0, BattlePyramid_FindItemBallEnd
	pyramid_hideitem
BattlePyramid_FindItemBallEnd::
	end

BattlePyramid_Retire::
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost

@ Also used by Trainer Hill
BattleFacility_TrainerBattle_PlaceholderText:
	.string "Messaggio d'esempio.$"

gText_BattlePyramidConfirmRest::
	.string "La tua avventura nella\n"
	.string "PIRAMIDE LOTTA verrà salvata.\l"
	.string "Va bene così?$"

gText_BattlePyramidConfirmRetire::
	.string "Vuoi davvero abbandonare la\n"
	.string "sfida alla PIRAMIDE?$"

BattlePyramid_Text_ExitHintUp1::
	.string "L'uscita di questo piano è\n"
	.string "in quella direzione: {UP_ARROW}$"

BattlePyramid_Text_ExitHintLeft1::
	.string "This floor's exit is in\n"
	.string "that direction: {LEFT_ARROW}$"

BattlePyramid_Text_ExitHintRight1::
	.string "L'uscita di questo piano è\n"
	.string "in quella direzione: {RIGHT_ARROW}$"

BattlePyramid_Text_ExitHintDown1::
	.string "This floor's exit is in\n"
	.string "that direction: {DOWN_ARROW}$"

BattlePyramid_Text_ExitHintUp2::
	.string "L'uscita di questo piano è\n"
	.string "nella direzione {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft2::
	.string "L'uscita di questo piano\n"
	.string "è verso {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight2::
	.string "L'uscita di questo piano è\n"
	.string "nella direzione {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown2::
	.string "L'uscita di questo piano\n"
	.string "è verso {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp3::
	.string "L'uscita è là\n"
	.string "in quella direzione: {UP_ARROW}$"

BattlePyramid_Text_ExitHintLeft3::
	.string "L'uscita è là\n"
	.string "in quella direzione: {LEFT_ARROW}$"

BattlePyramid_Text_ExitHintRight3::
	.string "L'uscita è là\n"
	.string "in quella direzione: {RIGHT_ARROW}$"

BattlePyramid_Text_ExitHintDown3::
	.string "L'uscita è là\n"
	.string "verso {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp4::
	.string "In questo piano, l'uscita è\n"
	.string "da qualche parte a {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft4::
	.string "In questo piano, l'uscita è\n"
	.string "da qualche parte a {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight4::
	.string "In questo piano, l'uscita è\n"
	.string "da qualche parte a {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown4::
	.string "Qui l'uscita è da qualche\n"
	.string "parte verso {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp5::
	.string "L'uscita?\n"
	.string "È là, a {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft5::
	.string "L'uscita?\n"
	.string "È là, a {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight5::
	.string "L'uscita?\n"
	.string "È là, a {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown5::
	.string "L'uscita?\n"
	.string "È là, verso {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp6::
	.string "Per caso, l'uscita si trova\n"
	.string "nella direzione {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft6::
	.string "Per caso, l'uscita si trova\n"
	.string "nella direzione {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight6::
	.string "Per caso, l'uscita si trova\n"
	.string "nella direzione {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown6::
	.string "Casomai, l'uscita è\n"
	.string "verso {DOWN_ARROW}.$"

BattlePyramid_Text_EightItemsRemaining1::
	.string "Cercate degli strumenti?\p"
	.string "Su questo piano restano\n"
	.string "otto oggetti.$"

BattlePyramid_Text_SevenItemsRemaining1::
	.string "Cerchi degli strumenti?\p"
	.string "Ne restano sette\n"
	.string "da trovare.$"

BattlePyramid_Text_SixItemsRemaining1::
	.string "Cerchi degli oggetti?\p"
	.string "In questo piano restano sei\n"
	.string "oggetti da trovare.$"

BattlePyramid_Text_FiveItemsRemaining1::
	.string "Cerchi oggetti?\p"
	.string "Restano ancora cinque oggetti\n"
	.string "da trovare.$"

BattlePyramid_Text_FourItemsRemaining1::
	.string "Cerci degli oggetti?\p"
	.string "Restano quattro oggetti\n"
	.string "nascosti.$"

BattlePyramid_Text_ThreeItemsRemaining1::
	.string "Cerchi degli oggetti?\p"
	.string "In questo piano restano tre\n"
	.string "oggetti da trovare.$"

BattlePyramid_Text_TwoItemsRemaining1::
	.string "Cerchi degli oggetti?\p"
	.string "Restano due oggetti\n"
	.string "da trovare.$"

BattlePyramid_Text_OneItemRemaining1::
	.string "Cerchi degli strumenti?\p"
	.string "Ne resta solo uno\n"
	.string "da trovare.$"

BattlePyramid_Text_ZeroItemsRemaining1::
	.string "Cerchi degli oggetti?\p"
	.string "Non è rimasto più nulla\n"
	.string "da trovare!$"

BattlePyramid_Text_EightItemsRemaining2::
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are eight items\n"
	.string "lying around here.$"

BattlePyramid_Text_SevenItemsRemaining2::
	.string "Hai vinto, quindi ti dico\n"
	.string "un segretino!\p"
	.string "Qui in giro restano\n"
	.string "sette strumenti.$"

BattlePyramid_Text_SixItemsRemaining2::
	.string "Hai vinto, quindi ti dico\n"
	.string "un segreto!\p"
	.string "Qui in giro restano\n"
	.string "sei oggetti.$"

BattlePyramid_Text_FiveItemsRemaining2::
	.string "Hai vinto, quindi ti dico\n"
	.string "un piccolo segreto!\p"
	.string "Ci sono ancora cinque oggetti\n"
	.string "sparsi qui in giro.$"

BattlePyramid_Text_FourItemsRemaining2::
	.string "Hai vinto, quindi ti dico\n"
	.string "un segreto!\p"
	.string "Restano quattro oggetti\n"
	.string "in giro qui.$"

BattlePyramid_Text_ThreeItemsRemaining2::
	.string "Hai vinto, quindi ti dico\n"
	.string "un segreto!\p"
	.string "Qui in giro restano\n"
	.string "tre oggetti.$"

BattlePyramid_Text_TwoItemsRemaining2::
	.string "Hai vinto, quindi ti dico\n"
	.string "un segreto!\p"
	.string "Qui restano due\n"
	.string "oggetti nascosti.$"

BattlePyramid_Text_OneItemRemaining2::
	.string "Hai vinto, quindi ti dico\n"
	.string "un segretino!\p"
	.string "Qui in giro c'è\n"
	.string "un solo strumento.$"

BattlePyramid_Text_ZeroItemsRemaining2::
	.string "Hai vinto, così ti rivelo\n"
	.string "un piccolo segreto!\p"
	.string "Qui non è rimasto\n"
	.string "più niente in giro.$"

BattlePyramid_Text_EightItemsRemaining3::
	.string "Come vanno gli strumenti?\p"
	.string "Direi che restano otto\n"
	.string "oggetti da trovare qui.$"

BattlePyramid_Text_SevenItemsRemaining3::
	.string "Come va con gli strumenti?\p"
	.string "Mi sa che su questo piano\n"
	.string "restano sette strumenti.$"

BattlePyramid_Text_SixItemsRemaining3::
	.string "Come vanno i tuoi oggetti?\p"
	.string "Sei oggetti sono ancora\n"
	.string "nascosti in questo piano.$"

BattlePyramid_Text_FiveItemsRemaining3::
	.string "Come va con le scorte?\p"
	.string "Mi sa che restano cinque oggetti\n"
	.string "da trovare su questo piano.$"

BattlePyramid_Text_FourItemsRemaining3::
	.string "Come va la scorta di oggetti?\p"
	.string "Credo restino quattro oggetti\n"
	.string "da trovare in questo piano.$"

BattlePyramid_Text_ThreeItemsRemaining3::
	.string "Come vanno i tuoi oggetti?\p"
	.string "Tre oggetti sono ancora\n"
	.string "nascosti in questo piano.$"

BattlePyramid_Text_TwoItemsRemaining3::
	.string "Quanti oggetti ti restano?\p"
	.string "Penso che ci siano ancora\n"
	.string "due oggetti da trovare qui.$"

BattlePyramid_Text_OneItemRemaining3::
	.string "Come va con gli strumenti?\p"
	.string "Mi sa che su questo piano\n"
	.string "resta solo uno strumento.$"

BattlePyramid_Text_ZeroItemsRemaining3::
	.string "Come vanno le tue scorte?\p"
	.string "Mi sa che su questo piano\n"
	.string "non ci sono più oggetti.\l"
	.string "Buona fortuna!$"

BattlePyramid_Text_EightItemsRemaining4::
	.string "Sei forte, quindi ecco\n"
	.string "un indizio!\p"
	.string "Sembra che restino otto\n"
	.string "oggetti in giro.$"

BattlePyramid_Text_SevenItemsRemaining4::
	.string "Sei forte, quindi ti spetta\n"
	.string "un indizio!\p"
	.string "Sembra che restino sette\n"
	.string "strumenti a terra.$"

BattlePyramid_Text_SixItemsRemaining4::
	.string "Sei forte, quindi ecco\n"
	.string "un indizio!\p"
	.string "Sembra che in TERRA ci\n"
	.string "siano altri sei oggetti.$"

BattlePyramid_Text_FiveItemsRemaining4::
	.string "Sei forte, quindi hai\n"
	.string "un indizio!\p"
	.string "Sembra che restino altri cinque\n"
	.string "oggetti a terra.$"

BattlePyramid_Text_FourItemsRemaining4::
	.string "Sei forte, quindi ti meriti\n"
	.string "questo!\p"
	.string "Sembra che restino quattro\n"
	.string "oggetti a TERRA.$"

BattlePyramid_Text_ThreeItemsRemaining4::
	.string "Sei forte, quindi ecco\n"
	.string "un indizio!\p"
	.string "Sembra che in TERRA ci\n"
	.string "siano altri tre oggetti.$"

BattlePyramid_Text_TwoItemsRemaining4::
	.string "Sei forte, ti meriti\n"
	.string "un indizio!\p"
	.string "Sembra che restino altri due\n"
	.string "oggetti in giro.$"

BattlePyramid_Text_OneItemRemaining4::
	.string "Sei forte, quindi ti spetta\n"
	.string "un indizio!\p"
	.string "Sembri che rimanga solo\n"
	.string "uno strumento a terra.$"

BattlePyramid_Text_ZeroItemsRemaining4::
	.string "Sei forte, quindi ti meriti\n"
	.string "un consiglio!\p"
	.string "Sembra che non ci siano più\n"
	.string "oggetti in giro.$"

BattlePyramid_Text_EightItemsRemaining5::
	.string "Su questo piano della\n"
	.string "PIRAMIDE, otto oggetti…$"

BattlePyramid_Text_SevenItemsRemaining5::
	.string "Su questo piano della PIRAMIDE,\n"
	.string "sentivo che ci sono 7 strumenti…$"

BattlePyramid_Text_SixItemsRemaining5::
	.string "In questo piano della PIRAMIDE,\n"
	.string "sento che restano sei oggetti…$"

BattlePyramid_Text_FiveItemsRemaining5::
	.string "Al piano della PIRAMIDE,\n"
	.string "si dice ci siano 5 oggetti…$"

BattlePyramid_Text_FourItemsRemaining5::
	.string "Al piano della PIRAMIDE,\n"
	.string "si dice ci siano 4 oggetti…$"

BattlePyramid_Text_ThreeItemsRemaining5::
	.string "In questo piano della PIRAMIDE,\n"
	.string "mi dicono che ci sono tre oggetti…$"

BattlePyramid_Text_TwoItemsRemaining5::
	.string "In questo piano della PIRAMIDE,\n"
	.string "mi dicono che ci sono due oggetti…$"

BattlePyramid_Text_OneItemRemaining5::
	.string "Su questo piano della PIRAMIDE,\n"
	.string "sentivo che c'è uno strumento…$"

BattlePyramid_Text_ZeroItemsRemaining5::
	.string "Su questo piano della PIRAMIDE,\n"
	.string "sentivo che non ci sono oggetti…$"

BattlePyramid_Text_EightItemsRemaining6::
	.string "Have you collected any items?\p"
	.string "I believe there are eight more\n"
	.string "items on this floor.$"

BattlePyramid_Text_SevenItemsRemaining6::
	.string "Hai raccolto strumenti?\p"
	.string "Credo che su questo piano\n"
	.string "ne restino altri sette.$"

BattlePyramid_Text_SixItemsRemaining6::
	.string "Hai raccolto qualche oggetto?\p"
	.string "Credo che restino altri sei\n"
	.string "oggetti qui.$"

BattlePyramid_Text_FiveItemsRemaining6::
	.string "Hai raccolto oggetti?\p"
	.string "Credo che restino cinque\n"
	.string "oggetti qui.$"

BattlePyramid_Text_FourItemsRemaining6::
	.string "Hai raccolto oggetti?\p"
	.string "Credo che restino quattro\n"
	.string "oggetti qui.$"

BattlePyramid_Text_ThreeItemsRemaining6::
	.string "Hai raccolto qualche oggetto?\p"
	.string "Credo che restino altri tre\n"
	.string "oggetti qui.$"

BattlePyramid_Text_TwoItemsRemaining6::
	.string "Hai raccolto qualche oggetto?\p"
	.string "Credo che restino altri due\n"
	.string "oggetti qui.$"

BattlePyramid_Text_OneItemRemaining6::
	.string "Hai raccolto strumenti?\p"
	.string "Credo che su questo piano\n"
	.string "resti un altro strumento.$"

BattlePyramid_Text_ZeroItemsRemaining6::
	.string "Hai raccolto oggetti?\p"
	.string "Secondo me su questo piano\n"
	.string "non ci sono più oggetti.$"

BattlePyramid_Text_SevenTrainersRemaining1::
	.string "Sei stato fantastico!\p"
	.string "Ma restano sette ALLENATORI\n"
	.string "forti oltre me!$"

BattlePyramid_Text_SixTrainersRemaining1::
	.string "Sei stato fantastico!\p"
	.string "Ma restano altri sei\n"
	.string "ALLENATORI forti oltre a me!$"

BattlePyramid_Text_FiveTrainersRemaining1::
	.string "Sei stato forte!\p"
	.string "Ma restano cinque ALLENATORI\n"
	.string "tosti oltre a me!$"

BattlePyramid_Text_FourTrainersRemaining1::
	.string "Sei stato forte!\p"
	.string "Ma restano quattro ALLENATORI\n"
	.string "tosti oltre a me!$"

BattlePyramid_Text_ThreeTrainersRemaining1::
	.string "Sei stato bravissimo!\p"
	.string "Ma restano ancora tre ALLENATORI\n"
	.string "in gamba oltre a me!$"

BattlePyramid_Text_TwoTrainersRemaining1::
	.string "Sei stato bravissimo!\p"
	.string "Ma restano ancora due ALLENATORI\n"
	.string "in gamba oltre a me!$"

BattlePyramid_Text_OneTrainersRemaining1::
	.string "Sei stato fantastico!\p"
	.string "Ma resta un ALLENATORE\n"
	.string "forte oltre me!$"

BattlePyramid_Text_ZeroTrainersRemaining1::
	.string "Sei stato fantastico!\p"
	.string "Non è rimasto più nessuno\n"
	.string "che possa batterti!$"

BattlePyramid_Text_SevenTrainersRemaining2::
	.string "This is so upsetting!\p"
	.string "But there are seven TRAINERS left!\n"
	.string "Someone will humble you!$"

BattlePyramid_Text_SixTrainersRemaining2::
	.string "This is so upsetting!\p"
	.string "But there are six TRAINERS left!\n"
	.string "Someone will humble you!$"

BattlePyramid_Text_FiveTrainersRemaining2::
	.string "This is so upsetting!\p"
	.string "But there are five TRAINERS left!\n"
	.string "Someone will humble you!$"

BattlePyramid_Text_FourTrainersRemaining2::
	.string "This is so upsetting!\p"
	.string "But there are four TRAINERS left!\n"
	.string "Someone will humble you!$"

BattlePyramid_Text_ThreeTrainersRemaining2::
	.string "This is so upsetting!\p"
	.string "But there are three TRAINERS left!\n"
	.string "Someone will humble you!$"

BattlePyramid_Text_TwoTrainersRemaining2::
	.string "This is so upsetting!\p"
	.string "But there are two TRAINERS left!\n"
	.string "Someone will humble you!$"

BattlePyramid_Text_OneTrainersRemaining2::
	.string "This is so upsetting!\p"
	.string "But there's one TRAINER left!\n"
	.string "I'm sure you will be humbled!$"

BattlePyramid_Text_ZeroTrainersRemaining2::
	.string "This is so upsetting!\p"
	.string "But there are no more TRAINERS\n"
	.string "who can engage you!$"

BattlePyramid_Text_SevenTrainersRemaining3::
	.string "Che forza notevole!\p"
	.string "Ma in questo piano restano\n"
	.string "ancora sette ALLENATORI. Li batti tutti?$"

BattlePyramid_Text_SixTrainersRemaining3::
	.string "Che forza notevole!\p"
	.string "Ma in questo piano restano\n"
	.string "altri sei ALLENATORI. Li batti tutti?$"

BattlePyramid_Text_FiveTrainersRemaining3::
	.string "That's pretty impressive!\p"
	.string "But there are five more TRAINERS\n"
	.string "on this floor. Can you beat them all?$"

BattlePyramid_Text_FourTrainersRemaining3::
	.string "That's pretty impressive!\p"
	.string "But there are four more TRAINERS\n"
	.string "on this floor. Can you beat them all?$"

BattlePyramid_Text_ThreeTrainersRemaining3::
	.string "That's pretty impressive!\p"
	.string "But there are three more TRAINERS\n"
	.string "on this floor. Can you beat them all?$"

BattlePyramid_Text_TwoTrainersRemaining3::
	.string "Niente male, davvero!\p"
	.string "Ma restano altri due ALLENATORI\n"
	.string "qui. Li batti entrambi?$"

BattlePyramid_Text_OneTrainersRemaining3::
	.string "Non è malvagio!\p"
	.string "Ma resta ancora un ALLENATORE\n"
	.string "qui. Riuscirai a batterlo?$"

BattlePyramid_Text_ZeroTrainersRemaining3::
	.string "That's pretty impressive!\p"
	.string "You've gone through all the TRAINERS\n"
	.string "on this floor.$"

BattlePyramid_Text_SevenTrainersRemaining4::
	.string "Forse potresti spazzare via\n"
	.string "i sette ALLENATORI del piano.$"

BattlePyramid_Text_SixTrainersRemaining4::
	.string "Forse potresti spazzare via\n"
	.string "i sei ALLENATORI del piano.$"

BattlePyramid_Text_FiveTrainersRemaining4::
	.string "Forse riuscirai a battere\n"
	.string "i cinque ALLENATORI rimasti.$"

BattlePyramid_Text_FourTrainersRemaining4::
	.string "Forse riuscirai a battere\n"
	.string "i quattro ALLENATORI rimasti.$"

BattlePyramid_Text_ThreeTrainersRemaining4::
	.string "Forse riuscirai a sfidare\n"
	.string "i tre ALLENATORI di questo piano.$"

BattlePyramid_Text_TwoTrainersRemaining4::
	.string "Forse riuscirai a sfidare\n"
	.string "i due ALLENATORI di questo piano.$"

BattlePyramid_Text_OneTrainersRemaining4::
	.string "Potresti finire in bellezza\n"
	.string "con l'ultimo ALLENATORE qui.$"

BattlePyramid_Text_ZeroTrainersRemaining4::
	.string "Non è rimasta più una sola persona\n"
	.string "che possa batterti ora…$"

BattlePyramid_Text_SevenTrainersRemaining5::
	.string "Forse ce la puoi fare a battere\n"
	.string "i sette ALLENATORI che restano.$"

BattlePyramid_Text_SixTrainersRemaining5::
	.string "Forse ce la puoi fare a battere\n"
	.string "i sei ALLENATORI che restano.$"

BattlePyramid_Text_FiveTrainersRemaining5::
	.string "Forse sei in grado di battere\n"
	.string "i cinque ALLENATORI esperti.$"

BattlePyramid_Text_FourTrainersRemaining5::
	.string "Forse sei in grado di battere\n"
	.string "i quattro ALLENATORI esperti.$"

BattlePyramid_Text_ThreeTrainersRemaining5::
	.string "Forse hai le carte per battere\n"
	.string "i tre ALLENATORI esperti.$"

BattlePyramid_Text_TwoTrainersRemaining5::
	.string "Forse hai le carte per battere\n"
	.string "i due ALLENATORI esperti.$"

BattlePyramid_Text_OneTrainersRemaining5::
	.string "Forse ce la farai contro\n"
	.string "l'ultimo ALLENATORE esperto.$"

BattlePyramid_Text_ZeroTrainersRemaining5::
	.string "Le tue doti sono eccellenti.\p"
	.string "Qui non ci sono più ALLENATORI\n"
	.string "con una minima chance contro di te.$"

BattlePyramid_Text_SevenTrainersRemaining6::
	.string "Puoi continuare a vincere contro\n"
	.string "gli altri sette ALLENATORI?$"

BattlePyramid_Text_SixTrainersRemaining6::
	.string "Puoi continuare a vincere contro\n"
	.string "gli altri sei ALLENATORI?$"

BattlePyramid_Text_FiveTrainersRemaining6::
	.string "Puoi continuare a vincere\n"
	.string "contro i cinque ALLENATORI?$"

BattlePyramid_Text_FourTrainersRemaining6::
	.string "Puoi continuare a vincere\n"
	.string "contro i quattro ALLENATORI?$"

BattlePyramid_Text_ThreeTrainersRemaining6::
	.string "Riuscirai a battere\n"
	.string "gli altri tre ALLENATORI?$"

BattlePyramid_Text_TwoTrainersRemaining6::
	.string "Riuscirai a battere\n"
	.string "gli altri due ALLENATORI?$"

BattlePyramid_Text_OneTrainersRemaining6::
	.string "Potrai continuare a vincere\n"
	.string "contro l'ultimo ALLENATORE?$"

BattlePyramid_Text_ZeroTrainersRemaining6::
	.string "Non è rimasto alcun ALLENATORE\n"
	.string "che possa affrontarti ora…$"
