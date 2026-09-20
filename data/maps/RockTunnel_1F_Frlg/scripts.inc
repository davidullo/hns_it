RockTunnel_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RockTunnel_1F_OnTransition
	.byte 0

RockTunnel_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_ROCK_TUNNEL_1F
	end

RockTunnel_1F_EventScript_RouteSign::
	msgbox RockTunnel_1F_Text_RouteSign, MSGBOX_SIGN
	end

RockTunnel_1F_EventScript_Lenny::
	trainerbattle_single TRAINER_HIKER_LENNY, RockTunnel_1F_Text_LennyIntro, RockTunnel_1F_Text_LennyDefeat
	msgbox RockTunnel_1F_Text_LennyPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Oliver::
	trainerbattle_single TRAINER_HIKER_OLIVER, RockTunnel_1F_Text_OliverIntro, RockTunnel_1F_Text_OliverDefeat
	msgbox RockTunnel_1F_Text_OliverPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Lucas::
	trainerbattle_single TRAINER_HIKER_LUCAS, RockTunnel_1F_Text_LucasIntro, RockTunnel_1F_Text_LucasDefeat
	msgbox RockTunnel_1F_Text_LucasPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Ashton::
	trainerbattle_single TRAINER_POKEMANIAC_ASHTON, RockTunnel_1F_Text_AshtonIntro, RockTunnel_1F_Text_AshtonDefeat
	msgbox RockTunnel_1F_Text_AshtonPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Leah::
	trainerbattle_single TRAINER_PICNICKER_LEAH, RockTunnel_1F_Text_LeahIntro, RockTunnel_1F_Text_LeahDefeat
	msgbox RockTunnel_1F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Ariana::
	trainerbattle_single TRAINER_PICNICKER_ARIANA, RockTunnel_1F_Text_ArianaIntro, RockTunnel_1F_Text_ArianaDefeat
	msgbox RockTunnel_1F_Text_ArianaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Dana::
	trainerbattle_single TRAINER_PICNICKER_DANA, RockTunnel_1F_Text_DanaIntro, RockTunnel_1F_Text_DanaDefeat
	msgbox RockTunnel_1F_Text_DanaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_Text_LennyIntro::
	.string "Questa grotta è lunghissima, ragazzo!$"

RockTunnel_1F_Text_LennyDefeat::
	.string "Ahia!\n"
	.string "Hai vinto!$"

RockTunnel_1F_Text_LennyPostBattle::
	.string "Attenzione agli ONIX.\n"
	.string "Compaiono solo ogni tanto.\p"
	.string "Quelli di alto livello possono\n"
	.string "stritolarti!$"

RockTunnel_1F_Text_OliverIntro::
	.string "Hmm.\n"
	.string "Forse mi sono perso qui dentro…$"

RockTunnel_1F_Text_OliverDefeat::
	.string "Piano!\n"
	.string "Che sto facendo?\l"
	.string "Da che parte si esce?$"

RockTunnel_1F_Text_OliverPostBattle::
	.string "Quel POKéMON che dorme sulla PERCORSO 12\n"
	.string "mi ha costretto a questa deviazione.$"

RockTunnel_1F_Text_LucasIntro::
	.string "Gli estranei come te devono\n"
	.string "portarmi rispetto!$"

RockTunnel_1F_Text_LucasDefeat::
	.string "Mi arrendo!$"

RockTunnel_1F_Text_LucasPostBattle::
	.string "Sei abbastanza bravo per scalare!$"

RockTunnel_1F_Text_AshtonIntro::
	.string "I POKéMON lottano!\n"
	.string "Pronti, via!$"

RockTunnel_1F_Text_AshtonDefeat::
	.string "Partita finita!$"

RockTunnel_1F_Text_AshtonPostBattle::
	.string "Vabbè, un ZUBAT lo trovo per strada!$"

RockTunnel_1F_Text_LeahIntro::
	.string "Ih!\p"
	.string "Non provare scherzi stupidi al\n"
	.string "buio!$"

RockTunnel_1F_Text_LeahDefeat::
	.string "Era troppo buio…$"

RockTunnel_1F_Text_LeahPostBattle::
	.string "Ho visto un MACHOP in questa grotta.$"

RockTunnel_1F_Text_DanaIntro::
	.string "Sono arrivata fin qui in cerca di\n"
	.string "POKéMON selvatici.$"

RockTunnel_1F_Text_DanaDefeat::
	.string "Non ho più POKéMON!$"

RockTunnel_1F_Text_DanaPostBattle::
	.string "Sembravi carino e innocuo.\n"
	.string "Mi sbagliavo di grosso!$"

RockTunnel_1F_Text_ArianaIntro::
	.string "Hai dei POKéMON!\n"
	.string "Iniziamo!$"

RockTunnel_1F_Text_ArianaDefeat::
	.string "Ci sai fare!$"

RockTunnel_1F_Text_ArianaPostBattle::
	.string "Fiuuu!\n"
	.string "Sono tutta sudata.$"

RockTunnel_1F_Text_RouteSign::
	.string "GROTTA ROCCIA\n"
	.string "CELESTOPOLI - LAVANDONIA$"

