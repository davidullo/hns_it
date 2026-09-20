GoldenrodCity_House2_hns_MapScripts::
	.byte 0

GoldenrodCity_House2_EventScript_Man::
	faceplayer
	lock
	msgbox GoldenrodPPSpeechHouse_Text_Man, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_House2_EventScript_Woman::
	faceplayer
	lock
	msgbox GoldenrodPPSpeechHouse_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodPPSpeechHouse_Text_Man:
    .string "Una volta, mentre lottavo, il mio\n"
    .string "POKéMON non poté usare mosse.\p"
    .string "I PUNTI POTERE, o PP, delle sue\n"
    .string "mosse erano finiti.$"

GoldenrodPPSpeechHouse_Text_Lass:
    .string "A volte un POKéMON sano non può\n"
    .string "usare le sue mosse.\p"
    .string "Se succede, curalo in un\n"
    .string "CENTRO POKéMON o usa un oggetto.$"
