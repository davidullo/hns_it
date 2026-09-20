OlivineCity_House2_hns_MapScripts::
	.byte 0

OlivineCity_EventScript_Punisher::
	lock
	faceplayer
	msgbox OlivineCity_Text_PunishmentBro, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_PunisherBoy::
	lock
	faceplayer
	msgbox OlivineCity_Text_PunishmentBoy, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_PunishmentBro:
	.string "Verso CIANWOOD\n"
	.string "ci sono quattro isole deserte.\p"
	.string "I bimbi cattivi vengono portati lì\n"
	.string "come punizione!$"

OlivineCity_Text_PunishmentBoy:
	.string "Quando combino guai,\n"
	.string "mio fratello mi spaventa sempre.$"
