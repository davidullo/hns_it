CeladonCity_Apartments_3F_hns_MapScripts::
	.byte 0

CeladonCity_Apartments_3F_EventScript_Sign::
	msgbox CeladonMansion3F_Text_DevRoomSign, MSGBOX_SIGN
	end

CeladonCity_Apartments_3F_EventScript_Programmer::
	msgbox GameFreak_Text_Programmer, MSGBOX_NPC
	end

CeladonCity_Apartments_3F_EventScript_GraphicArtist::
	msgbox GameFreak_Text_GraphicArtist, MSGBOX_NPC
	end

CeladonCity_Apartments_3F_EventScript_Program::
	msgbox CeladonMansion3F_Text_GameProgram, MSGBOX_SIGN
	end

CeladonCity_Apartments_3F_EventScript_Picture::
	msgbox CeladonMansion3F_Text_Drawing, MSGBOX_SIGN
	end

CeladonCity_Apartments_3F_EventScript_CharacterDesigner::
	msgbox GameFreak_Text_CharacterDesigner, MSGBOX_NPC
	end

GameFreak_Text_GameDesigner:
	.string "È così?\p"
	.string "Sono il GAME DESIGNER!\p"
	.string "Completare il POKéDEX è dura,\n"
	.string "ma non mollare!$"

GameFreak_Text_GameDesignerCompletedPokedex:
	.string "Wow! Perfetto! Hai completato\n"
	.string "il tuo POKéDEX!\p"
	.string "Congratulazioni!$"

GameFreak_Text_GraphicArtist:
	.string "Sono la GRAPHIC ARTIST.\p"
	.string "Ti ho disegnato io!$"

GameFreak_Text_GraphicArtistPrintDiploma:
	.string "Sono la GRAPHIC ARTIST.\p"
	.string "Hai completato il POKéDEX?\p"
	.string "Vuoi che ti stampi\n"
	.string "il DIPLOMA?$"

GameFreak_Text_GraphicArtistRefused:
	.string "Avvisami se vuoi il\n"
	.string "tuo DIPLOMA stampato.$"

GameFreak_Text_GraphicArtistError:
	.string "Qualcosa non va. Devo\n"
	.string "annullare la stampa.$"

GameFreak_Text_Programmer:
	.string "Io? Sono il PROGRAMMER.\p"
	.string "Gioca alle slot machine!$"

GameFreak_Text_CharacterDesigner:
	.string "Non sono adorabili le GEMELLE?\p"
	.string "Anche JASMINE è carina.\p"
	.string "Adoro entrambe!$"

CeladonMansion3F_Text_DevRoomSign:
	.string "STANZA DI SVILUPPO GAME FREAK$"

CeladonMansion3F_Text_Drawing:
	.string "È un disegno dettagliato\n"
	.string "di una bella ragazza.$"

CeladonMansion3F_Text_GameProgram:
	.string "È il programma del gioco.\n"
	.string "Smanettarci può creare un bug\n"
	.string "nel gioco!$"

CeladonMansion3F_Text_ReferenceMaterial:
	.string "È pieno di materiale\n"
	.string "di riferimento. C'è pure\n"
	.string "un POKé DOLL.$"
