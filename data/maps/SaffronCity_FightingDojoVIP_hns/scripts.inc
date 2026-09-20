SaffronCity_FightingDojoVIP_hns_MapScripts::
	.byte 0

SaffronCity_FightingDojoVIP_EventScript_Nurse::
	lock
	faceplayer
	specialvar VAR_RESULT, IsPokecenterChallengeActivated
	goto_if_eq VAR_RESULT, TRUE, SSAquaRooms_EventScript_Bed_PokecenterChallenge
	msgbox SaffronCity_FightingDojoVIP_Text_Nurse1, MSGBOX_NPC
	waitmessage
	fadescreen 0x1
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	fadescreen 0x0
	msgbox SaffronCity_FightingDojoVIP_Text_Nurse2, MSGBOX_NPC
	waitmessage
	release
	end

SaffronCity_FightingDojoVIP_Text_Nurse1:
	.string "Ciao! Benvenuto al DOJO DI ALLENAMENTO!\n"
	.string "Curerò i tuoi POKéMON.$"

SaffronCity_FightingDojoVIP_Text_Nurse2:
	.string "Speriamo di rivederti!$"


SaffronCity_FightingDojoVIP_EventScript_Declined::
	closemessage
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Falkner::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Falkner_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Falkner_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Falkner_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Falkner_Rematch::
	trainerbattle_no_intro TRAINER_FALKNER_2_HNS, SaffronCity_FightingDojoVIP_Text_Falkner_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Falkner_PostOBC::
	trainerbattle_no_intro TRAINER_FALKNER_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Falkner_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Bugsy::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Bugsy_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Bugsy_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Bugsy_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Bugsy_Rematch::
	trainerbattle_no_intro TRAINER_BUGSY_2_HNS, SaffronCity_FightingDojoVIP_Text_Bugsy_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Bugsy_PostOBC::
	trainerbattle_no_intro TRAINER_BUGSY_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Bugsy_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Whitney::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Whitney_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Whitney_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Whitney_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Whitney_Rematch::
	trainerbattle_no_intro TRAINER_WHITNEY_2_HNS, SaffronCity_FightingDojoVIP_Text_Whitney_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Whitney_PostOBC::
	trainerbattle_no_intro TRAINER_WHITNEY_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Whitney_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Morty::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Morty_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Morty_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Morty_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Morty_Rematch::
	trainerbattle_no_intro TRAINER_MORTY_2_HNS, SaffronCity_FightingDojoVIP_Text_Morty_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Morty_PostOBC::
	trainerbattle_no_intro TRAINER_MORTY_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Morty_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Chuck::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Chuck_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Chuck_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Chuck_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Chuck_Rematch::
	trainerbattle_no_intro TRAINER_CHUCK_2_HNS, SaffronCity_FightingDojoVIP_Text_Chuck_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Chuck_PostOBC::
	trainerbattle_no_intro TRAINER_CHUCK_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Chuck_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Jasmine::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Jasmine_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Jasmine_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Jasmine_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Jasmine_Rematch::
	trainerbattle_no_intro TRAINER_JASMINE_2_HNS, SaffronCity_FightingDojoVIP_Text_Jasmine_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Jasmine_PostOBC::
	trainerbattle_no_intro TRAINER_JASMINE_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Jasmine_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Pryce::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Pryce_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Pryce_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Pryce_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Pryce_Rematch::
	trainerbattle_no_intro TRAINER_PRYCE_2_HNS, SaffronCity_FightingDojoVIP_Text_Pryce_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Pryce_PostOBC::
	trainerbattle_no_intro TRAINER_PRYCE_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Pryce_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Clair::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Clair_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Clair_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Clair_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Clair_Rematch::
	trainerbattle_no_intro TRAINER_CLAIR_2_HNS, SaffronCity_FightingDojoVIP_Text_Clair_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Clair_PostOBC::
	trainerbattle_no_intro TRAINER_CLAIR_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Clair_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Brock::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Brock_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Brock_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Brock_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Brock_Rematch::
	trainerbattle_no_intro TRAINER_BROCK_HNS, SaffronCity_FightingDojoVIP_Text_Brock_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Brock_PostOBC::
	trainerbattle_no_intro TRAINER_BROCK_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Brock_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Misty::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Misty_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Misty_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Misty_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Misty_Rematch::
	trainerbattle_no_intro TRAINER_MISTY_HNS, SaffronCity_FightingDojoVIP_Text_Misty_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Misty_PostOBC::
	trainerbattle_no_intro TRAINER_MISTY_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Misty_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Surge::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Surge_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Surge_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Surge_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Surge_Rematch::
	trainerbattle_no_intro TRAINER_LTSURGE_HNS, SaffronCity_FightingDojoVIP_Text_Surge_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Surge_PostOBC::
	trainerbattle_no_intro TRAINER_LTSURGE_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Surge_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Erika::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Erika_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Erika_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Erika_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Erika_Rematch::
	trainerbattle_no_intro TRAINER_ERIKA_HNS, SaffronCity_FightingDojoVIP_Text_Erika_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Erika_PostOBC::
	trainerbattle_no_intro TRAINER_ERIKA_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Erika_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Janine::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Janine_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Janine_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Janine_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Janine_Rematch::
	trainerbattle_no_intro TRAINER_JANINE_HNS, SaffronCity_FightingDojoVIP_Text_Janine_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Janine_PostOBC::
	trainerbattle_no_intro TRAINER_JANINE_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Janine_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Sabrina::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Sabrina_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Sabrina_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Sabrina_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Sabrina_Rematch::
	trainerbattle_no_intro TRAINER_SABRINA_HNS, SaffronCity_FightingDojoVIP_Text_Sabrina_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Sabrina_PostOBC::
	trainerbattle_no_intro TRAINER_SABRINA_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Sabrina_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Blaine::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Blaine_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Blaine_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Blaine_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Blaine_Rematch::
	trainerbattle_no_intro TRAINER_BLAINE_HNS, SaffronCity_FightingDojoVIP_Text_Blaine_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Blaine_PostOBC::
	trainerbattle_no_intro TRAINER_BLAINE_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Blaine_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Blue::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Blue_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Blue_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Blue_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Blue_Rematch::
	trainerbattle_no_intro TRAINER_BLUE_HNS, SaffronCity_FightingDojoVIP_Text_Blue_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Blue_PostOBC::
	trainerbattle_no_intro TRAINER_BLUE_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Blue_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

