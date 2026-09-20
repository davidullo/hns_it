Route32_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route32_PokemonCenter_OnTransition	
	.byte 0

Route32_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_ROUTE_32_HNS
	end

Route32_PokemonCenter_EventScript_Lass::
	lock
	faceplayer
	msgbox Route32_Pokecenter_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

Route32_PokemonCenter_EventScript_FishingGuru::
	lock
	faceplayer
	checkitem ITEM_OLD_ROD
	goto_if_eq VAR_RESULT, TRUE, Route32_PokemonCenter_EventScript_FishingGuru3
	msgbox Route32_Pokecenter_Text_FishingGuruQuestion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route32_PokemonCenter_EventScript_FishingGuru2
	msgbox Route32_Pokecenter_Text_FishingGuruNo, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_PokemonCenter_EventScript_FishingGuru2::
	msgbox Route32_Pokecenter_Text_FishingGuruYes, MSGBOX_DEFAULT
	giveitem ITEM_OLD_ROD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route32_Pokecenter_Text_FishingGuruGiveRod, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_PokemonCenter_EventScript_FishingGuru3::
	msgbox Route32_Pokecenter_Text_FishingGuruAfter, MSGBOX_DEFAULT
	release
	end



Route32_Pokecenter_Text_FishingGuruQuestion:
	.string "Qui si pesca benissimo.\p"
	.string "Hai visto gente pescare?\n"
	.string "E tu?\p"
	.string "Vuoi una delle mie CANNE?$"

Route32_Pokecenter_Text_FishingGuruYes:
	.string "Eh, mi fa piacere.\p"
	.string "Ora sei un Pescatore anche tu!$"

Route32_Pokecenter_Text_FishingGuruGiveRod:
	.string "Pescare è fantastico!\p"
	.string "Se c'è acqua, che sia mare o\n"
	.string "fiume, prova la tua CANNA.$"

Route32_Pokecenter_Text_FishingGuruNo:
	.string "Oh. Che delusione…$"

Route32_Pokecenter_Text_FishingGuruAfter:
	.string "Ehi, ragazzo. Come abboccano?$"

Route32_Pokecenter_Text_CooltrainerF:
	.string "Cosa faccio tenere ai miei POKéMON?\p"
	.string "Forse uno strumento che aumenta\n"
	.string "l'ATTACCO…$"

