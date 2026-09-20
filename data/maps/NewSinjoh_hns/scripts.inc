NewSinjoh_hns_MapScripts::
map_script MAP_SCRIPT_ON_TRANSITION, NewSinjoh_On_Transition
	.byte 0

NewSinjoh_On_Transition:
    setflag FLAG_VISITED_NEW_SINJOH
	end

NewSinjoh_EventScript_TriggerNorthGate::
	lock
	msgbox NewSinjoh_Text_TriggerNorthGate, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	release
	end

NewSinjoh_Text_TriggerNorthGate:
	.string "Meglio non far aspettare\n"
	.string "le ragazze in kimono.$"

NewSinjoh_EventScript_PetStantler::
    lock
	faceplayer
	playmoncry SPECIES_STANTLER, 0
	msgbox NewSinjoh_Text_Stantler_Cry, MSGBOX_DEFAULT
	waitmoncry
    closemessage
	release
	end

NewSinjoh_Text_Stantler_Cry:
    .string "Lerrrrr!$"

NewSinjoh_EventScript_Steven::
	msgbox NewSinjoh_Text_Steven, MSGBOX_AUTOCLOSE
	end

NewSinjoh_Text_Steven:
	.string "STEVEN: Signora, posso\n"
	.string "accompagnarla alla fonte?\p"
	.string "C'è parecchio spazio.$"

NewSinjoh_MilkMan_EventScript_Seller::
	lock
	faceplayer
	checkitem ITEM_MOOMOO_MILK, 99
	goto_if_eq VAR_RESULT, 1, MilkMan_EventScript_Battle
	showmoneybox 0, 0
	msgbox NewSinjoh_MilkMan_text_BuyMilk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, NewSinjoh_EventScript_MilkMan_BuyMilk
	msgbox NewSinjoh_MilkMan_NoSale, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

NewSinjoh_EventScript_MilkMan_BuyMilk::
	checkmoney 500, 0
	goto_if_eq VAR_RESULT, FALSE, NewSinjoh_MilkMan_NotEnough
	additem ITEM_MOOMOO_MILK
	goto_if_eq VAR_RESULT, FALSE, NewSinjoh_MilkMan_BagFull
	removemoney 500
	updatemoneybox 0
	msgbox NewSinjoh_MilkMan_Text_WouldYouLikeAnother, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, NewSinjoh_EventScript_MilkMan_BuyMilk

	msgbox NewSinjoh_MilkMan_GotMilk, MSGBOX_DEFAULT
	closemessage
	playse MUS_OBTAIN_ITEM
	msgbox NewSinjoh_Text_GotMilk, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

NewSinjoh_MilkMan_BagFull::
	msgbox NewSinjoh_MilkMan_NoRoom, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

NewSinjoh_MilkMan_NotEnough::
	msgbox NewSinjoh_MilkMan_NoMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

NewSinjoh_MilkMan_text_BuyMilk:
	.string "Sono il Lattaio.\p"
	.string "Il mio latte è delizioso.\p"
	.string "Se oggi ne vuoi un po', costa\n"
	.string "¥500.$"

NewSinjoh_MilkMan_GotMilk:
	.string "Ecco qua!\n"
	.string "È fortificato con ciò che il mondo vuole.$"

NewSinjoh_MilkMan_NoMoney:
	.string "Mi dispiace.\n"
	.string "Porta dei soldi, poi affare fatto!$"

NewSinjoh_MilkMan_NoRoom:
	.string "Sembra che il tuo ZAINO sia pieno.$"

NewSinjoh_MilkMan_NoSale:
	.string "Non lo vuoi?\n"
	.string "Ha ciò che il mondo merita.$"

NewSinjoh_MilkMan_Text_WouldYouLikeAnother:
	.string "Ne vuoi un altro?$"

NewSinjoh_Text_GotMilk:
	.string "{PLAYER} ha ottenuto il LATTE MUUMUU.$"

MilkMan_EventScript_Battle:: 
    msgbox MilkMan_Battle_text
    Trainerbattle_no_intro TRAINER_MILKMAN_HNS, NewSinjoh_MilkMan_text_Lose
    release
    end

MilkMan_Battle_text:
	.string "Sono il Lattaio,\p"
	.string "il mio latte è delizioso.\p"
	.string "Consegna speciale oggi!$"

