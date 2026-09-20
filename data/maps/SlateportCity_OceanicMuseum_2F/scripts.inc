SlateportCity_OceanicMuseum_2F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_2F_EventScript_CaptStern::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, TRUE
	addobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter
	waitmovement 0
	addobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts, MSGBOX_DEFAULT
	call_if_ne VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou, MSGBOX_DEFAULT
	msgbox SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth
	call_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_1, SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat
	msgbox SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_2, SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_MeddlingKid, MSGBOX_DEFAULT
	closemessage
	delay 35
	addobject LOCALID_OCEANIC_MUSEUM_2F_ARCHIE
	applymovement LOCALID_OCEANIC_MUSEUM_2F_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_ArchieWarning, MSGBOX_DEFAULT
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_OCEANIC_MUSEUM_2F_ARCHIE
	removeobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1
	removeobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2
	fadescreen FADE_FROM_BLACK
	delay 30
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_DEVON_PARTS
	call Common_EventScript_PlayerHandedOverTheItem
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	removeobject LOCALID_OCEANIC_MUSEUM_2F_CAPT_STERN
	setflag FLAG_HIDE_ROUTE_110_TEAM_AQUA
	call_if_eq VAR_REGISTER_BIRCH_STATE, 0, SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch
	setflag FLAG_DELIVERED_DEVON_GOODS
	clearflag FLAG_HIDE_ROUTE_116_DEVON_EMPLOYEE
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1
	fadescreen FADE_FROM_BLACK
	release
	end

SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch::
	setvar VAR_REGISTER_BIRCH_STATE, 1
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts::
	applymovement LOCALID_OCEANIC_MUSEUM_2F_CAPT_STERN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth:
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest:
	walk_up
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_Unused:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	delay_8
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter:
	walk_down
	walk_right
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_fast_down
	walk_in_place_faster_up
	step_end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_PressureExperiment::
	msgbox SlateportCity_OceanicMuseum_2F_Text_PressureExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_HoennModel::
	msgbox SlateportCity_OceanicMuseum_2F_Text_HoennModel, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_DeepSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SurfaceSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSTidalReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmarineReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmersibleReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSAnneReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron3::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts:
	.string "Sì? Se cerchi STERN,\n"
	.string "sono io.\p"
	.string "Ah! Devono essere i pezzi che ho\n"
	.string "ordinato al SIG. STONE della DEVON.\p"
	.string "Grazie! Fantastico!\n"
	.string "Ora possiamo preparare la spedizione.$"

SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts:
	.string "Eh eh, fermo lì!\n"
	.string "Quei pezzi li prendiamo noi!$"

SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou:
	.string "CAP. STERN: Ch-cosa?\n"
	.string "Chi siete voi?$"

SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua:
	.string "Siamo il TEAM AQUA!\p"
	.string "Il nostro CAPO vuole quei pezzi!\n"
	.string "Chiudi il becco e passali!$"

SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat:
	.string "Awaaaah!\n"
	.string "Un bambino mi ha battuto!$"

SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious:
	.string "Oh, accidenti, che catastrofe…\n"
	.string "Il CAPO sarà furioso…$"

SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis:
	.string "Umpf, coniglio piagnucoloso!\n"
	.string "Ci penso io!$"

SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat:
	.string "Cosa?!\n"
	.string "Ho perso anch'io!$"

SlateportCity_OceanicMuseum_2F_Text_MeddlingKid:
	.string "E adesso? Se non prendiamo i pezzi,\n"
	.string "siamo nei guai!\p"
	.string "Arrgh, non pensavo che un ragazzino\n"
	.string "ficcanaso ci intralciasse!$"

SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong:
	.string "Sono venuto a vedere cosa ci metteva\n"
	.string "tanto a rubare quei pezzi, e voi\l"
	.string "siete bloccati da un bambino?$"

