EcruteakCity_House1_hns_MapScripts::
	.byte 0

EcruteakCity_House1_EventScript_Gramps::
	lock
	faceplayer
	msgbox EcruteakLugiaSpeechHouse_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_House1_EventScript_Youngster::
	lock
	faceplayer
	msgbox EcruteakLugiaSpeechHouse_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakLugiaSpeechHouse_Text_Gramps:
	.string "È successo quando ero giovane.\p"
	.string "Il cielo si fece nero. Un\n"
	.string "POKéMON volante gigantesco copriva\l"
	.string "il sole.\p"
	.string "Chissà cos'era quel POKéMON?\p"
	.string "Era come un uccello e un drago.$"

EcruteakLugiaSpeechHouse_Text_Youngster:
	.string "Esiste davvero un POKéMON così\p"
	.string "grande? Se esiste, è fortissimo.$"