@===============MONS===============================================================================================================

SaffronCity_FightingDojoVIP_EventScript_Scizor::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SCIZOR, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Scizor, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Scizor:
	.string "SCIZOR: Scii-zor!$"

SaffronCity_FightingDojoVIP_EventScript_Miltank::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MILTANK, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Miltank, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Miltank:
	.string "MILTANK: MuuuU!$"

SaffronCity_FightingDojoVIP_EventScript_Poliwhirl::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWHIRL, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Poliwhirl, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Poliwhirl:
	.string "POLIWHIRL: Whirl-whirl!$"

SaffronCity_FightingDojoVIP_EventScript_Dewgong::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DEWGONG, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Dewgong, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Dewgong:
	.string "DEWGONG: Goooong!$"

SaffronCity_FightingDojoVIP_EventScript_Steelix::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_STEELIX, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Steelix, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Steelix:
	.string "STEELIX: GraaAAANk!$"

SaffronCity_FightingDojoVIP_EventScript_Kingdra::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KINGDRA, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Kingdra, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Kingdra:
	.string "KINGDRA: Draaa…$"

SaffronCity_FightingDojoVIP_EventScript_Onix::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ONIX, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Onix, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Onix:
	.string "ONIX: Oooonix!$"

SaffronCity_FightingDojoVIP_EventScript_Starmie::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_STARMIE, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Starmie, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Starmie:
	.string "STARMIE: Hyaaa!$"

