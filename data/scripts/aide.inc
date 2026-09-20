Aide_EventScript_HaventCaughtEnough::
	msgbox Aide_Text_HaventCaughtEnoughMonsForItem
	release
	end

Aide_EventScript_NoRoomForItem::
	msgbox Aide_Text_DontHaveAnyRoomForItem
	release
	end

Aide_EventScript_DeclineCheckMons::
	msgbox Aide_Text_GetEnoughMonsComeBackForItem
	release
	end

Aide_Text_HaventCaughtEnoughMonsForItem::
	.string "Vediamo…\n"
	.string "Uh-oh! Hai catturato solo\l"
	.string "{STR_VAR_3} specie di POKéMON!\p"
	.string "Ti servono {STR_VAR_1} specie\n"
	.string "se vuoi {STR_VAR_2}.$"

Aide_Text_GetEnoughMonsComeBackForItem::
	.string "…Oh. Capisco.\p"
	.string "Quando avrai {STR_VAR_1} specie di POKéMON,\n"
	.string "torna per {STR_VAR_2}.$"

Aide_Text_DontHaveAnyRoomForItem::
	.string "Oh! Vedo che non hai\n"
	.string "spazio per {STR_VAR_2}.$"
