CeladonCity_House1_hns_MapScripts::
	.byte 0

CeladonCity_House1_EventScript_Chef::
	msgbox CeladonCity_House1_Text_ChefEatathon, MSGBOX_NPC
	end

CeladonCity_House1_EventScript_Fisher1::
	lock
	msgbox CeladonCity_House1_Text_Fisher1Snarfle, MSGBOX_DEFAULT
	faceplayer
	msgbox CeladonCity_House1_Text_Fisher1Concentration, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_WEST
	release
	end

CeladonCity_House1_EventScript_Fisher2::
	lock
	msgbox CeladonCity_House1_Text_Fisher2GulpChew, MSGBOX_DEFAULT
	faceplayer
	msgbox CeladonCity_House1_Text_Fisher2Quantity, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_EAST
	release
	end

CeladonCity_House1_EventScript_Fisher3::
	lock
	msgbox CeladonCity_House1_Text_Fisher3MunchMunch, MSGBOX_DEFAULT
	faceplayer
	msgbox CeladonCity_House1_Text_Fisher3GoldenrodIsBest, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_EAST
	release
	end

CeladonCity_House1_EventScript_Teacher::
	lock
	msgbox CeladonCity_House1_Text_TeacherCrunchCrunch, MSGBOX_DEFAULT
	faceplayer
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_House1_EventScript_TeacherCoincase
	msgbox CeladonCity_House1_Text_TeacherKeepEating, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_WEST
	release
	end

CeladonCity_House1_EventScript_TeacherCoincase::
	msgbox CeladonCity_House1_Text_TeacherNoCoinCase, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_WEST
	release
	end

CeladonCity_House1_EventScript_Sign::
	msgbox CeladonCity_House1_Text_EatathonContestPoster, MSGBOX_SIGN
	end

CeladonCity_House1_Text_ChefEatathon:
	.string "Ehi!\p"
	.string "Ora c'è una gara di abbuffate,\p"
	.string "non possiamo servirti.\n"
	.string "Scusa.$"

CeladonCity_House1_Text_Fisher1Snarfle:
	.string "…Slurp, gnam…$"

CeladonCity_House1_Text_Fisher1Concentration:
	.string "Non parlarmi!\p"
	.string "Rompi la mia concentrazione!$"

CeladonCity_House1_Text_Fisher2GulpChew:
	.string "…Gulp… Gnam…$"

CeladonCity_House1_Text_Fisher2Quantity:
	.string "La quantità batte la qualità!\p"
	.string "Basta una pancia piena!$"

CeladonCity_House1_Text_Fisher3MunchMunch:
	.string "Gnam, gnam…$"

CeladonCity_House1_Text_Fisher3GoldenrodIsBest:
	.string "Qui si mangia bene, ma a\n"
	.string "FIORDOROPOLI si mangia meglio\l"
	.string "di tutti.$"

CeladonCity_House1_Text_TeacherCrunchCrunch:
	.string "Scroc… Scroc…$"

CeladonCity_House1_Text_TeacherNoCoinCase:
	.string "Qui non ti danno il SALVADANAIO.\n"
	.string "Prova a cercare a JOHTO.$"

CeladonCity_House1_Text_TeacherKeepEating:
	.string "Scroc… Scroc…\p"
	.string "Continuo a mangiare!\p"
	.string "Ancora, CHEF!$"

CeladonCity_House1_Text_EatathonContestPoster:
	.string "Gara di abbuffate! Senza limite!\p"
	.string "Una sfida senza fine! Chi mangia\n"
	.string "di più non paga niente!$"

