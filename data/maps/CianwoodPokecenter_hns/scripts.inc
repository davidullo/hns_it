CianwoodPokecenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CianwoodPokecenter_OnTransition
	.byte 0

CianwoodPokecenter_OnTransition::
	setrespawn HEAL_LOCATION_CIANWOOD_CITY_HNS
	end

CianwoodPokemoncenter_EventScript_Fisher::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_1, CianwoodPokemoncenter_EventScript_FisherNormal
	checkfieldmove FIELD_MOVE_SURF
	goto_if_eq VAR_RESULT, PARTY_SIZE, CianwoodPokemoncenter_EventScript_FisherGiveTentacool
CianwoodPokemoncenter_EventScript_FisherNormal::
	msgbox CianwoodPokemoncenter_Text_Fisher1, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodPokemoncenter_EventScript_FisherGiveTentacool::
	msgbox CianwoodPokemoncenter_Text_Fisher2, MSGBOX_DEFAULT
	@HnS gift pokemon setup
	@callnative DisableStaticRandomizer
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TENTACOOL
	bufferspeciesname STR_VAR_1, SPECIES_TENTACOOL
	givemon SPECIES_TENTACOOL, 25
	call Common_EventScript_GiftMon
	setflag FLAG_TEMP_1
	@callnative EnableStaticRandomizer
	closemessage
	release
	end

CianwoodPokemoncenter_Text_Fisher1:
	.string "Tra i POKéMON ACQUA,\n"
	.string "TENTACOOL è il migliore\l"
	.string "di gran lunga!$"

CianwoodPokemoncenter_Text_Fisher2:
	.string "Credo che ti serva un\n"
	.string "POKéMON.\p"
	.string "Tieni, prendi questo, ne ho tanti.$"

CianwoodPokecenter_EventScript_Lass::
	lock
	faceplayer
	msgbox CianwoodCity_Text_PokecenterLass, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_PokecenterLass:
	.string "Hai conosciuto il POKéMANIAC?\p"
	.string "Si vanta sempre dei suoi\n"
	.string "POKéMON rari.$"


CianwoodGym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, CianwoodGym_EventScript_GymGuideAfter
	msgbox CianwoodCity_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_EventScript_GymGuideAfter::
	msgbox CianwoodCity_Text_GymGuideWin, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_GymGuide:
	.string "Gli allenatori della PALESTRA POKéMON\n"
	.string "sono dei bulli macho.\p"
	.string "Se resto qui, potrebbero\n"
	.string "venire a prendermi.\p"
	.string "Un consiglio: il CAPOPALESTRA\n"
	.string "usa il tipo Lotta.\p"
	.string "Quindi confondilo con\n"
	.string "POKéMON psichici.\p"
	.string "Metti KO i suoi POKéMON prima\n"
	.string "che usino la loro forza fisica.\p"
	.string "E quei massi al centro\n"
	.string "della PALESTRA?\p"
	.string "Se non li sposti bene,\n"
	.string "non arriverai al CAPOPALESTRA.\p"
	.string "Se ti blocchi, vai fuori.$"

CianwoodCity_Text_GymGuideWin:
	.string "{PLAYER}! Hai vinto!\n"
	.string "Si vedeva dal tuo sguardo!$"

CianwoodPokecenter_EventScript_Nerd::
	lock
	faceplayer
	msgbox CianwoodCity_Text_PokecenterSuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_PokecenterSuperNerd:
	.string "I love showing off the POKéMON\n"
	.string "that I've raised.\p"
	.string "Don't you?\p"
	.string "I'm going to get into a bunch of\n"
	.string "battles, and show off my POKéMON!$"
