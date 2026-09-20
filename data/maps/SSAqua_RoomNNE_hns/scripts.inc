SSAqua_RoomNNE_hns_MapScripts::
	.byte 0

SSAqua_RoomNNE_EventScript_Sean::
	trainerbattle_single TRAINER_SEAN_HNS, SSAqua_RoomNNE_Text_CooltrainermSeanSeen, SSAqua_RoomNNE_Text_CooltrainermSeanBeaten
	msgbox SSAqua_RoomNNE_Text_CooltrainermSeanAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNNE_EventScript_Carol::
	trainerbattle_single TRAINER_CAROL_HNS, SSAqua_RoomNNE_Text_CooltrainerfCarolSeen, SSAqua_RoomNNE_Text_CooltrainerfCarolBeaten
	msgbox SSAqua_RoomNNE_Text_CooltrainerfCarolAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNNE_Text_CooltrainermSeanSeen:
    .string "Vado a KANTO\n"
    .string "a mettermi alla prova.$"

SSAqua_RoomNNE_Text_CooltrainermSeanBeaten:
    .string "Volevo vincere!$"

SSAqua_RoomNNE_Text_CooltrainermSeanAfterBattle:
    .string "Gli allenatori di JOHTO\n"
    .string "possono sfidare i\l"
    .string "CAPOPALESTRA di KANTO.$"

SSAqua_RoomNNE_Text_CooltrainerfCarolSeen:
    .string "Mi alleno per\n"
    .string "diventare CAMPIONESSA!$"

SSAqua_RoomNNE_Text_CooltrainerfCarolBeaten:
    .string "Cosa ci rende\n"
    .string "così diverse?$"

SSAqua_RoomNNE_Text_CooltrainerfCarolAfterBattle:
    .string "Ti batterò\n"
    .string "un giorno!$"
