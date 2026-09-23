CeladonCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_EventScript_CityEnter
	.byte 0

CeladonCity_EventScript_CityEnter::
	setflag FLAG_VISITED_CELADON_CITY
	end

CeladonCity_EventScript_Erika::
    lock
    faceplayer
    msgbox CeladonCity_Text_Erika, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_FOUNTAIN_ERIKA
    removeobject LOCALID_CELADON_ERIKA
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_ERIKA
    release
    end

CeladonCity_Text_Erika:
    .string "Oh, {PLAYER}.\n"
	.string "Che bella la fontana oggi!\p"
	.string "Se vuoi un'altra lotta,\n"
	.string "sono al DOJO DI LOTTA.$"

CeladonCity_EventScript_Fatman::
	msgbox CeladonCity_Text_Fisher, MSGBOX_NPC
	end
CeladonCity_EventScript_Poliwrath::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWRATH, CRY_MODE_NORMAL
	msgbox CeladonCity_Text_Poliwrath, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeladonCity_EventScript_Teacher1::
	msgbox CeladonCity_Text_Teacher1, MSGBOX_NPC
	end

CeladonCity_EventScript_GrimerGramps::
	msgbox CeladonCity_Text_Gramps1, MSGBOX_NPC
	end

CeladonCity_EventScript_CreepGramps::
	msgbox CeladonCity_Text_Gramps2, MSGBOX_NPC
	end

CeladonCity_EventScript_Youngster::
	msgbox CeladonCity_Text_Youngster1, MSGBOX_NPC
	end

CeladonCity_EventScript_Youngster2::
	msgbox CeladonCity_Text_Youngster2, MSGBOX_NPC
	end

CeladonCity_EventScript_Teacher2::
	msgbox CeladonCity_Text_Teacher2, MSGBOX_NPC
	end

CeladonCity_EventScript_Lass::
	msgbox CeladonCity_Text_Lass, MSGBOX_NPC
	end

CeladonCity_EventScript_Item_Recycle::
    finditem ITEM_TM_RECYCLE
    end

CeladonCity_Text_Fisher:
	.string "POLIWRATH è il mio partner.\p"
	.string "Chissà se si evolverà mai\n"
	.string "in un POKéMON rana.$"

CeladonCity_Text_Poliwrath:
	.string "POLIWRATH: Cra cra!$"

CeladonCity_Text_Teacher1:
	.string "Ho perso di nuovo alle slot…\p"
	.string "Ora anche noi giochiamo alle slot.\p"
	.string "Vai a provarle anche tu.$"

CeladonCity_Text_Gramps1:
	.string "Ultimamente appaiono GRIMER.\p"
	.string "Vedi quello stagno davanti\n"
	.string "casa? Ora ci vivono i GRIMER.\p"
	.string "Da dove vengono? È un\n"
	.string "problema serio…$"

CeladonCity_Text_Gramps2:
	.string "Nihihi! Che bella PALESTRA!\n"
	.string "Qui solo ragazze!$"

CeladonCity_Text_Youngster1:
	.string "Vuoi sapere un segreto?\p"
	.string "La VILLA AZZURROPOLI ha una porta\n"
	.string "sul retro.$"

CeladonCity_Text_Youngster2:
	.string "Fanno una gara di abbuffata\n"
	.string "al ristorante.\p"
	.string "Solo a guardarli mi sento\n"
	.string "già pieno…$"

CeladonCity_Text_Teacher2:
	.string "Il GR. MAGAZZINI AZZURROPOLI ha\n"
	.string "la scelta più vasta che c'è.\p"
	.string "Se non lo trovi lì, non lo\n"
	.string "trovi da nessuna parte.\p"
	.string "Caspita… sembro una commessa.$"

CeladonCity_Text_Lass:
	.string "Guardare per terra mentre\n"
	.string "cammino mi gira la testa.$"

CeladonCity_EventScript_CitySign::
	msgbox CeladonCity_Text_Sign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GymSign::
	msgbox CeladonGym_Text_Sign, MSGBOX_SIGN
	end

CeladonCity_EventScript_StoreSign::
	msgbox CeladonCity_Text_DeptStoreSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_MansionSign::
	msgbox CeladonCity_Text_MansionSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GameCornerSign::
	msgbox CeladonCity_Text_GameCornerSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_TrainerTips::
	msgbox CeladonCity_Text_TrainerTips, MSGBOX_SIGN
	end

CeladonCity_Text_Sign:
	.string "AZZURROPOLI\p"
	.string "Città dei sogni arcobaleno$"

CeladonGym_Text_Sign:
	.string "CAPOPALESTRA DI AZZURROPOLI:\n"
	.string "ERIKA\p"
	.string "Principessa della natura$"

CeladonCity_Text_DeptStoreSign:
	.string "Trovi quel che cerchi al\n"
	.string "GR. MAGAZZINI AZZURROPOLI!$"

CeladonCity_Text_MansionSign:
	.string "VILLA AZZURROPOLI$"

CeladonCity_Text_GameCornerSign:
	.string "Il parco giochi per tutti\n"
	.string "SALA GIOCHI AZZURROPOLI$"

CeladonCity_Text_TrainerTips:
	.string "CONSIGLI UTILI\p"
	.string "ANTIDIFESA protegge i POKéMON\n"
	.string "dalle mosse speciali come\l"
	.string "LANCIAFIAMME e SURF.\p"
	.string "Trovi tutto al GR. MAGAZZINI\n"
	.string "AZZURROPOLI!$"