SlateportCity_OceanicMuseum_2F_Text_ArchieWarning:
	.string "Siamo il TEAM AQUA,\n"
	.string "e amiamo il mare!\p"
	.string "E io sono il capo del TEAM AQUA,\n"
	.string "ARCHIE!\p"
	.string "Perché ci ostacoli?\p"
	.string "…No! Non è possibile!\n"
	.string "Non sarai mica del TEAM MAGMA?\p"
	.string "Aspetta, non può essere.\n"
	.string "Non hai l'aria adatta.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "POKéMON, persone… Tutta la vita dipende\n"
	.string "dal mare.\p"
	.string "Il TEAM AQUA è quindi dedito\n"
	.string "all'espansione del mare.\p"
	.string "Non sei d'accordo? Ciò che facciamo\n"
	.string "è un'impresa magnifica.\p"
	.string "Ah, va bene…\n"
	.string "Sei troppo giovane per capire\l"
	.string "il nostro nobile obiettivo.\p"
	.string "Ma ti avverto, non provare mai più\n"
	.string "a intralciare i nostri piani.\p"
	.string "Le conseguenze ti costeranno\n"
	.string "caro!\p"
	.string "E non dimenticarlo!$"

SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs:
	.string "CAP. STERN: Tu sei…\n"
	.string "Ah, ok, tu sei {PLAYER}{KUN}…\p"
	.string "Che situazione tesa!\n"
	.string "Grazie per averci salvato!\p"
	.string "Ah, sì, quasi dimenticavo che hai\n"
	.string "portato anche i pezzi della DEVON!$"

SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo:
	.string "CAP. STERN: Ops!\n"
	.string "Non c'è tempo da perdere!\p"
	.string "Dobbiamo partire per la spedizione\n"
	.string "sul fondo dell'oceano, presto.\p"
	.string "Grazie ancora, ma ora devo\n"
	.string "andare!\p"
	.string "Però date pure un'occhiata in giro\n"
	.string "alle nostre strutture.$"

SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip:
	.string "Ho visto un modellino di nave.\p"
	.string "Mi ha ricordato la NAVE ABBANDONATA\n"
	.string "vicino a PORTO ALGHE…$"

SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum:
	.string "Non azzardarti a correre dentro\n"
	.string "il MUSEO!$"

SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine:
	.string "Uau, il sottomarino è fantastico!\n"
	.string "Vorrei farci un giro!$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1:
	.string "“CAMPIONE DI QUALITÀ 1,” dice\n"
	.string "l'etichetta.\p"
	.string "Il mare è tutto collegato, ma l'acqua\n"
	.string "sembra diversa da zona a zona.$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2:
	.string "“CAMPIONE DI QUALITÀ 2,” dice\n"
	.string "l'etichetta.\p"
	.string "Anche la salinità dell'acqua varia\n"
	.string "da zona a zona?$"

SlateportCity_OceanicMuseum_2F_Text_PressureExperiment:
	.string "Una palla di gomma si gonfia e\n"
	.string "si sgonfia.\p"
	.string "“Nel mare, il peso dell'acqua\n"
	.string "esercita una pressione.\p"
	.string "“In acque basse, la pressione non\n"
	.string "è molto forte.\p"
	.string "“In acque molto profonde, però,\n"
	.string "la pressione può raggiungere\l"
	.string "migliaia di tonnellate su un punto.”$"

SlateportCity_OceanicMuseum_2F_Text_HoennModel:
	.string "“MODELLO DELLA REGIONE DI HOENN”\p"
	.string "È un diorama in miniatura della\n"
	.string "regione di HOENN.\p"
	.string "Dov'è LITTLEROOT TOWN qui?$"

SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay:
	.string "È un pannello sul flusso dell'acqua.\p"
	.string "“Sul fondo del mare, l'acqua\n"
	.string "scorre per differenze di temperatura\l"
	.string "e salinità.”$"

SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay:
	.string "È un pannello sul flusso dell'acqua.\p"
	.string "“Verso la superficie, l'acqua scorre\n"
	.string "in correnti spinte dai venti.”$"

SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica:
	.string "“IL TRAGHETTO S.S. TIDAL\p"
	.string "“Una replica in scala della nave in\n"
	.string "costruzione nel CANTIERE DI STERN.”$"

SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica:
	.string "“ESPLORATORE SUBACQUEO 1\p"
	.string "“Una replica del sottomarino\n"
	.string "per l'esplorazione dei fondali.”$"

SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica:
	.string "“CAPSULA SUBACQUEA\p"
	.string "“Una replica di una capsula\n"
	.string "compatta per i fondali.”$"

SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica:
	.string "“S.S. ANNE\p"
	.string "“Una replica del transatlantico che\n"
	.string "fa il giro del mondo.”$"
