BattleFrontier_RankingHall_hns_MapScripts::
	.byte 0

BattleFrontier_RankingHall_EventScript_TowerSinglesRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_SINGLES
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_TowerDoublesRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_DOUBLES
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_TowerMultisRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_MULTIS
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_TowerLinkRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_LINK
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_ArenaRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_ARENA
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_PalaceRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_PALACE
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_FactoryRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_FACTORY
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_DomeRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_DOME
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_PikeRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_PIKE
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_PyramidRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_PYRAMID
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_ShowRecords_hns::
	special ShowRankingHallRecordsWindow
	waitbuttonpress
	special ScrollRankingHallRecordsWindow
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_RankingHall_EventScript_Attendant_hns::
	msgbox BattleFrontier_RankingHall_Text_ExplainRankingHall_hns, MSGBOX_NPC
	end

BattleFrontier_RankingHall_EventScript_DomePikeFactoryRecordsSign_hns::
	msgbox BattleFrontier_RankingHall_Text_DomePikeFactoryRecords_hns, MSGBOX_SIGN
	end

BattleFrontier_RankingHall_EventScript_PalaceArenaPyramidRecordsSIgn_hns::
	msgbox BattleFrontier_RankingHall_Text_PalaceArenaPyramidRecords_hns, MSGBOX_SIGN
	end

BattleFrontier_RankingHall_EventScript_NinjaBoy_hns::
	lock
	faceplayer
	msgbox BattleFrontier_RankingHall_Text_IsYourNameOnThisList_hns, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BattleFrontier_RankingHall_EventScript_NinjaBoy_hnsNameOnList_hns
	msgbox BattleFrontier_RankingHall_Text_WorkHarderIfYouSawFriendsName_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_RankingHall_EventScript_NinjaBoy_hnsNameOnList_hns::
	msgbox BattleFrontier_RankingHall_Text_WowThatsSuper_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_RankingHall_EventScript_Boy_hns::
	msgbox BattleFrontier_RankingHall_Text_MyNamesNotUpThere_hns, MSGBOX_NPC
	end

BattleFrontier_RankingHall_Text_ExplainRankingHall_hns:
	.string "È la SALA CLASSIFICA.\p"
	.string "Qui onoriamo gli immortali\n"
	.string "ALLENATORI con grandi record\l"
	.string "negli eventi della FRONTIERA.$"

BattleFrontier_RankingHall_Text_DomePikeFactoryRecords_hns:
	.string "DOMO LOTTA, LOTTA PIKE\n"
	.string "e FABBRICA LOTTA: Record$"

BattleFrontier_RankingHall_Text_PalaceArenaPyramidRecords_hns:
	.string "PALAZZO LOTTA, LOTTA ARENA\n"
	.string "e PIRAMIDE LOTTA: Record$"

BattleFrontier_RankingHall_Text_IsYourNameOnThisList_hns:
	.string "Ciao, sei in questa lista?$"

BattleFrontier_RankingHall_Text_WowThatsSuper_hns:
	.string "Wow, che forte!\n"
	.string "Anch'io mi impegnerò di più!$"

BattleFrontier_RankingHall_Text_WorkHarderIfYouSawFriendsName_hns:
	.string "Oh, davvero?\p"
	.string "Vedere il nome di un amico qui\n"
	.string "ti farebbe impegnare di più!$"

BattleFrontier_RankingHall_Text_MyNamesNotUpThere_hns:
	.string "Hmm…\n"
	.string "Il mio nome non c'è…\p"
	.string "Normale, visto che non ho\n"
	.string "fatto sfide ancora.$"

