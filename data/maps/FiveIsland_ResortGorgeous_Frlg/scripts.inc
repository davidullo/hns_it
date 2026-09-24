FiveIsland_ResortGorgeous_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FiveIsland_ResortGorgeous_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FiveIsland_ResortGorgeous_OnFrame
	.byte 0

FiveIsland_ResortGorgeous_OnWarp::
	map_script_2 VAR_MAP_SCENE_FIVE_ISLAND_RESORT_GORGEOUS, 1, FiveIsland_ResortGorgeous_EventScript_TurnPlayerNorth
	.2byte 0

FiveIsland_ResortGorgeous_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

FiveIsland_ResortGorgeous_OnFrame::
	map_script_2 VAR_MAP_SCENE_FIVE_ISLAND_RESORT_GORGEOUS, 1, FiveIsland_ResortGorgeous_EventScript_SelphyReturnHomeScene
	.2byte 0

FiveIsland_ResortGorgeous_EventScript_SelphyReturnHomeScene::
	lockall
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox FiveIsland_ResortGorgeous_Text_SelphyThanksYouMayGoNow
	closemessage
	applymovement LOCALID_RESORT_GORGEOUS_SELPHY, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 39, 8
	waitdooranim
	applymovement LOCALID_RESORT_GORGEOUS_SELPHY, FiveIsland_ResortGorgeous_Movement_SelphyEnterHome
	waitmovement 0
	closedoor 39, 8
	waitdooranim
	removeobject LOCALID_RESORT_GORGEOUS_SELPHY
	clearflag FLAG_HIDE_RESORT_GORGEOUS_INSIDE_SELPHY
	setvar VAR_MAP_SCENE_FIVE_ISLAND_RESORT_GORGEOUS, 2
	releaseall
	end

FiveIsland_ResortGorgeous_Movement_SelphyEnterHome::
	walk_up
	set_invisible
	step_end

FiveIsland_ResortGorgeous_EventScript_SelphysHouseSign::
	msgbox FiveIsland_ResortGorgeous_Text_SelphysHouse, MSGBOX_SIGN
	end

FiveIsland_ResortGorgeous_Text_DaisyIntro::
	.string "Con queste mani creerò\n"
	.string "vittoria!$"

FiveIsland_ResortGorgeous_Text_DaisyDefeat::
	.string "Che vergogna…\n"
	.string "Che imbarazzo…$"

FiveIsland_ResortGorgeous_Text_DaisyPostBattle::
	.string "Oh no, i tubi di colore\n"
	.string "son tutti sparsi!$"

FiveIsland_ResortGorgeous_Text_CelinaIntro::
	.string "Scusi!\n"
	.string "Sto dipingendo.\l"
	.string "Non ti voglio vedere!$"

FiveIsland_ResortGorgeous_Text_CelinaDefeat::
	.string "Ho perso…\n"
	.string "Mi sento svenire…$"

FiveIsland_ResortGorgeous_Text_CelinaPostBattle::
	.string "GIANNA?\n"
	.string "Inclina un po' la testa…\l"
	.string "Ecco! È l'aria che voglio!$"

FiveIsland_ResortGorgeous_Text_RaynaIntro::
	.string "Mm…\n"
	.string "L'angolo non è proprio giusto…$"

FiveIsland_ResortGorgeous_Text_RaynaDefeat::
	.string "Oh…\n"
	.string "I miei sentimenti son blu…$"

FiveIsland_ResortGorgeous_Text_RaynaPostBattle::
	.string "Il cielo e il mare…\n"
	.string "Sono mutevoli.\p"
	.string "I loro volti sempre diversi\n"
	.string "son difficili da cogliere.$"

FiveIsland_ResortGorgeous_Text_JackiIntro::
	.string "Visito la villa di un'amica,\n"
	.string "se devi saperlo.$"

FiveIsland_ResortGorgeous_Text_JackiDefeat::
	.string "Oh, che forza!$"

FiveIsland_ResortGorgeous_Text_JackiPostBattle::
	.string "Trovo piacevole combattere\n"
	.string "nella gentile brezza marina.$"

FiveIsland_ResortGorgeous_Text_GillianIntro::
	.string "Penso di farmi fare una\n"
	.string "piscina per i POKéMON.$"

FiveIsland_ResortGorgeous_Text_GillianDefeat::
	.string "Oh, santo cielo!$"

FiveIsland_ResortGorgeous_Text_GillianPostBattle::
	.string "La piscina va bene, ma\n"
	.string "un solarium è sublime.$"

FiveIsland_ResortGorgeous_Text_DestinIntro::
	.string "So correre bene.\n"
	.string "Che velocità!$"

FiveIsland_ResortGorgeous_Text_DestinDefeat::
	.string "Ops!\n"
	.string "Ho avuto fretta!$"

FiveIsland_ResortGorgeous_Text_DestinPostBattle::
	.string "Quando corro col vento, mi\n"
	.string "sembra volare!$"

FiveIsland_ResortGorgeous_Text_TobyIntro::
	.string "La vita marina di questo\n"
	.string "resort mi fa proprio bene.$"

FiveIsland_ResortGorgeous_Text_TobyDefeat::
	.string "Che sorpresa!\n"
	.string "Stai scherzando.$"

FiveIsland_ResortGorgeous_Text_TobyPostBattle::
	.string "Ti prendi troppo sul serio…\n"
	.string "Che assurdità.$"

FiveIsland_ResortGorgeous_Text_SelphyThanksYouMayGoNow::
	.string "NOIANNA: Grazie.\p"
	.string "Puoi andare.$"

FiveIsland_ResortGorgeous_Text_SelphysHouse::
	.string "CASA NOIANNA$"

