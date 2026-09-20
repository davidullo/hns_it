LilycoveCity_PokemonCenter_1F_EventScript_LilycoveLady::
	special Script_GetLilycoveLadyId
	switch VAR_RESULT
	case LILYCOVE_LADY_QUIZ, LilycoveCity_PokemonCenter_1F_EventScript_QuizLady
	case LILYCOVE_LADY_FAVOR, LilycoveCity_PokemonCenter_1F_EventScript_FavorLady
	case LILYCOVE_LADY_CONTEST, LilycoveCity_PokemonCenter_1F_EventScript_ContestLady
	end

LilycoveCity_PokemonCenter_1F_EventScript_FavorLady::
	lock
	faceplayer
	msgbox LilycoveCity_PokemonCenter_1F_Text_ImTheFavorLady, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetFavorLadyState
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_READY, LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyReady
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_COMPLETED, LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyCompleted
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_PRIZE, LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyPrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyCompleted::
	msgbox LilycoveCity_PokemonCenter_1F_Text_ThankYouForLastTime, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyReady::
	special BufferFavorLadyRequest
	msgbox LilycoveCity_PokemonCenter_1F_Text_ObsessedWithThing, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasAnotherPlayerGivenFavorLadyItem
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_RequestItem
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_TellAboutPlayersItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_TellAboutPlayersItem::
	special BufferFavorLadyItemName
	special BufferFavorLadyPlayerName
	specialvar VAR_RESULT, DidFavorLadyLikeItem
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveBadThing
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveGreatThing
	end

LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveBadThing::
	msgbox LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeBadThing, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_RequestItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveGreatThing::
	msgbox LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeGreatThing, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_RequestItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_RequestItem::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WillYouShareThing, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_DeclineFavor
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_AcceptFavor
	end

LilycoveCity_PokemonCenter_1F_EventScript_DeclineFavor::
	msgbox LilycoveCity_PokemonCenter_1F_Text_IsThatSoGoodbye, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_AcceptFavor::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WhatWillYouGiveMe, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_ChooseFavorItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_ChooseFavorItem::
	fadescreen FADE_TO_BLACK
	setvar VAR_RESULT, 0
	special Script_FavorLadyOpenBagMenu
	waitstate
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChooseFavorItem
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_GiveFavorItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChooseFavorItem::
	msgbox LilycoveCity_PokemonCenter_1F_Text_NotWillingToShare, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_DeclineFavor
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_ChooseFavorItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_GiveFavorItem::
	specialvar VAR_RESULT, Script_DoesFavorLadyLikeItem
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_DidntLikeFavorItem
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_CheckLovedItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_DidntLikeFavorItem::
	special BufferFavorLadyRequest
	msgbox LilycoveCity_PokemonCenter_1F_Text_IllTryToCherishIt, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_CheckLovedItem::
	specialvar VAR_RESULT, IsFavorLadyThresholdMet
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_LikedFavorItem
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_LovedFavorItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_LikedFavorItem::
	special BufferFavorLadyRequest
	msgbox LilycoveCity_PokemonCenter_1F_Text_IWillCherishThis, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_LovedFavorItem::
	special BufferFavorLadyRequest
	msgbox LilycoveCity_PokemonCenter_1F_Text_IWillTreasureThis, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyPrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyPrize::
	setvar VAR_0x8004, 0
	specialvar VAR_0x8004, FavorLadyGetPrize
	msgbox LilycoveCity_PokemonCenter_1F_Text_IllGiveYouThisInReturn, MSGBOX_DEFAULT
	giveitem VAR_0x8004
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_NoRoomForFavorPrize
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_ReceivedFavorPrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_NoRoomForFavorPrize::
	msgbox LilycoveCity_PokemonCenter_1F_Text_YouDontHaveSpaceForIt, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_ReceivedFavorPrize::
	special SetFavorLadyState_Complete
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_QuizLady::
	lock
	faceplayer
	msgbox LilycoveCity_PokemonCenter_1F_Text_ImTheQuizLady, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetQuizLadyState
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_READY, LilycoveCity_PokemonCenter_1F_EventScript_HasQuiz
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_COMPLETED, LilycoveCity_PokemonCenter_1F_EventScript_CheckMadeQuiz
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_PRIZE, LilycoveCity_PokemonCenter_1F_EventScript_ReadyGivePrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_HasQuiz::
	specialvar VAR_RESULT, GetQuizAuthor
	goto_if_eq VAR_RESULT, QUIZ_AUTHOR_PLAYER, LilycoveCity_PokemonCenter_1F_EventScript_WaitingToTakeYourQuiz
	goto_if_eq VAR_RESULT, QUIZ_AUTHOR_OTHER_PLAYER, LilycoveCity_PokemonCenter_1F_EventScript_PlayerQuizReady
	goto_if_eq VAR_RESULT, QUIZ_AUTHOR_LADY, LilycoveCity_PokemonCenter_1F_EventScript_LadyQuizReady
	end

