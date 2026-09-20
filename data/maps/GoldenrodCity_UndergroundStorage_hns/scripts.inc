GoldenrodCity_UndergroundStorage_hns_MapScripts::
	.byte 0

GoldenrodCity_UndergroundStorage_EventScript_Director::
    lock
    faceplayer
    checkitem ITEM_CARD_KEY
    goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_UndergroundStorage_EventScript_Director2
    msgbox RadioTowerBasement_Text_DirectorIntro, MSGBOX_DEFAULT
    closemessage
    giveitem ITEM_CARD_KEY
    msgbox RadioTowerBasement_Text_DirectorCardKey, MSGBOX_DEFAULT
    closemessage
    release
    end

GoldenrodCity_UndergroundStorage_EventScript_Director2::
    msgbox RadioTowerBasement_Text_DirectorAfter, MSGBOX_DEFAULT
    closemessage
    release
    end

GoldenrodCity_UndergroundStorage_EventScript_Grunt19::
    trainerbattle_single TRAINER_GRUNT_19_HNS, RadioTowerBasement_Text_GruntM24Seen, RadioTowerBasement_Text_GruntM24Beaten
	msgbox RadioTowerBasement_Text_GruntM24After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundStorage_EventScript_Grunt12::
    trainerbattle_single TRAINER_GRUNT_12_HNS, RadioTowerBasement_Text_GruntM14Seen, RadioTowerBasement_Text_GruntM14Beaten
	msgbox RadioTowerBasement_Text_GruntM14After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundStorage_EventScript_Eto::
    trainerbattle_single TRAINER_ETO_3_HNS, RadioTowerBasement_Text_GruntM15Seen, RadioTowerBasement_Text_GruntM15Beaten
	msgbox RadioTowerBasement_Text_GruntM15After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundStorage_EventScript_Item_TM_CALM_MIND::
    finditem ITEM_TM_CALM_MIND
    end

GoldenrodCity_UndergroundStorage_EventScript_Item_UltraBall::
    finditem ITEM_ULTRA_BALL
    end

GoldenrodCity_UndergroundStorage_EventScript_Item_MaxEther::
    finditem ITEM_MAX_ETHER
    end

RadioTowerBasement_Text_GruntM24Seen:
    .string "Come sei arrivato qui?\p"
    .string "Pazienza. Ti\n"
    .string "elimino io.$"

RadioTowerBasement_Text_GruntM24Beaten:
    .string "Mi hanno eliminato…$"

RadioTowerBasement_Text_GruntM24After:
    .string "Il TEAM ROCKET andrà avanti,\n"
    .string "aspettando GIOVANNI.\p"
    .string "Faremo di tutto.$"

RadioTowerBasement_Text_GruntM14Seen:
    .string "Non andrai più avanti!\p"
    .string "Non risparmio i nemici,\n"
    .string "nemmeno i mocciosi!$"

RadioTowerBasement_Text_GruntM14Beaten:
    .string "Accidenti!$"

RadioTowerBasement_Text_GruntM14After:
    .string "Ho perso…\p"
    .string "Perdonami, GIOVANNI!$"

RadioTowerBasement_Text_GruntM15Seen:
    .string "Gnihihihi! Guarda chi c'è!\p"
    .string "Pronto? Sono forte adesso!$"

RadioTowerBasement_Text_GruntM15Beaten:
    .string "Gnihihihi! Sei forte!\p"
    .string "Il TEAM ROCKET è solo\n"
    .string "un lavoro, ma fa male agli altri.\p"
    .string "Basta, me ne vado.\p"
    .string "Grazie mille. Scusa GIOVANNI!$"

RadioTowerBasement_Text_GruntM15After:
    .string "Gnihihihi! Che sballo!\n"
    .string "Mi ricorderò di te!$"

RadioTowerBasement_Text_DirectorIntro:
    .string "DIRETTORE: Chi? Cosa? Sei qui per\n"
    .string "salvarmi?\p"
    .string "Grazie!\p"
    .string "La RADIO!\p"
    .string "Cosa succede lì?\p"
    .string "Occupata dal TEAM ROCKET?\p"
    .string "Tieni. Prendi questa CARD KEY.$"

RadioTowerBasement_Text_DirectorCardKey:
    .string "DIRETTORE: Usala per aprire le\n"
    .string "serrande del 3F.$"

RadioTowerBasement_Text_DirectorAfter:
    .string "Ti prego, aiutami.\p"
    .string "Chissà cosa faranno se\n"
    .string "controllano il trasmettitore.\p"
    .string "Potrebbero perfino controllare\n"
    .string "i POKéMON con un segnale!\p"
    .string "Sei l'unico su cui conto.\p"
    .string "Salva la RADIO…\p"
    .string "E tutti i POKéMON del paese!$"
