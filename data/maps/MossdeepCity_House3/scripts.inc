MossdeepCity_House3_MapScripts::
	.byte 0

MossdeepCity_House3_EventScript_SuperRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SUPER_ROD, MossdeepCity_House3_EventScript_ReceivedSuperRod
	msgbox MossdeepCity_House3_Text_YouWantSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_House3_EventScript_DeclineSuperRod
	msgbox MossdeepCity_House3_Text_SuperRodIsSuper, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox MossdeepCity_House3_Text_TryDroppingRodInWater, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_ReceivedSuperRod::
	msgbox MossdeepCity_House3_Text_GoAfterSeafloorPokemon, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_DeclineSuperRod::
	msgbox MossdeepCity_House3_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_Text_YouWantSuperRod:
	.string "Ehi, ALLENATORE!\n"
	.string "Il SUPER AMO è davvero super!\p"
	.string "Dì quel che vuoi, ma questo gioiello\n"
	.string "cattura i POKéMON del fondale!\p"
	.string "Che ne dici?\n"
	.string "Lo vuoi, vero?$"

MossdeepCity_House3_Text_SuperRodIsSuper:
	.string "Sì, sì!\n"
	.string "Dopotutto, il SUPER AMO è davvero super!$"

MossdeepCity_House3_Text_TryDroppingRodInWater:
	.string "Se c'è dell'acqua, prova a calare\n"
	.string "l'AMO e vedi cosa abbocca!$"

MossdeepCity_House3_Text_DontYouLikeToFish:
	.string "Eh?\n"
	.string "Non ti piace pescare?$"

MossdeepCity_House3_Text_GoAfterSeafloorPokemon:
	.string "Vai a cercare i POKéMON del fondale\n"
	.string "con il SUPER AMO.$"

