RockTunnel_B1F_Frlg_MapScripts::
	.byte 0

RockTunnel_B1F_EventScript_Sofia::
	trainerbattle_single TRAINER_PICNICKER_SOFIA, RockTunnel_B1F_Text_SofiaIntro, RockTunnel_B1F_Text_SofiaDefeat
	msgbox RockTunnel_B1F_Text_SofiaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Martha::
	trainerbattle_single TRAINER_PICNICKER_MARTHA, RockTunnel_B1F_Text_MarthaIntro, RockTunnel_B1F_Text_MarthaDefeat
	msgbox RockTunnel_B1F_Text_MarthaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Dudley::
	trainerbattle_single TRAINER_HIKER_DUDLEY, RockTunnel_B1F_Text_DudleyIntro, RockTunnel_B1F_Text_DudleyDefeat
	msgbox RockTunnel_B1F_Text_DudleyPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Allen::
	trainerbattle_single TRAINER_HIKER_ALLEN, RockTunnel_B1F_Text_AllenIntro, RockTunnel_B1F_Text_AllenDefeat
	msgbox RockTunnel_B1F_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Eric::
	trainerbattle_single TRAINER_HIKER_ERIC, RockTunnel_B1F_Text_EricIntro, RockTunnel_B1F_Text_EricDefeat
	msgbox RockTunnel_B1F_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Cooper::
	trainerbattle_single TRAINER_POKEMANIAC_COOPER, RockTunnel_B1F_Text_CooperIntro, RockTunnel_B1F_Text_CooperDefeat
	msgbox RockTunnel_B1F_Text_CooperPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Steve::
	trainerbattle_single TRAINER_POKEMANIAC_STEVE, RockTunnel_B1F_Text_SteveIntro, RockTunnel_B1F_Text_SteveDefeat
	msgbox RockTunnel_B1F_Text_StevePostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Winston::
	trainerbattle_single TRAINER_POKEMANIAC_WINSTON, RockTunnel_B1F_Text_WinstonIntro, RockTunnel_B1F_Text_WinstonDefeat
	msgbox RockTunnel_B1F_Text_WinstonPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_Text_SofiaIntro::
	.string "Do you know how you can avoid\n"
	.string "getting lost in the mountains?\p"
	.string "You can bend twigs as trail\n"
	.string "markers.$"

RockTunnel_B1F_Text_SofiaDefeat::
	.string "Oooh!\n"
	.string "Ho dato il massimo!$"

RockTunnel_B1F_Text_SofiaPostBattle::
	.string "Voglio andare a casa!$"

RockTunnel_B1F_Text_DudleyIntro::
	.string "Ahahah!\n"
	.string "Batti la mia forza?$"

RockTunnel_B1F_Text_DudleyDefeat::
	.string "Ops!\n"
	.string "Sopraffatto!$"

RockTunnel_B1F_Text_DudleyPostBattle::
	.string "Vado di forza perché odio\n"
	.string "pensare.$"

RockTunnel_B1F_Text_CooperIntro::
	.string "Tu hai un POKéDEX?\n"
	.string "Ne voglio uno anch'io.$"

RockTunnel_B1F_Text_CooperDefeat::
	.string "Dannazione!\n"
	.string "Che invidia!$"

RockTunnel_B1F_Text_CooperPostBattle::
	.string "Quando finisci il POKéDEX,\n"
	.string "me lo dai?$"

RockTunnel_B1F_Text_SteveIntro::
	.string "Ehm… sai cosa sono i cosplay\n"
	.string "di POKéMON?$"

RockTunnel_B1F_Text_SteveDefeat::
	.string "Beh, è andata così.$"

RockTunnel_B1F_Text_StevePostBattle::
	.string "Il cosplay POKéMON è vestirsi da\n"
	.string "POKéMON per divertirsi.\p"
	.string "Clefairy è il preferito.$"

RockTunnel_B1F_Text_AllenIntro::
	.string "Le mie tecniche POKéMON ti faranno\n"
	.string "piangere!$"

RockTunnel_B1F_Text_AllenDefeat::
	.string "Mi arrendo!\n"
	.string "Sei un tecnico migliore!$"

RockTunnel_B1F_Text_AllenPostBattle::
	.string "In montagna si trovano spesso\n"
	.string "POKéMON di tipo ROCIA.$"

RockTunnel_B1F_Text_MarthaIntro::
	.string "Non vengo spesso qui, ma ti\n"
	.string "sfiderò.$"

RockTunnel_B1F_Text_MarthaDefeat::
	.string "Oh!\n"
	.string "Ho perso!$"

RockTunnel_B1F_Text_MarthaPostBattle::
	.string "Mi piacciono i POKéMON piccoli.\n"
	.string "I grandi fanno paura!$"

RockTunnel_B1F_Text_EricIntro::
	.string "Colpiscimi col tuo attacco migliore!$"

RockTunnel_B1F_Text_EricDefeat::
	.string "Bruciato!$"

RockTunnel_B1F_Text_EricPostBattle::
	.string "Allen(er)ò i miei POKéMON per\n"
	.string "battere i tuoi, ragazzo.$"

RockTunnel_B1F_Text_WinstonIntro::
	.string "Disegno illustrazioni di POKéMON\n"
	.string "quando sono a casa.$"

RockTunnel_B1F_Text_WinstonDefeat::
	.string "Fiu…\n"
	.string "Sono esausto…$"

RockTunnel_B1F_Text_WinstonPostBattle::
	.string "Sono un artista, non un lottatore.\n"
	.string "Torno a casa a disegnare.$"

