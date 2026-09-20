Route35_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route35_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route35_OnTransition: 
	callnative SetTimeBasedEncounters
	end	

Route35_EventScript_CamperIvan::
	trainerbattle_single TRAINER_IVAN_HNS, Route35_Text_CamperIvanSeen, Route35_Text_CamperIvanBeaten
	msgbox Route35_Text_CamperIvanAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_CamperElliot::
	trainerbattle_single TRAINER_ELLIOT_HNS, Route35_Text_CamperElliotSeen, Route35_Text_CamperElliotBeaten
	msgbox Route35_Text_CamperElliotAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_PicnickerBrooke::
	trainerbattle_single TRAINER_BROOKE_HNS, Route35_Text_PicnickerBrookeSeen, Route35_Text_PicnickerBrookeBeaten
	msgbox Route35_Text_PicnickerBrookeAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_PicnickerKim::
	trainerbattle_single TRAINER_KIM_HNS, Route35_Text_PicnickerKimSeen, Route35_Text_PicnickerKimBeaten
	msgbox Route35_Text_PicnickerKimAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_BirdKeeperBryan::
	trainerbattle_single TRAINER_BRYAN_HNS, Route35_Text_BirdKeeperBryanSeen, Route35_Text_BirdKeeperBryanBeaten
	msgbox Route35_Text_BirdKeeperBryanAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_JugglerIrwin::
	trainerbattle_single TRAINER_IRWIN_HNS, Route35_Text_JugglerIrwinSeen, Route35_Text_JugglerIrwinBeaten, Route35_EventScript_RegisterIrwin
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route35_EventScript_RematchIrwin
	msgbox Route35_Text_JugglerIrwinAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_RegisterIrwin::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route35_Text_IrwinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_IRWIN_HNS
	release
	end

Route35_EventScript_RematchIrwin::
	trainerbattle_rematch TRAINER_IRWIN_HNS, Route35_Text_JugglerIrwinSeen, Route35_Text_JugglerIrwinBeaten
	msgbox Route35_Text_JugglerIrwinAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_BugCatcherArnie::
	trainerbattle_single TRAINER_ARNIE_HNS, Route35_Text_BugCatcherArnieSeen, Route35_Text_BugCatcherArnieBeaten, Route35_EventScript_RegisterArnie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route35_EventScript_RematchArnie
	msgbox Route35_Text_BugCatcherArnieAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_RegisterArnie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route35_Text_ArnieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ARNIE_HNS
	release
	end

Route35_EventScript_RematchArnie::
	trainerbattle_rematch TRAINER_ARNIE_HNS, Route35_Text_ArnieRematchIntro, Route35_Text_ArnieRematchDefeat
	msgbox Route35_Text_ArniePostRematch, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_FirebreatherWalt::
	trainerbattle_single TRAINER_WALT_HNS, Route35_Text_FirebreatherWaltSeen, Route35_Text_FirebreatherWaltBeaten
	msgbox Route35_Text_FirebreatherWaltAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_PolicemanDirk::
	trainerbattle_single TRAINER_DIRK_HNS, Route35_Text_OfficerDirkSeen, Route35_Text_OfficerDirkBeaten
	msgbox Route35_Text_OfficerDirkAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_Sign1::
	lock
	msgbox Route35_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route35_EventScript_Sign2::
	lock
	msgbox Route35_Text_Sign2, MSGBOX_SIGN
	closemessage
	release
	end

Route35_EventScript_Item_Payback::
	finditem ITEM_TM_PAYBACK
	end

Route35_EventScript_Item_Nugget::
	finditem ITEM_BIG_NUGGET
	end

Route35_EventScript_Item_ParalyzeHeal::
	finditem ITEM_PARALYZE_HEAL
	end

Route35_Text_CamperIvanSeen:
	.string "Ricevo dati sui POKéMON dalla\n"
	.string "radio. Me la cavo bene.$"

Route35_Text_CamperIvanBeaten:
	.string "Mi arrendo!$"

Route35_Text_CamperIvanAfter:
	.string "La musica alla radio cambia\n"
	.string "l'umore dei POKéMON selvatici.$"

Route35_Text_CamperElliotSeen:
	.string "Mostrerò alla mia ragazza che\n"
	.string "sono un duro!$"

Route35_Text_CamperElliotBeaten:
	.string "Vorrei che avessi perso per me…$"

