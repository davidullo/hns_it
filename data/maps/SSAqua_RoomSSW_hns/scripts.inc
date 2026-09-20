SSAqua_RoomSSW_hns_MapScripts::
	.byte 0

SSAqua_RoomSSW_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE_HNS, SSAqua_RoomSSW_Text_FirebreatherLyleSeen, SSAqua_RoomSSW_Text_FirebreatherLyleBeaten
	msgbox SSAqua_RoomSSW_Text_FirebreatherLyleAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSSW_EventScript_Ken::
	trainerbattle_single TRAINER_KEN_HNS, SSAqua_RoomSSW_Text_BugCatcherKenSeen, SSAqua_RoomSSW_Text_BugCatcherKenBeaten
	msgbox SSAqua_RoomSSW_Text_BugCatcherKenAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSSW_Text_FirebreatherLyleSeen:
    .string "Vado a KANTO a fare\n"
    .string "spettacoli di fuoco!$"

SSAqua_RoomSSW_Text_FirebreatherLyleBeaten:
    .string "Sfzzz… La fiamma è debole…$"

SSAqua_RoomSSW_Text_FirebreatherLyleAfterBattle:
    .string "Il fuoco è debole sul mare.\n"
    .string "Non importa? Davvero?$"

SSAqua_RoomSSW_Text_BugCatcherKenSeen:
    .string "Vado dalla nonna a\n"
    .string "prendere qualche insetto!$"

SSAqua_RoomSSW_Text_BugCatcherKenBeaten:
    .string "Ooh, caspita. Sei forte!$"

SSAqua_RoomSSW_Text_BugCatcherKenAfterBattle:
    .string "Trovi tanti POKéMON\n"
    .string "fra gli alberi di JOHTO!$"
