CianwoodHouse2_hns_MapScripts::
	.byte 0

CianwoodHouse2_EventScript_Teacher::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseTeacher, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse2_EventScript_Lass::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseLass, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse2_EventScript_Twin::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseTwin, MSGBOX_DEFAULT
	closemessage
	release
	end
	
CianwoodCity_Text_LugiaHouseTeacher:
	.string "Vieni da OLIVINOPOLI?\p"
	.string "Ti ricordi le quattro isole\n"
	.string "del tragitto?\p"
	.string "Ho sentito di una creatura\n"
	.string "mitica nascosta tra loro.$"

CianwoodCity_Text_LugiaHouseLass:
	.string "Ho sentito che si può vedere\n"
	.string "solo con un'ALA ARGENTO.\p"
	.string "Dovrà avere lo stesso odore\n"
	.string "della creatura.$"

CianwoodCity_Text_LugiaHouseTwin:
	.string "I vortici attorno alle isole\n"
	.string "sono causati dalla creatura\l"
	.string "del mare.\p"
	.string "Per superarli ti serve\n"
	.string "forse una mossa speciale.$"
