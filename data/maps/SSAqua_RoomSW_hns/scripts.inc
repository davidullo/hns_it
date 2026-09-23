SSAqua_RoomSW_hns_MapScripts::
	.byte 0

SSAqua_RoomSW_EventScript_Cassie::
	trainerbattle_single TRAINER_CASSIE_HNS, SSAqua_RoomSW_Text_BeautyCassieSeen, SSAqua_RoomSW_Text_BeautyCassieBeaten
	msgbox SSAqua_RoomSW_Text_BeautyCassieAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSW_EventScript_Clyde::
	trainerbattle_single TRAINER_CLYDE_HNS, SSAqua_RoomSW_Text_GuitaristClydeSeen, SSAqua_RoomSW_Text_GuitaristClydeBeaten
	msgbox SSAqua_RoomSW_Text_GuitaristClydeAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSW_Text_BeautyCassieSeen:
    .string "Cerco di dimenticare i miei guai.\n"
    .string "Lottiamo!$"

SSAqua_RoomSW_Text_BeautyCassieBeaten:
    .string "Il mio cuore piange…$"

SSAqua_RoomSW_Text_BeautyCassieAfterBattle:
    .string "Un viaggio è l'ideale per guarire\n"
    .string "un cuore spezzato.\p"
    .string "Ma su un FAST SHIP si sta troppo poco\n"
    .string "per soffrire.$"

SSAqua_RoomSW_Text_GuitaristClydeSeen:
    .string "Vado a far sentire le mie canzoni\n"
    .string "alla RADIO di FIORDOROPOLI.$"

SSAqua_RoomSW_Text_GuitaristClydeBeaten:
    .string "Uau! Distorsione totale!$"

SSAqua_RoomSW_Text_GuitaristClydeAfterBattleMobile:
    .string "Dovevo debuttare alla\n"
    .string "TORRE LOTTA…\p"
    .string "Meglio tornare ad ARANCIOPOLI e\n"
    .string "riprendere l'allenamento…$"

SSAqua_RoomSW_Text_GuitaristClydeAfterBattle:
    .string "Parlando della RADIO,\n"
    .string "qual è il numero fortunato?$"
