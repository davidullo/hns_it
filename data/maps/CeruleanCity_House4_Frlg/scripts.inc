.set REWARD_TYPE, VAR_0x8004
.set REWARD_ITEM, VAR_0x8008

CeruleanCity_House4_Frlg_MapScripts::
	.byte 0

CeruleanCity_House4_EventScript_WonderNewsBerryMan::
	lock
	specialvar REWARD_TYPE, WonderNews_GetRewardInfo
	copyvar REWARD_ITEM, VAR_RESULT
	goto_if_eq REWARD_TYPE, NEWS_REWARD_NONE,       CeruleanCity_House4_EventScript_NoNews
	goto_if_eq REWARD_TYPE, NEWS_REWARD_RECV_SMALL, CeruleanCity_House4_EventScript_Reward_RecvSmall
	goto_if_eq REWARD_TYPE, NEWS_REWARD_RECV_BIG,   CeruleanCity_House4_EventScript_Reward_RecvBig
	goto_if_eq REWARD_TYPE, NEWS_REWARD_WAITING,    CeruleanCity_House4_EventScript_Waiting
	goto_if_eq REWARD_TYPE, NEWS_REWARD_SENT_SMALL, CeruleanCity_House4_EventScript_Reward_SentSmall
	goto_if_eq REWARD_TYPE, NEWS_REWARD_SENT_BIG,   CeruleanCity_House4_EventScript_Reward_SentBig
	goto_if_eq REWARD_TYPE, NEWS_REWARD_AT_MAX,     CeruleanCity_House4_EventScript_AtMax
	end

@ Mystery Gift is not enabled, or the player has no saved Wonder News
CeruleanCity_House4_EventScript_NoNews::
	msgbox CeruleanCity_House4_Text_NothingEntertaining
	release
	end

@ Small reward for receiving Wonder News from friend
CeruleanCity_House4_EventScript_Reward_RecvSmall::
	call CeruleanCity_House4_EventScript_MovementReactionToNews
	msgbox CeruleanCity_House4_Text_NewNewsInformativeHaveThis
	giveitem REWARD_ITEM
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House4_EventScript_NoRoomForBerries
	release
	end

@ Big reward for receiving Wonder News from non-friend source
CeruleanCity_House4_EventScript_Reward_RecvBig::
	call CeruleanCity_House4_EventScript_MovementReactionToNews
	msgbox CeruleanCity_House4_Text_IncredibleNewsHaveBerries
	giveitem REWARD_ITEM, 4
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House4_EventScript_NoRoomForBerries
	release
	end

@ Player has not recently sent Wonder News
CeruleanCity_House4_EventScript_Waiting::
	applymovement LOCALID_WONDER_NEWS_BERRY_MAN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox CeruleanCity_House4_Text_WishCouldShareNewsWithOthers
	release
	end

@ Small reward for sending Wonder News every 1-3 times
CeruleanCity_House4_EventScript_Reward_SentSmall::
	call CeruleanCity_House4_EventScript_MovementReactionToNews
	msgbox CeruleanCity_House4_Text_ThanksForSpreadingNewsTakeThis
	giveitem REWARD_ITEM
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House4_EventScript_NoRoomForBerries
	release
	end

@ Big reward for sending Wonder News every 4th time
CeruleanCity_House4_EventScript_Reward_SentBig::
	call CeruleanCity_House4_EventScript_MovementReactionToNews
	msgbox CeruleanCity_House4_Text_MagnificentNewsSpreadHaveBerries
	giveitem REWARD_ITEM, 4
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House4_EventScript_NoRoomForBerries
	release
	end

@ Player has hit reward limit and must wait to receive new rewards
CeruleanCity_House4_EventScript_AtMax::
	applymovement LOCALID_WONDER_NEWS_BERRY_MAN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox CeruleanCity_House4_Text_EnjoyingMyselfWithAllSortsOfNews
	release
	end

CeruleanCity_House4_EventScript_MovementReactionToNews::
	playse SE_PIN
	applymovement LOCALID_WONDER_NEWS_BERRY_MAN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WONDER_NEWS_BERRY_MAN, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_WONDER_NEWS_BERRY_MAN, Common_Movement_Delay48
	waitmovement 0
	return

CeruleanCity_House4_EventScript_NoRoomForBerries::
	msgbox CeruleanCity_House4_Text_YourBerryPouchIsFull
	release
	end

CeruleanCity_House4_Text_NothingEntertaining::
	.string "Uff…\n"
	.string "Troppo tempo, poco da fare…\p"
	.string "Non succede nulla di bello\n"
	.string "in giro?$"

CeruleanCity_House4_Text_NewNewsInformativeHaveThis::
	.string "Ah!\n"
	.string "Notizia fresca!\p"
	.string "Mm…\p"
	.string "Ecco!\n"
	.string "Molto istruttivo!\p"
	.string "Ti ammiro per l'interesse\n"
	.string "per le notizie a quest'età.\p"
	.string "Come ringraziamento per avermi\n"
	.string "dato la notizia, prendi questo.$"

CeruleanCity_House4_Text_IncredibleNewsHaveBerries::
	.string "Oh!\n"
	.string "Questa notizia!\p"
	.string "Mm…\p"
	.string "Uau!\n"
	.string "Che notizia incredibile!\p"
	.string "Non vedevo una notizia così\n"
	.string "incredibile da troppo tempo!\p"
	.string "Grazie per aver condiviso questa\n"
	.string "notizia. Ecco delle BACCHE!$"

CeruleanCity_House4_Text_WishCouldShareNewsWithOthers::
	.string "Che peccato non poter condividere\n"
	.string "questa notizia con altri…\p"
	.string "Vorrei dirlo a qualcuno…\n"
	.string "Far sapere la notizia…$"

CeruleanCity_House4_Text_ThanksForSpreadingNewsTakeThis::
	.string "Ah, hai diffuso la notizia?\p"
	.string "Una buona notizia vale quando\n"
	.string "tutti la condividono.\p"
	.string "Come ringraziamento per averla\n"
	.string "diffusa, tieni qua!$"

CeruleanCity_House4_Text_MagnificentNewsSpreadHaveBerries::
	.string "Hai diffuso ancora la notizia?\n"
	.string "Magnifico!\p"
	.string "Quella notizia dev'essere\n"
	.string "felice di girare così tanto.\p"
	.string "Eh sì!\p"
	.string "È un segno di stima\n"
	.string "da me e dalla notizia.\p"
	.string "Ti darò più BACCHE del\n"
	.string "solito.$"

CeruleanCity_House4_Text_EnjoyingMyselfWithAllSortsOfNews::
	.string "Mi sto divertendo un sacco con\n"
	.string "le notizie.\p"
	.string "Sì, ne sono felice!\n"
	.string "Non mi annoierò per un po'.$"

CeruleanCity_House4_Text_YourBerryPouchIsFull::
	.string "Hm? La BORSABACCHE è piena.\n"
	.string "Allora il regalo resta mio.$"

