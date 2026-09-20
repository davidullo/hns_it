MtMoon_B2F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMoon_B2F_OnTransition
	.byte 0

MtMoon_B2F_OnTransition::
	call_if_unset FLAG_GOT_FOSSIL_FROM_MT_MOON, MtMoon_B2F_EventScript_ShowFossils
	end

MtMoon_B2F_EventScript_ShowFossils::
	clearflag FLAG_HIDE_DOME_FOSSIL
	clearflag FLAG_HIDE_HELIX_FOSSIL
	return

MtMoon_B2F_EventScript_MiguelTrigger::
	lockall
	applymovement LOCALID_MIGUEL, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	call MtMoon_B2F_EventScript_BattleMiguel
	releaseall
	end

MtMoon_B2F_EventScript_Miguel::
	lock
	faceplayer
	goto_if_set FLAG_GOT_FOSSIL_FROM_MT_MOON, MtMoon_B2F_EventScript_MiguelFossilPicked
	goto_if_defeated TRAINER_SUPER_NERD_MIGUEL, MtMoon_B2F_EventScript_MiguelGoPickFossil
	call MtMoon_B2F_EventScript_BattleMiguel
	release
	end

MtMoon_B2F_EventScript_BattleMiguel::
	textcolor NPC_TEXT_COLOR_MALE
	message MtMoon_B2F_Text_MiguelIntro
	waitmessage
	playbgm MUS_RG_ENCOUNTER_GYM_LEADER, 0
	waitbuttonpress
	setvar VAR_LAST_TALKED, LOCALID_MIGUEL
	trainerbattle_no_intro TRAINER_SUPER_NERD_MIGUEL, MtMoon_B2F_Text_MiguelDefeat
	setvar VAR_MAP_SCENE_MT_MOON_B2F, 1
	msgbox MtMoon_B2F_Text_WellEachTakeAFossil
	return

MtMoon_B2F_EventScript_MiguelFossilPicked::
	msgbox MtMoon_B2F_Text_LabOnCinnabarRegeneratesFossils
	release
	end

MtMoon_B2F_EventScript_MiguelGoPickFossil::
	msgbox MtMoon_B2F_Text_WellEachTakeAFossil
	release
	end

MtMoon_B2F_EventScript_DomeFossil::
	lock
	faceplayer
	msgbox MtMoon_B2F_Text_YouWantDomeFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtMoon_B2F_EventScript_DontTakeFossil
	removeobject LOCALID_DOME_FOSSIL
	giveitem_msg MtMoon_B2F_Text_ObtainedDomeFossil, ITEM_DOME_FOSSIL, 1, MUS_RG_OBTAIN_KEY_ITEM
	closemessage
	delay 10
	applymovement LOCALID_MIGUEL, MtMoon_B2F_Movement_MiguelToHelixFossil
	waitmovement 0
	copyobjectxytoperm LOCALID_MIGUEL
	textcolor NPC_TEXT_COLOR_MALE
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message MtMoon_B2F_Text_ThenThisFossilIsMine
	waitmessage
	waitfanfare
	removeobject LOCALID_HELIX_FOSSIL
	setflag FLAG_GOT_DOME_FOSSIL
	setflag FLAG_GOT_FOSSIL_FROM_MT_MOON
	release
	end

MtMoon_B2F_Movement_MiguelToHelixFossil::
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

MtMoon_B2F_EventScript_HelixFossil::
	lock
	faceplayer
	msgbox MtMoon_B2F_Text_YouWantHelixFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtMoon_B2F_EventScript_DontTakeFossil
	removeobject LOCALID_HELIX_FOSSIL
	giveitem_msg MtMoon_B2F_Text_ObtainedHelixFossil, ITEM_HELIX_FOSSIL, 1, MUS_RG_OBTAIN_KEY_ITEM
	closemessage
	delay 10
	applymovement LOCALID_MIGUEL, MtMoon_B2F_Movement_MiguelToDomeFossil
	waitmovement 0
	copyobjectxytoperm LOCALID_MIGUEL
	textcolor NPC_TEXT_COLOR_MALE
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message MtMoon_B2F_Text_ThenThisFossilIsMine
	waitmessage
	waitfanfare
	removeobject LOCALID_DOME_FOSSIL
	setflag FLAG_GOT_HELIX_FOSSIL
	setflag FLAG_GOT_FOSSIL_FROM_MT_MOON
	release
	end

