NewSinjoh_House1_hns_MapScripts::
	.byte 0


NewSinjoh__House1_EventScripts_Elizabeth::
    lock
	faceplayer
	goto_if_set FLAG_NEWSINJOH_HOUSE1_ELIZABETH_GAVEWOOPER, NewSinjoh_House1_EventScript_Elizabeth_AfterGift
    msgbox NewSinjoh_House1_Text_Looking4Celebi MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, NewSinjoh_House1_EventScript_Decline
    checkspecies SPECIES_CELEBI
    goto_if_eq VAR_RESULT, TRUE, NewSinjoh_House1_EventScript_GiveWooperPaldea
	msgbox NewSinjoh_House1_Text_NicePokemonButNotCelebi, MSGBOX_DEFAULT
    release
    end

NewSinjoh_House1_EventScript_Decline::
	msgbox NewSinjoh_House1_Text_Decline, MSGBOX_DEFAULT
	closemessage
	release
	end

NewSinjoh_House1_EventScript_GiveWooperPaldea::
	playse SE_PIN
    applymovement LOCALID_NEWSINJOH_HOUSE1_ELIZABETH, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_NEWSINJOH_HOUSE1_ELIZABETH
    msgbox NewSinjoh_House1_OffersWooper MSGBOX_DEFAULT
    setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_WOOPER_PALDEA
    bufferspeciesname STR_VAR_1, SPECIES_WOOPER_PALDEA
    givemon SPECIES_WOOPER_PALDEA, 5
	call Common_EventScript_GiftMon
	setflag FLAG_NEWSINJOH_HOUSE1_ELIZABETH_GAVEWOOPER
	closemessage
    release
    end

NewSinjoh_House1_Text_Looking4Celebi:
    .string "Hey there, Trainer!\p"
	.string "You came all the way from\n"
	.string "NEW BARK TOWN?\p"
	.string "I have a request for someone as\n"
	.string "well traveled as you are.\l"
	.string "You see, my favorite POKEMON in the\l"
	.string "whole world just so happens to be\l"
	.string "the mythical POKEMON known as CELEBI.\p"
	.string "If you happen to have one, would\n"
	.string "you mind showing it to me?$"

NewSinjoh_House1_Text_NicePokemonButNotCelebi:
    .string "Hai un POKéMON bellissimo,\n"
	.string "ma non è proprio\l"
	.string "quello che cercavo..$"

NewSinjoh_House1_OffersWooper:
    .string "Ecco! È un vero CELEBI vivente!!\p"
	.string "Grazie per averlo portato\n"
	.string "fin quassù apposta per me.\p"
    .string "Tieni, la mia ragazza ne ha\n"
	.string "presi troppi durante il suo\l"
	.string "viaggio in una regione lontana..\p"
    .string "Prendi questo WOOPER speciale come\n"
	.string "ringraziamento, {PLAYER}.$"

NewSinjoh_House1_Text_Decline:
	.string "Che peccato. Volevo proprio\n"
	.string "vederne uno.$"

NewSinjoh_House1_Text_TakeCareOfWooper:
    .string "Prenditi cura di quel WOOPER\n"
	.string "per me, ok?$"

NewSinjoh_House1_EventScript_Elizabeth_AfterGift::
	msgbox NewSinjoh_House1_Text_GoodToSeeYouAgain MSGBOX_DEFAULT
	release
	end

NewSinjoh_House1_Text_GoodToSeeYouAgain:
    .string "È bello rivederti,\n"
	.string "{PLAYER}.\p"
	.string "Come hai trattato quel\n"
	.string "WOOPER?$"

NewSinjoh_House1_Bookshelf::
    lock
	msgbox NewSinjoh_House1_Bookshelf_Text MSGBOX_DEFAULT
	release
	end

NewSinjoh_House1_Bookshelf_Text:
    .string "È uno scaffale pieno zeppo di\n"
	.string "videogiochi e fumetti!$"

NewSinjoh_House1_Eevee::
    lock
	faceplayer
	playmoncry SPECIES_EEVEE, 0
	msgbox NewSinjoh_House1_Text_Eevee_Cry, MSGBOX_DEFAULT
	waitmoncry
    closemessage
	release
	end

NewSinjoh_House1_Text_Eevee_Cry:
    .string "Vee Vee?$"
