LilycoveCity_CoveLilyMotel_2F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
	lock
	faceplayer
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	specialvar VAR_RESULT, HasAllRegionalMons
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
	setflag FLAG_TEMP_2
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	specialvar VAR_RESULT, HasAllMons
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_TryGiveShinyCharm
	specialvar VAR_RESULT, HasAllRegionalMons
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_TryGiveOvalCharm
	special Special_ShowDiploma
	waitstate

	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_TryGiveOvalCharm::
	checkitem ITEM_OVAL_CHARM
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_CoveLilyMotel_2F_EventScript_GiveOvalCharm
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_GiveOvalCharm::
	giveitem ITEM_OVAL_CHARM
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_TryGiveShinyCharm::
	checkitem ITEM_SHINY_CHARM
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_CoveLilyMotel_2F_EventScript_GiveShinyCharm
	checkitem ITEM_OVAL_CHARM
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_CoveLilyMotel_2F_EventScript_GiveOvalCharm
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_GiveShinyCharm::
	giveitem ITEM_SHINY_CHARM
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
	.string "I'm the GAME DESIGNER.\p"
	.string "Oh, is that right?\n"
	.string "You're working on a POKéDEX?\p"
	.string "It's tough trying to complete it,\n"
	.string "but don't give up.\p"
	.string "If you do complete it, please come\n"
	.string "show me.$"

LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
	.string "Wow! Fantastico!\n"
	.string "Sì, davvero fantastico!\p"
	.string "Questo POKéDEX è completo!\n"
	.string "Devi amare molto i POKéMON!\p"
	.string "Sono impressionato!\p"
	.string "Lascia che ti dia qualcosa per\n"
	.string "questa impresa!$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
	.string "Io? Parli con me?\n"
	.string "Sono il PROGRAMMER.\p"
	.string "Chissà come sono le SLOT\n"
	.string "qui.$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
	.string "Sono il GRAPHIC ARTIST! I POKéMON\n"
	.string "di HOENN non sono interessanti?$"

LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute:
	.string "Le TUBER, sono carine, eh?\n"
	.string "Lottare contro una TUBER carina…\p"
	.string "Whoop, che bello!\p"
	.string "E i GEMELLI! Non sono carini?\n"
	.string "Una lotta 2 contro 2 coi GEMELLI…\p"
	.string "Whoop, che divertimento!$"

LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
	.string "La brezza di mare mi solletica\n"
	.string "il cuore. Che bello qui!$"

LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
	.string "You never know when and where\n"
	.string "people will challenge you.\p"
	.string "That's why I never leave home without\n"
	.string "my GAME BOY ADVANCE.$"

LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
	.string "SCOTT: … … … … …\n"
	.string "… … … … … Zzz…\p"
	.string "… … … … … Huh?!\n"
	.string "Oh, sorry, sorry! I was snoozing!\p"
	.string "I came to check out this POKéMON\n"
	.string "CONTEST thing.\p"
	.string "I have to admit, it does look quite\n"
	.string "entertaining, but…\p"
	.string "Consider me a purist--I prefer\n"
	.string "battles and tough TRAINERS.\p"
	.string "But that's just me.\p"
	.string "{PLAYER}{KUN}, I hope you'll enjoy everything\n"
	.string "like the GYMS, CONTESTS, BATTLE TENT,\l"
	.string "the whole works!$"

LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
	.string "SCOTT: credo che per vincere una\n"
	.string "GARA ci voglia strategia.\p"
	.string "Studiare strategie per le GARE è\n"
	.string "un modo per migliorare come ALLENATORE.$"