LilycoveCity_PokemonCenter_1F_EventScript_CheckMadeQuiz::
	specialvar VAR_RESULT, IsQuizLadyWaitingForChallenger
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_WaitingToTakeYourQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_WaitingToTakeYourQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WaitingToTakeYourQuiz, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_PlayerQuizReady::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WaitingForChallenger, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_AskTakeQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_LadyQuizReady::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WaitingForChallenger, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_AskTakeQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskTakeQuiz::
	setvar VAR_0x8004, 0
	msgbox LilycoveCity_PokemonCenter_1F_Text_TakeQuizChallenge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_TakeQuiz
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_DeclineQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_DeclineQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_HowBoringBye, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_TakeQuiz::
	special ClearQuizLadyPlayerAnswer
	goto_if_eq VAR_0x8004, 0, LilycoveCity_PokemonCenter_1F_EventScript_ShowQuestion
	goto_if_eq VAR_0x8004, EASY_CHAT_TYPE_QUIZ_ANSWER, LilycoveCity_PokemonCenter_1F_EventScript_GetAnswer

LilycoveCity_PokemonCenter_1F_EventScript_CheckQuizTakingState::
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_AskQuitQuiz
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_SubmitQuizResponse
	end

LilycoveCity_PokemonCenter_1F_EventScript_ShowQuestion::
	special QuizLadyShowQuizQuestion
	waitstate
	goto LilycoveCity_PokemonCenter_1F_EventScript_CheckQuizTakingState
	end

LilycoveCity_PokemonCenter_1F_EventScript_GetAnswer::
	special QuizLadyGetPlayerAnswer
	waitstate
	goto LilycoveCity_PokemonCenter_1F_EventScript_CheckQuizTakingState
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_YoureGoingToQuit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_QuitTakingQuiz
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_TakeQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_QuitTakingQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_TakeTheQuizAnotherTime, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_SubmitQuizResponse::
	special SetQuizLadyState_Complete
	msgbox LilycoveCity_PokemonCenter_1F_Text_WaitForAnswer, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsQuizAnswerCorrect
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_IncorrectResponse
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_CorrectResponse
	end

LilycoveCity_PokemonCenter_1F_EventScript_CorrectResponse::
	playse SE_SUCCESS
	delay 10
	playse SE_SUCCESS
	msgbox LilycoveCity_PokemonCenter_1F_Text_YouGotItRight, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_ReadyGivePrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_IncorrectResponse::
	special BufferQuizCorrectAnswer
	special BufferQuizPrizeName
	playse SE_FAILURE
	delay 10
	playse SE_FAILURE
	msgbox LilycoveCity_PokemonCenter_1F_Text_WrongTheCorrectAnswerIs, MSGBOX_DEFAULT
	msgbox LilycoveCity_PokemonCenter_1F_Text_IGetToKeepPrize, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz
	end

@ VAR_RESULT is essentially ignored, both jumps are identical
LilycoveCity_PokemonCenter_1F_EventScript_ReadyGivePrize::
	specialvar VAR_RESULT, BufferQuizAuthorNameAndCheckIfLady
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_GivePrize1
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_GivePrize0
	end