SaffronCity_FightingDojoVIP_EventScript_Victreebel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VICTREEBEL, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Victreebel, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Victreebel:
	.string "VICTREEBEL: Vreeee!$"

SaffronCity_FightingDojoVIP_EventScript_Muk::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MUK, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Muk, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Muk:
	.string "MUK: Muuuk…$"

SaffronCity_FightingDojoVIP_EventScript_Kadabra::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KADABRA, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Kadabra, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Kadabra:
	.string "KADABRA: Kadabra!$"

SaffronCity_FightingDojoVIP_EventScript_Magmar::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAGMAR, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Magmar, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Magmar:
	.string "MAGMAR: Magmaaaar!$"

SaffronCity_FightingDojoVIP_EventScript_Raichu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_RAICHU, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Raichu, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Raichu:
	.string "RAICHU: Rai-CHU!$"

SaffronCity_FightingDojoVIP_EventScript_Machamp::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHAMP, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Machamp, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Machamp:
	.string "MACHAMP: Maa-champ!$"

SaffronCity_FightingDojo_EventScript_Chased::
	msgbox SaffronCity_FightingDojoVIP_Text_Chased, MSGBOX_NPC
	end

SaffronCity_FightingDojoVIP_Text_Chased:
	.string "Aiuto!$"

SaffronCity_FightingDojoVIP_EvetScript_Statue::
	msgbox SaffronCity_FightingDojoVIP_Text_Statue, MSGBOX_SIGN
	end

SaffronCity_FightingDojoVIP_Text_Statue:
	.string "SALA VIP DOJO LOTTA$"

SaffronCity_FightingDojoVIP_Text_Falkner_Rematch:
	.string "Congratulazioni per aver battuto\n"
	.string "l'ELITE 4!\p"
	.string "Ho allenato i miei POKéMON\n"
	.string "di tipo VOLANTE ancora di più.\p"
	.string "Pensi di reggere di nuovo\n"
	.string "la forza dei cieli?$"

SaffronCity_FightingDojoVIP_Text_Falkner_RematchDefeat:
	.string "Wow… Mi hai battuto di nuovo.\p"
	.string "Mi allenerò di più per\n"
	.string "diventare il più grande Uccello!$"

SaffronCity_FightingDojoVIP_Text_Bugsy_Rematch:
	.string "Wow, ora sei il CAMPIONE\n"
	.string "di JOHTO!\p"
	.string "Le tue doti sono impressionanti!\p"
	.string "Ero preso dalle ricerche.\p"
	.string "Sono pronto a mostrarti le mie\n"
	.string "scoperte.\p"
	.string "Vuoi una rivincita con me?$"

SaffronCity_FightingDojoVIP_Text_Bugsy_RematchDefeat:
	.string "Wow, devi essere un'esperta\n"
	.string "di lotte.\p"
	.string "Le mie ricerche non sono\n"
	.string "complete…$"

SaffronCity_FightingDojoVIP_Text_Whitney_Rematch:
	.string "Ciao! Sei tu!\p"
	.string "Wow, CAMPIONE JOHTO ora?\p"
	.string "Sei davvero incredibile!\p"
	.string "Voglio vedere quanto sei forte.\p"
	.string "Vuoi una rivincita con me?$"

SaffronCity_FightingDojoVIP_Text_Whitney_RematchDefeat:
	.string "Waaaaah!\p"
	.string "Waaaaah!\p"
	.string "…Singhiozzo… …Che cattivo!$"

SaffronCity_FightingDojoVIP_Text_Morty_Rematch:
	.string "Ah, il CAMPIONE di JOHTO!\n"
	.string "Bene che sia venuto.\p"
	.string "Hai mostrato forza e\n"
	.string "abilità, ma sei migliorato\l"
	.string "dall'ultima battaglia?\p"
	.string "Mi sono allenato con POKéMON\n"
	.string "di tipo SPETTRO.\p"
	.string "Vediamo se superi ancora\n"
	.string "le ombre.\p"
	.string "Vuoi una rivincita con me?$"

