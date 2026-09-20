SootopolisCity_House3_MapScripts::
	.byte 0

SootopolisCity_House3_EventScript_Woman::
	lock
	faceplayer
	msgbox SootopolisCity_House3_Text_JuanHasManyFansDoYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SootopolisCity_House3_EventScript_HaveFans
	msgbox SootopolisCity_House3_Text_LonesomeTryWorkingHarder, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_HaveFans::
	msgbox SootopolisCity_House3_Text_YouMustBePrettyStrong, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_Girl::
	msgbox SootopolisCity_House3_Text_TrainerFanClubWasWild, MSGBOX_NPC
	end

SootopolisCity_House3_Text_JuanHasManyFansDoYou:
	.string "Sei un ALLENATORE di POKéMON, vero?\p"
	.string "JUAN di SOOTOPOLIS ha molti fan.\n"
	.string "Persino più del suo allievo WALLACE!\p"
	.string "E tu ne hai?$"

SootopolisCity_House3_Text_YouMustBePrettyStrong:
	.string "Oh, allora devi essere piuttosto forte.$"

SootopolisCity_House3_Text_LonesomeTryWorkingHarder:
	.string "Oh, cielo…\n"
	.string "È un po' triste.\p"
	.string "Impegnati un po' di più per\n"
	.string "averti dei fan.$"

SootopolisCity_House3_Text_TrainerFanClubWasWild:
	.string "Arrivano fan accaniti persino\n"
	.string "da fuori HOENN.\p"
	.string "Al FAN CLUB ALLENATORI di LILYCOVE\n"
	.string "c'era un gran fermento.$"

