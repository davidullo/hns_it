FuchsiaCity_House3_Frlg_MapScripts::
	.byte 0

FuchsiaCity_House3_EventScript_MoveDeleter::
	lock
	faceplayer
	msgbox FuchsiaCity_House3_Text_WouldYouLikeToForgetMove, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_House3_EventScript_ChooseMonForMoveDeleter
	goto FuchsiaCity_House3_EventScript_CancelForgetMove
	end

FuchsiaCity_House3_EventScript_ChooseMonForMoveDeleter::
	msgbox FuchsiaCity_House3_Text_WhichMonShouldForgetMove
	special ChoosePartyMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, FuchsiaCity_House3_EventScript_CancelForgetMove
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, FuchsiaCity_House3_EventScript_CantForgetMoveEgg
	special GetNumMovesSelectedMonHas
	goto_if_eq VAR_RESULT, 1, FuchsiaCity_House3_EventScript_CantForgetOnlyMove
	msgbox FuchsiaCity_House3_Text_WhichMoveShouldBeForgotten
	fadescreen FADE_TO_BLACK
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, FuchsiaCity_House3_EventScript_ChooseMonForMoveDeleter
	special BufferMoveDeleterNicknameAndMove
	msgbox FuchsiaCity_House3_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_House3_EventScript_ForgetMove
	goto FuchsiaCity_House3_EventScript_CancelForgetMove
	end

FuchsiaCity_House3_EventScript_ForgetMove::
	special MoveDeleterForgetMove
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	msgbox FuchsiaCity_House3_Text_MonHasForgottenMoveCompletely
	release
	end

FuchsiaCity_House3_EventScript_CantForgetOnlyMove::
	special BufferMoveDeleterNicknameAndMove
	msgbox FuchsiaCity_House3_Text_MonOnlyKnowsOneMove
	release
	end

FuchsiaCity_House3_EventScript_CantForgetMoveEgg::
	msgbox FuchsiaCity_House3_Text_NoEggShouldKnowMoves
	release
	end

FuchsiaCity_House3_EventScript_CancelForgetMove::
	msgbox FuchsiaCity_House3_Text_ComeAgainToForgetOtherMoves
	release
	end

FuchsiaCity_House3_Text_WouldYouLikeToForgetMove::
	.string "Uh…\n"
	.string "Ah, sì, sono il CANCELLAMOSSE.\p"
	.string "Faccio dimenticare le mosse ai\n"
	.string "POKéMON.\p"
	.string "Vuoi che lo faccia?$"

FuchsiaCity_House3_Text_WhichMonShouldForgetMove::
	.string "Quale POKéMON dimentica una\n"
	.string "mossa?$"

FuchsiaCity_House3_Text_WhichMoveShouldBeForgotten::
	.string "Quale mossa dimenticare?$"

FuchsiaCity_House3_Text_MonOnlyKnowsOneMove::
	.string "{STR_VAR_1} conosce una sola\n"
	.string "mossa…$"

FuchsiaCity_House3_Text_MonsMoveShouldBeForgotten::
	.string "Hm! {STR_VAR_2} di {STR_VAR_1}?\n"
	.string "Da dimenticare, quella mossa?$"

FuchsiaCity_House3_Text_MonHasForgottenMoveCompletely::
	.string "Perfetto, ci siamo!\p"
	.string "{STR_VAR_1} ha dimenticato\n"
	.string "del tutto {STR_VAR_2}.$"

FuchsiaCity_House3_Text_ComeAgainToForgetOtherMoves::
	.string "Torna se ci sono altre mosse\n"
	.string "da dimenticare.$"

FuchsiaCity_House3_Text_NoEggShouldKnowMoves::
	.string "Cosa?\n"
	.string "Un UOVO non conosce mosse.$"

