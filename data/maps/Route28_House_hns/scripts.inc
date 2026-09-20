Route28_House_hns_MapScripts::
	.byte 0

Route28House_EventScript_Celebrity::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_STEEL_WING, Route28House_EventScript_CelebrityAfter
	msgbox Route28House_Text_Celebrity1, MSGBOX_NPC
	giveitem ITEM_TM_STEEL_WING
	setflag FLAG_GOT_TM_STEEL_WING
Route28House_EventScript_CelebrityAfter::
	msgbox Route28House_Text_Celebrity2, MSGBOX_NPC
	release
	end

Route28House_Text_Celebrity1:
	.string "Oh, cielo. Mi hai trovato.\p"
	.string "Non dire a nessuno di me.\p"
	.string "Ti darò questo se tieni il\n"
	.string "segreto. Ti prego?$"

Route28House_Text_Celebrity2:
	.string "È dura essere una star.\p"
	.string "Ovunque vada, la gente mi insegue.\p"
	.string "Voglio solo essere lasciato in pace…$"

Route28House_Text_Fearow:
	.string "FEAROW: Fiirou!$"

