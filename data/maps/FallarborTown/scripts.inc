FallarborTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
	.byte 0

FallarborTown_OnTransition:
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	clearflag FLAG_CONTEST_SKETCH_CREATED
	end

FallarborTown_EventScript_ExpertM::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_EventScript_ExpertMNormal
	msgbox FallarborTown_Text_ShadyCharactersCozmosHome, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_ExpertMNormal::
	msgbox FallarborTown_Text_RegionKnownForMeteors, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_Girl::
	msgbox FallarborTown_Text_MyPreciousAzurill, MSGBOX_NPC
	end

FallarborTown_EventScript_Gentleman::
	msgbox FallarborTown_Text_HaveYouChallengedFlannery, MSGBOX_NPC
	end

FallarborTown_EventScript_Azurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox FallarborTown_Text_Azurill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_EventScript_BattleTentSign::
	msgbox FallarborTown_Text_BattleTentSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_TownSign::
	msgbox FallarborTown_Text_TownSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_MoveTutorSign::
	msgbox FallarborTown_Text_MoveTutorSign, MSGBOX_SIGN
	end

FallarborTown_Text_ShadyCharactersCozmosHome:
	.string "Succede qualcosa,\n"
	.string "e non mi piace!\p"
	.string "Ho visto tipi loschi girare\n"
	.string "attorno a casa del PROF. COZMO…$"

FallarborTown_Text_RegionKnownForMeteors:
	.string "La regione è nota per le meteore\n"
	.string "dai tempi antichi.\p"
	.string "Dicono che CASCATE METEORA fu\n"
	.string "scavata da un meteorite antico.$"

FallarborTown_Text_MyPreciousAzurill:
	.string "Guarda! Ammira!\n"
	.string "È il mio AZURILL adorato!\p"
	.string "È liscio, morbido e soffice!$"

FallarborTown_Text_Azurill:
	.string "AZURILL: Ruriluuu.$"

FallarborTown_Text_HaveYouChallengedFlannery:
	.string "Hai già sfidato FIAMMETTA,\n"
	.string "la CAPOPALESTRA di LAVARIDGE?\p"
	.string "Suo nonno era famoso.\n"
	.string "Faceva parte del SUPERQUATTRO\l"
	.string "della LEGA POKéMON.\p"
	.string "Non mi stupirei di vedere FIAMMETTA\n"
	.string "diventare una grande ALLENATRICE\l"
	.string "sola.$"

FallarborTown_Text_BattleTentSign:
	.string "TENDA LOTTA FALLARBOR\n"
	.string "“Che vincano i team migliori!”$"

FallarborTown_Text_TownSign:
	.string "FALLARBOR\n"
	.string "“Un paese agricolo con piccoli orti.”$"

FallarborTown_Text_MoveTutorSign:
	.string "CASA MAESTRO MOSSE\n"
	.string "“Nuove mosse per i POKéMON.”$"

