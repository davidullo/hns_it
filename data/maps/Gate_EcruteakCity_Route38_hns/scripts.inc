Gate_EcruteakCity_Route38_hns_MapScripts::
	.byte 0

Route38_EventScript_Officer::
	lock
	faceplayer
	msgbox Route38_Text_EcruteakGateOfficer, MSGBOX_DEFAULT
	closemessage
	release
	end

Route38_Text_EcruteakGateOfficer:
	.string "Da dove hai detto che vieni?\p"
	.string "BORGO FOGLIANOVA?\p"
	.string "PROF. ELM abita laggiù,\n"
	.string "vero?\p"
	.string "Hai fatto molta strada fin\n"
	.string "qui.$"
