FiveIsland_MemorialPillar_Frlg_MapScripts::
	.byte 0

FiveIsland_MemorialPillar_EventScript_MemorialMan::
	lock
	goto_if_set FLAG_GOT_TM42_AT_MEMORIAL_PILLAR, FiveIsland_MemorialPillar_EventScript_AlreadyGotTM42
	goto_if_set FLAG_NO_ROOM_FOR_TM42_AT_MEMORIAL_PILLAR, FiveIsland_MemorialPillar_EventScript_ReturnedForTM42
	msgbox FiveIsland_MemorialPillar_Text_ScrubScrub
	closemessage
	applymovement LOCALID_MEMORIAL_MAN, Common_Movement_FacePlayer
	waitmovement 0
	delay 45
	msgbox FiveIsland_MemorialPillar_Text_YourMonsLookHealthy
	applymovement LOCALID_MEMORIAL_MAN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox FiveIsland_MemorialPillar_Text_ThisIsWhereIBuriedMyOnix
	release
	end

FiveIsland_MemorialPillar_EventScript_AlreadyGotTM42::
	msgbox FiveIsland_MemorialPillar_Text_ScrubScrubTectonix
	release
	end

FiveIsland_MemorialPillar_EventScript_ReturnedForTM42::
	msgbox FiveIsland_MemorialPillar_Text_StillHaveThingAsMyThanks
	giveitem ITEM_TM42
	goto_if_eq VAR_RESULT, FALSE, FiveIsland_MemorialPillar_EventScript_NoRoomForTM42
	call FiveIsland_MemorialPillar_EventScript_ReceivedTM42
	release
	end

FiveIsland_MemorialPillar_EventScript_Memorial::
	lockall
	goto_if_set FLAG_GOT_TM42_AT_MEMORIAL_PILLAR, FiveIsland_MemorialPillar_EventScript_MemorialLemonadeAlreadyPlaced
	goto_if_set FLAG_NO_ROOM_FOR_TM42_AT_MEMORIAL_PILLAR, FiveIsland_MemorialPillar_EventScript_MemorialLemonadeAlreadyPlaced
	msgbox FiveIsland_MemorialPillar_Text_HereLiesTectonixLemonadeOffering
	checkitem ITEM_LEMONADE
	goto_if_eq VAR_RESULT, TRUE, FiveIsland_MemorialPillar_EventScript_AskPlaceLemonade
	releaseall
	end

FiveIsland_MemorialPillar_EventScript_AskPlaceLemonade::
	msgbox FiveIsland_MemorialPillar_Text_LeaveAnotherLemonadeOffering, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FiveIsland_MemorialPillar_EventScript_PlaceLemonade
	releaseall
	end

FiveIsland_MemorialPillar_EventScript_PlaceLemonade::
	removeitem ITEM_LEMONADE
	msgbox FiveIsland_MemorialPillar_Text_PlacedCanOfLemonade
	closemessage
	applymovement LOCALID_MEMORIAL_MAN, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 45
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox FiveIsland_MemorialPillar_Text_ThankYouPleaseTakeThis
	giveitem ITEM_TM42
	goto_if_eq VAR_RESULT, FALSE, FiveIsland_MemorialPillar_EventScript_NoRoomForTM42
	call FiveIsland_MemorialPillar_EventScript_ReceivedTM42
	releaseall
	end

FiveIsland_MemorialPillar_EventScript_ReceivedTM42::
	msgbox FiveIsland_MemorialPillar_Text_BeGoodToYourMonsToo
	applymovement LOCALID_MEMORIAL_MAN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	setflag FLAG_GOT_TM42_AT_MEMORIAL_PILLAR
	return

FiveIsland_MemorialPillar_EventScript_NoRoomForTM42::
	setflag FLAG_NO_ROOM_FOR_TM42_AT_MEMORIAL_PILLAR
	msgbox FiveIsland_MemorialPillar_Text_DontHaveRoomForIt
	releaseall
	end

FiveIsland_MemorialPillar_EventScript_MemorialLemonadeAlreadyPlaced::
	msgbox FiveIsland_MemorialPillar_Text_HereLiesTectonix
	releaseall
	end

