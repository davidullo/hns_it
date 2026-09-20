SSAqua_RoomNE_hns_MapScripts::
	.byte 0

SSAqua_RoomNE_EventScript_Noland::
	trainerbattle_single TRAINER_NOLAND_HNS, SSAqua_RoomNE_Text_HikerNolandSeen, SSAqua_RoomNE_Text_HikerNolandBeaten
	msgbox SSAqua_RoomNE_Text_HikerNolandAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNE_EventScript_Ethan::
	trainerbattle_single TRAINER_ETHAN_HNS, SSAqua_RoomNE_Text_PokemaniacEthanSeen, SSAqua_RoomNE_Text_PokemaniacEthanBeaten
	msgbox SSAqua_RoomNE_Text_PokemaniacEthanAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNE_Text_HikerNolandSeen:
    .string "Sei da solo?\n"
    .string "Allora lottiamo!$"

SSAqua_RoomNE_Text_HikerNolandBeaten:
    .string "È troppo per me!$"

SSAqua_RoomNE_Text_HikerNolandAfterBattle:
    .string "Chissà se a KANTO ci sono\n"
    .string "montagne che vale la pena scalare?$"

SSAqua_RoomNE_Text_PokemaniacEthanSeen:
    .string "Conosci LILY?\n"
    .string "È una DJ famosa a KANTO.$"

SSAqua_RoomNE_Text_PokemaniacEthanBeaten:
    .string "Gyaaah!$"

SSAqua_RoomNE_Text_PokemaniacEthanAfterBattle:
    .string "LILY è brava, ma\n"
    .string "MARY è la migliore!\n"
    .string "Voglio sentire\n"
    .string "i programmi radio\n"
    .string "di JOHTO!$"