LilycoveCity_PokemonCenter_1F_EventScript_GivePrize1::
	msgbox LilycoveCity_PokemonCenter_1F_Text_YouGotItRightYouveWonPersonsPrize, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_GivePrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_GivePrize0::
	msgbox LilycoveCity_PokemonCenter_1F_Text_YouGotItRightYouveWonPersonsPrize, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_GivePrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_GivePrize::
	setvar VAR_0x8005, 0
	special BufferQuizPrizeItem
	special SetQuizLadyState_Complete
	giveitem VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_NoSpaceForQuizPrize
	goto LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_NoSpaceForQuizPrize::
	msgbox LilycoveCity_PokemonCenter_1F_Text_YourBagIsFilledUp, MSGBOX_DEFAULT
	special SetQuizLadyState_GivePrize
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_MakeYourOwnQuiz, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_MakeQuiz
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz::
	special QuizLadyPickNewQuestion
	msgbox LilycoveCity_PokemonCenter_1F_Text_MaybeNextTime, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_MakeQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_PickYourPrize, MSGBOX_DEFAULT
LilycoveCity_PokemonCenter_1F_EventScript_PickPrize::
	fadescreen FADE_TO_BLACK
	setvar VAR_RESULT, 0
	special Script_QuizLadyOpenBagMenu
	waitstate
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChoosingPrize
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_WriteQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChoosingPrize::
	msgbox LilycoveCity_PokemonCenter_1F_Text_QuitChoosingPrize, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_PickPrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_WriteQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WriteYourQuiz, MSGBOX_DEFAULT
	special ClearQuizLadyQuestionAndAnswer
	special ClearQuizLadyPlayerAnswer
	setvar VAR_0x8004, EASY_CHAT_TYPE_QUIZ_QUESTION
LilycoveCity_PokemonCenter_1F_EventScript_WriteQuizQuestion::
	fadescreen FADE_TO_BLACK
	special QuizLadySetCustomQuestion
	waitstate
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_AskQuitWritingQuizQuestion
	goto LilycoveCity_PokemonCenter_1F_EventScript_FinishMakingQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitWritingQuizQuestion::
	msgbox LilycoveCity_PokemonCenter_1F_Text_QuitWritingQuizQuestion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_WriteQuizQuestion
	end

LilycoveCity_PokemonCenter_1F_EventScript_FinishMakingQuiz::
	special QuizLadyTakePrizeForCustomQuiz
	special QuizLadyRecordCustomQuizData
	special QuizLadySetWaitingForChallenger
	msgbox LilycoveCity_PokemonCenter_1F_Text_IllLookForAChallenger, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_ContestLady::
	lock
	faceplayer
	msgbox LilycoveCity_PokemonCenter_1F_Text_ImTheContestLady, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasPlayerGivenContestLadyPokeblock
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_NotGivenPokeblock
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_GivenPokeblock
	end

@ Redundant with above script, VAR_RESULT will always be FALSE here
LilycoveCity_PokemonCenter_1F_EventScript_NotGivenPokeblock::
	specialvar VAR_RESULT, ShouldContestLadyShowGoOnAir
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_AskForPokeblock
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_GivenPokeblock
	end

LilycoveCity_PokemonCenter_1F_EventScript_GivenPokeblock::
	msgbox LilycoveCity_PokemonCenter_1F_Text_ThankForPokeblock, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskForPokeblock::
	special Script_BufferContestLadyCategoryAndMonName
	msgbox LilycoveCity_PokemonCenter_1F_Text_MyFriendDisplaysQuality, MSGBOX_DEFAULT
	checkitem ITEM_POKEBLOCK_CASE
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_NoPokeblockCase
	msgbox LilycoveCity_PokemonCenter_1F_Text_AskingForOnePokeblock, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_DeclineGivePokeblock
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_ChoosePokeblock
	end

LilycoveCity_PokemonCenter_1F_EventScript_DeclineGivePokeblock::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WhatACheapskate, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_ChoosePokeblock::
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseForContestLady
	waitstate
	goto_if_eq VAR_RESULT, 0xFFFF, LilycoveCity_PokemonCenter_1F_EventScript_AskQuitGivingPokeblock
	goto_if_ne VAR_RESULT, 0xFFFF, LilycoveCity_PokemonCenter_1F_EventScript_GivePokeblock
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitGivingPokeblock::
	msgbox LilycoveCity_PokemonCenter_1F_Text_ICantHaveOnePokeblock, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_DeclineGivePokeblock
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_ChoosePokeblock
	end

