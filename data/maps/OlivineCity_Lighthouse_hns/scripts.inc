OlivineCity_Lighthouse_hns_MapScripts::
	.byte 0

OlivineLighthouse_EventScript_Item_Ether::
    finditem ITEM_ETHER
    end

OlivineLighthouse_EventScript_Item_RareCandy::
    finditem ITEM_RARE_CANDY
    end

OlivineLighthouse_EventScript_Item_TMSwagger::
    finditem ITEM_TM_SWAGGER
    end

OlivineLighthouse_EventScript_Item_HyperPotion::
    finditem ITEM_HYPER_POTION
    end

OlivineLighthouse_EventScript_Item_Protein::
    finditem ITEM_PROTEIN
    end

OlivineLighthouse_EventScript_1FSailor::
	lock
	faceplayer
	msgbox OlivineLighthouse_Text_1FSailor, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_EventScript_1FPokefanF::
	lock
	faceplayer
	msgbox OlivineLighthouse_Text_1FPokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_1FSailor:
	.string "La gente si allena in questo FARO.\p"
	.string "Non è facile salire con tutti\n"
	.string "gli allenatori che ci sono dentro.$"

OlivineLighthouse_Text_1FPokefanF:
	.string "In passato, i POKéMON illuminavano\n"
	.string "il mare intorno a OLIVINE di notte.\p"
	.string "Il FARO fu costruito in onore\n"
	.string "di quei nobili POKéMON.$"

@2nd floor==============================================================================================================================

OlivineLighthouse_EventScript_Huey::
	trainerbattle_single TRAINER_HUEY_HNS, OlivineLighthouse_Text_SailorHueySeen, OlivineLighthouse_Text_SailorHueyBeaten, OlivineLighthouse_EventScript_RegisterHuey
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, OlivineLighthouse_EventScript_RematchHuey
	msgbox OlivineLighthouse_Text_SailorHueyAfter, MSGBOX_AUTOCLOSE
	end

OlivineLighthouse_EventScript_RegisterHuey::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox OlivineLighthouse_Text_HueyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_HUEY_HNS
	release
	end

OlivineLighthouse_EventScript_RematchHuey::
	trainerbattle_rematch TRAINER_HUEY_HNS, OlivineLighthouse_Text_HueyRematchIntro, OlivineLighthouse_Text_HueyRematchDefeat
	msgbox OlivineLighthouse_Text_HueyPostRematch, MSGBOX_AUTOCLOSE
	end

OlivineLighthouse_EventScript_GentlemanAlfred::
    trainerbattle_single TRAINER_ALFRED_HNS, OlivineLighthouse_Text_GentlemanAlfredSeen, OlivineLighthouse_Text_GentlemanAlfredBeaten
    msgbox OlivineLighthouse_Text_GentlemanAlfredAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_Text_SailorHueySeen:
	.string "Gli uomini di mare cercano sempre\n"
	.string "una bella sfida!$"

OlivineLighthouse_Text_SailorHueyBeaten:
	.string "Urf!\n"
	.string "Ho perso!$"

OlivineLighthouse_Text_SailorHueyAfter:
	.string "Che potenza! Ti va di\n"
	.string "navigare i mari con me?$"

OlivineLighthouse_Text_HueyRegister:
	.string "Che potenza! Ti va di\n"
	.string "navigare i mari con me?$"

OlivineLighthouse_Text_HueyRematchIntro:
	.string "Gli uomini di mare cercano sempre\n"
	.string "una bella sfida!$"

OlivineLighthouse_Text_HueyRematchDefeat:
	.string "Urf!\n"
	.string "Ho perso!$"

OlivineLighthouse_Text_HueyPostRematch:
	.string "Che potenza! Ti va di\n"
	.string "navigare i mari con me?$"

OlivineLighthouse_Text_GentlemanAlfredSeen:
	.string "Hm? Questo non è un posto\n"
	.string "per giocare.$"

OlivineLighthouse_Text_GentlemanAlfredBeaten:
	.string "Ah! Vedo che fai\n"
	.string "sul serio.$"

OlivineLighthouse_Text_GentlemanAlfredAfter:
	.string "Lassù c'è un POKéMON che tiene\n"
	.string "acceso il FARO.\p"
	.string "Ma sento che ora è malato,\n"
	.string "e non si cura normalmente.$"

