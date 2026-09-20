Route44_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route44_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route44_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route44_EventScript_Wilton::
	trainerbattle_single TRAINER_WILTON_HNS, Route44_Text_FisherWilton1Seen, Route44_Text_FisherWilton1Beaten, Route44_EventScript_RegisterWilton
	goto_if_set FLAG_WILTON_HAS_ITEM_HNS, Route44_EventScript_WiltonGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route44_EventScript_RematchWilton
	msgbox Route44_Text_FisherWiltonHugePoliwag, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_RegisterWilton::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route44_Text_WiltonRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_WILTON_HNS
	release
	end

Route44_EventScript_RematchWilton::
	trainerbattle_rematch TRAINER_WILTON_HNS, Route44_Text_WiltonRematchIntro, Route44_Text_WiltonRematchDefeat
	msgbox Route44_Text_WiltonPostRematch, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_WiltonGiveItem::
	msgbox Route44_Text_WiltonHasItem, MSGBOX_DEFAULT
	giveitem VAR_WILTON_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route44_EventScript_WiltonNoRoom
	clearflag FLAG_WILTON_HAS_ITEM_HNS
	msgbox Route44_Text_WiltonGaveItem, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_WiltonNoRoom::
	msgbox Route44_Text_WiltonNoRoom, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Edgar::
	trainerbattle_single TRAINER_EDGAR_HNS, Route44_Text_FisherEdgarSeen, Route44_Text_FisherEdgarBeaten
	msgbox Route44_Text_FisherEdgarAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Vance::
	trainerbattle_single TRAINER_VANCE_HNS, Route44_Text_BirdKeeperVance1Seen, Route44_Text_BirdKeeperVance1Beaten, Route44_EventScript_RegisterVance
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route44_EventScript_RematchVance
	msgbox Route44_Text_BirdKeeperVanceBirds, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_RegisterVance::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route44_Text_VanceRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_VANCE_HNS
	release
	end

Route44_EventScript_RematchVance::
	trainerbattle_rematch TRAINER_VANCE_HNS, Route44_Text_VanceRematchIntro, Route44_Text_VanceRematchDefeat
	msgbox Route44_Text_VancePostRematch, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Phil::
	trainerbattle_single TRAINER_PHIL_HNS, Route44_Text_PsychicPhilSeen, Route44_Text_PsychicPhilBeaten
	msgbox Route44_Text_PsychicPhilAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Zach::
	trainerbattle_single TRAINER_ZACH_HNS, Route44_Text_PokemaniacZachSeen, Route44_Text_PokemaniacZachBeaten
	msgbox Route44_Text_PokemaniacZachAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Allen::
	trainerbattle_single TRAINER_ALLEN_HNS, Route44_Text_CooltrainermAllenSeen, Route44_Text_CooltrainermAllenBeaten
	msgbox Route44_Text_CooltrainermAllenAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Cybil::
	trainerbattle_single TRAINER_CYBIL_HNS, Route44_Text_CooltrainerfCybilSeen, Route44_Text_CooltrainerfCybilBeaten
	msgbox Route44_Text_CooltrainerfCybilAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Sign1::
	msgbox Route44_Text_Sign1, MSGBOX_SIGN
	end

Route44_EventScript_Sign2::
	msgbox Route44_Text_Sign2, MSGBOX_SIGN
	end

Route44_EventScript_Item_MaxRepel::
	finditem ITEM_MAX_REPEL
	end

Route44_EventScript_Item_UltraBall::
	finditem ITEM_ULTRA_BALL
	end

Route44_EventScript_Item_Elixir::
	finditem ITEM_ELIXIR
	end

Route44_Text_FisherWilton1Seen:
    .string "Aaah!\p"
    .string "Mi hai fatto perdere un POLIWAG!\n"
    .string "Come pensi di rimediare?$"

Route44_Text_FisherWilton1Beaten:
    .string "Lascia perdere.$"

Route44_Text_FisherWiltonHugePoliwag:
    .string "Quel POLIWAG scappato…\n"
    .string "era enorme.\p"
    .string "Giuro che era lungo\n"
    .string "quasi 5 metri!$"

Route44_Text_WiltonRegister:
    .string "Quel POLIWAG scappato…\n"
    .string "era enorme.\p"
    .string "Giuro che era lungo\n"
    .string "quasi 5 metri!$"

Route44_Text_WiltonRematchIntro:
    .string "Aaah!\p"
    .string "Mi hai fatto perdere un POLIWAG!\n"
    .string "Come pensi di rimediare?$"

Route44_Text_WiltonRematchDefeat:
    .string "Lascia perdere.$"

Route44_Text_WiltonPostRematch:
    .string "Quel POLIWAG scappato…\n"
    .string "era enorme.\p"
    .string "Giuro che era lungo\n"
    .string "quasi 5 metri!$"