LilycoveCity_PokemonCenter_1F_EventScript_GivePokeblock::
	msgbox LilycoveCity_PokemonCenter_1F_Text_IllUseYourPokeblock, MSGBOX_DEFAULT
	special SetContestLadyGivenPokeblock
	special GetContestLadyMonSpecies
	goto LilycoveCity_PokemonCenter_1F_EventScript_FeedPokeblock
	end

@ VAR_0x8004 here is the return value from GivePokeblockToContestLady
LilycoveCity_PokemonCenter_1F_EventScript_FeedPokeblock::
	applymovement LOCALID_LILYCOVE_LADY, LilycoveCity_PokemonCenter_1F_Movement_LadyFaceMon
	waitmovement 0
	delay 60
	applymovement LOCALID_LILYCOVE_LADYS_MON, LilycoveCity_PokemonCenter_1F_Movement_MonFaceLady
	waitmovement 0
	delay 60
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	delay 120
	waitmoncry
	goto_if_eq VAR_0x8004, 1, LilycoveCity_PokemonCenter_1F_EventScript_MonEnjoyPokeblock
	goto LilycoveCity_PokemonCenter_1F_EventScript_FinishFeedPokeblock
	end

@ VAR_0x8004 here is the return value from GivePokeblockToContestLady
LilycoveCity_PokemonCenter_1F_EventScript_MonEnjoyPokeblock::
	applymovement LOCALID_LILYCOVE_LADYS_MON, LilycoveCity_PokemonCenter_1F_Movement_MonJump
	waitmovement 0
	delay 60
LilycoveCity_PokemonCenter_1F_EventScript_FinishFeedPokeblock::
	applymovement LOCALID_LILYCOVE_LADY, LilycoveCity_PokemonCenter_1F_Movement_LadyFacePlayer
	waitmovement 0
	delay 60
	goto_if_eq VAR_0x8004, 0, LilycoveCity_PokemonCenter_1F_EventScript_MonDislikedPokeblock
	goto_if_eq VAR_0x8004, 1, LilycoveCity_PokemonCenter_1F_EventScript_MonLikedPokeblock
	end

LilycoveCity_PokemonCenter_1F_EventScript_MonDislikedPokeblock::
	msgbox LilycoveCity_PokemonCenter_1F_Text_NoChangeThanks, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_CheckAirContestLadyShow
	end

LilycoveCity_PokemonCenter_1F_EventScript_MonLikedPokeblock::
	special Script_BufferContestLadyCategoryAndMonName
	msgbox LilycoveCity_PokemonCenter_1F_Text_ReallyImprovedThanks, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_CheckAirContestLadyShow
	end

LilycoveCity_PokemonCenter_1F_EventScript_CheckAirContestLadyShow::
	specialvar VAR_RESULT, ShouldContestLadyShowGoOnAir
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_AirContestLadyShow
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_AirContestLadyShow::
	msgbox LilycoveCity_PokemonCenter_1F_Text_ReadyToEnterContests, MSGBOX_DEFAULT
	special PutLilycoveContestLadyShowOnTheAir
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_NoPokeblockCase::
	msgbox LilycoveCity_PokemonCenter_1F_Text_DontHaveAPokeblockCase, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_Movement_LadyFaceMon:
	face_right
	delay_8
	step_end

LilycoveCity_PokemonCenter_1F_Movement_MonFaceLady:
	face_left
	delay_8
	step_end

@ Unused
LilycoveCity_PokemonCenter_1F_Movement_MonFaceDown:
	face_down
	step_end

LilycoveCity_PokemonCenter_1F_Movement_LadyFacePlayer:
	face_player
	step_end

LilycoveCity_PokemonCenter_1F_Movement_MonJump:
	disable_jump_landing_ground_effect
	jump_in_place_left
	disable_jump_landing_ground_effect
	jump_in_place_left
	step_end

LilycoveCity_PokemonCenter_1F_EventScript_ContestLadyMon::
	specialvar VAR_RESULT, GetContestLadyCategory
	special Script_BufferContestLadyCategoryAndMonName
	special GetContestLadyMonSpecies
	goto_if_eq VAR_RESULT, CONTEST_CATEGORY_COOL, LilycoveCity_PokemonCenter_1F_EventScript_Zigzagoon
	goto_if_eq VAR_RESULT, CONTEST_CATEGORY_BEAUTY, LilycoveCity_PokemonCenter_1F_EventScript_Skitty
	goto_if_eq VAR_RESULT, CONTEST_CATEGORY_CUTE, LilycoveCity_PokemonCenter_1F_EventScript_Poochyena
	goto_if_eq VAR_RESULT, CONTEST_CATEGORY_SMART, LilycoveCity_PokemonCenter_1F_EventScript_Kecleon
	goto_if_eq VAR_RESULT, CONTEST_CATEGORY_TOUGH, LilycoveCity_PokemonCenter_1F_EventScript_Pikachu
	end

