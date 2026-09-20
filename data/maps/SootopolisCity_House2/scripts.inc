SootopolisCity_House2_MapScripts::
	.byte 0

SootopolisCity_House2_EventScript_ExpertF::
	lock
	faceplayer
	msgbox SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, SootopolisCity_House2_EventScript_KnowAboutOrbs
	call_if_eq VAR_RESULT, NO, SootopolisCity_House2_EventScript_DontKnowAboutOrbs
	release
	end

SootopolisCity_House2_EventScript_KnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_YesTwoOrbsSideBySide, MSGBOX_DEFAULT
	return

SootopolisCity_House2_EventScript_DontKnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_OughtToVisitAndSee, MSGBOX_DEFAULT
	return

SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs:
	.string "MT. PYRE…\p"
	.string "Sulla sua cima ci sono due sfere\n"
	.string "una accanto all'altra. Lo sapevi?$"

SootopolisCity_House2_Text_YesTwoOrbsSideBySide:
	.string "Sì, due sfere una accanto all'altra…\p"
	.string "Vederle insieme…\n"
	.string "È in qualche modo rassicurante…$"

SootopolisCity_House2_Text_OughtToVisitAndSee:
	.string "Davvero?\n"
	.string "Forse dovresti andare a vedere…$"

