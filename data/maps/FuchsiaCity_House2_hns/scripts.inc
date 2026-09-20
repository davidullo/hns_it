FuchsiaCity_House2_hns_MapScripts::
	.byte 0

FuchsiaCity_House2_EventScript_Granddaughter::	
	goto_if_set FLAG_TEMP_1, FuchsiaCity_House2_EventScript_Granddaughter2
	msgbox FuchsiaCity_House2_Text_WardensGranddaughter1, MSGBOX_NPC
	setflag FLAG_TEMP_1
	end

FuchsiaCity_House2_EventScript_Granddaughter2::
	msgbox FuchsiaCity_House2_Text_WardensGranddaughter2, MSGBOX_NPC
	end

FuchsiaCity_House2_EventScript_Photo::
	msgbox FuchsiaCity_House2_Text_WardenPhoto, MSGBOX_NPC
	end

FuchsiaCity_House2_Text_WardensGranddaughter1:
	.string "Mio nonno è il GUARDIANO del\n"
	.string "SAFARI ZONE.\p"
	.string "Almeno lo era…\p"
	.string "Ha deciso di andare in vacanza e\n"
	.string "partire da solo oltreoceano.\p"
	.string "Ha mollato il SAFARI ZONE così,\n"
	.string "e basta.$"

FuchsiaCity_House2_Text_WardensGranddaughter2:
	.string "Molti erano delusi dalla chiusura\n"
	.string "del SAFARI ZONE, ma il nonno\l"
	.string "è testardo…$"

FuchsiaCity_House2_Text_WardenPhoto:
	.string "È la foto di un vecchio sorridente\n"
	.string "circondato dai POKéMON.$"

FuchsiaCity_House2_Text_SafariZonePhoto:
	.string "È la foto di una grande prateria\n"
	.string "con rari POKéMON che giocano.$"