@3rd floor==============================================================================================================================

OlivineLighthouse_EventScript_BirdKeeperTheo::
    trainerbattle_single TRAINER_THEO_HNS, OlivineLighthouse_Text_BirdKeeperTheoSeen, OlivineLighthouse_Text_BirdKeeperTheoBeaten
    msgbox OlivineLighthouse_Text_BirdKeeperTheoAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_SailorTerrell::
    trainerbattle_single TRAINER_TERRELL_HNS, OlivineLighthouse_Text_SailorTerrellSeen, OlivineLighthouse_Text_SailorTerrellBeaten
    msgbox OlivineLighthouse_Text_SailorTerrellAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_GentlemanPreston::
    trainerbattle_single TRAINER_PRESTON_HNS, OlivineLighthouse_Text_GentlemanPrestonSeen, OlivineLighthouse_Text_GentlemanPrestonBeaten
    msgbox OlivineLighthouse_Text_GentlemanPrestonAfter, MSGBOX_AUTOCLOSE
    end


OlivineLighthouse_Text_BirdKeeperTheoSeen:
	.string "Perché sei qui? Vuoi solo\n"
	.string "curiosare? Ti consiglio di andartene!$"

OlivineLighthouse_Text_BirdKeeperTheoBeaten:
	.string "Tieni davvero al\n"
	.string "POKéMON malato…$"

OlivineLighthouse_Text_BirdKeeperTheoAfter:
	.string "Come diavolo si sale?\p"
	.string "Voglio visitare il POKéMON malato,\n"
	.string "ma non riesco ad arrivare lassù…$"

OlivineLighthouse_Text_SailorTerrellSeen:
	.string "I marinai sono gentili e forti.\n"
	.string "E tu?$"

OlivineLighthouse_Text_SailorTerrellBeaten:
	.string "Sei gentile e forte…$"

OlivineLighthouse_Text_SailorTerrellAfter:
	.string "Ogni volta che torno a OLIVINE,\n"
	.string "visito la PALESTRA.\p"
	.string "Il tipo dei POKéMON del CAPOPALESTRA\n"
	.string "è cambiato senza che me ne accorgessi.$"

OlivineLighthouse_Text_GentlemanPrestonSeen:
	.string "Viaggio il mondo per allenare i\n"
	.string "POKéMON. Voglio sfidarti.$"

OlivineLighthouse_Text_GentlemanPrestonBeaten:
	.string "…sigh… Devo allenarmi ancora…$"

OlivineLighthouse_Text_GentlemanPrestonAfter:
	.string "JASMINE usava POKéMON di tipo\n"
	.string "ROCCIA come ONIX.$"

@4th floor==============================================================================================================================

OlivineLighthouse_EventScript_SailorKent::
    trainerbattle_single TRAINER_KENT_HNS, OlivineLighthouse_Text_SailorKentSeen, OlivineLighthouse_Text_SailorKentBeaten
    msgbox OlivineLighthouse_Text_SailorKentAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_LassConnie::
    trainerbattle_single TRAINER_CONNIE_HNS, OlivineLighthouse_Text_LassConnieSeen, OlivineLighthouse_Text_LassConnieBeaten
    msgbox OlivineLighthouse_Text_LassConnieAfter, MSGBOX_AUTOCLOSE
    end


OlivineLighthouse_Text_SailorKentSeen:
	.string "JASMINE sarà preoccupatissima per\n"
	.string "i POKéMON qui.\p"
	.string "Di questi tempi non sorride mai.$"

OlivineLighthouse_Text_SailorKentBeaten:
	.string "Neanche io riesco a sorridere…$"

OlivineLighthouse_Text_SailorKentAfter:
	.string "A proposito di malati, ho sentito che\n"
	.string "c'è una buona FARMACIA a CIANWOOD.$"

OlivineLighthouse_Text_LassConnieSeen:
	.string "JASMINE è la CAPOPALESTRA di qui.\p"
	.string "Voglio riportarla con me.\p"
	.string "Nessuno provi a fermarmi!$"

OlivineLighthouse_Text_LassConnieBeaten:
	.string "Aaah! I miei POKéMON!$"

