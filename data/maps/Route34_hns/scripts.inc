Route34_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route34_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route34_OnTransition: 
	specialvar VAR_RESULT, GetDaycareState
	call_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route34_MapScript_EggReady
	callnative SetTimeBasedEncounters
	end	

Route34_MapScript_EggReady::
	setobjectxyperm LOCALID_ROUTE34_DAYCAREMAN, 30, 34
	return

Route34_EventScript_YoungsterSamuel::
	trainerbattle_single TRAINER_SAMUEL_HNS, Route34_Text_YoungsterSamuel_Seen, Route34_Text_YoungsterSamuel_Beaten
	msgbox Route34_Text_YoungsterSamuel_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_YoungsterIan::
	trainerbattle_single TRAINER_IAN_HNS, Route34_Text_YoungsterIan_Seen, Route34_Text_YoungsterIan_Beaten
	msgbox Route34_Text_YoungsterIan_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_CamperTodd::
	trainerbattle_single TRAINER_TODD_HNS, Route34_Text_CamperTodd_Seen, Route34_Text_CamperTodd_Beaten, Route34_EventScript_RegisterTodd
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route34_EventScript_RematchTodd
	msgbox Route34_Text_CamperTodd_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_RegisterTodd::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route34_Text_ToddRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TODD_HNS
	release
	end

Route34_EventScript_RematchTodd::
	trainerbattle_rematch TRAINER_TODD_HNS, Route34_Text_ToddRematchIntro, Route34_Text_ToddRematchDefeat
	msgbox Route34_Text_ToddPostRematch, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_PicnickerGina::
	trainerbattle_single TRAINER_GINA_HNS, Route34_Text_PicnickerGina_Seen, Route34_Text_PicnickerGina_Beaten, Route34_EventScript_RegisterGina
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route34_EventScript_RematchGina
	msgbox Route34_Text_PicnickerGina_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_RegisterGina::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route34_Text_GinaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GINA_HNS
	release
	end

Route34_EventScript_RematchGina::
	trainerbattle_rematch TRAINER_GINA_HNS, Route34_Text_PicnickerGina_Seen, Route34_Text_PicnickerGina_Beaten
	msgbox Route34_Text_PicnickerGina_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_OfficerKeith::
	trainerbattle_single TRAINER_KEITH_HNS, Route34_Text_OfficerKeith_Seen, Route34_Text_OfficerKeith_Win
	msgbox Route34_Text_OfficerKeith_After, MSGBOX_AUTOCLOSE
	end


Route34_EventScript_PokefanMBrandon::
	trainerbattle_single TRAINER_BRANDON_HNS, Route34_Text_PokefanBrandon_Seen, Route34_Text_PokefanBrandon_Beaten
	msgbox Route34_Text_PokefanBrandon_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Irene::
	trainerbattle_single TRAINER_IRENE_HNS, Route34_Text_CooltrainerIrene_Seen, Route34_Text_CooltrainerIrene_Beaten
	msgbox Route34_Text_CooltrainerIrene_After2, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Jenn::
	trainerbattle_single TRAINER_JENN_HNS, Route34_Text_CooltrainerJenn_Seen, Route34_Text_CooltrainerJenn_Beaten
	msgbox Route34_Text_CooltrainerJenn_After2, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Kate::
	trainerbattle_single TRAINER_KATE_HNS, Route34_Text_CooltrainerKate_Seen, Route34_Text_CooltrainerKate_Beaten
	msgbox Route34_Text_CooltrainerKate_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Sign1::
	lock
	msgbox Route34_Text_Sign_Route34, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Sign2::
	lock
	msgbox Route34_Text_Sign_DayCare, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Sign3::
	lock
	msgbox Route34_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Item_SoftSand::
	finditem ITEM_SOFT_SAND
	end

Route34_EventScript_Item_RareCandy::
	finditem ITEM_RARE_CANDY
	end
	
Route34_EventScript_Item_Embargo::
    finditem ITEM_TM_EMBARGO
    end


Route34_Text_YoungsterSamuel_Seen:
	.string "Ehi! Sto cercando un MANKEY!$"

Route34_Text_YoungsterSamuel_Beaten:
	.string "Battuto da un passante!$"

Route34_Text_YoungsterSamuel_After:
	.string "Mi allenerò ancora di più.\p"
	.string "Voglio diventare\n"
	.string "un CAPOPALESTRA.$"

Route34_Text_YoungsterIan_Seen:
	.string "Sono il migliore della classe\n"
	.string "coi POKéMON.$"

Route34_Text_YoungsterIan_Beaten:
	.string "No! Ci sono allenatori più forti…$"

Route34_Text_YoungsterIan_After:
	.string "Mi impegno tanto per essere\n"
	.string "il migliore della classe.$"

Route34_Text_CamperTodd_Seen:
	.string "Sono sicuro di saper\n"
	.string "allevare i POKéMON.\p"
	.string "Vuoi vedere?$"

