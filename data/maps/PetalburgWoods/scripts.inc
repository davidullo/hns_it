PetalburgWoods_MapScripts::
	.byte 0

PetalburgWoods_EventScript_DevonResearcherLeft::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
	waitmovement 0
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherRight::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
	waitmovement 0
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherIntro::
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
	waitmovement 0
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_DevonResearcherPostBattle::
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaRunAway
	waitmovement 0
	removeobject LOCALID_PETALBURG_WOODS_GRUNT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_BagFull::
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_DevonResearcherFinish::
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
	waitmovement 0
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_RemoveDevonResearcher::
	removeobject LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE
	setvar VAR_PETALBURG_WOODS_STATE, 1
	releaseall
	end

PetalburgWoods_Movement_DevonResearcherLookAround:
	face_up
	delay_16
	delay_4
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	step_end

PetalburgWoods_Movement_DevonResearcherExitLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
	delay_16
	face_player
	walk_down
	walk_down
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
	delay_16
	face_player
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PetalburgWoods_Movement_DevonResearcherExitRight:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_WatchResearcherLeave:
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherStartExit:
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	step_end

PetalburgWoods_Movement_AquaApproachResearcherLeft:
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaBackOff:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PetalburgWoods_Movement_AquaRunAway:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachResearcherRight:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaEntrance:
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachPlayer:
	walk_down
	step_end

PetalburgWoods_EventScript_Boy1::
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Boy2::
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MIRACLE_SEED
	release
	end

PetalburgWoods_EventScript_ExplainMiracleSeed::
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_Sign1::
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign2::
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_James::
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
	setvar VAR_0x8004, TRAINER_JAMES_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_TryRegisterJames::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
	release
	end

PetalburgWoods_EventScript_RegisterJames::
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_TryRegisterJames2::
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_RegisterJames2::
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_JamesRematch::
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_Text_NotAOneToBeFound:
	.string "Mmmh…\n"
	.string "Non ce n'è nemmeno uno…$"

PetalburgWoods_Text_HaveYouSeenShroomish:
	.string "Ciao, hai visto dei POKéMON\n"
	.string "chiamati SHROOMISH da queste parti?\p"
	.string "Adoro quel POKéMON.$"

PetalburgWoods_Text_IWasGoingToAmbushYou:
	.string "Volevo tenderti un'imboscata, ma tu\n"
	.string "hai bighellonato nel BOSCO PETALBURG\l"
	.string "per sempre, vero?\p"
	.string "Mi sono stufato di aspettare, eccomi!$"

PetalburgWoods_Text_HandOverThosePapers:
	.string "Tu! RICERCATORE DEVON!\p"
	.string "Consegna quei documenti!$"

PetalburgWoods_Text_YouHaveToHelpMe:
	.string "Ahiieeeh!\p"
	.string "Sei un ALLENATORE di POKéMON, vero?\n"
	.string "Devi aiutarmi, ti prego!$"

PetalburgWoods_Text_NoOneCrossesTeamAqua:
	.string "Eh? Cosa credi di fare?\n"
	.string "Cosa, vuoi proteggerlo?\p"
	.string "Nessuno che sfida il TEAM AQUA\n"
	.string "riceve pietà, nemmeno un bambino!\p"
	.string "Forza, lottiamo!$"

PetalburgWoods_Text_YoureKiddingMe:
	.string "Non ci credo! Sei forte!$"

PetalburgWoods_Text_YouveGotSomeNerve:
	.string "Grrr… Hai un bel coraggio\n"
	.string "a intrometterti nel TEAM IDRO!\l"
	.string "Forza, combatti di nuovo con me!\p"
	.string "Vorrei dirtelo, ma sono a corto di\n"
	.string "POKéMON…\p"
	.string "E poi noi del TEAM IDRO abbiamo\n"
	.string "un affare a PETALBURGO.\p"
	.string "Per oggi ti lascio andare!$"

PetalburgWoods_Text_ThatWasAwfullyClose:
	.string "Fiu…\n"
	.string "È andata fin troppo bene!\p"
	.string "Grazie a te non mi ha rubato\n"
	.string "questi documenti importanti.\p"
	.string "Sai cosa, ti do una GREAT BALL come\n"
	.string "ringraziamento!$"

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
	.string "Quel tipo del TEAM AQUA ha detto\n"
	.string "che cercavano qualcosa anche a\l"
	.string "RUSTBORO?$"