Route35_Text_CamperElliotAfter:
	.string "Sono stato umiliato davanti alla\n"
	.string "mia ragazza…$"

Route35_Text_PicnickerBrookeSeen:
	.string "Il mio ragazzo è debole, non posso\n"
	.string "contare su di lui.$"

Route35_Text_PicnickerBrookeBeaten:
	.string "Oh, mamma! Sei fortissimo!$"

Route35_Text_PicnickerBrookeAfter:
	.string "Conto più sui miei POKéMON che\n"
	.string "sul mio ragazzo.$"

Route35_Text_PicnickerKimSeen:
	.string "Vai in PALESTRA? Anch'io!$"

Route35_Text_PicnickerKimBeaten:
	.string "Oh. Non ho potuto vincere…$"

Route35_Text_PicnickerKimAfter:
	.string "Le MEDAGLIE sono belle. Le\n"
	.string "colleziono.$"

Route35_Text_BirdKeeperBryanSeen:
	.string "Che tipo di BALL usi?$"

Route35_Text_BirdKeeperBryanBeaten:
	.string "Ahia! Non sono stato abbastanza veloce!$"

Route35_Text_BirdKeeperBryanAfter:
	.string "Alcuni POKéMON fuggono subito.\p"
	.string "Prova a prenderli con la\n"
	.string "VELOCEBALL di KURT.\p"
	.string "Quando trovo una BACCA ASPEAR,\n"
	.string "la porto da KURT.\p"
	.string "Lui la trasforma in una Ball su misura.$"

Route35_Text_JugglerIrwinSeen:
	.string "Ammira la mia abilità con le BALL!$"

Route35_Text_JugglerIrwinBeaten:
	.string "Uff! Che scossa!$"

Route35_Text_JugglerIrwinAfter:
	.string "Volevo stupirti con il mio\n"
	.string "POKéMON preferito.\p"
	.string "Ma la tua bravura mi ha elettrizzato!$"

Route35_Text_BugCatcherArnieSeen:
	.string "Vado ovunque pur di vedere\n"
	.string "POKéMON coleottero.$"

Route35_Text_BugCatcherArnieBeaten:
	.string "Eh? Non dovevo perdere…$"

Route35_Text_BugCatcherArnieAfter:
	.string "Il mio VENONAT ha vinto il Concorso\n"
	.string "Cattura Coleotteri al PARCO NAZIONALE.$"

Route35_Text_IrwinRegister:
	.string "Volevo stupirti con il mio\n"
	.string "POKéMON preferito.\p"
	.string "Ma la tua bravura mi ha elettrizzato!$"

Route35_Text_ArnieRegister:
	.string "Il mio VENONAT ha vinto il Concorso\n"
	.string "Cattura Coleotteri al PARCO NAZIONALE.$"

Route35_Text_ArnieRematchIntro:
	.string "Vado ovunque pur di vedere\n"
	.string "POKéMON coleottero.$"

Route35_Text_ArnieRematchDefeat:
	.string "Eh? Non dovevo perdere…$"

Route35_Text_ArniePostRematch:
	.string "Il mio VENONAT ha vinto il Concorso\n"
	.string "Cattura Coleotteri al PARCO NAZIONALE.$"

Route35_Text_BugCatcherArnieYanma:
	.string "Wow… Guarda quanti YANMA!\p"
	.string "Sono così stupito che non mi muovo.$"

Route35_Text_FirebreatherWaltSeen:
	.string "Mi sto allenando a sputare fuoco.$"

Route35_Text_FirebreatherWaltBeaten:
	.string "Ahia! Mi sono bruciato la punta del naso!$"

Route35_Text_FirebreatherWaltAfter:
	.string "La Marcia dei POKéMON alla radio\n"
	.string "attira i POKéMON selvatici.$"

Route35_Text_OfficerDirkSeen:
	.string "Il pericolo si nasconde di notte!$"

Route35_Text_OfficerDirkBeaten:
	.string "Ops!$"

Route35_Text_OfficerDirkAfter:
	.string "Sai, di notte ci si diverte a\n"
	.string "modo suo.\p"
	.string "Ma non esagerare, OK?$"

Route35_Text_OfficerDirkTough:
	.string "I tuoi POKéMON sembrano forti.\p"
	.string "Potresti andare ovunque in sicurezza.$"

Route35_Text_Sign:
	.string "PERCORSO 35$"

Route35_Text_Sign2:
	.string "INGRESSO PARCO NAZIONALE$"