OlivineLighthouse_Text_LassConnieAfter:
	.string "Certo. Chiunque sarebbe preoccupato\n"
	.string "se i suoi POKéMON fossero feriti.\p"
	.string "Pregherò per i POKéMON qui, così\n"
	.string "JASMINE tornerà in PALESTRA.$"

@5th floor==============================================================================================================================

OlivineLighthouse_EventScript_SailorErnest::
    trainerbattle_single TRAINER_ERNEST_HNS, OlivineLighthouse_Text_SailorErnestSeen, OlivineLighthouse_Text_SailorErnestBeaten
    msgbox OlivineLighthouse_Text_SailorErnestAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_BirdKeeperDenis::
    trainerbattle_single TRAINER_DENIS_HNS, OlivineLighthouse_Text_BirdKeeperDenisSeen, OlivineLighthouse_Text_BirdKeeperDenisBeaten
    msgbox OlivineLighthouse_Text_BirdKeeperDenisAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_Text_SailorErnestSeen:
	.string "Volevo sfidare JASMINE, ma ora\n"
	.string "non se la sente.\p"
	.string "Allora, che ne dici di te?$"

OlivineLighthouse_Text_SailorErnestBeaten:
	.string "Caspita, sei travolgente!$"

OlivineLighthouse_Text_SailorErnestAfter:
	.string "Un CAPOPALESTRA non è solo\n"
	.string "forte.\p"
	.string "Un CAPO deve anche essere\n"
	.string "comprensivo.$"

OlivineLighthouse_Text_BirdKeeperDenisSeen:
	.string "Siamo belli in alto. I miei POKéMON\n"
	.string "uccello sono in gran forma.$"

OlivineLighthouse_Text_BirdKeeperDenisBeaten:
	.string "Ops… Sono caduti…$"

OlivineLighthouse_Text_BirdKeeperDenisAfter:
	.string "I miei POKéMON hanno imparato VOLO a\n"
	.string "CIANWOOD.\p"
	.string "Beh, dato che ho perso, userò VOLO\n"
	.string "per attraversare il mare…$"

@6th floor==============================================================================================================================

OlivineLighthouse_EventScript_Jasmine::
	lock
	faceplayer
	goto_if_eq VAR_OLIVINE_CITY_STATE, 3, OlivineLighthouse_EventScript_JasmineGoGetPotion
	goto_if_eq VAR_OLIVINE_CITY_STATE, 4, OlivineLighthouse_EventScript_JasmineDeliverPotion
	msgbox OlivineLighthouse_Text_JasmineCianwoodPharmacy, MSGBOX_DEFAULT
	msgbox OlivineLighthouse_Text_JasmineGetMedicine, MSGBOX_DEFAULT
	closemessage
	setvar VAR_OLIVINE_CITY_STATE, 3
	release
	end
OlivineLighthouse_EventScript_JasmineGoGetPotion::
	msgbox OlivineLighthouse_Text_JasmineGetMedicine2, MSGBOX_DEFAULT
	release
	end


OlivineLighthouse_EventScript_Ampharos::
	lock
	faceplayer
	goto_if_lt VAR_OLIVINE_CITY_STATE, 5, OlivineLighthouse_EventScript_AmpharosSick
	fadescreen FADE_TO_WHITE
	playse SE_M_THUNDERBOLT2
	waitse
	fadescreen FADE_FROM_WHITE
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPaluPalulu, MSGBOX_DEFAULT
	waitmoncry
	setflag FLAG_AMPHAROS_HEALED
	release
	end

OlivineLighthouse_EventScript_AmpharosSick::
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPalPaloo, MSGBOX_DEFAULT
	waitmoncry
	msgbox OlivineLighthouse_Text_AmphyBreathingLabored, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_JasmineCianwoodPharmacy:
	.string "JASMINE: …Questo POKéMON teneva\n"
	.string "sempre acceso il faro la notte.\p"
	.string "…Ma si è ammalato… È\n"
	.string "senza fiato…\p"
	.string "…So che c'è una\n"
	.string "FARMACIA a CIANWOOD…\p"
	.string "Ma è oltre il mare…\n"
	.string "E non posso lasciare AMPHY…$"

OlivineLighthouse_Text_JasmineGetMedicine:
	.string "…Potresti prendermi una medicina?\n"
	.string "Per favore?$"

