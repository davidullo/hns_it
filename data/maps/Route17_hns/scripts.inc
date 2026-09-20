Route17_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route17_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route17_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route17_EventScript_Riley::
	trainerbattle_single TRAINER_RILEY_HNS, Route17_Text_BikerRileySeen, Route17_Text_BikerRileyBeaten, Route17_EventScript_RegisterRiley
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route17_EventScript_RematchRiley
	msgbox Route17_Text_BikerRileyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_RegisterRiley::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route17_Text_RileyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_RILEY_HNS
	release
	end

Route17_EventScript_RematchRiley::
	trainerbattle_rematch TRAINER_RILEY_HNS, Route17_Text_RileyRematchIntro, Route17_Text_RileyRematchDefeat
	msgbox Route17_Text_RileyPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_RILEY_2_HNS, Route17_EventScript_RematchRileyTryGiveItem
	end

Route17_EventScript_RematchRileyTryGiveItem::
	checkitem ITEM_TM_TOXIC
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_TOXIC
	closemessage
	end

Route17_EventScript_Joel::
	trainerbattle_single TRAINER_JOEL_HNS, Route17_Text_BikerJoelSeen, Route17_Text_BikerJoelBeaten, Route17_EventScript_RegisterJoel
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route17_EventScript_RematchJoel
	msgbox Route17_Text_BikerJoelAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_RegisterJoel::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route17_Text_JoelRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOEL_HNS
	release
	end

Route17_EventScript_RematchJoel::
	trainerbattle_rematch TRAINER_JOEL_HNS, Route17_Text_JoelRematchIntro, Route17_Text_JoelRematchDefeat
	msgbox Route17_Text_JoelPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_JOEL_2_HNS, Route17_EventScript_RematchJoelTryGiveItem
	end

Route17_EventScript_RematchJoelTryGiveItem::
	checkitem ITEM_TM_BRICK_BREAK
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_BRICK_BREAK
	closemessage
	end

Route17_EventScript_Glenn::
	trainerbattle_single TRAINER_GLENN_HNS, Route17_Text_BikerGlennSeen, Route17_Text_BikerGlennBeaten
	msgbox Route17_Text_BikerGlennAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Charles::
	trainerbattle_single TRAINER_CHARLES_HNS, Route17_Text_BikerCharlesSeen, Route17_Text_BikerCharlesBeaten, Route17_EventScript_RegisterCharles
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route17_EventScript_RematchCharles
	msgbox Route17_Text_BikerCharlesAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_RegisterCharles::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route17_Text_CharlesRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CHARLES_HNS
	release
	end

Route17_EventScript_RematchCharles::
	trainerbattle_rematch TRAINER_CHARLES_HNS, Route17_Text_CharlesRematchIntro, Route17_Text_CharlesRematchDefeat
	msgbox Route17_Text_CharlesPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_CHARLES_2_HNS, Route17_EventScript_RematchCharlesTryGiveItem
	end

Route17_EventScript_RematchCharlesTryGiveItem::
	checkitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_BULK_UP
	closemessage
	end

Route17_Text_BikerRileySeen:
	.string "Ehi, tu! Vieni da JOHTO, vero?$"

Route17_Text_BikerRileyBeaten:
	.string "Cavoli, sei forte!$"

Route17_Text_BikerRileyAfterBattle:
	.string "Non fare lo sbruffone, Punk di JOHTO!$"

Route17_Text_BikerJoelSeen:
	.string "Wow. Che bella BICICLETTA!$"

Route17_Text_BikerJoelBeaten:
	.string "Ma tu non sembri solo forte…$"

Route17_Text_BikerJoelAfterBattle:
	.string "Sembro forte, ma sono debole,\n"
	.string "quindi non sono granché.\p"
	.string "Devo allenarmi di più…$"

Route17_Text_BikerGlennSeen:
	.string "Ehi! Vuoi fare una gara di velocità?$"

Route17_Text_BikerGlennBeaten:
	.string "Caspita! Che coppia!$"

Route17_Text_BikerGlennAfterBattle:
	.string "Andare senza mani è considerato\n"
	.string "forte sulla PISTA CICLABILE.$"

Route17_Text_BikerCharlesSeen:
	.string "Siamo stelle della strada senza paura!$"

Route17_Text_BikerCharlesBeaten:
	.string "Argh! Che botta!$"

Route17_Text_BikerCharlesAfterBattle:
	.string "La guida spericolata causa incidenti!\n"
	.string "Vai piano!$"

Route17_Text_RileyRegister:
	.string "Niente male per un ragazzino di JOHTO!$"

Route17_Text_RileyRematchIntro:
	.string "I Punk di JOHTO vincono solo una volta!$"

Route17_Text_RileyRematchDefeat:
	.string "Mi hai battuto...$"

Route17_Text_RileyPostRematch:
	.string "Forse dovrei allenarmi a JOHTO\n"
	.string "dopo tutto.$"

Route17_Text_JoelRegister:
	.string "Alla fine sei forte!\n"
	.string "Scambiamoci i numeri!$"

Route17_Text_JoelRematchIntro:
	.string "Vediamo chi è più forte ora!$"

Route17_Text_JoelRematchDefeat:
	.string "Non ancora abbastanza forte…$"

Route17_Text_JoelPostRematch:
	.string "Continuerò ad allenarmi per essere\n"
	.string "forte come te, ragazzino!$"

Route17_Text_CharlesRegister:
	.string "Sei uno spezzacuori come me, ragazzino!\n"
	.string "Dammi il tuo numero!$"

Route17_Text_CharlesRematchIntro:
	.string "Non sono solo una stella della strada,\n"
	.string "sono uno spezzacuori!$"

Route17_Text_CharlesRematchDefeat:
	.string "Ci sono ricascato di nuovo!$"

Route17_Text_CharlesPostRematch:
	.string "Ho incontrato un trainer come te a UNIMA.\n"
	.string "Non ti abbattere!$"

