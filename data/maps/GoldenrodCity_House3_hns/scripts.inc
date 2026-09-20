GoldenrodCity_House3_hns_MapScripts::
	.byte 0

GoldenrodCity_House3_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodHappinessRater_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_House3_EventScript_Twin::
	lock
	faceplayer
	msgbox GoldenrodHappinessRater_Text_Twin, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodHappinessRater_Text_PokefanM:
    .string "Continuo a perdere e i miei\n"
    .string "POKéMON finiscono esausti…\p"
    .string "Forse per questo non mi\n"
    .string "vogliono molto bene…$"

GoldenrodHappinessRater_Text_Twin:
    .string "Quando uso un oggetto sul POKéMON,\n"
    .string "diventa felicissimo!$"
