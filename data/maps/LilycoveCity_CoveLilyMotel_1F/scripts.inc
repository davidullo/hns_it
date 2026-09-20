LilycoveCity_CoveLilyMotel_1F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_1F_EventScript_MotelOwner::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_BlockingTV::
	lockall
	playse SE_PIN
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV
	applymovement LOCALID_MOTEL_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer
	waitmovement 0
	applymovement LOCALID_MOTEL_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn
	waitmovement 0
	release
	end

LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer:
	walk_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn:
	face_down
	walk_down
	face_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot:
	.string "Hm, quindi hanno raddoppiato gli\n"
	.string "ospiti usando i POKéMON?\p"
	.string "Hm, forse dovrei fare di un bel\n"
	.string "POKéMON la mascotte del motel.\p"
	.string "Chissà se attirerebbe più\n"
	.string "ospiti da noi?$"

LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua:
	.string "Oh, scusa, scusa!\n"
	.string "Ero preso dalla TV!\p"
	.string "Da quando il TEAM AQUA è in città,\n"
	.string "i turisti se ne stanno lontani.$"

LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV:
	.string "Ehi, spostati!\n"
	.string "Non vedo la TV!$"

LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem:
	.string "Incredibile! Un POKéMON ha\n"
	.string "trovato l'oggetto perso da qualcuno?\p"
	.string "Mica male. Con dei POKéMON\n"
	.string "intelligenti così…\p"
	.string "potremmo recuperare tutto ciò\n"
	.string "che perdono i nostri ospiti.$"

LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted:
	.string "Oh, scusa, scusa!\n"
	.string "Ero preso dalla TV!\p"
	.string "Ho sentito che qualcuno ha\n"
	.string "scoperto il NASCONDIGLIO TEAM AQUA.\p"
	.string "Per questo ci è arrivata\n"
	.string "la prenotazione di un gruppo.\p"
	.string "Era una ditta chiamata… Uh…\n"
	.string "GAME qualcosa…$"

LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar:
	.string "Incredibile! Un POKéMON che\n"
	.string "custodiva una casa ha preso un ladro?\p"
	.string "Mica male. Con un POKéMON forte\n"
	.string "come guardia giurata…\p"
	.string "potremmo dare ai nostri ospiti\n"
	.string "più sicurezza.$"

LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner:
	.string "Oh, scusa, scusa!\n"
	.string "Ero preso dalla TV.\p"
	.string "Ah, sì. Un bel gruppo di ospiti è\n"
	.string "arrivato poco fa.\p"
	.string "Hanno prenotato come GAME FREAK,\n"
	.string "quindi faranno dei giochi.\p"
	.string "Uh, meglio che prepari\n"
	.string "la loro cena!$"

