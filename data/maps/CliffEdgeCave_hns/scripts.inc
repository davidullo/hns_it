CliffEdgeCave_hns_MapScripts::
	.byte 0

CliffEdgeCave_EventScript_BaldMan::
	lock
	faceplayer
	msgbox CliffEdgeCave_Text_Baldman, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeCave_Text_Baldman:
	.string "Se in una grotta trovi un\n"
	.string "bivio, di solito una via\l"
	.string "è giusta e l'altra porta\l"
	.string "a un vicolo cieco.\p"
	.string "Ma tutti finiscono per provarle.$"