LilycoveCity_PokemonCenter_1F_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox LilycoveCity_PokemonCenter_1F_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox LilycoveCity_PokemonCenter_1F_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_Poochyena::
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox LilycoveCity_PokemonCenter_1F_Text_Poochyena, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_Kecleon::
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox LilycoveCity_PokemonCenter_1F_Text_Kecleon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox LilycoveCity_PokemonCenter_1F_Text_Pikachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_PokemonCenter_1F_Text_ImTheFavorLady:
	.string "Sono la SIGNORA FAVORI…$"

LilycoveCity_PokemonCenter_1F_Text_ObsessedWithThing:
	.string "Ultimamente ho una fissazione\n"
	.string "per le cose {STR_VAR_1}…$"

LilycoveCity_PokemonCenter_1F_Text_ThankYouForLastTime:
	.string "Oh…\n"
	.string "Grazie per l'altra volta…$"

LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeBadThing:
	.string "Prima, credo fosse {STR_VAR_3}…\p"
	.string "{STR_VAR_3} mi diede un {STR_VAR_2},\n"
	.string "dicendo che era {STR_VAR_1}.\p"
	.string "Ma non era {STR_VAR_1}.\n"
	.string "Neanche un po'.$"

LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeGreatThing:
	.string "Prima, {STR_VAR_3} mi diede un\n"
	.string "{STR_VAR_2} molto {STR_VAR_1}.\p"
	.string "Ora lo tengo caro.$"

LilycoveCity_PokemonCenter_1F_Text_WillYouShareThing:
	.string "Senti, se hai qualcosa che\n"
	.string "è {STR_VAR_1}, lo divideresti\l"
	.string "con me?$"

LilycoveCity_PokemonCenter_1F_Text_WhatWillYouGiveMe:
	.string "…Davvero?\n"
	.string "Cosa mi darai?$"

LilycoveCity_PokemonCenter_1F_Text_IsThatSoGoodbye:
	.string "Davvero?\n"
	.string "Allora, addio…$"

LilycoveCity_PokemonCenter_1F_Text_NotWillingToShare:
	.string "Oh…\n"
	.string "Non vuoi condividerlo?$"

LilycoveCity_PokemonCenter_1F_Text_IllTryToCherishIt:
	.string "Oh?\n"
	.string "Quel {STR_VAR_2} è {STR_VAR_1}?\p"
	.string "…Oh, davvero?\p"
	.string "Beh, ti ringrazio comunque.\n"
	.string "Cercherò di tenerlo caro…$"

LilycoveCity_PokemonCenter_1F_Text_IWillCherishThis:
	.string "Oh…\p"
	.string "È un {STR_VAR_1} davvero\n"
	.string "{STR_VAR_2}…\p"
	.string "Non è carino?\n"
	.string "È così da sogno…\p"
	.string "Grazie…\n"
	.string "Lo terrò caro…$"

LilycoveCity_PokemonCenter_1F_Text_IWillTreasureThis:
	.string "…Oh, oh, oh…\p"
	.string "È fantastico!\n"
	.string "Questo è davvero {STR_VAR_1}!\p"
	.string "Non sapevo che un {STR_VAR_2}\n"
	.string "potesse essere così {STR_VAR_1}!\p"
	.string "Grazie!\p"
	.string "Lo custodirò per il resto\n"
	.string "della mia vita!$"

LilycoveCity_PokemonCenter_1F_Text_IllGiveYouThisInReturn:
	.string "Ti do questo splendido oggetto in\n"
	.string "cambio del tuo favoloso regalo.\p"
	.string "Spero che lo terrai caro…$"

LilycoveCity_PokemonCenter_1F_Text_YouDontHaveSpaceForIt:
	.string "Oh, non puoi averlo se non hai\n"
	.string "lo spazio per metterlo.\p"
	.string "Torna a trovarmi quando avrai\n"
	.string "riordinato lo ZAINO…$"