NewSinjoh_MilkMan_text_Lose:
	.string "Questo mondo è perfetto,\n"
	.string "non credi?$"

NewSinjoh_Script_TravelMart::
	lock
	faceplayer
	message NewSinjoh_Text_TravelShopGreeting
	waitmessage
	pokemart NewSinjoh_Pokemart_TravelShop
	msgbox NewSinjoh_Text_TravelShopEnd, MSGBOX_DEFAULT
	release
	end

	.align 2
NewSinjoh_Pokemart_TravelShop:
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_REVIVAL_HERB
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_ELIXER
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_MAX_LURE
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NONE

NewSinjoh_Text_TravelShopGreeting:
	.string "Benvenuto nel mio piccolo emporio.\n"
	.string "Come posso aiutarti?$"

NewSinjoh_Text_TravelShopEnd:
	.string "Torna a trovarci.$"

Script_NewSinjoh_Traveler_Brother::
	lock
	faceplayer
	msgbox NewSinjoh_Text_TravelBrother_Greeting
	release
	end

NewSinjoh_Text_TravelBrother_Greeting:
    .string "La nostra merce è fatta\n"
	.string "in casa e coltivata qui!\p"
	.string "Mia sorella ha aperto il negozio,\n"
	.string "perché la POKéMART non apre\l"
	.string "una filiale così lontano\l"
	.string "da una grande città.$"

NewSinjoh_EventScript_Josh::
	msgbox NewSinjoh_Text_Josh, MSGBOX_NPC
	end

NewSinjoh_Text_Josh:
	.string "Questo posto è assurdo!\p"
	.string "Tenere nascoste queste sorgenti\n"
	.string "al mondo è un delitto.\p"
	.string "Lo dirò a tutti i miei amici!$"

NewSinjoh_EventScript_Janice::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_JaniceAfter
	msgbox NewSinjoh_Text_Janice, MSGBOX_NPC
	end
NewSinjoh_EventScript_JaniceAfter::
	msgbox NewSinjoh_Text_JaniceAfter, MSGBOX_NPC
	end

NewSinjoh_Text_Janice:
	.string "Queste sorgenti sono magiche,\n"
	.string "ma mi sembra che i locali\l"
	.string "ci guardino male.$"
NewSinjoh_Text_JaniceAfter:
	.string "Queste sorgenti sono magiche,\n"
	.string "e i locali sono gentilissimi\l"
	.string "quando li conosci!$"

NewSinjoh_EventScript_OldLady1::
	msgbox NewSinjoh_Text_OldLady1, MSGBOX_NPC
	end

NewSinjoh_Text_OldLady1:
	.string "Non c'è niente come un bel panorama\n"
	.string "per rinvigorire questa vecchia anima.$"

NewSinjoh_EventScript_OldLady2::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_OldLady2Steven
	msgbox NewSinjoh_Text_OldLady2, MSGBOX_NPC
	end
NewSinjoh_EventScript_OldLady2Steven::
	msgbox NewSinjoh_Text_OldLady2Steven, MSGBOX_NPC
	end

NewSinjoh_Text_OldLady2:
	.string "Ottimo, ora questi turisti\n"
	.string "occupano le nostre sorgenti!\p"
	.string "Ultimamente è una disgrazia\n"
	.string "dietro l'altra!$"
NewSinjoh_Text_OldLady2Steven:
	.string "Che bel giovanotto!\p"
	.string "Forse questi turisti non sono\n"
	.string "poi così male.$"

NewSinjoh_EventScript_OldLady3::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_OldLady3After
	msgbox NewSinjoh_Text_OldLady3, MSGBOX_NPC
	end
NewSinjoh_EventScript_OldLady3After::
	msgbox NewSinjoh_Text_OldLady3After, MSGBOX_NPC
	end

NewSinjoh_Text_OldLady3:
	.string "Come può quella donna\n"
	.string "essere così sgarbata con gli ospiti?\p"
	.string "Dovrebbe fare un bagno\n"
	.string "alle sorgenti. \p"
	.string "C'è spazio in abbondanza\n"
	.string "per tutti.$"
NewSinjoh_Text_OldLady3After:
	.string "Sembra che tutti si stiano\n"
	.string "abituando gli uni agli altri.\p"
	.string "Bene!$"