SaffronCity_FightingDojoVIP_Text_Morty_RematchDefeat:
	.string "Non sono ancora abbastanza forte…\p"
	.string "Hai visto molto più\n"
	.string "di me.\p"
	.string "Ti invidio per questo…$"

SaffronCity_FightingDojoVIP_Text_Chuck_Rematch:
	.string "WAHAHAH! CAMPIONE JOHTO!\p"
	.string "Sei tornato per il bis!\p"
	.string "Vedo che sei migliorato!\p"
	.string "Vediamo chi è più forte?$"

SaffronCity_FightingDojoVIP_Text_Chuck_RematchDefeat:
	.string "Wha? Eh? Ho perso? Di nuovo?$"

SaffronCity_FightingDojoVIP_Text_Jasmine_Rematch:
	.string "…Congratulazioni, CAMPIONE\n"
	.string "di JOHTO.\p"
	.string "Sei diventato così forte…\p"
	.string "Chissà se sono migliorata.\p"
	.string "Vuoi mettermi alla prova?\p"
	.string "Vuoi una rivincita con me?$"

SaffronCity_FightingDojoVIP_Text_Jasmine_RematchDefeat:
	.string "…Sei un allenatore migliore\n"
	.string "di me,\p"
	.string "in abilità e gentilezza.$"

SaffronCity_FightingDojoVIP_Text_Pryce_Rematch:
	.string "Ah, CAMPIONE di JOHTO!\p"
	.string "Le tue doti sono davvero\n"
	.string "notevoli.\p"
	.string "Sono impressionato.\p"
	.string "Ma c'è sempre molto da\n"
	.string "imparare l'uno dall'altro.\p"
	.string "Io, PRYCE, allenatore d'inverno,\p"
	.string "ho ancora qualche trucco.\p"
	.string "Vuoi una rivincita con me?$"

SaffronCity_FightingDojoVIP_Text_Pryce_RematchDefeat:
	.string "Ah, ancora una volta mi hai\n"
	.string "impressionato.\p"
	.string "Con la tua forza di volontà\n"
	.string "supererai ogni ostacolo\l"
	.string "della vita.$"

SaffronCity_FightingDojoVIP_Text_Clair_Rematch:
	.string "Ce l'hai fatta, eh?\p"
	.string "Ora sei il CAMPIONE di JOHTO.\p"
	.string "Hai provato la tua forza ma\n"
	.string "puoi ancora affrontarmi?\p"
	.string "Da Maestra Drago, non mi\n"
	.string "tratterrò.\p"
	.string "Non questa volta.\p"
	.string "Vuoi una rivincita con me?$"

SaffronCity_FightingDojoVIP_Text_Clair_RematchDefeat:
	.string "Ho perso?\p"
	.string "Di nuovo?\p"
	.string "Non ci credo. Ci deve\n"
	.string "essere un errore…$"

SaffronCity_FightingDojoVIP_Text_Brock_Rematch:
	.string "BROCK: Ehi, {PLAYER}!\p"
	.string "Ho sentito che ora sei il CAMPIONE\n"
	.string "di KANTO.\p"
	.string "Incredibile!\p"
	.string "Ora sarai ancora più forte.\p"
	.string "Vuoi una rivincita con me?$"

SaffronCity_FightingDojoVIP_Text_Brock_RematchDefeat:
	.string "BROCK: I tuoi POKéMON hanno di nuovo\n"
	.string "superato la mia difesa rocciosa…$"

SaffronCity_FightingDojoVIP_Text_Misty_Rematch:
	.string "MISTY: Wow, sei CAMPIONE\n"
	.string "di KANTO!\p"
	.string "Fantastico! Hai fatto tanta\n"
	.string "strada, {PLAYER}.\p"
	.string "Ma non mi arrendo.\p"
	.string "Vuoi una rivincita con me?$"