Route34_Text_CamperTodd_Beaten:
	.string "Ho sbagliato l'allenamento?$"

Route34_Text_CamperTodd_After:
	.string "Forse dovrei portarlo alla PENSIONE,\n"
	.string "o usare qualche strumento…$"

Route34_Text_ToddRegister:
	.string "Forse dovrei portarlo alla PENSIONE,\n"
	.string "o usare qualche strumento…$"

Route34_Text_ToddRematchIntro:
	.string "Sono sicuro di saper\n"
	.string "allevare i POKéMON.\p"
	.string "Vuoi vedere?$"

Route34_Text_ToddRematchDefeat:
	.string "Ho sbagliato l'allenamento?$"

Route34_Text_ToddPostRematch:
	.string "Forse dovrei portarlo alla PENSIONE,\n"
	.string "o usare qualche strumento…$"

Route34_Text_GinaRegister:
	.string "Sei troppo forte per\n"
	.string "allenarti con me.$"

Route34_Text_PicnickerGina_Seen:
	.string "Sei un ALLENATORE?\p"
	.string "Facciamo una lotta di allenamento.$"

Route34_Text_PicnickerGina_Beaten:
	.string "Oh, no! Non riesco mai a vincere…$"

Route34_Text_PicnickerGina_After:
	.string "Sei troppo forte per\n"
	.string "allenarti con me.$"

Route34_Text_OfficerKeith_Seen:
	.string "Chi va là?\n"
	.string "Che cosa fai in giro?$"

Route34_Text_OfficerKeith_Win:
	.string "Sei un ragazzino tosto.$"

Route34_Text_OfficerKeith_After:
	.string "Sì, oggi tutto tranquillo.\p"
	.string "Comportati bene e non combinare guai.$"

Route34_Text_OfficerKeith_Daytime:
	.string "Sono di pattuglia in cerca di\n"
	.string "tipi sospetti.$"

Route34_Text_PokefanBrandon_Seen:
	.string "Ho appena ripreso il mio POKéMON\n"
	.string "dalla PENSIONE.\p"
	.string "Vediamo quanto è cresciuto!$"

Route34_Text_PokefanBrandon_Beaten:
	.string "Perché finisce sempre così?$"

Route34_Text_PokefanBrandon_After:
	.string "My POKéMON came back with new moves.\p"
	.string "That confounded me to no end!$"

Route34_Text_Sign_IlexForest:
	.string "FORESTA DI ILEX\n"
	.string "OLTRE IL CANCELLO$"

Route34_Text_Sign_Route34:
	.string "PERCORSO 34\n"
	.string "FIORENZA - VIOLETTA\p"
	.string "FORESTA DI ILEX NEL MEZZO$"

Route34_Text_TrainerTips:
	.string "CONSIGLI PER ALLENATORI\p"
	.string "Gli alberi di BACCA ne producono\n"
	.string "di nuove più volte al giorno.\p"
	.string "Osserva quali alberi danno\n"
	.string "quali BACCE.$"

Route34_Text_CooltrainerIrene_Seen:
	.string "IRENE: Chi sei?!$"

Route34_Text_CooltrainerIrene_Beaten:
	.string "IRENE: Ohhh! Sei troppo forte!$"

Route34_Text_CooltrainerIrene_After1:
	.string "IRENE: Mia sorella KATE\n"
	.string "te la farà pagare!$"

Route34_Text_CooltrainerIrene_After2:
	.string "IRENE: Bella questa spiaggia, no?\p"
	.string "È il nostro angolo segreto!$"

Route34_Text_CooltrainerJenn_Seen:
	.string "JENN: Ma che...?\n"
	.string "Che cosa fai?$"

Route34_Text_CooltrainerJenn_Beaten:
	.string "JENN: Scusa, IRENE! Sorellona!$"

Route34_Text_CooltrainerJenn_After1:
	.string "JENN: Non fare lo spavaldo!\n"
	.string "Mia sorella KATE è tosta!$"

Route34_Text_CooltrainerJenn_After2:
	.string "JENN: Il sole rende il corpo\n"
	.string "più forte.$"

Route34_Text_CooltrainerKate_Seen:
	.string "KATE: Devo ripagarti per\n"
	.string "aver battuto le mie sorelle!$"

Route34_Text_CooltrainerKate_Beaten:
	.string "KATE: No! Non ci credo, ho perso.$"

Route34_Text_CooltrainerKate_GiveSoftSand:
	.string "KATE: Sei fortissimo.\n"
	.string "Abbiamo perso, senza scuse…\p"
	.string "Tieni, prendi questo!$"

Route34_Text_CooltrainerKate_After:
	.string "KATE: Scusa se ti abbiamo assalito.\p"
	.string "Non pensavamo che qualcuno\n"
	.string "ci trovasse qui. Ci hai spaventate.$"


Route34_Text_Sign_DayCare:
	.string "PENSIONE\p"
	.string "TI ALLEVIAMO I POKéMON!$"