LilycoveCity_PokemonCenter_1F_Text_ImTheQuizLady:
	.string "Sono la SIGNORA QUIZ!\n"
	.string "Adoro i quiz!$"

LilycoveCity_PokemonCenter_1F_Text_WaitingToTakeYourQuiz:
	.string "Oh?\p"
	.string "Aspetto uno sfidante che risponda\n"
	.string "al quiz che hai creato.\p"
	.string "Chiacchieriamo un'altra volta, ok?$"

LilycoveCity_PokemonCenter_1F_Text_WaitingForChallenger:
	.string "Aspetto qualcuno che raccolga\n"
	.string "la sfida del quiz di {STR_VAR_1}!$"

LilycoveCity_PokemonCenter_1F_Text_TakeQuizChallenge:
	.string "Se rispondi bene, puoi vincere\n"
	.string "premi favolosi!\p"
	.string "Vuoi provare la sfida\n"
	.string "del quiz?$"

LilycoveCity_PokemonCenter_1F_Text_WaitForAnswer:
	.string "… … … … … …\n"
	.string "… … … … … …$"

LilycoveCity_PokemonCenter_1F_Text_HowBoringBye:
	.string "Oh, che noia!\n"
	.string "Ciao ciao!$"

LilycoveCity_PokemonCenter_1F_Text_YoureGoingToQuit:
	.string "Ohhh!\n"
	.string "Vuoi smettere?$"

LilycoveCity_PokemonCenter_1F_Text_TakeTheQuizAnotherTime:
	.string "Prova la sfida del quiz\n"
	.string "un'altra volta!$"

LilycoveCity_PokemonCenter_1F_Text_YouGotItRight:
	.string "Sei un fenomeno! Hai indovinato!\n"
	.string "Sei proprio in gamba!$"

LilycoveCity_PokemonCenter_1F_Text_YouGotItRightYouveWonPersonsPrize:
	.string "Congratulazioni!\n"
	.string "Hai indovinato il quiz!\p"
	.string "Hai vinto un premio offerto da\n"
	.string "{STR_VAR_1}!$"

@ Unused
LilycoveCity_PokemonCenter_1F_Text_XReceivedOneY:
	.string "{STR_VAR_1} riceve\n"
	.string "un {STR_VAR_2}!$"

LilycoveCity_PokemonCenter_1F_Text_YourBagIsFilledUp:
	.string "Oh? Lo ZAINO è pieno!\n"
	.string "Torna quando avrai spazio.$"

LilycoveCity_PokemonCenter_1F_Text_WrongTheCorrectAnswerIs:
	.string "Hmm… Sbagliato!\n"
	.string "La risposta giusta è “{STR_VAR_3}”!$"

LilycoveCity_PokemonCenter_1F_Text_IGetToKeepPrize:
	.string "Peccato!\p"
	.string "Ora il premio del quiz\n"
	.string "{STR_VAR_1} lo tengo io!$"

LilycoveCity_PokemonCenter_1F_Text_MakeYourOwnQuiz:
	.string "Ascolta, ascolta!\n"
	.string "Vorresti creare un quiz tutto tuo?$"

LilycoveCity_PokemonCenter_1F_Text_MaybeNextTime:
	.string "Oh, capisco…\n"
	.string "Beh, sarà per la prossima!$"

LilycoveCity_PokemonCenter_1F_Text_PickYourPrize:
	.string "Okay, the first thing you have to do\n"
	.string "is pick the prize for the person that\l"
	.string "answers your quiz correctly.\p"
	.string "But beware, if the person taking\n"
	.string "the quiz can't get it right, I get to\l"
	.string "keep the prize!$"

LilycoveCity_PokemonCenter_1F_Text_QuitChoosingPrize:
	.string "Se non scegli un premio,\n"
	.string "il quiz non si può creare.\p"
	.string "Vuoi smettere di creare\n"
	.string "il tuo quiz?$"

LilycoveCity_PokemonCenter_1F_Text_WriteYourQuiz:
	.string "Oh, che bello!\n"
	.string "È un premio meraviglioso!\p"
	.string "Ora devi scrivere la domanda\n"
	.string "del quiz e la sua risposta.$"