PetalburgWoods_Text_ICantBeWastingTime:
	.string "Oh-oh! È un'emergenza!\n"
	.string "Non posso perdere tempo!$"

PetalburgWoods_Text_YoureLoadedWithItems:
	.string "Hai troppi strumenti.\n"
	.string "Non posso darti questa GREAT BALL.$"

PetalburgWoods_Text_GoBugPokemonTeam:
	.string "Ho catturato un sacco di POKéMON!\p"
	.string "Forza, forza, forza!\n"
	.string "La mia squadra di POKéMON COLEOTTERO!$"

PetalburgWoods_Text_ICouldntWin:
	.string "Ho tutti questi POKéMON,\n"
	.string "ma non ho potuto vincere…$"

PetalburgWoods_Text_ImOutOfPokeBalls:
	.string "Ho catturato un sacco di POKéMON.\n"
	.string "Ora ho finito le POKé BALL.$"

PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
	.string "Se porti a scuola POKéMON COLEOTTERO,\n"
	.string "diventi subito popolare!$"

PetalburgWoods_Text_CantBePopularIfILose:
	.string "Non posso essere popolare se perdo.$"

PetalburgWoods_Text_PeopleRespectYou:
	.string "Se hai un POKéMON COLEOTTERO forte,\n"
	.string "la gente ti rispetta.$"

PetalburgWoods_Text_IWantRematch1:
	.string "Voglio una rivincita quando i miei\n"
	.string "POKéMON COLEOTTERO saranno cresciuti!\p"
	.string "Ti registro nel POKéNAV!$"

PetalburgWoods_Text_IWantRematch2:
	.string "Voglio una rivincita quando i miei\n"
	.string "POKéMON COLEOTTERO saranno cresciuti!\p"
	.string "Ti registro nel POKéNAV!$"

PetalburgWoods_Text_MyPokemonHaveGrown:
	.string "I miei POKéMON Coleottero sono cresciuti.\n"
	.string "Tornerò a essere popolare.$"

PetalburgWoods_Text_CantBePopularIfLose:
	.string "Non posso essere popolare se perdo.$"

PetalburgWoods_Text_IveBeenTrainingHard:
	.string "Diventi popolare se hai\n"
	.string "POKéMON forti, no?\l"
	.string "Perciò mi sono allenato sodo.$"

PetalburgWoods_Text_StayOutOfTallGrass:
	.string "Ehi, tu!\n"
	.string "I tuoi POKéMON stanno bene?\p"
	.string "Se i tuoi POKéMON sono deboli e vuoi\n"
	.string "evitare le lotte, sta fuori\l"
	.string "dall'erba alta.$"

PetalburgWoods_Text_HiddenItemsExplanation:
	.string "A volte ci sono cose per\n"
	.string "terra anche se non le vedi.\p"
	.string "Per questo controllo sempre dove\n"
	.string "cammino.$"

PetalburgWoods_Text_TryUsingThisItem:
	.string "Oh, bello!\n"
	.string "È la MEDAGLIA della PALESTRA di FERRARO!\p"
	.string "Devi essere un ALLENATORE.\n"
	.string "Prova a usare questo strumento.$"

PetalburgWoods_Text_MiracleSeedExplanation:
	.string "È un SEME MIRACOLO.\n"
	.string "Se un POKéMON tiene questo strumento,\l"
	.string "le sue mosse di tipo ERBA si rinforzano.\p"
	.string "Oltre al SEME MIRACOLO, credo ci siano\n"
	.string "altri strumenti utili da far\l"
	.string "tenere ai POKéMON.$"

PetalburgWoods_Text_TrainerTipsExperience:
	.string "CONSIGLI UTILI\p"
	.string "Ogni POKéMON che appare almeno una volta\n"
	.string "in lotta riceve Punti Esperienza.\p"
	.string "Per allenare un POKéMON debole, mettilo\n"
	.string "a sinistra nella squadra.\p"
	.string "Appena inizia la lotta, cambialo.\n"
	.string "Così guadagna Punti Esperienza senza\l"
	.string "correre alcun pericolo.$"

PetalburgWoods_Text_TrainerTipsPP:
	.string "CONSIGLI PER GLI ALLENATORI\p"
	.string "Oltre ai Punti Vita (PS), i POKéMON\n"
	.string "hanno i Punti Potenza (PP) usati per\l"
	.string "le mosse in battaglia.\p"
	.string "Se i PP finiscono, il POKéMON va\n"
	.string "portato a un CENTRO POKéMON.$"

