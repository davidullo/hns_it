FortreeCity_House5_MapScripts::
	.byte 0

FortreeCity_House5_EventScript_PokefanF::
	msgbox FortreeCity_House5_Text_TreeHousesAreGreat, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Man::
	msgbox FortreeCity_House5_Text_AdaptedToNature, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House5_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House5_Text_TreeHousesAreGreat:
	.string "Le case sugli alberi di FORTREE\p"
	.string "son bellissime: la città numero uno\n"
	.string "per vivere coi POKéMON.$"

FortreeCity_House5_Text_AdaptedToNature:
	.string "POKéMON e persone si sono adattati\n"
	.string "alla natura.\p"
	.string "Non serve che la natura si\n"
	.string "adegui al nostro modo di vivere.$"

FortreeCity_House5_Text_Zigzagoon:
	.string "ZIGZAGOON: Bufuu!$"