OlivineLighthouse_Text_JasmineGetMedicine2:
	.string "C'è una FARMACIA fantastica\n"
	.string "a CIANWOOD…\p"
	.string "Ma è oltre il mare…\n"
	.string "E non posso lasciare AMPHY da solo…\p"
	.string "…Potresti prendermi una medicina?\n"
	.string "Per favore?$"

OlivineLighthouse_Text_JasmineCureAmphy:
	.string "JASMINE: …Quella medicina curerà\n"
	.string "AMPHY?$"


OlivineLighthouse_EventScript_JasmineDeliverPotion::
	msgbox OlivineLighthouse_Text_JasmineCureAmphy, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, OlivineLighthouse_EventScript_JasmineRefuse
	playse SE_USE_ITEM
	removeitem ITEM_SECRET_POTION
	msgbox OlivineLighthouse_Text_PlayerHandedSecretpotion, MSGBOX_DEFAULT
	waitse
	msgbox OlivineLighthouse_Text_JasmineDontBeOffended, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_LIGHTHOUSE_JASMINE, DIR_NORTH
	delay 20
	turnobject LOCALID_LIGHTHOUSE_AMPHAROS, DIR_SOUTH
	playfanfare MUS_HEAL
	waitfanfare
	msgbox OlivineLighthouse_Text_JasmineAmphyHowFeeling, MSGBOX_DEFAULT
	fadescreen FADE_TO_WHITE
	playse SE_M_THUNDERBOLT2
	waitse
	fadescreen FADE_FROM_WHITE
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPaluPalulu, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	applymovement LOCALID_LIGHTHOUSE_AMPHAROS, OlivineLighthouse_Movement_Amphy
	waitmovement 0
	applymovement LOCALID_LIGHTHOUSE_JASMINE, OlivineLighthouse_Movement_Jasmine
	msgbox OlivineLighthouse_Text_JasmineThankYou, MSGBOX_DEFAULT
	closemessage

	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_LIGHTHOUSE_JASMINE
	removeobject LOCALID_LIGHTHOUSE_JASMINE
	waitse
	delay 50
	fadescreen FADE_FROM_BLACK
	setvar VAR_SAFARI_ZONE_GATE_STATE, 1
	setvar VAR_OLIVINE_CITY_STATE, 5
	setflag FLAG_AMPHAROS_HEALED
	clearflag FLAG_HIDE_OLIVINE_CITY_GYM_JASMINE
	release
	end

OlivineLighthouse_Movement_Jasmine:
	face_player
	step_end

OlivineLighthouse_Movement_Amphy:
	walk_up
	jump_in_place_down
	jump_in_place_left
	jump_in_place_right
	jump_in_place_up
	face_down
	step_end


OlivineLighthouse_EventScript_JasmineRefuse::
	msgbox OlivineLighthouse_Text_JasmineISee, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_PlayerHandedSecretpotion:
	.string "{PLAYER} ha dato la POZIONE SEGRETA a\n"
	.string "JASMINE.$"

OlivineLighthouse_Text_JasmineDontBeOffended:
	.string "JASMINE: …Ehm, non ti\n"
	.string "offendere…\p"
	.string "…AMPHY non accetta nulla da\n"
	.string "nessuno tranne me…$"

OlivineLighthouse_Text_JasmineAmphyHowFeeling:
	.string "JASMINE: …\p"
	.string "AMPHY, come ti senti?$"

OlivineLighthouse_Text_JasmineThankYou:
	.string "JASMINE: …Oh, che sollievo…\p"
	.string "È semplicemente meraviglioso…\p"
	.string "Grazie infinite, davvero.\p"
	.string "…Tornerò in PALESTRA…\p"
	.string "Ti avverto, i tipi ACCIAIO\n"
	.string "sono forti.$"

OlivineLighthouse_Text_JasmineISee:
	.string "JASMINE: …Capisco…\n"
	.string "…AMPHY, resisti!$"

OlivineLighthouse_Text_AmphyPalPaloo:
	.string "AMPHY: …\n"
	.string "…Pa… paloo…$"

OlivineLighthouse_Text_AmphyBreathingLabored:
	.string "Il suo respiro è terribilmente\n"
	.string "affannato…$"

OlivineLighthouse_Text_AmphyPaluPalulu:
	.string "AMPHY: Palu! Palulu!$"