MtMoon_B2F_EventScript_DontTakeFossil::
	release
	end

MtMoon_B2F_Movement_MiguelToDomeFossil::
	walk_up
	walk_up
	walk_up
	step_end

MtMoon_B2F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT, MtMoon_B2F_Text_Grunt1Intro, MtMoon_B2F_Text_Grunt1Defeat
	msgbox MtMoon_B2F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_2, MtMoon_B2F_Text_Grunt2Intro, MtMoon_B2F_Text_Grunt2Defeat
	msgbox MtMoon_B2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_3, MtMoon_B2F_Text_Grunt3Intro, MtMoon_B2F_Text_Grunt3Defeat
	msgbox MtMoon_B2F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_EventScript_Grunt4::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_4, MtMoon_B2F_Text_Grunt4Intro, MtMoon_B2F_Text_Grunt4Defeat
	msgbox MtMoon_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_Text_MiguelIntro::
	.string "Ehi, fermo!\p"
	.string "Ho trovato io questi fossili!\n"
	.string "Sono tutti e due miei!$"

MtMoon_B2F_Text_MiguelDefeat::
	.string "Okay!\n"
	.string "Ti do il mio!$"

MtMoon_B2F_Text_WellEachTakeAFossil::
	.string "Prendiamo un fossile a testa!\n"
	.string "Niente ingordigia!$"

MtMoon_B2F_Text_ThenThisFossilIsMine::
	.string "Va bene.\n"
	.string "Allora questo fossile è mio!$"

MtMoon_B2F_Text_LabOnCinnabarRegeneratesFossils::
	.string "Lontano, sull'ISOLA di CINNABAR,\n"
	.string "c'è un LABORATORIO POKéMON.\p"
	.string "Studiano la rigenerazione dei\n"
	.string "fossili.$"

MtMoon_B2F_Text_Grunt1Intro::
	.string "Noi, il TEAM ROCKET, troveremo\n"
	.string "i fossili!\p"
	.string "Far rivivere POKéMON da essi ci\n"
	.string "porterà enormi ricchezze!$"

MtMoon_B2F_Text_Grunt1Defeat::
	.string "Urgh!\n"
	.string "Ora sono furioso!$"

MtMoon_B2F_Text_Grunt1PostBattle::
	.string "Mi hai fatto arrabbiare!\n"
	.string "Il TEAM ROCKET ti metterà in lista nera!$"

MtMoon_B2F_Text_Grunt2Intro::
	.string "Noi del TEAM ROCKET siamo\n"
	.string "gangster dei POKéMON!\l"
	.string "Seminiamo terrore con la nostra forza!$"

MtMoon_B2F_Text_Grunt2Defeat::
	.string "Ho fatto un pasticcio!$"

MtMoon_B2F_Text_Grunt2PostBattle::
	.string "Accidenti!\n"
	.string "I miei compagni non la passeranno liscia!$"

MtMoon_B2F_Text_Grunt3Intro::
	.string "Stiamo facendo un grosso colpo qui!\n"
	.string "Vattene, ragazzino!$"

MtMoon_B2F_Text_Grunt3Defeat::
	.string "Quindi sei forte…$"

MtMoon_B2F_Text_Grunt3PostBattle::
	.string "Se trovi un fossile, dammelo\n"
	.string "e levati di torno!$"

MtMoon_B2F_Text_Grunt4Intro::
	.string "I ragazzini non dovrebbero immischiarsi\n"
	.string "con i grandi!\p"
	.string "Potrebbero passare guai!$"

MtMoon_B2F_Text_Grunt4Defeat::
	.string "Sono furioso!$"

MtMoon_B2F_Text_Grunt4PostBattle::
	.string "I POKéMON vivevano qui molto prima\n"
	.string "che arrivassero gli uomini.$"

MtMoon_B2F_Text_YouWantDomeFossil::
	.string "Vuoi il FOSSILE DOMA?$"

MtMoon_B2F_Text_YouWantHelixFossil::
	.string "Vuoi il FOSSILE ELICA?$"

MtMoon_B2F_Text_ObtainedHelixFossil::
	.string "Hai ottenuto il FOSSILE ELICA!$"

MtMoon_B2F_Text_ObtainedDomeFossil::
	.string "Hai ottenuto il FOSSILE DUOMO!$"

