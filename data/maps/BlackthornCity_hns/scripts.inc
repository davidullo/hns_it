BlackthornCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BlackthornCity_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, BlackthornCity_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, BlackthornCity_EventScript_CityEnter
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

BlackthornCity_OnLoad::
	goto_if_unset FLAG_BADGE05_GET, BlackThornCity_EventScript_MoveGymBoy
	goto_if_unset FLAG_BADGE06_GET, BlackThornCity_EventScript_MoveGymBoy
	goto_if_unset FLAG_BADGE07_GET, BlackThornCity_EventScript_MoveGymBoy
	end

BlackThornCity_EventScript_MoveGymBoy::
	setobjectxyperm LOCALID_BLACKTHORN_BOY, 24, 27
	end

BlackthornCity_OnFrame::
	map_script_2 VAR_BLACKTHORN_CITY_STATE, 4, BlackthornCity_EventScript_Call
	.2byte 0

BlackthornCity_EventScript_CityEnter:: 
	setflag FLAG_VISITED_BLACKTHORN_CITY
	callnative SetTimeBasedEncounters
	end

BlackthornCity_EventScript_Call::
	lock
	setspeaker BlackthornCity_Text_ElmName
	pokenavcall BlackthornCity_Text_ElmCall
	waitmessage
	delay 30
	setvar VAR_BLACKTHORN_CITY_STATE, 5
	setvar VAR_NEWBARKTOWN_LABSTATE, 7
	release
	end

BlackthornCity_Text_ElmName:
	.string "PROF.ELM$"

BlackthornCity_Text_BaobaCall:
	.string "WARDEN BAOBA: {PLAYER}!\p"
	.string "Sono WARDEN BAOBA.\p"
	.string "Ti chiamo per dirti che\n"
	.string "la ZONA SAFARI si è espansa!\p"
	.string "Vieni a visitarla!$"

BlackthornCity_Text_ElmCall:
	.string "PROF.ELM: Pronto, {PLAYER}?\p"
	.string "Ho una cosa per te.\n"
	.string "Puoi passare dal mio LAB?\p"
	.string "A dopo!$"

BlackThornCity_EventScript_Sage::
	lock
	faceplayer
	goto_if_eq VAR_BLACKTHORN_CITY_STATE, 1, BlackThornCity_EventScript_SageRefuse
	msgbox BlackthornGrampsGrantsEntryText, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackThornCity_EventScript_SageRefuse::
	msgbox BlackthornGrampsRefusesEntryText, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackThornCity_Trigger_Sage::
	lock
	turnobject LOCALID_BLACKTHORN_SAGE, DIR_EAST
	msgbox BlackthornGrampsRefusesEntryText, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER Common_Movement_WalkDown1
	waitmovement 0
	turnobject LOCALID_BLACKTHORN_SAGE, DIR_SOUTH
	release
	end

BlackthornCity_EventScript_GymBoy::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE05_GET, BlackThornCity_EventScript_GymBoyNotReady
	goto_if_unset FLAG_BADGE06_GET, BlackThornCity_EventScript_GymBoyNotReady
	goto_if_unset FLAG_BADGE07_GET, BlackThornCity_EventScript_GymBoyNotReady
	goto_if_eq VAR_BLACKTHORN_CITY_STATE, 1, BlackThornCity_EventScript_GymBoyBefore
	msgbox BlackthornCity_Text_ClairIsBeaten, MSGBOX_DEFAULT
	closemessage
	release
	end	

BlackThornCity_EventScript_GymBoyNotReady::
	msgbox BlackthornCity_Text_ClairNotReady, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackThornCity_EventScript_GymBoyBefore::
	msgbox BlackthornCity_Text_ClairIsIn, MSGBOX_DEFAULT
	closemessage
	release
	end	

BlackthornCity_EventScript_BlackBelt::
	msgbox BlackBeltText_VoicesInMyHead, MSGBOX_NPC
	end

BlackthornCity_EventScript_CoolTrainerF::
	msgbox BlackthornCooltrainerF1Text, MSGBOX_NPC
	end

BlackthornCity_EventScript_Youngster::
	msgbox BlackthornYoungsterText, MSGBOX_NPC
	end

BlackthornCity_EventScript_CoolTrainerF2::
	msgbox BlackthornCooltrainerF2Text, MSGBOX_NPC
	end

BlackthornCity_EventScript_CitySign::
	msgbox BlackthornCitySignText, MSGBOX_SIGN
	end

BlackthornCity_EventScript_GymSign::
	msgbox BlackthornGymSignText, MSGBOX_SIGN
	end

BlackthornCity_EventScript_MoveHouseSign::
	msgbox BlackthornCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