Route44_Text_WiltonHasItem:
    .string "Ehi! Ho tirato su qualcosa\n"
    .string "che non è un POKéMON!\p"
    .string "Tieni, è tuo!$"

Route44_Text_WiltonGaveItem:
    .string "Ti avviso se ripesco\n"
    .string "qualcos'altro!$"

Route44_Text_WiltonNoRoom:
    .string "Hmm, la tua BORSA è piena.\p"
    .string "Torna quando avrai spazio.$"

Route44_Text_FisherEdgarSeen:
    .string "Pesco finché posso.\p"
    .string "E lotto finché reggo.\p"
    .string "È il mio rapporto con i miei\n"
    .string "POKéMON.$"

Route44_Text_FisherEdgarBeaten:
    .string "Mmmmm… Così non va bene.$"

Route44_Text_FisherEdgarAfter:
    .string "100 vittorie e 101 sconfitte.\p"
    .string "Non lotterò per un po'.$"

Route44_Text_BirdKeeperVance1Seen:
    .string "Conosci i POKéMON leggendari\n"
    .string "chiamati uccelli?$"

Route44_Text_BirdKeeperVance1Beaten:
    .string "Uao! Sei un vero fenomeno.$"

Route44_Text_BirdKeeperVanceBirds:
    .string "ARTICUNO, ZAPDOS e MOLTRES sono\n"
    .string "i tre POKéMON uccello leggendari.\p"
    .string "Ho sentito però che esistono\n"
    .string "altri uccelli leggendari.$"

Route44_Text_VanceRegister:
    .string "ARTICUNO, ZAPDOS e MOLTRES sono\n"
    .string "i tre POKéMON uccello leggendari.\p"
    .string "Ho sentito però che esistono\n"
    .string "altri uccelli leggendari.$"

Route44_Text_VanceRematchIntro:
    .string "Conosci i POKéMON leggendari\n"
    .string "chiamati uccelli?$"

Route44_Text_VanceRematchDefeat:
    .string "Uao! Sei un vero fenomeno.$"

Route44_Text_VancePostRematch:
    .string "ARTICUNO, ZAPDOS e MOLTRES sono\n"
    .string "i tre POKéMON uccello leggendari.\p"
    .string "Ho sentito però che esistono\n"
    .string "altri uccelli leggendari.$"

Route44_Text_PsychicPhilSeen:
    .string "Vincerò di sicuro!$"

Route44_Text_PsychicPhilBeaten:
    .string "Argh… Che sconfitta scioccante…$"

Route44_Text_PsychicPhilAfter:
    .string "È importante avere convinzione\n"
    .string "dalla propria parte.$"

Route44_Text_PokemaniacZachSeen:
    .string "Farei di tutto per mettere le mani\n"
    .string "su POKéMON rari!$"

Route44_Text_PokemaniacZachBeaten:
    .string "Oooh, i tuoi POKéMON sono\n"
    .string "così attraenti.$"

Route44_Text_PokemaniacZachAfter:
    .string "Se un POKéMON ha colori diversi\n"
    .string "dal solito, vale di più.\p"
    .string "Come? Vuoi dire che non è vero?$"

Route44_Text_CooltrainermAllenSeen:
    .string "Si vede che sei un bravo\n"
    .string "allenatore, solo guardandoti.\p"
    .string "Sono bravo coi POKéMON, e vedo\n"
    .string "che lo sei anche tu.$"

Route44_Text_CooltrainermAllenBeaten:
    .string "Tch! Per me è una disfatta totale.$"

Route44_Text_CooltrainermAllenAfter:
    .string "Wow. Hai un sacco di MEDAGLIE.\p"
    .string "Non c'è da stupirsi.\p"
    .string "Chissà se MORTY della PALESTRA\n"
    .string "DI ECRUTEAK si allena ancora?\p"
    .string "Mi ha battuto alla grande.$"

Route44_Text_CooltrainerfCybilSeen:
    .string "Sembri forte.\p"
    .string "I bravi allenatori cercano\n"
    .string "avversari tosti d'istinto.$"

Route44_Text_CooltrainerfCybilBeaten:
    .string "No! Così non va per niente.$"

Route44_Text_CooltrainerfCybilAfter:
    .string "Si migliora affrontando\n"
    .string "molte lotte.\p"
    .string "Ho lottato tanto per diventare\n"
    .string "quella che sono: un'élite.$"

Route44_Text_Sign1:
    .string "PERCORSO 44\n"
    .string "GROTTA GHIACCIO AVANTI$"

Route44_Text_Sign2:
    .string "PERCORSO 44\p"
    .string "MOGANIA - EBANOPOLI$"