NewSinjoh_EventScript_SpringsSage::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_SpringsSageAfter
	msgbox NewSinjoh_Text_SpringsSage, MSGBOX_NPC
	end
NewSinjoh_EventScript_SpringsSageAfter::
	msgbox NewSinjoh_Text_SpringsSageAfter, MSGBOX_NPC
	end

NewSinjoh_Text_SpringsSage:
	.string "Da quando sono arrivati\n"
	.string "i nuovi arrivati, nella\l"
	.string "nostra comunità regnano\p"
	.string "divisione e conflitti.\n"
	.string "Qualunque sia la tua idea,\l"
	.string "l'equilibrio è stato rotto.\p"
	.string "Siate gentili con i locali\n"
	.string "e con i turisti.$"
NewSinjoh_Text_SpringsSageAfter:
	.string "Le cose vanno meglio da quando\n"
	.string "i POKéMON leggendari sono stati placati.\p"
	.string "L'equilibrio è tornato a SINJOH.$"

NewSinjoh_EventScript_Sage2::
	msgbox NewSinjoh_Text_Sage2, MSGBOX_NPC
	end

NewSinjoh_Text_Sage2:
	.string "I tempi cambiano, ma gli STANTLER\n"
	.string "si radunano ancora. Per questo\l"
	.string "siamo grati.$"

NewSinjoh_EventScript_Daughter::
	msgbox NewSinjoh_Text_Daughter, MSGBOX_NPC
	end

NewSinjoh_Text_Daughter:
    .string "Wiiiiii!!\p"
    .string "Guarda, mamma!\n"
    .string "Senza mani!\p"
	.string "Come gli snowboarder!$"

NewSinjoh_EventScript_Mother::
	lock
	faceplayer
	msgbox NewSinjoh_Text_Mother, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_NEWSINJOH_MOTHER, DIR_EAST
	release
	end

NewSinjoh_Text_Mother:
    .string "Guarda la mia bimba che va!\p"
    .string "Questa pista esiste da\n"
	.string "generazioni, ma i bambini\l"
	.string "non l'usavano finché non\l"
	.string "sono arrivati i nuovi.$"

NewSinjoh_EventScript_Welcome_Sign::
	msgbox NewSinjoh_Text_Welcome_Sign, MSGBOX_SIGN
	end

NewSinjoh_Text_Welcome_Sign:
	.string "NUOVA SINJOH$"

NewSinjoh_EventScript_Resturant_Sign::
	msgbox NewSinjoh_Text_Resturant_Sign, MSGBOX_SIGN
	end

NewSinjoh_Text_Resturant_Sign:
	.string "CAFFÈ FAMIGLIA$"

NewSinjoh_EventScript_Cave_Sign::
	msgbox NewSinjoh_Text_Cave_Sign, MSGBOX_SIGN
	end

NewSinjoh_Text_Cave_Sign:
	.string "GROTTA TERMALE$"

NewSinjoh_EventScript_Hiker::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_HikerAfter
	msgbox NewSinjoh_Text_Hiker, MSGBOX_NPC
	end
NewSinjoh_EventScript_HikerAfter::
	msgbox NewSinjoh_Text_HikerAfter, MSGBOX_NPC
	end

NewSinjoh_Text_Hiker:
	.string "Gli affari vanno a gonfie vele!\n"
	.string "Ma i prezzi sono saliti da quando\l"
	.string "la gente di città si interessa\l"
	.string "alla nostra cittadina.$"
NewSinjoh_Text_HikerAfter:
	.string "Gli affari vanno a gonfie vele!\p"
	.string "E con le mance di quel tipo\n"
	.string "dai capelli argento, i prezzi sono scesi!$"

NewSinjoh_EventScript_OldLady4::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_OldLady4After
	msgbox NewSinjoh_Text_OldLady4, MSGBOX_NPC
	end
NewSinjoh_EventScript_OldLady4After::
	msgbox NewSinjoh_Text_OldLady4After, MSGBOX_NPC
	end

NewSinjoh_Text_OldLady4:
	.string "Vendo solo ai locali!$"
NewSinjoh_Text_OldLady4After:
	.string "Vendo ANCORA solo ai locali!$"

NewSinjoh_EventScript_Item_DuskBall::
	finditem ITEM_DUSK_BALL
    end


