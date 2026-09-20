PewterCity_House1_Frlg_MapScripts::
	.byte 0

PewterCity_House1_EventScript_BaldingMan::
	msgbox PewterCity_House1_Text_TradeMonsAreFinicky, MSGBOX_NPC
	end

PewterCity_House1_EventScript_LittleBoy::
	lock
	msgbox PewterCity_House1_Text_NidoranSit
	call PewterCity_House1_EventScript_DoNidoranCry
	release
	end

PewterCity_House1_EventScript_Nidoran::
	lock
	faceplayer
	call PewterCity_House1_EventScript_DoNidoranCry
	applymovement LOCALID_PEWTER_HOUSE_NIDORAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PewterCity_House1_EventScript_DoNidoranCry::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	waitse
	playmoncry SPECIES_NIDORAN_M, CRY_MODE_NORMAL
	msgbox PewterCity_House1_Text_Nidoran
	waitmoncry
	call EventScript_RestorePrevTextColor
	return

PewterCity_House1_Text_Nidoran::
	.string "NIDORAN♂: Bau bau!$"

PewterCity_House1_Text_NidoranSit::
	.string "NIDORAN, seduto!$"

PewterCity_House1_Text_TradeMonsAreFinicky::
	.string "Il nostro POKéMON è di scambio, quindi è\n"
	.string "capriccioso e difficile da gestire.\p"
	.string "Un POKéMON di scambio è quello che\n"
	.string "ottieni tramite uno scambio.\p"
	.string "Cresce in fretta, ma può ignorare un\n"
	.string "ALLENATORE inesperto in lotta.\p"
	.string "Se solo avessimo qualche MEDAGLIA…$"

