CeruleanCity_House2_Frlg_MapScripts::
	.byte 0

CeruleanCity_House2_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM28_FROM_ROCKET, CeruleanCity_House2_EventScript_HikerGotTM28
	msgbox CeruleanCity_House2_Text_RocketsStoleTMForDig
	release
	end

CeruleanCity_House2_EventScript_HikerGotTM28::
	msgbox CeruleanCity_House2_Text_TeachDiglettDigWithoutTM
	release
	end

CeruleanCity_House2_EventScript_Lass::
	msgbox CeruleanCity_House2_Text_TeamRocketTryingToDigIntoNoGood, MSGBOX_NPC
	end

CeruleanCity_House2_EventScript_WallHole::
	msgbox CeruleanCity_House2_Text_TeamRocketLeftWayOut, MSGBOX_SIGN
	end

CeruleanCity_House2_Text_RocketsStoleTMForDig::
	.string "Quei maledetti ROCKET!\p"
	.string "Guarda cosa hanno fatto a\n"
	.string "casa!\p"
	.string "Hanno rubato una MT che\n"
	.string "insegna FOSSA ai POKéMON!\p"
	.string "Volevo usarla su un\n"
	.string "MANKEY o SANDSHREW…\p"
	.string "Mi è costata un bel po'!$"

CeruleanCity_House2_Text_TeachDiglettDigWithoutTM::
	.string "Quel che è perso è perso.\p"
	.string "Ho deciso di insegnare a DIGLETT\n"
	.string "Fossa senza MT.$"

CeruleanCity_House2_Text_TeamRocketTryingToDigIntoNoGood::
	.string "TEAM ROCKET vuole usare Fossa\n"
	.string "per fini loschi!$"

CeruleanCity_House2_Text_TeamRocketLeftWayOut::
	.string "Un varco del TEAM ROCKET!$"

