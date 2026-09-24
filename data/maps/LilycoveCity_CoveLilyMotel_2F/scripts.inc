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
	.string "Sono il GAME DESIGNER.\p"
	.string "Ah, davvero?\n"
	.string "Lavori a un POKéDEX?\p"
	.string "È dura finirlo,\n"
	.string "ma non arrenderti.\p"
	.string "Se ci riuscirai, vieni\n"
	.string "a mostrarmelo.$"

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
	.string "Non sai mai quando e dove\n"
	.string "ti sfideranno.\p"
	.string "Perciò non esco mai senza\n"
	.string "il GAME BOY ADVANCE.$"

LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
	.string "SAVERIO: … … … … …\n"
	.string "… … … … … Zzz…\p"
	.string "… … … … … Eh?!\n"
	.string "Oh, scusa, scusa! Sonno!\p"
	.string "Sono qui per vedere la\n"
	.string "GARA POKéMON.\p"
	.string "Ammetto che sembra proprio\n"
	.string "divertente, ma…\p"
	.string "Sono un purista: amo\n"
	.string "lotte e ALLENATORI tosti.\p"
	.string "Ma son fatto così.\p"
	.string "{PLAYER}{KUN}, goditi tutto:\n"
	.string "PALESTRE, GARE, TENDONE LOTTA,\l"
	.string "tutto quanto!$"

LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
	.string "SAVERIO: credo che per vincere una\n"
	.string "GARA ci voglia strategia.\p"
	.string "Studiare strategie per le GARE è\n"
	.string "un modo per migliorare come ALLENATORE.$"

