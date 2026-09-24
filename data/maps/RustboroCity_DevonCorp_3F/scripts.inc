RustboroCity_DevonCorp_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_3F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RustboroCity_DevonCorp_3F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_DevonCorp_3F_OnFrame
	.byte 0

RustboroCity_DevonCorp_3F_OnTransition:
	call_if_eq VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos
	end

RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos::
	setobjectxyperm LOCALID_DEVON_CORP_3F_EMPLOYEE, 3, 2
	setobjectmovementtype LOCALID_DEVON_CORP_3F_EMPLOYEE, MOVEMENT_TYPE_FACE_LEFT
	return

RustboroCity_DevonCorp_3F_OnWarp:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast::
	turnobject LOCALID_PLAYER, DIR_EAST
	end

RustboroCity_DevonCorp_3F_OnFrame:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_MeetPresident
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_MeetPresident::
	lockall
	msgbox RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen
	waitmovement 0
	delay 80
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_FOLLOW_ME, FALSE
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident
	applymovement LOCALID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_PleaseGoAhead, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk
	applymovement LOCALID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor, MSGBOX_DEFAULT
	giveitem ITEM_LETTER
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_3F_Text_ReceivedPokenav
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare, MSGBOX_DEFAULT
	setflag FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_BRINEY_LOCATION, 1
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setvar VAR_DEVON_CORP_3F_STATE, 1
	setvar VAR_RUSTBORO_CITY_STATE, 6
	releaseall
	end

RustboroCity_DevonCorp_3F_Movement_Unused:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk:
	delay_16
	walk_in_place_faster_down
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

RustboroCity_DevonCorp_3F_EventScript_MrStone::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EXP_SHARE, RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, RustboroCity_DevonCorp_3F_EventScript_GiveExpShare
	msgbox RustboroCity_DevonCorp_3F_Text_CountingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_GiveExpShare::
	msgbox RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_EXP_SHARE
	msgbox RustboroCity_DevonCorp_3F_Text_ExplainExpShare, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor::
	msgbox RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REPEAT_BALL, RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls
	msgbox RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls::
	msgbox RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay::
	msgbox RustboroCity_DevonCorp_3F_Text_RareRocksDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor:
	.string "Sono il SIG. STONE, il PRESIDENTE\n"
	.string "della DEVON CORPORATION.\p"
	.string "Ho appena saputo di te!\p"
	.string "Hai salvato il nostro staff non una,\n"
	.string "ma due volte!\p"
	.string "Ho un favore da chiedere a una persona\n"
	.string "straordinaria come te.\p"
	.string "So che stai consegnando\n"
	.string "un pacco al CANTIERE di SALTOPORTO.\p"
	.string "Beh, strada facendo, potresti fermarti a\n"
	.string "PORTOALGHE?\p"
	.string "Speravo consegnassi una\n"
	.string "LETTERA a ROCCO a PORTOALGHE.$"

RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis:
	.string "SIG. STONE: Ora, sappi che\n"
	.string "sono un grande PRESIDENTE.\p"
	.string "Non sarei mai così tirchio da chiedere\n"
	.string "un favore senza ricambiare.\p"
	.string "Perciò voglio che tu prenda questo!$"

RustboroCity_DevonCorp_3F_Text_ReceivedPokenav:
	.string "{PLAYER} riceve un POKéNAV.$"

RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp:
	.string "SIG. STONE: Quell'oggetto…\p"
	.string "È un POKéMON NAVIGATOR, o POKéNAV\n"
	.string "in breve.\p"
	.string "È uno strumento indispensabile per ogni\n"
	.string "ALLENATORE in viaggio.\p"
	.string "Ha la mappa della regione di HOENN.\p"
	.string "Puoi vedere dove sono\n"
	.string "PORTOALGHE e SALTOPORTO!\p"
	.string "A proposito, ho sentito che loschi\n"
	.string "criminali, MAGMA e AQUA, pare,\l"
	.string "stanno creando guai ovunque.\p"
	.string "Credo che sia meglio riposare\n"
	.string "prima di rimetterti in cammino.$"

RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare:
	.string "SIG. STONE: Bene, allora, {PLAYER}{KUN},\n"
	.string "va' con prudenza e cautela!$"

RustboroCity_DevonCorp_3F_Text_CountingOnYou:
	.string "SIG. STONE: Conto su di te!$"

RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter:
	.string "MR. STONE: Hai consegnato la mia LETTERA?\n"
	.string "Grazie di cuore!\p"
	.string "Questo è il mio modo di ringraziarti.\n"
	.string "Dovrebbe aiutarti, ALLENATORE.$"

RustboroCity_DevonCorp_3F_Text_ExplainExpShare:
	.string "SIG. STONE: Un POKéMON che tiene\n"
	.string "il CONDIV. ESP. ottiene alcuni\l"
	.string "Punti Esperienza in battaglia.\p"
	.string "Li ottiene anche se non ha\n"
	.string "combattuto direttamente.\p"
	.string "Direi che il CONDIV. ESP. è molto utile\n"
	.string "per allenare POKéMON deboli.$"

RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends:
	.string "SIG. STONE: Fin da giovane mi sono immerso\n"
	.string "nel lavoro.\p"
	.string "Di conseguenza, non conosco\n"
	.string "le mode e cose del genere.\p"
	.string "Ma i giovani vogliono tutti diventare\n"
	.string "ALLENATORI della LEGA POKéMON?$"

RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere:
	.string "Questo è il terzo piano della\n"
	.string "DEVON CORPORATION.\p"
	.string "L'UFFICIO del nostro PRESIDENTE è\n"
	.string "su questo piano.\p"
	.string "Comunque, non so dirti quanto ti sia\n"
	.string "grato per ciò che hai fatto.\p"
	.string "Ehm… A proposito, quel pacco\n"
	.string "che ci hai recuperato…\p"
	.string "Potresti consegnarlo al\n"
	.string "CANTIERE di SALTOPORTO?\p"
	.string "Sarebbe terribile se quei ladri\n"
	.string "provassero a riprenderlo.\p"
	.string "Ehm… Eh eh eh, quindi, potrei contare\n"
	.string "su di te per farlo?\p"
	.string "Oh, giusto.\n"
	.string "Puoi aspettare qui un secondo?$"

RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe:
	.string "Il nostro PRESIDENTE vorrebbe\n"
	.string "parlarti.\p"
	.string "Ti prego, vieni con me.$"

RustboroCity_DevonCorp_3F_Text_PleaseGoAhead:
	.string "Prego, vai pure.$"

RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard:
	.string "Se vai al CANTIERE di SALTOPORTO,\n"
	.string "dovresti andare a trovare CAP. STERN.$"

RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular:
	.string "I nuovi prodotti DEVON, la RIPETIBALL\n"
	.string "e la TIMERBALL, sono diventati molto\l"
	.string "popolari tra gli ALLENATORI.$"

RustboroCity_DevonCorp_3F_Text_RareRocksDisplay:
	.string "È una collezione di rocce rare e\n"
	.string "pietre raccolte dal PRESIDENTE.$"