SaffronCity_FightingDojoVIP_Text_Misty_RematchDefeat:
	.string "MISTY: Sei davvero forte…$"

SaffronCity_FightingDojoVIP_Text_Surge_Rematch:
	.string "SURGE: Allora sei il CAMPIONE\n"
	.string "di KANTO!\p"
	.string "Bel lavoro, ragazzo! Ma non\n"
	.string "credere che sia finita!\p"
	.string "Che ne dici di riprovarci?$"

SaffronCity_FightingDojoVIP_Text_Surge_RematchDefeat:
	.string "SURGE: Arrrgh! Sei forte\n"
	.string "come sempre!$"

SaffronCity_FightingDojoVIP_Text_Erika_Rematch:
	.string "ERIKA: Oh, ciao.\p"
	.string "Che sorpresa, CAMPIONE!\p"
	.string "Che piacere rivederti.\p"
	.string "Il tuo viaggio sarà stato\n"
	.string "emozionante.\p"
	.string "Anche i campioni amano le sfide.\p"
	.string "Vuoi una rivincita con me?$"

SaffronCity_FightingDojoVIP_Text_Erika_RematchDefeat:
	.string "ERIKA: Anche perdere\n"
	.string "lascia l'amaro…\p"
	.string "Ma sapere che ci sono\n"
	.string "allenatori forti mi sprona…$"

SaffronCity_FightingDojoVIP_Text_Sabrina_Rematch:
	.string "SABRINA: Ah, il CAMPIONE.\p"
	.string "Ho percepito il tuo ritorno.\p"
	.string "La tua forza è cresciuta molto.\p"
	.string "Sento ancora la tua aura.\p"
	.string "Vuoi una rivincita con me?$"

SaffronCity_FightingDojoVIP_Text_Sabrina_RematchDefeat:
	.string "SABRINA: Il tuo amore per i\n"
	.string "POKéMON ha di nuovo vinto il\l"
	.string "mio potere psichico…$"

SaffronCity_FightingDojoVIP_Text_Janine_Rematch:
	.string "Fufufufu…\p"
	.string "Wow, ce l'hai fatta!\p"
	.string "Ora sei il CAMPIONE!\p"
	.string "Sono così fiera! Ma non\n"
	.string "crederò di andarci piano.\p"
	.string "Vuoi una rivincita con me?$"

SaffronCity_FightingDojoVIP_Text_Janine_RematchDefeat:
	.string "JANINE: Sei sempre forte\n"
	.string "come prima!\p"
	.string "Hai vinto senza dubbio…$"

SaffronCity_FightingDojoVIP_Text_Blaine_Rematch:
	.string "BLAINE: Uao!\p"
	.string "Vedo che sei diventato CAMPIONE\n"
	.string "di KANTO!\p"
	.string "Che fuoco!\p"
	.string "Le tue doti sono eccellenti.\p"
	.string "Non rifiuto mai una sfida.\p"
	.string "Vuoi una rivincita con me?$"

SaffronCity_FightingDojoVIP_Text_Blaine_RematchDefeat:
	.string "BLAINE: Le tue doti sono davvero\n"
	.string "incandescenti!\p"
	.string "Hai bruciato ogni mia\n"
	.string "difesa.$"

SaffronCity_FightingDojoVIP_Text_Blue_Rematch:
	.string "BLUE: Bene, bene. CAMPIONE!\p"
	.string "Vedo che hai fatto strada.\p"
	.string "Anch'io avevo quel titolo,\n"
	.string "sai. Ma non andrò piano.\p"
	.string "Vediamo se sai tenerlo.\p"
	.string "Vuoi una rivincita con me?$"

SaffronCity_FightingDojoVIP_Text_Blue_RematchDefeat:
	.string "BLUE: Cosa?\p"
	.string "Come diavolo ho perso di nuovo?$"

