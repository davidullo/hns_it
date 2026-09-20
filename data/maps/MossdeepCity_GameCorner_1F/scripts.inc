MossdeepCity_GameCorner_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_GameCorner_1F_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MossdeepCity_GameCorner_1F_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	.byte 0

MossdeepCity_GameCorner_1F_OnWarp:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_CheckTurnAttendant
	.2byte 0

MossdeepCity_GameCorner_1F_OnFrame:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
	.2byte 0

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_InfoMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_InfoMan2
	release
	end

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_OldMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_OldMan2
	release
	end


@ Everything below is leftover from RS
@ The house that was here in RS was moved to Sootopolis and replaced by the Game Corner
@ The text below is unused and duplicated in its replacement in Sootopolis City
@ And the BG Door event was moved inaccessibly into a wall

RS_MysteryEventsHouse_EventScript_Door::
	msgbox RS_MysteryEventsHouse_Text_DoorIsLocked, MSGBOX_SIGN
	end

RS_MysteryEventsHouse_Text_OldManGreeting:
	.string "Da giovane ho girato il mondo\n"
	.string "come ALLENATORE di POKéMON.\p"
	.string "Ora che sono un vecchio rimbambito,\n"
	.string "il mio unico svago è guardare i giovani\l"
	.string "ALLENATORI lottare.$"

RS_MysteryEventsHouse_Text_DoorIsLocked:
	.string "La porta sembra chiusa a chiave.$"

RS_MysteryEventsHouse_Text_ChallengeVisitingTrainer:
	.string "Un ALLENATORE, {STR_VAR_1},\n"
	.string "è ospite a casa mia.\p"
	.string "Vuoi sfidare\n"
	.string "{STR_VAR_1}?$"

RS_MysteryEventsHouse_Text_YouWontBattle:
	.string "Non lottate? Che peccato,\n"
	.string "non potrò vedervi lottare…$"

RS_MysteryEventsHouse_Text_KeepItToA3On3:
	.string "Oh, bene, bene!\p"
	.string "Ma casa mia non è molto solida.\p"
	.string "Potreste limitarvi\n"
	.string "a una lotta 3 contro 3?$"

RS_MysteryEventsHouse_Text_SaveYourProgress:
	.string "Prima di lottare, dovreste\n"
	.string "salvare i progressi.$"

RS_MysteryEventsHouse_Text_HopeToSeeAGoodMatch:
	.string "Spero in un bell'incontro!$"

RS_MysteryEventsHouse_Text_BattleTie:
	.string "Quindi è finita in parità.\p"
	.string "È stata una lotta splendida in cui\n"
	.string "nessuno ha ceduto un passo!$"

RS_MysteryEventsHouse_Text_BattleWon:
	.string "Che battaglia superba!\p"
	.string "È stato come rivedermi\n"
	.string "da giovane!$"

RS_MysteryEventsHouse_Text_BattleLost:
	.string "Ah, peccato per te!\p"
	.string "Ma è stata una bella lotta.\n"
	.string "Spero che la prossima volta vinca tu.$"