FiveIsland_MemorialPillar_Text_MiloIntro::
	.string "I'm the eldest of the BIRD\n"
	.string "BROTHERS.\p"
	.string "The best thing about birds…\n"
	.string "It has to be the beak.$"

FiveIsland_MemorialPillar_Text_MiloDefeat::
	.string "Che affilato!$"

FiveIsland_MemorialPillar_Text_MiloPostBattle::
	.string "Da qui puoi andare in Volo\n"
	.string "a ISOLA QUATTRO.$"

FiveIsland_MemorialPillar_Text_ChazIntro::
	.string "I'm the middle kid of the BIRD\n"
	.string "BROTHERS.\p"
	.string "The best thing about birds…\n"
	.string "It has to be the wings.$"

FiveIsland_MemorialPillar_Text_ChazDefeat::
	.string "Fla, fla!$"

FiveIsland_MemorialPillar_Text_ChazPostBattle::
	.string "C'era un tipo davvero cupo\n"
	.string "di là.$"

FiveIsland_MemorialPillar_Text_HaroldIntro::
	.string "Sono l'ultimo dei FRATELLI\n"
	.string "UCCELLO.\p"
	.string "Il bello degli uccelli…\n"
	.string "Sono le piume.$"

FiveIsland_MemorialPillar_Text_HaroldDefeat::
	.string "Che bel piumino…\n"
	.string "Mi fa dormire…$"

FiveIsland_MemorialPillar_Text_HaroldPostBattle::
	.string "Vedere i POKéMON uccello\n"
	.string "giocare mi dà felicità…$"

FiveIsland_MemorialPillar_Text_ScrubScrub::
	.string "Sfreg, sfreg…$"

FiveIsland_MemorialPillar_Text_YourMonsLookHealthy::
	.string "Ciao…\n"
	.string "I tuoi POKéMON in forma…$"

FiveIsland_MemorialPillar_Text_ThisIsWhereIBuriedMyOnix::
	.string "Qui ho sepolto il mio ONIX…\n"
	.string "Si chiamava TECTONIX…$"

FiveIsland_MemorialPillar_Text_HereLiesTectonixLemonadeOffering::
	.string "“Qui giace TECTONIX” è inciso\n"
	.string "su un masso.\p"
	.string "Un LEMONSUCCO è lasciato come\n"
	.string "offerta davanti alla tomba.$"

FiveIsland_MemorialPillar_Text_LeaveAnotherLemonadeOffering::
	.string "Vuoi lasciare come offerta\n"
	.string "un altro LEMONSUCCO?$"

FiveIsland_MemorialPillar_Text_PlacedCanOfLemonade::
	.string "{PLAYER} ha lasciato un LEMONSUCCO\n"
	.string "davanti alla tomba.$"

FiveIsland_MemorialPillar_Text_ThankYouPleaseTakeThis::
	.string "G-grazie…\p"
	.string "È il drink preferito\n"
	.string "di TECTONIX…\p"
	.string "Non ti conosco, ma il tuo\n"
	.string "gesto gentile…\p"
	.string "Mi ha tirato un po' su.\p"
	.string "Accettalo come mio\n"
	.string "grazie?$"

FiveIsland_MemorialPillar_Text_BeGoodToYourMonsToo::
	.string "Sii buono anche coi tuoi\n"
	.string "POKéMON.$"

FiveIsland_MemorialPillar_Text_DontHaveRoomForIt::
	.string "Se non hai posto,\n"
	.string "lo tengo per la prossima volta.$"

FiveIsland_MemorialPillar_Text_StillHaveThingAsMyThanks::
	.string "Oh, sei tu di quella volta…\p"
	.string "Ho ancora la cosa che volevo\n"
	.string "darti per ringraziarti.$"

FiveIsland_MemorialPillar_Text_ScrubScrubTectonix::
	.string "Sfreg, sfreg…\p"
	.string "… … …\n"
	.string "TECTONIX…$"

FiveIsland_MemorialPillar_Text_HereLiesTectonix::
	.string "Massi e rocce impilati con cura\n"
	.string "in un tumulo.\p"
	.string "“Qui giace TECTONIX” è inciso\n"
	.string "su un masso.$"

