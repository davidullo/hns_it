UnionCave_B1F_hns_MapScripts::
	.byte 0

UnionCave_B1F_EventScript_HikerPhillip::
	trainerbattle_single TRAINER_PHILLIP_HNS, UnionCave_B1F_Text_HikerPhillipSeen, UnionCave_B1F_Text_HikerPhillipBeaten
	msgbox UnionCave_B1F_Text_HikerPhillipAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_HikerLeonard::
	trainerbattle_single TRAINER_LEONARD_HNS, UnionCave_B1F_Text_HikerLeonardSeen, UnionCave_B1F_Text_HikerLeonardBeaten
	msgbox UnionCave_B1F_Text_HikerLeonardAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_PokemaniacAndrew::
	trainerbattle_single TRAINER_ANDREW_HNS, UnionCave_B1F_Text_PokemaniacAndrewSeen, UnionCave_B1F_Text_PokemaniacAndrewBeaten
	msgbox UnionCave_B1F_Text_PokemaniacAndrewAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_PokemaniacCalvin::
	trainerbattle_single TRAINER_CALVIN_HNS, UnionCave_B1F_Text_PokemaniacCalvinSeen, UnionCave_B1F_Text_PokemaniacCalvinBeaten
	msgbox UnionCave_B1F_Text_PokemaniacCalvinAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_Item_RockTomb::
	finditem ITEM_TM_ROCK_TOMB
	end

UnionCave_B1F_EventScript_Item_Xdefend::
	finditem ITEM_X_DEFEND
	end

UnionCave_B1F_Text_HikerPhillipSeen:
	.string "È da un po' che non vedo\n"
	.string "un'altra persona.\p"
	.string "Non essere timido. Combattiamo!$"

UnionCave_B1F_Text_HikerPhillipBeaten:
	.string "Uuurgh…$"

UnionCave_B1F_Text_HikerPhillipAfter:
	.string "Sono perso da tanto tempo…\p"
	.string "Qui non mi dispiace, ma ho\n"
	.string "fameee!$"

UnionCave_B1F_Text_HikerLeonardSeen:
	.string "Ma guarda! Un visitatore!$"

UnionCave_B1F_Text_HikerLeonardBeaten:
	.string "Wahahah! Sei un tipo tosto!$"

UnionCave_B1F_Text_HikerLeonardAfter:
	.string "Io vivo quaggiù.\p"
	.string "Anche tu puoi, se vuoi.\p"
	.string "C'è un sacco di spazio, sai.$"

UnionCave_B1F_Text_PokemaniacAndrewSeen:
	.string "Chi va là?\p"
	.string "Lascia in pace me e i miei POKéMON!$"

UnionCave_B1F_Text_PokemaniacAndrewBeaten:
	.string "Va'… Vattene!$"

UnionCave_B1F_Text_PokemaniacAndrewAfter:
	.string "Solo io e i miei POKéMON. Sono\n"
	.string "fuori di gioia.$"

UnionCave_B1F_Text_PokemaniacCalvinSeen:
	.string "Sono venuto fin qui per condurre\n"
	.string "le mie ricerche sui POKéMON.\p"
	.string "Ti mostro i miei risultati in una\n"
	.string "vera lotta!$"

UnionCave_B1F_Text_PokemaniacCalvinBeaten:
	.string "Mi hai usato come cavia!$"

UnionCave_B1F_Text_PokemaniacCalvinAfter:
	.string "Dovrei raccogliere e pubblicare i\n"
	.string "risultati dei miei studi.\p"
	.string "Potrei diventare famoso come\n"
	.string "PROF.ELM.$"
