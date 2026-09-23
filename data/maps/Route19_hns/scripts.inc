Route19_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route19_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route19_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route19_EventScript_Harold::
	trainerbattle_single TRAINER_HAROLD_HNS, Route19_Text_SwimmermHaroldSeen, Route19_Text_SwimmermHaroldBeaten
	msgbox Route19_Text_SwimmermHaroldAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Tucker::
	trainerbattle_single TRAINER_TUCKER_HNS, Route19_Text_SwimmermTuckerSeen, Route19_Text_SwimmermTuckerBeaten
	msgbox Route19_Text_SwimmermTuckerAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Dawn::
	trainerbattle_single TRAINER_DAWN_HNS, Route19_Text_SwimmerfDawnSeen, Route19_Text_SwimmerfDawnBeaten
	msgbox Route19_Text_SwimmerfDawnAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Jerome::
	trainerbattle_single TRAINER_JEROME_HNS, Route19_Text_SwimmermJeromeSeen, Route19_Text_SwimmermJeromeBeaten
	msgbox Route19_Text_SwimmermJeromeAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Fatman::
	goto_if_unset FLAG_DEFEATED_CINNABAR_ISLAND_GYM, Route19_EventScript_FatmanBefore
	msgbox Route19_Text_Fisher1_RocksCleared, MSGBOX_NPC
	end

Route19_EventScript_FatmanBefore::
	msgbox Route19_Text_Fisher2, MSGBOX_NPC
	end

Route19_EventScript_Sign::
	msgbox Route19_Text_Sign, MSGBOX_SIGN
	end

Route19_EventScript_SwimSign::
	msgbox Route19_Text_CarefulSwimmingSign, MSGBOX_SIGN
	end

CherryGroveCity_EventScript_Kingler::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KINGLER, CRY_MODE_NORMAL
	msgbox Route19_Text_Kingler, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route19_EventScript_Fisher::
	goto_if_unset FLAG_DEFEATED_CINNABAR_ISLAND_GYM, Route19_EventScript_FisherBefore
	msgbox Route19_Text_Fisher2_RocksCleared, MSGBOX_NPC
	end

Route19_EventScript_FisherBefore::
	msgbox Route19_Text_FisherBefore, MSGBOX_NPC
	end

Route19_EventScript_Item_Brine::
    finditem ITEM_TM_BRINE
    end

Route19_Text_SwimmermHaroldSeen:
	.string "Hai mai nuotato nel mare\n"
	.string "di notte?$"

Route19_Text_SwimmermHaroldBeaten:
	.string "Glub…$"

Route19_Text_SwimmermHaroldAfterBattle:
	.string "Di notte il mare diventa nero.\n"
	.string "Sembra che ti voglia inghiottire.$"

Route19_Text_SwimmermTuckerSeen:
	.string "Pant, pant… Ancora un… po'…\p"
	.string "di strada… fino a… FUCSIAPOLI…$"

Route19_Text_SwimmermTuckerBeaten:
	.string "Sto affogando!$"

Route19_Text_SwimmermTuckerAfterBattle:
	.string "Ho… chiesto alla mia ragazza di\n"
	.string "nuotare fino a FUCSIAPOLI… Ansimo…$"

Route19_Text_SwimmerfDawnSeen:
	.string "I fifoni mi fanno schifo!$"

Route19_Text_SwimmerfDawnBeaten:
	.string "Ti batterei a nuoto…$"

Route19_Text_SwimmerfDawnAfterBattle:
	.string "Da FUCSIAPOLI alle ISOLE SPUMA\n"
	.string "è una nuotata breve…\p"
	.string "Cavoli, che ometto il mio ragazzo!\n"
	.string "Che fifone!$"

Route19_Text_SwimmermJeromeSeen:
	.string "Nuotare? Sono negato.\p"
	.string "Sto solo sguazzando in queste\n"
	.string "acque basse.$"

Route19_Text_SwimmermJeromeBeaten:
	.string "Credevo di poter vincere.$"

Route19_Text_SwimmermJeromeAfterBattle:
	.string "Nuoto male, ma il mare\n"
	.string "mi piace da matti.$"

Route19_Text_Fisher1:
	.string "Scusa. Questa strada è chiusa\n"
	.string "per lavori.\p"
	.string "Se vuoi arrivare all'ISOLA CANNELLA,\n"
	.string "meglio passare a sud da BIANCAVILLA\n"
	.string "TOWN.$"

Route19_Text_Kingler:
	.string "KINGLER: KEEEEEEEEEEEE$"

Route19_Text_Fisher1_RocksCleared:
	.string "Che sudato. Ora un bel bagno!$"

Route19_Text_Fisher2:
	.string "Cavoli, KINGLER blocca la\n"
	.string "spiaggia.$"

Route19_Text_FisherBefore:
	.string "Niente pesca finché questi KINGLER\n"
	.string "non se ne vanno.$"

Route19_Text_Fisher2_RocksCleared:
	.string "Quei KINGLER se ne sono andati!\p"
	.string "Ora posso pescare di nuovo.$"

Route19_Text_Sign:
	.string "ROTTA 19\p"
	.string "FUCSIAPOLI - ISOLE SPUMA$"

Route19_Text_CarefulSwimmingSign:
	.string "Fate attenzione se nuotate\n"
	.string "fino alle ISOLE SPUMA.\p"
	.string "POLIZIA DI FUCSIAPOLI$"