BlackthornCity_EventScript_DragonsDenSign::
	msgbox BlackthornCity_Text_DragonDenSign, MSGBOX_SIGN
	end

BlackthornCity_EventScript_Santos::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SPELL_TAG, BlackthornCity_EventScript_SantosCompleted
	msgbox BlackthornCity_MeetSantosText, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, BlackthornCity_EventScript_SantosNope
	case 1, BlackthornCity_EventScript_SantosNope
	case 2, BlackthornCity_EventScript_SantosNope
	case 3, BlackthornCity_EventScript_SantosNope
	case 4, BlackthornCity_EventScript_SantosNope
	case 5, BlackthornCity_EventScript_SantosNope
	case 6, BlackthornCity_EventScript_SantosYes
	case 7 BlackthornCity_EventScript_SantosCancel
	case MULTI_B_PRESSED, BlackthornCity_EventScript_SantosCancel
	closemessage
	release
	end
BlackthornCity_EventScript_SantosYes::
	msgbox BlackthornCity_SantosGivesGiftText, MSGBOX_DEFAULT
	giveitem ITEM_SPELL_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_SPELL_TAG
	msgbox BlackthornCity_SantosGaveGiftText, MSGBOX_DEFAULT
	closemessage
	release
	end
BlackthornCity_EventScript_SantosNope::
	msgbox BlackthornCity_SantosNopeText, MSGBOX_DEFAULT
	closemessage
	release
	end
BlackthornCity_EventScript_SantosCancel::
	closemessage
	release
	end
BlackthornCity_EventScript_SantosCompleted::
	msgbox BlackthornCity_SantosSaturdayText, MSGBOX_DEFAULT
	closemessage
	release
	end


BlackthornCity_Text_ClairNotReady:
	.string "CLAIR, la nostra CAPOPALESTRA,\n"
	.string "segue i tuoi progressi.\p"
	.string "Però affronta solo chi ha\n"
	.string "già 7 medaglie.$"

BlackthornCity_Text_ClairIsIn:
	.string "CLAIR, la nostra CAPOPALESTRA ti\n"
	.string "aspetta.\p"
	.string "Ma per un allenatore qualunque\n"
	.string "vincere è impossibile.$"

BlackthornCity_Text_ClairIsBeaten:
	.string "Hai battuto CLAIR?\p"
	.string "È incredibile!\p"
	.string "Non ho mai sentito che perdesse\n"
	.string "con altri tranne LANCE.$"

BlackthornGrampsRefusesEntryText:
	.string "No. Solo allenatori scelti\n"
	.string "qui.\p"
	.string "Esci.$"

BlackthornGrampsGrantsEntryText:
	.string "Se CLAIR acconsente, anche\n"
	.string "nostro MAESTRO lo permetterà.\p"
	.string "Puoi entrare.$"

BlackBeltText_VoicesInMyHead:
	.string "Arooo! Voci in testa!\p"
	.string "Eh? Stavo ascoltando la radio!$"

BlackthornCooltrainerF1Text:
	.string "Vuoi far ricordare al tuo POKéMON\n"
	.string "qualche mossa?$"

BlackthornYoungsterText:
	.string "I maestri dei Draghi vengono tutti\n"
	.string "da FIORDORATO.$"

BlackthornCity_MeetSantosText:
	.string "SANTOS: …\p"
	.string "Sono SANTOS della famiglia dei\p"
	.string "giorni. Indovina.$"

BlackthornCity_SantosGivesGiftText:
	.string "Prendi questo…$"

BlackthornCity_SantosGaveGiftText:
	.string "SANTOS: …\p"
	.string "SPELL TAG…\p"
	.string "Le mosse di tipo SPETTRO sono\p"
	.string "più forti… Fa paura…$"

BlackthornCity_SantosSaturdayText:
	.string "SANTOS: …\p"
	.string "Ci vediamo a un altro sabato…\p"
	.string "Non avrò altri regali…$"

BlackthornCity_SantosNopeText:
	.string "SANTOS: No.$"

BlackthornCooltrainerF2Text:
	.string "Wow, dalla GROTTA GHIACCIO?\p"
	.string "Devi essere un allenatore tosto!$"

BlackthornCitySignText:
	.string "BLACKTHORN CITY\p"
	.string "Oasi quieta di montagna$"

BlackthornGymSignText:
	.string "PALESTRA POKéMON DI FIORDORATO\n"
	.string "CAPO: CLAIR\p"
	.string "Donna prescelta dai POKéMON DRAGO$"

BlackthornCity_Text_MoveDeletersHouseSign:
	.string "CASA DELLE MOSSE$"

BlackthornCity_Text_DragonDenSign:
	.string "GROTTA DEL DRAGO$"