LilycoveCity_PokemonCenter_1F_Text_QuitWritingQuizQuestion:
	.string "Vuoi smettere di scrivere\n"
	.string "la domanda del quiz?$"

@ Unused
LilycoveCity_PokemonCenter_1F_Text_QuitWritingQuizAnswer:
	.string "Vuoi smettere di scegliere\n"
	.string "la risposta del quiz?$"

LilycoveCity_PokemonCenter_1F_Text_IllLookForAChallenger:
	.string "Grazie!\n"
	.string "Hai creato un bel quiz.\p"
	.string "Vado subito a cercare qualcuno che\n"
	.string "accetti la tua sfida.$"

LilycoveCity_PokemonCenter_1F_Text_ImTheContestLady:
	.string "Sono la SIGNORA GARE!\n"
	.string "Adoro le GARE!$"

LilycoveCity_PokemonCenter_1F_Text_ThankForPokeblock:
	.string "Grazie per il {POKEBLOCK} di prima!$"

LilycoveCity_PokemonCenter_1F_Text_MyFriendDisplaysQuality:
	.string "Questo è il mio amico {STR_VAR_1}!\n"
	.string "È l'esempio di {STR_VAR_2}!\p"
	.string "Ma credo che mostrerà\n"
	.string "ancora più {STR_VAR_2}!$"

LilycoveCity_PokemonCenter_1F_Text_DontHaveAPokeblockCase:
	.string "Quindi mi serve il tuo aiuto!\p"
	.string "Me ne daresti un {POKEBLOCK}?\n"
	.string "Ne chiedo solo uno!\p"
	.string "…Oh, ma…\n"
	.string "Non hai un {POKEBLOCK} CASE?\l"
	.string "Poco male. Sarà per la prossima volta!$"

LilycoveCity_PokemonCenter_1F_Text_AskingForOnePokeblock:
	.string "Allora, mi serve il tuo aiuto!\p"
	.string "Per favore, me ne dai un {POKEBLOCK}?\n"
	.string "Te ne chiedo solo uno!$"

LilycoveCity_PokemonCenter_1F_Text_ICantHaveOnePokeblock:
	.string "Ohhh!\n"
	.string "Non posso avere un {POKEBLOCK}?!$"

LilycoveCity_PokemonCenter_1F_Text_WhatACheapskate:
	.string "Uffa!\n"
	.string "Che spilorcio!$"

LilycoveCity_PokemonCenter_1F_Text_IllUseYourPokeblock:
	.string "Evvai!\n"
	.string "Grazie!\p"
	.string "Darò subito il tuo {POKEBLOCK}\n"
	.string "ai miei POKéMON.$"

LilycoveCity_PokemonCenter_1F_Text_NoChangeThanks:
	.string "…Sembra non essere cambiato\n"
	.string "in alcun modo…\p"
	.string "Hmm…\p"
	.string "Oh, beh!\n"
	.string "Grazie mille!$"

LilycoveCity_PokemonCenter_1F_Text_ReallyImprovedThanks:
	.string "Oh, evviva!\n"
	.string "È davvero felice!\p"
	.string "Credo che {STR_VAR_1} sia davvero migliorato\n"
	.string "anche in {STR_VAR_2}.\p"
	.string "Grazie mille!$"

LilycoveCity_PokemonCenter_1F_Text_ReadyToEnterContests:
	.string "Hmm…\p"
	.string "Credo che siamo pronti per\n"
	.string "qualche GARA.\p"
	.string "Se ci vedi da qualche parte,\n"
	.string "spero che farai il tifo per noi.$"

LilycoveCity_PokemonCenter_1F_Text_Zigzagoon:
	.string "{STR_VAR_1}: Gu-guuh!$"

LilycoveCity_PokemonCenter_1F_Text_Kecleon:
	.string "{STR_VAR_1}: Igigigiiih!$"

LilycoveCity_PokemonCenter_1F_Text_Poochyena:
	.string "{STR_VAR_1}: Baaarun…$"

LilycoveCity_PokemonCenter_1F_Text_Pikachu:
	.string "{STR_VAR_1}: Pikka!$"

LilycoveCity_PokemonCenter_1F_Text_Skitty:
	.string "{STR_VAR_1}: Umyaaaan!$"
