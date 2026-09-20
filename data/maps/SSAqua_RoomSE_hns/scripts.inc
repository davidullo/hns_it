SSAqua_RoomSE_hns_MapScripts::
	.byte 0

SSAqua_RoomSE_EventScript_Colin::
	trainerbattle_single TRAINER_COLIN_HNS, SSAqua_RoomSE_Text_PokefanmColinSeen, SSAqua_RoomSE_Text_PokefanmColinBeaten
	msgbox SSAqua_RoomSE_Text_PokefanmColinAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSE_EventScript_Meg::
	trainerbattle_double TRAINER_MEG_AND_PEG_HNS, SSAqua_RoomSE_Text_TwinsMegandpeg1Seen, SSAqua_RoomSE_Text_TwinsMegandpeg1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox SSAqua_RoomSE_Text_TwinsMegandpeg1After, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSE_EventScript_Peg::
	trainerbattle_double TRAINER_MEG_AND_PEG_HNS, SSAqua_RoomSE_Text_TwinsMegandpeg2Seen, SSAqua_RoomSE_Text_TwinsMegandpeg2Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox SSAqua_RoomSE_Text_TwinsMegandpeg2After, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSE_Text_PokefanmColinSeen:
    .string "Ehi, ragazzo! Vuoi lottare\n"
    .string "con me?$"

SSAqua_RoomSE_Text_PokefanmColinBeaten:
    .string "Sei forte!$"

SSAqua_RoomSE_Text_PokefanmColinAfter:
    .string "Viaggi tutto da solo?\n"
    .string "Tua mamma non è in pensiero?$"

SSAqua_RoomSE_Text_TwinsMegandpeg1Seen:
    .string "Mi credi una bebè?\n"
    .string "Non è giusto!$"

SSAqua_RoomSE_Text_TwinsMegandpeg1Beaten:
    .string "Oh! Abbiamo perso!$"

SSAqua_RoomSE_Text_TwinsMegandpeg1After:
    .string "Bebè è un nome offensivo\n"
    .string "per noi ragazze!$"

SSAqua_RoomSE_Text_TwinsMegandpeg2Seen:
    .string "Non sono una bebè!\n"
    .string "Non si dice a una signorina!$"

SSAqua_RoomSE_Text_TwinsMegandpeg2Beaten:
    .string "Oh! Abbiamo perso!$"

SSAqua_RoomSE_Text_TwinsMegandpeg2After:
    .string "A volte i bambini sono più\n"
    .string "svegli dei grandi!$"
